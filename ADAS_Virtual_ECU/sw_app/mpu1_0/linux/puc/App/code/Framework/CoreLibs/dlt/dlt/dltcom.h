/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltCom
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Header file for implementation of the DltCom - Diagnostic log and trace communication module
 *    This file declares the functions used by dlt
 * ======================================================================== */

#ifndef DLTCOM_H_
#define DLTCOM_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 2400 EOF */ /* functions in global namespace */

/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */
/* PRQA S 3448 EOF */  /* Suppressed QAC warning, functions are declared in a header file */

#include "cfg/dlt_env.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/* --- Public Function Declarations ------------------------------------------------ */
/*** 8.6.2  Expected Interfaces from Dlt communication module *****************/

/* -------------------------------------------------------------------------- */
/**
 *
 * \par Description:
 *    this function initializes the module
 *
 */
extern void sDltCom_F_Init_v (void);


/* -------------------------------------------------------------------------- */
/**
 * 8.6.2.4  DltCom_Transmit   [SWS_Dlt_00263]
 *
 * \par Description:
 *    The Dlt communication module requests a transmission for the Dlt core module.
 *
 * \param[in] i_Id_t - ID of Dlt I-PDU to be transmitted. Range: 0..(maximum number of I-PDU IDs
 *                      which may be transmitted by Dcm) - 1
 * \param[in] i_Info_ps - Pointer to a structure with I-PDU related data that shall be transmitted:
 *                         data length and pointer to I-SDU buffer
 *
 * \return Std_ReturnType - E_OK - Transmit request has been accepted
 *                          E_NOT_OK - Transmit request has not been accepted
 */
extern DltStd_ReturnType sDltCom_F_transmit_t (sPdu_s_Id_t i_Id_t, const sDltPdu_s_Info_t* i_Info_ps);


/* -------------------------------------------------------------------------- */
/**
 *
 * \par Description:
 *    this function cyclically checks the rx queue for new messages.
 *    new messages are passed to DLT receive function.
 *
 */
extern void sDltCom_F_cyclic_v (void);

/* -------------------------------------------------------------------------- */
/**
 *
 * \par Description:
 *    this function handles the start of transmission request and provides
 *    a PDU to store the message to be sent
 *
 * \param[in] i_Length_t - length of the requested PDU
 * \param[out] *o_Id_pt - id of the allocated PDU
 * \param[out] *o_Info_ps - some information about the allocated PDU
 *
 * \return Std_ReturnType - E_OK - call succeeded
 *                          E_NOT_OK - no appropriate PDU available
 */
extern DltStd_ReturnType sDltCom_F_startOfTransmission_t (sPdu_s_Id_t * o_Id_pt,
                                                          sDltPdu_s_Info_t * o_Info_ps,
                                                          sDltPdu_s_Length_t i_Length_t);

typedef BOOL (*sDltCom_F_SendBuffer_t)(u8 i_Channel_u8, const sDltPdu_s_PduInfo_t *i_TxBuffer_ps);

/**
 *
 * \par Description:
 *    this function is used by the other module to register a function
 *    for sending a message to the transport protocol.
 *
 * \param[in] cb - pointer to callback function
 */
extern void sDltCom_F_RegisterSendBufferFunc_v(sDltCom_F_SendBuffer_t i_CallBack_pf);

/**
 * 8.6.2.3  DltCom_StartOfReception [SWS_Dlt_00517]
 *
 * \par Description:
 *    This function is called at the start of receiving an N-SDU. The N-SDU might be fragmented
 *    into multiple N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF).
 *
 * \param[in] i_Length_t - length of the incoming message
 *
 * \param[out] o_Buffer_pps - pointer to PDU description
 *
 * \return nothing: the function is called from isotp_cfg, and not expected to return an error apart from NULL
 */
extern void sDltCom_F_startOfReception_t (u16 i_Length_t, sDltPdu_s_PduInfo_t **o_Buffer_pps);


/* -------------------------------------------------------------------------- */
/**
 *
 * \par Description:
 *    this function handles the rx indication.
 *
 * \param[in] i_Pdu_ps - pointer to PDU structure
 */
extern bool_t sDltCom_F_RxIndication_b(sDltPdu_s_PduInfo_t *i_Pdu_ps, u16 i_Length_u16);

/**
 *
 * \par Description:
 *    this function handles the tx confirmation. it releases the used PDU.
 *
 * \param[in] i_Pdu_ps - pointer to PDU structure
 */
extern void sDltCom_F_txConfirmation_v(const sDltPdu_s_PduInfo_t *i_Pdu_ps, u16 i_Length_u16);

#if defined(__cplusplus)
}; // extern C
#endif

/* --------------------------------------------------------------------------------- */
#endif /* DLTCOM_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltcom.h */
