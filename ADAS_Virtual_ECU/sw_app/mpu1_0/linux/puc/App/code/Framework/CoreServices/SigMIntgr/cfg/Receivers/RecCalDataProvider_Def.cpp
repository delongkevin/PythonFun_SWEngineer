//--------------------------------------------------------------------------
/// @file RecCalDataProvider_Def.cpp
/// @brief Contains
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author sagar.saste@magna.com
///
//  --------------------------------------------------------------------------

#include "RecCalDataProvider_Def.h"

namespace sigm
{

RecCalDataProvider_Def::RecCalDataProvider_Def()
 : BaseReceiver(e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def, 50)
{
}

RecCalDataProvider_Def::~RecCalDataProvider_Def()
{
}

bool_t RecCalDataProvider_Def::handleSpecificReceiver_b()
{
  if (true == handle_RecCalDataProviderDefReceiver_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

void RecCalDataProvider_Def::updateCamera_v(const variants::Camera_t i_Camera_t, const sensor::CalibrationData_t& i_CalibrationData_rt)
{
  mutex_o.take_b();
  sensor::CameraBase& v_Camera_ro = dataProvider_po->getCamera_ro(i_Camera_t);
  v_Camera_ro.getCameraParams_ro().applyCalibrationData_v(i_CalibrationData_rt);
  mutex_o.give_v();
}

bool_t RecCalDataProvider_Def::handle_RecCalDataProviderDefReceiver_b()
{
  bool_t v_RequestOk_b = false;
  uint32_t size_u32 =0;

  size_u32 = BaseReceiver::getStructSize_u32<CalDataProvider_MPU_1_0_Def>();
  if(size_u32 != m_MsgReceived.msgSize_u32)
  {
  	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "CalDataProvider_MPU_1_0_Def message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
  }
  else
  {
	  CalDataProvider_MPU_1_0_Def v_NewRequest_t;
	  sensor::CalibrationData_t v_CalibrationData_t;

      if (m_MsgReceived.msgSize_u32 > 0)
      {
          v_RequestOk_b = true;
          memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
          dataProvider_po->setCalDataProvider_MPU_1_0_Def_v(v_NewRequest_t);
          logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);


      mutex_o.take_b();
      if(false == dataProvider_po->getCamDataInitStatus())
       {
         // considered only 4 cameras.
         for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount-1); v_I_u32++)
         {
           cameras_ao[v_I_u32] = &dataProvider_po->getCamera_ro(static_cast<variants::Camera_t>(v_I_u32));
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
         //ME_Debugger_F_Printf_v("  SigM: CamData init done_!()   \n");
       }
      mutex_o.give_v();

      // considered only 4 cameras. and set the calibration data.
      for(uint32_t v_I_u32 = 0; v_I_u32 < (variants::e_CameraCount-1); v_I_u32++)
      {
        switch(v_I_u32)
    	  {
    	    case  0:
    	           {
    	             v_CalibrationData_t.pitchDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Pitch_f32;
    	             v_CalibrationData_t.rollDelta_f32  = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Roll_f32;
    	             v_CalibrationData_t.yawDelta_f32   = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Yaw_f32;

    	             v_CalibrationData_t.xDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.X_f32;
    	             v_CalibrationData_t.yDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.Y_f32;
    	             v_CalibrationData_t.zDelta_f32 = v_NewRequest_t.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.Z_f32;
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
    	             break;
    	           }

    	   default:
    	          break;
    	  }
#if 0
        printf("SIGM_CAL_DATA_P CAM_id: %d\t[P: %f] [R: %f] [Y: %f] [x: %f] [y: %f] [z: %f]\n"
        		,v_I_u32
        		,v_CalibrationData_t.pitchDelta_f32
        		,v_CalibrationData_t.rollDelta_f32
        		,v_CalibrationData_t.yawDelta_f32
        		,v_CalibrationData_t.xDelta_f32
        		,v_CalibrationData_t.yDelta_f32
        		,v_CalibrationData_t.zDelta_f32
        );
#endif
        updateCamera_v(static_cast<variants::Camera_t>(v_I_u32), v_CalibrationData_t);
      }

      }
  }
  return v_RequestOk_b;
}


} /* namespace sigm */
