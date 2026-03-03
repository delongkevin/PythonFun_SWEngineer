//--------------------------------------------------------------------------
/// @file THAThread.cpp
/// @brief Contains the Job definition for TIOVX host
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------

#include "THAThread.h"
#include <logging/Logger.h>
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_THAThread     (1u)
#endif
#if PROFILE_THAThread
#include "osal/system/Clock.h"
static uint32_t v_AvgEOLThreadRuntime_u32 = 0;
static uint32_t v_EOLThreadRunCntr_u32 = 0;
static uint32_t v_AvgEOLThreadPeriodicity_u32 = 0;
static uint32_t v_EOLThreadPreviousTime_u32 = 0;
static uint32_t v_EOLThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsTHEnable_dp;
#endif

#define _30_FPS_ ((uint32_t)32)
static bool_t b_isInit_done = 0;
static bool_t b_start = true;

const uint32_t img_width = 1920U;   //should be same as algo_view_width
const uint32_t img_height = 1280U;  //should be same as algo_view_height

namespace tha
{

THAThreadRunnable::THAThreadRunnable( IDataProviderTHA& b_DataProvider_ro)
: IRunnable()
,dataProvider_ro( b_DataProvider_ro)
{
  m_StateProcess.getTHADetOutputAlgo( m_JobTHADetOutput );
  m_StateProcess.getTHADetDebugOutputAlgo( m_JobTHADetDebugOutput );
  m_StateProcess.getTHADataProvider(&b_DataProvider_ro);
}

THAThreadRunnable::~THAThreadRunnable()
{

}

vx_status appInit()
{
  vx_status status = VX_SUCCESS;

  status = appCommonInit();

  if(status==VX_SUCCESS)
  {
    tivxInit();
    tivxHostInit();
  }
  return status;
}

	/*
	*	Name: init_v
    *   Remarks: DD-ID: {B8951991-ABED-49d6-83A7-6A09F8551834}
	*	Remarks: DD-ID: {7FAD3D95-3339-4283-B2BC-922BE91A9EAC}
	*/
void THAThreadRunnable::init_v()
{
  //temporary delay added to make sure tivx init is done before this.
  ME_Thread_Sleep_t(500);

  #if PROFILE_THA
    PerformanceStatsTHEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
    {
      v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
      currPeriodicity = v_Start_t - v_THAThreadPreviousTime_u32;
    }
  #endif
  
  // Dipti : Read Calib data and valid flag
  dataProvider_ro.getCalibData();
	 /* Set State process configuration */
	m_StateProcessCfg = dataProvider_ro.getStateProcessConfig();
	 //m_StateProcess.m_Cfg = v_StateProcessCfg;
	 TrailerTrackCfg v_TrailerTrackConfig = dataProvider_ro.getTrailerTrackCfg();
	 //m_StateProcess.m_TrailerTrackConfig = v_TrailerTrackConfig;
	 m_ImgWidth  = img_width;// should be same as algo_view_width
   m_ImgHeight = img_height;// should be same as algo_view_height
   //m_StateProcess.m_ImgWidth = m_ImgWidth;
   //m_StateProcess.m_ImgHeight = m_ImgHeight;

   /* Init Job input */
   m_JobTHAInput = dataProvider_ro.getTHAInput();
   m_StateProcess.initStateData( m_StateProcessCfg, v_TrailerTrackConfig, m_ImgWidth, m_ImgHeight );
   m_StateProcess.getJobTHAInput( m_JobTHAInput );
   //m_StateProcess.m_JobTHAInput = m_JobTHAInput;
   /*Init & Put Job output */
   m_StateProcess.getTHADetOutputAlgo( m_JobTHADetOutput );
   dataProvider_ro.putTHADetOutput( m_JobTHADetOutput );
	 m_StateProcess.getTHADetDebugOutputAlgo( m_JobTHADetDebugOutput );
   dataProvider_ro.putTHADetDebugOutput( m_JobTHADetDebugOutput );
  
	
  	//--- Initialize state process
  	m_StateProcess.Init();
  	// //Dipti : Setting m_KFSmoothThresh according to input image resolution
  	// if( m_ImgWidth <= 640 )
  	// {
    //   m_StateProcess.m_KFSmoothThresh = 10;
  	// }
  	// else if( m_ImgWidth <= 1280 )
  	// {
    //   m_StateProcess.m_KFSmoothThresh = 20;
  	// }
  	// else
  	// {
    //   m_StateProcess.m_KFSmoothThresh = 30;
  	// }

  #if PROFILE_THA
    if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
    {
      v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
      v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
      v_THAThreadRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgTHAThreadPeriodicity_u32 = ((v_AvgTHAThreadPeriodicity_u32 * (v_THAThreadRunCntr_u32 -1)) + currPeriodicity)/v_THAThreadRunCntr_u32; //Average Periodicity
      v_AvgTHAThreadRuntime_u32 = ((v_AvgTHAThreadRuntime_u32 * (v_THAThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_THAThreadRunCntr_u32; //New Average  
      v_THAThreadRuntimeData = (((v_AvgTHAThreadRuntime_u32/1000U)<<16U) | ((v_AvgTHAThreadPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setTHAThreadRuntime(v_THAThreadRuntimeData);
      ME_Debugger_F_Printf_v("THAThrd: E: %lld P: %lld \n", v_AvgTHAThreadRuntime_u32, v_AvgTHAThreadPeriodicity_u32);
      v_THAThreadPreviousTime_u32 = v_Start_t;
      ME_Debugger_F_Printf_v("\nInit: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
    }
  #endif
  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::init_v() m_StateProcess.Init() end ### \n");
  #endif

  return;
}
#if ENABLE_CD_HD
vx_status THAThreadRunnable::app_tidl_CD_HD()
{
  vx_status v_status_b = VX_SUCCESS;

  /*Config parameter reading*/
  app_parse_cmd_line_args_CD_HD(&TIObj_s_CD_HD);
  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### CD_HD: Parsed user params! v_status_b=%d #### \n", v_status_b);
  #endif

  v_status_b = app_init_CD_HD(&TIObj_s_CD_HD);
  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### CD_HD: App Init Done! v_status_b=%d #### \n", v_status_b);
  #endif

  if(v_status_b == VX_SUCCESS)
  {
    v_status_b = app_create_graph_CD_HD(&TIObj_s_CD_HD);
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### CD_HD: App Create Graph Done! v_status_b=%d #### \n", v_status_b);
    #endif
  }
  if(v_status_b == VX_SUCCESS)
  {
    v_status_b = app_verify_graph_CD_HD(&TIObj_s_CD_HD);
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### CD_HD: App Verify Graph Done! v_status_b=%d #### \n", v_status_b);
    #endif
  }
  return v_status_b;
}
#endif

#if ENABLE_TrailerPose
vx_status THAThreadRunnable::app_tidl_TrailerPose()
{
  vx_status status = 0;
  ME_Thread_Sleep_t(10);
  app_parse_cmd_line_args_TrailerPose(&TIObj_s_TrailerPose);
  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### TrailerPose: Parsed user params! #### \n");
  #endif

  if(status == VX_SUCCESS)
  {
    status = app_init_TrailerPose(&TIObj_s_TrailerPose);
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### TrailerPose: App Init Done! v_status_b=%d #### \n", status);
    #endif
  }
  if(status == VX_SUCCESS)
  {
    status = app_create_graph_TrailerPose(&TIObj_s_TrailerPose);
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### TrailerPose: App Create Graph Done! v_status_b=%d #### \n", status);
    #endif
  }
  if(status == VX_SUCCESS)
  {
    status = app_verify_graph_TrailerPose(&TIObj_s_TrailerPose);
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### TrailerPose: App Verify Graph Done! v_status_b=%d #### \n", status);
    #endif
  }
  return status;
}
#endif

bool_t THAThreadRunnable::run_b()
{
#if PROFILE_THAThread
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  v_Start_t = __get_time_usec();
#endif
  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = 0;
  uint64_t v_EndTime_u64 = 0;
  static uint32_t v_TotalTime_u32 = 0;
  uint32_t v_AdjustmentTime_u32 = 0;
  #if PROFILE_THA
		static osal::Time start;
		volatile uint64_t v_Befor_Start_t, v_Befor_Execute_t, v_Befor_End_t = 0;
		volatile uint64_t v_After_Start_t, v_After_Execute_t, v_After_End_t = 0;
		static uint64_t v_Previous_t = 0, v_Current_t = 0;
  #endif
  v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #if PROFILE_THA
		v_Current_t = start.getTimeMsec_u64();
  #endif
  if(b_start == true)
  {
    #if PROFILE_THA
		v_Befor_Start_t = start.getTimeMsec_u64();
    #endif
    startTHA();
    b_start = false;
    #if PROFILE_THA
	  v_After_Start_t = start.getTimeMsec_u64();
    ME_Debugger_F_Printf_v("S: %lld\n",(v_After_Start_t - v_Befor_Start_t));
    #endif
  }
  else
  {
    #if PROFILE_THA
	  	v_Befor_Execute_t = start.getTimeMsec_u64();
    #endif
    executeTHA();
    b_start = true;
  
    #if PROFILE_THA
	  	v_After_Execute_t = start.getTimeMsec_u64();
	  	v_Befor_End_t = start.getTimeMsec_u64();
    #endif
    endTHA();
    #if PROFILE_THA
	  	v_After_End_t = start.getTimeMsec_u64();
      ME_Debugger_F_Printf_v("E: %lld, %lld\n",(v_After_Execute_t - v_Befor_Execute_t),
									(v_After_End_t - v_Befor_End_t));
    #endif
  }
  #if PROFILE_THA
		// ME_Debugger_F_Printf_v("%lld, %lld, %lld, %lld\n", (v_Current_t - v_Previous_t),
		// 							(v_After_Start_t - v_Befor_Start_t),
		// 							(v_After_Execute_t - v_Befor_Execute_t),
		// 							(v_After_End_t - v_Befor_End_t));
		v_Previous_t = v_Current_t;
  #endif
#if PROFILE_THAThread
  v_End_t = __get_time_usec();
  //ME_Debugger_F_Printf_v("THAThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
#endif
  v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  v_TotalTime_u32 = (uint32_t)(v_EndTime_u64 - v_StartTime_u64);
  if(_30_FPS_ > v_TotalTime_u32)
  {
    v_AdjustmentTime_u32 = (_30_FPS_ - v_TotalTime_u32); /* Remaning time above 30FPS*/
    ME_Thread_Sleep_t(v_AdjustmentTime_u32);
  }

  #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n\n\n\n ######################## THAThreadRunnable::run_b() ######################## \n\n\n\n");
  #endif

  return true;
}

	/*
	*	Name: start_v
	*   Remarks: DD-ID: {0AD13837-726B-4730-982D-AA7E967A4CDF}
	*	Remarks: DD-ID: {E2EA5B87-5490-481d-A66C-DF6C40D948BC}
	*/
void THAThreadRunnable::startTHA()
{
  #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  //Dipti : Condition added to Init TIDL when THA is in required state
  if(b_isInit_done == 0)
  {
    vx_status v_status_b = VX_SUCCESS;
    #if ENABLE_CD_HD
      /* CD_HD detector */
      v_status_b = app_tidl_CD_HD();
      #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n ### THAThreadRunnable: app_tidl_CD_HD status=%d #### \n", v_status_b);
      #endif
    #endif

    #if ENABLE_TrailerPose
      /* Trailer Pose */
      v_status_b = app_tidl_TrailerPose();
      #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n ### THAThreadRunnable: app_tidl_TrailerPose status=%d #### \n", v_status_b);
      #endif
    #endif
    b_isInit_done = 1;
    ME_Debugger_F_Printf_v("\n ### THA Init Done #### \n");
  }
  m_JobTHAInput                 = dataProvider_ro.getTHAInput();
  m_StateProcess.getJobTHAInput( m_JobTHAInput );
  //m_StateProcess.m_JobTHAInput  = m_JobTHAInput;
  bool_t v_isDetEnable = dataProvider_ro.getTHADetEnableFlag();
  bool_t v_isFeatureAllowed = dataProvider_ro.isTHAFeatureAllowedToRun();
  #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n### v_isDetEnable %d ###\n",v_isDetEnable);
  #endif
  if(( v_isDetEnable == true) && (v_isFeatureAllowed == true))
  {
    if (m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true)
    {
      #ifdef OD_TRACKER
	  uint8_t* v_InputImage_pu8 = m_StateProcess.m_CouplerTrackerObj.getInputImage();
    		if( m_StateProcessCfg.getUtilizeTrailerTracker() == true )
        {
        #ifdef _WIN32
          if( ( m_ImgWidth != 640 ) || ( m_ImgHeight != 400 ) )
          {
            matrixUtil::GrayBiLinearResize( m_JobTHAInput.InputImgGray_pu8, m_ImgWidth, m_ImgHeight, v_InputImage_pu8, m_StateProcess.m_CouplerTrackerObj.getImgWidth(), m_StateProcess.m_CouplerTrackerObj.getImgHeight() );
            m_StateProcess.m_CouplerTrackerObj.setInputImage( v_InputImage_pu8 );
          }
          else
          {
              memcpy( v_InputImage_pu8, m_JobTHAInput.InputImgGray_pu8, m_ImgWidth * m_ImgHeight );
              m_StateProcess.m_CouplerTrackerObj.setInputImage( v_InputImage_pu8 );
          }
        #else
          if(NULL != m_JobTHAInput.InputImgGray_pu8)
          {
            memcpy( v_InputImage_pu8, m_JobTHAInput.InputImgGray_pu8, (m_StateProcess.m_CouplerTrackerObj.getImgWidth()*m_StateProcess.m_CouplerTrackerObj.getImgHeight()) );
            m_StateProcess.m_CouplerTrackerObj.setInputImage( v_InputImage_pu8 );
		      }
          else
          {
            ME_Debugger_F_Printf_v("\n ### ThreadRunnable :: m_JobTHAInput.InputImgGray_pu8 is NULL #### \n");
          }
        #endif
        }
        #if ENABLE_DEBUG_THA
          ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::m_pInputImage_pu8 %p #### \n", m_StateProcess.m_CouplerTrackerObj.getInputImage());
        #endif
      #endif
    }
  }

  #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\n start: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
  #endif

  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::startTHA() %d Done #### \n", m_JobTHAInput.SMInput_s.THASmState_e);
  #endif
}
	/*
	*	Name: execute_v
	*	Remarks: DD-ID: {83D9EDA5-3171-41aa-981A-DADE5FD2EAF1}
    *   Remarks: DD-ID: {10A85367-6299-48c8-A58A-FA4A945DED0E}
	*/
void THAThreadRunnable::executeTHA()
{
  #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif

  m_StateProcess.ProcessTHASM(&TIObj_s_CD_HD, &TIObj_s_TrailerPose); // function call to determine THA Detection State
  
  #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\nexecute: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
  #endif
  
  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::executeTHA() Done #### \n");
  #endif
}
	/*
	*	Name: end_v
    *   Remarks: DD-ID: {3CD3B6B5-F4E3-408d-9A13-DEB047FCE7BB}
	*   Remarks: DD-ID: {F367B5FB-1553-47aa-A6DC-3822C4D5FF1F}
	*/
void THAThreadRunnable::endTHA()
{
  #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif
#if 0
  //Dipti : Condition added to De init TIDL when THA is not in required state
  if((b_isInit_done == 1) && ((m_StateProcess.m_JobTHAInput.SMInput_s.THASmState_e != THAState_e::e_EnabledSelection) && 
   (m_StateProcess.m_JobTHAInput.SMInput_s.THASmState_e != THAState_e::e_Engaged) &&
   (m_StateProcess.m_JobTHAInput.SMInput_s.THASmState_e != THAState_e::e_EngagedDelta)))
  {
    #if ENABLE_CD_HD  
    //CD HD
      app_delete_graph_CD_HD(&TIObj_s_CD_HD);
      app_deinit_CD_HD(&TIObj_s_CD_HD);
    #endif

    #if ENABLE_TrailerPose
      //TrailerPose
      app_delete_graph_TrailerPose(&TIObj_s_TrailerPose);
      app_deinit_TrailerPose(&TIObj_s_TrailerPose);
    #endif
    ME_Debugger_F_Printf_v("\n ### THA Deinit Done #### \n");
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::cleanup_v() Done #### \n");
    #endif
    b_isInit_done = 0;
  }
#endif

  //--- Algo to Impl: THA Detection data
  m_StateProcess.getTHADetOutputAlgo( m_JobTHADetOutput );
  dataProvider_ro.putTHADetOutput( m_JobTHADetOutput );
	//--- Algo to Impl: THA Detection Debug data
	m_StateProcess.getTHADetDebugOutputAlgo( m_JobTHADetDebugOutput );
	dataProvider_ro.putTHADetDebugOutput( m_JobTHADetDebugOutput );
  #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\nend: %f ms", (float32_t)(v_TotalTime_u64 * 1.0f));
  #endif

  #if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::endTHA() Done #### \n");
  #endif
}

void THAThreadRunnable::cleanup_v()
{

#if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ### THAThreadRunnable::cleanup_v() Done #### \n");
#endif
}

void THAThreadRunnable::stop_v()
{

}
  /*
  * Name: reset_v
  * Remarks: DD-ID: {B9D74310-E29E-4b4a-BEBB-8ED5224055F7}
  * Remarks: DD-ID: {F66C5793-35CE-4744-BCFB-FD3C2921FDD1}
  */
void THAThreadRunnable::reset_v( void )
{
        m_StateProcess.Init();
}

} // namespace tha
