/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   Dlt
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the DltHdr - Diagnostic log and trace header support
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"
#include "dlthdr.h"
#include "dlthlp.h"
#include "dltpdu.h"


/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */
const u8 sDltCfg_C_EcuId_u8[sDltCfg_d_HDR_LEN_ECUID] = sDltCfg_D_ECUID; // PRQA S 1504 // keep this here

/* --- Private Function Declarations ----------------------------------------------- */

/* --- Private Function Definitions ------------------------------------------------ */

/* --- Public Function Definitions ------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
u8 sDltHdr_F_assembleStandardHeader_u8 (sDlt_s_Header_t i_Header_t, u32 i_SessionId_u32, u32 i_TimeStamp_u32)
{
  u8 v_HeaderIdx_u8 = 0;
  u32 v_EcuId_u32;

  /* assembly header */
  /* set version and endianess of dlt data protocol */
  if(i_Header_t != NULL)
  {
    i_Header_t[sDltCfg_d_HDR_IDX_HTYP] = sDltCfg_D_HTYP_VERS;
  #if (sDltCfg_d_HEADER_PAYLOAD_ENDIANES == sDltCfg_D_BIG_ENDIAN)
    /**
     * [SWS_Dlt_00097] - If the MSBF bit is set, the most significant byte shall be
     * first in payload (big endian format).
     */
    i_Header_t[sDltCfg_d_HDR_IDX_HTYP] += sDltCfg_D_HTYP_MSBF;
  #endif

    /* set consecutive message number */
    i_Header_t[sDltCfg_d_HDR_IDX_MCNT] = sDlt_V_Data_s.MessageCount_u8;

    /* calculate index to optional part */
    v_HeaderIdx_u8 = sDltCfg_d_HDR_IDX_ECUID;

    /* write ECU ID if enabled */
    if (sDlt_V_Data_s.HeaderUseEcuId_b != FALSE)
    {
      v_EcuId_u32 = sDltHlp_F_writeByteArrayToUint32_u32(sDltCfg_C_EcuId_u8, sDltCfg_D_BIG_ENDIAN);
      sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], v_EcuId_u32, sDltCfg_D_BIG_ENDIAN);
      i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_WEID;
      v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_ECUID; // PRQA S 2984 // This operation is redundant // keep it for readability
    }

    /**
     * [SWS_Dlt_00091] - The Standard Header and the Extended Header shall be in big endian format (MSB first).
     */

    /* write session ID if enabled */
    if (sDlt_V_Data_s.HeaderUseSessionId_b != FALSE)
    {
      sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], i_SessionId_u32, sDltCfg_D_BIG_ENDIAN);
      i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_WSID;
      v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_SEID;
    }

  #ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
    /* write time stamp if enabled */
    if (sDlt_V_Data_s.HeaderUseTimestamp_b != FALSE)
    {
      sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], i_TimeStamp_u32, sDltCfg_D_BIG_ENDIAN);
      i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_WTMS;
      v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_TMSP;
    }
  #else
    (void)timeStamp;
  #endif

    /* set message length zero */
    i_Header_t[sDltCfg_d_HDR_IDX_LEN] = 0;
    i_Header_t[sDltCfg_d_HDR_IDX_LEN+1] = 0;
  }

  /* return number of written bytes */
  return v_HeaderIdx_u8;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
u8 sDltHdr_F_assembleExtendedHeader_u8 (sDlt_s_Header_t i_Header_t, sDlt_s_MessageType_t i_Mstp_t,
    u8 i_Mtin_u8, sDlt_s_MessageOptions_t i_Mopt_t, sDlt_s_MessageArgumentCount_t i_Margc_t,
    sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t)
#else
u8 sDltHdr_F_assembleExtendedHeader_u8 (sDlt_s_Header_t i_Header_t, sDlt_s_MessageType_t i_Mstp_t,
    u8 i_Mtin_u8, sDlt_s_MessageOptions_t i_Mopt_t, u8 i_Margc_u8,
    sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t)
#endif
{
  u8 v_RetVal_u8;
  u8 v_Margc_u8;

#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
  v_Margc_u8 = i_Margc_t;
#else
  v_Margc_u8 = i_Margc_u8;
#endif

  /* assume no data written to extended header */
  v_RetVal_u8 = 0u;

  /* check if extended header is used */
  if ((i_Header_t != NULL) && (sDlt_V_Data_s.HeaderUseExtendedHeader_b != FALSE))
  {
    /* set MSTP message type in MSIN message info bit 1:3 and message type info MTIN bit 4:7 */
    i_Header_t[sDltCfg_d_HDR_IDX_MSIN] = (u8)(i_Mstp_t << 1u) | (u8)(i_Mtin_u8 << 4u);

    /* check if message is a verbose message */
    if ((i_Mopt_t & sDltCfg_D_MOPT_VERBOSE_MODE) != 0u)
    {
      /* VERB verbose flag in MSIN message info bit 0 */
      i_Header_t[sDltCfg_d_HDR_IDX_MSIN] |= sDltCfg_D_TYPE_VERBOSE;
    }
    else
    {
      /**
       * [SWS_Dlt_00126] - Number of Arguments shall contain in Verbose Mode the number of
       * provided arguments within the payload. In Non Verbose Mode it shall contain 0x0.
       */
      v_Margc_u8 = 0u;
    }

    i_Header_t[sDltCfg_d_HDR_IDX_NOAR] = v_Margc_u8;

    /**
     * [SWS_Dlt_00091] - The Standard Header and the Extended Header shall be in big endian format (MSB first).
     */

    sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[sDltCfg_d_HDR_IDX_APID], (u32)i_AppId_t, sDltCfg_D_BIG_ENDIAN);
    sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[sDltCfg_d_HDR_IDX_CTID], (u32)i_ContextId_t, sDltCfg_D_BIG_ENDIAN);

    v_RetVal_u8 = sDltCfg_d_HDR_IDX_CTID + sDltCfg_d_HDR_LEN_CTID;
  }

  /* return number of written bytes */
  return v_RetVal_u8;
}
#endif

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
BOOL sDltHdr_F_evaluateRequestHeader_b (struct sDlt_s_ControlData_s * b_Ctrl_ps)
{
  u32 v_EcuIdCfg_u32;
  u32 v_EcuIdRx_u32;
  u8 v_ServiceId_au8[sDltCfg_d_HDR_LEN_SID];
  sDlt_s_Header_t v_Header_t;
  BOOL v_RetVal_b;

  /* assume invalid header configuration */
  v_RetVal_b = FALSE;

  /* fetch necessary standard header information (HTYP, MCNT, LEN, ECUID) */
  if(b_Ctrl_ps != NULL)
  {
    if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, v_Header_t, sDltCfg_d_HDR_LEN_STD))
    {
      /* collect information from standard header */
      /* store type of endianess */
      if ((v_Header_t[sDltCfg_d_HDR_IDX_HTYP] & sDltCfg_D_HTYP_MSBF) == sDltCfg_D_HTYP_MSBF)
      {
        b_Ctrl_ps->Endian_u8 = sDltCfg_D_BIG_ENDIAN;
      }
      else
      {
        b_Ctrl_ps->Endian_u8 = sDltCfg_D_LITTLE_ENDIAN;
      }

      /* store length of received message */
      b_Ctrl_ps->RxLen_t = (sDltPdu_s_Length_t)sDltHlp_F_writeByteArrayToUint16_u16(&v_Header_t[sDltCfg_d_HDR_IDX_LEN], b_Ctrl_ps->Endian_u8);
      /* get received ECU ID */
      v_EcuIdRx_u32 = sDltHlp_F_writeByteArrayToUint32_u32(&v_Header_t[sDltCfg_d_HDR_IDX_ECUID], b_Ctrl_ps->Endian_u8);
      /* get configured ECU ID */
      v_EcuIdCfg_u32 = sDltHlp_F_writeByteArrayToUint32_u32(sDltCfg_C_EcuId_u8, b_Ctrl_ps->Endian_u8);

      /**
       * 7.7.7.1  Control messages
       *    [SWS_Dlt_00187] - Control messages are in general normal Dlt messages
       *    with a Standard Header, an Extended Header and payload
       */

      /* check for attached extended header and correct protocol version and matching ecu id */
      if ( ((v_Header_t[sDltCfg_d_HDR_IDX_HTYP] & sDltCfg_D_HTYP_UEH) == sDltCfg_D_HTYP_UEH)
          /* check for correct DLT protocol version */
          && ((v_Header_t[sDltCfg_d_HDR_IDX_HTYP] & sDltCfg_D_HTYP_VERS_MASK) == sDltCfg_D_HTYP_VERS)
          /* check ECUID exists */
          && ((v_Header_t[sDltCfg_d_HDR_IDX_HTYP] & sDltCfg_D_HTYP_WEID) == sDltCfg_D_HTYP_WEID)
          /* check for correct ECUID */
          && (v_EcuIdCfg_u32 == v_EcuIdRx_u32))
      {
        /* assume session id is not present */
        b_Ctrl_ps->SesId_t = 0u;
        /* check if session id is attached to the header */
        if ((v_Header_t[sDltCfg_d_HDR_IDX_HTYP] & sDltCfg_D_HTYP_WSID) == sDltCfg_D_HTYP_WSID)
        {
          /* fetch session id from pdu */
          if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, &v_Header_t[sDltCfg_d_HDR_IDX_SEID], sDltCfg_d_HDR_LEN_SEID))
          {
            /* store session id header */
            b_Ctrl_ps->SesId_t = (sDlt_s_SessionId_t)sDltHlp_F_writeByteArrayToUint32_u32(&v_Header_t[sDltCfg_d_HDR_IDX_SEID], sDltCfg_D_BIG_ENDIAN);
          }
        }

        /* check if time stamp is attached to the header */
        if ((v_Header_t[sDltCfg_d_HDR_IDX_HTYP] & sDltCfg_D_HTYP_WTMS) == sDltCfg_D_HTYP_WTMS)
        {
          /* ignore time stamp by increment PDU source index with time stamp length */
          b_Ctrl_ps->PduIdx_t += sDltCfg_d_HDR_LEN_TMSP;
        }

        /* read necessary extended header information (MSIN, NOAR, APID, CTID) */
        if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, v_Header_t, sDltCfg_d_HDR_LEN_EXT))
        {
          /**
           * [SWS_Dlt_00189] - Control messages shall be sent in Non-Verbose Mode.
           */
          /* check if verbose mode is disabled */
          if ( ((v_Header_t[sDltCfg_d_HDR_IDX_MSIN] & sDltCfg_D_TYPE_VERBOSE) == 0u)
              /* check if received message type is a control type message */
              && ((v_Header_t[sDltCfg_d_HDR_IDX_MSIN] & (u8)(sDltCfg_D_TYPE_CONTROL << 1))
                  == (u8)(sDltCfg_D_TYPE_CONTROL << 1))
                  /* check if received control message is a request message */
                  && ((v_Header_t[sDltCfg_d_HDR_IDX_MSIN] & (u8)(sDltCfg_D_CONTROL_REQUEST << 4))
                      == (u8)(sDltCfg_D_CONTROL_REQUEST << 4)) )
          {
            /* check if message length has the appropriate length */
            if (b_Ctrl_ps->RxLen_t > b_Ctrl_ps->PduIdx_t)
            {
              /**
               * due to autobisar specification some services expect the application id and
               * context id in the payload and some other services expect this information
               * in the header (get/set verbose)
               */
              /* get application id and context id from header */
              b_Ctrl_ps->AppId_t = (sDlt_s_ApplicationId_t)sDltHlp_F_writeByteArrayToUint32_u32(&v_Header_t[sDltCfg_d_HDR_IDX_APID], sDltCfg_D_BIG_ENDIAN);
              b_Ctrl_ps->ConId_t = (sDlt_s_ContextId_t)sDltHlp_F_writeByteArrayToUint32_u32(&v_Header_t[sDltCfg_d_HDR_IDX_CTID], sDltCfg_D_BIG_ENDIAN);

              /* fetch service id from payload */
              if (E_OK == sDltPdu_F_copyFromPdu_t(b_Ctrl_ps->PduId_t, &b_Ctrl_ps->PduIdx_t, v_ServiceId_au8, sDltCfg_d_HDR_LEN_SID))
              {
                /* store service id */
                b_Ctrl_ps->ServiceId_u32 = sDltHlp_F_writeByteArrayToUint32_u32(v_ServiceId_au8, sDltCfg_D_BIG_ENDIAN);

                /* calculate remaining payload length */
                b_Ctrl_ps->RxLen_t -= b_Ctrl_ps->PduIdx_t;
                /* we have some payload to evaluate */
                v_RetVal_b = !FALSE;
              }
            }
          }
        }
      }
    }
  }

  return v_RetVal_b;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
u8 sDltHdr_F_assembleResponseHeader_u8 (const struct sDlt_s_ControlData_s * i_Ctrl_ps, sDlt_s_Header_t i_Header_t)
{
  u8 v_HeaderIdx_u8 = 0;
  u32 v_Tmp_u32;

  /* assembly standard header */
  /* set version and endianess of dlt data protocol */
  if((i_Header_t != NULL) && (i_Ctrl_ps != NULL))
  {
    i_Header_t[sDltCfg_d_HDR_IDX_HTYP] = sDltCfg_D_HTYP_VERS;
  #if (sDltCfg_d_HEADER_PAYLOAD_ENDIANES == sDltCfg_D_BIG_ENDIAN)
    /**
     * [SWS_Dlt_00097] - If the MSBF bit is set, the most significant byte shall be
     * first in payload (big endian format).
     */
    i_Header_t[sDltCfg_d_HDR_IDX_HTYP] += sDltCfg_D_HTYP_MSBF;
  #endif

    /* set consecutive message number */
    i_Header_t[sDltCfg_d_HDR_IDX_MCNT] = sDlt_V_Data_s.MessageCount_u8;

    /* calculate index to optional part */
    v_HeaderIdx_u8 = sDltCfg_d_HDR_IDX_ECUID;

    /* write ECU ID */
    v_Tmp_u32 = sDltHlp_F_writeByteArrayToUint32_u32(sDltCfg_C_EcuId_u8, sDltCfg_D_BIG_ENDIAN);
    sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], v_Tmp_u32, sDltCfg_D_BIG_ENDIAN);
    i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_WEID;
    v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_ECUID; // PRQA S 2984 // want to increase header index in a logical order

    /* write session id if present */
    if (i_Ctrl_ps->SesId_t != 0u)
    {
      sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], (u32)i_Ctrl_ps->SesId_t, sDltCfg_D_BIG_ENDIAN);
      i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_WSID;
      v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_SEID; // PRQA S 2984 // want to increase header index in a logical order
    }

    /* write time stamp if requested */
    if ((i_Ctrl_ps->Htyp_u8 & sDltCfg_D_HTYP_WTMS) != 0u)
    {
      sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], sDltCfg_d_GPT_CHANNEL, sDltCfg_D_BIG_ENDIAN);
      i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_WTMS;
      v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_TMSP; // PRQA S 2984 // want to increase header index in a logical order
    }

    /**
     * [SWS_Dlt_00188] - In the Standard Header the Application ID, Context ID, Session
     * ID and Timestamp may be left blank. This means that they should be filled with zeros
     * (0) if it not used otherwise in the control message. The fields Timestamp and
     * SessionID of the Standard Header can be left by setting the bits WSID or WTMS to zero.
     */

    /**
     * [SWS_Dlt_00187] - Control messages are in general normal Dlt messages with a
     * Standard Header, an Extended Header and payload.
     */

    /* assembly extended header */
    i_Header_t[sDltCfg_d_HDR_IDX_HTYP] |= sDltCfg_D_HTYP_UEH;

    /* set MSTP message type in MSIN message info bit 1:3 and message type info MTIN bit 4:7 */
    /* verbose mode not supported in response header */
    i_Header_t[v_HeaderIdx_u8] = i_Ctrl_ps->Msin_u8;
    v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_MSIN;

    /* no argument count */
    i_Header_t[v_HeaderIdx_u8] = 0u;
    v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_NOAR;

    /* write application id and context id as received */
    sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], (u32)i_Ctrl_ps->AppId_t, sDltCfg_D_BIG_ENDIAN);
    v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_APID;
    sDltHlp_F_writeUint32ToByteArray_v(&i_Header_t[v_HeaderIdx_u8], (u32)i_Ctrl_ps->ConId_t, sDltCfg_D_BIG_ENDIAN);
    v_HeaderIdx_u8 += sDltCfg_d_HDR_LEN_CTID;

  }

  /* return number of written bytes */
  return v_HeaderIdx_u8;
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlthdr.c */
