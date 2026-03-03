/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltCfg
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Header file for configuration and interface functions for Dlt
 * ======================================================================== */

#ifndef DLTAPP_H_
#define DLTAPP_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 2400 EOF */ /* functions in global namespace */

/* QA-C */
/* PRQA S 3210 EOF */ /* Suppressed QAC warning, identifiers provided for other DLT modules */
/* PRQA S 3447 EOF */ /* Suppressed QAC warning, arrays or functions are declared in a header file */
/* PRQA S 3448 EOF */ /* Suppressed QAC warning, type definition is declared in a header file */
/* PRQA S 2300 EOF */ /* global scope, this is a header file */

#include "dlt_types.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#define sDltApp_d_MAX_COUNT_SESSIONIDS   1 /* PRQA S 1025 */ /* Macro may be used as a literal */

/* the context information of a log message
 * this structure holds all data needed to assemble a log message.
 */
typedef struct sDltApp_s_LogContext_s
{
  sDlt_s_MessageLogInfo_t DltLogInfo;   /* this structure is used in calling the dlt filter function */
  sDlt_s_SessionId_t      DltSession;   /* session id, if any */
  u32                     DltTimestamp; /* the timestamp for the message */
  sPdu_s_Id_t             DltPdu;       /* the pdu to use */
  sDltPdu_s_Info_t        DltPduInfo;   /* used by Dlt */
  sDltPdu_s_Length_t      DltArgCountIdx; /* need to update the count before sending */
} sDltApp_s_LogContext_t;

/* get access to configuration data */
extern const sDlt_s_SessionIdTable_t sDltCfg_C_SessionIdTable_t [sDltApp_d_MAX_COUNT_SESSIONIDS]; /* PRQA S 1021 */ /* Macro may be used as a literal */
extern const sDlt_s_Config_t sDltCfg_C_Config_s; /* PRQA S 1500 */ /* incorrect, used by dltctrl.c */

/* --- Public Function Declarations ------------------------------------------------ */
extern void sDltApp_F_Init_v(void);

/*
 * register an application / context pair, using the default session and no description strings.
 * This function (or sDlt_F_registerContext_t, if the extra parameters are needed) must be called before
 * any of the DltApp logging functions can be used.
 */

extern sDlt_s_Return_t sDltApp_F_RegisterContext(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t);


/* start a new log message.
 * returns sDltCfg_D_E_OK, if the header info seems ok,
 * all other returns denote several errors:
 *
 */

extern sDlt_s_Return_t sDltApp_F_StartLogMessage(sDltApp_s_LogContext_t *o_LogMsgContext,
                                                 sDlt_s_Timestamp_t i_Timestamp,
                                                 sDlt_s_ApplicationId_t i_LogAppId,
                                                 sDlt_s_ContextId_t i_LogCtxId,
                                                 sDlt_s_MessageLogLevel_t i_LogLevel);

extern sDlt_s_Return_t sDltApp_F_EndLogMessage(sDltApp_s_LogContext_t *i_LogMsgContext);


extern sDlt_s_Return_t sDltApp_F_AddPayloadUInt8(sDltApp_s_LogContext_t *b_LogMsgContext, u8 i_Val_u8,
                                                 const char_t* i_Name, const char_t* i_Unit);

extern sDlt_s_Return_t sDltApp_F_AddPayloadUInt16(sDltApp_s_LogContext_t *b_LogMsgContext, u16 i_Val_u16,
                                                  const char_t* i_Name, const char_t* i_Unit);

extern sDlt_s_Return_t sDltApp_F_AddPayloadUInt32(sDltApp_s_LogContext_t *b_LogMsgContext, u32 i_Val_u32,
                                                  const char_t* i_Name, const char_t* i_Unit);

extern sDlt_s_Return_t sDltApp_F_AddPayloadSInt8(sDltApp_s_LogContext_t *b_LogMsgContext, s8 i_Val_s8,
                                                  const char_t* i_Name, const char_t* i_Unit);

extern sDlt_s_Return_t sDltApp_F_AddPayloadSInt16(sDltApp_s_LogContext_t *b_LogMsgContext, s16 i_Val_s16,
                                                  const char_t* i_Name, const char_t* i_Unit);

extern sDlt_s_Return_t sDltApp_F_AddPayloadSInt32(sDltApp_s_LogContext_t *b_LogMsgContext, s32 i_Val_s32,
                                                  const char_t* i_Name, const char_t* i_Unit);

extern sDlt_s_Return_t sDltApp_F_AddPayloadBool(sDltApp_s_LogContext_t *b_LogMsgContext, BOOL i_Val_b,
                                                const char_t* i_Name);

extern sDlt_s_Return_t sDltApp_F_AddPayloadString(sDltApp_s_LogContext_t *b_LogMsgContext, const char_t* i_Str,
                                                  const char_t* i_Name);

extern sDlt_s_Return_t sDltApp_F_AddPayloadRaw(sDltApp_s_LogContext_t *b_LogMsgContext, const u8* i_Data,
                                               s16 i_DataLen, const char_t* i_Name);

#if defined(__cplusplus)
}; // extern C
#endif

/* -------------------------------------------------------------------------- */
#endif /* DLTAPP_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltapp.h */



