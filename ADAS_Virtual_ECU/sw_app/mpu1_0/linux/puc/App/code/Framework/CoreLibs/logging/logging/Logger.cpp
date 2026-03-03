//--------------------------------------------------------------------------
/// @file LogSenderBase.cpp
/// @brief Contains a base implementation for ILogSender.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "Logger.h"

#include <osal/io/File.h>

namespace logging
{

bool_t             Logger::s_InitDone_b = false;

uint64_t           Logger::s_StartupTimeStamp_u64 = 0;

Mutex_s            Logger::s_Mutex_s;

uint32_t           Logger::s_DefaultModeMask_u32  = (e_LogModeMaskDlt | e_LogModeMaskPrintf); // PRQA S 3710 // masking with enums necessary here

LogLevel_t         Logger::s_DefaultLogLevel_t    = logging::e_LogLvlInfo;

uint32_t           Logger::s_ActiveModeMask_u32   = 0x00000000U;

uint32_t           Logger::s_DefaultAppId_u32     = 0x00000000U;

uint32_t           Logger::s_DefaultContextId_u32 = 0x00000000U;

LogHandle_s        Logger::s_LogHandles_as[e_LogModeCount];

osal::SocketClient Logger::s_SocketClients_ao[e_LogModeCount];

Logger::Logger()
  : logMode_u32(0U)
  , logLevel_u32(0U)
  , appId_u32(s_DefaultAppId_u32)
  , contextId_u32(s_DefaultContextId_u32)
{
  if(s_StartupTimeStamp_u64 == 0)
  {
    ME_Time_GetTimeUsec_t(&s_StartupTimeStamp_u64);

    // Resolution 100 micro seconds
    s_StartupTimeStamp_u64 /= 100;
  }
}

Logger::~Logger()
{
}

// initialize the static containers 
void Logger::init_v()
{
  SocketHandle_t v_Socket_t; 
  ME_Mutex_Init_t(&s_Mutex_s, true);

  s_DefaultAppId_u32 = ME_Platform_F_MakeFourCC_u32("DEF");
  s_DefaultContextId_u32 = ME_Platform_F_MakeFourCC_u32("RUN");
#if 0 //disabling socket communication for production software
  s_SocketClients_ao[e_LogModeDlt].init_b(e_SptTcp, "127.0.0.1", logging::s_LogPorts_pu32[e_LogModeDlt]);
  SocketHandle_t v_Socket_t = s_SocketClients_ao[e_LogModeDlt].getSocketHandle_t();

  if (ME_Socket_IsValid_b(&v_Socket_t) == true)
  {
    s_ActiveModeMask_u32 |= static_cast<uint32_t>(e_LogModeMaskDlt);
  }

  s_SocketClients_ao[e_LogModePrintf].init_b(e_SptTcp, "127.0.0.1", logging::s_LogPorts_pu32[e_LogModePrintf]);
  v_Socket_t = s_SocketClients_ao[e_LogModePrintf].getSocketHandle_t();

  if (ME_Socket_IsValid_b(&v_Socket_t) == true)
  {
    s_ActiveModeMask_u32 |= static_cast<uint32_t>(e_LogModeMaskPrintf);
  }
#endif
#ifdef ME_PLATFORM_WIN
  ME_Mutex_UnLock_t(&s_Mutex_s);
#endif

  s_InitDone_b = true;
}

void Logger::init_v(LogLevel_t i_DefaultLogLevel_t, uint32_t i_DefaultLogModeMask_u32)
{
  s_DefaultLogLevel_t = i_DefaultLogLevel_t;
  s_DefaultModeMask_u32 = i_DefaultLogModeMask_u32;

  init_v();
}

// PRQA S 3080 ++ // va_start and va_end necessary here
// PRQA S 3902 ++ // va_start and va_end necessary here
bool_t Logger::log_b(LogLevel_e i_LogLevel_e, uint32_t i_LogModeMask_u32, const char_t* i_Fmt_pc, ...)
{
  bool_t    v_Result_b = true;
  
  #if 1 //Pradeep
	return v_Result_b;
#endif	
  va_list_t v_Args_pt;


  if(s_InitDone_b == true)
  {
    va_start(v_Args_pt, i_Fmt_pc);

    if (static_cast<uint32_t>(i_LogLevel_e) >= static_cast<uint32_t>(s_DefaultLogLevel_t))
    {
      LogHeader_t v_LogHeader_t = createLogHeader_t(s_DefaultAppId_u32, s_DefaultContextId_u32, s_DefaultLogLevel_t);
      if (0 == dispatchLog_u32(i_LogModeMask_u32, v_LogHeader_t, i_Fmt_pc, v_Args_pt))
      {
        v_Result_b = false;
      }
    }

    va_end(v_Args_pt);
  }

  return v_Result_b;
}

void Logger::setDefaultLogLevel_v(LogLevel_e i_LogLevel_e)
{
  s_DefaultLogLevel_t = i_LogLevel_e;
}
// PRQA S 3080 --
// PRQA S 3902 --

bool_t Logger::config_b(LogLevel_e i_LogLevel_e, const char_t* i_AppId_pc, const char_t* i_ContextId_pc, uint32_t i_LogModeMask_u32)
{
  bool_t v_Result_b = true;
  
  logMode_u32 = i_LogModeMask_u32;
  logLevel_u32 = i_LogLevel_e;

  memcpy(&appId_u32, i_AppId_pc, sizeof(uint32_t));

//  appId_u32 = ((appId_u32 & 0x000000FFU) << 24)|
//              ((appId_u32 & 0x0000FF00U) << 8) |
//              ((appId_u32 & 0x00FF0000U) >> 8) |
//              ((appId_u32 & 0xFF000000U) >> 24);

  memcpy(&contextId_u32, i_ContextId_pc, sizeof(uint32_t));

//  contextId_u32 = ((contextId_u32 & 0x000000FFU) << 24)|
//                  ((contextId_u32 & 0x0000FF00U) << 8) |
//                  ((contextId_u32 & 0x00FF0000U) >> 8) |
//                  ((contextId_u32 & 0xFF000000U) >> 24);

  return v_Result_b;
}

// PRQA S 3080 ++ // va_start and va_end necessary here
// PRQA S 3902 ++ // va_start and va_end necessary here

// Log a message, with a given LogLevel, using the configured logHandle
bool_t Logger::log_b(LogLevel_e i_LogLevel_e, const char_t* i_Fmt_pc, ...) const
{
  bool_t v_Result_b = true;
  va_list_t v_Args_pt;
#if 1 //Pradeep
	return v_Result_b;
#endif	
  if(s_InitDone_b == true)
  {
    va_start(v_Args_pt, i_Fmt_pc);

    if(true == isLogLvlEnabled_b(i_LogLevel_e))
    {
      LogHeader_t v_LogHeader_t = createLogHeader_t(appId_u32, contextId_u32, i_LogLevel_e);
      if(0 == dispatchLog_u32(logMode_u32, v_LogHeader_t, i_Fmt_pc, v_Args_pt))
      {
        v_Result_b = false;
      }
    }
    else
    {
      v_Result_b = false;
    }

    va_end(v_Args_pt);
  }

  return v_Result_b;
}


// PRQA S 3080 --
// PRQA S 3902 --

// Compares the given LogLevel with the configured one
// If the given LogLevel is within the configured "range", logging output is enabled
bool_t Logger::isLogLvlEnabled_b(LogLevel_e i_LogLevel_e) const
{
  bool_t v_Result_b = false;

  if(static_cast<uint32_t>(i_LogLevel_e) >= logLevel_u32)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

// Logging a image
bool_t Logger::logImg_b(LogLevel_e i_LogLevel_e,
                        const uint8_t* i_Img_pu8, uint32_t i_ImgBitDepth_u32,
                        uint16_t i_ImgWidth_u16, uint16_t i_ImgHeight_u16) const
{
  // TODO: not (yet) implemented
  bool_t v_Result_b = true;
  
  if(isLogLvlEnabled_b(i_LogLevel_e) == true)
  {
    size_t v_ImgSize_t = (i_ImgWidth_u16 * i_ImgHeight_u16) * (i_ImgBitDepth_u32/8);

    if(true == isLogModeActive_b(logging::e_LogModeMaskDlt))
    {
      v_Result_b = s_SocketClients_ao[logging::e_LogModeDlt].send_b(reinterpret_cast<const uint8_t*>(i_Img_pu8), v_ImgSize_t);
    }
  }
  else
  {
    // module not initialized
    v_Result_b = false;
  }

  return v_Result_b;
}

// Logging binary data
bool_t Logger::logBin_b(LogLevel_e i_LogLevel_e, const uint8_t* i_Bin_pu8, uint32_t i_BinaryDataLength_u32) const
{
  bool_t v_Result_b = true;
  // not (yet) implemented

  if ((i_BinaryDataLength_u32 < logging::ME_MAX_LOG_LENGTH) && (isLogLvlEnabled_b(i_LogLevel_e) == true))
  {
    uint32_t v_LogMode_u32 = 0;
    for (uint32_t v_I_u32 = 0; v_I_u32 < 32; v_I_u32++)
    {
      v_LogMode_u32 = 0x1 << v_I_u32;
      if (((logMode_u32 & v_LogMode_u32) >> v_I_u32) == 0x1U)
      {
        if (true == isLogModeActive_b(v_LogMode_u32))
        {
          v_Result_b = s_SocketClients_ao[v_I_u32].send_b(reinterpret_cast<const uint8_t*>(i_Bin_pu8), i_BinaryDataLength_u32);
        }
      }
    }
  }
  else
  {
    // module not initialized
    v_Result_b = false;
  }

  return v_Result_b;
}

LogHeader_t Logger::createLogHeader_t(uint32_t i_AppId_u32, uint32_t i_ContextId_u32, uint8_t i_LogLevel_u8)
{
  uint64_t v_Timestamp_u64 = 0;

  LogHeader_t v_Result_t = {0, i_AppId_u32, i_ContextId_u32, static_cast<uint32_t>((v_Timestamp_u64 / 100) & 0x00000000FFFFFFFFU), i_LogLevel_u8};

  return v_Result_t;
}


bool_t Logger::isLogModeActive_b(uint32_t i_LogModeMask_e)
{
  bool_t v_Result_t = false;
  if ((s_ActiveModeMask_u32 & i_LogModeMask_e) != 0x0U)
  {
    v_Result_t = true;
  }

  return v_Result_t;
}


// Building the message string with all given (...) parameters
uint32_t Logger::assembleLog_v(const char_t* i_Fmt_pc, va_list_t b_ArgList_pt,
                               char_t* o_OutputBuf_pc, uint32_t i_OutputBufLen_u32)
{
  return ME_String_Vsnprintf_s32(&o_OutputBuf_pc[0], i_OutputBufLen_u32, i_Fmt_pc, b_ArgList_pt); // PRQA S 3706 // using subscript operator necessary here
}


// Decides on the configured logHandle_t which registered Logger should be used for output the logging message
bool_t Logger::dispatchLog_u32(uint32_t i_LogModeMask_u32, LogHeader_t& i_LogHeader_rt, const char_t* i_Fmt_pc, va_list_t b_ArgList_pt)
{
  bool_t v_Result_b = true;
  char_t v_OutputBuffer_ac[sizeof(LogHeader_t) + logging::ME_MAX_LOG_LENGTH];

  uint64_t v_Timestamp_u64 = 0;
  ME_Time_GetTimeUsec_t(&v_Timestamp_u64);

  // Resolution 100 micro seconds
  v_Timestamp_u64 /= 100;

  // Calculate the time since startup
  v_Timestamp_u64 -= s_StartupTimeStamp_u64;

  // Place the time stamp into the log header
  i_LogHeader_rt.Timestamp_u32 = static_cast<uint32_t>((v_Timestamp_u64) & 0x00000000FFFFFFFFU);

  ME_Mutex_Lock_t(&s_Mutex_s);

  memcpy(&v_OutputBuffer_ac[0], &i_LogHeader_rt, sizeof(LogHeader_t));

  uint32_t v_LogLength_u32 = assembleLog_v(i_Fmt_pc, b_ArgList_pt, &v_OutputBuffer_ac[sizeof(LogHeader_t)], logging::ME_MAX_LOG_LENGTH); // PRQA S 3706 // using subscript operator necessary here

  v_LogLength_u32 += sizeof(LogHeader_t);
  v_OutputBuffer_ac[v_LogLength_u32] = '\0';
  v_LogLength_u32++;

  memcpy(&v_OutputBuffer_ac[0], &v_LogLength_u32, sizeof(uint32_t));

#ifdef USE_SLOG2_FOR_OUTPUT
  uint32_t v_lastChar_u32 = v_LogLength_u32 - sizeof(LogHeader_t);
  char v_lastChar_c = v_OutputBuffer_ac[sizeof(LogHeader_t) + v_lastChar_u32 - 1];

  if( v_lastChar_c == '\n')
  {
	v_OutputBuffer_ac[sizeof(LogHeader_t) + v_lastChar_u32 - 1] = '\0';
  }	

  ME_Debugger_F_Printf_v("%10lld %s", v_Timestamp_u64, &v_OutputBuffer_ac[sizeof(LogHeader_t)]);
#endif
  
#if 0
    // Print the time stamp
    ME_Debugger_F_Printf_v("%10lld ", v_Timestamp_u64);

    // Print that part of the buffer which is behind the log header
    // only use printf on console, if printf-logging is deactivated
    ME_Debugger_F_Printf_v(&v_OutputBuffer_ac[sizeof(LogHeader_t)]); // PRQA S 3706 // using subscript operator necessary here

    // Add a line feed if it was not already printed
    uint32_t v_lastChar_u32 = v_LogLength_u32 - sizeof(LogHeader_t);
    char v_lastChar_c = v_OutputBuffer_ac[sizeof(LogHeader_t) + v_lastChar_u32 - 1];

    if( v_lastChar_c != '\n')
    {
      ME_Debugger_F_Printf_v("\n");
    }
#endif


  for(uint32_t v_I_u32 = 0; v_I_u32 < ME_MAX_LOGMODES; v_I_u32++)
  {
    uint32_t v_LogMode_u32 = 0x1U << v_I_u32;
    if(((i_LogModeMask_u32 & v_LogMode_u32) >> v_I_u32) == 0x1U)
    {
      if ((v_I_u32 < e_LogModeCount) && (true == isLogModeActive_b(v_LogMode_u32)))
      {
        v_Result_b = s_SocketClients_ao[v_I_u32].send_b(reinterpret_cast<const uint8_t*>(v_OutputBuffer_ac), v_LogLength_u32);
      }
    }
  }
  
  ME_Mutex_UnLock_t(&s_Mutex_s);
  
  return v_Result_b;
}


} // namespace logging

