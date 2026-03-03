/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltInterp
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the DltInterp module
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "dlt_types.h"
#include "dltinterp.h"

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */
#define sDltInterp_d_BIG_ENDIAN           1
#define sDltInterp_d_LITTLE_ENDIAN        0

#define sDltInterp_d_DLT_TYPE_LOG       0x0
#define sDltInterp_d_DLT_TYPE_APP_TRACE 0x1
#define sDltInterp_d_DLT_TYPE_NW_TRACE  0x2
#define sDltInterp_d_DLT_TYPE_CONTROL   0x3

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */

/* --- Private Function Declarations ----------------------------------------------- */
static uint32_t sDltInterp_f_writeByteArrayToUint32_u32 (const uint8_t i_Src_pu8[], uint8_t i_Endianess_u8);
static uint16_t sDltInterp_f_writeByteArrayToUint16_u16 (const uint8_t i_Src_pu8[], uint8_t i_Endianess_u8);
static bool_t sDltInterp_f_GetStandardHeaderLength_b (const uint8_t* i_Msg_pu8, uint32_t* o_StandardHeaderLen_pu32);

// PRQA S 1505 EOF // all functons shall be public, and can be used outside the translation unit (object file?)

/* --- Private Function Definitions ------------------------------------------------ */
static uint32_t sDltInterp_f_writeByteArrayToUint32_u32 (const uint8_t i_Src_pu8[], uint8_t i_Endianess_u8)
{
  uint16_t v_WordHi_u16 = 0;
  uint16_t v_WordLo_u16 = 0;

  if(i_Src_pu8 != NULL)
  {
    if (i_Endianess_u8 == sDltInterp_d_BIG_ENDIAN)
    {
      v_WordHi_u16 =  ((uint16_t)i_Src_pu8[0] << 8);
      v_WordHi_u16 |= ((uint16_t)i_Src_pu8[1]);
      v_WordLo_u16 =  ((uint16_t)i_Src_pu8[2] << 8);
      v_WordLo_u16 |= ((uint16_t)i_Src_pu8[3]);
    }
    else
    {
      v_WordLo_u16 =  ((uint16_t)i_Src_pu8[0]);
      v_WordLo_u16 |= ((uint16_t)i_Src_pu8[1] << 8);
      v_WordHi_u16 =  ((uint16_t)i_Src_pu8[2]);
      v_WordHi_u16 |= ((uint16_t)i_Src_pu8[3] << 8);
    }
  }

  return ((uint32_t)v_WordHi_u16 << 16) | v_WordLo_u16;
}

static uint16_t sDltInterp_f_writeByteArrayToUint16_u16 (const uint8_t i_Src_pu8[], uint8_t i_Endianess_u8)
{
  uint16_t v_Word_u16 = 0;

  if(i_Src_pu8 != NULL)
  {
    if (i_Endianess_u8 == sDltInterp_d_BIG_ENDIAN)
    {
      v_Word_u16 =  ((uint16_t)i_Src_pu8[0] << 8);
      v_Word_u16 |= ((uint16_t)i_Src_pu8[1]);
    }
    else
    {
      v_Word_u16 =  ((uint16_t)i_Src_pu8[0]);
      v_Word_u16 |= ((uint16_t)i_Src_pu8[1] << 8);
    }
  }

  return v_Word_u16;
}

/* --- Public Function Definitions ------------------------------------------------- */
bool_t sDltInterp_F_GetUEH_b(const uint8_t* i_Msg_pu8, uint8_t* o_UEH_pu8)
{
  bool_t v_Return_b = false;
  if ((i_Msg_pu8 != NULL) && (o_UEH_pu8 != NULL))
  {
    *o_UEH_pu8 = *i_Msg_pu8 & 0x01U /* i_Msg_pu8[0] & 0x01 */;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMSBF_b(const uint8_t* i_Msg_pu8, uint8_t* o_MSBF_pu8)
{
  bool_t v_Return_b = false;
  if ((i_Msg_pu8 != NULL) && (o_MSBF_pu8 != NULL))
  {
    *o_MSBF_pu8 = (*i_Msg_pu8 & 0x02U) >> 1 /* (i_Msg_pu8[0] & 0x02) >> 1 */;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetWEID_b(const uint8_t* i_Msg_pu8, uint8_t* o_WEID_pu8)
{
  bool_t v_Return_b = false;
  if ((i_Msg_pu8 != NULL) && (o_WEID_pu8 != NULL))
  {
    *o_WEID_pu8 = (*i_Msg_pu8 & 0x04U) >> 2 /* (i_Msg_pu8[0] & 0x04) >> 2 */;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetWSID_b(const uint8_t* i_Msg_pu8, uint8_t* o_WSID_pu8)
{
  bool_t v_Return_b = false;
  if ((i_Msg_pu8 != NULL) && (o_WSID_pu8 != NULL))
  {
    *o_WSID_pu8 = (*i_Msg_pu8 & 0x08U) >> 3 /* (i_Msg_pu8[0] & 0x08) >> 3 */;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetWTMS_b(const uint8_t* i_Msg_pu8, uint8_t* o_WTMS_pu8)
{
  bool_t v_Return_b = false;
  if ((i_Msg_pu8 != NULL) && (o_WTMS_pu8 != NULL))
  {
    *o_WTMS_pu8 = (*i_Msg_pu8 & 0x10U) >> 4 /* (i_Msg_pu8[0] & 0x10) >> 4 */;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetVERS_b(const uint8_t* i_Msg_pu8, uint8_t* o_VERS_pu8)
{
  bool_t v_Return_b = false;
  if ((i_Msg_pu8 != NULL) && (o_VERS_pu8 != NULL))
  {
    *o_VERS_pu8 = (*i_Msg_pu8 & 0xE0U) >> 5 /* (i_Msg_pu8[0] & 0xE0) >> 5 */;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMCNT_b(const uint8_t* i_Msg_pu8, uint8_t* o_MCNT_pu8)
{
  bool_t v_Return_b = false;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_MCNT_pu8 != NULL))
  {
    *o_MCNT_pu8 = v_Msg_au8[1] /*i_Msg_pu8[1]*/;
    v_Return_b = true;
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetLEN_b(const uint8_t* i_Msg_pu8, uint16_t* o_LEN_pu16)
{
  bool_t v_Return_b = false;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);



  if ((i_Msg_pu8 != NULL) && (o_LEN_pu16 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    if ((u8)TRUE == v_Success_b)
    {
      *o_LEN_pu16 = sDltInterp_f_writeByteArrayToUint16_u16(&v_Msg_au8[2]/*&i_Msg_pu8[2]*/, v_IsBigEndian_u8);
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetECU_b(const uint8_t* i_Msg_pu8, uint32_t* o_ECU_pu32)
{
  bool_t v_Return_b = false;
  uint32_t v_Index_u32 = 4;
  uint8_t  v_IsBigEndian_u8;
  uint8_t  v_EnableWEID_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_ECU_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetWEID_b(i_Msg_pu8, &v_EnableWEID_u8);

    if (((u8)TRUE == v_Success_b) && (v_EnableWEID_u8 == 1))
    {
      *o_ECU_pu32 = sDltInterp_f_writeByteArrayToUint32_u32(&v_Msg_au8[v_Index_u32]/* &i_Msg_pu8[v_Index_u32]*/, v_IsBigEndian_u8);
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetSEID_b (const uint8_t* i_Msg_pu8, uint32_t* o_SEID_pu32)
{

  bool_t v_Return_b = false;
  uint32_t v_Index_u32 = 4;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_EnableWEID_u8;
  uint8_t v_EnableWSID_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_SEID_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetWEID_b(i_Msg_pu8, &v_EnableWEID_u8);
    v_Success_b |= sDltInterp_F_GetWSID_b(i_Msg_pu8, &v_EnableWSID_u8);
    if ((u8)TRUE == v_Success_b)
    {
      if (v_EnableWEID_u8 == 1)
      {
        v_Index_u32 += 4; // PRQA S 2984 // want to increase index in a logical order
      }

      if (v_EnableWSID_u8 == 1)
      {
        *o_SEID_pu32 = sDltInterp_f_writeByteArrayToUint32_u32(&v_Msg_au8[v_Index_u32]/* &i_Msg_pu8[v_Index_u32] */, v_IsBigEndian_u8);
        v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetTMSP_b (const uint8_t* i_Msg_pu8, uint32_t* o_TMSP_pu32)
{
  bool_t v_Return_b = false;
  uint32_t v_Index_u32 = 4;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_EnableWEID_u8;
  uint8_t v_EnableWSID_u8;
  uint8_t v_EnableWTMS_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_TMSP_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetWEID_b(i_Msg_pu8, &v_EnableWEID_u8);
    v_Success_b |= sDltInterp_F_GetWSID_b(i_Msg_pu8, &v_EnableWSID_u8);
    v_Success_b |= sDltInterp_F_GetWTMS_b(i_Msg_pu8, &v_EnableWTMS_u8);
    if ((u8)TRUE == v_Success_b)
    {
      if (v_EnableWEID_u8 == 1)
      {
        v_Index_u32 += 4; // PRQA S 2984 // want to increase index in a logical order
      }

      if (v_EnableWSID_u8 == 1)
      {
        v_Index_u32 += 4; // PRQA S 2984 // want to increase index in a logical order
      }

      if (v_EnableWTMS_u8 == 1)
      {
        *o_TMSP_pu32 = sDltInterp_f_writeByteArrayToUint32_u32(&v_Msg_au8[v_Index_u32]/* &i_Msg_pu8[v_Index_u32]*/, v_IsBigEndian_u8);
        v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

/* Extended Header */
static bool_t sDltInterp_f_GetStandardHeaderLength_b (const uint8_t* i_Msg_pu8, uint32_t* o_StandardHeaderLen_pu32)
{
  bool_t v_Return_b = false;
  uint8_t v_EnableWEID_u8;
  uint8_t v_EnableWSID_u8;
  uint8_t v_EnableWTMS_u8;

  if ((i_Msg_pu8 != NULL) && (o_StandardHeaderLen_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetWEID_b(i_Msg_pu8, &v_EnableWEID_u8);
    v_Success_b |= sDltInterp_F_GetWSID_b(i_Msg_pu8, &v_EnableWSID_u8);
    v_Success_b |= sDltInterp_F_GetWTMS_b(i_Msg_pu8, &v_EnableWTMS_u8);
    if ((u8)TRUE == v_Success_b)
    {
      *o_StandardHeaderLen_pu32 = 4; // PRQA S 2984 // want to increase index in a logical order

      if (v_EnableWEID_u8 == 1)
      {
        *o_StandardHeaderLen_pu32 += 4; // PRQA S 2984 // want to increase index in a logical order
      }

      if (v_EnableWSID_u8 == 1)
      {
        *o_StandardHeaderLen_pu32 += 4; // PRQA S 2984 // want to increase index in a logical order
      }

      if (v_EnableWTMS_u8 == 1)
      {
        *o_StandardHeaderLen_pu32 += 4; // PRQA S 2984 // want to increase index in a logical order
      }
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetVERB_b (const uint8_t* i_Msg_pu8, uint8_t* o_VERB_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_VERB_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      *o_VERB_pu8 = v_Msg_au8[v_StandardHeaderLength_u32]/*i_Msg_pu8[v_StandardHeaderLength_u32]*/ & 0x01;
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMSTP_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSTP_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_MSTP_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      *o_MSTP_pu8 = (v_Msg_au8[v_StandardHeaderLength_u32]/*i_Msg_pu8[v_StandardHeaderLength_u32]*/ & 0x0E) >> 1;
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMSLI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSLI_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_MessageType_u8 = 0U;

  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_MSLI_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    v_Success_b |= sDltInterp_F_GetMSTP_b (i_Msg_pu8, &v_MessageType_u8);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      if (v_MessageType_u8 == sDltInterp_d_DLT_TYPE_LOG)
      {
        *o_MSLI_pu8 = (v_Msg_au8[v_StandardHeaderLength_u32] & 0xF0U) >> 4 /*(i_Msg_pu8[v_StandardHeaderLength_u32] & 0xF0) >> 4 */;
        v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMSTI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSTI_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_MessageType_u8 = 0U;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_MSTI_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    v_Success_b |= sDltInterp_F_GetMSTP_b (i_Msg_pu8, &v_MessageType_u8);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      if (v_MessageType_u8 == sDltInterp_d_DLT_TYPE_APP_TRACE)
      {
        *o_MSTI_pu8 =  (v_Msg_au8[v_StandardHeaderLength_u32] & 0xF0U) >> 4 /*(i_Msg_pu8[v_StandardHeaderLength_u32] & 0xF0) >> 4 */;
        v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMSBI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSBI_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_MessageType_u8 = 0U;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_MSBI_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    v_Success_b |= sDltInterp_F_GetMSTP_b (i_Msg_pu8, &v_MessageType_u8);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      if (v_MessageType_u8 == sDltInterp_d_DLT_TYPE_NW_TRACE)
      {
        *o_MSBI_pu8 = (v_Msg_au8[v_StandardHeaderLength_u32] & 0xF0U) >> 4 /* (i_Msg_pu8[v_StandardHeaderLength_u32] & 0xF0) >> 4 */;
        v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetMSCI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSCI_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_MessageType_u8 = 0U;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_MSCI_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    v_Success_b |= sDltInterp_F_GetMSTP_b (i_Msg_pu8, &v_MessageType_u8);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      if (v_MessageType_u8 == sDltInterp_d_DLT_TYPE_CONTROL)
      {
        *o_MSCI_pu8 = (v_Msg_au8[v_StandardHeaderLength_u32] & 0xF0U) >> 4 /* (i_Msg_pu8[v_StandardHeaderLength_u32] & 0xF0) >> 4 */;
        v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetNOAR_b(const uint8_t* i_Msg_pu8, uint8_t* o_NOAR_pu8)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_NOAR_pu8 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      *o_NOAR_pu8 = v_Msg_au8[v_StandardHeaderLength_u32 + 1]/*i_Msg_pu8[v_StandardHeaderLength_u32 + 1]*/;
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetAPID_b(const uint8_t* i_Msg_pu8, uint32_t* o_APID_pu32)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_APID_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      *o_APID_pu32 = sDltInterp_f_writeByteArrayToUint32_u32 (&v_Msg_au8[v_StandardHeaderLength_u32 + 2]/*&i_Msg_pu8[v_StandardHeaderLength_u32 + 2]*/, v_IsBigEndian_u8);
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

bool_t sDltInterp_F_GetCTID_b(const uint8_t* i_Msg_pu8, uint32_t* o_CTID_pu32)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_CTID_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    if (((u8)TRUE == v_Success_b) && (v_EnableUEH_u8 == 1))
    {
      *o_CTID_pu32 = sDltInterp_f_writeByteArrayToUint32_u32 (&v_Msg_au8[v_StandardHeaderLength_u32 + 6] /*&i_Msg_pu8[v_StandardHeaderLength_u32 + 6]*/, v_IsBigEndian_u8);
      v_Return_b = true;
    }
  }
  return v_Return_b;
}


bool_t sDltCtrlInterp_F_GetAPID_b(const uint8_t* i_Msg_pu8, uint32_t* o_APID_pu32)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);


  if ((i_Msg_pu8 != NULL) && (o_APID_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);
    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);

    if ((u8)TRUE == v_Success_b)
    {
      uint32_t v_ServiceId_u32;
      uint32_t v_HeaderLength_u32 = v_StandardHeaderLength_u32;
      if (v_EnableUEH_u8 == 1)
      {
        v_HeaderLength_u32 += 10;
      }

      v_ServiceId_u32 = sDltInterp_f_writeByteArrayToUint32_u32 (&v_Msg_au8[v_HeaderLength_u32]/*&i_Msg_pu8[v_HeaderLength_u32]*/, v_IsBigEndian_u8);

      if ((v_ServiceId_u32 == sDltCfg_D_SID_SET_LOG_LEVEL) ||
          (v_ServiceId_u32 == sDltCfg_D_SID_SET_TRACE_STATUS) ||
          (v_ServiceId_u32 == sDltCfg_D_SID_GET_LOG_INFO) ||
          (v_ServiceId_u32 == sDltCfg_D_SID_SWITCH_DUMP_MODE))
      {
        *o_APID_pu32 = sDltInterp_f_writeByteArrayToUint32_u32 (&v_Msg_au8[v_HeaderLength_u32 + 4] /*&i_Msg_pu8[v_HeaderLength_u32 + 4]*/,
                                                                v_IsBigEndian_u8);
         v_Return_b = true;
      }
    }
  }
  return v_Return_b;
}

bool_t sDltCtrlInterp_F_GetServiceID_b(const uint8_t* i_Msg_pu8, uint32_t* o_SID_pu32)
{
  bool_t v_Return_b = false;
  uint32_t v_StandardHeaderLength_u32;
  uint8_t v_EnableUEH_u8;
  uint8_t v_IsBigEndian_u8;
  uint8_t v_Msg_au8[sDltCfg_d_HDR_LEN_MAX];

  sDltEnv_MemCpy_v(v_Msg_au8, i_Msg_pu8, sDltCfg_d_HDR_LEN_MAX);

  if ((i_Msg_pu8 != NULL) && (o_SID_pu32 != NULL))
  {
    bool_t v_Success_b = sDltInterp_F_GetMSBF_b(i_Msg_pu8, &v_IsBigEndian_u8);
    v_Success_b |= sDltInterp_F_GetUEH_b(i_Msg_pu8, &v_EnableUEH_u8);

    v_Success_b |= sDltInterp_f_GetStandardHeaderLength_b(i_Msg_pu8, &v_StandardHeaderLength_u32);
    if ((u8)TRUE == v_Success_b)
    {
      uint32_t v_HeaderLength_u32 = v_StandardHeaderLength_u32;
      if (v_EnableUEH_u8 == 1)
      {
        v_HeaderLength_u32 += 10;
      }

      *o_SID_pu32 = sDltInterp_f_writeByteArrayToUint32_u32 (&v_Msg_au8[v_HeaderLength_u32]/*&i_Msg_pu8[v_HeaderLength_u32]*/, v_IsBigEndian_u8);
      v_Return_b = true;
    }
  }
  return v_Return_b;
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltinterp.c */
