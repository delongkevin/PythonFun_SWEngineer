/// --------------------------------------------------------------------------
/// @file THAThread.h
/// @brief Contains THAThread class is an algorithm container to separate algo and framework
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------

#ifndef THA_THREAD_H_
#define THA_THREAD_H_

#include <platform/PlatformAPI.h>
#include <container/JobBase.h>
#include <osal/threading/IRunnable.h>
#include <variants/Enums.h>
#include "IDataProviderTHA.h"

#ifdef APP_TIDL_TRACE_DUMP
#include <tivx_utils_tidl_trace.h>
#endif

#include "modules/include/app_common.h"

#include "TI/tivx_debug.h"
#include <variants/Components.h>
#include <variants/Assets.h>
#include "osal/system/Clock.h"

extern "C" {
#include <app_init.h>
#include "modules/include/THA_TI.h"
}
#include "algo/inc/JobTHADetOutput.h"
#include "algo/inc/JobTHAInput.h"
#include "mecl/core/MeclTypes.h"
#include "algo/inc/StateProcess.h"

namespace tha
{
class IDataProviderTHA;

class THAThreadRunnable: public osal::IRunnable
{

public:
  explicit THAThreadRunnable(IDataProviderTHA &b_DataProvider_ro);
  virtual ~THAThreadRunnable();

  virtual void init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void cleanup_v() ME_OVERRIDE;
  static void stop_v();
  AppObj_CD_HD TIObj_s_CD_HD;
  AppObj_TrailerPose TIObj_s_TrailerPose;

private:
  vx_status app_tidl_CD_HD();
  vx_status app_tidl_TrailerPose();
  

  void startTHA();
  void executeTHA();
  void endTHA();
  void reset_v();
  /*
    * State process configuration
  */
        StateProcessConfig m_StateProcessCfg;

  /*
  * Detection state process
  */
  StateProcess m_StateProcess;
  do_CameraParam m_aCameraInfo;

  IDataProviderTHA &dataProvider_ro;
  /*
  * Job inputs
  */
  JobTHAInput_t m_JobTHAInput;

  /*
  * Job outputs
  */
  JobTHAAlgoDetOutput_t m_JobTHADetOutput;
  JobTHAAlgoDetDebug_t m_JobTHADetDebugOutput;

  /*
  * Image info
  */
  uint16_t m_ImgWidth;
  uint16_t m_ImgHeight;
  /*
  * Start & last processed frame number
  */
  uint32_t m_JobLastTrailerFrameNum;
  
};

} //namespace tha

#endif // THA_THREAD_H_
