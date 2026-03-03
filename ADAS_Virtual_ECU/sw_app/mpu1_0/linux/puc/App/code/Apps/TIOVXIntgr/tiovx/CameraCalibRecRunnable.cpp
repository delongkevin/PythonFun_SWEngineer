//--------------------------------------------------------------------------
/// @file CameraCalibRecRunnable.cpp
/// @brief Contains the camera calibration receiver part update
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


#include "CameraCalibRecRunnable.h"

#include "IDataProviderTIOVX.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_CameraCalibRecThread   (1u)
#endif
#if PROFILE_CameraCalibRecThread
#include "osal/system/Time.h"
static uint32_t v_AvgCamCalibRuntime_u32 = 0;
static uint32_t v_CamCalibRunCntr_u32 = 0;
static uint32_t v_AvgCamCalibPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_CamCalibRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsCcEnable_dp;
#endif

namespace tiovx
{

namespace tiovxconsts
{
  const uint64_t c_SenderThresholdMS_u64 = 100;
  const uint32_t c_EepromRetryCount_u32 = 300;
} //names

CameraCalibRecRunnable::CameraCalibRecRunnable(IDataProviderTIOVX& i_DataProvider_ro, bsp::TIOVXHost *i_tiovx_po)
: IRunnable()
, dataProvider_ro(i_DataProvider_ro)
, tiovx_po(i_tiovx_po)
, mutex_o()
{

}

CameraCalibRecRunnable::~CameraCalibRecRunnable()
{

}

/// @brief  Render thread initialization
void CameraCalibRecRunnable::init_v()
{
}

/// @brief  Thread processing function
bool_t CameraCalibRecRunnable::run_b()
{
  #if PROFILE_CameraCalibRecThread
        PerformanceStatsCcEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
        static osal::Time start;
        volatile uint32_t v_Start_t = 0;
        volatile uint32_t v_End_t = 0;
        volatile uint32_t currPeriodicity = 0;
        if (TRUE ==  PerformanceStatsCcEnable_dp.RunTimeStatsEnable)
        {
          v_Start_t = __get_time_usec();
          currPeriodicity = v_Start_t - v_PreviousTime_u32;
        }
  #endif
  
  static uint32_t  CamEepromCount = 0u;
  static uint8_t printCount = 1u;
  CamHotplugStatus_t CamStatus = {0};
  static CamHotplugStatus_t prev_CamStatus = {0};
  
  CamStatus = dataProvider_ro.getCamHotplugStatus_v();
  
  if((memcmp(&prev_CamStatus, &CamStatus, sizeof(CamHotplugStatus_t))) != 0u)
  {
    prev_CamStatus = CamStatus;
    CamEepromCount = 0;
    /*printf("\n A72:Camera EEPROM read on Hotplug:[%u %u %u %u %u]\n",CamStatus.CamStatus[0], CamStatus.CamStatus[1], CamStatus.CamStatus[2], CamStatus.CamStatus[3], CamStatus.CamStatus[4]);*/
  }
  else
  {
    /* Nothing to do*/
  }    

  if(CamEepromCount < tiovxconsts::c_EepromRetryCount_u32)
  {
    mutex_o.take_b();
    dataProvider_ro.setCamEepromDataArray_v();
    mutex_o.give_v();
    CamEepromCount++;
  }
  else if( printCount == 1u ) 
  { 
     ME_Debugger_F_Printf_v("CameraCalibRecRunnable: stoping read eeprom retry\n");
     printCount = 0u;
  }

  updateCamCaliberation_v();
  
  //updateCamError_v();

  //bsp::TIOVXVideoInput &v_input_ro = tiovx_o.getVideoInput_ro();

  //CamFailID_u8 = v_input_ro.getSvsFailureMask_u8();
  
  //dataProvider_ro.setCameraFailure_v(CamFailID_u8);

  // return true to signal to be called again

  ME_Thread_Sleep_t(tiovxconsts::c_SenderThresholdMS_u64);

  #if PROFILE_CameraCalibRecThread
    if (TRUE ==  PerformanceStatsCcEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      //ME_Debugger_F_Printf_v("CameraCalib: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_CamCalibRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgCamCalibPeriodicity_u32 = ((v_AvgCamCalibPeriodicity_u32 * (v_CamCalibRunCntr_u32 -1)) + currPeriodicity)/v_CamCalibRunCntr_u32; //Average Periodicity
      v_AvgCamCalibRuntime_u32 = ((v_AvgCamCalibRuntime_u32 * (v_CamCalibRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_CamCalibRunCntr_u32; //New Average  
      //ME_Debugger_F_Printf_v("CamCalib: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_CamCalibRuntimeData = (((v_AvgCamCalibRuntime_u32/1000U)<<16U) | ((v_AvgCamCalibPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setCamCalibRuntime(v_CamCalibRuntimeData);
      //ME_Debugger_F_Printf_v("CamCalib: E: %lld P: %lld \n", v_AvgCamCalibRuntime_u32, v_AvgCamCalibPeriodicity_u32);
      v_PreviousTime_u32 = v_Start_t;
    }
  #endif

  return true;
}

void CameraCalibRecRunnable::cleanup_v()
{
}



void CameraCalibRecRunnable::updateCamCaliberation_v()
{
  Svs_CamEepromDataArray_t 	svs_CamEepromDataArray_t = dataProvider_ro.getCamEepromDataArray_v();
  sensor::CamEepromIntrinsicData_t v_CamEepromIntrinsicData_b;

  for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount-1); v_I_u32++)
  {
    memset(&v_CamEepromIntrinsicData_b, 0, sizeof(sensor::CamEepromIntrinsicData_t));

    memcpy(&v_CamEepromIntrinsicData_b, &(svs_CamEepromDataArray_t.CameraEepromData[v_I_u32].SVSIntrinsicData_s), sizeof(sensor::CamEepromIntrinsicData_t));
	//uint32_t version_temp32 = 0U;
	mutex_o.take_b();
	cameras_ao[v_I_u32] = &dataProvider_ro.getCamera_ro(static_cast<variants::Camera_t>(v_I_u32));
	cameras_ao[v_I_u32]->getCameraParams_ro().setEepromIntrinsicData_v(v_CamEepromIntrinsicData_b);
	mutex_o.give_v();

  }

  dataProvider_ro.updateCamCaliberationData_v();

}

void CameraCalibRecRunnable::updateCamError_v()
{
//  dataProvider_ro.updateCameraErrorData_v();

}

} // namespace tiovx
