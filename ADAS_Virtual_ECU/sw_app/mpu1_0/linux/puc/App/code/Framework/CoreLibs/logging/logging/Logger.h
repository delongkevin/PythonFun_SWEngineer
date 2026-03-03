//--------------------------------------------------------------------------
/// @file Logger.h
/// @brief Provides an interface to all existing logging mechanisms

/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGGER_H_
#define LOGGER_H_

#include "cfg/LogTypes.h"

#include <osal/networking/SocketClient.h>

#include <stdarg.h> // needed for va_list

namespace logging
{
typedef va_list va_list_t;

class Logger
{
public:
  Logger();

  virtual ~Logger();

  // Function for configuration of the own Logger instance
  bool_t        config_b(LogLevel_e i_LogLevel_e, const char_t* i_AppId_pc, const char_t* i_ContextId_pc, uint32_t i_LogModeMask_u32);

  // PRQA S 2012 1 // log functions have an unlimited number of parameters by design
  bool_t        log_b(LogLevel_e i_LogLevel_e, const char_t* i_Fmt_pc, ...) const;

  bool_t        isLogLvlEnabled_b(LogLevel_e i_LogLevel_e) const;

  /// Empty default implementation
  bool_t        logImg_b(LogLevel_e i_LogLevel_e,
                         const uint8_t* i_Img_pu8, uint32_t i_ImgBitDepth_u32,
                         uint16_t i_ImgWidth_u16, uint16_t i_ImgHeight_u16) const;

  /// Empty default implementation
  bool_t        logBin_b(LogLevel_e i_LogLevel_e, const uint8_t* i_Bin_pu8,
                                             uint32_t i_BinaryDataLength_u32) const;

public:

  static void   init_v();

  static void   init_v(LogLevel_t i_DefaultLogLevel_t, uint32_t i_DefaultLogModeMask_u32);

  // PRQA S 2012 1 // log functions have an unlimited number of parameters by design
  static bool_t log_b(LogLevel_e i_LogLevel_e, uint32_t i_LogModeMask_u32, const char_t* i_Fmt_pc, ...);

  static void   setDefaultLogLevel_v(LogLevel_e i_LogLevel_e);

  /// ----------------------------------------------------------------------------------------------------

  static LogLevel_t      getDefaultLogLevel_t() { return s_DefaultLogLevel_t; }

  static uint32_t        getDefaultAppId_u32() { return s_DefaultAppId_u32; }

  static uint32_t        getDefaultContextId_u32() { return s_DefaultContextId_u32; }

private:

  static LogHeader_t     createLogHeader_t(uint32_t i_AppId_u32, uint32_t i_ContextId_u32, uint8_t i_LogLevel_u8);

  static bool_t          isLogModeActive_b(uint32_t i_LogModeMask_e);

  static uint32_t        assembleLog_v(const char_t* i_Fmt_pc, va_list_t b_ArgList_pt,
                                       char_t* o_OutputBuf_pc, uint32_t i_OutputBufLen_u32);

  static bool_t          dispatchLog_u32(uint32_t i_LogModeMask_u32, LogHeader_t& i_LogHeader_rt, const char_t* i_Fmt_pc, va_list_t b_ArgList_pt);

private:

  // non static members

  uint32_t  logMode_u32;

  uint32_t  logLevel_u32;

  uint32_t  appId_u32;

  uint32_t  contextId_u32;

private:

  // static members

  static bool_t                 s_InitDone_b;
                                
  static uint64_t               s_StartupTimeStamp_u64;
                                
  // Mutex to avoid accessing data with two processes or threads simultaniously
  static Mutex_s                s_Mutex_s;
                                
  // Mode mask for static log function call
  static uint32_t               s_DefaultModeMask_u32;
                                
  // Log level for static log function call
  static LogLevel_t             s_DefaultLogLevel_t;
                                
  // App Id for static log function call
  static uint32_t               s_DefaultAppId_u32;
                                
  // Context Id for static log function call
  static uint32_t               s_DefaultContextId_u32;
                                
  //                            
  static uint32_t               s_ActiveModeMask_u32;

  static LogHandle_s            s_LogHandles_as[e_LogModeCount];

  static osal::SocketClient     s_SocketClients_ao[e_LogModeCount];
};

} // namspace logging

#endif /* LOGGING_LOGSENDERBASE_H_ */

