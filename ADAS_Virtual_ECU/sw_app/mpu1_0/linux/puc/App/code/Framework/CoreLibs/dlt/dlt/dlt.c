/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   Dlt
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the Dlt - Diagnostic log and trace module
 *    Configuration and interface functions are defined in DltCfg
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"

#include "dlt.h"
#include "dltcom.h"
#include "dltpdu.h"
#include "dlthdr.h"
#include "dltctrl.h"

#include "dlthlp.h"

#include "dltapp.h"

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */
/* PRQA S 2022 2 */ /* initialized with sDlt_F_init_v(...) */
sDlt_s_Data_t sDlt_V_Data_s;
sDlt_s_AppIdCIdTable_t sDlt_V_AppIdCIdTable_s [sDltCfg_d_MAX_COUNT_APPIDS];

/* --- Private Function Declarations ----------------------------------------------- */
static sDlt_s_Return_t sDlt_f_findSessionId_t (sDlt_s_SessionId_t i_SessionId_t,
                                               sDlt_s_MaxCountCbks_t * o_Idx_t);
static sDlt_s_Return_t sDlt_f_handlePreInitLogMessage_t (sDlt_s_SessionId_t i_SessionId_t,
                                                         const sDlt_s_MessageLogInfo_t* i_LogInfo_ps,
                                                         const u8* i_LogData_pu8, u16 i_LogDataLen_u16);
static void sDlt_f_handlePostInitLogMessage_v (void);
static sDlt_s_Return_t sDlt_f_checkVerboseMode_t (const sDlt_s_MessageOptions_t i_Mopt_t);
static sDlt_s_Return_t sDlt_f_checkTraceMessageFilter_t (const sDlt_s_MessageTraceInfo_t* i_TraceInfo_ps);
static sDlt_s_Return_t sDlt_f_transmitMessage_t (const u8* i_Header_pu8,
                                                 sDltPdu_s_Length_t i_HeaderLen_t,
                                                 const u8* v_Payload_pu8,
                                                 sDltPdu_s_Length_t v_PayloadLen_t);

/* --- Private Function Definitions ------------------------------------------------ */
/**
 * \par Description:
 *    searches session id in statically configured session id and callback function table
 *
 * \param[in] i_SessionId_t - id of session to be searched for
 * \param[out] *o_Idx_t - index to table entry with session id
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_UNKNOWN_SESSION_ID - if i_SessionId_t could not be found
 *                        sDltCfg_D_E_OK - if i_SessionId_t could be found
 */
static sDlt_s_Return_t sDlt_f_findSessionId_t (sDlt_s_SessionId_t i_SessionId_t, sDlt_s_MaxCountCbks_t * o_Idx_t)
{
  sDlt_s_Return_t v_RetVal_t;

  /* assume invalid session id */
  v_RetVal_t = sDltCfg_D_E_UNKNOWN_SESSION_ID;

  if(o_Idx_t != NULL)
  {
    /* search table for session id */
    for (*o_Idx_t = 0u; *o_Idx_t < sDltApp_d_MAX_COUNT_SESSIONIDS; (*o_Idx_t)++)
    {
      if (i_SessionId_t == sDltCfg_C_SessionIdTable_t[*o_Idx_t].SessionId_t)
      {
        /* session id found */
        v_RetVal_t = sDltCfg_D_E_OK;
        break;
      }
    }
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    during pre-init the log message data is stored into a PDU
 *
 * \param[in] i_SessionId_t - session id of the BSW module
 * \param[in] i_LogInfo_ps - message log information
 * \param[in] *i_LogData_pu8 - pointer to log message
 * \param[in] i_LogDataLength_u16 - length of log message
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK if storing is okay
 *                        sDltCfg_D_E_MSG_TOO_LARGE if message is to large or PDU b
 */
static sDlt_s_Return_t sDlt_f_handlePreInitLogMessage_t (sDlt_s_SessionId_t i_SessionId_t, const sDlt_s_MessageLogInfo_t* i_LogInfo_ps,
    const u8* i_LogData_pu8, u16 i_LogDataLen_u16)
{
  DltStd_ReturnType v_Result_t;
  sDlt_s_Return_t v_RetVal_t;
  sPdu_s_Id_t v_PduId_t;
  sDltPdu_s_Info_t v_PduInfo_s;
  sDltPdu_s_Length_t v_PduLen_t;
  sDltPdu_s_Length_t v_Dst_t;

  /* calculated needed space for log message */
  v_PduLen_t = (sDltPdu_s_Length_t)(sizeof(sDlt_s_SessionId_t) + sizeof(sDlt_s_MessageLogInfo_t) + sizeof(u16) + i_LogDataLen_u16);
  /* get free PDU from pool */
  v_Result_t = sDltPdu_F_getPdu_t(&v_PduId_t, &v_PduInfo_s, v_PduLen_t);
  if (v_Result_t == E_OK)
  {
    /* copy data to PDU */
    v_Dst_t = 0u;
    (void)sDltPdu_F_copyToPdu_t(v_PduId_t, &v_Dst_t, &i_SessionId_t, (sDltPdu_s_Length_t)sizeof(i_SessionId_t));
    (void)sDltPdu_F_copyToPdu_t(v_PduId_t, &v_Dst_t, i_LogInfo_ps, (sDltPdu_s_Length_t)sizeof(sDlt_s_MessageLogInfo_t));
    (void)sDltPdu_F_copyToPdu_t(v_PduId_t, &v_Dst_t, &i_LogDataLen_u16, (sDltPdu_s_Length_t)sizeof(i_LogDataLen_u16));
    (void)sDltPdu_F_copyToPdu_t(v_PduId_t, &v_Dst_t, i_LogData_pu8, (sDltPdu_s_Length_t)i_LogDataLen_u16);
  }

  if (v_Result_t == E_OK)
  {
    v_RetVal_t = sDltCfg_D_E_OK;
  }
  else
  {
    v_RetVal_t = sDltCfg_D_E_MSG_TOO_LARGE;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    during post-init the PDUs are checked if there was any log message data
 *    stored during pre-init. these log messages are processed during post-init.
 */
static void sDlt_f_handlePostInitLogMessage_v (void)
{
  DltStd_ReturnType v_Result_t;
  BOOL v_Locked_b;
  sPdu_s_Id_t v_PduId_t;
  sDltPdu_s_Info_t v_Info_s;
  sDltPdu_s_Length_t v_Src_t;
  sDlt_s_SessionId_t v_SesId_t;
  sDlt_s_MessageLogInfo_t v_LogInfo_s;
  u16 v_LogDataLen_t;
  u8 v_LogData_au8[sDltCfg_d_PDU_LENGTH_OF_PDU];

  /* make sure that at least one free PDU is available */
  if (E_NOT_OK == sDltPdu_F_getPdu_t(&v_PduId_t, &v_Info_s, sDltCfg_d_PDU_LENGTH_OF_PDU))
  {
    /* release new PDU */
    (void)sDltPdu_F_putPdu_t(v_PduId_t);
  }
  else
  {
    /* discard oldest PDU */
    (void)sDltPdu_F_putPdu_t(0u);
  }

  /* check PDU pool for pre-init messages */
  for (v_PduId_t = 0u; v_PduId_t < sPdu_D_PDU_NUMBER_OF_PDU; v_PduId_t++)
  {
    v_Result_t = sDltPdu_F_getPduStatus_t(v_PduId_t, &v_Locked_b);
    if ((v_Result_t == E_OK) && (v_Locked_b != FALSE))
    {
      v_Src_t = 0u;
      v_Result_t = sDltPdu_F_copyFromPdu_t(v_PduId_t, &v_Src_t, &v_SesId_t, (sDltPdu_s_Length_t)sizeof(v_SesId_t));
      if(v_Result_t == E_OK)
      {
        v_Result_t = sDltPdu_F_copyFromPdu_t(v_PduId_t, &v_Src_t, &v_LogInfo_s, (sDltPdu_s_Length_t)sizeof(sDlt_s_MessageLogInfo_t));
      }
      if(v_Result_t == E_OK)
      {
        v_Result_t = sDltPdu_F_copyFromPdu_t(v_PduId_t, &v_Src_t, &v_LogDataLen_t, (sDltPdu_s_Length_t)sizeof(v_LogDataLen_t));
      }
      if(v_Result_t == E_OK)
      {
        v_Result_t = sDltPdu_F_copyFromPdu_t(v_PduId_t, &v_Src_t, &v_LogData_au8[0], (sDltPdu_s_Length_t)v_LogDataLen_t);
      }

      if (v_Result_t == E_OK)
      {
        (void)sDlt_F_sendLogMessage_t(v_SesId_t, &v_LogInfo_s, &v_LogData_au8[0], v_LogDataLen_t);
      }

      (void)sDltPdu_F_putPdu_t(v_PduId_t);
    }
  }
}

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    check if verbose mode message is enabled
 *
 *    8.3.7  Dlt_MessageOptionsType - [SWS_Dlt_00229]
 *    verbose_mode  -- Bit 3: If set Verbose mode is used (yet not relevant)
 *
 * \param[in] i_Mopt_t - message options set by caller
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK - message is okay
 *                        sDltCfg_D_E_NOT_IN_VERBOSE_MODE - verbose mode not implemented
 */
static sDlt_s_Return_t sDlt_f_checkVerboseMode_t (const sDlt_s_MessageOptions_t i_Mopt_t)
{
  sDlt_s_Return_t v_RetVal_t;

  /* assume message is okay */
  v_RetVal_t = sDltCfg_D_E_OK;

  /* check verbose flag */
  if ((i_Mopt_t & sDltCfg_D_MOPT_VERBOSE_MODE) != 0u)
  {
#ifndef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
    /**
     * [SWS_Dlt_00090] - If DltImplementVerboseMode is not true, a call to Dlt_SendLogMessage
     * or Dlt_SendTraceMessage shall return sDltCfg_D_E_NOT_IN_VERBOSE_MODE to the caller of the
     * function and reject the message if it sends a message in Verbose Mode (verbose mode flag set).
     */
    v_RetVal_t = sDltCfg_D_E_NOT_IN_VERBOSE_MODE;
#endif
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    check if trace message has to be filtered
 *
 * \param[in] i_TraceInfo_ps - message info set by caller
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK - message is okay
 *                        sDltCfg_D_E_MESSAGE_FILTERED - verbose mode not implemented
 */
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
static sDlt_s_Return_t sDlt_f_checkTraceMessageFilter_t (const sDlt_s_MessageTraceInfo_t* i_TraceInfo_ps)
{
  sDlt_s_Return_t v_RetVal_t;
  sDlt_s_MaxCountAppIds_t v_AppIdx_t;

  /* assume message can pass */
  v_RetVal_t = sDltCfg_D_E_NOT_OK;
  /* check if message filtering is enabled */
  if (sDlt_V_Data_s.FilterMessages_b != FALSE)
  {
    /* check if pair of appId and contextId can not be found */
    if(i_TraceInfo_ps != NULL)
    {
      v_RetVal_t = sDlt_F_findAppIdContextIdPair_t(i_TraceInfo_ps->AppId_t, i_TraceInfo_ps->ContextId_t, &v_AppIdx_t);
      if (v_RetVal_t == sDltCfg_D_E_OK)
      {
        /* check if trace is not allowed by explicit configuration */
        if (sDlt_V_AppIdCIdTable_s[v_AppIdx_t].TraceStatus_b == FALSE)
        {
          /* return message has to be filtered*/
          v_RetVal_t = sDltCfg_D_E_MESSAGE_FILTERED;
        }
      }
      else
      {
        /* no explicit trace status information for pair of appId and conId */

        /**
         * [SWS_Dlt_00067] - If no explicit log level or trace status is set the value of
         * DltDefaultMaxLogLevel shall be used instead.
         *
         * respective defaultTraceStatus
         */

        /* check if trace is not allowed by default */
        if (sDlt_V_Data_s.DefaultTraceStatus_b == FALSE)
        {
          /* return message has to be filtered*/
          v_RetVal_t = sDltCfg_D_E_MESSAGE_FILTERED;
        }
      }
    }
  }

  return v_RetVal_t;
}
#endif

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    copy header buffer and log data into a PDU and send it via dltcom.
 *
 * \param[in] *i_Header_pu8 - pointer to header buffer
 * \param[in] i_HeaderLen_t - number of bytes to be sent from header buffer
 * \param[in] *v_Payload_pu8 - pointer to log data
 * \param[in] v_PayloadLen_t - number of bytes to be sent from log data buffer
 *
 * \return sDlt_s_Return_t - sDltCfg_D_E_OK - message sent
 *                        sDltCfg_D_E_IF_NOT_AVAILABLE - message could not be sent
 *                        sDltCfg_D_E_MSG_TOO_LARGE - size of header and log data is to big
 */
static sDlt_s_Return_t sDlt_f_transmitMessage_t (const u8* i_Header_pu8, sDltPdu_s_Length_t i_HeaderLen_t,
    const u8* v_Payload_pu8, sDltPdu_s_Length_t v_PayloadLen_t)
{
  sDlt_s_Return_t v_RetVal_t;
  sPdu_s_Id_t v_PduId_t;
  sDltPdu_s_Info_t v_PduInfo_s;
  sDltPdu_s_Length_t v_DstIdx_t;

  /* assume message was sent */
  v_RetVal_t = sDltCfg_D_E_OK;

  /* check and get if PDU is available */
  if (E_OK == sDltCom_F_startOfTransmission_t(&v_PduId_t, &v_PduInfo_s, (v_PayloadLen_t + i_HeaderLen_t)))
  {
    /* fill PDU with header and payload */
    v_DstIdx_t = 0u;
    (void)sDltPdu_F_copyToPdu_t(v_PduId_t, &v_DstIdx_t, i_Header_pu8, i_HeaderLen_t);
    (void)sDltPdu_F_copyToPdu_t(v_PduId_t, &v_DstIdx_t, v_Payload_pu8, v_PayloadLen_t);

    /* try to transmit the log message */
    if (sDltCom_F_transmit_t(v_PduId_t, &v_PduInfo_s) == E_OK)
    {
      /* increment consecutive message number */
      sDlt_V_Data_s.MessageCount_u8++;
    }
    else
    {
      v_RetVal_t = sDltCfg_D_E_IF_NOT_AVAILABLE;
    }

  }
  else
  {
    v_RetVal_t = sDltCfg_D_E_MSG_TOO_LARGE;
  }

  return v_RetVal_t;
}

/* --- Public Function Definitions ------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_reset_v (const sDlt_s_Config_t* i_Config_ps)
{
#ifdef sDltCfg_D_IMPLEMENT_NVRAM_STORAGE
     /* todo get configuration data from NVM */
#endif

  if (i_Config_ps != NULL)
  {
    sDlt_V_Data_s.BandwidthForDiagChannel_u32   = i_Config_ps->BandwidthForDiagChannel_u32;
    sDlt_V_Data_s.BandwidthForComModule_u32     = i_Config_ps->BandwidthForComModule_u32;
    sDlt_V_Data_s.DefaultLogLevel_u8            = i_Config_ps->DefaultLogLevel_u8;
    sDlt_V_Data_s.DefaultTraceStatus_b          = i_Config_ps->DefaultTraceStatus_b;
    sDlt_V_Data_s.HeaderUseEcuId_b              = i_Config_ps->HeaderUseEcuId_b;
    sDlt_V_Data_s.HeaderUseSessionId_b          = i_Config_ps->HeaderUseSessionId_b;
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
    sDlt_V_Data_s.HeaderUseExtendedHeader_b     = i_Config_ps->HeaderUseExtendedHeader_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
    sDlt_V_Data_s.FilterMessages_b              = i_Config_ps->FilterMessages_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    sDlt_V_Data_s.HeaderUseTimestamp_b          = i_Config_ps->HeaderUseTimestamp_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    sDlt_V_Data_s.SendCyclicTimestamp_b         = i_Config_ps->SendCyclicTimestamp_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
    sDlt_V_Data_s.HeaderUseVerboseMode_b        = i_Config_ps->HeaderUseVerboseMode_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
    sDlt_V_Data_s.VfbTraceLogLevel_u8           = i_Config_ps->VfbTraceLogLevel_u8;
#endif

    sDlt_V_Data_s.Initialized_b = !FALSE;

    sDlt_f_handlePostInitLogMessage_v();
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_init_v (const sDlt_s_Config_t* i_Config_ps)
{
  /* initialize dlt run time data */
  sDltEnv_Memset_v(&sDlt_V_Data_s, 0, sizeof(sDlt_V_Data_s));
  sDltEnv_Memset_v(sDlt_V_AppIdCIdTable_s, 0, sizeof(sDlt_V_AppIdCIdTable_s));

#ifdef sDltCfg_D_IMPLEMENT_NVRAM_STORAGE
     /* todo get configuration data from NVM */
#endif

  if (i_Config_ps != NULL)
  {
    sDlt_V_Data_s.BandwidthForDiagChannel_u32   = i_Config_ps->BandwidthForDiagChannel_u32;
    sDlt_V_Data_s.BandwidthForComModule_u32     = i_Config_ps->BandwidthForComModule_u32;
    sDlt_V_Data_s.DefaultLogLevel_u8            = i_Config_ps->DefaultLogLevel_u8;
    sDlt_V_Data_s.DefaultTraceStatus_b          = i_Config_ps->DefaultTraceStatus_b;
    sDlt_V_Data_s.HeaderUseEcuId_b              = i_Config_ps->HeaderUseEcuId_b;
    sDlt_V_Data_s.HeaderUseSessionId_b          = i_Config_ps->HeaderUseSessionId_b;
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
    sDlt_V_Data_s.HeaderUseExtendedHeader_b     = i_Config_ps->HeaderUseExtendedHeader_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
    sDlt_V_Data_s.FilterMessages_b              = i_Config_ps->FilterMessages_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    sDlt_V_Data_s.HeaderUseTimestamp_b          = i_Config_ps->HeaderUseTimestamp_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    sDlt_V_Data_s.SendCyclicTimestamp_b         = i_Config_ps->SendCyclicTimestamp_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
    sDlt_V_Data_s.HeaderUseVerboseMode_b        = i_Config_ps->HeaderUseVerboseMode_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
    sDlt_V_Data_s.VfbTraceLogLevel_u8           = i_Config_ps->VfbTraceLogLevel_u8;
#endif

    sDlt_V_Data_s.Initialized_b = !FALSE;

    sDlt_f_handlePostInitLogMessage_v();
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_deinit_v (void)
{
  sDlt_V_Data_s.Initialized_b = FALSE;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_cyclicTask_v (void)
{
  sDlt_s_Header_t v_Header_t;
  sDltPdu_s_Length_t v_HeaderLen_t;
  sDlt_s_ControlData_t v_Ctrl_s;

  /* todo send cyclic time stamp messages */
  /**
   * 7.7.7.2 Timing messages
   * [SWS_Dlt_00221] - The Dlt module shall send periodically time messages. This time
   * messages are used to calculate a relative time on the external client and as alive
   * signal. The period in which the timing messages are sent shall be one second.
   * Timing messages are send by the Dlt module without request of an external client,
   * but only if a connection to an external client is established (e.g. a diagnostic
   * session with ROE or an interface of the Dlt communication module is enabled).
   * [SWS_Dlt_00222] - A timing message contains no data but the standard and the
   * extended header. The SEID, APID and CTID fields can be left blank. All other fields
   * shall be filled with its standard values, especially the Timestamp field.
   */

  /* assemble header and store length of header */
  v_Ctrl_s.AppId_t = 0u;
  v_Ctrl_s.ConId_t = 0u;
  v_Ctrl_s.SesId_t = 0u;
  v_Ctrl_s.Htyp_u8 = sDltCfg_D_HTYP_WTMS;
  v_Ctrl_s.Msin_u8 = (u8)(sDltCfg_D_TYPE_CONTROL << 1u) | (u8)(sDltCfg_D_CONTROL_TIME << 4u);
  v_HeaderLen_t = sDltHdr_F_assembleResponseHeader_u8(&v_Ctrl_s, v_Header_t);

  /* set message length in header */
  sDltHlp_F_writeUint16ToByteArray_v(&v_Header_t[sDltCfg_d_HDR_IDX_LEN], (u16)v_HeaderLen_t, sDltCfg_D_BIG_ENDIAN);
  /* send control message response */
  (void)sDlt_f_transmitMessage_t(v_Header_t, v_HeaderLen_t, NULL, 0u);
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
#ifdef sDltCfg_d_VERSION_INFO_API
void sDlt_F_getVersionInfo_v (sStd_s_VersionInfoType_t* i_VersionInfo_ps)
{
  if (i_VersionInfo_ps != NULL)
  {
    i_VersionInfo_ps->InstanceID_u8        = sDltCfg_d_INSTANCE_ID;
    i_VersionInfo_ps->ModuleID_u16         = sDltCfg_d_MODULE_ID;
    i_VersionInfo_ps->Sw_major_version_u8  = sDltCfg_d_MAJOR_VERSION;
    i_VersionInfo_ps->Sw_minor_version_u8  = sDltCfg_d_MINOR_VERSION;
    i_VersionInfo_ps->Sw_patch_version_u8  = sDltCfg_d_PATCH_VERSION;
    i_VersionInfo_ps->VendorID_u16         = sDltCfg_d_VENDOR_ID;
  }
}
#endif

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
// PRQA S 1505 1 // keep it public
sDlt_s_Return_t sDlt_F_sendLogMessage_t (sDlt_s_SessionId_t i_SessionId_t, const sDlt_s_MessageLogInfo_t* i_LogInfo_ps,
    const u8* i_LogData_pu8, u16 i_LogDataLength_u16)
{
  u32 v_TimeStamp_u32;
  sDlt_s_Return_t v_RetVal_t;
  sDlt_s_MaxCountCbks_t v_SesIdx_t;
  sDlt_s_Header_t v_Header_t;
  sDltPdu_s_Length_t v_HeaderLen_t;
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
  u8 v_ExtHeaderLen_u8;
#endif

  if ((i_LogInfo_ps != NULL) && (i_LogData_pu8 != NULL))
  {
    /* fetch the current system time */
    v_TimeStamp_u32 = sDltCfg_d_GPT_CHANNEL;

    /* check if DLT is already initialized */
    if (sDlt_V_Data_s.Initialized_b == FALSE)
    {
      /* store log message temporarily */
      v_RetVal_t = sDlt_f_handlePreInitLogMessage_t(i_SessionId_t, i_LogInfo_ps, i_LogData_pu8, i_LogDataLength_u16);
    }
    else
    {
      /* check if message in verbose mode is allowed to send */
      v_RetVal_t = sDlt_f_checkVerboseMode_t(i_LogInfo_ps->Options_t);

      /* check if message is allowed to be processed */
      if (v_RetVal_t == sDltCfg_D_E_OK)
      {
        /* find session id in table */
        v_RetVal_t = sDlt_f_findSessionId_t(i_SessionId_t, &v_SesIdx_t);

        /* check if session id is valid */
        if (v_RetVal_t == sDltCfg_D_E_OK)
        {
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
          /* check if log message has to be filtered */
          v_RetVal_t = sDlt_F_checkLogMessageFilter_t(i_LogInfo_ps);

          /* check if message is not filtered */
          if (v_RetVal_t == sDltCfg_D_E_OK)
          {
#endif
            /* assemble header and store length of header */
            v_HeaderLen_t = sDltHdr_F_assembleStandardHeader_u8(&v_Header_t[0], (u32)i_SessionId_t, v_TimeStamp_u32);
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
            v_ExtHeaderLen_u8 = sDltHdr_F_assembleExtendedHeader_u8(&v_Header_t[v_HeaderLen_t], sDltCfg_D_TYPE_LOG, i_LogInfo_ps->LogLevel_t,
                i_LogInfo_ps->Options_t, i_LogInfo_ps->ArgCount_t, i_LogInfo_ps->AppId_t, i_LogInfo_ps->ContextId_t);
#else
            v_ExtHeaderLen_u8 = sDlt_F_assembleExtendedHeader_u8(&v_Header_t[v_HeaderLen_t], sDltCfg_D_TYPE_LOG, i_LogInfo_ps->LogLevel_t,
                i_LogInfo_ps->options, 0u, i_LogInfo_ps->appId, i_LogInfo_ps->contextId);
#endif

            if (v_ExtHeaderLen_u8 > 0u)
            {
              /* set extended header flag */
              v_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_UEH;
              v_HeaderLen_t += v_ExtHeaderLen_u8;
            }
#endif

            /* set message length in header */
            sDltHlp_F_writeUint16ToByteArray_v(&v_Header_t[sDltCfg_d_HDR_IDX_LEN], i_LogDataLength_u16 + v_HeaderLen_t, sDltCfg_D_BIG_ENDIAN);
            v_RetVal_t = sDlt_f_transmitMessage_t(v_Header_t, v_HeaderLen_t, i_LogData_pu8, (sDltPdu_s_Length_t)i_LogDataLength_u16);

#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
          }
          else
          {
            /* return filtered message with okay result */
            v_RetVal_t = sDltCfg_D_E_OK;
          }
#endif
        }
      }
    }
  }
  else
  {
    v_RetVal_t = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
sDlt_s_Return_t sDlt_F_sendTraceMessage_t (sDlt_s_SessionId_t i_SessionId_t, const sDlt_s_MessageTraceInfo_t* i_TraceInfo_ps,
    const u8* i_TraceData_pu8, u16 i_TraceDataLength_u16)
{
  u32 v_TimeStamp_u32;
  sDlt_s_Return_t v_RetVal_t;
  sDlt_s_MaxCountCbks_t v_SesIdx_t;
  sDlt_s_Header_t v_Header_t;
  sDltPdu_s_Length_t v_HeaderLen_t;
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
  u8 v_ExtHeaderLen_u8;
#endif

  if ((i_TraceInfo_ps != NULL) && (i_TraceData_pu8 != NULL))
  {
    /* fetch the current system time */
    v_TimeStamp_u32 = sDltCfg_d_GPT_CHANNEL;

    /* check if message in verbose mode is allowed to send */
    v_RetVal_t = sDlt_f_checkVerboseMode_t(i_TraceInfo_ps->Options_t);

    /* check if message is allowed to be processed */
    if (v_RetVal_t == sDltCfg_D_E_OK)
    {
      /* find session id in table */
      v_RetVal_t = sDlt_f_findSessionId_t(i_SessionId_t, &v_SesIdx_t);
      /* check if session id is valid */
      if (v_RetVal_t == sDltCfg_D_E_OK)
      {
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
        /* check if trace message has to be filtered */
        v_RetVal_t = sDlt_f_checkTraceMessageFilter_t(i_TraceInfo_ps);
        /* check if message is not filtered */
        if (v_RetVal_t == sDltCfg_D_E_OK)
        {
#endif
          /* assemble header and store length of header */
          v_HeaderLen_t = sDltHdr_F_assembleStandardHeader_u8(v_Header_t, (u32)i_SessionId_t, v_TimeStamp_u32);

#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
          v_ExtHeaderLen_u8 = sDltHdr_F_assembleExtendedHeader_u8(&v_Header_t[v_HeaderLen_t], sDltCfg_D_TYPE_APP_TRACE, i_TraceInfo_ps->TraceInfo_t,
              i_TraceInfo_ps->Options_t, 0u, i_TraceInfo_ps->AppId_t, i_TraceInfo_ps->ContextId_t);
          if (v_ExtHeaderLen_u8 > 0u)
          {
            /* set extended header flag */
            v_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_UEH;
            v_HeaderLen_t += v_ExtHeaderLen_u8;
          }
#endif

          /* set message length in header */
          sDltHlp_F_writeUint16ToByteArray_v(&v_Header_t[sDltCfg_d_HDR_IDX_LEN], (u16)(i_TraceDataLength_u16 + v_HeaderLen_t), sDltCfg_D_BIG_ENDIAN);

          (void)sDlt_f_transmitMessage_t(v_Header_t, v_HeaderLen_t, i_TraceData_pu8, (sDltPdu_s_Length_t)i_TraceDataLength_u16);

#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
        }
        else
        {
          /* return filtered message with okay result */
          v_RetVal_t = sDltCfg_D_E_OK;
        }
#endif
      }
    }
  }
  else
  {
    v_RetVal_t = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
sDlt_s_Return_t sDlt_F_registerContext_t (sDlt_s_SessionId_t i_SessionId_t, sDlt_s_ApplicationId_t i_AppId_t,
    sDlt_s_ContextId_t i_ContextId_t, const u8* i_AppDescription_pu8, u8 i_AppDescriptionLen_u8,
    const u8* i_ContextDescription_pu8, u8 i_ContextDescriptionLen_u8)
{
  sDlt_s_MaxCountAppIds_t v_AppIdx_t;
  sDlt_s_MaxCountCbks_t v_SesIdx_t = 0U;
  sDlt_s_Return_t v_RetVal_t = sDltCfg_D_E_OK;

  /* context id should not be 0 */
  if (i_ContextId_t == 0)
  {
    v_RetVal_t = sDltCfg_D_E_CONTEXT_ALREADY_REG;
  }

  /* check if session id can not be found in table */
  if(v_RetVal_t == sDltCfg_D_E_OK)
  {
    v_RetVal_t = sDlt_f_findSessionId_t(i_SessionId_t, &v_SesIdx_t);
  }

  if (v_RetVal_t == sDltCfg_D_E_OK)
  {
    /* check if pair of app_id and context id can not be found in table */
    v_RetVal_t = sDlt_F_findAppIdContextIdPair_t(i_AppId_t, i_ContextId_t, &v_AppIdx_t);
    if (v_RetVal_t != sDltCfg_D_E_OK)
    {
      if (sDlt_V_Data_s.RegCnt_t < sDltCfg_d_MAX_COUNT_APPIDS)
      {
        /* register pair of app_id and context_id with additional information */
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].AppId_t                    = i_AppId_t;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].ContextId_t                = i_ContextId_t;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].LogLevel_t                 = sDlt_V_Data_s.DefaultLogLevel_u8;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].TraceStatus_b              = sDlt_V_Data_s.DefaultTraceStatus_b;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].CbkRef_t                   = v_SesIdx_t;

#ifdef sDltCfg_D_IMPLEMENT_APPID_CONTEXTID_QUERY
        /* register app and context description */
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].AppDescription_pu8         = i_AppDescription_pu8;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].AppDescriptionLen_u8       = i_AppDescriptionLen_u8;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].ContextDescription_pu8     = i_ContextDescription_pu8;
        sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].ContextDescriptionLen_u8   = i_ContextDescriptionLen_u8;
#else
        (void)appDescription;
        (void)appDescriptionLen;
        (void)contextDescription;
        (void)contextDescriptionLen;
#endif

        /* invoke callback function to set initial log level and trace status */
        if (sDltCfg_C_SessionIdTable_t[v_SesIdx_t].CbSetLogLevel_t != NULL)
        {
          (*sDltCfg_C_SessionIdTable_t[v_SesIdx_t].CbSetLogLevel_t)(i_AppId_t, i_ContextId_t, sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].LogLevel_t);
        }
        if (sDltCfg_C_SessionIdTable_t[v_SesIdx_t].CbSetTraceStatus_t != NULL)
        {
          (*sDltCfg_C_SessionIdTable_t[v_SesIdx_t].CbSetTraceStatus_t)(i_AppId_t, i_ContextId_t, sDlt_V_AppIdCIdTable_s[sDlt_V_Data_s.RegCnt_t].TraceStatus_b);
        }

        /* increment number of registered app_id and context_id */
        sDlt_V_Data_s.RegCnt_t++;

        v_RetVal_t = sDltCfg_D_E_OK;
      }
    }
    else
    {
      v_RetVal_t = sDltCfg_D_E_CONTEXT_ALREADY_REG;
    }
  }

  return v_RetVal_t;
}

#ifdef sDltCfg_D_IMPLEMENT_DEM_INTERFACE
/* -------------------------------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_demTriggerOnEventStatus_v (sDem_s_EventId_t i_EventId_t, sDem_s_UdsStatusByte_t i_EventStatusByteOld_t,
    sDem_s_UdsStatusByte_t i_EventStatusByteNew_t)
{
  /*TODO implementation*/
  (void)i_EventId_t;
  (void)i_EventStatusByteOld_t;
  (void)i_EventStatusByteNew_t;
}
#endif

#ifdef sDltCfg_D_IMPLEMENT_DET_INTERFACE
/* -------------------------------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_detForwardErrorTrace_v (u16 i_ModuleId_u16, u8 i_InstanceId_u8, u8 i_ApiId_u8, u8 i_ErrorId_u8)
{
  /*TODO implementation*/
  (void)i_ModuleId_u16;
  (void)i_InstanceId_u8;
  (void)i_ApiId_u8;
  (void)i_ErrorId_u8;
}
#endif

#ifdef sDltCfg_D_IMPLEMENT_DCM_INTERFACE
/* -------------------------------------------------------------------------- */
/** @file dlt.h */
Std_ReturnType sDlt_F_activateEvent_t (u8 i_RoeEventId_u8, sDcm_s_RoeState_t i_RoeState_t)
{
  /*TODO implementation*/
  (void)i_RoeEventId_u8;
  (void)i_RoeState_t;

  return E_NOT_OK;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
Std_ReturnType sDlt_F_readData_t (sDcm_s_OpStatus_t i_OpStatus_t, u8* o_Data_pu8)
{
  Std_ReturnType v_RetVal_t;

  if (o_Data_pu8 != NULL)
  {
    /*TODO implementation*/
    (void)i_OpStatus_t;
    *o_Data_pu8 = 0u;
    v_RetVal_t = E_NOT_OK;
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
Std_ReturnType sDlt_F_readDataLength_t (u16* o_DataLength_pu16)
{
  Std_ReturnType v_RetVal_t;

  if (o_DataLength_pu16 != NULL)
  {
    /*TODO implementation*/
    *o_DataLength_pu16 = 0u;
    v_RetVal_t = E_NOT_OK;
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
Std_ReturnType sDlt_F_writeData_t (const u8* i_Data_pu8, u16 i_DataLength_u16, sDcm_s_OpStatus_t i_OpStatus_t,
    sDcm_s_NegativeResponseCode_t* o_ErrorCode_pt)
{
  Std_ReturnType v_RetVal_t;

  if ((i_Data_pu8 != NULL) && (o_ErrorCode_pt != NULL))
  {
    /*TODO implementation*/
    (void)i_DataLength_u16;
    (void)i_OpStatus_t;
    *o_ErrorCode_pt = 0u;
    v_RetVal_t = E_NOT_OK;
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
Std_ReturnType sDlt_F_conditionCheckRead_t (sDcm_s_OpStatus_t i_OpStatus_t, sDcm_s_NegativeResponseCode_t* o_ErrorCode_pt)
{
  Std_ReturnType v_RetVal_t;

  if (o_ErrorCode_pt != NULL)
  {
    /*TODO implementation*/
    (void)i_OpStatus_t;
    *o_ErrorCode_pt = 0u;
    v_RetVal_t = E_NOT_OK;
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}
#endif

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
bool_t sDlt_F_comRxIndication_b (sPdu_s_Id_t i_RxPduId_t, DltStd_ReturnType i_Result_t)
{
  bool_t v_RV_b = false; /* Return value */
  u8 v_RespBuf_au8[sDltCfg_d_CTRL_RESPONSE_BUFFER_SZ];
  sDlt_s_Header_t v_Header_t;
  sDltPdu_s_Length_t v_HeaderLen_t;
  sDlt_s_ControlData_t v_Ctrl_s;

  /* check if message is successful received */
  if (i_Result_t == E_OK)
  {
    /* initialize control structure */
    v_Ctrl_s.PduIdx_t = 0u;
    v_Ctrl_s.PduId_t = i_RxPduId_t;
    v_Ctrl_s.Resp_pu8 = &v_RespBuf_au8[sDltCfg_d_HDR_LEN_SID];
    v_Ctrl_s.TxLen_t = 0u;
    v_Ctrl_s.Htyp_u8 = 0u;
    v_Ctrl_s.Msin_u8 = (u8)(sDltCfg_D_TYPE_CONTROL << 1u) | (u8)(sDltCfg_D_CONTROL_RESPONSE << 4u);

    if (FALSE != sDltHdr_F_evaluateRequestHeader_b(&v_Ctrl_s))
    {

      switch (v_Ctrl_s.ServiceId_u32)
      {
      case sDltCfg_D_SID_SET_LOG_LEVEL:
        sDlt_F_setLogLevel_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_DEFAULT_LOG_LEVEL:
        sDlt_F_setDefaultLogLevel_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_TRACE_STATUS:
        sDlt_F_setTraceStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_DEFAULT_TRACE_STATUS:
        sDlt_F_setDefaultTraceStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_LOG_INFO:
        sDlt_F_getLogInfo_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_DEFAULT_LOG_LEVEL:
        sDlt_F_getDefaultLogLevel_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_DEFAULT_TRACE_STATUS:
        sDlt_F_getDefaultTraceStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_STORE_CONFIG:
        sDlt_F_storeConfig_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_RESET_TO_FACTORY_DEFAULT:
        sDlt_F_resetToFactoryDefault_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_COMINTERFACE_STATUS:
        sDlt_F_setComInterfaceStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_COMINTERFACE_STATUS:
        sDlt_F_getComInterfaceStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_COMINTERFACE_NAMES:
        sDlt_F_getComInterfaceNames_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_COMINTERFACE_MAX_BANDWIDTH:
        sDlt_F_setComInterfaceMaxBandwidth_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_COMINTERFACE_MAX_BANDWIDTH:
        sDlt_F_getComInterfaceMaxBandwidth_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_VERBOSE_MODE:
        sDlt_F_setVerboseMode_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_VERBOSE_MODE_STATUS:
        sDlt_F_getVerboseModeStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_MESSAGE_FILTERERING:
        sDlt_F_setMessageFilterering_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_MESSAGE_FILTERERING_STATUS:
        sDlt_F_getMessageFiltereringStatus_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_TIMING_PACKETS:
        sDlt_F_setTimingPackets_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_LOCAL_TIME:
        sDlt_F_getLocalTime_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_USE_ECUID:
        sDlt_F_setUseEcuId_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_USE_ECUID:
        sDlt_F_getUseEcuId_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SET_USE_SESSIONID:
        sDlt_F_setUseSessionId_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_USE_SESSIONID:
        sDlt_F_getUseSessionId_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_USE_TIME_STAMP:
        sDlt_F_setUseTimeStamp_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_USE_TIME_STAMP:
        sDlt_F_getUseTimeStamp_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_USE_EXTENDED_HEADER:
        sDlt_F_setUseExtendedHeader_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_USE_EXTENDED_HEADER:
        sDlt_F_getUseExtendedHeader_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_GET_SOFTWARE_VERSION:
        sDlt_F_getSoftwareVersion_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_MESSAGE_BUFFER_OVERFLOW:
        sDlt_F_messageBufferOverflow_v(&v_Ctrl_s);
        break;
      case sDltCfg_D_SID_SWITCH_DUMP_MODE:
        sDlt_F_switchDumpMode_v(&v_Ctrl_s);
        break;
      default:
        // PRQA S 2995 2 // check is wanted here, although "<=" operator is always true
        if ((v_Ctrl_s.ServiceId_u32 >= sDltCfg_D_SID_CALL_SWC_INJECTION_MIN)
            && (v_Ctrl_s.ServiceId_u32 <= sDltCfg_D_SID_CALL_SWC_INJECTION_MAX))  /*lint !e685 operator '<=' always evaluates to 'true' */
        {
          sDlt_F_callSwcInjection_v(&v_Ctrl_s);
        }
        break;
      }

      /* write service id to response buffer */
      sDltHlp_F_writeUint32ToByteArray_v(v_RespBuf_au8, v_Ctrl_s.ServiceId_u32, sDltCfg_D_BIG_ENDIAN);
      v_Ctrl_s.TxLen_t += sDltCfg_d_HDR_LEN_SID;

      /* assemble header and store length of header */
      v_HeaderLen_t = sDltHdr_F_assembleResponseHeader_u8(&v_Ctrl_s, v_Header_t);

      /* set message length in header */
      sDltHlp_F_writeUint16ToByteArray_v(&v_Header_t[sDltCfg_d_HDR_IDX_LEN], (u16)v_HeaderLen_t + v_Ctrl_s.TxLen_t, sDltCfg_D_BIG_ENDIAN);
      /* send control message response */
      (void)sDlt_f_transmitMessage_t(v_Header_t, v_HeaderLen_t, v_RespBuf_au8, v_Ctrl_s.TxLen_t);

      v_RV_b = true;
    }
    else
    {
      /* Unexpected DLT request header */
      v_RV_b = false;
    }
  }

  return v_RV_b;
}

/* -------------------------------------------------------------------------- */
/** @file dlt.h */
void sDlt_F_comTxConfirmation_v (sPdu_s_Id_t i_TxPduId_t, DltStd_ReturnType i_Result_t)
{
  if (i_Result_t == E_OK)
  {
   /* TODO - ugl tbd - */
  }
  else
  {
   /* TODO - ugl tbd - */
  }

  (void)sDltPdu_F_putPdu_t(i_TxPduId_t);
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
sDlt_s_Return_t sDlt_F_findAppIdContextIdPair_t (sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t,
    sDlt_s_MaxCountAppIds_t * o_Idx_pt)
{
  sDlt_s_Return_t retVal;

  /* assume invalid session id */
  retVal = sDltCfg_D_E_UNKNOWN_SESSION_ID;
  /* search table for pair of i_AppId_t and i_ContextId_t */
  if(o_Idx_pt != NULL)
  {
    for (*o_Idx_pt = 0u; *o_Idx_pt < sDlt_V_Data_s.RegCnt_t/*sDltCfg_d_MAX_COUNT_APPIDS*/; (*o_Idx_pt)++)
    {
      if ((sDlt_V_AppIdCIdTable_s[*o_Idx_pt].AppId_t == i_AppId_t) && (sDlt_V_AppIdCIdTable_s[*o_Idx_pt].ContextId_t == i_ContextId_t))
      {
        /* combination of app_id and context_id found */
        retVal = sDltCfg_D_E_OK;
        break;
      }
    }
  }

  return retVal;
}

/* -------------------------------------------------------------------------- */
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
sDlt_s_Return_t sDlt_F_checkLogMessageFilter_t (const sDlt_s_MessageLogInfo_t* i_LogInfo_s)
{
  sDlt_s_Return_t v_RetVal_t;
  sDlt_s_MaxCountAppIds_t v_AppIdx_t;

  /* assume message can pass */
  v_RetVal_t = sDltCfg_D_E_OK;

  /* check if message filtering is enabled */
  if (sDlt_V_Data_s.FilterMessages_b != FALSE)
  {
    /* check if pair of appId and contextId can be found */
    if(i_LogInfo_s != NULL)
    {
      v_RetVal_t = sDlt_F_findAppIdContextIdPair_t(i_LogInfo_s->AppId_t, i_LogInfo_s->ContextId_t, &v_AppIdx_t);
    }
    else
    {
      v_RetVal_t = sDltCfg_D_E_NOT_OK;
    }

    if (v_RetVal_t == sDltCfg_D_E_OK)
    {
      /* check if log level has to be filtered by explicit configuration */
      if (i_LogInfo_s->LogLevel_t > sDlt_V_AppIdCIdTable_s[v_AppIdx_t].LogLevel_t)
      {
        /* return message has to be filtered*/
        v_RetVal_t = sDltCfg_D_E_MESSAGE_FILTERED;
      }
    }
    else
    {
      /* no explicit log level information for pair of appId and conId */

      /**
       * [SWS_Dlt_00067] - If no explicit log level or trace status is set the value of
       * DltDefaultMaxLogLevel shall be used instead.
       *
       * respective defaultLogLevel
       */
      /* check if message has to be filtered by default */
      if(i_LogInfo_s != NULL)
      {
        if (i_LogInfo_s->LogLevel_t > sDlt_V_Data_s.DefaultLogLevel_u8)
        {
          /* return message has to be filtered*/
          v_RetVal_t = sDltCfg_D_E_MESSAGE_FILTERED;
        }
        else
        {
          /* message can pass */
          v_RetVal_t = sDltCfg_D_E_OK;
        }
      }
      else
      {
        v_RetVal_t = sDltCfg_D_E_NOT_OK;
      }
    }
  }

  return v_RetVal_t;
}
#endif

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlt.c */


