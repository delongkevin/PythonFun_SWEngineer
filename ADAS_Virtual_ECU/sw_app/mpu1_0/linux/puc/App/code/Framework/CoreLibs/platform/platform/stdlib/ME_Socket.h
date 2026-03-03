/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Socket.h
/// @brief Interface to abstract standard-library Socket functions
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

#ifndef ME_SOCKET_H
#define ME_SOCKET_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

typedef enum SocketProtocolType_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_SptTcp = 0,
  e_SptUdp
} SocketProtocolType_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

#define MAX_SOCKET_SIZE 1024U // PRQA S 1025 //  Macro may be used as a literal. Is OK here


/// Initiates the use of the sockets by a process and increments an internal counter
/// Some APIs like Winsock need a startup command. Make sure to call it once per process (qnx doesn't use this function)
PlatformError_t ME_Socket_Startup_t(void);

/// Terminates the use of the sockets by a process and decrements the internal counter
/// Some APIs like Winsock need a cleanup command. Make sure to call it once per process (qnx doesn't use this function)
PlatformError_t ME_Socket_Cleanup_t(void);

/// Initializes the handle correctly for further processing
void ME_Socket_Init_v(SocketHandle_t* b_Socket_pt);

/// Creates a new socket with the specified protocol type
PlatformError_t ME_Socket_Create_t(SocketHandle_t* b_Socket_pt, SocketProtocolType_t i_Protocol_e, bool_t i_Blocking_b);

/// Sends a shutdown message to the connected socket
PlatformError_t ME_Socket_Shutdown_t(SocketHandle_t* b_Socket_pt);

/// Closes the specified socket and frees all allocated data
PlatformError_t ME_Socket_Close_t(SocketHandle_t* b_Socket_pt);

/// Binds the socket to the specified IP address and port
PlatformError_t ME_Socket_Bind_t(const SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32);

/// Places the socket in a state in which it is listening for an incoming connection
PlatformError_t ME_Socket_Listen_t(SocketHandle_t* b_Socket_pt);

/// Permits an incoming connection attempt on the specified socket. AcceptedSocket contains the handle to the accepted socket if no error occurred
PlatformError_t ME_Socket_Accept_t(SocketHandle_t* b_Socket_pt, SocketHandle_t* b_AcceptedSocket_pt);

/// Establishes a connection to a specified socket
PlatformError_t ME_Socket_Connect_t(SocketHandle_t* b_Socket_pt, const char_t* i_Address_pc, sint32_t i_Port_s32);

/// Receives data from a connected socket or a bound connection less socket
PlatformError_t ME_Socket_Receive_t(SocketHandle_t* b_Socket_pt, char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesReceived_pt);

/// Sends data on the specified connected socket
PlatformError_t ME_Socket_Send_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt);

/// Sends data on the specified connected socket using the remote address
PlatformError_t ME_Socket_Send_t_ToDest_t(const SocketHandle_t* b_Socket_pt, const char_t* b_Buffer_pc, size_t i_BufferLength_t, size_t* b_NumBytesSent_pt, const char_t* i_RemoteIP_pc, sint32_t i_DestPort_s32);

bool_t          ME_Socket_IsValid_b(const SocketHandle_t* i_Socket_pt);

#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_SOCKET_H
