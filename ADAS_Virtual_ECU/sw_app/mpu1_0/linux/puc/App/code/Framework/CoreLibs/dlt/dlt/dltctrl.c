/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   Dlt
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the DltCtrl - Diagnostic log and trace control module
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"

#include "dlt.h"
#include "dltpdu.h"
#include "dlthlp.h"
#include "dltctrl.h"
#include "dltapp.h"


/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */
/**
 * 7.7.7.1.24 - Get ECU Software Version - [SWS_Dlt_00393]
 */
/* define the software version string */
// PRQA S 1514 1 // The variable shall be accessable from outside
const char_t sDltCfg_C_SoftwareVersionString_u8 [ECU_SW_VER] = {
    "DLT test software version"
};

/* --- Private Function Declarations ----------------------------------------------- */
static void sDlt_f_checkIdLogLevel_v(const sDlt_s_ControlData_t *b_Ctrl_pt,
                                     sDlt_s_SetLogLevelResponse_t *v_Resp_pt,
                                     const sDlt_s_SetLogLevelRequest_t *v_Req_pt);

static void sDlt_f_checkIdTraceStatus_v(const sDlt_s_ControlData_t *b_Ctrl_pt,
                                        sDlt_s_SetTraceStatusResponse_t *v_Resp_pt,
                                        const BOOL *v_NewTraceStatus_pb);


/* --- Private Function Definitions ------------------------------------------------ */
static void sDlt_f_checkIdLogLevel_v(const sDlt_s_ControlData_t *b_Ctrl_pt,
                                     sDlt_s_SetLogLevelResponse_t *v_Resp_pt,
                                     const sDlt_s_SetLogLevelRequest_t *v_Req_pt)
{
  if((b_Ctrl_pt != NULL) && (v_Resp_pt != NULL) && (v_Req_pt != NULL))
  {
    v_Resp_pt->Status_u8 = sDlt_F_setLogLevel_u8(b_Ctrl_pt->AppId_t, b_Ctrl_pt->ConId_t, v_Req_pt->NewLogLevel_u8);
  }
}
/* -------------------------------------------------------------------------- */

static void sDlt_f_checkIdTraceStatus_v(const sDlt_s_ControlData_t *b_Ctrl_pt,
                                        sDlt_s_SetTraceStatusResponse_t *v_Resp_pt,
                                        const BOOL *v_NewTraceStatus_pb)
{
  sDlt_s_MaxCountAppIds_t v_Idx_t;

  if((b_Ctrl_pt != NULL) && (v_Resp_pt != NULL) && (v_NewTraceStatus_pb != NULL))
  {
    v_Resp_pt->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;

    if ((b_Ctrl_pt->AppId_t != 0U) || (b_Ctrl_pt->ConId_t != 0U))
    {
      /* change trace status */
      for (v_Idx_t = 0u; v_Idx_t < sDltCfg_d_MAX_COUNT_APPIDS; v_Idx_t++)
      {
        /* AppId or ContId == 0 => wildcard, otherwise use exact match */
        if (((0U == b_Ctrl_pt->AppId_t) || (sDlt_V_AppIdCIdTable_s[v_Idx_t].AppId_t == b_Ctrl_pt->AppId_t))
            && ((0U == b_Ctrl_pt->ConId_t) || (sDlt_V_AppIdCIdTable_s[v_Idx_t].ContextId_t == b_Ctrl_pt->ConId_t)))
        {
          sDlt_V_AppIdCIdTable_s[v_Idx_t].TraceStatus_b = *v_NewTraceStatus_pb;
          v_Resp_pt->Status_u8 = sDltCfg_D_CTRL_OK;
        }
      }
    }
  }
   // else: both appId and ContId are 0 => not supported
}


/* --- Public Function Definitions ------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setLogLevel_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  u32 v_ComInterface_u32;
  sDlt_s_SetLogLevelResponse_t v_Resp_s;
  sDlt_s_SetLogLevelRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetLogLevelRequest_t))
    {
      /* fetch data from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        v_ComInterface_u32 = sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.ComInterface_au8, b_Ctrl_ps->Endian_u8);
        /* check com interface for valid value */
        if (v_ComInterface_u32 == 0u)
        {
          /* check new log level for default command */
          if (v_Req_s.NewLogLevel_u8 == 0xFFu)
          {
            v_Req_s.NewLogLevel_u8 = sDlt_V_Data_s.DefaultLogLevel_u8;
          }

          /* check for valid new log level */
          if (v_Req_s.NewLogLevel_u8 <= sDltCfg_D_LOG_VERBOSE)
          {
            b_Ctrl_ps->AppId_t = (sDlt_s_ApplicationId_t)sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.AppId_au8, b_Ctrl_ps->Endian_u8);
            b_Ctrl_ps->ConId_t = (sDlt_s_ContextId_t)sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.ConId_au8, b_Ctrl_ps->Endian_u8);

            /* check if application id and context id are present */
            sDlt_f_checkIdLogLevel_v(b_Ctrl_ps, &v_Resp_s, &v_Req_s);
          }
        }
        else
        {
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetLogLevelResponse_t);
  }
}

// PRQA S 1505 1 // Function isnt used outside the module, but can be used
u8 sDlt_F_setLogLevel_u8(sDlt_s_ApplicationId_t  i_AppId_t,
                         sDlt_s_ContextId_t i_ContId_t,
                         sDlt_s_MessageLogLevel_t i_LogLevel_t)
{
  sDlt_s_MaxCountAppIds_t v_Idx_t;
  uint8_t v_Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;

  if ((i_AppId_t != 0U) || (i_ContId_t != 0U))
  {
    /* change log levels only for application id related context ids */
    for (v_Idx_t = 0u; v_Idx_t < sDltCfg_d_MAX_COUNT_APPIDS; v_Idx_t++)
    {
      /* AppId or ContId == 0 => wildcard, otherwise use exact match */
      if (((0U == i_AppId_t) || (sDlt_V_AppIdCIdTable_s[v_Idx_t].AppId_t == i_AppId_t))
          && ((0U == i_ContId_t) || (sDlt_V_AppIdCIdTable_s[v_Idx_t].ContextId_t == i_ContId_t)))
      {
        sDlt_V_AppIdCIdTable_s[v_Idx_t].LogLevel_t = i_LogLevel_t;
        v_Status_u8 = sDltCfg_D_CTRL_OK;
      }
    }
  }
  // else: both appId and ContId are 0 => not supported

  return v_Status_u8;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setDefaultLogLevel_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  u32 v_ComInterface_u32;
  sDlt_s_SetDefaultLogLevelResponse_t v_Resp_s;
  sDlt_s_SetDefaultLogLevelRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetDefaultLogLevelRequest_t))
    {
      /* get data from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        v_ComInterface_u32 = sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.ComInterface_au8, b_Ctrl_ps->Endian_u8);
        /* check com interface for valid value */
        if (v_ComInterface_u32 == 0u)
        {
          /* check for valid new log level */
          if (v_Req_s.NewLogLevel_u8 <= sDltCfg_D_LOG_VERBOSE)
          {
            sDlt_V_Data_s.DefaultLogLevel_u8 = v_Req_s.NewLogLevel_u8;
            v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
          }
        }
        else
        {
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetDefaultLogLevelResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setTraceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  u32 v_ComInterface_u32;
  BOOL v_NewTraceStatus_b;
  sDlt_s_SetTraceStatusResponse_t v_Resp_s;
  sDlt_s_SetTraceStatusRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetTraceStatusRequest_t))
    {
      /* get data from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        v_ComInterface_u32 = sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.ComInterface_au8, b_Ctrl_ps->Endian_u8);
        /* check com interface for valid value */
        if (v_ComInterface_u32 == 0u)
        {
          /* check validity of input value */
          if ((v_Req_s.NewTraceStatus_u8 == 0xFFu) || (v_Req_s.NewTraceStatus_u8 == 0u) || (v_Req_s.NewTraceStatus_u8 == 1u))
          {
            /* check new trace status for default command */
            if (v_Req_s.NewTraceStatus_u8 == 0xFFu)
            {
              v_NewTraceStatus_b = sDlt_V_Data_s.DefaultTraceStatus_b;
            }
            else if (v_Req_s.NewTraceStatus_u8 == 0u)
            {
              v_NewTraceStatus_b = FALSE;
            }
            else
            {
              v_NewTraceStatus_b = !FALSE;
            }

            b_Ctrl_ps->AppId_t = (sDlt_s_ApplicationId_t)sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.AppId_au8, b_Ctrl_ps->Endian_u8);
            b_Ctrl_ps->ConId_t = (sDlt_s_ContextId_t)sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.ConId_au8, b_Ctrl_ps->Endian_u8);

            /* check if application id and context id are present */
            sDlt_f_checkIdTraceStatus_v(b_Ctrl_ps, &v_Resp_s, &v_NewTraceStatus_b);
          }
        }
        else
        {
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetTraceStatusResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setDefaultTraceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  u32 v_ComInterface_u32;
  sDlt_s_SetDefaultTraceStatusResponse_t v_Resp_s;
  sDlt_s_SetDefaultTraceStatusRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetDefaultTraceStatusRequest_t))
    {
      /* get data from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        v_ComInterface_u32 = sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.ComInterface_au8, b_Ctrl_ps->Endian_u8);
        /* check com interface for valid value */
        if (v_ComInterface_u32 == 0u)
        {
          if (v_Req_s.NewTraceStatus_u8 <= 1u)
          {
            if (v_Req_s.NewTraceStatus_u8 == 0u)
            {
              sDlt_V_Data_s.DefaultTraceStatus_b = FALSE;
            }
            else
            {
              sDlt_V_Data_s.DefaultTraceStatus_b = !FALSE;
            }
            v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
          }
        }
        else
        {
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetDefaultTraceStatusResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getLogInfo_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetLogInfoResponse_t v_Resp_s;
  /*sDlt_s_GetLogInfoRequest_t v_Req_s;*/

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_GetLogInfoRequest_t))
    {
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetLogInfoResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getDefaultLogLevel_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetDefaultLogLevelResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      v_Resp_s.LogLevel_u8 = sDlt_V_Data_s.DefaultLogLevel_u8;
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetDefaultLogLevelResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getDefaultTraceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetDefaultTraceStatusResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      if (sDlt_V_Data_s.DefaultTraceStatus_b == FALSE)
      {
        v_Resp_s.TraceStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.TraceStatus_u8 = 1u;
      }
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetDefaultTraceStatusResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_storeConfig_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_StoreConfigResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
  #ifdef sDltCfg_D_IMPLEMENT_NVRAM_STORAGE
       /* todo store configuration data to NVM */
  #endif
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_StoreConfigResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_resetToFactoryDefault_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_ResetToFactoryDefaultResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      sDlt_F_reset_v(&sDltCfg_C_Config_s);
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_ResetToFactoryDefaultResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setComInterfaceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetComInterfaceStatusResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetComInterfaceStatusRequest_t))
    {
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetComInterfaceStatusResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getComInterfaceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetComInterfaceStatusResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_GetComInterfaceStatusRequest_t))
    {
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
      v_Resp_s.IfStatus_u8 = 0;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetComInterfaceStatusResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getComInterfaceNames_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetComInterfaceNamesResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      v_Resp_s.CountIf_u8 = 0u;
      sDltHlp_F_writeUint32ToByteArray_v(v_Resp_s.ComIfNames_u8, 0u, sDltCfg_d_HEADER_PAYLOAD_ENDIANES);
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetComInterfaceNamesResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setComInterfaceMaxBandwidth_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetComIfMaxBandwidthResponse_t v_Resp_s;
  /*sDlt_s_SetComIfMaxBandwidthRequest_t v_Req_s;*/

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetComIfMaxBandwidthRequest_t))
    {
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetComIfMaxBandwidthResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getComInterfaceMaxBandwidth_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetComIfMaxBandwidthResponse_t v_Resp_s;
  /*sDlt_s_GetComIfMaxBandwidthRequest_t v_Req_s;*/

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_GetComIfMaxBandwidthRequest_t))
    {
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
      sDltEnv_Memset_v(v_Resp_s.MaxBandwith_au8, 0, sizeof(v_Resp_s.MaxBandwith_au8));
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetComIfMaxBandwidthResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setVerboseMode_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetVerboseModeResponse_t v_Resp_s;
  sDlt_s_SetVerboseModeRequest_t v_Req_s;
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
  sDlt_s_MaxCountAppIds_t v_Idx_t;
  BOOL  v_NewStatus_b;
#endif

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetVerboseModeRequest_t))
    {
      /* get data from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
  #ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            v_NewStatus_b = FALSE;
          }
          else
          {
            v_NewStatus_b = !FALSE;
          }
          /* check for global change */
          if ((b_Ctrl_ps->AppId_t == 0u) && (b_Ctrl_ps->ConId_t == 0u) && (b_Ctrl_ps->SesId_t == 0u))
          {
            sDlt_V_Data_s.HeaderUseVerboseMode_b = v_NewStatus_b;
            v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
          }
          else
          {
            /* check for a uniquely identified SWC by application id, context id and session id */
            if (sDltCfg_D_E_OK == sDlt_F_findAppIdContextIdPair_t(b_Ctrl_ps->AppId_t, b_Ctrl_ps->ConId_t, &v_Idx_t))
            {
              /* check for associate session id and configured callback function */
              if ((sDltCfg_C_SessionIdTable_t[v_Idx_t].SessionId_t == b_Ctrl_ps->SesId_t)
                  && (sDltCfg_C_SessionIdTable_t[v_Idx_t].CbSetVerboseMode_t != NULL))
              {
                (*sDltCfg_C_SessionIdTable_t[v_Idx_t].CbSetVerboseMode_t)(b_Ctrl_ps->AppId_t, b_Ctrl_ps->ConId_t, v_NewStatus_b);
                v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
              }
            }
            else
            {
              v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
            }
          }
  #else
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetVerboseModeResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getVerboseModeStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetVerboseModeStatusResponse_t v_Resp_s;
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
  sDlt_s_MaxCountAppIds_t v_Idx_t;
  BOOL v_ModeStatus_b;
#endif

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
  v_ModeStatus_b = FALSE;
#endif

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
  #ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
      /* check for global change */
      if ((b_Ctrl_ps->AppId_t == 0u) && (b_Ctrl_ps->ConId_t == 0u) && (b_Ctrl_ps->SesId_t == 0u))
      {
        v_ModeStatus_b = sDlt_V_Data_s.HeaderUseVerboseMode_b;
        v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
      }
      else
      {
        /* check for a uniquely identified SWC by application id, context id and session id */
        if (sDltCfg_D_E_OK == sDlt_F_findAppIdContextIdPair_t(b_Ctrl_ps->AppId_t, b_Ctrl_ps->ConId_t, &v_Idx_t))
        {
          /* check for associate session id and configured callback function */
          if ((sDltCfg_C_SessionIdTable_t[v_Idx_t].SessionId_t == b_Ctrl_ps->SesId_t)
              && (sDltCfg_C_SessionIdTable_t[v_Idx_t].CbSetVerboseMode_t != NULL))
          {
            v_ModeStatus_b = (*sDltCfg_C_SessionIdTable_t[v_Idx_t].CbGetVerboseMode_t)(b_Ctrl_ps->AppId_t, b_Ctrl_ps->ConId_t);
            v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
          }
        }
        else
        {
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
        }
      }

      if (v_ModeStatus_b == FALSE)
      {
        v_Resp_s.ModeStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.ModeStatus_u8 = 1u;
      }
  #else
      v_Resp_s->v_ModeStatus_b = 0u;
      v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetVerboseModeStatusResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setMessageFilterering_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetMessageFiltereringResponse_t v_Resp_s;
  sDlt_s_SetMessageFiltereringRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetMessageFiltereringRequest_t))
    {
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
  #ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            sDlt_V_Data_s.FilterMessages_b = FALSE;
          }
          else
          {
            sDlt_V_Data_s.FilterMessages_b = !FALSE;
          }
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
        }
  #else
    v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetMessageFiltereringResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getMessageFiltereringStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetMessageFiltereringResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
  #ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
      if (sDlt_V_Data_s.FilterMessages_b == FALSE)
      {
        v_Resp_s.FilterStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.FilterStatus_u8 = 1u;
      }
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
  #else
      v_Resp_s->filterStatus = 0u;
      v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetMessageFiltereringResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setTimingPackets_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetTimingPacketsResponse_t v_Resp_s;
  sDlt_s_SetTimingPacketsRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetTimingPacketsRequest_t))
    {
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
  #ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            sDlt_V_Data_s.SendCyclicTimestamp_b = FALSE;
          }
          else
          {
            sDlt_V_Data_s.SendCyclicTimestamp_b = !FALSE;
          }
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
        }
  #else
    v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetTimingPacketsResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getLocalTime_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetLocalTimeResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
  #ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
      b_Ctrl_ps->Htyp_u8 = sDltCfg_D_HTYP_WTMS;
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
  #else
      b_Ctrl_ps->hFlags = 0u;
      v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetLocalTimeResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setUseEcuId_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetUseEcuIdResponse_t v_Resp_s;
  sDlt_s_SetUseEcuIdRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetUseEcuIdRequest_t))
    {
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            sDlt_V_Data_s.HeaderUseEcuId_b = FALSE;
          }
          else
          {
            sDlt_V_Data_s.HeaderUseEcuId_b = !FALSE;
          }
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetUseEcuIdResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getUseEcuId_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetUseEcuIdResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      if (sDlt_V_Data_s.HeaderUseEcuId_b == FALSE)
      {
        v_Resp_s.EcuIdStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.EcuIdStatus_u8 = 1u;
      }
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetUseEcuIdResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setUseSessionId_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetUseSessionIdResponse_t v_Resp_s;
  sDlt_s_SetUseSessionIdRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetUseSessionIdRequest_t))
    {
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            sDlt_V_Data_s.HeaderUseSessionId_b = FALSE;
          }
          else
          {
            sDlt_V_Data_s.HeaderUseSessionId_b = !FALSE;
          }
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetUseSessionIdResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getUseSessionId_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetUseSessionIdResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      if (sDlt_V_Data_s.HeaderUseSessionId_b == FALSE)
      {
        v_Resp_s.SIdStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.SIdStatus_u8 = 1u;
      }
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetUseSessionIdResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setUseTimeStamp_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetUseTimeStampResponse_t v_Resp_s;
  sDlt_s_SetUseTimeStampRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetUseTimeStampRequest_t))
    {
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
  #ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            sDlt_V_Data_s.HeaderUseTimestamp_b = FALSE;
          }
          else
          {
            sDlt_V_Data_s.HeaderUseTimestamp_b = !FALSE;
          }
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
  #else
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetUseTimeStampResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getUseTimeStamp_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetUseTimeStampResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
  #ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
      if (sDlt_V_Data_s.HeaderUseTimestamp_b == FALSE)
      {
        v_Resp_s.TimeStampStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.TimeStampStatus_u8 = 1u;
      }
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
  #else
      v_Resp_s.TimeStampStatus = 0u;
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetUseTimeStampResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_setUseExtendedHeader_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SetUseExtendedHeaderResponse_t v_Resp_s;
  sDlt_s_SetUseExtendedHeaderRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SetUseExtendedHeaderRequest_t))
    {
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        /* check if new status is valid */
        if (v_Req_s.NewStatus_u8 <= 1u)
        {
  #ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
          if (v_Req_s.NewStatus_u8 == 0u)
          {
            sDlt_V_Data_s.HeaderUseExtendedHeader_b = FALSE;
          }
          else
          {
            sDlt_V_Data_s.HeaderUseExtendedHeader_b = !FALSE;
          }
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
  #else
          v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SetUseExtendedHeaderResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getUseExtendedHeader_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetUseExtendedHeaderResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
  #ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
      if (sDlt_V_Data_s.HeaderUseExtendedHeader_b == FALSE)
      {
        v_Resp_s.ExhStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.ExhStatus_u8 = 1u;
      }
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
  #else
      v_Resp_s->exhStatus = 0u;
      v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_GetUseExtendedHeaderResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_callSwcInjection_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  u32 v_DataLen_u32;
  sDlt_s_CallSwcInjectionResponse_t v_Resp_s;
  sDlt_s_CallSwcInjectionRequest_t v_Req_s;
#ifdef sDltCfg_D_IMPLEMENT_SWC_INJECTION
  u8 v_DataInj_au8[sDltCfg_d_CTRL_SWC_INJECTION_BUFFER_SZ];
  sDlt_s_MaxCountAppIds_t v_Idx_t;
#endif

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t >= sizeof(sDlt_s_CallSwcInjectionRequest_t))
    {
      /* get data length from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s,
          (sDltPdu_s_Length_t)sizeof(v_Req_s.DataLength_au8)))
      {
        v_DataLen_u32 = sDltHlp_F_writeByteArrayToUint32_u32(v_Req_s.DataLength_au8, b_Ctrl_ps->Endian_u8);
        /* check for valid injection data length */
        if (v_DataLen_u32 <= sDltCfg_d_CTRL_SWC_INJECTION_BUFFER_SZ)
        {
  #ifdef sDltCfg_D_IMPLEMENT_SWC_INJECTION
          /* get injection data from PDU payload */
          if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, v_DataInj_au8, (sDltPdu_s_Length_t)v_DataLen_u32))
          {
            /* check for a uniquely identified SWC by application id, context id and session id */
            if (sDltCfg_D_E_OK == sDlt_F_findAppIdContextIdPair_t(b_Ctrl_ps->AppId_t, b_Ctrl_ps->ConId_t, &v_Idx_t))
            {
              /* check for associate session id and configured callback function */
              if ((sDltCfg_C_SessionIdTable_t[v_Idx_t].SessionId_t == b_Ctrl_ps->SesId_t)
                  && (sDltCfg_C_SessionIdTable_t[v_Idx_t].CbSwcInjection_t != NULL))
              {
                (*sDltCfg_C_SessionIdTable_t[v_Idx_t].CbSwcInjection_t)(b_Ctrl_ps->AppId_t, b_Ctrl_ps->ConId_t,
                    b_Ctrl_ps->ServiceId_u32, v_DataLen_u32, v_DataInj_au8);
                v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
              }
            }
            else
            {
              /**
               * [SWS_Dlt_00219] - If a unique identification is not possible (this pair does not exist,
               * is not registered yet) the v_Resp_sonse shall be NOT_SUPPORTED.
               */
              v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
            }
          }
  #else
          v_Resp_s->Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
  #endif
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_CallSwcInjectionResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_getSoftwareVersion_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_GetSoftwareVersionResponse_t v_Resp_s;
  u16 v_Len_u16;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;
  v_Len_u16 = 0u;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      v_Len_u16 = sDltEnv_Strlen_u16(/*(const void*)*/sDltCfg_C_SoftwareVersionString_u8);
      if (v_Len_u16 <= sizeof(v_Resp_s.SwVersion_au8))
      {
        sDltHlp_F_writeUint32ToByteArray_v(v_Resp_s.Length_au8, v_Len_u16, sDltCfg_d_HEADER_PAYLOAD_ENDIANES);
        sDltEnv_MemCpy_v(v_Resp_s.SwVersion_au8, sDltCfg_C_SoftwareVersionString_u8, v_Len_u16);
        v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
      }
      else
      {
        v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)(sizeof(v_Resp_s.Status_u8) + sizeof(v_Resp_s.Length_au8) + v_Len_u16);
  }
}

static sDlt_F_DumpMode_t sDlt_F_DumpMode_fp = NULL;
void sDlt_F_RegisterDumpModeFunc_v(sDlt_F_DumpMode_t i_CallBack_pf)
{
  sDlt_F_DumpMode_fp = i_CallBack_pf;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_switchDumpMode_v(sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_SwitchDumpModeResponse_t v_Resp_s;
  sDlt_s_SwitchDumpModeRequest_t v_Req_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == sizeof(sDlt_s_SwitchDumpModeRequest_t))
    {
      /* get data from PDU payload */
      if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, (void*)&v_Req_s, (sDltPdu_s_Length_t)sizeof(v_Req_s)))
      {
        /* check if cmd is valid */
        if (v_Req_s.Cmd_u8 <= 1u)
        {
          if ((b_Ctrl_ps->ConId_t == 0u) && (b_Ctrl_ps->SesId_t == 0u))
          {
            sDlt_V_Data_s.DumpMode_u8 = v_Req_s.Cmd_u8;
            if (sDlt_F_DumpMode_fp != NULL)
            {
              sDlt_F_DumpMode_fp();
            }
            v_Resp_s.Status_u8 = sDltCfg_D_CTRL_OK;
          }
          else
          {
            v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
          }
        }
      }
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_SwitchDumpModeResponse_t);
  }
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDlt_F_messageBufferOverflow_v (sDlt_s_ControlData_t *b_Ctrl_ps)
{
  sDlt_s_messageBufferOverflowResponse_t v_Resp_s;

  /* assume invalid parameter */
  v_Resp_s.Status_u8 = sDltCfg_D_CTRL_ERROR;

  /* check remaining size of payload */
  if(b_Ctrl_ps != NULL)
  {
    if (b_Ctrl_ps->RxLen_t == 0)
    {
      if (sDlt_V_Data_s.MessageBufferOverflow_b == FALSE)
      {
        v_Resp_s.OvrflwStatus_u8 = 0u;
      }
      else
      {
        v_Resp_s.OvrflwStatus_u8 = 1u;
      }
      /*v_Resp_s->Status_u8 = sDltCfg_D_CTRL_OK; status currently not maintained */
      v_Resp_s.Status_u8 = sDltCfg_D_CTRL_NOT_SUPPORTED;
    }

    sDltEnv_MemCpy_v(b_Ctrl_ps->Resp_pu8, &v_Resp_s, sizeof(v_Resp_s));
    b_Ctrl_ps->TxLen_t = (sDltPdu_s_Length_t)sizeof(sDlt_s_messageBufferOverflowResponse_t);
  }
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltctrl.c */
