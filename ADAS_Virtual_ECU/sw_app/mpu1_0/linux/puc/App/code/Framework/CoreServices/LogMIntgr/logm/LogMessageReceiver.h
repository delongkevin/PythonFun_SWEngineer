//--------------------------------------------------------------------------
/// @file LogMessageReceiver.h
/// @brief Class, responsible to handle received messages by application
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------


#ifndef LOG_MESSAGE_RECEIVER_H_
#define LOG_MESSAGE_RECEIVER_H_

#include <osal/networking/INetworkMsgHandler.h>
#include <osal/system/Time.h>

#include <cfg/LogTypes.h>

namespace logm
{

class LogMessageReceiver : public osal::INetworkMsgHandler
{
public:

  LogMessageReceiver(LogBase& i_LogBase_ro)
    : logBase_ro(i_LogBase_ro)
    , tmpBufferIdx_u32(0U)
  {

  }

  virtual void onReceive_v(osal::INetwork * i_NetworkInterface_po, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
  {
    i_NetworkInterface_po = i_NetworkInterface_po;
    logBase_ro.log_b(b_Buffer_pu8, i_BufferLength_t);
  }

private:

  LogBase& logBase_ro;

  uint8_t tmpBuffer_au8[4096U];
  uint32_t tmpBufferIdx_u32;

};

}

#endif // LOG_MESSAGE_RECEIVER_H_
