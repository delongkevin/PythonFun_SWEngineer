//--------------------------------------------------------------------------
/// @file DLDThread.cpp
/// @brief Contains the Job definition for DLD
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#include "DLDThread.h"
#include <logging/Logger.h>
#include "algo/common/DLDDef.h"

#define _30_FPS_ ((uint32_t)32)
#define NUM_FRAMES_PER_CAMERA ((uint32_t)1u)
// Global variable to init DLD once
static bool_t b_isDLDInit_done = 0;
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_DLDThread     (1u)
#endif
#if PROFILE_DLDThread
#include "osal/system/Clock.h"
static uint32_t v_AvgDLDThreadRuntime_u32 = 0;
static uint32_t v_DLDThreadRunCntr_u32 = 0;
static uint32_t v_AvgDLDThreadPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_DLDThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsThEnable_dp;
#endif

namespace dld
{

DLDThreadRunnable::DLDThreadRunnable(IDataProviderDLD& b_DataProvider_ro)
: IRunnable(), 
m_currCamId(DLD_Camera_ID::DLD_NUM_CAMS),
m_jobDLDInput(),
m_jobDLDOutput(),
m_dataProvider_ro(b_DataProvider_ro),
m_stateMachine(NUM_FRAMES_PER_CAMERA),
m_dldAlgo()
{

}

DLDThreadRunnable::~DLDThreadRunnable() {

}

  /*
	*	Name: clearCamera
	*	Remarks: DD-ID: {77FADE6D-5BFE-45ac-9E5A-7130C5A251CA}
	*	Remarks: DD-ID: {67F8C6B0-B711-466c-ADDD-02FDB59D808A}
	*	Remarks: DD-ID: {A978546F-6140-40d2-A928-21BD4622AB09}
  */
void DLDThreadRunnable::clearCamera(DLD_Camera_ID camId) {
  m_jobDLDOutput.DldCameraStatus[camId].DLD_CamSts_e = DLD_Unknown;
  m_jobDLDOutput.DldCameraStatus[camId].OcclusionStatus = FALSE;
  m_jobDLDOutput.DldCameraStatus[camId].LowlightStatus = FALSE;
  m_jobDLDOutput.DldCameraStatus[camId].LowlightPerc = 0.0f;
  m_jobDLDOutput.DldCameraStatus[camId].HighlightPerc = 0.0f;
  m_jobDLDOutput.DldCameraStatus[camId].OccludedBinPerc = 0.0f;
  m_jobDLDOutput.DldCameraStatus[camId].UnoccludedBinPerc = 0.0f;
}

void DLDThreadRunnable::init_v() {
#if ENABLE_DLD_PROFILE
  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif

  ME_Thread_Sleep_t(500);
  /* Capture first frame to initialize algo views */
  m_jobDLDInput = m_dataProvider_ro.getDLDInput(DLD_Camera_ID::DLD_Rear);
  DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] DLDThreadRunnable::init_v()\n");

#if ENABLE_DLD_PROFILE
  uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
  ME_Debugger_F_Printf_v("[DLD Profile] Init: Time : %f ms (start = %f, end = %f)\n",
    (float32_t)(v_TotalTime_u64 * 1.0f), (float32_t)v_StartTime_u64, (float32_t)v_EndTime_u64);
#endif
  return;
}
  /*
	*	Name: run_b
	*	Remarks: DD-ID: {8D54D68C-0185-42b0-9AF8-8A9A921462A3}
	*	Remarks: DD-ID: {1CFA7F71-E51B-4141-BB4E-5B1F2DC022C5}
	*	Remarks: DD-ID: {86B70C0E-6E38-44db-B7FD-D7FD45BEFF16}
  */
bool_t DLDThreadRunnable::run_b() {
#if PROFILE_DLDThread
    PerformanceStatsThEnable_dp = m_dataProvider_ro.get_PerformanceStatsEnable();
    static osal::Time start;
    volatile uint32_t v_Start_t = 0;
    volatile uint32_t v_End_t = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE ==  PerformanceStatsThEnable_dp.RunTimeStatsEnable)
    {
      v_Start_t = __get_time_usec();
      currPeriodicity = v_Start_t - v_PreviousTime_u32;
    }
#endif

  DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] DLDThreadRunnable::run_b()\n");

  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = 0;
  uint64_t v_EndTime_u64 = 0;
  static uint32_t v_TotalTime_u32 = 0;
  uint32_t v_AdjustmentTime_u32 = 0;
  v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  bool_t statusInit = false;

  if (b_isDLDInit_done == 0)
  {
    /* algo init */
    statusInit = m_dldAlgo.init();
    if (statusInit)
    {
      /* Configure input padding as per the IO file */
      uint32_t inPadL = 0, inPadT = 0, inPadR = 0, inPadB = 0;
      m_dldAlgo.getInputPadSizes(inPadL, inPadT, inPadR, inPadB);
      m_dataProvider_ro.setInputPadSizes(inPadL, inPadT, inPadR, inPadB);
      b_isDLDInit_done = 1;
      ME_Debugger_F_Printf_v("\n ### DLD Init Done #### \n");
    }
  }

  /* Check status of other features to reduce the CPU load */
  bool isAllowed = m_dataProvider_ro.isFeatureAllowedToRun();
  if (isAllowed && b_isDLDInit_done)
  {
    startDLD();
    executeDLD();
  }
  else
  {
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Invalid Conditions <isAllowed=%d>\n", isAllowed);
    /*// Algo paused - do not clear the last results, change state only
    for (uint8_t camId = DLD_Camera_ID::DLD_Rear; camId < DLD_Camera_ID::DLD_NUM_CAMS; camId++)
    {
      m_jobDLDOutput.DldCameraStatus[camId].DLD_CamSts_e = DLD_Unknown;
    }*/
    for(uint8_t camId = DLD_Camera_ID::DLD_Rear; camId < DLD_Camera_ID::DLD_NUM_CAMS; camId++) {
    clearCamera(static_cast<DLD_Camera_ID>(camId));
    }
  }

  endDLD();
#if PROFILE_DLDThread
    if (TRUE ==  PerformanceStatsThEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      //ME_Debugger_F_Printf_v("DLDThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_DLDThreadRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgDLDThreadPeriodicity_u32 = ((v_AvgDLDThreadPeriodicity_u32 * (v_DLDThreadRunCntr_u32 -1)) + currPeriodicity)/v_DLDThreadRunCntr_u32; //Average Periodicity
      v_AvgDLDThreadRuntime_u32 = ((v_AvgDLDThreadRuntime_u32 * (v_DLDThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_DLDThreadRunCntr_u32; //New Average  
      //ME_Debugger_F_Printf_v("DLDThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_DLDThreadRuntimeData = (((v_AvgDLDThreadRuntime_u32/1000U)<<16U) | ((v_AvgDLDThreadPeriodicity_u32/1000U) & 0xFFFF));
      m_dataProvider_ro.setDLDThreadRuntime(v_DLDThreadRuntimeData);
      //ME_Debugger_F_Printf_v("DLDTh: E: %lld P: %lld \n", v_AvgDLDThreadRuntime_u32, v_AvgDLDThreadPeriodicity_u32);
      v_PreviousTime_u32 = v_Start_t;
    }
#endif

  v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  v_TotalTime_u32 = (uint32_t)(v_EndTime_u64 - v_StartTime_u64);
  if(v_TotalTime_u32 > _30_FPS_) {
    v_AdjustmentTime_u32 = (v_TotalTime_u32 % _30_FPS_); /* Remaning time above 30FPS */
    v_AdjustmentTime_u32 = (_30_FPS_ - v_AdjustmentTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
    ME_Thread_Sleep_t(v_AdjustmentTime_u32);
  }
  else {
    v_AdjustmentTime_u32 = (_30_FPS_ - v_TotalTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
    ME_Thread_Sleep_t(v_AdjustmentTime_u32);
  }

  return true;
}
	/*
	*	Name: start_v
	*	Remarks: DD-ID: {AA892F8F-49C0-465b-93DF-C4C6D2B71FD6}
	*	Remarks: DD-ID: {B81DEF37-6C2A-4f6c-A628-1EF56E8B252E}
	*	Remarks: DD-ID: {F2FCD75F-F145-4218-886C-196C74AB6493}
	*/
void DLDThreadRunnable::startDLD() {
#if ENABLE_DLD_PROFILE
  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif

  JobDLDVehicleInput_s vehicleInput = m_dataProvider_ro.getVehicleInput();
  bool allDoorsClosed = (vehicleInput.RHatchSts == 0) 
                     && (vehicleInput.LHRDoorSts == 0) 
                     && (vehicleInput.PsngrDoorSts == 0) 
                     && (vehicleInput.RHRDoorSts == 0) 
                     && (vehicleInput.DriverDoorSts == 0);

  /* Check status of other features to reduce the CPU load */
  //bool isAllowed = m_dataProvider_ro.isFeatureAllowedToRun();

  if(allDoorsClosed && (TeVBII_e_CmdIgnSts_RUN == vehicleInput.CmdIgnSts)) {
    static bool_t proxyValid_b = false;
    // Read proxy parameters until it is received as valid
    if (false == proxyValid_b)
    {
      proxy = m_dataProvider_ro.getProxiSettings();
      if (true == proxy->PRX_bValid_b)
      {
        proxyValid_b = true;
      }
    }
    /* Check and update camera participation */
    const JobDLDFIDs_t dldFIDs = m_dataProvider_ro.getDLDFIDs();
    bool camAvailable[DLD_Camera_ID::DLD_NUM_CAMS] = { false };
    camAvailable[DLD_Camera_ID::DLD_Rear]  = (dldFIDs.FID_DLD_REAR_DISABLED == 0u)  && (true == proxy->PRX_SurroundViewCamera_b || true == proxy->PRX_RvcEnbl_b) ;
    camAvailable[DLD_Camera_ID::DLD_Front] = (dldFIDs.FID_DLD_FRONT_DISABLED == 0u) && (true == proxy->PRX_SurroundViewCamera_b || true == proxy->PRX_FrwFacingCam_b);
    camAvailable[DLD_Camera_ID::DLD_Left] = (dldFIDs.FID_DLD_LEFT_DISABLED == 0u) && (true == proxy->PRX_SurroundViewCamera_b);
    camAvailable[DLD_Camera_ID::DLD_Right] = (dldFIDs.FID_DLD_RIGHT_DISABLED == 0u) && (true == proxy->PRX_SurroundViewCamera_b);
#if ENABLE_DLD_CHMSL_CAMERA
    camAvailable[DLD_Camera_ID::DLD_Chmsl] = (dldFIDs.FID_DLD_CHMSL_DISABLED == 0u) && (true == proxy->PRX_Digital_CHMSL_Camera_Psrnt); // todo check proxy
#endif

    for(uint8_t camId = DLD_Camera_ID::DLD_Rear; camId < DLD_Camera_ID::DLD_NUM_CAMS; camId++) {
      m_stateMachine.updateParticipation(static_cast<DLD_Camera_ID>(camId), camAvailable[camId]);
      /* Reset to unknown state for unavailable cameras */
      if(!camAvailable[camId]) { clearCamera(static_cast<DLD_Camera_ID>(camId)); }
    }

    /* Select camera from available list */
    m_currCamId = m_stateMachine.getCameraID();
    
    /* Capture the camera frame for selected camera */
    m_jobDLDInput = m_dataProvider_ro.getDLDInput(m_currCamId);
  }
  else {
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Invalid Conditions <CmdIgnSts=%d, Doors=%d%d%d%d%d>\n", 
      vehicleInput.CmdIgnSts, vehicleInput.RHatchSts, vehicleInput.PsngrDoorSts,
      vehicleInput.LHRDoorSts, vehicleInput.DriverDoorSts, vehicleInput.RHRDoorSts);
      
      m_currCamId = DLD_Camera_ID::DLD_NUM_CAMS;
      for(uint8_t camId = DLD_Camera_ID::DLD_Rear; camId < DLD_Camera_ID::DLD_NUM_CAMS; camId++) {
        clearCamera(static_cast<DLD_Camera_ID>(camId));
      }
#if 0
    if(TRUE == m_dldAlgo.isInitialised()) {
      /* algo deinit */
      m_dldAlgo.deinit();
      ME_Debugger_F_Printf_v("[DLD] ### DLD DE-INIT ###\n");
    }
    #endif
  }

#if ENABLE_DLD_PROFILE
  uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
  ME_Debugger_F_Printf_v("[DLD Profile] startDLD: Time : %f ms (start = %f, end = %f)\n",
    (float32_t)(v_TotalTime_u64 * 1.0f), (float32_t)v_StartTime_u64, (float32_t)v_EndTime_u64);
#endif
}
	/*
	*	Name: execute_v
	*	Remarks: DD-ID: {A52C26B4-8882-4b1c-8127-CABACFF16428}
	*	Remarks: DD-ID: {393287B3-7448-4cec-A9DD-9E6A6C7DB95C}
	*	Remarks: DD-ID: {4A0B1BE5-C59B-4cb8-A34B-1AA7BA7A0175}
	*/
void DLDThreadRunnable::executeDLD() {
#if ENABLE_DLD_PROFILE
  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif

  /* Process DNN algo and get results */
  if((m_currCamId < DLD_Camera_ID::DLD_NUM_CAMS)) {
    m_jobDLDOutput.DldCameraStatus[m_currCamId] = m_dldAlgo.ProcessDNN(m_currCamId, m_jobDLDInput.InputImgColor_pu8);
  }

#if ENABLE_DLD_PROFILE
  uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
  ME_Debugger_F_Printf_v("[DLD Profile] executeDLD: Time : %f ms (start = %f, end = %f)\n",
    (float32_t)(v_TotalTime_u64 * 1.0f), (float32_t)v_StartTime_u64, (float32_t)v_EndTime_u64);
#endif
}
	/*
	*	Name: end_v
	*	Remarks: DD-ID: {50E80602-1332-454e-97C6-EA1189EB8276}
	*	Remarks: DD-ID: {E443A80D-A0EC-4f4b-ACC6-9EF744E0B08F}
	*	Remarks: DD-ID: {EE1AA4D0-1CAA-41e9-948B-FAF118501CEA}
	*/
void DLDThreadRunnable::endDLD() {
#if ENABLE_DLD_PROFILE
  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif

  m_dataProvider_ro.setDLDOutput(m_jobDLDOutput);

#if ENABLE_DLD_PROFILE
  uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
  ME_Debugger_F_Printf_v("[DLD Profile] endDLD: Time : %f ms (start = %f, end = %f)\n",
    (float32_t)(v_TotalTime_u64 * 1.0f), (float32_t)v_StartTime_u64, (float32_t)v_EndTime_u64);
#endif

};

void DLDThreadRunnable::cleanup_v() {
  #if 0
  if(m_dldAlgo.isInitialised()) {
    m_dldAlgo.deinit();
  }
  #endif
}

void DLDThreadRunnable::stop_v() {

}

} // namespace dld

