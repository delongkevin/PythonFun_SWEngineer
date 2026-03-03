//--------------------------------------------------------------------------
/// @file CamMData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Gangadhar Reddy Yadiki (GangadharReddy.Yadiki@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_CAMM_DATA_H
#define CONTAINER_CAMM_DATA_H

#include <osal/threading/Mutex.h>

#include <variants/Enums.h>

#include "cfg/ImagerAS0149AT.h"
#include "cfg/DeserializerCXD4960ER.h"
#include "cfg/SerializerCXD4963ER.h"
#include "cfg/SpiFlashW25Q40.h"

#ifdef ME_PLATFORM_QNX
#include <cfg/CameraStellantis.h>
#else
#include <cfg/CamShm.h>
#endif

#include "container/DataContainer.h"
#include "sensor/CameraBase.h"

namespace container
{

class CamMData : public DataContainer
{
public:

  CamMData();

  virtual ~CamMData();

  /*Enable this function if we decide to run thread cameraStatusUpdateThread_pv from Apps to update camera error flags such as buffer/packet errors or camera is connected or not*/
#if 0
  void                             cameraStatusUpdate_pv(variants::Camera_t i_CameraId_t);
#else
  static void*                     cameraStatusUpdate_pv(void* v_Arg_pv);
#endif

  void                             initCameras_v();

  sensor::EcuSerializerCXD4963ER*  getEcuSerializer_po();

  // -------------------------------------------------------------------------------------------------
  // Getter

  sensor::CameraBase&              getCamera_ro(variants::Camera_t i_CameraId_t);

  bool_t                           getCameraReady_b();

  bool_t                           getCamDataInitStatus();

  const sensor::CalibrationData_t& getCameraCalibrationData_t(variants::Camera_t i_CameraId_t);

  variants::CamTestPattern_t       getCameraTestPatternMode_t(variants::Camera_t i_CameraId_t);

  bool_t                           getDeserializerRegisterData_b(variants::Camera_t i_CameraId_t,uint8_t i_RegisterAddress_u8, uint8_t* o_Buffer_pu8, uint32_t i_Size_u32);

  // -------------------------------------------------------------------------------------------------
  // Setter

  void                             setCameraCalibrationData_t(variants::Camera_t i_CameraId_t, const sensor::CalibrationData_t& i_CameraCalibrationData_t);

  void                             setCameraTestPatternMode_v(variants::Camera_t i_CameraId_t, variants::CamTestPattern_t i_PatternId_t);

  bool_t                           setDeserializerRegisterData_b(variants::Camera_t i_CameraId_t,uint8_t i_RegisterAddress_u8, const uint8_t* o_Buffer_pu8, uint32_t i_Size_u32);


private:

  osal::Mutex                     mutex_o;

  bsp::I2c                        i2c0_o;
  bsp::I2c                        i2c1_o;
  bool_t                          initialized_b;
  bool_t                          camDatainitialized_b;


  // Video output
  sensor::EcuSerializerCXD4963ER  ecuSerializerCXD4963ER_o; // video output serializer


  // Video IN
  sensor::DeserializerCXD4960ER   deserializerCXD4960ER_ao[variants::e_CameraCount];

  sensor::SerializerCXD4963ER     camSerializerCXD4963ER_ao[variants::e_CameraCount];

  sensor::ImagerAS0149AT          imagerAS0149AT_ao[variants::e_CameraCount];

  sensor::SpiFlashW25Q40          flashW25Q40_ao[variants::e_CameraCount];

  variants::CamTestPattern_t      requestedCamTestPattern_at[variants::e_CameraCount];

  sensor::CalibrationData_t       cameraCalibrationData_at[variants::e_CameraCount];

#ifdef ME_PLATFORM_QNX
  sensor::CameraStellanis        cameras_ao[variants::e_CameraCount]; // video in
#else // ME_PLATFORM_QNX
  sensor::CamShm                  cameras_ao[variants::e_CameraCount];
#endif // ME_PLATFORM_QNX

};

} // namespace container

#endif // CONTAINER_CAMM_DATA_H
