/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltPdu
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the DltPdu - Diagnostic log and trace PDU support
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "dlt_types.h"
#include "dltpdu.h"

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */
/* PRQA S 2022 2 */ /* initialized with sDltPdu_F_init_v(...) */
static sDltPdu_s_PduInfo_t sDltPdu_v_PDUEntry_s[sDltPdu_d_NUM_PDUS];
static uint8_t sDltPdu_v_Data_aau8[sDltPdu_d_NUM_PDUS][sDltPdu_d_SDU_LENGTH];



/* --- Private Function Declarations ----------------------------------------------- */

/* --- Private Function Definitions ------------------------------------------------ */

/* --- Public Function Definitions ------------------------------------------------- */
void sDltPdu_F_Init_v(void)
{
  sDltEnv_Memset_v(&sDltPdu_v_PDUEntry_s[0], 0, sizeof(sDltPdu_v_PDUEntry_s));
  sDltEnv_Memset_v(&sDltPdu_v_Data_aau8[0][0], 0, sizeof(sDltPdu_v_Data_aau8));
}

DltStd_ReturnType sDltPdu_F_getPdu_t (sPdu_s_Id_t *o_Id_pt, sDltPdu_s_Info_t *o_Info_ps, sDltPdu_s_Length_t i_Length_t)
{
  DltStd_ReturnType v_RetVal_t;

  sDltPdu_v_PDUEntry_s[0].PduData_pu8 = sDltPdu_v_Data_aau8[0];
  sDltPdu_v_PDUEntry_s[0].PduSize_u16 = sDltPdu_d_SDU_LENGTH;
  sDltPdu_v_PDUEntry_s[1].PduData_pu8 = sDltPdu_v_Data_aau8[1];
  sDltPdu_v_PDUEntry_s[1].PduSize_u16 = sDltPdu_d_SDU_LENGTH;

  /* ugl QA-C Msg. 4115, 3760, 4112: if (o_Id_pt && (*o_Id_pt) >= sPdu_D_PDU_NUMBER_OF_PDU) */
  /* TODO - ugl Check workaround regarding QA-C Msg. See commented out code above - */
  if ((o_Id_pt != NULL) && (*o_Id_pt >= sPdu_D_PDU_NUMBER_OF_PDU))
  {
    *o_Id_pt = 0;
  }
  else
  {
    /* Do nothing */
  }

  /* assume erroneous result */
  v_RetVal_t = E_NOT_OK;

  if ((o_Id_pt != NULL) && (o_Info_ps != NULL))
  {
    if(sDltPdu_v_PDUEntry_s[*o_Id_pt].PduStatus_e == sDltPdu_e_PDU_UNUSED)
    {
      *o_Id_pt = 0;
      o_Info_ps->SduLength_t = i_Length_t;
      o_Info_ps->SduDataPrt_pu8 = sDltPdu_v_PDUEntry_s[*o_Id_pt].PduData_pu8;
      sDltPdu_v_PDUEntry_s[*o_Id_pt].PduStatus_e = sDltPdu_e_PDU_IN_USE;
      sDltPdu_v_PDUEntry_s[*o_Id_pt].PduId_t = *o_Id_pt;

    }
    else{
      *o_Id_pt = 1;
      o_Info_ps->SduLength_t = i_Length_t;
      o_Info_ps->SduDataPrt_pu8 = sDltPdu_v_PDUEntry_s[*o_Id_pt].PduData_pu8;
      sDltPdu_v_PDUEntry_s[*o_Id_pt].PduStatus_e = sDltPdu_e_PDU_IN_USE;
      sDltPdu_v_PDUEntry_s[*o_Id_pt].PduId_t = *o_Id_pt;
    }

    v_RetVal_t = E_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
DltStd_ReturnType sDltPdu_F_putPdu_t (sPdu_s_Id_t i_Id_t)
{
  DltStd_ReturnType v_RetVal_t = E_OK;

  sDltPdu_v_PDUEntry_s[i_Id_t].PduStatus_e = sDltPdu_e_PDU_UNUSED;

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
DltStd_ReturnType sDltPdu_F_copyFromPdu_t (sPdu_s_Id_t i_Id_t, sDltPdu_s_Length_t *b_SrcIdx_t, void *i_Dst_pv, sDltPdu_s_Length_t i_Length_t)
{
  DltStd_ReturnType v_RetVal_t  = E_OK;
  uint8_t v_PduData_au8[sPdu_D_PDU_LENGTH_MAX];

  if(b_SrcIdx_t != NULL)
  {
    if((*b_SrcIdx_t + i_Length_t) <= sDltPdu_v_PDUEntry_s[i_Id_t].IsoTpDataLen_u16 )
    {
      /* ugl QA-C Msg. 0491: sDltEnv_MemCpy_v(i_Dst_pv, &(sDltPdu_v_PDUEntry_s[i_Id_t].PduData_pu8[*b_SrcIdx_t]), i_Length_t); */

      /* TODO - ugl Check workaround regarding QA-C Msg. 0491. See commented out code above - */
      sDltEnv_MemCpy_v(v_PduData_au8, sDltPdu_v_PDUEntry_s[i_Id_t].PduData_pu8, (*b_SrcIdx_t + i_Length_t));
      sDltEnv_MemCpy_v(i_Dst_pv, &v_PduData_au8[*b_SrcIdx_t], i_Length_t);

      *b_SrcIdx_t += i_Length_t;
    }
    else
    {
      v_RetVal_t = E_NOT_OK;
    }
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
DltStd_ReturnType sDltPdu_F_copyToPdu_t (sPdu_s_Id_t i_Id_t, sDltPdu_s_Length_t *b_DstIdx_t, const void *i_Src_pv, sDltPdu_s_Length_t i_Length_t)
{
  DltStd_ReturnType v_RetVal_t  = E_OK;
  uint8_t v_PduData_au8[sPdu_D_PDU_LENGTH_MAX] = {0};

  if(b_DstIdx_t != NULL)
  {
    if((*b_DstIdx_t + i_Length_t) < sDltPdu_v_PDUEntry_s[i_Id_t].PduSize_u16 )
    {
      /* ugl QA-C Msg. 0491: sDltEnv_MemCpy_v(&sDltPdu_v_PDUEntry_s[i_Id_t].PduData_pu8[*b_DstIdx_t], i_Src_pv, i_Length_t); */

      /* TODO - ugl Check workaround regarding QA-C Msg. 0491. See commented out code above - */
      sDltEnv_MemCpy_v(v_PduData_au8, sDltPdu_v_PDUEntry_s[i_Id_t].PduData_pu8, (*b_DstIdx_t));
      sDltEnv_MemCpy_v(&v_PduData_au8[*b_DstIdx_t], i_Src_pv, i_Length_t);
      sDltEnv_MemCpy_v(sDltPdu_v_PDUEntry_s[i_Id_t].PduData_pu8, v_PduData_au8, (*b_DstIdx_t + i_Length_t));

      *b_DstIdx_t += i_Length_t;
    }
    else
    {
      v_RetVal_t = E_NOT_OK;
    }
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
DltStd_ReturnType sDltPdu_F_getPduStatus_t (sPdu_s_Id_t i_Id_t, BOOL *o_Locked_b)
{
  DltStd_ReturnType v_RetVal_t = E_OK;

  if(o_Locked_b != NULL)
  {
    *o_Locked_b = (sDltPdu_v_PDUEntry_s[i_Id_t].PduStatus_e == sDltPdu_e_PDU_IN_USE);
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
DltStd_ReturnType sDltPdu_F_PduIdToPtr_t(sPdu_s_Id_t i_PduId, sDltPdu_s_PduInfo_t **o_PduPtr_pps)
{
  DltStd_ReturnType v_RetVal_t = E_OK;

  if((o_PduPtr_pps != NULL) && (i_PduId < sDltPdu_d_NUM_PDUS))
  {
    *o_PduPtr_pps = &sDltPdu_v_PDUEntry_s[i_PduId];
  }
  else
  {
    v_RetVal_t = E_NOT_OK;
    /* Do nothing */
  }

  return v_RetVal_t;
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDltPdu_F_SetIsoTpLength_v(sDltPdu_s_PduInfo_t *i_Pdu_ps, u16 i_IsoTpLen_u16)
{
  if(i_Pdu_ps != NULL)
  {
    i_Pdu_ps->IsoTpDataLen_u16 = i_IsoTpLen_u16;
  }
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltpdu.c */
