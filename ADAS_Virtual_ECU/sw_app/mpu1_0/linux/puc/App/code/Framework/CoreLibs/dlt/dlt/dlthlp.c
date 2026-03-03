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
#include "cfg/dlt_env.h"
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"
#include "dlthlp.h"

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */

/* --- Private Function Declarations ----------------------------------------------- */

/* --- Private Function Definitions ------------------------------------------------ */

/* --- Public Function Definitions ------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
u32 sDltHlp_F_writeByteArrayToUint32_u32 (const u8 i_Src_pu8[], u8 i_Endianess_u8)
{
  u16 v_WordHi_u16 = 0;
  u16 v_WordLo_u16 = 0;

  /*lint -save -e835 A zero has been given as right argument to operator '<<' */
  if(i_Src_pu8 != NULL)
  {
    if (i_Endianess_u8 == sDltCfg_D_BIG_ENDIAN)
    {
      v_WordHi_u16 =  ((u16)i_Src_pu8[0] << 8);
      v_WordHi_u16 |= ((u16)i_Src_pu8[1]);
      v_WordLo_u16 =  ((u16)i_Src_pu8[2] << 8);
      v_WordLo_u16 |= ((u16)i_Src_pu8[3]);
    }
    else
    {
      v_WordLo_u16 =  ((u16)i_Src_pu8[0]);
      v_WordLo_u16 |= ((u16)i_Src_pu8[1] << 8);
      v_WordHi_u16 =  ((u16)i_Src_pu8[2]);
      v_WordHi_u16 |= ((u16)i_Src_pu8[3] << 8);
    }
  }
  /*lint -restore */

  return (((u32)v_WordHi_u16 << 16) | v_WordLo_u16);
}
/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDltHlp_F_writeUint16ToByteArray_v (u8 i_Dst_pu8[], u16 i_Word_u16, u8 i_Endianess_u8)
{
  /*lint -save -e835 A zero has been given as right argument to operator '<<' */
  if(i_Dst_pu8 != NULL)
  {
    if (i_Endianess_u8 == sDltCfg_D_BIG_ENDIAN)
    {
      i_Dst_pu8[0] = (u8)(i_Word_u16 >> 8);
      i_Dst_pu8[1] = (u8)(i_Word_u16);
    }
    else
    {
      i_Dst_pu8[0] = (u8)(i_Word_u16);
      i_Dst_pu8[1] = (u8)(i_Word_u16 >> 8);
    }
  }
  /*lint -restore */
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
void sDltHlp_F_writeUint32ToByteArray_v (u8 i_Dst_pu8[], u32 i_Dword_u32, u8 i_Endianess_u8)
{
  u16 v_WordHi_u16;
  u16 v_WordLo_u16;

  /*lint -save -e835 A zero has been given as right argument to operator '<<' */
  if(i_Dst_pu8 != NULL)
  {
    v_WordHi_u16 = (u16)(i_Dword_u32 >> 16);
    v_WordLo_u16 = (u16)(i_Dword_u32);

    if (i_Endianess_u8 == sDltCfg_D_BIG_ENDIAN)
    {
      i_Dst_pu8[0] = (u8)(v_WordHi_u16 >> 8);
      i_Dst_pu8[1] = (u8)(v_WordHi_u16);
      i_Dst_pu8[2] = (u8)(v_WordLo_u16 >> 8);
      i_Dst_pu8[3] = (u8)(v_WordLo_u16);
    }
    else
    {
      i_Dst_pu8[0] = (u8)(v_WordLo_u16);
      i_Dst_pu8[1] = (u8)(v_WordLo_u16 >> 8);
      i_Dst_pu8[2] = (u8)(v_WordHi_u16);
      i_Dst_pu8[3] = (u8)(v_WordHi_u16 >> 8);
    }
  }
  /*lint -restore */
}

/* -------------------------------------------------------------------------- */
/** @file dlt_prv.h */
u16 sDltHlp_F_writeByteArrayToUint16_u16 (const u8 i_Src_pu8[], u8 i_Endianess_u8)
{
  u16 v_Word_u16 = 0;

  /*lint -save -e835 A zero has been given as right argument to operator '<<' */
  if(i_Src_pu8 != NULL)
  {
    if (i_Endianess_u8 == sDltCfg_D_BIG_ENDIAN)
    {
      v_Word_u16 =  ((u16)i_Src_pu8[0] << 8);
      v_Word_u16 |= ((u16)i_Src_pu8[1]);
    }
    else
    {
      v_Word_u16 =  ((u16)i_Src_pu8[0]);
      v_Word_u16 |= ((u16)i_Src_pu8[1] << 8);
    }
  }
  /*lint -restore */

  return v_Word_u16;
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlthlp.c */
