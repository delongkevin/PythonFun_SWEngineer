

#include "JobAlgoEol.h"

#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_EOL     (1u)
#define PROFILE_EOLThread     (1u)
#endif
#if PROFILE_EOL
#include "osal/system/Clock.h"
static uint32_t v_AvgEOLRuntime_u32 = 0;
static uint32_t v_EOLRunCntr_u32 = 0;
static uint32_t v_AvgEOLPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_EOLRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif


#if PROFILE_EOLThread
#include "osal/system/Clock.h"
static uint32_t v_AvgEOLThreadRuntime_u32 = 0;
static uint32_t v_EOLThreadRunCntr_u32 = 0;
static uint32_t v_AvgEOLThreadPeriodicity_u32 = 0;
static uint32_t v_EOLThreadPreviousTime_u32 = 0;
static uint32_t v_EOLThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsTHEnable_dp;
#endif

namespace eol
{
  #define _30_FPS_ ((uint32_t)32)

  /* *******************************************************************************
   *                                E O L    J O B
   ******************************************************************************* */
  JobAlgoEol::JobAlgoEol(container::JobDesc_s& b_JobDesc_rs, IDataProviderEol& b_DPEol_ro)
  : JobBase(b_JobDesc_rs, b_DPEol_ro),
    m_EOLThread_o("EOL_Thread"),
    m_EOLThreadRunnable_o(b_DPEol_ro)
  {
    m_EOLThread_o.setPriority_v(e_PriorityLow);
    //ME_Debugger_F_Printf_v("m_EOLThread_o.setPriority_v");
  }
  
  JobAlgoEol::~JobAlgoEol() {
  }

  bool_t JobAlgoEol::onInit_b() {
    /* DD-ID: {6E38446B-C61A-423c-A1A3-3584A925AD28}*/
    m_EOLThread_o.start_v(&m_EOLThreadRunnable_o);
    return true;
  }

  void JobAlgoEol::onVariantChanged_v(bool_t i_FirstTime_b) {
    /* DD-ID: {4829C894-9B4D-471c-B6CB-22AE86FC875D}*/
  }

  bool_t JobAlgoEol::onRun_b() {
    /* DD-ID: {6337EA32-97C3-4c65-8AAC-8819CFE2FDD5}*/
#if PROFILE_EOL
    PerformanceStatsEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
    static osal::Time start;
    volatile uint32_t v_Start_t = 0;
    volatile uint32_t v_End_t = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
    {
      v_Start_t = __get_time_usec();
      currPeriodicity = v_Start_t - v_PreviousTime_u32;
    }
#endif

#if PROFILE_EOL
    if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      //ME_Debugger_F_Printf_v("EOL: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_EOLRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgEOLPeriodicity_u32 = ((v_AvgEOLPeriodicity_u32 * (v_EOLRunCntr_u32 -1)) + currPeriodicity)/v_EOLRunCntr_u32; //Average Periodicity
      v_AvgEOLRuntime_u32 = ((v_AvgEOLRuntime_u32 * (v_EOLRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_EOLRunCntr_u32; //New Average  

      v_EOLRuntimeData = (((v_AvgEOLRuntime_u32/1000U)<<16U) | ((v_AvgEOLPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setEOLRuntime(v_EOLRuntimeData);
      //ME_Debugger_F_Printf_v("EOL: E: %lld P: %lld \n", v_AvgEOLRuntime_u32, v_AvgEOLPeriodicity_u32);
      v_PreviousTime_u32 = v_Start_t;
    }
#endif
    return true;
  }

  void JobAlgoEol::onCleanup_v() {
    /* DD-ID: {D194A60C-3008-4f3a-857C-FFFF863C3310}*/
    m_EOLThread_o.terminate_v();
    m_EOLThread_o.join_v();
  }


  /* *******************************************************************************
   *                    E O L    T H R E A D   R U N N A B L E
   ******************************************************************************* */

  EOLThreadRunnable::EOLThreadRunnable(IDataProviderEol& b_DPEol_ro)
  : IRunnable(),
  dataProvider_ro(b_DPEol_ro)
  {

  }

  EOLThreadRunnable::~EOLThreadRunnable() {

  }

  void EOLThreadRunnable::init_v()
  {
    /* DD-ID: {1CEBF21A-0394-427a-856B-BD9D1A5E910D}*/
    //ME_Debugger_F_Printf_v("\n ###### JobEol::onInit_b() Init done ###### \n");
	//dataProvider_ro.init_camera();
    //dataProvider_ro.getEolData();

    m_PrevAlgoCommand = ME_Hydra3defs_E_AlgoCommand_e::AlgoCommand_Unknown;
    m_PrevCamID = ME_Hydra3defs_E_CameraID_e::CamID_None;
  }

  bool_t EOLThreadRunnable::run_b()
  {
    /* DD-ID: {912D91DF-11E4-4bef-88FF-EDB766A8FED1}*/
#if PROFILE_EOLThread
    PerformanceStatsTHEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
    static osal::Time start;
    volatile uint32_t v_Start_t = 0;
    volatile uint32_t v_End_t = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
    {
      v_Start_t = __get_time_usec();
      currPeriodicity = v_Start_t - v_EOLThreadPreviousTime_u32;
    }
#endif
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();


  #ifdef TEST_CODE
    static int counter = 0;
    if (counter == 100)
    {
      start_v();
      execute_v();
      end_v();
    }
    counter++;
  #endif

    dataProvider_ro.getCalSMData();
    m_CurrAlgoCommand = (ME_Hydra3defs_E_AlgoCommand_t) dataProvider_ro.getAlgoCommand_u8();
    m_CurrCamID = dataProvider_ro.getCameraId_MEHydra3();
    m_CurrAlgoID = (aParaMgr_E_CalibrationType_t) dataProvider_ro.getAlgoType_u8();

    if (m_CurrAlgoCommand == ME_Hydra3defs_E_AlgoCommand_t::AlgoCommand_Start &&
        m_CurrAlgoID == eol::e_EndOfLineCalibration &&
        (m_PrevAlgoCommand != ME_Hydra3defs_E_AlgoCommand_t::AlgoCommand_Start ||
         m_PrevAlgoID != eol::e_EndOfLineCalibration ||
         m_CurrCamID != m_PrevCamID ))
    {
      ME_Debugger_F_Printf_v("EOL JOB \n");
      start_v();
      execute_v();
      end_v();
    }
    else
    {
    //ME_Debugger_F_Printf_v("\n ###### Eol::not received command conditions to start ###### \n");
    }

    m_PrevAlgoCommand = m_CurrAlgoCommand;
    m_PrevAlgoID = m_CurrAlgoID;
    m_PrevCamID = m_CurrCamID;
    // ME_Debugger_F_Printf_v("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
#if PROFILE_EOLThread
    if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      //ME_Debugger_F_Printf_v("EOLThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_EOLThreadRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgEOLThreadPeriodicity_u32 = ((v_AvgEOLThreadPeriodicity_u32 * (v_EOLThreadRunCntr_u32 -1)) + currPeriodicity)/v_EOLThreadRunCntr_u32; //Average Periodicity
      v_AvgEOLThreadRuntime_u32 = ((v_AvgEOLThreadRuntime_u32 * (v_EOLThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_EOLThreadRunCntr_u32; //New Average  
      v_EOLThreadRuntimeData = (((v_AvgEOLThreadRuntime_u32/1000U)<<16U) | ((v_AvgEOLThreadPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setEOLThreadRuntime(v_EOLThreadRuntimeData);
      //ME_Debugger_F_Printf_v("EOLTh: E: %lld P: %lld \n", v_AvgEOLThreadRuntime_u32, v_AvgEOLThreadPeriodicity_u32);
      v_EOLThreadPreviousTime_u32 = v_Start_t;
    }
#endif

    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint32_t v_TotalTime_u32 = (uint32_t)(v_EndTime_u64 - v_StartTime_u64);
    if(v_TotalTime_u32 < _30_FPS_)
    {
      uint32_t v_AdjustmentTime_u32 = (_30_FPS_ - v_TotalTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
      ME_Thread_Sleep_t(v_AdjustmentTime_u32);
    }
    return true;
  }

// -------------------------------------------------------------------------
void EOLThreadRunnable::start_v(void)
{
  /* DD-ID: {7F494405-DAE4-40cb-99BE-5F5BD66A274A}*/
  #if ENABLE_DEBUG
    ME_Debugger_F_Printf_v("\n ###### JobEol::start() ###### \n");  
  #endif
 
  dataProvider_ro.getCameraParameters_v();

  /* TIOVX image */
  memset(&eolcalib_o.lCaliVCalibration_s,0,sizeof(aParaMgr_S_Calibration_t));

  // Without the DebugScreenInfo_s reset code below, EOL cause segmentation faults on the second job execute
  const uint32_t c_NumElements_u32 = (sizeof(eolcalib_o.roiImages_as))/(sizeof(eolcalib_o.roiImages_as[0]));
  for(uint32_t v_I_u32 = 0U; v_I_u32 < c_NumElements_u32; v_I_u32++)
  {
    eolcalib_o.roiImages_as[v_I_u32] = DebugScreenInfo_s();
  }
  eolcalib_o.cntOfDebugImages_u32 = 0U;

  /*forget target seperation and optimizer_e*/

  m_EolInitData = dataProvider_ro.getEolData();
  eolcalib_o.c_EolInitData_ps = &m_EolInitData;
  eolcalib_o.lCaliVCalibration_s.calibrationType_u8 = eolcalib_o.c_EolInitData_ps->calibType_u8;
  eolcalib_o.lCaliVCalibration_s.camId_e            = static_cast<E_CameraId_t>(eolcalib_o.c_EolInitData_ps->cameraId_u8);

  stateAlgo_e = ME_Hydra3defs_E_EOLAlgoState_t::e_EOLRunning;

  dataProvider_ro.putEolOutput(eolcalib_o.lCaliVCalibration_s, stateAlgo_e, m_CurrCamID);

  /*360 EOL Calibration*/
  eolcalib_o.lCaliFInit_v();

}

// -------------------------------------------------------------------------
bool_t EOLThreadRunnable::hasNext_b()
{
  /* DD-ID: {AD9CDE54-97F8-4a5b-BE78-0A25CD148475}*/
  bool_t v_Ret_b = false;
  /*if (e_EolAlgoDoNothing != stateAlgo_e)
  {
    v_Ret_b = true;
  }*/
  return v_Ret_b;
}

// -------------------------------------------------------------------------
void EOLThreadRunnable::execute_v()
{
  /* DD-ID: {1BB60FD7-CCBE-4893-B7EB-737D6A6346B7}*/
  #if ENABLE_DEBUG
    ME_Debugger_F_Printf_v("\n ###### JobEol::execute() ###### \n");
  #endif 
  eolcalib_o.lCaliFCalibrate_v();
#if 0
  EOL_DEBUG_PRINTF(("Algo output: Pitch*1000: %d\n", static_cast<sint32_t>(1000.0F*eolcalib_o.lCaliVCalibration_s.camPitch_f32)));
  EOL_DEBUG_PRINTF(("Algo output: Yaw*1000: %d\n", static_cast<sint32_t>(1000.0F*eolcalib_o.lCaliVCalibration_s.camYaw_f32)));
  EOL_DEBUG_PRINTF(("Algo output: Roll*1000: %d\n", static_cast<sint32_t>(1000.0F*eolcalib_o.lCaliVCalibration_s.camRoll_f32)));
  EOL_DEBUG_PRINTF(("Algo output: X*100: %d\n", static_cast<sint32_t>(100.0F*eolcalib_o.lCaliVCalibration_s.camX_f32)));
  EOL_DEBUG_PRINTF(("Algo output: Y*100: %d\n", static_cast<sint32_t>(100.0F*eolcalib_o.lCaliVCalibration_s.camY_f32)));
  EOL_DEBUG_PRINTF(("Algo output: Z*100: %d\n", static_cast<sint32_t>(100.0F*eolcalib_o.lCaliVCalibration_s.camZ_f32)));
#endif
}

// -------------------------------------------------------------------------
EolCalib& EOLThreadRunnable::getEolCalib_ro()
{
  /* DD-ID: {14317D9B-FB3A-46ab-AD77-1FCF043E6BC1}*/
  return eolcalib_o;
}

// -------------------------------------------------------------------------
void EOLThreadRunnable::end_v()
{
  /* DD-ID: {F0EF99CE-650B-4040-9EC2-E67FBAB0E11B}*/
  stateAlgo_e = ME_Hydra3defs_E_EOLAlgoState_t::e_EOLFinished;
  dataProvider_ro.putEolOutput(eolcalib_o.lCaliVCalibration_s, stateAlgo_e, m_CurrCamID);

#if DUMP_EOL_DATA
    dump_v();
#endif
}

// -------------------------------------------------------------------------
void EOLThreadRunnable::dump_v()
{
  /* DD-ID: {C33528BC-7D12-44f6-8DFF-E589B1F4907B}*/
  //ME_Debugger_F_Printf_v("\n ###### JobEol::dump begin() ###### \n");
  FILE *fp = fopen("/tmp/EOL_Output.csv","a+");

    fprintf(fp,"%d,",(int)m_CurrCamID);
    fprintf(fp,"%f,",eolcalib_o.lCaliVCalibration_s.camPitch_f32);
    fprintf(fp,"%f,",eolcalib_o.lCaliVCalibration_s.camYaw_f32);
    fprintf(fp,"%f,",eolcalib_o.lCaliVCalibration_s.camRoll_f32);
    fprintf(fp,"%f,",eolcalib_o.lCaliVCalibration_s.camX_f32);
    fprintf(fp,"%f,",eolcalib_o.lCaliVCalibration_s.camY_f32);
    fprintf(fp,"%f\n",eolcalib_o.lCaliVCalibration_s.camZ_f32);

  fprintf (fp, "%i,%i,%i,%i,%i,%i,%i,%i\n",
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.status_u8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetInit_s8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8,
      eolcalib_o.lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8);//-V_CameraParam_s[i].Yaw_f32);
  fclose(fp);

  FILE *im_dump;
  if (m_CurrCamID == ME_Hydra3defs_E_CameraID_e::CamID_Front)
  {
    im_dump = fopen("/tmp/FrontEolImage.raw","wb");
  } else if (m_CurrCamID == ME_Hydra3defs_E_CameraID_e::CamID_Left)
  {
    im_dump = fopen("/tmp/LeftEolImage.raw","wb");
  } else if (m_CurrCamID == ME_Hydra3defs_E_CameraID_e::CamID_Right)
  {
    im_dump = fopen("/tmp/RightEolImage.raw","wb");
  } else if (m_CurrCamID == ME_Hydra3defs_E_CameraID_e::CamID_Rear)
  {
    im_dump = fopen("/tmp/RearEolImage.raw","wb");
  }
  //im_dump = fopen("/tmp/EolImage.raw","wb");
  fwrite(eol::m_InputImage, sizeof(eol::m_InputImage[0]), 1920*1280, im_dump);
  fclose(im_dump);
  //ME_Debugger_F_Printf_v("\n ###### JobEol::dump done() ###### \n");

}

// -------------------------------------------------------------------------
void EOLThreadRunnable::reset_v( void )
{
  /* DD-ID: {3DAB35F0-0C17-466e-80A9-F065B364277A}*/

}

void EOLThreadRunnable::cleanup_v() {
  /* DD-ID: {E72B84C8-5C4A-4595-8719-5D35A5137F2B}*/
}

// -------------------------------------------------------------------------
} //namespace Eol
