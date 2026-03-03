//--------------------------------------------------------------------------
/// @file JobTIOVX.cpp
/// @brief Contains the job definition for the TIOVX Host. Central Manager for setting axi registers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#include "JobTIOVX.h"

#include "cfg/DataProvider/DataProviderTIOVX.h"

#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_TIOVX   (1u)
#endif
#if PROFILE_TIOVX
#include "osal/system/Clock.h"
static uint32_t v_AvgTIOVXRuntime_u32 = 0;
static uint32_t v_TIOVXRunCntr_u32 = 0;
static uint32_t v_AvgTIOVXPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_TIOVXRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif

namespace tiovx
{

static ThreadHandle_s v_Thread_t;

JobTIOVX::JobTIOVX(container::JobDesc_s& b_JobDesc_rs, IDataProviderTIOVX& b_DataProvider_ro)
  : JobBase(b_JobDesc_rs, b_DataProvider_ro)
  , initialized_b(false)
  , tiovx_po(NULL)
  , tiovxHandler_o(b_DataProvider_ro)
  , tiovxThread_o("TIOVXHandlerThread")
  , cameraCalibThread_o("CameraCalibRecThread")
  , CameraCalibRecRunnable_o(b_DataProvider_ro, tiovx_po)
  , viewId_t(variants::e_ServiceHelper_E_HMIView_NoView)
  , mutex_o()
{
}

JobTIOVX::~JobTIOVX()
{

}
#if 0
sensor::CameraState_e JobTIOVX::getCamera_e(uint32_t v_I_u32)
{
  sensor::CameraBase& v_Camera_ro = dataProvider_ro.getCamera_ro(static_cast<variants::Camera_t>(v_I_u32));

  return v_Camera_ro.getCameraState_e();
}
#endif

bool_t JobTIOVX::onInit_b()
{    
  bool_t v_Result_b = false;

  tiovx_po = &dataProvider_ro.getTIOVX_ro();

  if (tiovx_po != NULL)
  {
    v_Result_b = dataProvider_ro.init_b(0);
  }

  dataProvider_ro.setCamEepromDataArray_v();

  ME_Debugger_F_Printf_v("Intrinsics applied \n");

  mutex_o.take_b();

  if(false == dataProvider_ro.getCamDataInitStatus())
  {
    // considered only 4 cameras.
    for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount-1); v_I_u32++)
    {
      cameras_ao[v_I_u32] = &dataProvider_ro.getCamera_ro(static_cast<variants::Camera_t>(v_I_u32));
    }

    for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount-1); v_I_u32++)
    {
      if(!cameraInit_ab[v_I_u32])
      {
        if(cameras_ao[v_I_u32] != NULL)
        {
          if(cameras_ao[v_I_u32]->open_b() == true)
          {
            cameras_ao[v_I_u32]->run_b();
            cameraInit_ab[v_I_u32] = true;
          }
        }
      }
    }
  }
  else
  {
    ME_Debugger_F_Printf_v("TIOVX: Error in camera initialization \n");
    //This is to check all other apps should start after tivox and  access camera params.
  }
  mutex_o.give_v();

  //Periodically check and update the camera  calibration data.

  startThread_v();
  return v_Result_b;
}


void JobTIOVX::onVariantChanged_v(bool_t i_FirstTime_b)
{

}


bool_t JobTIOVX::onRun_b()
{
#if PROFILE_TIOVX
        PerformanceStatsEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
        static osal::Time start;
        volatile uint32_t v_Start_t = 0;
        volatile uint32_t v_End_t = 0;
        volatile uint32_t currPeriodicity = 0;
        if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
        {
          v_Start_t = __get_time_usec();
          currPeriodicity = v_Start_t - v_PreviousTime_u32;
        }
#endif
  static bool_t v_CamerasStarted_b = false;
  if (!v_CamerasStarted_b)
  {
      v_CamerasStarted_b = true;
      dataProvider_ro.start_cameras();
  }
//  ME_Debugger_F_Printf_v("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
  ME_Thread_Sleep_t(5);
#if PROFILE_TIOVX
        if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
        {
          v_End_t = __get_time_usec();
          //ME_Debugger_F_Printf_v("TIOVX: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
          v_TIOVXRunCntr_u32++; //Increment the run counter for averaging purpose
          v_AvgTIOVXPeriodicity_u32 = ((v_AvgTIOVXPeriodicity_u32 * (v_TIOVXRunCntr_u32 -1)) + currPeriodicity)/v_TIOVXRunCntr_u32; //Average Periodicity
          v_AvgTIOVXRuntime_u32 = ((v_AvgTIOVXRuntime_u32 * (v_TIOVXRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_TIOVXRunCntr_u32; //New Average  
          v_TIOVXRuntimeData = (((v_AvgTIOVXRuntime_u32/1000U)<<16U) | ((v_AvgTIOVXPeriodicity_u32/1000U) & 0xFFFF));
          dataProvider_ro.setTIOVXRuntime(v_TIOVXRuntimeData);
          //ME_Debugger_F_Printf_v("TIOVX: E: %lld P: %lld \n", v_AvgTIOVXRuntime_u32, v_AvgTIOVXPeriodicity_u32);
          v_PreviousTime_u32 = v_Start_t;
        }
#endif
  return true;
}

void JobTIOVX::onCleanup_v()
{
   terminateThreads_v();
}

void JobTIOVX::startThread_v()
{
  cameraCalibThread_o.start_v(&CameraCalibRecRunnable_o);
  cameraCalibThread_o.setPriority_v(e_PriorityNormal);
}

void JobTIOVX::terminateThreads_v()
{
  cameraCalibThread_o.terminate_v();
}

void JobTIOVX::handleDataChanged_v(container::OpCodeDataChanged_e i_DataChanged_e)
{

}
  
} // namespace tiovx

