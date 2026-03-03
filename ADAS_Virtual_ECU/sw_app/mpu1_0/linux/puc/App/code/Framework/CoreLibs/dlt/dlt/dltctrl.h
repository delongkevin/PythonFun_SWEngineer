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

#ifndef DLTCTRL_H_
#define DLTCTRL_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 2400 EOF */ /* functions in global namespace */

/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */
/* PRQA S 3448 EOF */  /* Suppressed QAC warning, functions are declared in a header file */
/* PRQA S 2300 EOF */ /* global scope, this is a header file */

#include "dlt_types.h"

#if defined(__cplusplus)
extern "C"
{
#endif

struct sDlt_s_ControlData_s;
extern const char_t sDltCfg_C_SoftwareVersionString_u8[ECU_SW_VER]; /* PRQA S 1021 */ /* macro replaced with literal */

/* --- Public Function Declarations ------------------------------------------------ */
/**
 * \par Description:
 *    this function modifies the pass through range for log messages for a given Context ID.
 *
 * 7.7.7.1.1 Set Log Level - [SWS_Dlt_00194]
 *
 * Request Parameter:
 * Application_ ID - 4*u8 - Representation of the Application ID. If this field is filled
 *                               with NULL all log level for all Context IDs on this ECU are set.
 * Context_ID - 4*u8 -  Representation of the Context ID. If this field is filled with NULL
 *                            all Context IDs belonging to the given Application ID are set.
 *                            is only interpreted if Application ID is not NULL
 * new_log_level - sint8 - the new log level to set.  can be in the range of sDltCfg_D_LOG_FATAL to
 *                            sDltCfg_D_LOG_VERBOSE for setting the pass through range.
 *                            if set to 0 all messages from this Context ID are blocked
 *                            if set to -1 the default log level for this ECU will be used
 * com_interface - 4*u8 - This field is used if Dlt supports filtering messages for different
 *                            interfaces differently. Than the log level for this interface can
 *                            be provided. Otherwise it should be filled with zeros. Not used
 *                            bytes are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setLogLevel_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/**
 * Interface function to change the log level from an application without the need to implement the DLT protocol itself.
 *
 * @param[in] i_AppId_t application that the log level should be set for.
 * If 0 this is a wildcard for the given context id. One of application ID and context ID has to be not 0.
 * @param[in] i_ContId_t context id that the log level should be set for.
 * If 0 this is a wildcard for the given application id. One of application ID and context ID has to be not 0.
 * @param[in] i_LogLevel_t The log level to set, such as sDltCfg_D_LOG_INFO.
 *
 * @return sDltCfg_D_CTRL_OK on success. sDltCfg_D_CTRL_NOT_SUPPORTED if no matching ID was found or both IDs were 0.
 */
extern u8 sDlt_F_setLogLevel_u8(sDlt_s_ApplicationId_t  i_AppId_t,
                                sDlt_s_ContextId_t i_ContId_t,
                                sDlt_s_MessageLogLevel_t i_LogLevel_t);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function modifies the pass through range for log messages for all not explicit
 *    set Context IDs.
 *
 * 7.7.7.1.2 Set Default Log Level - [SWS_Dlt_00380]
 *
 * Request Parameter:
 * new_log_level - sint8 - the new log level to set can be in the range of sDltCfg_D_LOG_FATAL
 *                            to sDltCfg_D_LOG_VERBOSE for setting the pass through range
 *                            if set to 0 all messages are blocked
 * com_interface - 4*u8 - This field is used if Dlt supports filtering messages for different
 *                            interfaces differently. Than the log level for this interface can
 *                            be provided. Otherwise it should be filled with zeros. Not used
 *                            bytes are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setDefaultLogLevel_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function enables or disables trace messages for a given Context ID.
 *
 * 7.7.7.1.3 Set Trace Status - [SWS_Dlt_00196]
 *
 * Request Parameter: A
 * Application_ID - 4*u8 - Representation of the Application ID. If this field is
 *                               filled with NULL all trace status for all Context IDs
 *                               on this ECU are set.
 * Context_ID - 4*u8 - Representation of the Context ID. If this field is filled
 *                         with NULL all Context IDs belonging to the given Application
 *                         ID are set. is only interpreted if Application ID is not NULL
 * new_trace_status - sint8 - the new trace status to set. can be 1 ?for On and 0 ?for Off.
 *                               if set to -1 the default trace status for this ECU will be used
 * com_interface - 4*u8 - This field is used if Dlt supports filtering messages for different
 *                            interfaces differently. Than the trace status for this interface can
 *                            be provided. Otherwise it should be filled with zeros. Not used
 *                            bytes are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setTraceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function enables or disables trace messages for all not explicit set Context IDs
 *
 * 7.7.7.1.4 Set Default Trace Status - [SWS_Dlt_00383]
 *
 * Request Parameter:
 * new_trace_status - sint8 - the new trace status to set. can be 1 ?for On and 0 ?for Off
 * com_interface - 4*u8 - This field is used if Dlt supports filtering messages for different
 *                            interfaces differently. Than the trace status for this interface can
 *                            be provided. Otherwise it should be filled with zeros. Not used
 *                            bytes are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setDefaultTraceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function returns information about registered Application IDs, there
 *    Context IDs and the corresponding log level.
 *
 * 7.7.7.1.5 Get Log Info - [SWS_Dlt_00197]
 *
 * Request Parameter:
 * Options - u8 - 1 - reserved; 2 - reserved; 3 - means only information about registered
 *                      Application IDs and Context IDs without log level or trace status
 *                      information; 4 - means information about registered Application IDs
 *                      and Context IDs with log level and without trace status information;
 *                      5 - means information about registered Application IDs and Context
 *                      IDs without log level and with trace status information; 6 - means
 *                      information about registered Application IDs and Context IDs with log
 *                      level and with trace status information; 7 - means information about
 *                      registered Application IDs and Context IDs with log level and with
 *                      trace status information and all textual descriptions of each
 *                      Application ID and Context ID (If DltImplementVerboseMode is not set
 *                      NOT_SUPPORTED shall be the response)
 * Application_ID - 4*u8 - Representation of the Application ID. If this field is filled
 *                               with NULL all Application IDs with all Context IDs registered
 *                               with this ECU are requested
 * Context_ID - 4*u8 - Representation of the Context ID. If this field is filled with NULL
 *                         all Context IDs belonging to the given Application ID are requested.
 *                         is only interpreted if Application ID is not NULL
 * com_interface - 4*u8 - This field is used if Dlt supports filtering messages for different
 *                            interfaces differently. Than the log level for this interface can
 *                            be provided. Otherwise it should be filled with zeros. Not used
 *                            bytes are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 1 - NOT_SUPPORTED, 2 - ERROR; 3 - means only information about registered
 *                      Application IDs and Context IDs without log level or trace status
 *                      information; 4 - means information about registered Application IDs and
 *                      Context IDs with log level and without trace status information; 5 - means
 *                      information about registered Application IDs and Context IDs without log
 *                      level and with trace status information; 6 - means information about
 *                      registered Application IDs and Context IDs with log level and with trace
 *                      status information; 7 - means information about registered Application IDs
 *                      and Context IDs with log level and with trace status information and all
 *                      textual descriptions of each Application ID and Context ID
 *                      NOTE: In this case the control message shall be in Verbose Mode;
 *                      8 ?NO matching Context IDs; 9 ?RESPONSE DATA OVERFLOW ?If the generated
 *                      response is to large for transmitting a single Dlt message (PDU is 65536 Byte)
 *                      only Status type RESPONSE DATA OVERFLOW shall be send (No Application_IDs and
 *                      com_interface entries are transmitted). Than the user could than decide to
 *                      formulate a less complex request.
 *                      If the response is not of the Status 1, 2, 8 or 9 it should be the same that
 *                      is used in the request entry of �Options?
 * Application_IDs - LogInfoType - Null if Status  == 1 or 2, Response is build like this:
 *                                  1. Number of Application IDs
 *                                  2. Application ID + Number of Context IDs
 *                                     1. Context ID + log level; 2. Context ID + log level; 3.  ?
 *                                  3. Application ID + Number of Context IDs
 *                                     1. Context ID + log level; 2.
 *                                  4. �l
 *                                  For a detailed description see 7.7.7.1.5.1 to 7.7.7.1.5.3
 * com_interface - 4*u8 - This field is used if Dlt supports filtering messages for different
 *                            interfaces differently. Than the log level for this interface can
 *                            be provided. Otherwise it should be filled with zeros. Not used
 *                            bytes are filled by zero.
 *
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getLogInfo_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function returns the actual default log level
 *
 * 7.7.7.1.6 Get Default Log Level - [SWS_Dlt_00198]
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * log_level - u8 - Actual log level
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getDefaultLogLevel_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function returns the actual default trace status
 *
 * 7.7.7.1.7 Get Default Trace Status - [SWS_Dlt_00494]
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * trace_status - u8 - Actual Trace Status 0 - off, 1 - on
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getDefaultTraceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function stores the actual configuration of Dlt to NVRAM (see 7.6.6)
 *
 * 7.7.7.1.8 Store Configuration - [SWS_Dlt_00199]
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_storeConfig_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function sets the configuration of Dlt to factory defaults
 *
 * 7.7.7.1.9 Reset to Factory Default - [SWS_Dlt_00200]
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * log_level - u8 - Actual log level
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_resetToFactoryDefault_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function enables or disables a specific communication interface.
 *
 * 7.7.7.1.10 Set Communication Interface Status - [SWS_Dlt_00201]
 *
 * Request Parameter:
 * com_interface - 4*u8 - To interpret as a name for a interface. Not used bytes
 *                            are filled by zero.
 * new_status - uin8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setComInterfaceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function returns the status information of a specific communication interface.
 *
 * 7.7.7.1.11 Get Communication Interface Status - [SWS_Dlt_00501]
 *
 * Request Parameter:
 * com_interface - 4*u8 - To interpret as a name for a interface. Not used bytes
 *                            are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR, 3 == INTERFACE NOT AVAILABLE
 * if_status - uin8 - Current interface status 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getComInterfaceStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function returns all available communication interfaces.
 *
 * 7.7.7.1.12 Get Communication Interface Names - [SWS_Dlt_00502]
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * count_if - uin8 - Count of transmitted interface names
 * com_if_names - 4*uin8[] - List of communication interface names. Array on each 4 byte
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getComInterfaceNames_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function sets the maximum bandwidth for a specific communication interface.
 *
 * 7.7.7.1.13 Set Communication Maximum Bandwidth - [SWS_Dlt_00202]
 *
 * Request Parameter:
 * com_interface - 4*u8 - To interpret as a name for a interface. Not used bytes
 *                            are filled by zero.
 * max_bandwidth - u32 - the maximum bandwidth to allowed for this interface in bit per second
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setComInterfaceMaxBandwidth_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * \par Description:
 *    this function returns the current maximum bandwidth for a specific communication
 *
 * 7.7.7.1.14 Get Communication Maximum Bandwidth - [SWS_Dlt_00503]
 *
 * Request Parameter:
 * com_interface - 4*u8 - To interpret as a name for a interface. Not used bytes
 *                            are filled by zero.
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR, 3 == INTERFACE NOT AVAILABLE
 * max_bandwidth - u32 - the maximum bandwidth allowed for this interface in bit per second
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getComInterfaceMaxBandwidth_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.15 Switch to Verbose Mode - [SWS_Dlt_00489]
 *
 * \par Description:
 *    this function switches on/off the Verbose Mode. This works only if the Dlt module and
 *    all SW-Cs are compiled with Verbose Mode enabled. If DltImplementVerboseMode is not
 *    set the response shall be NOT_SUPPORTED.
 *
 *    [SWS_Dlt_00203] - SetVerboseMode
 *    [SWS_Dlt_00204 ] - This service modifies the DltUseVerboseMode parameter.
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 * APID, CTID, SEID from header
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setVerboseMode_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.15 Switch to Verbose Mode - [SWS_Dlt_00489]
 *
 * \par Description:
 *    this function returns the Verbose Mode. This functionality is optionally, only if the Dlt
 *    module can track the verbose mode changes of the SW-C.
 *
 *    [SWS_Dlt_00504] - GetVerboseModeStatus
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * mode_status - u8 - 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getVerboseModeStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.16 Filter messages
 *
 * \par Description:
 *    this function switches on/off the message filtering by the Dlt module. If
 *    DltImplementFilterMessages is not set NOT_SUPPORTED shall be the response.
 *
 *    [SWS_Dlt_00205] - SetMessageFilterering
 *    [SWS_Dlt_00206] - This message modifies DltFilterMessages.
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setMessageFilterering_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.16 Filter messages
 *
 * \par Description:
 *    this function returns the message filtering status from the Dlt module.
 *
 *    [SWS_Dlt_00505] - GetMessageFiltereringStatus
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * filter_status - u8 - 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getMessageFiltereringStatus_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.17 Set Timing Packets
 *
 * \par Description:
 *    this function switches on/off the continuous cyclic sending of timing packets. If
 *    DltImplementTimestamp is not set NOT_SUPPORTED shall be the response.
 *
 *    [SWS_Dlt_00207] - SetTimingPackets
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setTimingPackets_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.18  Get Local Time
 *
 * \par Description:
 *    this function returns a single packet with timestamp (TMSP). The TSMP (timestamp)
 *    field of the standard header from the response control message shall contain a valid
 *    timestamp. The TMSP field is used for transmitting the timestamp in the response. #
 *    If DltImplementTimestamp is not set NOT_SUPPORTED shall be the response.
 *
 *    [SWS_Dlt_00208] - GetLocalTime
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * TMSP in header
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getLocalTime_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.19 Use ECU ID
 *
 * \par Description:
 *    this function enables/disables the transmission of the ECU ID in the header.
 *
 *    [SWS_Dlt_00209] - SetUseECUID
 *    [SWS_Dlt_00210] - This message modifies DltHeaderUseEcuId.
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setUseEcuId_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.19 Use ECU ID
 *
 * \par Description:
 *    this function returns the status of DltHeaderUseEcuId
 *
 *    [SWS_Dlt_00506] - GetUseECUID
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * ecuid_status - u8 - 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getUseEcuId_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.20 Use Session ID
 *
 * \par Description:
 *    this function enables/disables the transmission of the Session ID in the header.
 *
 *    [SWS_Dlt_00211] - SetUseSessionID
 *    [SWS_Dlt_00212] - This message modifies DltHeaderUseSessionID.
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setUseSessionId_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.20 Use Session ID
 *
 * \par Description:
 *    this function returns the status of DltHeaderUseSessionID
 *
 *    [SWS_Dlt_00507] - GetUseSessionID
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * sid_status - u8 - 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getUseSessionId_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.21 Use Timestamp
 *
 * \par Description:
 *    this function enables/disables the transmission of the Timestamp in the header.
 *
 *    [SWS_Dlt_00213] - SetUseTimestamp
 *    [SWS_Dlt_00214] - This message modifies DltHeaderUseTimestamp.
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setUseTimeStamp_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.21 Use Timestamp
 *
 * \par Description:
 *    this function returns the status of DltHeaderUseTimestamp
 *
 *    [SWS_Dlt_00508] - GetUseTimestamp
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * tst_status - u8 - 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getUseTimeStamp_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.22 Use Extended Header
 *
 * \par Description:
 *    this function enables/disables  the transmission of the extended header. If
 *    DltImplementExtendedHeader is not set NOT_SUPPORTED shall be the response
 *
 *    [SWS_Dlt_00215] - SetUseExtendedHeader
 *    [SWS_Dlt_00216] - This message modifies DltHeaderUseExtendedHeader.
 *
 * Request Parameter:
 * new_status - u8 - 0 ?OFF, 1 ?ON
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_setUseExtendedHeader_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.22 Use Extended Header
 *
 * \par Description:
 *    this function returns the status of DltHeaderUseExtendedHeader
 *
 *    [SWS_Dlt_00509] - GetUseExtendedHeader
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * exh_status - u8 - 0 ?OFF, 1 ?ON
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getUseExtendedHeader_v (sDlt_s_ControlData_t * b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.23  Call SW-C Injection
 *
 * \par Description:
 *    this function calls a function in a SW-C. If DltImplementSWCInjection is not set
 *    NOT_SUPPORTED shall be the response.
 *
 *    [SWS_Dlt_00220] - CallSW-CInjection
 *
 * Request Parameter:
 * data_length - u32 - length of the provided data
 * data[] - u8[] - data to provide to the SW-C
 * APID, CTID, SEID from header
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR, 3 == PENDING
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_callSwcInjection_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.24 Get ECU Software Version
 *
 * \par Description:
 *    this function returns the SW-Version Number of the ECUs software. This shall be a
 *    string containing some numbers, dots, slashes or lines for identifying uniquely a
 *    software version number. The string is freely usable and mostly depends on the
 *    build system. In Non Verbose Mode this string shall be used to associate and
 *    identify a correct description file to the transmitted data. Because Message IDs
 *    and its associated arguments can vary on different SW versions a correct mapping
 *    of SW-version and description file is very important. In the associated description
 *    file this string for SW-version shall also be enclosed.
 *
 *    [SWS_Dlt_00393] - GetSoftwareVersion
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * length - u32 - length of the string sw_version
 * sw_version - char[] - String containing the ECU ?Software Version
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_getSoftwareVersion_v (sDlt_s_ControlData_t *b_Ctrl_ps);

/* -------------------------------------------------------------------------- */
/**
 * See Protocol for Image &  Binary dumping for SwitchDumpMode
 *
 * \par Description:
 *    this function reports that a SwitchDumoMode message received. This can be requested by a
 *    client.
 *
 *
 * Request Parameter:
 * CMD - u8 - 0 == disalbe dump, 1 = enable dump
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_switchDumpMode_v(sDlt_s_ControlData_t *b_Ctrl_ps);

/**
 * The callback function pointer for start dump mode
 *
 * \par Description:
 *    this function will be called when received a dump command.
 *
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * none
 */
typedef void (*sDlt_F_DumpMode_t)(void);

/* -------------------------------------------------------------------------- */
/**
 * Registe callback function for SwitchDumpMode
 *
 * \par Description:
 *    this function will be called by system application. A function for handling
 *    dump mode will be registed.
 *
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * none
 *
 * \param[inout] i_CallBack_pf - sDlt_F_DumpMode_t - the function pointer for handling dump mode
 */
extern void sDlt_F_RegisterDumpModeFunc_v(sDlt_F_DumpMode_t i_CallBack_pf);

/* -------------------------------------------------------------------------- */
/**
 * 7.7.7.1.25 MessageBufferOverflow
 *
 * \par Description:
 *    this function reports that a MessageBufferOverflow happens. This can be requested by a
 *    client. Additionally this message is actively send by Dlt at the point when a
 *    MessageBufferOVervlow happens.
 *
 *    [SWS_Dlt_00487] - MessageBufferOverflow
 *
 * Request Parameter:
 * none
 *
 * Response Parameter:
 * Status - u8 - 0 == OK, 1 == NOT_SUPPORTED, 2 == ERROR
 * status - u8 - 0 ?no Message BufferOverflow, 1 ?MessageBufferOverflow was happened
 *
 * \param[inout] *b_Ctrl_ps - pointer to control data also modified by this function
 */
extern void sDlt_F_messageBufferOverflow_v (sDlt_s_ControlData_t *b_Ctrl_ps);

#if defined(__cplusplus)
}; // extern C
#endif

/* --------------------------------------------------------------------------------- */
#endif /* DLTCTRL_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltctrl.h */

