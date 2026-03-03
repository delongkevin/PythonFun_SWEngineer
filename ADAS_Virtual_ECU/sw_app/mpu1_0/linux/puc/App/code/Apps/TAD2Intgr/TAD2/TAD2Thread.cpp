//--------------------------------------------------------------------------
/// @file TAD2Thread.cpp
/// @brief Contains the Job definition for TAD2 Thread
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
//  --------------------------------------------------------------------------

#include "TAD2Thread.h"
#include <logging/Logger.h>
#include "CANData.h"
#include "TRSC_Inputs_Outputs.h"
#include <cfg/shmdata/SigMData.h>
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_TADThread (1u)
#endif
#if PROFILE_TADThread
#include "osal/system/Clock.h"
static uint32_t v_AvgTADThreadRuntime_u32 = 0;
static uint32_t v_TADThreadRunCntr_u32 = 0;
static uint32_t v_AvgTADThreadPeriodicity_u32 = 0;
static uint32_t v_TADThreadPreviousTime_u32 = 0;
static uint32_t v_TADThreadRuntimeData = 0; // Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif

#define DEG_TO_RAD_FACTOR (0.0174532F)

extern volatile uint32_t m_FrameNumber;
#if !(TAD2_SIGM_TESTING)
const uint32_t TestDataSize_u32 = 11000;
#endif
#if DUMP_ALGO_VIEW_FOR_STATE7
extern int32_t TADState;
#endif

#if NVM_SANITY_TEST
const uint32_t trailerFeaturesBuff_Size = 182988 + 132;
extern uint8_t trailerFeaturesBuff[trailerFeaturesBuff_Size];
#include <fsdata/fsdata.h>
uint8_t trailerFeaturesBuff_read[trailerFeaturesBuff_Size];
#endif

extern TRSC_Calibration_data_MPU1_0_t TAD_Calib_Data;
extern uint8_t var_id;

#define _30_FPS_ ((uint32_t)32)

static real32_T KeTRSC_k_WhlAngCFBiasType1 = -0.0187606F;
static real32_T KeTRSC_k_WhlAngCFBiasType2 = -0.0154752F;
static real32_T KeTRSC_k_WhlAngCFBiasType3 = -0.0129193F;

static real32_T KeTRSC_k_WhlAngCFWtType1 = -0.0593083F;
static real32_T KeTRSC_k_WhlAngCFWtType2 = -0.0640842F;
static real32_T KeTRSC_k_WhlAngCFWtType3 = -0.0670865F;

namespace TAD2
{

  TAD2ThreadRunnable::TAD2ThreadRunnable(IDataProviderTAD2 &b_DataProvider_ro)
      : IRunnable(), dataProvider_ro(b_DataProvider_ro)
  {
    m_jobOutput.TRSC_DIDOutput.IeTRSC_e_TrailerCalibMemClearResponse.CalibMemClearResponse = TeTRSC_e_TrailerCalibMemClearResponse_Dummy;
    TRSCCalibClearResponse.CalibMemClearResponse = TeTRSC_e_TrailerCalibMemClearResponse_Dummy;
    TRSCCalibClearResponse.bValid = false;
    m_TAD2_Reload_Calib = false;
  }

  TAD2ThreadRunnable::~TAD2ThreadRunnable()
  {
  }

  void TAD2ThreadRunnable::init_v()
  {
#if TAD2_DEBUG_PRINTS
    ME_Debugger_F_Printf_v("\n ### TAD2ThreadRunnable::init_v Begin ###\n");
#endif

    m_jobOutput = {};
    if (m_initialized)
    {
      return;
    }

    memory::MemoryPool::Init();
    m_jobInput = dataProvider_ro.get_input();
    dataProvider_ro.set_config(m_config);
    m_TADAlgoObject.Init(m_config, dataProvider_ro.get_vehicle_params());
    m_TADAlgoObject.Start(*m_jobInput);
    m_initialized = true;

    return;
  }

  bool_t TAD2ThreadRunnable::run_b()
  {
#if PROFILE_TADThread
    PerformanceStatsEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
    static osal::Time start;
    volatile uint32_t v_Start_t = 0;
    volatile uint32_t v_End_t = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE == PerformanceStatsEnable_dp.RunTimeStatsEnable)
    {
      v_Start_t = __get_time_usec();
      currPeriodicity = v_Start_t - v_TADThreadPreviousTime_u32;
    }
#endif
#if TAD2_DEBUG_PRINTS
    ME_Debugger_F_Printf_v("\n TAD2ThreadRunnable::run_b() start\n");
#endif
    static osal::Time v_Time_o;
    static uint64_t v_StartTime_u64 = 0;
    static uint64_t v_EndTime_u64 = 0;
    static uint32_t v_TotalTime_u32 = 0;
    static uint32_t v_AdjustmentTime_u32 = 0;
    static bool_t b_TAD2_Reset_Allowed = true;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
    inputsFromTRSCSMVC = dataProvider_ro.getDetection_Inputs_from_TRSC();

    static bool_t proxyValid_b = false;
    // Read proxy parameters until it is received as valid
    if (false == proxyValid_b)
    {
      proxy_TAD2 = dataProvider_ro.getProxyData();
      if (true == proxy_TAD2->PRX_bValid_b)
      {
        proxyValid_b = true;
      }
    }

    bool isTADAllowed = dataProvider_ro.isTADFeatureAllowedToRun(inputsFromTRSCSMVC.MeTRSC_e_TrlrPrsntInfoCAN);

    if (true == isTADAllowed)
    {
#if UART_PRINT_TAD2_OUTPUT
      static osal::Time start;
      volatile uint64_t v_TAD_Befor_Start_t, v_TAD_Befor_Execute_t, v_TAD_Befor_End_t;
      volatile uint64_t v_TAD_After_Start_t, v_TAD_After_Execute_t, v_TAD_After_End_t;
      static uint64_t v_TAD_Previous_t = 0, v_TAD_Current_t = 0;
      v_TAD_Befor_Start_t = start.getTimeMsec_u64();
      v_TAD_Current_t = start.getTimeMsec_u64();
#endif
      TRSCCalibClearResponse = dataProvider_ro.calibrationMemClear();
      startTAD2();

#if UART_PRINT_TAD2_OUTPUT
      v_TAD_After_Start_t = start.getTimeMsec_u64();
      v_TAD_Befor_Execute_t = start.getTimeMsec_u64();
#endif // UART_PRINT_TAD2_OUTPUT

      executeTAD2();

#if UART_PRINT_TAD2_OUTPUT
      v_TAD_After_Execute_t = start.getTimeMsec_u64();
      v_TAD_Befor_End_t = start.getTimeMsec_u64();
#endif // UART_PRINT_TAD2_OUTPUT

      endTAD2();

#if UART_PRINT_TAD2_OUTPUT
      v_TAD_After_End_t = start.getTimeMsec_u64();
      startTime = v_TAD_After_Start_t - v_TAD_Befor_Start_t;
      executeTime = v_TAD_After_Execute_t - v_TAD_Befor_Execute_t;
      endTime = v_TAD_After_End_t - v_TAD_Befor_End_t;
      periodicity = v_TAD_Current_t - v_TAD_Previous_t;
      v_TAD_Previous_t = v_TAD_Current_t;
#endif // UART_PRINT_TAD2_OUTPUT

      b_TAD2_Reset_Allowed = true;
    }
    else if (true == b_TAD2_Reset_Allowed)
    {
      m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo = TeTRSC_e_TrlrCalInfo_NotCalibrated;
      m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrRecogInfo = TeTRSC_e_TrlrRecogInfo_Unknown;
      m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrPrsntInfo = TeTRSC_e_TrlrPrsntInfo_Unknown;
      m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState = TeTRSC_e_TADState_Idle;
      dataProvider_ro.setTRSC_Inputs_from_TrailerDetection(m_jobOutput.TRSC_TAD_output);
      reset_b();
      b_TAD2_Reset_Allowed = false;
      m_TAD2_Reload_Calib = true;
    }
#if PROFILE_TADThread
      if (TRUE == PerformanceStatsEnable_dp.RunTimeStatsEnable)
      {
        v_End_t = __get_time_usec();
        // ME_Debugger_F_Printf_v("TADThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
        v_TADThreadRunCntr_u32++;                                                                                                                    // Increment the run counter for averaging purpose
        v_AvgTADThreadPeriodicity_u32 = ((v_AvgTADThreadPeriodicity_u32 * (v_TADThreadRunCntr_u32 - 1)) + currPeriodicity) / v_TADThreadRunCntr_u32; // Average Periodicity
        v_AvgTADThreadRuntime_u32 = ((v_AvgTADThreadRuntime_u32 * (v_TADThreadRunCntr_u32 - 1)) + (v_End_t - v_Start_t)) / v_TADThreadRunCntr_u32;   // New Average

        v_TADThreadRuntimeData = (((v_AvgTADThreadRuntime_u32/1000U) << 16U) | ((v_AvgTADThreadPeriodicity_u32/1000U) & 0xFFFF));
        dataProvider_ro.setTADThreadRuntime(v_TADThreadRuntimeData);
        //ME_Debugger_F_Printf_v("TADThread: E: %lld P: %lld \n", v_AvgTADThreadRuntime_u32, v_AvgTADThreadPeriodicity_u32);
        v_TADThreadPreviousTime_u32 = v_Start_t;
      }
#endif    

      v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
      v_TotalTime_u32 = (uint32_t)(v_EndTime_u64 - v_StartTime_u64);
      if (v_TotalTime_u32 > _30_FPS_)
      {
        v_AdjustmentTime_u32 = (v_TotalTime_u32 % _30_FPS_);      /* Remaning time above 30FPS*/
        v_AdjustmentTime_u32 = (_30_FPS_ - v_AdjustmentTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
        ME_Thread_Sleep_t(v_AdjustmentTime_u32);
      }
      else
      {
        v_AdjustmentTime_u32 = (_30_FPS_ - v_TotalTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
        ME_Thread_Sleep_t(v_AdjustmentTime_u32);
      }
#if UART_PRINT_TAD2_OUTPUT
      ME_Debugger_F_Printf_v("TAD2 : %d, %d, %d, %d\n", startTime, executeTime, endTime, periodicity);
#endif // UART_PRINT_TAD2_OUTPUT
#if TAD2_DEBUG_PRINTS
      ME_Debugger_F_Printf_v("\n TAD2ThreadRunnable::run_b() end\n");
#endif

#if NVM_SANITY_TEST
      tadNVMSanity();
#endif
      return true;
  }

  void TAD2ThreadRunnable::reset_b()
  {
    m_TADAlgoObject.Uninit();
  }

  void TAD2ThreadRunnable::startTAD2()
  {
#if PROFILE_TAD2
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif // PROFILE_TAD2
#if TAD2_SIGM_TESTING
    osal::Time v_Time2_o;
    uint64_t v_TimeStamp_u64 = 0;
    v_TimeStamp_u64 = v_Time2_o.getTimeMsec_u64();

    static IKinematicData_t v_KM_Data_t;
    memset(&v_KM_Data_t, 0, sizeof(IKinematicData_t));
    v_KM_Data_t = dataProvider_ro.getKMData();
    v_KMData.dx_m = v_KM_Data_t.dx_m;
    v_KMData.dy_m = v_KM_Data_t.dy_m;
    v_KMData.dyaw_rad = v_KM_Data_t.dyaw_rad;

    dataProvider_ro.getVehicleData();
    v_VehData.speed_kmPh = dataProvider_ro.getVehicleSpeed();
    v_VehData.gear = (TAD2::eVehicleGear)dataProvider_ro.getVehicleGear();
    v_VehData.steeringWheelAngle_rad = dataProvider_ro.getVehicleSteeringWheelAng() * 0.0174532;
    v_VehData.timeStamp_s = (float32_t)v_TimeStamp_u64 / 1000.0f;

    float32_t steeringWheelAngle = dataProvider_ro.getVehicleSteeringWheelAng();
    /*calculating wheelangle using proxi steering type*/
    // 0 = type1, 1 = type2, 2 = type3
    if (proxy_TAD2->PRX_StrRatRckPinionTyp_u8 == 0)
    {
      // type 1
      v_VehData.wheelAngle_rad = DEG_TO_RAD_FACTOR * (steeringWheelAngle * KeTRSC_k_WhlAngCFWtType1 + KeTRSC_k_WhlAngCFBiasType1);
    }
    else if (proxy_TAD2->PRX_StrRatRckPinionTyp_u8 == 1)
    {
      // type 2
      v_VehData.wheelAngle_rad = DEG_TO_RAD_FACTOR * (steeringWheelAngle * KeTRSC_k_WhlAngCFWtType2 + KeTRSC_k_WhlAngCFBiasType2);
    }
    else
    {
      // type 3 - If not type1 or type2 smallest bias value will be default i.e type 3
      v_VehData.wheelAngle_rad = DEG_TO_RAD_FACTOR * (steeringWheelAngle * KeTRSC_k_WhlAngCFWtType3 + KeTRSC_k_WhlAngCFBiasType3);
    }

    if (true == m_TAD2_Reload_Calib)
    {
      dataProvider_ro.InitTrailerTemplate();
      dataProvider_ro.InitJobInput();
      m_jobInput = dataProvider_ro.get_input();
      m_TADAlgoObject.Init(m_config, dataProvider_ro.get_vehicle_params());
      m_TADAlgoObject.Start(*m_jobInput);
      m_TAD2_Reload_Calib = false;
    }

#else  // TAD2_SIGM_TESTING
    v_VehData = dataProvider_ro.get_Vehicle_data();
    v_KMData = dataProvider_ro.get_kinematic_data();
#endif // TAD2_SIGM_TESTING
#if PROFILE_TAD2
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("startTAD2 Time : %f ms\n", (float32_t)(v_TotalTime_u64 * 1.0f));
#endif // PROFILE_TAD2
  }

  void TAD2ThreadRunnable::executeTAD2()
  {
    uint32_t dataread = dataProvider_ro.read_topview_gray();

#if PROFILE_TAD2
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif

#if TAD2_SIGM_TESTING
    m_TADAlgoObject.Run(m_FrameNumber, (uint8_t *)dataProvider_ro.get_topview_u8c1(),
                        v_VehData, v_KMData,
                        inputsFromTRSCSMVC,
                        dataProvider_ro.get_input()->DLDInput.CamBlockStatus);
#else
    dataProvider_ro.readSanityTestData(v_VehData, v_KMData);
    static Detection_Inputs_from_TRSC_t StatemachineInput_test;
    // Below hardcoded numbers are for 20230901_TRSC_1.vid
    StatemachineInput_test.MeTRSC_deg_JackKnifeAngle = 80.00f;
    StatemachineInput_test.MeTRSC_m_TrailerBeamLen = 2100;
    StatemachineInput_test.MeTRSC_b_TRSCSwitchPressed = true;
    StatemachineInput_test.MeTRSC_b_TBLComputationDone = true;
    m_TADAlgoObject.Run(m_FrameNumber, (uint8_t *)dataProvider_ro.get_topview_u8c1(),
                        v_VehData, v_KMData,
                        StatemachineInput_test,
                        /*dataProvider_ro.get_input().DLDInput.CamBlockStatus*/ false);
#endif
    m_TADAlgoObject.GetOutput(m_jobOutput);
#if PROFILE_TAD2
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    printf("Frame: %d Time : %f ms\n", m_FrameNumber, (float32_t)(v_TotalTime_u64 * 1.0f));
#endif
  }

  void TAD2ThreadRunnable::endTAD2()
  {
#if PROFILE_TAD2
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif

#if (TAD2_SIGM_TESTING) // Pankaj: commented for unit testing
    if ((TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection == m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState) ||
        (TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround == m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState))
    {
      m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle = m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle - 90.0f;
    }
    else
    {
      m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle = 0;
    }
#endif
#if TAD2_HARDCODING_FOR_TEST
    m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle = 0;
#endif

    dataProvider_ro.put_output(m_jobOutput);
    m_TADAlgoObject.GetDebugOutput(m_JobTADDebugOutput);

#if TAD2_NVM_ACCESS_ENABLED
    // Load Trailer
    m_jobInput->NVMInput.trailerLoadedSuccessfully = false;

    // Save Trailer
    if (previousState == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround && m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_ScanningForTrailer)
    {
      // store features
      TAD2::TrailerFeatures FeatureData = m_jobOutput.TRSC_NVM_Output.trailerFeatures;
      dataProvider_ro.SaveTrailerFeatures(FeatureData);
      dataProvider_ro.InitJobInput();
    }
    previousState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState;
#endif

#if TAD2_SIGM_TESTING
    m_jobOutput.TRSC_TAD_output.m_leftCalibrationAngle = m_JobTADDebugOutput.leftCalibrationAngle;
    m_jobOutput.TRSC_TAD_output.m_rightCalibrationAngle = m_JobTADDebugOutput.rightCalibrationAngle;
    m_jobOutput.TRSC_TAD_output.m_hitchCalibrationAngle = m_JobTADDebugOutput.hitchCalibrationAngle;
    m_jobOutput.TRSC_TAD_output.m_averageIllumination = m_JobTADDebugOutput.averageIllumination;

    dataProvider_ro.setTRSC_Inputs_from_TrailerDetection(m_jobOutput.TRSC_TAD_output);
    m_jobOutput.TRSC_DIDOutput.IeTRSC_e_TrailerCalibMemClearResponse.CalibMemClearResponse = TRSCCalibClearResponse.CalibMemClearResponse;
    m_jobOutput.TRSC_DIDOutput.IeTRSC_e_TrailerCalibMemClearResponse.bValid = TRSCCalibClearResponse.bValid;
    dataProvider_ro.setTrailerDetection_DID(m_jobOutput.TRSC_DIDOutput);
#endif
#if PROFILE_TAD2
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("State %d \n", m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState);
    ME_Debugger_F_Printf_v("endTAD2 Time : %f ms\n==============\n", (float32_t)(v_TotalTime_u64 * 1.0f));
#endif
#if DUMP_ALGO_VIEW_FOR_STATE7
    TADState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState;
#endif
#if UART_PRINT_TAD2_OUTPUT
    static int32_t count = 1;
    // if (!(count % 30))
    if (executeTime > 30.0f)
    {
      ME_Debugger_F_Printf_v("\nFrame : %d, TADAng: %f, TADSt: %d, Subst: %d, TSubst: %d, HL: %f Spd: %f, Gear: %d WhAngDeg: %f, LftCalAng: %f, RgtCalAng: %f, HtcCalAng: %f [%lld, %lld, %lld, %lld]",
                             m_FrameNumber,
                             m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle,
                             m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState,
                             m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate,
                             m_jobOutput.TRSC_TAD_output.MeTRSC_e_TurnAroundSubState,
                             m_jobOutput.TRSC_TAD_output.MeTRSC_m_HitchLength,
                             v_VehData.speed_kmPh,
                             v_VehData.gear,
                             v_VehData.wheelAngle_rad / 0.0174532f,
                             m_JobTADDebugOutput.leftCalibrationAngle,
                             m_JobTADDebugOutput.rightCalibrationAngle,
                             m_JobTADDebugOutput.hitchCalibrationAngle,
                             periodicity,
                             startTime,
                             executeTime,
                             endTime);
    }
    count++;
#endif
#if !(TAD2_SIGM_TESTING)
    if (m_FrameNumber <= TestDataSize_u32)
#endif
    {
      m_FrameNumber++;
    }
  };

  void TAD2ThreadRunnable::cleanup_v()
  {
#if TAD2_DEBUG_PRINTS
    // ME_Debugger_F_Printf_v("TAD2ThreadRunnable::cleanup_v()\n");
#endif
  }

  void TAD2ThreadRunnable::stop_v()
  {
  }

#if NVM_SANITY_TEST
  void TAD2ThreadRunnable::tadNVMSanity()
  {
    for (int i = 0; i < trailerFeaturesBuff_Size; i++)
    {
      trailerFeaturesBuff[i] = i;
    }

    fsdata::fsdata_store_data("/fs/sanity-100.dat", (char *)&trailerFeaturesBuff, trailerFeaturesBuff_Size);

    fsdata::fsdata_read_data("/fs/sanity-100.dat", (char *)&trailerFeaturesBuff_read, trailerFeaturesBuff_Size);

    int memcmp_result = 0;
    memcmp_result = memcmp(trailerFeaturesBuff, trailerFeaturesBuff_read, trailerFeaturesBuff_Size);

    if (0 == memcmp_result)
    {
      printf("Blocks are same =============== \n");
    }
    else
    {
      printf("Blocks are not same xxxxxxxxxxxxx \n");
    }

    trailerFeaturesBuff_read[0] = 5;
    memcmp_result = memcmp(trailerFeaturesBuff, trailerFeaturesBuff_read, trailerFeaturesBuff_Size);

    if (0 == memcmp_result)
    {
      printf("Content modified. Blocks are same =============== \n");
    }
    else
    {
      printf("Content modified. Blocks are not same xxxxxxxxxxxxx \n");
    }
  }
#endif

} // namespace TAD2
