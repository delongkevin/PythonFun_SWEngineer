//--------------------------------------------------------------------------
/// @file CameraCalibRecRunnable.h
/// @brief Contains the camera calibration receiver part update.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady(ananda.kavradi@magna.com)
///
///
//  --------------------------------------------------------------------------

#ifndef CAMERA_CALIB_RECEIVER_RUNNABLE_H_
#define CAMERA_CALIB_RECEIVER_RUNNABLE_H_

#include <bsp/io/tiovx/TIOVXHost.h>
#include <container/JobBase.h>
#include <osal/threading/IRunnable.h>
#include "platform/PlatformAPI.h"
#include <sensor/CameraBase.h>
#include <cfg/CamTypes.h>


namespace tiovx
{

  class IDataProviderTIOVX;

  class CameraCalibRecRunnable : public osal::IRunnable //, public EventListener
  {
  public:
    explicit CameraCalibRecRunnable(IDataProviderTIOVX& i_DataProvider_ro, bsp::TIOVXHost* i_tiovx_po);
    virtual ~CameraCalibRecRunnable();

    virtual void   init_v() ME_OVERRIDE;
    virtual bool_t run_b() ME_OVERRIDE;
    virtual void   cleanup_v() ME_OVERRIDE;

  public:
  void updateCamCaliberation_v();
  void updateCamError_v();


  public:

    IDataProviderTIOVX&                 dataProvider_ro;
    bsp::TIOVXHost*                    tiovx_po;
    osal::Mutex                        mutex_o;
    sensor::CameraBase*    cameras_ao[(variants::e_CameraCount -1)];
  };
} // namespace tiovx

#endif // CAMERA_CALIB_RECEIVER_RUNNABLE_H_
