#include "SignalMgr.cfg"
#include "SignalDef.h"
#include "SigMgr_IpcBridge.h"
#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
#include "ipc_manager.h"
#endif




#ifdef BUILD_MPU1_0

static void SigMgr_IpcBridge_PpScreenResponse_ScreenResponse_t_callback(const ScreenResponse_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpScreenResponse_ScreenResponse_t,(uint16_t)sizeof(ScreenResponse_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_callback(const ErrorMgr_ErrorCommPack_QNX_QM* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM,(uint16_t)sizeof(ErrorMgr_ErrorCommPack_QNX_QM),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_callback(const ErrorMgr_ErrorCommPack_QNX_B* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B,(uint16_t)sizeof(ErrorMgr_ErrorCommPack_QNX_B),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_callback(const TRSC_Inputs_from_TrailerDetection_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t,(uint16_t)sizeof(TRSC_Inputs_from_TrailerDetection_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_data_MeDLD_e_RrCamSts_t_callback(const MeDLD_e_RrCamSts_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_data_MeDLD_e_RrCamSts_t,(uint16_t)sizeof(MeDLD_e_RrCamSts_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSR_State_QNX_State_QNX_callback(const SSM_QNX_CoreStatus* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSR_State_QNX_State_QNX,(uint16_t)sizeof(SSM_QNX_CoreStatus),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_callback(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t,(uint16_t)sizeof(TbSVS_S_SVSCamCurrentCalibDataToNVM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_callback(const TbSVS_S_SVSCamOCCalibDataToNVM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t,(uint16_t)sizeof(TbSVS_S_SVSCamOCCalibDataToNVM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_callback(const TbSVS_S_SVSCamSCCalibDataToNVM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t,(uint16_t)sizeof(TbSVS_S_SVSCamSCCalibDataToNVM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_callback(const TbSVS_S_SVSCamEOLCalibDataToNVM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t,(uint16_t)sizeof(TbSVS_S_SVSCamEOLCalibDataToNVM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_callback(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t,(uint16_t)sizeof(TbSVS_e_SVSOutputToDiagMgrCamCalib_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpJobTHADetOutput_JobTHADetOutput_t_callback(const JobTHADetOutput_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t,(uint16_t)sizeof(JobTHADetOutput_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpJobPLDData_IJobPLDOutput_t_callback(const IJobPLDOutput_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t,(uint16_t)sizeof(IJobPLDOutput_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_IParkingSlotInformation_t_callback(const IParkingSlotInformation_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_IParkingSlotInformation_t,(uint16_t)sizeof(IParkingSlotInformation_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_MOT_Output_callback(const MOT_Output* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_MOT_Output,(uint16_t)sizeof(MOT_Output),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCamEepromData_Svs_CamEepromDataArray_t_callback(const Svs_CamEepromDataArray_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t,(uint16_t)sizeof(Svs_CamEepromDataArray_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_callback(const LMD_Outputs_CVPAMFDData2_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t,(uint16_t)sizeof(LMD_Outputs_CVPAMFDData2_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTrailerDetectOP_TrailerDetection_Output_DID_t_callback(const TrailerDetection_Output_DID_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t,(uint16_t)sizeof(TrailerDetection_Output_DID_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TrscDebug_ScrRes_t_callback(const TrscDebug_ScrRes_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TrscDebug_ScrRes_t,(uint16_t)sizeof(TrscDebug_ScrRes_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_callback(const WdgCheckpointStatus_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t,(uint16_t)sizeof(WdgCheckpointStatus_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpLMDLaneOp_LMD_Lane_Outputs_s_callback(const LMD_Lane_Outputs_s* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s,(uint16_t)sizeof(LMD_Lane_Outputs_s),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_callback(const ME_Proxi_MPU1_0_to_MCU1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t,(uint16_t)sizeof(ME_Proxi_MPU1_0_to_MCU1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TbSVS_e_SVSCalibSMToHmi_t_callback(const TbSVS_e_SVSCalibSMToHmi_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToHmi_t,(uint16_t)sizeof(TbSVS_e_SVSCalibSMToHmi_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TrailerDetection_Output_HMI_t_callback(const TrailerDetection_Output_HMI_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TrailerDetection_Output_HMI_t,(uint16_t)sizeof(TrailerDetection_Output_HMI_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpDLDOutput_JobDLDOutput_t_callback(const JobDLDOutput_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpDLDOutput_JobDLDOutput_t,(uint16_t)sizeof(JobDLDOutput_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpKeepAliveResponse_KeepAliveResponse_t_callback(const KeepAliveResponse_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t,(uint16_t)sizeof(KeepAliveResponse_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_callback(const Error_Fault_MPU1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpErrFltMpu1_0_Error_Fault_MPU1_0_t,(uint16_t)sizeof(Error_Fault_MPU1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_callback(const RunTimeStats_MPU1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t,(uint16_t)sizeof(RunTimeStats_MPU1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_IpcBridge_Init(void)
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_PpScreenResponse_ScreenResponse_t_RegisterCallback(SigMgr_IpcBridge_PpScreenResponse_ScreenResponse_t_callback);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_RegisterCallback(SigMgr_IpcBridge_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_callback);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_RegisterCallback(SigMgr_IpcBridge_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_callback);
	bRet &= SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_RegisterCallback(SigMgr_IpcBridge_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_callback);
	bRet &= SigMgr_data_MeDLD_e_RrCamSts_t_RegisterCallback(SigMgr_IpcBridge_data_MeDLD_e_RrCamSts_t_callback);
	bRet &= SigMgr_PpSR_State_QNX_State_QNX_RegisterCallback(SigMgr_IpcBridge_PpSR_State_QNX_State_QNX_callback);
	bRet &= SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_RegisterCallback(SigMgr_IpcBridge_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_callback);
	bRet &= SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_RegisterCallback(SigMgr_IpcBridge_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_callback);
	bRet &= SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_RegisterCallback(SigMgr_IpcBridge_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_callback);
	bRet &= SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_RegisterCallback(SigMgr_IpcBridge_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_callback);
	bRet &= SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_RegisterCallback(SigMgr_IpcBridge_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_callback);
	bRet &= SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_RegisterCallback(SigMgr_IpcBridge_PpJobTHADetOutput_JobTHADetOutput_t_callback);
	bRet &= SigMgr_PpJobPLDData_IJobPLDOutput_t_RegisterCallback(SigMgr_IpcBridge_PpJobPLDData_IJobPLDOutput_t_callback);
	bRet &= SigMgr_Data_IParkingSlotInformation_t_RegisterCallback(SigMgr_IpcBridge_Data_IParkingSlotInformation_t_callback);
	bRet &= SigMgr_Data_MOT_Output_RegisterCallback(SigMgr_IpcBridge_Data_MOT_Output_callback);
	bRet &= SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_RegisterCallback(SigMgr_IpcBridge_PpCamEepromData_Svs_CamEepromDataArray_t_callback);
	bRet &= SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_RegisterCallback(SigMgr_IpcBridge_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_callback);
	bRet &= SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_RegisterCallback(SigMgr_IpcBridge_PpTrailerDetectOP_TrailerDetection_Output_DID_t_callback);
	bRet &= SigMgr_Data_TrscDebug_ScrRes_t_RegisterCallback(SigMgr_IpcBridge_Data_TrscDebug_ScrRes_t_callback);
	bRet &= SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_RegisterCallback(SigMgr_IpcBridge_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_callback);
	bRet &= SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_RegisterCallback(SigMgr_IpcBridge_PpLMDLaneOp_LMD_Lane_Outputs_s_callback);
	bRet &= SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_RegisterCallback(SigMgr_IpcBridge_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_callback);
	bRet &= SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_RegisterCallback(SigMgr_IpcBridge_Data_TbSVS_e_SVSCalibSMToHmi_t_callback);
	bRet &= SigMgr_Data_TrailerDetection_Output_HMI_t_RegisterCallback(SigMgr_IpcBridge_Data_TrailerDetection_Output_HMI_t_callback);
	bRet &= SigMgr_PpDLDOutput_JobDLDOutput_t_RegisterCallback(SigMgr_IpcBridge_PpDLDOutput_JobDLDOutput_t_callback);
	bRet &= SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_RegisterCallback(SigMgr_IpcBridge_PpKeepAliveResponse_KeepAliveResponse_t_callback);
	bRet &= SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_RegisterCallback(SigMgr_IpcBridge_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_callback);
	bRet &= SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_RegisterCallback(SigMgr_IpcBridge_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_callback);

	return bRet;
}

#ifdef __cplusplus
}
#endif


#endif /*MPU1_0*/



#ifdef BUILD_MCU1_0

static void SigMgr_IpcBridge_ME_VehInp_to_IpcSignals_data_f_callback(const ME_VehInp_to_IpcSignals_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f,(uint16_t)sizeof(ME_VehInp_to_IpcSignals_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_SSM_SystemState_callback(const SSM_SystemState* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_SSM_SystemState,(uint16_t)sizeof(SSM_SystemState),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_CalDataProvider_MPU_1_0_Def_callback(const CalDataProvider_MPU_1_0_Def* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def,(uint16_t)sizeof(CalDataProvider_MPU_1_0_Def),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_CalDataProvider_MCU_2_0_Def_callback(const CalDataProvider_MCU_2_0_Def* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_CalDataProvider_MCU_2_0_Def,(uint16_t)sizeof(CalDataProvider_MCU_2_0_Def),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_CalDataProvider_MCU_2_1_Def_callback(const CalDataProvider_MCU_2_1_Def* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_CalDataProvider_MCU_2_1_Def,(uint16_t)sizeof(CalDataProvider_MCU_2_1_Def),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_callback(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t,(uint16_t)sizeof(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_callback(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t,(uint16_t)sizeof(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_ME_Proxi_to_IpcSignals_t_callback(const ME_Proxi_to_IpcSignals_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_ME_Proxi_to_IpcSignals_t,(uint16_t)sizeof(ME_Proxi_to_IpcSignals_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_IKinematicData_t_callback(const IKinematicData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_IKinematicData_t,(uint16_t)sizeof(IKinematicData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_ExtY_Kinematic_T_callback(const ExtY_Kinematic_T* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_ExtY_Kinematic_T,(uint16_t)sizeof(ExtY_Kinematic_T),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_FID_STRUCT_QM_callback(const FID_STRUCT_QM* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_FID_STRUCT_QM,(uint16_t)sizeof(FID_STRUCT_QM),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_FID_STRUCT_B_callback(const FID_STRUCT_B* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_FID_STRUCT_B,(uint16_t)sizeof(FID_STRUCT_B),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_USS_Curr_Volt_Monitor_t_callback(const USS_Curr_Volt_Monitor_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_USS_Curr_Volt_Monitor_t,(uint16_t)sizeof(USS_Curr_Volt_Monitor_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_DiagToSVS_t_callback(const DiagToSVS_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_DiagToSVS_t,(uint16_t)sizeof(DiagToSVS_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_CAM_Curr_Volt_Monitor_t_callback(const CAM_Curr_Volt_Monitor_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_CAM_Curr_Volt_Monitor_t,(uint16_t)sizeof(CAM_Curr_Volt_Monitor_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_US_S_MarriageSensorIDs_t_callback(const US_S_MarriageSensorIDs_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_US_S_MarriageSensorIDs_t,(uint16_t)sizeof(US_S_MarriageSensorIDs_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_DiagToParkAssist_t_callback(const DiagToParkAssist_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_DiagToParkAssist_t,(uint16_t)sizeof(DiagToParkAssist_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_ME_ProxiToMPU1_0_Def_t_callback(const ME_ProxiToMPU1_0_Def_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t,(uint16_t)sizeof(ME_ProxiToMPU1_0_Def_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_ME_ProxiToMCU2_0_Def_t_callback(const ME_ProxiToMCU2_0_Def_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_ME_ProxiToMCU2_0_Def_t,(uint16_t)sizeof(ME_ProxiToMCU2_0_Def_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_ME_ProxiToMCU2_1_Def_t_callback(const ME_ProxiToMCU2_1_Def_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_ME_ProxiToMCU2_1_Def_t,(uint16_t)sizeof(ME_ProxiToMCU2_1_Def_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TbNVM_ReadParam_callback(const TbNVM_ReadParam* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TbNVM_ReadParam,(uint16_t)sizeof(TbNVM_ReadParam),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_ME_CanDebugRIDStatus_t_callback(const ME_CanDebugRIDStatus_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_ME_CanDebugRIDStatus_t,(uint16_t)sizeof(ME_CanDebugRIDStatus_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_SVS_NVMData_t_callback(const SVS_NVMData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_SVS_NVMData_t,(uint16_t)sizeof(SVS_NVMData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_USS_Calibration_Data_t_callback(const USS_Calibration_Data_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_USS_Calibration_Data_t,(uint16_t)sizeof(USS_Calibration_Data_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_THA_Calibration_data_MCU2_1_t_callback(const THA_Calibration_data_MCU2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_THA_Calibration_data_MCU2_1_t,(uint16_t)sizeof(THA_Calibration_data_MCU2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_THA_Calibration_data_MPU1_0_t_callback(const THA_Calibration_data_MPU1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t,(uint16_t)sizeof(THA_Calibration_data_MPU1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TRSC_Calibration_data_MCU2_1_t_callback(const TRSC_Calibration_data_MCU2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TRSC_Calibration_data_MCU2_1_t,(uint16_t)sizeof(TRSC_Calibration_data_MCU2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_APA_Calibration_data_MPU1_0_t_callback(const APA_Calibration_data_MPU1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t,(uint16_t)sizeof(APA_Calibration_data_MPU1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_APA_Calibration_data_MCU2_1_t_callback(const APA_Calibration_data_MCU2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_APA_Calibration_data_MCU2_1_t,(uint16_t)sizeof(APA_Calibration_data_MCU2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_SVS_Calibration_data_t_callback(const SVS_Calibration_data_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_SVS_Calibration_data_t,(uint16_t)sizeof(SVS_Calibration_data_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_FOD_Calibration_data_t_callback(const FOD_Calibration_data_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_FOD_Calibration_data_t,(uint16_t)sizeof(FOD_Calibration_data_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_LMD_Calibration_data_t_callback(const LMD_Calibration_data_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_LMD_Calibration_data_t,(uint16_t)sizeof(LMD_Calibration_data_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TRSC_Calibration_data_MPU1_0_t_callback(const TRSC_Calibration_data_MPU1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t,(uint16_t)sizeof(TRSC_Calibration_data_MPU1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_USS_Calibration_data_2_t_callback(const USS_Calibration_data_2_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_USS_Calibration_data_2_t,(uint16_t)sizeof(USS_Calibration_data_2_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_INVMSignalManager_t_callback(const INVMSignalManager_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_INVMSignalManager_t,(uint16_t)sizeof(INVMSignalManager_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TimeManagerProxy_TimeStamp_t_callback(const TimeManagerProxy_TimeStamp_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TimeManagerProxy_TimeStamp_t,(uint16_t)sizeof(TimeManagerProxy_TimeStamp_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TRSC_CalibrationClear_t_callback(const TRSC_CalibrationClear_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TRSC_CalibrationClear_t,(uint16_t)sizeof(TRSC_CalibrationClear_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_UssTunningData_mcu1_0_t_callback(const UssTunningData_mcu1_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_UssTunningData_mcu1_0_t,(uint16_t)sizeof(UssTunningData_mcu1_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_PerformanceStatsEnable_t_callback(const PerformanceStatsEnable_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_PerformanceStatsEnable_t,(uint16_t)sizeof(PerformanceStatsEnable_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_IpcBridge_Init(void)
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(SigMgr_IpcBridge_ME_VehInp_to_IpcSignals_data_f_callback);
	bRet &= SigMgr_Data_SSM_SystemState_RegisterCallback(SigMgr_IpcBridge_Data_SSM_SystemState_callback);
	bRet &= SigMgr_Data_CalDataProvider_MPU_1_0_Def_RegisterCallback(SigMgr_IpcBridge_Data_CalDataProvider_MPU_1_0_Def_callback);
	bRet &= SigMgr_Data_CalDataProvider_MCU_2_0_Def_RegisterCallback(SigMgr_IpcBridge_Data_CalDataProvider_MCU_2_0_Def_callback);
	bRet &= SigMgr_Data_CalDataProvider_MCU_2_1_Def_RegisterCallback(SigMgr_IpcBridge_Data_CalDataProvider_MCU_2_1_Def_callback);
	bRet &= SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_RegisterCallback(SigMgr_IpcBridge_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_callback);
	bRet &= SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_RegisterCallback(SigMgr_IpcBridge_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_callback);
	bRet &= SigMgr_Data_ME_Proxi_to_IpcSignals_t_RegisterCallback(SigMgr_IpcBridge_Data_ME_Proxi_to_IpcSignals_t_callback);
	bRet &= SigMgr_Data_IKinematicData_t_RegisterCallback(SigMgr_IpcBridge_Data_IKinematicData_t_callback);
	bRet &= SigMgr_Data_ExtY_Kinematic_T_RegisterCallback(SigMgr_IpcBridge_Data_ExtY_Kinematic_T_callback);
	bRet &= SigMgr_Data_FID_STRUCT_QM_RegisterCallback(SigMgr_IpcBridge_Data_FID_STRUCT_QM_callback);
	bRet &= SigMgr_Data_FID_STRUCT_B_RegisterCallback(SigMgr_IpcBridge_Data_FID_STRUCT_B_callback);
	bRet &= SigMgr_Data_USS_Curr_Volt_Monitor_t_RegisterCallback(SigMgr_IpcBridge_Data_USS_Curr_Volt_Monitor_t_callback);
	bRet &= SigMgr_Data_DiagToSVS_t_RegisterCallback(SigMgr_IpcBridge_Data_DiagToSVS_t_callback);
	bRet &= SigMgr_Data_CAM_Curr_Volt_Monitor_t_RegisterCallback(SigMgr_IpcBridge_Data_CAM_Curr_Volt_Monitor_t_callback);
	bRet &= SigMgr_Data_US_S_MarriageSensorIDs_t_RegisterCallback(SigMgr_IpcBridge_Data_US_S_MarriageSensorIDs_t_callback);
	bRet &= SigMgr_Data_DiagToParkAssist_t_RegisterCallback(SigMgr_IpcBridge_Data_DiagToParkAssist_t_callback);
	bRet &= SigMgr_Data_ME_ProxiToMPU1_0_Def_t_RegisterCallback(SigMgr_IpcBridge_Data_ME_ProxiToMPU1_0_Def_t_callback);
	bRet &= SigMgr_Data_ME_ProxiToMCU2_0_Def_t_RegisterCallback(SigMgr_IpcBridge_Data_ME_ProxiToMCU2_0_Def_t_callback);
	bRet &= SigMgr_Data_ME_ProxiToMCU2_1_Def_t_RegisterCallback(SigMgr_IpcBridge_Data_ME_ProxiToMCU2_1_Def_t_callback);
	bRet &= SigMgr_Data_TbNVM_ReadParam_RegisterCallback(SigMgr_IpcBridge_Data_TbNVM_ReadParam_callback);
	bRet &= SigMgr_Data_ME_CanDebugRIDStatus_t_RegisterCallback(SigMgr_IpcBridge_Data_ME_CanDebugRIDStatus_t_callback);
	bRet &= SigMgr_Data_SVS_NVMData_t_RegisterCallback(SigMgr_IpcBridge_Data_SVS_NVMData_t_callback);
	bRet &= SigMgr_Data_USS_Calibration_Data_t_RegisterCallback(SigMgr_IpcBridge_Data_USS_Calibration_Data_t_callback);
	bRet &= SigMgr_Data_THA_Calibration_data_MCU2_1_t_RegisterCallback(SigMgr_IpcBridge_Data_THA_Calibration_data_MCU2_1_t_callback);
	bRet &= SigMgr_Data_THA_Calibration_data_MPU1_0_t_RegisterCallback(SigMgr_IpcBridge_Data_THA_Calibration_data_MPU1_0_t_callback);
	bRet &= SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_RegisterCallback(SigMgr_IpcBridge_Data_TRSC_Calibration_data_MCU2_1_t_callback);
	bRet &= SigMgr_Data_APA_Calibration_data_MPU1_0_t_RegisterCallback(SigMgr_IpcBridge_Data_APA_Calibration_data_MPU1_0_t_callback);
	bRet &= SigMgr_Data_APA_Calibration_data_MCU2_1_t_RegisterCallback(SigMgr_IpcBridge_Data_APA_Calibration_data_MCU2_1_t_callback);
	bRet &= SigMgr_Data_SVS_Calibration_data_t_RegisterCallback(SigMgr_IpcBridge_Data_SVS_Calibration_data_t_callback);
	bRet &= SigMgr_Data_FOD_Calibration_data_t_RegisterCallback(SigMgr_IpcBridge_Data_FOD_Calibration_data_t_callback);
	bRet &= SigMgr_Data_LMD_Calibration_data_t_RegisterCallback(SigMgr_IpcBridge_Data_LMD_Calibration_data_t_callback);
	bRet &= SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_RegisterCallback(SigMgr_IpcBridge_Data_TRSC_Calibration_data_MPU1_0_t_callback);
	bRet &= SigMgr_Data_USS_Calibration_data_2_t_RegisterCallback(SigMgr_IpcBridge_Data_USS_Calibration_data_2_t_callback);
	bRet &= SigMgr_Data_INVMSignalManager_t_RegisterCallback(SigMgr_IpcBridge_Data_INVMSignalManager_t_callback);
	bRet &= SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(SigMgr_IpcBridge_Data_TimeManagerProxy_TimeStamp_t_callback);
	bRet &= SigMgr_Data_TRSC_CalibrationClear_t_RegisterCallback(SigMgr_IpcBridge_Data_TRSC_CalibrationClear_t_callback);
	bRet &= SigMgr_Data_UssTunningData_mcu1_0_t_RegisterCallback(SigMgr_IpcBridge_Data_UssTunningData_mcu1_0_t_callback);
	bRet &= SigMgr_Data_PerformanceStatsEnable_t_RegisterCallback(SigMgr_IpcBridge_Data_PerformanceStatsEnable_t_callback);

	return bRet;
}

#ifdef __cplusplus
}
#endif


#endif /*MCU1_0*/



#ifdef BUILD_MCU2_0

static void SigMgr_IpcBridge_data_SvsToTHADet_t_callback(const SvsToTHADet_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_data_SvsToTHADet_t,(uint16_t)sizeof(SvsToTHADet_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSvsToVCAN_SvsToVCAN_t_callback(const SvsToVCAN_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSvsToVCAN_SvsToVCAN_t,(uint16_t)sizeof(SvsToVCAN_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVStoTRSC_SVStoTRSC_t_callback(const SVStoTRSC_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVStoTRSC_SVStoTRSC_t,(uint16_t)sizeof(SVStoTRSC_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpScreenRequest_ScreenRequest_t_callback(const ScreenRequest_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpScreenRequest_ScreenRequest_t,(uint16_t)sizeof(ScreenRequest_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSvsToTHA_SvsToTHA_t_callback(const SvsToTHA_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSvsToTHA_SvsToTHA_t,(uint16_t)sizeof(SvsToTHA_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_callback(const ErrorMgr_ErrorCommPack_2_0_QM* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM,(uint16_t)sizeof(ErrorMgr_ErrorCommPack_2_0_QM),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_callback(const ErrorMgr_ErrorCommPack_2_0_B* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B,(uint16_t)sizeof(ErrorMgr_ErrorCommPack_2_0_B),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_data_SVStoTRSCSMVC_t_callback(const SVStoTRSCSMVC_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_data_SVStoTRSCSMVC_t,(uint16_t)sizeof(SVStoTRSCSMVC_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSR_State_MCU2_State_2_0_callback(const SSM_2_0_CoreStatus* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSR_State_MCU2_State_2_0,(uint16_t)sizeof(SSM_2_0_CoreStatus),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_IHMIInfoToFPA_t_callback(const IHMIInfoToFPA_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_IHMIInfoToFPA_t,(uint16_t)sizeof(IHMIInfoToFPA_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_IParkingSlotID_t_callback(const IParkingSlotID_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_IParkingSlotID_t,(uint16_t)sizeof(IParkingSlotID_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_THARelated_ScreenReq_t_callback(const THARelated_ScreenReq_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_THARelated_ScreenReq_t,(uint16_t)sizeof(THARelated_ScreenReq_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSToDiag_SVSToDiag_t_callback(const SVSToDiag_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSToDiag_SVSToDiag_t,(uint16_t)sizeof(SVSToDiag_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCamCsData_CAM_CS_Curr_Monitor_t_callback(const CAM_CS_Curr_Monitor_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCamCsData_CAM_CS_Curr_Monitor_t,(uint16_t)sizeof(CAM_CS_Curr_Monitor_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_HMIInfoToAP_t_callback(const HMIInfoToAP_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_HMIInfoToAP_t,(uint16_t)sizeof(HMIInfoToAP_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data1_USS_PowerSelect_t_callback(const USS_PowerSelect_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data1_USS_PowerSelect_t,(uint16_t)sizeof(USS_PowerSelect_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_TRSCDebug_ScrReq_t_callback(const TRSCDebug_ScrReq_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_TRSCDebug_ScrReq_t,(uint16_t)sizeof(TRSCDebug_ScrReq_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_callback(const CpuLoadMcu2_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t,(uint16_t)sizeof(CpuLoadMcu2_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSVSNVMData_SVS_NVMData_t_callback(const SVS_NVMData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSVSNVMData_SVS_NVMData_t,(uint16_t)sizeof(SVS_NVMData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_callback(const WdgCheckpointStatus_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t,(uint16_t)sizeof(WdgCheckpointStatus_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCamSerENStat_Cam_and_Ser_EN_Status_t_callback(const Cam_and_Ser_EN_Status_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCamSerENStat_Cam_and_Ser_EN_Status_t,(uint16_t)sizeof(Cam_and_Ser_EN_Status_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCAMSelInfo_CAM_select_info_t_callback(const CAM_select_info_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCAMSelInfo_CAM_select_info_t,(uint16_t)sizeof(CAM_select_info_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_callback(const Error_Fault_MCU2_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpErrFltMcu2_0_Error_Fault_MCU2_0_t,(uint16_t)sizeof(Error_Fault_MCU2_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_callback(const RunTimeStats_MCU2_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t,(uint16_t)sizeof(RunTimeStats_MCU2_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_CamHotplugStatus_t_callback(const CamHotplugStatus_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_CamHotplugStatus_t,(uint16_t)sizeof(CamHotplugStatus_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_callback(const StackUsage_MCU2_0_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t,(uint16_t)sizeof(StackUsage_MCU2_0_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_IpcBridge_Init(void)
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_data_SvsToTHADet_t_RegisterCallback(SigMgr_IpcBridge_data_SvsToTHADet_t_callback);
	bRet &= SigMgr_PpSvsToVCAN_SvsToVCAN_t_RegisterCallback(SigMgr_IpcBridge_PpSvsToVCAN_SvsToVCAN_t_callback);
	bRet &= SigMgr_PpSVStoTRSC_SVStoTRSC_t_RegisterCallback(SigMgr_IpcBridge_PpSVStoTRSC_SVStoTRSC_t_callback);
	bRet &= SigMgr_PpScreenRequest_ScreenRequest_t_RegisterCallback(SigMgr_IpcBridge_PpScreenRequest_ScreenRequest_t_callback);
	bRet &= SigMgr_PpSvsToTHA_SvsToTHA_t_RegisterCallback(SigMgr_IpcBridge_PpSvsToTHA_SvsToTHA_t_callback);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_RegisterCallback(SigMgr_IpcBridge_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_callback);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_RegisterCallback(SigMgr_IpcBridge_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_callback);
	bRet &= SigMgr_data_SVStoTRSCSMVC_t_RegisterCallback(SigMgr_IpcBridge_data_SVStoTRSCSMVC_t_callback);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_0_RegisterCallback(SigMgr_IpcBridge_PpSR_State_MCU2_State_2_0_callback);
	bRet &= SigMgr_Data_IHMIInfoToFPA_t_RegisterCallback(SigMgr_IpcBridge_Data_IHMIInfoToFPA_t_callback);
	bRet &= SigMgr_Data_IParkingSlotID_t_RegisterCallback(SigMgr_IpcBridge_Data_IParkingSlotID_t_callback);
	bRet &= SigMgr_Data_THARelated_ScreenReq_t_RegisterCallback(SigMgr_IpcBridge_Data_THARelated_ScreenReq_t_callback);
	bRet &= SigMgr_PpSVSToDiag_SVSToDiag_t_RegisterCallback(SigMgr_IpcBridge_PpSVSToDiag_SVSToDiag_t_callback);
	bRet &= SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_RegisterCallback(SigMgr_IpcBridge_PpCamCsData_CAM_CS_Curr_Monitor_t_callback);
	bRet &= SigMgr_Data_HMIInfoToAP_t_RegisterCallback(SigMgr_IpcBridge_Data_HMIInfoToAP_t_callback);
	bRet &= SigMgr_Data1_USS_PowerSelect_t_RegisterCallback(SigMgr_IpcBridge_Data1_USS_PowerSelect_t_callback);
	bRet &= SigMgr_Data_TRSCDebug_ScrReq_t_RegisterCallback(SigMgr_IpcBridge_Data_TRSCDebug_ScrReq_t_callback);
	bRet &= SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_RegisterCallback(SigMgr_IpcBridge_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_callback);
	bRet &= SigMgr_PpSVSNVMData_SVS_NVMData_t_RegisterCallback(SigMgr_IpcBridge_PpSVSNVMData_SVS_NVMData_t_callback);
	bRet &= SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_RegisterCallback(SigMgr_IpcBridge_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_callback);
	bRet &= SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_RegisterCallback(SigMgr_IpcBridge_PpCamSerENStat_Cam_and_Ser_EN_Status_t_callback);
	bRet &= SigMgr_PpCAMSelInfo_CAM_select_info_t_RegisterCallback(SigMgr_IpcBridge_PpCAMSelInfo_CAM_select_info_t_callback);
	bRet &= SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_RegisterCallback(SigMgr_IpcBridge_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_callback);
	bRet &= SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_RegisterCallback(SigMgr_IpcBridge_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_callback);
	bRet &= SigMgr_Data_CamHotplugStatus_t_RegisterCallback(SigMgr_IpcBridge_Data_CamHotplugStatus_t_callback);
	bRet &= SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_RegisterCallback(SigMgr_IpcBridge_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_callback);

	return bRet;
}

#ifdef __cplusplus
}
#endif


#endif /*MCU2_0*/



#ifdef BUILD_MCU2_1

static void SigMgr_IpcBridge_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_callback(const ErrorMgr_ErrorCommPack_2_1_QM* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM,(uint16_t)sizeof(ErrorMgr_ErrorCommPack_2_1_QM),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_callback(const ErrorMgr_ErrorCommPack_2_1_B* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B,(uint16_t)sizeof(ErrorMgr_ErrorCommPack_2_1_B),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTRSC_ME_VehOut_TRSC_t_callback(const ME_VehOut_TRSC_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTRSC_ME_VehOut_TRSC_t,(uint16_t)sizeof(ME_VehOut_TRSC_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_callback(const TRSCSMVCtoSVS_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t,(uint16_t)sizeof(TRSCSMVCtoSVS_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_callback(const Detection_Inputs_from_TRSC_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t,(uint16_t)sizeof(Detection_Inputs_from_TRSC_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSR_State_MCU2_State_2_1_callback(const SSM_2_1_CoreStatus* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSR_State_MCU2_State_2_1,(uint16_t)sizeof(SSM_2_1_CoreStatus),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpAPSMPAOut_TbAP_APSMPAOut_t_callback(const TbAP_APSMPAOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpAPSMPAOut_TbAP_APSMPAOut_t,(uint16_t)sizeof(TbAP_APSMPAOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_callback(const TbTHASmVc_FeatureOutputs_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t,(uint16_t)sizeof(TbTHASmVc_FeatureOutputs_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_IFPAInfoToHMI_t_callback(const IFPAInfoToHMI_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_IFPAInfoToHMI_t,(uint16_t)sizeof(IFPAInfoToHMI_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_IFPAInfoToPLD_t_callback(const IFPAInfoToPLD_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_IFPAInfoToPLD_t,(uint16_t)sizeof(IFPAInfoToPLD_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpJobFPAData_IJobFPAOutput_t_callback(const IJobFPAOutput_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpJobFPAData_IJobFPAOutput_t,(uint16_t)sizeof(IJobFPAOutput_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpNFCDOutput_NFCD_Output_callback(const NFCD_Output* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpNFCDOutput_NFCD_Output,(uint16_t)sizeof(NFCD_Output),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_callback(const TbAP_DriveAssistStatOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t,(uint16_t)sizeof(TbAP_DriveAssistStatOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSMDAInternal_TbAP_SMDAInternalOut_t_callback(const TbAP_SMDAInternalOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSMDAInternal_TbAP_SMDAInternalOut_t,(uint16_t)sizeof(TbAP_SMDAInternalOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_callback(const TbAP_SMPAInternalOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t,(uint16_t)sizeof(TbAP_SMPAInternalOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpFPAWarnOut_TbAP_FPAWarnOut_t_callback(const TbAP_FPAWarnOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpFPAWarnOut_TbAP_FPAWarnOut_t,(uint16_t)sizeof(TbAP_FPAWarnOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpRPAWarnOut_TbAP_RPAWarnOut_t_callback(const TbAP_RPAWarnOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpRPAWarnOut_TbAP_RPAWarnOut_t,(uint16_t)sizeof(TbAP_RPAWarnOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpPAStateOut_TbAP_PAStateOut_t_callback(const TbAP_PAStateOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpPAStateOut_TbAP_PAStateOut_t,(uint16_t)sizeof(TbAP_PAStateOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpVCActuatorOut_TbAP_VCActuatorOut_t_callback(const TbAP_VCActuatorOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpVCActuatorOut_TbAP_VCActuatorOut_t,(uint16_t)sizeof(TbAP_VCActuatorOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpVCState_TbAP_VCStateOut_t_callback(const TbAP_VCStateOut_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpVCState_TbAP_VCStateOut_t,(uint16_t)sizeof(TbAP_VCStateOut_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUssPointMapGrp_US_S_PointMapGroup_t_callback(const US_S_PointMapGroup_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUssPointMapGrp_US_S_PointMapGroup_t,(uint16_t)sizeof(US_S_PointMapGroup_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpSnrDirEcho_US_S_SnrDirEcho_t_callback(const US_S_SnrDirEcho_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpSnrDirEcho_US_S_SnrDirEcho_t,(uint16_t)sizeof(US_S_SnrDirEcho_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUssZoneInfo_US_S_ZoneInfo_t_callback(const US_S_ZoneInfo_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUssZoneInfo_US_S_ZoneInfo_t,(uint16_t)sizeof(US_S_ZoneInfo_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUSSBlockageBit_US_S_BlockageBit_t_callback(const US_S_BlockageBit_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t,(uint16_t)sizeof(US_S_BlockageBit_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUSSConstantData_US_S_USSConstantData_t_callback(const US_S_USSConstantData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUSSConstantData_US_S_USSConstantData_t,(uint16_t)sizeof(US_S_USSConstantData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_callback(const US_S_USSPeriodDiagData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t,(uint16_t)sizeof(US_S_USSPeriodDiagData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_callback(const US_S_USSErrorDiagData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t,(uint16_t)sizeof(US_S_USSErrorDiagData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_callback(const IFOD_Outputs_CVPAMFDData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t,(uint16_t)sizeof(IFOD_Outputs_CVPAMFDData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUssMrrgData_US_S_MarriageSensorIDs_t_callback(const US_S_MarriageSensorIDs_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUssMrrgData_US_S_MarriageSensorIDs_t,(uint16_t)sizeof(US_S_MarriageSensorIDs_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTrscToDiag_TRSCtoDiagMgr_t_callback(const TRSCtoDiagMgr_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTrscToDiag_TRSCtoDiagMgr_t,(uint16_t)sizeof(TRSCtoDiagMgr_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_Data_USS_PowerSelect_t_callback(const USS_PowerSelect_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_Data_USS_PowerSelect_t,(uint16_t)sizeof(USS_PowerSelect_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUssDataCollection_US_S_USSDataCollectionData_t_callback(const US_S_USSDataCollectionData_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUssDataCollection_US_S_USSDataCollectionData_t,(uint16_t)sizeof(US_S_USSDataCollectionData_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_callback(const US_S_PointDistOutputBuff_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpPointDistOpBuff_US_S_PointDistOutputBuff_t,(uint16_t)sizeof(US_S_PointDistOutputBuff_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_callback(const CpuLoadMcu2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t,(uint16_t)sizeof(CpuLoadMcu2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_callback(const IJobUSSObjectMapOutput_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t,(uint16_t)sizeof(IJobUSSObjectMapOutput_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_callback(const TbFA_ArbiterOutput_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t,(uint16_t)sizeof(TbFA_ArbiterOutput_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTbAPDebugOut_TbAP_DebugOut_callback(const TbAP_DebugOut* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTbAPDebugOut_TbAP_DebugOut,(uint16_t)sizeof(TbAP_DebugOut),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_callback(const WdgCheckpointStatus_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t,(uint16_t)sizeof(WdgCheckpointStatus_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_callback(const TbTHASmVc_DiagMgr_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t,(uint16_t)sizeof(TbTHASmVc_DiagMgr_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_callback(const IFOD_Outputs_Arbitration_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t,(uint16_t)sizeof(IFOD_Outputs_Arbitration_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpIDebugFODObject_IDebug_FODObject_t_callback(const IDebug_FODObject_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpIDebugFODObject_IDebug_FODObject_t,(uint16_t)sizeof(IDebug_FODObject_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTbFAResetKM_TbFA_ResetKM_t_callback(const TbFA_ResetKM_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTbFAResetKM_TbFA_ResetKM_t,(uint16_t)sizeof(TbFA_ResetKM_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_callback(const TRSCSMVCtoDebugCAN_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t,(uint16_t)sizeof(TRSCSMVCtoDebugCAN_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_callback(const US_S_CsmStateChangeReason_Type* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type,(uint16_t)sizeof(US_S_CsmStateChangeReason_Type),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUssDebugMsg_US_S_DebugMsg_t_callback(const US_S_DebugMsg_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUssDebugMsg_US_S_DebugMsg_t,(uint16_t)sizeof(US_S_DebugMsg_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_callback(const Error_Fault_MCU2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpErrFltMcu2_1_Error_Fault_MCU2_1_t,(uint16_t)sizeof(Error_Fault_MCU2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpUssTunData_UssTunningData_mcu2_1_t_callback(const UssTunningData_mcu2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpUssTunData_UssTunningData_mcu2_1_t,(uint16_t)sizeof(UssTunningData_mcu2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_callback(const RunTimeStats_MCU2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t,(uint16_t)sizeof(RunTimeStats_MCU2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}

static void SigMgr_IpcBridge_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_callback(const StackUsage_MCU2_1_t* const dataptr)
{
	#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED
	uint32_t  err=D_IPC_NO_ERROR;
	IPCMessage_Params_t params={(uint16_t) e_IpcMsgId_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t,(uint16_t)sizeof(StackUsage_MCU2_1_t),(uint8_t*)dataptr,(uint16_t)0};

	err=IPC_F_WrapperSend_u32(&params);
	if(err != D_IPC_NO_ERROR) { /* Do Nothing */} 
	#endif
}


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_IpcBridge_Init(void)
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_RegisterCallback(SigMgr_IpcBridge_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_callback);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_RegisterCallback(SigMgr_IpcBridge_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_callback);
	bRet &= SigMgr_PpTRSC_ME_VehOut_TRSC_t_RegisterCallback(SigMgr_IpcBridge_PpTRSC_ME_VehOut_TRSC_t_callback);
	bRet &= SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_RegisterCallback(SigMgr_IpcBridge_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_callback);
	bRet &= SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_RegisterCallback(SigMgr_IpcBridge_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_callback);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_1_RegisterCallback(SigMgr_IpcBridge_PpSR_State_MCU2_State_2_1_callback);
	bRet &= SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_RegisterCallback(SigMgr_IpcBridge_PpAPSMPAOut_TbAP_APSMPAOut_t_callback);
	bRet &= SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_RegisterCallback(SigMgr_IpcBridge_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_callback);
	bRet &= SigMgr_Data_IFPAInfoToHMI_t_RegisterCallback(SigMgr_IpcBridge_Data_IFPAInfoToHMI_t_callback);
	bRet &= SigMgr_Data_IFPAInfoToPLD_t_RegisterCallback(SigMgr_IpcBridge_Data_IFPAInfoToPLD_t_callback);
	bRet &= SigMgr_PpJobFPAData_IJobFPAOutput_t_RegisterCallback(SigMgr_IpcBridge_PpJobFPAData_IJobFPAOutput_t_callback);
	bRet &= SigMgr_PpNFCDOutput_NFCD_Output_RegisterCallback(SigMgr_IpcBridge_PpNFCDOutput_NFCD_Output_callback);
	bRet &= SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_RegisterCallback(SigMgr_IpcBridge_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_callback);
	bRet &= SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_RegisterCallback(SigMgr_IpcBridge_PpSMDAInternal_TbAP_SMDAInternalOut_t_callback);
	bRet &= SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_RegisterCallback(SigMgr_IpcBridge_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_callback);
	bRet &= SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_RegisterCallback(SigMgr_IpcBridge_PpFPAWarnOut_TbAP_FPAWarnOut_t_callback);
	bRet &= SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_RegisterCallback(SigMgr_IpcBridge_PpRPAWarnOut_TbAP_RPAWarnOut_t_callback);
	bRet &= SigMgr_PpPAStateOut_TbAP_PAStateOut_t_RegisterCallback(SigMgr_IpcBridge_PpPAStateOut_TbAP_PAStateOut_t_callback);
	bRet &= SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_RegisterCallback(SigMgr_IpcBridge_PpVCActuatorOut_TbAP_VCActuatorOut_t_callback);
	bRet &= SigMgr_PpVCState_TbAP_VCStateOut_t_RegisterCallback(SigMgr_IpcBridge_PpVCState_TbAP_VCStateOut_t_callback);
	bRet &= SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_RegisterCallback(SigMgr_IpcBridge_PpUssPointMapGrp_US_S_PointMapGroup_t_callback);
	bRet &= SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_RegisterCallback(SigMgr_IpcBridge_PpSnrDirEcho_US_S_SnrDirEcho_t_callback);
	bRet &= SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_RegisterCallback(SigMgr_IpcBridge_PpUssZoneInfo_US_S_ZoneInfo_t_callback);
	bRet &= SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_RegisterCallback(SigMgr_IpcBridge_PpUSSBlockageBit_US_S_BlockageBit_t_callback);
	bRet &= SigMgr_PpUSSConstantData_US_S_USSConstantData_t_RegisterCallback(SigMgr_IpcBridge_PpUSSConstantData_US_S_USSConstantData_t_callback);
	bRet &= SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_RegisterCallback(SigMgr_IpcBridge_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_callback);
	bRet &= SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_RegisterCallback(SigMgr_IpcBridge_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_callback);
	bRet &= SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_RegisterCallback(SigMgr_IpcBridge_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_callback);
	bRet &= SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_RegisterCallback(SigMgr_IpcBridge_PpUssMrrgData_US_S_MarriageSensorIDs_t_callback);
	bRet &= SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_RegisterCallback(SigMgr_IpcBridge_PpTrscToDiag_TRSCtoDiagMgr_t_callback);
	bRet &= SigMgr_Data_USS_PowerSelect_t_RegisterCallback(SigMgr_IpcBridge_Data_USS_PowerSelect_t_callback);
	bRet &= SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_RegisterCallback(SigMgr_IpcBridge_PpUssDataCollection_US_S_USSDataCollectionData_t_callback);
	bRet &= SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_RegisterCallback(SigMgr_IpcBridge_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_callback);
	bRet &= SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_RegisterCallback(SigMgr_IpcBridge_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_callback);
	bRet &= SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_RegisterCallback(SigMgr_IpcBridge_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_callback);
	bRet &= SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_RegisterCallback(SigMgr_IpcBridge_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_callback);
	bRet &= SigMgr_PpTbAPDebugOut_TbAP_DebugOut_RegisterCallback(SigMgr_IpcBridge_PpTbAPDebugOut_TbAP_DebugOut_callback);
	bRet &= SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_RegisterCallback(SigMgr_IpcBridge_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_callback);
	bRet &= SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_RegisterCallback(SigMgr_IpcBridge_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_callback);
	bRet &= SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_RegisterCallback(SigMgr_IpcBridge_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_callback);
	bRet &= SigMgr_PpIDebugFODObject_IDebug_FODObject_t_RegisterCallback(SigMgr_IpcBridge_PpIDebugFODObject_IDebug_FODObject_t_callback);
	bRet &= SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_RegisterCallback(SigMgr_IpcBridge_PpTbFAResetKM_TbFA_ResetKM_t_callback);
	bRet &= SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_RegisterCallback(SigMgr_IpcBridge_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_callback);
	bRet &= SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_RegisterCallback(SigMgr_IpcBridge_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_callback);
	bRet &= SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_RegisterCallback(SigMgr_IpcBridge_PpUssDebugMsg_US_S_DebugMsg_t_callback);
	bRet &= SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_RegisterCallback(SigMgr_IpcBridge_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_callback);
	bRet &= SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_RegisterCallback(SigMgr_IpcBridge_PpUssTunData_UssTunningData_mcu2_1_t_callback);
	bRet &= SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_RegisterCallback(SigMgr_IpcBridge_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_callback);
	bRet &= SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_RegisterCallback(SigMgr_IpcBridge_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_callback);

	return bRet;
}

#ifdef __cplusplus
}
#endif


#endif /*MCU2_1*/



#ifdef BUILD_MCU3_0


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_IpcBridge_Init(void)
{
	bool_t bRet=TRUE;


	return bRet;
}

#ifdef __cplusplus
}
#endif


#endif /*MCU3_0*/



#ifdef BUILD_MCU3_1


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_IpcBridge_Init(void)
{
	bool_t bRet=TRUE;


	return bRet;
}

#ifdef __cplusplus
}
#endif


#endif /*MCU3_1*/

