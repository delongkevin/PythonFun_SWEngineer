/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltCom
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the DltCom - Diagnostic log and trace communication module
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
//#include "cfg/dlt_env.h"
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"
#include "dlt.h"
#include "dltcom.h"
#include "dltpdu.h"

/* -------------------------------------------------------------------------- */

/* The two sides of DltCom, Dlt and IsoTP, are only loosely coupled:
 * in receive direction because the RxIndication from IsoTP may come from an
 * interrupt handler, in transmit direction, because we want to limit the
 * number of PDUs used by Dlt.
 * In order to keep the sides separated queues are used, and because we
 * want to make it as static as possible we used fixed-sized queues instead
 * of the linked lists used elsewhere.
 */

/* the array for the txqueue */

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */
/* TODO - ugl unused -static BOOL sDltCom_v_TxChannelBusy;*/ /* status of DLT IsoTP channel */
static sDltCom_F_SendBuffer_t sDltCom_F_SendBuffer_fp = NULL;

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */

/* --- Private Function Declarations ----------------------------------------------- */

/* --- Private Function Definitions ------------------------------------------------ */

/* --- Public Function Definitions ------------------------------------------------- */
void sDltCom_F_RegisterSendBufferFunc_v(sDltCom_F_SendBuffer_t i_CallBack_pf)
{
  sDltCom_F_SendBuffer_fp = i_CallBack_pf;
}

/** @file dltcom.h */
void sDltCom_F_Init_v (void)
{
}

/* -------------------------------------------------------------------------- */
/** @file dltcom.h */
void sDltCom_F_startOfReception_t(u16 i_Length_t, sDltPdu_s_PduInfo_t **o_Buffer_pps)
{
  DltStd_ReturnType v_RetVal_t;
  sPdu_s_Id_t v_Id_pt;
  sDltPdu_s_Info_t v_Info_ps;

  if(o_Buffer_pps != NULL)
  {
    v_RetVal_t = sDltPdu_F_getPdu_t(&v_Id_pt, &v_Info_ps, (sDltPdu_s_Length_t) i_Length_t);

    if (v_RetVal_t == E_OK)
    {
      (void)sDltPdu_F_PduIdToPtr_t(v_Id_pt, o_Buffer_pps);
    }
    else
    {
      *o_Buffer_pps = NULL;
    }
  }
}

/* -------------------------------------------------------------------------- */
/** @file dltcom.h */
DltStd_ReturnType sDltCom_F_startOfTransmission_t(sPdu_s_Id_t * o_Id_pt, sDltPdu_s_Info_t * o_Info_ps,
    sDltPdu_s_Length_t i_Length_t)
{
  DltStd_ReturnType v_RetVal_t;
  
  v_RetVal_t = sDltPdu_F_getPdu_t(o_Id_pt, o_Info_ps, i_Length_t);
  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dltcom.h */
DltStd_ReturnType sDltCom_F_transmit_t(sPdu_s_Id_t i_Id_t, const sDltPdu_s_Info_t* i_Info_ps)
{
  DltStd_ReturnType v_RetVal_t;
  sDltPdu_s_PduInfo_t *v_Pdu_ps;

  v_RetVal_t = E_NOT_OK;

  if(i_Info_ps != NULL)
  {
    v_RetVal_t = sDltPdu_F_PduIdToPtr_t(i_Id_t, &v_Pdu_ps);
    if(v_RetVal_t == E_OK)
    {
      /* set number of bytes to be sent */
      sDltPdu_F_SetIsoTpLength_v(v_Pdu_ps, (u16)i_Info_ps->SduLength_t);
      /* add to tx queue */

      #ifdef EMB_TESTING__
      sPdu_F_DumpPdu(v_Pdu_ps);
      #endif
      /* TODO - ugl unused - sDltCom_v_TxChannelBusy = TRUE;*/

      if (sDltCom_F_SendBuffer_fp != NULL)
      {
        if (sDltCom_F_SendBuffer_fp (sDltCfg_d_SEND_CHANNEL, v_Pdu_ps) != TRUE)
        {
          v_RetVal_t = E_NOT_OK;
        }
        else
        {
          /* Do nothing */
        }
      }
    }
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dltcom.h */
bool_t sDltCom_F_RxIndication_b(sDltPdu_s_PduInfo_t *i_Pdu_ps, u16 i_Length_u16)
{
  bool_t v_RV_b = false;

  if(i_Pdu_ps != NULL)
  {
    sDltPdu_F_SetIsoTpLength_v(i_Pdu_ps, i_Length_u16);
    v_RV_b = sDlt_F_comRxIndication_b(i_Pdu_ps->PduId_t, E_OK);
    /* free assigned PDU */
    (void)sDltPdu_F_putPdu_t(i_Pdu_ps->PduId_t);
  }

  return v_RV_b;
}

/* -------------------------------------------------------------------------- */
/** @file dltcom.h */
void sDltCom_F_txConfirmation_v(const sDltPdu_s_PduInfo_t *i_Pdu_ps, u16 i_Length_u16)
{
  /* release the pdu */
  (void)i_Length_u16; /* TODO - ugl unused - */

  if(i_Pdu_ps != NULL)
  {
    (void)sDltPdu_F_putPdu_t(i_Pdu_ps->PduId_t);
  }
  /* TODO - ugl unused - sDltCom_v_TxChannelBusy = FALSE;*/
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltcom.c */

