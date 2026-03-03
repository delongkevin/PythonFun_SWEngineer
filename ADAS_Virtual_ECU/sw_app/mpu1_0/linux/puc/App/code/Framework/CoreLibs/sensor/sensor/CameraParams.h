//--------------------------------------------------------------------------
/// @file CameraParams.h
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

#ifndef CAMERA_PARAMS_H_
#define CAMERA_PARAMS_H_

#include "cfg/CamTypes.h"
#include <osal/threading/Mutex.h>
#include <mecl/meclcfg.h>

namespace sensor
{


class CameraParams
{
public:

  CameraParams();

  ~CameraParams();

  bool_t         init_b(variants::Camera_t i_CameraId_t);

  // ----------------------------------------------------------------------------------------------------------------------------
  // Updates the Mecl Camera based on variants or eeprom data (if crc check succeeded).

  // --------------------------------------------------------------------------
  /// Updates intrinsic and extrinsic camera parameters (either design values or eeprom data)
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t         createRealCamera_b();

  // --------------------------------------------------------------------------
  /// Creates the camera object for the design camera and performs an initial configuration
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t         createDesignCamera_b();

public:

  // --------------------------------------------------------------------------
  /// set extrinsic calibration data
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  void           applyCalibrationData_v(const CalibrationData_t& i_CalibrationData_rt);

  // --------------------------------------------------------------------------
  /// set camera  CameraError data
  ///
  /// @return void
  // --------------------------------------------------------------------------
  void           applyCameraErrorData_v(const CameraErrorData_t& i_CameraErrorData_rt);

  // --------------------------------------------------------------------------
   /// set camera  CRC error
   ///
   /// @return void
   // --------------------------------------------------------------------------
   void           applyCameraCRCError_v();

  // --------------------------------------------------------------------------
  /// get camera  CameraError data
  ///
  /// @return CameraErrorData_t
  // --------------------------------------------------------------------------
  CameraErrorData_t   getCameraErrorData_v();

  // --------------------------------------------------------------------------
  /// set intrinsic eeprom data
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  void           setEepromData_v(const CameraEepromData_t& i_EepromData_rt);

  // --------------------------------------------------------------------------
  /// set intrinsic eeprom data
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  const CameraEepromData_t& getEepromData_rt();

  // --------------------------------------------------------------------------
  /// set intrinsic eeprom data from app
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  void           setEepromIntrinsicData_v(const CamEepromIntrinsicData_t& i_EepromIntrinisicData_rt);


public:

  mecl::Camera_t&                  getRealCamera_rt();

  bool_t                           getCameraInitializedStatus_t() const;

  const mecl::Camera_t&            getDesignCamera_ro() const;

  // --- EEPROM Data to MECL ---
  bool_t                           getRealRadialLensData_b(LensRadial_t::Config_s& b_Config_ro) const;

  bool_t                           getRealPinholeData_b(Pinhole_t::Config_s& b_Config_ro) const;

  bool_t                           getRealSensorData_b(Sensor_t::Config_s& b_Config_ro) const;

  // --- Variant Data to MECL ---
  bool_t                           getRadialLensDesignData_b(LensRadial_t::Config_s& b_Config_ro) const;
                                   
  bool_t                           getPinholeDesignData_b(Pinhole_t::Config_s& b_Config_ro) const;
                                   
  bool_t                           getSensorDesignData_b(Sensor_t::Config_s& b_Config_ro) const;
                                   
  bool_t                           getRealCameraCfg_b(Pinhole_t::Config_s&     o_PinholeCfg_rs,
                                                      LensRadial_t::Config_s&  o_LensRadialCfg_rs,
                                                      Sensor_t::Config_s&      o_SensorCfg_rs) const;

  bool_t                           getDesignCameraCfg_b(Pinhole_t::Config_s&     o_PinholeCfg_rs,
                                                        LensRadial_t::Config_s&  o_LensRadialCfg_rs,
                                                        Sensor_t::Config_s&      o_SensorCfg_rs) const;

  bool_t 						   getDesignPinholeData_b(Pinhole_t::Config_s& b_Config_ro) const;
  bool_t 							getDesignSensorData_b(Sensor_t::Config_s& b_Config_ro) const;

  // --------------------------------------------------------------------------
  /// returns boolean to check whether the real MECL camera object is already initialized or not
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t                           isRealMeclCameraInitalized_b() const;
  uint32_t   getRealCameraCfgVersion_t() const;


private:

  /// Helper functions

  static mecl::model::PreRoll_e             toMeclPreRoll_e(variants::PreRoll_t i_PreRoll_t);

  static mecl::model::RotationType_e        toMeclRotType_e(variants::RotationType_t i_RotType_t);

  static mecl::model::ImageOriginPosition_e toMeclImageOrigin_e(variants::ImageOriginPosition_t i_ImageOrigin_t);

private:

  variants::Camera_t            cameraID_t;

  // --- Mecl Camera Types ---
  Pinhole_t                     realPinhole_o;
  LensRadial_t                  realLensRadial_o;
  Sensor_t                      realSensor_o;
  mecl::Camera_t                realCamera_o;
  bool_t                        isRealCameraInitialized_b;

  Pinhole_t                     designPinhole_o;
  LensRadial_t                  designLensRadial_o;
  Sensor_t                      designSensor_o;
  mecl::Camera_t                designCamera_o;
  bool_t                        isDesignCameraInitialized_b;

  // Delta values from calibration
  CalibrationData_t             calibrationData_t;

  CameraErrorData_t             cameraIPCErrorData_t;

  // Eeprom Data
  CameraEepromData_t            eepromData_t;
  bool_t                        isEepromSet_b;
  uint32_t                      version_u32;
  osal::Mutex                   mutex_o;

};

} // namespace sensor

#endif // CAMERA_PARAMS_H_
