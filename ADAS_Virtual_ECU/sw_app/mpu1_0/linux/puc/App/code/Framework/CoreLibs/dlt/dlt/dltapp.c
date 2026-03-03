/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltApp
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the interface between Dlt and application
 *
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"
#include "dlt.h"
#include "dltpdu.h"
#include "dlthdr.h"
#include "dlthlp.h"
#include "dltcom.h"
#include "dltapp.h"
#include "dltapp_defs.h"

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */
/* length of type info in bytes */
#define sDltApp_d_PAYLOAD_TINFO_SIZE   4

/* values in byte 0 */
#define sDltApp_d_PAYLOAD_TYLE_UNDEF   0x00
#define sDltApp_d_PAYLOAD_TYLE_BIT8    0x01
#define sDltApp_d_PAYLOAD_TYLE_BIT16   0x02
#define sDltApp_d_PAYLOAD_TYLE_BIT32   0x03
#define sDltApp_d_PAYLOAD_TYLE_BIT64   0x04
#define sDltApp_d_PAYLOAD_TYLE_BIT128  0x05

#define sDltApp_d_PAYLOAD_TYPE_BOOL    0x10
#define sDltApp_d_PAYLOAD_TYPE_SINT    0x20
#define sDltApp_d_PAYLOAD_TYPE_UINT    0x40
#define sDltApp_d_PAYLOAD_TYPE_FLOA    0x80

/* values in byte 1 */
#define sDltApp_d_PAYLOAD_TYPE_ARAY    0x01
#define sDltApp_d_PAYLOAD_TYPE_STRG    0x02
#define sDltApp_d_PAYLOAD_TYPE_RAWD    0x04
#define sDltApp_d_PAYLOAD_TYPE_VARI    0x08
#define sDltApp_d_PAYLOAD_TYPE_FIXP    0x10
#define sDltApp_d_PAYLOAD_TYPE_TRAI    0x20
#define sDltApp_d_PAYLOAD_TYPE_STRU    0x40
#define sDltApp_d_PAYLOAD_TYPE_SCOD1   0x00

/* values in byte 2 */
#define sDltApp_d_PAYLOAD_TYPE_SCODASC  0x00
#define sDltApp_d_PAYLOAD_TYPE_SCODUTF8 0x40

/* --- Private Macros -------------------------------------------------------------- */
/* all other null */
#define SWAP_BYTE(b0, b1)  \
  do                       \
  {                        \
    uint8_t tmp = (b0);      \
    (b0) = (b1);               \
    (b1) = (tmp);              \
  }                        \
  while (0)

#define SWAP4(ti)               \
  do                            \
  {                             \
    SWAP_BYTE((ti)[0], (ti)[3]);    \
    SWAP_BYTE((ti)[1], (ti)[2]);    \
  }                             \
  while (0)

#if sDltCfg_D_BIG_ENDIAN == STD_ON
#define TYPEINFO_SWAP(ti)        \
  do                             \
  {                              \
    SWAP4(ti);                   \
  }                              \
  while (0)
#elif sDltCfg_D_BIG_ENDIAN == STD_OFF
#define TYPEINFO_SWAP(ti)        \
  do                             \
  {                              \
    ;                            \
  }                              \
  while (0)
#endif

/* --- Extern Declarations --------------------------------------------------------- */
/* session table for Dlt
 * no callbacks are defined
 */

const sDlt_s_SessionIdTable_t sDltCfg_C_SessionIdTable_t [/*sDltApp_d_MAX_COUNT_SESSIONIDS*/] =
{
    /*    session_id,      cbSetLogLevel,      cbSetTraceStatus */
    { DLTAPP_SID_DEFAULT, NULL, NULL
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
        /* cbSetVerboseMode */
        , NULL
        /* cbGetVerboseMode */
        , NULL
#endif
#ifdef sDltCfg_D_IMPLEMENT_SWC_INJECTION
        /* cbSwcInjection */
        , NULL
#endif
    },
};

/* define default configuration for DLT */
const sDlt_s_Config_t sDltCfg_C_Config_s =  /* PRQA S 1500 */ /* incorrect, used by dltctrl.c */
{
    10000U,                                   /* BandwidthForDiagChannel_u32 */
    10000U,                                   /* BandwidthForComModule_u32 */
    TRUE,                                   /* HeaderUseEcuId_b */
    FALSE,                                   /* HeaderUseSessionId_b */
    FALSE,                                   /* DefaultTraceStatus_b */
    sDltCfg_D_LOG_ERROR,  /* DefaultLogLevel_u8 */

    /* ECUC_Dlt_00836 - dependency: Can only be true if DltImplementVerboseMode is true. */
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
    !FALSE,                                   /* HeaderUseVerboseMode_b */
#else
    FALSE,                                    /* HeaderUseVerboseMode_b */
#endif
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
    !FALSE,                                   /* HeaderUseExtendedHeader_b */
#endif
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
    !FALSE,                                   /* FilterMessages_b */
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    !FALSE,                                   /* HeaderUseTimestamp_b */
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    FALSE,                                   /* SendCyclicTimestamp_b */
#endif
#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
    6U,                                       /* VfbTraceLogLevel_u8 */
#endif
};



/* --- Private Function Declarations ----------------------------------------------- */
#if 0
/* example declarations of session specific callbacks that may be used in the sDltCfg_C_SessionIdTable_t */
static void DltApp_SetLogLevel_v(sDlt_s_ApplicationId_t appId,
                                 sDlt_s_ContextId_t contextId,
                                 sDlt_s_MessageLogLevel_t logLevel);

static void DltApp_SetTraceStatus_v(sDlt_s_ApplicationId_t appId,
                                    sDlt_s_ContextId_t contextId,
                                    BOOL newTraceStatus);

#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
static void DltApp_SetVerboseMode_v(sDlt_s_ApplicationId_t appId,
                                    sDlt_s_ContextId_t contextId,
                                    BOOL isVerboseMode);

static BOOL DltApp_GetVerboseMode_b(sDlt_s_ApplicationId_t appId,
                                    sDlt_s_ContextId_t contextId);
#endif

#ifdef sDltCfg_D_IMPLEMENT_SWC_INJECTION
static void DltApp_InjectCall_v(sDlt_s_ApplicationId_t appId,
                                sDlt_s_ContextId_t contextId,
                                u32 serviceId,
                                u32 dataLength,
                                const u8* data);
#endif

#endif

static sDlt_s_Return_t sDltApp_f_AddVari2(sPdu_s_Id_t b_Pdu,
                                          sDltPdu_s_Length_t *b_DstIdx,
                                          const char_t* i_Name,
                                          const char_t* i_Unit);

static sDlt_s_Return_t sDltApp_f_AddVari1(sPdu_s_Id_t b_Pdu,
                                          sDltPdu_s_Length_t *b_DstIdx,
                                          const char_t* i_Name);

static sDlt_s_Return_t sDltApp_f_AddPayload(sDltApp_s_LogContext_t *b_LogMsgContext,
                                            u8 o_TypeInfo_pu8[],
                                            const char_t* i_Name,
                                            const char_t* i_Unit,
                                            const void * i_Val_pu8,
                                            u16 i_ValLen_u16);

/* --- Private Function Definitions ------------------------------------------------ */
/* format variable info for payload with name and unit
 * the size of the output parameter must be at least 6 bytes + the length of all strings.
 */

static sDlt_s_Return_t sDltApp_f_AddVari1(sPdu_s_Id_t b_Pdu, sDltPdu_s_Length_t *b_DstIdx, const char_t* i_Name)
{
  DltStd_ReturnType v_RVal;
  sDlt_s_Return_t v_RetVal = sDltCfg_D_E_OK;
  u16 v_NameLen = 0;
  u8 v_Tmp[2]; /* temp buffer fuer the variable info length */
  sDltPdu_s_Length_t v_DestIdx_t;

  if(b_DstIdx != NULL)
  {
    v_DestIdx_t = *b_DstIdx;

    /* have a name or unit */
    if(i_Name != NULL)
    {
      v_NameLen = sDltEnv_Strlen_u16(i_Name) + 1;
    }

    sDltHlp_F_writeUint16ToByteArray_v(&v_Tmp[0], v_NameLen, sDltCfg_D_BIG_ENDIAN);

    v_RVal = sDltPdu_F_copyToPdu_t(b_Pdu, &v_DestIdx_t, &v_Tmp[0], 2);
    if(v_RVal != E_OK)
    {
      v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
    }

    /* add variable info .. name */
    if((v_RetVal == sDltCfg_D_E_OK) && (v_NameLen > 0))
    {
      v_RVal = sDltPdu_F_copyToPdu_t(b_Pdu, &v_DestIdx_t, i_Name, v_NameLen);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    if (sDltCfg_D_E_OK == v_RetVal)
    {
      *b_DstIdx = v_DestIdx_t;
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

static sDlt_s_Return_t sDltApp_f_AddVari2(sPdu_s_Id_t b_Pdu, sDltPdu_s_Length_t *b_DstIdx,
                                          const char_t* i_Name, const char_t* i_Unit)
{
  DltStd_ReturnType v_RVal;
  sDlt_s_Return_t v_RetVal=sDltCfg_D_E_OK;
  u16 v_NameLen=0;
  u16 v_UnitLen=0;
  u8 v_Tmp[4]; /* temp buffer fuer the variable info length */
  sDltPdu_s_Length_t v_DstIdx_t;

  if(b_DstIdx != NULL)
  {
    v_DstIdx_t = *b_DstIdx;
    /* have a name or unit */
    if(i_Name != NULL)
    {
      v_NameLen = sDltEnv_Strlen_u16(i_Name) + 1;
    }
    if(i_Unit != NULL)
    {
      v_UnitLen = sDltEnv_Strlen_u16(i_Unit) + 1;
    }

    sDltHlp_F_writeUint16ToByteArray_v(&v_Tmp[0], v_NameLen, sDltCfg_D_BIG_ENDIAN);
    sDltHlp_F_writeUint16ToByteArray_v(&v_Tmp[2], v_UnitLen, sDltCfg_D_BIG_ENDIAN);

    v_RVal = sDltPdu_F_copyToPdu_t(b_Pdu, &v_DstIdx_t, &v_Tmp[0], 4);
    if(v_RVal != E_OK)
    {
      v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
    }

    /* add variable info .. name */
    if((v_RetVal == sDltCfg_D_E_OK) && (v_NameLen > 0))
    {
      v_RVal = sDltPdu_F_copyToPdu_t(b_Pdu, &v_DstIdx_t, i_Name, v_NameLen);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* add variable info .. unit */
    if((v_RetVal == sDltCfg_D_E_OK) && (v_UnitLen > 0))
    {
      v_RVal = sDltPdu_F_copyToPdu_t(b_Pdu, &v_DstIdx_t, i_Unit, v_UnitLen);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    if(v_RetVal == sDltCfg_D_E_OK)
    {
      *b_DstIdx = v_DstIdx_t;
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

static sDlt_s_Return_t sDltApp_f_AddPayload(sDltApp_s_LogContext_t *b_LogMsgContext,
                                            u8 o_TypeInfo_pu8[],
                                            const char_t* i_Name,
                                            const char_t* i_Unit,
                                            const void *i_Val_pu8,
                                            u16 i_ValLen_u16)
{
  DltStd_ReturnType v_RVal;
  sDlt_s_Return_t v_RetVal;
  sDltPdu_s_Length_t v_DstIdx;
  BOOL v_AddVari = FALSE;

  /* check needed pointers */
  if((b_LogMsgContext == NULL) || (o_TypeInfo_pu8 == NULL) || (i_Val_pu8 == NULL) || (i_ValLen_u16 == 0))
  {
    /* this should never happen */
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }
  else
  {
    v_RetVal = sDltCfg_D_E_OK;
    v_DstIdx = b_LogMsgContext->DltPduInfo.SduLength_t;

    /* 4th byte is always 0 */
    o_TypeInfo_pu8[3] = 0;

    /* have a name or unit */
    if((i_Name != NULL) || (i_Unit != NULL))
    {
      o_TypeInfo_pu8[1] |= sDltApp_d_PAYLOAD_TYPE_VARI;
      v_AddVari = TRUE;
    }

    TYPEINFO_SWAP(o_TypeInfo_pu8);
    /* write type info */
    v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, o_TypeInfo_pu8, sDltApp_d_PAYLOAD_TINFO_SIZE);
    if(v_RVal != E_OK)
    {
      v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
    }

    if(v_RetVal == sDltCfg_D_E_OK)
    {
      if(v_AddVari != FALSE)
      {
        /* add variable info */
        v_RetVal = sDltApp_f_AddVari2(b_LogMsgContext->DltPdu, &v_DstIdx, i_Name, i_Unit);
      }
    }

    /* variable data added, now the value in local format */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, i_Val_pu8, i_ValLen_u16);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* done with adding data, remember length */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      /* we use the sdu length to keep track of the used data because the pdu knows its maximum length */
      b_LogMsgContext->DltPduInfo.SduLength_t = v_DstIdx;
      b_LogMsgContext->DltLogInfo.ArgCount_t++;
    }
  }
  return v_RetVal;
}

/* --- Public Function Definitions ------------------------------------------------- */
void sDltApp_F_Init_v(void)
{
  sDlt_F_init_v(&sDltCfg_C_Config_s);
  /* example: register context for all valid app/context pairs */

  sDltPdu_F_Init_v();
}

sDlt_s_Return_t sDltApp_F_RegisterContext(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t)
{
  return sDlt_F_registerContext_t (DLTAPP_SID_DEFAULT, i_AppId_t, i_ContextId_t, NULL, 0, NULL, 0);
}

/*
 * aDltApp_F_StartLogMessage - start a log message. Reserves a PDU, writes most of
 * the header (except the number of arguments), checks if the emssage should be
 * filtered.
 *
 * \param o_LogMsgContext   A structure keeping all information that is needed to assemble
 *                          the log message.
 *
 *
 */
sDlt_s_Return_t sDltApp_F_StartLogMessage(sDltApp_s_LogContext_t *o_LogMsgContext,
                                          sDlt_s_Timestamp_t i_Timestamp,
                                          sDlt_s_ApplicationId_t i_LogAppId,
                                          sDlt_s_ContextId_t i_LogCtxId,
                                          sDlt_s_MessageLogLevel_t i_LogLevel)
{
  sDlt_s_Return_t v_RetVal;
  DltStd_ReturnType v_RVal;
  sDlt_s_Header_t v_Header;
  sDltPdu_s_Length_t v_HeaderLen;
  u8 v_ExtHeaderLen;
  sDltPdu_s_Length_t v_DstIdx;

  if(o_LogMsgContext != NULL)
  {
    o_LogMsgContext->DltLogInfo.AppId_t = i_LogAppId;
    o_LogMsgContext->DltLogInfo.ContextId_t = i_LogCtxId;
    o_LogMsgContext->DltLogInfo.LogLevel_t = i_LogLevel;
    o_LogMsgContext->DltLogInfo.ArgCount_t = 0;
    o_LogMsgContext->DltLogInfo.Options_t = sDltCfg_D_MOPT_VERBOSE_MODE;
    o_LogMsgContext->DltTimestamp = i_Timestamp;
    o_LogMsgContext->DltSession = DLTAPP_SID_DEFAULT;
    o_LogMsgContext->DltArgCountIdx = 0;
    o_LogMsgContext->DltPduInfo.SduLength_t = 0;

    /* check if log message has to be filtered */
    v_RetVal = sDlt_F_checkLogMessageFilter_t(&(o_LogMsgContext->DltLogInfo));

    /* check if message is not filtered */
    if (v_RetVal == sDltCfg_D_E_OK)
    {
      /* message not filtered, proceed:
       * signal to dltcom that we plan to send something.
       * this essentially reserves a pdu
       */

      v_RVal = sDltCom_F_startOfTransmission_t(&(o_LogMsgContext->DltPdu), &(o_LogMsgContext->DltPduInfo), sDltPdu_d_MAX_PDU_LEN);
      if(v_RVal == E_OK)
      {
        /* have a pdu, assemble header locally, then copy to pdu */
        v_HeaderLen = sDltHdr_F_assembleStandardHeader_u8(&v_Header[0],
                                       o_LogMsgContext->DltSession, o_LogMsgContext->DltTimestamp);
        o_LogMsgContext->DltArgCountIdx = v_HeaderLen;
        /* extended header, arg count is zero for now, will be updated later */
        v_ExtHeaderLen = sDltHdr_F_assembleExtendedHeader_u8(&v_Header[v_HeaderLen], sDltCfg_D_TYPE_LOG,
                         i_LogLevel, o_LogMsgContext->DltLogInfo.Options_t, 0, i_LogAppId, i_LogCtxId);
        if (v_ExtHeaderLen > 0u)
        {
          /* set extended header flag */
          v_Header[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_UEH;
          /* arg counter is second in extended header (= after standard header) */
          o_LogMsgContext->DltArgCountIdx = v_HeaderLen + sDltCfg_d_HDR_IDX_NOAR;
          v_HeaderLen += v_ExtHeaderLen;
        }
        /* copy header to pdu */
        v_DstIdx = 0u;
        v_RVal = sDltPdu_F_copyToPdu_t(o_LogMsgContext->DltPdu, &v_DstIdx, &v_Header[0], v_HeaderLen);
        if(v_RVal == E_OK)
        {
          /* we use the sdu length to keep track of the used data because the pdu knows its maximum length */
          o_LogMsgContext->DltPduInfo.SduLength_t = v_DstIdx;
        }
        else
        {
          v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
        }
      }
      else
      {
        /* no pdu, the most likely reason being that no bufer of the expected length was found */
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}


/*
 * finish the log message and send it
 * the message is alread assembled in the pdu
 */

sDlt_s_Return_t sDltApp_F_EndLogMessage(sDltApp_s_LogContext_t *i_LogMsgContext)
{
  sDlt_s_Return_t v_RetVal;
  DltStd_ReturnType v_RVal;
  sDltPdu_s_Length_t v_HeaderIdx;
  sDltPdu_s_Length_t v_ArgCountIdx_t;
  u8 v_MsgLen_au8[2];

  /* update the argument count */
  if(i_LogMsgContext != NULL)
  {
    v_RVal = E_OK;
    v_ArgCountIdx_t = i_LogMsgContext->DltArgCountIdx;

    if (sDlt_V_Data_s.HeaderUseExtendedHeader_b == TRUE)
    {
      v_RVal = sDltPdu_F_copyToPdu_t(i_LogMsgContext->DltPdu, &(v_ArgCountIdx_t),
                                     &(i_LogMsgContext->DltLogInfo.ArgCount_t), 1);
    }
    else
    {
      /* Do nothing */
    }

    if(v_RVal == E_OK)
    {
      /* set message length in header */
      sDltHlp_F_writeUint16ToByteArray_v(&v_MsgLen_au8[0], i_LogMsgContext->DltPduInfo.SduLength_t, sDltCfg_D_BIG_ENDIAN);
      v_HeaderIdx = sDltCfg_d_HDR_IDX_LEN;
      v_RVal = sDltPdu_F_copyToPdu_t(i_LogMsgContext->DltPdu, &v_HeaderIdx, &v_MsgLen_au8[0], 2);

      if(v_RVal == E_OK)
      {
        v_RVal = sDltCom_F_transmit_t(i_LogMsgContext->DltPdu, &(i_LogMsgContext->DltPduInfo));
      }

      if (v_RVal == E_OK)
      {
        i_LogMsgContext->DltArgCountIdx = v_ArgCountIdx_t;
        i_LogMsgContext->DltPduInfo.SduLength_t = v_HeaderIdx;
        /* increment consecutive message number */
        sDlt_V_Data_s.MessageCount_u8++;
        v_RetVal = sDltCfg_D_E_OK;
      }
      else
      {
        v_RetVal = sDltCfg_D_E_IF_NOT_AVAILABLE;
      }
    }
    else
    {
      v_RetVal = sDltCfg_D_E_NOT_OK;
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}




sDlt_s_Return_t sDltApp_F_AddPayloadUInt8(sDltApp_s_LogContext_t *b_LogMsgContext, u8 i_Val_u8,
                                           const char_t* i_Name, const char_t* i_Unit)
{
  sDlt_s_Return_t v_RetVal;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];

  /* update the argument count */
  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT8 + sDltApp_d_PAYLOAD_TYPE_UINT;
    v_TypeInfo[1] = 0;
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_RetVal = sDltApp_f_AddPayload(b_LogMsgContext, &(v_TypeInfo[0]), i_Name, i_Unit, &i_Val_u8, 1u);
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}


sDlt_s_Return_t sDltApp_F_AddPayloadUInt16(sDltApp_s_LogContext_t *b_LogMsgContext, u16 i_Val_u16,
                                           const char_t* i_Name, const char_t* i_Unit)
{
  sDlt_s_Return_t v_RetVal;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];

  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT16 + sDltApp_d_PAYLOAD_TYPE_UINT;
    v_TypeInfo[1] = 0;
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_RetVal = sDltApp_f_AddPayload(b_LogMsgContext, &(v_TypeInfo[0]), i_Name, i_Unit, &i_Val_u16, 2u);
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}


sDlt_s_Return_t sDltApp_F_AddPayloadUInt32(sDltApp_s_LogContext_t *b_LogMsgContext, u32 i_Val_u32,
                                           const char_t* i_Name, const char_t* i_Unit)
{
  sDlt_s_Return_t v_RetVal;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];

  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT32 + sDltApp_d_PAYLOAD_TYPE_UINT;
    v_TypeInfo[1] = 0;
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_RetVal = sDltApp_f_AddPayload(b_LogMsgContext, &(v_TypeInfo[0]), i_Name, i_Unit, &i_Val_u32, 4u);
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}


sDlt_s_Return_t sDltApp_F_AddPayloadSInt8(sDltApp_s_LogContext_t *b_LogMsgContext, s8 i_Val_s8,
                                           const char_t* i_Name, const char_t* i_Unit)
{
  sDlt_s_Return_t v_RetVal;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];

  /* update the argument count */
  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT8 + sDltApp_d_PAYLOAD_TYPE_SINT;
    v_TypeInfo[1] = 0;
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_RetVal = sDltApp_f_AddPayload(b_LogMsgContext, &(v_TypeInfo[0]), i_Name, i_Unit, &i_Val_s8, 1u);
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

sDlt_s_Return_t sDltApp_F_AddPayloadSInt16(sDltApp_s_LogContext_t *b_LogMsgContext, s16 i_Val_s16,
                                           const char_t* i_Name, const char_t* i_Unit)
{
  sDlt_s_Return_t v_RetVal;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];

  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT16 + sDltApp_d_PAYLOAD_TYPE_SINT;
    v_TypeInfo[1] = 0;
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_RetVal = sDltApp_f_AddPayload(b_LogMsgContext, &(v_TypeInfo[0]), i_Name, i_Unit, &i_Val_s16, 2u);
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

sDlt_s_Return_t sDltApp_F_AddPayloadSInt32(sDltApp_s_LogContext_t *b_LogMsgContext, s32 i_Val_s32,
                                           const char_t* i_Name, const char_t* i_Unit)
{
  sDlt_s_Return_t v_RetVal;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];

  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT32 + sDltApp_d_PAYLOAD_TYPE_SINT;
    v_TypeInfo[1] = 0;
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_RetVal = sDltApp_f_AddPayload(b_LogMsgContext, &(v_TypeInfo[0]), i_Name, i_Unit, &i_Val_s32, 4u);
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

sDlt_s_Return_t sDltApp_F_AddPayloadBool(sDltApp_s_LogContext_t *b_LogMsgContext, BOOL i_Val_b, const char_t* i_Name)
{
  DltStd_ReturnType v_RVal;
  sDlt_s_Return_t v_RetVal=sDltCfg_D_E_OK;
  sDltPdu_s_Length_t v_DstIdx;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];
  BOOL v_AddVari;
  u8 v_Tmp;

  /* update the argument count */
  if(b_LogMsgContext != NULL)
  {
    v_TypeInfo[0] = sDltApp_d_PAYLOAD_TYLE_BIT8 + sDltApp_d_PAYLOAD_TYPE_BOOL;

    /* have a name or unit */
    if(i_Name != NULL)
    {
      v_TypeInfo[1] = sDltApp_d_PAYLOAD_TYPE_VARI;
      v_AddVari = TRUE;
    }
    else
    {
      v_TypeInfo[1] = 0;
      v_AddVari = FALSE;
    }
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_DstIdx = b_LogMsgContext->DltPduInfo.SduLength_t;

    TYPEINFO_SWAP(v_TypeInfo);
    v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, &v_TypeInfo[0], sDltApp_d_PAYLOAD_TINFO_SIZE);
    if(v_RVal != E_OK)
    {
      v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
    }

    if(v_AddVari != FALSE)
    {
      /* add variable info .. length */
      if(v_RetVal == sDltCfg_D_E_OK)
      {
        /* add variable info */
        v_RetVal = sDltApp_f_AddVari1(b_LogMsgContext->DltPdu, &v_DstIdx, i_Name);
      }
    }

    /* variable data added, now the value in local format */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      if(i_Val_b != FALSE)
      {
        v_Tmp = 0x01;
      }
      else
      {
        v_Tmp = 0x00;
      }
      v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, &v_Tmp, 1);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* done with adding data, remember length */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      /* we use the sdu length to keep track of the used data because the pdu knows its maximum length */
      b_LogMsgContext->DltPduInfo.SduLength_t = v_DstIdx;
      b_LogMsgContext->DltLogInfo.ArgCount_t++;
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

sDlt_s_Return_t sDltApp_F_AddPayloadString(sDltApp_s_LogContext_t *b_LogMsgContext, const char_t* i_Str, const char_t* i_Name)
{
  DltStd_ReturnType v_RVal;
  sDlt_s_Return_t v_RetVal=sDltCfg_D_E_OK;
  sDltPdu_s_Length_t v_DstIdx;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];
  sDltPdu_s_Length_t v_StrLen;
  BOOL v_AddVari;
  u8 v_Tmp[2];

  /* update the argument count */
  if((b_LogMsgContext != NULL) && (i_Str != NULL))
  {
    v_TypeInfo[0] = 0;

    /* have a name */
    if(i_Name != NULL)
    {
      v_TypeInfo[1] = sDltApp_d_PAYLOAD_TYPE_STRG + sDltApp_d_PAYLOAD_TYPE_VARI;
      v_AddVari = TRUE;
    }
    else
    {
      v_TypeInfo[1] =  sDltApp_d_PAYLOAD_TYPE_STRG;
      v_AddVari = FALSE;
    }
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_DstIdx = b_LogMsgContext->DltPduInfo.SduLength_t;

    TYPEINFO_SWAP(v_TypeInfo);
    v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, &v_TypeInfo[0], sDltApp_d_PAYLOAD_TINFO_SIZE);
    if(v_RVal != E_OK)
    {
      v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
    }

    /* strlen */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      v_StrLen = sDltEnv_Strlen_u16(i_Str)+1;
      sDltHlp_F_writeUint16ToByteArray_v(&v_Tmp[0], v_StrLen, sDltCfg_D_BIG_ENDIAN);

      v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, &v_Tmp[0], 2);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* the variable info */
    if(v_AddVari != FALSE)
    {
      /* add variable info .. length */
      if(v_RetVal == sDltCfg_D_E_OK)
      {
        /* add variable info */
        v_RetVal = sDltApp_f_AddVari1(b_LogMsgContext->DltPdu, &v_DstIdx, i_Name);
      }
    }

    /* and the string */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, (const void* )i_Str, v_StrLen);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* done with adding data, remember length */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      /* we use the sdu length to keep track of the used data because the pdu knows its maximum length */
      b_LogMsgContext->DltPduInfo.SduLength_t = v_DstIdx;
      b_LogMsgContext->DltLogInfo.ArgCount_t++;
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

sDlt_s_Return_t sDltApp_F_AddPayloadRaw(sDltApp_s_LogContext_t *b_LogMsgContext, const u8* i_Data,
                                               s16 i_DataLen, const char_t* i_Name)
{
  DltStd_ReturnType v_RVal;
  sDlt_s_Return_t v_RetVal=sDltCfg_D_E_OK;
  sDltPdu_s_Length_t v_DstIdx;
  u8 v_TypeInfo[sDltApp_d_PAYLOAD_TINFO_SIZE];
  BOOL v_AddVari;
  u8 v_Tmp[2];

  /* update the argument count */
  if((b_LogMsgContext != NULL) && (i_Data != NULL))
  {
    v_TypeInfo[0] = 0;

    /* have a name */
    if(i_Name != NULL)
    {
      v_TypeInfo[1] = sDltApp_d_PAYLOAD_TYPE_RAWD + sDltApp_d_PAYLOAD_TYPE_VARI;
      v_AddVari = TRUE;
    }
    else
    {
      v_TypeInfo[1] =  sDltApp_d_PAYLOAD_TYPE_RAWD;
      v_AddVari = FALSE;
    }
    v_TypeInfo[2] = 0;
    v_TypeInfo[3] = 0;

    v_DstIdx = b_LogMsgContext->DltPduInfo.SduLength_t;

    TYPEINFO_SWAP(v_TypeInfo);
    v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, &v_TypeInfo[0], sDltApp_d_PAYLOAD_TINFO_SIZE);
    if(v_RVal != E_OK)
    {
      v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
    }

    /* strlen */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      sDltHlp_F_writeUint16ToByteArray_v(&v_Tmp[0], (uint16_t) i_DataLen, sDltCfg_D_BIG_ENDIAN);

      v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, &v_Tmp[0], 2);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* the variable info */
    if(v_AddVari != FALSE)
    {
      /* add variable info .. length */
      if(v_RetVal == sDltCfg_D_E_OK)
      {
        /* add variable info */
        v_RetVal = sDltApp_f_AddVari1(b_LogMsgContext->DltPdu, &v_DstIdx, i_Name);
      }
    }

    /* and the data */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      v_RVal = sDltPdu_F_copyToPdu_t(b_LogMsgContext->DltPdu, &v_DstIdx, i_Data, (sDltPdu_s_Length_t) i_DataLen);
      if(v_RVal != E_OK)
      {
        v_RetVal = sDltCfg_D_E_MSG_TOO_LARGE;
      }
    }

    /* done with adding data, remember length */
    if(v_RetVal == sDltCfg_D_E_OK)
    {
      /* we use the sdu length to keep track of the used data because the pdu knows its maximum length */
      b_LogMsgContext->DltPduInfo.SduLength_t = v_DstIdx;
      b_LogMsgContext->DltLogInfo.ArgCount_t++;
    }
  }
  else
  {
    v_RetVal = sDltCfg_D_E_NOT_OK;
  }

  return v_RetVal;
}

#ifdef EMB_TESTING__
void sDltApp_F_DumpLogContext(sDltApp_s_LogContext_t *i_LogMsgContext)
{
  printf("log context at %p:\n", i_LogMsgContext);
  printf(" session %u\n", i_LogMsgContext->DltSession);
  printf(" timestamp %lu\n", i_LogMsgContext->DltTimestamp);
  printf(" pdu id %u\n", i_LogMsgContext->DltPdu);
  printf(" arg count %u\n", i_LogMsgContext->DltLogInfo.ArgCount_t);
  printf(" arg count idx %u\n", i_LogMsgContext->DltArgCountIdx);
}
#endif

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltapp.c */
