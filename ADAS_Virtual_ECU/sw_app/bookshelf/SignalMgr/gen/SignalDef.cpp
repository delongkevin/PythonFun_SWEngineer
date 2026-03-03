
#include "SignalDef.h"
#include "SignalMgrBase.h"
using namespace SignalMgr;


static bool_t SigDef_GetInitState();


#ifdef BUILD_MPU1_0

// *********************************************************************
// ****************** Start SignalData : uint8_t :: data_UnknownMsg_t 
// *********************************************************************
static SignalMgr_ProtectedData<uint8_t> SigMgr_data_UnknownMsg_t;
static bool_t SigMgr_data_UnknownMsg_t_Init(const char *uid_name,const uint8_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_UnknownMsg_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_UnknownMsg_t_Put(uint8_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_UnknownMsg_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_UnknownMsg_t_Get(uint8_t *data)
{
	SigMgr_data_UnknownMsg_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
uint8_t * SigMgr_data_UnknownMsg_t_GetDataObjRef()
{
	return SigMgr_data_UnknownMsg_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_UnknownMsg_t_Lock()
{
	SigMgr_data_UnknownMsg_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_UnknownMsg_t_UnLock()
{
	SigMgr_data_UnknownMsg_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : uint8_t :: data_UnknownMsg_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************
static SignalMgr_ProtectedData<SvsToTHADet_t> SigMgr_data_SvsToTHADet_t;
static bool_t SigMgr_data_SvsToTHADet_t_Init(const char *uid_name,const SvsToTHADet_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_SvsToTHADet_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SvsToTHADet_t_Put(SvsToTHADet_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_SvsToTHADet_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Get(SvsToTHADet_t *data)
{
	SigMgr_data_SvsToTHADet_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHADet_t * SigMgr_data_SvsToTHADet_t_GetDataObjRef()
{
	return SigMgr_data_SvsToTHADet_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Lock()
{
	SigMgr_data_SvsToTHADet_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_UnLock()
{
	SigMgr_data_SvsToTHADet_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************
static SignalMgr_ProtectedData<ScreenRequest_t> SigMgr_PpScreenRequest_ScreenRequest_t;
static bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Init(const char *uid_name,const ScreenRequest_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data)
{
	SigMgr_PpScreenRequest_ScreenRequest_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef()
{
	return SigMgr_PpScreenRequest_ScreenRequest_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ScreenResponse_t,1> SigMgr_PpScreenResponse_ScreenResponse_t;
static bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Init(const char *uid_name,const ScreenResponse_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenResponse_ScreenResponse_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Put(ScreenResponse_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenResponse_ScreenResponse_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Get(ScreenResponse_t *data)
{
	SigMgr_PpScreenResponse_ScreenResponse_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenResponse_t * SigMgr_PpScreenResponse_ScreenResponse_t_GetDataObjRef()
{
	return SigMgr_PpScreenResponse_ScreenResponse_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Lock()
{
	SigMgr_PpScreenResponse_ScreenResponse_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_UnLock()
{
	SigMgr_PpScreenResponse_ScreenResponse_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_RegisterCallback(void (*Callback)(const ScreenResponse_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpScreenResponse_ScreenResponse_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_VehInp_to_IpcSignals_t,1> SigMgr_ME_VehInp_to_IpcSignals_data_f;
static bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Init(const char *uid_name,const ME_VehInp_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data)
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef()
{
	return SigMgr_ME_VehInp_to_IpcSignals_data_f.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const))
{
	bool_t bRet;
	bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ErrorMgr_ErrorCommPack_QNX_QM,1> SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM;
static bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_QNX_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put(ErrorMgr_ErrorCommPack_QNX_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(ErrorMgr_ErrorCommPack_QNX_QM *data)
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_QM * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_GetDataObjRef()
{
	return SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Lock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_UnLock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_QNX_QM * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ErrorMgr_ErrorCommPack_QNX_B,1> SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B;
static bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_QNX_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put(ErrorMgr_ErrorCommPack_QNX_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(ErrorMgr_ErrorCommPack_QNX_B *data)
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_B * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_GetDataObjRef()
{
	return SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Lock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_UnLock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_QNX_B * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSC_Inputs_from_TrailerDetection_t,1> SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t;
static bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init(const char *uid_name,const TRSC_Inputs_from_TrailerDetection_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data)
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef()
{
	return SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_RegisterCallback(void (*Callback)(const TRSC_Inputs_from_TrailerDetection_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<MeDLD_e_RrCamSts_t,1> SigMgr_data_MeDLD_e_RrCamSts_t;
static bool_t SigMgr_data_MeDLD_e_RrCamSts_t_Init(const char *uid_name,const MeDLD_e_RrCamSts_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_MeDLD_e_RrCamSts_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_MeDLD_e_RrCamSts_t_Put(MeDLD_e_RrCamSts_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_MeDLD_e_RrCamSts_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Get(MeDLD_e_RrCamSts_t *data)
{
	SigMgr_data_MeDLD_e_RrCamSts_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MeDLD_e_RrCamSts_t * SigMgr_data_MeDLD_e_RrCamSts_t_GetDataObjRef()
{
	return SigMgr_data_MeDLD_e_RrCamSts_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Lock()
{
	SigMgr_data_MeDLD_e_RrCamSts_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_UnLock()
{
	SigMgr_data_MeDLD_e_RrCamSts_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_MeDLD_e_RrCamSts_t_RegisterCallback(void (*Callback)(const MeDLD_e_RrCamSts_t * const))
{
	bool_t bRet;
	bRet=SigMgr_data_MeDLD_e_RrCamSts_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData<Detection_Inputs_from_TRSC_t> SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t;
static bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Init(const char *uid_name,const Detection_Inputs_from_TRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(Detection_Inputs_from_TRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(Detection_Inputs_from_TRSC_t *data)
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Detection_Inputs_from_TRSC_t * SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_GetDataObjRef()
{
	return SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Lock()
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_UnLock()
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_2_0_CoreStatus> SigMgr_PpSR_State_MCU2_State_2_0;
static bool_t SigMgr_PpSR_State_MCU2_State_2_0_Init(const char *uid_name,const SSM_2_0_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_0.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_0.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_2_1_CoreStatus> SigMgr_PpSR_State_MCU2_State_2_1;
static bool_t SigMgr_PpSR_State_MCU2_State_2_1_Init(const char *uid_name,const SSM_2_1_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_1.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_1.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SSM_QNX_CoreStatus,1> SigMgr_PpSR_State_QNX_State_QNX;
static bool_t SigMgr_PpSR_State_QNX_State_QNX_Init(const char *uid_name,const SSM_QNX_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data)
{
	SigMgr_PpSR_State_QNX_State_QNX.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef()
{
	return SigMgr_PpSR_State_QNX_State_QNX.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock()
{
	SigMgr_PpSR_State_QNX_State_QNX.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock()
{
	SigMgr_PpSR_State_QNX_State_QNX.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_RegisterCallback(void (*Callback)(const SSM_QNX_CoreStatus * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSR_State_QNX_State_QNX.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_SystemState> SigMgr_Data_SSM_SystemState;
static bool_t SigMgr_Data_SSM_SystemState_Init(const char *uid_name,const SSM_SystemState *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data)
{
	SigMgr_Data_SSM_SystemState.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState * SigMgr_Data_SSM_SystemState_GetDataObjRef()
{
	return SigMgr_Data_SSM_SystemState.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock()
{
	SigMgr_Data_SSM_SystemState.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock()
{
	SigMgr_Data_SSM_SystemState.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************
static SignalMgr_ProtectedData<CalDataProvider_MPU_1_0_Def> SigMgr_Data_CalDataProvider_MPU_1_0_Def;
static bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_Init(const char *uid_name,const CalDataProvider_MPU_1_0_Def *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CalDataProvider_MPU_1_0_Def.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put(CalDataProvider_MPU_1_0_Def *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CalDataProvider_MPU_1_0_Def.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Get(CalDataProvider_MPU_1_0_Def *data)
{
	SigMgr_Data_CalDataProvider_MPU_1_0_Def.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MPU_1_0_Def * SigMgr_Data_CalDataProvider_MPU_1_0_Def_GetDataObjRef()
{
	return SigMgr_Data_CalDataProvider_MPU_1_0_Def.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Lock()
{
	SigMgr_Data_CalDataProvider_MPU_1_0_Def.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_UnLock()
{
	SigMgr_Data_CalDataProvider_MPU_1_0_Def.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibSMToAlgoCamCalib_t :: Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_e_SVSCalibSMToAlgoCamCalib_t> SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
static bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Init(const char *uid_name,const TbSVS_e_SVSCalibSMToAlgoCamCalib_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Put(TbSVS_e_SVSCalibSMToAlgoCamCalib_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Get(TbSVS_e_SVSCalibSMToAlgoCamCalib_t *data)
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibSMToAlgoCamCalib_t * SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Lock()
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_UnLock()
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_SVSCalibSMToAlgoCamCalib_t :: Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibAlgoToSMCamCalib_t :: Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_e_SVSCalibAlgoToSMCamCalib_t> SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
static bool_t SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Init(const char *uid_name,const TbSVS_e_SVSCalibAlgoToSMCamCalib_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Put(TbSVS_e_SVSCalibAlgoToSMCamCalib_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Get(TbSVS_e_SVSCalibAlgoToSMCamCalib_t *data)
{
	SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibAlgoToSMCamCalib_t * SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Lock()
{
	SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_UnLock()
{
	SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_SVSCalibAlgoToSMCamCalib_t :: Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_S_SVSCamCurrentCalibDataToNVM_t,1> SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamCurrentCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Get(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamCurrentCalibDataToNVM_t * SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_S_SVSCamOCCalibDataToNVM_t,1> SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamOCCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put(TbSVS_S_SVSCamOCCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Get(TbSVS_S_SVSCamOCCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamOCCalibDataToNVM_t * SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamOCCalibDataToNVM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_S_SVSCamSCCalibDataToNVM_t,1> SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamSCCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put(TbSVS_S_SVSCamSCCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Get(TbSVS_S_SVSCamSCCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamSCCalibDataToNVM_t * SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamSCCalibDataToNVM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_S_SVSCamEOLCalibDataToNVM_t,1> SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamEOLCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Get(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamEOLCalibDataToNVM_t * SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamEOLCalibDataToNVM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_e_SVSOutputToDiagMgrCamCalib_t,1> SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t;
static bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Init(const char *uid_name,const TbSVS_e_SVSOutputToDiagMgrCamCalib_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Get(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data)
{
	SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSOutputToDiagMgrCamCalib_t * SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_GetDataObjRef()
{
	return SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Lock()
{
	SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_UnLock()
{
	SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_RegisterCallback(void (*Callback)(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t> SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
static bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Init(const char *uid_name,const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Get(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data)
{
	SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t * SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Lock()
{
	SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_UnLock()
{
	SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t> SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;
static bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Init(const char *uid_name,const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Get(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data)
{
	SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t * SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Lock()
{
	SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_UnLock()
{
	SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<JobTHADetOutput_t,1> SigMgr_PpJobTHADetOutput_JobTHADetOutput_t;
static bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init(const char *uid_name,const JobTHADetOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data)
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_RegisterCallback(void (*Callback)(const JobTHADetOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbTHASmVc_FeatureOutputs_t> SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t;
static bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init(const char *uid_name,const TbTHASmVc_FeatureOutputs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data)
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef()
{
	return SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************
static SignalMgr_ProtectedData<IFPAInfoToPLD_t> SigMgr_Data_IFPAInfoToPLD_t;
static bool_t SigMgr_Data_IFPAInfoToPLD_t_Init(const char *uid_name,const IFPAInfoToPLD_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IFPAInfoToPLD_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToPLD_t_Put(IFPAInfoToPLD_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IFPAInfoToPLD_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Get(IFPAInfoToPLD_t *data)
{
	SigMgr_Data_IFPAInfoToPLD_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToPLD_t * SigMgr_Data_IFPAInfoToPLD_t_GetDataObjRef()
{
	return SigMgr_Data_IFPAInfoToPLD_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Lock()
{
	SigMgr_Data_IFPAInfoToPLD_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_UnLock()
{
	SigMgr_Data_IFPAInfoToPLD_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IJobPLDOutput_t,1> SigMgr_PpJobPLDData_IJobPLDOutput_t;
static bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Init(const char *uid_name,const IJobPLDOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(IJobPLDOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(IJobPLDOutput_t *data)
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobPLDOutput_t * SigMgr_PpJobPLDData_IJobPLDOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobPLDData_IJobPLDOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Lock()
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_UnLock()
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_RegisterCallback(void (*Callback)(const IJobPLDOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************
static SignalMgr_ProtectedData<IKinematicData_t> SigMgr_Data_IKinematicData_t;
static bool_t SigMgr_Data_IKinematicData_t_Init(const char *uid_name,const IKinematicData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data)
{
	SigMgr_Data_IKinematicData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t * SigMgr_Data_IKinematicData_t_GetDataObjRef()
{
	return SigMgr_Data_IKinematicData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock()
{
	SigMgr_Data_IKinematicData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock()
{
	SigMgr_Data_IKinematicData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IParkingSlotInformation_t,1> SigMgr_Data_IParkingSlotInformation_t;
static bool_t SigMgr_Data_IParkingSlotInformation_t_Init(const char *uid_name,const IParkingSlotInformation_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IParkingSlotInformation_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotInformation_t_Put(IParkingSlotInformation_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IParkingSlotInformation_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Get(IParkingSlotInformation_t *data)
{
	SigMgr_Data_IParkingSlotInformation_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotInformation_t * SigMgr_Data_IParkingSlotInformation_t_GetDataObjRef()
{
	return SigMgr_Data_IParkingSlotInformation_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Lock()
{
	SigMgr_Data_IParkingSlotInformation_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_UnLock()
{
	SigMgr_Data_IParkingSlotInformation_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotInformation_t_RegisterCallback(void (*Callback)(const IParkingSlotInformation_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_IParkingSlotInformation_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<MOT_Output,1> SigMgr_Data_MOT_Output;
static bool_t SigMgr_Data_MOT_Output_Init(const char *uid_name,const MOT_Output *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_MOT_Output.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_MOT_Output_Put(MOT_Output *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_MOT_Output.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Get(MOT_Output *data)
{
	SigMgr_Data_MOT_Output.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MOT_Output * SigMgr_Data_MOT_Output_GetDataObjRef()
{
	return SigMgr_Data_MOT_Output.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Lock()
{
	SigMgr_Data_MOT_Output.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_UnLock()
{
	SigMgr_Data_MOT_Output.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_MOT_Output_RegisterCallback(void (*Callback)(const MOT_Output * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_MOT_Output.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_DriveAssistStatOut_t> SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t;
static bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Init(const char *uid_name,const TbAP_DriveAssistStatOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(TbAP_DriveAssistStatOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(TbAP_DriveAssistStatOut_t *data)
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DriveAssistStatOut_t * SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_GetDataObjRef()
{
	return SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Lock()
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_UnLock()
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************
static SignalMgr_ProtectedData<FID_STRUCT_QM> SigMgr_Data_FID_STRUCT_QM;
static bool_t SigMgr_Data_FID_STRUCT_QM_Init(const char *uid_name,const FID_STRUCT_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data)
{
	SigMgr_Data_FID_STRUCT_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock()
{
	SigMgr_Data_FID_STRUCT_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock()
{
	SigMgr_Data_FID_STRUCT_QM.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************
static SignalMgr_ProtectedData<FID_STRUCT_B> SigMgr_Data_FID_STRUCT_B;
static bool_t SigMgr_Data_FID_STRUCT_B_Init(const char *uid_name,const FID_STRUCT_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data)
{
	SigMgr_Data_FID_STRUCT_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B * SigMgr_Data_FID_STRUCT_B_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock()
{
	SigMgr_Data_FID_STRUCT_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock()
{
	SigMgr_Data_FID_STRUCT_B.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_BlockageBit_t> SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t;
static bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Init(const char *uid_name,const US_S_BlockageBit_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(US_S_BlockageBit_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(US_S_BlockageBit_t *data)
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_BlockageBit_t * SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_GetDataObjRef()
{
	return SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Lock()
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_UnLock()
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_USSErrorDiagData_t> SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t;
static bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Init(const char *uid_name,const US_S_USSErrorDiagData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(US_S_USSErrorDiagData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(US_S_USSErrorDiagData_t *data)
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSErrorDiagData_t * SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_GetDataObjRef()
{
	return SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Lock()
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_UnLock()
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************
static SignalMgr_ProtectedData<THARelated_ScreenReq_t> SigMgr_Data_THARelated_ScreenReq_t;
static bool_t SigMgr_Data_THARelated_ScreenReq_t_Init(const char *uid_name,const THARelated_ScreenReq_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_THARelated_ScreenReq_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THARelated_ScreenReq_t_Put(THARelated_ScreenReq_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_THARelated_ScreenReq_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Get(THARelated_ScreenReq_t *data)
{
	SigMgr_Data_THARelated_ScreenReq_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THARelated_ScreenReq_t * SigMgr_Data_THARelated_ScreenReq_t_GetDataObjRef()
{
	return SigMgr_Data_THARelated_ScreenReq_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Lock()
{
	SigMgr_Data_THARelated_ScreenReq_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_UnLock()
{
	SigMgr_Data_THARelated_ScreenReq_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<Svs_CamEepromDataArray_t,1> SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t;
static bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Init(const char *uid_name,const Svs_CamEepromDataArray_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put(Svs_CamEepromDataArray_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Get(Svs_CamEepromDataArray_t *data)
{
	SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Svs_CamEepromDataArray_t * SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_GetDataObjRef()
{
	return SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Lock()
{
	SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_UnLock()
{
	SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_RegisterCallback(void (*Callback)(const Svs_CamEepromDataArray_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<LMD_Outputs_CVPAMFDData2_t,1> SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t;
static bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Init(const char *uid_name,const LMD_Outputs_CVPAMFDData2_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put(LMD_Outputs_CVPAMFDData2_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Get(LMD_Outputs_CVPAMFDData2_t *data)
{
	SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Outputs_CVPAMFDData2_t * SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_GetDataObjRef()
{
	return SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Lock()
{
	SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_UnLock()
{
	SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_RegisterCallback(void (*Callback)(const LMD_Outputs_CVPAMFDData2_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TrailerDetection_Output_DID_t,1> SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t;
static bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Init(const char *uid_name,const TrailerDetection_Output_DID_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put(TrailerDetection_Output_DID_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Get(TrailerDetection_Output_DID_t *data)
{
	SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_DID_t * SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_GetDataObjRef()
{
	return SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Lock()
{
	SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_UnLock()
{
	SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_RegisterCallback(void (*Callback)(const TrailerDetection_Output_DID_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_ProxiToMPU1_0_Def_t> SigMgr_Data_ME_ProxiToMPU1_0_Def_t;
static bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Init(const char *uid_name,const ME_ProxiToMPU1_0_Def_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_ProxiToMPU1_0_Def_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put(ME_ProxiToMPU1_0_Def_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_ProxiToMPU1_0_Def_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Get(ME_ProxiToMPU1_0_Def_t *data)
{
	SigMgr_Data_ME_ProxiToMPU1_0_Def_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMPU1_0_Def_t * SigMgr_Data_ME_ProxiToMPU1_0_Def_t_GetDataObjRef()
{
	return SigMgr_Data_ME_ProxiToMPU1_0_Def_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Lock()
{
	SigMgr_Data_ME_ProxiToMPU1_0_Def_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_UnLock()
{
	SigMgr_Data_ME_ProxiToMPU1_0_Def_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TrscDebug_ScrRes_t,1> SigMgr_Data_TrscDebug_ScrRes_t;
static bool_t SigMgr_Data_TrscDebug_ScrRes_t_Init(const char *uid_name,const TrscDebug_ScrRes_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TrscDebug_ScrRes_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrscDebug_ScrRes_t_Put(TrscDebug_ScrRes_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TrscDebug_ScrRes_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Get(TrscDebug_ScrRes_t *data)
{
	SigMgr_Data_TrscDebug_ScrRes_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrscDebug_ScrRes_t * SigMgr_Data_TrscDebug_ScrRes_t_GetDataObjRef()
{
	return SigMgr_Data_TrscDebug_ScrRes_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Lock()
{
	SigMgr_Data_TrscDebug_ScrRes_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_UnLock()
{
	SigMgr_Data_TrscDebug_ScrRes_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrscDebug_ScrRes_t_RegisterCallback(void (*Callback)(const TrscDebug_ScrRes_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TrscDebug_ScrRes_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSCDebug_ScrReq_t> SigMgr_Data_TRSCDebug_ScrReq_t;
static bool_t SigMgr_Data_TRSCDebug_ScrReq_t_Init(const char *uid_name,const TRSCDebug_ScrReq_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSCDebug_ScrReq_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSCDebug_ScrReq_t_Put(TRSCDebug_ScrReq_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSCDebug_ScrReq_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Get(TRSCDebug_ScrReq_t *data)
{
	SigMgr_Data_TRSCDebug_ScrReq_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCDebug_ScrReq_t * SigMgr_Data_TRSCDebug_ScrReq_t_GetDataObjRef()
{
	return SigMgr_Data_TRSCDebug_ScrReq_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Lock()
{
	SigMgr_Data_TRSCDebug_ScrReq_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_UnLock()
{
	SigMgr_Data_TRSCDebug_ScrReq_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_CanDebugRIDStatus_t> SigMgr_Data_ME_CanDebugRIDStatus_t;
static bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Init(const char *uid_name,const ME_CanDebugRIDStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data)
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef()
{
	return SigMgr_Data_ME_CanDebugRIDStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<WdgCheckpointStatus_t,1> SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t;
static bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Init(const char *uid_name,const WdgCheckpointStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data)
{
	SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t * SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_GetDataObjRef()
{
	return SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Lock()
{
	SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_UnLock()
{
	SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_RegisterCallback(void (*Callback)(const WdgCheckpointStatus_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<LMD_Lane_Outputs_s,1> SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s;
static bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Init(const char *uid_name,const LMD_Lane_Outputs_s *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put(LMD_Lane_Outputs_s *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Get(LMD_Lane_Outputs_s *data)
{
	SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Lane_Outputs_s * SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_GetDataObjRef()
{
	return SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Lock()
{
	SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_UnLock()
{
	SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_RegisterCallback(void (*Callback)(const LMD_Lane_Outputs_s * const))
{
	bool_t bRet;
	bRet=SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<THA_Calibration_data_MPU1_0_t> SigMgr_Data_THA_Calibration_data_MPU1_0_t;
static bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_Init(const char *uid_name,const THA_Calibration_data_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put(THA_Calibration_data_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Get(THA_Calibration_data_MPU1_0_t *data)
{
	SigMgr_Data_THA_Calibration_data_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MPU1_0_t * SigMgr_Data_THA_Calibration_data_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_Data_THA_Calibration_data_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Lock()
{
	SigMgr_Data_THA_Calibration_data_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_UnLock()
{
	SigMgr_Data_THA_Calibration_data_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<APA_Calibration_data_MPU1_0_t> SigMgr_Data_APA_Calibration_data_MPU1_0_t;
static bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_Init(const char *uid_name,const APA_Calibration_data_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put(APA_Calibration_data_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Get(APA_Calibration_data_MPU1_0_t *data)
{
	SigMgr_Data_APA_Calibration_data_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MPU1_0_t * SigMgr_Data_APA_Calibration_data_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_Data_APA_Calibration_data_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Lock()
{
	SigMgr_Data_APA_Calibration_data_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_UnLock()
{
	SigMgr_Data_APA_Calibration_data_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData<LMD_Calibration_data_t> SigMgr_Data_LMD_Calibration_data_t;
static bool_t SigMgr_Data_LMD_Calibration_data_t_Init(const char *uid_name,const LMD_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_LMD_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_Put(LMD_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_LMD_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Get(LMD_Calibration_data_t *data)
{
	SigMgr_Data_LMD_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Calibration_data_t * SigMgr_Data_LMD_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_LMD_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Lock()
{
	SigMgr_Data_LMD_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_UnLock()
{
	SigMgr_Data_LMD_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSC_Calibration_data_MPU1_0_t> SigMgr_Data_TRSC_Calibration_data_MPU1_0_t;
static bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Init(const char *uid_name,const TRSC_Calibration_data_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put(TRSC_Calibration_data_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Get(TRSC_Calibration_data_MPU1_0_t *data)
{
	SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MPU1_0_t * SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Lock()
{
	SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_UnLock()
{
	SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_Proxi_MPU1_0_to_MCU1_0_t,1> SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t;
static bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Init(const char *uid_name,const ME_Proxi_MPU1_0_to_MCU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Get(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
{
	SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_MPU1_0_to_MCU1_0_t * SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_GetDataObjRef()
{
	return SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Lock()
{
	SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_UnLock()
{
	SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_RegisterCallback(void (*Callback)(const ME_Proxi_MPU1_0_to_MCU1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_e_SVSCalibSMToHmi_t,1> SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t;
static bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Init(const char *uid_name,const TbSVS_e_SVSCalibSMToHmi_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put(TbSVS_e_SVSCalibSMToHmi_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(TbSVS_e_SVSCalibSMToHmi_t *data)
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibSMToHmi_t * SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Lock()
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_UnLock()
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_RegisterCallback(void (*Callback)(const TbSVS_e_SVSCalibSMToHmi_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TrailerDetection_Output_HMI_t,1> SigMgr_Data_TrailerDetection_Output_HMI_t;
static bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_Init(const char *uid_name,const TrailerDetection_Output_HMI_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TrailerDetection_Output_HMI_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_Put(TrailerDetection_Output_HMI_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TrailerDetection_Output_HMI_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Get(TrailerDetection_Output_HMI_t *data)
{
	SigMgr_Data_TrailerDetection_Output_HMI_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_HMI_t * SigMgr_Data_TrailerDetection_Output_HMI_t_GetDataObjRef()
{
	return SigMgr_Data_TrailerDetection_Output_HMI_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Lock()
{
	SigMgr_Data_TrailerDetection_Output_HMI_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_UnLock()
{
	SigMgr_Data_TrailerDetection_Output_HMI_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_RegisterCallback(void (*Callback)(const TrailerDetection_Output_HMI_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TrailerDetection_Output_HMI_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<JobDLDOutput_t,1> SigMgr_PpDLDOutput_JobDLDOutput_t;
static bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_Init(const char *uid_name,const JobDLDOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDLDOutput_JobDLDOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_Put(JobDLDOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDLDOutput_JobDLDOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Get(JobDLDOutput_t *data)
{
	SigMgr_PpDLDOutput_JobDLDOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobDLDOutput_t * SigMgr_PpDLDOutput_JobDLDOutput_t_GetDataObjRef()
{
	return SigMgr_PpDLDOutput_JobDLDOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Lock()
{
	SigMgr_PpDLDOutput_JobDLDOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_UnLock()
{
	SigMgr_PpDLDOutput_JobDLDOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_RegisterCallback(void (*Callback)(const JobDLDOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpDLDOutput_JobDLDOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<KeepAliveResponse_t,1> SigMgr_PpKeepAliveResponse_KeepAliveResponse_t;
static bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Init(const char *uid_name,const KeepAliveResponse_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(KeepAliveResponse_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(KeepAliveResponse_t *data)
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
KeepAliveResponse_t * SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_GetDataObjRef()
{
	return SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Lock()
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_UnLock()
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_RegisterCallback(void (*Callback)(const KeepAliveResponse_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<Error_Fault_MPU1_0_t,1> SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t;
static bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Init(const char *uid_name,const Error_Fault_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put(Error_Fault_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Get(Error_Fault_MPU1_0_t *data)
{
	SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MPU1_0_t * SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Lock()
{
	SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_UnLock()
{
	SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_RegisterCallback(void (*Callback)(const Error_Fault_MPU1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSC_CalibrationClear_t> SigMgr_Data_TRSC_CalibrationClear_t;
static bool_t SigMgr_Data_TRSC_CalibrationClear_t_Init(const char *uid_name,const TRSC_CalibrationClear_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSC_CalibrationClear_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_CalibrationClear_t_Put(TRSC_CalibrationClear_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSC_CalibrationClear_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Get(TRSC_CalibrationClear_t *data)
{
	SigMgr_Data_TRSC_CalibrationClear_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_CalibrationClear_t * SigMgr_Data_TRSC_CalibrationClear_t_GetDataObjRef()
{
	return SigMgr_Data_TRSC_CalibrationClear_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Lock()
{
	SigMgr_Data_TRSC_CalibrationClear_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_UnLock()
{
	SigMgr_Data_TRSC_CalibrationClear_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************
static SignalMgr_ProtectedData<PerformanceStatsEnable_t> SigMgr_Data_PerformanceStatsEnable_t;
static bool_t SigMgr_Data_PerformanceStatsEnable_t_Init(const char *uid_name,const PerformanceStatsEnable_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data)
{
	SigMgr_Data_PerformanceStatsEnable_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef()
{
	return SigMgr_Data_PerformanceStatsEnable_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock()
{
	SigMgr_Data_PerformanceStatsEnable_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock()
{
	SigMgr_Data_PerformanceStatsEnable_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<RunTimeStats_MPU1_0_t,1> SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t;
static bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Init(const char *uid_name,const RunTimeStats_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put(RunTimeStats_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Get(RunTimeStats_MPU1_0_t *data)
{
	SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MPU1_0_t * SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Lock()
{
	SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_UnLock()
{
	SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_RegisterCallback(void (*Callback)(const RunTimeStats_MPU1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<CamHotplugStatus_t> SigMgr_Data_CamHotplugStatus_t;
static bool_t SigMgr_Data_CamHotplugStatus_t_Init(const char *uid_name,const CamHotplugStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CamHotplugStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CamHotplugStatus_t_Put(CamHotplugStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CamHotplugStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Get(CamHotplugStatus_t *data)
{
	SigMgr_Data_CamHotplugStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CamHotplugStatus_t * SigMgr_Data_CamHotplugStatus_t_GetDataObjRef()
{
	return SigMgr_Data_CamHotplugStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Lock()
{
	SigMgr_Data_CamHotplugStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_UnLock()
{
	SigMgr_Data_CamHotplugStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** SignalDef LocalData ******************************
// *********************************************************************
static bool_t SigDef_Init_state=FALSE;
// *********************************************************************
// ****************** SignalDef Const Init Data ************************
// *********************************************************************

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init()
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_data_UnknownMsg_t_Init("data_UnknownMsg_t_uid",NULL,TRUE);
	bRet &= SigMgr_data_SvsToTHADet_t_Init("data_SvsToTHADet_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenRequest_ScreenRequest_t_Init("PpScreenRequest_ScreenRequest_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenResponse_ScreenResponse_t_Init("PpScreenResponse_ScreenResponse_t_uid",NULL,TRUE);
	bRet &= SigMgr_ME_VehInp_to_IpcSignals_data_f_Init("ME_VehInp_to_IpcSignals_data_f_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Init("PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Init("PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init("PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_uid",NULL,TRUE);
	bRet &= SigMgr_data_MeDLD_e_RrCamSts_t_Init("data_MeDLD_e_RrCamSts_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Init("PpDetInpTrsc_Detection_Inputs_from_TRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_0_Init("PpSR_State_MCU2_State_2_0_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_1_Init("PpSR_State_MCU2_State_2_1_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_QNX_State_QNX_Init("PpSR_State_QNX_State_QNX_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SSM_SystemState_Init("Data_SSM_SystemState_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CalDataProvider_MPU_1_0_Def_Init("Data_CalDataProvider_MPU_1_0_Def_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Init("Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Init("Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Init("PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Init("PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Init("PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Init("PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Init("PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Init("Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Init("Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init("PpJobTHADetOutput_JobTHADetOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init("PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IFPAInfoToPLD_t_Init("Data_IFPAInfoToPLD_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobPLDData_IJobPLDOutput_t_Init("PpJobPLDData_IJobPLDOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IKinematicData_t_Init("Data_IKinematicData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IParkingSlotInformation_t_Init("Data_IParkingSlotInformation_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_MOT_Output_Init("Data_MOT_Output_uid",NULL,TRUE);
	bRet &= SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Init("PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_QM_Init("Data_FID_STRUCT_QM_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_B_Init("Data_FID_STRUCT_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Init("PpUSSBlockageBit_US_S_BlockageBit_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Init("PpUSSErrorDiagData_US_S_USSErrorDiagData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_THARelated_ScreenReq_t_Init("Data_THARelated_ScreenReq_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Init("PpCamEepromData_Svs_CamEepromDataArray_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Init("PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Init("PpTrailerDetectOP_TrailerDetection_Output_DID_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Init("Data_ME_ProxiToMPU1_0_Def_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TrscDebug_ScrRes_t_Init("Data_TrscDebug_ScrRes_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSCDebug_ScrReq_t_Init("Data_TRSCDebug_ScrReq_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_CanDebugRIDStatus_t_Init("Data_ME_CanDebugRIDStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Init("PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Init("PpLMDLaneOp_LMD_Lane_Outputs_s_uid",NULL,TRUE);
	bRet &= SigMgr_Data_THA_Calibration_data_MPU1_0_t_Init("Data_THA_Calibration_data_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_APA_Calibration_data_MPU1_0_t_Init("Data_APA_Calibration_data_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_LMD_Calibration_data_t_Init("Data_LMD_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Init("Data_TRSC_Calibration_data_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Init("PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Init("Data_TbSVS_e_SVSCalibSMToHmi_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TrailerDetection_Output_HMI_t_Init("Data_TrailerDetection_Output_HMI_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpDLDOutput_JobDLDOutput_t_Init("PpDLDOutput_JobDLDOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Init("PpKeepAliveResponse_KeepAliveResponse_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Init("PpErrFltMpu1_0_Error_Fault_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSC_CalibrationClear_t_Init("Data_TRSC_CalibrationClear_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_PerformanceStatsEnable_t_Init("Data_PerformanceStatsEnable_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Init("PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CamHotplugStatus_t_Init("Data_CamHotplugStatus_t_uid",NULL,TRUE);

	if((bRet != FALSE))
		{SigDef_Init_state=TRUE;}

	return bRet;
}

#ifdef __cplusplus
}
#endif
static bool_t SigDef_GetInitState()
{
	return SigDef_Init_state;
}


#endif



#ifdef BUILD_MCU1_0

// *********************************************************************
// ****************** Start SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************
static SignalMgr_ProtectedData<SvsToVCAN_t> SigMgr_PpSvsToVCAN_SvsToVCAN_t;
static bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Init(const char *uid_name,const SvsToVCAN_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(SvsToVCAN_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(SvsToVCAN_t *data)
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToVCAN_t * SigMgr_PpSvsToVCAN_SvsToVCAN_t_GetDataObjRef()
{
	return SigMgr_PpSvsToVCAN_SvsToVCAN_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Lock()
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_UnLock()
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVStoTRSC_t> SigMgr_PpSVStoTRSC_SVStoTRSC_t;
static bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_Init(const char *uid_name,const SVStoTRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVStoTRSC_SVStoTRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put(SVStoTRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVStoTRSC_SVStoTRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Get(SVStoTRSC_t *data)
{
	SigMgr_PpSVStoTRSC_SVStoTRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSC_t * SigMgr_PpSVStoTRSC_SVStoTRSC_t_GetDataObjRef()
{
	return SigMgr_PpSVStoTRSC_SVStoTRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Lock()
{
	SigMgr_PpSVStoTRSC_SVStoTRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_UnLock()
{
	SigMgr_PpSVStoTRSC_SVStoTRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************
static SignalMgr_ProtectedData<ScreenRequest_t> SigMgr_PpScreenRequest_ScreenRequest_t;
static bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Init(const char *uid_name,const ScreenRequest_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data)
{
	SigMgr_PpScreenRequest_ScreenRequest_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef()
{
	return SigMgr_PpScreenRequest_ScreenRequest_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************
static SignalMgr_ProtectedData<SvsToTHA_t> SigMgr_PpSvsToTHA_SvsToTHA_t;
static bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Init(const char *uid_name,const SvsToTHA_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Put(SvsToTHA_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Get(SvsToTHA_t *data)
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHA_t * SigMgr_PpSvsToTHA_SvsToTHA_t_GetDataObjRef()
{
	return SigMgr_PpSvsToTHA_SvsToTHA_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Lock()
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_UnLock()
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************
static SignalMgr_ProtectedData<ScreenResponse_t> SigMgr_PpScreenResponse_ScreenResponse_t;
static bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Init(const char *uid_name,const ScreenResponse_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenResponse_ScreenResponse_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Put(ScreenResponse_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenResponse_ScreenResponse_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Get(ScreenResponse_t *data)
{
	SigMgr_PpScreenResponse_ScreenResponse_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenResponse_t * SigMgr_PpScreenResponse_ScreenResponse_t_GetDataObjRef()
{
	return SigMgr_PpScreenResponse_ScreenResponse_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Lock()
{
	SigMgr_PpScreenResponse_ScreenResponse_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_UnLock()
{
	SigMgr_PpScreenResponse_ScreenResponse_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_VehInp_to_IpcSignals_t,2> SigMgr_ME_VehInp_to_IpcSignals_data_f;
static bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Init(const char *uid_name,const ME_VehInp_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data)
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef()
{
	return SigMgr_ME_VehInp_to_IpcSignals_data_f.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const))
{
	bool_t bRet;
	bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************
static SignalMgr_ProtectedData<ErrorMgr_ErrorCommPack_2_0_QM> SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM;
static bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_0_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put(ErrorMgr_ErrorCommPack_2_0_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(ErrorMgr_ErrorCommPack_2_0_QM *data)
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_QM * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_GetDataObjRef()
{
	return SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Lock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_UnLock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************
static SignalMgr_ProtectedData<ErrorMgr_ErrorCommPack_2_0_B> SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B;
static bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_0_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put(ErrorMgr_ErrorCommPack_2_0_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(ErrorMgr_ErrorCommPack_2_0_B *data)
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_B * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_GetDataObjRef()
{
	return SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Lock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_UnLock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************
static SignalMgr_ProtectedData<ErrorMgr_ErrorCommPack_2_1_QM> SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM;
static bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_1_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put(ErrorMgr_ErrorCommPack_2_1_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(ErrorMgr_ErrorCommPack_2_1_QM *data)
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_QM * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_GetDataObjRef()
{
	return SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Lock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_UnLock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************
static SignalMgr_ProtectedData<ErrorMgr_ErrorCommPack_2_1_B> SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B;
static bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_1_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put(ErrorMgr_ErrorCommPack_2_1_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(ErrorMgr_ErrorCommPack_2_1_B *data)
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_B * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_GetDataObjRef()
{
	return SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Lock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_UnLock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************
static SignalMgr_ProtectedData<ErrorMgr_ErrorCommPack_QNX_QM> SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM;
static bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_QNX_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put(ErrorMgr_ErrorCommPack_QNX_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(ErrorMgr_ErrorCommPack_QNX_QM *data)
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_QM * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_GetDataObjRef()
{
	return SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Lock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_UnLock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************
static SignalMgr_ProtectedData<ErrorMgr_ErrorCommPack_QNX_B> SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B;
static bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_QNX_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put(ErrorMgr_ErrorCommPack_QNX_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(ErrorMgr_ErrorCommPack_QNX_B *data)
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_B * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_GetDataObjRef()
{
	return SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Lock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_UnLock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSC_Inputs_from_TrailerDetection_t> SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t;
static bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init(const char *uid_name,const TRSC_Inputs_from_TrailerDetection_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data)
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef()
{
	return SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_VehOut_TRSC_t> SigMgr_PpTRSC_ME_VehOut_TRSC_t;
static bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_Init(const char *uid_name,const ME_VehOut_TRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTRSC_ME_VehOut_TRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(ME_VehOut_TRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTRSC_ME_VehOut_TRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(ME_VehOut_TRSC_t *data)
{
	SigMgr_PpTRSC_ME_VehOut_TRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehOut_TRSC_t * SigMgr_PpTRSC_ME_VehOut_TRSC_t_GetDataObjRef()
{
	return SigMgr_PpTRSC_ME_VehOut_TRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Lock()
{
	SigMgr_PpTRSC_ME_VehOut_TRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_UnLock()
{
	SigMgr_PpTRSC_ME_VehOut_TRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSCSMVCtoSVS_t> SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t;
static bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Init(const char *uid_name,const TRSCSMVCtoSVS_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(TRSCSMVCtoSVS_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(TRSCSMVCtoSVS_t *data)
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoSVS_t * SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_GetDataObjRef()
{
	return SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Lock()
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_UnLock()
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData<Detection_Inputs_from_TRSC_t> SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t;
static bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Init(const char *uid_name,const Detection_Inputs_from_TRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(Detection_Inputs_from_TRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(Detection_Inputs_from_TRSC_t *data)
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Detection_Inputs_from_TRSC_t * SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_GetDataObjRef()
{
	return SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Lock()
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_UnLock()
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_2_0_CoreStatus> SigMgr_PpSR_State_MCU2_State_2_0;
static bool_t SigMgr_PpSR_State_MCU2_State_2_0_Init(const char *uid_name,const SSM_2_0_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_0.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_0.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_2_1_CoreStatus> SigMgr_PpSR_State_MCU2_State_2_1;
static bool_t SigMgr_PpSR_State_MCU2_State_2_1_Init(const char *uid_name,const SSM_2_1_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_1.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_1.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_QNX_CoreStatus> SigMgr_PpSR_State_QNX_State_QNX;
static bool_t SigMgr_PpSR_State_QNX_State_QNX_Init(const char *uid_name,const SSM_QNX_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data)
{
	SigMgr_PpSR_State_QNX_State_QNX.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef()
{
	return SigMgr_PpSR_State_QNX_State_QNX.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock()
{
	SigMgr_PpSR_State_QNX_State_QNX.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock()
{
	SigMgr_PpSR_State_QNX_State_QNX.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SSM_SystemState,1> SigMgr_Data_SSM_SystemState;
static bool_t SigMgr_Data_SSM_SystemState_Init(const char *uid_name,const SSM_SystemState *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data)
{
	SigMgr_Data_SSM_SystemState.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState * SigMgr_Data_SSM_SystemState_GetDataObjRef()
{
	return SigMgr_Data_SSM_SystemState.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock()
{
	SigMgr_Data_SSM_SystemState.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock()
{
	SigMgr_Data_SSM_SystemState.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_RegisterCallback(void (*Callback)(const SSM_SystemState * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_SSM_SystemState.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CalDataProvider_MPU_1_0_Def,1> SigMgr_Data_CalDataProvider_MPU_1_0_Def;
static bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_Init(const char *uid_name,const CalDataProvider_MPU_1_0_Def *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CalDataProvider_MPU_1_0_Def.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put(CalDataProvider_MPU_1_0_Def *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CalDataProvider_MPU_1_0_Def.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Get(CalDataProvider_MPU_1_0_Def *data)
{
	SigMgr_Data_CalDataProvider_MPU_1_0_Def.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MPU_1_0_Def * SigMgr_Data_CalDataProvider_MPU_1_0_Def_GetDataObjRef()
{
	return SigMgr_Data_CalDataProvider_MPU_1_0_Def.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Lock()
{
	SigMgr_Data_CalDataProvider_MPU_1_0_Def.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_UnLock()
{
	SigMgr_Data_CalDataProvider_MPU_1_0_Def.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_RegisterCallback(void (*Callback)(const CalDataProvider_MPU_1_0_Def * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_CalDataProvider_MPU_1_0_Def.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CalDataProvider_MCU_2_0_Def,1> SigMgr_Data_CalDataProvider_MCU_2_0_Def;
static bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_Init(const char *uid_name,const CalDataProvider_MCU_2_0_Def *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_0_Def.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put(CalDataProvider_MCU_2_0_Def *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_0_Def.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get(CalDataProvider_MCU_2_0_Def *data)
{
	SigMgr_Data_CalDataProvider_MCU_2_0_Def.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_0_Def * SigMgr_Data_CalDataProvider_MCU_2_0_Def_GetDataObjRef()
{
	return SigMgr_Data_CalDataProvider_MCU_2_0_Def.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Lock()
{
	SigMgr_Data_CalDataProvider_MCU_2_0_Def.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_UnLock()
{
	SigMgr_Data_CalDataProvider_MCU_2_0_Def.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_RegisterCallback(void (*Callback)(const CalDataProvider_MCU_2_0_Def * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_CalDataProvider_MCU_2_0_Def.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CalDataProvider_MCU_2_1_Def,1> SigMgr_Data_CalDataProvider_MCU_2_1_Def;
static bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_Init(const char *uid_name,const CalDataProvider_MCU_2_1_Def *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_1_Def.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put(CalDataProvider_MCU_2_1_Def *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_1_Def.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(CalDataProvider_MCU_2_1_Def *data)
{
	SigMgr_Data_CalDataProvider_MCU_2_1_Def.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_1_Def * SigMgr_Data_CalDataProvider_MCU_2_1_Def_GetDataObjRef()
{
	return SigMgr_Data_CalDataProvider_MCU_2_1_Def.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Lock()
{
	SigMgr_Data_CalDataProvider_MCU_2_1_Def.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_UnLock()
{
	SigMgr_Data_CalDataProvider_MCU_2_1_Def.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_RegisterCallback(void (*Callback)(const CalDataProvider_MCU_2_1_Def * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_CalDataProvider_MCU_2_1_Def.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_S_SVSCamCurrentCalibDataToNVM_t> SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamCurrentCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Get(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamCurrentCalibDataToNVM_t * SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_S_SVSCamOCCalibDataToNVM_t> SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamOCCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put(TbSVS_S_SVSCamOCCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Get(TbSVS_S_SVSCamOCCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamOCCalibDataToNVM_t * SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_S_SVSCamSCCalibDataToNVM_t> SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamSCCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put(TbSVS_S_SVSCamSCCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Get(TbSVS_S_SVSCamSCCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamSCCalibDataToNVM_t * SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_S_SVSCamEOLCalibDataToNVM_t> SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t;
static bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Init(const char *uid_name,const TbSVS_S_SVSCamEOLCalibDataToNVM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Get(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data)
{
	SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamEOLCalibDataToNVM_t * SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_GetDataObjRef()
{
	return SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Lock()
{
	SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_UnLock()
{
	SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_e_SVSOutputToDiagMgrCamCalib_t> SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t;
static bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Init(const char *uid_name,const TbSVS_e_SVSOutputToDiagMgrCamCalib_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Get(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data)
{
	SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSOutputToDiagMgrCamCalib_t * SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_GetDataObjRef()
{
	return SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Lock()
{
	SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_UnLock()
{
	SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t,1> SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;
static bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Init(const char *uid_name,const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Get(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data)
{
	SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t * SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Lock()
{
	SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_UnLock()
{
	SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_RegisterCallback(void (*Callback)(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t,1> SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;
static bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Init(const char *uid_name,const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Get(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data)
{
	SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t * SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Lock()
{
	SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_UnLock()
{
	SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_RegisterCallback(void (*Callback)(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_Proxi_to_IpcSignals_t,1> SigMgr_Data_ME_Proxi_to_IpcSignals_t;
static bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Init(const char *uid_name,const ME_Proxi_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(ME_Proxi_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(ME_Proxi_to_IpcSignals_t *data)
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_to_IpcSignals_t * SigMgr_Data_ME_Proxi_to_IpcSignals_t_GetDataObjRef()
{
	return SigMgr_Data_ME_Proxi_to_IpcSignals_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Lock()
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_UnLock()
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_RegisterCallback(void (*Callback)(const ME_Proxi_to_IpcSignals_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<JobTHADetOutput_t> SigMgr_PpJobTHADetOutput_JobTHADetOutput_t;
static bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init(const char *uid_name,const JobTHADetOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data)
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_APSMPAOut_t> SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t;
static bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Init(const char *uid_name,const TbAP_APSMPAOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(TbAP_APSMPAOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(TbAP_APSMPAOut_t *data)
{
	SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_APSMPAOut_t * SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_GetDataObjRef()
{
	return SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Lock()
{
	SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_UnLock()
{
	SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbTHASmVc_FeatureOutputs_t> SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t;
static bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init(const char *uid_name,const TbTHASmVc_FeatureOutputs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data)
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef()
{
	return SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<IJobPLDOutput_t> SigMgr_PpJobPLDData_IJobPLDOutput_t;
static bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Init(const char *uid_name,const IJobPLDOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(IJobPLDOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(IJobPLDOutput_t *data)
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobPLDOutput_t * SigMgr_PpJobPLDData_IJobPLDOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobPLDData_IJobPLDOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Lock()
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_UnLock()
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IKinematicData_t,1> SigMgr_Data_IKinematicData_t;
static bool_t SigMgr_Data_IKinematicData_t_Init(const char *uid_name,const IKinematicData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data)
{
	SigMgr_Data_IKinematicData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t * SigMgr_Data_IKinematicData_t_GetDataObjRef()
{
	return SigMgr_Data_IKinematicData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock()
{
	SigMgr_Data_IKinematicData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock()
{
	SigMgr_Data_IKinematicData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_RegisterCallback(void (*Callback)(const IKinematicData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_IKinematicData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ExtY_Kinematic_T,1> SigMgr_Data_ExtY_Kinematic_T;
static bool_t SigMgr_Data_ExtY_Kinematic_T_Init(const char *uid_name,const ExtY_Kinematic_T *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ExtY_Kinematic_T.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_Put(ExtY_Kinematic_T *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ExtY_Kinematic_T.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Get(ExtY_Kinematic_T *data)
{
	SigMgr_Data_ExtY_Kinematic_T.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ExtY_Kinematic_T * SigMgr_Data_ExtY_Kinematic_T_GetDataObjRef()
{
	return SigMgr_Data_ExtY_Kinematic_T.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Lock()
{
	SigMgr_Data_ExtY_Kinematic_T.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_UnLock()
{
	SigMgr_Data_ExtY_Kinematic_T.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_RegisterCallback(void (*Callback)(const ExtY_Kinematic_T * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ExtY_Kinematic_T.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<IJobFPAOutput_t> SigMgr_PpJobFPAData_IJobFPAOutput_t;
static bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Init(const char *uid_name,const IJobFPAOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(IJobFPAOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(IJobFPAOutput_t *data)
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobFPAOutput_t * SigMgr_PpJobFPAData_IJobFPAOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobFPAData_IJobFPAOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Lock()
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_UnLock()
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************
static SignalMgr_ProtectedData<NFCD_Output> SigMgr_PpNFCDOutput_NFCD_Output;
static bool_t SigMgr_PpNFCDOutput_NFCD_Output_Init(const char *uid_name,const NFCD_Output *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpNFCDOutput_NFCD_Output.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpNFCDOutput_NFCD_Output_Put(NFCD_Output *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpNFCDOutput_NFCD_Output.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Get(NFCD_Output *data)
{
	SigMgr_PpNFCDOutput_NFCD_Output.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
NFCD_Output * SigMgr_PpNFCDOutput_NFCD_Output_GetDataObjRef()
{
	return SigMgr_PpNFCDOutput_NFCD_Output.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Lock()
{
	SigMgr_PpNFCDOutput_NFCD_Output.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_UnLock()
{
	SigMgr_PpNFCDOutput_NFCD_Output.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_DriveAssistStatOut_t> SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t;
static bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Init(const char *uid_name,const TbAP_DriveAssistStatOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(TbAP_DriveAssistStatOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(TbAP_DriveAssistStatOut_t *data)
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DriveAssistStatOut_t * SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_GetDataObjRef()
{
	return SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Lock()
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_UnLock()
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_SMDAInternalOut_t> SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t;
static bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Init(const char *uid_name,const TbAP_SMDAInternalOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(TbAP_SMDAInternalOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(TbAP_SMDAInternalOut_t *data)
{
	SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMDAInternalOut_t * SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_GetDataObjRef()
{
	return SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Lock()
{
	SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_UnLock()
{
	SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_SMPAInternalOut_t> SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t;
static bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Init(const char *uid_name,const TbAP_SMPAInternalOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(TbAP_SMPAInternalOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(TbAP_SMPAInternalOut_t *data)
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMPAInternalOut_t * SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_GetDataObjRef()
{
	return SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Lock()
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_UnLock()
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_FPAWarnOut_t> SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t;
static bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Init(const char *uid_name,const TbAP_FPAWarnOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(TbAP_FPAWarnOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(TbAP_FPAWarnOut_t *data)
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_FPAWarnOut_t * SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_GetDataObjRef()
{
	return SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Lock()
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_UnLock()
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_RPAWarnOut_t> SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t;
static bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Init(const char *uid_name,const TbAP_RPAWarnOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(TbAP_RPAWarnOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(TbAP_RPAWarnOut_t *data)
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_RPAWarnOut_t * SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_GetDataObjRef()
{
	return SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Lock()
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_UnLock()
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_PAStateOut_t> SigMgr_PpPAStateOut_TbAP_PAStateOut_t;
static bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Init(const char *uid_name,const TbAP_PAStateOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpPAStateOut_TbAP_PAStateOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(TbAP_PAStateOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpPAStateOut_TbAP_PAStateOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(TbAP_PAStateOut_t *data)
{
	SigMgr_PpPAStateOut_TbAP_PAStateOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_PAStateOut_t * SigMgr_PpPAStateOut_TbAP_PAStateOut_t_GetDataObjRef()
{
	return SigMgr_PpPAStateOut_TbAP_PAStateOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Lock()
{
	SigMgr_PpPAStateOut_TbAP_PAStateOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_UnLock()
{
	SigMgr_PpPAStateOut_TbAP_PAStateOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_VCActuatorOut_t> SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t;
static bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Init(const char *uid_name,const TbAP_VCActuatorOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(TbAP_VCActuatorOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Get(TbAP_VCActuatorOut_t *data)
{
	SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCActuatorOut_t * SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_GetDataObjRef()
{
	return SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Lock()
{
	SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_UnLock()
{
	SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_VCStateOut_t> SigMgr_PpVCState_TbAP_VCStateOut_t;
static bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_Init(const char *uid_name,const TbAP_VCStateOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpVCState_TbAP_VCStateOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_Put(TbAP_VCStateOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpVCState_TbAP_VCStateOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Get(TbAP_VCStateOut_t *data)
{
	SigMgr_PpVCState_TbAP_VCStateOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCStateOut_t * SigMgr_PpVCState_TbAP_VCStateOut_t_GetDataObjRef()
{
	return SigMgr_PpVCState_TbAP_VCStateOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Lock()
{
	SigMgr_PpVCState_TbAP_VCStateOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_UnLock()
{
	SigMgr_PpVCState_TbAP_VCStateOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<FID_STRUCT_QM,1> SigMgr_Data_FID_STRUCT_QM;
static bool_t SigMgr_Data_FID_STRUCT_QM_Init(const char *uid_name,const FID_STRUCT_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data)
{
	SigMgr_Data_FID_STRUCT_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock()
{
	SigMgr_Data_FID_STRUCT_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock()
{
	SigMgr_Data_FID_STRUCT_QM.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_RegisterCallback(void (*Callback)(const FID_STRUCT_QM * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_FID_STRUCT_QM.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<FID_STRUCT_B,1> SigMgr_Data_FID_STRUCT_B;
static bool_t SigMgr_Data_FID_STRUCT_B_Init(const char *uid_name,const FID_STRUCT_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data)
{
	SigMgr_Data_FID_STRUCT_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B * SigMgr_Data_FID_STRUCT_B_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock()
{
	SigMgr_Data_FID_STRUCT_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock()
{
	SigMgr_Data_FID_STRUCT_B.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_RegisterCallback(void (*Callback)(const FID_STRUCT_B * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_FID_STRUCT_B.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_PointMapGroup_t> SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t;
static bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Init(const char *uid_name,const US_S_PointMapGroup_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put(US_S_PointMapGroup_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(US_S_PointMapGroup_t *data)
{
	SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointMapGroup_t * SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_GetDataObjRef()
{
	return SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Lock()
{
	SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_UnLock()
{
	SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_SnrDirEcho_t> SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t;
static bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Init(const char *uid_name,const US_S_SnrDirEcho_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put(US_S_SnrDirEcho_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Get(US_S_SnrDirEcho_t *data)
{
	SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_SnrDirEcho_t * SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_GetDataObjRef()
{
	return SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Lock()
{
	SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_UnLock()
{
	SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_ZoneInfo_t> SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t;
static bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Init(const char *uid_name,const US_S_ZoneInfo_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put(US_S_ZoneInfo_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Get(US_S_ZoneInfo_t *data)
{
	SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_ZoneInfo_t * SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_GetDataObjRef()
{
	return SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Lock()
{
	SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_UnLock()
{
	SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_BlockageBit_t> SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t;
static bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Init(const char *uid_name,const US_S_BlockageBit_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(US_S_BlockageBit_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(US_S_BlockageBit_t *data)
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_BlockageBit_t * SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_GetDataObjRef()
{
	return SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Lock()
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_UnLock()
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_USSConstantData_t> SigMgr_PpUSSConstantData_US_S_USSConstantData_t;
static bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Init(const char *uid_name,const US_S_USSConstantData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSConstantData_US_S_USSConstantData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put(US_S_USSConstantData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSConstantData_US_S_USSConstantData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Get(US_S_USSConstantData_t *data)
{
	SigMgr_PpUSSConstantData_US_S_USSConstantData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSConstantData_t * SigMgr_PpUSSConstantData_US_S_USSConstantData_t_GetDataObjRef()
{
	return SigMgr_PpUSSConstantData_US_S_USSConstantData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Lock()
{
	SigMgr_PpUSSConstantData_US_S_USSConstantData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_UnLock()
{
	SigMgr_PpUSSConstantData_US_S_USSConstantData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_USSPeriodDiagData_t> SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t;
static bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Init(const char *uid_name,const US_S_USSPeriodDiagData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put(US_S_USSPeriodDiagData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Get(US_S_USSPeriodDiagData_t *data)
{
	SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSPeriodDiagData_t * SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_GetDataObjRef()
{
	return SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Lock()
{
	SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_UnLock()
{
	SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_USSErrorDiagData_t> SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t;
static bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Init(const char *uid_name,const US_S_USSErrorDiagData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(US_S_USSErrorDiagData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(US_S_USSErrorDiagData_t *data)
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSErrorDiagData_t * SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_GetDataObjRef()
{
	return SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Lock()
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_UnLock()
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<USS_Curr_Volt_Monitor_t,2> SigMgr_Data_USS_Curr_Volt_Monitor_t;
static bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_Init(const char *uid_name,const USS_Curr_Volt_Monitor_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_Curr_Volt_Monitor_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_Put(USS_Curr_Volt_Monitor_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_Curr_Volt_Monitor_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Get(USS_Curr_Volt_Monitor_t *data)
{
	SigMgr_Data_USS_Curr_Volt_Monitor_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Curr_Volt_Monitor_t * SigMgr_Data_USS_Curr_Volt_Monitor_t_GetDataObjRef()
{
	return SigMgr_Data_USS_Curr_Volt_Monitor_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Lock()
{
	SigMgr_Data_USS_Curr_Volt_Monitor_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_UnLock()
{
	SigMgr_Data_USS_Curr_Volt_Monitor_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_RegisterCallback(void (*Callback)(const USS_Curr_Volt_Monitor_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_USS_Curr_Volt_Monitor_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************
static SignalMgr_ProtectedData<Svs_CamEepromDataArray_t> SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t;
static bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Init(const char *uid_name,const Svs_CamEepromDataArray_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put(Svs_CamEepromDataArray_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Get(Svs_CamEepromDataArray_t *data)
{
	SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Svs_CamEepromDataArray_t * SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_GetDataObjRef()
{
	return SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Lock()
{
	SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_UnLock()
{
	SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<DiagToSVS_t,1> SigMgr_Data_DiagToSVS_t;
static bool_t SigMgr_Data_DiagToSVS_t_Init(const char *uid_name,const DiagToSVS_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_DiagToSVS_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToSVS_t_Put(DiagToSVS_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_DiagToSVS_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Get(DiagToSVS_t *data)
{
	SigMgr_Data_DiagToSVS_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToSVS_t * SigMgr_Data_DiagToSVS_t_GetDataObjRef()
{
	return SigMgr_Data_DiagToSVS_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Lock()
{
	SigMgr_Data_DiagToSVS_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_UnLock()
{
	SigMgr_Data_DiagToSVS_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToSVS_t_RegisterCallback(void (*Callback)(const DiagToSVS_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_DiagToSVS_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVSToDiag_t> SigMgr_PpSVSToDiag_SVSToDiag_t;
static bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_Init(const char *uid_name,const SVSToDiag_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSToDiag_SVSToDiag_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_Put(SVSToDiag_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSToDiag_SVSToDiag_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Get(SVSToDiag_t *data)
{
	SigMgr_PpSVSToDiag_SVSToDiag_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVSToDiag_t * SigMgr_PpSVSToDiag_SVSToDiag_t_GetDataObjRef()
{
	return SigMgr_PpSVSToDiag_SVSToDiag_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Lock()
{
	SigMgr_PpSVSToDiag_SVSToDiag_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_UnLock()
{
	SigMgr_PpSVSToDiag_SVSToDiag_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************
static SignalMgr_ProtectedData<IFOD_Outputs_CVPAMFDData_t> SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t;
static bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Init(const char *uid_name,const IFOD_Outputs_CVPAMFDData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(IFOD_Outputs_CVPAMFDData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Get(IFOD_Outputs_CVPAMFDData_t *data)
{
	SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_CVPAMFDData_t * SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_GetDataObjRef()
{
	return SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Lock()
{
	SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_UnLock()
{
	SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************
static SignalMgr_ProtectedData<LMD_Outputs_CVPAMFDData2_t> SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t;
static bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Init(const char *uid_name,const LMD_Outputs_CVPAMFDData2_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put(LMD_Outputs_CVPAMFDData2_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Get(LMD_Outputs_CVPAMFDData2_t *data)
{
	SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Outputs_CVPAMFDData2_t * SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_GetDataObjRef()
{
	return SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Lock()
{
	SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_UnLock()
{
	SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CAM_Curr_Volt_Monitor_t,1> SigMgr_Data_CAM_Curr_Volt_Monitor_t;
static bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_Init(const char *uid_name,const CAM_Curr_Volt_Monitor_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CAM_Curr_Volt_Monitor_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put(CAM_Curr_Volt_Monitor_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CAM_Curr_Volt_Monitor_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(CAM_Curr_Volt_Monitor_t *data)
{
	SigMgr_Data_CAM_Curr_Volt_Monitor_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_Curr_Volt_Monitor_t * SigMgr_Data_CAM_Curr_Volt_Monitor_t_GetDataObjRef()
{
	return SigMgr_Data_CAM_Curr_Volt_Monitor_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Lock()
{
	SigMgr_Data_CAM_Curr_Volt_Monitor_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_UnLock()
{
	SigMgr_Data_CAM_Curr_Volt_Monitor_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_RegisterCallback(void (*Callback)(const CAM_Curr_Volt_Monitor_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_CAM_Curr_Volt_Monitor_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************
static SignalMgr_ProtectedData<CAM_CS_Curr_Monitor_t> SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t;
static bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Init(const char *uid_name,const CAM_CS_Curr_Monitor_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(CAM_CS_Curr_Monitor_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Get(CAM_CS_Curr_Monitor_t *data)
{
	SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_CS_Curr_Monitor_t * SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_GetDataObjRef()
{
	return SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Lock()
{
	SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_UnLock()
{
	SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_MarriageSensorIDs_t> SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t;
static bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Init(const char *uid_name,const US_S_MarriageSensorIDs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data)
{
	SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t * SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_GetDataObjRef()
{
	return SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Lock()
{
	SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_UnLock()
{
	SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_MarriageSensorIDs_t,2> SigMgr_Data_US_S_MarriageSensorIDs_t;
static bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_Init(const char *uid_name,const US_S_MarriageSensorIDs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_US_S_MarriageSensorIDs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_US_S_MarriageSensorIDs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data)
{
	SigMgr_Data_US_S_MarriageSensorIDs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t * SigMgr_Data_US_S_MarriageSensorIDs_t_GetDataObjRef()
{
	return SigMgr_Data_US_S_MarriageSensorIDs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Lock()
{
	SigMgr_Data_US_S_MarriageSensorIDs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_UnLock()
{
	SigMgr_Data_US_S_MarriageSensorIDs_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_RegisterCallback(void (*Callback)(const US_S_MarriageSensorIDs_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_US_S_MarriageSensorIDs_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSCtoDiagMgr_t> SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t;
static bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Init(const char *uid_name,const TRSCtoDiagMgr_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(TRSCtoDiagMgr_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Get(TRSCtoDiagMgr_t *data)
{
	SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCtoDiagMgr_t * SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_GetDataObjRef()
{
	return SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Lock()
{
	SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_UnLock()
{
	SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************
static SignalMgr_ProtectedData<TrailerDetection_Output_DID_t> SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t;
static bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Init(const char *uid_name,const TrailerDetection_Output_DID_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put(TrailerDetection_Output_DID_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Get(TrailerDetection_Output_DID_t *data)
{
	SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_DID_t * SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_GetDataObjRef()
{
	return SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Lock()
{
	SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_UnLock()
{
	SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<DiagToParkAssist_t,1> SigMgr_Data_DiagToParkAssist_t;
static bool_t SigMgr_Data_DiagToParkAssist_t_Init(const char *uid_name,const DiagToParkAssist_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_DiagToParkAssist_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToParkAssist_t_Put(DiagToParkAssist_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_DiagToParkAssist_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Get(DiagToParkAssist_t *data)
{
	SigMgr_Data_DiagToParkAssist_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToParkAssist_t * SigMgr_Data_DiagToParkAssist_t_GetDataObjRef()
{
	return SigMgr_Data_DiagToParkAssist_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Lock()
{
	SigMgr_Data_DiagToParkAssist_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_UnLock()
{
	SigMgr_Data_DiagToParkAssist_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToParkAssist_t_RegisterCallback(void (*Callback)(const DiagToParkAssist_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_DiagToParkAssist_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_ProxiToMPU1_0_Def_t,1> SigMgr_Data_ME_ProxiToMPU1_0_Def_t;
static bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Init(const char *uid_name,const ME_ProxiToMPU1_0_Def_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_ProxiToMPU1_0_Def_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put(ME_ProxiToMPU1_0_Def_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_ProxiToMPU1_0_Def_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Get(ME_ProxiToMPU1_0_Def_t *data)
{
	SigMgr_Data_ME_ProxiToMPU1_0_Def_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMPU1_0_Def_t * SigMgr_Data_ME_ProxiToMPU1_0_Def_t_GetDataObjRef()
{
	return SigMgr_Data_ME_ProxiToMPU1_0_Def_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Lock()
{
	SigMgr_Data_ME_ProxiToMPU1_0_Def_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_UnLock()
{
	SigMgr_Data_ME_ProxiToMPU1_0_Def_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_RegisterCallback(void (*Callback)(const ME_ProxiToMPU1_0_Def_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ME_ProxiToMPU1_0_Def_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_ProxiToMCU2_0_Def_t,1> SigMgr_Data_ME_ProxiToMCU2_0_Def_t;
static bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Init(const char *uid_name,const ME_ProxiToMCU2_0_Def_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_0_Def_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put(ME_ProxiToMCU2_0_Def_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_0_Def_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data)
{
	SigMgr_Data_ME_ProxiToMCU2_0_Def_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_0_Def_t * SigMgr_Data_ME_ProxiToMCU2_0_Def_t_GetDataObjRef()
{
	return SigMgr_Data_ME_ProxiToMCU2_0_Def_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Lock()
{
	SigMgr_Data_ME_ProxiToMCU2_0_Def_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_UnLock()
{
	SigMgr_Data_ME_ProxiToMCU2_0_Def_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_RegisterCallback(void (*Callback)(const ME_ProxiToMCU2_0_Def_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ME_ProxiToMCU2_0_Def_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_ProxiToMCU2_1_Def_t,1> SigMgr_Data_ME_ProxiToMCU2_1_Def_t;
static bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Init(const char *uid_name,const ME_ProxiToMCU2_1_Def_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_1_Def_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put(ME_ProxiToMCU2_1_Def_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_1_Def_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(ME_ProxiToMCU2_1_Def_t *data)
{
	SigMgr_Data_ME_ProxiToMCU2_1_Def_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_1_Def_t * SigMgr_Data_ME_ProxiToMCU2_1_Def_t_GetDataObjRef()
{
	return SigMgr_Data_ME_ProxiToMCU2_1_Def_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Lock()
{
	SigMgr_Data_ME_ProxiToMCU2_1_Def_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_UnLock()
{
	SigMgr_Data_ME_ProxiToMCU2_1_Def_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_RegisterCallback(void (*Callback)(const ME_ProxiToMCU2_1_Def_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ME_ProxiToMCU2_1_Def_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_USSDataCollectionData_t> SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t;
static bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Init(const char *uid_name,const US_S_USSDataCollectionData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put(US_S_USSDataCollectionData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Get(US_S_USSDataCollectionData_t *data)
{
	SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSDataCollectionData_t * SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_GetDataObjRef()
{
	return SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Lock()
{
	SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_UnLock()
{
	SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_PointDistOutputBuff_t> SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t;
static bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Init(const char *uid_name,const US_S_PointDistOutputBuff_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put(US_S_PointDistOutputBuff_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Get(US_S_PointDistOutputBuff_t *data)
{
	SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointDistOutputBuff_t * SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_GetDataObjRef()
{
	return SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Lock()
{
	SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_UnLock()
{
	SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<CpuLoadMcu2_1_t> SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t;
static bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Init(const char *uid_name,const CpuLoadMcu2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(CpuLoadMcu2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Get(CpuLoadMcu2_1_t *data)
{
	SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_1_t * SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_GetDataObjRef()
{
	return SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Lock()
{
	SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_UnLock()
{
	SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<CpuLoadMcu2_0_t> SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t;
static bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Init(const char *uid_name,const CpuLoadMcu2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(CpuLoadMcu2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Get(CpuLoadMcu2_0_t *data)
{
	SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_0_t * SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_GetDataObjRef()
{
	return SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Lock()
{
	SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_UnLock()
{
	SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbNVM_ReadParam,1> SigMgr_Data_TbNVM_ReadParam;
static bool_t SigMgr_Data_TbNVM_ReadParam_Init(const char *uid_name,const TbNVM_ReadParam *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbNVM_ReadParam.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbNVM_ReadParam_Put(TbNVM_ReadParam *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbNVM_ReadParam.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Get(TbNVM_ReadParam *data)
{
	SigMgr_Data_TbNVM_ReadParam.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbNVM_ReadParam * SigMgr_Data_TbNVM_ReadParam_GetDataObjRef()
{
	return SigMgr_Data_TbNVM_ReadParam.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Lock()
{
	SigMgr_Data_TbNVM_ReadParam.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_UnLock()
{
	SigMgr_Data_TbNVM_ReadParam.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbNVM_ReadParam_RegisterCallback(void (*Callback)(const TbNVM_ReadParam * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TbNVM_ReadParam.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_CanDebugRIDStatus_t,1> SigMgr_Data_ME_CanDebugRIDStatus_t;
static bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Init(const char *uid_name,const ME_CanDebugRIDStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data)
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef()
{
	return SigMgr_Data_ME_CanDebugRIDStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_RegisterCallback(void (*Callback)(const ME_CanDebugRIDStatus_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SVS_NVMData_t,1> SigMgr_Data_SVS_NVMData_t;
static bool_t SigMgr_Data_SVS_NVMData_t_Init(const char *uid_name,const SVS_NVMData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SVS_NVMData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_NVMData_t_Put(SVS_NVMData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SVS_NVMData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Get(SVS_NVMData_t *data)
{
	SigMgr_Data_SVS_NVMData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t * SigMgr_Data_SVS_NVMData_t_GetDataObjRef()
{
	return SigMgr_Data_SVS_NVMData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Lock()
{
	SigMgr_Data_SVS_NVMData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_UnLock()
{
	SigMgr_Data_SVS_NVMData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_NVMData_t_RegisterCallback(void (*Callback)(const SVS_NVMData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_SVS_NVMData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<IJobUSSObjectMapOutput_t> SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t;
static bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Init(const char *uid_name,const IJobUSSObjectMapOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put(IJobUSSObjectMapOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Get(IJobUSSObjectMapOutput_t *data)
{
	SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobUSSObjectMapOutput_t * SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_GetDataObjRef()
{
	return SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Lock()
{
	SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_UnLock()
{
	SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbFA_ArbiterOutput_t> SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t;
static bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Init(const char *uid_name,const TbFA_ArbiterOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(TbFA_ArbiterOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Get(TbFA_ArbiterOutput_t *data)
{
	SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ArbiterOutput_t * SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_GetDataObjRef()
{
	return SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Lock()
{
	SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_UnLock()
{
	SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVS_NVMData_t> SigMgr_PpSVSNVMData_SVS_NVMData_t;
static bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_Init(const char *uid_name,const SVS_NVMData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSNVMData_SVS_NVMData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_Put(SVS_NVMData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSNVMData_SVS_NVMData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Get(SVS_NVMData_t *data)
{
	SigMgr_PpSVSNVMData_SVS_NVMData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t * SigMgr_PpSVSNVMData_SVS_NVMData_t_GetDataObjRef()
{
	return SigMgr_PpSVSNVMData_SVS_NVMData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Lock()
{
	SigMgr_PpSVSNVMData_SVS_NVMData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_UnLock()
{
	SigMgr_PpSVSNVMData_SVS_NVMData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<USS_Calibration_Data_t,1> SigMgr_Data_USS_Calibration_Data_t;
static bool_t SigMgr_Data_USS_Calibration_Data_t_Init(const char *uid_name,const USS_Calibration_Data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_Calibration_Data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_Data_t_Put(USS_Calibration_Data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_Calibration_Data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Get(USS_Calibration_Data_t *data)
{
	SigMgr_Data_USS_Calibration_Data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_Data_t * SigMgr_Data_USS_Calibration_Data_t_GetDataObjRef()
{
	return SigMgr_Data_USS_Calibration_Data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Lock()
{
	SigMgr_Data_USS_Calibration_Data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_UnLock()
{
	SigMgr_Data_USS_Calibration_Data_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_Data_t_RegisterCallback(void (*Callback)(const USS_Calibration_Data_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_USS_Calibration_Data_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_DebugOut> SigMgr_PpTbAPDebugOut_TbAP_DebugOut;
static bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Init(const char *uid_name,const TbAP_DebugOut *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbAPDebugOut_TbAP_DebugOut.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(TbAP_DebugOut *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbAPDebugOut_TbAP_DebugOut.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Get(TbAP_DebugOut *data)
{
	SigMgr_PpTbAPDebugOut_TbAP_DebugOut.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DebugOut * SigMgr_PpTbAPDebugOut_TbAP_DebugOut_GetDataObjRef()
{
	return SigMgr_PpTbAPDebugOut_TbAP_DebugOut.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Lock()
{
	SigMgr_PpTbAPDebugOut_TbAP_DebugOut.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_UnLock()
{
	SigMgr_PpTbAPDebugOut_TbAP_DebugOut.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<WdgCheckpointStatus_t> SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t;
static bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Init(const char *uid_name,const WdgCheckpointStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data)
{
	SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t * SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_GetDataObjRef()
{
	return SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Lock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_UnLock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<WdgCheckpointStatus_t> SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t;
static bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Init(const char *uid_name,const WdgCheckpointStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data)
{
	SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t * SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_GetDataObjRef()
{
	return SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Lock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_UnLock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<WdgCheckpointStatus_t> SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t;
static bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Init(const char *uid_name,const WdgCheckpointStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data)
{
	SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t * SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_GetDataObjRef()
{
	return SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Lock()
{
	SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_UnLock()
{
	SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************
static SignalMgr_ProtectedData<LMD_Lane_Outputs_s> SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s;
static bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Init(const char *uid_name,const LMD_Lane_Outputs_s *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put(LMD_Lane_Outputs_s *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Get(LMD_Lane_Outputs_s *data)
{
	SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Lane_Outputs_s * SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_GetDataObjRef()
{
	return SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Lock()
{
	SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_UnLock()
{
	SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbTHASmVc_DiagMgr_t> SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t;
static bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Init(const char *uid_name,const TbTHASmVc_DiagMgr_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(TbTHASmVc_DiagMgr_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Get(TbTHASmVc_DiagMgr_t *data)
{
	SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_DiagMgr_t * SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_GetDataObjRef()
{
	return SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Lock()
{
	SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_UnLock()
{
	SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<THA_Calibration_data_MCU2_1_t,1> SigMgr_Data_THA_Calibration_data_MCU2_1_t;
static bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_Init(const char *uid_name,const THA_Calibration_data_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put(THA_Calibration_data_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(THA_Calibration_data_MCU2_1_t *data)
{
	SigMgr_Data_THA_Calibration_data_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MCU2_1_t * SigMgr_Data_THA_Calibration_data_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_Data_THA_Calibration_data_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Lock()
{
	SigMgr_Data_THA_Calibration_data_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_UnLock()
{
	SigMgr_Data_THA_Calibration_data_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_RegisterCallback(void (*Callback)(const THA_Calibration_data_MCU2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_THA_Calibration_data_MCU2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<THA_Calibration_data_MPU1_0_t,1> SigMgr_Data_THA_Calibration_data_MPU1_0_t;
static bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_Init(const char *uid_name,const THA_Calibration_data_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put(THA_Calibration_data_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Get(THA_Calibration_data_MPU1_0_t *data)
{
	SigMgr_Data_THA_Calibration_data_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MPU1_0_t * SigMgr_Data_THA_Calibration_data_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_Data_THA_Calibration_data_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Lock()
{
	SigMgr_Data_THA_Calibration_data_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_UnLock()
{
	SigMgr_Data_THA_Calibration_data_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_RegisterCallback(void (*Callback)(const THA_Calibration_data_MPU1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_THA_Calibration_data_MPU1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSC_Calibration_data_MCU2_1_t,1> SigMgr_Data_TRSC_Calibration_data_MCU2_1_t;
static bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Init(const char *uid_name,const TRSC_Calibration_data_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put(TRSC_Calibration_data_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(TRSC_Calibration_data_MCU2_1_t *data)
{
	SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MCU2_1_t * SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Lock()
{
	SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_UnLock()
{
	SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_RegisterCallback(void (*Callback)(const TRSC_Calibration_data_MCU2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<APA_Calibration_data_MPU1_0_t,1> SigMgr_Data_APA_Calibration_data_MPU1_0_t;
static bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_Init(const char *uid_name,const APA_Calibration_data_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put(APA_Calibration_data_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Get(APA_Calibration_data_MPU1_0_t *data)
{
	SigMgr_Data_APA_Calibration_data_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MPU1_0_t * SigMgr_Data_APA_Calibration_data_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_Data_APA_Calibration_data_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Lock()
{
	SigMgr_Data_APA_Calibration_data_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_UnLock()
{
	SigMgr_Data_APA_Calibration_data_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_RegisterCallback(void (*Callback)(const APA_Calibration_data_MPU1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_APA_Calibration_data_MPU1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<APA_Calibration_data_MCU2_1_t,1> SigMgr_Data_APA_Calibration_data_MCU2_1_t;
static bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_Init(const char *uid_name,const APA_Calibration_data_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put(APA_Calibration_data_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(APA_Calibration_data_MCU2_1_t *data)
{
	SigMgr_Data_APA_Calibration_data_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MCU2_1_t * SigMgr_Data_APA_Calibration_data_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_Data_APA_Calibration_data_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Lock()
{
	SigMgr_Data_APA_Calibration_data_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_UnLock()
{
	SigMgr_Data_APA_Calibration_data_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_RegisterCallback(void (*Callback)(const APA_Calibration_data_MCU2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_APA_Calibration_data_MCU2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SVS_Calibration_data_t,1> SigMgr_Data_SVS_Calibration_data_t;
static bool_t SigMgr_Data_SVS_Calibration_data_t_Init(const char *uid_name,const SVS_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SVS_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_Put(SVS_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SVS_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Get(SVS_Calibration_data_t *data)
{
	SigMgr_Data_SVS_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_Calibration_data_t * SigMgr_Data_SVS_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_SVS_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Lock()
{
	SigMgr_Data_SVS_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_UnLock()
{
	SigMgr_Data_SVS_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_RegisterCallback(void (*Callback)(const SVS_Calibration_data_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_SVS_Calibration_data_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<FOD_Calibration_data_t,1> SigMgr_Data_FOD_Calibration_data_t;
static bool_t SigMgr_Data_FOD_Calibration_data_t_Init(const char *uid_name,const FOD_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FOD_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FOD_Calibration_data_t_Put(FOD_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FOD_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Get(FOD_Calibration_data_t *data)
{
	SigMgr_Data_FOD_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FOD_Calibration_data_t * SigMgr_Data_FOD_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_FOD_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Lock()
{
	SigMgr_Data_FOD_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_UnLock()
{
	SigMgr_Data_FOD_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FOD_Calibration_data_t_RegisterCallback(void (*Callback)(const FOD_Calibration_data_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_FOD_Calibration_data_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<LMD_Calibration_data_t,1> SigMgr_Data_LMD_Calibration_data_t;
static bool_t SigMgr_Data_LMD_Calibration_data_t_Init(const char *uid_name,const LMD_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_LMD_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_Put(LMD_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_LMD_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Get(LMD_Calibration_data_t *data)
{
	SigMgr_Data_LMD_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Calibration_data_t * SigMgr_Data_LMD_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_LMD_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Lock()
{
	SigMgr_Data_LMD_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_UnLock()
{
	SigMgr_Data_LMD_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_RegisterCallback(void (*Callback)(const LMD_Calibration_data_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_LMD_Calibration_data_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSC_Calibration_data_MPU1_0_t,1> SigMgr_Data_TRSC_Calibration_data_MPU1_0_t;
static bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Init(const char *uid_name,const TRSC_Calibration_data_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put(TRSC_Calibration_data_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Get(TRSC_Calibration_data_MPU1_0_t *data)
{
	SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MPU1_0_t * SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Lock()
{
	SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_UnLock()
{
	SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_RegisterCallback(void (*Callback)(const TRSC_Calibration_data_MPU1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TRSC_Calibration_data_MPU1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************
static SignalMgr_ProtectedData<IFOD_Outputs_Arbitration_t> SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t;
static bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Init(const char *uid_name,const IFOD_Outputs_Arbitration_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put(IFOD_Outputs_Arbitration_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(IFOD_Outputs_Arbitration_t *data)
{
	SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_Arbitration_t * SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_GetDataObjRef()
{
	return SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Lock()
{
	SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_UnLock()
{
	SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************
static SignalMgr_ProtectedData<IDebug_FODObject_t> SigMgr_PpIDebugFODObject_IDebug_FODObject_t;
static bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Init(const char *uid_name,const IDebug_FODObject_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpIDebugFODObject_IDebug_FODObject_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(IDebug_FODObject_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpIDebugFODObject_IDebug_FODObject_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Get(IDebug_FODObject_t *data)
{
	SigMgr_PpIDebugFODObject_IDebug_FODObject_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IDebug_FODObject_t * SigMgr_PpIDebugFODObject_IDebug_FODObject_t_GetDataObjRef()
{
	return SigMgr_PpIDebugFODObject_IDebug_FODObject_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Lock()
{
	SigMgr_PpIDebugFODObject_IDebug_FODObject_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_UnLock()
{
	SigMgr_PpIDebugFODObject_IDebug_FODObject_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbFA_ResetKM_t> SigMgr_PpTbFAResetKM_TbFA_ResetKM_t;
static bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Init(const char *uid_name,const TbFA_ResetKM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(TbFA_ResetKM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Get(TbFA_ResetKM_t *data)
{
	SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ResetKM_t * SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_GetDataObjRef()
{
	return SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Lock()
{
	SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_UnLock()
{
	SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_Proxi_MPU1_0_to_MCU1_0_t> SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t;
static bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Init(const char *uid_name,const ME_Proxi_MPU1_0_to_MCU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Get(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
{
	SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_MPU1_0_to_MCU1_0_t * SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_GetDataObjRef()
{
	return SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Lock()
{
	SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_UnLock()
{
	SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<USS_Calibration_data_2_t,1> SigMgr_Data_USS_Calibration_data_2_t;
static bool_t SigMgr_Data_USS_Calibration_data_2_t_Init(const char *uid_name,const USS_Calibration_data_2_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_Calibration_data_2_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_data_2_t_Put(USS_Calibration_data_2_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_Calibration_data_2_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Get(USS_Calibration_data_2_t *data)
{
	SigMgr_Data_USS_Calibration_data_2_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_data_2_t * SigMgr_Data_USS_Calibration_data_2_t_GetDataObjRef()
{
	return SigMgr_Data_USS_Calibration_data_2_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Lock()
{
	SigMgr_Data_USS_Calibration_data_2_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_UnLock()
{
	SigMgr_Data_USS_Calibration_data_2_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_data_2_t_RegisterCallback(void (*Callback)(const USS_Calibration_data_2_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_USS_Calibration_data_2_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************
static SignalMgr_ProtectedData<Cam_and_Ser_EN_Status_t> SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t;
static bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Init(const char *uid_name,const Cam_and_Ser_EN_Status_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(Cam_and_Ser_EN_Status_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Get(Cam_and_Ser_EN_Status_t *data)
{
	SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Cam_and_Ser_EN_Status_t * SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_GetDataObjRef()
{
	return SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Lock()
{
	SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_UnLock()
{
	SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<JobDLDOutput_t> SigMgr_PpDLDOutput_JobDLDOutput_t;
static bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_Init(const char *uid_name,const JobDLDOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDLDOutput_JobDLDOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_Put(JobDLDOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDLDOutput_JobDLDOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Get(JobDLDOutput_t *data)
{
	SigMgr_PpDLDOutput_JobDLDOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobDLDOutput_t * SigMgr_PpDLDOutput_JobDLDOutput_t_GetDataObjRef()
{
	return SigMgr_PpDLDOutput_JobDLDOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Lock()
{
	SigMgr_PpDLDOutput_JobDLDOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_UnLock()
{
	SigMgr_PpDLDOutput_JobDLDOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<INVMSignalManager_t,1> SigMgr_Data_INVMSignalManager_t;
static bool_t SigMgr_Data_INVMSignalManager_t_Init(const char *uid_name,const INVMSignalManager_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_INVMSignalManager_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_INVMSignalManager_t_Put(INVMSignalManager_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_INVMSignalManager_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Get(INVMSignalManager_t *data)
{
	SigMgr_Data_INVMSignalManager_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
INVMSignalManager_t * SigMgr_Data_INVMSignalManager_t_GetDataObjRef()
{
	return SigMgr_Data_INVMSignalManager_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Lock()
{
	SigMgr_Data_INVMSignalManager_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_UnLock()
{
	SigMgr_Data_INVMSignalManager_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_INVMSignalManager_t_RegisterCallback(void (*Callback)(const INVMSignalManager_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_INVMSignalManager_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSCSMVCtoDebugCAN_t> SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t;
static bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Init(const char *uid_name,const TRSCSMVCtoDebugCAN_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(TRSCSMVCtoDebugCAN_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Get(TRSCSMVCtoDebugCAN_t *data)
{
	SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoDebugCAN_t * SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_GetDataObjRef()
{
	return SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Lock()
{
	SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_UnLock()
{
	SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TimeManagerProxy_TimeStamp_t,2> SigMgr_Data_TimeManagerProxy_TimeStamp_t;
static bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Init(const char *uid_name,const TimeManagerProxy_TimeStamp_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(TimeManagerProxy_TimeStamp_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(TimeManagerProxy_TimeStamp_t *data)
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TimeManagerProxy_TimeStamp_t * SigMgr_Data_TimeManagerProxy_TimeStamp_t_GetDataObjRef()
{
	return SigMgr_Data_TimeManagerProxy_TimeStamp_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Lock()
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_UnLock()
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(void (*Callback)(const TimeManagerProxy_TimeStamp_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_CsmStateChangeReason_Type> SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type;
static bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Init(const char *uid_name,const US_S_CsmStateChangeReason_Type *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put(US_S_CsmStateChangeReason_Type *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Get(US_S_CsmStateChangeReason_Type *data)
{
	SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_CsmStateChangeReason_Type * SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_GetDataObjRef()
{
	return SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Lock()
{
	SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_UnLock()
{
	SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************
static SignalMgr_ProtectedData<KeepAliveResponse_t> SigMgr_PpKeepAliveResponse_KeepAliveResponse_t;
static bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Init(const char *uid_name,const KeepAliveResponse_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(KeepAliveResponse_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(KeepAliveResponse_t *data)
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
KeepAliveResponse_t * SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_GetDataObjRef()
{
	return SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Lock()
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_UnLock()
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************
static SignalMgr_ProtectedData<US_S_DebugMsg_t> SigMgr_PpUssDebugMsg_US_S_DebugMsg_t;
static bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Init(const char *uid_name,const US_S_DebugMsg_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put(US_S_DebugMsg_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Get(US_S_DebugMsg_t *data)
{
	SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_DebugMsg_t * SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_GetDataObjRef()
{
	return SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Lock()
{
	SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_UnLock()
{
	SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************
static SignalMgr_ProtectedData<CAM_select_info_t> SigMgr_PpCAMSelInfo_CAM_select_info_t;
static bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Init(const char *uid_name,const CAM_select_info_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCAMSelInfo_CAM_select_info_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(CAM_select_info_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCAMSelInfo_CAM_select_info_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Get(CAM_select_info_t *data)
{
	SigMgr_PpCAMSelInfo_CAM_select_info_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_select_info_t * SigMgr_PpCAMSelInfo_CAM_select_info_t_GetDataObjRef()
{
	return SigMgr_PpCAMSelInfo_CAM_select_info_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Lock()
{
	SigMgr_PpCAMSelInfo_CAM_select_info_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_UnLock()
{
	SigMgr_PpCAMSelInfo_CAM_select_info_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<Error_Fault_MCU2_0_t> SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t;
static bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Init(const char *uid_name,const Error_Fault_MCU2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put(Error_Fault_MCU2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Get(Error_Fault_MCU2_0_t *data)
{
	SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_0_t * SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_GetDataObjRef()
{
	return SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Lock()
{
	SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_UnLock()
{
	SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<Error_Fault_MCU2_1_t> SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t;
static bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Init(const char *uid_name,const Error_Fault_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put(Error_Fault_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Get(Error_Fault_MCU2_1_t *data)
{
	SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_1_t * SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Lock()
{
	SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_UnLock()
{
	SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<Error_Fault_MPU1_0_t> SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t;
static bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Init(const char *uid_name,const Error_Fault_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put(Error_Fault_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Get(Error_Fault_MPU1_0_t *data)
{
	SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MPU1_0_t * SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Lock()
{
	SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_UnLock()
{
	SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSC_CalibrationClear_t,1> SigMgr_Data_TRSC_CalibrationClear_t;
static bool_t SigMgr_Data_TRSC_CalibrationClear_t_Init(const char *uid_name,const TRSC_CalibrationClear_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSC_CalibrationClear_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_CalibrationClear_t_Put(TRSC_CalibrationClear_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSC_CalibrationClear_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Get(TRSC_CalibrationClear_t *data)
{
	SigMgr_Data_TRSC_CalibrationClear_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_CalibrationClear_t * SigMgr_Data_TRSC_CalibrationClear_t_GetDataObjRef()
{
	return SigMgr_Data_TRSC_CalibrationClear_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Lock()
{
	SigMgr_Data_TRSC_CalibrationClear_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_UnLock()
{
	SigMgr_Data_TRSC_CalibrationClear_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_CalibrationClear_t_RegisterCallback(void (*Callback)(const TRSC_CalibrationClear_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TRSC_CalibrationClear_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<UssTunningData_mcu1_0_t,2> SigMgr_Data_UssTunningData_mcu1_0_t;
static bool_t SigMgr_Data_UssTunningData_mcu1_0_t_Init(const char *uid_name,const UssTunningData_mcu1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_UssTunningData_mcu1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_Put(UssTunningData_mcu1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_UssTunningData_mcu1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Get(UssTunningData_mcu1_0_t *data)
{
	SigMgr_Data_UssTunningData_mcu1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu1_0_t * SigMgr_Data_UssTunningData_mcu1_0_t_GetDataObjRef()
{
	return SigMgr_Data_UssTunningData_mcu1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Lock()
{
	SigMgr_Data_UssTunningData_mcu1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_UnLock()
{
	SigMgr_Data_UssTunningData_mcu1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_UssTunningData_mcu1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<UssTunningData_mcu2_1_t,1> SigMgr_PpUssTunData_UssTunningData_mcu2_1_t;
static bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Init(const char *uid_name,const UssTunningData_mcu2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(UssTunningData_mcu2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Get(UssTunningData_mcu2_1_t *data)
{
	SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu2_1_t * SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_GetDataObjRef()
{
	return SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Lock()
{
	SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_UnLock()
{
	SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<RunTimeStats_MCU2_1_t> SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t;
static bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Init(const char *uid_name,const RunTimeStats_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(RunTimeStats_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Get(RunTimeStats_MCU2_1_t *data)
{
	SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_1_t * SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Lock()
{
	SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_UnLock()
{
	SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<RunTimeStats_MCU2_0_t> SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t;
static bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Init(const char *uid_name,const RunTimeStats_MCU2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(RunTimeStats_MCU2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Get(RunTimeStats_MCU2_0_t *data)
{
	SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_0_t * SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_GetDataObjRef()
{
	return SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Lock()
{
	SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_UnLock()
{
	SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<PerformanceStatsEnable_t,1> SigMgr_Data_PerformanceStatsEnable_t;
static bool_t SigMgr_Data_PerformanceStatsEnable_t_Init(const char *uid_name,const PerformanceStatsEnable_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data)
{
	SigMgr_Data_PerformanceStatsEnable_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef()
{
	return SigMgr_Data_PerformanceStatsEnable_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock()
{
	SigMgr_Data_PerformanceStatsEnable_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock()
{
	SigMgr_Data_PerformanceStatsEnable_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_RegisterCallback(void (*Callback)(const PerformanceStatsEnable_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_PerformanceStatsEnable_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<RunTimeStats_MPU1_0_t> SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t;
static bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Init(const char *uid_name,const RunTimeStats_MPU1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put(RunTimeStats_MPU1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Get(RunTimeStats_MPU1_0_t *data)
{
	SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MPU1_0_t * SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_GetDataObjRef()
{
	return SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Lock()
{
	SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_UnLock()
{
	SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<StackUsage_MCU2_1_t> SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t;
static bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Init(const char *uid_name,const StackUsage_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(StackUsage_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Get(StackUsage_MCU2_1_t *data)
{
	SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_1_t * SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Lock()
{
	SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_UnLock()
{
	SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData<StackUsage_MCU2_0_t> SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t;
static bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Init(const char *uid_name,const StackUsage_MCU2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(StackUsage_MCU2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Get(StackUsage_MCU2_0_t *data)
{
	SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_0_t * SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_GetDataObjRef()
{
	return SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Lock()
{
	SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_UnLock()
{
	SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** SignalDef LocalData ******************************
// *********************************************************************
static bool_t SigDef_Init_state=FALSE;
// *********************************************************************
// ****************** SignalDef Const Init Data ************************
// *********************************************************************

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init()
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_PpSvsToVCAN_SvsToVCAN_t_Init("PpSvsToVCAN_SvsToVCAN_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVStoTRSC_SVStoTRSC_t_Init("PpSVStoTRSC_SVStoTRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenRequest_ScreenRequest_t_Init("PpScreenRequest_ScreenRequest_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSvsToTHA_SvsToTHA_t_Init("PpSvsToTHA_SvsToTHA_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenResponse_ScreenResponse_t_Init("PpScreenResponse_ScreenResponse_t_uid",NULL,TRUE);
	bRet &= SigMgr_ME_VehInp_to_IpcSignals_data_f_Init("ME_VehInp_to_IpcSignals_data_f_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Init("PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Init("PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Init("PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Init("PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Init("PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Init("PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init("PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTRSC_ME_VehOut_TRSC_t_Init("PpTRSC_ME_VehOut_TRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Init("PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Init("PpDetInpTrsc_Detection_Inputs_from_TRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_0_Init("PpSR_State_MCU2_State_2_0_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_1_Init("PpSR_State_MCU2_State_2_1_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_QNX_State_QNX_Init("PpSR_State_QNX_State_QNX_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SSM_SystemState_Init("Data_SSM_SystemState_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CalDataProvider_MPU_1_0_Def_Init("Data_CalDataProvider_MPU_1_0_Def_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CalDataProvider_MCU_2_0_Def_Init("Data_CalDataProvider_MCU_2_0_Def_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CalDataProvider_MCU_2_1_Def_Init("Data_CalDataProvider_MCU_2_1_Def_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Init("PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Init("PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Init("PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Init("PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Init("PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Init("Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Init("Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_Proxi_to_IpcSignals_t_Init("Data_ME_Proxi_to_IpcSignals_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init("PpJobTHADetOutput_JobTHADetOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Init("PpAPSMPAOut_TbAP_APSMPAOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init("PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobPLDData_IJobPLDOutput_t_Init("PpJobPLDData_IJobPLDOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IKinematicData_t_Init("Data_IKinematicData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ExtY_Kinematic_T_Init("Data_ExtY_Kinematic_T_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobFPAData_IJobFPAOutput_t_Init("PpJobFPAData_IJobFPAOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpNFCDOutput_NFCD_Output_Init("PpNFCDOutput_NFCD_Output_uid",NULL,TRUE);
	bRet &= SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Init("PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Init("PpSMDAInternal_TbAP_SMDAInternalOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Init("PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Init("PpFPAWarnOut_TbAP_FPAWarnOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Init("PpRPAWarnOut_TbAP_RPAWarnOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Init("PpPAStateOut_TbAP_PAStateOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Init("PpVCActuatorOut_TbAP_VCActuatorOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpVCState_TbAP_VCStateOut_t_Init("PpVCState_TbAP_VCStateOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_QM_Init("Data_FID_STRUCT_QM_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_B_Init("Data_FID_STRUCT_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Init("PpUssPointMapGrp_US_S_PointMapGroup_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Init("PpSnrDirEcho_US_S_SnrDirEcho_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Init("PpUssZoneInfo_US_S_ZoneInfo_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Init("PpUSSBlockageBit_US_S_BlockageBit_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Init("PpUSSConstantData_US_S_USSConstantData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Init("PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Init("PpUSSErrorDiagData_US_S_USSErrorDiagData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_Curr_Volt_Monitor_t_Init("Data_USS_Curr_Volt_Monitor_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Init("PpCamEepromData_Svs_CamEepromDataArray_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_DiagToSVS_t_Init("Data_DiagToSVS_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSToDiag_SVSToDiag_t_Init("PpSVSToDiag_SVSToDiag_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Init("PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Init("PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CAM_Curr_Volt_Monitor_t_Init("Data_CAM_Curr_Volt_Monitor_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Init("PpCamCsData_CAM_CS_Curr_Monitor_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Init("PpUssMrrgData_US_S_MarriageSensorIDs_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_US_S_MarriageSensorIDs_t_Init("Data_US_S_MarriageSensorIDs_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Init("PpTrscToDiag_TRSCtoDiagMgr_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Init("PpTrailerDetectOP_TrailerDetection_Output_DID_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_DiagToParkAssist_t_Init("Data_DiagToParkAssist_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Init("Data_ME_ProxiToMPU1_0_Def_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Init("Data_ME_ProxiToMCU2_0_Def_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Init("Data_ME_ProxiToMCU2_1_Def_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Init("PpUssDataCollection_US_S_USSDataCollectionData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Init("PpPointDistOpBuff_US_S_PointDistOutputBuff_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Init("PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Init("PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbNVM_ReadParam_Init("Data_TbNVM_ReadParam_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_CanDebugRIDStatus_t_Init("Data_ME_CanDebugRIDStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SVS_NVMData_t_Init("Data_SVS_NVMData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Init("PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Init("PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSNVMData_SVS_NVMData_t_Init("PpSVSNVMData_SVS_NVMData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_Calibration_Data_t_Init("Data_USS_Calibration_Data_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Init("PpTbAPDebugOut_TbAP_DebugOut_uid",NULL,TRUE);
	bRet &= SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Init("PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Init("PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Init("PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Init("PpLMDLaneOp_LMD_Lane_Outputs_s_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Init("PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_THA_Calibration_data_MCU2_1_t_Init("Data_THA_Calibration_data_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_THA_Calibration_data_MPU1_0_t_Init("Data_THA_Calibration_data_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Init("Data_TRSC_Calibration_data_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_APA_Calibration_data_MPU1_0_t_Init("Data_APA_Calibration_data_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_APA_Calibration_data_MCU2_1_t_Init("Data_APA_Calibration_data_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SVS_Calibration_data_t_Init("Data_SVS_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FOD_Calibration_data_t_Init("Data_FOD_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_LMD_Calibration_data_t_Init("Data_LMD_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Init("Data_TRSC_Calibration_data_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Init("PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Init("PpIDebugFODObject_IDebug_FODObject_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Init("PpTbFAResetKM_TbFA_ResetKM_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Init("PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_Calibration_data_2_t_Init("Data_USS_Calibration_data_2_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Init("PpCamSerENStat_Cam_and_Ser_EN_Status_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpDLDOutput_JobDLDOutput_t_Init("PpDLDOutput_JobDLDOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_INVMSignalManager_t_Init("Data_INVMSignalManager_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Init("PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TimeManagerProxy_TimeStamp_t_Init("Data_TimeManagerProxy_TimeStamp_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Init("PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_uid",NULL,TRUE);
	bRet &= SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Init("PpKeepAliveResponse_KeepAliveResponse_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Init("PpUssDebugMsg_US_S_DebugMsg_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCAMSelInfo_CAM_select_info_t_Init("PpCAMSelInfo_CAM_select_info_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Init("PpErrFltMcu2_0_Error_Fault_MCU2_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Init("PpErrFltMcu2_1_Error_Fault_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Init("PpErrFltMpu1_0_Error_Fault_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSC_CalibrationClear_t_Init("Data_TRSC_CalibrationClear_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_UssTunningData_mcu1_0_t_Init("Data_UssTunningData_mcu1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Init("PpUssTunData_UssTunningData_mcu2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Init("PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Init("PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_PerformanceStatsEnable_t_Init("Data_PerformanceStatsEnable_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Init("PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Init("PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Init("PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_uid",NULL,TRUE);

	if((bRet != FALSE))
		{SigDef_Init_state=TRUE;}

	return bRet;
}

#ifdef __cplusplus
}
#endif
static bool_t SigDef_GetInitState()
{
	return SigDef_Init_state;
}


#endif



#ifdef BUILD_MCU2_0

// *********************************************************************
// ****************** Start SignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SvsToTHADet_t,1> SigMgr_data_SvsToTHADet_t;
static bool_t SigMgr_data_SvsToTHADet_t_Init(const char *uid_name,const SvsToTHADet_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_SvsToTHADet_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SvsToTHADet_t_Put(SvsToTHADet_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_SvsToTHADet_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Get(SvsToTHADet_t *data)
{
	SigMgr_data_SvsToTHADet_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHADet_t * SigMgr_data_SvsToTHADet_t_GetDataObjRef()
{
	return SigMgr_data_SvsToTHADet_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Lock()
{
	SigMgr_data_SvsToTHADet_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_UnLock()
{
	SigMgr_data_SvsToTHADet_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SvsToTHADet_t_RegisterCallback(void (*Callback)(const SvsToTHADet_t * const))
{
	bool_t bRet;
	bRet=SigMgr_data_SvsToTHADet_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SvsToVCAN_t,1> SigMgr_PpSvsToVCAN_SvsToVCAN_t;
static bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Init(const char *uid_name,const SvsToVCAN_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(SvsToVCAN_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(SvsToVCAN_t *data)
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToVCAN_t * SigMgr_PpSvsToVCAN_SvsToVCAN_t_GetDataObjRef()
{
	return SigMgr_PpSvsToVCAN_SvsToVCAN_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Lock()
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_UnLock()
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_RegisterCallback(void (*Callback)(const SvsToVCAN_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SVStoTRSC_t,1> SigMgr_PpSVStoTRSC_SVStoTRSC_t;
static bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_Init(const char *uid_name,const SVStoTRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVStoTRSC_SVStoTRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put(SVStoTRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVStoTRSC_SVStoTRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Get(SVStoTRSC_t *data)
{
	SigMgr_PpSVStoTRSC_SVStoTRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSC_t * SigMgr_PpSVStoTRSC_SVStoTRSC_t_GetDataObjRef()
{
	return SigMgr_PpSVStoTRSC_SVStoTRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Lock()
{
	SigMgr_PpSVStoTRSC_SVStoTRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_UnLock()
{
	SigMgr_PpSVStoTRSC_SVStoTRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_RegisterCallback(void (*Callback)(const SVStoTRSC_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVStoTRSC_SVStoTRSC_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ScreenRequest_t,1> SigMgr_PpScreenRequest_ScreenRequest_t;
static bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Init(const char *uid_name,const ScreenRequest_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data)
{
	SigMgr_PpScreenRequest_ScreenRequest_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef()
{
	return SigMgr_PpScreenRequest_ScreenRequest_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_RegisterCallback(void (*Callback)(const ScreenRequest_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpScreenRequest_ScreenRequest_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SvsToTHA_t,1> SigMgr_PpSvsToTHA_SvsToTHA_t;
static bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Init(const char *uid_name,const SvsToTHA_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Put(SvsToTHA_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Get(SvsToTHA_t *data)
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHA_t * SigMgr_PpSvsToTHA_SvsToTHA_t_GetDataObjRef()
{
	return SigMgr_PpSvsToTHA_SvsToTHA_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Lock()
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_UnLock()
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_RegisterCallback(void (*Callback)(const SvsToTHA_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************
static SignalMgr_ProtectedData<ScreenResponse_t> SigMgr_PpScreenResponse_ScreenResponse_t;
static bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Init(const char *uid_name,const ScreenResponse_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenResponse_ScreenResponse_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Put(ScreenResponse_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenResponse_ScreenResponse_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Get(ScreenResponse_t *data)
{
	SigMgr_PpScreenResponse_ScreenResponse_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenResponse_t * SigMgr_PpScreenResponse_ScreenResponse_t_GetDataObjRef()
{
	return SigMgr_PpScreenResponse_ScreenResponse_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Lock()
{
	SigMgr_PpScreenResponse_ScreenResponse_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_UnLock()
{
	SigMgr_PpScreenResponse_ScreenResponse_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_VehInp_to_IpcSignals_t,1> SigMgr_ME_VehInp_to_IpcSignals_data_f;
static bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Init(const char *uid_name,const ME_VehInp_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data)
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef()
{
	return SigMgr_ME_VehInp_to_IpcSignals_data_f.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const))
{
	bool_t bRet;
	bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ErrorMgr_ErrorCommPack_2_0_QM,1> SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM;
static bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_0_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put(ErrorMgr_ErrorCommPack_2_0_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(ErrorMgr_ErrorCommPack_2_0_QM *data)
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_QM * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_GetDataObjRef()
{
	return SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Lock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_UnLock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_0_QM * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ErrorMgr_ErrorCommPack_2_0_B,1> SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B;
static bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_0_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put(ErrorMgr_ErrorCommPack_2_0_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(ErrorMgr_ErrorCommPack_2_0_B *data)
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_B * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_GetDataObjRef()
{
	return SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Lock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_UnLock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_0_B * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSC_Inputs_from_TrailerDetection_t> SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t;
static bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init(const char *uid_name,const TRSC_Inputs_from_TrailerDetection_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data)
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef()
{
	return SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************
static SignalMgr_ProtectedData<MeDLD_e_RrCamSts_t> SigMgr_data_MeDLD_e_RrCamSts_t;
static bool_t SigMgr_data_MeDLD_e_RrCamSts_t_Init(const char *uid_name,const MeDLD_e_RrCamSts_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_MeDLD_e_RrCamSts_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_MeDLD_e_RrCamSts_t_Put(MeDLD_e_RrCamSts_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_MeDLD_e_RrCamSts_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Get(MeDLD_e_RrCamSts_t *data)
{
	SigMgr_data_MeDLD_e_RrCamSts_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MeDLD_e_RrCamSts_t * SigMgr_data_MeDLD_e_RrCamSts_t_GetDataObjRef()
{
	return SigMgr_data_MeDLD_e_RrCamSts_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Lock()
{
	SigMgr_data_MeDLD_e_RrCamSts_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_UnLock()
{
	SigMgr_data_MeDLD_e_RrCamSts_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SVStoTRSCSMVC_t,1> SigMgr_data_SVStoTRSCSMVC_t;
static bool_t SigMgr_data_SVStoTRSCSMVC_t_Init(const char *uid_name,const SVStoTRSCSMVC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_SVStoTRSCSMVC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SVStoTRSCSMVC_t_Put(SVStoTRSCSMVC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_SVStoTRSCSMVC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Get(SVStoTRSCSMVC_t *data)
{
	SigMgr_data_SVStoTRSCSMVC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSCSMVC_t * SigMgr_data_SVStoTRSCSMVC_t_GetDataObjRef()
{
	return SigMgr_data_SVStoTRSCSMVC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Lock()
{
	SigMgr_data_SVStoTRSCSMVC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_UnLock()
{
	SigMgr_data_SVStoTRSCSMVC_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SVStoTRSCSMVC_t_RegisterCallback(void (*Callback)(const SVStoTRSCSMVC_t * const))
{
	bool_t bRet;
	bRet=SigMgr_data_SVStoTRSCSMVC_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSCSMVCtoSVS_t> SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t;
static bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Init(const char *uid_name,const TRSCSMVCtoSVS_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(TRSCSMVCtoSVS_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(TRSCSMVCtoSVS_t *data)
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoSVS_t * SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_GetDataObjRef()
{
	return SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Lock()
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_UnLock()
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SSM_2_0_CoreStatus,1> SigMgr_PpSR_State_MCU2_State_2_0;
static bool_t SigMgr_PpSR_State_MCU2_State_2_0_Init(const char *uid_name,const SSM_2_0_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_0.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_0.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_RegisterCallback(void (*Callback)(const SSM_2_0_CoreStatus * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSR_State_MCU2_State_2_0.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_2_1_CoreStatus> SigMgr_PpSR_State_MCU2_State_2_1;
static bool_t SigMgr_PpSR_State_MCU2_State_2_1_Init(const char *uid_name,const SSM_2_1_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_1.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_1.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_QNX_CoreStatus> SigMgr_PpSR_State_QNX_State_QNX;
static bool_t SigMgr_PpSR_State_QNX_State_QNX_Init(const char *uid_name,const SSM_QNX_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data)
{
	SigMgr_PpSR_State_QNX_State_QNX.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef()
{
	return SigMgr_PpSR_State_QNX_State_QNX.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock()
{
	SigMgr_PpSR_State_QNX_State_QNX.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock()
{
	SigMgr_PpSR_State_QNX_State_QNX.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_SystemState> SigMgr_Data_SSM_SystemState;
static bool_t SigMgr_Data_SSM_SystemState_Init(const char *uid_name,const SSM_SystemState *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data)
{
	SigMgr_Data_SSM_SystemState.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState * SigMgr_Data_SSM_SystemState_GetDataObjRef()
{
	return SigMgr_Data_SSM_SystemState.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock()
{
	SigMgr_Data_SSM_SystemState.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock()
{
	SigMgr_Data_SSM_SystemState.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************
static SignalMgr_ProtectedData<CalDataProvider_MCU_2_0_Def> SigMgr_Data_CalDataProvider_MCU_2_0_Def;
static bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_Init(const char *uid_name,const CalDataProvider_MCU_2_0_Def *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_0_Def.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put(CalDataProvider_MCU_2_0_Def *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_0_Def.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get(CalDataProvider_MCU_2_0_Def *data)
{
	SigMgr_Data_CalDataProvider_MCU_2_0_Def.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_0_Def * SigMgr_Data_CalDataProvider_MCU_2_0_Def_GetDataObjRef()
{
	return SigMgr_Data_CalDataProvider_MCU_2_0_Def.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Lock()
{
	SigMgr_Data_CalDataProvider_MCU_2_0_Def.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_UnLock()
{
	SigMgr_Data_CalDataProvider_MCU_2_0_Def.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_Proxi_to_IpcSignals_t> SigMgr_Data_ME_Proxi_to_IpcSignals_t;
static bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Init(const char *uid_name,const ME_Proxi_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(ME_Proxi_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(ME_Proxi_to_IpcSignals_t *data)
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_to_IpcSignals_t * SigMgr_Data_ME_Proxi_to_IpcSignals_t_GetDataObjRef()
{
	return SigMgr_Data_ME_Proxi_to_IpcSignals_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Lock()
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_UnLock()
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<JobTHADetOutput_t> SigMgr_PpJobTHADetOutput_JobTHADetOutput_t;
static bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init(const char *uid_name,const JobTHADetOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data)
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbTHASmVc_FeatureOutputs_t> SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t;
static bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init(const char *uid_name,const TbTHASmVc_FeatureOutputs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data)
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef()
{
	return SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************
static SignalMgr_ProtectedData<IFPAInfoToHMI_t> SigMgr_Data_IFPAInfoToHMI_t;
static bool_t SigMgr_Data_IFPAInfoToHMI_t_Init(const char *uid_name,const IFPAInfoToHMI_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IFPAInfoToHMI_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToHMI_t_Put(IFPAInfoToHMI_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IFPAInfoToHMI_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Get(IFPAInfoToHMI_t *data)
{
	SigMgr_Data_IFPAInfoToHMI_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToHMI_t * SigMgr_Data_IFPAInfoToHMI_t_GetDataObjRef()
{
	return SigMgr_Data_IFPAInfoToHMI_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Lock()
{
	SigMgr_Data_IFPAInfoToHMI_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_UnLock()
{
	SigMgr_Data_IFPAInfoToHMI_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IHMIInfoToFPA_t,1> SigMgr_Data_IHMIInfoToFPA_t;
static bool_t SigMgr_Data_IHMIInfoToFPA_t_Init(const char *uid_name,const IHMIInfoToFPA_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IHMIInfoToFPA_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IHMIInfoToFPA_t_Put(IHMIInfoToFPA_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IHMIInfoToFPA_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Get(IHMIInfoToFPA_t *data)
{
	SigMgr_Data_IHMIInfoToFPA_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IHMIInfoToFPA_t * SigMgr_Data_IHMIInfoToFPA_t_GetDataObjRef()
{
	return SigMgr_Data_IHMIInfoToFPA_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Lock()
{
	SigMgr_Data_IHMIInfoToFPA_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_UnLock()
{
	SigMgr_Data_IHMIInfoToFPA_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IHMIInfoToFPA_t_RegisterCallback(void (*Callback)(const IHMIInfoToFPA_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_IHMIInfoToFPA_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************
static SignalMgr_ProtectedData<IKinematicData_t> SigMgr_Data_IKinematicData_t;
static bool_t SigMgr_Data_IKinematicData_t_Init(const char *uid_name,const IKinematicData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data)
{
	SigMgr_Data_IKinematicData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t * SigMgr_Data_IKinematicData_t_GetDataObjRef()
{
	return SigMgr_Data_IKinematicData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock()
{
	SigMgr_Data_IKinematicData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock()
{
	SigMgr_Data_IKinematicData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************
static SignalMgr_ProtectedData<ExtY_Kinematic_T> SigMgr_Data_ExtY_Kinematic_T;
static bool_t SigMgr_Data_ExtY_Kinematic_T_Init(const char *uid_name,const ExtY_Kinematic_T *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ExtY_Kinematic_T.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_Put(ExtY_Kinematic_T *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ExtY_Kinematic_T.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Get(ExtY_Kinematic_T *data)
{
	SigMgr_Data_ExtY_Kinematic_T.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ExtY_Kinematic_T * SigMgr_Data_ExtY_Kinematic_T_GetDataObjRef()
{
	return SigMgr_Data_ExtY_Kinematic_T.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Lock()
{
	SigMgr_Data_ExtY_Kinematic_T.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_UnLock()
{
	SigMgr_Data_ExtY_Kinematic_T.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<IJobFPAOutput_t> SigMgr_PpJobFPAData_IJobFPAOutput_t;
static bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Init(const char *uid_name,const IJobFPAOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(IJobFPAOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(IJobFPAOutput_t *data)
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobFPAOutput_t * SigMgr_PpJobFPAData_IJobFPAOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobFPAData_IJobFPAOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Lock()
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_UnLock()
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IParkingSlotID_t,1> SigMgr_Data_IParkingSlotID_t;
static bool_t SigMgr_Data_IParkingSlotID_t_Init(const char *uid_name,const IParkingSlotID_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IParkingSlotID_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotID_t_Put(IParkingSlotID_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IParkingSlotID_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Get(IParkingSlotID_t *data)
{
	SigMgr_Data_IParkingSlotID_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotID_t * SigMgr_Data_IParkingSlotID_t_GetDataObjRef()
{
	return SigMgr_Data_IParkingSlotID_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Lock()
{
	SigMgr_Data_IParkingSlotID_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_UnLock()
{
	SigMgr_Data_IParkingSlotID_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotID_t_RegisterCallback(void (*Callback)(const IParkingSlotID_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_IParkingSlotID_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_SMPAInternalOut_t> SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t;
static bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Init(const char *uid_name,const TbAP_SMPAInternalOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(TbAP_SMPAInternalOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(TbAP_SMPAInternalOut_t *data)
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMPAInternalOut_t * SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_GetDataObjRef()
{
	return SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Lock()
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_UnLock()
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_FPAWarnOut_t> SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t;
static bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Init(const char *uid_name,const TbAP_FPAWarnOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(TbAP_FPAWarnOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(TbAP_FPAWarnOut_t *data)
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_FPAWarnOut_t * SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_GetDataObjRef()
{
	return SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Lock()
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_UnLock()
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_RPAWarnOut_t> SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t;
static bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Init(const char *uid_name,const TbAP_RPAWarnOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(TbAP_RPAWarnOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(TbAP_RPAWarnOut_t *data)
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_RPAWarnOut_t * SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_GetDataObjRef()
{
	return SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Lock()
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_UnLock()
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************
static SignalMgr_ProtectedData<FID_STRUCT_QM> SigMgr_Data_FID_STRUCT_QM;
static bool_t SigMgr_Data_FID_STRUCT_QM_Init(const char *uid_name,const FID_STRUCT_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data)
{
	SigMgr_Data_FID_STRUCT_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock()
{
	SigMgr_Data_FID_STRUCT_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock()
{
	SigMgr_Data_FID_STRUCT_QM.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************
static SignalMgr_ProtectedData<FID_STRUCT_B> SigMgr_Data_FID_STRUCT_B;
static bool_t SigMgr_Data_FID_STRUCT_B_Init(const char *uid_name,const FID_STRUCT_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data)
{
	SigMgr_Data_FID_STRUCT_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B * SigMgr_Data_FID_STRUCT_B_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock()
{
	SigMgr_Data_FID_STRUCT_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock()
{
	SigMgr_Data_FID_STRUCT_B.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<THARelated_ScreenReq_t,1> SigMgr_Data_THARelated_ScreenReq_t;
static bool_t SigMgr_Data_THARelated_ScreenReq_t_Init(const char *uid_name,const THARelated_ScreenReq_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_THARelated_ScreenReq_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THARelated_ScreenReq_t_Put(THARelated_ScreenReq_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_THARelated_ScreenReq_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Get(THARelated_ScreenReq_t *data)
{
	SigMgr_Data_THARelated_ScreenReq_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THARelated_ScreenReq_t * SigMgr_Data_THARelated_ScreenReq_t_GetDataObjRef()
{
	return SigMgr_Data_THARelated_ScreenReq_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Lock()
{
	SigMgr_Data_THARelated_ScreenReq_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_UnLock()
{
	SigMgr_Data_THARelated_ScreenReq_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THARelated_ScreenReq_t_RegisterCallback(void (*Callback)(const THARelated_ScreenReq_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_THARelated_ScreenReq_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************
static SignalMgr_ProtectedData<DiagToSVS_t> SigMgr_Data_DiagToSVS_t;
static bool_t SigMgr_Data_DiagToSVS_t_Init(const char *uid_name,const DiagToSVS_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_DiagToSVS_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToSVS_t_Put(DiagToSVS_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_DiagToSVS_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Get(DiagToSVS_t *data)
{
	SigMgr_Data_DiagToSVS_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToSVS_t * SigMgr_Data_DiagToSVS_t_GetDataObjRef()
{
	return SigMgr_Data_DiagToSVS_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Lock()
{
	SigMgr_Data_DiagToSVS_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_UnLock()
{
	SigMgr_Data_DiagToSVS_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SVSToDiag_t,1> SigMgr_PpSVSToDiag_SVSToDiag_t;
static bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_Init(const char *uid_name,const SVSToDiag_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSToDiag_SVSToDiag_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_Put(SVSToDiag_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSToDiag_SVSToDiag_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Get(SVSToDiag_t *data)
{
	SigMgr_PpSVSToDiag_SVSToDiag_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVSToDiag_t * SigMgr_PpSVSToDiag_SVSToDiag_t_GetDataObjRef()
{
	return SigMgr_PpSVSToDiag_SVSToDiag_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Lock()
{
	SigMgr_PpSVSToDiag_SVSToDiag_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_UnLock()
{
	SigMgr_PpSVSToDiag_SVSToDiag_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_RegisterCallback(void (*Callback)(const SVSToDiag_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSToDiag_SVSToDiag_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************
static SignalMgr_ProtectedData<CAM_Curr_Volt_Monitor_t> SigMgr_Data_CAM_Curr_Volt_Monitor_t;
static bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_Init(const char *uid_name,const CAM_Curr_Volt_Monitor_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CAM_Curr_Volt_Monitor_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put(CAM_Curr_Volt_Monitor_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CAM_Curr_Volt_Monitor_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(CAM_Curr_Volt_Monitor_t *data)
{
	SigMgr_Data_CAM_Curr_Volt_Monitor_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_Curr_Volt_Monitor_t * SigMgr_Data_CAM_Curr_Volt_Monitor_t_GetDataObjRef()
{
	return SigMgr_Data_CAM_Curr_Volt_Monitor_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Lock()
{
	SigMgr_Data_CAM_Curr_Volt_Monitor_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_UnLock()
{
	SigMgr_Data_CAM_Curr_Volt_Monitor_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CAM_CS_Curr_Monitor_t,1> SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t;
static bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Init(const char *uid_name,const CAM_CS_Curr_Monitor_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(CAM_CS_Curr_Monitor_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Get(CAM_CS_Curr_Monitor_t *data)
{
	SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_CS_Curr_Monitor_t * SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_GetDataObjRef()
{
	return SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Lock()
{
	SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_UnLock()
{
	SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_RegisterCallback(void (*Callback)(const CAM_CS_Curr_Monitor_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<HMIInfoToAP_t,1> SigMgr_Data_HMIInfoToAP_t;
static bool_t SigMgr_Data_HMIInfoToAP_t_Init(const char *uid_name,const HMIInfoToAP_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_HMIInfoToAP_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_HMIInfoToAP_t_Put(HMIInfoToAP_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_HMIInfoToAP_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Get(HMIInfoToAP_t *data)
{
	SigMgr_Data_HMIInfoToAP_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
HMIInfoToAP_t * SigMgr_Data_HMIInfoToAP_t_GetDataObjRef()
{
	return SigMgr_Data_HMIInfoToAP_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Lock()
{
	SigMgr_Data_HMIInfoToAP_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_UnLock()
{
	SigMgr_Data_HMIInfoToAP_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_HMIInfoToAP_t_RegisterCallback(void (*Callback)(const HMIInfoToAP_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_HMIInfoToAP_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************
static SignalMgr_ProtectedData<USS_PowerSelect_t> SigMgr_Data_USS_PowerSelect_t;
static bool_t SigMgr_Data_USS_PowerSelect_t_Init(const char *uid_name,const USS_PowerSelect_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_PowerSelect_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_PowerSelect_t_Put(USS_PowerSelect_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_PowerSelect_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Get(USS_PowerSelect_t *data)
{
	SigMgr_Data_USS_PowerSelect_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t * SigMgr_Data_USS_PowerSelect_t_GetDataObjRef()
{
	return SigMgr_Data_USS_PowerSelect_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Lock()
{
	SigMgr_Data_USS_PowerSelect_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_UnLock()
{
	SigMgr_Data_USS_PowerSelect_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<USS_PowerSelect_t,1> SigMgr_Data1_USS_PowerSelect_t;
static bool_t SigMgr_Data1_USS_PowerSelect_t_Init(const char *uid_name,const USS_PowerSelect_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data1_USS_PowerSelect_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data1_USS_PowerSelect_t_Put(USS_PowerSelect_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data1_USS_PowerSelect_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Get(USS_PowerSelect_t *data)
{
	SigMgr_Data1_USS_PowerSelect_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t * SigMgr_Data1_USS_PowerSelect_t_GetDataObjRef()
{
	return SigMgr_Data1_USS_PowerSelect_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Lock()
{
	SigMgr_Data1_USS_PowerSelect_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_UnLock()
{
	SigMgr_Data1_USS_PowerSelect_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data1_USS_PowerSelect_t_RegisterCallback(void (*Callback)(const USS_PowerSelect_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data1_USS_PowerSelect_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_ProxiToMCU2_0_Def_t> SigMgr_Data_ME_ProxiToMCU2_0_Def_t;
static bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Init(const char *uid_name,const ME_ProxiToMCU2_0_Def_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_0_Def_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put(ME_ProxiToMCU2_0_Def_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_0_Def_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data)
{
	SigMgr_Data_ME_ProxiToMCU2_0_Def_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_0_Def_t * SigMgr_Data_ME_ProxiToMCU2_0_Def_t_GetDataObjRef()
{
	return SigMgr_Data_ME_ProxiToMCU2_0_Def_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Lock()
{
	SigMgr_Data_ME_ProxiToMCU2_0_Def_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_UnLock()
{
	SigMgr_Data_ME_ProxiToMCU2_0_Def_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************
static SignalMgr_ProtectedData<TrscDebug_ScrRes_t> SigMgr_Data_TrscDebug_ScrRes_t;
static bool_t SigMgr_Data_TrscDebug_ScrRes_t_Init(const char *uid_name,const TrscDebug_ScrRes_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TrscDebug_ScrRes_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrscDebug_ScrRes_t_Put(TrscDebug_ScrRes_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TrscDebug_ScrRes_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Get(TrscDebug_ScrRes_t *data)
{
	SigMgr_Data_TrscDebug_ScrRes_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrscDebug_ScrRes_t * SigMgr_Data_TrscDebug_ScrRes_t_GetDataObjRef()
{
	return SigMgr_Data_TrscDebug_ScrRes_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Lock()
{
	SigMgr_Data_TrscDebug_ScrRes_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_UnLock()
{
	SigMgr_Data_TrscDebug_ScrRes_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSCDebug_ScrReq_t,1> SigMgr_Data_TRSCDebug_ScrReq_t;
static bool_t SigMgr_Data_TRSCDebug_ScrReq_t_Init(const char *uid_name,const TRSCDebug_ScrReq_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSCDebug_ScrReq_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSCDebug_ScrReq_t_Put(TRSCDebug_ScrReq_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSCDebug_ScrReq_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Get(TRSCDebug_ScrReq_t *data)
{
	SigMgr_Data_TRSCDebug_ScrReq_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCDebug_ScrReq_t * SigMgr_Data_TRSCDebug_ScrReq_t_GetDataObjRef()
{
	return SigMgr_Data_TRSCDebug_ScrReq_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Lock()
{
	SigMgr_Data_TRSCDebug_ScrReq_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_UnLock()
{
	SigMgr_Data_TRSCDebug_ScrReq_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSCDebug_ScrReq_t_RegisterCallback(void (*Callback)(const TRSCDebug_ScrReq_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TRSCDebug_ScrReq_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CpuLoadMcu2_0_t,1> SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t;
static bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Init(const char *uid_name,const CpuLoadMcu2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(CpuLoadMcu2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Get(CpuLoadMcu2_0_t *data)
{
	SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_0_t * SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_GetDataObjRef()
{
	return SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Lock()
{
	SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_UnLock()
{
	SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_RegisterCallback(void (*Callback)(const CpuLoadMcu2_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_CanDebugRIDStatus_t> SigMgr_Data_ME_CanDebugRIDStatus_t;
static bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Init(const char *uid_name,const ME_CanDebugRIDStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data)
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef()
{
	return SigMgr_Data_ME_CanDebugRIDStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVS_NVMData_t> SigMgr_Data_SVS_NVMData_t;
static bool_t SigMgr_Data_SVS_NVMData_t_Init(const char *uid_name,const SVS_NVMData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SVS_NVMData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_NVMData_t_Put(SVS_NVMData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SVS_NVMData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Get(SVS_NVMData_t *data)
{
	SigMgr_Data_SVS_NVMData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t * SigMgr_Data_SVS_NVMData_t_GetDataObjRef()
{
	return SigMgr_Data_SVS_NVMData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Lock()
{
	SigMgr_Data_SVS_NVMData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_UnLock()
{
	SigMgr_Data_SVS_NVMData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SVS_NVMData_t,1> SigMgr_PpSVSNVMData_SVS_NVMData_t;
static bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_Init(const char *uid_name,const SVS_NVMData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSVSNVMData_SVS_NVMData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_Put(SVS_NVMData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSVSNVMData_SVS_NVMData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Get(SVS_NVMData_t *data)
{
	SigMgr_PpSVSNVMData_SVS_NVMData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t * SigMgr_PpSVSNVMData_SVS_NVMData_t_GetDataObjRef()
{
	return SigMgr_PpSVSNVMData_SVS_NVMData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Lock()
{
	SigMgr_PpSVSNVMData_SVS_NVMData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_UnLock()
{
	SigMgr_PpSVSNVMData_SVS_NVMData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_RegisterCallback(void (*Callback)(const SVS_NVMData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSVSNVMData_SVS_NVMData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<WdgCheckpointStatus_t,1> SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t;
static bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Init(const char *uid_name,const WdgCheckpointStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data)
{
	SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t * SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_GetDataObjRef()
{
	return SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Lock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_UnLock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_RegisterCallback(void (*Callback)(const WdgCheckpointStatus_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVS_Calibration_data_t> SigMgr_Data_SVS_Calibration_data_t;
static bool_t SigMgr_Data_SVS_Calibration_data_t_Init(const char *uid_name,const SVS_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SVS_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_Put(SVS_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SVS_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Get(SVS_Calibration_data_t *data)
{
	SigMgr_Data_SVS_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_Calibration_data_t * SigMgr_Data_SVS_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_SVS_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Lock()
{
	SigMgr_Data_SVS_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_UnLock()
{
	SigMgr_Data_SVS_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbSVS_e_SVSCalibSMToHmi_t> SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t;
static bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Init(const char *uid_name,const TbSVS_e_SVSCalibSMToHmi_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put(TbSVS_e_SVSCalibSMToHmi_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(TbSVS_e_SVSCalibSMToHmi_t *data)
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibSMToHmi_t * SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_GetDataObjRef()
{
	return SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Lock()
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_UnLock()
{
	SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<Cam_and_Ser_EN_Status_t,1> SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t;
static bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Init(const char *uid_name,const Cam_and_Ser_EN_Status_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(Cam_and_Ser_EN_Status_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Get(Cam_and_Ser_EN_Status_t *data)
{
	SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Cam_and_Ser_EN_Status_t * SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_GetDataObjRef()
{
	return SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Lock()
{
	SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_UnLock()
{
	SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_RegisterCallback(void (*Callback)(const Cam_and_Ser_EN_Status_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************
static SignalMgr_ProtectedData<TrailerDetection_Output_HMI_t> SigMgr_Data_TrailerDetection_Output_HMI_t;
static bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_Init(const char *uid_name,const TrailerDetection_Output_HMI_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TrailerDetection_Output_HMI_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_Put(TrailerDetection_Output_HMI_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TrailerDetection_Output_HMI_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Get(TrailerDetection_Output_HMI_t *data)
{
	SigMgr_Data_TrailerDetection_Output_HMI_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_HMI_t * SigMgr_Data_TrailerDetection_Output_HMI_t_GetDataObjRef()
{
	return SigMgr_Data_TrailerDetection_Output_HMI_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Lock()
{
	SigMgr_Data_TrailerDetection_Output_HMI_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_UnLock()
{
	SigMgr_Data_TrailerDetection_Output_HMI_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TimeManagerProxy_TimeStamp_t,1> SigMgr_Data_TimeManagerProxy_TimeStamp_t;
static bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Init(const char *uid_name,const TimeManagerProxy_TimeStamp_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(TimeManagerProxy_TimeStamp_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(TimeManagerProxy_TimeStamp_t *data)
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TimeManagerProxy_TimeStamp_t * SigMgr_Data_TimeManagerProxy_TimeStamp_t_GetDataObjRef()
{
	return SigMgr_Data_TimeManagerProxy_TimeStamp_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Lock()
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_UnLock()
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(void (*Callback)(const TimeManagerProxy_TimeStamp_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************
static SignalMgr_ProtectedData<KeepAliveResponse_t> SigMgr_PpKeepAliveResponse_KeepAliveResponse_t;
static bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Init(const char *uid_name,const KeepAliveResponse_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(KeepAliveResponse_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(KeepAliveResponse_t *data)
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
KeepAliveResponse_t * SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_GetDataObjRef()
{
	return SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Lock()
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_UnLock()
{
	SigMgr_PpKeepAliveResponse_KeepAliveResponse_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CAM_select_info_t,1> SigMgr_PpCAMSelInfo_CAM_select_info_t;
static bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Init(const char *uid_name,const CAM_select_info_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCAMSelInfo_CAM_select_info_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(CAM_select_info_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCAMSelInfo_CAM_select_info_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Get(CAM_select_info_t *data)
{
	SigMgr_PpCAMSelInfo_CAM_select_info_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_select_info_t * SigMgr_PpCAMSelInfo_CAM_select_info_t_GetDataObjRef()
{
	return SigMgr_PpCAMSelInfo_CAM_select_info_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Lock()
{
	SigMgr_PpCAMSelInfo_CAM_select_info_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_UnLock()
{
	SigMgr_PpCAMSelInfo_CAM_select_info_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_RegisterCallback(void (*Callback)(const CAM_select_info_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCAMSelInfo_CAM_select_info_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<Error_Fault_MCU2_0_t,1> SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t;
static bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Init(const char *uid_name,const Error_Fault_MCU2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put(Error_Fault_MCU2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Get(Error_Fault_MCU2_0_t *data)
{
	SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_0_t * SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_GetDataObjRef()
{
	return SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Lock()
{
	SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_UnLock()
{
	SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_RegisterCallback(void (*Callback)(const Error_Fault_MCU2_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<RunTimeStats_MCU2_0_t,1> SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t;
static bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Init(const char *uid_name,const RunTimeStats_MCU2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(RunTimeStats_MCU2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Get(RunTimeStats_MCU2_0_t *data)
{
	SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_0_t * SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_GetDataObjRef()
{
	return SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Lock()
{
	SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_UnLock()
{
	SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_RegisterCallback(void (*Callback)(const RunTimeStats_MCU2_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************
static SignalMgr_ProtectedData<PerformanceStatsEnable_t> SigMgr_Data_PerformanceStatsEnable_t;
static bool_t SigMgr_Data_PerformanceStatsEnable_t_Init(const char *uid_name,const PerformanceStatsEnable_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data)
{
	SigMgr_Data_PerformanceStatsEnable_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef()
{
	return SigMgr_Data_PerformanceStatsEnable_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock()
{
	SigMgr_Data_PerformanceStatsEnable_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock()
{
	SigMgr_Data_PerformanceStatsEnable_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CamHotplugStatus_t,1> SigMgr_Data_CamHotplugStatus_t;
static bool_t SigMgr_Data_CamHotplugStatus_t_Init(const char *uid_name,const CamHotplugStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CamHotplugStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CamHotplugStatus_t_Put(CamHotplugStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CamHotplugStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Get(CamHotplugStatus_t *data)
{
	SigMgr_Data_CamHotplugStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CamHotplugStatus_t * SigMgr_Data_CamHotplugStatus_t_GetDataObjRef()
{
	return SigMgr_Data_CamHotplugStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Lock()
{
	SigMgr_Data_CamHotplugStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_UnLock()
{
	SigMgr_Data_CamHotplugStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CamHotplugStatus_t_RegisterCallback(void (*Callback)(const CamHotplugStatus_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_CamHotplugStatus_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<StackUsage_MCU2_0_t,1> SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t;
static bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Init(const char *uid_name,const StackUsage_MCU2_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(StackUsage_MCU2_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Get(StackUsage_MCU2_0_t *data)
{
	SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_0_t * SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_GetDataObjRef()
{
	return SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Lock()
{
	SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_UnLock()
{
	SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_RegisterCallback(void (*Callback)(const StackUsage_MCU2_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** SignalDef LocalData ******************************
// *********************************************************************
static bool_t SigDef_Init_state=FALSE;
// *********************************************************************
// ****************** SignalDef Const Init Data ************************
// *********************************************************************

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init()
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_data_SvsToTHADet_t_Init("data_SvsToTHADet_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSvsToVCAN_SvsToVCAN_t_Init("PpSvsToVCAN_SvsToVCAN_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVStoTRSC_SVStoTRSC_t_Init("PpSVStoTRSC_SVStoTRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenRequest_ScreenRequest_t_Init("PpScreenRequest_ScreenRequest_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSvsToTHA_SvsToTHA_t_Init("PpSvsToTHA_SvsToTHA_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenResponse_ScreenResponse_t_Init("PpScreenResponse_ScreenResponse_t_uid",NULL,TRUE);
	bRet &= SigMgr_ME_VehInp_to_IpcSignals_data_f_Init("ME_VehInp_to_IpcSignals_data_f_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Init("PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Init("PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init("PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_uid",NULL,TRUE);
	bRet &= SigMgr_data_MeDLD_e_RrCamSts_t_Init("data_MeDLD_e_RrCamSts_t_uid",NULL,TRUE);
	bRet &= SigMgr_data_SVStoTRSCSMVC_t_Init("data_SVStoTRSCSMVC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Init("PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_0_Init("PpSR_State_MCU2_State_2_0_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_1_Init("PpSR_State_MCU2_State_2_1_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_QNX_State_QNX_Init("PpSR_State_QNX_State_QNX_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SSM_SystemState_Init("Data_SSM_SystemState_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CalDataProvider_MCU_2_0_Def_Init("Data_CalDataProvider_MCU_2_0_Def_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_Proxi_to_IpcSignals_t_Init("Data_ME_Proxi_to_IpcSignals_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init("PpJobTHADetOutput_JobTHADetOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init("PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IFPAInfoToHMI_t_Init("Data_IFPAInfoToHMI_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IHMIInfoToFPA_t_Init("Data_IHMIInfoToFPA_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IKinematicData_t_Init("Data_IKinematicData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ExtY_Kinematic_T_Init("Data_ExtY_Kinematic_T_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobFPAData_IJobFPAOutput_t_Init("PpJobFPAData_IJobFPAOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IParkingSlotID_t_Init("Data_IParkingSlotID_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Init("PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Init("PpFPAWarnOut_TbAP_FPAWarnOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Init("PpRPAWarnOut_TbAP_RPAWarnOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_QM_Init("Data_FID_STRUCT_QM_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_B_Init("Data_FID_STRUCT_B_uid",NULL,TRUE);
	bRet &= SigMgr_Data_THARelated_ScreenReq_t_Init("Data_THARelated_ScreenReq_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_DiagToSVS_t_Init("Data_DiagToSVS_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSToDiag_SVSToDiag_t_Init("PpSVSToDiag_SVSToDiag_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CAM_Curr_Volt_Monitor_t_Init("Data_CAM_Curr_Volt_Monitor_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Init("PpCamCsData_CAM_CS_Curr_Monitor_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_HMIInfoToAP_t_Init("Data_HMIInfoToAP_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_PowerSelect_t_Init("Data_USS_PowerSelect_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data1_USS_PowerSelect_t_Init("Data1_USS_PowerSelect_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Init("Data_ME_ProxiToMCU2_0_Def_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TrscDebug_ScrRes_t_Init("Data_TrscDebug_ScrRes_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSCDebug_ScrReq_t_Init("Data_TRSCDebug_ScrReq_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Init("PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_CanDebugRIDStatus_t_Init("Data_ME_CanDebugRIDStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SVS_NVMData_t_Init("Data_SVS_NVMData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSVSNVMData_SVS_NVMData_t_Init("PpSVSNVMData_SVS_NVMData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Init("PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SVS_Calibration_data_t_Init("Data_SVS_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Init("Data_TbSVS_e_SVSCalibSMToHmi_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Init("PpCamSerENStat_Cam_and_Ser_EN_Status_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TrailerDetection_Output_HMI_t_Init("Data_TrailerDetection_Output_HMI_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TimeManagerProxy_TimeStamp_t_Init("Data_TimeManagerProxy_TimeStamp_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Init("PpKeepAliveResponse_KeepAliveResponse_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCAMSelInfo_CAM_select_info_t_Init("PpCAMSelInfo_CAM_select_info_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Init("PpErrFltMcu2_0_Error_Fault_MCU2_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Init("PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_PerformanceStatsEnable_t_Init("Data_PerformanceStatsEnable_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CamHotplugStatus_t_Init("Data_CamHotplugStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Init("PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_uid",NULL,TRUE);

	if((bRet != FALSE))
		{SigDef_Init_state=TRUE;}

	return bRet;
}

#ifdef __cplusplus
}
#endif
static bool_t SigDef_GetInitState()
{
	return SigDef_Init_state;
}


#endif



#ifdef BUILD_MCU2_1

// *********************************************************************
// ****************** Start SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************
static SignalMgr_ProtectedData<SvsToVCAN_t> SigMgr_PpSvsToVCAN_SvsToVCAN_t;
static bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Init(const char *uid_name,const SvsToVCAN_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(SvsToVCAN_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSvsToVCAN_SvsToVCAN_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(SvsToVCAN_t *data)
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToVCAN_t * SigMgr_PpSvsToVCAN_SvsToVCAN_t_GetDataObjRef()
{
	return SigMgr_PpSvsToVCAN_SvsToVCAN_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Lock()
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_UnLock()
{
	SigMgr_PpSvsToVCAN_SvsToVCAN_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************
static SignalMgr_ProtectedData<ScreenRequest_t> SigMgr_PpScreenRequest_ScreenRequest_t;
static bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Init(const char *uid_name,const ScreenRequest_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpScreenRequest_ScreenRequest_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data)
{
	SigMgr_PpScreenRequest_ScreenRequest_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef()
{
	return SigMgr_PpScreenRequest_ScreenRequest_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock()
{
	SigMgr_PpScreenRequest_ScreenRequest_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************
static SignalMgr_ProtectedData<SvsToTHA_t> SigMgr_PpSvsToTHA_SvsToTHA_t;
static bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Init(const char *uid_name,const SvsToTHA_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Put(SvsToTHA_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSvsToTHA_SvsToTHA_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Get(SvsToTHA_t *data)
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHA_t * SigMgr_PpSvsToTHA_SvsToTHA_t_GetDataObjRef()
{
	return SigMgr_PpSvsToTHA_SvsToTHA_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Lock()
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_UnLock()
{
	SigMgr_PpSvsToTHA_SvsToTHA_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_VehInp_to_IpcSignals_t,1> SigMgr_ME_VehInp_to_IpcSignals_data_f;
static bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Init(const char *uid_name,const ME_VehInp_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data)
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef()
{
	return SigMgr_ME_VehInp_to_IpcSignals_data_f.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock()
{
	SigMgr_ME_VehInp_to_IpcSignals_data_f.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const))
{
	bool_t bRet;
	bRet=SigMgr_ME_VehInp_to_IpcSignals_data_f.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ErrorMgr_ErrorCommPack_2_1_QM,1> SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM;
static bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_1_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put(ErrorMgr_ErrorCommPack_2_1_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(ErrorMgr_ErrorCommPack_2_1_QM *data)
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_QM * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_GetDataObjRef()
{
	return SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Lock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_UnLock()
{
	SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_1_QM * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ErrorMgr_ErrorCommPack_2_1_B,1> SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B;
static bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Init(const char *uid_name,const ErrorMgr_ErrorCommPack_2_1_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put(ErrorMgr_ErrorCommPack_2_1_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(ErrorMgr_ErrorCommPack_2_1_B *data)
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_B * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_GetDataObjRef()
{
	return SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Lock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_UnLock()
{
	SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_1_B * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSC_Inputs_from_TrailerDetection_t> SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t;
static bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init(const char *uid_name,const TRSC_Inputs_from_TrailerDetection_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data)
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef()
{
	return SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock()
{
	SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<ME_VehOut_TRSC_t,1> SigMgr_PpTRSC_ME_VehOut_TRSC_t;
static bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_Init(const char *uid_name,const ME_VehOut_TRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTRSC_ME_VehOut_TRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(ME_VehOut_TRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTRSC_ME_VehOut_TRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(ME_VehOut_TRSC_t *data)
{
	SigMgr_PpTRSC_ME_VehOut_TRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehOut_TRSC_t * SigMgr_PpTRSC_ME_VehOut_TRSC_t_GetDataObjRef()
{
	return SigMgr_PpTRSC_ME_VehOut_TRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Lock()
{
	SigMgr_PpTRSC_ME_VehOut_TRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_UnLock()
{
	SigMgr_PpTRSC_ME_VehOut_TRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_RegisterCallback(void (*Callback)(const ME_VehOut_TRSC_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTRSC_ME_VehOut_TRSC_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVStoTRSCSMVC_t> SigMgr_data_SVStoTRSCSMVC_t;
static bool_t SigMgr_data_SVStoTRSCSMVC_t_Init(const char *uid_name,const SVStoTRSCSMVC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_data_SVStoTRSCSMVC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SVStoTRSCSMVC_t_Put(SVStoTRSCSMVC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_data_SVStoTRSCSMVC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Get(SVStoTRSCSMVC_t *data)
{
	SigMgr_data_SVStoTRSCSMVC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSCSMVC_t * SigMgr_data_SVStoTRSCSMVC_t_GetDataObjRef()
{
	return SigMgr_data_SVStoTRSCSMVC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Lock()
{
	SigMgr_data_SVStoTRSCSMVC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_UnLock()
{
	SigMgr_data_SVStoTRSCSMVC_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSCSMVCtoSVS_t,1> SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t;
static bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Init(const char *uid_name,const TRSCSMVCtoSVS_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(TRSCSMVCtoSVS_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(TRSCSMVCtoSVS_t *data)
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoSVS_t * SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_GetDataObjRef()
{
	return SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Lock()
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_UnLock()
{
	SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_RegisterCallback(void (*Callback)(const TRSCSMVCtoSVS_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<Detection_Inputs_from_TRSC_t,1> SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t;
static bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Init(const char *uid_name,const Detection_Inputs_from_TRSC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(Detection_Inputs_from_TRSC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(Detection_Inputs_from_TRSC_t *data)
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Detection_Inputs_from_TRSC_t * SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_GetDataObjRef()
{
	return SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Lock()
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_UnLock()
{
	SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_RegisterCallback(void (*Callback)(const Detection_Inputs_from_TRSC_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_2_0_CoreStatus> SigMgr_PpSR_State_MCU2_State_2_0;
static bool_t SigMgr_PpSR_State_MCU2_State_2_0_Init(const char *uid_name,const SSM_2_0_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_0.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_0.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_0.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_0.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<SSM_2_1_CoreStatus,1> SigMgr_PpSR_State_MCU2_State_2_1;
static bool_t SigMgr_PpSR_State_MCU2_State_2_1_Init(const char *uid_name,const SSM_2_1_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_MCU2_State_2_1.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data)
{
	SigMgr_PpSR_State_MCU2_State_2_1.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef()
{
	return SigMgr_PpSR_State_MCU2_State_2_1.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock()
{
	SigMgr_PpSR_State_MCU2_State_2_1.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_RegisterCallback(void (*Callback)(const SSM_2_1_CoreStatus * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSR_State_MCU2_State_2_1.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_QNX_CoreStatus> SigMgr_PpSR_State_QNX_State_QNX;
static bool_t SigMgr_PpSR_State_QNX_State_QNX_Init(const char *uid_name,const SSM_QNX_CoreStatus *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSR_State_QNX_State_QNX.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data)
{
	SigMgr_PpSR_State_QNX_State_QNX.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef()
{
	return SigMgr_PpSR_State_QNX_State_QNX.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock()
{
	SigMgr_PpSR_State_QNX_State_QNX.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock()
{
	SigMgr_PpSR_State_QNX_State_QNX.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************
static SignalMgr_ProtectedData<SSM_SystemState> SigMgr_Data_SSM_SystemState;
static bool_t SigMgr_Data_SSM_SystemState_Init(const char *uid_name,const SSM_SystemState *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SSM_SystemState.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data)
{
	SigMgr_Data_SSM_SystemState.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState * SigMgr_Data_SSM_SystemState_GetDataObjRef()
{
	return SigMgr_Data_SSM_SystemState.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock()
{
	SigMgr_Data_SSM_SystemState.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock()
{
	SigMgr_Data_SSM_SystemState.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************
static SignalMgr_ProtectedData<CalDataProvider_MCU_2_1_Def> SigMgr_Data_CalDataProvider_MCU_2_1_Def;
static bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_Init(const char *uid_name,const CalDataProvider_MCU_2_1_Def *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_1_Def.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put(CalDataProvider_MCU_2_1_Def *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_CalDataProvider_MCU_2_1_Def.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(CalDataProvider_MCU_2_1_Def *data)
{
	SigMgr_Data_CalDataProvider_MCU_2_1_Def.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_1_Def * SigMgr_Data_CalDataProvider_MCU_2_1_Def_GetDataObjRef()
{
	return SigMgr_Data_CalDataProvider_MCU_2_1_Def.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Lock()
{
	SigMgr_Data_CalDataProvider_MCU_2_1_Def.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_UnLock()
{
	SigMgr_Data_CalDataProvider_MCU_2_1_Def.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_Proxi_to_IpcSignals_t> SigMgr_Data_ME_Proxi_to_IpcSignals_t;
static bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Init(const char *uid_name,const ME_Proxi_to_IpcSignals_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(ME_Proxi_to_IpcSignals_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_Proxi_to_IpcSignals_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(ME_Proxi_to_IpcSignals_t *data)
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_to_IpcSignals_t * SigMgr_Data_ME_Proxi_to_IpcSignals_t_GetDataObjRef()
{
	return SigMgr_Data_ME_Proxi_to_IpcSignals_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Lock()
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_UnLock()
{
	SigMgr_Data_ME_Proxi_to_IpcSignals_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<JobTHADetOutput_t> SigMgr_PpJobTHADetOutput_JobTHADetOutput_t;
static bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init(const char *uid_name,const JobTHADetOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data)
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock()
{
	SigMgr_PpJobTHADetOutput_JobTHADetOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_APSMPAOut_t,1> SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t;
static bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Init(const char *uid_name,const TbAP_APSMPAOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(TbAP_APSMPAOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(TbAP_APSMPAOut_t *data)
{
	SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_APSMPAOut_t * SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_GetDataObjRef()
{
	return SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Lock()
{
	SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_UnLock()
{
	SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_RegisterCallback(void (*Callback)(const TbAP_APSMPAOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbTHASmVc_FeatureOutputs_t,1> SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t;
static bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init(const char *uid_name,const TbTHASmVc_FeatureOutputs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data)
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef()
{
	return SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock()
{
	SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_RegisterCallback(void (*Callback)(const TbTHASmVc_FeatureOutputs_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IFPAInfoToHMI_t,1> SigMgr_Data_IFPAInfoToHMI_t;
static bool_t SigMgr_Data_IFPAInfoToHMI_t_Init(const char *uid_name,const IFPAInfoToHMI_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IFPAInfoToHMI_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToHMI_t_Put(IFPAInfoToHMI_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IFPAInfoToHMI_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Get(IFPAInfoToHMI_t *data)
{
	SigMgr_Data_IFPAInfoToHMI_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToHMI_t * SigMgr_Data_IFPAInfoToHMI_t_GetDataObjRef()
{
	return SigMgr_Data_IFPAInfoToHMI_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Lock()
{
	SigMgr_Data_IFPAInfoToHMI_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_UnLock()
{
	SigMgr_Data_IFPAInfoToHMI_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToHMI_t_RegisterCallback(void (*Callback)(const IFPAInfoToHMI_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_IFPAInfoToHMI_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToVC_t :: Data_IFPAInfoToVC_t 
// *********************************************************************
static SignalMgr_ProtectedData<IFPAInfoToVC_t> SigMgr_Data_IFPAInfoToVC_t;
static bool_t SigMgr_Data_IFPAInfoToVC_t_Init(const char *uid_name,const IFPAInfoToVC_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IFPAInfoToVC_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToVC_t_Put(IFPAInfoToVC_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IFPAInfoToVC_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToVC_t_Get(IFPAInfoToVC_t *data)
{
	SigMgr_Data_IFPAInfoToVC_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToVC_t * SigMgr_Data_IFPAInfoToVC_t_GetDataObjRef()
{
	return SigMgr_Data_IFPAInfoToVC_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToVC_t_Lock()
{
	SigMgr_Data_IFPAInfoToVC_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToVC_t_UnLock()
{
	SigMgr_Data_IFPAInfoToVC_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFPAInfoToVC_t :: Data_IFPAInfoToVC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IFPAInfoToPLD_t,1> SigMgr_Data_IFPAInfoToPLD_t;
static bool_t SigMgr_Data_IFPAInfoToPLD_t_Init(const char *uid_name,const IFPAInfoToPLD_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IFPAInfoToPLD_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToPLD_t_Put(IFPAInfoToPLD_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IFPAInfoToPLD_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Get(IFPAInfoToPLD_t *data)
{
	SigMgr_Data_IFPAInfoToPLD_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToPLD_t * SigMgr_Data_IFPAInfoToPLD_t_GetDataObjRef()
{
	return SigMgr_Data_IFPAInfoToPLD_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Lock()
{
	SigMgr_Data_IFPAInfoToPLD_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_UnLock()
{
	SigMgr_Data_IFPAInfoToPLD_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToPLD_t_RegisterCallback(void (*Callback)(const IFPAInfoToPLD_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_IFPAInfoToPLD_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************
static SignalMgr_ProtectedData<IHMIInfoToFPA_t> SigMgr_Data_IHMIInfoToFPA_t;
static bool_t SigMgr_Data_IHMIInfoToFPA_t_Init(const char *uid_name,const IHMIInfoToFPA_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IHMIInfoToFPA_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IHMIInfoToFPA_t_Put(IHMIInfoToFPA_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IHMIInfoToFPA_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Get(IHMIInfoToFPA_t *data)
{
	SigMgr_Data_IHMIInfoToFPA_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IHMIInfoToFPA_t * SigMgr_Data_IHMIInfoToFPA_t_GetDataObjRef()
{
	return SigMgr_Data_IHMIInfoToFPA_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Lock()
{
	SigMgr_Data_IHMIInfoToFPA_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_UnLock()
{
	SigMgr_Data_IHMIInfoToFPA_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData<IJobPLDOutput_t> SigMgr_PpJobPLDData_IJobPLDOutput_t;
static bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Init(const char *uid_name,const IJobPLDOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(IJobPLDOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobPLDData_IJobPLDOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(IJobPLDOutput_t *data)
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobPLDOutput_t * SigMgr_PpJobPLDData_IJobPLDOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobPLDData_IJobPLDOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Lock()
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_UnLock()
{
	SigMgr_PpJobPLDData_IJobPLDOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IUPASensorDataV2_t :: Data_IUPASensorDataV2_t 
// *********************************************************************
static SignalMgr_ProtectedData<IUPASensorDataV2_t> SigMgr_Data_IUPASensorDataV2_t;
static bool_t SigMgr_Data_IUPASensorDataV2_t_Init(const char *uid_name,const IUPASensorDataV2_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IUPASensorDataV2_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IUPASensorDataV2_t_Put(IUPASensorDataV2_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IUPASensorDataV2_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IUPASensorDataV2_t_Get(IUPASensorDataV2_t *data)
{
	SigMgr_Data_IUPASensorDataV2_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IUPASensorDataV2_t * SigMgr_Data_IUPASensorDataV2_t_GetDataObjRef()
{
	return SigMgr_Data_IUPASensorDataV2_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IUPASensorDataV2_t_Lock()
{
	SigMgr_Data_IUPASensorDataV2_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IUPASensorDataV2_t_UnLock()
{
	SigMgr_Data_IUPASensorDataV2_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IUPASensorDataV2_t :: Data_IUPASensorDataV2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IPathPlannerState_t :: Data_IPathPlannerState_t 
// *********************************************************************
static SignalMgr_ProtectedData<IPathPlannerState_t> SigMgr_Data_IPathPlannerState_t;
static bool_t SigMgr_Data_IPathPlannerState_t_Init(const char *uid_name,const IPathPlannerState_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IPathPlannerState_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IPathPlannerState_t_Put(IPathPlannerState_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IPathPlannerState_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IPathPlannerState_t_Get(IPathPlannerState_t *data)
{
	SigMgr_Data_IPathPlannerState_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IPathPlannerState_t * SigMgr_Data_IPathPlannerState_t_GetDataObjRef()
{
	return SigMgr_Data_IPathPlannerState_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IPathPlannerState_t_Lock()
{
	SigMgr_Data_IPathPlannerState_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IPathPlannerState_t_UnLock()
{
	SigMgr_Data_IPathPlannerState_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IPathPlannerState_t :: Data_IPathPlannerState_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************
static SignalMgr_ProtectedData<IKinematicData_t> SigMgr_Data_IKinematicData_t;
static bool_t SigMgr_Data_IKinematicData_t_Init(const char *uid_name,const IKinematicData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IKinematicData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data)
{
	SigMgr_Data_IKinematicData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t * SigMgr_Data_IKinematicData_t_GetDataObjRef()
{
	return SigMgr_Data_IKinematicData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock()
{
	SigMgr_Data_IKinematicData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock()
{
	SigMgr_Data_IKinematicData_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************
static SignalMgr_ProtectedData<ExtY_Kinematic_T> SigMgr_Data_ExtY_Kinematic_T;
static bool_t SigMgr_Data_ExtY_Kinematic_T_Init(const char *uid_name,const ExtY_Kinematic_T *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ExtY_Kinematic_T.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_Put(ExtY_Kinematic_T *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ExtY_Kinematic_T.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Get(ExtY_Kinematic_T *data)
{
	SigMgr_Data_ExtY_Kinematic_T.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ExtY_Kinematic_T * SigMgr_Data_ExtY_Kinematic_T_GetDataObjRef()
{
	return SigMgr_Data_ExtY_Kinematic_T.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Lock()
{
	SigMgr_Data_ExtY_Kinematic_T.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_UnLock()
{
	SigMgr_Data_ExtY_Kinematic_T.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************
static SignalMgr_ProtectedData<IParkingSlotInformation_t> SigMgr_Data_IParkingSlotInformation_t;
static bool_t SigMgr_Data_IParkingSlotInformation_t_Init(const char *uid_name,const IParkingSlotInformation_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IParkingSlotInformation_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotInformation_t_Put(IParkingSlotInformation_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IParkingSlotInformation_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Get(IParkingSlotInformation_t *data)
{
	SigMgr_Data_IParkingSlotInformation_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotInformation_t * SigMgr_Data_IParkingSlotInformation_t_GetDataObjRef()
{
	return SigMgr_Data_IParkingSlotInformation_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Lock()
{
	SigMgr_Data_IParkingSlotInformation_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_UnLock()
{
	SigMgr_Data_IParkingSlotInformation_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IJobFPAOutput_t,1> SigMgr_PpJobFPAData_IJobFPAOutput_t;
static bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Init(const char *uid_name,const IJobFPAOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(IJobFPAOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(IJobFPAOutput_t *data)
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobFPAOutput_t * SigMgr_PpJobFPAData_IJobFPAOutput_t_GetDataObjRef()
{
	return SigMgr_PpJobFPAData_IJobFPAOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Lock()
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_UnLock()
{
	SigMgr_PpJobFPAData_IJobFPAOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_RegisterCallback(void (*Callback)(const IJobFPAOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpJobFPAData_IJobFPAOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IAutoParkingState_t :: Data_IAutoParkingState_t 
// *********************************************************************
static SignalMgr_ProtectedData<IAutoParkingState_t> SigMgr_Data_IAutoParkingState_t;
static bool_t SigMgr_Data_IAutoParkingState_t_Init(const char *uid_name,const IAutoParkingState_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IAutoParkingState_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IAutoParkingState_t_Put(IAutoParkingState_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IAutoParkingState_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IAutoParkingState_t_Get(IAutoParkingState_t *data)
{
	SigMgr_Data_IAutoParkingState_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IAutoParkingState_t * SigMgr_Data_IAutoParkingState_t_GetDataObjRef()
{
	return SigMgr_Data_IAutoParkingState_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IAutoParkingState_t_Lock()
{
	SigMgr_Data_IAutoParkingState_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IAutoParkingState_t_UnLock()
{
	SigMgr_Data_IAutoParkingState_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IAutoParkingState_t :: Data_IAutoParkingState_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************
static SignalMgr_ProtectedData<IParkingSlotID_t> SigMgr_Data_IParkingSlotID_t;
static bool_t SigMgr_Data_IParkingSlotID_t_Init(const char *uid_name,const IParkingSlotID_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_IParkingSlotID_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotID_t_Put(IParkingSlotID_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_IParkingSlotID_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Get(IParkingSlotID_t *data)
{
	SigMgr_Data_IParkingSlotID_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotID_t * SigMgr_Data_IParkingSlotID_t_GetDataObjRef()
{
	return SigMgr_Data_IParkingSlotID_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Lock()
{
	SigMgr_Data_IParkingSlotID_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_UnLock()
{
	SigMgr_Data_IParkingSlotID_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<NFCD_Output,1> SigMgr_PpNFCDOutput_NFCD_Output;
static bool_t SigMgr_PpNFCDOutput_NFCD_Output_Init(const char *uid_name,const NFCD_Output *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpNFCDOutput_NFCD_Output.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpNFCDOutput_NFCD_Output_Put(NFCD_Output *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpNFCDOutput_NFCD_Output.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Get(NFCD_Output *data)
{
	SigMgr_PpNFCDOutput_NFCD_Output.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
NFCD_Output * SigMgr_PpNFCDOutput_NFCD_Output_GetDataObjRef()
{
	return SigMgr_PpNFCDOutput_NFCD_Output.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Lock()
{
	SigMgr_PpNFCDOutput_NFCD_Output.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_UnLock()
{
	SigMgr_PpNFCDOutput_NFCD_Output.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpNFCDOutput_NFCD_Output_RegisterCallback(void (*Callback)(const NFCD_Output * const))
{
	bool_t bRet;
	bRet=SigMgr_PpNFCDOutput_NFCD_Output.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************
static SignalMgr_ProtectedData<MOT_Output> SigMgr_Data_MOT_Output;
static bool_t SigMgr_Data_MOT_Output_Init(const char *uid_name,const MOT_Output *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_MOT_Output.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_MOT_Output_Put(MOT_Output *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_MOT_Output.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Get(MOT_Output *data)
{
	SigMgr_Data_MOT_Output.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MOT_Output * SigMgr_Data_MOT_Output_GetDataObjRef()
{
	return SigMgr_Data_MOT_Output.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Lock()
{
	SigMgr_Data_MOT_Output.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_UnLock()
{
	SigMgr_Data_MOT_Output.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_DriveAssistStatOut_t,1> SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t;
static bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Init(const char *uid_name,const TbAP_DriveAssistStatOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(TbAP_DriveAssistStatOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(TbAP_DriveAssistStatOut_t *data)
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DriveAssistStatOut_t * SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_GetDataObjRef()
{
	return SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Lock()
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_UnLock()
{
	SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_RegisterCallback(void (*Callback)(const TbAP_DriveAssistStatOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_SMDAInternalOut_t,1> SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t;
static bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Init(const char *uid_name,const TbAP_SMDAInternalOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(TbAP_SMDAInternalOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(TbAP_SMDAInternalOut_t *data)
{
	SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMDAInternalOut_t * SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_GetDataObjRef()
{
	return SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Lock()
{
	SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_UnLock()
{
	SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_RegisterCallback(void (*Callback)(const TbAP_SMDAInternalOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_SMPAInternalOut_t,1> SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t;
static bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Init(const char *uid_name,const TbAP_SMPAInternalOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(TbAP_SMPAInternalOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(TbAP_SMPAInternalOut_t *data)
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMPAInternalOut_t * SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_GetDataObjRef()
{
	return SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Lock()
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_UnLock()
{
	SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_RegisterCallback(void (*Callback)(const TbAP_SMPAInternalOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_FPAWarnOut_t,1> SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t;
static bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Init(const char *uid_name,const TbAP_FPAWarnOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(TbAP_FPAWarnOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(TbAP_FPAWarnOut_t *data)
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_FPAWarnOut_t * SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_GetDataObjRef()
{
	return SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Lock()
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_UnLock()
{
	SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_RegisterCallback(void (*Callback)(const TbAP_FPAWarnOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_RPAWarnOut_t,1> SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t;
static bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Init(const char *uid_name,const TbAP_RPAWarnOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(TbAP_RPAWarnOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(TbAP_RPAWarnOut_t *data)
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_RPAWarnOut_t * SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_GetDataObjRef()
{
	return SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Lock()
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_UnLock()
{
	SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_RegisterCallback(void (*Callback)(const TbAP_RPAWarnOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_PAStateOut_t,1> SigMgr_PpPAStateOut_TbAP_PAStateOut_t;
static bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Init(const char *uid_name,const TbAP_PAStateOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpPAStateOut_TbAP_PAStateOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(TbAP_PAStateOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpPAStateOut_TbAP_PAStateOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(TbAP_PAStateOut_t *data)
{
	SigMgr_PpPAStateOut_TbAP_PAStateOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_PAStateOut_t * SigMgr_PpPAStateOut_TbAP_PAStateOut_t_GetDataObjRef()
{
	return SigMgr_PpPAStateOut_TbAP_PAStateOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Lock()
{
	SigMgr_PpPAStateOut_TbAP_PAStateOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_UnLock()
{
	SigMgr_PpPAStateOut_TbAP_PAStateOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_RegisterCallback(void (*Callback)(const TbAP_PAStateOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpPAStateOut_TbAP_PAStateOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_VCActuatorOut_t,1> SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t;
static bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Init(const char *uid_name,const TbAP_VCActuatorOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(TbAP_VCActuatorOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Get(TbAP_VCActuatorOut_t *data)
{
	SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCActuatorOut_t * SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_GetDataObjRef()
{
	return SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Lock()
{
	SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_UnLock()
{
	SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_RegisterCallback(void (*Callback)(const TbAP_VCActuatorOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCTrajOut_t :: PpVCTrajOut_TbAP_VCTrajOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_VCTrajOut_t> SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t;
static bool_t SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Init(const char *uid_name,const TbAP_VCTrajOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Put(TbAP_VCTrajOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Get(TbAP_VCTrajOut_t *data)
{
	SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCTrajOut_t * SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_GetDataObjRef()
{
	return SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Lock()
{
	SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_UnLock()
{
	SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_VCTrajOut_t :: PpVCTrajOut_TbAP_VCTrajOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_VCStateOut_t,1> SigMgr_PpVCState_TbAP_VCStateOut_t;
static bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_Init(const char *uid_name,const TbAP_VCStateOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpVCState_TbAP_VCStateOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_Put(TbAP_VCStateOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpVCState_TbAP_VCStateOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Get(TbAP_VCStateOut_t *data)
{
	SigMgr_PpVCState_TbAP_VCStateOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCStateOut_t * SigMgr_PpVCState_TbAP_VCStateOut_t_GetDataObjRef()
{
	return SigMgr_PpVCState_TbAP_VCStateOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Lock()
{
	SigMgr_PpVCState_TbAP_VCStateOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_UnLock()
{
	SigMgr_PpVCState_TbAP_VCStateOut_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_RegisterCallback(void (*Callback)(const TbAP_VCStateOut_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpVCState_TbAP_VCStateOut_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************
static SignalMgr_ProtectedData<FID_STRUCT_QM> SigMgr_Data_FID_STRUCT_QM;
static bool_t SigMgr_Data_FID_STRUCT_QM_Init(const char *uid_name,const FID_STRUCT_QM *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_QM.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data)
{
	SigMgr_Data_FID_STRUCT_QM.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_QM.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock()
{
	SigMgr_Data_FID_STRUCT_QM.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock()
{
	SigMgr_Data_FID_STRUCT_QM.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************
static SignalMgr_ProtectedData<FID_STRUCT_B> SigMgr_Data_FID_STRUCT_B;
static bool_t SigMgr_Data_FID_STRUCT_B_Init(const char *uid_name,const FID_STRUCT_B *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FID_STRUCT_B.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data)
{
	SigMgr_Data_FID_STRUCT_B.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B * SigMgr_Data_FID_STRUCT_B_GetDataObjRef()
{
	return SigMgr_Data_FID_STRUCT_B.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock()
{
	SigMgr_Data_FID_STRUCT_B.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock()
{
	SigMgr_Data_FID_STRUCT_B.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_PointMapGroup_t,1> SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t;
static bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Init(const char *uid_name,const US_S_PointMapGroup_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put(US_S_PointMapGroup_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(US_S_PointMapGroup_t *data)
{
	SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointMapGroup_t * SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_GetDataObjRef()
{
	return SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Lock()
{
	SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_UnLock()
{
	SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_RegisterCallback(void (*Callback)(const US_S_PointMapGroup_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_SnrDirEcho_t,1> SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t;
static bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Init(const char *uid_name,const US_S_SnrDirEcho_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put(US_S_SnrDirEcho_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Get(US_S_SnrDirEcho_t *data)
{
	SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_SnrDirEcho_t * SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_GetDataObjRef()
{
	return SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Lock()
{
	SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_UnLock()
{
	SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_RegisterCallback(void (*Callback)(const US_S_SnrDirEcho_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_ZoneInfo_t,1> SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t;
static bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Init(const char *uid_name,const US_S_ZoneInfo_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put(US_S_ZoneInfo_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Get(US_S_ZoneInfo_t *data)
{
	SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_ZoneInfo_t * SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_GetDataObjRef()
{
	return SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Lock()
{
	SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_UnLock()
{
	SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_RegisterCallback(void (*Callback)(const US_S_ZoneInfo_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_BlockageBit_t,1> SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t;
static bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Init(const char *uid_name,const US_S_BlockageBit_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(US_S_BlockageBit_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(US_S_BlockageBit_t *data)
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_BlockageBit_t * SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_GetDataObjRef()
{
	return SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Lock()
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_UnLock()
{
	SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_RegisterCallback(void (*Callback)(const US_S_BlockageBit_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_USSConstantData_t,1> SigMgr_PpUSSConstantData_US_S_USSConstantData_t;
static bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Init(const char *uid_name,const US_S_USSConstantData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSConstantData_US_S_USSConstantData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put(US_S_USSConstantData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSConstantData_US_S_USSConstantData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Get(US_S_USSConstantData_t *data)
{
	SigMgr_PpUSSConstantData_US_S_USSConstantData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSConstantData_t * SigMgr_PpUSSConstantData_US_S_USSConstantData_t_GetDataObjRef()
{
	return SigMgr_PpUSSConstantData_US_S_USSConstantData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Lock()
{
	SigMgr_PpUSSConstantData_US_S_USSConstantData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_UnLock()
{
	SigMgr_PpUSSConstantData_US_S_USSConstantData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_RegisterCallback(void (*Callback)(const US_S_USSConstantData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUSSConstantData_US_S_USSConstantData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_USSPeriodDiagData_t,1> SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t;
static bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Init(const char *uid_name,const US_S_USSPeriodDiagData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put(US_S_USSPeriodDiagData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Get(US_S_USSPeriodDiagData_t *data)
{
	SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSPeriodDiagData_t * SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_GetDataObjRef()
{
	return SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Lock()
{
	SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_UnLock()
{
	SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_RegisterCallback(void (*Callback)(const US_S_USSPeriodDiagData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_USSErrorDiagData_t,1> SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t;
static bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Init(const char *uid_name,const US_S_USSErrorDiagData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(US_S_USSErrorDiagData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(US_S_USSErrorDiagData_t *data)
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSErrorDiagData_t * SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_GetDataObjRef()
{
	return SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Lock()
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_UnLock()
{
	SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_RegisterCallback(void (*Callback)(const US_S_USSErrorDiagData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<USS_Curr_Volt_Monitor_t,1> SigMgr_Data_USS_Curr_Volt_Monitor_t;
static bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_Init(const char *uid_name,const USS_Curr_Volt_Monitor_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_Curr_Volt_Monitor_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_Put(USS_Curr_Volt_Monitor_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_Curr_Volt_Monitor_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Get(USS_Curr_Volt_Monitor_t *data)
{
	SigMgr_Data_USS_Curr_Volt_Monitor_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Curr_Volt_Monitor_t * SigMgr_Data_USS_Curr_Volt_Monitor_t_GetDataObjRef()
{
	return SigMgr_Data_USS_Curr_Volt_Monitor_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Lock()
{
	SigMgr_Data_USS_Curr_Volt_Monitor_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_UnLock()
{
	SigMgr_Data_USS_Curr_Volt_Monitor_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_RegisterCallback(void (*Callback)(const USS_Curr_Volt_Monitor_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_USS_Curr_Volt_Monitor_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IFOD_Outputs_CVPAMFDData_t,1> SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t;
static bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Init(const char *uid_name,const IFOD_Outputs_CVPAMFDData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(IFOD_Outputs_CVPAMFDData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Get(IFOD_Outputs_CVPAMFDData_t *data)
{
	SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_CVPAMFDData_t * SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_GetDataObjRef()
{
	return SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Lock()
{
	SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_UnLock()
{
	SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_RegisterCallback(void (*Callback)(const IFOD_Outputs_CVPAMFDData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_MarriageSensorIDs_t,1> SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t;
static bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Init(const char *uid_name,const US_S_MarriageSensorIDs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data)
{
	SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t * SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_GetDataObjRef()
{
	return SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Lock()
{
	SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_UnLock()
{
	SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_RegisterCallback(void (*Callback)(const US_S_MarriageSensorIDs_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_MarriageSensorIDs_t,1> SigMgr_Data_US_S_MarriageSensorIDs_t;
static bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_Init(const char *uid_name,const US_S_MarriageSensorIDs_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_US_S_MarriageSensorIDs_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_US_S_MarriageSensorIDs_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data)
{
	SigMgr_Data_US_S_MarriageSensorIDs_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t * SigMgr_Data_US_S_MarriageSensorIDs_t_GetDataObjRef()
{
	return SigMgr_Data_US_S_MarriageSensorIDs_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Lock()
{
	SigMgr_Data_US_S_MarriageSensorIDs_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_UnLock()
{
	SigMgr_Data_US_S_MarriageSensorIDs_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_RegisterCallback(void (*Callback)(const US_S_MarriageSensorIDs_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_US_S_MarriageSensorIDs_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSCtoDiagMgr_t,1> SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t;
static bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Init(const char *uid_name,const TRSCtoDiagMgr_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(TRSCtoDiagMgr_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Get(TRSCtoDiagMgr_t *data)
{
	SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCtoDiagMgr_t * SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_GetDataObjRef()
{
	return SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Lock()
{
	SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_UnLock()
{
	SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_RegisterCallback(void (*Callback)(const TRSCtoDiagMgr_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_USSStateOut_t :: Data_TbAP_USSStateOut_t 
// *********************************************************************
static SignalMgr_ProtectedData<TbAP_USSStateOut_t> SigMgr_Data_TbAP_USSStateOut_t;
static bool_t SigMgr_Data_TbAP_USSStateOut_t_Init(const char *uid_name,const TbAP_USSStateOut_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbAP_USSStateOut_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbAP_USSStateOut_t_Put(TbAP_USSStateOut_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbAP_USSStateOut_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbAP_USSStateOut_t_Get(TbAP_USSStateOut_t *data)
{
	SigMgr_Data_TbAP_USSStateOut_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_USSStateOut_t * SigMgr_Data_TbAP_USSStateOut_t_GetDataObjRef()
{
	return SigMgr_Data_TbAP_USSStateOut_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbAP_USSStateOut_t_Lock()
{
	SigMgr_Data_TbAP_USSStateOut_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbAP_USSStateOut_t_UnLock()
{
	SigMgr_Data_TbAP_USSStateOut_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_USSStateOut_t :: Data_TbAP_USSStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************
static SignalMgr_ProtectedData<HMIInfoToAP_t> SigMgr_Data_HMIInfoToAP_t;
static bool_t SigMgr_Data_HMIInfoToAP_t_Init(const char *uid_name,const HMIInfoToAP_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_HMIInfoToAP_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_HMIInfoToAP_t_Put(HMIInfoToAP_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_HMIInfoToAP_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Get(HMIInfoToAP_t *data)
{
	SigMgr_Data_HMIInfoToAP_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
HMIInfoToAP_t * SigMgr_Data_HMIInfoToAP_t_GetDataObjRef()
{
	return SigMgr_Data_HMIInfoToAP_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Lock()
{
	SigMgr_Data_HMIInfoToAP_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_UnLock()
{
	SigMgr_Data_HMIInfoToAP_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************
static SignalMgr_ProtectedData<DiagToParkAssist_t> SigMgr_Data_DiagToParkAssist_t;
static bool_t SigMgr_Data_DiagToParkAssist_t_Init(const char *uid_name,const DiagToParkAssist_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_DiagToParkAssist_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToParkAssist_t_Put(DiagToParkAssist_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_DiagToParkAssist_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Get(DiagToParkAssist_t *data)
{
	SigMgr_Data_DiagToParkAssist_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToParkAssist_t * SigMgr_Data_DiagToParkAssist_t_GetDataObjRef()
{
	return SigMgr_Data_DiagToParkAssist_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Lock()
{
	SigMgr_Data_DiagToParkAssist_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_UnLock()
{
	SigMgr_Data_DiagToParkAssist_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<USS_PowerSelect_t,1> SigMgr_Data_USS_PowerSelect_t;
static bool_t SigMgr_Data_USS_PowerSelect_t_Init(const char *uid_name,const USS_PowerSelect_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_PowerSelect_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_PowerSelect_t_Put(USS_PowerSelect_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_PowerSelect_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Get(USS_PowerSelect_t *data)
{
	SigMgr_Data_USS_PowerSelect_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t * SigMgr_Data_USS_PowerSelect_t_GetDataObjRef()
{
	return SigMgr_Data_USS_PowerSelect_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Lock()
{
	SigMgr_Data_USS_PowerSelect_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_UnLock()
{
	SigMgr_Data_USS_PowerSelect_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_PowerSelect_t_RegisterCallback(void (*Callback)(const USS_PowerSelect_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_USS_PowerSelect_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************
static SignalMgr_ProtectedData<USS_PowerSelect_t> SigMgr_Data1_USS_PowerSelect_t;
static bool_t SigMgr_Data1_USS_PowerSelect_t_Init(const char *uid_name,const USS_PowerSelect_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data1_USS_PowerSelect_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data1_USS_PowerSelect_t_Put(USS_PowerSelect_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data1_USS_PowerSelect_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Get(USS_PowerSelect_t *data)
{
	SigMgr_Data1_USS_PowerSelect_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t * SigMgr_Data1_USS_PowerSelect_t_GetDataObjRef()
{
	return SigMgr_Data1_USS_PowerSelect_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Lock()
{
	SigMgr_Data1_USS_PowerSelect_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_UnLock()
{
	SigMgr_Data1_USS_PowerSelect_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_ProxiToMCU2_1_Def_t> SigMgr_Data_ME_ProxiToMCU2_1_Def_t;
static bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Init(const char *uid_name,const ME_ProxiToMCU2_1_Def_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_1_Def_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put(ME_ProxiToMCU2_1_Def_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_ProxiToMCU2_1_Def_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(ME_ProxiToMCU2_1_Def_t *data)
{
	SigMgr_Data_ME_ProxiToMCU2_1_Def_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_1_Def_t * SigMgr_Data_ME_ProxiToMCU2_1_Def_t_GetDataObjRef()
{
	return SigMgr_Data_ME_ProxiToMCU2_1_Def_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Lock()
{
	SigMgr_Data_ME_ProxiToMCU2_1_Def_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_UnLock()
{
	SigMgr_Data_ME_ProxiToMCU2_1_Def_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_USSDataCollectionData_t,1> SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t;
static bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Init(const char *uid_name,const US_S_USSDataCollectionData_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put(US_S_USSDataCollectionData_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Get(US_S_USSDataCollectionData_t *data)
{
	SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSDataCollectionData_t * SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_GetDataObjRef()
{
	return SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Lock()
{
	SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_UnLock()
{
	SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_RegisterCallback(void (*Callback)(const US_S_USSDataCollectionData_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_PointDistOutputBuff_t,1> SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t;
static bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Init(const char *uid_name,const US_S_PointDistOutputBuff_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put(US_S_PointDistOutputBuff_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Get(US_S_PointDistOutputBuff_t *data)
{
	SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointDistOutputBuff_t * SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_GetDataObjRef()
{
	return SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Lock()
{
	SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_UnLock()
{
	SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_RegisterCallback(void (*Callback)(const US_S_PointDistOutputBuff_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<CpuLoadMcu2_1_t,1> SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t;
static bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Init(const char *uid_name,const CpuLoadMcu2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(CpuLoadMcu2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Get(CpuLoadMcu2_1_t *data)
{
	SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_1_t * SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_GetDataObjRef()
{
	return SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Lock()
{
	SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_UnLock()
{
	SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_RegisterCallback(void (*Callback)(const CpuLoadMcu2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************
static SignalMgr_ProtectedData<TbNVM_ReadParam> SigMgr_Data_TbNVM_ReadParam;
static bool_t SigMgr_Data_TbNVM_ReadParam_Init(const char *uid_name,const TbNVM_ReadParam *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbNVM_ReadParam.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbNVM_ReadParam_Put(TbNVM_ReadParam *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbNVM_ReadParam.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Get(TbNVM_ReadParam *data)
{
	SigMgr_Data_TbNVM_ReadParam.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbNVM_ReadParam * SigMgr_Data_TbNVM_ReadParam_GetDataObjRef()
{
	return SigMgr_Data_TbNVM_ReadParam.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Lock()
{
	SigMgr_Data_TbNVM_ReadParam.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_UnLock()
{
	SigMgr_Data_TbNVM_ReadParam.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData<ME_CanDebugRIDStatus_t> SigMgr_Data_ME_CanDebugRIDStatus_t;
static bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Init(const char *uid_name,const ME_CanDebugRIDStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ME_CanDebugRIDStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data)
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef()
{
	return SigMgr_Data_ME_CanDebugRIDStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock()
{
	SigMgr_Data_ME_CanDebugRIDStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IJobUSSObjectMapOutput_t,1> SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t;
static bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Init(const char *uid_name,const IJobUSSObjectMapOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put(IJobUSSObjectMapOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Get(IJobUSSObjectMapOutput_t *data)
{
	SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobUSSObjectMapOutput_t * SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_GetDataObjRef()
{
	return SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Lock()
{
	SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_UnLock()
{
	SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_RegisterCallback(void (*Callback)(const IJobUSSObjectMapOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbFA_ArbiterOutput_t,1> SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t;
static bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Init(const char *uid_name,const TbFA_ArbiterOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(TbFA_ArbiterOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Get(TbFA_ArbiterOutput_t *data)
{
	SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ArbiterOutput_t * SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_GetDataObjRef()
{
	return SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Lock()
{
	SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_UnLock()
{
	SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_RegisterCallback(void (*Callback)(const TbFA_ArbiterOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************
static SignalMgr_ProtectedData<USS_Calibration_Data_t> SigMgr_Data_USS_Calibration_Data_t;
static bool_t SigMgr_Data_USS_Calibration_Data_t_Init(const char *uid_name,const USS_Calibration_Data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_Calibration_Data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_Data_t_Put(USS_Calibration_Data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_Calibration_Data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Get(USS_Calibration_Data_t *data)
{
	SigMgr_Data_USS_Calibration_Data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_Data_t * SigMgr_Data_USS_Calibration_Data_t_GetDataObjRef()
{
	return SigMgr_Data_USS_Calibration_Data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Lock()
{
	SigMgr_Data_USS_Calibration_Data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_UnLock()
{
	SigMgr_Data_USS_Calibration_Data_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbAP_DebugOut,1> SigMgr_PpTbAPDebugOut_TbAP_DebugOut;
static bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Init(const char *uid_name,const TbAP_DebugOut *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbAPDebugOut_TbAP_DebugOut.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(TbAP_DebugOut *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbAPDebugOut_TbAP_DebugOut.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Get(TbAP_DebugOut *data)
{
	SigMgr_PpTbAPDebugOut_TbAP_DebugOut.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DebugOut * SigMgr_PpTbAPDebugOut_TbAP_DebugOut_GetDataObjRef()
{
	return SigMgr_PpTbAPDebugOut_TbAP_DebugOut.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Lock()
{
	SigMgr_PpTbAPDebugOut_TbAP_DebugOut.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_UnLock()
{
	SigMgr_PpTbAPDebugOut_TbAP_DebugOut.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_RegisterCallback(void (*Callback)(const TbAP_DebugOut * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTbAPDebugOut_TbAP_DebugOut.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<WdgCheckpointStatus_t,1> SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t;
static bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Init(const char *uid_name,const WdgCheckpointStatus_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data)
{
	SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t * SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_GetDataObjRef()
{
	return SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Lock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_UnLock()
{
	SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_RegisterCallback(void (*Callback)(const WdgCheckpointStatus_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : uint32_t :: Data_ParkingMode_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<uint32_t,1> SigMgr_Data_ParkingMode_t;
static bool_t SigMgr_Data_ParkingMode_t_Init(const char *uid_name,const uint32_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_ParkingMode_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ParkingMode_t_Put(uint32_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_ParkingMode_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ParkingMode_t_Get(uint32_t *data)
{
	SigMgr_Data_ParkingMode_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
uint32_t * SigMgr_Data_ParkingMode_t_GetDataObjRef()
{
	return SigMgr_Data_ParkingMode_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ParkingMode_t_Lock()
{
	SigMgr_Data_ParkingMode_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ParkingMode_t_UnLock()
{
	SigMgr_Data_ParkingMode_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ParkingMode_t_RegisterCallback(void (*Callback)(const uint32_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_ParkingMode_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : uint32_t :: Data_ParkingMode_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbTHASmVc_DiagMgr_t,1> SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t;
static bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Init(const char *uid_name,const TbTHASmVc_DiagMgr_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(TbTHASmVc_DiagMgr_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Get(TbTHASmVc_DiagMgr_t *data)
{
	SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_DiagMgr_t * SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_GetDataObjRef()
{
	return SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Lock()
{
	SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_UnLock()
{
	SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_RegisterCallback(void (*Callback)(const TbTHASmVc_DiagMgr_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<THA_Calibration_data_MCU2_1_t> SigMgr_Data_THA_Calibration_data_MCU2_1_t;
static bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_Init(const char *uid_name,const THA_Calibration_data_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put(THA_Calibration_data_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_THA_Calibration_data_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(THA_Calibration_data_MCU2_1_t *data)
{
	SigMgr_Data_THA_Calibration_data_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MCU2_1_t * SigMgr_Data_THA_Calibration_data_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_Data_THA_Calibration_data_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Lock()
{
	SigMgr_Data_THA_Calibration_data_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_UnLock()
{
	SigMgr_Data_THA_Calibration_data_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<TRSC_Calibration_data_MCU2_1_t> SigMgr_Data_TRSC_Calibration_data_MCU2_1_t;
static bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Init(const char *uid_name,const TRSC_Calibration_data_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put(TRSC_Calibration_data_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(TRSC_Calibration_data_MCU2_1_t *data)
{
	SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MCU2_1_t * SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Lock()
{
	SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_UnLock()
{
	SigMgr_Data_TRSC_Calibration_data_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData<APA_Calibration_data_MCU2_1_t> SigMgr_Data_APA_Calibration_data_MCU2_1_t;
static bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_Init(const char *uid_name,const APA_Calibration_data_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put(APA_Calibration_data_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_APA_Calibration_data_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(APA_Calibration_data_MCU2_1_t *data)
{
	SigMgr_Data_APA_Calibration_data_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MCU2_1_t * SigMgr_Data_APA_Calibration_data_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_Data_APA_Calibration_data_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Lock()
{
	SigMgr_Data_APA_Calibration_data_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_UnLock()
{
	SigMgr_Data_APA_Calibration_data_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData<SVS_Calibration_data_t> SigMgr_Data_SVS_Calibration_data_t;
static bool_t SigMgr_Data_SVS_Calibration_data_t_Init(const char *uid_name,const SVS_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_SVS_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_Put(SVS_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_SVS_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Get(SVS_Calibration_data_t *data)
{
	SigMgr_Data_SVS_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_Calibration_data_t * SigMgr_Data_SVS_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_SVS_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Lock()
{
	SigMgr_Data_SVS_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_UnLock()
{
	SigMgr_Data_SVS_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData<FOD_Calibration_data_t> SigMgr_Data_FOD_Calibration_data_t;
static bool_t SigMgr_Data_FOD_Calibration_data_t_Init(const char *uid_name,const FOD_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_FOD_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FOD_Calibration_data_t_Put(FOD_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_FOD_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Get(FOD_Calibration_data_t *data)
{
	SigMgr_Data_FOD_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FOD_Calibration_data_t * SigMgr_Data_FOD_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_FOD_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Lock()
{
	SigMgr_Data_FOD_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_UnLock()
{
	SigMgr_Data_FOD_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************
static SignalMgr_ProtectedData<LMD_Calibration_data_t> SigMgr_Data_LMD_Calibration_data_t;
static bool_t SigMgr_Data_LMD_Calibration_data_t_Init(const char *uid_name,const LMD_Calibration_data_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_LMD_Calibration_data_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_Put(LMD_Calibration_data_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_LMD_Calibration_data_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Get(LMD_Calibration_data_t *data)
{
	SigMgr_Data_LMD_Calibration_data_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Calibration_data_t * SigMgr_Data_LMD_Calibration_data_t_GetDataObjRef()
{
	return SigMgr_Data_LMD_Calibration_data_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Lock()
{
	SigMgr_Data_LMD_Calibration_data_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_UnLock()
{
	SigMgr_Data_LMD_Calibration_data_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IFOD_Outputs_Arbitration_t,1> SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t;
static bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Init(const char *uid_name,const IFOD_Outputs_Arbitration_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put(IFOD_Outputs_Arbitration_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(IFOD_Outputs_Arbitration_t *data)
{
	SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_Arbitration_t * SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_GetDataObjRef()
{
	return SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Lock()
{
	SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_UnLock()
{
	SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_RegisterCallback(void (*Callback)(const IFOD_Outputs_Arbitration_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<IDebug_FODObject_t,1> SigMgr_PpIDebugFODObject_IDebug_FODObject_t;
static bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Init(const char *uid_name,const IDebug_FODObject_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpIDebugFODObject_IDebug_FODObject_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(IDebug_FODObject_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpIDebugFODObject_IDebug_FODObject_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Get(IDebug_FODObject_t *data)
{
	SigMgr_PpIDebugFODObject_IDebug_FODObject_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IDebug_FODObject_t * SigMgr_PpIDebugFODObject_IDebug_FODObject_t_GetDataObjRef()
{
	return SigMgr_PpIDebugFODObject_IDebug_FODObject_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Lock()
{
	SigMgr_PpIDebugFODObject_IDebug_FODObject_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_UnLock()
{
	SigMgr_PpIDebugFODObject_IDebug_FODObject_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_RegisterCallback(void (*Callback)(const IDebug_FODObject_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpIDebugFODObject_IDebug_FODObject_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_USSStateOutput_t :: Data_TbFA_USSStateOutput_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbFA_USSStateOutput_t,1> SigMgr_Data_TbFA_USSStateOutput_t;
static bool_t SigMgr_Data_TbFA_USSStateOutput_t_Init(const char *uid_name,const TbFA_USSStateOutput_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TbFA_USSStateOutput_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbFA_USSStateOutput_t_Put(TbFA_USSStateOutput_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TbFA_USSStateOutput_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbFA_USSStateOutput_t_Get(TbFA_USSStateOutput_t *data)
{
	SigMgr_Data_TbFA_USSStateOutput_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_USSStateOutput_t * SigMgr_Data_TbFA_USSStateOutput_t_GetDataObjRef()
{
	return SigMgr_Data_TbFA_USSStateOutput_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbFA_USSStateOutput_t_Lock()
{
	SigMgr_Data_TbFA_USSStateOutput_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbFA_USSStateOutput_t_UnLock()
{
	SigMgr_Data_TbFA_USSStateOutput_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbFA_USSStateOutput_t_RegisterCallback(void (*Callback)(const TbFA_USSStateOutput_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TbFA_USSStateOutput_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbFA_USSStateOutput_t :: Data_TbFA_USSStateOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TbFA_ResetKM_t,1> SigMgr_PpTbFAResetKM_TbFA_ResetKM_t;
static bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Init(const char *uid_name,const TbFA_ResetKM_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(TbFA_ResetKM_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Get(TbFA_ResetKM_t *data)
{
	SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ResetKM_t * SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_GetDataObjRef()
{
	return SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Lock()
{
	SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_UnLock()
{
	SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_RegisterCallback(void (*Callback)(const TbFA_ResetKM_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTbFAResetKM_TbFA_ResetKM_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************
static SignalMgr_ProtectedData<USS_Calibration_data_2_t> SigMgr_Data_USS_Calibration_data_2_t;
static bool_t SigMgr_Data_USS_Calibration_data_2_t_Init(const char *uid_name,const USS_Calibration_data_2_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_USS_Calibration_data_2_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_data_2_t_Put(USS_Calibration_data_2_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_USS_Calibration_data_2_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Get(USS_Calibration_data_2_t *data)
{
	SigMgr_Data_USS_Calibration_data_2_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_data_2_t * SigMgr_Data_USS_Calibration_data_2_t_GetDataObjRef()
{
	return SigMgr_Data_USS_Calibration_data_2_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Lock()
{
	SigMgr_Data_USS_Calibration_data_2_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_UnLock()
{
	SigMgr_Data_USS_Calibration_data_2_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************
static SignalMgr_ProtectedData<INVMSignalManager_t> SigMgr_Data_INVMSignalManager_t;
static bool_t SigMgr_Data_INVMSignalManager_t_Init(const char *uid_name,const INVMSignalManager_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_INVMSignalManager_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_INVMSignalManager_t_Put(INVMSignalManager_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_INVMSignalManager_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Get(INVMSignalManager_t *data)
{
	SigMgr_Data_INVMSignalManager_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
INVMSignalManager_t * SigMgr_Data_INVMSignalManager_t_GetDataObjRef()
{
	return SigMgr_Data_INVMSignalManager_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Lock()
{
	SigMgr_Data_INVMSignalManager_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_UnLock()
{
	SigMgr_Data_INVMSignalManager_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TRSCSMVCtoDebugCAN_t,1> SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t;
static bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Init(const char *uid_name,const TRSCSMVCtoDebugCAN_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(TRSCSMVCtoDebugCAN_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Get(TRSCSMVCtoDebugCAN_t *data)
{
	SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoDebugCAN_t * SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_GetDataObjRef()
{
	return SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Lock()
{
	SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_UnLock()
{
	SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_RegisterCallback(void (*Callback)(const TRSCSMVCtoDebugCAN_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<TimeManagerProxy_TimeStamp_t,1> SigMgr_Data_TimeManagerProxy_TimeStamp_t;
static bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Init(const char *uid_name,const TimeManagerProxy_TimeStamp_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(TimeManagerProxy_TimeStamp_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(TimeManagerProxy_TimeStamp_t *data)
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TimeManagerProxy_TimeStamp_t * SigMgr_Data_TimeManagerProxy_TimeStamp_t_GetDataObjRef()
{
	return SigMgr_Data_TimeManagerProxy_TimeStamp_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Lock()
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_UnLock()
{
	SigMgr_Data_TimeManagerProxy_TimeStamp_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(void (*Callback)(const TimeManagerProxy_TimeStamp_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_TimeManagerProxy_TimeStamp_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_CsmStateChangeReason_Type,1> SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type;
static bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Init(const char *uid_name,const US_S_CsmStateChangeReason_Type *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put(US_S_CsmStateChangeReason_Type *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Get(US_S_CsmStateChangeReason_Type *data)
{
	SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_CsmStateChangeReason_Type * SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_GetDataObjRef()
{
	return SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Lock()
{
	SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_UnLock()
{
	SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_RegisterCallback(void (*Callback)(const US_S_CsmStateChangeReason_Type * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<US_S_DebugMsg_t,1> SigMgr_PpUssDebugMsg_US_S_DebugMsg_t;
static bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Init(const char *uid_name,const US_S_DebugMsg_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put(US_S_DebugMsg_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Get(US_S_DebugMsg_t *data)
{
	SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_DebugMsg_t * SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_GetDataObjRef()
{
	return SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Lock()
{
	SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_UnLock()
{
	SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_RegisterCallback(void (*Callback)(const US_S_DebugMsg_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssDebugMsg_US_S_DebugMsg_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<Error_Fault_MCU2_1_t,1> SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t;
static bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Init(const char *uid_name,const Error_Fault_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put(Error_Fault_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Get(Error_Fault_MCU2_1_t *data)
{
	SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_1_t * SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Lock()
{
	SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_UnLock()
{
	SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_RegisterCallback(void (*Callback)(const Error_Fault_MCU2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<UssTunningData_mcu1_0_t,1> SigMgr_Data_UssTunningData_mcu1_0_t;
static bool_t SigMgr_Data_UssTunningData_mcu1_0_t_Init(const char *uid_name,const UssTunningData_mcu1_0_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_UssTunningData_mcu1_0_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_Put(UssTunningData_mcu1_0_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_UssTunningData_mcu1_0_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Get(UssTunningData_mcu1_0_t *data)
{
	SigMgr_Data_UssTunningData_mcu1_0_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu1_0_t * SigMgr_Data_UssTunningData_mcu1_0_t_GetDataObjRef()
{
	return SigMgr_Data_UssTunningData_mcu1_0_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Lock()
{
	SigMgr_Data_UssTunningData_mcu1_0_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_UnLock()
{
	SigMgr_Data_UssTunningData_mcu1_0_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu1_0_t * const))
{
	bool_t bRet;
	bRet=SigMgr_Data_UssTunningData_mcu1_0_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<UssTunningData_mcu2_1_t,2> SigMgr_PpUssTunData_UssTunningData_mcu2_1_t;
static bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Init(const char *uid_name,const UssTunningData_mcu2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(UssTunningData_mcu2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Get(UssTunningData_mcu2_1_t *data)
{
	SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu2_1_t * SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_GetDataObjRef()
{
	return SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Lock()
{
	SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_UnLock()
{
	SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpUssTunData_UssTunningData_mcu2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<RunTimeStats_MCU2_1_t,1> SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t;
static bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Init(const char *uid_name,const RunTimeStats_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(RunTimeStats_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Get(RunTimeStats_MCU2_1_t *data)
{
	SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_1_t * SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Lock()
{
	SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_UnLock()
{
	SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_RegisterCallback(void (*Callback)(const RunTimeStats_MCU2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************
static SignalMgr_ProtectedData<PerformanceStatsEnable_t> SigMgr_Data_PerformanceStatsEnable_t;
static bool_t SigMgr_Data_PerformanceStatsEnable_t_Init(const char *uid_name,const PerformanceStatsEnable_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_Data_PerformanceStatsEnable_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data)
{
	SigMgr_Data_PerformanceStatsEnable_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef()
{
	return SigMgr_Data_PerformanceStatsEnable_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock()
{
	SigMgr_Data_PerformanceStatsEnable_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock()
{
	SigMgr_Data_PerformanceStatsEnable_t.unlock();
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************
static SignalMgr_ProtectedData_WithNotifier<StackUsage_MCU2_1_t,1> SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t;
static bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Init(const char *uid_name,const StackUsage_MCU2_1_t *InitVal,bool_t ZeroOut)
{
	bool_t bRet=FALSE;
	if((uid_name != NULL) && (SigDef_GetInitState() == FALSE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.Init(uid_name,InitVal,ZeroOut);
	}
	return bRet;
}

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(StackUsage_MCU2_1_t *data)
{
	bool_t bRet=FALSE;
	if((data != NULL) && (SigDef_GetInitState() == TRUE))
	{
		bRet=SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.Set(data);
	}
	return bRet;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Get(StackUsage_MCU2_1_t *data)
{
	SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.Get(data);
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_1_t * SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_GetDataObjRef()
{
	return SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.GetDataObjRef();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Lock()
{
	SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.lock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_UnLock()
{
	SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.unlock();
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_RegisterCallback(void (*Callback)(const StackUsage_MCU2_1_t * const))
{
	bool_t bRet;
	bRet=SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t.RegisterCallback(Callback);
	return bRet;
}
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** EndSignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** SignalDef LocalData ******************************
// *********************************************************************
static bool_t SigDef_Init_state=FALSE;
// *********************************************************************
// ****************** SignalDef Const Init Data ************************
// *********************************************************************

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init()
{
	bool_t bRet=TRUE;

	bRet &= SigMgr_PpSvsToVCAN_SvsToVCAN_t_Init("PpSvsToVCAN_SvsToVCAN_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpScreenRequest_ScreenRequest_t_Init("PpScreenRequest_ScreenRequest_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSvsToTHA_SvsToTHA_t_Init("PpSvsToTHA_SvsToTHA_t_uid",NULL,TRUE);
	bRet &= SigMgr_ME_VehInp_to_IpcSignals_data_f_Init("ME_VehInp_to_IpcSignals_data_f_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Init("PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_uid",NULL,TRUE);
	bRet &= SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Init("PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Init("PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTRSC_ME_VehOut_TRSC_t_Init("PpTRSC_ME_VehOut_TRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_data_SVStoTRSCSMVC_t_Init("data_SVStoTRSCSMVC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Init("PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Init("PpDetInpTrsc_Detection_Inputs_from_TRSC_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_0_Init("PpSR_State_MCU2_State_2_0_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_MCU2_State_2_1_Init("PpSR_State_MCU2_State_2_1_uid",NULL,TRUE);
	bRet &= SigMgr_PpSR_State_QNX_State_QNX_Init("PpSR_State_QNX_State_QNX_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SSM_SystemState_Init("Data_SSM_SystemState_uid",NULL,TRUE);
	bRet &= SigMgr_Data_CalDataProvider_MCU_2_1_Def_Init("Data_CalDataProvider_MCU_2_1_Def_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_Proxi_to_IpcSignals_t_Init("Data_ME_Proxi_to_IpcSignals_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Init("PpJobTHADetOutput_JobTHADetOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Init("PpAPSMPAOut_TbAP_APSMPAOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Init("PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IFPAInfoToHMI_t_Init("Data_IFPAInfoToHMI_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IFPAInfoToVC_t_Init("Data_IFPAInfoToVC_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IFPAInfoToPLD_t_Init("Data_IFPAInfoToPLD_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IHMIInfoToFPA_t_Init("Data_IHMIInfoToFPA_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobPLDData_IJobPLDOutput_t_Init("PpJobPLDData_IJobPLDOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IUPASensorDataV2_t_Init("Data_IUPASensorDataV2_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IPathPlannerState_t_Init("Data_IPathPlannerState_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IKinematicData_t_Init("Data_IKinematicData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ExtY_Kinematic_T_Init("Data_ExtY_Kinematic_T_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IParkingSlotInformation_t_Init("Data_IParkingSlotInformation_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpJobFPAData_IJobFPAOutput_t_Init("PpJobFPAData_IJobFPAOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IAutoParkingState_t_Init("Data_IAutoParkingState_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_IParkingSlotID_t_Init("Data_IParkingSlotID_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpNFCDOutput_NFCD_Output_Init("PpNFCDOutput_NFCD_Output_uid",NULL,TRUE);
	bRet &= SigMgr_Data_MOT_Output_Init("Data_MOT_Output_uid",NULL,TRUE);
	bRet &= SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Init("PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Init("PpSMDAInternal_TbAP_SMDAInternalOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Init("PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Init("PpFPAWarnOut_TbAP_FPAWarnOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Init("PpRPAWarnOut_TbAP_RPAWarnOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Init("PpPAStateOut_TbAP_PAStateOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Init("PpVCActuatorOut_TbAP_VCActuatorOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Init("PpVCTrajOut_TbAP_VCTrajOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpVCState_TbAP_VCStateOut_t_Init("PpVCState_TbAP_VCStateOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_QM_Init("Data_FID_STRUCT_QM_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FID_STRUCT_B_Init("Data_FID_STRUCT_B_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Init("PpUssPointMapGrp_US_S_PointMapGroup_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Init("PpSnrDirEcho_US_S_SnrDirEcho_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Init("PpUssZoneInfo_US_S_ZoneInfo_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Init("PpUSSBlockageBit_US_S_BlockageBit_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Init("PpUSSConstantData_US_S_USSConstantData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Init("PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Init("PpUSSErrorDiagData_US_S_USSErrorDiagData_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_Curr_Volt_Monitor_t_Init("Data_USS_Curr_Volt_Monitor_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Init("PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Init("PpUssMrrgData_US_S_MarriageSensorIDs_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_US_S_MarriageSensorIDs_t_Init("Data_US_S_MarriageSensorIDs_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Init("PpTrscToDiag_TRSCtoDiagMgr_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbAP_USSStateOut_t_Init("Data_TbAP_USSStateOut_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_HMIInfoToAP_t_Init("Data_HMIInfoToAP_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_DiagToParkAssist_t_Init("Data_DiagToParkAssist_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_PowerSelect_t_Init("Data_USS_PowerSelect_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data1_USS_PowerSelect_t_Init("Data1_USS_PowerSelect_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Init("Data_ME_ProxiToMCU2_1_Def_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Init("PpUssDataCollection_US_S_USSDataCollectionData_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Init("PpPointDistOpBuff_US_S_PointDistOutputBuff_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Init("PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbNVM_ReadParam_Init("Data_TbNVM_ReadParam_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ME_CanDebugRIDStatus_t_Init("Data_ME_CanDebugRIDStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Init("PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Init("PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_Calibration_Data_t_Init("Data_USS_Calibration_Data_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Init("PpTbAPDebugOut_TbAP_DebugOut_uid",NULL,TRUE);
	bRet &= SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Init("PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_ParkingMode_t_Init("Data_ParkingMode_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Init("PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_THA_Calibration_data_MCU2_1_t_Init("Data_THA_Calibration_data_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Init("Data_TRSC_Calibration_data_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_APA_Calibration_data_MCU2_1_t_Init("Data_APA_Calibration_data_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_SVS_Calibration_data_t_Init("Data_SVS_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_FOD_Calibration_data_t_Init("Data_FOD_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_LMD_Calibration_data_t_Init("Data_LMD_Calibration_data_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Init("PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Init("PpIDebugFODObject_IDebug_FODObject_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TbFA_USSStateOutput_t_Init("Data_TbFA_USSStateOutput_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Init("PpTbFAResetKM_TbFA_ResetKM_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_USS_Calibration_data_2_t_Init("Data_USS_Calibration_data_2_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_INVMSignalManager_t_Init("Data_INVMSignalManager_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Init("PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_TimeManagerProxy_TimeStamp_t_Init("Data_TimeManagerProxy_TimeStamp_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Init("PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Init("PpUssDebugMsg_US_S_DebugMsg_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Init("PpErrFltMcu2_1_Error_Fault_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_UssTunningData_mcu1_0_t_Init("Data_UssTunningData_mcu1_0_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Init("PpUssTunData_UssTunningData_mcu2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Init("PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_uid",NULL,TRUE);
	bRet &= SigMgr_Data_PerformanceStatsEnable_t_Init("Data_PerformanceStatsEnable_t_uid",NULL,TRUE);
	bRet &= SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Init("PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_uid",NULL,TRUE);

	if((bRet != FALSE))
		{SigDef_Init_state=TRUE;}

	return bRet;
}

#ifdef __cplusplus
}
#endif
static bool_t SigDef_GetInitState()
{
	return SigDef_Init_state;
}


#endif



#ifdef BUILD_MCU3_0

// *********************************************************************
// ****************** SignalDef LocalData ******************************
// *********************************************************************
static bool_t SigDef_Init_state=FALSE;
// *********************************************************************
// ****************** SignalDef Const Init Data ************************
// *********************************************************************

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init()
{
	bool_t bRet=TRUE;


	if((bRet != FALSE))
		{SigDef_Init_state=TRUE;}

	return bRet;
}

#ifdef __cplusplus
}
#endif
static bool_t SigDef_GetInitState()
{
	return SigDef_Init_state;
}


#endif



#ifdef BUILD_MCU3_1

// *********************************************************************
// ****************** SignalDef LocalData ******************************
// *********************************************************************
static bool_t SigDef_Init_state=FALSE;
// *********************************************************************
// ****************** SignalDef Const Init Data ************************
// *********************************************************************

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init()
{
	bool_t bRet=TRUE;


	if((bRet != FALSE))
		{SigDef_Init_state=TRUE;}

	return bRet;
}

#ifdef __cplusplus
}
#endif
static bool_t SigDef_GetInitState()
{
	return SigDef_Init_state;
}


#endif

