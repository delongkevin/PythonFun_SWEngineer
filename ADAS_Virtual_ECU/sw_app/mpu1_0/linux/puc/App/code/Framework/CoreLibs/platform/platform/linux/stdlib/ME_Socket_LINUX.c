//--------------------------------------------------------------------------
/// @file ME_Socket_QNX.c
/// @brief Linux implementation for standard-library Socket
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

#include "platform/stdlib/ME_Socket.h"
#include "platform/stdlib/ME_Assert.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

// stdlib header include

#include <sys/select.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

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
  if(NULL != b_Socket_pt)
  {
    b_Socket_pt->socketHandle_s32 = ME_INVALID_SOCKET;
    b_Socket_pt->isBlocking_b = true;
  }
  else
  {
    /* do nothing */
  }
}

/// Creates a new socket with the specified protocol type
PlatformError_t ME_Socket_Create_t(SocketHandle_t* b_Socket_pt, SocketProtocolType_t i_Protocol_e, bool_t i_Blocking_b)
{
  PlatformError_t v_Error_t;

  if (NULL == b_Socket_pt)
  {
    // set invalid parameter error if socket is null
    v_Error_t = e_PeInvalid;
  }
  else
  {
    switch (i_Protocol_e)
    {
      case e_SptTcp:
        {
          b_Socket_pt->socketHandle_s32 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        }
        break;
      case e_SptUdp:
        {
          b_Socket_pt->socketHandle_s32 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        }
        break;
      default:
        b_Socket_pt->socketHandle_s32 = ME_INVALID_SOCKET;
        break;
    }

    if (b_Socket_pt->socketHandle_s32 == ME_INVALID_SOCKET)
    {
      v_Error_t = ME_GetPlatformError_t(ME_INVALID_SOCKET);
    }
    else
    {
      b_Socket_pt->isBlocking_b = i_Blocking_b;
      if(true == i_Blocking_b)
      {
        // this is the default mode
        v_Error_t = e_PeOk;
      }
      else
      {
        sint32_t v_Result_s32;
        sint32_t v_Flags_s32;

        // Set non-blocking mode
        v_Flags_s32 = fcntl(b_Socket_pt->socketHandle_s32, F_GETFL, 0);

        v_Result_s32 = fcntl(b_Socket_pt->socketHandle_s32, F_SETFL, v_Flags_s32 | O_NONBLOCK); // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

        if((v_Flags_s32 == -1) || (v_Result_s32 < 0))
        {
          v_Error_t = ME_GetPlatformError_t(v_Result_s32);
        }
        else
        {
          v_Error_t = e_PeOk;
        }
      }
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Shutdown_t(SocketHandle_t* b_Socket_pt) // PRQA S 3673 // keep this non const, as win implementation cannot handle
{
  PlatformError_t v_Error_t;

  if(NULL != b_Socket_pt)
  {
    // shut down further sends and receives (SHUT_RDWR)
    if (ME_INVALID_SOCKET == shutdown(b_Socket_pt->socketHandle_s32, SHUT_RDWR))
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

/// Closes the specified socket and frees all allocated data
PlatformError_t ME_Socket_Close_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(NULL != b_Socket_pt)
  {
    sint32_t v_Result_s32;
    if(b_Socket_pt->socketHandle_s32 != ME_INVALID_SOCKET)
    {
      v_Result_s32 = close(b_Socket_pt->socketHandle_s32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
    }

    b_Socket_pt->socketHandle_s32 = ME_INVALID_SOCKET;
  }
  else
  {
    /* do nothing */
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Bind_t(const SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t;
  struct sockaddr_in v_LocalAddress_s;
  struct hostent* v_Host_ps;
  sint32_t v_Result_s32;

  if((NULL != b_Socket_pt) && (b_Socket_pt->socketHandle_s32 != ME_INVALID_SOCKET))
  {
    v_LocalAddress_s.sin_family = AF_INET;
    v_LocalAddress_s.sin_port = htons(i_Port_s32); // PRQA S 3759 // defined by QNX example code

    if (NULL != i_Address_pc)
    {
      v_LocalAddress_s.sin_addr.s_addr = inet_addr(i_Address_pc);

      if (v_LocalAddress_s.sin_addr.s_addr == INADDR_NONE) // PRQA S 1281 // defined by QNX
      {
        v_Host_ps = gethostbyname(i_Address_pc);

        if (NULL != v_Host_ps)
        {
          v_LocalAddress_s.sin_addr.s_addr = ((struct in_addr*) v_Host_ps->h_addr)->s_addr; // PRQA S 310 // PRQA S 3305 // PRQA S 491 // this is working
        }
      }
    }
    else
    {
      v_LocalAddress_s.sin_addr.s_addr = INADDR_ANY;
    }

    v_Result_s32 = bind(b_Socket_pt->socketHandle_s32, (struct sockaddr*)&v_LocalAddress_s, sizeof(v_LocalAddress_s)); // PRQA S 310 // this is working
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
    Assert(e_PeOk == v_Error_t);
  }
  else
  {
    //set invalid parameter error for invalid socket
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Listen_t(SocketHandle_t* b_Socket_pt) // PRQA S 3673 // keep this non const, as win implementation cannot handle
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;
  sint32_t disableNagle = 1;

  if((NULL != b_Socket_pt) && (b_Socket_pt->socketHandle_s32 != ME_INVALID_SOCKET))
  {
    if (listen(b_Socket_pt->socketHandle_s32, 0x7fffffff) != 0)
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      // Disable Nagle algorithm for TCP connections
      v_Result_s32 = setsockopt(b_Socket_pt->socketHandle_s32, IPPROTO_TCP, TCP_NODELAY, (void*) &disableNagle, sizeof(disableNagle));
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);

      // Set the size of the internal receive buffer
      v_Result_s32 = setsockopt(b_Socket_pt->socketHandle_s32, SOL_SOCKET, SO_RCVBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);

      // Set the size of the internal send buffer
      v_Result_s32 = setsockopt(b_Socket_pt->socketHandle_s32, SOL_SOCKET, SO_SNDBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);

      v_Error_t = e_PeOk;
    }
  }
  else
  {
    //set invalid parameter error for invalid socket
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Accept_t(SocketHandle_t* b_Socket_pt, SocketHandle_t* b_AcceptedSocket_pt) // PRQA S 3673 // keep this non const, as win implementation cannot handle
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if((NULL == b_Socket_pt) || (NULL == b_AcceptedSocket_pt))
  {
    //set invalid parameter error for invalid socket
    v_Error_t = e_PeInvalid;
  }
  else
  {
    if(b_Socket_pt->socketHandle_s32 != ME_INVALID_SOCKET)
    {
      b_AcceptedSocket_pt->socketHandle_s32 = accept(b_Socket_pt->socketHandle_s32, NULL, NULL);

      if (ME_INVALID_SOCKET == b_AcceptedSocket_pt->socketHandle_s32)
      {
        v_Error_t = e_PeAgain;
      }
      else
      {
        v_Error_t = e_PeOk;
      }
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Connect_t(SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32) // PRQA S 3673 // keep this non const, as win implementation cannot handle
{
  PlatformError_t v_Error_t;
  struct sockaddr_in v_RemoteAddress_s;
  struct hostent* v_Host_ps;
  char_t v_TempAddress_ac[256] = "";
  sint32_t v_Flags_s32;
  sint32_t v_ErrorCode_s32;
  sint32_t v_DisableNagle_s32 = 1;

  if((NULL != b_Socket_pt) && (b_Socket_pt->socketHandle_s32 != ME_INVALID_SOCKET))
  {
    v_RemoteAddress_s.sin_family = AF_INET;
    v_RemoteAddress_s.sin_port = htons(i_Port_s32); // PRQA S 3759 // defined by QNX example code
    v_RemoteAddress_s.sin_addr.s_addr = ((i_Address_pc != NULL) ? inet_addr(i_Address_pc) : INADDR_NONE); // PRQA S 1281 // defined by QNX

    if (v_RemoteAddress_s.sin_addr.s_addr == INADDR_NONE) // PRQA S 1281 // defined by QNX
    {
      // On Mac OS X and Linux there is no specification what gethostbyname returns if the argument "name" is empty or NULL
      // The MSDN documentation for Windows says:
      // If the name parameter points to an empty string or name is NULL, the returned string is the same as
      // the string returned by a successful gethostname function call (the standard host name for the local computer).
      // To mirror this behavior the following if statement is used
      if (NULL == i_Address_pc)
      {
        // if a buffer of 256 bytes is passed in the name parameter and the namelen parameter
        // is set to 256, the buffer size will always be adequate. (MSDN Documentation)
        (void)gethostname(v_TempAddress_ac, sizeof(v_TempAddress_ac));

        v_Host_ps = gethostbyname(v_TempAddress_ac);
      }
      else
      {
        v_Host_ps = gethostbyname(i_Address_pc);
      }

      if (NULL != v_Host_ps)
      {
        v_RemoteAddress_s.sin_addr.s_addr = ((struct in_addr*) v_Host_ps->h_addr)->s_addr; // PRQA S 310 // PRQA S 3305 // PRQA S 491 // this is working
      }
    }

    v_ErrorCode_s32 = connect(b_Socket_pt->socketHandle_s32, (const struct sockaddr*) &v_RemoteAddress_s, sizeof(v_RemoteAddress_s)); // PRQA S 310 // this is working
    if(v_ErrorCode_s32 != -1)
    {
      // Set non-blocking mode
      v_Flags_s32 = fcntl(b_Socket_pt->socketHandle_s32, F_GETFL, 0);

      v_ErrorCode_s32 = fcntl(b_Socket_pt->socketHandle_s32, F_SETFL, v_Flags_s32 | O_NONBLOCK); // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

      if((v_Flags_s32 == -1) || (v_ErrorCode_s32 < 0))
      {
        v_Error_t = ME_GetPlatformError_t(v_ErrorCode_s32);
        Assert(e_PeOk == v_Error_t);
      }

      // Disable Nagle algorithm for TCP connections
      v_ErrorCode_s32 = setsockopt(b_Socket_pt->socketHandle_s32, IPPROTO_TCP, TCP_NODELAY, (void*) &v_DisableNagle_s32, sizeof(v_DisableNagle_s32));
      v_Error_t = ME_GetPlatformError_t(v_ErrorCode_s32);
      Assert(e_PeOk == v_Error_t);

      // Set the size of the internal receive buffer
      v_ErrorCode_s32 = setsockopt(b_Socket_pt->socketHandle_s32, SOL_SOCKET, SO_RCVBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
      v_Error_t = ME_GetPlatformError_t(v_ErrorCode_s32);
      Assert(e_PeOk == v_Error_t);

      // Set the size of the internal send buffer
      v_ErrorCode_s32 = setsockopt(b_Socket_pt->socketHandle_s32, SOL_SOCKET, SO_SNDBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
      v_Error_t = ME_GetPlatformError_t(v_ErrorCode_s32);
      Assert(e_PeOk == v_Error_t);
    }
    else
    {
      v_Error_t = e_PeInvalid;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Receive_t(SocketHandle_t* b_Socket_pt, char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesReceived_pt) // PRQA S 3673 // keep this non const, as win implementation cannot handle
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if((NULL == b_Socket_pt) || (b_Socket_pt->socketHandle_s32 == ME_INVALID_SOCKET) || (NULL == b_NumBytesReceived_pt))
  {
    // set invalid parameter error
    v_Error_t = e_PeInvalid;
  }
  else
  {
    v_Result_s32 = (sint32_t)recv(b_Socket_pt->socketHandle_s32, (char_t*)b_Buffer_pc, i_BufferLength_t, 0);

    if (0 == v_Result_s32)
    {
      v_Error_t = e_PeConnAborted;
      *b_NumBytesReceived_pt = 0;
      errno = 0;
    }
    else if (-1 == v_Result_s32)
    {
      // don't check platform error here, check errno directly, because in non-blocking mode resource temp unavailable will be displayed.
      // but its ok if we have non blocking socket. getPlatformError will display error message, but it's not an error, just a hint that socket is busy.
      if (EAGAIN == errno)
      {
        // if we are non blocking and we receive the again error, just set numBytes received to zero
        *b_NumBytesReceived_pt = 0;
        errno = 0;
        v_Error_t = e_PeAgain;
      }
      else if ((ECONNABORTED == errno) || (ECONNRESET == errno))
      {
        // TODO: remove? if you look into the qnx reference I cannot find ECONNABORTED or ECONNRESET as valid errno for "recv()"
        // maybe it's only valid in non-blocking mode?
        v_Error_t = e_PeConnAborted;
        *b_NumBytesReceived_pt = 0;
        errno = 0;
      }
      else
      {
        v_Error_t = ME_GetPlatformError_t(v_Result_s32);
        //Assert(e_PeOk == v_Error_t);
      }
    }
    else
    {
      *b_NumBytesReceived_pt = v_Result_s32; // PRQA S 3843 // target type is larger then source type, this is OK
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Send_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if((NULL == b_Socket_pt) || (0 == b_Socket_pt->socketHandle_s32) || (NULL == b_NumBytesSent_pt))
  {
    // set invalid parameter error
    v_Error_t = e_PeInvalid;
  }
  else
  {
    fd_set socketSet;
    struct timeval timeout;

    FD_ZERO(&socketSet);
    FD_SET(b_Socket_pt->socketHandle_s32, &socketSet); // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

    timeout.tv_sec  = 0;
    timeout.tv_usec = 0;

    v_Result_s32 = select(b_Socket_pt->socketHandle_s32, NULL, &socketSet, NULL, &timeout);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
    Assert(e_PeOk == v_Error_t);

    v_Result_s32 = (sint32_t)send(b_Socket_pt->socketHandle_s32, (const char_t*)b_Buffer_pc, i_BufferLength_t, 0);

    if (v_Result_s32 < 0)
    {
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);
      *b_NumBytesSent_pt = 0;
    }
    else
    {
      *b_NumBytesSent_pt = v_Result_s32; // PRQA S 3843 // target type is larger then source type, this is OK
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Send_t_ToDest_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt, const char_t* i_RemoteIP_pc, sint32_t i_DestPort_s32)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if((NULL == b_Socket_pt) || (0 == b_Socket_pt->socketHandle_s32) || (NULL == b_NumBytesSent_pt))
  {
    // set invalid parameter error
    v_Error_t = e_PeInvalid;
  }
  else
  {
    struct sockaddr_in v_RemoteAddress_s;
    struct hostent* v_Host_ps;
    char_t v_TempAddress_ac[256] = "";

    v_RemoteAddress_s.sin_family = AF_INET;
    v_RemoteAddress_s.sin_port = htons(i_DestPort_s32); // PRQA S 3759 // defined by QNX example code
    v_RemoteAddress_s.sin_addr.s_addr = ((i_RemoteIP_pc != NULL) ? inet_addr(i_RemoteIP_pc) : INADDR_NONE); // PRQA S 1281 // defined by QNX

    if (v_RemoteAddress_s.sin_addr.s_addr == INADDR_NONE) // PRQA S 1281 // defined by QNX
    {
      // On Mac OS X and Linux there is no specification what gethostbyname returns if the argument "name" is empty or NULL
      // The MSDN documentation for Windows says:
      // If the name parameter points to an empty string or name is NULL, the returned string is the same as
      // the string returned by a successful gethostname function call (the standard host name for the local computer).
      // To mirror this behavior the following if statement is used
      if (NULL == i_RemoteIP_pc)
      {
        // if a buffer of 256 bytes is passed in the name parameter and the namelen parameter
        // is set to 256, the buffer size will always be adequate. (MSDN Documentation)
        (void)gethostname(v_TempAddress_ac, sizeof(v_TempAddress_ac));

        v_Host_ps = gethostbyname(v_TempAddress_ac);
      }
      else
      {
        v_Host_ps = gethostbyname(i_RemoteIP_pc);
      }

      if (NULL != v_Host_ps)
      {
        v_RemoteAddress_s.sin_addr.s_addr = ((struct in_addr*) v_Host_ps->h_addr)->s_addr; // PRQA S 310 // PRQA S 3305 // PRQA S 491 // this is working
      }
    }

    v_Result_s32 = (sint32_t)sendto(b_Socket_pt->socketHandle_s32, (const char_t*)b_Buffer_pc, i_BufferLength_t, 0, (const struct sockaddr*) &v_RemoteAddress_s, sizeof(v_RemoteAddress_s)); // PRQA S 310 // this is working
    if (v_Result_s32 < 0)
    {
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);
      *b_NumBytesSent_pt = 0;
    }
    else
    {
      *b_NumBytesSent_pt = v_Result_s32; // PRQA S 3843 // target type is larger then source type, this is OK
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

bool_t ME_Socket_IsValid_b(const SocketHandle_t* i_Socket_pt)
{
  bool_t v_Ret_b;

  if(NULL != i_Socket_pt)
  {
    v_Ret_b = (i_Socket_pt->socketHandle_s32 != ME_INVALID_SOCKET);
  }
  else
  {
    v_Ret_b = false;
  }

  return v_Ret_b;
}

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
