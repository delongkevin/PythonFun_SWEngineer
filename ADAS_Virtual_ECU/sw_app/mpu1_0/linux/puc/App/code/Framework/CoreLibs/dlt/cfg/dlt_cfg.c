/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltCfg
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Configuration and interface functions for Dlt
 * ======================================================================== */

//#include "dlt_env.h"
//#include "dlt_cfg.h"
//#include "dlt/dlt_types.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* define default configuration for DLT */
//const sDlt_s_Config_t sDltCfg_C_Config_s =
//{
//    10000U,                                   /* BandwidthForDiagChannel_u32 */
//    10000U,                                   /* BandwidthForComModule_u32 */
//    FALSE,                                   /* HeaderUseEcuId_b */
//    FALSE,                                   /* HeaderUseSessionId_b */
//    FALSE,                                   /* DefaultTraceStatus_b */
//    sDltCfg_D_LOG_ERROR,  /* DefaultLogLevel_u8 */
//
//    /* ECUC_Dlt_00836 - dependency: Can only be true if DltImplementVerboseMode is true. */
//#ifdef sDltCfg_D_IMPLEMENT_VERBOSE_MODE
//    !FALSE,                                   /* HeaderUseVerboseMode_b */
//#else
//    FALSE,                                    /* HeaderUseVerboseMode_b */
//#endif
//#ifdef sDltCfg_D_IMPLEMENT_EXTENDED_HEADER
//    !FALSE,                                   /* HeaderUseExtendedHeader_b */
//#endif
//#ifdef sDltCfg_D_IMPLEMENT_FILTER_MESSAGES
//    !FALSE,                                   /* FilterMessages_b */
//#endif
//#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
//    FALSE,                                   /* HeaderUseTimestamp_b */
//#endif
//#ifdef sDltCfg_D_IMPLEMENT_TIME_STAMP
//    FALSE,                                   /* SendCyclicTimestamp_b */
//#endif
//#ifdef sDltCfg_D_IMPLEMENT_VFB_TRACE
//    6U,                                       /* VfbTraceLogLevel_u8 */
//#endif
//};

/**
 * 7.7.7.1.24 - Get ECU Software Version - [SWS_Dlt_00393]
 */
/* define the software version string */
//const u8 sDltCfg_C_SoftwareVersionString_u8 [ECU_SW_VER] = {
//    "DLT test software version"
//};

/*lint -restore */

/* -------------------------------------------------------------------------- */
