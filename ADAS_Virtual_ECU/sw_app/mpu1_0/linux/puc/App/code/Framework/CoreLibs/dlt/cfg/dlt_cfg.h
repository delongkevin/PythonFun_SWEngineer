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

#ifndef DLT_CFG_H_
#define DLT_CFG_H_

#include <platform/PlatformSpecs.h>

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
/* PRQA S 1052 EOF */ /* This file contains some commented out compiler switches by design */

/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 1020 EOF */ /* Use of macros */
/* PRQA S 1021 EOF */ /* definitions in depending C-header files */
/* PRQA S 1026 EOF */ /* Macro may be used as a constant expression */

/* define standard header position index and length */
#define sDltCfg_d_HDR_IDX_HTYP         (0U)
#define sDltCfg_d_HDR_IDX_MCNT         (1U)
#define sDltCfg_d_HDR_IDX_LEN          (2U)
#define sDltCfg_d_HDR_IDX_ECUID        (4U)
#define sDltCfg_d_HDR_IDX_SEID         (8U)
#define sDltCfg_d_HDR_IDX_TMSP         (12U)
#define sDltCfg_d_HDR_LEN_HTYP         (1U)
#define sDltCfg_d_HDR_LEN_MCNT         (1U)
#define sDltCfg_d_HDR_LEN_LEN          (2U)
#define sDltCfg_d_HDR_LEN_ECUID        (4U)
#define sDltCfg_d_HDR_LEN_SEID         (4U)
#define sDltCfg_d_HDR_LEN_TMSP         (4U)

/* define extended header position index and length */
#define sDltCfg_d_HDR_IDX_MSIN         (0U)
#define sDltCfg_d_HDR_IDX_NOAR         (1U)
#define sDltCfg_d_HDR_IDX_APID         (2U)
#define sDltCfg_d_HDR_IDX_CTID         (6U)
#define sDltCfg_d_HDR_LEN_MSIN         (1U)
#define sDltCfg_d_HDR_LEN_NOAR         (1U)
#define sDltCfg_d_HDR_LEN_APID         (4U)
#define sDltCfg_d_HDR_LEN_CTID         (4U)

/* define max length for header (std + ext) */
#define sDltCfg_d_HDR_LEN_MAX          (26U)

/* define length if service id */
#define sDltCfg_d_HDR_LEN_SID          (4U)

/* define necessary standard header length needed to evaluate the incoming header */
#define sDltCfg_d_HDR_LEN_STD          (sDltCfg_d_HDR_LEN_HTYP + sDltCfg_d_HDR_LEN_MCNT + sDltCfg_d_HDR_LEN_LEN + sDltCfg_d_HDR_LEN_ECUID)
/* define necessary extended header length needed to evaluate the incoming header */
#define sDltCfg_d_HDR_LEN_EXT          (sDltCfg_d_HDR_LEN_MSIN + sDltCfg_d_HDR_LEN_NOAR + sDltCfg_d_HDR_LEN_APID + sDltCfg_d_HDR_LEN_CTID)

/* -------------------------------------------------------------------------- */
/**
 * ECUC_Dlt_00806 - DltEcuId
 * This is the name of the ECU for use within the Dlt protocol. The meaning is described
 * in the document. This name is transmitted within the Dlt protocol. There this are 4
 * characters. If you want to use an number representation type this as character.
 */
/*lint -save -e960 */
#ifdef ME_PLATFORM_QNX
#define sDltCfg_D_ECUID "QNX"
#elif defined(ME_PLATFORM_WIN)
#define sDltCfg_D_ECUID "WIN"
#elif defined(ME_PLATFORM_LINUX)
#define sDltCfg_D_ECUID "LNX"
#else
#define sDltCfg_D_ECUID "N/A"
#endif

/* number of PDUs available */
#define sPdu_D_PDU_NUMBER_OF_PDU    (2U)

/* define PDU length */
#define sPdu_D_PDU_LENGTH_MAX       (4095U)


#define sBufReq_D_E_NOT_OK  (1U)

/* define source of time stamp */
/* TODO - ugl see MeclTypes.h, typedef "unsigned int" instead
   of "unsigned long" for "uint32_t"- (0x12345678U) */
#define sDltCfg_d_GET_TIME_STAMP (0x1234U)


/* define Channel for sending buffers */
#define sDltCfg_d_SEND_CHANNEL    (4U)

/* -------------------------------------------------------------------------- */
/**
 * 8.4.1.2 - Dlt_GetVersionInfo - [SWS_Dlt_00271]
 */
/* define DLT version information */
#define sDltCfg_d_INSTANCE_ID          (1U)
#define sDltCfg_d_MODULE_ID            (20U)
#define sDltCfg_d_MAJOR_VERSION        (0U)
#define sDltCfg_d_MINOR_VERSION        (1U)
#define sDltCfg_d_PATCH_VERSION        (0U)
#define sDltCfg_d_VENDOR_ID            (0x42U)

/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */
/**
 * ECUC_Dlt_00840 - DltDevErrorDetect
 * Enables/Disables development error detection.
 */
/*#undef sDltCfg_d_DEV_ERROR_DETECT*/
#ifndef sDltCfg_d_DEV_ERROR_DETECT
/*#define sDltCfg_D_DEV_ERROR_DETECT STD_ON*/
#endif

/**
 * ECUC_Dlt_00815 - DltImplementAppIdContextIdQuery
 * If set the functionality for Verbose Mode shall be available.
 */
#define sDltCfg_D_IMPLEMENT_APPID_CONTEXTID_QUERY STD_ON
/*#undef sDltCfg_D_IMPLEMENT_APPID_CONTEXTID_QUERY*/

/**
 * ECUC_Dlt_00821 - DltImplementVerboseMode
 * If set the functionality for Verbose Mode shall be available.
 */
#define sDltCfg_D_IMPLEMENT_VERBOSE_MODE STD_ON
/*#undef sDltCfg_D_IMPLEMENT_VERBOSE_MODE*/

/**
 * ECUC_Dlt_00816 - DltImplementExtendedHeader
 * If set the extended functionality for the header shall be available.
 */
#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
#define sDltCfg_D_IMPLEMENT_EXTENDED_HEADER STD_ON
#else
#define sDltCfg_D_IMPLEMENT_EXTENDED_HEADER STD_ON
/*#undef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER*/
#endif

/**
 * ECUC_Dlt_00817 - DltImplementFilterMessages
 * This flag is for code generation of Dlt. If set the functionality for filtering
 * messages shall be included in the code.
 */
#define sDltCfg_D_IMPLEMENT_FILTER_MESSAGES STD_ON
/*#undef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES*/

/**
 * ECUC_Dlt_00818 - DltImplementNVRamStorage
 * If set the functionality for storing and loading information in and from NVRam
 * shall be available.
 */
#define sDltCfg_D_IMPLEMENT_NVRAM_STORAGE STD_ON
/*#undef sDltCfg_D_IMPLEMENT_NVRAM_STORAGE*/

/**
 * ECUC_Dlt_00819 - DltImplementSWCInjection
 * If the remote call from functions over the Dlt in SW-C shall be available.
 */
#define sDltCfg_D_IMPLEMENT_SWC_INJECTION STD_ON
/*#undef sDltCfg_D_IMPLEMENT_SWC_INJECTION*/

/**
 * ECUC_Dlt_00820 - DltImplementTimestamp
 * If set the timestamp functionality for the header shall be available.
 */
#define sDltCfg_D_IMPLEMENT_TIME_STAMP STD_ON
/*#undef sDltCfg_D_IMPLEMENT_TIME_STAMP*/

/**
 * ECUC_Dlt_00822 - DltImplementVfbTrace
 * If set the the header files and the implementation of VFB-trace shall be
 * generated.
 */
/*#define sDltCfg_D_IMPLEMENT_VFB_TRACE STD_ON*/
#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
  #undef sDltCfg_D_IMPLEMENT_VFB_TRACE
#endif

/**
 * ECUC_Dlt_00844 - DltVersionInfoApi
 * Pre-processor switch for enabling Version Info API support.
 * True: version information API activated
 * False: version information API deactivated
 */
/*#define sDltCfg_d_VERSION_INFO_API STD_ON*/
#define sDltCfg_D_VERSION_INFO_API STD_OFF

/**
 * ECUC_Dlt_00841 - DltGptChannel
 * Reference to the hardware free running timer of the GPT module for time
 * stamps (if no HWFRT is applied, calls to add timestamps are ignored).
 */
#define sDltCfg_d_GPT_CHANNEL sDltCfg_d_GET_TIME_STAMP

/**
 * ECUC_Dlt_00823 - DltInitBufferSize
 * Buffer size for the C-init buffer. This buffer is for storing messages from
 * other BSW modules before Dlt is initialized. Unit: byte
 * range: 0 .. 4294967295
 */
#define sDltCfg_d_INIT_BUFFER_SIZE (0U)

/**
 * ECUC_Dlt_00824 - DltMaxCountAppIds
 * The maximum count of registerable Application Ids. There shall be a table
 * to manage registered Application IDs, this is the number of lines to hold in
 * this table. Unit: byte
 * range: 1 .. 4294967295
 */
/* define for a large number of application and context Ids - four table implementation */
/*#define sDltCfg_d_MAX_COUNT_APPIDS (1) - currently two table implementation used*/
/* define for a small number of application and context Ids - two table implementation */
#define sDltCfg_d_MAX_COUNT_APPIDS (20U)

/**
 * ECUC_Dlt_00825 - DltMaxCountContextIds
 * The maximum count of registerable Context Ids. There shall be a table to
 * manage registered Context IDs, this is the number of lines to hold in this
 * table. Unit: byte
 * range: 1 .. 4294967295
 */
/* define for small and large number of application and context Ids */
#define sDltCfg_d_MAX_COUNT_CONTEXTIDS (1U)

/**
 * ECUC_Dlt_00826 - DltMaxCountContextIdsPerAppId
 * Each Context ID belongs to a specific Application ID. Dlt shall handle the
 * correlation between them. The table of the registered Application IDs shall
 * hold for every Application ID several references to the proper Context IDs.
 * This is the maximum count for Context IDs per Application ID. Unit: byte
 * range: 1 .. 4294967295
 */
/* define for a large number of application and context Ids - four table implementation */
/*#define sDltCfg_d_MAX_COUNT_CONTEXTIDS_PER_APPID - currently two table implementation used*/

/**
 * ECUC_Dlt_00829 - DltMessageBufferSize
 * Buffer size for storing Dlt messages for waiting to transmit over the
 * Network (send buffer). Unit: byte
 * range: 0 .. 4294967295
 */
#define sDltCfg_d_MESSAGE_BUFFER_SIZE (0U)

/**
 * ECUC_Dlt_00838 - DltVfbTraceFunction
 * The Dlt generator shall enable VFB tracing for a given hook function when
 * there is a #define in the Dlt-VFB configuration header file for the hook
 * function name and tracing is globally enabled.
 * Example: #define Dlt_Rte WriteHook i1 p1 a Start. Also the corresponding
 * function shall be generated. The exact argument description for the
 * function is to take from the provided BSWModudulDescription from the
 * RTE module.
 */
/*#define sDltCfg_d_VFB_TRACE_FUNCTION STD_ON*/
#ifdef sDltCfg_d_VFB_TRACE_FUNCTION
  #undef sDltCfg_d_VFB_TRACE_FUNCTION
#endif

/**
 * ECUC_Dlt_00804 - DltBswModuleEntryRef
 * Foreign reference to the BSWModuleEntry describing the trace function
 * implementation.
 */
/*#define sDltCfg_d_BSW_MODULE_ENTRY_REF STD_ON*/
#ifdef sDltCfg_d_BSW_MODULE_ENTRY_REF
  #undef sDltCfg_d_BSW_MODULE_ENTRY_REF
#endif


/**
 * ECUC_Dlt_00831 - DltNvRamBlockRef
 * Reference to the NvM Block which is used to store the Dlt parameters.
 */
/*#define sDltCfg_d_NVRAM_BLOCK_REF STD_ON*/
#ifdef sDltCfg_d_NVRAM_BLOCK_REF
  #undef sDltCfg_d_NVRAM_BLOCK_REF
#endif

/**
 * ECUC_Dlt_00835 - DltTimePeriodTrafficShaping
 * For implementing a traffic shaping, a time window for measuring shall be
 * provided. Unit: second
 * range: 0 .. INF
 */
#define sDltCfg_d_TIME_PERIOD_TRAFFIC_SHAPING (0U)

/**
 * ECUC_Dlt_00807 - DltFactoryDefaultMaxLogLevel
 * The maximum log level a received message (from SW-C to Dlt) can have. This is for
 * setting DltDefaultMaxLogLevel to factory defaults. The value 0 means logging is
 * disabled.
 * ImplementationType: sDlt_s_MessageLogLevel_t
 * range: 0 .. 6
 */
#define sDltCfg_d_FACTORY_DEFAULT_MAX_LOG_LEVEL (6U)

/**
 * ECUC_Dlt_00810 - DltHeaderPayloadEndianes
 * Determines the endianess of the CPU (Most Significant Byte).
 */
#define sDltCfg_d_HEADER_PAYLOAD_ENDIANES sDltCfg_D_BIG_ENDIAN

/**
 * ECUC_Dlt_00827 - DltMaxMessageLength
 * The maximum length of a Dlt log or trace message.
 * range: 8 .. 65535
 */
#define sDltCfg_d_MAX_MESSAGE_LENGTH (128U)

/* -------------------------------------------------------------------------- */

#define sDltCfg_d_PDU_LENGTH_OF_PDU       (sDltCfg_d_MAX_MESSAGE_LENGTH)

#define sDltCfg_d_CTRL_RESPONSE_BUFFER_SZ       (sDltCfg_d_PDU_LENGTH_OF_PDU - sDltCfg_d_HDR_LEN_MAX)
#define sDltCfg_d_CTRL_SWC_INJECTION_BUFFER_SZ  (32U)

/* non-Autosar configuration values */
/* PDU related configurations */
#define sDltPdu_d_MAX_PDU_LEN  sPdu_D_PDU_LENGTH_MAX

/* the pdu buffer pool used by DLT */
#define sDltPdu_d_DltBufferPool (0U)

#define ECU_SW_VER (26U)

/* --- Public Function Declarations ------------------------------------------------ */


/* --------------------------------------------------------------------------------- */
#endif /* DLT_CFG_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlt_cfg.h */


