
//--------------------------------------------------------------------------
/// @file IpcCom_Rtos.cpp
/// @brief Implementation of IpcCom
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (Ananda.Kavrady@Magna.com)
///
//  --------------------------------------------------------------------------

#include "bsp/driver/IpcCom.h"
#include <osal/networking/INetworkMsgHandler.h>


namespace bsp
{

#ifdef ME_PLATFORM_RTOS

IpcCom::IpcCom()
  : INetwork()
  , iccomHandle_t()
  , channelId_u8(0)
  , msgHandler_po(NULL)
  , status_e(e_Closed)
{
}
IpcCom::~IpcCom()
{
}

void IpcCom::registerHandler_v(INetworkMsgHandler* b_Handler_po)
{
  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

}//END registerHandler_v()

bool_t IpcCom::process_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;

}//END process_b()

void IpcCom::shutdown_v()
{
}//END shutdown_v()

bool_t IpcCom::send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}//END send_v()

void IpcCom::init_v(uint8_t i_ChannelId_u8)
{
  channelId_u8 = i_ChannelId_u8;
}

bool_t IpcCom::open_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

// ==========================================================================
// Inlines
// ==========================================================================
inline bool_t IpcCom::isOpened_b() const
{
  return ( e_Opened == status_e );
}

inline bool_t IpcCom::isClosed_b() const
{
  return ( e_Closed == status_e );
}

inline bool_t IpcCom::isFailed_b() const
{
  return ( e_SendFailed == status_e );
}


#endif // ME_PLATFORM_RTOS

} // namespace bsp






