//--------------------------------------------------------------------------
/// @file TIOVXHandlerThread.h
/// @brief Contains the Job definition for TIOVX host
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>
#include "tiovx/IDataProviderTIOVX.h"
#include "TIOVXHandlerThread.h"

#include <logging/Logger.h>
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_TIOVXThread     (1u)
#endif
#if PROFILE_TIOVXThread
#include "osal/system/Time.h"
static uint32_t v_AvgTIOVXThreadRuntime_u32 = 0;
static uint32_t v_TIOVXThreadRunCntr_u32 = 0;
static uint32_t v_AvgTIOVXThreadPeriodicity_u32 = 0;
static uint32_t v_TIOVXThreadPreviousTime_u32 = 0;
static uint32_t v_TIOVXThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsTHEnable_dp;
#endif

namespace tiovx
{

TIOVXHandlerThread::TIOVXHandlerThread(IDataProviderTIOVX& i_DataProvider_ro)
  : IRunnable()
  , dataProvider_ro(i_DataProvider_ro)
  , isRunning_b(false)
  , tiovx_po(NULL)
#if 0	
  , layerEngine_po(NULL)
  , viewGen_po(NULL)
  , axisMipMem_po(NULL)
  , updateAll_b(false)
#endif
{
}

TIOVXHandlerThread::~TIOVXHandlerThread()
{
}


void TIOVXHandlerThread::init_v()
{
  if (tiovx_po != NULL)
  {
    isRunning_b = true;
  }

  ME_Debugger_F_Printf_v("init_v done: %d\n", isRunning_b);
}

bool_t TIOVXHandlerThread::run_b()
{
#if 0    
  FpgaUpdateState_e v_State_e = e_UpdateIdleState;
  FpgaUpdateState_e v_NextState_e = e_UpdateIdleState;

  bool_t v_InitVideoOutput_b = false;
  bool_t v_FirstViewGenConfigDone_b = false;
  bool_t v_FirstLayerENgineConfigDone_b = true;

  while(true == isRunning_b)
  {
    if(fpga_po->getFpgaState_e() == bsp::e_FpgaStateInitalized)
    {
      switch(v_State_e)
      {
      case e_UpdateIdleState:
      {
        fpga_po->getFrameTrigger_u32();

        if(viewGen_po->isProcessingViewGen_b() == true)
        {
          v_NextState_e = e_UpdateViewGenState;
        }
        if(layerEngine_po->isLayerProcessed_e() > bsp::e_FlpsNoLayerProcessed)
        {
          v_NextState_e = e_UpdateLayerEngineState;
        }

        break;
      }
      case e_UpdateViewGenState:
      {
        if((viewGen_po->isProcessingViewGen_b() == true)
        && (viewGen_po->isConfigViewGenDone_b() == false))
        {
          v_NextState_e = e_UpdateViewGenState;
        }
        else if((viewGen_po->isProcessingViewGen_b() == true)
             && (viewGen_po->isConfigViewGenDone_b() == true))
        {
          if(true == viewGen_po->update_b())
          {
            v_FirstViewGenConfigDone_b = true;
            viewGen_po->free_v();

            if(layerEngine_po->isLayerProcessed_e() > bsp::e_FlpsNoLayerProcessed)
            {
              v_NextState_e = e_UpdateLayerEngineState;
            }
            else
            {
              v_NextState_e = e_UpdateFinishState;
            }
          }
        }
        else
        {
          v_NextState_e = e_UpdateFinishState;
        }

        break;
      }
      case e_UpdateLayerEngineState:
      {
        if((layerEngine_po->isLayerConfigDone_b() == false)
        && (layerEngine_po->isLayerProcessed_e() > bsp::e_FlpsNoLayerProcessed))
        {
          v_NextState_e = e_UpdateLayerEngineState;
        }
        else if((layerEngine_po->isLayerConfigDone_b() == true)
             && (layerEngine_po->isLayerProcessed_e() > bsp::e_FlpsNoLayerProcessed))
        {
          if(true == layerEngine_po->update_b())
          {
            v_FirstLayerENgineConfigDone_b = true;
            layerEngine_po->free_v();

            if(viewGen_po->isProcessingViewGen_b() == true)
            {
              v_NextState_e = e_UpdateViewGenState;
            }
            else
            {
              v_NextState_e = e_UpdateFinishState;
            }
          }
        }
        else
        {
          v_NextState_e = e_UpdateFinishState;
        }

        break;
      }
      case e_UpdateFinishState:
      {
#if 0
        printLayer_v();
#endif

        v_NextState_e = e_UpdateIdleState;
        break;
      }
      default:
      {
        break;
      }
      }

#if 0
      if(v_NextState_e != v_State_e)
      {
        ME_Debugger_F_Printf_v("Next state: [%d], frame number [%d], prev frame number [%d]\n", v_NextState_e, v_FrameNumber_u32, v_PrevFrameNumber_u32);
      }
#endif

      v_State_e = v_NextState_e;
    }
    else
    {
      ME_Thread_Sleep_t(32);
    }
  }
#endif
#if PROFILE_TIOVXThread
  PerformanceStatsTHEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_TIOVXThreadPreviousTime_u32;
  }
#endif
  ME_Thread_Sleep_t(1000);
  // TODO: remove while loop, everything is handled in upper class (e.g. Thread)
#if PROFILE_TIOVXThread
  if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    //ME_Debugger_F_Printf_v("TIOVXThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_TIOVXThreadRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgTIOVXThreadPeriodicity_u32 = ((v_AvgTIOVXThreadPeriodicity_u32 * (v_TIOVXThreadRunCntr_u32 -1)) + currPeriodicity)/v_TIOVXThreadRunCntr_u32; //Average Periodicity
		v_AvgTIOVXThreadRuntime_u32 = ((v_AvgTIOVXThreadRuntime_u32 * (v_TIOVXThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_TIOVXThreadRunCntr_u32; //New Average  
    v_TIOVXThreadRuntimeData = (((v_AvgTIOVXThreadRuntime_u32/1000U)<<16U) | ((v_AvgTIOVXThreadPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setTIOVXThreadRuntime(v_TIOVXThreadRuntimeData);
    //ME_Debugger_F_Printf_v("TIOVXTh: E: %lld P: %lld \n", v_AvgTIOVXThreadRuntime_u32, v_AvgTIOVXThreadPeriodicity_u32);
    v_TIOVXThreadPreviousTime_u32 = v_Start_t;
  }
#endif
  return true;
}

void TIOVXHandlerThread::cleanup_v()
{
  isRunning_b = false;
}

#if 0
void FpgaHandlerThread::printLayer_v() const
{
#if 0    
  ME_Debugger_F_Printf_v("Fpga Layer\n");
  ME_Debugger_F_Printf_v("-----------------------------------------------------------------------------\n");
  bsp::LayerConfig_s v_LayerConfig_s;
  for(uint32_t v_I_u32 = 0; v_I_u32 < bsp::c_LayerEngineLayerCount_u8; v_I_u32++)
  {
    layerEngine_po->getLayerConfig_v(static_cast<bsp::FpgaLayerID_e>(v_I_u32), v_LayerConfig_s);
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "ID [%d], Buf [%d], En [%d], xP [%d], xS [%d], xO [%d], yP [%d], yS [%d], yO [%d], alpha [%d], offsetKb [0x%x]\n"
                           , v_LayerConfig_s.layerID_e
                           , v_LayerConfig_s.bufferID_u8
                           , v_LayerConfig_s.enable_b
                           , v_LayerConfig_s.xPos_u32
                           , v_LayerConfig_s.xSize_u32
                           , v_LayerConfig_s.xOffset_u32
                           , v_LayerConfig_s.yPos_u32
                           , v_LayerConfig_s.ySize_u32
                           , v_LayerConfig_s.yOffset_u32
                           , v_LayerConfig_s.alphaValue_u16
                           , v_LayerConfig_s.layerOffset_u32);

    memset(&v_LayerConfig_s, 0, sizeof(v_LayerConfig_s));
  }
#endif  
}
#endif

} // namespace tiovx

