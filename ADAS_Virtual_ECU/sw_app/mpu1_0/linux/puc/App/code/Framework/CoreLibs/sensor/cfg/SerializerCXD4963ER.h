//--------------------------------------------------------------------------
/// @file SerializerMAX9249.h
/// @brief Implementation of SerializerMAX9249 interface
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

#ifndef SERIALIZER_CXD4963ER_H_
#define SERIALIZER_CXD4963ER_H_

#include <sensor/devices/SerializerBase.h>

#include <bsp/driver/I2c.h>



/// General status Monitor 1
#define GENERAL_STATUS_REG_1 0x00U
#define GVIF2TX_ACTIVATED    0x01U

/// General status Monitor 2
#define GENERAL_STATUS_REG_2 0x01U
#define READY                0x10U

/// Error status monitor 1
#define ERROR_STATUS_REG_1   0x10U

/// Error status monitor 7
#define ERROR_STATUS_REG_7   0x16U



namespace sensor
{

class SerializerCXD4963ER : public SerializerBase<uint32_t>
{
public:

  SerializerCXD4963ER();

  virtual ~SerializerCXD4963ER();

  virtual bool_t   init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8) ME_OVERRIDE;

  virtual void     deInit_v() ME_OVERRIDE;

  virtual bool_t   write_b(uint32_t i_RegisterAddress_u8, const uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  virtual bool_t   read_b(uint32_t i_RegisterAddress_u8, uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  virtual bool_t   runCommand_b(sint8_t i_Command_s8) ME_OVERRIDE;

protected:

  bool_t           runCheckStatus_b();

private:

  bool_t           runInitCmd_b();

};



class EcuSerializerCXD4963ER : public SerializerCXD4963ER
{
public:

  EcuSerializerCXD4963ER()
    : SerializerCXD4963ER()
  {
  }

  virtual ~EcuSerializerCXD4963ER()
  {
  }


public:

  bool_t runCommand_b(sint8_t i_Command_s8) ME_OVERRIDE;

};

}

#endif // SERIALIZER_CXD4963ER_H_
