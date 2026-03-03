//--------------------------------------------------------------------------
/// @file DataProviderTIOVX.cpp
/// @brief Contains implementation of TIOVX Dataprovider interface
///
/// DataProvider is an interface between TIOVX module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------


#include "DataProviderTIOVX.h"


namespace tiovx
{
  DataProviderTIOVX::DataProviderTIOVX(container::IDataProvider& b_DataProvider_ro)
    : IDataProviderTIOVX()
    , dataProvider_ro(b_DataProvider_ro)
  {

  }

  DataProviderTIOVX::~DataProviderTIOVX()
  {
  }

  bool_t DataProviderTIOVX::init_b(uint8_t i_InitType_u8)
  {
    bsp::TIOVXHost& v_tiovx_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();

	ME_Debugger_F_Printf_v("tiovx-init call...\n");
    v_tiovx_ro.init_b();

#if 0	
    if(i_InitType_u8 == 0)
    {
      v_Fpga_ro.getFpgaVideoInput_ro().initVideoInput_b();
      dataProvider_ro.getCamMData_po()->init_v();
    }

    if(i_InitType_u8 == 1)
    {
      v_Fpga_ro.init_b();
    }

    if(i_InitType_u8 == 2)
    {
      v_Fpga_ro.getFpgaVideoOutput_ro().initVideoOutput_b();
      dataProvider_ro.getCamMData_po()->initVideoOutSerializer_v();
    }
#endif
    return true;
  }

 void DataProviderTIOVX::updateCamera_v(const variants::Camera_t i_Camera_t, const sensor::CalibrationData_t &i_CalibrationData_rt)
{
#if 0
  ME_Debugger_F_Printf_v("<< TIOVX:CamApplyCalib ID:: %d, dPitch= %3.5f, dYaw= %3.5f, dRoll= %3.5f, dX= %3.5f, dY= %3.5f, dZ = %3.5f >>\n",
      i_Camera_t,
      i_CalibrationData_rt.pitchDelta_f32,
      i_CalibrationData_rt.yawDelta_f32,
      i_CalibrationData_rt.rollDelta_f32,
      i_CalibrationData_rt.xDelta_f32,
      i_CalibrationData_rt.yDelta_f32,
      i_CalibrationData_rt.zDelta_f32);
#endif

  sensor::CameraBase& v_Camera_ro = dataProvider_ro.getCamMData_po()->getCamera_ro(i_Camera_t);
  v_Camera_ro.getCameraParams_ro().applyCalibrationData_v(i_CalibrationData_rt);

}

void DataProviderTIOVX::updateCamCaliberationData_v()
{
  sensor::CalibrationData_t v_CalibrationData_t;
  bool_t v_FrontCamStatus_b = false;
  bool_t v_RightCamStatus_b = false;
  bool_t v_LeftCamStatus_b = false;
  bool_t v_RearCamStatus_b = false;

  CalDataProvider_MPU_1_0_Def v_NewRequest_t;
  v_NewRequest_t = dataProvider_ro.getSigMData_po()->getCalDataProvider_MPU_1_0_Def();

  for (uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount - 1); v_I_u32++)
  {
    switch (v_I_u32)
    {
    case  0:
           {
             v_CalibrationData_t.pitchDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Pitch_f32;
             v_CalibrationData_t.rollDelta_f32  = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Roll_f32;
             v_CalibrationData_t.yawDelta_f32   = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Yaw_f32;

             v_CalibrationData_t.xDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.X_f32;
             v_CalibrationData_t.yDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.Y_f32;
             v_CalibrationData_t.zDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.Z_f32;

             if(memcmp(&v_CalibrationData_t, &v_LastCalibrationDataCamFront_t, sizeof(v_LastCalibrationDataCamFront_t)))
             {
                 v_LastCalibrationDataCamFront_t = v_CalibrationData_t;
                 v_FrontCamStatus_b = true;

             }
             break;
           }

    case  1:
           {
             v_CalibrationData_t.pitchDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.Pitch_f32;
             v_CalibrationData_t.rollDelta_f32  = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.Roll_f32;
             v_CalibrationData_t.yawDelta_f32   = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.Yaw_f32;

             v_CalibrationData_t.xDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.X_f32;
             v_CalibrationData_t.yDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.Y_f32;
             v_CalibrationData_t.zDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.Z_f32;
             if(memcmp(&v_CalibrationData_t, &v_LastCalibrationDataCamLeft_t, sizeof(v_LastCalibrationDataCamLeft_t)))
             {
               v_LastCalibrationDataCamLeft_t = v_CalibrationData_t;
                v_LeftCamStatus_b = true;
             }
             break;
           }

    case  2:
           {
             v_CalibrationData_t.pitchDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.Pitch_f32;
             v_CalibrationData_t.rollDelta_f32  = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.Roll_f32;
             v_CalibrationData_t.yawDelta_f32   = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.Yaw_f32;

             v_CalibrationData_t.xDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.X_f32;
             v_CalibrationData_t.yDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.Y_f32;
             v_CalibrationData_t.zDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.Z_f32;
             if(memcmp(&v_CalibrationData_t, &v_LastCalibrationDataCamRear_t, sizeof(v_LastCalibrationDataCamRear_t)))
             {
               v_LastCalibrationDataCamRear_t = v_CalibrationData_t;
                v_RearCamStatus_b = true;
             }
             break;
           }
    case  3:
           {
             v_CalibrationData_t.pitchDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.Pitch_f32;
             v_CalibrationData_t.rollDelta_f32  = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.Roll_f32;
             v_CalibrationData_t.yawDelta_f32   = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.Yaw_f32;

             v_CalibrationData_t.xDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.X_f32;
             v_CalibrationData_t.yDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.Y_f32;
             v_CalibrationData_t.zDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.Z_f32;
             if(memcmp(&v_CalibrationData_t, &v_LastCalibrationDataCamRight_t, sizeof(v_LastCalibrationDataCamRight_t)))
             {
                   v_LastCalibrationDataCamRight_t = v_CalibrationData_t;
                   v_RightCamStatus_b = true;
             }
             break;
           }

   default:
          break;
    }

    if(v_FrontCamStatus_b || v_RightCamStatus_b || v_LeftCamStatus_b || v_RearCamStatus_b)
    {
       updateCamera_v(static_cast<variants::Camera_t>(v_I_u32), v_CalibrationData_t);
    }
  }

}

  void DataProviderTIOVX::start_cameras()
  {
    bsp::TIOVXHost& v_tiovx_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    v_tiovx_ro.getVideoInput_ro().powerEnable_v(true);
  }
	
  bsp::TIOVXHost& DataProviderTIOVX::getTIOVX_ro()
  {
    return dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
  }
#ifdef USE_REQUEST_AND_RESPONSE
  uint8_t DataProviderTIOVX::getViewId_u8()
  {
    return 0U;//dataProvider_ro.getSigMData_po()->getScreenRequest_t().ViewID_u8;
  }
#else
  uint8_t DataProviderTIOVX::getViewId_u8(bool_t* o_receive_status_b_p )
  {
    return 0U;//dataProvider_ro.getSigMData_po()->getScreenRequest_t(o_receive_status_b_p).ViewID_u8;
  }
#endif

  sensor::CameraBase& DataProviderTIOVX::getCamera_ro(variants::Camera_t i_CameraId_t)
  {
    return dataProvider_ro.getCamMData_po()->getCamera_ro(i_CameraId_t);
   }

bool_t DataProviderTIOVX::getCamDataInitStatus()
  {
    return dataProvider_ro.getCamMData_po()->getCamDataInitStatus();
  }

  void DataProviderTIOVX::setCamEepromDataArray_v()
  {
    bsp::TIOVXHost& v_tiovx_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();

    // considered only 4 cameras.
    for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount-1); v_I_u32++)
    {
      if(true == v_tiovx_ro.getVideoInput_ro().getsvsVideoSensor_ro().getSvsEepromCrcErrorStatus(static_cast<variants::Camera_t>(v_I_u32)))
      {
        crcError_ab[v_I_u32] = true;
        sensor::CameraBase& v_Camera_ro = dataProvider_ro.getCamMData_po()->getCamera_ro(static_cast<variants::Camera_t>(v_I_u32));
        v_Camera_ro.getCameraParams_ro().applyCameraCRCError_v();
      }
    }

    svs_CamEepromDataArray_t = v_tiovx_ro.getVideoInput_ro().getsvsVideoSensor_ro().getSvsEepromData();

    dataProvider_ro.getSigMData_po()->setSvs_CamEepromDataArray_v(svs_CamEepromDataArray_t);
  }

  Svs_CamEepromDataArray_t DataProviderTIOVX::getCamEepromDataArray_v()
  {
    return svs_CamEepromDataArray_t;
  }

  void DataProviderTIOVX::setTIOVXRuntime(uint32_t u_Runtime_u32)
  {
    dataProvider_ro.getTIOVXData_po()->setTIOVXRuntime(u_Runtime_u32);
  }

  void DataProviderTIOVX::setTIOVXThreadRuntime(uint32_t u_Runtime_u32)
  {
    dataProvider_ro.getTIOVXData_po()->setTIOVXThreadRuntime(u_Runtime_u32);
  }

  void DataProviderTIOVX::setCamCalibRuntime(uint32_t u_Runtime_u32)
  {
    dataProvider_ro.getTIOVXData_po()->setCamCalibRuntime(u_Runtime_u32);
  }

  PerformanceStatsEnable_t DataProviderTIOVX::get_PerformanceStatsEnable(void)
  {
    return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
  }  
  
  CamHotplugStatus_t DataProviderTIOVX::getCamHotplugStatus_v(void)
  {
	  return dataProvider_ro.getSigMData_po()->getCamHotplugStatus_t();
  }

} // namespace tiovx
