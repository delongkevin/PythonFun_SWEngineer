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
/*!        \file  vDam.c
 *        \brief  Diagnostic Access Manager
 *
 *      \details  Implementation of the Diagnostic Access Manager
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VDAM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vDam.h"
#include "vDam_Dcm.h"

#ifdef __VCA__ /* COV_VDAM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
# include "vDam_Appl.vcaspecs.h"
#endif

#if (VDAM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (VDAM_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

     /* Check the version of the header file */
#if ( (VDAM_SW_MAJOR_VERSION != (2u)) \
    || (VDAM_SW_MINOR_VERSION != (0u)) \
    || (VDAM_SW_PATCH_VERSION != (2u)))
# error "Vendor specific version numbers of vDam.c and vDam.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (VDAM_LOCAL) /* COV_VDAM_LOCAL_DEFINE */
# define VDAM_LOCAL                                                   static
#endif

#if !defined (VDAM_LOCAL_INLINE) /* COV_VDAM_LOCAL_DEFINE */
# define VDAM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Build an uin16 value from two bytes. */
#define vDam_GetUint16(hiByte, loByte)                                ((uint16)((((uint16)(hiByte)) << 8u) | ((uint16)(loByte))))

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 vDam_AccessRights_SidType;
typedef uint8 vDam_AccessRights_SubFuncType;
typedef uint16 vDam_AccessRights_IdType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define VDAM_START_SEC_VAR_CLEARED_8
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VDAM_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
VDAM_LOCAL VAR(uint8, VDAM_VAR_CLEARED)                 vDam_ModuleInitialized = VDAM_UNINIT;
#endif

#define VDAM_STOP_SEC_VAR_CLEARED_8
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VDAM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VDAM_USE_INIT_POINTER == STD_ON)
VDAM_LOCAL P2CONST(vDam_ConfigType, VDAM_VAR_CLEARED, VDAM_PBCFG) vDam_ConfigDataPtr = NULL_PTR;
#endif

#define VDAM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define VDAM_START_SEC_CODE
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vDam_GetSubfunc()
 **********************************************************************************************************************/
/*!
 * \brief       Gets the sub-function of the requested diagnostic service.
 * \details     This function gets the sub-function of the requested diagnostic service.
 * \param[in]   SID          The service identifier.
 * \param[in]   RequestData  Pointer to the whole data of the current request.
 * \param[in]   DataSize     Length of RequestData in bytes.
 * \param[out]  subFunc      The sub-function of the requested diagnostic service. 0xFF if there is no sub-function.
 * \param[out]  idIdx        Index position in the RequestData where the id can be read.
 * \return      E_OK         SubFunc could be determined successfully
 *              E_NOT_OK     Sub-function could not be determined, e.g. data was to short
 * \pre         subFunc must be a valid pointer.
 * \pre         idIdx must be a valid pointer.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_GetSubfunc(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(vDam_AccessRights_SubFuncType, AUTOMATIC, AUTOMATIC) subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx);

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_IsAllowed()
 **********************************************************************************************************************/
/*!
 * \brief         Check if the currentRole is allowed according to accessRights.
 * \details       -
 * \param[in]     currentRole   Current user Roles (Bit Mask).
 * \param[in]     accessRights  Allowed user Roles (Bit Mask).
 * \return        TRUE  Access allowed.
 *                FALSE Access denied.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
VDAM_LOCAL_INLINE FUNC(boolean, VDAM_CODE) vDam_CheckAccessRights_IsAllowed(
  uint32 currentRole,
  uint32 accessRights);

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_SidSubtable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches the service ID sub-table of the given access control list for the assigned access rights.
 * \details       -
 * \param[in]     sid         The service ID to be searched.
 * \param[out]    serviceIdx  The table index of the found service.
 * \return        E_OK                              The service is allowed according to the user role.
 *                VDAM_E_RIGHTS_CHECKNEXTLEVEL      The service is not allowed on this level.
 *                VDAM_E_RIGHTS_SERVICENOTSUPPORTED The service is not supported, i.e. to be rejected.
 * \pre           serviceIdx must be a valid pointer.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights_SidSubtable(
  vDam_AccessRights_SidType sid,
  P2VAR(vDam_SizeOfServiceInfoType, AUTOMATIC, AUTOMATIC) serviceIdx);

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_SubfuncSubtable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches the service sub-func sub-table of the given access control list for the assigned access rights.
 * \details       -
 * \param[in]     subFunc         The sub service ID to be searched.
 * \param[in]     serviceIdx      The table index of the found service.
 * \param[out]    subServiceIdx   The table index of the found sub-service.
 * \param[in]     currentRole     The current user Role.
 * \return        E_OK                                  The service is allowed according to the user role.
 *                VDAM_E_RIGHTS_CHECKNEXTLEVEL          The service is not allowed on this level.
 *                VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED The service is not supported, i.e. to be rejected.
 * \pre           subServiceIdx must be a valid pointer.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights_SubfuncSubtable(
  vDam_AccessRights_SubFuncType subFunc,
  vDam_SizeOfServiceInfoType serviceIdx,
  P2VAR(vDam_SizeOfSubServiceInfoType, AUTOMATIC, AUTOMATIC) subServiceIdx,
  uint32 currentRole);

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_IdSubtable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches the ID sub-table of the given access control list for the assigned access rights.
 * \details       -
 * \param[in]     id              The ID to be searched.
 * \param[in]     subServiceIdx   The table index of the found sub-service.
 * \param[in]     serviceIdx      The service identifier.
 * \param[in]     currentRole     The current user Role.
 * \return        E_OK                                  The service is allowed according to the user role.
 *                VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed on this level.
 *                VDAM_E_RIGHTS_IDNOTSUPPORTED          The service is not supported, i.e. to be rejected.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights_IdSubtable(
  vDam_AccessRights_IdType id,
  vDam_SizeOfSubServiceInfoType subServiceIdx,
  vDam_SizeOfServiceInfoType serviceIdx,
  uint32 currentRole);

/**********************************************************************************************************************
 *  vDam_CheckSidAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if given service grants access to given user role.
 * \details     -
 * \param[in]   currentRole           The current user Role.
 * \param[in]   serviceIdx            The table index of the found service.
 * \param[in]   noRoleResult          Result which shall be returned if no role restriction is available.
 * \return      E_OK                                  The service is allowed according to the user role.
 *              VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 *              All values from noRoleResult
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckSidAccessRights(
  uint32 currentRole,
  vDam_SizeOfServiceInfoType serviceIdx, 
  Std_ReturnType noRoleResult);

/**********************************************************************************************************************
 *  vDam_CheckSubfuncAndSidAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if given service / sub-service grants access to given user role.
 * \details     If sub-service offers dedicated rights, these rights are used to check the passed role, otherwise
 *              the rigths of the service are considered.
 * \param[in]   currentRole           The current user Role.
 * \param[in]   subServiceIdx         The table index of the found sub-service.
 * \param[in]   serviceIdx            The table index of the found service.
 * \param[in]   noRoleResult          Result which shall be returned if no role restriction is available.
 * \return      E_OK                                  The service is allowed according to the user role.
 *              VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 *              All values from noRoleResult
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckSubfuncAndSidAccessRights(
  uint32 currentRole,
  vDam_SizeOfSubServiceInfoType subServiceIdx,
  vDam_SizeOfServiceInfoType serviceIdx,
  Std_ReturnType noRoleResult);

/**********************************************************************************************************************
 *  vDam_CheckIdentifierAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if given identifier grants access to given user role.
 * \details     -
 * \param[in]   currentRole           The current user Role.
 * \param[in]   identifierIdx         The table index of the found identifier.
 * \return      E_OK                                  The service is allowed according to the user role.
 *              VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckIdentifierAccessRights(
  uint32 currentRole,
  vDam_SizeOfIdentifierInfoType identifierIdx);

/**********************************************************************************************************************
 *  vDam_CheckAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Gets the access rights granted to the user roles for the given diagnostic service.
 * \details     This function searches for the given diagnostic service defined by the triplet SID, sub-function and ID
 *              through the given access control list.
 * \param[in]   sid            The service identifier.
 * \param[in]   subFunc        The sub function of the service. 0xFF if there is no sub-function for the service.
 * \param[in]   id             The DID or RID if of the service.
 * \param[in]   currentRole    The current user Role.
 * \return      E_OK                                  The service is allowed according to the user role.
 *              VDAM_E_RIGHTS_SERVICENOTSUPPORTED     The service is not supported, i.e. to be rejected.
 *              VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED The sub-service is not supported, i.e. to be rejected.
 *              VDAM_E_RIGHTS_IDNOTSUPPORTED          The id is not supported, i.e. to be rejected.
 *              VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights(
  vDam_AccessRights_SidType sid,
  vDam_AccessRights_SubFuncType subFunc,
  vDam_AccessRights_IdType id,
  uint32 currentRole);

/**********************************************************************************************************************
 *  vDam_EvaluateAccessRightsForSid2A()
 **********************************************************************************************************************/
/*!
 * \brief         Evaluates the access rights only for the DynamicallyDefineDataIdentifier service.
 * \details       -
 * \param[in]     RequestData  Pointer to the whole data of the current request.
 * \param[in]     DataSize     Length of RequestData in bytes.
 * \param[in]     subFunc      The sub-function of the service.
 * \param[in,out] idIdx        Index position in the RequestData where the id can be read.
 * \param[in]     currentRole  The current user Role.
 * \return        E_OK                                  The service is allowed according to the user role.
 *                VDAM_E_RIGHTS_SERVICENOTSUPPORTED     The service is not supported, i.e. to be rejected.
 *                VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED The sub-service is not supported, i.e. to be rejected.
 *                VDAM_E_RIGHTS_IDNOTSUPPORTED          The id is not supported, i.e. to be rejected.
 *                VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 * \pre           idIdx must be a valid pointer.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_EvaluateAccessRightsForSid2A(P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize,
  vDam_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  uint32 currentRole);

/**********************************************************************************************************************
 *  vDam_EvaluateAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief         Evaluates the access rights for the requested diagnostic service except of the DynamicallyDefineDataIdentifier service.
 * \details       -
 * \param[in]     SID          Identifier of the requested diagnostic service.
 * \param[in]     RequestData  Pointer to the whole data of the current request.
 * \param[in]     DataSize     Length of RequestData in bytes.
 * \param[in]     subFunc      The sub-function of the service.
 * \param[in,out] idIdx        Index position in the RequestData where the id can be read.
 * \param[out]    ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \param[in]     currentRole  The current user Role.
 * \return        E_OK                                  The service is allowed according to the user role.
 *                E_NOT_OK                              Error occurred, details in ErrorCode.
 *                VDAM_E_RIGHTS_SERVICENOTSUPPORTED     The service is not supported, i.e. to be rejected.
 *                VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED The sub-service is not supported, i.e. to be rejected.
 *                VDAM_E_RIGHTS_IDNOTSUPPORTED          The id is not supported, i.e. to be rejected.
 *                VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 * \pre           idIdx must be a valid pointer.
 * \pre           ErrorCode must be a valid pointer.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_EvaluateAccessRights(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize, vDam_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode,
  uint32 currentRole);

/**********************************************************************************************************************
 *  vDam_EvaluateAccessRightsForDiagService()
 **********************************************************************************************************************/
/*!
 * \brief       Evaluates the access rights for the requested diagnostic service.
 * \details     This function evaluates the access rights for the requested diagnostic service.
 * \param[in]   SID          Identifier of the requested diagnostic service.
 * \param[in]   RequestData  Pointer to the whole data of the current request.
 * \param[in]   DataSize     Length of RequestData in bytes.
 * \param[out]  ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \param[in]   currentRole  The current user Role.
 * \return      E_OK                                  The service is allowed according to the user role.
 *              E_NOT_OK                              Error occurred, details in ErrorCode.
 *              VDAM_E_RIGHTS_SERVICENOTSUPPORTED     The service is not supported, i.e. to be rejected.
 *              VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED The sub-service is not supported, i.e. to be rejected.
 *              VDAM_E_RIGHTS_IDNOTSUPPORTED          The id is not supported, i.e. to be rejected.
 *              VDAM_E_RIGHTS_SECURITYACCESSDENIED    The service is not allowed.
 * \pre         ErrorCode must be a valid pointer.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VDAM_LOCAL_INLINE FUNC(uint8, VDAM_CODE) vDam_EvaluateAccessRightsForDiagService(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode,
  uint32 currentRole);

/***********************************************************************************************************************
 *  vDam_Local_ServiceRole_Indication_InternalErrorStateEvaluation
 **********************************************************************************************************************/
/*!
 * \brief        Mapps the internal error states of vDam to negative response codes which are returned to DCM.
 * \details      This subfunction is used by vDam_Local_ServiceRole_Indication. It receives the internal error state
 *               of vDam and the prefilled errCode. Depending on the internal error state, either the value of
 *               errCode is returned or another negative response code.
 * \param[in]    internalErrorState  Internal error state of vDam to be evaluated
 * \param[in]    errCode    Prefilled negative response code if internal error state is E_NOT_OK
 * \return       DCM_E_POSITIVERESPONSE                       The service is allowed according to the user role.
 *               DCM_E_SECURITYACCESSDENIED                   The service is not allowed.
 *               DCM_E_SERVICENOTSUPPORTED                    The service is not supported, i.e. to be rejected.
 *               DCM_E_SUBFUNCTIONNOTSUPPORTED                The sub-service is not supported, i.e. to be rejected.
 *               DCM_E_REQUESTOUTOFRANGE                      The id (DDID, RID) is not contained in the access control lists
 *               DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT  Message contains no Ids and the transmission mode is not "stop all"
 * \pre          -
 * \context      TASK
 * \reentrant    TRUE
 * \synchronous  TRUE
 */
VDAM_LOCAL FUNC(Dcm_NegativeResponseCodeType, VDAM_CODE) vDam_Local_ServiceRole_Indication_InternalErrorStateEvaluation(
  vDam_InternalErrorStateType internalErrorState,
  Dcm_NegativeResponseCodeType errCode);

/***********************************************************************************************************************
 *  vDam_Local_ServiceRole_Indication
 **********************************************************************************************************************/
/*!
 * \brief         Performs manufacturer or supplier specific validations on a diagnostic service request.
 * \details       This function checks if the service is allowed according to user role and is a request from the DCM
 *                to the application to validate the received diagnostic service, additionally to the DCM internal
 *                validation.
 *                If the manufacturer specific verification is used the vDam checks the service at an early point of
 *                processing. If the supplier specific verification is used the vDam checks the service at a later
 *                point of processing. More information for the manufacturer and supplier specific verification can
 *                be found in the Dcm Technical Reference and the diagnostic ISO.
 *                The customer can decide at which time the vDam shall check the service. The early verification is
 *                preferred from security point of view to give the caller as little information as possible.
 *                This function checks if the service is allowed according to user role.
 * \param[in]     SID                         Contains the diagnostic service Id
 * \param[in]     RequestData                 Points to the request data. Points behind the service Id byte
 * \param[in]     DataSize                    Specifies the requested data length (without the SID byte)
 * \param[in]     SourceAddress               Contains the diagnostic client source address
 * \param[out]    ErrorCode                   NRC to be sent in the negative response in case of failure (E_NOT_OK)
 * \return        E_OK                        The operation is finished
 * \return        E_NOT_OK                    The operation has failed
 *                                            A concrete NRC shall be set, otherwise the DCM sends NRC 0x22
 * \pre           ErrorCode must be a valid pointer.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_Local_ServiceRole_Indication(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_DCM_VAR) RequestData,
  uint16 DataSize,
  uint16 SourceAddress,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) ErrorCode);

#define VDAM_STOP_SEC_CODE
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VDAM_START_SEC_CODE
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vDam_GetSubfunc()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_GetSubfunc(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(vDam_AccessRights_SubFuncType, AUTOMATIC, AUTOMATIC) subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx)
{
  Std_ReturnType retVal = E_NOT_OK;
  *subFunc = VDAM_NO_SUB_FUNCTION;

   /* By default the id has to be read out at position 0. */
  *idIdx = 0u;

   /* #10 Filter for service identifiers depending on the position of the sub-function in the request data buffer. */
  switch (SID)
  {
    case 0x10:
    case 0x11:
    case 0x19:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2C:
    case 0x2A:
    case 0x31:
    case 0x3E:
    case 0x83:
    case 0x85:
    case 0x86:
    case 0x87:
    {
    /* #20 The services 0x10, 0x11, 0x19, 0x27, 0x28, 0x29, 0x2C, 0x2A, 0x31, 0x3E, 0x83, 0x85, 0x86, 0x87 have a sub-function
 * at position 0. Service 0x31 has an ID in addition. */

     /* The id has to be read out at position 1. */
      *idIdx = 1u;

      if (((SID != 0x31u) && (DataSize >= 1u)) || (DataSize >= 3u))
      {
        /* #25 To blind out the suppressPositiveResponse bit, the byte containing the sub-function
        parameter shall be calculated as "byte value AND 0x7F". */
        *subFunc = (vDam_AccessRights_SubFuncType)(RequestData[0] & 0x7Fu);
        retVal = E_OK;
      }
      break;
    }
    case 0x22:
    case 0x24:
    case 0x2E:
    {
    /* #30 The service 0x22, 0x24, 0x2E have an ID (requiring two bytes). */
      if (DataSize >= 2u)
      {
        retVal = E_OK;
      }
      break;
    }
    case 0x2Fu:
    {
    /* #40 The service 0x2F has the so-called IOCP (InputOutput Control Parameter) at position 2 (handled like sub-function). */
      if (DataSize >= 3u)
      {
        *subFunc = (vDam_AccessRights_SubFuncType)(RequestData[2]);
        retVal = E_OK;
      }
      break;
    }
    default:
    {
    /* #50 All other services have no sub-function but an ID, i.e. sub-function must be skipped and id has to be read out at position 0. */
    /* 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x14, 0x23, 0x34, 0x35, 0x36, 0x37, 0x38, 0x3D, 0x84, 0xB2, 0xB6, 0xB7 */
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_IsAllowed()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(boolean, VDAM_CODE) vDam_CheckAccessRights_IsAllowed(uint32 currentRole, uint32 accessRights)
{
  boolean allowed = FALSE;
  /* # Check if Right and Role are matching. */
  if ((accessRights & currentRole) != 0u)
  {
    allowed = TRUE;
  }
  return allowed;
}

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_SidSubtable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights_SidSubtable(
  vDam_AccessRights_SidType sid,
  P2VAR(vDam_SizeOfServiceInfoType, AUTOMATIC, AUTOMATIC) serviceIdx)
{
  Std_ReturnType retVal = VDAM_E_RIGHTS_SERVICENOTSUPPORTED;
  vDam_SizeOfServiceInfoType left, middle, right;

  left = 0u;
  right = vDam_GetSizeOfServiceInfo();

  /* Search as long as there is something to search in. */
  while (left < right)
  {
    middle = left + ((vDam_SizeOfServiceInfoType)(right - left) / 2u); /* Divide in half.  */
    if (vDam_GetServiceIdOfServiceInfo(middle) > sid)
    {
      right = middle;     /* Search in left part. */
    }
    else if (vDam_GetServiceIdOfServiceInfo(middle) < sid)
    {
      left = middle + 1u;      /* Search in right part. */
    }
    else
    {
      /* Middle is it. */
      /* SID is available */
      *serviceIdx = middle;
      retVal = VDAM_E_RIGHTS_CHECKNEXTLEVEL;
      /* SID has been found. Leave loop. */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vDam_CheckAccessRights_SubfuncSubtable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights_SubfuncSubtable(
  vDam_AccessRights_SubFuncType subFunc,
  vDam_SizeOfServiceInfoType serviceIdx,
  P2VAR(vDam_SizeOfSubServiceInfoType, AUTOMATIC, AUTOMATIC) subServiceIdx,
  uint32 currentRole)
{
  Std_ReturnType retVal = VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED;
  vDam_SizeOfSubServiceInfoType left, middle, right;

  if (vDam_IsSubServiceInfoUsedOfServiceInfo(serviceIdx))
  {

    left = vDam_GetSubServiceInfoStartIdxOfServiceInfo(serviceIdx);
    right = vDam_GetSubServiceInfoEndIdxOfServiceInfo(serviceIdx);

    /* Search as long as there is something to search in. */
    while (left < right)
    {
      middle = left + ((vDam_SizeOfSubServiceInfoType)(right - left) / 2u); /* Divide in half.  */
      if (vDam_GetSubServiceIdOfSubServiceInfo(middle) > subFunc)
      {
        right = middle;     /* Search in left part. */
      }
      else if (vDam_GetSubServiceIdOfSubServiceInfo(middle) < subFunc)
      {
        left = middle + 1u;      /* Search in right part. */
      }
      else
      {
        /* Middle is it. */
        /* Subservice is available. */
        *subServiceIdx = middle;
        retVal = VDAM_E_RIGHTS_CHECKNEXTLEVEL;
        /* Sub-func has been found. Leave loop. */
        break;
      }
    }
    /* SSID not found */
    if (retVal == VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED)
    {
      /* Check if we have ID configuration without SSID */
      if (vDam_GetSubServiceIdOfSubServiceInfo(vDam_GetSubServiceInfoEndIdxOfServiceInfo(serviceIdx) - 1u) == 0xFFu)
      {
        /* check if subfunction can be available, but is not generated and marked as 0xFF */
        *subServiceIdx = vDam_GetSubServiceInfoEndIdxOfServiceInfo(serviceIdx) - (uint8)1u;
        retVal = VDAM_E_RIGHTS_CHECKNEXTLEVEL;
      }
      else
      {
        /* No subfunctions not found, check access rights for SID */
        retVal = vDam_CheckSidAccessRights(currentRole, serviceIdx, VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED);
      }
    }
  }
  else
  {
    /* No subfunctions and Ids available, check access rights for SID */
    retVal = vDam_CheckSidAccessRights(currentRole, serviceIdx, VDAM_E_RIGHTS_SERVICENOTSUPPORTED);
  }

  return retVal;
}

  /**********************************************************************************************************************
 *  vDam_CheckAccessRights_IdSubtable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights_IdSubtable(  /* PRQA S 6080 */ /* MD_MSR_STMIF */
  vDam_AccessRights_IdType id,
  vDam_SizeOfSubServiceInfoType subServiceIdx,
  vDam_SizeOfServiceInfoType serviceIdx,
  uint32 currentRole)
{
  Std_ReturnType retVal = VDAM_E_RIGHTS_IDNOTSUPPORTED;
  vDam_SizeOfIdentifierInfoType left, middle, right;

  if (vDam_IsIdentifierInfoUsedOfSubServiceInfo(subServiceIdx))
  {

    left = vDam_GetIdentifierInfoStartIdxOfSubServiceInfo(subServiceIdx);
    right = vDam_GetIdentifierInfoEndIdxOfSubServiceInfo(subServiceIdx);

    /* Search as long as there is something to search in. */
    while (left < right)
    {
      middle = left + ((vDam_SizeOfIdentifierInfoType)(right - left) / 2u); /* Divide in half.  */
      if (vDam_GetIdentifierIdOfIdentifierInfo(middle) > id)
      {
        right = middle;     /* Search in left part. */
      }
      else if (vDam_GetIdentifierIdOfIdentifierInfo(middle) < id)
      {
        left = middle + 1u;      /* Search in right part. */
      }
      else
      {
        /* Middle is it. */

        /* Service is available, check if Access is allowed. */
        retVal = vDam_CheckIdentifierAccessRights(currentRole, middle);

        /* ID has been found. Leave loop. */
        break;
      }
    }

    if (retVal == VDAM_E_RIGHTS_IDNOTSUPPORTED)
    {
      /* Id was not found, check access rights for subfunction and sid */
      retVal = vDam_CheckSubfuncAndSidAccessRights(currentRole, subServiceIdx, serviceIdx, VDAM_E_RIGHTS_IDNOTSUPPORTED);
    }
  }
  else
  {
    /* no Ids available, check access rights for subfunction and sid */
    retVal = vDam_CheckSubfuncAndSidAccessRights(currentRole, subServiceIdx, serviceIdx, VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vDam_CheckSidAccessRights()
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckSidAccessRights(
  uint32 currentRole,
  vDam_SizeOfServiceInfoType serviceIdx,
  Std_ReturnType noRoleResult)
{
  Std_ReturnType retVal = noRoleResult;
  if (vDam_IsServiceRolesValidOfServiceInfo(serviceIdx))
  {
    if (vDam_CheckAccessRights_IsAllowed(currentRole, vDam_GetServiceRolesOfServiceInfo(serviceIdx)))
    {
      retVal = E_OK;
    }
    else
    {
      retVal = VDAM_E_RIGHTS_SECURITYACCESSDENIED;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vDam_CheckSubfuncAndSidAccessRights()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckSubfuncAndSidAccessRights(
  uint32 currentRole,
  vDam_SizeOfSubServiceInfoType subServiceIdx,
  vDam_SizeOfServiceInfoType serviceIdx,
  Std_ReturnType noRoleResult)
{
  Std_ReturnType retVal = noRoleResult;
  if (vDam_IsSubServiceRolesValidOfSubServiceInfo(subServiceIdx))
  {
    if (vDam_CheckAccessRights_IsAllowed(currentRole, vDam_GetSubServiceRolesOfSubServiceInfo(subServiceIdx)))
    {
      retVal = E_OK;
    }
    else
    {
      retVal = VDAM_E_RIGHTS_SECURITYACCESSDENIED;
    }
  }
  else
  {
   /* Check the upper level if there is no valid role on this level. */
    retVal = vDam_CheckSidAccessRights(currentRole, serviceIdx, noRoleResult);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vDam_CheckIdentifierAccessRights()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckIdentifierAccessRights(
  uint32 currentRole,
  vDam_SizeOfIdentifierInfoType identifierIdx)
{
  Std_ReturnType retVal = VDAM_E_RIGHTS_SECURITYACCESSDENIED;

  if (vDam_CheckAccessRights_IsAllowed(currentRole, vDam_GetIdentifierRolesOfIdentifierInfo(identifierIdx)))
  {
    retVal = E_OK;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  vDam_CheckAccessRights()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_CheckAccessRights(
  vDam_AccessRights_SidType sid,
  vDam_AccessRights_SubFuncType subFunc,
  vDam_AccessRights_IdType id,
  uint32 currentRole)
{
  Std_ReturnType retVal;
  vDam_SizeOfServiceInfoType serviceIdx = 0u;
  vDam_SizeOfSubServiceInfoType subServiceIdx = 0u;

  /* #22 Check service ID table. */
  retVal = vDam_CheckAccessRights_SidSubtable(sid, &serviceIdx);

  /* #24 If SID supported and if the service ID tables refers to sub-function table check the sub-function table. */
  if (retVal == VDAM_E_RIGHTS_CHECKNEXTLEVEL)
  {
    retVal = vDam_CheckAccessRights_SubfuncSubtable(subFunc, serviceIdx, &subServiceIdx, currentRole);
  }

  /* #26 If sub-func supported and if the sub-function table refers to the ID table check the ID table. */
  if (retVal == VDAM_E_RIGHTS_CHECKNEXTLEVEL)
  {
    retVal = vDam_CheckAccessRights_IdSubtable(id, subServiceIdx, serviceIdx, currentRole);
  }

  /* #30 Finally return the access rights granted to the user-roles. */
  return retVal;
}

/**********************************************************************************************************************
 *  vDam_EvaluateAccessRightsForSid2A()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_EvaluateAccessRightsForSid2A(
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize,
  vDam_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  uint32 currentRole)
{
  Std_ReturnType retVal;
  vDam_AccessRights_IdType id = 0xFFFFu;

  /* #10 Extract the ID from the RequestData. Though some services might not have an ID, compose an ID which is without
   * any effect since the ACL list does not have an ID in these cases. */
  if (DataSize > *idIdx)
  {
    id = (vDam_AccessRights_IdType)0xF200u | RequestData[*idIdx];
    *idIdx += 1u;
  }

  /* #20 Check for service defined by SID, sub-func and ID if access right is granted. */
  retVal = vDam_CheckAccessRights(0x2A, subFunc, id, currentRole);

  if ((retVal == VDAM_E_RIGHTS_IDNOTSUPPORTED) && (id == 0xFFFFu))
  {
    retVal = VDAM_E_RIGHTS_INVALID_REQUESTDATA;
  }

  {
    Std_ReturnType loopError = retVal;
    /* #30 Iterate for the service 0x2A through the remaining data and check the identifiers. */
    /* Continue ID processing until an ID is not granted. */
    while ((loopError <= VDAM_E_RIGHTS_STOP_SEARCHING) && (*idIdx < DataSize))
    {
      /* #31 Get the ID. */
      id = (vDam_AccessRights_IdType)0xF200u | RequestData[*idIdx];
      /* step-size is 1 */
      *idIdx += 1u;
      /* #32 Check if access right is granted. */
      loopError = vDam_CheckAccessRights(0x2A, subFunc, id, currentRole);

      if (loopError > retVal)
      {
        retVal = loopError;
      }
    }
  }

  /* #40 Return the return value for the check if access right is granted. */
  return retVal;
}

/**********************************************************************************************************************
 *  vDam_EvaluateAccessRights()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(Std_ReturnType, VDAM_CODE) vDam_EvaluateAccessRights(  /* PRQA S 6060 */ /* MD_MSR_STPAR */
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize, vDam_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode,
  uint32 currentRole)
{
  Std_ReturnType retVal;
  vDam_AccessRights_IdType id;

  /* #10 Extract the ID from the RequestData. Though some services might not have an ID, compose an ID which is without
   * any effect since the ACL list does not have an ID in these cases. */
  if (DataSize > (*idIdx + 1u))
  {
    id = vDam_GetUint16(RequestData[*idIdx], RequestData[*idIdx + 1u]);
    /* step-size is 2 */
    *idIdx += 2u;
  }
  else
  {
    id = 0xFFFFu;
  }

  /* #20 Check for service defined by SID, sub-func and ID if access right is granted. */
  retVal = vDam_CheckAccessRights(SID, subFunc, id, currentRole);

  /* #30 Iterate for the service 0x22 through the remaining data and check the identifiers. */
  if (SID == 0x22u)
  {
    vDam_InternalErrorStateType loopError = retVal;

    /* Continue ID processing until an ID is not granted. */
    while ((loopError <= VDAM_E_RIGHTS_STOP_SEARCHING) && (*idIdx < DataSize))
    {
      if (DataSize > (*idIdx + 1u))
      {
        /* #31 Get the ID. */
        id = vDam_GetUint16(RequestData[*idIdx], RequestData[*idIdx + 1u]);
        /* step-size is 2 */
        *idIdx += 2u;
        /* #32 Check if access right is granted. */
        loopError = vDam_CheckAccessRights(SID, subFunc, id, currentRole);

        if (loopError > retVal)
        {
          retVal = loopError;
        }
      }
      else
      {
        /* No ID could be read. */
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        loopError = VDAM_E_RIGHTS_INVALID_REQUESTDATA;
        retVal = E_NOT_OK;
      }
    }
  }

  /* #50 Return the return value for the check if access right is granted. */
  return retVal;
}

/**********************************************************************************************************************
 *  vDam_EvaluateAccessRightsForDiagService()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VDAM_LOCAL_INLINE FUNC(uint8, VDAM_CODE) vDam_EvaluateAccessRightsForDiagService(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode,
  uint32 currentRole)
{
  Std_ReturnType retVal;
  vDam_AccessRights_SubFuncType subFunc;
  uint16 idIdx = 0u;

  /* #10 Get the sub-function resp. the IOCP of the requested diagnostic service. */
  retVal = vDam_GetSubfunc(SID, RequestData, DataSize, &subFunc, &idIdx);
  if (retVal == E_NOT_OK)
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else if (SID == 0x2Au)
  {
    retVal = vDam_EvaluateAccessRightsForSid2A(RequestData, DataSize, subFunc, &idIdx, currentRole);
  }
  else
  {
    /* #20 Check access right. */
    retVal = vDam_EvaluateAccessRights(SID, RequestData, DataSize, subFunc, &idIdx, ErrorCode, currentRole);
  }

  return retVal;
}

/***********************************************************************************************************************
 *  vDam_Local_ServiceRole_Indication_InternalErrorStateEvaluation
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VDAM_LOCAL FUNC(Dcm_NegativeResponseCodeType, VDAM_CODE) vDam_Local_ServiceRole_Indication_InternalErrorStateEvaluation(
  vDam_InternalErrorStateType internalErrorState,
  Dcm_NegativeResponseCodeType errCode)
{
  Dcm_NegativeResponseCodeType retVal;

  switch (internalErrorState)
  {
    case VDAM_E_RIGHTS_SECURITYACCESSDENIED:
    {
      /* Set negative response code to "security access denied" if the requested diagnostic service is
      * contained in the access control lists but not available for the current Diagnostic Channel. */
      retVal = DCM_E_SECURITYACCESSDENIED;
      break;
    }
    case VDAM_E_RIGHTS_SERVICENOTSUPPORTED:
    {
      /* Set negative response code to "security not supported" if the requested diagnostic service is not
      * contained in the access control lists. */
    
      retVal = DCM_E_SERVICENOTSUPPORTED;
      break;
    }
    case VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED:
    {
      /* Set negative response code to "sub-function not supported" if the requested diagnostic sub function is not
      * contained in the access control lists. */
      retVal = DCM_E_SUBFUNCTIONNOTSUPPORTED;
      break;
    }
    case VDAM_E_RIGHTS_IDNOTSUPPORTED:
    {
      /* Set negative response code to "request out of range" if the requested diagnostic id (DDID, RID) is not
      * contained in the access control lists. */
      retVal = DCM_E_REQUESTOUTOFRANGE;
      break;
    }
    case VDAM_E_RIGHTS_INVALID_REQUESTDATA:
    {
      /* Only relevant for SID=0x2A. Set negative response code to "invalid message",
      * if the message contains no Ids and the transmission mode is not "stop all". */
      retVal = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      break;
    }
    default:
    {
      /* Accept the requested diagnostic service only if no error occurred. */
      retVal = errCode;
      break;
    }
  }

  return retVal;
}

/***********************************************************************************************************************
 *  vDam_Local_ServiceRole_Indication
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
VDAM_LOCAL FUNC(Std_ReturnType, VDAM_CODE) vDam_Local_ServiceRole_Indication(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_DCM_VAR) RequestData,
  uint16 DataSize,
  uint16 SourceAddress,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) ErrorCode)
{
  /* ----- Local Variables ---------------------------------------------- */

  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  vDam_InternalErrorStateType internalErrorState = E_NOT_OK;
  Dcm_NegativeResponseCodeType errCode = DCM_E_POSITIVERESPONSE;
  uint32 userRole;
  P2FUNC(Std_ReturnType, VDAM_APPL_CODE, userRoleCalloutFunc) ( uint16 TesterSourceAddress, P2VAR(uint32, AUTOMATIC, AUTOMATIC) userRole );

  /* Get Current User Role */
  userRoleCalloutFunc = vDam_GetFuncOfUserRoleCallout();

#ifdef __VCA__ /* COV_VDAM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
  userRoleCalloutFunc = Vcastub_Appl_vDamUserRoleCalloutFunc;
#endif

  if (userRoleCalloutFunc(SourceAddress, &userRole) == E_OK)
  {
    /* #40 Evaluate the access rights for the requested diagnostic service. */
    internalErrorState = vDam_EvaluateAccessRightsForDiagService(SID, RequestData, DataSize, &errCode, userRole);
  }
  else
  {
    errCode = DCM_E_GENERALREJECT;
  }

  /* #80 Set the negative return code depending on which error occurred. */
  if (internalErrorState != E_OK)
  {
    *ErrorCode = vDam_Local_ServiceRole_Indication_InternalErrorStateEvaluation(internalErrorState, errCode);

#if (vDam_GetServiceConfigurationStrategyOfGeneral() == VDAM_DENY_NOT_CONFIGURED)
    /* do nothing, retVal already set to  E_NOT_OK */
#elif (vDam_GetServiceConfigurationStrategyOfGeneral() == VDAM_ALLOW_NOT_CONFIGURED_SERVICE)
    if (*ErrorCode == DCM_E_SERVICENOTSUPPORTED)
    {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
    }
#else /* VDAM_ALLOW_NOT_CONFIGURED */
    if ((*ErrorCode == DCM_E_SERVICENOTSUPPORTED) || (*ErrorCode == DCM_E_SUBFUNCTIONNOTSUPPORTED) || (*ErrorCode == DCM_E_REQUESTOUTOFRANGE))
    {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
    }
#endif
  }
  else
  {
    retVal = internalErrorState;
  }

  /* Replace DCM_E_SECURITYACCESSDENIED with DCM_E_REQUESTOUTOFRANGE to be compliant with the specification rather than ISO 14229 */
  if (*ErrorCode == DCM_E_SECURITYACCESSDENIED)
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
  }

  /* #100 Provide callout for custom remapping of NRC */
#if (VDAM_CUSTOMREMAPNRCCALLOUTFUNCOFGENERAL == STD_ON)
  {
    P2FUNC(void, VDAM_APPL_CODE, nrcRemappingCalloutFunc) (uint8 SID, Std_ReturnType intErrorCode, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) errorCode);
    nrcRemappingCalloutFunc = vDam_GetCustomRemapNrcCalloutFuncOfGeneral();

#ifdef __VCA__ /* COV_VDAM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
    nrcRemappingCalloutFunc = Vcastub_Appl_vDamRemapNrcCalloutFunc;
#endif

    nrcRemappingCalloutFunc(SID, internalErrorState, ErrorCode);
  }
#endif

  if (*ErrorCode == DCM_E_POSITIVERESPONSE)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  vDam_InitMemory
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, VDAM_CODE) vDam_InitMemory(void)
{
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
  /* # Uninitialize module. */
  vDam_ModuleInitialized = (uint8)VDAM_UNINIT;
#endif
}

/***********************************************************************************************************************
 *  vDam_Init
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VDAM_CODE) vDam_Init(P2CONST(vDam_ConfigType, AUTOMATIC, VDAM_APPL_DATA) configPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDAM_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* # Check initialization state of the component. */
#if (VDAM_USE_INIT_POINTER == STD_ON)
  if (configPtr == NULL_PTR)
  {
# if (VDAM_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
    EcuM_BswErrorHook((uint16)VDAM_MODULE_ID, (uint8)ECUM_BSWERROR_NULLPTR);
# endif
    errorId = VDAM_E_PARAM_POINTER;
  }
# if(VDAM_CONFIGURATION_VARIANT == VDAM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
  else if(configPtr->FinalMagicNumberOfPBConfig != VDAM_FINAL_MAGIC_NUMBER)
  {
#  if (VDAM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_VDAM_POSTBUILD_ECUM_BSW_ERROR_HOOK */
    EcuM_BswErrorHook((uint16)VDAM_MODULE_ID, (uint8)ECUM_BSWERROR_MAGICNUMBER);
#  endif
  }
  else if (configPtr->GeneratorCompatibilityVersionOfPBConfig != vDam_GetExpectedCompatibilityVersion())
  {
#  if (VDAM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_VDAM_POSTBUILD_ECUM_BSW_ERROR_HOOK */
    EcuM_BswErrorHook((uint16)VDAM_MODULE_ID, (uint8)ECUM_BSWERROR_COMPATIBILITYVERSION);
#  endif
  }
# endif
  else
#endif
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
  if (vDam_ModuleInitialized == VDAM_INITIALIZED)
  {
    errorId = VDAM_E_INIT_FAILED;
  }
  else
# if (VDAM_USE_INIT_POINTER == STD_OFF)
  if (configPtr != NULL_PTR)
  {
     errorId = VDAM_E_PARAM_CONFIG;
  }
  else
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if (VDAM_USE_INIT_POINTER == STD_ON)
    vDam_ConfigDataPtr = configPtr;
# endif
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
    /* Set module state to initialized */
    vDam_ModuleInitialized = (uint8)VDAM_INITIALIZED;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VDAM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDAM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDAM_MODULE_ID,
                          VDAM_INSTANCE_ID,
                          (uint8)VDAM_SID_INIT,
                          errorId);
  }
#else
  VDAM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VDAM_DUMMY_STATEMENT(configPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/**********************************************************************************************************************
  vDam_DeInit
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VDAM_CODE) vDam_DeInit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDAM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
  if(vDam_ModuleInitialized != (uint8)VDAM_INITIALIZED)
  {
    errorId = VDAM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
    vDam_ModuleInitialized = (uint8)VDAM_UNINIT;
#endif
#if(VDAM_USE_INIT_POINTER == STD_ON)
    vDam_ConfigDataPtr = NULL_PTR;
#endif
  }

#if(VDAM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VDAM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDAM_MODULE_ID,
                          VDAM_INSTANCE_ID,
                          (uint8)VDAM_SID_DE_INIT,
                          errorId);
  }
#else
  VDAM_DUMMY_STATEMENT(errorId);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

#if (VDAM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vDam_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VDAM_CODE) vDam_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, VDAM_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDAM_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */

  /* # Check plausibility of parameters. */
# if (VDAM_DEV_ERROR_DETECT == STD_ON)
  if (versioninfo == NULL_PTR)
  {
    errorId = VDAM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Write versionInfo pointer with modules versions. */
    versioninfo->vendorID = (uint16)VDAM_VENDOR_ID;
    versioninfo->moduleID = (uint16)VDAM_MODULE_ID;
    versioninfo->sw_major_version = (uint8)VDAM_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)VDAM_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)VDAM_SW_PATCH_VERSION;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VDAM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDAM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDAM_MODULE_ID,
                          VDAM_INSTANCE_ID,
                          (uint8)VDAM_SID_GET_VERSION_INFO,
                          errorId);
  }
# else
  VDAM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif /* (VDAM_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
 *  vDam_ServiceRole_Indication
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VDAM_CODE) vDam_ServiceRole_Indication(  /* PRQA S 6060 */ /* MD_MSR_STPAR */
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_DCM_VAR) RequestData,
  uint16 DataSize,
  uint8 ReqType,
  uint16 SourceAddress,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) ErrorCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDAM_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  /* #1 Check plausibility of parameters. */
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
  if (vDam_ModuleInitialized != VDAM_INITIALIZED)
  {
    errorId = VDAM_E_UNINIT;
  }
  else if (RequestData == NULL_PTR)
  {
    errorId = VDAM_E_PARAM_POINTER;
  }
  else if (ErrorCode == NULL_PTR)
  {
    errorId = VDAM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
  /* #2 Handle Service Indication. */
    retVal = vDam_Local_ServiceRole_Indication(SID, RequestData, DataSize, SourceAddress, ErrorCode);
    VDAM_DUMMY_STATEMENT_CONST(ReqType); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VDAM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDAM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDAM_MODULE_ID,
                          VDAM_INSTANCE_ID,
                          VDAM_SID_SERVICE_ROLE_INDICATION,
                          errorId);
  }
#else
  VDAM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
}

/***********************************************************************************************************************
 *  vDam_ServiceRole_Confirmation
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VDAM_CODE) vDam_ServiceRole_Confirmation(
  uint8 SID,
  uint8 ReqType,
  uint16 SourceAddress,
  Dcm_ConfirmationStatusType ConfirmationStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VDAM_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  /* #1 Check plausibility of parameters. */
#if (VDAM_DEV_ERROR_DETECT == STD_ON)
  if (vDam_ModuleInitialized != VDAM_INITIALIZED)
  {
    errorId = VDAM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #2 Default return value is set to E_OK. */
    retVal = E_OK;
    VDAM_DUMMY_STATEMENT_CONST(SID); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    VDAM_DUMMY_STATEMENT_CONST(ReqType); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    VDAM_DUMMY_STATEMENT_CONST(SourceAddress); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    VDAM_DUMMY_STATEMENT_CONST(ConfirmationStatus); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VDAM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VDAM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)VDAM_MODULE_ID,
                          VDAM_INSTANCE_ID,
                          VDAM_SID_SERVICE_ROLE_CONFIRMATION,
                          errorId);
  }
#else
  VDAM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

#define VDAM_STOP_SEC_CODE
#include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

  /* COV_JUSTIFICATION_BEGIN

  \ID COV_VDAM_LOCAL_DEFINE
    \ACCEPT TX
    \REASON VDAM_LOCAL and VDAM_LOCAL_INLINE is never defined externally.

  \ID COV_VDAM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB
    \ACCEPT TX
    \REASON For VCA analysis, stubs for user-configured callout and callback functions are used in order to properly
    simulate their parameter requirements, side-effects and results.

  \ID COV_VDAM_POSTBUILD_ECUM_BSW_ERROR_HOOK
    \ACCEPT TX
    \REASON BSW error hook is always used when postbuild loadable is configured. Check for magic number and generator
    compatibility is only executed for postbuild loadable.

  COV_JUSTIFICATION_END */
