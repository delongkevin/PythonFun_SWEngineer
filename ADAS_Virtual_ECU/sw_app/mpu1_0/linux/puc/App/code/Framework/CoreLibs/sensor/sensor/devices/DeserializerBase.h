//--------------------------------------------------------------------------
/// @file EepromBase.h
/// @brief Defines a general interface implementation for Eeproms (e.g. cameras)
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

#ifndef DESERIALIZER_BASE_H_
#define DESERIALIZER_BASE_H_

#include "IDevice.h"

#include "cfg/CamTypes.h"

namespace sensor
{


typedef struct DeserializerData_s
{
} DeserializerData_t;

enum DeserializerCmd_e
{
  e_DeserCmdInit = 0,
  e_DeserCmdCheckStatus,
  e_DeserCmdRunPrbsTest,
  e_DeserCmdCount,
  e_DeserCmdInvalid
};

template<typename T>
class DeserializerBase : public IDevice<T>
{

public: 

  DeserializerBase()
  : i2c_po(NULL)
  , deviceAddress_u8(0U)
  , deviceFlipAddress_u8(0U)
  {

  }

  virtual ~DeserializerBase()
  {
  }

public:

  virtual bool_t                init_b(bsp::I2c& i_I2C_ro, T i_DeviceAddress_u8) = 0;
                                
  virtual bool_t                read_b(T i_RegisterAddress_u8, T* b_Buffer_pu8, uint32_t i_BufferLength_t) = 0;
                                
  virtual bool_t                write_b(T i_RegisterAddress_u8, const T* b_Buffer_pu8, uint32_t i_BufferLength_t) = 0;
                                
  virtual void                  deInit_v() = 0;
                                
  virtual bool_t                runCommand_b(sint8_t i_Command_s8) = 0;

public:

  void                          setFlipAddress_v(T i_FlipAddress_u8) { deviceFlipAddress_u8 = i_FlipAddress_u8; }

protected:

  bsp::I2c*                     i2c_po;

  uint8_t                       deviceAddress_u8;
  uint8_t                       deviceFlipAddress_u8;

  DeserializerData_t            data_t;

};

} // namespace sensor

#endif // DESERIALIZER_BASE_H_
