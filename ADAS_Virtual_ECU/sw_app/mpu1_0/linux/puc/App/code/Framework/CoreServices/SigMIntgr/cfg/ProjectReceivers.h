//--------------------------------------------------------------------------
/// @file ProjectReceivers.h
/// @brief Contains project specific request configuration and defines the list that is used big JobSigM
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (Ananda.kavrady@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SIGM_PROJECT_RECEIVERS_H_
#define SIGM_PROJECT_RECEIVERS_H_

#include "mecl/core/ArrayList.h"

#include "cfg/Receivers/RecScreenRequest.h"
#include "cfg/Receivers/RecDiagMgrOutputToSVSCamCalibSM.h"
#include "cfg/Receivers/RecIKinematicData.h"
#include "cfg/Receivers/RecIFPAInfoToPLD.h"
#include "cfg/Receivers/RecSSM_SystemState.h"
#include "cfg/Receivers/RecCalDataProvider_Def.h"
#include "cfg/Receivers/RecCalDataProvider_Def.h"
#include "cfg/Receivers/RecDiagMgrOutputToSVSCamCalibSM.h"
#include "cfg/Receivers/RecFeatureOutputsTHA_TbTHASmVc_FeatureOutputs.h"
#include "cfg/Receivers/RecIFPAInfoToPLD.h"
#include "cfg/Receivers/RecMCU2_State_2_0.h"
#include "cfg/Receivers/RecMCU2_State_2_1.h"
#include "cfg/Receivers/RecME_VehInp_to_IpcSignals_data.h"
#include "cfg/Receivers/RecProxi_to_IpcSignals.h"
#include "cfg/Receivers/RecSSM_SystemState.h"
#include "cfg/Receivers/RecSvsToTHADet.h"
#include "cfg/Receivers/RecTHARelated_ScreenReq.h"
#include "cfg/Receivers/RecUS_S_BlockageBit.h"
#include "cfg/Receivers/RecUS_S_USSErrorDiagData.h"
#include "cfg/Receivers/RecDetection_Inputs_from_TRSC.h"
#include "cfg/Receivers/RecTbAP_DriveAssistStatOut.h"
#include "cfg/Receivers/Recfid_struct.h"
#include "cfg/Receivers/RecTHA_Calibration_data_MPU1_0.h"
#include "cfg/Receivers/RecAPA_Calibration_data_MPU1_0.h"
#include "cfg/Receivers/RecLMD_Calibration_data.h"
#include "cfg/Receivers/RecTRSC_Calibration_data_MPU1_0.h"
#include "cfg/Receivers/RecTRSC_CalibrationClear.h"
#include "cfg/Receivers/RecFunctionalSettingsNVMToSVSCalibSM.h"
#include "cfg/Receivers/RecFID_STRUCT_QM.h"
#include "cfg/Receivers/RecTRSCDebug_ScrReq.h"
#include "cfg/Receivers/RecCanDebugRIDStatus.h"

#include "cfg/Receivers/RecPerformanceStatsEnable.h"
#include "cfg/Receivers/RecCamHotplugStatus.h"
namespace sigm
{

class BaseReceiver;

// Base Request list definition for JobSigm
const uint32_t MaxReceiverTypes = e_Message_count;
typedef mecl::core::ArrayList<BaseReceiver*,MaxReceiverTypes> BaseReceiverList_t;

// project specifig quests
struct ProjectReceivers_s
{
  void init_v(BaseReceiverList_t& b_Items_t)
  {
	  b_Items_t.pushBack_v(&SvsToTHADet_o );
	  b_Items_t.pushBack_v(&RecScreenRequest_o );
	  b_Items_t.pushBack_v(&ME_VehInp_to_IpcSignals_data_o);
	  b_Items_t.pushBack_v(&Detection_Inputs_from_TRSC_o);
	  b_Items_t.pushBack_v(&MCU2_State_2_0_o);
	  b_Items_t.pushBack_v(&MCU2_State_2_1_o);
	  b_Items_t.pushBack_v(&RecSSM_SystemState_o );
	  b_Items_t.pushBack_v(&RecCalDataProvider_Def_o );
	  b_Items_t.pushBack_v(&RecFunctionalSettingsNVMToSVSCalibSM_o );
	  b_Items_t.pushBack_v(&RecDiagMgrOutputToSVSCamCalibSM_o );
	  b_Items_t.pushBack_v(&FeatureOutputsTHA_TbTHASmVc_FeatureOutputs_o );
	  b_Items_t.pushBack_v(&RecIFPAInfoToPLD_o );
	  b_Items_t.pushBack_v(&RecIKinematicData_o );
	  b_Items_t.pushBack_v(&TbAP_DriveAssistStatOut_o);
	  b_Items_t.pushBack_v(&FID_STRUCT_QM_C_o);
	  b_Items_t.pushBack_v(&FID_STRUCT_B_o);
	  b_Items_t.pushBack_v(&US_S_BlockageBit_o );
	  b_Items_t.pushBack_v(&US_S_USSErrorDiagData_o );
	  b_Items_t.pushBack_v(&THARelated_ScreenReq_o );
	  b_Items_t.pushBack_v(&Proxi_to_IpcSignals_o );
	  b_Items_t.pushBack_v(&TRSCDebug_ScrReq_o );
	  b_Items_t.pushBack_v(&CanDebugRIDStatus_o );
	  b_Items_t.pushBack_v(&THA_Calibration_data_MPU1_0_o);
	  b_Items_t.pushBack_v(&APA_Calibration_data_MPU1_0_o);
	  b_Items_t.pushBack_v(&LMD_Calibration_data_o);
	  b_Items_t.pushBack_v(&TRSC_Calibration_data_MPU1_0_o);
    b_Items_t.pushBack_v(&TRSC_CalibrationClear_o);
	b_Items_t.pushBack_v(&PerformanceStatsEnable_o);
  	b_Items_t.pushBack_v(&CamHotplugStatus_o);
  }

private:

  RecScreenRequest RecScreenRequest_o;
  RecDiagMgrOutputToSVSCamCalibSM RecDiagMgrOutputToSVSCamCalibSM_o;
  RecIKinematicData RecIKinematicData_o;
  RecIFPAInfoToPLD RecIFPAInfoToPLD_o;
  RecSSM_SystemState RecSSM_SystemState_o;
  RecCalDataProvider_Def RecCalDataProvider_Def_o;
  Detection_Inputs_from_TRSC Detection_Inputs_from_TRSC_o;
  FeatureOutputsTHA_TbTHASmVc_FeatureOutputs FeatureOutputsTHA_TbTHASmVc_FeatureOutputs_o;
  MCU2_State_2_0 MCU2_State_2_0_o;
  MCU2_State_2_1 MCU2_State_2_1_o;
  ME_VehInp_to_IpcSignals_data ME_VehInp_to_IpcSignals_data_o;
  Proxi_to_IpcSignals Proxi_to_IpcSignals_o;
  SvsToTHADet SvsToTHADet_o;
  THARelated_ScreenReq THARelated_ScreenReq_o;
  US_S_BlockageBit US_S_BlockageBit_o;
  US_S_USSErrorDiagData US_S_USSErrorDiagData_o;
  TbAP_DriveAssistStatOut TbAP_DriveAssistStatOut_o;
  fid_struct FID_STRUCT_B_o;
  THA_Calibration_data_MPU1_0 THA_Calibration_data_MPU1_0_o;
  APA_Calibration_data_MPU1_0 APA_Calibration_data_MPU1_0_o;
  LMD_Calibration_data LMD_Calibration_data_o;
  TRSC_Calibration_data_MPU1_0 TRSC_Calibration_data_MPU1_0_o;
  TRSC_CalibrationClear TRSC_CalibrationClear_o;
  RecFunctionalSettingsNVMToSVSCalibSM RecFunctionalSettingsNVMToSVSCalibSM_o;
  FID_STRUCT_QM_C FID_STRUCT_QM_C_o;
  CanDebugRIDStatus CanDebugRIDStatus_o;
  TRSCDebug_ScrReq TRSCDebug_ScrReq_o;
  PerformanceStatsEnable PerformanceStatsEnable_o;
  CamHotplugStatus CamHotplugStatus_o;
};

} // namespace SIgM




#endif /* SIGM_PROJECT_RECEIVERS_H_ */
