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
#include <osal/networking/INetworkMsgHandler.h>

namespace bsp
{


#ifdef ME_PLATFORM_RTOS

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

bool_t Iccom::registerHandler_b(osal::INetworkMsgHandler* b_Handler_po)
{
  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

  return true;
}//END registerHandler_v()

bool_t Iccom::process_b()
{
  bool_t v_Result_b = true;
  return v_Result_b;

}//END process_b()

void Iccom::shutdown_v()
{
}//END shutdown_v()

bool_t Iccom::send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}//END send_v()

void Iccom::init_v(uint8_t i_ChannelId_u8)
{
  channelId_u8 = i_ChannelId_u8;
}

bool_t Iccom::open_b()
{
  bool_t v_Result_b = true;
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


#endif // ME_PLATFORM_AUTOSAR

} // namespace bsp
