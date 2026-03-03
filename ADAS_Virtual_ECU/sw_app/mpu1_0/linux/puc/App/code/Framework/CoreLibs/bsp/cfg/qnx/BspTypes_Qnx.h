//--------------------------------------------------------------------------
/// @file BspTypes_Qnx.h
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

#ifndef BSP_TYPES_QNX_H_
#define BSP_TYPES_QNX_H_

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_QNX

#include <screen/screen.h>

// PRQA S 2300 EOF // const objects for defines in global scope allowed here
// PRQA S 2400 EOF // Typenames in global scope allowed here

// --------------------------------------------------------------------
// Screen
// --------------------------------------------------------------------

#include <bsp/io/fpga/FpgaZCU102.h>

typedef screen_context_t ScreenContext_t;

typedef screen_stream_t  Stream_t;

typedef screen_event_t   Event_t;

typedef screen_display_t Display_t;

typedef screen_pixmap_t  Pixmap_t;

typedef screen_buffer_t  Buffer_t;

typedef enum WindowTypeQNX_e
{
  e_ApplicationWindow,
  e_ChildWindow
} WindowType_t;

typedef screen_window_t Window_t;

typedef bsp::FpgaZCU102* DeviceContext_t;

// add other QNX dependent types here



// --------------------------------------------------------------------
// I2c
// --------------------------------------------------------------------

#include <hw/i2c.h>

const uint32_t I2C_BUFFER_SIZE = 256;
const uint32_t I2C_SEND_BUFFER_SIZE = (I2C_BUFFER_SIZE + 1);

typedef struct I2cHandle_s
{
  sint32_t    i2cHandle_s32;
  i2c_addr_t  i2cSlaveAddress_t;
} I2cHandle_t;

typedef struct SendMessage_s
{
  i2c_send_t header_t;
  uint8_t    sendBuffer_au8[I2C_SEND_BUFFER_SIZE];
} SendMessage_t;

typedef struct RecvMessage_s
{
  i2c_recv_t header_t;
  uint8_t    recvBuffer_au8[I2C_BUFFER_SIZE];
} RecvMessage_t;

// --------------------------------------------------------------------
// Uart
// --------------------------------------------------------------------

const uint32_t UART_BUFFER_SIZE = 256;

typedef sint32_t UartHandle_t;

typedef struct IpcComHandle_s
{
  sint32_t    ipcComFd_s32;
} IpcComHandle_t;

// --------------------------------------------------------------------
// ICCOM
// --------------------------------------------------------------------

typedef sint32_t IccomHandle_t;

// --------------------------------------------------------------------
// CAN
// --------------------------------------------------------------------

#include <sys/can_dcmd.h>

const uint8_t c_CanIdSize_u8 = 2U;

/* Extended CAN Message */
typedef CAN_MSG_EXT CanMsgExt_t;


/* CAN Message */
typedef CAN_MSG CanMessage_t;

typedef sint32_t CanHandleRx_t;

typedef sint32_t CanHandleTx_t;

#endif // ME_PLATFORM_QNX

#endif // IO_TYPES_QNX_H_
