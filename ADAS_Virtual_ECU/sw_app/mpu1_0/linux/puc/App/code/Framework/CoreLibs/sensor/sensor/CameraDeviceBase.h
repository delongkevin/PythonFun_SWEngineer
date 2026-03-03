//--------------------------------------------------------------------------
/// @file ICameraDevice.h
/// @brief Defines a general interface implementation for cameras devices
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CAMERA_DEVICE_BASE_H_
#define CAMERA_DEVICE_BASE_H_

#include <platform/PlatformAPI.h>

namespace sensor
{

//class CameraDeviceBase
//{
//public:
//
//  CameraDeviceBase()
//  : deviceAddress_u8(0x00U)
//  {
//
//  }
//
//  virtual ~CameraDeviceBase()
//  {
//
//  }
//
//  virtual bool_t init_b(uint8_t i_DeviceAddress_u8) = 0;
//
//  virtual void   deInit_v() = 0;
//
//  virtual bool_t write_b(T i_RegisterAddress_x, const uint8_t* i_Buffer_pu8, uint32_t i_BufferLength_u32) = 0;
//
//  virtual bool_t read_b(T i_RegisterAddress_x, uint8_t* i_Buffer_pu8, uint32_t i_BufferLength_u32) = 0;
//
//public:
//
//  uint8_t getDeviceAddress_u8()
//  {
//    return deviceAddress_u8;
//  }
//
//protected:
//
//  uint8_t deviceAddress_u8;
//
//}; // class CameraDeviceBase

} // namespace sensor

#endif // CAMERA_DEVICE_BASE_H_
