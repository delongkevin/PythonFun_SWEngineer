//--------------------------------------------------------------------------
/// @file DataContainer.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Gangadhar Reddy Yadiki (GangadharReddy.Yadiki@magna.com)
///         Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "CamMData.h"

#include <platform/PlatformAPI.h>

#include <logging/Logger.h>

#include <bsp/io/fpga/FpgaHelper.h>

namespace container
{

static uint8_t s_ECUSerializerAdresses_au8 = 0x20;

static uint8_t s_DeserializerAdresses_au8[variants::e_CameraCount] =
{
  0x21U,
  0x22U,
  0x23U,
  0x24U,
  0x26U,
#if 0
  0x27U
#endif
};

const uint8_t s_FlipAddr_au8[variants::e_CameraCount] = {0xc2U,
                                                         0xc4U,
                                                         0xc6U,
                                                         0xc8U,
                                                         0xcaU,
#if 0
                                                         0xccU
#endif
};

static uint8_t s_SerializerAdresses_au8[variants::e_CameraCount] =
{
  0x41U,
  0x42U,
  0x43U,
  0x44U,
  0x45U,
#if 0
  0x46U
#endif
};


static uint8_t s_ImagerAdresses_au8[variants::e_CameraCount] =
{
  0x29U,
  0x2AU,
  0x2BU,
  0x2CU,
  0x2DU,
#if 0
  0x2EU
#endif
};


CamMData::CamMData()
  : DataContainer()
  , mutex_o()
  , initialized_b(false)
  , camDatainitialized_b(false)
{
#if 0
  i2c0_o.init_b("/dev/i2c0");
  i2c1_o.init_b("/dev/i2c1");

  initCameras_v();
#endif
}

CamMData::~CamMData()
{
}


void CamMData::initCameras_v()
{
  bool_t v_Result_b = true;
  camDatainitialized_b = true;

  for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount - 1); ++v_I_u32)
  {
    cameras_ao[v_I_u32].init_b(static_cast<variants::Camera_t>(v_I_u32));
    cameras_ao[v_I_u32].getCameraParams_ro().init_b(static_cast<variants::Camera_t>(v_I_u32));
  }

}

sensor::EcuSerializerCXD4963ER* CamMData::getEcuSerializer_po()
{
  ecuSerializerCXD4963ER_o.init_b(i2c1_o, s_ECUSerializerAdresses_au8);
  return &ecuSerializerCXD4963ER_o;
}

/// ----------------------------------------------------------------------------------
// Getter

sensor::CameraBase& CamMData::getCamera_ro(variants::Camera_t i_CameraId_t)
{
  if(false == initialized_b)
  {
	initCameras_v();
	initialized_b = true;
  }
  return cameras_ao[i_CameraId_t];
}

bool_t CamMData::getCamDataInitStatus()
{
	return camDatainitialized_b;
}

bool_t CamMData::getCameraReady_b()
{
  bool_t v_Result_b = true;

  mutex_o.take_b();

  for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_CameraCount; v_I_u32++)
  {
    v_Result_b &= (cameras_ao[v_I_u32].getCameraState_e() == sensor::e_CameraStateRunning)
               || (cameras_ao[v_I_u32].getCameraState_e() == sensor::e_CameraStateDisconnected);
  }

  mutex_o.give_v();

  return v_Result_b;
}

const sensor::CalibrationData_t& CamMData::getCameraCalibrationData_t(variants::Camera_t i_CameraId_t)
{
  return cameraCalibrationData_at[i_CameraId_t];
}

variants::CamTestPattern_t CamMData::getCameraTestPatternMode_t(variants::Camera_t i_CameraId_t)
{
  return requestedCamTestPattern_at[i_CameraId_t];
}

bool_t CamMData::getDeserializerRegisterData_b(variants::Camera_t i_CameraId_t,uint8_t i_RegisterAddress_u8, uint8_t* o_Buffer_pu8, uint32_t i_Size_u32)
{
  return deserializerCXD4960ER_ao[i_CameraId_t].read_b(static_cast<uint32_t>(i_RegisterAddress_u8), reinterpret_cast<uint32_t*>(o_Buffer_pu8), i_Size_u32);
}

void CamMData::setCameraCalibrationData_t(variants::Camera_t i_CameraId_t, const sensor::CalibrationData_t& i_CameraCalibrationData_t)
{
  cameraCalibrationData_at[i_CameraId_t] = i_CameraCalibrationData_t;
}

void CamMData::setCameraTestPatternMode_v(variants::Camera_t i_CameraId_t, variants::CamTestPattern_e i_PatternId_t)
{
  requestedCamTestPattern_at[i_CameraId_t] = i_PatternId_t;
}

bool_t CamMData::setDeserializerRegisterData_b(variants::Camera_t i_CameraId_t,uint8_t i_RegisterAddress_u8, const uint8_t* o_Buffer_pu8, uint32_t i_Size_u32)
{
  return deserializerCXD4960ER_ao[i_CameraId_t].write_b(static_cast<uint32_t>(i_RegisterAddress_u8), reinterpret_cast<const uint32_t*>(o_Buffer_pu8), i_Size_u32);
}


} // namespace container
