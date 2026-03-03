//--------------------------------------------------------------------------
/// @file LogTypes.h
/// @brief Contains definition of a base implementation of ILogSender.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGTYPES_H
#define LOGTYPES_H

#include <platform/PlatformAPI.h>

namespace logging
{

  typedef struct LogHeader_s
  {
    uint32_t Size_u32;
    uint32_t AppId_u32;
    uint32_t ContextId_s32;
    uint32_t Timestamp_u32;
    uint8_t  LogLevel_u8;
  } LogHeader_t;

  typedef enum LogLevel_e {
    e_LogLvlVerbose = 0,
    e_LogLvlDebug, 
    e_LogLvlInfo, 
    e_LogLvlWarning,
    e_LogLvlError, 
    e_LogLvlFatal,
    e_LogLvlDisable
  } LogLevel_t;

  typedef enum LogMode_e
  {
    e_LogModeDlt = 0,
    e_LogModePrintf,
    e_LogModeCount,
    e_LogModeInvalid
  } LogMode_t;

  // PRQA S 3710 ++ // To create the mask, we have to do it like that. But be aware to define the first enum-entry with 0
  typedef enum LogModeMask_e
  {
    e_LogModeMaskPrintf = (1 << e_LogModePrintf),
    e_LogModeMaskDlt    = (1 << e_LogModeDlt),
    e_LogModeMaskAll    = e_LogModeMaskPrintf | e_LogModeMaskDlt
  } LogModeMask_t;
  // PRQA S 3710 --


  const uint32_t ME_MAX_LOGMODES = 32U;

  const uint32_t ME_INVALID_REG_ID = static_cast<uint32_t>(-1);

  const uint32_t ME_MAX_LOG_LENGTH = 1024U;

  const uint32_t ME_MAX_LOG_BUFFER_SIZE = 10U * ME_MAX_LOG_LENGTH;

  extern const uint32_t s_LogPorts_pu32[e_LogModeCount];

}

#endif /* LOGTYPES_H */
