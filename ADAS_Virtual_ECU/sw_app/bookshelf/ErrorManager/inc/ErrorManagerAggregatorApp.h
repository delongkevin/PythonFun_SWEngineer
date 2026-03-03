#ifndef ERRORMANAGERAGGREGATOR_APP_H_INCLUDEGUARD
#define ERRORMANAGERAGGREGATOR_APP_H_INCLUDEGUARD


#ifdef __cplusplus
extern "C" {
#endif

	void ErrorMgrAggregatorApp_Init(ErrorMgr_AsilList AsilLevel);
/*	void ErrorMgrAggregatorApp_DeInit(void);*/
	void ErrorMgrAggregatorApp_ReadInputs(ErrorMgr_AsilList AsilLevel);
	void ErrorMgrAggregatorApp_Write_AsilGrouped_ErrorStatus(ErrorMgr_AsilList asilLevel,uint32_t *bErrorData,uint32_t errsize,ErrorMgrAggregator_InternalRuntimeErrorDefs *RunDef);
	void ErrorMgrAggregatorApp_Write_SafeState(ErrorMgr_AsilList asilLevel,bool_t *bSafeState,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *RunDef);
	#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU1_0
	void ErrorMgrAggregatorApp_Write_SafeState2ReasonProcess(uint16 SafeState2_RstRsn_flag);
	#endif




#ifdef __cplusplus
}
#endif

#endif /*ERRORMANAGERAGGREGATOR_APP_H_INCLUDEGUARD*/
