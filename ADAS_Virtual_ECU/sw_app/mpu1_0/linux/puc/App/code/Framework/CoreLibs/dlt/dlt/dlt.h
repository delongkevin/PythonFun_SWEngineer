/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   Dlt
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Header file for implementation of the Dlt - Diagnostic log and trace module
 *    Configuration and interface functions are defined in DltCfg
 * ======================================================================== */

#ifndef DLT_H_
#define DLT_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* QA-C */
/* PRQA S 3205 EOF */ /* Suppressed QAC warning, identifier is used in other DLT modules */
/* PRQA S 3210 EOF */ /* Suppressed QAC warning, identifiers provided for other DLT modules */
/* PRQA S 3447 EOF */ /* Suppressed QAC warning, functions are declared in a header file */

#include <cfg/dlt_cfg.h>
#include "dlt_types.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/* define header type including standard and extended header */
typedef u8 sDlt_s_Header_t[sDltCfg_d_HDR_LEN_MAX];

extern sDlt_s_Data_t sDlt_V_Data_s;
extern sDlt_s_AppIdCIdTable_t sDlt_V_AppIdCIdTable_s [sDltCfg_d_MAX_COUNT_APPIDS];

/* --- Public Function Declarations ------------------------------------------------ */
/*** 8.4.1  General provided Functions for BSW-modules ************************/

/* -------------------------------------------------------------------------- */
/**
 * 8.4.1.1  dlt_reset
 *
 * \par Description:
 *   Reset status  
 *
 * \param[in] i_Config_ps - Pointer to a DLT configuration structure
 */
extern void sDlt_F_reset_v (const sDlt_s_Config_t* i_Config_ps);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.1.1  dlt_init [SWS_Dlt_00239]
 *
 * \par Description:
 *    Dlt is using the NVRamManager and is to be initialized very late in the
 *    ECU startup phase. The Dlt_Init() function should be called after the
 *    NVRamManager is initialed.
 *
 * \param[in] i_Config_ps - Pointer to a DLT configuration structure
 */
extern void sDlt_F_init_v (const sDlt_s_Config_t* i_Config_ps);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.1.2  dlt_GetVersionInfo   [SWS_Dlt_00271]
 *
 * \par Description:#
 *    Returns the version information of this module.
 *
 * \param[out] i_VersionInfo_ps - Pointer to where to store the version information
 *                                of this module.
 */
#ifdef sDltCfg_d_VERSION_INFO_API
extern void sDlt_F_getVersionInfo_v (sStd_s_VersionInfoType_t* i_VersionInfo_ps);
#endif

/*** 8.4.2  Provided functions for sending log messages from SW-Cs ************/

/* -------------------------------------------------------------------------- */
/**
 * 8.4.2.1  dlt_sendLogMessage   [SWS_Dlt_00241]
 *
 * \par Description:
 *    The service represents the interface to be used by basic software modules
 *    or by software component to send log messages.
 *
 * \param[in] i_SessionId_t - For SW-C this is not visible (Port defined argument value),
 *                            for BSW-modules it is the module number
 * \param[in] i_LogInfo_ps - Structure containing the relevant information for filtering the message.
 * \param[in] i_LogData_pu8 - Buffer containing the parameters to be logged. The contents of this
 *                            pointer represents the payload of the send log message
 * \param[in] i_LogDataLength_u16 - Length of the data buffer log_data.
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK - The required operation succeeded.
 *                            sDltCfg_D_E_MSG_TOO_LARGE - The message is too large for sending over the network.
 *                            sDltCfg_D_E_IF_NOT_AVAILABLE - The interface is not available.
 *                            sDltCfg_D_E_UNKNOWN_SESSION_ID - The provided session id is unknown.
 *                            sDltCfg_D_E_NOT_IN_VERBOSE_MODE - Unable to send the message in verbose mode.
 */
extern sDlt_s_Return_t sDlt_F_sendLogMessage_t (sDlt_s_SessionId_t i_SessionId_t,
                                                const sDlt_s_MessageLogInfo_t* i_LogInfo_ps,
                                                const u8* i_LogData_pu8,
                                                u16 i_LogDataLength_u16);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.2.2  dlt_sendTraceMessage [SWS_Dlt_00243]
 *
 * \par Description:
 *    The service represents the interface to be used by basic software modules
 *    or by software component to trace parameters.
 *
 * \param[in] i_SessionId_t - For SW-C this is not visible (Port defined argument
 *                            value), for BSW-modules it is the module number
 * \param[in] i_TraceInfo_ps - Structure containing the relevant information for
 *                              filtering the message.
 * \param[in] i_TraceData_pu8 - Buffer containing the parameters to be traced. The
 *                              contents of this pointer represents the payload of
 *                              the send log message
 * \param[in] i_TraceDataLength_u16 - Length of the data buffer trace_data
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK - The required operation succeeded.
 *                            sDltCfg_D_E_MSG_TOO_LARGE - The message is too large for sending over the network.
 *                            sDltCfg_D_E_IF_NOT_AVAILABLE - The interface is not available.
 *                            sDltCfg_D_E_UNKNOWN_SESSION_ID - The provided session id is unknown.
 *                            sDltCfg_D_E_NOT_IN_VERBOSE_MODE - Unable to send the message in verbose mode.
 */
extern sDlt_s_Return_t sDlt_F_sendTraceMessage_t (sDlt_s_SessionId_t i_SessionId_t,
                                                  const sDlt_s_MessageTraceInfo_t* i_TraceInfo_ps,
                                                  const u8* i_TraceData_pu8,
                                                  u16 i_TraceDataLength_u16);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.2.3  dlt_registerContext  [SWS_Dlt_00245]
 *
 * \par Description:
 *    The service has to be called when a software module wants to use
 *    services offered by DLT software component for a specific context. If a
 *    context id is being registered for an already registered application id
 *    then app_description can be NULL and len_app_description zero.
 *
 * \param[in] i_SessionId_t - number of the module (Module ID within BSW, Port defined argument
 *                            value within SW-C)
 * \param[in] i_AppId_t - the Application ID
 * \param[in] i_ContextId_t - the Context ID
 * \param[in] i_AppDescription_pu8 - Points to description string for the provided application id. At
 *                                    maximum 255 characters are interpreted.
 * \param[in] i_AppDescriptionLen_u8 - The length of the description for the application id string
 *                                      (number of characters of description string).
 * \param[in] i_ContextDescription_pu8 - Points to description string for the provided context. At
 *                                        maximum 255 characters are interpreted.
 * \param[in] i_ContextDescriptionLen_u8 - The length of the description string (number of characters
 *                                          of description string).
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_CONTEXT_ALREADY_REG - The software module context has already registered.
 *                            sDltCfg_D_E_OK - The required operation succeed.
 */
extern sDlt_s_Return_t sDlt_F_registerContext_t (sDlt_s_SessionId_t i_SessionId_t,
                                                 sDlt_s_ApplicationId_t i_AppId_t,
                                                 sDlt_s_ContextId_t i_ContextId_t,
                                                 const u8* i_AppDescription_pu8,
                                                 u8 i_AppDescriptionLen_u8,
                                                 const u8* i_ContextDescription_pu8,
                                                 u8 i_ContextDescriptionLen_u8);

/*** 8.4.2.4  Provided functions for triggering DTC changes from Dem **********/

#ifdef sDltCfg_D_IMPLEMENT_DEM_INTERFACE
/* -------------------------------------------------------------------------- */
/**
 * 8.4.2.5  dlt_demTriggerOnEventStatus   [SWS_Dlt_00470]
 *
 * \par Description:
 *    This service is provided by the Dem in order to call Dlt upon status changes.
 *
 * \param[in] i_EventId_t - Identification of an Event by assigned event number.
 *                          The Event Number is configured in the Dem. Min.: 1 (0: Indication of no
 *                          Event or Failure) Max.: Result of configuration of Event Numbers in Dem
 *                          (Max is either 255 or 65535)
 * \param[in] i_EventStatusByteOld_t - Extended event status before change
 * \param[in] i_EventStatusByteNew_t - Detected / reported of event status
 */
extern void sDlt_F_demTriggerOnEventStatus_v (sDem_s_EventId_t i_EventId_t,
                                              sDem_s_UdsStatusByte_t i_EventStatusByteOld_t,
                                              sDem_s_UdsStatusByte_t i_EventStatusByteNew_t);
#endif

/*** 8.4.3  Provided function for fan-out capability of Det *******************/

#ifdef sDltCfg_D_IMPLEMENT_DET_INTERFACE
/* -------------------------------------------------------------------------- */
/**
 * 8.4.3.1  dlt_detForwardErrorTrace   [SWS_Dlt_00432]
 *
 * \par Description:
 *    Service to forward error reports from Det to Dlt.
 *
 * \param[in] i_ModuleId_u16 - Module ID of calling module.
 * \param[in] i_InstanceId_u8 - The identifier of the index based instance of a module, starting from 0, If
 *                              the module is a single instance module it shall pass 0 as the InstanceId.
 * \param[in] i_ApiId_u8 - ID of API service in which error is detected (defined in SWS of calling module)
 * \param[in] i_ErrorId_u8 - ID of detected development error (defined in SWS of calling module).
 */
extern void sDlt_F_detForwardErrorTrace_v (u16 i_ModuleId_u16,
                                           u8 i_InstanceId_u8,
                                           u8 i_ApiId_u8, u8 i_ErrorId_u8);
#endif

#ifdef sDltCfg_D_IMPLEMENT_DCM_INTERFACE
/* -------------------------------------------------------------------------- */
/**
 * 8.4.4.1  dlt_activateEvent [SWS_Dlt_00488]
 *
 * \par Description:
 *    This function is called by the Dcm if a specific ResponseOnEvent is enabled by a
 *    user. The RoeEventID shall be used by the Dlt to notify the Dcm about some actions
 *    to do for the ROE service. Normally for the Dlt module, only the ReadDataByIdendifer
 *    (0x22) should be used for ROE. In addition, when a specific ROE for the Dlt module
 *    is disabled/turned off by a user, the Dlt module is notified with this function.
 *
 * \param[in] i_RoeEventId_u8 - The eventID to use for the ResponseOnEvent (0x86). This eventId shall be
 *                              used within the Dcm_TriggerOnEvent() function called by Dlt."
 * \param[in] i_RoeState_t - --
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - call has some errors
 */
extern Std_ReturnType sDlt_F_activateEvent_t (u8 i_RoeEventId_u8,
                                              sDcm_s_RoeState_t i_RoeState_t);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.4.2  dlt_readData   [SWS_Dlt_00247]
 *
 * \par Description:
 *    Is called from Dcm when UDS service ReadDataByIdendifer for Dlt DID is called.
 *
 * \param[in] i_OpStatus_t - See description of Dcm_OpStatusType in AUTOSAR_SWS_DCM.
 *
 * \param[out] o_Data_pu8 - Contains a complete Dlt message
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_PENDING - application process not yet completed, another call is required
 *                          E_NOT_OK - call has some errors
 */
extern Std_ReturnType sDlt_F_readData_t (sDcm_s_OpStatus_t i_OpStatus_t, u8* o_Data_pu8);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.4.3  dlt_readDataLength   [SWS_Dlt_00248]
 *
 * \par Description:
 *    Is called from Dcm when UDS service ReadDataByIdendifer for Dlt DID is called.
 *
 * \param[out] o_DataLength_pu16 - Data length of the DID to read by Dcm (This is the Dlt message length
 *                                  since only Dlt message are transmitted)
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - call has some errors
 */
extern Std_ReturnType sDlt_F_readDataLength_t (u16* o_DataLength_pu16);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.4.4  dlt_writeData  [SWS_Dlt_00249]
 *
 * \par Description:
 *    Is called from Dcm when UDS service WriteDataByIdendifer for Dlt DID is called.
 *
 * \param[in] i_Data_pu8 - data to write (Shall contain a complete Dlt message send from a external
 *                         client by using WriteDataByIdendifer)
 * \param[in] i_DataLength_u16 - length of data to write by Dcm
 * \param[in] i_OpStatus_t - See description of Dcm_OpStatusType in AUTOSAR_SWS_DCM.
 * \param[out] o_ErrorCode_pt - See description in Dcm service component
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_PENDING - application process not yet completed, another call is required
 *                          E_NOT_OK - call has some errors
 */
extern Std_ReturnType sDlt_F_writeData_t (const u8* i_Data_pu8,
                                          u16 i_DataLength_u16,
                                          sDcm_s_OpStatus_t i_OpStatus_t,
                                          sDcm_s_NegativeResponseCode_t* o_ErrorCode_pt);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.4.5  dlt_conditionCheckRead  [SWS_Dlt_00428]
 *
 * \par Description:
 *    Is called from Dcm when UDS service ReadDataByIdendifer for Dlt DID is called to
 *    see if Dlt_ReadData can be called.
 *
 * \param[in] i_OpStatus_t - See description of Dcm_OpStatusType in AUTOSAR_SWS_DCM.
 *
 * \param[out] o_ErrorCode_pt - See description in Dcm service component
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_PENDING - application process not yet completed, another call is required
 *                          E_NOT_OK - call has some errors
 */
extern Std_ReturnType sDlt_F_conditionCheckRead_t (sDcm_s_OpStatus_t i_OpStatus_t,
                                                   sDcm_s_NegativeResponseCode_t* o_ErrorCode_pt);
#endif

/*** 8.4.5  Interfaces  provided  by  Dlt  core  module  for  internal  use  with  Dlt communication module ************************/

/* -------------------------------------------------------------------------- */
/**
 * 8.4.5.1  dlt_comRxIndication  [SWS_Dlt_00272]
 *
 * \par Description:
 *    This function is called by the Dlt communication module:
 *    - with Result = E_OK after the complete Dlt I-PDU has successfully been received, i.e. at
 *    the very end of the segmented TP receive cycle or after receiving an unsegmented N-PDU.
 *    - with Result = E_NOT_OK it is indicated that an error (e.g. timeout) has occurred during
 *    the reception of the Dlt I-PDU. This passes the receive buffer back to Dlt and allows error
 *    handling. It is undefined which part of the buffer contains valid data in this case, so Dlt
 *    shall not evaluate that buffer. By calling this service only Dlt is allowed to access the buffer.
 *    Caveats:
 *    This function might be called in interrupt context. If an existing reception has to be canceled
 *    to establish a new reception it is required to indicate a cancellation first before requesting
 *    a buffer for the new reception. Otherwise Dlt will be requested to open a second connection.
 *
 * \param[in] i_RxPduId_t - ID of DLT I-PDU that has been received. Identifies the data that has been
 *                          received. Range: 0..(maximum number of I-PDU IDs received by DLT) 1
 * \param[in] i_Result_t - Result of the N-PDU reception:
 *                         - E_OK: the complete N-PDU has been received.
 *                         - E_NOT_OK: an error occurred during reception, used to enable unlocking
 *                            of the receive buffer.
 */
extern bool_t sDlt_F_comRxIndication_b (sPdu_s_Id_t i_RxPduId_t, DltStd_ReturnType i_Result_t);

/* -------------------------------------------------------------------------- */
/**
 * 8.4.5.2  dlt_comTxConfirmation   [SWS_Dlt_00273]
 *
 * \par Description:
 *    This function is called by the Dlt communication module:
 *    - with Result = E_OK after the complete Dlt I-PDU has successfully been transmitted, i.e.
 *    at the very end of the segmented TP transmit cycle. Within this function, Dlt shall unlock
 *    the transmit buffer.
 *    - with Result = E_NOT_OK if an error (e.g. timeout) has occurred during the transmission
 *    of the Dlt I-PDU. This enables unlocking of the transmit buffer. The I-PDU can be rejected
 *    and an error reporting may be done. Error handling is up to the PduRouter.
 *    - with Result = E_NOT_OK if the N-PDU has been successfully cancelled after a request with
 *    Dlt_ComCancelTransmitRequest()
 *    Caveats:
 *    This function might be called in interrupt context (e.g. from a transmit interrupt).
 *    However, for transmission via FlexRay there is a restriction:
 *    Since the FlexRay Specification does not mandate the existence of a transmit interrupt, the
 *    exact meaning of this confirmation (i.e. "transfer into the FlexRay controller�s send buffer"
 *    OR "transmission onto the FlexRay network") depends on the capabilities of the FlexRay
 *    communication controller and the configuration of the FlexRay Interface.
 *
 * \param[in] i_TxPduId_t - ID of Dlt I-PDU that has been transmitted. Range: 0..(maximum number
 *                          of I-PDU IDs transmitted by Dcm) - 1
 * \param[in] i_Result_t - Result of the N-PDU transmission:
 *                         - E_OK: the complete N-PDU has been transmitted.
 *                         - E_NOT_OK: an error occurred during transmission, used to enable unlocking
 *                            of the transmit buffer.
 */
extern void sDlt_F_comTxConfirmation_v (sPdu_s_Id_t i_TxPduId_t, DltStd_ReturnType i_Result_t);

/*** embeddeers required functions ********************************************/

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    De-initialization of DLT module
 *
 */
extern void sDlt_F_deinit_v (void);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    cyclic task for DLT
 *
 */
extern void sDlt_F_cyclicTask_v (void);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    searches pair of app_id and context_id in local registration table
 *
 * \param[in] i_AppId_t - id of application to be searched for
 * \param[in] i_ContextId_t - id of context to be searched for
 * \param[out] *o_Idx_pt - index to table entry with appId and conextId
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_UNKNOWN_SESSION_ID - if appId and contextId pair could not be found
 *                        sDltCfg_D_E_OK - if appId and contextId pair could be found
 */
extern sDlt_s_Return_t sDlt_F_findAppIdContextIdPair_t (sDlt_s_ApplicationId_t i_AppId_t,
                                                        sDlt_s_ContextId_t i_ContextId_t,
                                                        sDlt_s_MaxCountAppIds_t *o_Idx_pt);



/**
 * \par Description:
 *    check if log message has to be filtered
 *
 * \param[in] i_LogInfo_s - message info set by caller
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK - message is okay
 *                        sDltCfg_D_E_MESSAGE_FILTERED - verbose mode not implemented
 */
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
extern sDlt_s_Return_t sDlt_F_checkLogMessageFilter_t (const sDlt_s_MessageLogInfo_t* i_LogInfo_s);
#endif

#if defined(__cplusplus)
}; // extern C
#endif

/* --------------------------------------------------------------------------------- */
#endif /* DLT_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlt.h */


