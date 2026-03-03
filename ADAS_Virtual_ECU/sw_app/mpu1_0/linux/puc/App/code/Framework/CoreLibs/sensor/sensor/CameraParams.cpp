//--------------------------------------------------------------------------
/// @file CameraParams.cpp
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


#include "CameraParams.h"

#include <variants/VariantHelper.h>

namespace sensor
{

CameraParams::CameraParams()
  : cameraID_t(variants::e_CameraInvalid)
  , mutex_o()
  , realPinhole_o()
  , realLensRadial_o()
  , realSensor_o()
  , realCamera_o(realPinhole_o, realLensRadial_o, realSensor_o)
  , isRealCameraInitialized_b(false)
  , designPinhole_o()
  , designLensRadial_o()
  , designSensor_o()
  , designCamera_o(designPinhole_o, designLensRadial_o, designSensor_o)
  , isDesignCameraInitialized_b(false)
  , calibrationData_t()
  , eepromData_t()
  , isEepromSet_b(false)
{

}


CameraParams::~CameraParams()
{

}

bool_t CameraParams::init_b(variants::Camera_t i_CameraId_t)
{
  bool_t v_Result_b = true;

  cameraID_t = i_CameraId_t;

  v_Result_b = createDesignCamera_b() && v_Result_b;
  v_Result_b = createRealCamera_b()   && v_Result_b;

  return v_Result_b;
}

bool_t CameraParams::createRealCamera_b()
{
  Pinhole_t::Config_s     v_RealPinholeCfg_s;
  LensRadial_t::Config_s  v_RealLensRadialCfg_s;
  Sensor_t::Config_s      v_RealSensorCfg_s;

  Pinhole_t::Config_s     v_DesignPinholeCfg_s;
  LensRadial_t::Config_s  v_DesignLensRadialCfg_s;
  Sensor_t::Config_s      v_DesignSensorCfg_s;
	mutex_o.take_b();
  if ( isRealCameraInitialized_b == false )
  {
    memset(&v_RealPinholeCfg_s,    0, sizeof(v_RealPinholeCfg_s));
    memset(&v_RealLensRadialCfg_s, 0, sizeof(v_RealLensRadialCfg_s));
    memset(&v_RealSensorCfg_s,     0, sizeof(v_RealSensorCfg_s));

    bool_t v_Result_b = getRealCameraCfg_b( v_RealPinholeCfg_s,v_RealLensRadialCfg_s,v_RealSensorCfg_s);

    if ((v_Result_b != false) && (isDesignCameraInitialized_b == true))
    {
      getDesignCameraCfg_b(v_DesignPinholeCfg_s, v_DesignLensRadialCfg_s, v_DesignSensorCfg_s);

      // update mecl camera with ApplyCalibrationData
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x = mecl::math::toDegrees_x(v_DesignPinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x);
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x   = mecl::math::toDegrees_x(v_DesignPinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x);
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x  = mecl::math::toDegrees_x(v_DesignPinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x);

      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x += calibrationData_t.pitchDelta_f32;
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x   += calibrationData_t.yawDelta_f32;
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x  += calibrationData_t.rollDelta_f32;
      v_RealPinholeCfg_s.extrinsic_s.pos_x.cVal_ax[0]       = v_DesignPinholeCfg_s.extrinsic_s.pos_x.cVal_ax[0] + calibrationData_t.xDelta_f32;
      v_RealPinholeCfg_s.extrinsic_s.pos_x.cVal_ax[1]       = v_DesignPinholeCfg_s.extrinsic_s.pos_x.cVal_ax[1] + calibrationData_t.yDelta_f32;
      v_RealPinholeCfg_s.extrinsic_s.pos_x.cVal_ax[2]       = v_DesignPinholeCfg_s.extrinsic_s.pos_x.cVal_ax[2] + calibrationData_t.zDelta_f32;

      // update mecl Camera
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x = mecl::math::toRadians_x(v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x);
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x   = mecl::math::toRadians_x(v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x);
      v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x  = mecl::math::toRadians_x(v_RealPinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x);

      v_RealPinholeCfg_s.extrinsic_s.preRoll_e             = v_DesignPinholeCfg_s.extrinsic_s.preRoll_e;
      v_RealPinholeCfg_s.extrinsic_s.rotationType_e        = v_DesignPinholeCfg_s.extrinsic_s.rotationType_e;

	  v_Result_b = getRealPinholeData_b(v_RealPinholeCfg_s) && v_Result_b;
	  v_Result_b = getRealSensorData_b(v_RealSensorCfg_s) && v_Result_b;
	  v_Result_b = getRealRadialLensData_b(v_RealLensRadialCfg_s) && v_Result_b;

      realPinhole_o.updateConfig_v(v_RealPinholeCfg_s);
      realSensor_o.updateConfig_v(v_RealSensorCfg_s);
      realLensRadial_o.updateConfig_v(v_RealLensRadialCfg_s);

      realCamera_o = mecl::Camera_t(realPinhole_o, realLensRadial_o, realSensor_o);

      isRealCameraInitialized_b = true;
    }
    else
    {
       printf("CameraParams::createRealCamera_b(): [CAM: %d] v_Result_b: %d\tisDesignCameraInitialized_b: %d\n", cameraID_t,v_Result_b, isDesignCameraInitialized_b);
    }
  }
	version_u32++;
  mutex_o.give_v();
  return isRealCameraInitialized_b;
}


bool_t CameraParams::createDesignCamera_b()
{
  mutex_o.take_b();

  if (isDesignCameraInitialized_b == false)
  {
    Pinhole_t::Config_s     v_PinholeCfg_s;
    LensRadial_t::Config_s  v_LensRadialCfg_s;
    Sensor_t::Config_s      v_SensorCfg_s;

    memset(&v_PinholeCfg_s, 0, sizeof(v_PinholeCfg_s));
    memset(&v_LensRadialCfg_s, 0, sizeof(v_LensRadialCfg_s));
    memset(&v_SensorCfg_s, 0, sizeof(v_SensorCfg_s));

    bool_t v_Success_b = getDesignCameraCfg_b(v_PinholeCfg_s, v_LensRadialCfg_s, v_SensorCfg_s);
    if ( v_Success_b != false)
    {
      designPinhole_o.updateConfig_v(v_PinholeCfg_s);

      designSensor_o.updateConfig_v(v_SensorCfg_s);

      designLensRadial_o.updateConfig_v(v_LensRadialCfg_s);

      designCamera_o = mecl::Camera_t(designPinhole_o, designLensRadial_o, designSensor_o);
      isDesignCameraInitialized_b = true;
    }
  }

  mutex_o.give_v();

  return isDesignCameraInitialized_b;
}

void CameraParams::applyCalibrationData_v(const CalibrationData_t& i_CalibrationData_rt)
{
  mutex_o.take_b();
  calibrationData_t = i_CalibrationData_rt;

  isRealCameraInitialized_b = false;
  mutex_o.give_v();

  createRealCamera_b();
}

void CameraParams::applyCameraErrorData_v(const CameraErrorData_t& i_CameraErrorData_rt)
{
  mutex_o.take_b();

  cameraIPCErrorData_t.Tested_u8             = i_CameraErrorData_rt.Tested_u8;
  cameraIPCErrorData_t.CamDataError_u8       = i_CameraErrorData_rt.CamDataError_u8;
  cameraIPCErrorData_t.CamOperationError_u8  = i_CameraErrorData_rt.CamOperationError_u8;
  cameraIPCErrorData_t.DESError_u8           = i_CameraErrorData_rt.DESError_u8;
  cameraIPCErrorData_t.I2CError_u8           = i_CameraErrorData_rt.I2CError_u8;
  cameraIPCErrorData_t.RunningStatus_u8      = i_CameraErrorData_rt.RunningStatus_u8;
  cameraIPCErrorData_t.PowerStatus_u8        = i_CameraErrorData_rt.PowerStatus_u8;

  mutex_o.give_v();
}

void CameraParams::applyCameraCRCError_v()
{
  mutex_o.take_b();
  cameraIPCErrorData_t.EepromCrcError_u8 = 1;
  mutex_o.give_v();
}

CameraErrorData_t  CameraParams::getCameraErrorData_v()
{
  CameraErrorData_t v_CameraErrorData_b;
  mutex_o.take_b();
  v_CameraErrorData_b = cameraIPCErrorData_t;
  mutex_o.give_v();
  return v_CameraErrorData_b;
}

void CameraParams::setEepromData_v(const CameraEepromData_t& i_EepromData_rt)
{
  mutex_o.take_b();
  eepromData_t = i_EepromData_rt;
  isEepromSet_b = true;
  mutex_o.give_v();
}

void CameraParams::setEepromIntrinsicData_v(const CamEepromIntrinsicData_t& i_EepromIntrinisicData_rt)
{
  mutex_o.take_b();
  eepromData_t.camIntrinsicData_s  = i_EepromIntrinisicData_rt;

  isEepromSet_b = true;
  mutex_o.give_v();
  createRealCamera_b();
}

const CameraEepromData_t& CameraParams::getEepromData_rt()
{
  return eepromData_t;
}

const mecl::Camera_t&  CameraParams::getDesignCamera_ro() const
{
  return designCamera_o;
}


bool_t CameraParams::getRealCameraCfg_b(Pinhole_t::Config_s&     o_PinholeCfg_rs,
                                        LensRadial_t::Config_s&  o_LensRadialCfg_rs,
                                        Sensor_t::Config_s&      o_SensorCfg_rs) const
{
  bool_t v_Success_b = false;

  if(isRealCameraInitialized_b == true)
  {
    realPinhole_o.copyConfig_v(o_PinholeCfg_rs);
    realSensor_o.copyConfig_v(o_SensorCfg_rs);
    realLensRadial_o.copyConfig_v(o_LensRadialCfg_rs);

    v_Success_b = true;
  }
  else
  {
    v_Success_b = getDesignCameraCfg_b(o_PinholeCfg_rs, o_LensRadialCfg_rs, o_SensorCfg_rs);
  }

  return v_Success_b;
}

bool_t CameraParams::getDesignCameraCfg_b(Pinhole_t::Config_s&     o_PinholeCfg_rs,
                                          LensRadial_t::Config_s&  o_LensRadialCfg_rs,
                                          Sensor_t::Config_s&      o_SensorCfg_rs) const
{
  bool_t v_Success_b = getRadialLensDesignData_b(o_LensRadialCfg_rs);
  v_Success_b        = getPinholeDesignData_b(o_PinholeCfg_rs) && v_Success_b;
  v_Success_b        = getSensorDesignData_b(o_SensorCfg_rs)   && v_Success_b;

  return v_Success_b;
}

mecl::Camera_t& CameraParams::getRealCamera_rt()
{
  mecl::Camera_t& v_RetCamera_rt = (isRealCameraInitialized_b == true) ? realCamera_o : designCamera_o;

  return v_RetCamera_rt;
}

bool_t CameraParams::getCameraInitializedStatus_t() const
{
  return isRealCameraInitialized_b;
}

bool_t CameraParams::getRealRadialLensData_b(LensRadial_t::Config_s& b_Config_ro) const
{
  uint32_t v_MaxPolySize_u32 = mecl::core::min_x(c_EepromIntrnisicPolySize_u32, static_cast<uint32_t>(variants::e_CoefficientsCount));

  if(isEepromSet_b == true)
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < v_MaxPolySize_u32; ++v_I_u32)
    {
      b_Config_ro.image2world_x[v_I_u32] = eepromData_t.camIntrinsicData_s.polyImage2World_af32[v_I_u32];
      b_Config_ro.world2image_x[v_I_u32] = eepromData_t.camIntrinsicData_s.polyWorld2Image_af32[v_I_u32];
    }

    // 0.5F multiplication is taken over from H2E code
    b_Config_ro.elevationMaxCfg_x = mecl::math::toDegrees_x(0.5F * eepromData_t.camIntrinsicData_s.fieldOfView_f32);
  }

  return (v_MaxPolySize_u32 == c_EepromIntrnisicPolySize_u32);
}

bool_t CameraParams::getRealPinholeData_b(Pinhole_t::Config_s& b_Config_ro) const
{
  if(isEepromSet_b == true)
  {
    b_Config_ro.intrinsic_s.foclX_x = eepromData_t.camIntrinsicData_s.effectiveFocalLength_f32;
    b_Config_ro.intrinsic_s.foclY_x = eepromData_t.camIntrinsicData_s.effectiveFocalLength_f32;

    // this is always 0/0 -> this is read out in Sensor
    b_Config_ro.intrinsic_s.pppCfg_x.cVal_ax[0] = 0.0F;
    b_Config_ro.intrinsic_s.pppCfg_x.cVal_ax[1] = 0.0F;
  }

  return true;
}

bool_t CameraParams::getDesignPinholeData_b(Pinhole_t::Config_s& b_Config_ro) const
{
	return ME_VariantHelper_GetCameraFocalLength_b(cameraID_t,&b_Config_ro.intrinsic_s.foclX_x,&b_Config_ro.intrinsic_s.foclY_x);
}

bool_t CameraParams::getDesignSensorData_b(Sensor_t::Config_s& b_Config_ro) const
{
	b_Config_ro.imageOriginPositionCfg_e = mecl::model::e_UpperLeft;
	bool_t v_Success_b = ME_VariantHelper_GetCameraPrincipalPoint_b(cameraID_t,&b_Config_ro.pppCfg_x.cVal_ax[0],&b_Config_ro.pppCfg_x.cVal_ax[1]);
	v_Success_b        = v_Success_b && ME_VariantHelper_GetCameraPixelSize_b(cameraID_t,&b_Config_ro.pszCfg_x.cVal_ax[0],&b_Config_ro.pszCfg_x.cVal_ax[1]);
  return v_Success_b;
}

bool_t CameraParams::getRealSensorData_b(Sensor_t::Config_s& b_Config_ro) const
{
  if(isEepromSet_b == true)
  {
    b_Config_ro.pppCfg_x.cVal_ax[0] = eepromData_t.camIntrinsicData_s.ppx_f32;
    b_Config_ro.pppCfg_x.cVal_ax[1] = eepromData_t.camIntrinsicData_s.ppy_f32;

    b_Config_ro.pszCfg_x.cVal_ax[0] = eepromData_t.camIntrinsicData_s.pixelSizeX_f32;
    b_Config_ro.pszCfg_x.cVal_ax[1] = eepromData_t.camIntrinsicData_s.pixelSizeY_f32;

    b_Config_ro.imageOriginPositionCfg_e = mecl::model::e_UpperLeft;

    b_Config_ro.pos1Cfg_x.cVal_ax[0] = 0.0F;
    b_Config_ro.pos1Cfg_x.cVal_ax[1] = 0.0F;

    b_Config_ro.pos2Cfg_x.cVal_ax[0] = static_cast<float32_t>(eepromData_t.camIntrinsicData_s.imageWidth_u32);
    b_Config_ro.pos2Cfg_x.cVal_ax[1] = static_cast<float32_t>(eepromData_t.camIntrinsicData_s.imageHeight_u32);
  }

  return true;
}

bool_t CameraParams::getRadialLensDesignData_b(LensRadial_t::Config_s& b_Config_ro) const
{
  bool_t v_Success_b = ME_VariantHelper_GetCameraLensMaxElevation_b(cameraID_t, &b_Config_ro.elevationMaxCfg_x);
  v_Success_b        = v_Success_b && ME_VariantHelper_GetCameraLensImageToWorld_b(cameraID_t, &b_Config_ro.image2world_x[0], variants::e_CoefficientsCount);
  v_Success_b        = v_Success_b && ME_VariantHelper_GetCameraLensWorldToImage_b(cameraID_t, &b_Config_ro.world2image_x[0], variants::e_CoefficientsCount);

  return v_Success_b;
}

bool_t CameraParams::getPinholeDesignData_b(Pinhole_t::Config_s& b_Config_ro) const
{
  bool_t v_Success_b = (cameraID_t < variants::e_CameraCount);

  if (true == v_Success_b)
  {
    // Extrinsic
//	  printf("CameraParams::getPinholeDesignData: Requested Camera is %d\n",cameraID_t);
    v_Success_b = ME_VariantHelper_GetCameraRotation_b(cameraID_t, &b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x, &b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x, &b_Config_ro.extrinsic_s.eulerAngles_s.roll_x);

    // convert from degrees (tool) to radians
    b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x = mecl::math::toRadians_x(b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x);
    b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x   = mecl::math::toRadians_x(b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x);
    b_Config_ro.extrinsic_s.eulerAngles_s.roll_x  = mecl::math::toRadians_x(b_Config_ro.extrinsic_s.eulerAngles_s.roll_x);

    v_Success_b = ME_VariantHelper_GetCameraPosition_b(cameraID_t, &b_Config_ro.extrinsic_s.pos_x.cVal_ax[0],
                                                       &b_Config_ro.extrinsic_s.pos_x.cVal_ax[1],
                                                       &b_Config_ro.extrinsic_s.pos_x.cVal_ax[2]) && v_Success_b;

    variants::PreRoll_t v_PreRoll_t         = variants::e_PreRollInvalid;
    variants::RotationType_t v_RotType_t    = variants::e_RotationTypeInvalid;

    v_Success_b = ME_VariantHelper_GetCameraPreRollAndRotType_b(cameraID_t, &v_PreRoll_t, &v_RotType_t) && v_Success_b;

    b_Config_ro.extrinsic_s.preRoll_e       = toMeclPreRoll_e(v_PreRoll_t);
    b_Config_ro.extrinsic_s.rotationType_e  = toMeclRotType_e(v_RotType_t);

    // Intrinsic is only focal length. principal point is set in sensor
    v_Success_b = ME_VariantHelper_GetCameraFocalLength_b(cameraID_t, &b_Config_ro.intrinsic_s.foclX_x,
                                                           &b_Config_ro.intrinsic_s.foclY_x) && v_Success_b;

    // this is always 0/0 -> this is read out in Sensor
    b_Config_ro.intrinsic_s.pppCfg_x.cVal_ax[0] = 0.0F;
    b_Config_ro.intrinsic_s.pppCfg_x.cVal_ax[1] = 0.0F;
  }

  return true;
}

bool_t CameraParams::getSensorDesignData_b(Sensor_t::Config_s& b_Config_ro) const
{
  bool_t v_Success_b = (cameraID_t < variants::e_CameraCount);

  if (true == v_Success_b)
  {
    v_Success_b = ME_VariantHelper_GetCameraPrincipalPoint_b(cameraID_t, &b_Config_ro.pppCfg_x.cVal_ax[0], &b_Config_ro.pppCfg_x.cVal_ax[1]);
    v_Success_b = ME_VariantHelper_GetCameraPixelSize_b(cameraID_t, &b_Config_ro.pszCfg_x.cVal_ax[0], &b_Config_ro.pszCfg_x.cVal_ax[1])               && v_Success_b;
    v_Success_b = ME_VariantHelper_GetCameraSensorAreaTopLeft_b(cameraID_t, &b_Config_ro.pos1Cfg_x.cVal_ax[0], &b_Config_ro.pos1Cfg_x.cVal_ax[1])     && v_Success_b;
    v_Success_b = ME_VariantHelper_GetCameraSensorAreaBottomRight_b(cameraID_t, &b_Config_ro.pos2Cfg_x.cVal_ax[0], &b_Config_ro.pos2Cfg_x.cVal_ax[1]) && v_Success_b;

    variants::ImageOriginPosition_t v_ImageOrigin_t = variants::e_ImageOriginPositionInvalid;
    v_Success_b = ME_VariantHelper_GetCameraImageOrigin_b(cameraID_t, &v_ImageOrigin_t) && v_Success_b;
    b_Config_ro.imageOriginPositionCfg_e = toMeclImageOrigin_e(v_ImageOrigin_t);
  }

  return v_Success_b;
}

mecl::model::PreRoll_e CameraParams::toMeclPreRoll_e(variants::PreRoll_t i_PreRoll_t)
{
  mecl::model::PreRoll_e v_MeclPreRoll_e = mecl::model::e_PreRoll0;

  switch (i_PreRoll_t)
  {
  case variants::e_PreRoll0       : { v_MeclPreRoll_e = mecl::model::e_PreRoll0;                    } break;
  case variants::e_PreRoll90      : { v_MeclPreRoll_e = mecl::model::e_PreRoll90;                   } break;
  case variants::e_PreRoll180     : { v_MeclPreRoll_e = mecl::model::e_PreRoll180;                  } break;
  case variants::e_PreRoll270     : { v_MeclPreRoll_e = mecl::model::e_PreRoll270;                  } break;
  case variants::e_PreRollCount   : { v_MeclPreRoll_e = mecl::model::e_PreRoll0;    Assert(false);  } break;
  case variants::e_PreRollInvalid : { v_MeclPreRoll_e = mecl::model::e_PreRoll0;    Assert(false);  } break;
  default                         : { v_MeclPreRoll_e = mecl::model::e_PreRoll0;    Assert(false);  } break;
  }

  return v_MeclPreRoll_e;
}

mecl::model::RotationType_e CameraParams::toMeclRotType_e(variants::RotationType_t i_RotType_t)
{
  mecl::model::RotationType_e v_MeclRotType_e = mecl::model::e_WorldToCamera;

  switch (i_RotType_t)
  {
  case variants::e_WorldToCamera        : { v_MeclRotType_e = mecl::model::e_WorldToCamera;                    } break;
  case variants::e_CameraToWorld        : { v_MeclRotType_e = mecl::model::e_CameraToWorld;                    } break;
  case variants::e_RotationTypeCount    : { v_MeclRotType_e = mecl::model::e_WorldToCamera;    Assert(false);  } break;
  case variants::e_RotationTypeInvalid  : { v_MeclRotType_e = mecl::model::e_WorldToCamera;    Assert(false);  } break;
  default                               : { v_MeclRotType_e = mecl::model::e_WorldToCamera;    Assert(false);  } break;
  }

  return v_MeclRotType_e;
}

mecl::model::ImageOriginPosition_e CameraParams::toMeclImageOrigin_e(variants::ImageOriginPosition_t i_ImageOrigin_t)
{
  mecl::model::ImageOriginPosition_e v_MeclImageOrigin_e = mecl::model::e_UpperLeft;

  switch (i_ImageOrigin_t)
  {
  case variants::e_UpperLeft                  : { v_MeclImageOrigin_e = mecl::model::e_UpperLeft;                     } break;
  case variants::e_UpperRight                 : { v_MeclImageOrigin_e = mecl::model::e_UpperRight;                    } break;
  case variants::e_LowerLeft                  : { v_MeclImageOrigin_e = mecl::model::e_LowerLeft;                     } break;
  case variants::e_LowerRight                 : { v_MeclImageOrigin_e = mecl::model::e_LowerRight;                    } break;
  case variants::e_ImageOriginPositionCount   : { v_MeclImageOrigin_e = mecl::model::e_UpperLeft;    Assert(false);   } break;
  case variants::e_ImageOriginPositionInvalid : { v_MeclImageOrigin_e = mecl::model::e_UpperLeft;    Assert(false);   } break;
  default                                     : { v_MeclImageOrigin_e = mecl::model::e_UpperLeft;    Assert(false);   } break;
  }

  return v_MeclImageOrigin_e;
}



bool_t CameraParams::isRealMeclCameraInitalized_b() const
{
  return isRealCameraInitialized_b;
}
uint32_t CameraParams::getRealCameraCfgVersion_t() const
{
  return version_u32;
}


} // namespace sensor
