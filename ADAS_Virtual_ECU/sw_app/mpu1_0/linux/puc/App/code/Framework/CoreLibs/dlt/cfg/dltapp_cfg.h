/*! \cond FILEINFO
 ******************************************************************************
 * \file dltapp_cfg.h
 ******************************************************************************
 * Copyright (C) embeddeers GmbH, 2014
 ******************************************************************************
 *
 * \brief  application side configuration of DLT
 *
 * \par Purpose
 *    Defines the test cases and test suites for the DLT module.
 *
 * \endcond
 *
 ******************************************************************************
 */

#ifndef DLTAPP_CFG_H_
#define DLTAPP_CFG_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */

/* - ugl move to dltapp.h - #define sDltApp_d_MAX_COUNT_SESSIONIDS   1 */
/* TODO - ugl unused - #define CHK_DLT_SID_UNKNOWN      (0xFFu) */

/* get access to configuration data */
/* - ugl move to dltapp.c - extern const sDlt_s_SessionIdTable_t sDltCfg_C_SessionIdTable_t [sDltApp_d_MAX_COUNT_SESSIONIDS] */

/* --- Public Function Declarations ------------------------------------------------ */
/*** 8.5.1  Expected Interfaces from SW-Cs ************************************/

/* -------------------------------------------------------------------------- */
/**
 * 8.5.1.1  dlt_setLogLevel - [SWS_Dlt_00252]
 *
 * \par Description:
 *    Callback is called by Dlt to inform the SW-C of a new log level status of a given context.
 *
 * \param[in] app_id - the Application ID
 * \param[in] context_id - the Context ID
 * \param[in] loglevel - the new log level of the context
 */
/* TODO - ugl unused - extern void aDltApp_F_SetLogLevel_01 (sDlt_s_ApplicationId_t appId,
                                      sDlt_s_ContextId_t contextId,
                                      sDlt_s_MessageLogLevel_t logLevel); */

/* -------------------------------------------------------------------------- */
/**
 * 8.5.1.2  dlt_setTraceStatus - [SWS_Dlt_00254]
 *
 * \par Description:
 *    Callback is called by Dlt to inform the SW-C of a new trace status of a given context.
 *
 * \param[in] app_id - the Application ID
 * \param[in] context_id - the Context ID
 * \param[in] new_trace_status - the new trace_status for the pair of Application ID and Context ID
 */
/* TODO - ugl unused - extern void aDltApp_F_SetTraceStatus_01 (sDlt_s_ApplicationId_t appId,
                                         sDlt_s_ContextId_t contextId,
                                         BOOL newTraceStatus); */

/* -------------------------------------------------------------------------- */
/**
 * 8.5.1.3  dlt_setVerboseMode - [SWS_Dlt_00256]
 *
 * \par Description:
 *    Callback is called by Dlt to inform the SW-C of a change of the verbose mode.
 *
 * \param[in] app_id - the Application ID
 * \param[in] context_id - the Context ID
 * \param[in] is_verbose_mode - if true, Verbose Mode is enabled, if false Verbose Mode is disabled
 */
/* TODO - ugl unused - extern void aDltApp_F_SetVerboseMode_01 (sDlt_s_ApplicationId_t appId,
                                         sDlt_s_ContextId_t contextId,
                                         BOOL isVerboseMode); */

/* -------------------------------------------------------------------------- */
/**
 * 8.5.1.xxx  dlt_getVerboseMode - [SWS_Dlt_00xxx]
 *
 * \par Description:
 *    Callback is called by Dlt to get the verbose mode status from the SW-C
 *
 * \param[in] app_id - the Application ID
 * \param[in] context_id - the Context ID
 *
 * \return BOOL - current verbose mode status
 */
/* TODO - ugl unused - extern BOOL aDltApp_F_GetVerboseMode_01 (sDlt_s_ApplicationId_t appId, sDlt_s_ContextId_t contextId); */

/* -------------------------------------------------------------------------- */
/**
 * 8.5.1.4  dlt_injectCall - [SWS_Dlt_00259]
 *
 * \par Description:
 *    Callback is called by Dlt to inject a function call in the SW-C. The behaviour
 *    trigged by this function should depend on the service_id also the interpretation of
 *    the user data. Both are specific to the application.
 *
 * \param[in] app_id - the Application ID
 * \param[in] context_id - the Context ID
 * \param[in] service_id - the service ID for the injection (user defined)
 * \param[in] data_length - length of the data puffer provided
 * \param[in] data - pointer to data puffer with data belonging to the injection (serviceID).
 *                         The contents of the data is user defined
 */
/* TODO - ugl unused - extern void aDltApp_F_InjectCall_01 (sDlt_s_ApplicationId_t appId,
                                     sDlt_s_ContextId_t contextId,
                                     u32 serviceId,
                                     u32 dataLength,
                                     const u8* data); */

/*** 8.6.1  Expected Interfaces from Dcm **************************************/

/* -------------------------------------------------------------------------- */
/**
 * 8.6.1.1  Dcm_TriggerOnEvent - [SWS_Dlt_00262]
 *
 * \par Description:
 *    The call to this function allows to trigger an event linked to a ResponseOnEvent request.
 *    On the function call, the DCM will execute the associated service if the corresponding
 *    Mode of the RoeEventId is 'ROE started'.
 *
 * \param[in] RoeEventId - Identifier of the event that is triggered
 *
 * \return Std_ReturnType - E_OK: RoeEventId value is valid
 *                          E_NOT_OK: RoeEventId value is not valid
 */
/* TODO - ugl unused - extern DltStd_ReturnType Dcm_triggerOnEvent (u8 roeEventId); */

/*** 8.6.3  Expected Interfaces from Gpt **************************************/

/* -------------------------------------------------------------------------- */
/**
 * 8.6.3.1  Gpt_EnableNotification - [SWS_Dlt_00513]
 *
 * \par Description:
 *    Enables the interrupt notification for a channel (relevant in normal mode).
 *
 * \param[in] Channel - Numeric identifier of the GPT channel.
 */
/* TODO - ugl unused - extern void Gpt_enableNotification (sGpt_s_Channel_t i_Channel_t); */

/* -------------------------------------------------------------------------- */
/**
 * 8.6.3.2  Gpt_StartTimer - [SWS_Dlt_00514]
 *
 * \par Description:
 *    Starts a timer channel.
 *
 * \param[in] Channel - Numeric identifier of the GPT channel.
 * \param[in] Value - Target time in number of ticks.
 */
/* TODO - ugl unused - extern void Gpt_StartTimer (sGpt_s_Channel_t i_Channel_t, sGpt_s_Value_t i_Value_t); */

/* TODO - ugl unused - DltStd_ReturnType chk_transmit (sPdu_s_Id_t dltTxPduId, const sDltPdu_s_Info_t* pduInfoPtr); */

/* --------------------------------------------------------------------------------- */
#endif /* DLTAPP_CFG_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltapp_cfg.h */
