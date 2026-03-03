#ifndef ERRORMANAGERTYPES_H_INCLUDEGUARD
#define ERRORMANAGERTYPES_H_INCLUDEGUARD

#include "PlatformDataTypes.h"
#include "ErrorManagercfg.h"
#include "ErrorManagerShared.h"

/* ErrorMgr Core Asil Definitions */
typedef enum {
	#if ERRMANAGER_QM_LEVEL_ACTIVE == 1
	ErrorMgr_Asil_QM,
	#endif
	#if ERRMANAGER_A_LEVEL_ACTIVE == 1
	ErrorMgr_Asil_A,
	#endif
	#if ERRMANAGER_B_LEVEL_ACTIVE == 1
	ErrorMgr_Asil_B,
	#endif
	#if ERRMANAGER_C_LEVEL_ACTIVE == 1
	ErrorMgr_Asil_C,
	#endif
	#if ERRMANAGER_D_LEVEL_ACTIVE == 1
	ErrorMgr_Asil_D,
	#endif
	ErrorMgr_Asil_MAX,
}ErrorMgr_AsilList;

/* ErrorMgr Core Defintions */
typedef enum {
	ErrorMgr_Core_1_0 = ERRORMGRCORE_MCU1_0,
	ErrorMgr_Core_2_0 = ERRORMGRCORE_MCU2_0,
	ErrorMgr_Core_2_1 = ERRORMGRCORE_MCU2_1,
//	ErrorMgr_Core_3_0 = ERRORMGRCORE_MCU3_0,
//	ErrorMgr_Core_3_1 = ERRORMGRCORE_MCU3_1,
	ErrorMgr_Core_QNX = ERRORMGRCORE_MCUQNX,
	ErrorMgr_Core_CORE_MAX = ERRORMGRCORE_CORE_MAX,
}ErrorMgr_CoreList;


typedef struct 
{	
	uint16_t MatureTime;
	uint16_t DematureTime;
	ldef_ErrorMgr_stAddData stAddData;
	bool_t bErrorActive;
	ldef_ErrorMgr_enErrorStatus bCurrentCycleInvocation;
	ldef_ErrorMgr_enErrorStatus bPrevCycleInvocation;
}ErrorMgr_RuntimeStateDef;

typedef struct
{
	uint32_t ErrMapErrNo_NotWithinRange;
	uint32_t Err_Output_ErrorStatus_RteSize_Mismatch;
	uint32_t Err_Output_SafeState_RteSize_Mismatch;
	uint32_t Err_DTCMgr_UnconnectedPortsCall;
	uint32_t Err_DTCMgr_CallError;
	uint32_t Err_SafeStateValueOutofMaxVal;
}ErrorMgrAggregator_InternalRuntimeErrorDefs;





typedef void (*ErrorMgrAggregator_Callback_HandleLossofComm)(ErrorMgr_CoreList enCore, ldef_ErrorMgr_enErrorStatus  Status);
typedef void (*ErrorMgrAggregator_Callback_HandleError)(ldef_ErrorMgr_enErrorStatus status, uint8_t* AdditionalData,ErrorMgrAggregator_InternalRuntimeErrorDefs *RuntimeErr);


typedef struct
{
	bool_t bLossOfCommDetected[ERRORMGRCORE_CORE_MAX];
	uint32_t CurrentCount[ERRORMGRCORE_CORE_MAX];
	uint32_t LastRecvdCount[ERRORMGRCORE_CORE_MAX];
}ErrorMgrAggregator_SatelliteMonitorConf_RamDef;

typedef struct
{
	ErrorMgrAggregator_SatelliteMonitorConf_RamDef* RamDef;
	uint32_t Timeout_ms[ERRORMGRCORE_CORE_MAX];					// Just for informational: Can be removed
	uint32_t AggregatorTaskPeriod;		// Just for informational: Can be removed
	uint32_t Timeout_MonitorTaskCounts[ERRORMGRCORE_CORE_MAX];
	ErrorMgrAggregator_Callback_HandleLossofComm LossOfCommCallBack;
}ErrorMgrAggregator_SatelliteMonitorConf;



typedef struct 
{
	uint32_t SatRunCount[ERRORMGRCORE_CORE_MAX];
	ErrorMgrAggregator_InternalRuntimeErrorDefs RuntimeErr;
}ErrorManagerAggregator_RuntimeDefs;








#endif
