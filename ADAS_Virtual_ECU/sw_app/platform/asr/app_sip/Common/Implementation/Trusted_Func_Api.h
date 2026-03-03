#ifndef TRUSTED_FUNC_API_H
# define TRUSTED_FUNC_API_H

#include "Rte_Type.h"

extern FUNC(void, CDD_IPCHandler_CODE) RE_IpcTxData(void * b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
extern FUNC(void, CDD_GenericBsw_CODE)CanWUp_Val_StartWakeUpValidation(void);
extern FUNC(void, CDD_GenericBsw_CODE)CanWUp_Val_StopWakeUpValidation(void);
extern FUNC(void, CDD_GenericBsw_CODE) CanWUp_Val_CheckPN(VAR(uint32, AUTOMATIC) WakeupSource);
extern FUNC(Std_ReturnType, DET_CODE) Det_UserReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
extern FUNC(void, OS_CODE) ShutdownOS(StatusType Error);
extern FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamEOLCalibData); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamOCCalibData); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamSCCalibData); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern FUNC(void, SWC_ProxiConfigMgr_CODE) RE_DID2023_ProxiData(P2CONST(uint8, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_DATA) Data, uint16 Datalength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) Errorcode); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamCalibReset(P2CONST(TbSVS_S_SVSCamCalibReset_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamCalibReset); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern void PMIC_EnterLongWindow_DisableWdg(void);
extern FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
extern FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceRegData(DeviceAddress DeviceAdd, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
extern FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
extern FUNC(Std_ReturnType, CalDataProvider_CODE) RE_IntrinsicCameraSN_Readblock(P2VAR(IntrinsicCamID, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) CamNvmData, P2VAR(CamNvmReadSts, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) NvmCamSts); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern void Update_Proxi_MirrorBlock(boolean Proxi_Erase_block);
extern void Update_CalDataProvider_MirrorBlock(boolean CalDataProvider_Erase_block);
extern void Update_CDD_IPCHandler_MirrorBlock(boolean CDD_IPCHandler_Erase_block);
extern void Update_SafetyGuard_MirrorBlock(boolean SafetyGuard_Erase_block);
extern void Update_Cdd_Safety_MirrorBlock(boolean Cdd_Safety_Erase_block);
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmCalloutStub_GetSeed(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) SecurityAccessDataRecord,Dcm_OpStatusType OpStatus,P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed,P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
extern FUNC(void, CDD_IPCHandler_CODE) CddIpcHandler_Init(void);
extern FUNC(void, CDD_IPCHandler_CODE) CddIpcHandler_Main(void);
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmCalloutStub_CompareKey(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
extern FUNC(Std_ReturnType, ErrorMgrSat_1_0_B_CODE) RE_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_ERRORMGRSAT_1_0_B_APPL_DATA) addData); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern void DcmCalloutStub_SessionCallback(uint8 formerSession, uint8 newSession);
extern void Appl_vDamRemapNrcCalloutFunc(uint8 SID, uint8 intErrorCode, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) errorCode);
extern void Update_ComCallout_FlagStatus(uint8* const flagPtrU8, const uint8 data);
extern void Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(uint8 index, uint8 Data, uint8 storeAtShut);
extern FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
extern FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
extern FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
extern FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
extern FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

extern void Pmic_F_SafeState2_v(uint8 SafeStateReason);
extern sint32 Pmic_AppEnterInLongWindow(void);
extern void f_Send_Dbg_SSMFault_CanTx(uint8*  SSMFault);
extern void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault);


#endif /* TRUSTED_FUNC_API_H */

