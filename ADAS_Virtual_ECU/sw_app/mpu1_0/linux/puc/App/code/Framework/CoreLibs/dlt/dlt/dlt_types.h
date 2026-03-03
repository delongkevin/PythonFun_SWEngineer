/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   Dlt
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Header file with types for implementation of the Dlt - Diagnostic log and trace
 * ======================================================================== */

#ifndef DLT_TYPES_H_
#define DLT_TYPES_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 1020 EOF */ /* Use of macros */
/* PRQA S 1021 EOF */ /* definitions in depending C-header files */
/* PRQA S 1026 EOF */ /* Macro may be used as a constant expression */
/* PRQA S 2400 EOF */ /* functions in global namespace */

/* QA-C */
/* PRQA S 3205 EOF */  /* Suppressed QAC warning, identifiers provided for other DLT modules */

#include "cfg/dlt_env.h"

/**
 * 8.3.2  Dlt_MessageTypeType - [SWS_Dlt_00224]
 * enumeration - This type describes the type of the message.
 *
 * for values see:
 * 7.7.4  Dlt Extended Header - [SWS_Dlt_00457]  The Extended Header shall contain
 * these entries - bit 1-3 - Message Type (MSTP)
 */
/* TODO - ugl change to typedef enum see example below */
typedef u8 sDlt_s_MessageType_t;
#define sDltCfg_D_TYPE_LOG          (0x00U)   /**< A log message */
#define sDltCfg_D_TYPE_APP_TRACE    (0x01U)   /**< A trace message */
#define sDltCfg_D_TYPE_NW_TRACE     (0x02U)   /**< A message forwarded from a communication bus (like CAN, FlexRay) */
#define sDltCfg_D_TYPE_CONTROL      (0x03U)   /**< A message for internal use/control send between Dlt module and external client */
#define sDltCfg_D_TYPE_VERBOSE      (0x01U)   /**< verbose flag in MSIN of extended header */
/**
 * 8.3.15 Dlt_ReturnType - [SWS_Dlt_00238]
 * enumeration - DLT return type
 */
/* TODO - ugl change to typedef enum see example below */
typedef DltStd_ReturnType sDlt_s_Return_t;
#define sDltCfg_D_E_OK                    (0U)  /**< The required operation succeeded.*/
#define sDltCfg_D_E_MSG_TOO_LARGE         (1U)  /**< The message is too big for the internal Dlt buffer. */
#define sDltCfg_D_E_CONTEXT_ALREADY_REG   (2U)  /**< The software module context has already registered. */
#define sDltCfg_D_E_UNKNOWN_SESSION_ID    (3U)  /**< Unknown session id. */
#define sDltCfg_D_E_IF_NOT_AVAILABLE      (4U)  /**< The interface is not available. */
#define sDltCfg_D_E_IF_BUSY               (5U)  /**< The interface is busy. */
#define sDltCfg_D_E_ERROR_UNKNOWN         (6U)  /**< An unknown error is occurred. */
#define sDltCfg_D_E_PENDING               (7U)  /**< Application process not yet completed, another call is required. */
#define sDltCfg_D_E_NOT_IN_VERBOSE_MODE   (8U)  /**< The Verbose Mode DltImplementVerboseMode flag has not been set,
                                                hence all functions that requires to send a message in verbose
                                                mode (i.e. Dlt_SendLogMessage and Dlt_SendTraceMessage ) shell
                                                return this error. */
#define sDltCfg_D_E_NOT_OK                (0xFDU)  /**< unexpected error like NULL pointer */
#define sDltCfg_D_E_MESSAGE_FILTERED      (0xFEU)  /**< message can not be sent due to filter rules */
#define sDltCfg_D_E_SNA                   (0xFFU)  /**< result not available */

/**
 * 8.3.8  Dlt_MessageLogLevelType - [SWS_Dlt_00230]
 * enumeration - This type describes the log level for each log message.
 */
/* TODO - ugl change to typedef enum see example below */
typedef u8  sDlt_s_MessageLogLevel_t;
#define sDltCfg_D_LOG_OFF        (0x00U)   /**< Turn off logging */
#define sDltCfg_D_LOG_FATAL      (0x01U)   /**< Fatal system error */
#define sDltCfg_D_LOG_ERROR      (0x02U)   /**< Errors occurring in a SW-C with impact to correct functionality */
#define sDltCfg_D_LOG_WARN       (0x03U)   /**< Log messages where a incorrect behavior can not be ensured  */
#define sDltCfg_D_LOG_INFO       (0x04U)   /**< Log messages providing information for better understanding of
                                            the internal behavior of a software */
#define sDltCfg_D_LOG_DEBUG      (0x05U)   /**< Log messages, which are usable only for debugging of a software */
#define sDltCfg_D_LOG_VERBOSE    (0x06U)   /**< Log messages with the highest communicative level, here all possible
                                             states, information and everything else can be logged */

/**
 * 8.3.9  Dlt_MessageTraceType - [SWS_Dlt_00231]
 * enumeration - This type describes labels for trace messages.
 */
/* TODO - ugl change to typedef enum see example below */
typedef u8 sDlt_s_MessageTrace_t;
#define sDltCfg_D_TRACE_VARIABLE          (0x01U)   /**< For tracing the value of a variable */
#define sDltCfg_D_TRACE_FUNCTION_IN       (0x02U)   /**< For tracing the calling of a function */
#define sDltCfg_D_TRACE_FUNCTION_OUT      (0x03U)   /**< For tracing the returning of a function */
#define sDltCfg_D_TRACE_STATE             (0x04U)   /**< For tracing a state of a state machine */
#define sDltCfg_D_TRACE_VFB               (0x05U)   /**< For tracing RTE Events */

/**
 * 8.3.10 Dlt_MessageControlInfoType - [SWS_Dlt_00232]
 * enumeration - This type describes the type of a Dlt control message.
 */
/* TODO - ugl change to typedef enum see example below */
#define sDltCfg_D_CONTROL_REQUEST         (0x01U)   /**< Declares a request of an operation on Dlt module */
#define sDltCfg_D_CONTROL_RESPONSE        (0x02U)   /**< Declares a the answer of an request */
#define sDltCfg_D_CONTROL_TIME            (0x03U)   /**< Declares a timing message */

/**
 * 8.3.11 Dlt_MessageNetworkTraceInfoType - [SWS_Dlt_00233]#
 * enumeration - This type describes transported type of a Dlt BUSMESSAGE.
 */
/* TODO - ugl change to typedef enum see example below */
#define sDltCfg_D_NW_TRACE_IPC            (0x01U)   /**< Inter process communication */
#define sDltCfg_D_NW_TRACE_CAN            (0x02U)   /**< CAN communication */
#define sDltCfg_D_NW_TRACE_FLEXRAY        (0x03U)   /**< Flexray communication */

/* Example for typedef enum */
// PRQA S 1051 ++ // code example
//typedef enum sDlt_E_Return_e
//{
//  sDlt_E_OK = 0x00U,
//  sDlt_E_MSG_TOO_LARGE = 0x01U,
//  sDlt_E_CONTEXT_ALREADY_REG = 0x02U,
//  sDlt_E_UNKNOWN_SESSION_ID = 0x03U,
//  sDlt_E_IF_NOT_AVAILABLE = 0x04U,
//  sDlt_E_IF_BUSY = 0x05U,
//  sDlt_E_ERROR_UNKNOWN = 0x06U,
//  sDlt_E_PENDING = 0x07U,
//  sDlt_E_NOT_IN_VERBOSE_MOD = 0x08U,
//  sDlt_E_NOT_OK = 0xFDU,
//  sDlt_E_MESSAGE_FILTERED = 0xFEU,
//  sDlt_E_SNA = 0xFFU
//}sDlt_E_Return_t;
// PRQA S 1051 ++ // code example

/* define DLT endianess coding */
#define sDltCfg_D_BIG_ENDIAN           STD_ON
#define sDltCfg_D_LITTLE_ENDIAN        STD_OFF

/**
 * 8.3.7  Dlt_MessageOptionsType - [SWS_Dlt_00229]
 * verbose_mode -- Bit 3: If set Verbose mode is used (yet not relevant)
 *
 * define bit mask for verbose mode
 */
#define sDltCfg_D_MOPT_VERBOSE_MODE         (0x08U)

/**
 * 8.3.12 Dlt_ MessageArgumentCount - [SWS_Dlt_00235]
 * This type describe count of arguments provided to a message
 *
 * for type see:
 * 7.7.4  Dlt Extended Header - [SWS_Dlt_00457]  The Extended Header shall contain
 * these entries - byte 1 bits 8 - Number of arguments (NOAR)
 */
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
typedef u8 sDlt_s_MessageArgumentCount_t;
#endif

/**
 * 8.3.7  Dlt_MessageOptionsType - [SWS_Dlt_00229]
 * bit field - Bit 0-2 sDlt_s_MessageType_t: determines type of msg (log,trace,...)
 *             Bit 3: If set Verbose mode is used (yet not relevant)
 */
typedef u8 sDlt_s_MessageOptions_t;

/**
 * 8.3.13 Dlt_MessageLogInfoType - [SWS_Dlt_00236]
 * structure -
 */
typedef struct sDlt_s_MessageLogInfo_s
{
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
  sDlt_s_MessageArgumentCount_t    ArgCount_t;
#endif
  sDlt_s_MessageLogLevel_t         LogLevel_t;
  sDlt_s_MessageOptions_t          Options_t;
  sDlt_s_ContextId_t               ContextId_t;
  sDlt_s_ApplicationId_t           AppId_t;
} sDlt_s_MessageLogInfo_t;

/**
 * 8.3.14 Dlt_MessageTraceInfoType - [SWS_Dlt_00237]
 * structure -
 */
typedef struct sDlt_s_MessageTraceInfo_s
{
  sDlt_s_MessageTrace_t      TraceInfo_t;
  sDlt_s_MessageOptions_t    Options_t;
  sDlt_s_ContextId_t         ContextId_t;
  sDlt_s_ApplicationId_t     AppId_t;
} sDlt_s_MessageTraceInfo_t;

/* -------------------------------------------------------------------------- */

/**
 * 7.7.3  Standard Header - [SWS_Dlt_00458]
 * The Standard Header shall consist of the following entries:
 */

/**
 * 7.7.3.1.1 Use Extended Header (UEH) - [SWS_Dlt_00406]
 * The Use Extended Header (UEH) bit is set depending on the configuration parameter
 * DltHeaderUseExtendedHeader.
 */
#define sDltCfg_D_HTYP_UEH          (0x01U)

/**
 * 7.7.3.1.2 Most Significant Byte First (MSBF)
 * The MSBF bit specifies the byte order of the payload. It depends on the
 * configuration parameter DltHeaderPayloadEndianes.
 */
#define sDltCfg_D_HTYP_MSBF         (0x02U)

/**
 * 7.7.3.1.3 With ECU ID (WEID)
 * With this parameter the sender of a message can be identified unique.
 * The WEID bit is set depending on the configuration parameter DltHeaderUseEcuId.
 */
#define sDltCfg_D_HTYP_WEID         (0x04U)

/**
 * 7.7.3.1.4 With Session ID (WSID) - [SWS_Dlt_00407]
 * The WSID bit is set depending on the configuration parameter DltHeaderUseSessionID.
 */
#define sDltCfg_D_HTYP_WSID         (0x08U)

/**
 * 7.7.3.1.5 With Timestamp (WTMS) - [SWS_Dlt_00408]
 * The WTMS bit is set depending on the configuration parameter DltHeaderUseTimestamp.
 */
#define sDltCfg_D_HTYP_WTMS         (0x10U)

/**
 * 7.7.3.1.6 Version Number (VERS)
 * The sender sets the Version Number of the Dlt Data Protocol in the Standard Header
 * according to the used version. The receiver checks the Version Number and interprets
 * the Dlt message according to the Version Number. Future versions of Dlt Data Protocol may exist.
 *
 * [SWS_Dlt_00299] - The Version Number for this Dlt Data Protocol is 0x1.
 */
#define sDltCfg_D_HTYP_VERS         (u8)(1U << 5U)
#define sDltCfg_D_HTYP_VERS_MASK    (u8)(7U << 5U)

/* -------------------------------------------------------------------------- */

/**
 * 7.7.4  Dlt Extended Header
 * The Extended Header will be transmitted if the UEH bit (Use Extended Header)
 * is set in the Standard Header.
 */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* define function types for call back functions */
/* -------------------------------------------------------------------------- */
/**
 * 8.5.1.1  dlt_setLogLevel - [SWS_Dlt_00252]
 *
 * \par Description:
 *    Callback is called by Dlt to inform the SW-C of a new log level status of a given context.
 *
 * \param[in] i_AppId_t - the Application ID
 * \param[in] i_ContextId_t - the Context ID
 * \param[in] i_LogLevel_t - the new log level of the context
 */
typedef void (*sDlt_s_SetLogLevelCbk_t)(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t, sDlt_s_MessageLogLevel_t i_LogLevel_t);

/**
 * 8.5.1.2  dlt_setTraceStatus - [SWS_Dlt_00254]
 *
 * \par Description:
 *    Callback is called by Dlt to inform the SW-C of a new trace status of a given context.
 *
 * \param[in] i_AppId_t - the Application ID
 * \param[in] i_ContextId_t - the Context ID
 * \param[in] i_NewTraceStatus_b - the new trace_status for the pair of Application ID and Context ID
 */
typedef void (*sDlt_s_SetTraceStatusCbk_t)(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t, BOOL i_NewTraceStatus_b);

/**
 * 8.5.1.3  dlt_setVerboseMode - [SWS_Dlt_00256]
 *
 * \par Description:
 *    Callback is called by Dlt to inform the SW-C of a change of the verbose mode.
 *
 * \param[in] i_AppId_t - the Application ID
 * \param[in] i_ContextId_t - the Context ID
 * \param[in] i_IsVerboseMode_b - if true, Verbose Mode is enabled, if false Verbose Mode is disabled
 */
typedef void (*sDlt_s_SetVerboseModeCbk_t)(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t, BOOL i_IsVerboseMode_b);

/**
 * 8.5.1.xxx  dlt_getVerboseMode - [SWS_Dlt_00xxx]
 *
 * \par Description:
 *    Callback is called by Dlt to get the verbose mode status from the SW-C
 *
 * \param[in] i_AppId_t - the Application ID
 * \param[in] i_ContextId_t - the Context ID
 *
 * \return BOOL - current verbose mode status
 */
typedef BOOL (*sDlt_s_GetVerboseModeCbk_t)(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t);

/**
 * 8.5.1.4  dlt_injectCall - [SWS_Dlt_00259]
 *
 * \par Description:
 *    Callback is called by Dlt to inject a function call in the SW-C. The behaviour
 *    trigged by this function should depend on the service_id also the interpretation of
 *    the user data. Both are specific to the application.
 *
 * \param[in] i_AppId_t - the Application ID
 * \param[in] i_ContextId_t - the Context ID
 * \param[in] i_ServiceId_u32 - the service ID for the injection (user defined)
 * \param[in] i_DataLength_u32 - length of the data puffer provided
 * \param[in] i_Data_pu8 - pointer to data puffer with data belonging to the injection (serviceID).
 *                         The contents of the data is user defined
 */
typedef void (*sDlt_s_SwcInjectionCbk_t)(sDlt_s_ApplicationId_t i_AppId_t, sDlt_s_ContextId_t i_ContextId_t, u32 i_ServiceId_u32,
    u32 i_DataLength_u32, const u8* i_Data_pu8);

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/** define DLT Service IDs */
#define sDltCfg_D_SID_SET_LOG_LEVEL                   (0x01U)   /**< 7.7.7.1.1 Set Log Level - [SWS_Dlt_00194] */
#define sDltCfg_D_SID_SET_DEFAULT_LOG_LEVEL           (0x11U)   /**< 7.7.7.1.2 Set Default Log Level - [SWS_Dlt_00380] */
#define sDltCfg_D_SID_SET_TRACE_STATUS                (0x02U)   /**< 7.7.7.1.3 Set Trace Status - [SWS_Dlt_00196] */
#define sDltCfg_D_SID_SET_DEFAULT_TRACE_STATUS        (0x12U)   /**< 7.7.7.1.4 Set Default Trace Status - [SWS_Dlt_00383] */
#define sDltCfg_D_SID_GET_LOG_INFO                    (0x03U)   /**< 7.7.7.1.5 Get Log Info - [SWS_Dlt_00197] */
#define sDltCfg_D_SID_GET_DEFAULT_LOG_LEVEL           (0x04U)   /**< 7.7.7.1.6 Get Default Log Level - [SWS_Dlt_00198] */
#define sDltCfg_D_SID_GET_DEFAULT_TRACE_STATUS        (0x15U)   /**< 7.7.7.1.7 Get Default Trace Status - [SWS_Dlt_00494] */
#define sDltCfg_D_SID_STORE_CONFIG                    (0x05U)   /**< 7.7.7.1.8 Store Configuration - [SWS_Dlt_00199] */
#define sDltCfg_D_SID_RESET_TO_FACTORY_DEFAULT        (0x06U)   /**< 7.7.7.1.9 Reset to Factory Default - [SWS_Dlt_00200] */
#define sDltCfg_D_SID_SET_COMINTERFACE_STATUS         (0x07U)   /**< 7.7.7.1.10  Set Communication Interface Status - [SWS_Dlt_00201] */
#define sDltCfg_D_SID_GET_COMINTERFACE_STATUS         (0x16U)   /**< 7.7.7.1.11  Get Communication Interface Status - [SWS_Dlt_00501] */
#define sDltCfg_D_SID_GET_COMINTERFACE_NAMES          (0x17U)   /**< 7.7.7.1.12  Get Communication Interface Names - [SWS_Dlt_00502] */
#define sDltCfg_D_SID_SET_COMINTERFACE_MAX_BANDWIDTH  (0x08U)   /**< 7.7.7.1.13  Set Communication Maximum Bandwidth - [SWS_Dlt_00202] */
#define sDltCfg_D_SID_GET_COMINTERFACE_MAX_BANDWIDTH  (0x18U)   /**< 7.7.7.1.14  Get Communication Maximum Bandwidth - [SWS_Dlt_00503] */
#define sDltCfg_D_SID_SET_VERBOSE_MODE                (0x09U)   /**< 7.7.7.1.15  Switch to Verbose Mode - [SWS_Dlt_00203] */
#define sDltCfg_D_SID_GET_VERBOSE_MODE_STATUS         (0x19U)   /**< 7.7.7.1.15  Switch to Verbose Mode - [SWS_Dlt_00504] */
#define sDltCfg_D_SID_SET_MESSAGE_FILTERERING         (0x0AU)   /**< 7.7.7.1.16  Filter messages - [SWS_Dlt_00205] */
#define sDltCfg_D_SID_GET_MESSAGE_FILTERERING_STATUS  (0x1AU)   /**< 7.7.7.1.16  Filter messages - [SWS_Dlt_00505] */
#define sDltCfg_D_SID_SET_TIMING_PACKETS              (0x0BU)   /**< 7.7.7.1.17  Set Timing Packets - [SWS_Dlt_00207] */
#define sDltCfg_D_SID_GET_LOCAL_TIME                  (0x0CU)   /**< 7.7.7.1.18  Get Local Time - [SWS_Dlt_00208] */
#define sDltCfg_D_SID_SET_USE_ECUID                   (0x0DU)   /**< 7.7.7.1.19  Use ECU ID - [SWS_Dlt_00209] */
#define sDltCfg_D_SID_GET_USE_ECUID                   (0x1BU)   /**< 7.7.7.1.19  Use ECU ID - [SWS_Dlt_00506] */
#define sDltCfg_D_SID_SET_USE_SESSIONID               (0x0EU)   /**< 7.7.7.1.20  Use Session ID - [SWS_Dlt_00211] */
#define sDltCfg_D_SID_GET_USE_SESSIONID               (0x1CU)   /**< 7.7.7.1.20  Use Session ID - [SWS_Dlt_00507] */
#define sDltCfg_D_SID_USE_TIME_STAMP                  (0x0FU)   /**< 7.7.7.1.21  Use Timestamp - [SWS_Dlt_00213] */
#define sDltCfg_D_SID_GET_USE_TIME_STAMP              (0x1DU)   /**< 7.7.7.1.21  Use Timestamp - [SWS_Dlt_00508] */
#define sDltCfg_D_SID_USE_EXTENDED_HEADER             (0x10U)   /**< 7.7.7.1.22  Use Extended Header - [SWS_Dlt_00215] */
#define sDltCfg_D_SID_GET_USE_EXTENDED_HEADER         (0x1EU)   /**< 7.7.7.1.22  Use Extended Header - [SWS_Dlt_00509] */
#define sDltCfg_D_SID_GET_SOFTWARE_VERSION            (0x13U)   /**< 7.7.7.1.24  Get ECU Software Version - [SWS_Dlt_00393] */
#define sDltCfg_D_SID_MESSAGE_BUFFER_OVERFLOW         (0x14U)   /**< 7.7.7.1.25  MessageBufferOverflow - [SWS_Dlt_00487] */
#define sDltCfg_D_SID_SWITCH_DUMP_MODE                (0xDDU)    /** Extend DLT to let client be able to enalb/disable dump mode */
#define sDltCfg_D_SID_CALL_SWC_INJECTION_MIN          (0x0FFFU) /**< 7.7.7.1.23  Call SW-C Injection - [SWS_Dlt_00220] */
#define sDltCfg_D_SID_CALL_SWC_INJECTION_MAX          (0xFFFFFFFFU) /**< 7.7.7.1.23  range 0xFFF ... 0xFFFFFFFF */

/* define return codes for control messages */
#define sDltCfg_D_CTRL_OK               (0U)
#define sDltCfg_D_CTRL_NOT_SUPPORTED    (1U)
#define sDltCfg_D_CTRL_ERROR            (2U)

/**
 * 7.8  Error classification - [SWS_Dlt_00447]
 * DLT service return codes
 */
#define sDltCfg_D_E_WRONG_PARAMETERS         (0x01)
#define sDltCfg_D_E_ERROR_IN_PROV_SERVICE    (0x02)
#define sDltCfg_D_E_COM_FAILURE              (0x03)
#define sDltCfg_D_E_ERROR_TO_MANY_CONTEXT    (0x04)
#define sDltCfg_D_E_MSG_LOOSE                (0x05)
#define sDltCfg_D_E_PARAM_POINTER            (0x06)

/**
 * 7.7.7.1.5.3 ContextIDsInfoType
 * structure - Holds information about a specific Context ID
 */
typedef struct sDlt_s_ContextIdsInfo_s
{
  u32     ContextId_u32;
  s8      LogLevel_s8;                     /**< if options == 4,6 or 7 */
  s8      TraceStatus_s8;                  /**< if options == 5,6 or 7 */
  u16     ContextDescriptionLen_u16;       /**< optional, if options == 7 */
  string  ContextDescription_pc;           /**< optional, if options == 7 */
} sDlt_s_ContextIdsInfo_t;

/**
 * 7.7.7.1.5.2 AppIDsType
 * structure - Holds information about a specific Application ID
 */
typedef struct sDlt_s_AppIds_s
{
  u32                       AppId_u32;
  u16                       ContextIdsCount_u16;
  sDlt_s_ContextIdsInfo_t   ContextIdInfo_t;
  u16                       AppDescriptionLen_u16;           /**< optional, if options == 7 */
  string                    AppDescription_pc;               /**< optional, if options == 7 */
} sDlt_s_AppIds_t;

/**
 * 7.7.7.1.5.1 LogInfoType
 * structure -
 */
typedef struct sDlt_s_LogInfo_s
{
  u16               AppIdsCount_u16;
  sDlt_s_AppIds_t   AppIds_t;
} sDlt_s_LogInfo_t;

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

#if (sDltCfg_d_MAX_COUNT_APPIDS < 256U)
typedef u8 sDlt_s_MaxCountAppIds_t;
#elif (sDltCfg_d_MAX_COUNT_APPIDS < 65536U)
typedef u16 sDlt_s_MaxCountAppIds_t;
#else
#error symbol sDltCfg_d_MAX_COUNT_APPIDS is out of bounds
#endif

#if (sDltCfg_d_MAX_COUNT_CONTEXTIDS < 256U)
typedef u8 sDlt_s_MaxCountCbks_t;
#elif (sDltCfg_d_MAX_COUNT_CONTEXTIDS < 65536U)
typedef u16 sDlt_s_MaxCountCbks_t;
#else
#error symbol sDltCfg_d_MAX_COUNT_CONTEXTIDS is out of bounds
#endif
/* -------------------------------------------------------------------------- */

/* define max length for header (std + ext) */
/* TODO - ugl move to dlt_cfg.h - #define sDltCfg_d_HDR_LEN_MAX          (26U) */

/* define header type including standard and extended header */
/* TODO - ugl move to dlt_cfg.h - typedef u8 sDlt_s_Header_t[sDltCfg_d_HDR_LEN_MAX]; */

/** dlt run time data structure */
typedef struct sDlt_s_Data_s
{
  u32   BandwidthForDiagChannel_u32;      /**< ECUC_Dlt_00803 - DltBandwidthForDiagChannel - For communication
                                               over the DCM and as follows over the diagnostic interface the
                                               maximum bandwidth shall be set. Unit: kbit per second range:
                                               0 .. 4294967295 */
  u32   BandwidthForComModule_u32;        /**< ECUC_Dlt_00802 - DltBandwidthForComModule - For communication over
                                               the Dlt Communication Module the maximum bandwidth shall be set.
                                               Unit: kbit per second range: 0 .. 4294967295 */
  sDlt_s_MaxCountAppIds_t RegCnt_t;       /**< count number of registered app/context ids */
  BOOL  HeaderUseEcuId_b;                 /**< ECUC_Dlt_00811 - DltHeaderUseEcuId - Corresponds to field WEID
                                               (With ECU ID). If set ECU ID shall be placed in the header,
                                               else not. */
  BOOL  HeaderUseSessionId_b;             /**< ECUC_Dlt_00813 - DltHeaderUseSessionID - Corresponds to field WSID
                                               (with Session ID). If set the Session ID shall be placed in the
                                               header, else not. */
  BOOL  DefaultTraceStatus_b;             /**< ECUC_Dlt_00843 - DltDefaultTraceStatus - Tells if trace messages
                                               shall be forwarded by Dlt. */
  u8    DefaultLogLevel_u8;               /**< ECUC_Dlt_00805 - DltDefaultMaxLogLevel - The maximum log level
                                               a received message (from SW-C to Dlt) can have. This can also
                                               be modified at runtime and stored persistently in NVRAM. */
  BOOL  Initialized_b;                    /**< dlt initialized signal */
  u8    MessageCount_u8;                  /**< counter for sent messages */
  BOOL  HeaderUseVerboseMode_b;           /**< ECUC_Dlt_00836 - DltUseVerboseMode - If this flag is set Dlt shall
                                               use the Verbose Mode for generating the header of the transport
                                               protocol. If it is not set, the Non Verbose Mode shall be used.
                                               dependency: Can only be true if DltImplementVerboseMode is true. */
  BOOL  MessageBufferOverflow_b;          /**< [SWS_Dlt_00297] - If message loose happens the Dlt control message
                                               MessageBufferOverflow shall be send. Additionally an internal flag
                                               shall be set for remembering this messages loose. */

#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
  BOOL  HeaderUseExtendedHeader_b;        /**< ECUC_Dlt_00812 - DltHeaderUseExtendedHeader - Corresponds to
                                               field UEH (Use Extended Header). If set the Extended Header
                                               shall be attached, else not. */
#endif

#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
  BOOL  FilterMessages_b;                 /**< ECUC_Dlt_00808 - DltFilterMessages - This flag gives the Dlt
                                               the instruction to filter or not to filter incoming log or
                                               trace messages. If it is not set all incoming messages are
                                               forwarded to the communication channel. */
#endif

#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
  BOOL  HeaderUseTimestamp_b;             /**< ECUC_Dlt_00814 - DltHeaderUseTimestamp - Corresponds to field
                                               WTMS (With Timestamp). If set the timestamp shall be placed
                                               in the header, else not. */
#endif

#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
  BOOL  SendCyclicTimestamp_b;            /**< [SWS_Dlt_00207] - Called to switch on/off the continuous cyclic
                                               sending of timing packets. If DltImplementTimestamp is not set
                                               NOT_SUPPORTED shall be the response.  */
#endif

#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
  u8    VfbTraceLogLevel_u8;              /**< ECUC_Dlt_00839 - DltVfbTraceLogLevel - The log level of the log
                                               messages generated by the VFB-Trace. ImplementationType:
                                               sDlt_s_MessageLogLevel_t, select the VFB trace log level range: 0 .. 6 */
#endif
  u8    DumpMode_u8;
} sDlt_s_Data_t;



/* -------------------------------------------------------------------------- */
/**
 * 7.6.4.3  Recommended tables in Dlt to hold information about Application and Context IDs
 * Figure 19 - a solution with two tables. This is for a small number of Application and
 * Context IDs. Here a linear search must be done.
 * The size (number of lines) of sDlt_s_AppIdCIdTable_t corresponds to DltMaxCountAppIds.
 * The number of rows of sDlt_s_SessionIdTable_t corresponds to DltMaxCountContextIds.
 */
typedef struct sDlt_s_AppIdCIdTable_s
{
  sDlt_s_ApplicationId_t    AppId_t;
  sDlt_s_ContextId_t        ContextId_t;
  sDlt_s_MaxCountCbks_t     CbkRef_t;
  sDlt_s_MessageLogLevel_t  LogLevel_t;
  BOOL                      TraceStatus_b;
  /**
   * [SWS_Dlt_00064]
   * If DltImplementAppIdContextIdQuery is true additionally to each Application ID
   * and Context ID a description string shall be storable.
   */
#ifdef sDltCfg_D_IMPLEMENT_APPID_CONTEXTID_QUERY
  const u8*             AppDescription_pu8;
  u8                    AppDescriptionLen_u8;
  const u8*             ContextDescription_pu8;
  u8                    ContextDescriptionLen_u8;
#endif
} sDlt_s_AppIdCIdTable_t;

typedef struct sDlt_s_SessionIdTable_s
{
  sDlt_s_SessionId_t          SessionId_t;
  sDlt_s_SetLogLevelCbk_t     CbSetLogLevel_t;
  sDlt_s_SetTraceStatusCbk_t  CbSetTraceStatus_t;
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
  sDlt_s_SetVerboseModeCbk_t  CbSetVerboseMode_t;
  sDlt_s_GetVerboseModeCbk_t  CbGetVerboseMode_t;
#endif
#ifdef sDltCfg_D_IMPLEMENT_SWC_INJECTION
  sDlt_s_SwcInjectionCbk_t    CbSwcInjection_t;
#endif
} sDlt_s_SessionIdTable_t;

/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */

/* define header type including standard and extended header */
/* TODO - ugl already declared - typedef u8 sDlt_s_Header_t[sDltCfg_d_HDR_LEN_MAX]; */

/* define PDU data structure */
typedef struct sDlt_sPDU_Data_s
{
  u8  Data_u8;
} sDlt_sPDU_Data_t;

/* define structure for control message processing */
typedef struct sDlt_s_ControlData_s
{
  u8 *                    Resp_pu8;
  u32                     ServiceId_u32;
  sDlt_s_SessionId_t      SesId_t;
  sDlt_s_ApplicationId_t  AppId_t;
  sDlt_s_ContextId_t      ConId_t;
  sPdu_s_Id_t             PduId_t;
  sDltPdu_s_Length_t      PduIdx_t;
  sDltPdu_s_Length_t      RxLen_t;
  sDltPdu_s_Length_t      TxLen_t;
  u8                      Endian_u8;
  u8                      Htyp_u8;
  u8                      Msin_u8;
} sDlt_s_ControlData_t;

/* -------------------------------------------------------------------------- */
/* define request and response structures for control message processing */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetLogLevelRequest_s
{
  u8 AppId_au8[4];
  u8 ConId_au8[4];
  u8 NewLogLevel_u8;
  u8 ComInterface_au8[4];
} sDlt_s_SetLogLevelRequest_t;

typedef struct sDlt_s_SetLogLevelResponse_s
{
  u8 Status_u8;
} sDlt_s_SetLogLevelResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetDefaultLogLevelRequest_s
{
  u8 NewLogLevel_u8;
  u8 ComInterface_au8[4];
} sDlt_s_SetDefaultLogLevelRequest_t;

typedef struct sDlt_s_SetDefaultLogLevelResponse_s
{
  u8 Status_u8;
} sDlt_s_SetDefaultLogLevelResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetTraceStatusRequest_s
{
  u8 AppId_au8[4];
  u8 ConId_au8[4];
  u8 NewTraceStatus_u8;
  u8 ComInterface_au8[4];
} sDlt_s_SetTraceStatusRequest_t;

typedef struct sDlt_s_SetTraceStatusResponse_s
{
  u8 Status_u8;
} sDlt_s_SetTraceStatusResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetDefaultTraceStatusRequest_s
{
  u8 NewTraceStatus_u8;
  u8 ComInterface_au8[4];
} sDlt_s_SetDefaultTraceStatusRequest_t;

typedef struct sDlt_s_SetDefaultTraceStatusResponse_s
{
  u8 Status_u8;
} sDlt_s_SetDefaultTraceStatusResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_GetLogInfoRequest_s
{
  u8 Options_u8;
  u8 AppId_au8[4];
  u8 ConId_au8[4];
  u8 ComIf_au8[4];
} sDlt_s_GetLogInfoRequest_t;

typedef struct sDlt_s_GetLogInfoResponse_s
{
  u8 Status_u8;
  /* structure incomplete */
} sDlt_s_GetLogInfoResponse_t;

typedef struct sDlt_s_GetDefaultLogLevelResponse_s
{
  u8 Status_u8;
  u8 LogLevel_u8;
} sDlt_s_GetDefaultLogLevelResponse_t;

typedef struct sDlt_s_GetDefaultTraceStatusResponse_s
{
  u8 Status_u8;
  u8 TraceStatus_u8;
} sDlt_s_GetDefaultTraceStatusResponse_t;

typedef struct sDlt_s_StoreConfigResponse_s
{
  u8 Status_u8;
} sDlt_s_StoreConfigResponse_t;

typedef struct sDlt_s_ResetToFactoryDefaultResponse_s
{
  u8 Status_u8;
} sDlt_s_ResetToFactoryDefaultResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetComInterfaceStatusRequest_s
{
  u8 ComInterface_au8[4];
  u8 NewStatus_u8_u8;
} sDlt_s_SetComInterfaceStatusRequest_t;

typedef struct sDlt_s_SetComInterfaceStatusResponse_s
{
  u8 Status_u8;
} sDlt_s_SetComInterfaceStatusResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_GetComInterfaceStatusRequest_s
{
  u8 ComInterface_au8[4];
} sDlt_s_GetComInterfaceStatusRequest_t;

typedef struct sDlt_s_GetComInterfaceStatusResponse_s
{
  u8 Status_u8;
  u8 IfStatus_u8;
} sDlt_s_GetComInterfaceStatusResponse_t;

typedef struct sDlt_s_GetComInterfaceNamesResponse_s
{
  u8 Status_u8;
  u8 CountIf_u8;
  u8 ComIfNames_u8[4];
} sDlt_s_GetComInterfaceNamesResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetComIfMaxBandwidthRequest_s
{
  u8 ComInterface_au8[4];
  u8 MaxBandwith_au8[4];
} sDlt_s_SetComIfMaxBandwidthRequest_t;

typedef struct sDlt_s_SetComIfMaxBandwidthResponse_s
{
  u8 Status_u8;
} sDlt_s_SetComIfMaxBandwidthResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_GetComIfMaxBandwidthRequest_s
{
  u8 ComInterface_au8[4];
} sDlt_s_GetComIfMaxBandwidthRequest_t;

typedef struct sDlt_s_GetComIfMaxBandwidthResponse_s
{
  u8 Status_u8;
  u8 MaxBandwith_au8[4];
} sDlt_s_GetComIfMaxBandwidthResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetVerboseModeRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetVerboseModeRequest_t;

typedef struct sDlt_s_SetVerboseModeResponse_s
{
  u8 Status_u8;
} sDlt_s_SetVerboseModeResponse_t;

typedef struct sDlt_s_GetVerboseModeStatusResponse_s
{
  u8 Status_u8;
  u8 ModeStatus_u8;
} sDlt_s_GetVerboseModeStatusResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetMessageFiltereringRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetMessageFiltereringRequest_t;

typedef struct sDlt_s_SetMessageFiltereringResponse_s
{
  u8 Status_u8;
} sDlt_s_SetMessageFiltereringResponse_t;

typedef struct sDlt_s_GetMessageFiltereringResponse_s
{
  u8 Status_u8;
  u8 FilterStatus_u8;
} sDlt_s_GetMessageFiltereringResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetTimingPacketsRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetTimingPacketsRequest_t;

typedef struct sDlt_s_SetTimingPacketsResponse_s
{
  u8 Status_u8;
} sDlt_s_SetTimingPacketsResponse_t;

typedef struct sDlt_s_GetLocalTimeResponse_s
{
  u8 Status_u8;
} sDlt_s_GetLocalTimeResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetUseEcuIdRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetUseEcuIdRequest_t;

typedef struct sDlt_s_SetUseEcuIdResponse_s
{
  u8 Status_u8;
} sDlt_s_SetUseEcuIdResponse_t;

typedef struct sDlt_s_GetUseEcuIdResponse_s
{
  u8 Status_u8;
  u8 EcuIdStatus_u8;
} sDlt_s_GetUseEcuIdResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetUseSessionIdRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetUseSessionIdRequest_t;

typedef struct sDlt_s_SetUseSessionIdResponse_s
{
  u8 Status_u8;
} sDlt_s_SetUseSessionIdResponse_t;

typedef struct sDlt_s_GetUseSessionIdResponse_s
{
  u8 Status_u8;
  u8 SIdStatus_u8;
} sDlt_s_GetUseSessionIdResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetUseTimeStampRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetUseTimeStampRequest_t;

typedef struct sDlt_s_SetUseTimeStampResponse_s
{
  u8 Status_u8;
} sDlt_s_SetUseTimeStampResponse_t;


typedef struct sDlt_s_GetUseTimeStampResponse_s
{
  u8 Status_u8;
  u8 TimeStampStatus_u8;
} sDlt_s_GetUseTimeStampResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SetUseExtendedHeaderRequest_s
{
  u8 NewStatus_u8;
} sDlt_s_SetUseExtendedHeaderRequest_t;

typedef struct sDlt_s_SetUseExtendedHeaderResponse_s
{
  u8 Status_u8;
} sDlt_s_SetUseExtendedHeaderResponse_t;

typedef struct sDlt_s_GetUseExtendedHeaderResponse_s
{
  u8 Status_u8;
  u8 ExhStatus_u8;
} sDlt_s_GetUseExtendedHeaderResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_CallSwcInjectionRequest_s
{
  u8 DataLength_au8[4];
  u8 Data_u8;
} sDlt_s_CallSwcInjectionRequest_t;

typedef struct sDlt_s_CallSwcInjectionResponse_s
{
  u8 Status_u8;
} sDlt_s_CallSwcInjectionResponse_t;

typedef struct sDlt_s_GetSoftwareVersionResponse_s
{
  u8 Status_u8;
  u8 Length_au8[4];
  u8 SwVersion_au8[sDltCfg_d_CTRL_RESPONSE_BUFFER_SZ - 9U]; /* size of sw version buffer is PDU length
                                                               - std header - ext header = response buffer size
                                                               - service id (4) - status (1)- length (4) */
} sDlt_s_GetSoftwareVersionResponse_t;

/* -------------------------------------------------------------------------- */
typedef struct sDlt_s_SwitchDumpModeRequest_s
{
  u8 AppId_au8[4];
  u8 Cmd_u8;
} sDlt_s_SwitchDumpModeRequest_t;

typedef struct sDlt_s_SwitchDumpModeReponse_s
{
  u8 Status_u8;
} sDlt_s_SwitchDumpModeResponse_t;

typedef struct sDlt_s_messageBufferOverflowResponse_s
{
  u8 Status_u8;
  u8 OvrflwStatus_u8;
} sDlt_s_messageBufferOverflowResponse_t;

/**
 * 8.3.1  Dlt_ConfigType - [SWS_Dlt_00437]
 * structure - This is the type of the data structure containing the initialization data for Dlt.
 */
typedef struct sDlt_s_Config_s
{
  u32   BandwidthForDiagChannel_u32;
  u32   BandwidthForComModule_u32;
  BOOL  HeaderUseEcuId_b;
  BOOL  HeaderUseSessionId_b;
  BOOL  DefaultTraceStatus_b;
  u8    DefaultLogLevel_u8;
  BOOL  HeaderUseVerboseMode_b;
#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
  BOOL  HeaderUseExtendedHeader_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
  BOOL  FilterMessages_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
  BOOL  HeaderUseTimestamp_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
  BOOL  SendCyclicTimestamp_b;
#endif
#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
  u8    VfbTraceLogLevel_u8;
#endif
} sDlt_s_Config_t;
/* --------------------------------------------------------------------------------- */
#endif /* DLT_TYPES_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlt_types.h */
