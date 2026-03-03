//--------------------------------------------------------------------------
/// @file SigMData.h
/// @brief Contains access functions and data for SigM
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "SigMData.h"
#ifdef ME_PLATFORM_QNX
	#include <hw/inout.h>
	#include <sys/mman.h>
#endif
#include <logging/Logger.h>
#include "ME_CalibSVS.h"
#include "ipc_lookup_table.h"

namespace container
{


SigMData::SigMData()
  : DataContainer()
  , mutex_o()
  , screenRequest_t()
  , vehicleState_t()
  , calibrationCamera_t(variants::e_CameraInvalid)
  , calibrationType_t(variants::e_CalibTypeNONE)
  , isEOLcompleted_b(false)
  , isEOLtriggered_b(false)
  , m_VariantID(0)
  , m_RadioDisp(0)
  , m_etfs_mount_status(0)
  , m_render_frameNum(0)
{
  memset(&screenRequest_t, 0, sizeof(screenRequest_t));

//  screenRequest_t.ZoomFactor_u8 = 100U;

  memset(&vehicleState_t, 0, sizeof(vehicleState_t));
  memset(&applyConfig_t, 0, sizeof(applyConfig_t));
  memset(&requestEOLCmd_t, 0, sizeof(requestEOLCmd_t));

  for(uint8_t i = 0; i < 4; i++ )
  {
    memset(&responseEOLCmd_t[i], 0, sizeof(ResponseEOLCmd_t));
  }

/*
  for(uint8_t i = 0; i < 20; i++ )
  {
    memset(&MessageStatus_Array[i], 0, sizeof(MessageStatus_t));
    memset(&MessageStatus_ArrayTx[i], 0, sizeof(MessageStatus_t));
  }
*/

  for(uint8_t i = 0; i < 26U; i++ )
  {
    memset(&MessageStatus_Array[i], 0, sizeof(MessageStatus_t));
  }
  for(uint8_t i = 0; i < 25U; i++ )
  {
    memset(&MessageStatus_ArrayTx[i], 0, sizeof(MessageStatus_t));
  }


  memset(&requestOCCmd_t, 0, sizeof(requestOCCmd_t));
  memset(&responseOCCmd_t, 0, sizeof(responseOCCmd_t));
  memset(&requestSCCmd_t, 0, sizeof(requestSCCmd_t));
  memset(&responseSCCmd_t, 0, sizeof(responseSCCmd_t));
  memset(&requestTEOLCmd_t, 0, sizeof(requestTEOLCmd_t));
  memset(&responseTEOLCmd_t, 0, sizeof(responseTEOLCmd_t));

  memset(hmiSoftButtons_at, 0U, sizeof(hmiSoftButtons_at));
}

SigMData::~SigMData()
{

}

#ifdef USE_REQUEST_AND_RESPONSE
ScreenRequest_t SigMData::getScreenRequest_t()
{
  ScreenRequest_t v_ScreenRequest_t;
  mutex_o.take_b();
  v_ScreenRequest_t = screenRequest_t;
  mutex_o.give_v();

  return v_ScreenRequest_t;
}
#else
ScreenRequest_t SigMData::getScreenRequest_t(bool_t *o_ReceiveStatus_pb )
{
  ScreenRequest_t v_ScreenRequest_t;
  mutex_o.take_b();
  v_ScreenRequest_t = screenRequest_t;
  *o_ReceiveStatus_pb = MessageStatus_Array[e_ScreenRequestIndx].receiver_Status_b;
  MessageStatus_Array[e_ScreenRequestIndx].receiver_Status_b = false;
  mutex_o.give_v();

  return v_ScreenRequest_t;
}
#endif

#ifdef USE_REQUEST_AND_RESPONSE
void SigMData::setScreenRequest_v(const ScreenRequest_t& i_ScreenRequest_rt)
{
  mutex_o.take_b();

  screenRequest_t = i_ScreenRequest_rt;

  mutex_o.give_v();
}
#else
void SigMData::setScreenRequest_v(const ScreenRequest_t& i_ScreenRequest_rt)
{
  mutex_o.take_b();

  screenRequest_t = i_ScreenRequest_rt;
  MessageStatus_Array[e_ScreenRequestIndx].messageID_u32 = e_IpcMsgId_PpScreenRequest_ScreenRequest_t;
  MessageStatus_Array[e_ScreenRequestIndx].receiver_Status_b= true;

  mutex_o.give_v();
}
#endif

TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t SigMData::getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t *o_ReceiveStatus_pb )
{
  TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t v_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;
  mutex_o.take_b();
  v_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t = tbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;
  *o_ReceiveStatus_pb = MessageStatus_Array[e_TbSVS_e_DiagMgrOutputToSVSCamCalibSMIndx].receiver_Status_b;
  MessageStatus_Array[e_TbSVS_e_DiagMgrOutputToSVSCamCalibSMIndx].receiver_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;
}


void SigMData::setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t& i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt)
{
  mutex_o.take_b();

  tbSVS_e_DiagMgrOutputToSVSCamCalibSM_t = i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt;
  MessageStatus_Array[e_TbSVS_e_DiagMgrOutputToSVSCamCalibSMIndx].messageID_u32 = e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;
  MessageStatus_Array[e_TbSVS_e_DiagMgrOutputToSVSCamCalibSMIndx].receiver_Status_b= true;

  mutex_o.give_v();
}



ScreenResponse_t SigMData::getScreenResponse_t()
{
  ScreenResponse_t v_ScreenResponse_t;
  mutex_o.take_b();
  v_ScreenResponse_t = screenResponse_t;
  MessageStatus_ArrayTx[e_ScreenResponseIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ScreenResponse_t;
}

void SigMData::setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt)
{
  mutex_o.take_b();

  screenResponse_t = i_ScreenResponse_rt;
  MessageStatus_ArrayTx[e_ScreenResponseIndx].messageID_u32 = e_IpcMsgId_PpScreenResponse_ScreenResponse_t;
  MessageStatus_ArrayTx[e_ScreenResponseIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TbSVS_e_SVSOutputToDiagMgrCamCalib_t SigMData::getTbSVS_e_SVSOutputToDiagMgrCamCalib_t()
{
  TbSVS_e_SVSOutputToDiagMgrCamCalib_t v_TbSVS_e_SVSOutputToDiagMgrCamCalib_t;
  mutex_o.take_b();
  v_TbSVS_e_SVSOutputToDiagMgrCamCalib_t = tbSVS_e_SVSOutputToDiagMgrCamCalib_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSOutputToDiagMgrCamCalibIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_e_SVSOutputToDiagMgrCamCalib_t;
}

void SigMData::setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t& i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt)
{
  mutex_o.take_b();

  tbSVS_e_SVSOutputToDiagMgrCamCalib_t = i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSOutputToDiagMgrCamCalibIndx].messageID_u32 = e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSOutputToDiagMgrCamCalibIndx].sender_Status_b = true;

  mutex_o.give_v();
}


MessageStatus_t SigMData::getMessageStatus_t(uint8_t i_index_u8)
{
 MessageStatus_t v_MessageStatus_t;
 mutex_o.take_b();
 v_MessageStatus_t = MessageStatus_ArrayTx[i_index_u8];
 mutex_o.give_v();

return v_MessageStatus_t;
}

TRA_Data_Request_t SigMData::getTRAData_t()
{
  TRA_Data_Request_t v_TRA_Data_Request_t;
  mutex_o.take_b();
  v_TRA_Data_Request_t = Tra_Data_Request_t;
  mutex_o.give_v();

  return v_TRA_Data_Request_t;
}

void  SigMData::setTRARequest_v(const TRA_Data_Request_s& i_TRA_s)
{

   mutex_o.take_b();
   Tra_Data_Request_t = i_TRA_s;
   mutex_o.give_v();
}

void  SigMData::setTRAResponse_v(const TRA_Data_Response_s& i_TRA_s)
{

   mutex_o.take_b();
   Tra_Data_Response_t = i_TRA_s;
   mutex_o.give_v();
}

TRA_Data_Response_t SigMData::getTRAResponse_t()
{
  TRA_Data_Response_t v_TRA_Data_Response_t;
  mutex_o.take_b();
  v_TRA_Data_Response_t = Tra_Data_Response_t;
  mutex_o.give_v();

  return v_TRA_Data_Response_t;
}

MiscRequest_t SigMData::getMiscRequest_t()
{
	MiscRequest_t v_MiscRequest_t;
    mutex_o.take_b();
    v_MiscRequest_t = miscRequest_t;
    mutex_o.give_v();
    return v_MiscRequest_t;
}

void SigMData::setMiscRequest_v(const MiscRequest_t& i_MiscRequest_rt)
{
   mutex_o.take_b();
   miscRequest_t = i_MiscRequest_rt;
   mutex_o.give_v();
}

void SigMData::setEolTriggeredFlag_v()
{
   mutex_o.take_b();
   isEOLtriggered_b = true;
   mutex_o.give_v();
}

void SigMData::resetEolTriggeredFlag_v()
{
   mutex_o.take_b();
   isEOLtriggered_b = false;
   mutex_o.give_v();
}

bool_t SigMData::isEolAlgoTriggered_b()
{
   bool_t v_RetVal_b = false;
   mutex_o.take_b();
   v_RetVal_b = isEOLtriggered_b;
   mutex_o.give_v();
   return v_RetVal_b;
}

MCU_TRAGateway1Request_t SigMData::getMCUTRAGateway1_t()
{
  MCU_TRAGateway1Request_t v_MCU_TRAGateway1Request_t;
  mutex_o.take_b();
  v_MCU_TRAGateway1Request_t = MCU_TraGateway1Request_t;
  mutex_o.give_v();
  return v_MCU_TRAGateway1Request_t;
}

void SigMData::setMCUTRAGateway1Request_v(const MCU_TRAGateway1Request_t& i_MCUTRAGateway1_rt)
{
   mutex_o.take_b();
   MCU_TraGateway1Request_t = i_MCUTRAGateway1_rt;
   mutex_o.give_v();
}

MCU_TRAGateway2Request_t SigMData::getMCUTRAGateway2_t()
{
  MCU_TRAGateway2Request_t v_MCU_TRAGateway2_Data_Request_t;
  mutex_o.take_b();
  v_MCU_TRAGateway2_Data_Request_t = MCU_TraGateway2Request_t;
  mutex_o.give_v();

  return v_MCU_TRAGateway2_Data_Request_t;
}

void  SigMData::setMCUTRAGateway2Request_v(const MCU_TRAGateway2Request_t& i_MCUTRAGateway2_rt)
{

   mutex_o.take_b();
   MCU_TraGateway2Request_t = i_MCUTRAGateway2_rt;
   mutex_o.give_v();
}

MCU_TRAGateway3Request_t SigMData::getMCUTRAGateway3_t()
{
  MCU_TRAGateway3Request_t v_MCU_TRAGateway3_Data_Request_t;
  mutex_o.take_b();
  v_MCU_TRAGateway3_Data_Request_t = MCU_TraGateway3Request_t;
  mutex_o.give_v();

  return v_MCU_TRAGateway3_Data_Request_t;
}

void  SigMData::setMCUTRAGateway3Request_v(const MCU_TRAGateway3Request_t& i_MCUTRAGateway3_rt)
{

   mutex_o.take_b();
   MCU_TraGateway3Request_t = i_MCUTRAGateway3_rt;
   mutex_o.give_v();
}

MCU_TRAGateway4Request_t SigMData::getMCUTRAGateway4_t()
{
  MCU_TRAGateway4Request_t v_MCU_TRAGateway4Request_t;
  mutex_o.take_b();
  v_MCU_TRAGateway4Request_t = MCU_TraGateway4Request_t;
  mutex_o.give_v();
  return v_MCU_TRAGateway4Request_t;
}

void  SigMData::setMCUTRAGateway4Request_v(const MCU_TRAGateway4Request_t& i_TRAGateway4_rt)
{
   mutex_o.take_b();
   MCU_TraGateway4Request_t = i_TRAGateway4_rt;
   mutex_o.give_v();  

}
VehicleStateRequest_t SigMData::getVehicleState_s()
{
  VehicleStateRequest_t v_VehicleState_t;
  mutex_o.take_b();
  v_VehicleState_t = vehicleState_t;
  mutex_o.give_v();

  return v_VehicleState_t;
}

void SigMData::setVehicleState_v(const VehicleStateRequest_t& i_VehicleState_s)
{
  mutex_o.take_b();
  vehicleState_t = i_VehicleState_s;
  mutex_o.give_v();
}


ApplyConfigRequest_t SigMData::getApplyConfig_t()
{
  ApplyConfigRequest_t v_ApplyConfig_t;
  mutex_o.take_b();
  v_ApplyConfig_t = applyConfig_t;
  mutex_o.give_v();

  return v_ApplyConfig_t;
}

void SigMData::setApplyConfig_v(const ApplyConfigRequest_t& i_ApplyConfig_rs)
{
  mutex_o.take_b();
  applyConfig_t = i_ApplyConfig_rs;
  mutex_o.give_v();
}


void SigMData::setRequestEOLCmd_v(const container::RequestEOLCmd_t&  i_RequestEOLCmd_rt  )
{ 
    mutex_o.take_b();
    requestEOLCmd_t = i_RequestEOLCmd_rt; 
    mutex_o.give_v();
}


const container::RequestEOLCmd_t&  SigMData::getRequestEOLCmd_rt(void) const
{ 
    return requestEOLCmd_t; 
}

void SigMData::setEolAlgoFinishedCmd_v(bool_t flag_b )
{
    mutex_o.take_b();
    isEOLcompleted_b = flag_b;
    mutex_o.give_v();
}

bool_t SigMData::getEolAlgoFinishedCmd_b()
{
	bool_t flag_b;
    mutex_o.take_b();
    flag_b = isEOLcompleted_b;
    mutex_o.give_v();

    return flag_b;
}

void SigMData::setResponseEOLCmd_v(const ResponseEOLCmd_t*  i_ResponseEOLCmd_rt )
{ 
    mutex_o.take_b();
    responseEOLCmd_t[0]= i_ResponseEOLCmd_rt[0];
    responseEOLCmd_t[1]= i_ResponseEOLCmd_rt[1];
    responseEOLCmd_t[2]= i_ResponseEOLCmd_rt[2];
    responseEOLCmd_t[3]= i_ResponseEOLCmd_rt[3];
    mutex_o.give_v();
}


const ResponseEOLCmd_t*  SigMData::getResponseEOLCmd_rt(void ) const
{ 
    return responseEOLCmd_t; 
}

void SigMData::setRequestOCCmd_v(const RequestOCCmd_t&  i_RequestOCCmd_rt  )
{ 
    mutex_o.take_b();
    requestOCCmd_t = i_RequestOCCmd_rt; 
    mutex_o.give_v();
}


const RequestOCCmd_t&  SigMData::getRequestOCCmd_rt(void) const
{ 
    return requestOCCmd_t; 
}


void SigMData::setResponseOCCmd_v(const ResponseOCCmd_t&  i_ResponseOCCmd_rt  )
{ 
    mutex_o.take_b();
    responseOCCmd_t = i_ResponseOCCmd_rt; 
    mutex_o.give_v();
}


const ResponseOCCmd_t&  SigMData::getResponseOCCmd_rt(void ) const
{ 
    return responseOCCmd_t; 
}

void SigMData::setRequestTEOLCmd_v(const RequestTEOLCmd_t&  i_RequestTEOLCmd_rt  )
{ 
    mutex_o.take_b();
    requestTEOLCmd_t = i_RequestTEOLCmd_rt; 
    mutex_o.give_v();
}


const RequestTEOLCmd_t&  SigMData::getRequestTEOLCmd_rt(void) const
{ 
    return requestTEOLCmd_t;
}


void SigMData::setResponseTEOLCmd_v(const ResponseTEOLCmd_t&  i_ResponseTEOLCmd_rt  )
{ 
    mutex_o.take_b();
    responseTEOLCmd_t = i_ResponseTEOLCmd_rt; 
    mutex_o.give_v();
}


const ResponseTEOLCmd_t&  SigMData::getResponseTEOLCmd_rt(void ) const
{ 
    return responseTEOLCmd_t; 
}

variants::Camera_t SigMData::getCalibrationCamera_t(void) const
{ 
    return calibrationCamera_t; 
}

void SigMData::setCalibrationCamera_v(const variants::Camera_t i_CalibrationCamera_t)
{ 
    mutex_o.take_b();
    calibrationCamera_t = i_CalibrationCamera_t; 
    mutex_o.give_v();
}

variants::CalibrationTypeE_t SigMData:: getCalibrationType_t(void) const
{ 
    return calibrationType_t; 
}

void SigMData::setCalibrationType_v(const variants::CalibrationTypeE_t i_CalibrationType_t)
{ 
    mutex_o.take_b();
    calibrationType_t = i_CalibrationType_t; 
    mutex_o.give_v();
}

void SigMData::setErrorDataCamera_v(variants::Camera_t i_Cam_t, const ErrorDataCamera_t& i_ErrorDataCamera_rt)
{
  mutex_o.take_b();
  errorDataCamera_at[i_Cam_t] = i_ErrorDataCamera_rt;
  mutex_o.give_v();
}

ErrorDataCamera_t SigMData::getErrorDataCamera_t(variants::Camera_t i_Cam_t)
{
  ErrorDataCamera_t v_ErrorDataCamera_at;

  mutex_o.take_b();
  v_ErrorDataCamera_at = errorDataCamera_at[i_Cam_t];
  mutex_o.give_v();

  return v_ErrorDataCamera_at;
}

variants::HmiSoftButtonStatus_t SigMData::getHmiSoftButtonStatus_t(variants::HmiSoftButton_t i_SoftButton_e)
{
  return hmiSoftButtons_at[i_SoftButton_e];
}

void SigMData::setHmiSoftButtonStatus_v(variants::HmiSoftButton_t i_SoftButton_e,variants::HmiSoftButtonStatus_t i_Status_e)
{
  hmiSoftButtons_at[i_SoftButton_e] = i_Status_e;
}

variants::Language_t SigMData::getLanguageId_t(void)
{
  variants::Language_t v_Language_e = variants::e_LanguageEnglish;
  uint8_t v_LanguageIdRaw_u8;

  mutex_o.take_b();
  v_LanguageIdRaw_u8 = vehicleState_t.LanguageId_u8;
  mutex_o.give_v();

  switch(v_LanguageIdRaw_u8)
  {
    case 0x01U: //ReqID 10272447 - English
    {
      v_Language_e = variants::e_LanguageEnglish;
      break;
    }
    case 0x1FU: //ReqID 10272451 - French
      {
        v_Language_e = variants::e_LanguageFrench;
        break;
      }
    case 0x20U: //ReqID 10272449 - Spanish
      {
        v_Language_e = variants::e_LanguageSpanish;
        break;
      }
    default:
    {
      v_Language_e = variants::e_LanguageEnglish;
      break;
    }    
  }
  return v_Language_e;
}

IKinematicData_t SigMData::getIKinematicData_t()
{
  IKinematicData_t v_IKinematicData_t;
  mutex_o.take_b();
  v_IKinematicData_t = m_IKinematicData_t;
  MessageStatus_Array[e_IKinematicDataIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_IKinematicData_t;
}

void SigMData::setIKinematicData_v(const IKinematicData_t& i_IKinematicData_rt)
{
  mutex_o.take_b();
  m_IKinematicData_t = i_IKinematicData_rt;
  MessageStatus_Array[e_IKinematicDataIndx].messageID_u32 = e_IpcMsgId_Data_IKinematicData_t;
  MessageStatus_Array[e_IKinematicDataIndx].sender_Status_b = true;
  mutex_o.give_v();
}

IJobPLDOutput_t SigMData::getIJobPLDOutput_t()
{
  IJobPLDOutput_t v_IJobPLDOutput_t;
  mutex_o.take_b();
  v_IJobPLDOutput_t = m_IJobPLDOutput_t;
  MessageStatus_ArrayTx[e_IJobPLDOutputIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_IJobPLDOutput_t;
}

void SigMData::setIJobPLDOutput_v(const IJobPLDOutput_t& i_IJobPLDOutput_rt)
{
  mutex_o.take_b();

  m_IJobPLDOutput_t = i_IJobPLDOutput_rt;
  MessageStatus_ArrayTx[e_IJobPLDOutputIndx].messageID_u32 = e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t;
  MessageStatus_ArrayTx[e_IJobPLDOutputIndx].sender_Status_b = true;

  mutex_o.give_v();
}

IParkingSlotInformation_t SigMData::getIParkingSlotInformation_t()
{
  IParkingSlotInformation_t v_IParkingSlotInformation_t;
  mutex_o.take_b();
  v_IParkingSlotInformation_t = m_IParkingSlotInformation_t;
  MessageStatus_ArrayTx[e_IParkingSlotInformationIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_IParkingSlotInformation_t;
}

void SigMData::setIParkingSlotInformation_v(const IParkingSlotInformation_t& i_IParkingSlotInformation_rt)
{
  mutex_o.take_b();
  m_IParkingSlotInformation_t = i_IParkingSlotInformation_rt;
  MessageStatus_ArrayTx[e_IParkingSlotInformationIndx].messageID_u32 = e_IpcMsgId_Data_IParkingSlotInformation_t;
  MessageStatus_ArrayTx[e_IParkingSlotInformationIndx].sender_Status_b = true;
  mutex_o.give_v();
}

IFPAInfoToPLD_t SigMData::getIFPAInfoToPLD_t()
{
  IFPAInfoToPLD_t v_IFPAInfoToPLD_t;
  mutex_o.take_b();

  v_IFPAInfoToPLD_t = m_IFPAInfoToPLD_t;
  MessageStatus_Array[e_IFPAInfoToPLDIndx].sender_Status_b = false;

  mutex_o.give_v();

  return v_IFPAInfoToPLD_t;
}

void SigMData::setIFPAInfoToPLD_v(const IFPAInfoToPLD_t& i_IFPAInfoToPLD_rt)
{
  mutex_o.take_b();

  m_IFPAInfoToPLD_t = i_IFPAInfoToPLD_rt;
  MessageStatus_Array[e_IFPAInfoToPLDIndx].messageID_u32 = e_IpcMsgId_Data_IFPAInfoToPLD_t;
  MessageStatus_Array[e_IFPAInfoToPLDIndx].sender_Status_b = true;


  mutex_o.give_v();
}

MOT_Output SigMData::getMOT_Output_t()
{
	MOT_Output v_MOT_Output_t;
  mutex_o.take_b();
  v_MOT_Output_t = m_MOT_Output_t;
  MessageStatus_ArrayTx[e_MOT_OutputIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_MOT_Output_t;
}

void SigMData::setMOT_Output_v(const MOT_Output& i_MOT_Output_rt)
{
  mutex_o.take_b();

  m_MOT_Output_t = i_MOT_Output_rt;
  MessageStatus_ArrayTx[e_MOT_OutputIndx].messageID_u32 = e_IpcMsgId_Data_MOT_Output;
  MessageStatus_ArrayTx[e_MOT_OutputIndx].sender_Status_b = true;

  mutex_o.give_v();
}

ME_VehInp_to_IpcSignals_t SigMData::getME_VehInp_to_IpcSignals_t()
{
	ME_VehInp_to_IpcSignals_t v_ME_VehInp_to_IpcSignals_t;
  mutex_o.take_b();
  v_ME_VehInp_to_IpcSignals_t = m_ME_VehInp_to_IpcSignals_t;
  MessageStatus_Array[e_ME_VehInp_to_IpcSignals_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ME_VehInp_to_IpcSignals_t;
}

void SigMData::setME_VehInp_to_IpcSignals_v(const ME_VehInp_to_IpcSignals_t& i_ME_VehInp_to_IpcSignals_t_rt)
{
  mutex_o.take_b();

  m_ME_VehInp_to_IpcSignals_t = i_ME_VehInp_to_IpcSignals_t_rt;
  MessageStatus_Array[e_ME_VehInp_to_IpcSignals_tIndx].messageID_u32 = e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f;
  MessageStatus_Array[e_ME_VehInp_to_IpcSignals_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

ME_ProxiToMPU1_0_Def_t SigMData::getME_Proxi_to_IpcSignals_t()
{
	ME_ProxiToMPU1_0_Def_t v_ME_Proxi_to_IpcSignals_t;
  mutex_o.take_b();
  v_ME_Proxi_to_IpcSignals_t = m_ME_Proxi_to_IpcSignals_t;
  MessageStatus_Array[e_ME_Proxi_to_IpcSignals_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ME_Proxi_to_IpcSignals_t;
}

void SigMData::setME_Proxi_to_IpcSignals_v(const ME_ProxiToMPU1_0_Def_t& i_ME_Proxi_to_IpcSignals_t_rt)
{
  mutex_o.take_b();

  m_ME_Proxi_to_IpcSignals_t = i_ME_Proxi_to_IpcSignals_t_rt;
  MessageStatus_Array[e_ME_Proxi_to_IpcSignals_tIndx].messageID_u32 = e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t;
  MessageStatus_Array[e_ME_Proxi_to_IpcSignals_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

SvsToTHADet_t SigMData::getSvsToTHADet_t()
{
	SvsToTHADet_t v_SvsToTHADet_t;
  mutex_o.take_b();
  v_SvsToTHADet_t = m_SvsToTHADet_t;
  MessageStatus_Array[e_SvsToTHADet_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_SvsToTHADet_t;
}

void SigMData::setSvsToTHADet_v(const SvsToTHADet_t& i_SvsToTHADet_t_rt)
{
  mutex_o.take_b();

  m_SvsToTHADet_t = i_SvsToTHADet_t_rt;
  MessageStatus_Array[e_SvsToTHADet_tIndx].messageID_u32 = e_IpcMsgId_data_SvsToTHADet_t;
  MessageStatus_Array[e_SvsToTHADet_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

SSM_2_0_CoreStatus SigMData::getSSM_2_0_CoreStatus()
{
	SSM_2_0_CoreStatus v_SSM_2_0_CoreStatus;
  mutex_o.take_b();
  v_SSM_2_0_CoreStatus = m_SSM_2_0_CoreStatus;
  MessageStatus_Array[e_SSM_2_0_CoreStatusIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_SSM_2_0_CoreStatus;
}

void SigMData::setSSM_2_0_CoreStatus_v(const SSM_2_0_CoreStatus& i_SSM_2_0_CoreStatus_rt)
{
  mutex_o.take_b();

  m_SSM_2_0_CoreStatus = i_SSM_2_0_CoreStatus_rt;
  MessageStatus_Array[e_SSM_2_0_CoreStatusIndx].messageID_u32 = e_IpcMsgId_PpSR_State_MCU2_State_2_0;
  MessageStatus_Array[e_SSM_2_0_CoreStatusIndx].sender_Status_b = true;

  mutex_o.give_v();
}

SSM_2_1_CoreStatus SigMData::getSSM_2_1_CoreStatus()
{
	SSM_2_1_CoreStatus v_SSM_2_1_CoreStatus;
  mutex_o.take_b();
  v_SSM_2_1_CoreStatus = m_SSM_2_1_CoreStatus;
  MessageStatus_Array[e_SSM_2_1_CoreStatusIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_SSM_2_1_CoreStatus;
}

void SigMData::setSSM_2_1_CoreStatus_v(const SSM_2_1_CoreStatus& i_SSM_2_1_CoreStatus_rt)
{
  mutex_o.take_b();

  m_SSM_2_1_CoreStatus = i_SSM_2_1_CoreStatus_rt;
  MessageStatus_Array[e_SSM_2_1_CoreStatusIndx].messageID_u32 = e_IpcMsgId_PpSR_State_MCU2_State_2_1;
  MessageStatus_Array[e_SSM_2_1_CoreStatusIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TbTHASmVc_FeatureOutputs_t SigMData::getTbTHASmVc_FeatureOutputs_t()
{
	TbTHASmVc_FeatureOutputs_t v_TbTHASmVc_FeatureOutputs_t;
  mutex_o.take_b();
  v_TbTHASmVc_FeatureOutputs_t = m_TbTHASmVc_FeatureOutputs_t;
  MessageStatus_Array[e_TbTHASmVc_FeatureOutputs_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbTHASmVc_FeatureOutputs_t;
}

void SigMData::setTbTHASmVc_FeatureOutputs_v(const TbTHASmVc_FeatureOutputs_t& i_TbTHASmVc_FeatureOutputs_t_rt)
{
  mutex_o.take_b();

  m_TbTHASmVc_FeatureOutputs_t = i_TbTHASmVc_FeatureOutputs_t_rt;
  MessageStatus_Array[e_TbTHASmVc_FeatureOutputs_tIndx].messageID_u32 = e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t;
  MessageStatus_Array[e_TbTHASmVc_FeatureOutputs_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

Detection_Inputs_from_TRSC_t SigMData::getDetection_Inputs_from_TRSC_t()
{
	Detection_Inputs_from_TRSC_t v_Detection_Inputs_from_TRSC_t;
  mutex_o.take_b();
  v_Detection_Inputs_from_TRSC_t = m_Detection_Inputs_from_TRSC_t;
  MessageStatus_Array[e_Detection_Inputs_from_TRSC_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_Detection_Inputs_from_TRSC_t;
}

void SigMData::setDetection_Inputs_from_TRSC_v(const Detection_Inputs_from_TRSC_t& i_Detection_Inputs_from_TRSC_t_rt)
{
  mutex_o.take_b();

  m_Detection_Inputs_from_TRSC_t = i_Detection_Inputs_from_TRSC_t_rt;
  MessageStatus_Array[e_Detection_Inputs_from_TRSC_tIndx].messageID_u32 = e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t;
  MessageStatus_Array[e_Detection_Inputs_from_TRSC_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

US_S_BlockageBit_t SigMData::getUS_S_BlockageBit_t()
{
	US_S_BlockageBit_t v_US_S_BlockageBit_t;
  mutex_o.take_b();
  v_US_S_BlockageBit_t = m_US_S_BlockageBit_t;
  MessageStatus_Array[e_US_S_BlockageBit_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_US_S_BlockageBit_t;
}

void SigMData::setUS_S_BlockageBit_v(const US_S_BlockageBit_t& i_US_S_BlockageBit_t_rt)
{
  mutex_o.take_b();

  m_US_S_BlockageBit_t = i_US_S_BlockageBit_t_rt;
  MessageStatus_Array[e_US_S_BlockageBit_tIndx].messageID_u32 = e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t;
  MessageStatus_Array[e_US_S_BlockageBit_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

US_S_USSErrorDiagData_t SigMData::getUS_S_USSErrorDiagData_t()
{
	US_S_USSErrorDiagData_t v_US_S_USSErrorDiagData_t;
  mutex_o.take_b();
  v_US_S_USSErrorDiagData_t = m_US_S_USSErrorDiagData_t;
  MessageStatus_Array[e_US_S_USSErrorDiagData_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_US_S_USSErrorDiagData_t;
}

void SigMData::setUS_S_USSErrorDiagData_v(const US_S_USSErrorDiagData_t& i_US_S_USSErrorDiagData_t_rt)
{
  mutex_o.take_b();

  m_US_S_USSErrorDiagData_t = i_US_S_USSErrorDiagData_t_rt;
  MessageStatus_Array[e_US_S_USSErrorDiagData_tIndx].messageID_u32 = e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t;
  MessageStatus_Array[e_US_S_USSErrorDiagData_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

THARelated_ScreenReq_t SigMData::getTHARelated_ScreenReq_t()
{
	THARelated_ScreenReq_t v_THARelated_ScreenReq_t;
  mutex_o.take_b();
  v_THARelated_ScreenReq_t = m_THARelated_ScreenReq_t;
  MessageStatus_Array[e_THARelated_ScreenReq_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_THARelated_ScreenReq_t;
}

void SigMData::setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt)
{
  mutex_o.take_b();

  m_THARelated_ScreenReq_t = i_THARelated_ScreenReq_t_rt;
  MessageStatus_Array[e_THARelated_ScreenReq_tIndx].messageID_u32 = e_IpcMsgId_Data_THARelated_ScreenReq_t;
  MessageStatus_Array[e_THARelated_ScreenReq_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

ErrorMgr_ErrorCommPack_QNX_QM SigMData::getErrorMgr_ErrorCommPack_QNX_QM()
{
	ErrorMgr_ErrorCommPack_QNX_QM v_ErrorMgr_ErrorCommPack_QNX_QM;
  mutex_o.take_b();
  v_ErrorMgr_ErrorCommPack_QNX_QM = m_ErrorMgr_ErrorCommPack_QNX_QM;
  MessageStatus_ArrayTx[e_ErrorMgr_ErrorCommPack_QNX_QMIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ErrorMgr_ErrorCommPack_QNX_QM;
}

void SigMData::setErrorMgr_ErrorCommPack_QNX_QM_v(const ErrorMgr_ErrorCommPack_QNX_QM& i_ErrorMgr_ErrorCommPack_QNX_QM_rt)
{
  mutex_o.take_b();

  m_ErrorMgr_ErrorCommPack_QNX_QM = i_ErrorMgr_ErrorCommPack_QNX_QM_rt;
  MessageStatus_ArrayTx[e_ErrorMgr_ErrorCommPack_QNX_QMIndx].messageID_u32 = e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM;
  MessageStatus_ArrayTx[e_ErrorMgr_ErrorCommPack_QNX_QMIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TRSC_Inputs_from_TrailerDetection_t SigMData::getTRSC_Inputs_from_TrailerDetection_t()
{
	TRSC_Inputs_from_TrailerDetection_t v_TRSC_Inputs_from_TrailerDetection_t;
  mutex_o.take_b();
  v_TRSC_Inputs_from_TrailerDetection_t = m_TRSC_Inputs_from_TrailerDetection_t;
  MessageStatus_ArrayTx[e_TRSC_Inputs_from_TrailerDetection_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TRSC_Inputs_from_TrailerDetection_t;
}

void SigMData::setTRSC_Inputs_from_TrailerDetection_v(const TRSC_Inputs_from_TrailerDetection_t& i_TRSC_Inputs_from_TrailerDetection_t_rt)
{
  mutex_o.take_b();

  m_TRSC_Inputs_from_TrailerDetection_t = i_TRSC_Inputs_from_TrailerDetection_t_rt;
  MessageStatus_ArrayTx[e_TRSC_Inputs_from_TrailerDetection_tIndx].messageID_u32 = e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t;
  MessageStatus_ArrayTx[e_TRSC_Inputs_from_TrailerDetection_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
MeDLD_e_RrCamSts_t SigMData::getMeDLD_e_RrCamSts_t()
{
	MeDLD_e_RrCamSts_t v_MeDLD_e_RrCamSts_t;
  mutex_o.take_b();
  v_MeDLD_e_RrCamSts_t = m_MeDLD_e_RrCamSts_t;
  MessageStatus_ArrayTx[e_MeDLD_e_RrCamSts_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_MeDLD_e_RrCamSts_t;
}

void SigMData::setMeDLD_e_RrCamSts_v(const MeDLD_e_RrCamSts_t& i_MeDLD_e_RrCamSts_t_rt)
{
  mutex_o.take_b();

  m_MeDLD_e_RrCamSts_t = i_MeDLD_e_RrCamSts_t_rt;
  MessageStatus_ArrayTx[e_MeDLD_e_RrCamSts_tIndx].messageID_u32 = e_IpcMsgId_data_MeDLD_e_RrCamSts_t;
  MessageStatus_ArrayTx[e_MeDLD_e_RrCamSts_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TbSVS_e_SVSCalibSMToAlgoCamCalib_t SigMData::getTbSVS_e_SVSCalibSMToAlgoCamCalib_t()
{
	TbSVS_e_SVSCalibSMToAlgoCamCalib_t v_TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
  mutex_o.take_b();
  v_TbSVS_e_SVSCalibSMToAlgoCamCalib_t = m_TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibSMToAlgoCamCalib_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
}

void SigMData::setTbSVS_e_SVSCalibSMToAlgoCamCalib_v(const TbSVS_e_SVSCalibSMToAlgoCamCalib_t& i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_e_SVSCalibSMToAlgoCamCalib_t = i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibSMToAlgoCamCalib_tIndx].messageID_u32 = e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibSMToAlgoCamCalib_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TbSVS_e_SVSCalibAlgoToSMCamCalib_t SigMData::getTbSVS_e_SVSCalibAlgoToSMCamCalib_t()
{
	TbSVS_e_SVSCalibAlgoToSMCamCalib_t v_TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
  mutex_o.take_b();
  v_TbSVS_e_SVSCalibAlgoToSMCamCalib_t = m_TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibAlgoToSMCamCalib_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
}

void SigMData::setTbSVS_e_SVSCalibAlgoToSMCamCalib_v(const TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_e_SVSCalibAlgoToSMCamCalib_t = i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibAlgoToSMCamCalib_tIndx].messageID_u32 = e_IpcMsgId_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibAlgoToSMCamCalib_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TbSVS_S_SVSCamCurrentCalibDataToNVM_t SigMData::getTbSVS_S_SVSCamCurrentCalibDataToNVM_t()
{
	TbSVS_S_SVSCamCurrentCalibDataToNVM_t v_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
  mutex_o.take_b();
  v_TbSVS_S_SVSCamCurrentCalibDataToNVM_t = m_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamCurrentCalibDataToNVM_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
}

void SigMData::setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t& i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_S_SVSCamCurrentCalibDataToNVM_t = i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamCurrentCalibDataToNVM_tIndx].messageID_u32 = e_IpcMsgId_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamCurrentCalibDataToNVM_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TbSVS_S_SVSCamOCCalibDataToNVM_t SigMData::getTbSVS_S_SVSCamOCCalibDataToNVM_t()
{
	TbSVS_S_SVSCamOCCalibDataToNVM_t v_TbSVS_S_SVSCamOCCalibDataToNVM_t;
  mutex_o.take_b();
  v_TbSVS_S_SVSCamOCCalibDataToNVM_t = m_TbSVS_S_SVSCamOCCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamOCCalibDataToNVM_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_S_SVSCamOCCalibDataToNVM_t;
}

void SigMData::setTbSVS_S_SVSCamOCCalibDataToNVM_v(const TbSVS_S_SVSCamOCCalibDataToNVM_t& i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_S_SVSCamOCCalibDataToNVM_t = i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamOCCalibDataToNVM_tIndx].messageID_u32 = e_IpcMsgId_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamOCCalibDataToNVM_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TbSVS_S_SVSCamSCCalibDataToNVM_t SigMData::getTbSVS_S_SVSCamSCCalibDataToNVM_t()
{
	TbSVS_S_SVSCamSCCalibDataToNVM_t v_TbSVS_S_SVSCamSCCalibDataToNVM_t;
  mutex_o.take_b();
  v_TbSVS_S_SVSCamSCCalibDataToNVM_t = m_TbSVS_S_SVSCamSCCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamSCCalibDataToNVM_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_S_SVSCamSCCalibDataToNVM_t;
}

void SigMData::setTbSVS_S_SVSCamSCCalibDataToNVM_v(const TbSVS_S_SVSCamSCCalibDataToNVM_t& i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_S_SVSCamSCCalibDataToNVM_t = i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamSCCalibDataToNVM_tIndx].messageID_u32 = e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamSCCalibDataToNVM_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
TbSVS_S_SVSCamEOLCalibDataToNVM_t SigMData::getTbSVS_S_SVSCamEOLCalibDataToNVM_t()
{
	TbSVS_S_SVSCamEOLCalibDataToNVM_t v_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
  mutex_o.take_b();
  v_TbSVS_S_SVSCamEOLCalibDataToNVM_t = m_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamEOLCalibDataToNVM_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
}

void SigMData::setTbSVS_S_SVSCamEOLCalibDataToNVM_v(const TbSVS_S_SVSCamEOLCalibDataToNVM_t& i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_S_SVSCamEOLCalibDataToNVM_t = i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamEOLCalibDataToNVM_tIndx].messageID_u32 = e_IpcMsgId_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
  MessageStatus_ArrayTx[e_TbSVS_S_SVSCamEOLCalibDataToNVM_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

JobTHADetOutput_t SigMData::getJobTHADetOutput_t()
{
	JobTHADetOutput_t v_JobTHADetOutput_t;
  mutex_o.take_b();
  v_JobTHADetOutput_t = m_JobTHADetOutput_t;
  MessageStatus_ArrayTx[e_JobTHADetOutput_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_JobTHADetOutput_t;
}

void SigMData::setJobTHADetOutput_v(const JobTHADetOutput_t& i_JobTHADetOutput_t_rt)
{
  mutex_o.take_b();

  m_JobTHADetOutput_t = i_JobTHADetOutput_t_rt;
  MessageStatus_ArrayTx[e_JobTHADetOutput_tIndx].messageID_u32 = e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t;
  MessageStatus_ArrayTx[e_JobTHADetOutput_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

CalDataProvider_MPU_1_0_Def SigMData::getCalDataProvider_MPU_1_0_Def()
{
	CalDataProvider_MPU_1_0_Def v_CalDataProvider_MPU_1_0_Def;
  mutex_o.take_b();
  v_CalDataProvider_MPU_1_0_Def = m_CalDataProvider_MPU_1_0_Def;
  MessageStatus_Array[e_CalDataProvider_MPU_1_0_DefIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_CalDataProvider_MPU_1_0_Def;
}

void SigMData::setCalDataProvider_MPU_1_0_Def_v(const CalDataProvider_MPU_1_0_Def& i_CalDataProvider_MPU_1_0_Def_rt)
{
  mutex_o.take_b();

  m_CalDataProvider_MPU_1_0_Def = i_CalDataProvider_MPU_1_0_Def_rt;
  MessageStatus_Array[e_CalDataProvider_MPU_1_0_DefIndx].messageID_u32 = e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def;
  MessageStatus_Array[e_CalDataProvider_MPU_1_0_DefIndx].sender_Status_b = true;

  mutex_o.give_v();
}

SSM_SystemState SigMData::getSSM_SystemState()
{
	SSM_SystemState v_SSM_SystemState;
  mutex_o.take_b();
  v_SSM_SystemState = m_SSM_SystemState;
  MessageStatus_Array[e_SSM_SystemStateIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_SSM_SystemState;
}

void SigMData::setSSM_SystemState_v(const SSM_SystemState& i_SSM_SystemState_rt)
{
  mutex_o.take_b();

  m_SSM_SystemState = i_SSM_SystemState_rt;
  MessageStatus_Array[e_SSM_SystemStateIndx].messageID_u32 = e_IpcMsgId_Data_SSM_SystemState;
  MessageStatus_Array[e_SSM_SystemStateIndx].sender_Status_b = true;

  mutex_o.give_v();
}

ErrorMgr_ErrorCommPack_QNX_B SigMData::getErrorMgr_ErrorCommPack_QNX_B()
{
	ErrorMgr_ErrorCommPack_QNX_B v_ErrorMgr_ErrorCommPack_QNX_B;
  mutex_o.take_b();
  v_ErrorMgr_ErrorCommPack_QNX_B = m_ErrorMgr_ErrorCommPack_QNX_B;
  MessageStatus_ArrayTx[e_ErrorMgr_ErrorCommPack_QNX_BIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ErrorMgr_ErrorCommPack_QNX_B;
}

void SigMData::setErrorMgr_ErrorCommPack_QNX_B_v(const ErrorMgr_ErrorCommPack_QNX_B& i_ErrorMgr_ErrorCommPack_QNX_B_rt)
{
  mutex_o.take_b();

  m_ErrorMgr_ErrorCommPack_QNX_B = i_ErrorMgr_ErrorCommPack_QNX_B_rt;
  MessageStatus_ArrayTx[e_ErrorMgr_ErrorCommPack_QNX_BIndx].messageID_u32 = e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B;
  MessageStatus_ArrayTx[e_ErrorMgr_ErrorCommPack_QNX_BIndx].sender_Status_b = true;

  mutex_o.give_v();
}

SSM_QNX_CoreStatus SigMData::getSSM_QNX_CoreStatus()
{
	SSM_QNX_CoreStatus v_SSM_QNX_CoreStatus;
  mutex_o.take_b();
  v_SSM_QNX_CoreStatus = m_SSM_QNX_CoreStatus;
  MessageStatus_ArrayTx[e_QNX_State_QNXIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_SSM_QNX_CoreStatus;
}

void SigMData::setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt)
{
  mutex_o.take_b();

  m_SSM_QNX_CoreStatus = i_SSM_QNX_CoreStatus_rt;
  MessageStatus_ArrayTx[e_QNX_State_QNXIndx].messageID_u32 = e_IpcMsgId_PpSR_State_QNX_State_QNX;
  MessageStatus_ArrayTx[e_QNX_State_QNXIndx].sender_Status_b = true;

  mutex_o.give_v();
}

Svs_CamEepromDataArray_t SigMData::getSvs_CamEepromDataArray_t()
{
	Svs_CamEepromDataArray_t v_Svs_CamEepromDataArray_t;
  mutex_o.take_b();
  v_Svs_CamEepromDataArray_t = m_Svs_CamEepromDataArray_t;
  MessageStatus_ArrayTx[e_Svs_CamEepromDataArrayIndx].sender_Status_b = false;
  mutex_o.give_v();
  return v_Svs_CamEepromDataArray_t;
}

void SigMData::setSvs_CamEepromDataArray_v(const Svs_CamEepromDataArray_t& i_Svs_CamEepromDataArray_t_rt)
{
  mutex_o.take_b();

  m_Svs_CamEepromDataArray_t = i_Svs_CamEepromDataArray_t_rt;
  MessageStatus_ArrayTx[e_Svs_CamEepromDataArrayIndx].messageID_u32 = e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t;
  MessageStatus_ArrayTx[e_Svs_CamEepromDataArrayIndx].sender_Status_b = true;

  mutex_o.give_v();
}

LMD_Outputs_CVPAMFDData2_t SigMData::getCVPAMFDData2_LMD_Outputs_CVPAMFDData()
{
	LMD_Outputs_CVPAMFDData2_t v_LMD_Outputs_CVPAMFDData2_t;
  mutex_o.take_b();
  v_LMD_Outputs_CVPAMFDData2_t = m_LMD_Outputs_CVPAMFDData2_t;
  MessageStatus_ArrayTx[e_LMD_Outputs_CVPAMFDData2_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_LMD_Outputs_CVPAMFDData2_t;
}

void SigMData::setCVPAMFDData2_LMD_Outputs_CVPAMFDData_v(const LMD_Outputs_CVPAMFDData2_t& i_LMD_Outputs_CVPAMFDData2_t_rt)
{
  mutex_o.take_b();

  m_LMD_Outputs_CVPAMFDData2_t = i_LMD_Outputs_CVPAMFDData2_t_rt;
  MessageStatus_ArrayTx[e_LMD_Outputs_CVPAMFDData2_tIndx].messageID_u32 = e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t;
  MessageStatus_ArrayTx[e_LMD_Outputs_CVPAMFDData2_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TrailerDetection_Output_DID_t SigMData::getTrailerDet_Output_DID()
{
	TrailerDetection_Output_DID_t v_TrailerDetection_Output_DID_t;
  mutex_o.take_b();
  v_TrailerDetection_Output_DID_t = m_TrailerDetection_Output_DID_t;
  MessageStatus_ArrayTx[e_TrailerDetection_Output_DID_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TrailerDetection_Output_DID_t;
}

void SigMData::setTrailerDet_Output_DID_v(const TrailerDetection_Output_DID_t& i_TrailerDetection_Output_DID_t_rt)
{
  mutex_o.take_b();

  m_TrailerDetection_Output_DID_t = i_TrailerDetection_Output_DID_t_rt;
  MessageStatus_ArrayTx[e_TrailerDetection_Output_DID_tIndx].messageID_u32 = e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t;
  MessageStatus_ArrayTx[e_TrailerDetection_Output_DID_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TbAP_DriveAssistStatOut_t SigMData::getTbAP_DriveAssistStatOut()
{
	TbAP_DriveAssistStatOut_t v_TbAP_DriveAssistStatOut_t;
  mutex_o.take_b();
  v_TbAP_DriveAssistStatOut_t = m_TbAP_DriveAssistStatOut_t;
  MessageStatus_Array[e_TbAP_DriveAssistStatOut_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbAP_DriveAssistStatOut_t;
}

void SigMData::setTbAP_DriveAssistStatOut_v(const TbAP_DriveAssistStatOut_t& i_TbAP_DriveAssistStatOut_t_rt)
{
  mutex_o.take_b();

  m_TbAP_DriveAssistStatOut_t = i_TbAP_DriveAssistStatOut_t_rt;
  MessageStatus_Array[e_TbAP_DriveAssistStatOut_tIndx].messageID_u32 = e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t;
  MessageStatus_Array[e_TbAP_DriveAssistStatOut_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

FID_STRUCT_B SigMData::getfid_struct()
{
  FID_STRUCT_B v_FID_STRUCT_B;
  mutex_o.take_b();
  v_FID_STRUCT_B = m_FID_STRUCT_B;
  MessageStatus_Array[e_FID_STRUCT_BIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_FID_STRUCT_B;
}

void SigMData::setfid_struct_v(const FID_STRUCT_B& i_FID_STRUCT_B_rt)
{
  mutex_o.take_b();

  m_FID_STRUCT_B = i_FID_STRUCT_B_rt;
  MessageStatus_Array[e_FID_STRUCT_BIndx].messageID_u32 = e_IpcMsgId_Data_FID_STRUCT_B;
  MessageStatus_Array[e_FID_STRUCT_BIndx].sender_Status_b = true;

  mutex_o.give_v();
}

LMD_Lane_Outputs_s SigMData::getLMD_Lane_Outputs()
{
	LMD_Lane_Outputs_s v_LMD_Lane_Outputs_s;
  mutex_o.take_b();
  v_LMD_Lane_Outputs_s = m_LMD_Lane_Outputs_s;
  MessageStatus_ArrayTx[e_LMD_Lane_Outputs_sIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_LMD_Lane_Outputs_s;
}

void SigMData::setLMD_Lane_Outputs_v(const LMD_Lane_Outputs_s& i_LMD_Lane_Outputs_s_rt)
{
  mutex_o.take_b();

  m_LMD_Lane_Outputs_s = i_LMD_Lane_Outputs_s_rt;
  MessageStatus_ArrayTx[e_LMD_Lane_Outputs_sIndx].messageID_u32 = e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s;
  MessageStatus_ArrayTx[e_LMD_Lane_Outputs_sIndx].sender_Status_b = true;

  mutex_o.give_v();
}

THA_Calibration_data_MPU1_0_t SigMData::getTHA_Calibration_data_MPU1_0()
{
	THA_Calibration_data_MPU1_0_t v_THA_Calibration_data_MPU1_0_t;
  mutex_o.take_b();
  v_THA_Calibration_data_MPU1_0_t = m_THA_Calibration_data_MPU1_0_t;
  MessageStatus_Array[e_THA_Calibration_data_MPU1_0_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_THA_Calibration_data_MPU1_0_t;
}

void SigMData::setTHA_Calibration_data_MPU1_0_v(const THA_Calibration_data_MPU1_0_t& i_THA_Calibration_data_MPU1_0_t_rt)
{
  mutex_o.take_b();

  m_THA_Calibration_data_MPU1_0_t = i_THA_Calibration_data_MPU1_0_t_rt;
  MessageStatus_Array[e_THA_Calibration_data_MPU1_0_tIndx].messageID_u32 = e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t;
  MessageStatus_Array[e_THA_Calibration_data_MPU1_0_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

APA_Calibration_data_MPU1_0_t SigMData::getAPA_Calibration_data_MPU1_0()
{
	APA_Calibration_data_MPU1_0_t v_APA_Calibration_data_MPU1_0_t;
  mutex_o.take_b();
  v_APA_Calibration_data_MPU1_0_t = m_APA_Calibration_data_MPU1_0_t;
  MessageStatus_Array[e_APA_Calibration_data_MPU1_0_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_APA_Calibration_data_MPU1_0_t;
}

void SigMData::setAPA_Calibration_data_MPU1_0_v(const APA_Calibration_data_MPU1_0_t& i_APA_Calibration_data_MPU1_0_t_rt)
{
  mutex_o.take_b();

  m_APA_Calibration_data_MPU1_0_t = i_APA_Calibration_data_MPU1_0_t_rt;
  MessageStatus_Array[e_APA_Calibration_data_MPU1_0_tIndx].messageID_u32 = e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t;
  MessageStatus_Array[e_APA_Calibration_data_MPU1_0_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

LMD_Calibration_data_t SigMData::getLMD_Calibration_data()
{
	LMD_Calibration_data_t v_LMD_Calibration_data_t;
  mutex_o.take_b();
  v_LMD_Calibration_data_t = m_LMD_Calibration_data_t;
  MessageStatus_Array[e_LMD_Calibration_data_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_LMD_Calibration_data_t;
}

void SigMData::setLMD_Calibration_data_v(const LMD_Calibration_data_t& i_LMD_Calibration_data_t_rt)
{
  mutex_o.take_b();

  m_LMD_Calibration_data_t = i_LMD_Calibration_data_t_rt;
  MessageStatus_Array[e_LMD_Calibration_data_tIndx].messageID_u32 = e_IpcMsgId_Data_LMD_Calibration_data_t;
  MessageStatus_Array[e_LMD_Calibration_data_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TRSC_Calibration_data_MPU1_0_t SigMData::getTRSC_Calibration_data_MPU1_0()
{
	TRSC_Calibration_data_MPU1_0_t v_TRSC_Calibration_data_MPU1_0_t;
  mutex_o.take_b();
  v_TRSC_Calibration_data_MPU1_0_t = m_TRSC_Calibration_data_MPU1_0_t;
  MessageStatus_Array[e_TRSC_Calibration_data_MPU1_0_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TRSC_Calibration_data_MPU1_0_t;
}

void SigMData::setTRSC_Calibration_data_MPU1_0_v(const TRSC_Calibration_data_MPU1_0_t& i_TRSC_Calibration_data_MPU1_0_t_rt)
{
  mutex_o.take_b();

  m_TRSC_Calibration_data_MPU1_0_t = i_TRSC_Calibration_data_MPU1_0_t_rt;
  MessageStatus_Array[e_TRSC_Calibration_data_MPU1_0_tIndx].messageID_u32 = e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t;
  MessageStatus_Array[e_TRSC_Calibration_data_MPU1_0_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TbSVS_e_SVSCalibSMToHmi_t SigMData::getTbSVS_e_SVSCalibSMToHmi()
{
	TbSVS_e_SVSCalibSMToHmi_t v_TbSVS_e_SVSCalibSMToHmi_t;
  mutex_o.take_b();
  v_TbSVS_e_SVSCalibSMToHmi_t = m_TbSVS_e_SVSCalibSMToHmi_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibSMToHmi_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_e_SVSCalibSMToHmi_t;
}

void SigMData::setTbSVS_e_SVSCalibSMToHmi_v(const TbSVS_e_SVSCalibSMToHmi_t& i_TbSVS_e_SVSCalibSMToHmi_t_rt)
{
  mutex_o.take_b();

  m_TbSVS_e_SVSCalibSMToHmi_t = i_TbSVS_e_SVSCalibSMToHmi_t_rt;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibSMToHmi_tIndx].messageID_u32 = e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToHmi_t;
  MessageStatus_ArrayTx[e_TbSVS_e_SVSCalibSMToHmi_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

ME_Proxi_MPU1_0_to_MCU1_0_t SigMData::getME_Proxi_MPU1_0_to_MCU1_0()
{
	ME_Proxi_MPU1_0_to_MCU1_0_t v_ME_Proxi_MPU1_0_to_MCU1_0_t;
  mutex_o.take_b();
  v_ME_Proxi_MPU1_0_to_MCU1_0_t = m_ME_Proxi_MPU1_0_to_MCU1_0_t;
  MessageStatus_ArrayTx[e_ME_Proxi_MPU1_0_to_MCU1_0_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ME_Proxi_MPU1_0_to_MCU1_0_t;
}

void SigMData::setME_Proxi_MPU1_0_to_MCU1_0_v(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt)
{
  mutex_o.take_b();

  m_ME_Proxi_MPU1_0_to_MCU1_0_t = i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt;
  MessageStatus_ArrayTx[e_ME_Proxi_MPU1_0_to_MCU1_0_tIndx].messageID_u32 = e_IpcMsgId_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t;
  MessageStatus_ArrayTx[e_ME_Proxi_MPU1_0_to_MCU1_0_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

FID_STRUCT_QM SigMData::getFID_STRUCT_QM()
{
	FID_STRUCT_QM v_FID_STRUCT_QM;
	mutex_o.take_b();
	v_FID_STRUCT_QM = m_FID_STRUCT_QM;
	MessageStatus_Array[e_FID_STRUCT_QM_Indx].sender_Status_b = false;
	mutex_o.give_v();

	return v_FID_STRUCT_QM;
}

void SigMData::setFID_STRUCT_QM_v(const FID_STRUCT_QM& i_FID_STRUCT_QM_rt)
{
  mutex_o.take_b();

  m_FID_STRUCT_QM = i_FID_STRUCT_QM_rt;
  MessageStatus_Array[e_FID_STRUCT_QM_Indx].messageID_u32 = e_IpcMsgId_Data_FID_STRUCT_QM;
  MessageStatus_Array[e_FID_STRUCT_QM_Indx].sender_Status_b = true;

  mutex_o.give_v();
}

TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t SigMData::getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(bool_t *o_ReceiveStatus_pb )
{
  TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t v_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
  mutex_o.take_b();
  v_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t = tbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
  *o_ReceiveStatus_pb = MessageStatus_Array[e_FunctionalSettingsNVMToSVSCalibSM_tIndx].receiver_Status_b;
  MessageStatus_Array[e_FunctionalSettingsNVMToSVSCalibSM_tIndx].receiver_Status_b = false;
  mutex_o.give_v();

  return v_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
}

void SigMData::setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t& i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt)
{
  mutex_o.take_b();

  tbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t = i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt;
  MessageStatus_Array[e_FunctionalSettingsNVMToSVSCalibSM_tIndx].messageID_u32 = e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
  MessageStatus_Array[e_FunctionalSettingsNVMToSVSCalibSM_tIndx].receiver_Status_b= true;

  mutex_o.give_v();
}

TrailerDetection_Output_HMI_t SigMData::getTrailerDetection_Output_HMI()
{
	TrailerDetection_Output_HMI_t v_TrailerDetection_Output_HMI_t_rt;
	mutex_o.take_b();
	m_TrailerDetection_Output_HMI_t = m_TrailerDetection_Output_HMI_t;
	MessageStatus_ArrayTx[e_TrailerDetection_Output_HMI_tIndx].sender_Status_b = false;
	mutex_o.give_v();

	return v_TrailerDetection_Output_HMI_t_rt;
}

void SigMData::setTrailerDetection_Output_HMI_v(const TrailerDetection_Output_HMI_t& i_TrailerDetection_Output_HMI_t_rt)
{
  mutex_o.take_b();

  m_TrailerDetection_Output_HMI_t = i_TrailerDetection_Output_HMI_t_rt;
  MessageStatus_ArrayTx[e_TrailerDetection_Output_HMI_tIndx].messageID_u32 = e_IpcMsgId_Data_TrailerDetection_Output_HMI_t;
  MessageStatus_ArrayTx[e_TrailerDetection_Output_HMI_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

JobDLDOutput_t SigMData::getJobDLDOutput()
{
	JobDLDOutput_t v_JobDLDOutput;
  mutex_o.take_b();
  v_JobDLDOutput = m_JobDLDOutput_t;
  MessageStatus_ArrayTx[e_JobDLDOutput_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_JobDLDOutput;
}

void SigMData::setJobDLDOutput_v(const JobDLDOutput_t& i_JobDLDOutput_rt)
{
  mutex_o.take_b();

  m_JobDLDOutput_t = i_JobDLDOutput_rt;
  MessageStatus_ArrayTx[e_JobDLDOutput_tIndx].messageID_u32 = e_IpcMsgId_PpDLDOutput_JobDLDOutput_t;
  MessageStatus_ArrayTx[e_JobDLDOutput_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

Error_Fault_MPU1_0_t SigMData::getError_Fault_MPU1_0()
{
	Error_Fault_MPU1_0_t v_Error_Fault_MPU1_0;
  mutex_o.take_b();
  v_Error_Fault_MPU1_0 = m_Error_Fault_MPU1_0_t;
  MessageStatus_ArrayTx[e_Error_Fault_MPU1_0_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_Error_Fault_MPU1_0;
}

void SigMData::setError_Fault_MPU1_0_v(const Error_Fault_MPU1_0_t& i_Error_Fault_MPU1_0_rt)
{
  mutex_o.take_b();

  m_Error_Fault_MPU1_0_t = i_Error_Fault_MPU1_0_rt;
  MessageStatus_ArrayTx[e_Error_Fault_MPU1_0_tIndx].messageID_u32 = e_IpcMsgId_PpErrFltMpu1_0_Error_Fault_MPU1_0_t;
  MessageStatus_ArrayTx[e_Error_Fault_MPU1_0_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

TRSC_CalibrationClear_t SigMData::getTRSC_CalibrationClear_t()
{
	TRSC_CalibrationClear_t v_TRSC_CalibrationClear_t;
  mutex_o.take_b();
  v_TRSC_CalibrationClear_t = m_TRSC_CalibrationClear_t;
  MessageStatus_Array[e_TRSC_CalibrationClear_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TRSC_CalibrationClear_t;
}

void SigMData::setTRSC_CalibrationClear_v(const TRSC_CalibrationClear_t& i_TRSC_CalibrationClear_t_rt)
{
  mutex_o.take_b();

  m_TRSC_CalibrationClear_t = i_TRSC_CalibrationClear_t_rt;
  MessageStatus_Array[e_TRSC_CalibrationClear_tIndx].messageID_u32 = e_IpcMsgId_Data_TRSC_CalibrationClear_t;
  MessageStatus_Array[e_TRSC_CalibrationClear_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
PerformanceStatsEnable_t SigMData::getPerformanceStatsEnable_t()
{
	PerformanceStatsEnable_t v_PerformanceStatsEnable_t;
  mutex_o.take_b();
  v_PerformanceStatsEnable_t = m_PerformanceStatsEnable_t;
  MessageStatus_Array[e_PerformanceStatsEnable_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_PerformanceStatsEnable_t;
}

void SigMData::setPerformanceStatsEnable_v(const PerformanceStatsEnable_t& i_PerformanceStatsEnable_t_rt)
{
  mutex_o.take_b();

  m_PerformanceStatsEnable_t = i_PerformanceStatsEnable_t_rt;
  MessageStatus_Array[e_PerformanceStatsEnable_tIndx].messageID_u32 = e_IpcMsgId_Data_PerformanceStatsEnable_t;
  MessageStatus_Array[e_PerformanceStatsEnable_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
RunTimeStats_MPU1_0_t SigMData::getRunTimeStats_MPU1_0_t()
{
	RunTimeStats_MPU1_0_t v_RunTimeStats_MPU1_0;
  mutex_o.take_b();
  v_RunTimeStats_MPU1_0 = m_RunTimeStats_MPU1_0_t;
  MessageStatus_ArrayTx[e_RunTimeStats_MPU1_0_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_RunTimeStats_MPU1_0;
}

void SigMData::setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt)
{
  mutex_o.take_b();

  m_RunTimeStats_MPU1_0_t = i_RunTimeStats_MPU1_0_rt;
  MessageStatus_ArrayTx[e_RunTimeStats_MPU1_0_tIndx].messageID_u32 = e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t;
  MessageStatus_ArrayTx[e_RunTimeStats_MPU1_0_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}
CamHotplugStatus_t SigMData::getCamHotplugStatus_t()
{
	CamHotplugStatus_t v_CamHotplugStatus_t;
  mutex_o.take_b();
  v_CamHotplugStatus_t = m_CamHotplugStatus_t;
  MessageStatus_Array[e_CamHotplugStatus_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_CamHotplugStatus_t;
}

void SigMData::setCamHotplugStatus_v(const CamHotplugStatus_t& i_CamHotplugStatus_t_rt)
{
  mutex_o.take_b();

  m_CamHotplugStatus_t = i_CamHotplugStatus_t_rt;
  MessageStatus_Array[e_CamHotplugStatus_tIndx].messageID_u32 = e_IpcMsgId_Data_CamHotplugStatus_t;
  MessageStatus_Array[e_CamHotplugStatus_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

uint8_t SigMData::getVariantID(void)
{
	uint8_t var_id;
	mutex_o.take_b();
	var_id = m_VariantID;
	mutex_o.give_v();
	return var_id;
}

void SigMData::setVariantID(const uint8_t var_id)
{
  mutex_o.take_b();
  m_VariantID = var_id;
  mutex_o.give_v();
}

uint8_t SigMData::getRadioDisp(void)
{
	uint8_t radio_id;
	mutex_o.take_b();
	radio_id = m_RadioDisp;
	mutex_o.give_v();
	return radio_id;
}

void SigMData::setRadioDisp(const uint8_t radio_id)
{
  mutex_o.take_b();
  m_RadioDisp = radio_id;
  mutex_o.give_v();
}

uint8_t SigMData::getETFS_mount_status(void)
{
	uint8_t etfs_status;
	mutex_o.take_b();
	etfs_status = m_etfs_mount_status;
	mutex_o.give_v();
	return etfs_status;
}

void SigMData::setETFS_mount_status(const uint8_t etfs_status)
{
  mutex_o.take_b();
  m_etfs_mount_status = etfs_status - '0';
  mutex_o.give_v();
}

uint32_t SigMData::getRenderFrameID(void)
{
	uint32_t v_frameNum_32;
	mutex_o.take_b();
	v_frameNum_32 = m_render_frameNum;
	mutex_o.give_v();
	return v_frameNum_32;
}

void SigMData::setRenderFrameID(const uint32_t i_render_frameNum)
{
  mutex_o.take_b();
  m_render_frameNum = i_render_frameNum;
  mutex_o.give_v();
}

TRSCDebug_ScrReq_t SigMData::getTRSCDebug_ScrReq()
{
	TRSCDebug_ScrReq_t v_TRSCDebug_ScrReq_t;
  mutex_o.take_b();
  v_TRSCDebug_ScrReq_t = m_TRSCDebug_ScrReq_t;
  MessageStatus_Array[e_TRSCDebug_ScrReq_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_TRSCDebug_ScrReq_t;
}

void SigMData::setTRSCDebug_ScrReq_v(const TRSCDebug_ScrReq_t& i_TRSCDebug_ScrReq_t_rt)
{
  mutex_o.take_b();

  m_TRSCDebug_ScrReq_t = i_TRSCDebug_ScrReq_t_rt;
  MessageStatus_Array[e_TRSCDebug_ScrReq_tIndx].messageID_u32 = e_IpcMsgId_Data_TRSCDebug_ScrReq_t;
  MessageStatus_Array[e_TRSCDebug_ScrReq_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

ME_CanDebugRIDStatus_t SigMData::getCanDebugRIDStatus()
{
	ME_CanDebugRIDStatus_t v_ME_CanDebugRIDStatus_t;
  mutex_o.take_b();
  v_ME_CanDebugRIDStatus_t = m_ME_CanDebugRIDStatus_t;
  MessageStatus_Array[e_ME_CanDebugRIDStatus_tIndx].sender_Status_b = false;
  mutex_o.give_v();

  return v_ME_CanDebugRIDStatus_t;
}

void SigMData::setCanDebugRIDStatus_v(const ME_CanDebugRIDStatus_t& i_ME_CanDebugRIDStatus_t_rt)
{
  mutex_o.take_b();

  m_ME_CanDebugRIDStatus_t = i_ME_CanDebugRIDStatus_t_rt;
  MessageStatus_Array[e_ME_CanDebugRIDStatus_tIndx].messageID_u32 = e_IpcMsgId_Data_ME_CanDebugRIDStatus_t;
  MessageStatus_Array[e_ME_CanDebugRIDStatus_tIndx].sender_Status_b = true;

  mutex_o.give_v();
}

uint32_t SigMData::getSigMRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_SigM_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void SigMData::setSigMRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_SigM_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t SigMData::getThSigMRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_ThSigM_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void SigMData::setThSigMRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_ThSigM_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t SigMData::getKeepAliveRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_KeepAlive_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void SigMData::setKeepAliveRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_KeepAlive_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t SigMData::getMsgSndrRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_MsgSndr_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void SigMData::setMsgSndrRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_MsgSndr_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t SigMData::getLogMRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_LogM_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void SigMData::setLogMRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_LogM_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}
} // namespace container
