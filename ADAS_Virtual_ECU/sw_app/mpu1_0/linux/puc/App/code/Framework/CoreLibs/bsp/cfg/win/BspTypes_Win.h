//--------------------------------------------------------------------------
/// @file IoTypes_Win.h
/// @brief Header for Qnx Specific Standard Library Types
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef BSP_TYPES_WIN_H_
#define BSP_TYPES_WIN_H_

#ifdef ME_PLATFORM_WIN

// Screen

typedef void*   ScreenContext_t;

typedef void*   Stream_t;

typedef void*   Event_t;

typedef void*   Display_t;

typedef void*   Pixmap_t;

typedef void*   Buffer_t;

typedef enum WindowTypeWin_e
{
  e_ApplicationWindow,
  e_ChildWindow
} WindowType_t;

typedef HWND Window_t;

typedef HDC  DeviceContext_t;

// I2c

const uint32_t I2C_BUFFER_SIZE = 64;

typedef struct I2cHandleWin_s
{
  sint32_t    i2cHandle_s32;
} I2cHandle_t;

typedef struct SendMessageWin_s
{
  uint8_t    sendBuffer_au8[I2C_BUFFER_SIZE];
} SendMessage_t;

typedef struct RecvMessageWin_s
{
  uint8_t    recvBuffer_au8[I2C_BUFFER_SIZE];
} RecvMessage_t;

// --------------------------------------------------------------------
// Uart
// --------------------------------------------------------------------

#define UART_BUFFER_SIZE 256

typedef struct UartHandleWin_s
{
  sint32_t    uartHandle_s32;
  sint32_t  uartSlaveAddress_t;
} UartHandle_t;

// --------------------------------------------------------------------
// ICCOM
// --------------------------------------------------------------------

typedef struct IccomHandleWin_s
{
  sint32_t rxHandle_s32;
  sint32_t txHandle_s32;
  uint8_t channelId_s8;
} IccomHandle_t;

// --------------------------------------------------------------------
// CAN
// --------------------------------------------------------------------

/* Extended CAN Message */
typedef sint32_t CanMsgExt_t;

/* CAN Message */
typedef sint32_t CanMessage_t;

typedef struct CanHandleRxWin_s
{
  uint8_t channelId_u8;
} CanHandleRx_t;

typedef struct CanHandleTxWin_s
{
  uint8_t channelId_u8;
} CanHandleTx_t;

#endif // ME_PLATFORM_WIN

#endif // IO_TYPES_WIN_H_
