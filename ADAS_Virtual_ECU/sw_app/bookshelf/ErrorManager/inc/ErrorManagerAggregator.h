#ifndef ERRORMANAGERAGGREGARTOE_H_INCLUDEGUARD
#define ERRORMANAGERAGGREGARTOE_H_INCLUDEGUARD



#ifdef __cplusplus
extern "C" {
#endif


	void ErrorMgrAggregator_Init_QM(void);
//	void ErrorMgrAggregator_Init_A(void);
	void ErrorMgrAggregator_Init_B(void);
//	void ErrorMgrAggregator_Init_C(void);
//	void ErrorMgrAggregator_Init_D(void);

	/*void ErrorMgrAggregator_DeInit(void);*/
	void ErrorMgrAggregator_QM_PeriodicFunction(void);
	void ErrorMgrAggregator_B_PeriodicFunction(void);
//	void ErrorMgrAggregator_PeriodicFunction_D(void);

	void ErrorMgrAggregator_Callback_WriteDtcData_B(void);
	void ErrorMgrAggregator_Callback_WriteDtcData_QM(void);

#ifdef __cplusplus
}
#endif





#define ErrorMgr_MaxOf2Vals(Cat1,Cat2) ((Cat1)>(Cat2)?(Cat1):(Cat2))
#define ErrorMgr_MaxOf5Vals(Cat1,Cat2,Cat3,Cat4,Cat5) ErrorMgr_MaxOf2Vals(ErrorMgr_MaxOf2Vals(ErrorMgr_MaxOf2Vals(Cat1,Cat2),ErrorMgr_MaxOf2Vals(Cat3,Cat4)),Cat5) 

#define ErrorMgr_GetBytePos(enVal) ((enVal)/32)
#define ErrorMgr_GetBitPos(enVal)  ((enVal)%32)

#define ErrorMgrSetError_BitPacked(arr,enVal)  (arr)[ErrorMgr_GetBytePos((enVal))] |= ((uint32_t)0x00000001<<ErrorMgr_GetBitPos((enVal)))
#define ErrorMgrGetError_BitPacked(arr,enVal)  ((arr)[ErrorMgr_GetBytePos((enVal))] & ((uint32_t)0x00000001<<ErrorMgr_GetBitPos((enVal))))
#define ErrorMgrGetError_BitPacked_Rsh_1stBitPos(arr,enVal)  (ErrorMgrGetError_BitPacked(arr,enVal)>>ErrorMgr_GetBitPos((enVal)))

//divide by 32 and add 1 if remained is 1
#define ERRMANAGER_GETPACKEDSIZE(x)  (((x)>>5u)+(((x)&(uint8_t)0x1F) != 0u?(uint8_t)1:(uint8_t)0))

#endif //ERRORMANAGERAGGREGARTOE_H_INCLUDEGUARD
