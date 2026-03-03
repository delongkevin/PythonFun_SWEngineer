/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  vDiagSecAcc.c
 *        \brief  Security Access
 *
 *      \details  Implementation of the Security Access
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VDIAGSECACC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vDiagSecAcc.h"
#include "vDiagSecAcc_Cbk.h"

#if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

 /* Check the version of the header file */
#if ( (VDIAGSECACC_SW_MAJOR_VERSION != (1u)) \
    || (VDIAGSECACC_SW_MINOR_VERSION != (1u)) \
    || (VDIAGSECACC_SW_PATCH_VERSION != (0u)))
# error "Vendor specific version numbers of vDiagSecAcc.c and vDiagSecAcc.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (VDIAGSECACC_LOCAL) /* COV_VDIAGSECACC_LOCAL_DEFINE */
# define VDIAGSECACC_LOCAL                                            static
#endif

#if !defined (VDIAGSECACC_LOCAL_INLINE) /* COV_VDIAGSECACC_LOCAL_DEFINE */
# define VDIAGSECACC_LOCAL_INLINE                                     LOCAL_INLINE
#endif

 /** State Type */
#define VDIAGSECACC_JOBSTATE_INITIAL                                  (0u)  /**< Initial state */
#define VDIAGSECACC_JOBSTATE_OPERATION_PENDING                        (1u)  /**< Operation is pending */
#define VDIAGSECACC_JOBSTATE_OPERATION_SUCCESSFUL                     (2u)  /**< Successful */
#define VDIAGSECACC_JOBSTATE_OPERATION_CANCEL                         (3u)  /**< Cancel request */
#define VDIAGSECACC_JOBSTATE_OPERATION_FAILED                         (4u)  /**< Failed */

#define VDIAGSECACC_INVALID_CALLBACK_RESULT                           (0xFFu) /**< Initial state */
/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 /** State Type */
typedef uint8 vDiagSecAcc_StateType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define VDIAGSECACC_START_SEC_VAR_ZERO_INIT_8BIT
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
VDIAGSECACC_LOCAL VAR(uint8, VDIAGSECACC_VAR_ZERO_INIT)                     vDiagSecAcc_ModuleInitialized = VDIAGSECACC_UNINIT;
#endif

#define VDIAGSECACC_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define VDIAGSECACC_START_SEC_VAR_NOINIT_8BIT
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** State of seed generation */
VDIAGSECACC_LOCAL VAR(vDiagSecAcc_StateType, VDIAGSECACC_VAR_NOINIT)        vDiagSecAcc_SeedState;
/** State of key comparison */
VDIAGSECACC_LOCAL VAR(vDiagSecAcc_StateType, VDIAGSECACC_VAR_NOINIT)        vDiagSecAcc_CompareState;

/** Variable to store signature verification result */
VDIAGSECACC_LOCAL VAR(Crypto_VerifyResultType, VDIAGSECACC_VAR_NOINIT)      vDiagSecAcc_SignatureVerificationResult;

/** Callback results */
#if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
VDIAGSECACC_LOCAL VAR(Std_ReturnType, VDIAGSECACC_VAR_NOINIT)               vDiagSecAcc_SeedCallbackResult;
#endif
#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON)
VDIAGSECACC_LOCAL VAR(Std_ReturnType, VDIAGSECACC_VAR_NOINIT)               vDiagSecAcc_SignatureVerificationCallbackResult;
#endif

#define VDIAGSECACC_STOP_SEC_VAR_NOINIT_8BIT
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define VDIAGSECACC_START_SEC_VAR_NOINIT_32BIT
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Length of generated seed */
VDIAGSECACC_LOCAL VAR(uint32, VDIAGSECACC_VAR_NOINIT)                       vDiagSecAcc_GeneratedSeedLength;

#define VDIAGSECACC_STOP_SEC_VAR_NOINIT_32BIT
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define VDIAGSECACC_START_SEC_CODE
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  vDiagSecAcc_Local_MemCpy
 **********************************************************************************************************************/
/*! \brief         Copies data from source to destination.
 *  \details       Copies data from source to destination for the given length.
 *  \param[out]    destination      Pointer to buffer where the data shall be copied to
 *  \param[in]     source           Pointer to data which shall be copied
 *  \param[in]     length           Number of bytes which shall be copied
 *  \pre           length of the buffer provided by destination can hold at least the number of bytes given in length
 *  \pre           All pointers need to be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_MemCpy(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) destination,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) source,
  uint32 length);

#if (VDIAGSECACC_DEV_ERROR_DETECT== STD_ON)
/***********************************************************************************************************************
*  vDiagSecAcc_Local_DevCheck
**********************************************************************************************************************/
/*! \brief        Development Error Checks.
*  \details       -
*  \param[in]     ptr    Pointer to buffer which holds the data
*  \return        VDIAGSECACC_E_NO_ERROR      No error.
*  \return        VDIAGSECACC_E_UNINIT        Module not initialized.
*  \return        VDIAGSECACC_E_PARAM_POINTER Invalid pointer.
*  \pre           -
*  \context       TASK
*  \reentrant     TRUE
*  \synchronous   TRUE
*********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(uint8, VDIAGSECACC_CODE) vDiagSecAcc_Local_DevCheck(
  P2CONST(void, AUTOMATIC, VDIAGSECACC_APPL_DATA) ptr);
#endif

/***********************************************************************************************************************
*  vDiagSecAcc_Local_HandleDcmCancel
**********************************************************************************************************************/
/*! \brief        Handles DCM OpStatus Cancel.
*  \details       -
*  \param[in]     asyncJob      Holds whether the job is asynchronous.
*  \param[in,out] state         Holds a pointer to the state machine.
*  \pre           -
*  \context       TASK
*  \reentrant     TRUE
*  \synchronous   TRUE
*********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_HandleDcmCancel(
  boolean asyncJob,
  P2VAR(vDiagSecAcc_StateType, AUTOMATIC, AUTOMATIC) state);

/***********************************************************************************************************************
*  vDiagSecAcc_Local_RequestSeedGeneration
**********************************************************************************************************************/
/*! \brief        Triggers seed generation.
*  \details       Calls Csm_RandomGenerate to request a seed generation.
*  \param[in]      seedLength     Length of Seed
*  \param[in,out]  globalSeedBuffer  Pointer to a global buffer, to which the generated seed is written
*  \return        DCM_E_PENDING    Request pending.
*  \return        E_NOT_OK         Request failed.
*  \pre           State needs to be a valid vDiagSecAcc_StateType pointer.
*  \context       TASK
*  \reentrant     FALSE
*  \synchronous   TRUE
*********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_RequestSeedGeneration(
  uint32 seedLength, P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) globalSeedBuffer);

/***********************************************************************************************************************
*  vDiagSecAcc_Local_HandleSuccessfulSeedGeneration
**********************************************************************************************************************/
/*! \brief        Handles successful seed generation.
*  \details       Safes the result of a successful seed generation and allows next seed request.
*  \param[in,out] seed              Pointer to seed buffer
*  \param[in]     seedLength        Length of seed
*  \param[in]     globalSeedBuffer  Pointer to a globa buffer containing the generated seed
*  \pre           Pointers need to be valid.
*  \context       TASK
*  \reentrant     FALSE
*  \synchronous   TRUE
*********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_HandleSuccessfulSeedGeneration(
  P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) seed, uint32 seedLength, P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) globalSeedBuffer);

/***********************************************************************************************************************
*  vDiagSecAcc_Local_RequestSignatureVerification
**********************************************************************************************************************/
/*! \brief        Triggers verification of a given signature.
*  \details       Calls Csm_SignatureVerify and handles the result.
*  \param[in]     key         Received key from tester
*  \param[in]     levelIdx    Holds index of the security level
*  \return        DCM_E_PENDING    Request pending (for sync job this is equivalent to successful).
*  \return        E_NOT_OK         Request failed.
*  \pre           Key needs to be a valid ptr with length of keyLength.
*  \pre           State needs to be a valid vDiagSecAcc_StateType pointer.
*  \context       TASK
*  \reentrant     TRUE
*  \synchronous   TRUE
**********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_RequestSignatureVerification(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) key,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx);

/***********************************************************************************************************************
*  vDiagSecAcc_Local_HandleSuccessfulSignatureVerification
**********************************************************************************************************************/
/*! \brief        Handle result of a signature verification
*  \details       Checks if signature was verified.
*  \return        E_OK                        signature verification successful
*  \return        DCM_E_COMPARE_KEY_FAILED    signature verification failed
*  \pre           State needs to be a valid   vDiagSecAcc_StateType pointer.
*  \context       TASK
*  \reentrant     TRUE
*  \synchronous   TRUE
**********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_HandleSuccessfulSignatureVerification(void);

/***********************************************************************************************************************
*  vDiagSecAcc_Local_DispatchCompareStateSync
**********************************************************************************************************************/
/*! \brief        Dispatches compareState for synchronous compare key
*  \details       Triggers signature verification and checks if verification was successful.
*  \param[in]     key           Received key from tester
*  \param[in]     levelIdx      Holds idx of the security level
*  \return        E_OK                        signature verification successful
*  \return        DCM_E_COMPARE_KEY_FAILED    signature verification failed
*  \pre           State needs to be a valid vDiagSecAcc_StateType pointer.
*  \context       TASK
*  \reentrant     TRUE
*  \synchronous   TRUE
**********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_DispatchCompareStateSync(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) key,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx);

#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON)
/***********************************************************************************************************************
*  vDiagSecAcc_Local_DispatchCompareStateAsync
**********************************************************************************************************************/
/*! \brief        Dispatches compareState for asynchronous compare key
*  \details       Triggers signature verification and checks if verification was successful.
*  \param[in]     key           Received key from tester
*  \param[in]     levelIdx      Holds idx of the security level
*  \return        E_OK                        signature verification successful
*  \return        DCM_E_COMPARE_KEY_FAILED    signature verification failed
*  \pre           State needs to be a valid vDiagSecAcc_StateType pointer.
*  \context       TASK
*  \reentrant     TRUE
*  \synchronous   TRUE
**********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_DispatchCompareStateAsync(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) key,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx);
#endif

#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON) || (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
/***********************************************************************************************************************
 *  vDiagSecAcc_Local_CallbackNotification
 **********************************************************************************************************************/
/*! \brief         Handles Callback Notification.
 *  \details       Notifies the vDiagSecAcc that the job has finished. Updates the state variable according to the callback result.
 *  \param[in]     result       Contains the result of the cryptographic operation.
 *  \param[in,out] state        Holds a pointer to the state machine.
 *  \pre           State needs to be a valid vDiagSecAcc_StateType pointer.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 **********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_CallbackNotification(
  Std_ReturnType result,
  P2VAR(vDiagSecAcc_StateType, AUTOMATIC, AUTOMATIC) state);
#endif

/***********************************************************************************************************************
 *  vDiagSecAcc_Local_CsmRvalUpdateState
 **********************************************************************************************************************/
/*! \brief        Parse CSM return value.
 *  \details       The return value of the function can be passed to the DCM.
 *  \param[in]     value      Holds the Csm return value.
 *  \param[in,out] state      Holds a pointer to the state machine.
 *  \return        DCM_E_PENDING    Request pending.
 *  \return        E_NOT_OK         Request failed.
 *  \pre           State needs to be a valid vDiagSecAcc_StateType pointer.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_CsmRvalUpdateState(
  Std_ReturnType value,
  P2VAR(vDiagSecAcc_StateType, AUTOMATIC, AUTOMATIC) state);

#define VDIAGSECACC_STOP_SEC_CODE
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VDIAGSECACC_START_SEC_CODE
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  vDiagSecAcc_Local_MemCpy
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_MemCpy(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) destination,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) source,
  uint32 length)
{
  /* ----- Local Variables ---------------------------------------------- */
    uint32_least count;

  /* ----- Implementation ----------------------------------------------- */
  /* # Copy data bytewise to the destination buffer */
  for (count = 0; count < length; count++)
  {
    destination[count] = source[count];
  }
}

#if (VDIAGSECACC_DEV_ERROR_DETECT== STD_ON)
/***********************************************************************************************************************
*  vDiagSecAcc_Local_DevCheck
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(uint8, VDIAGSECACC_CODE) vDiagSecAcc_Local_DevCheck(
  P2CONST(void, AUTOMATIC, VDIAGSECACC_APPL_DATA) ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check initialization state of the component. */
  if (vDiagSecAcc_ModuleInitialized != VDIAGSECACC_INITIALIZED)
  {
    errorId = VDIAGSECACC_E_UNINIT;
  }
  /* # Check plausibility of parameters. */
  else if (ptr == NULL_PTR)
  {
    errorId = VDIAGSECACC_E_PARAM_POINTER;
  }
  else
  {
    errorId = VDIAGSECACC_E_NO_ERROR;
  }

  return errorId;
}
#endif

/***********************************************************************************************************************
 *  vDiagSecAcc_Local_HandleDcmCancel
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_HandleDcmCancel(
  boolean asyncJob, P2VAR(vDiagSecAcc_StateType, AUTOMATIC, AUTOMATIC) state)
{
  /* ----- Implementation ----------------------------------------------- */
  /* DCM request was canceled */
#if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_OFF) && (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_OFF)
  /* only sync communication with Csm */
  *state = VDIAGSECACC_JOBSTATE_INITIAL;
  VDIAGSECACC_DUMMY_STATEMENT(asyncJob); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#else
  /* sync and async communication with Csm */
  if (asyncJob == FALSE)
  {
    /* sync job */
    *state = VDIAGSECACC_JOBSTATE_INITIAL;
  }
  else
  {
    /* async job */
    if (*state == VDIAGSECACC_JOBSTATE_OPERATION_PENDING)
    {
      *state = VDIAGSECACC_JOBSTATE_OPERATION_CANCEL;
    }
    else
    {
      *state = VDIAGSECACC_JOBSTATE_INITIAL;
    }
  }
#endif
}

/***********************************************************************************************************************
*  vDiagSecAcc_Local_RequestSeedGeneration
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_RequestSeedGeneration(
  uint32 seedLength, P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) globalSeedBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType CsmRetVal;

  /* ----- Implementation ----------------------------------------------- */
  vDiagSecAcc_GeneratedSeedLength = seedLength;
  /* # Trigger random number generation for seed value */
  CsmRetVal = Csm_RandomGenerate(vDiagSecAcc_GetRandomGenerateJobRefOfGeneral(), globalSeedBuffer, &vDiagSecAcc_GeneratedSeedLength); /* VCA_VDIAGSECACC_CSM_RANDOM_GENERATE */
  /* # Update seedState */
  retVal = vDiagSecAcc_Local_CsmRvalUpdateState(CsmRetVal, &vDiagSecAcc_SeedState);

  return retVal;
}

/***********************************************************************************************************************
*  vDiagSecAcc_Local_HandleSuccessfulSeedGeneration
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
*/

VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_HandleSuccessfulSeedGeneration(
  P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) seed, uint32 seedLength, P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) globalSeedBuffer)
{
  /* ----- Implementation ----------------------------------------------- */
  /* Seed generation finished */
  /* Copy generated seed value to output buffer */
  vDiagSecAcc_Local_MemCpy(seed, globalSeedBuffer, seedLength);

  /* Allow next seed request */
  vDiagSecAcc_SeedState = VDIAGSECACC_JOBSTATE_INITIAL;
}

/***********************************************************************************************************************
*  vDiagSecAcc_Local_RequestSignatureVerification
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_RequestSignatureVerification(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) key, vDiagSecAcc_SizeOfSecurityLevelType levelIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType CsmRetVal;
  uint32 jobId = vDiagSecAcc_GetCompareKeyCsmJobRefOfSecurityLevel(levelIdx);
  uint32 keyLength = vDiagSecAcc_GetKeyLengthOfSecurityLevel(levelIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* # Trigger signature verification */
  CsmRetVal = Csm_SignatureVerify(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, &vDiagSecAcc_GetSeedBuffer(vDiagSecAcc_GetSeedBufferStartIdxOfSecurityLevel(levelIdx)), vDiagSecAcc_GeneratedSeedLength, key, keyLength, &vDiagSecAcc_SignatureVerificationResult); /* VCA_VDIAGSECACC_CSM_SIGNATUREVERIFY */
  /* Update compareState */
  retVal = vDiagSecAcc_Local_CsmRvalUpdateState(CsmRetVal, &vDiagSecAcc_CompareState);

  return retVal;
}

/***********************************************************************************************************************
*  vDiagSecAcc_Local_HandleSuccessfulSignatureVerification
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_HandleSuccessfulSignatureVerification( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  retVal = DCM_E_COMPARE_KEY_FAILED;
  if (vDiagSecAcc_SignatureVerificationResult == CRYPTO_E_VER_OK)
  {
    /* Signature is verified */
    retVal = E_OK;
  }
  /* Allow next verification request */
  vDiagSecAcc_CompareState = VDIAGSECACC_JOBSTATE_INITIAL;

  return retVal;
}

/***********************************************************************************************************************
*  vDiagSecAcc_Local_DispatchCompareStateSync
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_DispatchCompareStateSync(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) key,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* trigger signature verification */
  retVal = vDiagSecAcc_Local_RequestSignatureVerification(key, levelIdx);
  if ((retVal == DCM_E_PENDING) && (vDiagSecAcc_CompareState == VDIAGSECACC_JOBSTATE_OPERATION_PENDING)) /* Pending is equivalent to successful for synchronous call */
  {
    retVal = vDiagSecAcc_Local_HandleSuccessfulSignatureVerification();
  }

  return retVal;
}

#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON)
/***********************************************************************************************************************
*  vDiagSecAcc_Local_DispatchCompareStateAsync
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_DispatchCompareStateAsync(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) key,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Callback for async signature verification */
  if (vDiagSecAcc_SignatureVerificationCallbackResult != VDIAGSECACC_INVALID_CALLBACK_RESULT)
  {
    vDiagSecAcc_Local_CallbackNotification(vDiagSecAcc_SignatureVerificationCallbackResult, &vDiagSecAcc_CompareState);
    vDiagSecAcc_SignatureVerificationCallbackResult = VDIAGSECACC_INVALID_CALLBACK_RESULT;
  }

  switch (vDiagSecAcc_CompareState)
  {
    /* Start signature verification */
    case VDIAGSECACC_JOBSTATE_INITIAL:
    {
      retVal = vDiagSecAcc_Local_RequestSignatureVerification(key, levelIdx);
      break;
    }
    case VDIAGSECACC_JOBSTATE_OPERATION_PENDING:
    {
     /* Verification not finished yet, try again */
      retVal = DCM_E_PENDING;
      break;
    }
    case VDIAGSECACC_JOBSTATE_OPERATION_SUCCESSFUL:
    {
      /* Verification successful, evaluate verification result */
      retVal = vDiagSecAcc_Local_HandleSuccessfulSignatureVerification();
      break;
    }
    case VDIAGSECACC_JOBSTATE_OPERATION_FAILED:
    {
      /* Verification failed or invalid state */
      /* Allow next verification request */
      vDiagSecAcc_CompareState = VDIAGSECACC_JOBSTATE_INITIAL;
      retVal = E_NOT_OK;
      break;
    }

    /* VDIAGSECACC_JOBSTATE_OPERATION_CANCEL */
    default:
    {
      /* Verification not finished yet, try again */
      retVal = DCM_E_PENDING;
      break;
    }
  }

  return retVal;
}
#endif

#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON) || (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
/**********************************************************************************************************************
 *  vDiagSecAcc_Local_CallbackNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VDIAGSECACC_LOCAL FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Local_CallbackNotification(
  Std_ReturnType result,
  P2VAR(vDiagSecAcc_StateType, AUTOMATIC, AUTOMATIC) state)
{
  /* ----- Implementation ----------------------------------------------- */
  /* Result of CSM operation */
  if (result == E_OK)
  {
    /* Operation successful */

    /* Handle state machine */
    switch (*state)
    {
      case VDIAGSECACC_JOBSTATE_OPERATION_PENDING:
      {
        /* Notification is expected in state pending,
        callback result is now valid */
        *state = VDIAGSECACC_JOBSTATE_OPERATION_SUCCESSFUL;

        break;
      }
      case VDIAGSECACC_JOBSTATE_OPERATION_CANCEL:
      {
        /* Notification is unexpected, since job has been canceled
        callback result is invalid */
        *state = VDIAGSECACC_JOBSTATE_INITIAL;

        break;
      }
      default: /* COV_VDIAGSECACC_MISRA_STATEMENT */
      {
        /* Notification is unexpected,
        callback result is invalid */
        *state = VDIAGSECACC_JOBSTATE_OPERATION_FAILED;
        break;
      }
    }
  }
  else
  {
    /* Operation failed, callback result is invalid */
    *state = VDIAGSECACC_JOBSTATE_OPERATION_FAILED;
  }
}
#endif /* (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON) || (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON) */

/***********************************************************************************************************************
*  vDiagSecAcc_Local_CsmRvalUpdateState
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
*/
VDIAGSECACC_LOCAL FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_CsmRvalUpdateState(
  Std_ReturnType value,
  P2VAR(vDiagSecAcc_StateType, AUTOMATIC, AUTOMATIC) state)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  switch (value)
  {
  case E_OK:
    /* Generation pending (asynchronous CSM) or successful (synchronous CSM) */
    *state = VDIAGSECACC_JOBSTATE_OPERATION_PENDING;

    retVal = DCM_E_PENDING;
    break;

  case CRYPTO_E_QUEUE_FULL:
  case CRYPTO_E_BUSY:
    /* CSM busy, try again */
    retVal = DCM_E_PENDING;
    break;

  default:
    /* Operation failed */
    retVal = E_NOT_OK;
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /***********************************************************************************************************************
 *  vDiagSecAcc_Local_GetSeed
 **********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_GetSeed(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) Seed,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_APPL_VAR) ErrorCode,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDIAGSECACC_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
  boolean asyncJob = TRUE;
#else
  boolean asyncJob = FALSE;
#endif
  uint32 seedLength;

  /* ----- Development Error Checks ------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Check plausibility of parameters. */
  errorId = vDiagSecAcc_Local_DevCheck(Seed); /* PRQA S 0315 */ /* MD_VDIAGSECACC_P2VOID_CAST */
  if (errorId  != VDIAGSECACC_E_NO_ERROR)
  {
    /* errorId is already set */
  }
  else if (levelIdx >= vDiagSecAcc_GetSizeOfSecurityLevel())
  {
    errorId = VDIAGSECACC_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    seedLength = vDiagSecAcc_GetSeedBufferLengthOfSecurityLevel(levelIdx);

    /* # Handle DCM OpStatus */
    if (OpStatus == DCM_CANCEL)
    {
      vDiagSecAcc_Local_HandleDcmCancel(asyncJob, &vDiagSecAcc_SeedState);
      retVal = E_OK;
    }
    else
    {
      /* # Handle state machine */
#if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_OFF)
      /* sync seed generation */

      retVal = vDiagSecAcc_Local_RequestSeedGeneration(seedLength, &vDiagSecAcc_GetSeedBuffer(vDiagSecAcc_GetSeedBufferStartIdxOfSecurityLevel(levelIdx)));
      if ((retVal == DCM_E_PENDING) && (vDiagSecAcc_SeedState == VDIAGSECACC_JOBSTATE_OPERATION_PENDING)) /* Pending is equivalent to successful for synchronous call */
      {
        retVal = E_OK;
        vDiagSecAcc_Local_HandleSuccessfulSeedGeneration(Seed, seedLength, &vDiagSecAcc_GetSeedBuffer(vDiagSecAcc_GetSeedBufferStartIdxOfSecurityLevel(levelIdx)));
      }
#else
      /* async seed generation */

      /* Callback for async getSeed */
      if (vDiagSecAcc_SeedCallbackResult != VDIAGSECACC_INVALID_CALLBACK_RESULT)
      {
        vDiagSecAcc_Local_CallbackNotification(vDiagSecAcc_SeedCallbackResult, &vDiagSecAcc_SeedState);
        vDiagSecAcc_SeedCallbackResult = VDIAGSECACC_INVALID_CALLBACK_RESULT;
      }

      /* Handle current seed state */
      switch (vDiagSecAcc_SeedState)
      {
        /* Start generating new seed value */
        case VDIAGSECACC_JOBSTATE_INITIAL:
        {
          retVal = vDiagSecAcc_Local_RequestSeedGeneration(seedLength, &vDiagSecAcc_GetSeedBuffer(vDiagSecAcc_GetSeedBufferStartIdxOfSecurityLevel(levelIdx)));
          break;
        }
        case VDIAGSECACC_JOBSTATE_OPERATION_SUCCESSFUL:
        {
          retVal = E_OK;
          vDiagSecAcc_Local_HandleSuccessfulSeedGeneration(Seed, seedLength, &vDiagSecAcc_GetSeedBuffer(vDiagSecAcc_GetSeedBufferStartIdxOfSecurityLevel(levelIdx)));
          break;
        }
        case VDIAGSECACC_JOBSTATE_OPERATION_FAILED:
        {
          /* Seed generation failed or invalid state */
          /* Allow next seed request */
          vDiagSecAcc_SeedState = VDIAGSECACC_JOBSTATE_INITIAL;
          retVal = E_NOT_OK;
          break;
        }
        /* VDIAGSECACC_JOBSTATE_OPERATION_CANCEL */
        /* VDIAGSECACC_JOBSTATE_OPERATION_PENDING */
        default:
        {
          /* Random number generation not finished yet, try again */
          retVal = DCM_E_PENDING;
          break;
        }
      }

#endif /* VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON) */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDIAGSECACC_MODULE_ID, VDIAGSECACC_INSTANCE_ID, VDIAGSECACC_SID_GET_SEED, errorId);
  }
#else
  VDIAGSECACC_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
                                                                                             /* Set negative response code depending on the return value. */
  if (retVal == E_NOT_OK)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }
  else
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
  }
  return retVal;
  /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
}

/***********************************************************************************************************************
*  vDiagSecAcc_Local_CompareKey
**********************************************************************************************************************/
/*!
*
* Internal comment removed.
 *
 *
 *
 *
*/
FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_CompareKey(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) Key,
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_DCM_VAR) ErrorCode,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDIAGSECACC_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean asyncJob;
  /* ----- Development Error Checks ------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Check plausibility of parameters. */
  errorId = vDiagSecAcc_Local_DevCheck(Key); /* PRQA S 0315 */ /* MD_VDIAGSECACC_P2VOID_CAST */
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    /* errorId is already set */
  }
  else if (levelIdx >= vDiagSecAcc_GetSizeOfSecurityLevel())
  {
    errorId = VDIAGSECACC_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    asyncJob = (boolean)(vDiagSecAcc_IsvDiagSecAccCompareKeyCsmJobRefAsyncOfSecurityLevel(levelIdx));

    /* # Handle DCM OpStatus */
    if (OpStatus == DCM_CANCEL)
    {
      vDiagSecAcc_Local_HandleDcmCancel(asyncJob, &vDiagSecAcc_CompareState);
      retVal = E_OK;
    }
    else
    {
      /* # Handle state machine */
#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_OFF)
      retVal = vDiagSecAcc_Local_DispatchCompareStateSync(Key, levelIdx);
#else
      if (asyncJob)
        /* async job */
      {
        retVal = vDiagSecAcc_Local_DispatchCompareStateAsync(Key, levelIdx);
      }
      else
      {
        /* sync job */
        retVal = vDiagSecAcc_Local_DispatchCompareStateSync(Key, levelIdx);
      }
#endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDIAGSECACC_MODULE_ID, VDIAGSECACC_INSTANCE_ID, VDIAGSECACC_SID_COMPARE_KEY, errorId);
  }
#else
  VDIAGSECACC_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Set negative response code depending on the return value. */
  if (retVal == E_NOT_OK)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }
  else
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
  }

  return retVal;
}

/***********************************************************************************************************************
 *  vDiagSecAcc_InitMemory
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Uninitialize module. */
  vDiagSecAcc_ModuleInitialized = (uint8)VDIAGSECACC_UNINIT;
#endif
}

/***********************************************************************************************************************
 *  vDiagSecAcc_Init
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDIAGSECACC_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component. */
  if (vDiagSecAcc_ModuleInitialized == VDIAGSECACC_INITIALIZED)
  {
    errorId = VDIAGSECACC_E_INIT_FAILED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Initialize CsmJob States for Seed generation and key comparison */
    vDiagSecAcc_SeedState = VDIAGSECACC_JOBSTATE_INITIAL;
    vDiagSecAcc_CompareState = VDIAGSECACC_JOBSTATE_INITIAL;

    /* Initialize CallbackResult */
#if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
    vDiagSecAcc_SeedCallbackResult = VDIAGSECACC_INVALID_CALLBACK_RESULT;
#endif
#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON)
    vDiagSecAcc_SignatureVerificationCallbackResult = VDIAGSECACC_INVALID_CALLBACK_RESULT;
#endif

#if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
    /* Set module state to initialized */
    vDiagSecAcc_ModuleInitialized = (uint8)VDIAGSECACC_INITIALIZED;
#endif
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDIAGSECACC_MODULE_ID, VDIAGSECACC_INSTANCE_ID, (uint8)VDIAGSECACC_SID_INIT, errorId);
  }
#else
  VDIAGSECACC_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

#if (VDIAGSECACC_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vDiagSecAcc_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, VDIAGSECACC_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDIAGSECACC_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Check plausibility of parameters. */
  if (versioninfo == NULL_PTR)
  {
    errorId = VDIAGSECACC_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Write versionInfo pointer with modules versions. */
    versioninfo->vendorID = (uint16)VDIAGSECACC_VENDOR_ID;
    versioninfo->moduleID = (uint16)VDIAGSECACC_MODULE_ID;
    versioninfo->sw_major_version = (uint8)VDIAGSECACC_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)VDIAGSECACC_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)VDIAGSECACC_SW_PATCH_VERSION;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDIAGSECACC_MODULE_ID, VDIAGSECACC_INSTANCE_ID, (uint8)VDIAGSECACC_SID_GET_VERSION_INFO, errorId);
  }
# else
  VDIAGSECACC_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif /* (VDIAGSECACC_VERSION_INFO_API == STD_ON) */

#if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
/***********************************************************************************************************************
 *  vDiagSecAcc_CallbackNotificationRandomGenerate
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_CallbackNotificationRandomGenerate( P2VAR(Crypto_JobType, AUTOMATIC, VDIAGSECACC_APPL_VAR) job, Std_ReturnType result) /* PRQA S 3673 */ /* MD_VDIAGSECACC_AUTOSAR_API */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDIAGSECACC_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Check plausibility of parameters. */
  errorId = vDiagSecAcc_Local_DevCheck(job); /* PRQA S 0315 */ /* MD_VDIAGSECACC_P2VOID_CAST */
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    /* errorId already set */
  }
  else
  /* ----- Implementation ----------------------------------------------- */
# else
  /* ----- Implementation ----------------------------------------------- */
  VDIAGSECACC_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  {
    /* Result of CSM operation */
    vDiagSecAcc_SeedCallbackResult = result;
  }
  /* ----- Development Error Report --------------------------------------- */
# if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDIAGSECACC_MODULE_ID, VDIAGSECACC_INSTANCE_ID, (uint8)VDIAGSECACC_SID_CALLBACKNOTIFICATION_RANDOMGENERATE, errorId);
  }
# else
  VDIAGSECACC_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif /* (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON) */

#if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON)
/***********************************************************************************************************************
 *  vDiagSecAcc_CallbackNotificationCipher
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_CallbackNotificationCipher(P2VAR( Crypto_JobType, AUTOMATIC, VDIAGSECACC_APPL_VAR) job, Std_ReturnType result) /* PRQA S 3673 */ /* MD_VDIAGSECACC_AUTOSAR_API */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDIAGSECACC_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (VDIAGSECACC_DEV_ERROR_DETECT == STD_ON)
  /* # Check plausibility of parameters. */
  errorId = vDiagSecAcc_Local_DevCheck(job);  /* PRQA S 0315 */ /* MD_VDIAGSECACC_P2VOID_CAST */
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    /* errorId already set */
  }
  else
    /* ----- Implementation ----------------------------------------------- */
# else
  /* ----- Implementation ----------------------------------------------- */
  VDIAGSECACC_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  {
    /* Result of CSM operation */
    vDiagSecAcc_SignatureVerificationCallbackResult = result;
  }
  /* ----- Development Error Report --------------------------------------- */
# if (VDIAGSECACC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDIAGSECACC_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDIAGSECACC_MODULE_ID, VDIAGSECACC_INSTANCE_ID, (uint8)VDIAGSECACC_SID_CALLBACKNOTIFICATION_CIPHER, errorId);
  }
# else
  VDIAGSECACC_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

#define VDIAGSECACC_STOP_SEC_CODE
#include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA  violations and justifications
 *********************************************************************************************************************/
/* module specific MISRA deviations:

MD_VDIAGSECACC_GLOBAL_CBK_FUNC:
Description: Rule 8.5: An external object or function shall be declared once in one and only one file
Reason:      MICROSAR Csm declares its callbacks in its Cfg.h. Files that include both Csm.h and vDiagSecAcc_Cbk.h will thus see a double declaration of this callback.
Risk:        Declarations are not identical.
Prevention:  Checked by review that declaration are identical.

MD_VDIAGSECACC_AUTOSAR_API
Reason:     This API signature is specified by AUTOSAR and therefore not changed.
Risk:       None
Prevention: Not necessary

MD_VDIAGSECACC_P2VOID_CAST:
Reason:     The implicit conversion from a pointer to object type to a pointer to void is used
when calling functions that allow pointers to different object types as parameter.
Risk:       There is an invalid conversion within the function from a pointer to void to a pointer to object type
and thus invalid data are read.
Prevention: Code inspection, function only checks for NULL_PTRs.

MD_VDIAGSECACC_CHARACTER_REQUIRED_FOR_VCA:
Reason:     The character is required for the silent analysis with VCA.
Risk:       Potential to cause unexpected program operation
Prevention: Review - Character is only used in comments
 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_VDIAGSECACC_LOCAL_DEFINE
\ACCEPT TX
\REASON VDIAGSECACC_LOCAL and VDIAGSECACC_LOCAL_INLINE is never defined externally.

\ID COV_VDIAGSECACC_MISRA_STATEMENT
\ACCEPT X
\REASON Additional statement required by Misra.

COV_JUSTIFICATION_END */

/* VCA_JUSTIFICATION_BEGIN 

\ID VCA_VDIAGSECACC_CSM_SIGNATUREVERIFY
  \DESCRIPTION  Write access to pointer argument vDiagSecAcc_SignatureVerificationResult.
  \COUNTERMEASURE \N The pointer argument is a pointer to an address referencing a buffer with correct length.

\ID VCA_VDIAGSECACC_CSM_RANDOM_GENERATE
  \DESCRIPTION  Access to vDiagSecAcc_SeedBuffer (globalSeedBuffer) via indirection over SeedBufferLength in vDiagSecAcc_SecurityLevel
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

VCA_JUSTIFICATION_END */
