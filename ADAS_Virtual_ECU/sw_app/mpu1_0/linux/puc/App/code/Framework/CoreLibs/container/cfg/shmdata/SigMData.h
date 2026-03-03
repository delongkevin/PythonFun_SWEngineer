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

#ifndef CONTAINER_SIGM_DATA_H
#define CONTAINER_SIGM_DATA_H

#include <osal/threading/Mutex.h>
#include "platform/PlatformAPI.h"

#include "container/DataContainer.h"
#include "SigM_Messages.h"

#include "variants/Components.h"
#include "variants/Enums.h"
#include "variants/Assets.h"
#include "cfg/SerializerCXD4963ER.h"
//#include "ME_CalibSVS_local.h"

namespace container
{
typedef struct ME_EolTargetData_s
{
  sint8_t TargetInit_s8;              /* Target Init               */
  sint8_t TargetLimitFront_s8;        /* Target Limit Front        */
  sint8_t TargetLimitRear_s8;         /* Target Limit Rear         */
  sint8_t TargetDetectLeftFront_s8;   /* Target Detect Left-Front  */
  sint8_t TargetDetectLeftRear_s8;    /* Target Detect Left-Rear   */
  sint8_t TargetDetectRightFront_s8;  /* Target Detect Right-Front */
  sint8_t TargetDetectRightRear_s8;   /* Target Detect Right-Rear  */
  sint8_t Reserved_s8;
} ME_EolTargetData_t;

typedef struct ME_EolStatus_s
{
  float32_t deltaPitch_f32;
  float32_t deltaYaw_f32;
  float32_t deltaRoll_f32;
  float32_t deltaX_f32;
  float32_t deltaY_f32;
  float32_t deltaZ_f32;
  uint16_t  markerDetectionLeft_u16[10];
  uint16_t  markerDetectionRight_u16[10];
  variants::EolAlgoStateE_t  algoState_t;
  variants::EolErrorCodeE_t  errorCode_t;
  ME_EolTargetData_t   targetData_s;
} ME_EolStatus_t;

typedef struct ME_ScStatus_s
{
  float32_t deltaPitch_f32;
  float32_t deltaYaw_f32;
  float32_t deltaRoll_f32;
  float32_t deltaX_f32;
  float32_t deltaY_f32;
  float32_t deltaZ_f32;
  uint32_t    algoState_u32;
  uint32_t    errorCode_u32;
} ME_ScStatus_t;

typedef struct ME_OCStatus_s
{
  float32_t deltaPitch_f32;
  float32_t deltaYaw_f32;
  float32_t deltaRoll_f32;
  uint32_t    validFeatures_u32;
  uint32_t    ignoredFeatures_u32;
  uint32_t    invalidFeatures_u32;
  uint32_t    algoState_u32;
  uint32_t    errorCode_u32;
} ME_OCStatus_t;

typedef struct ME_TEOLStatus_s
{
  float32_t deltaPitch_f32;
  float32_t deltaYaw_f32;
  float32_t deltaRoll_f32;
  uint32_t    validFeatures_u32;
  uint32_t    ignoredFeatures_u32;
  uint32_t    invalidFeatures_u32;
  uint32_t    algoState_u32;
  uint32_t    errorCode_u32;
} ME_TEOLStatus_t;

typedef struct RequestTarget_s // PRQA S 2400 // global scope, yes
{
    uint32_t numberOfSquares_u32; /* number of squares for target 1 */
    sint32_t targetX_s32; /* X-( center -)position of target 1 */
    sint32_t targetY_s32; /* Y-( center -)position of target 1 */
    sint32_t orientation_s32; /* orientation of target 1 in degrees */
} RequestTarget_t;


typedef struct RequestEOLCmd_s // PRQA S 2400 // global scope, yes
{
    variants::Camera_t camera_t;
    variants::CalibrationRequestE_t cmd_t;
    variants::CalibrationTypeE_t calibrationType_t;
    uint32_t frameId_u32;
    uint8_t Algo_Selected_u8;
    uint8_t Read_Offset_u8;

    RequestTarget_t targets_at[2];
} RequestEOLCmd_t;


typedef struct ResponseEOLCmd_s // PRQA S 2400 // global scope, yes
{
    variants::Camera_t              camera_t;
    variants::CalibrationRequestE_t cmd_t;
    variants::CalibrationTypeE_t    calibrationType_t;
    uint32_t                        frameId_u32;
    uint32_t                        numberOfTargets_u32;
    ME_EolStatus_t                  status_t;
} ResponseEOLCmd_t;


typedef RequestEOLCmd_t RequestSCCmd_t;
typedef ResponseEOLCmd_t ResponseSCCmd_t;

typedef struct RequestOCCmd_s // PRQA S 2400 // global scope, yes
{
    uint32_t                        camera_u32;
    variants::CalibrationRequestE_t cmd_t;
    variants::CalibrationTypeE_t    calibrationType_t;
    uint32_t                        frameId_u32;
} RequestOCCmd_t;

typedef struct ResponseOCCmd_s // PRQA S 2400 // global scope, yes
{
    uint32_t                        camera_u32;
    variants::CalibrationRequestE_t cmd_t;
    variants::CalibrationTypeE_t    calibrationType_t;
    uint32_t                        frameId_u32;
    ME_OCStatus_t                   status_at[variants::e_CameraCount];
} ResponseOCCmd_t;

typedef struct RequestTEOLCmd_s // PRQA S 2400 // global scope, yes
{
    variants::Camera_t              camera_t;
    variants::CalibrationRequestE_t cmd_t;
    variants::CalibrationTypeE_t    calibrationType_t;
    uint32_t                        frameId_u32;
} RequestTEOLCmd_t;

typedef struct ResponseTEOLCmd_s // PRQA S 2400 // global scope, yes
{
    variants::Camera_t              camera_t;
    variants::CalibrationRequestE_t cmd_t;
    variants::CalibrationTypeE_t    calibrationType_t;
    uint32_t                        frameId_u32;
    ME_TEOLStatus_t                 status_t;
} ResponseTEOLCmd_t;



#pragma pack(1) // exact fit - no padding // PRQA S 1040 // pragma needed for structures
typedef struct ErrorDataCamera_s
{
  uint16_t DetErr_u16;                  // 2
  uint16_t CorrErr_u16;                 // 4

  uint8_t ConfigLinkDetected_u8   : 1;
  uint8_t VideoLinkDetected_u8    : 1;
  uint8_t HLocked_u8              : 1;
  uint8_t LengthErr_u8            : 1;
  uint8_t LineBufferOverflow_u8   : 1;
  uint8_t VSyncdetect_u8          : 1;
  uint8_t FSync_Locked_u8         : 1;
  uint8_t reserved0_u8            : 1;  // 5

  uint8_t reserved4_u8            : 4;
  uint8_t reserved5_u8            : 1;
  uint8_t EepromCrcError_u8       : 1;
  uint8_t RunningStatus_u8        : 1;
  uint8_t PowerStatus_u8          : 1;  // 6

  ErrorDataCamera_s()
    : DetErr_u16(0)
    , CorrErr_u16(0)
    , ConfigLinkDetected_u8(0)
    , VideoLinkDetected_u8(0)
    , HLocked_u8(0)
    , LengthErr_u8(0)
    , LineBufferOverflow_u8(0)
    , VSyncdetect_u8(0)
    , FSync_Locked_u8(0)
    , reserved0_u8(0)
    , reserved4_u8(0)
    , reserved5_u8(0)
    , EepromCrcError_u8(0)
    , RunningStatus_u8(0)
    , PowerStatus_u8(0)
  {
  }

} ErrorDataCamera_t;
#pragma pack() //back to whatever the previous packing mode was // PRQA S 1040 // pragma needed for structures

class SigMData : public DataContainer
{
public:
  SigMData();
  virtual ~SigMData();
#ifdef USE_REQUEST_AND_RESPONSE
  ScreenRequest_t getScreenRequest_t();
#else
  ScreenRequest_t getScreenRequest_t(bool_t *o_receive_status_b_p );
#endif  
  void setScreenRequest_v(const ScreenRequest_t& i_ScreenRequest_rt);

  ScreenResponse_t getScreenResponse_t();
  void setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt);

//  TbSVS_e_SVSOutputToNVMCamCalibSM_t getTbSVS_e_SVSOutputToNVMCamCalibSM_t();
//  void setTbSVS_e_SVSOutputToNVMCamCalibSM_v(const TbSVS_e_SVSOutputToNVMCamCalibSM_t& i_TbSVS_e_SVSOutputToNVMCamCalibSM_rt);

  MessageStatus_t getMessageStatus_t(uint8_t i_index_u8);

  TRA_Data_Request_t getTRAData_t();
  void  setTRARequest_v(const TRA_Data_Request_t& i_TRA_rt);

  TRA_Data_Response_t getTRAResponse_t();
  void  setTRAResponse_v(const TRA_Data_Response_t& i_TRA_rt);

  MiscRequest_t getMiscRequest_t();
  void setMiscRequest_v(const MiscRequest_t& i_MiscRequest_rt);

  MCU_TRAGateway1Request_t getMCUTRAGateway1_t();
  void setMCUTRAGateway1Request_v(const MCU_TRAGateway1Request_t& i_MCUTRAGateway1_rt);
  
  MCU_TRAGateway2Request_t getMCUTRAGateway2_t();
  void  setMCUTRAGateway2Request_v(const MCU_TRAGateway2Request_t& i_MCUTRAGateway2_rt);
  
  MCU_TRAGateway3Request_t getMCUTRAGateway3_t();
  void  setMCUTRAGateway3Request_v(const MCU_TRAGateway3Request_t& i_MCUTRAGateway3_rt);

  MCU_TRAGateway4Request_t getMCUTRAGateway4_t();
  void  setMCUTRAGateway4Request_v(const MCU_TRAGateway4Request_t& i_MCUTRAGateway4_rt);
  
  VehicleStateRequest_t getVehicleState_s();
  void setVehicleState_v(const VehicleStateRequest_t& i_VehicleState_s);

  ApplyConfigRequest_t getApplyConfig_t();
  void setApplyConfig_v(const ApplyConfigRequest_t& i_ApplyConfig_rs);

  void setEolAlgoFinishedCmd_v(bool_t flag_b );

  bool_t getEolAlgoFinishedCmd_b();

  void setEolTriggeredFlag_v();
  void resetEolTriggeredFlag_v();
  bool_t isEolAlgoTriggered_b();

  void setRequestEOLCmd_v(const RequestEOLCmd_t&  i_RequestEOLCmd_rt  );
  const RequestEOLCmd_t&  getRequestEOLCmd_rt(void) const;
  void setResponseEOLCmd_v(const ResponseEOLCmd_t*  i_ResponseEOLCmd_rt  );
  const ResponseEOLCmd_t*  getResponseEOLCmd_rt(void ) const;

  void setRequestOCCmd_v(const RequestOCCmd_t&  i_RequestOCCmd_rt  );
  const RequestOCCmd_t&  getRequestOCCmd_rt(void) const;
  void setResponseOCCmd_v(const ResponseOCCmd_t&  i_ResponseOCCmd_rt  );
  const ResponseOCCmd_t&  getResponseOCCmd_rt(void ) const;

  void setRequestTEOLCmd_v(const RequestTEOLCmd_t&  i_RequestTEOLCmd_rt  );
  const RequestTEOLCmd_t&  getRequestTEOLCmd_rt(void) const;
  void setResponseTEOLCmd_v(const ResponseTEOLCmd_t&  i_ResponseTEOLCmd_rt  );
  const ResponseTEOLCmd_t&  getResponseTEOLCmd_rt(void ) const;

  variants::Camera_t                  getCalibrationCamera_t(void) const;
  void                                setCalibrationCamera_v(const variants::Camera_t i_CalibrationCamera_t);

  variants::CalibrationTypeE_t        getCalibrationType_t(void) const;
  void                                setCalibrationType_v(const variants::CalibrationTypeE_t i_CalibrationType_t);

  void setErrorDataCamera_v(variants::Camera_t i_Cam_t, const ErrorDataCamera_t& i_ErrorDataCamera_rt);
  ErrorDataCamera_t getErrorDataCamera_t(variants::Camera_t i_Cam_t);

  variants::HmiSoftButtonStatus_t getHmiSoftButtonStatus_t(variants::HmiSoftButton_t i_SoftButton_e);
  void setHmiSoftButtonStatus_v(variants::HmiSoftButton_t i_SoftButton_e,variants::HmiSoftButtonStatus_t i_Status_e);

  TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t *o_receive_status_b_p );
  void setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t& i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt);
  TbSVS_e_SVSOutputToDiagMgrCamCalib_t getTbSVS_e_SVSOutputToDiagMgrCamCalib_t();
  void setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t& i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt);


  IKinematicData_t getIKinematicData_t();
  void setIKinematicData_v(const IKinematicData_t&);

  IJobPLDOutput_t getIJobPLDOutput_t();
  void setIJobPLDOutput_v(const IJobPLDOutput_t&);

  IParkingSlotInformation_t getIParkingSlotInformation_t();
  void setIParkingSlotInformation_v(const IParkingSlotInformation_t&);

  IFPAInfoToPLD_t getIFPAInfoToPLD_t();
  void setIFPAInfoToPLD_v(const IFPAInfoToPLD_t&);

  MOT_Output getMOT_Output_t();
  void setMOT_Output_v(const MOT_Output& );

  variants::Language_t getLanguageId_t(void);

  ME_VehInp_to_IpcSignals_t getME_VehInp_to_IpcSignals_t();
  void setME_VehInp_to_IpcSignals_v(const ME_VehInp_to_IpcSignals_t& );
  ME_ProxiToMPU1_0_Def_t getME_Proxi_to_IpcSignals_t();
  void setME_Proxi_to_IpcSignals_v(const ME_ProxiToMPU1_0_Def_t& i_ME_Proxi_to_IpcSignals_t_rt);
  SvsToTHADet_t getSvsToTHADet_t();
  void setSvsToTHADet_v(const SvsToTHADet_t& i_SvsToTHADet_t_rt);
  SSM_2_0_CoreStatus getSSM_2_0_CoreStatus();
  void setSSM_2_0_CoreStatus_v(const SSM_2_0_CoreStatus& i_SSM_2_0_CoreStatus_rt);
  SSM_2_1_CoreStatus getSSM_2_1_CoreStatus();
  void setSSM_2_1_CoreStatus_v(const SSM_2_1_CoreStatus& i_SSM_2_1_CoreStatus_rt);
  TbTHASmVc_FeatureOutputs_t getTbTHASmVc_FeatureOutputs_t();
  void setTbTHASmVc_FeatureOutputs_v(const TbTHASmVc_FeatureOutputs_t& i_TbTHASmVc_FeatureOutputs_t_rt);
  Detection_Inputs_from_TRSC_t getDetection_Inputs_from_TRSC_t();
  void setDetection_Inputs_from_TRSC_v(const Detection_Inputs_from_TRSC_t& i_Detection_Inputs_from_TRSC_t_rt);
  US_S_BlockageBit_t getUS_S_BlockageBit_t();
  void setUS_S_BlockageBit_v(const US_S_BlockageBit_t& i_US_S_BlockageBit_t_rt);
  US_S_USSErrorDiagData_t getUS_S_USSErrorDiagData_t();
  void setUS_S_USSErrorDiagData_v(const US_S_USSErrorDiagData_t& i_US_S_USSErrorDiagData_t_rt);
  THARelated_ScreenReq_t getTHARelated_ScreenReq_t();
  void setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt);
  ErrorMgr_ErrorCommPack_QNX_QM getErrorMgr_ErrorCommPack_QNX_QM();
  void setErrorMgr_ErrorCommPack_QNX_QM_v(const ErrorMgr_ErrorCommPack_QNX_QM& i_ErrorMgr_ErrorCommPack_QNX_QM_rt);
  TRSC_Inputs_from_TrailerDetection_t getTRSC_Inputs_from_TrailerDetection_t();
  void setTRSC_Inputs_from_TrailerDetection_v(const TRSC_Inputs_from_TrailerDetection_t& i_TRSC_Inputs_from_TrailerDetection_t_rt);
  MeDLD_e_RrCamSts_t getMeDLD_e_RrCamSts_t();
  void setMeDLD_e_RrCamSts_v(const MeDLD_e_RrCamSts_t& i_MeDLD_e_RrCamSts_t_rt);

  TbSVS_e_SVSCalibSMToAlgoCamCalib_t getTbSVS_e_SVSCalibSMToAlgoCamCalib_t();
  void setTbSVS_e_SVSCalibSMToAlgoCamCalib_v(const TbSVS_e_SVSCalibSMToAlgoCamCalib_t& i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt);
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t getTbSVS_e_SVSCalibAlgoToSMCamCalib_t();
  void setTbSVS_e_SVSCalibAlgoToSMCamCalib_v(const TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt);
  TbSVS_S_SVSCamCurrentCalibDataToNVM_t getTbSVS_S_SVSCamCurrentCalibDataToNVM_t();
  void setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t& i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt);
  TbSVS_S_SVSCamOCCalibDataToNVM_t getTbSVS_S_SVSCamOCCalibDataToNVM_t();
  void setTbSVS_S_SVSCamOCCalibDataToNVM_v(const TbSVS_S_SVSCamOCCalibDataToNVM_t& i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt);
  TbSVS_S_SVSCamSCCalibDataToNVM_t getTbSVS_S_SVSCamSCCalibDataToNVM_t();
  void setTbSVS_S_SVSCamSCCalibDataToNVM_v(const TbSVS_S_SVSCamSCCalibDataToNVM_t& i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt);
  TbSVS_S_SVSCamEOLCalibDataToNVM_t getTbSVS_S_SVSCamEOLCalibDataToNVM_t();
  void setTbSVS_S_SVSCamEOLCalibDataToNVM_v(const TbSVS_S_SVSCamEOLCalibDataToNVM_t& i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt);

  void setJobTHADetOutput_v(const JobTHADetOutput_t& i_JobTHADetOutput_t_rt);
  JobTHADetOutput_t getJobTHADetOutput_t();
  CalDataProvider_MPU_1_0_Def getCalDataProvider_MPU_1_0_Def();
  void setCalDataProvider_MPU_1_0_Def_v(const CalDataProvider_MPU_1_0_Def& i_CalDataProvider_MPU_1_0_Def_rt);

  SSM_SystemState getSSM_SystemState();
  void setSSM_SystemState_v(const SSM_SystemState& i_SSM_SystemState_rt);
  ErrorMgr_ErrorCommPack_QNX_B getErrorMgr_ErrorCommPack_QNX_B();
  void setErrorMgr_ErrorCommPack_QNX_B_v(const ErrorMgr_ErrorCommPack_QNX_B& i_ErrorMgr_ErrorCommPack_QNX_B_rt);
  SSM_QNX_CoreStatus getSSM_QNX_CoreStatus();
  void setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt);

  Svs_CamEepromDataArray_t  getSvs_CamEepromDataArray_t();
  void setSvs_CamEepromDataArray_v(const Svs_CamEepromDataArray_t& i_Svs_CamEepromDataArray_rt);


  LMD_Outputs_CVPAMFDData2_t getCVPAMFDData2_LMD_Outputs_CVPAMFDData();
  void setCVPAMFDData2_LMD_Outputs_CVPAMFDData_v(const LMD_Outputs_CVPAMFDData2_t& i_LMD_Outputs_CVPAMFDData2_t_rt);
  TrailerDetection_Output_DID_t getTrailerDet_Output_DID();
  void setTrailerDet_Output_DID_v(const TrailerDetection_Output_DID_t& i_TrailerDetection_Output_DID_t_rt);
  TbAP_DriveAssistStatOut_t getTbAP_DriveAssistStatOut();
  void setTbAP_DriveAssistStatOut_v(const TbAP_DriveAssistStatOut_t& i_TbAP_DriveAssistStatOut_t_rt);
  FID_STRUCT_B getfid_struct();
  void setfid_struct_v(const FID_STRUCT_B& i_FID_STRUCT_B_rt);
  LMD_Lane_Outputs_s getLMD_Lane_Outputs();
  void setLMD_Lane_Outputs_v(const LMD_Lane_Outputs_s& i_LMD_Lane_Outputs_s_rt);
  THA_Calibration_data_MPU1_0_t getTHA_Calibration_data_MPU1_0();
  void setTHA_Calibration_data_MPU1_0_v(const THA_Calibration_data_MPU1_0_t& i_THA_Calibration_data_MPU1_0_t_rt);
  APA_Calibration_data_MPU1_0_t getAPA_Calibration_data_MPU1_0();
  void setAPA_Calibration_data_MPU1_0_v(const APA_Calibration_data_MPU1_0_t& i_APA_Calibration_data_MPU1_0_t_rt);
  LMD_Calibration_data_t getLMD_Calibration_data();
  void setLMD_Calibration_data_v(const LMD_Calibration_data_t& i_LMD_Calibration_data_t_rt);
  TRSC_Calibration_data_MPU1_0_t getTRSC_Calibration_data_MPU1_0();
  void setTRSC_Calibration_data_MPU1_0_v(const TRSC_Calibration_data_MPU1_0_t& i_TRSC_Calibration_data_MPU1_0_t_rt);
  TbSVS_e_SVSCalibSMToHmi_t getTbSVS_e_SVSCalibSMToHmi();
  void setTbSVS_e_SVSCalibSMToHmi_v(const TbSVS_e_SVSCalibSMToHmi_t& i_TbSVS_e_SVSCalibSMToHmi_t_rt);
  ME_Proxi_MPU1_0_to_MCU1_0_t getME_Proxi_MPU1_0_to_MCU1_0();
  void setME_Proxi_MPU1_0_to_MCU1_0_v(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt);

  FID_STRUCT_QM getFID_STRUCT_QM();
  void setFID_STRUCT_QM_v(const FID_STRUCT_QM& i_FID_STRUCT_QM_rt);
  TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(bool_t *o_ReceiveStatus_pb );
  void setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t& i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt);
  TrailerDetection_Output_HMI_t getTrailerDetection_Output_HMI();
  void setTrailerDetection_Output_HMI_v(const TrailerDetection_Output_HMI_t& i_TrailerDetection_Output_HMI_t_rt);
  JobDLDOutput_t getJobDLDOutput();
  void setJobDLDOutput_v(const JobDLDOutput_t& i_JobDLDOutput_rt);
  Error_Fault_MPU1_0_t getError_Fault_MPU1_0();
  void setError_Fault_MPU1_0_v(const Error_Fault_MPU1_0_t& i_JobError_Fault_MPU1_0_rt);

  TRSC_CalibrationClear_t getTRSC_CalibrationClear_t();
  void setTRSC_CalibrationClear_v(const TRSC_CalibrationClear_t& i_TRSC_CalibrationClear_t_rt);
  RunTimeStats_MPU1_0_t getRunTimeStats_MPU1_0_t();
  void setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt);
  PerformanceStatsEnable_t getPerformanceStatsEnable_t();
  void setPerformanceStatsEnable_v(const PerformanceStatsEnable_t& i_PerformanceStatsEnable_t_rt);
  CamHotplugStatus_t getCamHotplugStatus_t();
  void setCamHotplugStatus_v(const CamHotplugStatus_t& i_CamHotplugStatus_t_rt);
  uint8_t getVariantID(void);
  void setVariantID(const uint8_t var_id);

  uint32_t getRenderFrameID(void);
  void setRenderFrameID(const uint32_t i_render_frameNum);

  void setRadioDisp(const uint8_t radio_id);
  uint8_t getRadioDisp(void);

  uint8_t getETFS_mount_status(void);
  void setETFS_mount_status(const uint8_t etfs_status);


  TRSCDebug_ScrReq_t getTRSCDebug_ScrReq();
  void setTRSCDebug_ScrReq_v(const TRSCDebug_ScrReq_t& i_TRSCDebug_ScrReq_t_rt);
  ME_CanDebugRIDStatus_t getCanDebugRIDStatus();
  void setCanDebugRIDStatus_v(const ME_CanDebugRIDStatus_t& i_ME_CanDebugRIDStatus_t_rt);

  uint32_t getSigMRuntime(void);
  void setSigMRuntime(uint32_t u_SigMRuntime_val);
  uint32_t getThSigMRuntime(void);
  void setThSigMRuntime(uint32_t u_SigMRuntime_val);
  uint32_t getKeepAliveRuntime(void);
  void setKeepAliveRuntime(uint32_t u_SigMRuntime_val);
  uint32_t getMsgSndrRuntime(void);
  void setMsgSndrRuntime(uint32_t u_Runtime_val);
  uint32_t getLogMRuntime(void);
  void setLogMRuntime(uint32_t u_Runtime_val);  
private:
  osal::Mutex mutex_o;
  
  ScreenRequest_t screenRequest_t;
  TRA_Data_Request_t Tra_Data_Request_t;
  TRA_Data_Response_t Tra_Data_Response_t;
  MiscRequest_t miscRequest_t;
  MCU_TRAGateway1Request_t MCU_TraGateway1Request_t;
  MCU_TRAGateway2Request_t MCU_TraGateway2Request_t;
  MCU_TRAGateway3Request_t MCU_TraGateway3Request_t;
  MCU_TRAGateway4Request_t MCU_TraGateway4Request_t;
  VehicleStateRequest_t vehicleState_t;
  ApplyConfigRequest_t applyConfig_t;
  
  bool_t                        isEOLcompleted_b;
  bool_t                        isEOLtriggered_b;

  uint8_t m_VariantID;
  uint8_t m_RadioDisp;
  uint8_t m_etfs_mount_status;
  uint32_t m_render_frameNum;
  uint32_t m_SigM_rt_data;
  uint32_t m_ThSigM_rt_data;
  uint32_t m_KeepAlive_rt_data;
  uint32_t m_MsgSndr_rt_data;
  uint32_t m_LogM_rt_data;

  RequestEOLCmd_t               requestEOLCmd_t;
  ResponseEOLCmd_t              responseEOLCmd_t[4];
  RequestSCCmd_t                requestSCCmd_t;
  ResponseSCCmd_t               responseSCCmd_t;
  RequestOCCmd_t                requestOCCmd_t;
  ResponseOCCmd_t               responseOCCmd_t;

  RequestTEOLCmd_t              requestTEOLCmd_t;
  ResponseTEOLCmd_t             responseTEOLCmd_t;
  variants::Camera_t            calibrationCamera_t;
  variants::CalibrationTypeE_t  calibrationType_t;
  
#ifdef ME_PLATFORM_QNX
  sensor::SerializerCXD4963ER     ecuSerializerCXD4963ER_o;
#endif

  ErrorDataCamera_t errorDataCamera_at[variants::e_CameraCount];
  variants::HmiSoftButtonStatus_t hmiSoftButtons_at[variants::e_HmiSoftButtonCount];
  MessageStatus_t   MessageStatus_Array[e_Message_count];
  MessageStatus_t   MessageStatus_ArrayTx[e_MessageTx_count];

  ScreenResponse_t         screenResponse_t;
  TbSVS_e_SVSOutputToDiagMgrCamCalib_t tbSVS_e_SVSOutputToDiagMgrCamCalib_t;
  TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t tbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;

  TbSVS_e_SVSCalibSMToAlgoCamCalib_t tbSVS_e_SVSCalibSMToAlgoCamCalib_t;
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t tbSVS_e_SVSCalibAlgoToSMCamCalib_t;
  TbSVS_S_SVSCamEOLCalibDataToNVM_t tbSVS_S_SVSCamEOLCalibDataToNVM_t;
  TbSVS_S_SVSCamOCCalibDataToNVM_t tbSVS_S_SVSCamOCCalibDataToNVM_t;
  TbSVS_S_SVSCamSCCalibDataToNVM_t tbSVS_S_SVSCamSCCalibDataToNVM_t;
  TbSVS_S_SVSCamCurrentCalibDataToNVM_t tbSVS_S_SVSCamCurrentCalibDataToNVM_t;

  IKinematicData_t m_IKinematicData_t;
  IJobPLDOutput_t m_IJobPLDOutput_t;
  IParkingSlotInformation_t m_IParkingSlotInformation_t;
  IFPAInfoToPLD_t m_IFPAInfoToPLD_t;
  MOT_Output m_MOT_Output_t;


  ME_VehInp_to_IpcSignals_t  m_ME_VehInp_to_IpcSignals_t;
  ME_ProxiToMPU1_0_Def_t  m_ME_Proxi_to_IpcSignals_t;
  SvsToTHADet_t  m_SvsToTHADet_t;
  SSM_2_0_CoreStatus  m_SSM_2_0_CoreStatus;
  SSM_2_1_CoreStatus  m_SSM_2_1_CoreStatus;
  TbTHASmVc_FeatureOutputs_t  m_TbTHASmVc_FeatureOutputs_t;
  Detection_Inputs_from_TRSC_t  m_Detection_Inputs_from_TRSC_t;
  US_S_BlockageBit_t  m_US_S_BlockageBit_t;
  US_S_USSErrorDiagData_t  m_US_S_USSErrorDiagData_t;
  THARelated_ScreenReq_t  m_THARelated_ScreenReq_t;
  ErrorMgr_ErrorCommPack_QNX_QM  m_ErrorMgr_ErrorCommPack_QNX_QM;
  TRSC_Inputs_from_TrailerDetection_t  m_TRSC_Inputs_from_TrailerDetection_t;
  MeDLD_e_RrCamSts_t  m_MeDLD_e_RrCamSts_t;
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t  m_TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t  m_TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
  TbSVS_S_SVSCamCurrentCalibDataToNVM_t  m_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
  TbSVS_S_SVSCamOCCalibDataToNVM_t  m_TbSVS_S_SVSCamOCCalibDataToNVM_t;
  TbSVS_S_SVSCamSCCalibDataToNVM_t  m_TbSVS_S_SVSCamSCCalibDataToNVM_t;
  TbSVS_S_SVSCamEOLCalibDataToNVM_t  m_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
  JobTHADetOutput_t  m_JobTHADetOutput_t;
  SSM_QNX_CoreStatus  m_SSM_QNX_CoreStatus;
  CalDataProvider_MPU_1_0_Def m_CalDataProvider_MPU_1_0_Def;
  SSM_SystemState m_SSM_SystemState;
  ErrorMgr_ErrorCommPack_QNX_B m_ErrorMgr_ErrorCommPack_QNX_B;
  Svs_CamEepromDataArray_t m_Svs_CamEepromDataArray_t;
  LMD_Outputs_CVPAMFDData2_t m_LMD_Outputs_CVPAMFDData2_t;
  FOD_Outputs_CVPAMFDData_t m_FOD_Outputs_CVPAMFDData_t;
  TrailerDetection_Output_DID_t m_TrailerDetection_Output_DID_t;
  TbAP_DriveAssistStatOut_t m_TbAP_DriveAssistStatOut_t;
  FID_STRUCT_B m_FID_STRUCT_B;
  LMD_Lane_Outputs_s m_LMD_Lane_Outputs_s;  
  THA_Calibration_data_MPU1_0_t m_THA_Calibration_data_MPU1_0_t;
  APA_Calibration_data_MPU1_0_t m_APA_Calibration_data_MPU1_0_t;
  LMD_Calibration_data_t m_LMD_Calibration_data_t;
  TRSC_Calibration_data_MPU1_0_t m_TRSC_Calibration_data_MPU1_0_t;
  TbSVS_e_SVSCalibSMToHmi_t m_TbSVS_e_SVSCalibSMToHmi_t;
  ME_Proxi_MPU1_0_to_MCU1_0_t m_ME_Proxi_MPU1_0_to_MCU1_0_t;
  FID_STRUCT_QM m_FID_STRUCT_QM;
  TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t tbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
  TrailerDetection_Output_HMI_t m_TrailerDetection_Output_HMI_t;
  JobDLDOutput_t m_JobDLDOutput_t;
  Error_Fault_MPU1_0_t m_Error_Fault_MPU1_0_t;
  TRSC_CalibrationClear_t m_TRSC_CalibrationClear_t;
  ME_CanDebugRIDStatus_t m_ME_CanDebugRIDStatus_t;
  TRSCDebug_ScrReq_t m_TRSCDebug_ScrReq_t;
  RunTimeStats_MPU1_0_t m_RunTimeStats_MPU1_0_t;
  PerformanceStatsEnable_t m_PerformanceStatsEnable_t;
  CamHotplugStatus_t m_CamHotplugStatus_t;
};

} // namespace container

#endif // CONTAINER_SIGM_DATA_H
