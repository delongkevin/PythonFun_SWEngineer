/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   Dlt
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Private header file for implementation of the Dlt - Diagnostic log and trace
 * ======================================================================== */

#ifndef DLTPDU_H_
#define DLTPDU_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */
/* PRQA S 2300 EOF */ /* global scope, this is a header file */

#include "cfg/dlt_env.h"
#include "cfg/dlt_cfg.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// PRQA S 1021 2 // literal used here as shared c and cpp file
#define sDltPdu_d_SDU_LENGTH  sPdu_D_PDU_LENGTH_MAX
#define sDltPdu_d_NUM_PDUS sPdu_D_PDU_NUMBER_OF_PDU


/* --- Public Function Declarations ------------------------------------------------ */

extern void sDltPdu_F_Init_v(void);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    allocates a PDU matching the requested length
 *
 * \param[in] i_Length_t - length of the requested PDU
 * \param[out] *o_Id_pt - id of the allocated PDU
 * \param[out] *o_Info_ps - some information about the allocated PDU
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - no appropriate PDU available
 */
extern DltStd_ReturnType sDltPdu_F_getPdu_t (sPdu_s_Id_t *o_Id_pt,
                                              sDltPdu_s_Info_t *o_Info_ps,
                                              sDltPdu_s_Length_t i_Length_t);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    deallocates the indicated PDU
 *
 * \param[in] i_Id_t - id of PDU to deallocate
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - invalid PDU id
 */
extern DltStd_ReturnType sDltPdu_F_putPdu_t (sPdu_s_Id_t i_Id_t);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    copies some data from PDU to a buffer as specified
 *
 * \param[in] i_Id_t - id of PDU to to read from
 * \param[inout] b_SrcIdx_t - index to buffer, in: start position, out: end position
 * \param[in] *i_Dst_pu8 - pointer to destination buffer
 * \param[in] i_Length_t - number of bytes to read from PDU
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - invalid PDU id or PDU not locked or invalid length
 */
extern DltStd_ReturnType sDltPdu_F_copyFromPdu_t (sPdu_s_Id_t i_Id_t,
                                                   sDltPdu_s_Length_t *b_SrcIdx_t,
                                                   void *i_Dst_pv,
                                                   sDltPdu_s_Length_t i_Length_t);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    copies some data from a buffer to PDU as specified
 *
 * \param[in] i_Id_t - id of PDU to to write to
 * \param[inout] b_DstIdx_t - index to buffer, in: start position, out: end position
 * \param[in] *i_Src_pu8 - pointer to source buffer
 * \param[in] i_Length_t - number of bytes to write to PDU
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - invalid PDU id or PDU not locked or invalid length
 */
extern DltStd_ReturnType sDltPdu_F_copyToPdu_t (sPdu_s_Id_t i_Id_t,
                                                 sDltPdu_s_Length_t *b_DstIdx_t,
                                                 const void *i_Src_pv,
                                                 sDltPdu_s_Length_t i_Length_t);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    returns some status information of specified PDU
 *
 * \param[in] i_Id_t - id of PDU to to write to
 * \param[out] *o_Locked_b - FALSE: PDU is not locked, !FALSE: PDU is locked
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - invalid PDU id
 */
extern DltStd_ReturnType sDltPdu_F_getPduStatus_t (sPdu_s_Id_t i_Id_t, BOOL *o_Locked_b);
/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    returns the PDU Info to an PDU ID
 *
 * \param[in] i_PduId - ID of the PDU
 * \param[out] o_PduPtr_pps - pointer to the pointer to the corresponding PDU Info
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - invalid PDU id
 */

extern DltStd_ReturnType sDltPdu_F_PduIdToPtr_t(sPdu_s_Id_t i_PduId, sDltPdu_s_PduInfo_t **o_PduPtr_pps);
/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    sets the currunt data length
 *
 * \param[in] i_Pdu_ps - pointer to the PDU Info
 * \param[in] i_IsoTpLen_u16 - length of the data length
 *
 * \return u8 - number of bytes written to header buffer
 */
extern void sDltPdu_F_SetIsoTpLength_v(sDltPdu_s_PduInfo_t *i_Pdu_ps, u16 i_IsoTpLen_u16);

#if defined(__cplusplus)
}; // extern C
#endif

/* --------------------------------------------------------------------------------- */
#endif /* DLTPDU_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltpdu.h */
