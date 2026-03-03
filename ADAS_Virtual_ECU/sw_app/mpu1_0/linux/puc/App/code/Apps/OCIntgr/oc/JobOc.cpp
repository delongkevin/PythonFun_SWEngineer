//--------------------------------------------------------------------------
/// @file JobOC.cpp
/// @brief Contains
/// Online Calibration Job that calls the Targetless Service Calibration (TSC) algorithm
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Muzammil Rasool (muzammil.rasool@magna.com)
/// @author Nikhil Parlapalli (nikhil.parlapalli@magna.com)
///
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>


#include "JobOc.h"
#include "osal/system/Clock.h"

#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_OC     (1u)
#define PROFILE_OCThread     (1u)
#endif
#if PROFILE_OC
#include "osal/system/Clock.h"
static uint32_t v_AvgOCRuntime_u32 = 0;
static uint32_t v_OCRunCntr_u32 = 0;
static uint32_t v_AvgOCPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_OCRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif


#if PROFILE_OCThread
#include "osal/system/Clock.h"
static uint32_t v_AvgOCThreadRuntime_u32 = 0;
static uint32_t v_OCThreadRunCntr_u32 = 0;
static uint32_t v_AvgOCThreadPeriodicity_u32 = 0;
static uint32_t v_OCThreadPreviousTime_u32 = 0;
static uint32_t v_OCThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsThEnable_dp;
#endif

#ifdef OC_SIMINP_DEBUG
#include "osal/io/File.h"
#include "oc_simulation.h"
int oc_sim_frame_id;
#endif

//#define HARDCODE_OC
//#define OC_INDIV_PROFILE
//#define OC_TIMESTAMPS


uint8_t OcSyntheticImageFront_au8[IMAGE_WIDTH * IMAGE_HEIGHT]; 

namespace oc
{
#define _30_FPS_ ((uint32_t)32)

#ifdef OC_SIMINP_DEBUG //For Simulation 

const float64_t V_PreRoll_af32[tscApi::e_TscNumCam] =
{ -90.0F, 0.0F, 90.0F, 180.0F};

#endif

#ifdef USE_SVSCM

const float64_t V_PreRoll_af32[tscApi::e_TscNumCam] =
{ -90.0F, 0.0F, 90.0F, 180.0F};
#endif

/* *******************************************************************************
  *                             O C    J O B
  ******************************************************************************* */

JobOC::JobOC(container::JobDesc_s& b_JobDesc_rs, IDataProviderOC& b_DataProvider_ro)
  : container::JobBase<IDataProviderOC>(b_JobDesc_rs, b_DataProvider_ro),
  m_OCThread_o("OC_Thread"),
  m_OCThreadRunnable_o(b_DataProvider_ro)
{
  m_OCThread_o.setPriority_v(e_PriorityNormal);
}

JobOC::~JobOC() {
}

bool_t JobOC::onInit_b() {
  /* DD-ID: {D5E0BCC6-4E63-4765-AA06-BE1BDBE34916}*/
  m_OCThread_o.start_v(&m_OCThreadRunnable_o);
  return true;
}

void JobOC::onVariantChanged_v(bool_t i_FirstTime_b) {
  /* DD-ID: {FB6712D1-E7EC-4e97-A7B6-A9228AC2BB3D}*/
}

bool_t JobOC::onRun_b() {
  /* DD-ID: {4CDE18D1-68D2-42c1-ABED-637A3C3865D5}*/
#if PROFILE_OC
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

#if PROFILE_OC
    if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      //ME_Debugger_F_Printf_v("OC: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_OCRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgOCPeriodicity_u32 = ((v_AvgOCPeriodicity_u32 * (v_OCRunCntr_u32 -1)) + currPeriodicity)/v_OCRunCntr_u32; //Average Periodicity
      v_AvgOCRuntime_u32 = ((v_AvgOCRuntime_u32 * (v_OCRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_OCRunCntr_u32; //New Average  
      v_OCRuntimeData = (((v_AvgOCRuntime_u32/1000U)<<16U) | ((v_AvgOCPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setOCRuntime(v_OCRuntimeData);
      //ME_Debugger_F_Printf_v("OC: E: %lld P: %lld \n", v_AvgOCRuntime_u32, v_AvgOCPeriodicity_u32);
      v_PreviousTime_u32 = v_Start_t;
    }
#endif
    return true;
  }

void JobOC::onCleanup_v() {
  /* DD-ID: {28D39985-E166-42ea-BDEE-F39EF8B40E28}*/
  m_OCThread_o.terminate_v();
  m_OCThread_o.join_v();
}

/* *******************************************************************************
 *                     O C    T H R E A D   R U N N A B L E
 ******************************************************************************* */

OCThreadRunnable::OCThreadRunnable(IDataProviderOC &b_DataProvider_ro)
    :   dataProvider_ro(b_DataProvider_ro),
        state_e(e_UnInit),
        ocFrameCounter_u32(0U),
        isAlgorithmStarted_b(false),
        isNewCommand_b(false),
        algoCommand_e(AlgoCommand_Unknown),
        c_OcExtrinsics_ps(NULL),
        algoViewBufferToRead_e(container::e_OcAlgoViewBuffer0),
        algoViewConfiguredCounter_u32(0U),
        prevValidFeatureCount_u32(0U),
        abortFrameCounter_u32(0U),
        m_aFrontCameraInfo(b_DataProvider_ro.getFrontDoCameraParam()),
        m_aLeftCameraInfo(b_DataProvider_ro.getLeftDoCameraParam()),
        m_aRearCameraInfo(b_DataProvider_ro.getRearDoCameraParam()),
        m_aRightCameraInfo(b_DataProvider_ro.getRightDoCameraParam()),
        mcuCamIdToOcAlgo_e(container::e_Front)
{

#ifdef OC_SIMINP_DEBUG //For Simulation 

  oc_sim_frame_id = 1;  // Frame Id for Simulation 

#endif

  for (uint32_t v_Index_u32 = 0U; v_Index_u32 < static_cast<uint32_t>(tscApi::e_TscNumCam); v_Index_u32++)
  {
    tscIntermediateData_as[v_Index_u32].data_pu8 = NULL;
    tscIntermediateData_as[v_Index_u32].len_u32 = 0U;
    tscCtrlInfo_o.PutM_PSvdDtInf(v_Index_u32, &tscIntermediateData_as[v_Index_u32]);
  }

  memset(&tscStartConfiguration_as, 0, sizeof(tscStartConfiguration_as));
  memset(&tscErrorCode_ae, 0, sizeof(tscErrorCode_ae));
  memset(&tscAlgoState_ae, 0, sizeof(tscAlgoState_ae));
  memset(&tscCalibrationResults_as, 0, sizeof(tscCalibrationResults_as));
  tscCtrlInfo_o.PutM_Spd(0.0F);
  tscCtrlInfo_o.PutM_WhlAngl(0.0F);
  tscCtrlInfo_o.PutM_GrDrctn(tscApi::TSCCtrlInfo::e_GearForward);
  tscCtrlInfo_o.PutM_CmrFrntOpn(true);
  tscCtrlInfo_o.PutM_FrmNmbr(0U);
  tscCtrlInfo_o.PutM_VdWdth(c_ImageWidth_u32);
  tscCtrlInfo_o.PutM_VdHght(c_ImageHeight_u32);
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscFrontCam, NULL);
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscLeftCam, NULL);
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscRearCam, NULL);
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscRightCam, NULL);
  OC_DEBUG_PRINTF(("*JobOcConstructor* %d, %lu, %u, %d, %u\n", 
                      tscCtrlInfo_o.getMCmrFrntOpn_b(), 
                      tscCtrlInfo_o.getMFrmNmbr_u32(), 
                      tscCtrlInfo_o.getMVdHght_u16(), 
                      tscCtrlInfo_o.getMGrDrctn_s32(), 
                      tscCtrlInfo_o.getMVdWdth_u16()));
}

OCThreadRunnable::~OCThreadRunnable()
{
}

void OCThreadRunnable::init_v()
{
  /* DD-ID: {82D57202-B1AE-473f-AB6B-A41A2CC98B79}*/
#ifdef OC_TIMESTAMPS
 uint64_t curr_timestamp = 0;
 uint64_t prev_timestamp = 0;
#endif

  #if ENABLE_TSC_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif

  bool_t v_IsAlgoInitSuccess_b = false;

#ifdef OC_SIMINP_DEBUG //For Simulation 
  tscCtrlInfo_o.PutM_Spd(0.0F);
  tscCtrlInfo_o.PutM_WhlAngl(0.0F);
#endif
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscFrontCam, get640x400AlgoView_pu8(container::e_Front));
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscLeftCam, get640x400AlgoView_pu8(container::e_Left));
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscRearCam, get640x400AlgoView_pu8(container::e_Rear));
  tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscRightCam, get640x400AlgoView_pu8(container::e_Right));

  v_IsAlgoInitSuccess_b = TSC_Init(&tscCtrlInfo_o);

  if (false == v_IsAlgoInitSuccess_b)
  {
    initialisation_data.ocAlgoState_e = variants::e_OcStateError;
    initialisation_data.ocErrorCode_e = variants::e_OcErrCodeInitFail;
  }
  else
  {
    initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(tscApi::e_TscFrontCam));
    initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(tscApi::e_TscFrontCam));
    state_e = e_OcInit;
  }

#ifdef OC_SIMINP_DEBUG //For Simulation 
  const uint32_t c_FrameId_u32 = oc_sim_frame_id;
#else
  const uint32_t c_FrameId_u32 = dataProvider_ro.getFrameNum_u32();
#endif

  initialisation_data.updatedAt_u32 = c_FrameId_u32;

  OC_DEBUG_PRINTF(("*init_v* v_IsAlgoInitSuccess_b %d, state %d, error %d\n", v_IsAlgoInitSuccess_b, initialisation_data.ocAlgoState_e, initialisation_data.ocErrorCode_e));

  #if ENABLE_TSC_PROFILE
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("[TSC Profile] Init: Time : %f ms (start = %f, end = %f)\n",
    (float32_t)(v_TotalTime_u64 * 1.0f), (float32_t)v_StartTime_u64, (float32_t)v_EndTime_u64);
  #endif
}

bool_t OCThreadRunnable::hasNext_b() const
{
  /* DD-ID: {2F318B47-0DA6-481d-A329-93E919322DAE}*/


#ifdef OC_SIMINP_DEBUG //For Simulation 
  return (oc_sim_frame_id < SIMULATED_IMG_NUM);
#else  

  bool_t v_Ret_t = false;
  if (e_OcReadyToExecute == state_e)
  {
    v_Ret_t = true;
  }

  return v_Ret_t;
#endif
}

void OCThreadRunnable::start_v()
{
  /* DD-ID: {2A388CD9-92BE-43cf-8485-5BD410BB0C88}*/

  // Don't bother checking AlgoType - we are always running OC
  // Check if algorithm has started - if so, we will skip this function
  // There are no "commands" coming in, so we will only start algorithm once and let it run
  #if ENABLE_TSC_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif

  setmcuCamIdToOcAlgo_e(m_request_camera);

  tscApi::enuCameraID v_OcAlgoCamId_e = getOcAlgoCamId_e(mcuCamIdToOcAlgo_e);
  isNewCommand_b = true;

#ifdef OC_SIMINP_DEBUG //For Simulation 
  const uint8_t *c_AlgoViewBuf_pu8 = get640x400AlgoView_pu8(static_cast<container::CameraId_e>(v_OcAlgoCamId_e));
#endif

  algoCommand_e = m_request_cmd; //From data provider

#ifdef OC_SIMINP_DEBUG //For Simulation 
  uint32_t v_FrameId_u32 = oc_sim_frame_id;
#else
  uint32_t v_FrameId_u32 = dataProvider_ro.getFrameNum_u32();
#endif

  initialisation_data.lastRequestedAt_u32 = v_FrameId_u32;

  static ME_Hydra3defs_E_AlgoCommand_t prev_algocommand = AlgoCommand_Unknown;
  static tscApi::enuCameraID prevCamId = tscApi::e_TscNumCam; //5;
  if ((prev_algocommand != algoCommand_e) || (v_OcAlgoCamId_e != prevCamId))
  {
    OC_DEBUG_PRINTF(("\n*JobOC::v_OcAlgoCamId_e  %d, algoCommand_e:%d, m_request_camera %d mcuCamIdToOcAlgo_e %d\n",
    		                    v_OcAlgoCamId_e,algoCommand_e, (int)m_request_camera, (int)mcuCamIdToOcAlgo_e));
    prevCamId = v_OcAlgoCamId_e;
  }
  if (prev_algocommand != algoCommand_e)
  {
    prev_algocommand = algoCommand_e;
    switch (algoCommand_e)
    {
    case AlgoCommand_Start:

      {
      // If algorithm is already running, it has to be stopped. So that new OC run can be started.
      if (true == isAlgorithmStarted_b)
      {
        bool_t v_IsStopSuccess_b = false;
        v_IsStopSuccess_b = TSC_Stop();

        if (false == v_IsStopSuccess_b)
        {
          initialisation_data.ocAlgoState_e = variants::e_OcStateError;
          initialisation_data.ocErrorCode_e = variants::e_OcErrCodeUnexpectedRequest;
        }
        else
        {
          initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        OC_DEBUG_PRINTF(("*start_v* OC running already, new start command comes. Current run stopped. \n"));
      }
      else
      {
        initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
      }

      initialisation_data.mcuCameraId_u8 = mcuCamIdToOcAlgo_e;
      // Initialize tscStartConfiguration_as
      setOcKinematicModelConfiguration_v();
      setOcCamModelConfiguration_v();
      setOcFeatureCollectionConfiguration_v();
#ifdef OC_LOG_PRINTF_ON
      bool_t v_IsAlgoStartSuccess_b = false;
#endif

      if (variants::e_OcStateUninit != initialisation_data.ocAlgoState_e)
      {
#ifndef OC_LOG_PRINTF_ON
        bool_t v_IsAlgoStartSuccess_b = false;
#endif
        v_IsAlgoStartSuccess_b = TSC_Start(v_OcAlgoCamId_e, &tscStartConfiguration_as[v_OcAlgoCamId_e], NULL);

        if (false == v_IsAlgoStartSuccess_b)
        {
          initialisation_data.ocAlgoState_e = variants::e_OcStateError;
          initialisation_data.ocErrorCode_e = variants::e_OcErrCodeStartFail;
        }
        else
        {
          initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

#ifdef OC_SIMINP_DEBUG //For Simulation 
        v_FrameId_u32 = oc_sim_frame_id;
#else
        v_FrameId_u32 = dataProvider_ro.getFrameNum_u32();
#endif

        initialisation_data.updatedAt_u32 = v_FrameId_u32;
      }

      OC_DEBUG_PRINTF(("*start_v* v_IsAlgoStartSuccess_b %d, state %d, error %d\n", v_IsAlgoStartSuccess_b, initialisation_data.ocAlgoState_e, initialisation_data.ocErrorCode_e));
      ocFrameCounter_u32 = 0U;
      isAlgorithmStarted_b = true;
 
      break;
    }

    case AlgoCommand_Stop:
      {
      bool_t v_IsStopSuccess_b = false;

      v_IsStopSuccess_b = TSC_Stop();

      if (false == v_IsStopSuccess_b)
      {
        initialisation_data.ocAlgoState_e = variants::e_OcStateError;
        initialisation_data.ocErrorCode_e = variants::e_OcErrCodeCalibrationError;
      }
      else
      {
        initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
      }

      initialisation_data.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
      OC_DEBUG_PRINTF(("*StopCommand* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n",
              v_OcAlgoCamId_e
              ,tscAlgoState_ae[v_OcAlgoCamId_e]
              ,initialisation_data.ocAlgoState_e
              ,initialisation_data.ocErrorCode_e
              ,initialisation_data.validFeaturesCount_u32
              ,initialisation_data.ignoredFeaturesCount_u32
              ,initialisation_data.invalidFeaturesCount_u32
              ,TSC_GetSkippedFramesCount(v_OcAlgoCamId_e)
              ,initialisation_data.ProcessedFrameCount
              ,TSC_GetState(v_OcAlgoCamId_e)
              ,TSC_GetError(v_OcAlgoCamId_e)));
      isAlgorithmStarted_b = false;
      break;
    }



    case AlgoCommand_Pause:
      {
   
      bool_t v_IsPauseSuccess_b = false;
      v_IsPauseSuccess_b = TSC_Pause();

      if (false == v_IsPauseSuccess_b)
      {
        initialisation_data.ocAlgoState_e = variants::e_OcStateError;
        initialisation_data.ocErrorCode_e = variants::e_OcErrCodeCalibrationError;
      }
      else
      {
        initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
      }

      initialisation_data.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
      isAlgorithmStarted_b = false;
      break;
    }



    case AlgoCommand_Status:
      {
      break;
    }
#ifdef _WINDOWS
      case container::e_Sync:
      {
        // OC_DEBUG_PRINTF(("JobOC::execute_v = %d, sync\n", static_cast<printInt_t>(v_Time_o.getTimeNs_u64() / 1000000)));
        break;
      }

      case variants::e_GetResult:
      {
        break;
      }
#endif
    case AlgoCommand_Resume:
      {
      // OC_DEBUG_PRINTF(("JobOC::execute_v = %d, resumed\n", static_cast<printInt_t>(v_Time_o.getTimeNs_u64() / 1000000)));
      bool_t v_IsResumeSuccess_b = false;
      v_IsResumeSuccess_b = TSC_Resume();

      if (false == v_IsResumeSuccess_b)
      {
        initialisation_data.ocAlgoState_e = variants::e_OcStateError;
        initialisation_data.ocErrorCode_e = variants::e_OcErrCodeUnexpectedRequest;
      }
      else
      {
        initialisation_data.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        initialisation_data.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
      }

      initialisation_data.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
      initialisation_data.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
      isAlgorithmStarted_b = true;
      break;
    }

    case AlgoCommand_Debug:
      {
      // OC_DEBUG_PRINTF(("start_v = %lu, debug, val: %d\n", v_Time_o.getTimeMs_u32(), dataProvider_ro.getDataMcu()->algoControl_s.algMData_s.algoDebugView_e));
      break;
    }

    default:
      {
      break;
    }
    }
  }

  state_e = e_OcReadyToExecute;

  #if ENABLE_TSC_PROFILE
    static uint64_t v_PrevTimeStart_u64 = 0;
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("[TSC Profile] start: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeStart_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
    v_PrevTimeStart_u64 = v_Time_o.getTimeMsec_u64();
  #endif
}

void OCThreadRunnable::execute_v()
{
  /* DD-ID: {C7DA283B-DCEB-444d-A8B6-340A3FCEF937}*/
  //OC_DEBUG_PRINTF(("\n*JobOC::execute_v* \n"));
  #if ENABLE_TSC_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif

  container::OcData_s &v_OcData_rs = initialisation_data;    // TODO check if this is thread safe
  tscApi::enuCameraID v_OcAlgoCamId_e = getOcAlgoCamId_e(mcuCamIdToOcAlgo_e);
  tscAlgoState_ae[v_OcAlgoCamId_e] = TSC_GetState(v_OcAlgoCamId_e);
  tscErrorCode_ae[v_OcAlgoCamId_e] = TSC_GetError(v_OcAlgoCamId_e);

  if (true == isAlgorithmStarted_b)
  {
    ocFrameCounter_u32++;

    if (tscApi::e_TscErrorNoError == tscErrorCode_ae[v_OcAlgoCamId_e])
    {
      switch (tscAlgoState_ae[v_OcAlgoCamId_e])
      {
      case tscApi::e_TscStateUnInit:
        {
        OC_DEBUG_PRINTF(("*Statemachine_uninit* Shouldn't come here\n"));
        bool_t v_IsAlgoInitSuccess_b = false;
        tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscFrontCam, get640x400AlgoView_pu8(container::e_Front));
        tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscLeftCam, get640x400AlgoView_pu8(container::e_Left));
        tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscRearCam, get640x400AlgoView_pu8(container::e_Rear));
        tscCtrlInfo_o.PutM_Cmrs(tscApi::e_TscRightCam, get640x400AlgoView_pu8(container::e_Right));
        v_IsAlgoInitSuccess_b = TSC_Init(&tscCtrlInfo_o);

        if (false == v_IsAlgoInitSuccess_b)
        {
          v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
          v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeInitFail;
          isAlgorithmStarted_b = false;
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        OC_DEBUG_PRINTF(("*Statemachine_uninit* v_IsAlgoInitSuccess_b %d, state %d, error %d\n", v_IsAlgoInitSuccess_b, v_OcData_rs.ocAlgoState_e, v_OcData_rs.ocErrorCode_e));

        break;
      }

      case tscApi::e_TscStateInitOk:
        {
        // memset( &v_OcData_rs.ocDataToMcu_s, 0, sizeof( container::OcDataToMcu_s ) );

        // If algorithm is already running, it has to be stopped. So that new OC run can be started.
        if (true == isAlgorithmStarted_b)
        {
          bool_t v_IsStopSuccess_b = false;
          v_IsStopSuccess_b = TSC_Stop();

          if (false == v_IsStopSuccess_b)
          {
            v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
            v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeUnexpectedRequest;
          }
          else
          {
            v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
            v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
          }

          OC_DEBUG_PRINTF(("*Statemachine_initok* OC running already, new start command comes. Current run stopped. \n"));
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        bool_t v_IsAlgoStartSuccess_b = false;
        // Initialize tscStartConfiguration_as
        setOcKinematicModelConfiguration_v();
        setOcCamModelConfiguration_v();
        setOcFeatureCollectionConfiguration_v();
        // TODO Intermediate/saved data
        v_IsAlgoStartSuccess_b = TSC_Start(v_OcAlgoCamId_e, &tscStartConfiguration_as[v_OcAlgoCamId_e], NULL);

        if (false == v_IsAlgoStartSuccess_b)
        {
          v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
          v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeStartFail;
          isAlgorithmStarted_b = false;
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        OC_DEBUG_PRINTF(("*Statemachine_initok* v_IsAlgoStartSuccess_b %d, state %d, error %d\n", v_IsAlgoStartSuccess_b, v_OcData_rs.ocAlgoState_e, v_OcData_rs.ocErrorCode_e));
        OC_DEBUG_PRINTF(("*Statemachine_initok* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n", v_OcAlgoCamId_e, tscAlgoState_ae[v_OcAlgoCamId_e],
                v_OcData_rs.ocAlgoState_e,
                v_OcData_rs.ocErrorCode_e,
                v_OcData_rs.validFeaturesCount_u32,
                v_OcData_rs.ignoredFeaturesCount_u32,
                v_OcData_rs.invalidFeaturesCount_u32,
                TSC_GetSkippedFramesCount(v_OcAlgoCamId_e),
                initialisation_data.ProcessedFrameCount,
                TSC_GetState(v_OcAlgoCamId_e),
                TSC_GetError(v_OcAlgoCamId_e)));

        break;
      }

      case tscApi::e_TscStateError:
        {
        bool_t v_IsStopSuccess_b = false;
        v_IsStopSuccess_b = TSC_Stop();

        if (false == v_IsStopSuccess_b)
        {
          v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
          v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        OC_DEBUG_PRINTF(("*Statemachine_error* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n", v_OcAlgoCamId_e, tscAlgoState_ae[v_OcAlgoCamId_e],
                v_OcData_rs.ocAlgoState_e, v_OcData_rs.ocErrorCode_e, v_OcData_rs.validFeaturesCount_u32, v_OcData_rs.ignoredFeaturesCount_u32, v_OcData_rs.invalidFeaturesCount_u32, TSC_GetSkippedFramesCount(v_OcAlgoCamId_e), TSC_GetProcessedFramesCount(v_OcAlgoCamId_e),
                TSC_GetState(v_OcAlgoCamId_e), TSC_GetError(v_OcAlgoCamId_e)));
        isAlgorithmStarted_b = false;

        break;
      }

      case tscApi::e_TscStateFeatureCollection:
        {
        {
          bool_t v_IsAlgoFcSuccess_b = false;
#ifdef OC_SIMINP_DEBUG //For Simulation        
		  int v_sim_id = oc_sim_frame_id;

		  /* oc_simulation.h must be populated with the CAN data received from Appcntrl
		   * and feed it to ECU for simulation
		   */
          tscCtrlInfo_o.PutM_Spd(oc_sim_vinfo[v_sim_id].speed);	// image names starting at oc_sim_frame_id=1          
          tscCtrlInfo_o.PutM_WhlAngl(oc_sim_vinfo[v_sim_id-1].wheelAngle);
		  
#ifdef WRITE_CAN_OC         
          FILE *CAN_FILE;
          CAN_FILE = fopen("CAN_FILE.txt", "a");
          fprintf(CAN_FILE, " {%d, %d, %f , %f } \n",oc_sim_frame_id, v_sim_id,  oc_sim_vinfo[v_sim_id-1].speed,oc_sim_vinfo[v_sim_id-1].wheelAngle);
          fclose(CAN_FILE);
#endif

          // PRQA S 1051 1 // This commented code is uncommented and used when debugging.
          // tscCtrlInfo_o.PutM_FrmNmbr(1 + tscCtrlInfo_o.GetM_FrmNmbr());
          tscCtrlInfo_o.PutM_FrmNmbr(oc_sim_frame_id);
          const uint8_t *c_AlgoViewBuf_pu8 = get640x400AlgoView_pu8(static_cast<container::CameraId_e>(v_OcData_rs.mcuCameraId_u8));
          //                       vid_save_bmp("/tmp/Image.bmp",(char*)c_AlgoViewBuf_pu8, IMAGE_HEIGHT,IMAGE_WIDTH);
          tscCtrlInfo_o.PutM_Cmrs(v_OcAlgoCamId_e, c_AlgoViewBuf_pu8);
#else

          tscCtrlInfo_o.PutM_Spd(dataProvider_ro.getSpeed_f32());
          tscCtrlInfo_o.PutM_WhlAngl(dataProvider_ro.getWheelAngle_f32());
          const uint8_t *c_AlgoViewBuf_pu8 = get640x400AlgoView_pu8(static_cast<container::CameraId_e>(v_OcData_rs.mcuCameraId_u8));
          tscCtrlInfo_o.PutM_Cmrs(v_OcAlgoCamId_e, c_AlgoViewBuf_pu8);
          // PRQA S 1051 1 // This commented code is uncommented and used when debugging.
          tscCtrlInfo_o.PutM_FrmNmbr(dataProvider_ro.getFrameNum_u32());

#endif
#if 0
             //if (variants:: e_OcStatePaused != v_OcData_rs.ocAlgoState_e)
             if (dataProvider_ro.getFrameNum_u32()%100 == 0)
             {
               OC_DEBUG_PRINTF(("*Statemachine_featurecollection:: Speed :%f, Angle: %f, frameId: %lu\n"
                     ,(tscCtrlInfo_o.getMSpd_f32())
                     ,(tscCtrlInfo_o.getMWhlAngl_f32())
                    ,dataProvider_ro.getFrameNum_u32()
                     ));
             }
#endif
           #ifdef WRITE_CAN_OC
             FILE *CAN_FILE;
            CAN_FILE = fopen("/ti_sd/CAN_FILE.txt", "a");
            fprintf(CAN_FILE, " {CamID: %d, speed: %d, StWhl: %f, FrameId: %d,} \n",
            		           v_OcAlgoCamId_e, dataProvider_ro.getSpeed_f32(), dataProvider_ro.getWheelAngle_f32(), dataProvider_ro.getFrameNum_u32() );
            fclose(CAN_FILE);
          #endif 

          #if dump_image_oc

          if (6 > ocFrameCounter_u32)
          {
        	 static char FileName[64] = {0};
        	 static uint32_t v_FrameCounter_u32 = 0;
        	 sprintf(FileName, "/ti_sd/FrontImage_%d.bmp", v_FrameCounter_u32++);

        	 if (0x01 == v_OcData_rs.mcuCameraId_u8)
        	 {
        	   char* frontImg = ( char* )get640x400AlgoView_pu8( container::e_Front );
        	   vid_save_bmp( "FileName", frontImg, IMAGE_HEIGHT,IMAGE_WIDTH );
        	 }
        	 else if (0x02 == v_OcData_rs.mcuCameraId_u8)
        	 {
        	   char* leftImg = ( char* )get640x400AlgoView_pu8( container::e_Left );
        	   vid_save_bmp( "FileName", leftImg, IMAGE_HEIGHT,IMAGE_WIDTH );
        	 }
        	 else if(0x03 == v_OcData_rs.mcuCameraId_u8)
        	 {
        	   char* rearImg = ( char* )get640x400AlgoView_pu8( container::e_Rear );
        	   vid_save_bmp( "FileName", rearImg, IMAGE_HEIGHT,IMAGE_WIDTH );
        	 }
        	 else if(0x03 == v_OcData_rs.mcuCameraId_u8)
        	 {
        		 char* rightImg = ( char* )get640x400AlgoView_pu8( container::e_Right );
        		 vid_save_bmp( "FileName", rightImg, IMAGE_HEIGHT,IMAGE_WIDTH );
        	 }
          }
          #endif
          {
            v_IsAlgoFcSuccess_b = TSC_ProcessFrame();
#ifdef DEBUG_TSC_ALG
            const tscApi::DebugCounters *v_DebugCounter_ps = TSC_GetDebugCounters(v_OcAlgoCamId_e);

            if (NULL != v_DebugCounter_ps)
            {
              vm_cprintf("ignIGComb:%lu,ignIGDev:%lu,ignIGThr:%lu,ignMisPr:%lu,invPxMtn:%lu,invTrcL:%lu,invVSl:%lu,spd:%d,angl:%d\n", v_DebugCounter_ps->ignoredIGCombinThreshold, v_DebugCounter_ps->ignoredIGDeviation, v_DebugCounter_ps->ignoredIGThreshold,
                  v_DebugCounter_ps->ignoredMissingPair, v_DebugCounter_ps->invalidPxMotion, v_DebugCounter_ps->invalidTrckLen, v_DebugCounter_ps->invalidValidSlope, static_cast<sint32_t>(tscCtrlInfo_o.getMSpd_f32() * 10000),
                  static_cast<sint32_t>(mecl::math::toDegrees_x(tscCtrlInfo_o.getMWhlAngl_f32()) * 10000));
            }

#endif
          }

          if (false == v_IsAlgoFcSuccess_b)
          {
            v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
            v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
            bool_t v_IsStopSuccess_b = false;
            v_IsStopSuccess_b = TSC_Stop();

            if (false == v_IsStopSuccess_b)
            {
              v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
              v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
            }
            else
            {
              v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
              v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
            }

            isAlgorithmStarted_b = false;
          }
          else
          {
            v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
            v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
          }
        }
        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);

        break;
      }

      case tscApi::e_TscStateFeatureCollectionCompleted:
        {
        bool_t v_IsAlgoCalibSuccess_b = false;
        v_IsAlgoCalibSuccess_b = TSC_Calibrate(v_OcAlgoCamId_e);

        if (false == v_IsAlgoCalibSuccess_b)
        {
          v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
          v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeCalibrationError;
          bool_t v_IsStopSuccess_b = false;
          v_IsStopSuccess_b = TSC_Stop();

          if (false == v_IsStopSuccess_b)
          {
            v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
            v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
          }
          else
          {
            v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
            v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
          }

          isAlgorithmStarted_b = false;
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);

        break;
      }

      case tscApi::e_TscStateCalibration:
        {
        v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);

        break;
      }

      case tscApi::e_TscStateCalibrationCompleted:
        {
        bool_t v_IsAlgoFinalResultSuccess_b = false;
        v_IsAlgoFinalResultSuccess_b = TSC_GetFinalCalibrationResult(v_OcAlgoCamId_e, &tscCalibrationResults_as[v_OcAlgoCamId_e]);

        if (false == v_IsAlgoFinalResultSuccess_b)
        {
          v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
          v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeCalibrationError;
          bool_t v_IsStopSuccess_b = false;
          v_IsStopSuccess_b = TSC_Stop();

          if (false == v_IsStopSuccess_b)
          {
            v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
            v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
          }
          else
          {
            v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
            v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
          }
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        if ((mecl::math::abs_x<float64_t>(tscCalibrationResults_as[v_OcAlgoCamId_e].pitchDeg_f64) < mecl::math::numeric_limits<float32_t>::epsilon_x())
            || ( NULL == c_OcExtrinsics_ps))
        {
          v_OcData_rs.deltaPitch_f32 = 0.0F;
        }
        else
        {
          v_OcData_rs.deltaPitch_f32 = static_cast<float32_t>(tscCalibrationResults_as[v_OcAlgoCamId_e].pitchDeg_f64)
              - mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.pitch_x);
        }

        if ((mecl::math::abs_x<float64_t>(tscCalibrationResults_as[v_OcAlgoCamId_e].yawDeg_f64) < mecl::math::numeric_limits<float32_t>::epsilon_x())
            || ( NULL == c_OcExtrinsics_ps))
        {
          v_OcData_rs.deltaYaw_f32 = 0.0F;
        }
        else
        {
          v_OcData_rs.deltaYaw_f32 = static_cast<float32_t>(tscCalibrationResults_as[v_OcAlgoCamId_e].yawDeg_f64)
              - mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.yaw_x);
        }

        if ((mecl::math::abs_x<float64_t>(tscCalibrationResults_as[v_OcAlgoCamId_e].rollDeg_f64) < mecl::math::numeric_limits<float32_t>::epsilon_x())
            || ( NULL == c_OcExtrinsics_ps))
        {
          v_OcData_rs.deltaRoll_f32 = 0.0F;
        }
        else
        {
          v_OcData_rs.deltaRoll_f32 = static_cast<float32_t>(tscCalibrationResults_as[v_OcAlgoCamId_e].rollDeg_f64)
              - mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.roll_x);

          if (v_OcData_rs.deltaRoll_f32 > 180.0F)
          {
            v_OcData_rs.deltaRoll_f32 -= 360.0F;
          }
          else if (v_OcData_rs.deltaRoll_f32 < -180.0F)
          {
            v_OcData_rs.deltaRoll_f32 += 360.0F;
          }
          else
          {
            // Do nothing
          }
        }

        OC_DEBUG_PRINTF(("OcDelta_p %.6f, ",v_OcData_rs.deltaPitch_f32));
        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        OC_DEBUG_PRINTF( ( "*Statemachine_calibrationcompleted* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n"
                , v_OcAlgoCamId_e
                , tscAlgoState_ae[v_OcAlgoCamId_e]
                , v_OcData_rs.ocAlgoState_e
                , v_OcData_rs.ocErrorCode_e
                , v_OcData_rs.validFeaturesCount_u32
                , v_OcData_rs.ignoredFeaturesCount_u32
                , v_OcData_rs.invalidFeaturesCount_u32
                , TSC_GetSkippedFramesCount( v_OcAlgoCamId_e )
                , initialisation_data.ProcessedFrameCount
                , TSC_GetState( v_OcAlgoCamId_e )
                , TSC_GetError( v_OcAlgoCamId_e )
            ) );
        OC_DEBUG_PRINTF( ( "*Statemachine_calibrationcompleted* Pitch: %f, Yaw: %f, Roll: %f, X: %f, Y: %f, Z: %f\n"
                , ( tscCalibrationResults_as[v_OcAlgoCamId_e].pitchDeg_f64 )
                , ( tscCalibrationResults_as[v_OcAlgoCamId_e].yawDeg_f64 )
                , ( tscCalibrationResults_as[v_OcAlgoCamId_e].rollDeg_f64 )
                , ( tscCalibrationResults_as[v_OcAlgoCamId_e].xMM_f64 )
                , ( tscCalibrationResults_as[v_OcAlgoCamId_e].yMM_f64 )
                , ( tscCalibrationResults_as[v_OcAlgoCamId_e].zMM_f64 )
            ) );
        OC_DEBUG_PRINTF( ( "*Statemachine_calibrationcompleted* deltaPitch: %f, deltaYaw: %f, deltaRoll: %f\n"
                , ( v_OcData_rs.deltaPitch_f32 )
                , ( v_OcData_rs.deltaYaw_f32 )
                , ( v_OcData_rs.deltaRoll_f32 )
            ) );
        isAlgorithmStarted_b = false;
        isAlgorithmFinished_b = true;
        // --------------------------------------------------------------------------------------
        // Dumping to CSV file
		#ifdef OC_SIMINP_DEBUG
        DumpCalibrationResults(v_OcAlgoCamId_e, v_OcData_rs);
		#endif
        // ------------------------------------------------------------------------------------------
      
      break;
      }
    

      case tscApi::e_TscStateTerminated:
        {
        v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        isAlgorithmStarted_b = false;

        break;
      }

      case tscApi::e_TscStatePaused:
        {
        v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        isAlgorithmStarted_b = false;

        break;
      }

      default:
        {
        v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        break;
      }
      }

      static variants::OCAlgoStateE_t v_PrevState_e;
      static variants::OCErrorCodeE_t v_PrevError_e;

      if ((v_PrevState_e != v_OcData_rs.ocAlgoState_e) || (v_PrevError_e != v_OcData_rs.ocErrorCode_e))
      {
        v_PrevState_e = v_OcData_rs.ocAlgoState_e;
        v_PrevError_e = v_OcData_rs.ocErrorCode_e;
        OC_DEBUG_PRINTF( ( "*execute_v:IsAlgoStarted* algoCam: %d, Machinestate: %d, state: %d, error: %d, valid: %lu, ignored: %lu, invalid: %lu, undetected: %d, skiped: %d, procsd: %d, state: %d, error: %d\n"
                , v_OcAlgoCamId_e
                , tscAlgoState_ae[v_OcAlgoCamId_e]
                , v_OcData_rs.ocAlgoState_e
                , v_OcData_rs.ocErrorCode_e
                , v_OcData_rs.validFeaturesCount_u32
                , v_OcData_rs.ignoredFeaturesCount_u32
                , v_OcData_rs.invalidFeaturesCount_u32
                , TSC_GetUndetectedFeaturesCount( v_OcAlgoCamId_e )
                , TSC_GetSkippedFramesCount( v_OcAlgoCamId_e )
                , initialisation_data.ProcessedFrameCount
                , TSC_GetState( v_OcAlgoCamId_e )
                , TSC_GetError( v_OcAlgoCamId_e )
            ) );
      }

      // Abort strategy
      sint32_t v_ProcessedFramesCount_s32 = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);

      if (v_ProcessedFramesCount_s32 >= 0)
      {
        const uint32_t c_ProcessedFramesCount_u32 = static_cast<uint32_t>(v_ProcessedFramesCount_s32);

        // If processed frames are already more than minimum abort frame count limit
        if ((c_MinAbortFrameCntLimit_u32 < c_ProcessedFramesCount_u32)
            && (variants::e_OcStateFeatureCollectionCompleted != v_OcData_rs.ocAlgoState_e)
            && (variants::e_OcStateCalibration != v_OcData_rs.ocAlgoState_e)
            && (variants::e_OcStateCalibrationCompleted != v_OcData_rs.ocAlgoState_e)
            )
        {
          abortFrameCounter_u32++;

          if (c_FrameWindow_u32 == abortFrameCounter_u32)
          {
            abortFrameCounter_u32 = 0U;

            if (c_MinValidFeaturesInWindow_u32 > (v_OcData_rs.validFeaturesCount_u32 - prevValidFeatureCount_u32))
            {
              bool_t v_IsStopSuccess_b = false;
              v_IsStopSuccess_b = TSC_Stop();

              if (false == v_IsStopSuccess_b)
              {
                v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
                v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
              }
              else
              {
                v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
                v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
              }

              v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
              v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
              v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
              v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
#ifdef OC_SIMINP_DEBUG //For Simulation 
              OC_DEBUG_PRINTF(("*execute_v:abortHandling* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n"
                  , v_OcAlgoCamId_e
                  , tscAlgoState_ae[v_OcAlgoCamId_e]
                  , v_OcData_rs.ocAlgoState_e
                  , v_OcData_rs.ocErrorCode_e
                  , v_OcData_rs.validFeaturesCount_u32
                  , v_OcData_rs.ignoredFeaturesCount_u32
                  , v_OcData_rs.invalidFeaturesCount_u32
                  , TSC_GetSkippedFramesCount(v_OcAlgoCamId_e)
                      , initialisation_data.ProcessedFrameCount
                  , TSC_GetState(v_OcAlgoCamId_e)
                      , TSC_GetError(v_OcAlgoCamId_e)
                      ));
#endif
              isAlgorithmStarted_b = false;
            }
            else
            {
              prevValidFeatureCount_u32 = v_OcData_rs.validFeaturesCount_u32;
            }
          }
        }
        else
        {
          prevValidFeatureCount_u32 = v_OcData_rs.validFeaturesCount_u32;
          abortFrameCounter_u32 = 0;
        }
      }
      else
      {
        bool_t v_IsStopSuccess_b = false;
        v_IsStopSuccess_b = TSC_Stop();

        if (false == v_IsStopSuccess_b)
        {
          v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
          v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
        }
        else
        {
          v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
          v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
        }

        v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
        v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
        OC_DEBUG_PRINTF( ( "*execute_v:AbortProcessFramesCountElseCase* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n"
                , v_OcAlgoCamId_e
                , tscAlgoState_ae[v_OcAlgoCamId_e]
                , v_OcData_rs.ocAlgoState_e
                , v_OcData_rs.ocErrorCode_e
                , v_OcData_rs.validFeaturesCount_u32
                , v_OcData_rs.ignoredFeaturesCount_u32
                , v_OcData_rs.invalidFeaturesCount_u32
                , TSC_GetSkippedFramesCount( v_OcAlgoCamId_e )
                , initialisation_data.ProcessedFrameCount
                , TSC_GetState( v_OcAlgoCamId_e )
                , TSC_GetError( v_OcAlgoCamId_e )
            ) );
        isAlgorithmStarted_b = false;
      }
    }
    else
    {
      bool_t v_IsStopSuccess_b = false;
      v_IsStopSuccess_b = TSC_Stop();

      if (false == v_IsStopSuccess_b)
      {
        v_OcData_rs.ocAlgoState_e = variants::e_OcStateError;
        v_OcData_rs.ocErrorCode_e = variants::e_OcErrCodeFeatureCollectionError;
      }
      else
      {
        v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(TSC_GetState(v_OcAlgoCamId_e));
        v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
      }

      v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
      v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
      v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
      v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
      OC_DEBUG_PRINTF( ( "*execute_v:NoErrorElseCase* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n"
              , v_OcAlgoCamId_e
              , tscAlgoState_ae[v_OcAlgoCamId_e]
              , v_OcData_rs.ocAlgoState_e
              , v_OcData_rs.ocErrorCode_e
              , v_OcData_rs.validFeaturesCount_u32
              , v_OcData_rs.ignoredFeaturesCount_u32
              , v_OcData_rs.invalidFeaturesCount_u32
              , TSC_GetSkippedFramesCount( v_OcAlgoCamId_e )
              , initialisation_data.ProcessedFrameCount
              , TSC_GetState( v_OcAlgoCamId_e )
              , TSC_GetError( v_OcAlgoCamId_e )
          ) );
      isAlgorithmStarted_b = false;
    }

    // configureFpgaForAlgoView_v( isAlgorithmStarted_b );
  }
  else
  {
    // Do nothing
  }

  if (true == isNewCommand_b)
  {
    switch (algoCommand_e)
    {
    case AlgoCommand_Start:
      {
      break;
    }

    case AlgoCommand_Stop:
      {
      // configureFpgaForAlgoView_v( isAlgorithmStarted_b );
      break;
    }

    case AlgoCommand_Pause:
      {
      // configureFpgaForAlgoView_v( isAlgorithmStarted_b );
      break;
    }

    case AlgoCommand_Status:
      {
      if ((variants::e_OcStateError != v_OcData_rs.ocAlgoState_e)
          && (variants::e_OcErrCodeNoError == v_OcData_rs.ocErrorCode_e))
      {
        v_OcData_rs.ocAlgoState_e = static_cast<variants::OCAlgoStateE_t>(tscAlgoState_ae[v_OcAlgoCamId_e]);
        v_OcData_rs.ocErrorCode_e = static_cast<variants::OCErrorCodeE_t>(TSC_GetError(v_OcAlgoCamId_e));
      }

      v_OcData_rs.validFeaturesCount_u32 = TSC_GetValidFeaturesCount(v_OcAlgoCamId_e);
      v_OcData_rs.ignoredFeaturesCount_u32 = TSC_GetIgnoredValidFeaturesCount(v_OcAlgoCamId_e);
      v_OcData_rs.invalidFeaturesCount_u32 = TSC_GetInvalidFeaturesCount(v_OcAlgoCamId_e);
      v_OcData_rs.ProcessedFrameCount = TSC_GetProcessedFramesCount(v_OcAlgoCamId_e);
      #if 0
      if (variants:: e_OcStatePaused != v_OcData_rs.ocAlgoState_e)
      {
        OC_DEBUG_PRINTF( ( "*StatusCommand* algoCam: %d, Machinestate: %d, stateToMcu: %d, errorToMcu: %d, validToMcu: %lu, ignoredToMcu: %lu, invalidToMcu: %lu, skiped: %d, procsd: %d, state: %d, error: %d\n"
                , v_OcAlgoCamId_e
                , tscAlgoState_ae[v_OcAlgoCamId_e]
                , v_OcData_rs.ocAlgoState_e
                , v_OcData_rs.ocErrorCode_e
                , v_OcData_rs.validFeaturesCount_u32
                , v_OcData_rs.ignoredFeaturesCount_u32
                , v_OcData_rs.invalidFeaturesCount_u32
                , TSC_GetSkippedFramesCount( v_OcAlgoCamId_e )
                , initialisation_data.ProcessedFrameCount
                , TSC_GetState( v_OcAlgoCamId_e )
                , TSC_GetError( v_OcAlgoCamId_e )
            ) );
      }
      #endif
      break;
    }

    case AlgoCommand_Resume:
      {
      // configureFpgaForAlgoView_v( isAlgorithmStarted_b );
      break;
    }

    case AlgoCommand_Debug:
      {
      // dataInProvider_ro.getDataMcu()->algoControl_s.algMData_s.algoDebugView_e ) );
      break;
    }

    default:
      {
      break;
    }
    }

    isNewCommand_b = false;
  }

  v_OcData_rs.isOcActive_b = isAlgorithmStarted_b;
#ifdef OC_SIMINP_DEBUG //For Simulation 
  v_OcData_rs.updatedAt_u32 = oc_sim_frame_id;
#else
  v_OcData_rs.updatedAt_u32 = dataProvider_ro.getFrameNum_u32();
#endif

  //    OC_DEBUG_PRINTF(("execute_v finish = %d, lastreq_at = %u, reqat: %u\n", static_cast<printInt_t>(v_time_o.getTimeNs_u64() / 1000000),
  //    v_OcData_rs.lastRequestedAt_u32, dataInProvider_ro.getDataMcu()->algoControl_s.cntrl_s.requestedAt_u32));
  //OC_DEBUG_PRINTF(("\n ### Check state End: %d, %d , %d , %d \n" , v_OcAlgoCamId_e, tscAlgoState_ae[v_OcAlgoCamId_e], ocFrameCounter_u32 , isAlgorithmStarted_b));
  state_e = e_DoNothing;

#if ENABLE_TSC_PROFILE
  static uint64_t v_PrevTimeExecute_u64 = 0;
  uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
  ME_Debugger_F_Printf_v("[TSC Profile] execute: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeExecute_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
  v_PrevTimeExecute_u64 = v_Time_o.getTimeMsec_u64();
#endif

}

bool_t OCThreadRunnable::run_b()
{
  /* DD-ID: {F86EA1AA-353B-47e0-9971-F5BC3AEBFEAE}*/
#if PROFILE_OCThread
  PerformanceStatsThEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsThEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_OCThreadPreviousTime_u32;
  }
#endif
  uint64_t curr_timestamp = 0;
  uint64_t prev_timestamp = 0;
  
  osal::Time v_Time_o;
  uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();

  static uint32_t v_frameNum_u32 = 0;
  container::RequestOCCalibCmd_t v_OcRequest_t;
  static variants::CalibrationTypeE_t prev_caltype = variants::e_CalibrationTypeEInvalid; //9;

#if ENABLE_TSC_PROFILE
  uint64_t v_StartTimeRun_b_u64 = v_Time_o.getTimeMsec_u64();
#endif

  if (1)
  {

#ifdef OC_SIMINP_DEBUG //For Simulation 
    v_frameNum_u32 = oc_sim_frame_id;  
#else       
    v_frameNum_u32 = dataProvider_ro.getFrameNum_u32(); // Receive Frame number from DataProvider #endif
#endif

#ifdef OC_INDIV_PROFILE  //Profiling tools 
    osal::Clock start;
    start.start_v();
#endif

#ifdef OC_TIMESTAMPS  //Profiling tools 
    osal::Time v_Time_o;
    curr_timestamp = v_Time_o.getTimeMsec_u64();
#endif

    // Use request form Data provider  
    dataProvider_ro.getOCRequest_v(v_OcRequest_t);                            // Populate CAM ID and Algo command in Data provider  
    c_calibrationType_e = v_OcRequest_t.calibrationType_t; //dataProvider_ro.getCalibrationType_v();             // Receive calibration type from data provider 

    if(prev_caltype != c_calibrationType_e)
    {
      OC_DEBUG_PRINTF(("v_calibrationType_e %d\n", (int)c_calibrationType_e));
      prev_caltype = c_calibrationType_e;
    } 

    m_request_cmd = v_OcRequest_t.cmd_t;                                      // Request command from Data provider 

    /* o_OCRequest_rt.camera_u32 : Front = 0, Left = 1 , Rear = 2, Right =3 */
    m_request_camera = static_cast<variants::Camera_t>(v_OcRequest_t.camera_u32);  // Camera ID from Data provider

#if DUMP_ALL_CAM_IMAGES_CAN_DATA
    /* Getting the data at once for all cams but not dumping */
    dataProvider_ro.setFrontInputImage();
    dataProvider_ro.setLeftInputImage();
    dataProvider_ro.setRearInputImage();
    dataProvider_ro.setRightInputImage();

    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();

    /* Dumping the images to SD card */
    dataProvider_ro.dump_FrontAlgoViewImages();
    dataProvider_ro.dump_LeftAlgoViewImages();
    dataProvider_ro.dump_RearAlgoViewImages();
    dataProvider_ro.dump_RightAlgoViewImages();

    static uint64_t v_PrevTimeRun_b_u64 = 0;
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("[TSC Profile] DUMP_ALL_CAM_IMAGES_CAN_DATA: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeRun_b_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
    v_PrevTimeRun_b_u64 = v_Time_o.getTimeMsec_u64();
#endif

#ifdef HARDCODE_OC
	  static bool once_b = false;

    //if(dataProvider_ro.getFrameNum_u32() >= 100)
    {
      m_request_camera = variants::e_CameraLeft;
      c_calibrationType_e = variants::e_CalibTypeSC; //SC or OC ?

      if(once_b == false)
      {
        m_request_cmd = AlgoCommand_Start;
        once_b = true;
      }
    }
#endif

  if ((m_request_camera < variants::e_CameraCount) && c_calibrationType_e == variants::e_CalibTypeSC)
  {

    switch (m_request_camera)  // Receive image from buffer 
    {
      case variants::e_CameraFront:
      {
        dataProvider_ro.setFrontInputImage();
        break;
      }
   
      case variants::e_CameraLeft:
      {
        dataProvider_ro.setLeftInputImage();
        break;
      }

      case variants::e_CameraRear:
      {
        dataProvider_ro.setRearInputImage();
        break;
      }

      case variants::e_CameraRight:
      {
        dataProvider_ro.setRightInputImage();
        break;
      }

      default:
      {
        break;
      }
    }

#ifdef OC_INDIV_PROFILE //For profiling 
    OC_DEBUG_PRINTF( ("OC before start = %f\n", start.getDeltaTime_f64()) );
    start.start_v();
#endif

      dataProvider_ro.setFrameNum_u32();

      start_v();

#ifdef OC_INDIV_PROFILE
      OC_DEBUG_PRINTF( ("after start = %f -- ", start.getDeltaTime_f64()) );
      start.start_v();
#endif

      execute_v();

#ifdef OC_INDIV_PROFILE
      OC_DEBUG_PRINTF( ("after execute = %f -- ", start.getDeltaTime_f64()) );
      start.start_v();
#endif

      end_v();

#ifdef OC_INDIV_PROFILE
      OC_DEBUG_PRINTF(("after end = %f -- ", start.getDeltaTime_f64()));
      start.start_v();
#endif  

#ifdef OC_TIMESTAMPS
      OC_DEBUG_PRINTF(("OC Time Elapsed = %llums\n", (curr_timestamp - prev_timestamp)));
      prev_timestamp = curr_timestamp;
      uint64_t t2 = v_Time_o.getTimeMsec_u64();
      OC_DEBUG_PRINTF(("OC Total Time = %llums\n\n", (t2 - curr_timestamp)));
#endif
    }

#ifndef _WINDOWS
    dataProvider_ro.setOCResponse_v(m_request_cmd, &tscCalibrationResults_as[0], &initialisation_data);  // Writes to shared memory
#endif

    m_prevRequest_cmd = m_request_cmd;

#ifdef OC_SIMINP_DEBUG //For Simulation 

    oc_sim_frame_id++;

    if (oc_sim_frame_id >= SIMULATED_IMG_NUM) // This is the max numer of frames we can simulate
    {
      oc_sim_frame_id = 1;	// images starting at 1
    }

#endif 

#ifdef OC_INDIV_PROFILE
    OC_DEBUG_PRINTF( ("ending = %f\n", start.getDeltaTime_f64()) );
#endif
}

#if PROFILE_OCThread
  if (TRUE ==  PerformanceStatsThEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    //ME_Debugger_F_Printf_v("OCThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_OCThreadRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgOCThreadPeriodicity_u32 = ((v_AvgOCThreadPeriodicity_u32 * (v_OCThreadRunCntr_u32 -1)) + currPeriodicity)/v_OCThreadRunCntr_u32; //Average Periodicity
		v_AvgOCThreadRuntime_u32 = ((v_AvgOCThreadRuntime_u32 * (v_OCThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_OCThreadRunCntr_u32; //New Average  
    v_OCThreadRuntimeData = (((v_AvgOCThreadRuntime_u32/1000U)<<16U) | ((v_AvgOCThreadPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setOCThreadRuntime(v_OCThreadRuntimeData);
    //ME_Debugger_F_Printf_v("OCTh: E: %lld P: %lld \n", v_AvgOCThreadRuntime_u32, v_AvgOCThreadPeriodicity_u32);
    v_OCThreadPreviousTime_u32 = v_Start_t;
  }
#endif

  #if ENABLE_TSC_PROFILE
    static uint64_t v_PrevTimeRun_b_u64 = 0;
    uint64_t v_EndTimeRun_b_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTimeRun_b_u64 = v_EndTimeRun_b_u64 - v_StartTimeRun_b_u64;
    ME_Debugger_F_Printf_v("[TSC run_b]: Time: %f \n", (float32_t)(v_TotalTimeRun_b_u64 * 1.0f));
    v_PrevTimeRun_b_u64 = v_Time_o.getTimeMsec_u64();
  #endif

#if OC_ALGO_VIEW_ENABLE
  uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
  uint32_t v_TotalTime_u32 = (uint32_t)(v_EndTime_u64 - v_StartTime_u64);
  if(v_TotalTime_u32 < _30_FPS_)
  {
    uint32_t v_AdjustmentTime_u32 = (_30_FPS_ - v_TotalTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
    ME_Thread_Sleep_t(v_AdjustmentTime_u32);
  }
#endif
  
  return true;
}

void OCThreadRunnable::end_v()
{
  /* DD-ID: {36E514DE-B20F-4f54-934D-2FE44313C8B4}*/

#ifdef OC_SIMINP_DEBUG //For Simulation 

  osal::File v_File_o;
  char frameNum[12];
  std::sprintf(frameNum, "/tmp/%d",oc_sim_frame_id);
  v_File_o.open_b(frameNum, e_FomWrite);
  int emptyint = 0;
  v_File_o.write_u64(&emptyint, 4);
  v_File_o.close_b();
  
#endif

}

void OCThreadRunnable::dump_v()
{
  /* DD-ID: {35B31AD8-CE57-49be-A9ED-261A5AB7F46F}*/
}

void OCThreadRunnable::cleanup_v()
{
  /* DD-ID: {2B94082A-F1D3-4dd5-AA45-D05B1A365623}*/
}

/* 
Notes: 
Getting Fisheye view from Camera
This function needs to be replaced with getting camera views
from the Windows DataProvider
*/ 

const uint8_t *OCThreadRunnable::get640x400AlgoView_pu8(container::CameraId_e CamID) const
{
  /* DD-ID: {E3424BC8-7BB5-4c55-99B9-0276FA865882}*/
  const uint8_t *c_AlgoViewBufferAddress_pu8;

#ifdef OC_SIMINP_DEBUG
  
  //The following code reads iage from /tmp/folder

  c_AlgoViewBufferAddress_pu8 = &OcSyntheticImageFront_au8[0];
#if 0
  /* The images stored in temp folder will be feed to Algo using momentics*/
  osal::File v_File_o;
  char frameNum[12];
  switch(m_request_camera)
  {
    case variants::e_CameraFront:
    	std::sprintf(frameNum, "/tmp/Front_%d.bin",oc_sim_frame_id);
      break;
    case variants::e_CameraLeft:
    	std::sprintf(frameNum, "/tmp/Left_%d.bin",oc_sim_frame_id);
      break;
    case variants::e_CameraRear:
    	std::sprintf(frameNum, "/tmp/Rear_%d.bin",oc_sim_frame_id);
      break;
    case variants::e_CameraRight:
    	std::sprintf(frameNum, "/tmp/Right_%d.bin",oc_sim_frame_id);
      break;
    default:
      break;
  }

  bool_t v_Success_b = false;
  while (!v_Success_b)
  {
    v_Success_b = v_File_o.open_b(frameNum, e_FomRead );
    if (v_Success_b) v_Success_b = v_File_o.getSize_u64() == IMAGE_WIDTH*IMAGE_HEIGHT;
    usleep(10000);
  }
  v_File_o.read_u64( (void *)c_AlgoViewBufferAddress_pu8, IMAGE_WIDTH*IMAGE_HEIGHT);
  OC_DEBUG_PRINTF(("OC frame number %d\n",oc_sim_frame_id));
  v_File_o.close_b();
#endif

  /* The images stored in SD card will be feed to Algo */
  char FileName[256] = {0};

  switch(m_request_camera)
  {
    case variants::e_CameraFront:
      sprintf(FileName, "/ti_sd/Front_%d.bin", oc_sim_frame_id);
      break;
    case variants::e_CameraLeft:
      sprintf(FileName, "/ti_sd/Left_%d.bin", oc_sim_frame_id);
      break;
    case variants::e_CameraRear:
      sprintf(FileName, "/ti_sd/Rear_%d.bin", oc_sim_frame_id);
      break;
    case variants::e_CameraRight:
      sprintf(FileName, "/ti_sd/Right_%d.bin", oc_sim_frame_id);
      break;
    default:
      break;
  }

  FILE *fptr = fopen(FileName, "rb");
  if (NULL != fptr)
  {
  	size_t Ret = fread((void *)c_AlgoViewBufferAddress_pu8, IMAGE_WIDTH*IMAGE_HEIGHT, 1, fptr);
  	fclose(fptr);
  	fptr = NULL;
  }
  else
  {
  	ME_Debugger_F_Printf_v("Failed to open file [%s]\n", FileName);
  }

  // Dump images 
  // vid_save_bmp("Front1.bmp", (char*)c_AlgoViewBufferAddress_pu8, 640,960);

#else   


  switch (CamID)
  {
  case 1:
    {
    c_AlgoViewBufferAddress_pu8 = dataProvider_ro.getFrontInputImage();
    break;
  }

  case 2:
    {
    c_AlgoViewBufferAddress_pu8 = dataProvider_ro.getLeftInputImage();
    break;
  }

  case 3:
    {
    c_AlgoViewBufferAddress_pu8 = dataProvider_ro.getRearInputImage();
    break;
  }

  case 4:
    {
    c_AlgoViewBufferAddress_pu8 = dataProvider_ro.getRightInputImage();
    break;
  }

  default:
    {
    c_AlgoViewBufferAddress_pu8 = dataProvider_ro.getFrontInputImage();
    break;
  }
  }
#endif  // OC_SIMINP_DEBUG

  return c_AlgoViewBufferAddress_pu8;

}

void OCThreadRunnable::setOcKinematicModelConfiguration_v(void)
{
  /* DD-ID: {D9F97F7C-4A81-4936-9D04-7316E6A1F730}*/
  for (uint32_t v_Index_u32 = 0U; v_Index_u32 < static_cast<uint32_t>(tscApi::e_TscNumCam); v_Index_u32++)
  {
// Leave this hardcoded to true for now
#ifdef OC_SIMINP_DEBUG

    // Leave hardcoded for now since I'm not sure how to get KinematicModel config from DataProvider
    tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.tireCircumferencePerPulseMM_f32 = 1.0F;
    /*tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.distanceCoG2FrontAxisMM_f64     = 1550.5;
     tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.distanceCoG2RearAxisMM_f64      = 1550.5;*/
    tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.distanceCoG2FrontAxisMM_f64 = 1949.45;
    tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.distanceCoG2RearAxisMM_f64 = 1949.45;
#else
    dataProvider_ro.getOCKMConfig_v(&tscStartConfiguration_as[v_Index_u32]);
#endif
    OC_DEBUG_PRINTF(("KM config %f, %f\n", tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.distanceCoG2FrontAxisMM_f64, tscStartConfiguration_as[v_Index_u32].kinematicModelExternalConfig_t.distanceCoG2RearAxisMM_f64));
  }
}

void OCThreadRunnable::setOcCamModelConfiguration_v(void)
{
  /* DD-ID: {CEFCF780-5BD7-4480-9BA2-AF36D4700207}*/
  // TODO :Need to figure out setCamParametersOneCam
  // then this function will be fine
  setCamParametersOneCam_v(mcuCamIdToOcAlgo_e);
}

void OCThreadRunnable::setCamParametersOneCam_v(container::CameraId_e camID)
{
  /* DD-ID: {4B31DC44-9485-443c-B482-C29E918E1284}*/
  tscApi::enuCameraID v_OcAlgoCamId_e = getOcAlgoCamId_e(camID);
  // uint8_t v_ConnectorCamId_u8 = prjcontainer::AdapterCameraReal::getCameraConnectorIdFromMcuId_u8( i_McuCamId_e, dataProvider_ro );

#if defined(OC_LOG_PRINTF_ON) || defined(USE_SVSCM)
  mecl::Sensor_t *v_OcSensor_po = NULL;
  mecl::LensRadial_t::Config_s v_OcLensRadialCfg_s;
  mecl::LensRadial_t *v_OcLensRadial_po = NULL;
  const mecl::Pinhole_t::Intrinsic_s *v_OcIntrinsic_ps = NULL;
#endif

  mecl::Camera_t *v_OcCamera_po = NULL;

  switch (camID)
  {
  case container::e_Front:
    {
    // v_OcCamera_po = &adapterCameraRealFront_o.accessCamera_rt( v_ConnectorCamId_u8, prjcontainer::AdapterCameraReal::e_ExtrDesign,
    // prjcontainer::AdapterCameraReal::e_IntrCurrent, prjcontainer::AdapterCameraReal::e_LensCurrent, true );
    v_OcCamera_po = &dataProvider_ro.getFrontDoCameraParam().camera_param.m_realCam;
    break;
  }

  case container::e_Left:
    {
    // v_OcCamera_po = &adapterCameraRealLeft_o.accessCamera_rt( v_ConnectorCamId_u8, prjcontainer::AdapterCameraReal::e_ExtrDesign,
    // prjcontainer::AdapterCameraReal::e_IntrCurrent, prjcontainer::AdapterCameraReal::e_LensCurrent, true );
    v_OcCamera_po = &dataProvider_ro.getLeftDoCameraParam().camera_param.m_realCam;
    break;
  }

  case container::e_Rear:
    {
    // v_OcCamera_po = &adapterCameraRealRear_o.accessCamera_rt( v_ConnectorCamId_u8, prjcontainer::AdapterCameraReal::e_ExtrDesign,
    // prjcontainer::AdapterCameraReal::e_IntrCurrent, prjcontainer::AdapterCameraReal::e_LensCurrent, true );
    v_OcCamera_po = &dataProvider_ro.getRearDoCameraParam().camera_param.m_realCam;
    break;
  }

  case container::e_Right:
    {
    // v_OcCamera_po = &adapterCameraRealRight_o.accessCamera_rt( v_ConnectorCamId_u8, prjcontainer::AdapterCameraReal::e_ExtrDesign,
    // prjcontainer::AdapterCameraReal::e_IntrCurrent, prjcontainer::AdapterCameraReal::e_LensCurrent, true );
    v_OcCamera_po = &dataProvider_ro.getRightDoCameraParam().camera_param.m_realCam;
    break;
  }

  default:
    {
    // v_OcCamera_po = &adapterCameraRealFront_o.accessCamera_rt( v_ConnectorCamId_u8, prjcontainer::AdapterCameraReal::e_ExtrDesign,
    // prjcontainer::AdapterCameraReal::e_IntrCurrent, prjcontainer::AdapterCameraReal::e_LensCurrent, true );
    v_OcCamera_po = &dataProvider_ro.getFrontDoCameraParam().camera_param.m_realCam;
    break;
  }
  }

  if (NULL != v_OcCamera_po)
  {
    // PRQA S 3077 3 // This downcast is necessary here.
#if 0  // new func for setting camera param
    mecl::Pinhole_t &v_PinHole_ro = dynamic_cast<mecl::Pinhole_t &>(v_OcCamera_po->getImager_rx());
    v_PinHole_ro.init_v();
    c_OcExtrinsics_ps = &v_PinHole_ro.getExtrinsic_rs();
#if defined(OC_LOG_PRINTF_ON) || defined(USE_SVSCM)
    // PRQA S 3077 2 // This downcast is necessary here.
    v_OcSensor_po = &dynamic_cast<mecl::Sensor_t &>(v_OcCamera_po->getSensor_rx());
    v_OcLensRadial_po = &dynamic_cast<mecl::LensRadial_t &>(v_OcCamera_po->getLens_rx());
    v_OcLensRadial_po->copyConfig_v(v_OcLensRadialCfg_s);
    v_OcIntrinsic_ps = &v_PinHole_ro.getIntrinsic_rs();
#endif
#endif
  }

#ifdef USE_SVSCM

  if (NULL != v_OcIntrinsic_ps)
  {
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.focalLength = static_cast<float64_t>(v_OcIntrinsic_ps->foclX_x);
  }

  if (NULL != v_OcSensor_po)
  {
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.pixelSize = static_cast<float64_t>(v_OcSensor_po->getPsz_rx().getPosX());
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.ppx = static_cast<float64_t>(v_OcSensor_po->getPpp_rx().getPosX());
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.ppy = static_cast<float64_t>(v_OcSensor_po->getPpp_rx().getPosY());
#if 0
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.pixelSize = static_cast<float64_t>( v_OcSensorCfg_ps->pszCfg_x.cVal_ax[0] );
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.ppx = static_cast<float64_t>( v_OcSensorCfg_ps->pppCfg_x.cVal_ax[0] ); // + 0.5F //TODO: 0.5F added for SVS model?
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.ppy = static_cast<float64_t>( v_OcSensorCfg_ps->pppCfg_x.cVal_ax[1] );// + 0.5F //TODO: 0.5F added for SVS model?
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.axisX = static_cast<float64_t>( v_OcSensorCfg_ps->pppCfg_x.cVal_ax[0] );
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.axisY = static_cast<float64_t>( v_OcSensorCfg_ps->pppCfg_x.cVal_ax[1] );
#endif
    OC_DEBUG_PRINTF( ( "camId:%d, pixelSize*10000: %d, focalLength*10000: %d, ppx*10000: %d, ppy*10000: %d\n, ",
            v_OcAlgoCamId_e,
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.pixelSize * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.focalLength * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.ppx * 10000 ),
            static_cast<sint32_t>(tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.ppy * 10000)));
  }

  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.radialZeroCrossing = 2400.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.radialCoeff1 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.radialCoeff2 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.radialCoeff3 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.tangentialCoeff1 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.tangentialCoeff2 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.affineCoeff1 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.affineCoeff2 = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.origX = 1280.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.origY = 800.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.axisX = 639.5;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.axisY = 399.5;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.intrinsicParams.downsampleFactor = 2;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.X_mm = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Y_mm = 0.0;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.flipped = false;
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.orientationParams.preRoll_deg = V_PreRoll_af32[v_OcAlgoCamId_e];

  if (NULL != c_OcExtrinsics_ps)
  {
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.orientationParams.deltaX = static_cast<float64_t>(c_OcExtrinsics_ps->pos_x.cVal_ax[0]);
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.orientationParams.deltaY = static_cast<float64_t>(c_OcExtrinsics_ps->pos_x.cVal_ax[1]);
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Z_mm = static_cast<float64_t>(c_OcExtrinsics_ps->pos_x.cVal_ax[2]);
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Pitch_deg = static_cast<float64_t>(mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.pitch_x));
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Yaw_deg = static_cast<float64_t>(mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.yaw_x));
    tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Roll_deg = static_cast<float64_t>(mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.roll_x));
    OC_DEBUG_PRINTF( ( "pitch*10000: %d, yaw*10000: %d, roll*10000: %d, PreRoll*10000:%d\n, ",
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Pitch_deg * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Yaw_deg * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Roll_deg * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.orientationParams.preRoll_deg * 10000 )
        ) );
    OC_DEBUG_PRINTF( ( "deltaX*10000: %d, deltaY*10000: %d, z*10000: %d\n, ",
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.orientationParams.deltaX * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.orientationParams.deltaY * 10000 ),
            static_cast<sint32_t>( tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.extrinsicParams.Z_mm * 10000 )
        ) );
  }

  if (NULL != v_OcLensRadial_po)
  {
  }

#else
  dataProvider_ro.setCameraparams(camID, /*c_calibrationType_e*/variants :: e_CalibTypeOC);
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.camera_px = v_OcCamera_po;
  mecl::Pinhole_t &v_PinHole_ro = dynamic_cast<mecl::Pinhole_t&>(tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.camera_px->getImager_rx());
  v_PinHole_ro.init_v();
  c_OcExtrinsics_ps = &v_PinHole_ro.getExtrinsic_rs();
  tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.downSampleFactor_f32 = 2.0F;

#endif
  OC_DEBUG_PRINTF(("extr_ps: %p, Cam_ro: %p\n", c_OcExtrinsics_ps, tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.camera_px));

  if (NULL != c_OcExtrinsics_ps)
  {
    OC_DEBUG_PRINTF(("p:%f, y:%f, r:%f\n",
            (mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.pitch_x )),
            (mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.yaw_x)),
            (mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.roll_x))));
    OC_DEBUG_PRINTF(("x:%f, y:%f, z:%f, pre_r : % d, rot_type: % d\n ",
            (c_OcExtrinsics_ps->pos_x.cVal_ax[0]),
            (c_OcExtrinsics_ps->pos_x.cVal_ax[1]),
            (c_OcExtrinsics_ps->pos_x.cVal_ax[2]),
            c_OcExtrinsics_ps->preRoll_e,
            c_OcExtrinsics_ps->rotationType_e));

    OC_DEBUG_PRINTF(("x:%f, y:%f, z:%f, pre_r : % d, rot_type: % d\n ",
            (c_OcExtrinsics_ps->pos_x.cVal_ax[0]),
            (c_OcExtrinsics_ps->pos_x.cVal_ax[1]),
            (c_OcExtrinsics_ps->pos_x.cVal_ax[2]),
            c_OcExtrinsics_ps->preRoll_e,
            c_OcExtrinsics_ps->rotationType_e));
    // ME_Debugger_F_Printf_v("p:%f, y:%f, r:%f\n", (mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.pitch_x)), (mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.yaw_x)),
    //                        (mecl::math::toDegrees_x(c_OcExtrinsics_ps->eulerAngles_s.roll_x)));
    // ME_Debugger_F_Printf_v("x:%f, y:%f, z:%f, pre_r:%f, rot_type: %f\n", (c_OcExtrinsics_ps->pos_x.cVal_ax[0]), (c_OcExtrinsics_ps->pos_x.cVal_ax[1] * 10000.0F),
    //                        (c_OcExtrinsics_ps->pos_x.cVal_ax[2] * 10000.0F), c_OcExtrinsics_ps->preRoll_e, c_OcExtrinsics_ps->rotationType_e);
  }

#ifdef OC_LOG_PRINTF_ON

  v_OcIntrinsic_ps = &v_PinHole_ro.getIntrinsic_rs();
  if (NULL != v_OcIntrinsic_ps)
  {
    OC_DEBUG_PRINTF(("fX:%f,fY:%f,pppCfgX:%f,pppCfgY:%f\n", (v_OcIntrinsic_ps->foclX_x ), (v_OcIntrinsic_ps->foclY_x), (v_OcIntrinsic_ps->pppCfg_x.cVal_ax[0]),
            (v_OcIntrinsic_ps->pppCfg_x.cVal_ax[1])));
  }
  v_OcSensor_po = &dynamic_cast<mecl::Sensor_t &>(tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.camera_px->getSensor_rx());
  if (NULL != v_OcSensor_po)
  {
    OC_DEBUG_PRINTF(("ppx:%f,ppy:%f\n", (v_OcSensor_po->getPpp_rx().getPosX()), (v_OcSensor_po->getPpp_rx().getPosY())));
  }

  v_OcLensRadial_po = &dynamic_cast<mecl::LensRadial_t &>(tscStartConfiguration_as[v_OcAlgoCamId_e].cameraModelExternalConfig_t.camera_px->getLens_rx());

  v_OcLensRadial_po->copyConfig_v(v_OcLensRadialCfg_s);
  if (NULL != v_OcLensRadial_po)
  {
    OC_DEBUG_PRINTF(("W2I[0]: %f, W2I[1]: %f, W2I[2]: %f, W2I[3]: %f, W2I[4]: %f, W2I[5]: %f\n", (v_OcLensRadialCfg_s.world2image_x[0]), (v_OcLensRadialCfg_s.world2image_x[1]),
            (v_OcLensRadialCfg_s.world2image_x[2]), (v_OcLensRadialCfg_s.world2image_x[3]), (v_OcLensRadialCfg_s.world2image_x[4]),
            (v_OcLensRadialCfg_s.world2image_x[5])));
    OC_DEBUG_PRINTF(("I2W[0]: %f, I2W[1]: %f, I2W[2]: %f, I2W[3]: %f, I2W[4]: %f, I2W[5]: %f\n, ", (v_OcLensRadialCfg_s.image2world_x[0]), (v_OcLensRadialCfg_s.image2world_x[1]),
            (v_OcLensRadialCfg_s.image2world_x[2]), (v_OcLensRadialCfg_s.image2world_x[3]), (v_OcLensRadialCfg_s.image2world_x[4]),
            (v_OcLensRadialCfg_s.image2world_x[5])));
  }

#endif
}

tscApi::enuCameraID OCThreadRunnable::getOcAlgoCamId_e(container::CameraId_e i_McuCamId_e)
{
  /* DD-ID: {30CEF97C-A426-432f-870B-C6E2EB72DC61}*/
  tscApi::enuCameraID v_OcAlgoCamId_e;

  switch (i_McuCamId_e)
  {
  case container::e_Front:
    {
    v_OcAlgoCamId_e = tscApi::e_TscFrontCam;
    break;
  }

  case container::e_Left:
    {
    v_OcAlgoCamId_e = tscApi::e_TscLeftCam;
    break;
  }

  case container::e_Rear:
    {
    v_OcAlgoCamId_e = tscApi::e_TscRearCam;
    break;
  }

  case container::e_Right:
    {
    v_OcAlgoCamId_e = tscApi::e_TscRightCam;
    break;
  }

  default:
    {
    v_OcAlgoCamId_e = tscApi::e_TscFrontCam;
    break;
  }
  }

  return v_OcAlgoCamId_e;
}

void OCThreadRunnable::setOcFeatureCollectionConfiguration_v(void)
{
  /* DD-ID: {EB50959A-9441-4c1b-AF67-032847B8C3DE}*/
   // Leave this hardcoded to true for now
  // Probably can switch this from checking variant data to
  // reading from a cfg file like a normal AppCtrl plugin
#if 0 //#ifdef OC_SIMINP_DEBUG
  // FRONT CAM
  // Trajectory Filter
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.minPixelMotionThresh_u32 = 5;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64 = 0.08;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useSfmFilter_b = false;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64 = 20.0;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64 = 5.0;//10.0;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.deviationPercentageIG_u32 = 20;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useCombinations_b = true;//J//false;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64 = 2.0;
  // BMALFC
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[0] = 5;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[1] = 10;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[2] = 15;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[3] = 20;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[4] = 25;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[5] = 35;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [0] = 3;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [1] = 2;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [2] = 1;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [3] = 0;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [4] = 0;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [5] = 0;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].x_s32 = 300;//400;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].y_s32 = 280;//230;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].width_s32 = 30;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].height_s32 = 30;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].x_s32 = 600;//540;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].y_s32 = 280;//230;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].width_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscFrontCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].height_s32 = 40;
  // LEFT CAM
  // Trajectory Filter
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.minPixelMotionThresh_u32 = 5; /* default 5    */
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64 = 0.02; /* default 0.02 */
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useSfmFilter_b = false;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64 = 40.0;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64 = 5;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.deviationPercentageIG_u32 = 20;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useCombinations_b = true;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64 = 2;
  // BMALFC
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[0] = 6;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[1] = 12;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[2] = 17;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[3] = 22;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[4] = 25;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[5] = 35;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[0] = 3;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[1] = 2;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[2] = 1;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[3] = 0;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[4] = 0;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[5] = 0;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].x_s32 = 330;//580;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].y_s32 = 130;//330;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].width_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].height_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].x_s32 = 390;//580;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].y_s32 = 220;//410;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].width_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscLeftCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].height_s32 = 40;
  // REAR CAM
  // Trajectory Filter
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.minPixelMotionThresh_u32 = 5; /* default 5    */
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64 = 0.05; /* default 0.05 */
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useSfmFilter_b = false;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64 = 20.0;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64 = 5;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.deviationPercentageIG_u32 = 20;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useCombinations_b = true;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64 = 2;
  // BMALFC
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[0] = 6;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[1] = 11;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[2] = 15;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[3] = 20;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[4] = 25;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[5] = 35;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [0] = 3;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [1] = 2;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [2] = 1;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [3] = 0;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [4] = 0;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [5] = 0;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].x_s32 = 320;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].y_s32 = 160;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].width_s32 = 30;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].height_s32 = 30;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].x_s32 = 590;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].y_s32 = 160;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].width_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscRearCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].height_s32 = 40;
  // RIGHT CAM
  // Trajectory Filter
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.minPixelMotionThresh_u32 = 5; /* default 5    */
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64 = 0.02; /* default 0.05 */
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useSfmFilter_b = false;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64 = 40.0;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64 = 5;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.deviationPercentageIG_u32 = 20;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.useCombinations_b = true;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64 = 2;
  // BMALFC
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[0] = 6;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[1] = 12;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[2] = 17;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[3] = 22;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[4] = 25;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[5] = 35;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[0] = 3;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[1] = 2;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[2] = 1;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[3] = 0;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[4] = 0;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32[5] = 0;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].x_s32 = 630;//J//580;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].y_s32 = 130;//J//280;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].width_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].height_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].x_s32 = 570;//J//580;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].y_s32 = 220;//J//210;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].width_s32 = 40;
  tscStartConfiguration_as[tscApi::e_TscRightCam].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].height_s32 = 40;
#else
  for (uint32_t v_Index_u32 = 0U; v_Index_u32 < static_cast<uint32_t>(tscApi::e_TscNumCam); v_Index_u32++)
  {
    // PRQA S 3706 1 //Using subscript operator here is intended.
    dataProvider_ro.getOCConfig_v(v_Index_u32, &tscStartConfiguration_as[v_Index_u32]);
  }
#endif
  for (uint32_t v_Index_u32 = 0U; v_Index_u32 < static_cast<uint32_t>(tscApi::e_TscNumCam); v_Index_u32++)
  {
    OC_DEBUG_PRINTF(("OC config %d, %f, %d, %f, %f, %d, %d, %f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d , %d,  %d\n",
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.
            trajectoryFilterConfig_t.minPixelMotionThresh_u32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64,
            (uint8_t)tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.useSfmFilter_b ,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64 ,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64 ,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.deviationPercentageIG_u32 ,
            (uint8_t)tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.useCombinations_b ,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64 ,
            // BMALFC
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[0],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[1],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[2],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[3],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[4],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[5],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [0],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [1],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [2],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [3],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [4],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [5],
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].x_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].y_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].width_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].height_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].x_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].y_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].width_s32,
            tscStartConfiguration_as[v_Index_u32].featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].height_s32));
  }
}

int OCThreadRunnable::vid_save_bmp(char *input_filename, char *img, int h, int w)
{
  /* DD-ID: {8603B282-6302-49bd-ABDA-76651423C693}*/
  FILE *f;
  // int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int
  int filesize = 54 + w * h;  // w is your image width, h is image height, both int
  int i;
  unsigned int image_offset = 54 + 4 * 256; /* offset is file header + Dib header + colormap */
  unsigned char bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
  unsigned char bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0 };
  unsigned char bmppad[3] = { 0, 0, 0 };
  bmpfileheader[2] = (unsigned char) (filesize);
  bmpfileheader[3] = (unsigned char) (filesize >> 8);
  bmpfileheader[4] = (unsigned char) (filesize >> 16);
  bmpfileheader[5] = (unsigned char) (filesize >> 24);
  bmpfileheader[0xA] = (unsigned char) (image_offset >> 0); /* set offset of image */
  bmpfileheader[0xB] = (unsigned char) (image_offset >> 8);
  bmpfileheader[0xC] = (unsigned char) (image_offset >> 16);
  bmpfileheader[0xD] = (unsigned char) (image_offset >> 24);
  bmpinfoheader[4] = (unsigned char) (w);
  bmpinfoheader[5] = (unsigned char) (w >> 8);
  bmpinfoheader[6] = (unsigned char) (w >> 16);
  bmpinfoheader[7] = (unsigned char) (w >> 24);
  bmpinfoheader[8] = (unsigned char) (h);
  bmpinfoheader[9] = (unsigned char) (h >> 8);
  bmpinfoheader[10] = (unsigned char) (h >> 16);
  bmpinfoheader[11] = (unsigned char) (h >> 24);
  f = fopen(input_filename, "wb");
  fwrite(bmpfileheader, 1, 14, f);
  fwrite(bmpinfoheader, 1, 40, f);
  // write out 256 entry grayscale
  unsigned char bgr_[4];

  for (i = 0; i < 256; i++)
  {
    bgr_[0] = (char) i;
    bgr_[1] = (char) i;
    bgr_[2] = (char) i;
    bgr_[3] = 0;
    fwrite(bgr_, 1, 4, f);
  }

  for (i = 0; i < h; i++)
  {
    fwrite(img + (w * (h - i - 1)), 1, w, f);
    fwrite(bmppad, 1, (4 - (w) % 4) % 4, f);
    //    fwrite(img+(w*(h-i-1)*3),3,w,f);
    //    fwrite(bmppad,1,(4-(w*3)%4)%4,f);
  }

  fclose(f);
  return (0);
}
#if 0
void OCThreadRunnable::vid_save_txt(const char *input_filename, char *img, int h, int w)
{
  // Save image as 8 bit hex map
  FILE *fp;
  fp = fopen(input_filename, "w");
  int k = 0;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      fprintf(fp, "0x%hhx,", img[k]);
      k++;
    }

    fprintf(fp, "\n");
  }
}
#endif

void OCThreadRunnable::DumpCalibrationResults(tscApi::enuCameraID v_OcAlgoCamId_e, container::OcData_s& v_OcData_rs)
{
  /* DD-ID: {89D8A4B9-86E8-44be-ABFB-AFB6FBC71C8C}*/
  FILE *fp1;
  FILE *fp2;
  switch (v_OcAlgoCamId_e)
  {
  case 0: //Front
    fp1 = fopen("/ti_sd/FRONT_AlgoStateResult_ECU.csv", "w");
    fp2 = fopen("/ti_sd/FRONT_CalibrationResult_ECU.csv", "w");
    break;
  case 1: //Left
    fp1 = fopen("/ti_sd/LEFT_AlgoStateResult_ECU.csv", "w");
    fp2 = fopen("/ti_sd/LEFT_CalibrationResult_ECU.csv", "w");
    break;
  case 2: //Rear
    fp1 = fopen("/ti_sd/REAR_AlgoStateResul_ECUt.csv", "w");
    fp2 = fopen("/ti_sd/REAR_CalibrationResult_ECU.csv", "w");
    break;
  case 3: //Right
    fp1 = fopen("/ti_sd/RIGHT_AlgoStateResult_ECU.csv", "w");
    fp2 = fopen("/ti_sd/RIGHT_CalibrationResult_ECU.csv", "w");
    break;
  default: //
    fp1 = fopen("/ti_sd/AlgoStateResult_ECU.csv", "w");
    fp2 = fopen("/ti_sd/CalibrationResult_ECU.csv", "w");
    break;
  }

  if (!fp1)
  {
    ME_Debugger_F_Printf_v("Failed to open file for OC AlgoStateResult results!\n");
  }
  if (!fp2)
  {
    ME_Debugger_F_Printf_v("Failed to open file for OC CalibrationResult results!\n");
  }

  fprintf(fp1, "%s\n",
      "Camera ID"
          ",TSC Algo State"
          ",State to MCU"
          ",OC Error Code"
          ",Valid Features"
          ",Ignored Features"
          ",Invalid Features"
          ",Skipped Frames"
          ",Processed Frames"
          ",State"
          ",Error"
      );

#if 0
  fprintf(fp1, "%d, %d, %d, %d, %lu, %lu, %lu, %d, %d, %d, %d\n",
      v_OcAlgoCamId_e
      , tscAlgoState_ae[v_OcAlgoCamId_e]
      , v_OcData_rs.ocAlgoState_e
      , v_OcData_rs.ocErrorCode_e
      , v_OcData_rs.validFeaturesCount_u32
      , v_OcData_rs.ignoredFeaturesCount_u32
      , v_OcData_rs.invalidFeaturesCount_u32
      , TSC_GetSkippedFramesCount(v_OcAlgoCamId_e)
          , initialisation_data.ProcessedFrameCount
      , TSC_GetState(v_OcAlgoCamId_e)
          , TSC_GetError(v_OcAlgoCamId_e)
          );
  fclose(fp1);
#endif

  fprintf(fp2, "%s\n",
      "Pitch"
          ",Yaw"
          ",Roll"
          ",X"
          ",Y"
          ",Z"
          ",Delta Pitch"
          ",Delta Yaw"
          ",Delta Roll"
      );

#if 0
  fprintf(fp2, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n",
      tscCalibrationResults_as[v_OcAlgoCamId_e].pitchDeg_f64
      , tscCalibrationResults_as[v_OcAlgoCamId_e].yawDeg_f64
      , tscCalibrationResults_as[v_OcAlgoCamId_e].rollDeg_f64
      , tscCalibrationResults_as[v_OcAlgoCamId_e].xMM_f64
      , tscCalibrationResults_as[v_OcAlgoCamId_e].yMM_f64
      , tscCalibrationResults_as[v_OcAlgoCamId_e].zMM_f64
      , v_OcData_rs.deltaPitch_f32
      , v_OcData_rs.deltaYaw_f32
      , v_OcData_rs.deltaRoll_f32
      );
  fclose(fp2);
#endif
}

void OCThreadRunnable::setmcuCamIdToOcAlgo_e(variants::Camera_t i_request_camera)
{
  /* DD-ID: {C8EB7148-2FCC-41e6-BBD7-C435F634691F}*/
  switch (i_request_camera)
  {
  case variants::e_CameraFront:
    {
    mcuCamIdToOcAlgo_e = container::e_Front;  // prjcontainer::e_Rear //This MCU Cam ID is used for OC/TSC algorithm
    break;
  }
  case variants::e_CameraLeft:
    {
    mcuCamIdToOcAlgo_e = container::e_Left;  // prjcontainer::e_Rear //This MCU Cam ID is used for OC/TSC algorithm
    break;
  }
  case variants::e_CameraRear:
    {
    mcuCamIdToOcAlgo_e = container::e_Rear;  // prjcontainer::e_Rear //This MCU Cam ID is used for OC/TSC algorithm
    break;
  }
  case variants::e_CameraRight:
    {
    mcuCamIdToOcAlgo_e = container::e_Right;  // prjcontainer::e_Rear //This MCU Cam ID is used for OC/TSC algorithm
    break;
  }

  case variants::e_CameraInvalid:
    {
    mcuCamIdToOcAlgo_e = container::e_NoCamera;  // prjcontainer::e_Rear //This MCU Cam ID is used for OC/TSC algorithm
    break;
  }
  default:
    {
    mcuCamIdToOcAlgo_e = container::e_NoCamera;
    break;
  }
  }
}

} /* namespace oc */
