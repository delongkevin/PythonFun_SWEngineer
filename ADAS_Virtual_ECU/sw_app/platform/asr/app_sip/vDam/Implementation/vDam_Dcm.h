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
/*!        \file  vDam_Dcm.h
 *        \brief  Diagnostic Access Manager Dcm Callouts
 *
 *      \details  Declaration of Callouts for Dcm
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VDAM_CBK_H)
# define VDAM_CBK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vDam_Cfg.h"
# include "Dcm_Types.h"

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

# define VDAM_START_SEC_CODE
# include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  vDam_ServiceRole_Indication
 **********************************************************************************************************************/
/*!
 * \brief         Performs manufacturer or supplier specific validations on a diagnostic service request.
 * \details       This function checks if the service is allowed according to user role and is a request from the DCM
 *                to the application to validate the received diagnostic service, additionally to the DCM internal
 *                validation.
 *                This function can be configured as DCM manufacturer notification or DCM supplier notification.
 *                The manufacturer specific verification checks the service at an early point of processing.
 *                The supplier specific verification checks the service at a later point of processing. This results
 *                in more checks being performed by the Dcm. More information for the manufacturer and supplier
 *                specific verification can be found in the Dcm Technical Reference and the diagnostic ISO.
 *                The customer can decide at which time the vDam shall check the service. The early verification is
 *                preferred from security point of view to give the caller as little information as possible.
 * \param[in]     SID                         Contains the diagnostic service Id
 * \param[in]     RequestData                 Points to the request data. Points behind the service Id byte
 * \param[in]     DataSize                    Specifies the requested data length (without the SID byte)
 * \param[in]     ReqType                     Specifies the diagnostic request type:
 *                                            0 - physical request
 *                                            1 - functional request
 * \param[in]     SourceAddress               Contains the diagnostic client source address
 * \param[out]    ErrorCode                   NRC to be sent in the negative response in case of failure (E_NOT_OK)
 *                                            DCM_E_SECURITYACCESSDENIED
 *                                            DCM_E_SERVICENOTSUPPORTED
 *                                            DCM_E_SUBSERVICENOTSUPPORTED
 *                                            DCM_E_REQUESTOUTOFRANGE
 *                                            DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
 * \return        E_OK                        The operation is finished
 * \return        E_NOT_OK                    The operation has failed. Access to the service is denied.
 *                                            The reason for denial is specified in the ErrorCode.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, VDAM_CODE) vDam_ServiceRole_Indication(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, VDAM_DCM_VAR) RequestData,
  uint16 DataSize,
  uint8 ReqType,
  uint16 SourceAddress,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) ErrorCode);

/***********************************************************************************************************************
 *  vDam_ServiceRole_Confirmation()
 **********************************************************************************************************************/
/*!
 * \brief         Finishes manufacturer specific actions on a diagnostic service request.
 * \details       This function is a notification from the DCM to the application that a diagnostic service processing
 *                is finished.
 *                No actions of vDam on this confirmation callout.
 * \param[in]     SID                 Contains the diagnostic service Id
 * \param[in]     ReqType             Specifies the diagnostic request type:
 *                                    0 - physical request
 *                                    1 - functional request
 * \param[in]     SourceAddress       Contains the diagnostic client source address
 * \param[in]     ConfirmationStatus  Contains the response transmission resp. diagnostic response type
 * \return        E_OK                The operation is finished
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 */
FUNC(Std_ReturnType, VDAM_CODE) vDam_ServiceRole_Confirmation(
  uint8 SID,
  uint8 ReqType,
  uint16 SourceAddress,
  Dcm_ConfirmationStatusType ConfirmationStatus);

# define VDAM_STOP_SEC_CODE
# include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VDAM_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: vDam_Cbk.h
 *********************************************************************************************************************/
