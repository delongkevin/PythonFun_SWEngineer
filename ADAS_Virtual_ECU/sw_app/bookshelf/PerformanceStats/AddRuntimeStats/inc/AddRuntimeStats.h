#ifndef AddRuntimeStats_INCLUDEGUARD
#define AddRuntimeStats_INCLUDEGUARD

#ifdef RTE_CORE
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned char bool_t;
//typedef uint64_t uint64;
#else
#include "PlatformDataTypes.h"
#endif

#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
#include "ApplicationTasks.h"
#include "BaseSwTasks.h"
#if defined (BUILD_MCU2_1)
#include "SafetyTasks.h"
#endif
#endif
#if defined (BUILD_MCU1_0)
#include "Os_Types_Lcfg.h"
#endif
typedef struct 
{
	uint32_t MultipleInvocationErrorCount;
	uint32_t StopInvoationWithoutStart;
}AddRuntimeStats_ErrorLog;

typedef struct 
{
	double TotalTimeSpend_ms;
	double AverageTime_ms;
	uint64_t LastInvocationTime_us;
	uint64_t MaximumTime_us;
	uint64_t CurrentRuntTime;
	uint32_t InvocationCount;    
	AddRuntimeStats_ErrorLog ErrorInfo;
	uint8   bMeasuementStarted;
	uint32_t bCurrentPeriodicity_ms;
	double bAveragePeriodicity_ms;
	uint32_t PeriodicityBucket_ms[100];
}AddRuntimeStats_LogStructDef;

/* Update MCU 2_0 enum with any new functions */
#if defined(BUILD_MCU2_0) 
	typedef enum
	{
		AddRuntimeStats_IPC_F_IpcManager_RUN,
		AddRuntimeStats_Diagnostics_RUN,
		AddRuntimeStats_cpu_load_MCU2_0_RUN,
		AddRuntimeStats_F_TRSC_RUN,
		AddRuntimeStats_ErrorMgrSatellite_RUN,
		AddRuntimeStats_ErrorMgrSatellite_b_RUN,
		AddRuntimeStats_LoggableEntries_2_0_Max,
	}AddRuntimeStats_LoggableEntries_2_0;
#endif

/* Update MCU 2_1 enum with any new functions */
#if defined(BUILD_MCU2_1) 
	typedef enum
	{
		AddRuntimeStats_ERRORMGR_QM_RUN,
		AddRuntimeStats_US_ControllerTask_QM_RUN,
		AddRuntimeStats_US_MgrAndODTask_QM_RUN,
		AddRuntimeStats_US_InputOutputBuffTask_QM_RUN,
		AddRuntimeStats_US_DrvTask_QM_RUN,
		AddRuntimeStats_USIntDeferProcessTask_QM_RUN,
		AddRuntimeStats_IpcManager_QM_RUN,
		AddRuntimeStats_cpu_load_MCU2_1_QM_RUN,
		AddRuntimeStats_LoggableEntries_2_1_Max,
	}AddRuntimeStats_LoggableEntries_2_1;
#endif

#if defined(BUILD_MCU2_0) 
		typedef AddRuntimeStats_LoggableEntries_2_0 AddRuntimeStats_LoggableEntries_Local;
#define AddRuntimeStats_Loggable_Entries_Max AddRuntimeStats_LoggableEntries_2_0_Max
#elif defined(BUILD_MCU2_1) 
		typedef AddRuntimeStats_LoggableEntries_2_1 AddRuntimeStats_LoggableEntries_Local;
#define AddRuntimeStats_Loggable_Entries_Max AddRuntimeStats_LoggableEntries_2_1_Max
#endif

typedef enum{
	#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	AdditionalRuntimeStats_LogType_Function,
	#endif
	#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
		AdditionalRuntimeStats_LogType_AppTask,
		AdditionalRuntimeStats_LogType_BswTask,
	#if defined(BUILD_MCU2_1)
		AdditionalRuntimeStats_LogType_AppSafeTask,
		AdditionalRuntimeStats_LogType_BswSafeTask,		
	#endif
	#endif
	#if defined(BUILD_MCU1_0)
		AdditionalRuntimeStats_LogType_Task,
	#endif
}AdditionalRuntimeStats_LogType_Entity;

typedef struct 
{
	uint32_t InvalidEntityId;
	uint32_t InvalidType;
}AddRuntimeStats_GlobalErrorCount;

typedef struct 
{
	#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	AddRuntimeStats_LogStructDef AddRuntimeStats_Stats_LogStruct_Entities[AddRuntimeStats_Loggable_Entries_Max];
	#endif
	#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
		AddRuntimeStats_LogStructDef AddRuntimeStats_BSWTask_Time[en_Task_BSW_MAX];
		AddRuntimeStats_LogStructDef AddRuntimeStats_AppTask_Time[en_Task_APP_MAX];
		#if defined(BUILD_MCU2_1)
		AddRuntimeStats_LogStructDef AddRuntimeStats_SafeTask_Time[en_Task_SAFETY_MAX];
		uint32 AddRuntimeStats_SafeTask_StackUsage[en_Task_SAFETY_MAX];
		#endif	
		uint32 AddRuntimeStats_BSWTask_StackUsage[en_Task_BSW_MAX];
		uint32 AddRuntimeStats_AppTask_StackUsage[en_Task_APP_MAX];
		float AddRuntimeStats_BSWTask_StackUsage_PerCent[en_Task_BSW_MAX];
		float AddRuntimeStats_AppTask_StackUsage_PerCent[en_Task_APP_MAX];
		#if defined(BUILD_MCU2_1)
		float AddRuntimeStats_SafeTask_StackUsage_PerCent[en_Task_SAFETY_MAX];
		#endif
	#endif
	#if defined(BUILD_MCU1_0)
		AddRuntimeStats_LogStructDef AddRuntimeStats_OsTask_Time[OS_TASKID_COUNT];
	#endif
	AddRuntimeStats_GlobalErrorCount InternalError;
}AdditionalRuntimeStats_Log;


#ifdef ADDRUNTIMESTATS


#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	void AdditionalRuntimeStats_Start_Function(AddRuntimeStats_LoggableEntries_Local RunEntityId);
	void AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_LoggableEntries_Local RunEntityId);
#endif
#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	void AdditionalRuntimeStats_Start_AppTask(en_APP_Tasks_Def RunEntityId);
	void AdditionalRuntimeStats_Stop_AppTask(en_APP_Tasks_Def RunEntityId);
	void AdditionalRuntimeStats_Start_BswTask(en_BSW_Tasks_Def RunEntityId);
	void AdditionalRuntimeStats_Stop_BswTask(en_BSW_Tasks_Def RunEntityId);
#if defined (BUILD_MCU2_1)	
	void AdditionalRuntimeStats_Start_AppSafeTask(en_SAFETY_Tasks_Def RunEntityId);
	void AdditionalRuntimeStats_Stop_AppSafeTask(en_SAFETY_Tasks_Def RunEntityId);
	void AdditionalRuntimeStats_Start_BswSafeTask(en_SAFETY_Tasks_Def RunEntityId);
	void AdditionalRuntimeStats_Stop_BswSafeTask(en_SAFETY_Tasks_Def RunEntityId);
#endif	
#endif
#if defined(BUILD_MCU1_0)
	void AdditionalRuntimeStats_Start_Task(TaskType RunEntityId);
	void AdditionalRuntimeStats_Stop_Task(TaskType RunEntityId);
#endif
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
AdditionalRuntimeStats_Log* AdditionalRuntimeStats_GetData(void);
#endif

#endif
#endif
