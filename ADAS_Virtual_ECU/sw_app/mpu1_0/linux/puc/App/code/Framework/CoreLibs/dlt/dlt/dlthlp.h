/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltHlp
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    <tbd>
 * ======================================================================== */

#ifndef DLTHLP_H_
#define DLTHLP_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */

#include"cfg/dlt_env.h"

/* --- Public Function Declarations ------------------------------------------------ */
/**
 * \par Description:
 *    writes a byte array source to a u32 destination
 *
 * \param[in] i_Src_pu8[] - byte array source
 * \param[in] i_Endianess_u8 - type of endian
 *
 * \return u32 - assembled value
 */
extern u32 sDltHlp_F_writeByteArrayToUint32_u32 (const u8 i_Src_pu8[], u8 i_Endianess_u8);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    writes a u32 source to a byte array destination
 *
 * \param[in] i_Dst_pu8[] - byte array destination
 * \param[in] i_Dword_u32 - u32 source
 * \param[in] i_Endianess_u8 - type of endian
 */
extern void sDltHlp_F_writeUint32ToByteArray_v (u8 i_Dst_pu8[], u32 i_Dword_u32, u8 i_Endianess_u8);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    writes a u16 source to a byte array destination
 *
 * \param[in] i_Dst_pu8[] - byte array destination
 * \param[in] i_Word_u16 - u16 source
 * \param[in] i_Endianess_u8 - type of endian
 */
extern void sDltHlp_F_writeUint16ToByteArray_v (u8 i_Dst_pu8[], u16 i_Word_u16, u8 i_Endianess_u8);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    writes a byte array source to a u16 destination
 *
 * \param[in] i_Src_pu8[] - byte array source
 * \param[in] i_Endianess_u8 - type of endian
 *
 * \return u16 - assembled value
 */
extern u16 sDltHlp_F_writeByteArrayToUint16_u16 (const u8 i_Src_pu8[], u8 i_Endianess_u8);

/* --------------------------------------------------------------------------------- */
#endif /* DLTHLP_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlthlp.h */
