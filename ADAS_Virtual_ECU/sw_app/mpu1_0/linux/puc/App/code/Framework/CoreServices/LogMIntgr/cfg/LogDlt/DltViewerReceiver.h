//--------------------------------------------------------------------------
/// @file DltViewerReceiver.h
/// @brief Receiving incoming messages from DltViewer tool
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef DLT_VIEWER_RECEIVER_H_
#define DLT_VIEWER_RECEIVER_H_

#include <cfg/dlt_cfg.h>
#include <dlt/dlt_types.h>
#include <dlt/dlthdr.h>

#include "LogDlt.h"

namespace logm
{

struct DltHeader_s
{
  uint8_t   headerType_u8;
  uint8_t   messageCount_u8;
  uint16_t  length_u16;
};

struct DltResponseHeader_s
{
  uint8_t   headerType_u8;
  uint8_t   messageCount_u8;
  uint16_t  length_u16;
  uint8_t   optionalIds_au8[12];
};

struct DltExtendedHeader_s
{
  uint8_t messageInfo_u8;
  uint8_t numOfArguments_u8;
  uint8_t appId_au8[4];
  uint8_t conId_au8[4];
};


class DltViewerReceiver : public osal::INetworkMsgHandler
{
public:

  DltResponseHeader_s createResponseHeader_s(uint32_t i_EcuId_u32, uint32_t i_SessionId_u32, uint32_t i_Timestamp_u32,
                                             bool_t i_HasExtendedHeader_b, bool_t i_MsbFirst_b, 
                                             bool_t i_HasEcuId_b, bool_t i_HasSessionId_b, bool_t i_HasTimestamp_b,
                                             uint16_t& b_Length_u16, uint8_t i_MessageCount_u8, uint16_t& o_OptionalLength_ru16)
  {
    DltResponseHeader_s v_Result_s;

    v_Result_s.headerType_u8 = i_HasExtendedHeader_b << 0;
    v_Result_s.headerType_u8 |= i_MsbFirst_b          << 1;
    v_Result_s.headerType_u8 |= i_HasEcuId_b          << 2;
    v_Result_s.headerType_u8 |= i_HasSessionId_b      << 3;
    v_Result_s.headerType_u8 |= i_HasTimestamp_b      << 4;

    uint8_t v_Offset_u8 = 0;
    if(i_HasEcuId_b == true)
    {
      memcpy(&v_Result_s.optionalIds_au8[v_Offset_u8], &i_EcuId_u32, sizeof(i_EcuId_u32));
      v_Offset_u8 += sizeof(i_EcuId_u32);
    }

    if(i_HasSessionId_b == true)
    {
      memcpy( &v_Result_s.optionalIds_au8[v_Offset_u8], &i_SessionId_u32, sizeof(i_SessionId_u32));
      v_Offset_u8 += sizeof(i_SessionId_u32);
    }

    if(i_HasTimestamp_b == true)
    {
      memcpy(&v_Result_s.optionalIds_au8[v_Offset_u8], &i_Timestamp_u32, sizeof(i_Timestamp_u32));
      v_Offset_u8 += sizeof(i_Timestamp_u32);
    }

    v_Result_s.messageCount_u8 = i_MessageCount_u8;
    v_Result_s.length_u16 = ME_Platform_F_EndianSwap_u16(b_Length_u16);

    b_Length_u16 += v_Offset_u8;
    o_OptionalLength_ru16 = v_Offset_u8;

    return v_Result_s;
  }

  DltExtendedHeader_s createExtendedHeader_s(uint32_t i_AppId_u32, uint32_t i_ContextId_u32, bool_t i_Verbose_b,
                                             uint8_t i_MessageType_u8, uint8_t i_MessageTypeInfo_u8, uint8_t i_NumberOfArguments_u8)
  {
    DltExtendedHeader_s v_Result_s;

    v_Result_s.messageInfo_u8 = i_Verbose_b << 0;
    v_Result_s.messageInfo_u8 |= i_MessageType_u8 << 1;
    v_Result_s.messageInfo_u8 |= i_MessageTypeInfo_u8 << 4;

    memcpy(v_Result_s.appId_au8, &i_AppId_u32, sizeof(v_Result_s.appId_au8));
    memcpy(v_Result_s.conId_au8, &i_ContextId_u32, sizeof(v_Result_s.conId_au8));

    v_Result_s.numOfArguments_u8 = i_NumberOfArguments_u8;

    return v_Result_s;
  }


  void handleHeader_v(const DltHeader_s* i_Header_ps, const uint8_t* i_Payload_pu8)
  {
    uint8_t v_EcuId_au8[4];
    uint8_t v_SessionId_au8[4];
    uint8_t v_Timestamp_au8[4];

    uint16_t v_Offset_u16 = 0U;

    bool_t v_HasExtendedHeader_rb = ((i_Header_ps->headerType_u8 & sDltCfg_D_HTYP_UEH) >> 0);
    bool_t v_MSBFirst_rb          = ((i_Header_ps->headerType_u8 & sDltCfg_D_HTYP_MSBF) >> 1);
    bool_t v_HasEcuId_rb          = ((i_Header_ps->headerType_u8 & sDltCfg_D_HTYP_WEID) >> 2);
    bool_t v_HasSessionId_rb      = ((i_Header_ps->headerType_u8 & sDltCfg_D_HTYP_WSID) >> 3);
    bool_t v_HasTimestamp_rb      = ((i_Header_ps->headerType_u8 & sDltCfg_D_HTYP_WTMS) >> 4);

    if (v_HasEcuId_rb == true)
    {
      memcpy(&v_EcuId_au8, &i_Payload_pu8[v_Offset_u16], sizeof(v_EcuId_au8));
      v_Offset_u16 += sizeof(v_EcuId_au8);
    }

    if (v_HasSessionId_rb == true)
    {
      memcpy(&v_SessionId_au8, &i_Payload_pu8[v_Offset_u16], sizeof(v_SessionId_au8));
      v_Offset_u16 += sizeof(v_SessionId_au8);
    }

    if (v_HasTimestamp_rb == true)
    {
      memcpy(&v_Timestamp_au8, &i_Payload_pu8[v_Offset_u16], sizeof(v_Timestamp_au8));
      v_Offset_u16 += sizeof(v_Timestamp_au8);
    }

    const DltExtendedHeader_s* v_ExtHeader_ps = reinterpret_cast<const DltExtendedHeader_s*>(&i_Payload_pu8[v_Offset_u16]);
    v_Offset_u16 += sizeof(DltExtendedHeader_s);

    if (v_HasExtendedHeader_rb == true)
    {
      handleExtHeader_v(v_ExtHeader_ps, &i_Payload_pu8[v_Offset_u16]);
    }
  }

  void handleExtHeader_v(const DltExtendedHeader_s* i_ExtHeader_ps, const uint8_t* i_Payload_pu8)
  {
    bool_t v_Verbose_b = false;
    uint8_t v_MessageType_u8 = 0;
    uint8_t v_MessageTypeInfo_u8 = 0;

    v_Verbose_b          = (i_ExtHeader_ps->messageInfo_u8 & 0x1U);
    v_MessageType_u8     = (i_ExtHeader_ps->messageInfo_u8 & 0xeU) >> 1U;
    v_MessageTypeInfo_u8 = (i_ExtHeader_ps->messageInfo_u8 & 0xf0U) >> 4U;

    uint16_t v_Offset_u16 = 0;

    switch(v_MessageType_u8)
    {
    case sDltCfg_D_TYPE_LOG:
      {
        handleLogMessage_v(v_MessageTypeInfo_u8);
        break;
      }
    case sDltCfg_D_TYPE_APP_TRACE:
      {
        handleTraceMessage_v(v_MessageTypeInfo_u8);
        break;
      }
    case sDltCfg_D_TYPE_NW_TRACE:
      {
        handleNetworkMessage_v(v_MessageTypeInfo_u8);
        break;
      }
    case sDltCfg_D_TYPE_CONTROL:
      {
        handleControlMessage_v(v_MessageTypeInfo_u8, &i_Payload_pu8[0]);
        break;
      }
    default:
      break;
    }
  }

  void handleLogMessage_v(uint8_t i_MessageTypeInfo_u8)
  {
    switch(i_MessageTypeInfo_u8)
    {

    }
  }

  void handleTraceMessage_v(uint8_t i_MessageTypeInfo_u8)
  {
    switch(i_MessageTypeInfo_u8)
    {

    }
  }

  void handleNetworkMessage_v(uint8_t i_MessageTypeInfo_u8)
  {
    switch(i_MessageTypeInfo_u8)
    {

    }
  }

  void handleControlMessage_v(uint8_t i_MessageTypeInfo_u8, const uint8_t* i_Payload_pu8)
  {
    switch(i_MessageTypeInfo_u8)
    {
    case sDltCfg_D_CONTROL_REQUEST:
    {
      uint32_t v_MessageId_u32 = 0x00U;
      memcpy(&v_MessageId_u32, i_Payload_pu8, sizeof(uint32_t));
      handleControlRequest_v(v_MessageId_u32, &i_Payload_pu8[sizeof(uint32_t)]);
      break;
    }
    case sDltCfg_D_CONTROL_RESPONSE:
    {
      break;
    }
    default:
      break;
    }
  }

  void handleControlRequest_v(uint32_t i_MessageId_u8, const uint8_t* i_Payload_pu8)
  {
    switch (i_MessageId_u8)
    {
    case sDltCfg_D_SID_SET_LOG_LEVEL:
    {
      const sDlt_s_SetLogLevelRequest_t* v_SetLogLevelRequest_t = reinterpret_cast<const sDlt_s_SetLogLevelRequest_t*>(i_Payload_pu8);

      break;
    }
    case sDltCfg_D_SID_SET_DEFAULT_LOG_LEVEL:
    {
      const sDlt_s_SetDefaultLogLevelRequest_t* v_SetLogLevelRequest_t = reinterpret_cast<const sDlt_s_SetDefaultLogLevelRequest_t*>(i_Payload_pu8);

      logging::Logger::setDefaultLogLevel_v(LogDlt::getPlatformLoglevel_u8(v_SetLogLevelRequest_t->NewLogLevel_u8));
      break;
    }
    case sDltCfg_D_SID_GET_DEFAULT_LOG_LEVEL:
    {
      uint8_t v_ResponseBuffer_au8[64];

      uint16_t v_Length_u16 = sizeof(DltHeader_s) 
                            + sizeof(DltExtendedHeader_s) 
                            + sizeof(sDlt_s_GetDefaultLogLevelResponse_t);
      uint16_t v_OptLenght_u16 = 0;

      uint32_t v_EcuId_u32 = ME_Platform_F_MakeFourCC_u32(sDltCfg_D_ECUID);
      DltResponseHeader_s v_ResponseHeader_s    = createResponseHeader_s(v_EcuId_u32, 1, 0, true, true, true, false, false, v_Length_u16, 0, v_OptLenght_u16);
      DltExtendedHeader_s v_ResponseExtHeader_s = createExtendedHeader_s(logging::Logger::getDefaultAppId_u32(),
                                                                         logging::Logger::getDefaultContextId_u32(),
                                                                         false, sDltCfg_D_TYPE_CONTROL, sDltCfg_D_CONTROL_RESPONSE, 1);
      sDlt_s_GetDefaultLogLevelResponse_s v_Payload_s;
      v_Payload_s.Status_u8 = sDltCfg_D_E_NOT_OK;
      v_Payload_s.LogLevel_u8 = LogDlt::getDltLoglevel_u8(logging::Logger::getDefaultLogLevel_t());

      uint8_t v_Offset_u8 = 0;
      memcpy(&v_ResponseBuffer_au8[v_Offset_u8], &v_ResponseHeader_s, sizeof(v_ResponseHeader_s) - sizeof(v_ResponseHeader_s.optionalIds_au8) + v_OptLenght_u16);
      v_Offset_u8 += sizeof(v_ResponseHeader_s) - sizeof(v_ResponseHeader_s.optionalIds_au8) + v_OptLenght_u16;

      memcpy(&v_ResponseBuffer_au8[v_Offset_u8], &v_ResponseExtHeader_s, sizeof(v_ResponseExtHeader_s));
      v_Offset_u8 += sizeof(v_ResponseExtHeader_s);

      memcpy(&v_ResponseBuffer_au8[v_Offset_u8], &v_Payload_s, sizeof(v_Payload_s));

      network_po->send_b(v_ResponseBuffer_au8, v_Length_u16);

      break;
    }
    default:
      break;
    }
  }

  virtual void onReceive_v(osal::INetwork * i_NetworkInterface_po, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
  {
    uint16_t v_MessageOffset_u16 = 0;

    network_po = i_NetworkInterface_po;

    uint8_t tmp[256];
    memcpy(tmp, b_Buffer_pu8, i_BufferLength_t);

    while(v_MessageOffset_u16 < i_BufferLength_t)
    {
      DltHeader_s* v_Header_ps = reinterpret_cast<DltHeader_s*>(&b_Buffer_pu8[v_MessageOffset_u16]);
      v_Header_ps->length_u16 = ME_Platform_F_EndianSwap_u16(v_Header_ps->length_u16);
      handleHeader_v(v_Header_ps, &b_Buffer_pu8[sizeof(DltHeader_s)]);

      v_MessageOffset_u16 = v_Header_ps->length_u16;
    }
  }

  private:

    osal::INetwork* network_po;
};

}

#endif // DLT_VIEWER_RECEIVER_H_

