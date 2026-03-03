#include "PlatformDataTypes.h"

#if defined (BUILD_MCU2_1)
typedef struct
{
uint32 en_Task_BSWTaskTime[14];
uint32 en_Task_APPTaskTime[4];
uint32 en_Task_SAFETYTaskTime[4];
}RunTimeStats_MCU2_1_t;
#endif

#if defined (BUILD_MCU2_0)
typedef struct
{
uint32 en_Task_BSWTaskTime[10];
uint32 en_Task_APPTaskTime[6];
}RunTimeStats_MCU2_0_t;
#endif
#if defined (BUILD_MCU2_0)
 typedef struct StackUsage_MCU2_0_s
{
uint8 en_Task_BSWTaskTime[5];
uint8 en_Task_APPTaskTime[3];
}StackUsage_MCU2_0_t;
#endif
#if defined (BUILD_MCU2_1) 
typedef struct StackUsage_MCU2_1_s
{
uint8 en_Task_BSWTaskTime[6];
uint8 en_Task_APPTaskTime[2];
uint8 en_Task_SAFETYTaskTime[2];
}StackUsage_MCU2_1_t;
#endif
#if defined (BUILD_MCUQNX)
typedef struct RunTimeStats_MPU1_0_s
{ 
	uint32_t APA_Runtime;
	uint32_t CALSM_Runtime;
	uint32_t CALSMThread_Runtime;
	uint32_t DLDThread_Runtime;
	uint32_t DLD_Runtime;
	uint32_t PLDThread_Runtime;
	uint32_t EOL_Runtime;
	uint32_t EOLThread_Runtime;
	uint32_t MOT_Runtime;
	uint32_t OC_Runtime;
	uint32_t OCThread_Runtime;
	uint32_t OD_Runtime;
	uint32_t ODThread_Runtime;
	uint32_t OVL3D_Runtime;
	uint32_t RenderThread_Runtime;
	uint32_t TAD_Runtime;
	uint32_t TADThread_Runtime;
	uint32_t THA_Runtime;
	uint32_t THAThread_Runtime;
	uint32_t TIOVXThread_Runtime;
	uint32_t TIOVX_Runtime;
	uint32_t CameraCalib_Runtime;
	uint32_t VideoInput_Runtime;
	uint32_t AppM_Runtime;
	uint32_t LogM_Runtime;
	uint32_t KeepAlive_Runtime;
	uint32_t ThreadMsgSndr_Runtime;
	uint32_t SigM_Runtime;
	uint32_t ThreadSigM_Runtime;
	uint32_t Sys_Runtime;
	uint32_t SysMon_Runtime;
	uint32_t VarM_Runtime;
	uint32_t AlgoViewThread_Runtime;
}RunTimeStats_MPU1_0_t;
#endif

#if defined (BUILD_MCU1_0) || defined (BUILD_MCU2_1) || defined (BUILD_MCU2_0) || defined (BUILD_MCUQNX)
typedef struct PerformanceStatsEnable_s
{
   uint32_t RunTimeStatsEnable;
   uint32_t StackUsageStatsEnable;
} PerformanceStatsEnable_t;

#endif