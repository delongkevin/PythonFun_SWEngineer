//--------------------------------------------------------------------------
/// @file LogPrintf.h
/// @brief
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#include "LogDlt.h"

#include <osal/system/Time.h>

// PRQA S 1021 EOF // literals are used

namespace logm
{

osal::INetwork* LogDlt::s_LogInterface_ro = NULL;

LogDlt::LogDlt(mecl::buffer::IBuffer& i_Buffer_ro)
  : LogBase(i_Buffer_ro)
  , processThread_o(NULL)
{
}

LogDlt::~LogDlt()
{
}

void LogDlt::onInit_v()
{
  sDltApp_F_Init_v();
  sDltCom_F_Init_v();

  sDltCom_F_RegisterSendBufferFunc_v(reinterpret_cast<sDltCom_F_SendBuffer_t>(sendBuffer_b));

  if(s_LogInterface_ro != NULL)
  {
    processThread_o.setInterface_v(s_LogInterface_ro);
    processThread_o.start_v(&processThread_o);
  }

  while(processThread_o.getIsActive_b() == false)
  {
    ME_Thread_Sleep_t(100);
  }
}

bool_t LogDlt::processLogMsg_b(const logging::LogHeader_t* i_LogHeader_pt)
{
  bool_t v_Result_b = false;
  
  while (processThread_o.getIsActive_b() == false)
  {
    ME_Thread_Sleep_t(100);
  }

  if(i_LogHeader_pt != NULL)
  {
    v_Result_b = true;

    sDltApp_s_LogContext_t v_LogMsgContext_t;

    uint32_t v_AppId_u32 = ME_Platform_F_EndianSwap_u32(i_LogHeader_pt->AppId_u32);
    uint32_t v_ContextId_u32 = ME_Platform_F_EndianSwap_u32(i_LogHeader_pt->ContextId_s32);

    sDltApp_F_RegisterContext(v_AppId_u32, v_ContextId_u32);

    sDlt_F_setLogLevel_u8(v_AppId_u32, v_ContextId_u32, getDltLoglevel_u8(static_cast<logging::LogLevel_t>(i_LogHeader_pt->LogLevel_u8)));

    sDlt_s_Return_t v_ErrCode_u8 = sDltApp_F_StartLogMessage(&v_LogMsgContext_t,
                                                             i_LogHeader_pt->Timestamp_u32,
                                                             v_AppId_u32,
                                                             v_ContextId_u32,
                                                             getDltLoglevel_u8(static_cast<logging::LogLevel_t>(i_LogHeader_pt->LogLevel_u8)));

    if ((sDltCfg_D_E_OK == v_ErrCode_u8) || (sDltCfg_D_E_MESSAGE_FILTERED == v_ErrCode_u8))
    {
      const char_t* v_Payload_pc = reinterpret_cast<const char_t*>(i_LogHeader_pt);
      // add the message, strings are supported only at the moment
      v_ErrCode_u8 = sDltApp_F_AddPayloadString(&v_LogMsgContext_t, &v_Payload_pc[sizeof(logging::LogHeader_t)], 0); // PRQA S 3706 // must remove header from payload string
      // check if the message is larger than our buffer
      if(sDltCfg_D_E_MSG_TOO_LARGE == v_ErrCode_u8)
      {
        v_ErrCode_u8 = sDltApp_F_AddPayloadString(&v_LogMsgContext_t, "Msg too long", 0);
      }
    }

    if (sDltCfg_D_E_OK == v_ErrCode_u8)
    {
      // finalize the message and send it to dlt buffer
      v_ErrCode_u8 = sDltApp_F_EndLogMessage(&v_LogMsgContext_t);
    }

    if (sDltCfg_D_E_OK != v_ErrCode_u8)
    {
      if (sDltCfg_D_E_IF_NOT_AVAILABLE == v_ErrCode_u8)
      {
        osal::Time v_Time_o;
        static uint64_t v_LastWarned_u64 = v_Time_o.getTimeMsec_u64();
        if ((v_Time_o.getTimeMsec_u64() - v_LastWarned_u64) > 1000UL)
        {
          v_LastWarned_u64 = v_Time_o.getTimeMsec_u64();
        }
      }
      else
      {
      }
    }
  }

  return v_Result_b;
}

void LogDlt::onCleanup_v()
{

}

bool_t LogDlt::send_b(uint8_t i_PduId_u8)
{
  sDltPdu_s_PduInfo_t* v_PduPtr_ps;

  bool_t v_Return_b = true;
  if(E_OK != sDltPdu_F_PduIdToPtr_t(i_PduId_u8, &v_PduPtr_ps))
  {
    v_Return_b = false;
  }

  if(v_Return_b == true)
  {
    if(s_LogInterface_ro != NULL)
    {
      v_Return_b = s_LogInterface_ro->send_b(v_PduPtr_ps->PduData_pu8, v_PduPtr_ps->IsoTpDataLen_u16);

      sDltCom_F_txConfirmation_v(v_PduPtr_ps, v_PduPtr_ps->IsoTpDataLen_u16);
    }
  }

  return v_Return_b;
}

uint8_t LogDlt::getDltLoglevel_u8(logging::LogLevel_t i_CommonLogLevel_e)
{
  uint8_t v_DltLogLevel_u8 = sDltCfg_D_LOG_OFF;

  switch (i_CommonLogLevel_e)
  {
    case logging::e_LogLvlFatal:
    {
      v_DltLogLevel_u8 = sDltCfg_D_LOG_FATAL;
      break;
    }
    case logging::e_LogLvlError:
    {
      v_DltLogLevel_u8 = sDltCfg_D_LOG_ERROR;
      break;
    }
    case logging::e_LogLvlWarning:
    {
      v_DltLogLevel_u8 = sDltCfg_D_LOG_WARN;
      break;
    }
    case logging::e_LogLvlInfo:
    {
      v_DltLogLevel_u8 = sDltCfg_D_LOG_INFO;
      break;
    }
    case logging::e_LogLvlDebug:
    {
      v_DltLogLevel_u8 = sDltCfg_D_LOG_DEBUG;
      break;
    }
    case logging::e_LogLvlVerbose:
    {
      v_DltLogLevel_u8 = sDltCfg_D_LOG_VERBOSE;
      break;
    }
    default:
    {
      break;
    }
  }

  return v_DltLogLevel_u8;
}

logging::LogLevel_t LogDlt::getPlatformLoglevel_u8(uint8_t i_CommonLogLevel_u8)
{
  logging::LogLevel_t v_DltLogLevel_e = logging::e_LogLvlDisable;

  switch (i_CommonLogLevel_u8)
  {
  case sDltCfg_D_LOG_FATAL:
    {
      v_DltLogLevel_e = logging::e_LogLvlFatal;
      break;
    }
  case sDltCfg_D_LOG_ERROR:
    {
      v_DltLogLevel_e = logging::e_LogLvlError;
      break;
    }
  case sDltCfg_D_LOG_WARN:
    {
      v_DltLogLevel_e = logging::e_LogLvlWarning;
      break;
    }
  case sDltCfg_D_LOG_INFO:
    {
      v_DltLogLevel_e = logging::e_LogLvlInfo;
      break;
    }
  case sDltCfg_D_LOG_DEBUG:
    {
      v_DltLogLevel_e = logging::e_LogLvlDebug;
      break;
    }
  case sDltCfg_D_LOG_VERBOSE:
    {
      v_DltLogLevel_e = logging::e_LogLvlVerbose;
      break;
    }
  default:
    {
      break;
    }
  }

  return v_DltLogLevel_e;
}

uint8_t LogDlt::sendBuffer_b(uint8_t i_Channel_u8, const sDltPdu_s_PduInfo_t *i_TxBuffer_ps)
{
  bool_t v_RV_b = false;
  const uint8_t c_ChannelID_u8 = 4; /* channelID is set from DLT but not used in this implementaton*/

  if(i_Channel_u8 == c_ChannelID_u8)
  {
      v_RV_b = send_b(i_TxBuffer_ps->PduId_t);
  }

  return v_RV_b;
}

void LogDlt::setLogInterface_v(osal::INetwork* i_LogInterface_po)
{
  s_LogInterface_ro = i_LogInterface_po;
}

} // namespace logm
