//--------------------------------------------------------------------------
/// @file ICCOMServer.cpp
/// @brief Class implementation of Iccom server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Farzad Safa (Farzad.Safa@partner.magna.com)
///
//  --------------------------------------------------------------------------


// ==========================================================================
// Includes
// ==========================================================================
#include "bsp/driver/Iccom.h"
#include "osal/networking/INetworkMsgHandler.h"

namespace bsp
{


#ifdef ME_PLATFORM_LINUX

// --------------------------------------------------------------------------
// Class ICCOMServer
// --------------------------------------------------------------------------
Iccom::Iccom()
  : INetwork()
  , iccomHandle_t()
  , channelId_u8(0)
  , msgHandler_po(NULL)
  , status_e(e_Closed)
{
  (void)memset(&receiveBuffer_ac[0], 0, sizeof(receiveBuffer_ac));
}//END ICCOMServer()

Iccom::~Iccom()
{
}//END ~ICCOMServer()

void Iccom::registerHandler_v(INetworkMsgHandler* b_Handler_po)
{
  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

}//END registerHandler_v()

bool_t Iccom::process_b()
{
  bool_t v_Result_b = true;

  size_t v_NumBytesReceived_t = 0;
  PlatformError_t v_Error_t = e_PeInvalid;

  if(isOpened_b() == true)
  {
    v_NumBytesReceived_t = read(iccomHandle_t, &receiveBuffer_ac[0], sizeof(receiveBuffer_ac));

    if(e_PeOk != v_Error_t)
    {
      shutdown_v();
      v_Result_b = false;
    }

    // we've successfully received a message
    if( v_Result_b == true )
    {
      // received message is non-empty
      if( v_NumBytesReceived_t > 0 )
      {
        // just drop the message if no handler is registered yet
        if( NULL != msgHandler_po )
        {
          msgHandler_po->onReceive_v(this, reinterpret_cast<uint8_t*>(&receiveBuffer_ac[0]), v_NumBytesReceived_t);
        }
      }
    }
  }
  else
  {
    ME_Thread_Sleep_t(500);
    shutdown_v();
    open_b();
  }

  return v_Result_b;

}//END process_b()

void Iccom::shutdown_v()
{
  (void)close(iccomHandle_t);

  status_e = e_Closed;
}//END shutdown_v()

bool_t Iccom::send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = isOpened_b();

  if(v_Result_b == true)
  {
    size_t v_NumBytesSent_t = 0;

    v_NumBytesSent_t = write(iccomHandle_t, b_Buffer_pu8, i_BufferLength_t);

    if(v_NumBytesSent_t < 0)
    {
      status_e = e_SendFailed;
    }

    if(v_NumBytesSent_t != i_BufferLength_t)
    {
      v_Result_b = false;
    }
  }

  return v_Result_b;
}//END send_v()

void Iccom::init_v(uint8_t i_ChannelId_u8)
{
  channelId_u8 = i_ChannelId_u8;
}

bool_t Iccom::open_b()
{
  bool_t v_Result_b = true;
  sint32_t v_Flags_s32 = O_RDWR;

  char_t v_Path_ac[64];
  (void)sprintf(v_Path_ac, "/dev/iccom/%d", channelId_u8);

  iccomHandle_t = open(&v_Path_ac[0], v_Flags_s32);

  if( iccomHandle_t < 0 )
  {
    status_e = e_Closed;

    v_Result_b = false;
  }
  else
  {
    status_e = e_Opened;
  }

  return v_Result_b;
}

// ==========================================================================
// Inlines
// ==========================================================================
inline bool_t Iccom::isOpened_b() const
{
  return ( e_Opened == status_e );
}

inline bool_t Iccom::isClosed_b() const
{
  return ( e_Closed == status_e );
}

inline bool_t Iccom::isFailed_b() const
{
  return ( e_SendFailed == status_e );
}


#endif // ME_PLATFORM_LINUX

} // namespace bsp
