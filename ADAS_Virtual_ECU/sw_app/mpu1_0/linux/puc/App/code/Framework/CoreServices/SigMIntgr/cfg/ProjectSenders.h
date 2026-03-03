//--------------------------------------------------------------------------
/// @file ProjectSenders.h
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

#ifndef SIGM_PROJECT_SENDERS_H_
#define SIGM_PROJECT_SENDERS_H_

#include "mecl/core/ArrayList.h"

#include "cfg/Senders/SenScreenResponse.h"
#include "cfg/Senders/SenSVSOutputToDiagMgrCamCalib.h"
#include "cfg/Senders/SenErrorMgr_ErrorCommPack_QNX_B.h"
#include "cfg/Senders/SenMOT_Output.h"
#include "cfg/Senders/SenIJobPLDOutput.h"
#include "cfg/Senders/SenIJobPLDOutput.h"
#include "cfg/Senders/SenIParkingSlotInformation.h"
#include "cfg/Senders/SenErrorCommPack_QNX_QM.h"
#include "cfg/Senders/SenJobTHADetOutput.h"
#include "cfg/Senders/SenMeDLD_e_RrCamSts.h"
#include "cfg/Senders/SenQNX_State_QNX.h"
#include "cfg/Senders/SenSvs_CamEepromData.h"
#include "cfg/Senders/SenSVSCalibAlgoToSMCamCalib.h"
#include "cfg/Senders/SenSVSCalibSMToAlgoCamCalib.h"
#include "cfg/Senders/SenSVSCamCurrentCalibDataToNVM.h"
#include "cfg/Senders/SenSVSCamEOLCalibDataToNVM.h"
#include "cfg/Senders/SenSVSCamOCCalibDataToNVM.h"
#include "cfg/Senders/SenSVSCamSCCalibDataToNVM.h"
#include "cfg/Senders/SenSVSOutputToDiagMgrCamCalib.h"
#include "cfg/Senders/SenTRSC_Inputs_from_TrailerDetection.h"
#include "cfg/Senders/SenCVPAMFDData2_LMD_Outputs_CVPAMFDData.h"
#include "cfg/Senders/SenTrailerDet_Output_DID.h"
#include "cfg/Senders/SenLMD_Lane_Outputs.h"
#include "cfg/Senders/SenTbSVS_e_SVSCalibSMToHmi.h"
#include "cfg/Senders/SenME_Proxi_MPU1_0_to_MCU1_0.h"
#include "cfg/Senders/SenJobDLDOutput.h"
#include "cfg/Senders/SenTrailerDetection_Output_HMI.h"
#include "cfg/Senders/SenError_Fault_MPU1_0.h"
#include "cfg/Senders/SenRunTimeStats_MPU1_0.h"

namespace sigm
{

class BaseSender;

// Base Request list definition for JobSigm
const uint32_t MaxSendersTypes = e_MessageTx_count;
typedef mecl::core::ArrayList<BaseSender*,MaxSendersTypes> BaseSenderList_t;

// project specifig quests
struct ProjectSenders_s
{
  void init_v(BaseSenderList_t& b_Items_t)
  {
	  b_Items_t.pushBack_v(&SenScreenResponse_o);
	  b_Items_t.pushBack_v(&ErrorCommPack_QNX_QM_o);
	  b_Items_t.pushBack_v(&SenErrorMgr_ErrorCommPack_QNX_B_o);
	  b_Items_t.pushBack_v(&TRSC_Inputs_from_TrailerDetection_o);
	  b_Items_t.pushBack_v(&MeDLD_e_RrCamSts_o);
	  b_Items_t.pushBack_v(&QNX_State_QNX_o);
	  b_Items_t.pushBack_v(&SVSCalibSMToAlgoCamCalib_o);
	  b_Items_t.pushBack_v(&SVSCalibAlgoToSMCamCalib_o);
	  b_Items_t.pushBack_v(&SVSCamCurrentCalibDataToNVM_o);
	  b_Items_t.pushBack_v(&SVSCamOCCalibDataToNVM_o);
	  b_Items_t.pushBack_v(&SVSCamSCCalibDataToNVM_o);
	  b_Items_t.pushBack_v(&SVSCamEOLCalibDataToNVM_o);
	  b_Items_t.pushBack_v(&SenSVSOutputToDiagMgrCamCalib_o);
	  b_Items_t.pushBack_v(&JobTHADetOutput_o);
	  b_Items_t.pushBack_v(&SenIJobPLDOutput_o);
	  b_Items_t.pushBack_v(&SenIParkingSlotInformation_o);
	  b_Items_t.pushBack_v(&SenMOT_Output_o);
	  b_Items_t.pushBack_v(&SenSvs_CamEepromData_o);
	  b_Items_t.pushBack_v(&CVPAMFDData2_LMD_Outputs_CVPAMFDData_o);
	  b_Items_t.pushBack_v(&TrailerDet_Output_DID_o);
	  b_Items_t.pushBack_v(&LMD_Lane_Outputs_o);
	  b_Items_t.pushBack_v(&TbSVS_e_SVSCalibSMToHmi_o);
	  b_Items_t.pushBack_v(&ME_Proxi_MPU1_0_to_MCU1_0_o);
	  b_Items_t.pushBack_v(&TrailerDetection_Output_HMI_o);
	  b_Items_t.pushBack_v(&JobDLDOutput_o);
    b_Items_t.pushBack_v(&Error_Fault_MPU1_0_o);
	b_Items_t.pushBack_v(&RunTimeStats_MPU1_0_o);
  }

private:

  SenScreenResponse SenScreenResponse_o;
  SenSVSOutputToDiagMgrCamCalib SenSVSOutputToDiagMgrCamCalib_o;
  SenErrorMgr_ErrorCommPack_QNX_B SenErrorMgr_ErrorCommPack_QNX_B_o;
  SenMOT_Output SenMOT_Output_o;
  SenIJobPLDOutput SenIJobPLDOutput_o;
  SenIParkingSlotInformation SenIParkingSlotInformation_o;
  TRSC_Inputs_from_TrailerDetection TRSC_Inputs_from_TrailerDetection_o;
  SVSCamSCCalibDataToNVM SVSCamSCCalibDataToNVM_o;
  SVSCamOCCalibDataToNVM SVSCamOCCalibDataToNVM_o;
  SVSCamEOLCalibDataToNVM SVSCamEOLCalibDataToNVM_o;
  SVSCamCurrentCalibDataToNVM SVSCamCurrentCalibDataToNVM_o;
  SVSCalibSMToAlgoCamCalib SVSCalibSMToAlgoCamCalib_o;
  SVSCalibAlgoToSMCamCalib SVSCalibAlgoToSMCamCalib_o;
  QNX_State_QNX QNX_State_QNX_o;
  MeDLD_e_RrCamSts MeDLD_e_RrCamSts_o;
  JobTHADetOutput JobTHADetOutput_o;
  ErrorCommPack_QNX_QM ErrorCommPack_QNX_QM_o;
  SenSvs_CamEepromData SenSvs_CamEepromData_o;
  CVPAMFDData2_LMD_Outputs_CVPAMFDData CVPAMFDData2_LMD_Outputs_CVPAMFDData_o;
  TrailerDet_Output_DID TrailerDet_Output_DID_o;
  LMD_Lane_Outputs LMD_Lane_Outputs_o;
  TbSVS_e_SVSCalibSMToHmi TbSVS_e_SVSCalibSMToHmi_o;
  ME_Proxi_MPU1_0_to_MCU1_0 ME_Proxi_MPU1_0_to_MCU1_0_o;
  TrailerDetection_Output_HMI TrailerDetection_Output_HMI_o;
  JobDLDOutput JobDLDOutput_o;
  Error_Fault_MPU1_0 Error_Fault_MPU1_0_o;
  RunTimeStats_MPU1_0 RunTimeStats_MPU1_0_o;
};

} // namespace SIgM




#endif /* SIGM_PROJECT_RECEIVERS_H_ */
