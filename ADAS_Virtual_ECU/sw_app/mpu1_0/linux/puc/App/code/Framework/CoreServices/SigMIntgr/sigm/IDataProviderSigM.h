//--------------------------------------------------------------------------
/// @file IDataProviderSigM.h
/// @brief Contains
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Marcel Engelhardt (Marcel.Engelhardt@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef IDATAPROVIDERSIGM_H_
#define IDATAPROVIDERSIGM_H_

#include <platform/PlatformSpecs.h>

#include <cfg/shmdata/SigMData.h>

#include <sensor/CameraBase.h>
#include <bsp/io/fpga/FpgaZCU102.h>

namespace sigm
{


  class IDataProviderSigM
  {
  public:
    explicit IDataProviderSigM()
    {}

    virtual ~IDataProviderSigM()
    {}

    //----------------------------------------------------------------------------------------
    // // Data Input (only getter)
    //---------------------------------------------------------------------------------------

    /// Misc
    virtual uint32_t                            getFrameID_u32() const = 0;
    virtual uint8_t                             getBootState_u8() const = 0;
#ifdef USE_REQUEST_AND_RESPONSE	
    virtual ScreenRequest_t                     getScreenRequest_t() const = 0;
#else
    virtual ScreenRequest_t                     getScreenRequest_t(bool_t* o_receive_status_b_p ) const = 0;
#endif	
    virtual MiscRequest_t                       getMiscRequest_t() const = 0;
    virtual ApplyConfigRequest_t                getApplyConfig_t() const = 0;
    virtual VehicleStateRequest_t               getVehicleState_s() const = 0;
    virtual const float32_t                     getSoCTemperature_f32() const = 0;
    virtual bsp::FpgaVersion_s                  getPlVersion_s() = 0;
    virtual sensor::CameraBase&                 getCamera_ro(variants::Camera_t i_CameraId_t) = 0;
    virtual bool_t 								getCamDataInitStatus() = 0;

    /// TRA
    virtual TRA_Data_Request_t                  getTRAData_t() const = 0;
    virtual TRA_Data_Response_t                 getTRAresponse_t() const = 0;
    virtual uint8_t                             getTRAconfidence() const = 0;
    virtual uint16_t                            getTRAframeNumber() const = 0;
    virtual uint8_t                             getTRAState() const = 0;
    virtual MCU_TRAGateway1Request_t            getMCUTRAGateway1_t() const = 0;
    virtual MCU_TRAGateway2Request_t            getMCUTRAGateway2_t() const = 0;
    virtual MCU_TRAGateway3Request_t            getMCUTRAGateway3_t() const = 0;
    virtual MCU_TRAGateway4Request_t            getMCUTRAGateway4_t() const = 0;
    virtual MCU_TRAGateway4Response_t           getMCU_TRAGateway4Response_t() const = 0;

    virtual const container::RequestEOLCmd_t&   getEOLRequest_rt(void) const  = 0;
    virtual  bool_t                             getEolAlgoFinishedCmd_b() = 0;
    virtual const container::ResponseEOLCmd_t*  getEOLResponse_rt(void) const = 0;

    virtual const bool_t                        isEolAlgoTriggered_b(void) const = 0;

    /// OC
    virtual const container::ResponseOCCmd_t&   getOCResponse_rt(void) const = 0;
    virtual const container::RequestOCCmd_t&    getOCRequest_rt(void) const  = 0;

	virtual ScreenResponse_t                    getScreenResponse_t() const = 0;

	virtual TbSVS_e_SVSOutputToDiagMgrCamCalib_t            getTbSVS_e_SVSOutputToDiagMgrCamCalib_t() const = 0;

	virtual TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t           getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t* o_receive_status_b_p ) const = 0;



    virtual MessageStatus_t                     getMessageStatus_t(uint8_t i_index_u8) const = 0;

    /// SC
    virtual const container::RequestSCCmd_t&    getSCRequest_rt(void) const  = 0;

    /// TEOL
    virtual const container::RequestTEOLCmd_t&  getTEOLRequest_rt(void) const  = 0;
    virtual const container::ResponseTEOLCmd_t& getTEOLResponse_rt(void) const = 0;

    /// Calibration
    virtual variants::Camera_t                  getCalibrationCamera_t(void) const = 0;
    virtual variants::CalibrationTypeE_t        getCalibrationType_t(void) const = 0;

    /// Camera
    virtual uint16_t                            getCameraDeviceRegister_v(variants::Camera_t i_CameraId_t, variants::CameraDevice_t i_CameraDevice_t, uint16_t i_RegisterAddress_u16) = 0;
    virtual sensor::CameraErrorData_t           getCameraErrorData_t(variants::Camera_t i_Cam_t)  = 0;
    virtual uint8_t                             getCameraShutdownState_u8() const = 0;

    //----------------------------------------------------------------------------------------
    // Data Output (only setter)
    //----------------------------------------------------------------------------------------

    /// Misc
    virtual void                                setMiscRequest_v(const MiscRequest_t& i_MiscRequest_rt) = 0;
    virtual void                                setVehicleState_s(const VehicleStateRequest_t& i_VehicleState_s) = 0;
    virtual void                                setApplyConfig_v(const ApplyConfigRequest_t& i_ApplyConfig_t) = 0;


    /// EOL
    virtual void                                setEOLRequest_v(const container::RequestEOLCmd_t& i_RequestEOLCmd_t) = 0;
    virtual void                                setEolAlgoFinishedCmd_v(bool_t flag_b)   = 0;
    virtual void                                setEOLResponse_v(const container::ResponseEOLCmd_t* i_ResponseEOLCmd_t) = 0;
#if 0
    virtual void                                setHMIWrtDataScreen(uint8_t progFactor) = 0;
#endif
    /// OC
    virtual void                                setOCRequest_v(const container::RequestOCCmd_t& i_RequestOCCmd_t) = 0;
    virtual void                                setOCResponse_v(const container::ResponseOCCmd_t& i_ResponseOCCmd_t) = 0;

    /// SC
    virtual void                                setSCRequest_v(const container::RequestSCCmd_t& i_RequestSCCmd_t) = 0;
    virtual void                                setSCResponse_v(const container::ResponseSCCmd_t& i_ResponseSCCmd_t) = 0;

    /// TEOL
    virtual void                                setTEOLRequest_v(const container::RequestTEOLCmd_t& i_RequestTEOLCmd_t) = 0;
    virtual void                                setTEOLResponse_v(const container::ResponseTEOLCmd_t& i_ResponseTEOLCmd_t) = 0;

    /// Calibration
    virtual void                                setCalibrationCamera_v(const variants::Camera_t) = 0;
    virtual void                                setCalibrationType_v(const variants::CalibrationTypeE_t) = 0;

    ///TRA
    virtual void                                setTRARequest_v(const TRA_Data_Request_s& i_TRA_rt) = 0;
    virtual void                                setMCUTRAGateway1Request_v(const MCU_TRAGateway1Request_t& i_MCUTRAGateway1_rt) = 0;
    virtual void                                setMCUTRAGateway2Request_v(const MCU_TRAGateway2Request_t& i_MCUTRAGateway2_rt) = 0;
    virtual void                                setMCUTRAGateway3Request_v(const MCU_TRAGateway3Request_t& i_MCUTRAGateway3_rt) = 0;
    virtual void                                setMCUTRAGateway4Request_v(const MCU_TRAGateway4Request_t& i_MCUTRAGateway4_rt) = 0;

    virtual void                                setCameraCalibrationData_v(variants::Camera_t i_CameraId_t, const sensor::CalibrationData_t& i_CamCalibrationData_rt) = 0;
    virtual void                                setCameraTestPattern_v(variants::Camera_t i_CameraId_t, variants::CamTestPattern_t i_PatternId_t) = 0;
    virtual void                                setCameraDeviceRegister_v(variants::Camera_t i_CameraId_t, variants::CameraDevice_t, uint16_t i_RegisterAddress_u16, uint16_t i_RegisterValue_u16) = 0;
    virtual bool_t                              setCameraPowerMode_b(variants::Camera_t i_CameraID_t, variants::CameraPowerMode_t i_CameraPowerMode_t) = 0;
    virtual void                                setCameraSerializerPowerMode_v(variants::CameraPowerMode_t i_CameraPowerMode_t) = 0;
    virtual void                                setCameraShutdownState_u8(uint8_t i_CameraPowerMode_t) = 0;

    virtual void                                setHmiSoftButtonStatus_v(variants::HmiSoftButton_t i_SoftButton_e,variants::HmiSoftButtonStatus_t i_Status_e) = 0;

    virtual void                                setScreenRequest_v(const ScreenRequest_t& i_Screen_rt) = 0;

	virtual void                              setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt) = 0;

    virtual void                              setSvs_CamEepromDataArray_v(const Svs_CamEepromDataArray_t& i_Svs_CamEepromDataArray_rt) = 0;

	 virtual TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(bool_t *o_receive_status_b_p )                                       =0;
	 virtual void setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t& i_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_rt)               =0;
	 virtual TbSVS_e_SVSOutputToDiagMgrCamCalib_t getTbSVS_e_SVSOutputToDiagMgrCamCalib_t()                                                                        =0;
	 virtual void setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t& i_TbSVS_e_SVSOutputToDiagMgrCamCalib_rt)                     =0;

	 virtual  IKinematicData_t getIKinematicData_t()                               = 0;
	 virtual  void setIKinematicData_v(const IKinematicData_t&)                    = 0;
	 virtual  IJobPLDOutput_t getIJobPLDOutput_t()                                 = 0;
	 virtual  void setIJobPLDOutput_v(const IJobPLDOutput_t&)                      = 0;
	 virtual  IParkingSlotInformation_t getIParkingSlotInformation_t()             = 0;
	 virtual  void setIParkingSlotInformation_v(const IParkingSlotInformation_t&)  = 0;
	 virtual  IFPAInfoToPLD_t getIFPAInfoToPLD_t()                                 = 0;
	 virtual  void setIFPAInfoToPLD_v(const IFPAInfoToPLD_t&)                       = 0;
	 virtual MOT_Output getMOT_Output_t()  =0;
	 virtual void setMOT_Output_v(const MOT_Output& ) =0;

	 virtual ME_VehInp_to_IpcSignals_t getME_VehInp_to_IpcSignals_t() = 0;
	 virtual void setME_VehInp_to_IpcSignals_v(const ME_VehInp_to_IpcSignals_t& ) = 0;
	 virtual ME_ProxiToMPU1_0_Def_t getME_Proxi_to_IpcSignals_t() = 0;
	 virtual void setME_Proxi_to_IpcSignals_v(const ME_ProxiToMPU1_0_Def_t& i_ME_Proxi_to_IpcSignals_t_rt) = 0;
	 virtual SvsToTHADet_t getSvsToTHADet_t() = 0;
	 virtual void setSvsToTHADet_v(const SvsToTHADet_t& i_SvsToTHADet_t_rt) = 0;
	 virtual SSM_2_0_CoreStatus getSSM_2_0_CoreStatus() = 0;
	 virtual void setSSM_2_0_CoreStatus_v(const SSM_2_0_CoreStatus& i_SSM_2_0_CoreStatus_rt) = 0;
	 virtual SSM_2_1_CoreStatus getSSM_2_1_CoreStatus() = 0;
	 virtual void setSSM_2_1_CoreStatus_v(const SSM_2_1_CoreStatus& i_SSM_2_1_CoreStatus_rt) = 0;
	 virtual TbTHASmVc_FeatureOutputs_t getTbTHASmVc_FeatureOutputs_t() = 0;
	 virtual void setTbTHASmVc_FeatureOutputs_v(const TbTHASmVc_FeatureOutputs_t& i_TbTHASmVc_FeatureOutputs_t_rt) = 0;
	 virtual Detection_Inputs_from_TRSC_t getDetection_Inputs_from_TRSC_t() = 0;
	 virtual void setDetection_Inputs_from_TRSC_v(const Detection_Inputs_from_TRSC_t& i_Detection_Inputs_from_TRSC_t_rt) = 0;
	 virtual US_S_BlockageBit_t getUS_S_BlockageBit_t() = 0;
	 virtual void setUS_S_BlockageBit_v(const US_S_BlockageBit_t& i_US_S_BlockageBit_t_rt) = 0;
	 virtual US_S_USSErrorDiagData_t getUS_S_USSErrorDiagData_t() = 0;
	 virtual void setUS_S_USSErrorDiagData_v(const US_S_USSErrorDiagData_t& i_US_S_USSErrorDiagData_t_rt) = 0;
	 virtual THARelated_ScreenReq_t getTHARelated_ScreenReq_t() = 0;
	 virtual void setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt) = 0;
	 virtual ErrorMgr_ErrorCommPack_QNX_QM getErrorMgr_ErrorCommPack_QNX_QM() = 0;
	 virtual void setErrorMgr_ErrorCommPack_QNX_QM_v(const ErrorMgr_ErrorCommPack_QNX_QM& i_ErrorMgr_ErrorCommPack_QNX_QM_rt) = 0;
	 virtual TRSC_Inputs_from_TrailerDetection_t getTRSC_Inputs_from_TrailerDetection_t() = 0;
	 virtual void setTRSC_Inputs_from_TrailerDetection_v(const TRSC_Inputs_from_TrailerDetection_t& i_TRSC_Inputs_from_TrailerDetection_t_rt) = 0;
	 virtual MeDLD_e_RrCamSts_t getMeDLD_e_RrCamSts_t() = 0;
	 virtual void setMeDLD_e_RrCamSts_v(const MeDLD_e_RrCamSts_t& i_MeDLD_e_RrCamSts_t_rt) = 0;

	 virtual TbSVS_e_SVSCalibSMToAlgoCamCalib_t getTbSVS_e_SVSCalibSMToAlgoCamCalib_t() = 0;
	 virtual void setTbSVS_e_SVSCalibSMToAlgoCamCalib_v(const TbSVS_e_SVSCalibSMToAlgoCamCalib_t& i_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_rt) = 0;
	 virtual TbSVS_e_SVSCalibAlgoToSMCamCalib_t getTbSVS_e_SVSCalibAlgoToSMCamCalib_t() = 0;
	 virtual void setTbSVS_e_SVSCalibAlgoToSMCamCalib_v(const TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_rt) = 0;
	 virtual TbSVS_S_SVSCamCurrentCalibDataToNVM_t getTbSVS_S_SVSCamCurrentCalibDataToNVM_t() = 0;
	 virtual void setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t& i_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_rt) = 0;
	 virtual TbSVS_S_SVSCamOCCalibDataToNVM_t getTbSVS_S_SVSCamOCCalibDataToNVM_t() = 0;
	 virtual void setTbSVS_S_SVSCamOCCalibDataToNVM_v(const TbSVS_S_SVSCamOCCalibDataToNVM_t& i_TbSVS_S_SVSCamOCCalibDataToNVM_t_rt) = 0;
	 virtual TbSVS_S_SVSCamSCCalibDataToNVM_t getTbSVS_S_SVSCamSCCalibDataToNVM_t() = 0;
	 virtual void setTbSVS_S_SVSCamSCCalibDataToNVM_v(const TbSVS_S_SVSCamSCCalibDataToNVM_t& i_TbSVS_S_SVSCamSCCalibDataToNVM_t_rt) = 0;
	 virtual TbSVS_S_SVSCamEOLCalibDataToNVM_t getTbSVS_S_SVSCamEOLCalibDataToNVM_t() = 0;
	 virtual void setTbSVS_S_SVSCamEOLCalibDataToNVM_v(const TbSVS_S_SVSCamEOLCalibDataToNVM_t& i_TbSVS_S_SVSCamEOLCalibDataToNVM_t_rt) = 0;

	  virtual void setJobTHADetOutput_v(const JobTHADetOutput_t& i_JobTHADetOutput_t_rt) =0;
	  virtual JobTHADetOutput_t getJobTHADetOutput_t() =0;

	  virtual CalDataProvider_MPU_1_0_Def getCalDataProvider_MPU_1_0_Def() =0;
	  virtual void setCalDataProvider_MPU_1_0_Def_v(const CalDataProvider_MPU_1_0_Def& i_CalDataProvider_MPU_1_0_Def_rt) =0;

	  virtual SSM_SystemState getSSM_SystemState()=0;
	  virtual void setSSM_SystemState_v(const SSM_SystemState& i_SSM_SystemState_rt)=0;

	  virtual ErrorMgr_ErrorCommPack_QNX_B getErrorMgr_ErrorCommPack_QNX_B() =0;
	  virtual void setErrorMgr_ErrorCommPack_QNX_B_v(const ErrorMgr_ErrorCommPack_QNX_B& i_ErrorMgr_ErrorCommPack_QNX_B_rt) =0;
	  virtual SSM_QNX_CoreStatus getSSM_QNX_CoreStatus() =0;
	  virtual void setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt) =0;

	  virtual Svs_CamEepromDataArray_t getSvs_CamEepromDataArray_t() const = 0;

	  virtual LMD_Outputs_CVPAMFDData2_t getCVPAMFDData2_LMD_Outputs_CVPAMFDData() =0;
	  virtual void setCVPAMFDData2_LMD_Outputs_CVPAMFDData_v(const LMD_Outputs_CVPAMFDData2_t& i_LMD_Outputs_CVPAMFDData2_t_rt) =0;

	  virtual TrailerDetection_Output_DID_t getTrailerDet_Output_DID() =0;
	  virtual void setTrailerDet_Output_DID_v(const TrailerDetection_Output_DID_t& i_TrailerDetection_Output_DID_t_rt) =0;
	  virtual TbAP_DriveAssistStatOut_t getTbAP_DriveAssistStatOut() =0;
	  virtual void setTbAP_DriveAssistStatOut_v(const TbAP_DriveAssistStatOut_t& i_TbAP_DriveAssistStatOut_t_rt) =0;
      virtual FID_STRUCT_B getfid_struct() =0;
	  virtual void setfid_struct_v(const FID_STRUCT_B& i_FID_STRUCT_B_rt) =0;
      virtual LMD_Lane_Outputs_s getLMD_Lane_Outputs() =0;
	  virtual void setLMD_Lane_Outputs_v(const LMD_Lane_Outputs_s& i_LMD_Lane_Outputs_s_rt) =0;
      virtual THA_Calibration_data_MPU1_0_t getTHA_Calibration_data_MPU1_0() =0;
      virtual void setTHA_Calibration_data_MPU1_0_v(const THA_Calibration_data_MPU1_0_t& i_THA_Calibration_data_MPU1_0_t_rt) =0;
      virtual APA_Calibration_data_MPU1_0_t getAPA_Calibration_data_MPU1_0() =0;
      virtual void setAPA_Calibration_data_MPU1_0_v(const APA_Calibration_data_MPU1_0_t& i_APA_Calibration_data_MPU1_0_t_rt) =0;
      virtual LMD_Calibration_data_t getLMD_Calibration_data() =0;
      virtual void setLMD_Calibration_data_v(const LMD_Calibration_data_t& i_LMD_Calibration_data_t_rt) =0;
      virtual TRSC_Calibration_data_MPU1_0_t getTRSC_Calibration_data_MPU1_0() =0;
      virtual void setTRSC_Calibration_data_MPU1_0_v(const TRSC_Calibration_data_MPU1_0_t& i_TRSC_Calibration_data_MPU1_0_t_rt) =0;
      virtual TbSVS_e_SVSCalibSMToHmi_t getTbSVS_e_SVSCalibSMToHmi() =0;
      virtual void setTbSVS_e_SVSCalibSMToHmi_v(const TbSVS_e_SVSCalibSMToHmi_t& i_TbSVS_e_SVSCalibSMToHmi_t_rt) =0;
      virtual ME_Proxi_MPU1_0_to_MCU1_0_t getME_Proxi_MPU1_0_to_MCU1_0() =0;
      virtual void setME_Proxi_MPU1_0_to_MCU1_0_v(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t_rt) =0;
	  virtual uint8_t getVariantID(void) =0;
	  virtual void setVariantID(const uint8_t var_id) =0;

      virtual uint32_t getRenderFrameID(void) =0;
      virtual void setRenderFrameID(const uint32_t i_render_frameNum) =0;

	  virtual void setRadioDisp(const uint8_t radio_id) =0;
	  virtual uint8_t getRadioDisp(void) =0;

	  virtual uint8_t getETFS_mount_status(void) = 0;
	  virtual void setETFS_mount_status(const uint8_t etfs_status) =0;

      virtual FID_STRUCT_QM getFID_STRUCT_QM()  = 0;
      virtual void setFID_STRUCT_QM_v(const FID_STRUCT_QM& i_FID_STRUCT_QM_rt)  = 0;
      virtual TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(bool_t *o_ReceiveStatus_pb )  = 0;
      virtual void setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t& i_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_rt)  = 0;
      virtual TrailerDetection_Output_HMI_t getTrailerDetection_Output_HMI()  = 0;
      virtual void setTrailerDetection_Output_HMI_v(const TrailerDetection_Output_HMI_t& i_TrailerDetection_Output_HMI_t_rt)  = 0;
      virtual JobDLDOutput_t getJobDLDOutput()  = 0;
      virtual void setJobDLDOutput_v(const JobDLDOutput_t& i_JobDLDOutput_rt)  = 0;
      virtual Error_Fault_MPU1_0_t getError_Fault_MPU1_0()  = 0;
      virtual void setError_Fault_MPU1_0_v(const Error_Fault_MPU1_0_t& i_Error_Fault_MPU1_0_rt)  = 0;
      virtual RunTimeStats_MPU1_0_t getRunTimeStats_MPU1_0_t()  = 0;
      virtual void setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt)  = 0;

      virtual TRSC_CalibrationClear_t getTRSC_CalibrationClear_t() =0;
      virtual void setTRSC_CalibrationClear_v(const TRSC_CalibrationClear_t& i_TRSC_CalibrationClear_t_rt) =0;
	  virtual PerformanceStatsEnable_t getPerformanceStatsEnable_t() =0;
      virtual void setPerformanceStatsEnable_v(const PerformanceStatsEnable_t& i_PerformanceStatsEnable_t_rt) =0;
      virtual CamHotplugStatus_t getCamHotplugStatus_t() =0;
      virtual void setCamHotplugStatus_v(const CamHotplugStatus_t& i_CamHotplugStatus_t_rt) =0;
      virtual TRSCDebug_ScrReq_t getTRSCDebug_ScrReq() =0;
      virtual void setTRSCDebug_ScrReq_v(const TRSCDebug_ScrReq_t& i_TRSCDebug_ScrReq_t_rt) =0;
      virtual ME_CanDebugRIDStatus_t getCanDebugRIDStatus() =0;
      virtual void setCanDebugRIDStatus_v(const ME_CanDebugRIDStatus_t& i_ME_CanDebugRIDStatus_t_rt) =0;
      virtual void setSigMRuntime(uint32_t u_Runtime_u32) = 0;
      virtual void setThSigMRuntime(uint32_t u_Runtime_u32) = 0;
      virtual void setKeepAliveRuntime(uint32_t u_Runtime_u32) = 0;
      virtual void setMsgSndrRuntime(uint32_t u_Runtime_u32) = 0;
      virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
  };

} // namespace sigm

#endif // IDATAPROVIDERSIGM_H_

