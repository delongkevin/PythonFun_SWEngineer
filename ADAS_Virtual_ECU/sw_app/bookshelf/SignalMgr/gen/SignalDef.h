#ifndef SIGNALDATA_H_INCGUARD 
#define SIGNALDATA_H_INCGUARD 

#include "PlatformDataTypes.h"
#include "SignalMgrSigTypes.h"

#ifdef BUILD_MPU1_0

// *********************************************************************
// ****************** Start SignalData : uint8_t :: data_UnknownMsg_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_UnknownMsg_t(data) SigMgr_data_UnknownMsg_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_UnknownMsg_t_Put(uint8_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_UnknownMsg_t(data) SigMgr_data_UnknownMsg_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_UnknownMsg_t_Get(uint8_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
uint8_t  * SigMgr_data_UnknownMsg_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_UnknownMsg_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_UnknownMsg_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : uint8_t :: data_UnknownMsg_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_SvsToTHADet_t(data) SigMgr_data_SvsToTHADet_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SvsToTHADet_t_Put(SvsToTHADet_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_SvsToTHADet_t(data) SigMgr_data_SvsToTHADet_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Get(SvsToTHADet_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHADet_t  * SigMgr_data_SvsToTHADet_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t  * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenResponse_ScreenResponse_t(data) SigMgr_PpScreenResponse_ScreenResponse_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Put(ScreenResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenResponse_ScreenResponse_t(data) SigMgr_PpScreenResponse_ScreenResponse_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Get(ScreenResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenResponse_t  * SigMgr_PpScreenResponse_ScreenResponse_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_RegisterCallback(void (*Callback)(const ScreenResponse_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t  * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put(ErrorMgr_ErrorCommPack_QNX_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(ErrorMgr_ErrorCommPack_QNX_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_QM  * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_QNX_QM * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put(ErrorMgr_ErrorCommPack_QNX_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(ErrorMgr_ErrorCommPack_QNX_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_B  * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_QNX_B * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t  * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_RegisterCallback(void (*Callback)(const TRSC_Inputs_from_TrailerDetection_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_MeDLD_e_RrCamSts_t(data) SigMgr_data_MeDLD_e_RrCamSts_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_MeDLD_e_RrCamSts_t_Put(MeDLD_e_RrCamSts_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_MeDLD_e_RrCamSts_t(data) SigMgr_data_MeDLD_e_RrCamSts_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Get(MeDLD_e_RrCamSts_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MeDLD_e_RrCamSts_t  * SigMgr_data_MeDLD_e_RrCamSts_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_MeDLD_e_RrCamSts_t_RegisterCallback(void (*Callback)(const MeDLD_e_RrCamSts_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(data) SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(Detection_Inputs_from_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(data) SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(Detection_Inputs_from_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Detection_Inputs_from_TRSC_t  * SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus  * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_RegisterCallback(void (*Callback)(const SSM_QNX_CoreStatus * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState  * SigMgr_Data_SSM_SystemState_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CalDataProvider_MPU_1_0_Def(data) SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put(CalDataProvider_MPU_1_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CalDataProvider_MPU_1_0_Def(data) SigMgr_Data_CalDataProvider_MPU_1_0_Def_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Get(CalDataProvider_MPU_1_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MPU_1_0_Def  * SigMgr_Data_CalDataProvider_MPU_1_0_Def_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibSMToAlgoCamCalib_t :: Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t(data) SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Put(TbSVS_e_SVSCalibSMToAlgoCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t(data) SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Get(TbSVS_e_SVSCalibSMToAlgoCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibSMToAlgoCamCalib_t  * SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_SVSCalibSMToAlgoCamCalib_t :: Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibAlgoToSMCamCalib_t :: Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t(data) SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Put(TbSVS_e_SVSCalibAlgoToSMCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t(data) SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Get(TbSVS_e_SVSCalibAlgoToSMCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibAlgoToSMCamCalib_t  * SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_SVSCalibAlgoToSMCamCalib_t :: Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(data) SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(data) SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Get(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamCurrentCalibDataToNVM_t  * SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(data) SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put(TbSVS_S_SVSCamOCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(data) SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Get(TbSVS_S_SVSCamOCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamOCCalibDataToNVM_t  * SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamOCCalibDataToNVM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(data) SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put(TbSVS_S_SVSCamSCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(data) SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Get(TbSVS_S_SVSCamSCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamSCCalibDataToNVM_t  * SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamSCCalibDataToNVM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(data) SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(data) SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Get(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamEOLCalibDataToNVM_t  * SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_RegisterCallback(void (*Callback)(const TbSVS_S_SVSCamEOLCalibDataToNVM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(data) SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(data) SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Get(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSOutputToDiagMgrCamCalib_t  * SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_RegisterCallback(void (*Callback)(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(data) SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(data) SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Get(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t  * SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(data) SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(data) SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Get(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t  * SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t  * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_RegisterCallback(void (*Callback)(const JobTHADetOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t  * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IFPAInfoToPLD_t(data) SigMgr_Data_IFPAInfoToPLD_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToPLD_t_Put(IFPAInfoToPLD_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IFPAInfoToPLD_t(data) SigMgr_Data_IFPAInfoToPLD_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Get(IFPAInfoToPLD_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToPLD_t  * SigMgr_Data_IFPAInfoToPLD_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobPLDData_IJobPLDOutput_t(data) SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(IJobPLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobPLDData_IJobPLDOutput_t(data) SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(IJobPLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobPLDOutput_t  * SigMgr_PpJobPLDData_IJobPLDOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_RegisterCallback(void (*Callback)(const IJobPLDOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t  * SigMgr_Data_IKinematicData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IParkingSlotInformation_t(data) SigMgr_Data_IParkingSlotInformation_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotInformation_t_Put(IParkingSlotInformation_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IParkingSlotInformation_t(data) SigMgr_Data_IParkingSlotInformation_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Get(IParkingSlotInformation_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotInformation_t  * SigMgr_Data_IParkingSlotInformation_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotInformation_t_RegisterCallback(void (*Callback)(const IParkingSlotInformation_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_MOT_Output(data) SigMgr_Data_MOT_Output_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_MOT_Output_Put(MOT_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_MOT_Output(data) SigMgr_Data_MOT_Output_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Get(MOT_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MOT_Output  * SigMgr_Data_MOT_Output_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_MOT_Output_RegisterCallback(void (*Callback)(const MOT_Output * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(data) SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(TbAP_DriveAssistStatOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(data) SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(TbAP_DriveAssistStatOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DriveAssistStatOut_t  * SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM  * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B  * SigMgr_Data_FID_STRUCT_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSBlockageBit_US_S_BlockageBit_t(data) SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(US_S_BlockageBit_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSBlockageBit_US_S_BlockageBit_t(data) SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(US_S_BlockageBit_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_BlockageBit_t  * SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(data) SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(US_S_USSErrorDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(data) SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(US_S_USSErrorDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSErrorDiagData_t  * SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_THARelated_ScreenReq_t(data) SigMgr_Data_THARelated_ScreenReq_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THARelated_ScreenReq_t_Put(THARelated_ScreenReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_THARelated_ScreenReq_t(data) SigMgr_Data_THARelated_ScreenReq_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Get(THARelated_ScreenReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THARelated_ScreenReq_t  * SigMgr_Data_THARelated_ScreenReq_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCamEepromData_Svs_CamEepromDataArray_t(data) SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put(Svs_CamEepromDataArray_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCamEepromData_Svs_CamEepromDataArray_t(data) SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Get(Svs_CamEepromDataArray_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Svs_CamEepromDataArray_t  * SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_RegisterCallback(void (*Callback)(const Svs_CamEepromDataArray_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(data) SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put(LMD_Outputs_CVPAMFDData2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(data) SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Get(LMD_Outputs_CVPAMFDData2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Outputs_CVPAMFDData2_t  * SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_RegisterCallback(void (*Callback)(const LMD_Outputs_CVPAMFDData2_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrailerDetectOP_TrailerDetection_Output_DID_t(data) SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put(TrailerDetection_Output_DID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrailerDetectOP_TrailerDetection_Output_DID_t(data) SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Get(TrailerDetection_Output_DID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_DID_t  * SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_RegisterCallback(void (*Callback)(const TrailerDetection_Output_DID_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_ProxiToMPU1_0_Def_t(data) SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put(ME_ProxiToMPU1_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_ProxiToMPU1_0_Def_t(data) SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Get(ME_ProxiToMPU1_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMPU1_0_Def_t  * SigMgr_Data_ME_ProxiToMPU1_0_Def_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TrscDebug_ScrRes_t(data) SigMgr_Data_TrscDebug_ScrRes_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrscDebug_ScrRes_t_Put(TrscDebug_ScrRes_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TrscDebug_ScrRes_t(data) SigMgr_Data_TrscDebug_ScrRes_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Get(TrscDebug_ScrRes_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrscDebug_ScrRes_t  * SigMgr_Data_TrscDebug_ScrRes_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrscDebug_ScrRes_t_RegisterCallback(void (*Callback)(const TrscDebug_ScrRes_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSCDebug_ScrReq_t(data) SigMgr_Data_TRSCDebug_ScrReq_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSCDebug_ScrReq_t_Put(TRSCDebug_ScrReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSCDebug_ScrReq_t(data) SigMgr_Data_TRSCDebug_ScrReq_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Get(TRSCDebug_ScrReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCDebug_ScrReq_t  * SigMgr_Data_TRSCDebug_ScrReq_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t  * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t  * SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_RegisterCallback(void (*Callback)(const WdgCheckpointStatus_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpLMDLaneOp_LMD_Lane_Outputs_s(data) SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put(LMD_Lane_Outputs_s *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpLMDLaneOp_LMD_Lane_Outputs_s(data) SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Get(LMD_Lane_Outputs_s *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Lane_Outputs_s  * SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_RegisterCallback(void (*Callback)(const LMD_Lane_Outputs_s * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_THA_Calibration_data_MPU1_0_t(data) SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put(THA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_THA_Calibration_data_MPU1_0_t(data) SigMgr_Data_THA_Calibration_data_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Get(THA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MPU1_0_t  * SigMgr_Data_THA_Calibration_data_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_APA_Calibration_data_MPU1_0_t(data) SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put(APA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_APA_Calibration_data_MPU1_0_t(data) SigMgr_Data_APA_Calibration_data_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Get(APA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MPU1_0_t  * SigMgr_Data_APA_Calibration_data_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_LMD_Calibration_data_t(data) SigMgr_Data_LMD_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_Put(LMD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_LMD_Calibration_data_t(data) SigMgr_Data_LMD_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Get(LMD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Calibration_data_t  * SigMgr_Data_LMD_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSC_Calibration_data_MPU1_0_t(data) SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put(TRSC_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSC_Calibration_data_MPU1_0_t(data) SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Get(TRSC_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MPU1_0_t  * SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(data) SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put(ME_Proxi_MPU1_0_to_MCU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(data) SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Get(ME_Proxi_MPU1_0_to_MCU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_MPU1_0_to_MCU1_0_t  * SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_RegisterCallback(void (*Callback)(const ME_Proxi_MPU1_0_to_MCU1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_SVSCalibSMToHmi_t(data) SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put(TbSVS_e_SVSCalibSMToHmi_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_SVSCalibSMToHmi_t(data) SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(TbSVS_e_SVSCalibSMToHmi_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibSMToHmi_t  * SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_RegisterCallback(void (*Callback)(const TbSVS_e_SVSCalibSMToHmi_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TrailerDetection_Output_HMI_t(data) SigMgr_Data_TrailerDetection_Output_HMI_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_Put(TrailerDetection_Output_HMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TrailerDetection_Output_HMI_t(data) SigMgr_Data_TrailerDetection_Output_HMI_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Get(TrailerDetection_Output_HMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_HMI_t  * SigMgr_Data_TrailerDetection_Output_HMI_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_RegisterCallback(void (*Callback)(const TrailerDetection_Output_HMI_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDLDOutput_JobDLDOutput_t(data) SigMgr_PpDLDOutput_JobDLDOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_Put(JobDLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDLDOutput_JobDLDOutput_t(data) SigMgr_PpDLDOutput_JobDLDOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Get(JobDLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobDLDOutput_t  * SigMgr_PpDLDOutput_JobDLDOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_RegisterCallback(void (*Callback)(const JobDLDOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpKeepAliveResponse_KeepAliveResponse_t(data) SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(KeepAliveResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpKeepAliveResponse_KeepAliveResponse_t(data) SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(KeepAliveResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
KeepAliveResponse_t  * SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_RegisterCallback(void (*Callback)(const KeepAliveResponse_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(data) SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put(Error_Fault_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(data) SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Get(Error_Fault_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MPU1_0_t  * SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_RegisterCallback(void (*Callback)(const Error_Fault_MPU1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSC_CalibrationClear_t(data) SigMgr_Data_TRSC_CalibrationClear_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_CalibrationClear_t_Put(TRSC_CalibrationClear_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSC_CalibrationClear_t(data) SigMgr_Data_TRSC_CalibrationClear_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Get(TRSC_CalibrationClear_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_CalibrationClear_t  * SigMgr_Data_TRSC_CalibrationClear_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t  * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(data) SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put(RunTimeStats_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(data) SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Get(RunTimeStats_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MPU1_0_t  * SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_RegisterCallback(void (*Callback)(const RunTimeStats_MPU1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CamHotplugStatus_t(data) SigMgr_Data_CamHotplugStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CamHotplugStatus_t_Put(CamHotplugStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CamHotplugStatus_t(data) SigMgr_Data_CamHotplugStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Get(CamHotplugStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CamHotplugStatus_t  * SigMgr_Data_CamHotplugStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************



#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init();
#ifdef __cplusplus
}
#endif


#endif



#ifdef BUILD_MCU1_0

// *********************************************************************
// ****************** Start SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSvsToVCAN_SvsToVCAN_t(data) SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(SvsToVCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSvsToVCAN_SvsToVCAN_t(data) SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(SvsToVCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToVCAN_t  * SigMgr_PpSvsToVCAN_SvsToVCAN_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVStoTRSC_SVStoTRSC_t(data) SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put(SVStoTRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVStoTRSC_SVStoTRSC_t(data) SigMgr_PpSVStoTRSC_SVStoTRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Get(SVStoTRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSC_t  * SigMgr_PpSVStoTRSC_SVStoTRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t  * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSvsToTHA_SvsToTHA_t(data) SigMgr_PpSvsToTHA_SvsToTHA_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Put(SvsToTHA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSvsToTHA_SvsToTHA_t(data) SigMgr_PpSvsToTHA_SvsToTHA_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Get(SvsToTHA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHA_t  * SigMgr_PpSvsToTHA_SvsToTHA_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenResponse_ScreenResponse_t(data) SigMgr_PpScreenResponse_ScreenResponse_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Put(ScreenResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenResponse_ScreenResponse_t(data) SigMgr_PpScreenResponse_ScreenResponse_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Get(ScreenResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenResponse_t  * SigMgr_PpScreenResponse_ScreenResponse_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t  * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put(ErrorMgr_ErrorCommPack_2_0_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(ErrorMgr_ErrorCommPack_2_0_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_QM  * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put(ErrorMgr_ErrorCommPack_2_0_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(ErrorMgr_ErrorCommPack_2_0_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_B  * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put(ErrorMgr_ErrorCommPack_2_1_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(ErrorMgr_ErrorCommPack_2_1_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_QM  * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put(ErrorMgr_ErrorCommPack_2_1_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(ErrorMgr_ErrorCommPack_2_1_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_B  * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put(ErrorMgr_ErrorCommPack_QNX_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(ErrorMgr_ErrorCommPack_QNX_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_QM  * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_QNX_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put(ErrorMgr_ErrorCommPack_QNX_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(ErrorMgr_ErrorCommPack_QNX_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_QNX_B  * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_QNX_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t  * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTRSC_ME_VehOut_TRSC_t(data) SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(ME_VehOut_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTRSC_ME_VehOut_TRSC_t(data) SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(ME_VehOut_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehOut_TRSC_t  * SigMgr_PpTRSC_ME_VehOut_TRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(data) SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(TRSCSMVCtoSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(data) SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(TRSCSMVCtoSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoSVS_t  * SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(data) SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(Detection_Inputs_from_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(data) SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(Detection_Inputs_from_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Detection_Inputs_from_TRSC_t  * SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus  * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState  * SigMgr_Data_SSM_SystemState_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_RegisterCallback(void (*Callback)(const SSM_SystemState * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CalDataProvider_MPU_1_0_Def(data) SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put(CalDataProvider_MPU_1_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CalDataProvider_MPU_1_0_Def(data) SigMgr_Data_CalDataProvider_MPU_1_0_Def_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Get(CalDataProvider_MPU_1_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MPU_1_0_Def  * SigMgr_Data_CalDataProvider_MPU_1_0_Def_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MPU_1_0_Def_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MPU_1_0_Def_RegisterCallback(void (*Callback)(const CalDataProvider_MPU_1_0_Def * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CalDataProvider_MPU_1_0_Def :: Data_CalDataProvider_MPU_1_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CalDataProvider_MCU_2_0_Def(data) SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put(CalDataProvider_MCU_2_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CalDataProvider_MCU_2_0_Def(data) SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get(CalDataProvider_MCU_2_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_0_Def  * SigMgr_Data_CalDataProvider_MCU_2_0_Def_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_RegisterCallback(void (*Callback)(const CalDataProvider_MCU_2_0_Def * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CalDataProvider_MCU_2_1_Def(data) SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put(CalDataProvider_MCU_2_1_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CalDataProvider_MCU_2_1_Def(data) SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(CalDataProvider_MCU_2_1_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_1_Def  * SigMgr_Data_CalDataProvider_MCU_2_1_Def_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_RegisterCallback(void (*Callback)(const CalDataProvider_MCU_2_1_Def * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(data) SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(data) SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Get(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamCurrentCalibDataToNVM_t  * SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamCurrentCalibDataToNVM_t :: PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(data) SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put(TbSVS_S_SVSCamOCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(data) SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Get(TbSVS_S_SVSCamOCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamOCCalibDataToNVM_t  * SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamOCCalibDataToNVM_t :: PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(data) SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put(TbSVS_S_SVSCamSCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(data) SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Get(TbSVS_S_SVSCamSCCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamSCCalibDataToNVM_t  * SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamSCCalibDataToNVM_t :: PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(data) SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(data) SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Get(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_S_SVSCamEOLCalibDataToNVM_t  * SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_S_SVSCamEOLCalibDataToNVM_t :: PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(data) SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(data) SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Get(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSOutputToDiagMgrCamCalib_t  * SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_SVSOutputToDiagMgrCamCalib_t :: PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(data) SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(data) SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Get(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t  * SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_RegisterCallback(void (*Callback)(const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t :: Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(data) SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(data) SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Get(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t  * SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_RegisterCallback(void (*Callback)(const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t :: Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_Proxi_to_IpcSignals_t(data) SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(ME_Proxi_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_Proxi_to_IpcSignals_t(data) SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(ME_Proxi_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_to_IpcSignals_t  * SigMgr_Data_ME_Proxi_to_IpcSignals_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_RegisterCallback(void (*Callback)(const ME_Proxi_to_IpcSignals_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t  * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpAPSMPAOut_TbAP_APSMPAOut_t(data) SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(TbAP_APSMPAOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpAPSMPAOut_TbAP_APSMPAOut_t(data) SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(TbAP_APSMPAOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_APSMPAOut_t  * SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t  * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobPLDData_IJobPLDOutput_t(data) SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(IJobPLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobPLDData_IJobPLDOutput_t(data) SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(IJobPLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobPLDOutput_t  * SigMgr_PpJobPLDData_IJobPLDOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t  * SigMgr_Data_IKinematicData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_RegisterCallback(void (*Callback)(const IKinematicData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ExtY_Kinematic_T(data) SigMgr_Data_ExtY_Kinematic_T_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_Put(ExtY_Kinematic_T *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ExtY_Kinematic_T(data) SigMgr_Data_ExtY_Kinematic_T_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Get(ExtY_Kinematic_T *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ExtY_Kinematic_T  * SigMgr_Data_ExtY_Kinematic_T_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_RegisterCallback(void (*Callback)(const ExtY_Kinematic_T * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobFPAData_IJobFPAOutput_t(data) SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(IJobFPAOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobFPAData_IJobFPAOutput_t(data) SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(IJobFPAOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobFPAOutput_t  * SigMgr_PpJobFPAData_IJobFPAOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpNFCDOutput_NFCD_Output(data) SigMgr_PpNFCDOutput_NFCD_Output_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpNFCDOutput_NFCD_Output_Put(NFCD_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpNFCDOutput_NFCD_Output(data) SigMgr_PpNFCDOutput_NFCD_Output_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Get(NFCD_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
NFCD_Output  * SigMgr_PpNFCDOutput_NFCD_Output_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(data) SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(TbAP_DriveAssistStatOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(data) SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(TbAP_DriveAssistStatOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DriveAssistStatOut_t  * SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSMDAInternal_TbAP_SMDAInternalOut_t(data) SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(TbAP_SMDAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSMDAInternal_TbAP_SMDAInternalOut_t(data) SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(TbAP_SMDAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMDAInternalOut_t  * SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(data) SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(TbAP_SMPAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(data) SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(TbAP_SMPAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMPAInternalOut_t  * SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFPAWarnOut_TbAP_FPAWarnOut_t(data) SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(TbAP_FPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFPAWarnOut_TbAP_FPAWarnOut_t(data) SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(TbAP_FPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_FPAWarnOut_t  * SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRPAWarnOut_TbAP_RPAWarnOut_t(data) SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(TbAP_RPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRPAWarnOut_TbAP_RPAWarnOut_t(data) SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(TbAP_RPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_RPAWarnOut_t  * SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpPAStateOut_TbAP_PAStateOut_t(data) SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(TbAP_PAStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpPAStateOut_TbAP_PAStateOut_t(data) SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(TbAP_PAStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_PAStateOut_t  * SigMgr_PpPAStateOut_TbAP_PAStateOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpVCActuatorOut_TbAP_VCActuatorOut_t(data) SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(TbAP_VCActuatorOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpVCActuatorOut_TbAP_VCActuatorOut_t(data) SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Get(TbAP_VCActuatorOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCActuatorOut_t  * SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpVCState_TbAP_VCStateOut_t(data) SigMgr_PpVCState_TbAP_VCStateOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_Put(TbAP_VCStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpVCState_TbAP_VCStateOut_t(data) SigMgr_PpVCState_TbAP_VCStateOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Get(TbAP_VCStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCStateOut_t  * SigMgr_PpVCState_TbAP_VCStateOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM  * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_RegisterCallback(void (*Callback)(const FID_STRUCT_QM * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B  * SigMgr_Data_FID_STRUCT_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_RegisterCallback(void (*Callback)(const FID_STRUCT_B * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssPointMapGrp_US_S_PointMapGroup_t(data) SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put(US_S_PointMapGroup_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssPointMapGrp_US_S_PointMapGroup_t(data) SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(US_S_PointMapGroup_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointMapGroup_t  * SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSnrDirEcho_US_S_SnrDirEcho_t(data) SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put(US_S_SnrDirEcho_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSnrDirEcho_US_S_SnrDirEcho_t(data) SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Get(US_S_SnrDirEcho_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_SnrDirEcho_t  * SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssZoneInfo_US_S_ZoneInfo_t(data) SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put(US_S_ZoneInfo_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssZoneInfo_US_S_ZoneInfo_t(data) SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Get(US_S_ZoneInfo_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_ZoneInfo_t  * SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSBlockageBit_US_S_BlockageBit_t(data) SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(US_S_BlockageBit_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSBlockageBit_US_S_BlockageBit_t(data) SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(US_S_BlockageBit_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_BlockageBit_t  * SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSConstantData_US_S_USSConstantData_t(data) SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put(US_S_USSConstantData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSConstantData_US_S_USSConstantData_t(data) SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Get(US_S_USSConstantData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSConstantData_t  * SigMgr_PpUSSConstantData_US_S_USSConstantData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(data) SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put(US_S_USSPeriodDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(data) SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Get(US_S_USSPeriodDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSPeriodDiagData_t  * SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(data) SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(US_S_USSErrorDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(data) SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(US_S_USSErrorDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSErrorDiagData_t  * SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_Curr_Volt_Monitor_t(data) SigMgr_Data_USS_Curr_Volt_Monitor_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_Put(USS_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_Curr_Volt_Monitor_t(data) SigMgr_Data_USS_Curr_Volt_Monitor_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Get(USS_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Curr_Volt_Monitor_t  * SigMgr_Data_USS_Curr_Volt_Monitor_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_RegisterCallback(void (*Callback)(const USS_Curr_Volt_Monitor_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCamEepromData_Svs_CamEepromDataArray_t(data) SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put(Svs_CamEepromDataArray_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCamEepromData_Svs_CamEepromDataArray_t(data) SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Get(Svs_CamEepromDataArray_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Svs_CamEepromDataArray_t  * SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Svs_CamEepromDataArray_t :: PpCamEepromData_Svs_CamEepromDataArray_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_DiagToSVS_t(data) SigMgr_Data_DiagToSVS_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToSVS_t_Put(DiagToSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_DiagToSVS_t(data) SigMgr_Data_DiagToSVS_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Get(DiagToSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToSVS_t  * SigMgr_Data_DiagToSVS_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToSVS_t_RegisterCallback(void (*Callback)(const DiagToSVS_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSToDiag_SVSToDiag_t(data) SigMgr_PpSVSToDiag_SVSToDiag_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_Put(SVSToDiag_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSToDiag_SVSToDiag_t(data) SigMgr_PpSVSToDiag_SVSToDiag_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Get(SVSToDiag_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVSToDiag_t  * SigMgr_PpSVSToDiag_SVSToDiag_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(data) SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(IFOD_Outputs_CVPAMFDData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(data) SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Get(IFOD_Outputs_CVPAMFDData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_CVPAMFDData_t  * SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(data) SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put(LMD_Outputs_CVPAMFDData2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(data) SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Get(LMD_Outputs_CVPAMFDData2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Outputs_CVPAMFDData2_t  * SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Outputs_CVPAMFDData2_t :: PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CAM_Curr_Volt_Monitor_t(data) SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put(CAM_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CAM_Curr_Volt_Monitor_t(data) SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(CAM_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_Curr_Volt_Monitor_t  * SigMgr_Data_CAM_Curr_Volt_Monitor_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_RegisterCallback(void (*Callback)(const CAM_Curr_Volt_Monitor_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCamCsData_CAM_CS_Curr_Monitor_t(data) SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(CAM_CS_Curr_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCamCsData_CAM_CS_Curr_Monitor_t(data) SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Get(CAM_CS_Curr_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_CS_Curr_Monitor_t  * SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssMrrgData_US_S_MarriageSensorIDs_t(data) SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssMrrgData_US_S_MarriageSensorIDs_t(data) SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t  * SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_US_S_MarriageSensorIDs_t(data) SigMgr_Data_US_S_MarriageSensorIDs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_US_S_MarriageSensorIDs_t(data) SigMgr_Data_US_S_MarriageSensorIDs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t  * SigMgr_Data_US_S_MarriageSensorIDs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_RegisterCallback(void (*Callback)(const US_S_MarriageSensorIDs_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscToDiag_TRSCtoDiagMgr_t(data) SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(TRSCtoDiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscToDiag_TRSCtoDiagMgr_t(data) SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Get(TRSCtoDiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCtoDiagMgr_t  * SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrailerDetectOP_TrailerDetection_Output_DID_t(data) SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put(TrailerDetection_Output_DID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrailerDetectOP_TrailerDetection_Output_DID_t(data) SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Get(TrailerDetection_Output_DID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_DID_t  * SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TrailerDetection_Output_DID_t :: PpTrailerDetectOP_TrailerDetection_Output_DID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_DiagToParkAssist_t(data) SigMgr_Data_DiagToParkAssist_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToParkAssist_t_Put(DiagToParkAssist_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_DiagToParkAssist_t(data) SigMgr_Data_DiagToParkAssist_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Get(DiagToParkAssist_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToParkAssist_t  * SigMgr_Data_DiagToParkAssist_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToParkAssist_t_RegisterCallback(void (*Callback)(const DiagToParkAssist_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_ProxiToMPU1_0_Def_t(data) SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put(ME_ProxiToMPU1_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_ProxiToMPU1_0_Def_t(data) SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Get(ME_ProxiToMPU1_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMPU1_0_Def_t  * SigMgr_Data_ME_ProxiToMPU1_0_Def_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMPU1_0_Def_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMPU1_0_Def_t_RegisterCallback(void (*Callback)(const ME_ProxiToMPU1_0_Def_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_ProxiToMPU1_0_Def_t :: Data_ME_ProxiToMPU1_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_ProxiToMCU2_0_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put(ME_ProxiToMCU2_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_ProxiToMCU2_0_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_0_Def_t  * SigMgr_Data_ME_ProxiToMCU2_0_Def_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_RegisterCallback(void (*Callback)(const ME_ProxiToMCU2_0_Def_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_ProxiToMCU2_1_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put(ME_ProxiToMCU2_1_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_ProxiToMCU2_1_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(ME_ProxiToMCU2_1_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_1_Def_t  * SigMgr_Data_ME_ProxiToMCU2_1_Def_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_RegisterCallback(void (*Callback)(const ME_ProxiToMCU2_1_Def_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssDataCollection_US_S_USSDataCollectionData_t(data) SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put(US_S_USSDataCollectionData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssDataCollection_US_S_USSDataCollectionData_t(data) SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Get(US_S_USSDataCollectionData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSDataCollectionData_t  * SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(data) SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put(US_S_PointDistOutputBuff_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(data) SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Get(US_S_PointDistOutputBuff_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointDistOutputBuff_t  * SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(data) SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(CpuLoadMcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(data) SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Get(CpuLoadMcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_1_t  * SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(data) SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(CpuLoadMcu2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(data) SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Get(CpuLoadMcu2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_0_t  * SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbNVM_ReadParam(data) SigMgr_Data_TbNVM_ReadParam_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbNVM_ReadParam_Put(TbNVM_ReadParam *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbNVM_ReadParam(data) SigMgr_Data_TbNVM_ReadParam_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Get(TbNVM_ReadParam *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbNVM_ReadParam  * SigMgr_Data_TbNVM_ReadParam_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbNVM_ReadParam_RegisterCallback(void (*Callback)(const TbNVM_ReadParam * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t  * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_RegisterCallback(void (*Callback)(const ME_CanDebugRIDStatus_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SVS_NVMData_t(data) SigMgr_Data_SVS_NVMData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_NVMData_t_Put(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SVS_NVMData_t(data) SigMgr_Data_SVS_NVMData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Get(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t  * SigMgr_Data_SVS_NVMData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_NVMData_t_RegisterCallback(void (*Callback)(const SVS_NVMData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(data) SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put(IJobUSSObjectMapOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(data) SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Get(IJobUSSObjectMapOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobUSSObjectMapOutput_t  * SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(data) SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(TbFA_ArbiterOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(data) SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Get(TbFA_ArbiterOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ArbiterOutput_t  * SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSNVMData_SVS_NVMData_t(data) SigMgr_PpSVSNVMData_SVS_NVMData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_Put(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSNVMData_SVS_NVMData_t(data) SigMgr_PpSVSNVMData_SVS_NVMData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Get(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t  * SigMgr_PpSVSNVMData_SVS_NVMData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_Calibration_Data_t(data) SigMgr_Data_USS_Calibration_Data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_Data_t_Put(USS_Calibration_Data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_Calibration_Data_t(data) SigMgr_Data_USS_Calibration_Data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Get(USS_Calibration_Data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_Data_t  * SigMgr_Data_USS_Calibration_Data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_Data_t_RegisterCallback(void (*Callback)(const USS_Calibration_Data_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbAPDebugOut_TbAP_DebugOut(data) SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(TbAP_DebugOut *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbAPDebugOut_TbAP_DebugOut(data) SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Get(TbAP_DebugOut *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DebugOut  * SigMgr_PpTbAPDebugOut_TbAP_DebugOut_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t  * SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t  * SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t  * SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpLMDLaneOp_LMD_Lane_Outputs_s(data) SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put(LMD_Lane_Outputs_s *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpLMDLaneOp_LMD_Lane_Outputs_s(data) SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Get(LMD_Lane_Outputs_s *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Lane_Outputs_s  * SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Lane_Outputs_s :: PpLMDLaneOp_LMD_Lane_Outputs_s 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(data) SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(TbTHASmVc_DiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(data) SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Get(TbTHASmVc_DiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_DiagMgr_t  * SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_THA_Calibration_data_MCU2_1_t(data) SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put(THA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_THA_Calibration_data_MCU2_1_t(data) SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(THA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MCU2_1_t  * SigMgr_Data_THA_Calibration_data_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_RegisterCallback(void (*Callback)(const THA_Calibration_data_MCU2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_THA_Calibration_data_MPU1_0_t(data) SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put(THA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_THA_Calibration_data_MPU1_0_t(data) SigMgr_Data_THA_Calibration_data_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Get(THA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MPU1_0_t  * SigMgr_Data_THA_Calibration_data_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MPU1_0_t_RegisterCallback(void (*Callback)(const THA_Calibration_data_MPU1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : THA_Calibration_data_MPU1_0_t :: Data_THA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSC_Calibration_data_MCU2_1_t(data) SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put(TRSC_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSC_Calibration_data_MCU2_1_t(data) SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(TRSC_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MCU2_1_t  * SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_RegisterCallback(void (*Callback)(const TRSC_Calibration_data_MCU2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_APA_Calibration_data_MPU1_0_t(data) SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put(APA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_APA_Calibration_data_MPU1_0_t(data) SigMgr_Data_APA_Calibration_data_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Get(APA_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MPU1_0_t  * SigMgr_Data_APA_Calibration_data_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MPU1_0_t_RegisterCallback(void (*Callback)(const APA_Calibration_data_MPU1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : APA_Calibration_data_MPU1_0_t :: Data_APA_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_APA_Calibration_data_MCU2_1_t(data) SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put(APA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_APA_Calibration_data_MCU2_1_t(data) SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(APA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MCU2_1_t  * SigMgr_Data_APA_Calibration_data_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_RegisterCallback(void (*Callback)(const APA_Calibration_data_MCU2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SVS_Calibration_data_t(data) SigMgr_Data_SVS_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_Put(SVS_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SVS_Calibration_data_t(data) SigMgr_Data_SVS_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Get(SVS_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_Calibration_data_t  * SigMgr_Data_SVS_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_RegisterCallback(void (*Callback)(const SVS_Calibration_data_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FOD_Calibration_data_t(data) SigMgr_Data_FOD_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FOD_Calibration_data_t_Put(FOD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FOD_Calibration_data_t(data) SigMgr_Data_FOD_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Get(FOD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FOD_Calibration_data_t  * SigMgr_Data_FOD_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FOD_Calibration_data_t_RegisterCallback(void (*Callback)(const FOD_Calibration_data_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_LMD_Calibration_data_t(data) SigMgr_Data_LMD_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_Put(LMD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_LMD_Calibration_data_t(data) SigMgr_Data_LMD_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Get(LMD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Calibration_data_t  * SigMgr_Data_LMD_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_RegisterCallback(void (*Callback)(const LMD_Calibration_data_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSC_Calibration_data_MPU1_0_t(data) SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put(TRSC_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSC_Calibration_data_MPU1_0_t(data) SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Get(TRSC_Calibration_data_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MPU1_0_t  * SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_RegisterCallback(void (*Callback)(const TRSC_Calibration_data_MPU1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Calibration_data_MPU1_0_t :: Data_TRSC_Calibration_data_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(data) SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put(IFOD_Outputs_Arbitration_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(data) SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(IFOD_Outputs_Arbitration_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_Arbitration_t  * SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpIDebugFODObject_IDebug_FODObject_t(data) SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(IDebug_FODObject_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpIDebugFODObject_IDebug_FODObject_t(data) SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Get(IDebug_FODObject_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IDebug_FODObject_t  * SigMgr_PpIDebugFODObject_IDebug_FODObject_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbFAResetKM_TbFA_ResetKM_t(data) SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(TbFA_ResetKM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbFAResetKM_TbFA_ResetKM_t(data) SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Get(TbFA_ResetKM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ResetKM_t  * SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(data) SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put(ME_Proxi_MPU1_0_to_MCU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(data) SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Get(ME_Proxi_MPU1_0_to_MCU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_MPU1_0_to_MCU1_0_t  * SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_Proxi_MPU1_0_to_MCU1_0_t :: PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_Calibration_data_2_t(data) SigMgr_Data_USS_Calibration_data_2_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_data_2_t_Put(USS_Calibration_data_2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_Calibration_data_2_t(data) SigMgr_Data_USS_Calibration_data_2_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Get(USS_Calibration_data_2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_data_2_t  * SigMgr_Data_USS_Calibration_data_2_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_data_2_t_RegisterCallback(void (*Callback)(const USS_Calibration_data_2_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCamSerENStat_Cam_and_Ser_EN_Status_t(data) SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(Cam_and_Ser_EN_Status_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCamSerENStat_Cam_and_Ser_EN_Status_t(data) SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Get(Cam_and_Ser_EN_Status_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Cam_and_Ser_EN_Status_t  * SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDLDOutput_JobDLDOutput_t(data) SigMgr_PpDLDOutput_JobDLDOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDLDOutput_JobDLDOutput_t_Put(JobDLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDLDOutput_JobDLDOutput_t(data) SigMgr_PpDLDOutput_JobDLDOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Get(JobDLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobDLDOutput_t  * SigMgr_PpDLDOutput_JobDLDOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDLDOutput_JobDLDOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : JobDLDOutput_t :: PpDLDOutput_JobDLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_INVMSignalManager_t(data) SigMgr_Data_INVMSignalManager_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_INVMSignalManager_t_Put(INVMSignalManager_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_INVMSignalManager_t(data) SigMgr_Data_INVMSignalManager_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Get(INVMSignalManager_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
INVMSignalManager_t  * SigMgr_Data_INVMSignalManager_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_INVMSignalManager_t_RegisterCallback(void (*Callback)(const INVMSignalManager_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(data) SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(TRSCSMVCtoDebugCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(data) SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Get(TRSCSMVCtoDebugCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoDebugCAN_t  * SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TimeManagerProxy_TimeStamp_t(data) SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(TimeManagerProxy_TimeStamp_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TimeManagerProxy_TimeStamp_t(data) SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(TimeManagerProxy_TimeStamp_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TimeManagerProxy_TimeStamp_t  * SigMgr_Data_TimeManagerProxy_TimeStamp_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(void (*Callback)(const TimeManagerProxy_TimeStamp_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(data) SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put(US_S_CsmStateChangeReason_Type *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(data) SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Get(US_S_CsmStateChangeReason_Type *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_CsmStateChangeReason_Type  * SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpKeepAliveResponse_KeepAliveResponse_t(data) SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(KeepAliveResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpKeepAliveResponse_KeepAliveResponse_t(data) SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(KeepAliveResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
KeepAliveResponse_t  * SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssDebugMsg_US_S_DebugMsg_t(data) SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put(US_S_DebugMsg_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssDebugMsg_US_S_DebugMsg_t(data) SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Get(US_S_DebugMsg_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_DebugMsg_t  * SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCAMSelInfo_CAM_select_info_t(data) SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(CAM_select_info_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCAMSelInfo_CAM_select_info_t(data) SigMgr_PpCAMSelInfo_CAM_select_info_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Get(CAM_select_info_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_select_info_t  * SigMgr_PpCAMSelInfo_CAM_select_info_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(data) SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put(Error_Fault_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(data) SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Get(Error_Fault_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_0_t  * SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(data) SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put(Error_Fault_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(data) SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Get(Error_Fault_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_1_t  * SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(data) SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put(Error_Fault_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(data) SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Get(Error_Fault_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MPU1_0_t  * SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Error_Fault_MPU1_0_t :: PpErrFltMpu1_0_Error_Fault_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSC_CalibrationClear_t(data) SigMgr_Data_TRSC_CalibrationClear_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_CalibrationClear_t_Put(TRSC_CalibrationClear_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSC_CalibrationClear_t(data) SigMgr_Data_TRSC_CalibrationClear_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Get(TRSC_CalibrationClear_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_CalibrationClear_t  * SigMgr_Data_TRSC_CalibrationClear_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_CalibrationClear_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_CalibrationClear_t_RegisterCallback(void (*Callback)(const TRSC_CalibrationClear_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_CalibrationClear_t :: Data_TRSC_CalibrationClear_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_UssTunningData_mcu1_0_t(data) SigMgr_Data_UssTunningData_mcu1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_Put(UssTunningData_mcu1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_UssTunningData_mcu1_0_t(data) SigMgr_Data_UssTunningData_mcu1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Get(UssTunningData_mcu1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu1_0_t  * SigMgr_Data_UssTunningData_mcu1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssTunData_UssTunningData_mcu2_1_t(data) SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(UssTunningData_mcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssTunData_UssTunningData_mcu2_1_t(data) SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Get(UssTunningData_mcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu2_1_t  * SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(data) SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(RunTimeStats_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(data) SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Get(RunTimeStats_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_1_t  * SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(data) SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(RunTimeStats_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(data) SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Get(RunTimeStats_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_0_t  * SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t  * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_RegisterCallback(void (*Callback)(const PerformanceStatsEnable_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(data) SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put(RunTimeStats_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(data) SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Get(RunTimeStats_MPU1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MPU1_0_t  * SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : RunTimeStats_MPU1_0_t :: PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(data) SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(StackUsage_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(data) SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Get(StackUsage_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_1_t  * SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(data) SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(StackUsage_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(data) SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Get(StackUsage_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_0_t  * SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************



#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init();
#ifdef __cplusplus
}
#endif


#endif



#ifdef BUILD_MCU2_0

// *********************************************************************
// ****************** Start SignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_SvsToTHADet_t(data) SigMgr_data_SvsToTHADet_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SvsToTHADet_t_Put(SvsToTHADet_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_SvsToTHADet_t(data) SigMgr_data_SvsToTHADet_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Get(SvsToTHADet_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHADet_t  * SigMgr_data_SvsToTHADet_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SvsToTHADet_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SvsToTHADet_t_RegisterCallback(void (*Callback)(const SvsToTHADet_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToTHADet_t :: data_SvsToTHADet_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSvsToVCAN_SvsToVCAN_t(data) SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(SvsToVCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSvsToVCAN_SvsToVCAN_t(data) SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(SvsToVCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToVCAN_t  * SigMgr_PpSvsToVCAN_SvsToVCAN_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_RegisterCallback(void (*Callback)(const SvsToVCAN_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVStoTRSC_SVStoTRSC_t(data) SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put(SVStoTRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVStoTRSC_SVStoTRSC_t(data) SigMgr_PpSVStoTRSC_SVStoTRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Get(SVStoTRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSC_t  * SigMgr_PpSVStoTRSC_SVStoTRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVStoTRSC_SVStoTRSC_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVStoTRSC_SVStoTRSC_t_RegisterCallback(void (*Callback)(const SVStoTRSC_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVStoTRSC_t :: PpSVStoTRSC_SVStoTRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t  * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_RegisterCallback(void (*Callback)(const ScreenRequest_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSvsToTHA_SvsToTHA_t(data) SigMgr_PpSvsToTHA_SvsToTHA_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Put(SvsToTHA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSvsToTHA_SvsToTHA_t(data) SigMgr_PpSvsToTHA_SvsToTHA_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Get(SvsToTHA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHA_t  * SigMgr_PpSvsToTHA_SvsToTHA_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_RegisterCallback(void (*Callback)(const SvsToTHA_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenResponse_ScreenResponse_t(data) SigMgr_PpScreenResponse_ScreenResponse_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenResponse_ScreenResponse_t_Put(ScreenResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenResponse_ScreenResponse_t(data) SigMgr_PpScreenResponse_ScreenResponse_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Get(ScreenResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenResponse_t  * SigMgr_PpScreenResponse_ScreenResponse_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenResponse_ScreenResponse_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenResponse_t :: PpScreenResponse_ScreenResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t  * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put(ErrorMgr_ErrorCommPack_2_0_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(ErrorMgr_ErrorCommPack_2_0_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_QM  * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_0_QM * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_0_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put(ErrorMgr_ErrorCommPack_2_0_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(ErrorMgr_ErrorCommPack_2_0_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_0_B  * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_0_B * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_0_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t  * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_MeDLD_e_RrCamSts_t(data) SigMgr_data_MeDLD_e_RrCamSts_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_MeDLD_e_RrCamSts_t_Put(MeDLD_e_RrCamSts_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_MeDLD_e_RrCamSts_t(data) SigMgr_data_MeDLD_e_RrCamSts_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Get(MeDLD_e_RrCamSts_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MeDLD_e_RrCamSts_t  * SigMgr_data_MeDLD_e_RrCamSts_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_MeDLD_e_RrCamSts_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : MeDLD_e_RrCamSts_t :: data_MeDLD_e_RrCamSts_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_SVStoTRSCSMVC_t(data) SigMgr_data_SVStoTRSCSMVC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SVStoTRSCSMVC_t_Put(SVStoTRSCSMVC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_SVStoTRSCSMVC_t(data) SigMgr_data_SVStoTRSCSMVC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Get(SVStoTRSCSMVC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSCSMVC_t  * SigMgr_data_SVStoTRSCSMVC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SVStoTRSCSMVC_t_RegisterCallback(void (*Callback)(const SVStoTRSCSMVC_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(data) SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(TRSCSMVCtoSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(data) SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(TRSCSMVCtoSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoSVS_t  * SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_RegisterCallback(void (*Callback)(const SSM_2_0_CoreStatus * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus  * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState  * SigMgr_Data_SSM_SystemState_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CalDataProvider_MCU_2_0_Def(data) SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put(CalDataProvider_MCU_2_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CalDataProvider_MCU_2_0_Def(data) SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get(CalDataProvider_MCU_2_0_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_0_Def  * SigMgr_Data_CalDataProvider_MCU_2_0_Def_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_0_Def_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CalDataProvider_MCU_2_0_Def :: Data_CalDataProvider_MCU_2_0_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_Proxi_to_IpcSignals_t(data) SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(ME_Proxi_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_Proxi_to_IpcSignals_t(data) SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(ME_Proxi_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_to_IpcSignals_t  * SigMgr_Data_ME_Proxi_to_IpcSignals_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t  * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t  * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IFPAInfoToHMI_t(data) SigMgr_Data_IFPAInfoToHMI_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToHMI_t_Put(IFPAInfoToHMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IFPAInfoToHMI_t(data) SigMgr_Data_IFPAInfoToHMI_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Get(IFPAInfoToHMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToHMI_t  * SigMgr_Data_IFPAInfoToHMI_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IHMIInfoToFPA_t(data) SigMgr_Data_IHMIInfoToFPA_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IHMIInfoToFPA_t_Put(IHMIInfoToFPA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IHMIInfoToFPA_t(data) SigMgr_Data_IHMIInfoToFPA_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Get(IHMIInfoToFPA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IHMIInfoToFPA_t  * SigMgr_Data_IHMIInfoToFPA_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IHMIInfoToFPA_t_RegisterCallback(void (*Callback)(const IHMIInfoToFPA_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t  * SigMgr_Data_IKinematicData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ExtY_Kinematic_T(data) SigMgr_Data_ExtY_Kinematic_T_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_Put(ExtY_Kinematic_T *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ExtY_Kinematic_T(data) SigMgr_Data_ExtY_Kinematic_T_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Get(ExtY_Kinematic_T *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ExtY_Kinematic_T  * SigMgr_Data_ExtY_Kinematic_T_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobFPAData_IJobFPAOutput_t(data) SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(IJobFPAOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobFPAData_IJobFPAOutput_t(data) SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(IJobFPAOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobFPAOutput_t  * SigMgr_PpJobFPAData_IJobFPAOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IParkingSlotID_t(data) SigMgr_Data_IParkingSlotID_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotID_t_Put(IParkingSlotID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IParkingSlotID_t(data) SigMgr_Data_IParkingSlotID_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Get(IParkingSlotID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotID_t  * SigMgr_Data_IParkingSlotID_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotID_t_RegisterCallback(void (*Callback)(const IParkingSlotID_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(data) SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(TbAP_SMPAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(data) SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(TbAP_SMPAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMPAInternalOut_t  * SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFPAWarnOut_TbAP_FPAWarnOut_t(data) SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(TbAP_FPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFPAWarnOut_TbAP_FPAWarnOut_t(data) SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(TbAP_FPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_FPAWarnOut_t  * SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRPAWarnOut_TbAP_RPAWarnOut_t(data) SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(TbAP_RPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRPAWarnOut_TbAP_RPAWarnOut_t(data) SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(TbAP_RPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_RPAWarnOut_t  * SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM  * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B  * SigMgr_Data_FID_STRUCT_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_THARelated_ScreenReq_t(data) SigMgr_Data_THARelated_ScreenReq_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THARelated_ScreenReq_t_Put(THARelated_ScreenReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_THARelated_ScreenReq_t(data) SigMgr_Data_THARelated_ScreenReq_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Get(THARelated_ScreenReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THARelated_ScreenReq_t  * SigMgr_Data_THARelated_ScreenReq_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THARelated_ScreenReq_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THARelated_ScreenReq_t_RegisterCallback(void (*Callback)(const THARelated_ScreenReq_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : THARelated_ScreenReq_t :: Data_THARelated_ScreenReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_DiagToSVS_t(data) SigMgr_Data_DiagToSVS_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToSVS_t_Put(DiagToSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_DiagToSVS_t(data) SigMgr_Data_DiagToSVS_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Get(DiagToSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToSVS_t  * SigMgr_Data_DiagToSVS_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToSVS_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : DiagToSVS_t :: Data_DiagToSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSToDiag_SVSToDiag_t(data) SigMgr_PpSVSToDiag_SVSToDiag_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_Put(SVSToDiag_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSToDiag_SVSToDiag_t(data) SigMgr_PpSVSToDiag_SVSToDiag_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Get(SVSToDiag_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVSToDiag_t  * SigMgr_PpSVSToDiag_SVSToDiag_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSToDiag_SVSToDiag_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSToDiag_SVSToDiag_t_RegisterCallback(void (*Callback)(const SVSToDiag_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVSToDiag_t :: PpSVSToDiag_SVSToDiag_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CAM_Curr_Volt_Monitor_t(data) SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put(CAM_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CAM_Curr_Volt_Monitor_t(data) SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(CAM_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_Curr_Volt_Monitor_t  * SigMgr_Data_CAM_Curr_Volt_Monitor_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CAM_Curr_Volt_Monitor_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CAM_Curr_Volt_Monitor_t :: Data_CAM_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCamCsData_CAM_CS_Curr_Monitor_t(data) SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(CAM_CS_Curr_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCamCsData_CAM_CS_Curr_Monitor_t(data) SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Get(CAM_CS_Curr_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_CS_Curr_Monitor_t  * SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_RegisterCallback(void (*Callback)(const CAM_CS_Curr_Monitor_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CAM_CS_Curr_Monitor_t :: PpCamCsData_CAM_CS_Curr_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_HMIInfoToAP_t(data) SigMgr_Data_HMIInfoToAP_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_HMIInfoToAP_t_Put(HMIInfoToAP_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_HMIInfoToAP_t(data) SigMgr_Data_HMIInfoToAP_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Get(HMIInfoToAP_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
HMIInfoToAP_t  * SigMgr_Data_HMIInfoToAP_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_HMIInfoToAP_t_RegisterCallback(void (*Callback)(const HMIInfoToAP_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_PowerSelect_t(data) SigMgr_Data_USS_PowerSelect_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_PowerSelect_t_Put(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_PowerSelect_t(data) SigMgr_Data_USS_PowerSelect_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Get(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t  * SigMgr_Data_USS_PowerSelect_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data1_USS_PowerSelect_t(data) SigMgr_Data1_USS_PowerSelect_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data1_USS_PowerSelect_t_Put(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data1_USS_PowerSelect_t(data) SigMgr_Data1_USS_PowerSelect_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Get(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t  * SigMgr_Data1_USS_PowerSelect_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data1_USS_PowerSelect_t_RegisterCallback(void (*Callback)(const USS_PowerSelect_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_ProxiToMCU2_0_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put(ME_ProxiToMCU2_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_ProxiToMCU2_0_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_0_Def_t  * SigMgr_Data_ME_ProxiToMCU2_0_Def_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_ProxiToMCU2_0_Def_t :: Data_ME_ProxiToMCU2_0_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TrscDebug_ScrRes_t(data) SigMgr_Data_TrscDebug_ScrRes_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrscDebug_ScrRes_t_Put(TrscDebug_ScrRes_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TrscDebug_ScrRes_t(data) SigMgr_Data_TrscDebug_ScrRes_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Get(TrscDebug_ScrRes_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrscDebug_ScrRes_t  * SigMgr_Data_TrscDebug_ScrRes_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrscDebug_ScrRes_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TrscDebug_ScrRes_t :: Data_TrscDebug_ScrRes_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSCDebug_ScrReq_t(data) SigMgr_Data_TRSCDebug_ScrReq_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSCDebug_ScrReq_t_Put(TRSCDebug_ScrReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSCDebug_ScrReq_t(data) SigMgr_Data_TRSCDebug_ScrReq_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Get(TRSCDebug_ScrReq_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCDebug_ScrReq_t  * SigMgr_Data_TRSCDebug_ScrReq_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSCDebug_ScrReq_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSCDebug_ScrReq_t_RegisterCallback(void (*Callback)(const TRSCDebug_ScrReq_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCDebug_ScrReq_t :: Data_TRSCDebug_ScrReq_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(data) SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(CpuLoadMcu2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(data) SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Get(CpuLoadMcu2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_0_t  * SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_RegisterCallback(void (*Callback)(const CpuLoadMcu2_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CpuLoadMcu2_0_t :: PpCpuLoadMcu2_0_CpuLoadMcu2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t  * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SVS_NVMData_t(data) SigMgr_Data_SVS_NVMData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_NVMData_t_Put(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SVS_NVMData_t(data) SigMgr_Data_SVS_NVMData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Get(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t  * SigMgr_Data_SVS_NVMData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_NVMData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_NVMData_t :: Data_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSVSNVMData_SVS_NVMData_t(data) SigMgr_PpSVSNVMData_SVS_NVMData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_Put(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSVSNVMData_SVS_NVMData_t(data) SigMgr_PpSVSNVMData_SVS_NVMData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Get(SVS_NVMData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_NVMData_t  * SigMgr_PpSVSNVMData_SVS_NVMData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSVSNVMData_SVS_NVMData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSVSNVMData_SVS_NVMData_t_RegisterCallback(void (*Callback)(const SVS_NVMData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_NVMData_t :: PpSVSNVMData_SVS_NVMData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t  * SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_RegisterCallback(void (*Callback)(const WdgCheckpointStatus_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SVS_Calibration_data_t(data) SigMgr_Data_SVS_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_Put(SVS_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SVS_Calibration_data_t(data) SigMgr_Data_SVS_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Get(SVS_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_Calibration_data_t  * SigMgr_Data_SVS_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbSVS_e_SVSCalibSMToHmi_t(data) SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put(TbSVS_e_SVSCalibSMToHmi_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbSVS_e_SVSCalibSMToHmi_t(data) SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(TbSVS_e_SVSCalibSMToHmi_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbSVS_e_SVSCalibSMToHmi_t  * SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbSVS_e_SVSCalibSMToHmi_t :: Data_TbSVS_e_SVSCalibSMToHmi_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCamSerENStat_Cam_and_Ser_EN_Status_t(data) SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(Cam_and_Ser_EN_Status_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCamSerENStat_Cam_and_Ser_EN_Status_t(data) SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Get(Cam_and_Ser_EN_Status_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Cam_and_Ser_EN_Status_t  * SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_RegisterCallback(void (*Callback)(const Cam_and_Ser_EN_Status_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Cam_and_Ser_EN_Status_t :: PpCamSerENStat_Cam_and_Ser_EN_Status_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TrailerDetection_Output_HMI_t(data) SigMgr_Data_TrailerDetection_Output_HMI_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TrailerDetection_Output_HMI_t_Put(TrailerDetection_Output_HMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TrailerDetection_Output_HMI_t(data) SigMgr_Data_TrailerDetection_Output_HMI_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Get(TrailerDetection_Output_HMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TrailerDetection_Output_HMI_t  * SigMgr_Data_TrailerDetection_Output_HMI_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TrailerDetection_Output_HMI_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TrailerDetection_Output_HMI_t :: Data_TrailerDetection_Output_HMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TimeManagerProxy_TimeStamp_t(data) SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(TimeManagerProxy_TimeStamp_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TimeManagerProxy_TimeStamp_t(data) SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(TimeManagerProxy_TimeStamp_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TimeManagerProxy_TimeStamp_t  * SigMgr_Data_TimeManagerProxy_TimeStamp_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(void (*Callback)(const TimeManagerProxy_TimeStamp_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpKeepAliveResponse_KeepAliveResponse_t(data) SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put(KeepAliveResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpKeepAliveResponse_KeepAliveResponse_t(data) SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Get(KeepAliveResponse_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
KeepAliveResponse_t  * SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : KeepAliveResponse_t :: PpKeepAliveResponse_KeepAliveResponse_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCAMSelInfo_CAM_select_info_t(data) SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(CAM_select_info_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCAMSelInfo_CAM_select_info_t(data) SigMgr_PpCAMSelInfo_CAM_select_info_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Get(CAM_select_info_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CAM_select_info_t  * SigMgr_PpCAMSelInfo_CAM_select_info_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCAMSelInfo_CAM_select_info_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_RegisterCallback(void (*Callback)(const CAM_select_info_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CAM_select_info_t :: PpCAMSelInfo_CAM_select_info_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(data) SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put(Error_Fault_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(data) SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Get(Error_Fault_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_0_t  * SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_RegisterCallback(void (*Callback)(const Error_Fault_MCU2_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Error_Fault_MCU2_0_t :: PpErrFltMcu2_0_Error_Fault_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(data) SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(RunTimeStats_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(data) SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Get(RunTimeStats_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_0_t  * SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_RegisterCallback(void (*Callback)(const RunTimeStats_MCU2_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : RunTimeStats_MCU2_0_t :: PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t  * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CamHotplugStatus_t(data) SigMgr_Data_CamHotplugStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CamHotplugStatus_t_Put(CamHotplugStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CamHotplugStatus_t(data) SigMgr_Data_CamHotplugStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Get(CamHotplugStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CamHotplugStatus_t  * SigMgr_Data_CamHotplugStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CamHotplugStatus_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CamHotplugStatus_t_RegisterCallback(void (*Callback)(const CamHotplugStatus_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CamHotplugStatus_t :: Data_CamHotplugStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(data) SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(StackUsage_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(data) SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Get(StackUsage_MCU2_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_0_t  * SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_RegisterCallback(void (*Callback)(const StackUsage_MCU2_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : StackUsage_MCU2_0_t :: PpStackUsage_MCU2_0_StackUsage_MCU2_0_t 
// *********************************************************************



#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init();
#ifdef __cplusplus
}
#endif


#endif



#ifdef BUILD_MCU2_1

// *********************************************************************
// ****************** Start SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSvsToVCAN_SvsToVCAN_t(data) SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(SvsToVCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSvsToVCAN_SvsToVCAN_t(data) SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(SvsToVCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToVCAN_t  * SigMgr_PpSvsToVCAN_SvsToVCAN_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToVCAN_SvsToVCAN_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToVCAN_t :: PpSvsToVCAN_SvsToVCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpScreenRequest_ScreenRequest_t_Put(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpScreenRequest_ScreenRequest_t(data) SigMgr_PpScreenRequest_ScreenRequest_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Get(ScreenRequest_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ScreenRequest_t  * SigMgr_PpScreenRequest_ScreenRequest_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpScreenRequest_ScreenRequest_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ScreenRequest_t :: PpScreenRequest_ScreenRequest_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSvsToTHA_SvsToTHA_t(data) SigMgr_PpSvsToTHA_SvsToTHA_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSvsToTHA_SvsToTHA_t_Put(SvsToTHA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSvsToTHA_SvsToTHA_t(data) SigMgr_PpSvsToTHA_SvsToTHA_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Get(SvsToTHA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SvsToTHA_t  * SigMgr_PpSvsToTHA_SvsToTHA_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSvsToTHA_SvsToTHA_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SvsToTHA_t :: PpSvsToTHA_SvsToTHA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_Put(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_ME_VehInp_to_IpcSignals_data_f(data) SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(ME_VehInp_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehInp_to_IpcSignals_t  * SigMgr_ME_VehInp_to_IpcSignals_data_f_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_ME_VehInp_to_IpcSignals_data_f_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback(void (*Callback)(const ME_VehInp_to_IpcSignals_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_VehInp_to_IpcSignals_t :: ME_VehInp_to_IpcSignals_data_f 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put(ErrorMgr_ErrorCommPack_2_1_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(data) SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(ErrorMgr_ErrorCommPack_2_1_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_QM  * SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_1_QM * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_1_QM :: PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put(ErrorMgr_ErrorCommPack_2_1_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(data) SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(ErrorMgr_ErrorCommPack_2_1_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ErrorMgr_ErrorCommPack_2_1_B  * SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_RegisterCallback(void (*Callback)(const ErrorMgr_ErrorCommPack_2_1_B * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ErrorMgr_ErrorCommPack_2_1_B :: PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(data) SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(TRSC_Inputs_from_TrailerDetection_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Inputs_from_TrailerDetection_t  * SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Inputs_from_TrailerDetection_t :: PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTRSC_ME_VehOut_TRSC_t(data) SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(ME_VehOut_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTRSC_ME_VehOut_TRSC_t(data) SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(ME_VehOut_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_VehOut_TRSC_t  * SigMgr_PpTRSC_ME_VehOut_TRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSC_ME_VehOut_TRSC_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSC_ME_VehOut_TRSC_t_RegisterCallback(void (*Callback)(const ME_VehOut_TRSC_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_VehOut_TRSC_t :: PpTRSC_ME_VehOut_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_data_SVStoTRSCSMVC_t(data) SigMgr_data_SVStoTRSCSMVC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_data_SVStoTRSCSMVC_t_Put(SVStoTRSCSMVC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_data_SVStoTRSCSMVC_t(data) SigMgr_data_SVStoTRSCSMVC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Get(SVStoTRSCSMVC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVStoTRSCSMVC_t  * SigMgr_data_SVStoTRSCSMVC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_data_SVStoTRSCSMVC_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVStoTRSCSMVC_t :: data_SVStoTRSCSMVC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(data) SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(TRSCSMVCtoSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(data) SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(TRSCSMVCtoSVS_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoSVS_t  * SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_RegisterCallback(void (*Callback)(const TRSCSMVCtoSVS_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCSMVCtoSVS_t :: PpTrscSmvctoSvs_TRSCSMVCtoSVS_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(data) SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(Detection_Inputs_from_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(data) SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Get(Detection_Inputs_from_TRSC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Detection_Inputs_from_TRSC_t  * SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_RegisterCallback(void (*Callback)(const Detection_Inputs_from_TRSC_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Detection_Inputs_from_TRSC_t :: PpDetInpTrsc_Detection_Inputs_from_TRSC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_0_Put(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_0(data) SigMgr_PpSR_State_MCU2_State_2_0_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_0_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_0_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_0_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_0_CoreStatus :: PpSR_State_MCU2_State_2_0 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_Put(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_MCU2_State_2_1(data) SigMgr_PpSR_State_MCU2_State_2_1_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Get(SSM_2_1_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_2_1_CoreStatus  * SigMgr_PpSR_State_MCU2_State_2_1_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_MCU2_State_2_1_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_MCU2_State_2_1_RegisterCallback(void (*Callback)(const SSM_2_1_CoreStatus * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_2_1_CoreStatus :: PpSR_State_MCU2_State_2_1 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSR_State_QNX_State_QNX_Put(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSR_State_QNX_State_QNX(data) SigMgr_PpSR_State_QNX_State_QNX_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Get(SSM_QNX_CoreStatus *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_QNX_CoreStatus  * SigMgr_PpSR_State_QNX_State_QNX_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSR_State_QNX_State_QNX_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_QNX_CoreStatus :: PpSR_State_QNX_State_QNX 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SSM_SystemState_Put(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SSM_SystemState(data) SigMgr_Data_SSM_SystemState_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Get(SSM_SystemState *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SSM_SystemState  * SigMgr_Data_SSM_SystemState_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SSM_SystemState_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SSM_SystemState :: Data_SSM_SystemState 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_CalDataProvider_MCU_2_1_Def(data) SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put(CalDataProvider_MCU_2_1_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_CalDataProvider_MCU_2_1_Def(data) SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(CalDataProvider_MCU_2_1_Def *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CalDataProvider_MCU_2_1_Def  * SigMgr_Data_CalDataProvider_MCU_2_1_Def_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_CalDataProvider_MCU_2_1_Def_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CalDataProvider_MCU_2_1_Def :: Data_CalDataProvider_MCU_2_1_Def 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_Proxi_to_IpcSignals_t(data) SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put(ME_Proxi_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_Proxi_to_IpcSignals_t(data) SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Get(ME_Proxi_to_IpcSignals_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_Proxi_to_IpcSignals_t  * SigMgr_Data_ME_Proxi_to_IpcSignals_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_Proxi_to_IpcSignals_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_Proxi_to_IpcSignals_t :: Data_ME_Proxi_to_IpcSignals_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobTHADetOutput_JobTHADetOutput_t(data) SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(JobTHADetOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
JobTHADetOutput_t  * SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : JobTHADetOutput_t :: PpJobTHADetOutput_JobTHADetOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpAPSMPAOut_TbAP_APSMPAOut_t(data) SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(TbAP_APSMPAOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpAPSMPAOut_TbAP_APSMPAOut_t(data) SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(TbAP_APSMPAOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_APSMPAOut_t  * SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_RegisterCallback(void (*Callback)(const TbAP_APSMPAOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_APSMPAOut_t :: PpAPSMPAOut_TbAP_APSMPAOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(data) SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(TbTHASmVc_FeatureOutputs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_FeatureOutputs_t  * SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_RegisterCallback(void (*Callback)(const TbTHASmVc_FeatureOutputs_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbTHASmVc_FeatureOutputs_t :: PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IFPAInfoToHMI_t(data) SigMgr_Data_IFPAInfoToHMI_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToHMI_t_Put(IFPAInfoToHMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IFPAInfoToHMI_t(data) SigMgr_Data_IFPAInfoToHMI_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Get(IFPAInfoToHMI_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToHMI_t  * SigMgr_Data_IFPAInfoToHMI_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToHMI_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToHMI_t_RegisterCallback(void (*Callback)(const IFPAInfoToHMI_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFPAInfoToHMI_t :: Data_IFPAInfoToHMI_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToVC_t :: Data_IFPAInfoToVC_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IFPAInfoToVC_t(data) SigMgr_Data_IFPAInfoToVC_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToVC_t_Put(IFPAInfoToVC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IFPAInfoToVC_t(data) SigMgr_Data_IFPAInfoToVC_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToVC_t_Get(IFPAInfoToVC_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToVC_t  * SigMgr_Data_IFPAInfoToVC_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToVC_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToVC_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFPAInfoToVC_t :: Data_IFPAInfoToVC_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IFPAInfoToPLD_t(data) SigMgr_Data_IFPAInfoToPLD_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToPLD_t_Put(IFPAInfoToPLD_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IFPAInfoToPLD_t(data) SigMgr_Data_IFPAInfoToPLD_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Get(IFPAInfoToPLD_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFPAInfoToPLD_t  * SigMgr_Data_IFPAInfoToPLD_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IFPAInfoToPLD_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IFPAInfoToPLD_t_RegisterCallback(void (*Callback)(const IFPAInfoToPLD_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFPAInfoToPLD_t :: Data_IFPAInfoToPLD_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IHMIInfoToFPA_t(data) SigMgr_Data_IHMIInfoToFPA_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IHMIInfoToFPA_t_Put(IHMIInfoToFPA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IHMIInfoToFPA_t(data) SigMgr_Data_IHMIInfoToFPA_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Get(IHMIInfoToFPA_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IHMIInfoToFPA_t  * SigMgr_Data_IHMIInfoToFPA_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IHMIInfoToFPA_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IHMIInfoToFPA_t :: Data_IHMIInfoToFPA_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobPLDData_IJobPLDOutput_t(data) SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobPLDData_IJobPLDOutput_t_Put(IJobPLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobPLDData_IJobPLDOutput_t(data) SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Get(IJobPLDOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobPLDOutput_t  * SigMgr_PpJobPLDData_IJobPLDOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobPLDData_IJobPLDOutput_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobPLDOutput_t :: PpJobPLDData_IJobPLDOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IUPASensorDataV2_t :: Data_IUPASensorDataV2_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IUPASensorDataV2_t(data) SigMgr_Data_IUPASensorDataV2_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IUPASensorDataV2_t_Put(IUPASensorDataV2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IUPASensorDataV2_t(data) SigMgr_Data_IUPASensorDataV2_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IUPASensorDataV2_t_Get(IUPASensorDataV2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IUPASensorDataV2_t  * SigMgr_Data_IUPASensorDataV2_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IUPASensorDataV2_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IUPASensorDataV2_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IUPASensorDataV2_t :: Data_IUPASensorDataV2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IPathPlannerState_t :: Data_IPathPlannerState_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IPathPlannerState_t(data) SigMgr_Data_IPathPlannerState_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IPathPlannerState_t_Put(IPathPlannerState_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IPathPlannerState_t(data) SigMgr_Data_IPathPlannerState_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IPathPlannerState_t_Get(IPathPlannerState_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IPathPlannerState_t  * SigMgr_Data_IPathPlannerState_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IPathPlannerState_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IPathPlannerState_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IPathPlannerState_t :: Data_IPathPlannerState_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IKinematicData_t_Put(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IKinematicData_t(data) SigMgr_Data_IKinematicData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Get(IKinematicData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IKinematicData_t  * SigMgr_Data_IKinematicData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IKinematicData_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IKinematicData_t :: Data_IKinematicData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ExtY_Kinematic_T(data) SigMgr_Data_ExtY_Kinematic_T_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ExtY_Kinematic_T_Put(ExtY_Kinematic_T *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ExtY_Kinematic_T(data) SigMgr_Data_ExtY_Kinematic_T_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Get(ExtY_Kinematic_T *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ExtY_Kinematic_T  * SigMgr_Data_ExtY_Kinematic_T_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ExtY_Kinematic_T_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ExtY_Kinematic_T :: Data_ExtY_Kinematic_T 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IParkingSlotInformation_t(data) SigMgr_Data_IParkingSlotInformation_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotInformation_t_Put(IParkingSlotInformation_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IParkingSlotInformation_t(data) SigMgr_Data_IParkingSlotInformation_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Get(IParkingSlotInformation_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotInformation_t  * SigMgr_Data_IParkingSlotInformation_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotInformation_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IParkingSlotInformation_t :: Data_IParkingSlotInformation_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpJobFPAData_IJobFPAOutput_t(data) SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_Put(IJobFPAOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpJobFPAData_IJobFPAOutput_t(data) SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(IJobFPAOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobFPAOutput_t  * SigMgr_PpJobFPAData_IJobFPAOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpJobFPAData_IJobFPAOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpJobFPAData_IJobFPAOutput_t_RegisterCallback(void (*Callback)(const IJobFPAOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobFPAOutput_t :: PpJobFPAData_IJobFPAOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IAutoParkingState_t :: Data_IAutoParkingState_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IAutoParkingState_t(data) SigMgr_Data_IAutoParkingState_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IAutoParkingState_t_Put(IAutoParkingState_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IAutoParkingState_t(data) SigMgr_Data_IAutoParkingState_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IAutoParkingState_t_Get(IAutoParkingState_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IAutoParkingState_t  * SigMgr_Data_IAutoParkingState_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IAutoParkingState_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IAutoParkingState_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IAutoParkingState_t :: Data_IAutoParkingState_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_IParkingSlotID_t(data) SigMgr_Data_IParkingSlotID_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_IParkingSlotID_t_Put(IParkingSlotID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_IParkingSlotID_t(data) SigMgr_Data_IParkingSlotID_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Get(IParkingSlotID_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IParkingSlotID_t  * SigMgr_Data_IParkingSlotID_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_IParkingSlotID_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IParkingSlotID_t :: Data_IParkingSlotID_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpNFCDOutput_NFCD_Output(data) SigMgr_PpNFCDOutput_NFCD_Output_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpNFCDOutput_NFCD_Output_Put(NFCD_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpNFCDOutput_NFCD_Output(data) SigMgr_PpNFCDOutput_NFCD_Output_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Get(NFCD_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
NFCD_Output  * SigMgr_PpNFCDOutput_NFCD_Output_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpNFCDOutput_NFCD_Output_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpNFCDOutput_NFCD_Output_RegisterCallback(void (*Callback)(const NFCD_Output * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : NFCD_Output :: PpNFCDOutput_NFCD_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_MOT_Output(data) SigMgr_Data_MOT_Output_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_MOT_Output_Put(MOT_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_MOT_Output(data) SigMgr_Data_MOT_Output_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Get(MOT_Output *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
MOT_Output  * SigMgr_Data_MOT_Output_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_MOT_Output_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : MOT_Output :: Data_MOT_Output 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(data) SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(TbAP_DriveAssistStatOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(data) SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(TbAP_DriveAssistStatOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DriveAssistStatOut_t  * SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_RegisterCallback(void (*Callback)(const TbAP_DriveAssistStatOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_DriveAssistStatOut_t :: PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSMDAInternal_TbAP_SMDAInternalOut_t(data) SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(TbAP_SMDAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSMDAInternal_TbAP_SMDAInternalOut_t(data) SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(TbAP_SMDAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMDAInternalOut_t  * SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_RegisterCallback(void (*Callback)(const TbAP_SMDAInternalOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_SMDAInternalOut_t :: PpSMDAInternal_TbAP_SMDAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(data) SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(TbAP_SMPAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(data) SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(TbAP_SMPAInternalOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_SMPAInternalOut_t  * SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_RegisterCallback(void (*Callback)(const TbAP_SMPAInternalOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_SMPAInternalOut_t :: PpTbAPSMPAOut_TbAP_SMPAInternalOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpFPAWarnOut_TbAP_FPAWarnOut_t(data) SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(TbAP_FPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpFPAWarnOut_TbAP_FPAWarnOut_t(data) SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(TbAP_FPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_FPAWarnOut_t  * SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_RegisterCallback(void (*Callback)(const TbAP_FPAWarnOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_FPAWarnOut_t :: PpFPAWarnOut_TbAP_FPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRPAWarnOut_TbAP_RPAWarnOut_t(data) SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(TbAP_RPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRPAWarnOut_TbAP_RPAWarnOut_t(data) SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(TbAP_RPAWarnOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_RPAWarnOut_t  * SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_RegisterCallback(void (*Callback)(const TbAP_RPAWarnOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_RPAWarnOut_t :: PpRPAWarnOut_TbAP_RPAWarnOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpPAStateOut_TbAP_PAStateOut_t(data) SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(TbAP_PAStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpPAStateOut_TbAP_PAStateOut_t(data) SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(TbAP_PAStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_PAStateOut_t  * SigMgr_PpPAStateOut_TbAP_PAStateOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPAStateOut_TbAP_PAStateOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPAStateOut_TbAP_PAStateOut_t_RegisterCallback(void (*Callback)(const TbAP_PAStateOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_PAStateOut_t :: PpPAStateOut_TbAP_PAStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpVCActuatorOut_TbAP_VCActuatorOut_t(data) SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(TbAP_VCActuatorOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpVCActuatorOut_TbAP_VCActuatorOut_t(data) SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Get(TbAP_VCActuatorOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCActuatorOut_t  * SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_RegisterCallback(void (*Callback)(const TbAP_VCActuatorOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_VCActuatorOut_t :: PpVCActuatorOut_TbAP_VCActuatorOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCTrajOut_t :: PpVCTrajOut_TbAP_VCTrajOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpVCTrajOut_TbAP_VCTrajOut_t(data) SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Put(TbAP_VCTrajOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpVCTrajOut_TbAP_VCTrajOut_t(data) SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Get(TbAP_VCTrajOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCTrajOut_t  * SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_VCTrajOut_t :: PpVCTrajOut_TbAP_VCTrajOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpVCState_TbAP_VCStateOut_t(data) SigMgr_PpVCState_TbAP_VCStateOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_Put(TbAP_VCStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpVCState_TbAP_VCStateOut_t(data) SigMgr_PpVCState_TbAP_VCStateOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Get(TbAP_VCStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_VCStateOut_t  * SigMgr_PpVCState_TbAP_VCStateOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpVCState_TbAP_VCStateOut_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpVCState_TbAP_VCStateOut_t_RegisterCallback(void (*Callback)(const TbAP_VCStateOut_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_VCStateOut_t :: PpVCState_TbAP_VCStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_QM_Put(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_QM(data) SigMgr_Data_FID_STRUCT_QM_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Get(FID_STRUCT_QM *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_QM  * SigMgr_Data_FID_STRUCT_QM_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_QM_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_QM :: Data_FID_STRUCT_QM 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FID_STRUCT_B_Put(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FID_STRUCT_B(data) SigMgr_Data_FID_STRUCT_B_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Get(FID_STRUCT_B *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FID_STRUCT_B  * SigMgr_Data_FID_STRUCT_B_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FID_STRUCT_B_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FID_STRUCT_B :: Data_FID_STRUCT_B 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssPointMapGrp_US_S_PointMapGroup_t(data) SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put(US_S_PointMapGroup_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssPointMapGrp_US_S_PointMapGroup_t(data) SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(US_S_PointMapGroup_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointMapGroup_t  * SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_RegisterCallback(void (*Callback)(const US_S_PointMapGroup_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_PointMapGroup_t :: PpUssPointMapGrp_US_S_PointMapGroup_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpSnrDirEcho_US_S_SnrDirEcho_t(data) SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put(US_S_SnrDirEcho_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpSnrDirEcho_US_S_SnrDirEcho_t(data) SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Get(US_S_SnrDirEcho_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_SnrDirEcho_t  * SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_RegisterCallback(void (*Callback)(const US_S_SnrDirEcho_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_SnrDirEcho_t :: PpSnrDirEcho_US_S_SnrDirEcho_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssZoneInfo_US_S_ZoneInfo_t(data) SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put(US_S_ZoneInfo_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssZoneInfo_US_S_ZoneInfo_t(data) SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Get(US_S_ZoneInfo_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_ZoneInfo_t  * SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_RegisterCallback(void (*Callback)(const US_S_ZoneInfo_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_ZoneInfo_t :: PpUssZoneInfo_US_S_ZoneInfo_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSBlockageBit_US_S_BlockageBit_t(data) SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put(US_S_BlockageBit_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSBlockageBit_US_S_BlockageBit_t(data) SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get(US_S_BlockageBit_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_BlockageBit_t  * SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_RegisterCallback(void (*Callback)(const US_S_BlockageBit_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_BlockageBit_t :: PpUSSBlockageBit_US_S_BlockageBit_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSConstantData_US_S_USSConstantData_t(data) SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put(US_S_USSConstantData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSConstantData_US_S_USSConstantData_t(data) SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Get(US_S_USSConstantData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSConstantData_t  * SigMgr_PpUSSConstantData_US_S_USSConstantData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSConstantData_US_S_USSConstantData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSConstantData_US_S_USSConstantData_t_RegisterCallback(void (*Callback)(const US_S_USSConstantData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSConstantData_t :: PpUSSConstantData_US_S_USSConstantData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(data) SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put(US_S_USSPeriodDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(data) SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Get(US_S_USSPeriodDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSPeriodDiagData_t  * SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_RegisterCallback(void (*Callback)(const US_S_USSPeriodDiagData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSPeriodDiagData_t :: PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(data) SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put(US_S_USSErrorDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(data) SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(US_S_USSErrorDiagData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSErrorDiagData_t  * SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_RegisterCallback(void (*Callback)(const US_S_USSErrorDiagData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSErrorDiagData_t :: PpUSSErrorDiagData_US_S_USSErrorDiagData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_Curr_Volt_Monitor_t(data) SigMgr_Data_USS_Curr_Volt_Monitor_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_Put(USS_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_Curr_Volt_Monitor_t(data) SigMgr_Data_USS_Curr_Volt_Monitor_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Get(USS_Curr_Volt_Monitor_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Curr_Volt_Monitor_t  * SigMgr_Data_USS_Curr_Volt_Monitor_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Curr_Volt_Monitor_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Curr_Volt_Monitor_t_RegisterCallback(void (*Callback)(const USS_Curr_Volt_Monitor_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_Curr_Volt_Monitor_t :: Data_USS_Curr_Volt_Monitor_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(data) SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(IFOD_Outputs_CVPAMFDData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(data) SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Get(IFOD_Outputs_CVPAMFDData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_CVPAMFDData_t  * SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_RegisterCallback(void (*Callback)(const IFOD_Outputs_CVPAMFDData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFOD_Outputs_CVPAMFDData_t :: PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssMrrgData_US_S_MarriageSensorIDs_t(data) SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssMrrgData_US_S_MarriageSensorIDs_t(data) SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t  * SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_RegisterCallback(void (*Callback)(const US_S_MarriageSensorIDs_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_MarriageSensorIDs_t :: PpUssMrrgData_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_US_S_MarriageSensorIDs_t(data) SigMgr_Data_US_S_MarriageSensorIDs_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_Put(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_US_S_MarriageSensorIDs_t(data) SigMgr_Data_US_S_MarriageSensorIDs_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Get(US_S_MarriageSensorIDs_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_MarriageSensorIDs_t  * SigMgr_Data_US_S_MarriageSensorIDs_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_US_S_MarriageSensorIDs_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_US_S_MarriageSensorIDs_t_RegisterCallback(void (*Callback)(const US_S_MarriageSensorIDs_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_MarriageSensorIDs_t :: Data_US_S_MarriageSensorIDs_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTrscToDiag_TRSCtoDiagMgr_t(data) SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(TRSCtoDiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTrscToDiag_TRSCtoDiagMgr_t(data) SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Get(TRSCtoDiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCtoDiagMgr_t  * SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_RegisterCallback(void (*Callback)(const TRSCtoDiagMgr_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCtoDiagMgr_t :: PpTrscToDiag_TRSCtoDiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_USSStateOut_t :: Data_TbAP_USSStateOut_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbAP_USSStateOut_t(data) SigMgr_Data_TbAP_USSStateOut_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbAP_USSStateOut_t_Put(TbAP_USSStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbAP_USSStateOut_t(data) SigMgr_Data_TbAP_USSStateOut_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbAP_USSStateOut_t_Get(TbAP_USSStateOut_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_USSStateOut_t  * SigMgr_Data_TbAP_USSStateOut_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbAP_USSStateOut_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbAP_USSStateOut_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_USSStateOut_t :: Data_TbAP_USSStateOut_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_HMIInfoToAP_t(data) SigMgr_Data_HMIInfoToAP_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_HMIInfoToAP_t_Put(HMIInfoToAP_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_HMIInfoToAP_t(data) SigMgr_Data_HMIInfoToAP_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Get(HMIInfoToAP_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
HMIInfoToAP_t  * SigMgr_Data_HMIInfoToAP_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_HMIInfoToAP_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : HMIInfoToAP_t :: Data_HMIInfoToAP_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_DiagToParkAssist_t(data) SigMgr_Data_DiagToParkAssist_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_DiagToParkAssist_t_Put(DiagToParkAssist_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_DiagToParkAssist_t(data) SigMgr_Data_DiagToParkAssist_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Get(DiagToParkAssist_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
DiagToParkAssist_t  * SigMgr_Data_DiagToParkAssist_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_DiagToParkAssist_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : DiagToParkAssist_t :: Data_DiagToParkAssist_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_PowerSelect_t(data) SigMgr_Data_USS_PowerSelect_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_PowerSelect_t_Put(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_PowerSelect_t(data) SigMgr_Data_USS_PowerSelect_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Get(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t  * SigMgr_Data_USS_PowerSelect_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_PowerSelect_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_PowerSelect_t_RegisterCallback(void (*Callback)(const USS_PowerSelect_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_PowerSelect_t :: Data_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data1_USS_PowerSelect_t(data) SigMgr_Data1_USS_PowerSelect_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data1_USS_PowerSelect_t_Put(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data1_USS_PowerSelect_t(data) SigMgr_Data1_USS_PowerSelect_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Get(USS_PowerSelect_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_PowerSelect_t  * SigMgr_Data1_USS_PowerSelect_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data1_USS_PowerSelect_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_PowerSelect_t :: Data1_USS_PowerSelect_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_ProxiToMCU2_1_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put(ME_ProxiToMCU2_1_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_ProxiToMCU2_1_Def_t(data) SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(ME_ProxiToMCU2_1_Def_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_ProxiToMCU2_1_Def_t  * SigMgr_Data_ME_ProxiToMCU2_1_Def_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_ProxiToMCU2_1_Def_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_ProxiToMCU2_1_Def_t :: Data_ME_ProxiToMCU2_1_Def_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssDataCollection_US_S_USSDataCollectionData_t(data) SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put(US_S_USSDataCollectionData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssDataCollection_US_S_USSDataCollectionData_t(data) SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Get(US_S_USSDataCollectionData_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_USSDataCollectionData_t  * SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_RegisterCallback(void (*Callback)(const US_S_USSDataCollectionData_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_USSDataCollectionData_t :: PpUssDataCollection_US_S_USSDataCollectionData_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(data) SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put(US_S_PointDistOutputBuff_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(data) SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Get(US_S_PointDistOutputBuff_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_PointDistOutputBuff_t  * SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_RegisterCallback(void (*Callback)(const US_S_PointDistOutputBuff_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_PointDistOutputBuff_t :: PpPointDistOpBuff_US_S_PointDistOutputBuff_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(data) SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(CpuLoadMcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(data) SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Get(CpuLoadMcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
CpuLoadMcu2_1_t  * SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_RegisterCallback(void (*Callback)(const CpuLoadMcu2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : CpuLoadMcu2_1_t :: PpCpuLoadMcu2_1_CpuLoadMcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbNVM_ReadParam(data) SigMgr_Data_TbNVM_ReadParam_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbNVM_ReadParam_Put(TbNVM_ReadParam *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbNVM_ReadParam(data) SigMgr_Data_TbNVM_ReadParam_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Get(TbNVM_ReadParam *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbNVM_ReadParam  * SigMgr_Data_TbNVM_ReadParam_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbNVM_ReadParam_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbNVM_ReadParam :: Data_TbNVM_ReadParam 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ME_CanDebugRIDStatus_t_Put(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ME_CanDebugRIDStatus_t(data) SigMgr_Data_ME_CanDebugRIDStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Get(ME_CanDebugRIDStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
ME_CanDebugRIDStatus_t  * SigMgr_Data_ME_CanDebugRIDStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ME_CanDebugRIDStatus_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : ME_CanDebugRIDStatus_t :: Data_ME_CanDebugRIDStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(data) SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put(IJobUSSObjectMapOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(data) SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Get(IJobUSSObjectMapOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IJobUSSObjectMapOutput_t  * SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_RegisterCallback(void (*Callback)(const IJobUSSObjectMapOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IJobUSSObjectMapOutput_t :: PpIJobUSSObjOp_IJobUSSObjectMapOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(data) SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(TbFA_ArbiterOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(data) SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Get(TbFA_ArbiterOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ArbiterOutput_t  * SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_RegisterCallback(void (*Callback)(const TbFA_ArbiterOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbFA_ArbiterOutput_t :: PpTbFAArbiterOutput_TbFA_ArbiterOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_Calibration_Data_t(data) SigMgr_Data_USS_Calibration_Data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_Data_t_Put(USS_Calibration_Data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_Calibration_Data_t(data) SigMgr_Data_USS_Calibration_Data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Get(USS_Calibration_Data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_Data_t  * SigMgr_Data_USS_Calibration_Data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_Data_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_Calibration_Data_t :: Data_USS_Calibration_Data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbAPDebugOut_TbAP_DebugOut(data) SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(TbAP_DebugOut *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbAPDebugOut_TbAP_DebugOut(data) SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Get(TbAP_DebugOut *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbAP_DebugOut  * SigMgr_PpTbAPDebugOut_TbAP_DebugOut_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbAPDebugOut_TbAP_DebugOut_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbAPDebugOut_TbAP_DebugOut_RegisterCallback(void (*Callback)(const TbAP_DebugOut * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbAP_DebugOut :: PpTbAPDebugOut_TbAP_DebugOut 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(data) SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Get(WdgCheckpointStatus_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
WdgCheckpointStatus_t  * SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_RegisterCallback(void (*Callback)(const WdgCheckpointStatus_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : WdgCheckpointStatus_t :: PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : uint32_t :: Data_ParkingMode_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_ParkingMode_t(data) SigMgr_Data_ParkingMode_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ParkingMode_t_Put(uint32_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_ParkingMode_t(data) SigMgr_Data_ParkingMode_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ParkingMode_t_Get(uint32_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
uint32_t  * SigMgr_Data_ParkingMode_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ParkingMode_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_ParkingMode_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_ParkingMode_t_RegisterCallback(void (*Callback)(const uint32_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : uint32_t :: Data_ParkingMode_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(data) SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(TbTHASmVc_DiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(data) SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Get(TbTHASmVc_DiagMgr_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbTHASmVc_DiagMgr_t  * SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_RegisterCallback(void (*Callback)(const TbTHASmVc_DiagMgr_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbTHASmVc_DiagMgr_t :: PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_THA_Calibration_data_MCU2_1_t(data) SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put(THA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_THA_Calibration_data_MCU2_1_t(data) SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(THA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
THA_Calibration_data_MCU2_1_t  * SigMgr_Data_THA_Calibration_data_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_THA_Calibration_data_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : THA_Calibration_data_MCU2_1_t :: Data_THA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TRSC_Calibration_data_MCU2_1_t(data) SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put(TRSC_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TRSC_Calibration_data_MCU2_1_t(data) SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(TRSC_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSC_Calibration_data_MCU2_1_t  * SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSC_Calibration_data_MCU2_1_t :: Data_TRSC_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_APA_Calibration_data_MCU2_1_t(data) SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put(APA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_APA_Calibration_data_MCU2_1_t(data) SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(APA_Calibration_data_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
APA_Calibration_data_MCU2_1_t  * SigMgr_Data_APA_Calibration_data_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_APA_Calibration_data_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : APA_Calibration_data_MCU2_1_t :: Data_APA_Calibration_data_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_SVS_Calibration_data_t(data) SigMgr_Data_SVS_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_SVS_Calibration_data_t_Put(SVS_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_SVS_Calibration_data_t(data) SigMgr_Data_SVS_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Get(SVS_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
SVS_Calibration_data_t  * SigMgr_Data_SVS_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_SVS_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : SVS_Calibration_data_t :: Data_SVS_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_FOD_Calibration_data_t(data) SigMgr_Data_FOD_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_FOD_Calibration_data_t_Put(FOD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_FOD_Calibration_data_t(data) SigMgr_Data_FOD_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Get(FOD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
FOD_Calibration_data_t  * SigMgr_Data_FOD_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_FOD_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : FOD_Calibration_data_t :: Data_FOD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_LMD_Calibration_data_t(data) SigMgr_Data_LMD_Calibration_data_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_LMD_Calibration_data_t_Put(LMD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_LMD_Calibration_data_t(data) SigMgr_Data_LMD_Calibration_data_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Get(LMD_Calibration_data_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LMD_Calibration_data_t  * SigMgr_Data_LMD_Calibration_data_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_LMD_Calibration_data_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : LMD_Calibration_data_t :: Data_LMD_Calibration_data_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(data) SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put(IFOD_Outputs_Arbitration_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(data) SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(IFOD_Outputs_Arbitration_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IFOD_Outputs_Arbitration_t  * SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_RegisterCallback(void (*Callback)(const IFOD_Outputs_Arbitration_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IFOD_Outputs_Arbitration_t :: PpIFODOpArbitration_IFOD_Outputs_Arbitration_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpIDebugFODObject_IDebug_FODObject_t(data) SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(IDebug_FODObject_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpIDebugFODObject_IDebug_FODObject_t(data) SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Get(IDebug_FODObject_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
IDebug_FODObject_t  * SigMgr_PpIDebugFODObject_IDebug_FODObject_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpIDebugFODObject_IDebug_FODObject_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpIDebugFODObject_IDebug_FODObject_t_RegisterCallback(void (*Callback)(const IDebug_FODObject_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : IDebug_FODObject_t :: PpIDebugFODObject_IDebug_FODObject_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_USSStateOutput_t :: Data_TbFA_USSStateOutput_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TbFA_USSStateOutput_t(data) SigMgr_Data_TbFA_USSStateOutput_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbFA_USSStateOutput_t_Put(TbFA_USSStateOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TbFA_USSStateOutput_t(data) SigMgr_Data_TbFA_USSStateOutput_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbFA_USSStateOutput_t_Get(TbFA_USSStateOutput_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_USSStateOutput_t  * SigMgr_Data_TbFA_USSStateOutput_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbFA_USSStateOutput_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TbFA_USSStateOutput_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TbFA_USSStateOutput_t_RegisterCallback(void (*Callback)(const TbFA_USSStateOutput_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbFA_USSStateOutput_t :: Data_TbFA_USSStateOutput_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTbFAResetKM_TbFA_ResetKM_t(data) SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(TbFA_ResetKM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTbFAResetKM_TbFA_ResetKM_t(data) SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Get(TbFA_ResetKM_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TbFA_ResetKM_t  * SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_RegisterCallback(void (*Callback)(const TbFA_ResetKM_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TbFA_ResetKM_t :: PpTbFAResetKM_TbFA_ResetKM_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_USS_Calibration_data_2_t(data) SigMgr_Data_USS_Calibration_data_2_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_USS_Calibration_data_2_t_Put(USS_Calibration_data_2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_USS_Calibration_data_2_t(data) SigMgr_Data_USS_Calibration_data_2_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Get(USS_Calibration_data_2_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
USS_Calibration_data_2_t  * SigMgr_Data_USS_Calibration_data_2_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_USS_Calibration_data_2_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : USS_Calibration_data_2_t :: Data_USS_Calibration_data_2_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_INVMSignalManager_t(data) SigMgr_Data_INVMSignalManager_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_INVMSignalManager_t_Put(INVMSignalManager_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_INVMSignalManager_t(data) SigMgr_Data_INVMSignalManager_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Get(INVMSignalManager_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
INVMSignalManager_t  * SigMgr_Data_INVMSignalManager_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_INVMSignalManager_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : INVMSignalManager_t :: Data_INVMSignalManager_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(data) SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(TRSCSMVCtoDebugCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(data) SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Get(TRSCSMVCtoDebugCAN_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TRSCSMVCtoDebugCAN_t  * SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_RegisterCallback(void (*Callback)(const TRSCSMVCtoDebugCAN_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TRSCSMVCtoDebugCAN_t :: PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_TimeManagerProxy_TimeStamp_t(data) SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put(TimeManagerProxy_TimeStamp_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_TimeManagerProxy_TimeStamp_t(data) SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(TimeManagerProxy_TimeStamp_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
TimeManagerProxy_TimeStamp_t  * SigMgr_Data_TimeManagerProxy_TimeStamp_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_TimeManagerProxy_TimeStamp_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_TimeManagerProxy_TimeStamp_t_RegisterCallback(void (*Callback)(const TimeManagerProxy_TimeStamp_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : TimeManagerProxy_TimeStamp_t :: Data_TimeManagerProxy_TimeStamp_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(data) SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put(US_S_CsmStateChangeReason_Type *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(data) SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Get(US_S_CsmStateChangeReason_Type *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_CsmStateChangeReason_Type  * SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_RegisterCallback(void (*Callback)(const US_S_CsmStateChangeReason_Type * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_CsmStateChangeReason_Type :: PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssDebugMsg_US_S_DebugMsg_t(data) SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put(US_S_DebugMsg_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssDebugMsg_US_S_DebugMsg_t(data) SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Get(US_S_DebugMsg_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
US_S_DebugMsg_t  * SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_RegisterCallback(void (*Callback)(const US_S_DebugMsg_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : US_S_DebugMsg_t :: PpUssDebugMsg_US_S_DebugMsg_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(data) SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put(Error_Fault_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(data) SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Get(Error_Fault_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
Error_Fault_MCU2_1_t  * SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_RegisterCallback(void (*Callback)(const Error_Fault_MCU2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : Error_Fault_MCU2_1_t :: PpErrFltMcu2_1_Error_Fault_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_UssTunningData_mcu1_0_t(data) SigMgr_Data_UssTunningData_mcu1_0_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_Put(UssTunningData_mcu1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_UssTunningData_mcu1_0_t(data) SigMgr_Data_UssTunningData_mcu1_0_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Get(UssTunningData_mcu1_0_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu1_0_t  * SigMgr_Data_UssTunningData_mcu1_0_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_UssTunningData_mcu1_0_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_UssTunningData_mcu1_0_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu1_0_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : UssTunningData_mcu1_0_t :: Data_UssTunningData_mcu1_0_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpUssTunData_UssTunningData_mcu2_1_t(data) SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(UssTunningData_mcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpUssTunData_UssTunningData_mcu2_1_t(data) SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Get(UssTunningData_mcu2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
UssTunningData_mcu2_1_t  * SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_RegisterCallback(void (*Callback)(const UssTunningData_mcu2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : UssTunningData_mcu2_1_t :: PpUssTunData_UssTunningData_mcu2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(data) SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(RunTimeStats_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(data) SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Get(RunTimeStats_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
RunTimeStats_MCU2_1_t  * SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_RegisterCallback(void (*Callback)(const RunTimeStats_MCU2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : RunTimeStats_MCU2_1_t :: PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_Data_PerformanceStatsEnable_t_Put(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_Data_PerformanceStatsEnable_t(data) SigMgr_Data_PerformanceStatsEnable_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Get(PerformanceStatsEnable_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
PerformanceStatsEnable_t  * SigMgr_Data_PerformanceStatsEnable_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_Data_PerformanceStatsEnable_t_UnLock();
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : PerformanceStatsEnable_t :: Data_PerformanceStatsEnable_t 
// *********************************************************************


// *********************************************************************
// ****************** Start SignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Write_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(data) SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(StackUsage_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef SIGMGR_GENERATE_RTE_INTERFACES
#define Rte_Read_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(data) SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Get(data)
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Get(StackUsage_MCU2_1_t *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
StackUsage_MCU2_1_t  * SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_GetDataObjRef();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Lock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_UnLock();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
bool_t SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_RegisterCallback(void (*Callback)(const StackUsage_MCU2_1_t * const));
#ifdef __cplusplus
}
#endif
// *********************************************************************
// ****************** End SignalData : StackUsage_MCU2_1_t :: PpStackUsage_MCU2_1_StackUsage_MCU2_1_t 
// *********************************************************************



#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init();
#ifdef __cplusplus
}
#endif


#endif



#ifdef BUILD_MCU3_0


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init();
#ifdef __cplusplus
}
#endif


#endif



#ifdef BUILD_MCU3_1


#ifdef __cplusplus
extern "C" {
#endif
bool_t SigDef_Init();
#ifdef __cplusplus
}
#endif


#endif

#endif 
