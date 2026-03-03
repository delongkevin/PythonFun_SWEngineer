#ifndef TESTSUPPORTDEFS_INCLUDEGUARD
#define TESTSUPPORTDEFS_INCLUDEGUARD

#include "TestErrorMgr_PlatformDataTypes.h"

//temporary fixes for non generated code because of autosar 
#ifdef Rte_TypeDef_ErrorMgr_enSafeStates
	#ifndef ErrorMgr_SafeState_SafeState1
		#define ErrorMgr_SafeState_SafeState1 (0)
	#else
		#erro "This fix needs to be removed"
	#endif

	#ifndef ErrorMgr_SafeState_Max
		#define ErrorMgr_SafeState_Max (1)
	#else
		#erro "This fix needs to be removed"
	#endif
#endif

typedef struct {

	uint32_t MatureTime;
	uint32_t DematureTime;
}ErrorMgrTest_ErrorTime;

typedef struct {
public:
	ldef_ErrorMgr_enErrorNo enGlobalErrNo;
	ErrorMgr_CoreList enCore;
	ErrorMgr_AsilList enAsil;
	uint32_t enAsilEnumVal;
	uint32_t enSafeStateLength;
	const ldef_ErrorMgr_enSafeStates *enApplicableSafeStates;
	ErrorMgrTest_ErrorTime Timing;
	ErrorMgr_DiagDetails DiagDetails;
	uint32_t enCoreAsilSpecificEnumVal;
}ErrorMgr_stTestErrorSpecs;



#ifdef __cplusplus
extern "C" {
#endif
	void Rte_InitMemory_Stub();
#ifdef __cplusplus
}
#endif

#endif
