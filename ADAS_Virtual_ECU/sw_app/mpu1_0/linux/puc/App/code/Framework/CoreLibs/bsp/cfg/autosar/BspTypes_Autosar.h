//--------------------------------------------------------------------------
/// @file IoTypes_QNX.h
/// @brief Header for Qnx Specific Standard Library Types
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

#ifndef IO_TYPES_AUTOSAR_H_
#define IO_TYPES_AUTOSAR_H_

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_AUTOSAR

// Screen
typedef sint32_t ScreenContext_t;

typedef sint32_t Stream_t;

typedef sint32_t Event_t;

typedef sint32_t Display_t;

typedef sint32_t Pixmap_t;

typedef sint32_t Buffer_t;

typedef enum WindowTypeAutosar_e
{
  e_ApplicationWindow,
  e_ChildWindow
} WindowType_t;

typedef struct WindowAutosar_s
{
  sint32_t  contextHandle_t;
  sint32_t  windowHandle_t;
} Window_t;

// I2c

#define I2C_BUFFER_SIZE 64

typedef struct I2cHandleAutosar_s
{
  sint32_t    i2cHandle_s32;
} I2cHandle_t;

typedef struct SendMessageAutosar_s
{
  uint8_t    sendBuffer_au8[I2C_BUFFER_SIZE];
} SendMessage_t;

typedef struct RecvMessageAutosar_s
{
  uint8_t    recvBuffer_au8[I2C_BUFFER_SIZE];
} RecvMessage_t;

// --------------------------------------------------------------------
// Uart
// --------------------------------------------------------------------

#define UART_BUFFER_SIZE 256

typedef struct UartHandleAutosar_s
{
  sint32_t    uartHandle_s32;
  sint32_t    uartSlaveAddress_t;
} UartHandle_t;

// --------------------------------------------------------------------
// ICCOM
// --------------------------------------------------------------------

typedef struct IccomHandleAutosar_s
{
  sint32_t handle_s32;
  uint8_t channelId_s8;
} IccomHandle_t;

#endif // ME_PLATFORM_AUTOSAR
#endif // IO_TYPES_QNX_H_
