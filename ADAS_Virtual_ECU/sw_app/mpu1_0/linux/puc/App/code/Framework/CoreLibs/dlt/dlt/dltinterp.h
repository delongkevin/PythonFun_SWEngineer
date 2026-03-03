/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltInterp
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Header file for the DltInterp module
 * ======================================================================== */

#ifndef DLTINTERP_H_
#define DLTINTERP_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */

#include <platform/PlatformSpecs.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* --- Public Function Declarations ------------------------------------------------ */

/* -------------------------------------------------------------------------- */
/* --------------------------- Standard Header ------------------------------ */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Check if the Extended Header is transmitted.
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. If it's 1, the
 *                            Extended Header is transmitted. If it's 0, the
 *                            Extended Header is not transmitted.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetUEH_b (const uint8_t* i_Msg_pu8, uint8_t* o_UEH_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If set, the payload data is in big endian format, else in little endian format.
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. If it's 1, is in big
 *                            endian format. If it's 0, is in little endian format.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMSBF_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSBF_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If set, the ECU ID (ECU) is attached in the Standard Header.
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. If it's 1, the ECU ID
 *                            is attached. If it's 0, the ECU ID is not attached.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetWEID_b (const uint8_t* i_Msg_pu8, uint8_t* o_WEID_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If set, the Session ID (SEID) is attached in the Standard Header.
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. If it's 1, Session
 *                            ID is attached. If it's 0, the Session ID is not
 *                            attached.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetWSID_b (const uint8_t* i_Msg_pu8, uint8_t* o_WSID_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
      If set, the timestamp (TMSP) is attached in the Standard Header.
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. If it's 1, timestamp
 *                            is attached. If it's 0, not attached.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetWTMS_b (const uint8_t* i_Msg_pu8, uint8_t* o_WTMS_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Get version number of Dlt Data protocol
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent version.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetVERS_b (const uint8_t* i_Msg_pu8, uint8_t* o_VERS_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Continuous number of message, for detection of lost messages. Counter is
 *    increased for every received message by the Dlt API message in local buffer.
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent message
 *                            count.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMCNT_b (const uint8_t* i_Msg_pu8, uint8_t* o_MCNT_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Get length of the complete message in bytes
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 16 bit unsigned int. It represent length
 *                            of complete message in bytes.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetLEN_b (const uint8_t* i_Msg_pu8, uint16_t* o_LEN_pu16);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Get unique address of sender (Diag-Addr/ECU Name/...), interpreted as 4 ASCII
 *    characters
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 32 bit unsigned int. It represent 4 ASCII
 *                            characters for unique address of sender.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetECU_b (const uint8_t* i_Msg_pu8, uint32_t* o_ECU_pu32);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Get session number
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 32 bit unsigned int. It represent Session
 *                            number.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetSEID_b (const uint8_t* i_Msg_pu8, uint32_t* o_SEID_pu32);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Get continuous time / ticks from the ECU at the moment the message is sent
 *    to Dlt.
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 32 bit unsigned int. It represent
 *                            continuous time / ticks.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetTMSP_b (const uint8_t* i_Msg_pu8, uint32_t* o_TMSP_pu32);



/* -------------------------------------------------------------------------- */
/* --------------------------- Extended Header ------------------------------ */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If set, a description of the transmitted data is provided within the payload.
 *    If not set, this information will be given within a file.
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. If it's 1, the flag
 *                            was set. If it's 0, the flag was not set.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetVERB_b (const uint8_t* i_Msg_pu8, uint8_t* o_VERB_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Enum of following types:
 *      DLT_TYPE_LOG        0x0
 *      DLT_TYPE_APP_TRACE  0x1
 *      DLT_TYPE_NW_TRACE   0x2
 *      DLT_TYPE_CONTROL    0x3
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent the value
 *                            of Enum list in description.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMSTP_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSTP_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If MSTP is DLT_TYPE_LOG, Enum of following info:
 *      DLT_LOG_FATAL    0x1
 *      DLT_LOG_ERROR    0x2
 *      DLT_LOG_WARN     0x3
 *      DLT_LOG_INFO     0x4
 *      DLT_LOG_DEBUG    0x5
 *      DLT_LOG_VERBOSE  0x6
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent the value
 *                            of Enum list in description.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMSLI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSLI_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If MSTP is DLT_TYPE_APP_TRACE, Enum of following info:
 *      DLT_TRACE_VARIABLE     0x1
 *      DLT_TRACE_FUNCTION_IN  0x2
 *      DLT_TRACE_FUNCTION_OUT 0x3
 *      DLT_TRACE_STATE        0x4
 *      DLT_TRACE_VFB          0x5
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent the value
 *                            of Enum list in description.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMSTI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSTI_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If MSTP is DLT_TYPE_NW_TRACE, Enum of following info:
 *      DLT_NW_TRACE_IPC     0x1
 *      DLT_NW_TRACE_CAN     0x2
 *      DLT_NW_TRACE_FLEXRAY 0x3
 *      DLT_NW_TRACE_MOST    0x4
 *      Reserved             0x5-0x7
 *      UserDefined          0x8-0x15
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent the value
 *                            of Enum list in description.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMSBI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSBI_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    If MSTP is DLT_TYPE_CONTROL, Enum of following info:
 *      DLT_CONTROL_REQUEST   0x1
 *      DLT_CONTROL_RESPONSE  0x2
 *      DLT_CONTROL_TIME      0x3
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent the value
 *                            of Enum list in description.
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetMSCI_b (const uint8_t* i_Msg_pu8, uint8_t* o_MSCI_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Number of arguments in the message payload
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 8 bit unsigned int. It represent the number of
 *                            arguments (NOAR)
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetNOAR_b(const uint8_t* i_Msg_pu8, uint8_t* o_NOAR_pu8);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Number/ID of application - interpreted as 4 ASCII characters
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 32 bit unsigned int. It represent Application
 *                            ID (APID)
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetAPID_b(const uint8_t* i_Msg_pu8, uint32_t* o_APID_pu32);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Unique ID of logging/tracing context - interpreted as 4 ASCII characters
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_UEH_pu8 - Pointer to a 32 bit unsigned int. It represent Context
 *                            ID (CTID)
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltInterp_F_GetCTID_b(const uint8_t* i_Msg_pu8, uint32_t* o_CTID_pu32);

/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Number/ID of application in predefined control message
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_APID_pu32 - Pointer to a 32 bit unsigned int. It represent application ID
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltCtrlInterp_F_GetAPID_b(const uint8_t* i_Msg_pu8, uint32_t* o_APID_pu32);


/* -------------------------------------------------------------------------- */
/**
 * \Description:
 *    Service to execute
 *
 * \param[in]   - i_Msg_pu8 - The DLT Message.
 * \param[out]  - o_SID_pu32 - Pointer to a 32 bit unsigned int. It represents service ID
 * \return bool - true      - Get the information successfully.
 *                flase     - The information does not exist in the DLT Message.
 */
bool_t sDltCtrlInterp_F_GetServiceID_b(const uint8_t* i_Msg_pu8, uint32_t* o_SID_pu32);


#ifdef __cplusplus
}
#endif

/* --------------------------------------------------------------------------------- */
#endif /* DLTINTERP_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltinterp.h */

