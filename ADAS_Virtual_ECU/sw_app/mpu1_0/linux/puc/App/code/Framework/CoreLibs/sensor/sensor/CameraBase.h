//--------------------------------------------------------------------------
/// @file CameraBase.h
/// @brief Defines a general interface implementation for cameras
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

#ifndef CAMERA_BASE_H_
#define CAMERA_BASE_H_

#include "SensorBase.h"
#include "IspBase.h"
#include "CameraParams.h"

#include "devices/IDevice.h"

#include "cfg/CamTypes.h"

#include <variants/Enums.h>
#include <variants/VariantHelper.h>

namespace sensor
{

  class CameraBase : public SensorBase
  {
  public:

    CameraBase();

    virtual ~CameraBase();

    // ----------------------------------------------------------------------------------------------------------------------------
    // control functions

    virtual bool_t         open_b() = 0;

    virtual bool_t         close_b() = 0;

    virtual bool_t         run_b() = 0;

    virtual bool_t         stop_b() = 0;

    // ----------------------------------------------------------------------------------------------------------------------------
    // Sub devices

    
    IspBase*                               getIsp_po() const;

    IDevice<uint32_t>*                     getDevice_po(variants::CameraDevice_t i_Device_e);

    virtual bool_t                         getEepromData_b(CameraEepromData_t& o_EepromData_rt) = 0;

    // ----------------------------------------------------------------------------------------------------------------------------
    // Setter

    bool_t                                 setDevice_b(variants::CameraDevice_t i_Device_t, IDevice<uint32_t>& i_Device_ro);

    // --------------------------------------------------------------------------
    /// set video mode (human or machine vision)
    ///
    /// @return bool_t
    // --------------------------------------------------------------------------
    virtual bool_t                         setVideoMode_b(VideoMode_e i_VideoMode_e) = 0;

    // --------------------------------------------------------------------------
    /// set power mode per camera
    ///
    /// @return bool_t
    // --------------------------------------------------------------------------
    virtual bool_t                         setPowerMode_b(variants::CameraPowerMode_t i_CameraPowerMode_e) = 0;

    // --------------------------------------------------------------------------
    /// set test pattern mode per camera
    ///
    /// @return bool_t
    // --------------------------------------------------------------------------
    virtual bool_t                         setTestPatternMode_b(variants::CamTestPattern_t i_TestPatternMode_e) = 0;

    // --------------------------------------------------------------------------
    /// change camera state per camera
    ///
    /// @return bool_t
    // --------------------------------------------------------------------------
    virtual void                           setCameraState_v(CameraState_e i_CameraState_e) = 0;

    // ----------------------------------------------------------------------------------------------------------------------------
    // Getter

  public:

    variants::Camera_t                     getCameraId_t() const;

    variants::CameraPowerMode_t            getCameraPowerMode_t() const;

    variants::CamTestPattern_t             getCameraTestPatternMode_t() const;

    const CameraErrorData_t&               getCameraErrorData_rt() const;

    CameraState_e                          getCameraState_e() const;

    CameraParams&                          getCameraParams_ro();

  protected:

    osal::Mutex                            mutex_o;

    variants::Camera_t                     cameraID_t;

    CameraErrorData_t                      cameraErrorData_t;

    variants::CameraPowerMode_e            cameraPowerMode_t;

    variants::CamTestPattern_t             cameraTestPattern_t;

    CameraState_e                          cameraState_e;

    CameraParams                           cameraParams_o;

    /// Sub devices

    IspBase*                               isp_po;

    IDevice<uint32_t>*                     deviceList_ao[variants::e_CameraDeviceCount];

  }; // class CameraBase

} // namespace sensor

#endif // CAMERA_BASE_H_
