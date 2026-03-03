//--------------------------------------------------------------------------
/// @file ME_Socket_WIN.c
/// @brief Windows implementation for standard-library Sockets
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

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

#define _WINSOCK_DEPRECATED_NO_WARNINGS

// stdlib header include
#include "platform/stdlib/ME_Socket.h"
#include "platform/stdlib/ME_Assert.h"

static const uint32_t c_SocketBufferSize_u32 = MAX_SOCKET_SIZE;

PlatformError_t ME_Socket_Startup_t(void)
{
  WSADATA v_WsaData_t;
  PlatformError_t v_Error_t = e_PeOk;

  // Initiate the use of the winsock dll
  if (WSAStartup(MAKEWORD(2, 2), &v_WsaData_t) != 0)
  {
    v_Error_t = ME_GetPlatformError_t(-1);
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Cleanup_t(void)
{
  PlatformError_t v_Error_t = e_PeOk;

  // Must be called for each WSAStartup call
  if (WSACleanup() == SOCKET_ERROR)
  {
    v_Error_t = ME_GetPlatformError_t(-1);
  }

  return v_Error_t;
}

void ME_Socket_Init_v(SocketHandle_t* b_Socket_pt)
{
  b_Socket_pt->socket_t = ME_INVALID_SOCKET;
  b_Socket_pt->isNonBlocking_u32 = 0;
}

PlatformError_t ME_Socket_Create_t(SocketHandle_t* b_Socket_pt, SocketProtocolType_t i_Protocol_e, bool_t i_Blocking_b)
{
  PlatformError_t v_Error_t = e_PeOk;

  switch (i_Protocol_e)
  {
    case e_SptTcp:
    {
      b_Socket_pt->socket_t = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    }
    break;
    case e_SptUdp:
    {
      b_Socket_pt->socket_t = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    }
    break;
  }

  if (b_Socket_pt->socket_t == INVALID_SOCKET)
  {
    v_Error_t = e_PeInvalid;
  }
  else
  {
    if (true == i_Blocking_b)
    {
      b_Socket_pt->isNonBlocking_u32 = 0;
    }
    else
    {
      b_Socket_pt->isNonBlocking_u32 = 1;
    }

    // Set non-blocking mode
    if (ioctlsocket(b_Socket_pt->socket_t, FIONBIO, &b_Socket_pt->isNonBlocking_u32) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      Assert(false);
    }
    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Shutdown_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (b_Socket_pt->socket_t != INVALID_SOCKET)
  {
    if (shutdown(b_Socket_pt->socket_t, SD_BOTH) == SOCKET_ERROR)
    {
      v_Error_t = ME_GetPlatformError_t(-1);
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Close_t(SocketHandle_t* i_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (i_Socket_pt->socket_t != INVALID_SOCKET)
  {
    if (closesocket(i_Socket_pt->socket_t) == SOCKET_ERROR)
    {
      v_Error_t = ME_GetPlatformError_t(-1);
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }

  ME_Socket_Init_v(i_Socket_pt);

  return v_Error_t;
}

PlatformError_t ME_Socket_Bind_t(const SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t = e_PeOk;
  struct sockaddr_in v_LocalAddress_s;
  HOSTENT* v_Host_pt;

  if (b_Socket_pt->socket_t != INVALID_SOCKET)
  {
    v_LocalAddress_s.sin_family = AF_INET;
    v_LocalAddress_s.sin_port   = htons(i_Port_s32);

    if (NULL != i_Address_pc)
    {
      v_LocalAddress_s.sin_addr.s_addr = inet_addr(i_Address_pc);

      if (v_LocalAddress_s.sin_addr.s_addr == INADDR_NONE)
      {
        v_Host_pt = gethostbyname(i_Address_pc);

        if (v_Host_pt)
        {
          v_LocalAddress_s.sin_addr.s_addr = ((IN_ADDR*)v_Host_pt->h_addr)->s_addr;
        }
      }
    }
    else
    {
      v_LocalAddress_s.sin_addr.s_addr = INADDR_ANY;
    }

    if (bind(b_Socket_pt->socket_t, (SOCKADDR*)&v_LocalAddress_s, sizeof(v_LocalAddress_s)) == SOCKET_ERROR)
    {
      v_Error_t = ME_GetPlatformError_t(-1);
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Listen_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;
  BOOL v_DisableNagle_b = 1;

  if (INVALID_SOCKET != b_Socket_pt->socket_t)
  {
    if (listen((SOCKET)b_Socket_pt->socket_t, SOMAXCONN) == SOCKET_ERROR)
    {
      v_Error_t = ME_GetPlatformError_t(WSAGetLastError());
      Assert(e_PeOk == v_Error_t);
    }

    // Set non-blocking mode
    if (ioctlsocket(b_Socket_pt->socket_t, FIONBIO, &b_Socket_pt->isNonBlocking_u32) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      Assert(false);
    }

    // Disable Nagle algorithm for TCP connections
    if (setsockopt(b_Socket_pt->socket_t, IPPROTO_TCP, TCP_NODELAY, (char_t*)&v_DisableNagle_b, sizeof(v_DisableNagle_b)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      Assert(false);
    }

    // Set the size of the internal receive buffer
    if (setsockopt(b_Socket_pt->socket_t, SOL_SOCKET, SO_RCVBUF, (char_t*)&c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      Assert(false);
    }

    // Set the size of the internal send buffer
    if (setsockopt(b_Socket_pt->socket_t, SOL_SOCKET, SO_SNDBUF, (char_t*)&c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      Assert(false);
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Accept_t(SocketHandle_t* b_Socket_pt, SocketHandle_t* b_AcceptedSocket_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (INVALID_SOCKET != b_Socket_pt->socket_t)
  {
    b_AcceptedSocket_pt->socket_t = accept(b_Socket_pt->socket_t, NULL, NULL);

    if (b_AcceptedSocket_pt->socket_t == INVALID_SOCKET)
    {
      // send again, unix does this, too if we didn't accept a valid socket if nonblocking mode is set
      v_Error_t = e_PeAgain;
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Connect_t(SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t = e_PeOk;
  struct sockaddr_in v_RemoteAddress_s;
  HOSTENT* v_Host_pt;
  BOOL v_DisableNagle_b = 1;

  if (INVALID_SOCKET != b_Socket_pt->socket_t)
  {
    v_RemoteAddress_s.sin_family      = AF_INET;
    v_RemoteAddress_s.sin_port        = htons(i_Port_s32);
    v_RemoteAddress_s.sin_addr.s_addr = i_Address_pc != NULL ? inet_addr(i_Address_pc) : INADDR_NONE;

    if (v_RemoteAddress_s.sin_addr.s_addr == INADDR_NONE)
    {
      v_Host_pt = gethostbyname(i_Address_pc);
      if (v_Host_pt)
      {
        v_RemoteAddress_s.sin_addr.s_addr = ((IN_ADDR*)v_Host_pt->h_addr)->s_addr;
      }
    }

    if (connect(b_Socket_pt->socket_t, (SOCKADDR*)&v_RemoteAddress_s, sizeof(v_RemoteAddress_s)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      v_Error_t = e_PeFault;
    }

    // Set non-blocking mode
    if (ioctlsocket(b_Socket_pt->socket_t, FIONBIO, &b_Socket_pt->isNonBlocking_u32) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      v_Error_t = e_PeFault;
    }

    // Disable Nagle algorithm for TCP connections
    if (setsockopt(b_Socket_pt->socket_t, IPPROTO_TCP, TCP_NODELAY, (char*)&v_DisableNagle_b, sizeof(v_DisableNagle_b)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      v_Error_t = e_PeFault;
    }

    // Set the size of the internal receive buffer
    if (setsockopt(b_Socket_pt->socket_t, SOL_SOCKET, SO_RCVBUF, (char*)&c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      v_Error_t = e_PeFault;
    }

    // Set the size of the internal send buffer
    if (setsockopt(b_Socket_pt->socket_t, SOL_SOCKET, SO_SNDBUF, (char*)&c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32)) == SOCKET_ERROR)
    {
      // TODO: Handle different error codes
      v_Error_t = e_PeFault;
    }
  }

  return v_Error_t;
}

/// Receives data from a connected socket or a bound connection less socket
PlatformError_t ME_Socket_Receive_t(SocketHandle_t* b_Socket_pt, char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesReceived_pt)
{
  sint32_t v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  *b_NumBytesReceived_pt = 0;

  if (ME_INVALID_SOCKET != b_Socket_pt->socket_t)
  {
    // receive and check result
    v_Result_s32 = recv(b_Socket_pt->socket_t, (char_t*)b_Buffer_pc, i_BufferLength_t, 0);

    // check if error occured
    if (0 == v_Result_s32)
    {
      v_Error_t = e_PeConnAborted;
    }
    else if (SOCKET_ERROR == v_Result_s32)
    {
      v_Result_s32 = WSAGetLastError();
      if (v_Result_s32 == WSAEWOULDBLOCK)
      {
        // Blocking socket, no error here
        v_Error_t = e_PeOk;
      }
      else if((v_Result_s32 == WSAECONNRESET) || (v_Result_s32 == WSAECONNABORTED) || (v_Result_s32 == WSAEINTR))
      {
        v_Error_t = e_PeConnAborted;
      }
      else
      {
        // some error occurred that we didn't handle
        v_Error_t = e_PeInvalid;
      }

      *b_NumBytesReceived_pt = 0;
    }
    else
    {
      // no error occurred, we received some bytes.
      *b_NumBytesReceived_pt = (size_t)v_Result_s32;
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

/// Sends data on the specified connected socket
PlatformError_t ME_Socket_Send_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt)
{
  PlatformError_t v_Error_t = e_PeOk;
  struct fd_set v_SocketSet_s;
  struct timeval v_Timeout_s;
  sint32_t v_Result_s32;
  *b_NumBytesSent_pt = 0;

  if (INVALID_SOCKET != b_Socket_pt->socket_t)
  {
    v_SocketSet_s.fd_count    = 1;
    v_SocketSet_s.fd_array[0] = b_Socket_pt->socket_t;

    v_Timeout_s.tv_sec  = 0;
    v_Timeout_s.tv_usec = 0;

    v_Result_s32 = select(0, NULL, &v_SocketSet_s, NULL, NULL);

    if (v_Result_s32 == SOCKET_ERROR || v_Result_s32 == 0)
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      *b_NumBytesSent_pt = send(b_Socket_pt->socket_t, (const char_t*)b_Buffer_pc, i_BufferLength_t, 0);

      if (*b_NumBytesSent_pt == SOCKET_ERROR)
      {
        v_Error_t = e_PeFault;
      }
    }
  }

  return v_Error_t;
}

/// Sends data on the specified connected socket using the remote address
PlatformError_t ME_Socket_Send_t_ToDest_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt, const char_t* i_RemoteIP_pc, sint32_t i_DestPort_s32)
{
  PlatformError_t v_Error_t = e_PeOk;
  struct fd_set v_SocketSet_s;
  struct timeval v_Timeout_s;
  sint32_t v_Result_s32;

  struct sockaddr_in RemoteAddr;

  RemoteAddr.sin_family = AF_INET;
  RemoteAddr.sin_addr.s_addr = inet_addr(i_RemoteIP_pc);
  RemoteAddr.sin_port = htons(i_DestPort_s32);

  *b_NumBytesSent_pt = 0;

  if (INVALID_SOCKET != b_Socket_pt->socket_t)
  {
    v_SocketSet_s.fd_count = 1;
    v_SocketSet_s.fd_array[0] = b_Socket_pt->socket_t;

    v_Timeout_s.tv_sec = 0;
    v_Timeout_s.tv_usec = 0;

    v_Result_s32 = sendto(b_Socket_pt->socket_t, b_Buffer_pc, i_BufferLength_t, 0, (SOCKADDR*)&RemoteAddr, sizeof(RemoteAddr));
    if (v_Result_s32 == SOCKET_ERROR || v_Result_s32 == 0)
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      *b_NumBytesSent_pt = v_Result_s32;
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

bool_t ME_Socket_IsValid_b(const SocketHandle_t* i_Socket_pt)
{
  return (i_Socket_pt->socket_t != ME_INVALID_SOCKET);
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
