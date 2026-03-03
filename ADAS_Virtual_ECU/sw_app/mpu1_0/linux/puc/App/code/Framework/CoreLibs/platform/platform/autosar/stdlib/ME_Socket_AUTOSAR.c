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
#ifdef ME_PLATFORM_AUTOSARTODO

#include "platform/stdlib/ME_Socket.h"
#include "platform/stdlib/ME_Assert.h"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
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
          *b_Socket_pt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        }
        break;
      case e_SptUdp:
        {
          *b_Socket_pt = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        }
        break;
      default:
        *b_Socket_pt = -1;
        break;
    }

    if (*b_Socket_pt == -1)
    {
      v_Error_t = getPlatformError_t(-1);
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Shutdown_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t;

  // shut down further sends and receives (SHUT_RDWR)
  if (-1 == shutdown(i_Socket_t, SHUT_RDWR))
  {
    v_Error_t = getPlatformError_t(-1);
  }
  else
  {
    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

/// Closes the specified socket and frees all allocated data
PlatformError_t ME_Socket_Close_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if (i_Socket_t == 0)
  {
    //set invalid parameter error for invalid socket
    v_Error_t = e_PeInvalid;
  }
  else
  {
    v_Result_s32 = close(i_Socket_t);
    v_Error_t = getPlatformError_t(v_Result_s32);
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Bind_t(SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t;
  struct sockaddr_in v_LocalAddress_s;
  struct hostent* v_Host_ps;
  sint32_t v_Result_s32;

  if (i_Socket_t != 0)
  {
    v_LocalAddress_s.sin_family = AF_INET;
    v_LocalAddress_s.sin_port = htons(i_Port_s32);

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

    v_Result_s32 = bind(i_Socket_t, (struct sockaddr*)&v_LocalAddress_s, sizeof(v_LocalAddress_s)); // PRQA S 310 // this is working
    v_Error_t = getPlatformError_t(v_Result_s32);
    Assert(e_PeOk == v_Error_t);
  }
  else
  {
    //set invalid parameter error for invalid socket
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Listen_t(SocketHandle_t* b_Socket_pt)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;
  sint32_t v_Flags_s32;
  sint32_t disableNagle = 1;

  if (i_Socket_t != 0)
  {
    if (listen(i_Socket_t, 0x7fffffff) != 0)
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      // Set non-blocking mode
      v_Flags_s32 = fcntl(i_Socket_t, F_GETFL, 0);

      v_Result_s32 = fcntl(i_Socket_t, F_SETFL, v_Flags_s32 | O_NONBLOCK); // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

      if((v_Flags_s32 == -1) || (v_Result_s32 < 0))
      {
        v_Error_t = getPlatformError_t(v_Result_s32);
        Assert(e_PeOk == v_Error_t);
      }

      // Disable Nagle algorithm for TCP connections
      v_Result_s32 = setsockopt(i_Socket_t, IPPROTO_TCP, TCP_NODELAY, (void*) &disableNagle, sizeof(disableNagle));
      v_Error_t = getPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);

      // Set the size of the internal receive buffer
      v_Result_s32 = setsockopt(i_Socket_t, SOL_SOCKET, SO_RCVBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
      v_Error_t = getPlatformError_t(v_Result_s32);
      Assert(e_PeOk == v_Error_t);

      // Set the size of the internal send buffer
      v_Result_s32 = setsockopt(i_Socket_t, SOL_SOCKET, SO_SNDBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
      v_Error_t = getPlatformError_t(v_Result_s32);
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

PlatformError_t ME_Socket_Accept_t(SocketHandle_t* b_Socket_pt, SocketHandle_t* b_AcceptedSocket_pt)
{
  PlatformError_t v_Error_t;

  if((0 == i_Socket_t) || (NULL == b_AcceptedSocket_pt))
  {
    //set invalid parameter error for invalid socket
    v_Error_t = e_PeInvalid;
  }
  else
  {
    *b_AcceptedSocket_pt = accept(i_Socket_t, NULL, NULL);

    if (-1 == *b_AcceptedSocket_pt)
    {
      v_Error_t = e_PeAgain;
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Connect_t(SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32)
{
  PlatformError_t v_Error_t = e_PeOk;
  struct sockaddr_in v_RemoteAddress_s;
  struct hostent* v_Host_ps;
  char_t v_TempAddress_ac[256] = "";
  sint32_t v_Flags_s32;
  sint32_t v_ErrorCode_s32;
  sint32_t v_DisableNagle_s32 = 1;

  if (i_Socket_t != 0)
  {
    v_RemoteAddress_s.sin_family = AF_INET;
    v_RemoteAddress_s.sin_port = htons(i_Port_s32);
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

    v_ErrorCode_s32 = connect(i_Socket_t, (const struct sockaddr*) &v_RemoteAddress_s, sizeof(v_RemoteAddress_s)); // PRQA S 310 // this is working
    v_Error_t = getPlatformError_t(v_ErrorCode_s32);
    Assert(e_PeOk == v_Error_t);

    // Set non-blocking mode
    v_Flags_s32 = fcntl(i_Socket_t, F_GETFL, 0);

    v_ErrorCode_s32 = fcntl(i_Socket_t, F_SETFL, v_Flags_s32 | O_NONBLOCK); // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

    if((v_Flags_s32 == -1) || (v_ErrorCode_s32 < 0))
    {
      v_Error_t = getPlatformError_t(v_ErrorCode_s32);
      Assert(e_PeOk == v_Error_t);
    }

    // Disable Nagle algorithm for TCP connections
    v_ErrorCode_s32 = setsockopt(i_Socket_t, IPPROTO_TCP, TCP_NODELAY, (void*) &v_DisableNagle_s32, sizeof(v_DisableNagle_s32));
    v_Error_t = getPlatformError_t(v_ErrorCode_s32);
    Assert(e_PeOk == v_Error_t);

    // Set the size of the internal receive buffer
    v_ErrorCode_s32 = setsockopt(i_Socket_t, SOL_SOCKET, SO_RCVBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
    v_Error_t = getPlatformError_t(v_ErrorCode_s32);
    Assert(e_PeOk == v_Error_t);

    // Set the size of the internal send buffer
    v_ErrorCode_s32 = setsockopt(i_Socket_t, SOL_SOCKET, SO_SNDBUF, (const void*) &c_SocketBufferSize_u32, sizeof(c_SocketBufferSize_u32));
    v_Error_t = getPlatformError_t(v_ErrorCode_s32);
    Assert(e_PeOk == v_Error_t);
  }

  return v_Error_t;
}

PlatformError_t ME_Socket_Receive_t(SocketHandle_t* b_Socket_pt, char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesReceived_pt)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if((i_Socket_t == ME_INVALID_SOCKET) || (NULL == b_NumBytesReceived_pt))
  {
    // set invalid parameter error
    v_Error_t = e_PeInvalid;
  }
  else
  {
#ifdef NONBLOCKING_MODE
    //http://www.openqnx.com/phpbbforum/viewtopic.php?t=2387
    //https://stackoverflow.com/questions/7964967/how-do-i-set-a-udp-socket-to-non-blocking-in-qnx
    //http://www.qnx.com/developers/docs/7.0.0/index.html#com.qnx.doc.neutrino.devctl/topic/fio/fionbio.html

    int setnonblocking = 1; // Zero to clear O_NONBLOCK, or nonzero to set it.
    v_Result_s32 = ioctl_socket(i_Socket_t, FIONBIO, &setnonblocking); // PRQA S 2855 //defined by QNX
    v_Error_t = getPlatformError_t(v_Result_s32);
    Assert(e_PeOk == v_Error_t);
#endif
    v_Result_s32 = (sint32_t)recv(i_Socket_t, (char_t*)b_Buffer_pc, i_BufferLength_t, 0);

    if (-1 == v_Result_s32)
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
        v_Error_t = e_PeConnAborted;
        *b_NumBytesReceived_pt = 0;
        errno = 0;
      }
      else
      {
        v_Error_t = getPlatformError_t(v_Result_s32);
        Assert(e_PeOk == v_Error_t);
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

PlatformError_t ME_Socket_Send_t(SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if((0 == i_Socket_t) || (NULL == b_NumBytesSent_pt))
  {
    // set invalid parameter error
    v_Error_t = e_PeInvalid;
  }
  else
  {
    struct fd_set socketSet;
    struct timeval timeout;

    (void)FD_ZERO(&socketSet);
    (void)FD_SET(i_Socket_t, &socketSet); // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

    timeout.tv_sec  = 0;
    timeout.tv_usec = 0;

    v_Result_s32 = select(i_Socket_t, NULL, &socketSet, NULL, &timeout);
    v_Error_t = getPlatformError_t(v_Result_s32);
    Assert(e_PeOk == v_Error_t);

    v_Result_s32 = (sint32_t)send(i_Socket_t, (const char_t*)b_Buffer_pc, i_BufferLength_t, 0);

    if (v_Result_s32 < 0)
    {
      v_Error_t = getPlatformError_t(v_Result_s32);
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

PlatformError_t ME_Socket_Send_t_ToDest_t(SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt, const char_t* i_RemoteIP_pc, sint32_t i_DestPort_s32)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if((0 == i_Socket_t) || (NULL == b_NumBytesSent_pt))
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
    v_RemoteAddress_s.sin_port = htons(i_DestPort_s32);
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

    v_Result_s32 = (sint32_t)sendto(i_Socket_t, (const char_t*)b_Buffer_pc, i_BufferLength_t, 0, (const struct sockaddr*) &v_RemoteAddress_s, sizeof(v_RemoteAddress_s)); // PRQA S 310 // this is working
    if (v_Result_s32 < 0)
    {
      v_Error_t = getPlatformError_t(v_Result_s32);
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


#endif // ME_PLATFORM_AUTOSAR // PRQA S 862 // this define decides which platform is defined

