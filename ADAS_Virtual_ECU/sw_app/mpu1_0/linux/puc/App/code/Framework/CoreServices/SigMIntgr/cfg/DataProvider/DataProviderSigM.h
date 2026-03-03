//--------------------------------------------------------------------------
/// @file DataProviderSigM.h
/// @brief Contains
///
/// DataProvider is an interface between EOL module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef DATAPROVIDERSIGM_H_
#define DATAPROVIDERSIGM_H_

#include "sigm/IDataProviderSigM.h"
#include <cfg/IDataProvider.h>

namespace sigm
{

  class DataProviderSigM : public IDataProviderSigM
  {
  public:

    explicit DataProviderSigM(container::IDataProvider& b_DataProvider_ro);
    virtual ~DataProviderSigM();

    //----------------------------------------------------------------------------------------
    // // Data Input (only getter)
    //---------------------------------------------------------------------------------------

    virtual uint32_t                            getFrameID_u32() const ME_OVERRIDE;
    virtual uint8_t                             getBootState_u8() const ME_OVERRIDE;
    virtual uint8_t                             getCameraShutdownState_u8() const ME_OVERRIDE;
#ifdef USE_REQUEST_AND_RESPONSE
    virtual ScreenRequest_t                     getScreenRequest_t() const ME_OVERRIDE;
#else
    virtual ScreenRequest_t                     getScreenRequest_t(bool_t* o_ReceiveStatus_pb ) const ME_OVERRIDE;
#endif	
    virtual TRA_Data_Request_t                  getTRAData_t() const ME_OVERRIDE;
    virtual TRA_Data_Response_t                 getTRAresponse_t() const ME_OVERRIDE;
    virtual uint8_t                             getTRAconfidence() const ME_OVERRIDE;
    virtual uint16_t                            getTRAframeNumber() const ME_OVERRIDE;
    virtual uint8_t                             getTRAState() const ME_OVERRIDE;

    virtual MCU_TRAGateway1Request_t            getMCUTRAGateway1_t()const ME_OVERRIDE;
    virtual MCU_TRAGateway2Request_t            getMCUTRAGateway2_t() const ME_OVERRIDE;
    virtual MCU_TRAGateway3Request_t            getMCUTRAGateway3_t() const ME_OVERRIDE;
    virtual MCU_TRAGateway4Request_t            getMCUTRAGateway4_t()const ME_OVERRIDE;
    virtual MiscRequest_t                       getMiscRequest_t() const ME_OVERRIDE;
 
    virtual VehicleStateRequest_t               getVehicleState_s() const ME_OVERRIDE;
    virtual const float32_t                     getSoCTemperature_f32() const ME_OVERRIDE;
    virtual ApplyConfigRequest_t                getApplyConfig_t() const ME_OVERRIDE;
    virtual sensor::CameraBase&                 getCamera_ro(variants::Camera_t i_CameraId_t) ME_OVERRIDE;
    virtual bool_t 								getCamDataInitStatus() ME_OVERRIDE;
    virtual MCU_TRAGateway4Response_t           getMCU_TRAGateway4Response_t() const ME_OVERRIDE;

    virtual TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t           getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t* o_receive_status_b_p ) const ME_OVERRIDE;

    virtual MessageStatus_t                     getMessageStatus_t(uint8_t i_index_u8) const ME_OVERRIDE;
	virtual ScreenResponse_t                    getScreenResponse_t() const ME_OVERRIDE;
	virtual TbSVS_e_SVSOutputToDiagMgrCamCalib_t            getTbSVS_e_SVSOutputToDiagMgrCamCalib_t() const ME_OVERRIDE;
    //----------------------------------------------------------------------------------------
    // Data Output (only setter)
    //----------------------------------------------------------------------------------------

    virtual void                                setScreenRequest_v(const ScreenRequest_t& i_Screen_s) ME_OVERRIDE;
    virtual void                                setTRARequest_v(const TRA_Data_Request_t& i_TRA_s) ME_OVERRIDE;
    
    virtual void                                setMCUTRAGateway1Request_v(const MCU_TRAGateway1Request_t& i_MCUTRAGateway1_rt) ME_OVERRIDE;
    virtual void                                setMCUTRAGateway2Request_v(const MCU_TRAGateway2Request_t& i_MCUTRAGateway2_rt) ME_OVERRIDE;
    virtual void                                setMCUTRAGateway3Request_v(const MCU_TRAGateway3Request_t& i_MCUTRAGateway3_rt) ME_OVERRIDE;
    virtual void                                setMCUTRAGateway4Request_v(const MCU_TRAGateway4Request_t& i_MCUTRAGateway4_rt)ME_OVERRIDE;
    virtual void                                setMiscRequest_v(const MiscRequest_t& i_MiscRequest_rt) ME_OVERRIDE;
    virtual void                                setVehicleState_s(const VehicleStateRequest_t& i_VehicleState_s) ME_OVERRIDE;
    virtual void                                setApplyConfig_v(const ApplyConfigRequest_t& i_ApplyConfig_t) ME_OVERRIDE;


    virtual void                                setEOLRequest_v(const container::RequestEOLCmd_t& i_RequestEOLCmd_t);
    virtual const container::RequestEOLCmd_t&   getEOLRequest_rt(void) const;

    virtual void                                setEolAlgoFinishedCmd_v(bool_t flag_b);
    virtual bool_t                              getEolAlgoFinishedCmd_b();
    virtual void                                setEOLResponse_v(const container::ResponseEOLCmd_t* i_ResponseEOLCmd_t);
    virtual const container::ResponseEOLCmd_t*  getEOLResponse_rt(void) const;
    virtual const bool_t                        isEolAlgoTriggered_b(void) const;
#if 0
    virtual void                                setHMIWrtDataScreen(uint8_t progFactor);
#endif
    virtual void                                setOCRequest_v(const container::RequestOCCmd_t& i_RequestOCCmd_t);
    virtual const container::RequestOCCmd_t&    getOCRequest_rt(void) const;
    virtual void                                setOCResponse_v(const container::ResponseOCCmd_t& i_ResponseOCCmd_t);
    virtual const container::ResponseOCCmd_t&   getOCResponse_rt(void) const;

    virtual void                                setSCRequest_v(const container::RequestSCCmd_t& i_RequestSCCmd_t);
    virtual const container::RequestSCCmd_t&    getSCRequest_rt(void) const;
    virtual void                                setSCResponse_v(const container::ResponseSCCmd_t& i_ResponseSCCmd_t);
    //virtual const container::ResponseSCCmd_t&   getSCResponse_rt(void) const;

    virtual void                                setTEOLRequest_v(const container::RequestTEOLCmd_t& i_RequestTEOLCmd_t);
    virtual const container::RequestTEOLCmd_t&  getTEOLRequest_rt(void) const;
    virtual void                                setTEOLResponse_v(const container::ResponseTEOLCmd_t& i_ResponseTEOLCmd_t);
    virtual const container::ResponseTEOLCmd_t& getTEOLResponse_rt(void) const;

    virtual variants::Camera_t                  getCalibrationCamera_t(void) const;
    virtual void                                setCalibrationCamera_v(const variants::Camera_t);
    virtual variants::CalibrationTypeE_t        getCalibrationType_t(void) const;
    virtual void                                setCalibrationType_v(const variants::CalibrationTypeE_t);

    virtual void                                setCameraCalibrationData_v(variants::Camera_t i_CameraId_t, const sensor::CalibrationData_t& i_CamCalibrationData_rt) ME_OVERRIDE;
    virtual void                                setCameraTestPattern_v(variants::Camera_t i_CameraId_t, variants::CamTestPattern_t i_PatternId_t) ME_OVERRIDE;

    virtual void                                setCameraDeviceRegister_v(variants::Camera_t i_CameraId_t, variants::CameraDevice_t, uint16_t i_RegisterAddress_u16, uint16_t i_RegisterValue_u16) ME_OVERRIDE;
    virtual uint16_t                            getCameraDeviceRegister_v(variants::Camera_t i_CameraId_t, variants::CameraDevice_t i_CameraDevice_t, uint16_t i_RegisterAddress_u16) ME_OVERRIDE;

    virtual sensor::CameraErrorData_t           getCameraErrorData_t(variants::Camera_t i_Cam_t) ME_OVERRIDE;

    virtual bool_t                              setCameraPowerMode_b(variants::Camera_t i_CameraID_t, variants::CameraPowerMode_t i_CameraPowerMode_t) ME_OVERRIDE;

    virtual void                                setCameraSerializerPowerMode_v(variants::CameraPowerMode_t i_CameraPowerMode_t) ME_OVERRIDE;

    virtual void                              	setCameraShutdownState_u8(uint8_t i_CameraPowerMode_t) ME_OVERRIDE;

    virtual bsp::FpgaVersion_s                  getPlVersion_s() ME_OVERRIDE;

    virtual void                                setHmiSoftButtonStatus_v(variants::HmiSoftButton_t i_SoftButton_e,variants::HmiSoftButtonStatus_t i_Status_e) ME_OVERRIDE;

    virtual void                                setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt) ME_OVERRIDE;

    virtual void                                setSvs_CamEepromDataArray_v(const Svs_CamEepromDataArray_t& i_Svs_CamEepromDataArray_rt) ME_OVERRIDE;
	 virtual  IKinematicData_t getIKinematicData_t()                               ME_OVERRIDE;
	 virtual  void setIKinematicData_v(const IKinematicData_t&)                    ME_OVERRIDE;
	 virtual  IJobPLDOutput_t getIJobPLDOutput_t()                                 ME_OVERRIDE;
	 virtual  void setIJobPLDOutput_v(const IJobPLDOutput_t&)                      ME_OVERRIDE;
	 virtual  IParkingSlotInformation_t getIParkingSlotInformation_t()             ME_OVERRIDE;
	 virtual  void setIParkingSlotInformation_v(const IParkingSlotInformation_t&)  ME_OVERRIDE;
	 virtual  IFPAInfoToPLD_t getIFPAInfoToPLD_t()                                 ME_OVERRIDE;
	 virtual  void setIFPAInfoToPLD_v(const IFPAInfoToPLD_t&)                       ME_OVERRIDE;
	 virtual MOT_Output getMOT_Output_t()  ME_OVERRIDE;
	 virtual void setMOT_Output_v(const MOT_Output& ) ME_OVERRIDE;

	  virtual TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t *o_receive_status_b_p )                                        ME_OVERRIDE;
	  virtual void setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t& i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt)                ME_OVERRIDE;
	  virtual TbSVS_e_SVSOutputToDiagMgrCamCalib_t getTbSVS_e_SVSOutputToDiagMgrCamCalib_t()                                                                         ME_OVERRIDE;
	  virtual void setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t& i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt)                      ME_OVERRIDE;


	  virtual ME_VehInp_to_IpcSignals_t getME_VehInp_to_IpcSignals_t() ME_OVERRIDE;
	  virtual void setME_VehInp_to_IpcSignals_v(const ME_VehInp_to_IpcSignals_t& ) ME_OVERRIDE;
	  virtual ME_ProxiToMPU1_0_Def_t getME_Proxi_to_IpcSignals_t() ME_OVERRIDE;
	  virtual void setME_Proxi_to_IpcSignals_v(const ME_ProxiToMPU1_0_Def_t& i_ME_Proxi_to_IpcSignals_t_rt) ME_OVERRIDE;
	  virtual SvsToTHADet_t getSvsToTHADet_t() ME_OVERRIDE;
	  virtual void setSvsToTHADet_v(const SvsToTHADet_t& i_SvsToTHADet_t_rt) ME_OVERRIDE;
	  virtual SSM_2_0_CoreStatus getSSM_2_0_CoreStatus() ME_OVERRIDE;
	  virtual void setSSM_2_0_CoreStatus_v(const SSM_2_0_CoreStatus& i_SSM_2_0_CoreStatus_rt) ME_OVERRIDE;
	  virtual SSM_2_1_CoreStatus getSSM_2_1_CoreStatus() ME_OVERRIDE;
	  virtual void setSSM_2_1_CoreStatus_v(const SSM_2_1_CoreStatus& i_SSM_2_1_CoreStatus_rt) ME_OVERRIDE;
	  virtual TbTHASmVc_FeatureOutputs_t getTbTHASmVc_FeatureOutputs_t() ME_OVERRIDE;
	  virtual void setTbTHASmVc_FeatureOutputs_v(const TbTHASmVc_FeatureOutputs_t& i_TbTHASmVc_FeatureOutputs_t_rt) ME_OVERRIDE;
	  virtual Detection_Inputs_from_TRSC_t getDetection_Inputs_from_TRSC_t() ME_OVERRIDE;
	  virtual void setDetection_Inputs_from_TRSC_v(const Detection_Inputs_from_TRSC_t& i_Detection_Inputs_from_TRSC_t_rt) ME_OVERRIDE;
	  virtual US_S_BlockageBit_t getUS_S_BlockageBit_t() ME_OVERRIDE;
	  virtual void setUS_S_BlockageBit_v(const US_S_BlockageBit_t& i_US_S_BlockageBit_t_rt) ME_OVERRIDE;
	  virtual US_S_USSErrorDiagData_t getUS_S_USSErrorDiagData_t() ME_OVERRIDE;
	  virtual void setUS_S_USSErrorDiagData_v(const US_S_USSErrorDiagData_t& i_US_S_USSErrorDiagData_t_rt) ME_OVERRIDE;
	  virtual THARelated_ScreenReq_t getTHARelated_ScreenReq_t() ME_OVERRIDE;
	  virtual void setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt) ME_OVERRIDE;
	  virtual ErrorMgr_ErrorCommPack_QNX_QM getErrorMgr_ErrorCommPack_QNX_QM() ME_OVERRIDE;
	  virtual void setErrorMgr_ErrorCommPack_QNX_QM_v(const ErrorMgr_ErrorCommPack_QNX_QM& i_ErrorMgr_ErrorCommPack_QNX_QM_rt) ME_OVERRIDE;
	  virtual TRSC_Inputs_from_TrailerDetection_t getTRSC_Inputs_from_TrailerDetection_t() ME_OVERRIDE;
	  virtual void setTRSC_Inputs_from_TrailerDetection_v(const TRSC_Inputs_from_TrailerDetection_t& i_TRSC_Inputs_from_TrailerDetection_t_rt) ME_OVERRIDE;
	  virtual MeDLD_e_RrCamSts_t getMeDLD_e_RrCamSts_t() ME_OVERRIDE;
	  virtual void setMeDLD_e_RrCamSts_v(const MeDLD_e_RrCamSts_t& i_MeDLD_e_RrCamSts_t_rt) ME_OVERRIDE;


	  virtual TbSVS_e_SVSCalibSMToAlgoCamCalib_t getTbSVS_e_SVSCalibSMToAlgoCamCalib_t() ME_OVERRIDE;
	  virtual void setTbSVS_e_SVSCalibSMToAlgoCamCalib_v(const TbSVS_e_SVSCalibSMToAlgoCamCalib_t& i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt) ME_OVERRIDE;
	  virtual TbSVS_e_SVSCalibAlgoToSMCamCalib_t getTbSVS_e_SVSCalibAlgoToSMCamCalib_t() ME_OVERRIDE;
	  virtual void setTbSVS_e_SVSCalibAlgoToSMCamCalib_v(const TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt) ME_OVERRIDE;
	  virtual TbSVS_S_SVSCamCurrentCalibDataToNVM_t getTbSVS_S_SVSCamCurrentCalibDataToNVM_t() ME_OVERRIDE;
	  virtual void setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t& i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt) ME_OVERRIDE;
	  virtual TbSVS_S_SVSCamOCCalibDataToNVM_t getTbSVS_S_SVSCamOCCalibDataToNVM_t() ME_OVERRIDE;
	  virtual void setTbSVS_S_SVSCamOCCalibDataToNVM_v(const TbSVS_S_SVSCamOCCalibDataToNVM_t& i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt) ME_OVERRIDE;
	  virtual TbSVS_S_SVSCamSCCalibDataToNVM_t getTbSVS_S_SVSCamSCCalibDataToNVM_t() ME_OVERRIDE;
	  virtual void setTbSVS_S_SVSCamSCCalibDataToNVM_v(const TbSVS_S_SVSCamSCCalibDataToNVM_t& i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt) ME_OVERRIDE;
	  virtual TbSVS_S_SVSCamEOLCalibDataToNVM_t getTbSVS_S_SVSCamEOLCalibDataToNVM_t() ME_OVERRIDE;
	  virtual void setTbSVS_S_SVSCamEOLCalibDataToNVM_v(const TbSVS_S_SVSCamEOLCalibDataToNVM_t& i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt) ME_OVERRIDE;

	  virtual void setJobTHADetOutput_v(const JobTHADetOutput_t& i_JobTHADetOutput_t_rt) ME_OVERRIDE;
	  virtual JobTHADetOutput_t getJobTHADetOutput_t() ME_OVERRIDE;

	  virtual CalDataProvider_MPU_1_0_Def getCalDataProvider_MPU_1_0_Def() ME_OVERRIDE;
	  virtual void setCalDataProvider_MPU_1_0_Def_v(const CalDataProvider_MPU_1_0_Def& i_CalDataProvider_MPU_1_0_Def_rt) ME_OVERRIDE;

	  virtual SSM_SystemState getSSM_SystemState()ME_OVERRIDE;
	  virtual void setSSM_SystemState_v(const SSM_SystemState& i_SSM_SystemState_rt)ME_OVERRIDE;
	  virtual ErrorMgr_ErrorCommPack_QNX_B getErrorMgr_ErrorCommPack_QNX_B() ME_OVERRIDE;
	  virtual void setErrorMgr_ErrorCommPack_QNX_B_v(const ErrorMgr_ErrorCommPack_QNX_B& i_ErrorMgr_ErrorCommPack_QNX_B_rt) ME_OVERRIDE;
	  virtual SSM_QNX_CoreStatus getSSM_QNX_CoreStatus()ME_OVERRIDE;
	  virtual void setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt)ME_OVERRIDE;

	  virtual Svs_CamEepromDataArray_t getSvs_CamEepromDataArray_t() const ME_OVERRIDE;
	  //virtual void setSvs_CamEepromDataArray_t(const Svs_CamEepromDataArray_t& i_Svs_CamEepromDataArray_t_rt) ME_OVERRIDE;

	  virtual LMD_Outputs_CVPAMFDData2_t getCVPAMFDData2_LMD_Outputs_CVPAMFDData() ME_OVERRIDE;
	  virtual void setCVPAMFDData2_LMD_Outputs_CVPAMFDData_v(const LMD_Outputs_CVPAMFDData2_t& i_LMD_Outputs_CVPAMFDData2_t_rt) ME_OVERRIDE;
	  virtual uint8_t getVariantID(void) ME_OVERRIDE;
	  virtual void setVariantID(const uint8_t var_id) ME_OVERRIDE;

          virtual uint32_t getRenderFrameID(void) ME_OVERRIDE;
          virtual void setRenderFrameID(const uint32_t i_render_frameNum) ME_OVERRIDE;

	  virtual void setRadioDisp(const uint8_t radio_id) ME_OVERRIDE;
	  virtual uint8_t getRadioDisp(void) ME_OVERRIDE;

	  virtual uint8_t getETFS_mount_status(void) ME_OVERRIDE;
	  virtual void setETFS_mount_status(const uint8_t etfs_status) ME_OVERRIDE;

	  virtual TrailerDetection_Output_DID_t getTrailerDet_Output_DID() ME_OVERRIDE;
	  virtual void setTrailerDet_Output_DID_v(const TrailerDetection_Output_DID_t& i_TrailerDetection_Output_DID_t_rt) ME_OVERRIDE;
      virtual TbAP_DriveAssistStatOut_t getTbAP_DriveAssistStatOut() ME_OVERRIDE;
	  virtual void setTbAP_DriveAssistStatOut_v(const TbAP_DriveAssistStatOut_t& i_TbAP_DriveAssistStatOut_t_rt) ME_OVERRIDE;
      virtual FID_STRUCT_B getfid_struct() ME_OVERRIDE;
	  virtual void setfid_struct_v(const FID_STRUCT_B& i_FID_STRUCT_B_rt) ME_OVERRIDE;
      virtual LMD_Lane_Outputs_s getLMD_Lane_Outputs() ME_OVERRIDE;
	  virtual void setLMD_Lane_Outputs_v(const LMD_Lane_Outputs_s& i_LMD_Lane_Outputs_s_rt) ME_OVERRIDE;
      virtual THA_Calibration_data_MPU1_0_t getTHA_Calibration_data_MPU1_0() ME_OVERRIDE;
      virtual void setTHA_Calibration_data_MPU1_0_v(const THA_Calibration_data_MPU1_0_t& i_THA_Calibration_data_MPU1_0_t_rt) ME_OVERRIDE;
      virtual APA_Calibration_data_MPU1_0_t getAPA_Calibration_data_MPU1_0() ME_OVERRIDE;
      virtual void setAPA_Calibration_data_MPU1_0_v(const APA_Calibration_data_MPU1_0_t& i_APA_Calibration_data_MPU1_0_t_rt) ME_OVERRIDE;
      virtual LMD_Calibration_data_t getLMD_Calibration_data() ME_OVERRIDE;
      virtual void setLMD_Calibration_data_v(const LMD_Calibration_data_t& i_LMD_Calibration_data_t_rt) ME_OVERRIDE;
      virtual TRSC_Calibration_data_MPU1_0_t getTRSC_Calibration_data_MPU1_0() ME_OVERRIDE;
      virtual void setTRSC_Calibration_data_MPU1_0_v(const TRSC_Calibration_data_MPU1_0_t& i_TRSC_Calibration_data_MPU1_0_t_rt) ME_OVERRIDE;
      virtual TbSVS_e_SVSCalibSMToHmi_t getTbSVS_e_SVSCalibSMToHmi() ME_OVERRIDE;
      virtual void setTbSVS_e_SVSCalibSMToHmi_v(const TbSVS_e_SVSCalibSMToHmi_t& i_TbSVS_e_SVSCalibSMToHmi_t_rt) ME_OVERRIDE;
      virtual ME_Proxi_MPU1_0_to_MCU1_0_t getME_Proxi_MPU1_0_to_MCU1_0() ME_OVERRIDE;
      virtual void setME_Proxi_MPU1_0_to_MCU1_0_v(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt) ME_OVERRIDE;

      virtual FID_STRUCT_QM getFID_STRUCT_QM() ME_OVERRIDE;
      virtual void setFID_STRUCT_QM_v(const FID_STRUCT_QM& i_FID_STRUCT_QM_rt) ME_OVERRIDE;
      virtual TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(bool_t *o_ReceiveStatus_pb ) ME_OVERRIDE;
      virtual void setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t& i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt) ME_OVERRIDE;
      virtual TrailerDetection_Output_HMI_t getTrailerDetection_Output_HMI() ME_OVERRIDE;
      virtual void setTrailerDetection_Output_HMI_v(const TrailerDetection_Output_HMI_t& i_TrailerDetection_Output_HMI_t_rt) ME_OVERRIDE;
      virtual JobDLDOutput_t getJobDLDOutput() ME_OVERRIDE;
      virtual void setJobDLDOutput_v(const JobDLDOutput_t& i_JobDLDOutput_rt) ME_OVERRIDE;
      virtual Error_Fault_MPU1_0_t getError_Fault_MPU1_0() ME_OVERRIDE;
      virtual void setError_Fault_MPU1_0_v(const Error_Fault_MPU1_0_t& i_Error_Fault_MPU1_0_rt) ME_OVERRIDE;

      virtual TRSC_CalibrationClear_t getTRSC_CalibrationClear_t() ME_OVERRIDE;
      virtual void setTRSC_CalibrationClear_v(const TRSC_CalibrationClear_t& i_TRSC_CalibrationClear_t_rt) ME_OVERRIDE;
	  virtual RunTimeStats_MPU1_0_t getRunTimeStats_MPU1_0_t() ME_OVERRIDE;
      virtual void setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt) ME_OVERRIDE;
	  virtual PerformanceStatsEnable_t getPerformanceStatsEnable_t() ME_OVERRIDE;
      virtual void setPerformanceStatsEnable_v(const PerformanceStatsEnable_t& i_PerformanceStatsEnable_t_rt) ME_OVERRIDE;
      virtual CamHotplugStatus_t getCamHotplugStatus_t() ME_OVERRIDE;
      virtual void setCamHotplugStatus_v(const CamHotplugStatus_t& i_CamHotplugStatus_t_rt) ME_OVERRIDE;
      virtual TRSCDebug_ScrReq_t getTRSCDebug_ScrReq() ME_OVERRIDE;
      virtual void setTRSCDebug_ScrReq_v(const TRSCDebug_ScrReq_t& i_TRSCDebug_ScrReq_t_rt) ME_OVERRIDE;
      virtual ME_CanDebugRIDStatus_t getCanDebugRIDStatus() ME_OVERRIDE;
      virtual void setCanDebugRIDStatus_v(const ME_CanDebugRIDStatus_t& i_ME_CanDebugRIDStatus_t_rt) ME_OVERRIDE;
      virtual void setSigMRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
      virtual void setThSigMRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
      virtual void setKeepAliveRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
      virtual void setMsgSndrRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
      virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;


  private:
    uint8_t                                 CamDeserSerState_u8;
    container::IDataProvider&               dataProvider_ro;

    // dummys
    container::RequestEOLCmd_t              requestEOLCmd_t;
    container::ResponseEOLCmd_t             responseEOLCmd_t;
    container::RequestOCCmd_t               requestOCCmd_t;
    container::ResponseOCCmd_t              responseOCCmd_t;
    container::RequestSCCmd_t               requestSCCmd_t;
    container::ResponseSCCmd_t              responseSCCmd_t;
    container::RequestTEOLCmd_t             requestTEOLCmd_t;
    container::ResponseTEOLCmd_t            responseTEOLCmd_t;
  };

} // namespace sigm

#endif // DATAPROVIDERSIGM_H_

