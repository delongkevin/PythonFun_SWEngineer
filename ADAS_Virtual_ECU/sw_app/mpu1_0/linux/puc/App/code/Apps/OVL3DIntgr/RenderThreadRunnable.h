//--------------------------------------------------------------------------
/// @file RenderThread.h
/// @brief Separate RenderThread needed. This needs to be synced with the Job's Shared Memory data via Locks
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OVL3D_RENDER_THREAD_H
#define OVL3D_RENDER_THREAD_H

#include <platform/PlatformAPI.h>

#include <container/JobBase.h>
#include <bsp/graphics/Window.h>
#include <bsp/graphics/Screen.h>
#include <EGL/egl.h>
#define EGL_EGLEXT_PROTOTYPES
#include <EGL/eglext.h>
#include <GLES2/gl2.h>

#include <osal/threading/IRunnable.h>
#include "osal/threading/Mutex.h"

#include "sv.h"
typedef ovl3d::sv sv_t;

// PRQA S 2100 EOF // public members in struct used here by design
// PRQA S 1120 EOF // Scoped enumartions are fine c++11 or greater support

namespace ovl3d
{
  struct RenderThreadData_s
  {
    float32_t steeringAngle_f32;
    float32_t vehicleSpeed_f32;

    RenderThreadData_s()
      : steeringAngle_f32(0.0f)
      , vehicleSpeed_f32(20.0f)
    {
    }
  };

  enum RenderThreadUpdateFlag_e : uint32_t
  {
    e_RtufSteeringAngle   = 1 << 0, // 0000 0000 0000 0000 0000 0000 0000 0001
    e_RtufVehicleSpeed    = 1 << 1, // 0000 0000 0000 0000 0000 0000 0000 0010
    e_RtufViewId          = 1 << 2, // 0000 0000 0000 0000 0000 0000 0000 0100
    e_RtufChassisColor    = 1 << 3, // 0000 0000 0000 0000 0000 0000 0000 1000
    e_RtufRotateCamera    = 1 << 5, // 0000 0000 0000 0000 0000 0000 0010 0000
    e_RtufModelFile       = 1 << 6, // 0000 0000 0000 0000 0000 0000 0100 0000
    e_RtufTogglePlayPause = 1 << 7, // 0000 0000 0000 0000 0000 0000 1000 0000
    e_VufAll              = e_RtufSteeringAngle | e_RtufVehicleSpeed | e_RtufViewId | e_RtufChassisColor | e_RtufRotateCamera | e_RtufModelFile | e_RtufTogglePlayPause
  };


  enum ModelFade_e
  {
    e_NoFade,
    e_FadeIn,
    e_FadeOut
  };

  enum CameraMovementState_e
  {
    e_CmsIdle,
    e_CmsRotateAroundCar,
    e_CmsMoveToTopViewpoint
  };

  class IDataProviderOvl3D;

  class RenderThreadRunnable : public osal::IRunnable //, public EventListener
  {
  public:
    explicit RenderThreadRunnable(IDataProviderOvl3D& i_DataProvider_ro);
    virtual ~RenderThreadRunnable();

    virtual void   init_v() ME_OVERRIDE;
    virtual bool_t run_b() ME_OVERRIDE;
    virtual void   cleanup_v() ME_OVERRIDE;

    static void stop_v();

    //void syncThreadData_v(const RenderThreadData_s& i_Data_rs);


//    void onKeyFrameReached_v(const KeyFrameReachedEvent* i_Event_po);

  //private:
  public:
    IDataProviderOvl3D&                 dataProvider_ro;
    bsp::Screen                         screen_o;
    bsp::Window                         window_o;
    bool_t                              isRunning_b;
    RenderThreadData_s                  data_s;
    osal::Mutex                         dataMutex_o;
    bool_t                              isPlaying_b;
    sv_t                               	sv;

    struct StreamInfo_s
    {
      Buffer_t                         buffer_at[NUM_CAM_BUFS];
      Pixmap_t                         pixmap_at[NUM_CAM_BUFS];
      uint32_t                         streamId_u32[NUM_CAM_BUFS];
    };

    StreamInfo_s                       stream_o[NUM_CAMERAS + 1];

  };
} // namespace ovl3d

#endif // OVL3D_RENDER_THREAD_H
