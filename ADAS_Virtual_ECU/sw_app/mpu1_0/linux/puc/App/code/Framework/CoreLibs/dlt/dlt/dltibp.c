/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltIbp
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Implementation of the DltIbp module
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "dlt_types.h"
#include "dlthlp.h"
#include "dltibp.h"

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */
#define sIbpCfg_d_HDR_IDX_SERIALNO     0U
#define sIbpCfg_d_HDR_IDX_HTYP         2U
#define sIbpCfg_d_HDR_IDX_FORMAT       3U
#define sIbpCfg_d_HDR_IDX_WIDTH        4U
#define sIbpCfg_d_HDR_IDX_HEIGHT       6U

/* --- Private Macros -------------------------------------------------------------- */

/* --- Extern Declarations --------------------------------------------------------- */

/* --- Private Function Declarations ----------------------------------------------- */

/* --- Private Function Definitions ------------------------------------------------ */

/* --- Public Function Definitions ------------------------------------------------- */
/**
 *
@startuml DLT send binary data width=5cm
digraph binData {
  rankdir=LR bgcolor="#FFF0F0:#FFF8F8" fontcolor="white" compound=true
  node [fontname="Arial" shape=record]

  binData [bgcolor="#FF0000" label="binary data"]

  subgraph cluster1 {
    start [label="start frame | ser:N"]
    cont0  [label="cont. frame | 0"]
    cont1  [label="cont. frame | N-2"]
    end  [label="end frame | N-1"]
  }

  binData -> start [ltail=cluster0, lhead=cluster1]


  start -> cont0
  cont1 -> end

  edge[style=dotted]
  cont0 -> cont1
}
@enduml
 */
uint8_t sDltEncap_F_writeHeaderData_u8(uint8_t o_Buf_au8[], uint16_t i_BufLen_u16,
                                       DltEncap_CompressionType_t i_CompressionType_t, DltEncap_FrameType_t i_FrameType_t,
                                       DltEncap_Content_t i_Content_t, uint16_t i_SerialNo_u16)
{
  uint8_t v_Len_u8 = 0;

  if ((o_Buf_au8 != NULL) && (i_BufLen_u16 >= sDltEncap_d_HEADER_LEN))
  {
    sDltHlp_F_writeUint16ToByteArray_v(&o_Buf_au8[sIbpCfg_d_HDR_IDX_SERIALNO],
                                       i_SerialNo_u16,
                                       sDltCfg_D_BIG_ENDIAN);

    o_Buf_au8[sIbpCfg_d_HDR_IDX_HTYP] = ((uint8_t)i_CompressionType_t) | ((uint8_t)i_FrameType_t) | ((uint8_t)i_Content_t);

    v_Len_u8 = sDltEncap_d_HEADER_LEN;
  }

  return v_Len_u8;
}

uint8_t sDltEncap_F_writeHeaderImageData_u8(uint8_t o_Buf_au8[], uint16_t i_BufLen_u16,
                                            DltEncap_ImageType_t i_ImageType_t, uint16_t i_ImageWidth_u16, uint16_t i_ImageHeight_u16)
{
  uint8_t v_Len_u8 = 0;
  if ((o_Buf_au8 != NULL) && (i_BufLen_u16 >= sDltEncap_d_START_FRAME_LEN))
  {
    o_Buf_au8[sIbpCfg_d_HDR_IDX_FORMAT] = ((uint8_t)i_ImageType_t);
    sDltHlp_F_writeUint16ToByteArray_v(&o_Buf_au8[sIbpCfg_d_HDR_IDX_WIDTH],
                                       i_ImageWidth_u16,
                                       sDltCfg_D_BIG_ENDIAN);

    sDltHlp_F_writeUint16ToByteArray_v(&o_Buf_au8[sIbpCfg_d_HDR_IDX_HEIGHT],
                                       i_ImageHeight_u16,
                                       sDltCfg_D_BIG_ENDIAN);

    v_Len_u8 = sDltEncap_d_START_FRAME_LEN;
  }

  return v_Len_u8;
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltibp.c */
