//--------------------------------------------------------------------------
/// @file JobSysMon.cpp
/// @brief Contains the System Monitor job implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobSysMon.h"
#include "variants/VariantHelper.h"
#include "fsdata/fsdata.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_SysMon   (1u)
#endif
#if PROFILE_SysMon
#include "osal/system/Time.h"
static uint32_t v_AvgSysMonRuntime_u32 = 0;
static uint32_t v_SysMonRunCntr_u32 = 0;
static uint32_t v_AvgSysMonPeriodicity_u32 = 0;
static uint32_t v_SysMonPreviousTime_u32 = 0;
static uint32_t v_SysMonRuntimeData = 0;
static PerformanceStatsEnable_t PerformanceStatsEnable_dp; 
#endif

namespace sysmon
{
const int VERSION_FILE_LEN = 5;

JobSysMon::JobSysMon(container::JobDesc_s& i_JobDesc_rs, IDataProviderSysMon& i_DataProviderSysMon_ro)
  : container::JobBase<IDataProviderSysMon>(i_JobDesc_rs, i_DataProviderSysMon_ro)
	, m_runtimeStatsThread_o("RuntimeStatsThread")
	, m_runtimeStatsRunnable_o(i_DataProviderSysMon_ro)
//  , socTempMonitorThread_o("SoCTempMonThread")
//  , socTempMonitorRunnable_o()
//  , softwareWatchdogThread_o("SoftwareWatchdogRunnable")
//  , softwareWatchdogRunnable_o()
{
  // Nothing to do yet!
}

JobSysMon::~JobSysMon()
{
  // Nothing to do yet!
}

bool_t JobSysMon::onInit_b()
{
	ME_Proxi_MPU1_0_to_MCU1_0_t proxi_req = {0.0f,QNX_IDLE_STATE,0,0};
	SSM_QNX_CoreStatus ssm_state;
	uint8_t etfs_status = 0;
	float32_t avg_cpu_load = 0;

	//Start runtime stats thread
	m_runtimeStatsThread_o.start_v(&m_runtimeStatsRunnable_o, false);

	fsdata::fsdata_read_data("/tmp/etfs_status", (char*)&etfs_status, sizeof(etfs_status));

	dataProvider_ro.setETFS_mount_status(etfs_status);
	etfs_status = dataProvider_ro.getETFS_mount_status();

	ssm_state.CoreStatus = SSM_SlaveCore_State_BSP_Init_Done_i;

	if(etfs_status == 1)
	{
		if(false == fsdata::fsdata_read_data(variants::ME_VariantHelper_GetVariantIdFilePath_pc(),(char*)&proxi_req,sizeof(proxi_req)))
		{
			printf("JOBSYSMON: Read from file failed. Sending default values\n");
			//todo : do we need to send default
			proxi_req.PRX_variantID_u8 = 8;
			proxi_req.PRX_RadioDispTyp_u8 = 7;
		}
		else
		{
			//do nothing
		}
		printf("JOBSYSMON: ETFS Mount is successful. VarID: %d\tRadioType: %d from File\n",proxi_req.PRX_variantID_u8,proxi_req.PRX_RadioDispTyp_u8);
		proxi_req.state = QNX_BOOTUP_STATE;
	}
	else
	{
		proxi_req.PRX_variantID_u8 = 8;
		proxi_req.PRX_RadioDispTyp_u8 = 7;
		printf("JOBSYSMON: ETFS FS is not ready yet\n");
		proxi_req.state = QNX_ETFS_NOT_READY_STATE;
	}
	/*ME_Debugger_F_GetAverageCpuUsage_v(&avg_cpu_load);
	proxi_req.a72_cpu_load = avg_cpu_load;*/
	dataProvider_ro.setME_Proxi_MPU1_0_to_MCU1_0(proxi_req);
	dataProvider_ro.setSSM_QNX_CoreStatus_v(ssm_state);
  return true;
}

void JobSysMon::onVariantChanged_v(bool_t i_FirstTime_b)
{
  // Nothing to do yet!
}

bool_t JobSysMon::onRun_b()
{
  #if PROFILE_SysMon
  PerformanceStatsEnable_dp = dataProvider_ro.getPerformanceStatsEnable_t();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
  {
	v_Start_t = __get_time_usec();
	currPeriodicity = v_Start_t - v_SysMonPreviousTime_u32;
  }
  #endif

  MEP_BEGIN("SysMon", "run");
  float32_t avg_cpu_load = 0;
	/*ME_Proxi_MPU1_0_to_MCU1_0_t proxi_req = {0.0f,QNX_IDLE_STATE,0,0};

  ME_Debugger_F_GetAverageCpuUsage_v(&avg_cpu_load);
  proxi_req = dataProvider_ro.getME_Proxi_MPU1_0_to_MCU1_0();
  proxi_req.a72_cpu_load = avg_cpu_load;
  printf("JOBSysMon CPU load is %f\n",proxi_req.a72_cpu_load);
  dataProvider_ro.setME_Proxi_MPU1_0_to_MCU1_0(proxi_req);*/
  

  //dataProvider_ro.setCurrentSoCTemperature(socTempMonitorRunnable_o.getSoCTemperature_u32());
  m_runtimeStatsThread_o.resume_v();

  MEP_END("SysMon", "run");
//  printf("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
    ME_Thread_Sleep_t(5);


  #if PROFILE_SysMon
	if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
  	{
  	v_End_t = __get_time_usec();
//   ME_Debugger_F_Printf_v("SysMon: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
	v_SysMonRunCntr_u32++; //Increment the run counter for averaging purpose
	v_AvgSysMonPeriodicity_u32 = ((v_AvgSysMonPeriodicity_u32 * (v_SysMonRunCntr_u32 -1)) + currPeriodicity)/v_SysMonRunCntr_u32; //Average Periodicity
	v_AvgSysMonRuntime_u32 = ((v_AvgSysMonRuntime_u32 * (v_SysMonRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_SysMonRunCntr_u32; //New Average  
	v_SysMonRuntimeData = (((v_AvgSysMonRuntime_u32/1000U)<<16U) | ((v_AvgSysMonPeriodicity_u32/1000U) & 0xFFFF));
	dataProvider_ro.setSysMonRuntime(v_SysMonRuntimeData);
	//ME_Debugger_F_Printf_v("SysMon: E: %lld P: %lld \n", v_AvgSysMonRuntime_u32, v_AvgSysMonPeriodicity_u32);
	v_SysMonPreviousTime_u32 = v_Start_t;
	}
  #endif

  return true;
}

void JobSysMon::onCleanup_v()
{
//  socTempMonitorThread_o.terminate_v();
//  socTempMonitorThread_o.join_v();
  m_runtimeStatsThread_o.terminate_v();
  m_runtimeStatsThread_o.join_v();
}

} // namespace sysmon	
