//--------------------------------------------------------------------------
/// @file JobTIOVX.h
/// @brief Contains the job definition for the TIOVX Manager. Central Manager for setting axi registers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#ifndef JOB_TIOVX_H
#define JOB_TIOVX_H

#include "IDataProviderTIOVX.h"
#include <osal/threading/Thread.h>
#include "cfg/TIOVXHandlerThread.h"
#include <bsp/io/tiovx/TIOVXHost.h>
#include <sensor/CameraBase.h>
#include <cfg/CamTypes.h>
#include "CameraCalibRecRunnable.h"

#include <container/JobBase.h>

namespace tiovx
{

class JobTIOVX : public container::JobBase<IDataProviderTIOVX>
{

public:
#if 0
  static void*  fpgaBufferCaptureThread_pv(void* arg);

  static void*  cameraWatchdogThread_pv(void* v_Arg_pv);
#endif
public:
  explicit JobTIOVX(container::JobDesc_s& b_JobDesc_rs, IDataProviderTIOVX& b_DataProvider_ro);
  virtual ~JobTIOVX();

  // JobBase implementation
  virtual bool_t        onInit_b() ME_OVERRIDE;
  virtual void          onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t        onRun_b() ME_OVERRIDE;
  virtual void          onCleanup_v() ME_OVERRIDE;

  virtual void          handleDataChanged_v(container::OpCodeDataChanged_e i_DataChanged_e);

private:

  sensor::CameraState_e getCamera_e(uint32_t v_I_u32);

  void                  checkView_v();

  void                  checkCamera_v();
  virtual void          startThread_v();
  virtual void          terminateThreads_v();
//  virtual void          getCamEepromDataArray_v();

private:

  bool_t                             initialized_b;

  bsp::TIOVXHost*                    tiovx_po;
  TIOVXHandlerThread                 tiovxHandler_o;
  osal::Thread                       tiovxThread_o;

  osal::Thread                               cameraCalibThread_o;
  CameraCalibRecRunnable                     CameraCalibRecRunnable_o;

  variants::ViewId_t                 viewId_t;
  osal::Mutex                        mutex_o;

  sensor::CameraBase*    cameras_ao[(variants::e_CameraCount -1)];

  bool_t                 cameraInit_ab[(variants::e_CameraCount -1)];

};
} // namespace tiovx

#endif // JOB_TIOVX_H

