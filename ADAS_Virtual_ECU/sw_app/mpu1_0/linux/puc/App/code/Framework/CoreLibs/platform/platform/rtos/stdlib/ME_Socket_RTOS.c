/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
//--------------------------------------------------------------------------

/// @file ME_Socket_AUTOSAR.c
/// @brief AUTOSAR implementation for standard-library Socket
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

#include "platform/stdlib/ME_Socket.h"
#include "platform/stdlib/ME_Assert.h"

static const uint32_t c_SocketBufferSize_u32 = MAX_SOCKET_SIZE;

PlatformError_t ME_Socket_Startup_t(void)
{
  // not needed in qnx
  return e_PeOk;
}
PlatformError_t ME_Socket_Cleanup_t(void)
{
  // not needed in qnx
  return e_PeOk;
}

void ME_Socket_Init_v(SocketHandle_t* b_Socket_pt)
{
}

/// Creates a new socket with the specified protocol type
PlatformError_t ME_Socket_Create_t(SocketHandle_t* b_Socket_pt, SocketProtocolType_t i_Protocol_e, bool_t i_Blocking_b)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Shutdown_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

/// Closes the specified socket and frees all allocated data
PlatformError_t ME_Socket_Close_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Bind_t(const SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Listen_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Accept_t(SocketHandle_t* b_Socket_pt, SocketHandle_t* b_AcceptedSocket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Connect_t(SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Receive_t(SocketHandle_t* b_Socket_pt, char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesReceived_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Send_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Socket_Send_t_ToDest_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt, const char_t* i_RemoteIP_pc, sint32_t i_DestPort_s32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

bool_t ME_Socket_IsValid_b(const SocketHandle_t* i_Socket_pt)
{
  return (i_Socket_pt != NULL);
}


#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined

