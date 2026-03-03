/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltHdr
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Private header file for implementation of the Dlt - Diagnostic log and trace
 * ======================================================================== */

#ifndef DLTHDR_H_
#define DLTHDR_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */

#include "cfg/dlt_env.h"
#include "cfg/dlt_cfg.h"
#include "dlt_types.h"
#include "dlt.h"


struct sDlt_s_ControlData_s;
extern const u8 sDltCfg_C_EcuId_u8[sDltCfg_d_HDR_LEN_ECUID];

/* --- Public Function Declarations ------------------------------------------------ */

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    assemble the standard header
 *
 * \param[in] i_Header_t - byte array destination
 * \param[in] i_SessionId_u32 - session id to be written
 * \param[in] i_TimeStamp_u32 - time stamp to be written
 *
 * \return u8 - number of bytes written to header buffer
 */
extern u8 sDltHdr_F_assembleStandardHeader_u8 (sDlt_s_Header_t i_Header_t, u32 i_SessionId_u32, u32 i_TimeStamp_u32);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    assemble the extended header
 *
 * \param[in] i_Header_t - byte array destination
 * \param[in] i_Mstp_t - message type to be written
 * \param[in] i_Mtin_u8 - message type info to be written
 * \param[in] i_Mopt_t - message options -> verbose mode set?
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
 * \param[in] i_Margc_t - message arguments count to be written
#else
 * \param[in] i_Margc_u8 - message arguments count to be written
#endif
#endif
 * \param[in] i_AppId_t - application id to be written
 * \param[in] i_ContextId_t - context id to be written
 *
 * \return u8 - number of bytes written to header buffer
 */
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
extern u8 sDltHdr_F_assembleExtendedHeader_u8 (sDlt_s_Header_t i_Header_t,
                                               sDlt_s_MessageType_t i_Mstp_t,
                                               u8 i_Mtin_u8,
                                               sDlt_s_MessageOptions_t i_Mopt_t,
                                               sDlt_s_MessageArgumentCount_t i_Margc_t,
                                               sDlt_s_ApplicationId_t i_AppId_t,
                                               sDlt_s_ContextId_t i_ContextId_t);
#else
extern u8 sDltHdr_F_assembleExtendedHeader_u8 (sDlt_s_Header_t i_Header_t,
                                               sDlt_s_MessageType_t i_Mstp_t,
                                               u8 i_Mtin_u8,
                                               sDlt_s_MessageOptions_t i_Mopt_t,
                                               u8 i_Margc_u8,
                                               sDlt_s_ApplicationId_t i_AppId_t,
                                               sDlt_s_ContextId_t i_ContextId_t);
#endif
#endif

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    evaluate and get information from received header
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 *
 * \return BOOL - valid header received
 */
/** @file dlt_prv.h */

extern BOOL sDltHdr_F_evaluateRequestHeader_b (struct sDlt_s_ControlData_s * b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    assemble the response header
 *
 * \param[in] *i_Ctrl_ps - pointer to control data
 * \param[in] i_Header_t - byte array destination
 *
 * \return u8 - number of bytes written to header buffer
 */
extern u8 sDltHdr_F_assembleResponseHeader_u8 (const struct sDlt_s_ControlData_s * i_Ctrl_ps, sDlt_s_Header_t i_Header_t);

/* --------------------------------------------------------------------------------- */
#endif /* DLTHDR_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlthdr.h */
