//--------------------------------------------------------------------------
/// @file ImagerBase.h
/// @brief Defines a general interface implementation for Serializer (e.g. cameras)
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

#ifndef IMAGER_BASE_H_
#define IMAGER_BASE_H_


#include "IDevice.h"

namespace sensor
{

template<typename T>
class ImagerBase : public IDevice<T>
{
public: 

  ImagerBase(){}

  virtual ~ImagerBase(){}

public: 

  virtual bool_t         init_b(bsp::I2c& i_I2C_ro, T i_DeviceAddress_u8) = 0;

  virtual bool_t         read_b(T i_RegisterAddress_u8, T* b_Buffer_pu8, uint32_t i_BufferLength_t) = 0;

  virtual bool_t         write_b(T i_RegisterAddress_u8, const T* b_Buffer_pu8, uint32_t i_BufferLength_t) = 0;

  virtual void           deInit_v() = 0;

  virtual bool_t         runCommand_b(sint8_t i_Command_s8) = 0;

};

} // namespace sensor

#endif // IMAGER_BASE_H_
