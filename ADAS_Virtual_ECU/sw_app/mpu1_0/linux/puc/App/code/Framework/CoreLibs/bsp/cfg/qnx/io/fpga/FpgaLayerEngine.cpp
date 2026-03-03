//--------------------------------------------------------------------------
/// @file FpgaLayerEngine.cpp
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>

#include <logging/Logger.h>

#include "bsp/io/fpga/FpgaLayerEngine.h"

#include "bsp/io/fpga/FpgaParameters.h"

#ifdef ME_PLATFORM_QNX

namespace bsp
{

static logging::Logger s_Logger_o;
static ThreadID_t      s_LockThreadID_t = ME_INVALID_PROCESS_ID;
static uint8_t         s_LockDepth_u8 = 0;

bool_t isOverlayLayer_b(FpgaLayerID_e i_LayerId_e)
{
  bool_t v_Result_b = false;

  if((i_LayerId_e >= e_OverlayLayer1) && (i_LayerId_e <= e_OverlayLayer2))
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t isVideoLayer_b(FpgaLayerID_e i_LayerId_e)
{
  bool_t v_Result_b = false;

  if((i_LayerId_e >= e_VideoLayer0) && (i_LayerId_e <= e_VideoLayer2))
  {
    v_Result_b = true;
  }

  return v_Result_b;
}


FpgaLayerEngine::FpgaLayerEngine()
  : time_o()
  , lockMutex_o()
  , mutex_o()
  , isLayerEngineEnabled_b(false)
  , layerEngineCommon_pv(NULL)
  , layerEngineBase_pv(NULL)
  , screenRequest_t()
  , prevZoomFactor_u8(100U)
{/*
  for(uint32_t v_I_u32 = 0; v_I_u32 < c_LayerEngineLayerCount_u8; v_I_u32++)
  {
    layerBuffer_apv[v_I_u32][0] = NULL;
    layerBuffer_apv[v_I_u32][1] = NULL;

    isConfigLayerDone_ab[v_I_u32] = false;
    isProcessingLayer_ab[v_I_u32] = false;
    wasProcessedLayer_ab[v_I_u32] = false;
  }

  screenRequest_t.ViewID_u8 = variants::e_ViewIdInvalid;

  s_Logger_o.config_b(logging::e_LogLvlDisable, "FLE", "FPGA", logging::e_LogModeMaskPrintf);
*/}

FpgaLayerEngine::~FpgaLayerEngine()
{

}


bool_t FpgaLayerEngine::initLayerEngine_b()
{
  bool_t v_Result_b = false;
/*
  ME_IO_MapDeviceAdress_b(bsp::c_LayerEngineAxiGPIO0Base_u32, 0x1U, &layerEngineCommon_pv);
  ME_IO_MapDeviceAdress_b(bsp::c_LayerEngineBase_u32, 0x10000U, &layerEngineBase_pv);

  if(e_PeOk == ME_SharedMemory_MapPhysicalByAddress_t(c_LayerEngineOverlayLayer0_u32, c_LayerEngineOverlayLayerSize_u32, &layerBuffer_apv[e_OverlayLayer0][0]))
  {
    if(e_PeOk != ME_SharedMemory_MapPhysicalByAddress_t(c_LayerEngineOverlayLayer0_u32 + c_LayerEngineOverlayBufferOffset_u32, c_LayerEngineOverlayLayerSize_u32, &layerBuffer_apv[e_OverlayLayer0][1]))
    {
      s_Logger_o.log_b(logging::e_LogLvlInfo, "Failed to map layer engine memory\n");
    }
  }
  else
  {
    s_Logger_o.log_b(logging::e_LogLvlInfo, "Failed to map layer engine memory\n");
  }

  if(e_PeOk == ME_SharedMemory_MapPhysicalByAddress_t(c_LayerEngineOverlayLayer1_u32, c_LayerEngineOverlayLayerSize_u32, &layerBuffer_apv[e_OverlayLayer1][0]))
  {
    if(e_PeOk != ME_SharedMemory_MapPhysicalByAddress_t(c_LayerEngineOverlayLayer1_u32 + c_LayerEngineOverlayBufferOffset_u32, c_LayerEngineOverlayLayerSize_u32, &layerBuffer_apv[e_OverlayLayer1][1]))
    {
      s_Logger_o.log_b(logging::e_LogLvlInfo, "Failed to map layer engine memory\n");
    }
  }
  else
  {
    s_Logger_o.log_b(logging::e_LogLvlInfo, "Failed to map layer engine memory\n");
  }

  if(e_PeOk == ME_SharedMemory_MapPhysicalByAddress_t(c_LayerEngineOverlayLayer2_u32, c_LayerEngineOverlayLayerSize_u32, &layerBuffer_apv[e_OverlayLayer2][0]))
  {
    if(e_PeOk != ME_SharedMemory_MapPhysicalByAddress_t(c_LayerEngineOverlayLayer2_u32 + c_LayerEngineOverlayBufferOffset_u32, c_LayerEngineOverlayLayerSize_u32, &layerBuffer_apv[e_OverlayLayer2][1]))
    {
      s_Logger_o.log_b(logging::e_LogLvlInfo, "Failed to map layer engine memory\n");
    }
  }
  {
    s_Logger_o.log_b(logging::e_LogLvlInfo, "Failed to map layer engine memory\n");
  }

  if((layerEngineCommon_pv != NULL)
  && (layerEngineBase_pv != NULL))
  {
    v_Result_b = true;

    if(true == lock_b())
    {
      for(uint32_t v_I_u32 = 0; v_I_u32 < c_AlphaLayerCount_u8; v_I_u32++)
      {
        uint32_t v_AlphaLayerAddress_u32 = 0x0U;
        uint32_t v_AlphaLayerSize_u32    = 0x0U;

        ME_IO_In32_b(layerEngineBase_pv, 0x400U + (v_I_u32 << 6) + (3 << 2), &v_AlphaLayerAddress_u32);
        ME_IO_In32_b(layerEngineBase_pv, 0x400U + (v_I_u32 << 6) + (4 << 2), &v_AlphaLayerSize_u32);

        if((e_PeOk ==  ME_SharedMemory_MapPhysicalByAddress_t(v_AlphaLayerAddress_u32,                        0x00400000U, &layerBuffer_apv[v_I_u32][0]))
        && (e_PeOk ==  ME_SharedMemory_MapPhysicalByAddress_t(v_AlphaLayerAddress_u32 + v_AlphaLayerSize_u32, 0x00400000U, &layerBuffer_apv[v_I_u32][1])))
        {
          v_Result_b = true;
        }
        else
        {
          v_Result_b = false;
        }
      }

      unlock_b();
    }

    for(uint32_t v_I_u32 = 0; v_I_u32 < c_LayerEngineLayerCount_u8; v_I_u32++)
    {
      if((layerBuffer_apv[v_I_u32][0] == NULL) || (layerBuffer_apv[v_I_u32][1] == NULL))
      {
        v_Result_b = false;
      }
    }
  }*/

  return v_Result_b;
}

bool_t FpgaLayerEngine::setScreenRequest_b(ScreenRequest_t i_ScreenRequest_t)
{
  bool_t v_Result_b;
 /* v_Result_b = (i_ScreenRequest_t.ViewID_u8 < variants::e_ViewIdCount)
                   && (0 != memcmp(&screenRequest_t, &i_ScreenRequest_t, sizeof(ScreenRequest_t)));

  mutex_o.take_b();
  if(v_Result_b == true)
  {
    screenRequest_t = i_ScreenRequest_t;
  }
  mutex_o.give_v();*/

  return v_Result_b;
}

bool_t FpgaLayerEngine::setVehicleState_b(VehicleStateRequest_t i_VehicleState_t)
{
  bool_t v_Result_b;
  /*v_Result_b = (0 != memcmp(&vehicleState_t, &i_VehicleState_t, sizeof(VehicleStateRequest_t)));

  mutex_o.take_b();
  if(v_Result_b == true)
  {
    vehicleState_t = i_VehicleState_t;
  }
  mutex_o.give_v();*/

  return v_Result_b;
}

VehicleStateRequest_t FpgaLayerEngine::getVehicleState_t()
{/*
  mutex_o.take_b();
  VehicleStateRequest_t v_VehicleState_t = vehicleState_t;
  mutex_o.give_v();

  return v_VehicleState_t;
*/}

ScreenRequest_t FpgaLayerEngine::getScreenRequest_t()
{/*
  mutex_o.take_b();
  ScreenRequest_t v_ScreenRequest_t = screenRequest_t;
  mutex_o.give_v();

  return v_ScreenRequest_t;
*/}


bool_t FpgaLayerEngine::update_b()
{
  bool_t v_IsLayerUpdated_b = true;
/*
  if(lock_b() == true)
  {
    if((isLayerEngineEnabled_b == true))
    {
      MEP_BEGIN("update", "LayerEngine");
      for(uint32_t v_I_u32 = 0; v_I_u32 < c_LayerEngineLayerCount_u8; v_I_u32++)
      {
        if((isProcessingLayer_ab[v_I_u32] == true) && (isConfigLayerDone_ab[v_I_u32] == true))
        {
          if(v_I_u32 < e_OverlayLayer0)
          {
            wasProcessedLayer_ab[v_I_u32] = updateVideoLayer_b(cacheLayerConfig_as[v_I_u32]);
          }
          else
          {
            wasProcessedLayer_ab[v_I_u32] = updateOverlayLayer_b(cacheLayerConfig_as[v_I_u32]);
          }

          v_IsLayerUpdated_b = (v_IsLayerUpdated_b && wasProcessedLayer_ab[v_I_u32]);
        }
      }
    }
    else
    {
      v_IsLayerUpdated_b = false;
    }

    prevZoomFactor_u8 = screenRequest_t.ZoomFactor_u8;

    printLayer_v();

    unlock_b();

    MEP_END("update", "LayerEngine");
  }
  else
  {
    v_IsLayerUpdated_b = false;
  }*/

  return v_IsLayerUpdated_b;
}

bool_t FpgaLayerEngine::updateNonLock_b()
{
  bool_t v_IsLayerUpdated_b = true;
/*
  mutex_o.take_b();

  if((isLayerEngineEnabled_b == true))
  {
    MEP_BEGIN("update", "LayerEngine");
    for(uint32_t v_I_u32 = 0; v_I_u32 < c_LayerEngineLayerCount_u8; v_I_u32++)
    {
      if((isProcessingLayer_ab[v_I_u32] == true) && (isConfigLayerDone_ab[v_I_u32] == true))
      {
        if(v_I_u32 < e_OverlayLayer0)
        {
          wasProcessedLayer_ab[v_I_u32] = updateVideoLayer_b(cacheLayerConfig_as[v_I_u32]);
        }
        else
        {
          wasProcessedLayer_ab[v_I_u32] = updateOverlayLayer_b(cacheLayerConfig_as[v_I_u32]);
        }

        v_IsLayerUpdated_b = (v_IsLayerUpdated_b && wasProcessedLayer_ab[v_I_u32]);
      }
    }

    prevZoomFactor_u8 = screenRequest_t.ZoomFactor_u8;

    printLayer_v();

    MEP_END("update", "LayerEngine");
  }
  else
  {
    v_IsLayerUpdated_b = false;
  }

  mutex_o.give_v();*/

  return v_IsLayerUpdated_b;
}

void FpgaLayerEngine::free_v()
{/*
  mutex_o.take_b();

  for(uint32_t v_I_u32 = 0; v_I_u32 < c_LayerEngineLayerCount_u8; v_I_u32++)
  {
    if(wasProcessedLayer_ab[v_I_u32] == true)
    {
      isProcessingLayer_ab[v_I_u32] = false;
      isConfigLayerDone_ab[v_I_u32] = false;
      wasProcessedLayer_ab[v_I_u32] = false;
    }
  }

  mutex_o.give_v();
*/}

void FpgaLayerEngine::freeLayer_v(FpgaLayerID_e i_LayerID_e)
{/*
  mutex_o.take_b();
  wasProcessedLayer_ab[i_LayerID_e] = false;
  isProcessingLayer_ab[i_LayerID_e] = false;
  isConfigLayerDone_ab[i_LayerID_e] = false;
  mutex_o.give_v();
*/}

bool_t FpgaLayerEngine::isLayerConfigDone_b(bool_t i_All_b)
{
  bool_t v_Result_b = false;
  /*uint32_t v_ConfigDoneCount_u32 = 0U;
  uint32_t v_ProcessingCount_u32 = 0U;

  mutex_o.take_b();
  for(uint32_t v_I_u32 = 0; v_I_u32 < c_LayerEngineLayerCount_u8; v_I_u32++)
  {
    if(isConfigLayerDone_ab[v_I_u32] == true)
    {
      v_ConfigDoneCount_u32++;
    }

    if(isProcessingLayer_ab[v_I_u32] == true)
    {
      v_ProcessingCount_u32++;
    }
  }
  mutex_o.give_v();

  if(i_All_b == false)
  {
    if((v_ProcessingCount_u32 > 0)
    && (v_ConfigDoneCount_u32 == v_ProcessingCount_u32))
    {
      v_Result_b = true;
    }
  }
  else if(v_ConfigDoneCount_u32 == c_LayerEngineLayerCount_u8)
  {
    v_Result_b = true;
  }*/


  return v_Result_b;
}

FpgaLayerProcessState_e FpgaLayerEngine::isLayerProcessed_e()
{
  FpgaLayerProcessState_e v_Result_u32 = e_FlpsNoLayerProcessed;
  /*bool_t v_IsVideoLayerProcessed_b    = false;
  bool_t v_IsOverlayLayerProcessed_b  = false;

  mutex_o.take_b();
  for(uint32_t v_I_u32 = e_VideoLayer0; v_I_u32 <= e_VideoLayer2; v_I_u32++)
  {
    if(isProcessingLayer_ab[v_I_u32] == true)
    {
      v_IsVideoLayerProcessed_b = true;
    }
  }

  for(uint32_t v_I_u32 = e_OverlayLayer0; v_I_u32 <= e_OverlayLayer2; v_I_u32++)
  {
    if(isProcessingLayer_ab[v_I_u32] == true)
    {
      v_IsOverlayLayerProcessed_b = true;
    }
  }

  mutex_o.give_v();

  if(v_IsVideoLayerProcessed_b && v_IsOverlayLayerProcessed_b)
  {
    v_Result_u32 = e_FlpsAllLayerProcessed;
  }
  else if (v_IsVideoLayerProcessed_b == true)
  {
    if(isLayerConfigDone_b(false) == false)
    {
      v_Result_u32 = e_FlpsVideoLayerProcessed;
    }
  }
  else if (v_IsOverlayLayerProcessed_b == true)
  {
    if(isLayerConfigDone_b(false) == false)
    {
      v_Result_u32 = e_FlpsOverlayLayerProcessed;
    }
  }
  else
  {
    v_Result_u32 = e_FlpsNoLayerProcessed;
  }*/

  return v_Result_u32;
}

bool_t FpgaLayerEngine::isEnabled_b() const
{
  return isLayerEngineEnabled_b;
}

bool_t FpgaLayerEngine::isViewChangeConfigDone_b()
{
  bool_t v_AllLayerForView_b = true;
/*
  mutex_o.take_b();

  for(uint32_t v_I_u32 = 0; v_I_u32 < bsp::c_LayerEngineLayerCount_u8; v_I_u32++)
  {
    if((cacheLayerConfig_as[v_I_u32].viewID_t != screenRequest_t.ViewID_u8))
    {
      v_AllLayerForView_b = false;
    }
  }

  mutex_o.give_v();*/

  return v_AllLayerForView_b;
}

bool_t FpgaLayerEngine::enableLayerEngine_b(bool_t i_Enable_b)
{
  bool_t v_Result_b = false;
/*
  mutex_o.take_b();

  if(i_Enable_b == true)
  {
    v_Result_b = ME_IO_Out32_b(layerEngineCommon_pv, 0x0U, 0x1U);
  }
  else
  {
    v_Result_b = ME_IO_Out32_b(layerEngineCommon_pv, 0x0U, 0x0U);
  }

  if(v_Result_b == true)
  {
    isLayerEngineEnabled_b = i_Enable_b;
  }

  mutex_o.give_v();*/

  return v_Result_b;
}

bool_t FpgaLayerEngine::lock_b()
{
  bool_t v_Result_b = false;
  /*static const uint32_t c_MaxReTries_u32 = 33U;

  if(s_LockThreadID_t == ME_INVALID_PROCESS_ID)
  {
    if(lockMutex_o.take_b() == true)
    {
      s_LockDepth_u8 = 1;
      uint32_t v_Read_u32 = 0x00U;
      uint32_t v_ReTries_u32 = 0U;

      while((v_Result_b != true))
      {
        ME_IO_Out32_b(layerEngineBase_pv, 0x00U, 0x01U);
        ME_Thread_Sleep_t(1);
        ME_IO_In32_b(layerEngineBase_pv, 0x00U, &v_Read_u32);
        v_Result_b = (v_Read_u32 == 0x01U);

        v_ReTries_u32++;
        if(v_ReTries_u32 > c_MaxReTries_u32)
        {
          v_Result_b = false;
          break;
        }
      }

      if(false == v_Result_b)
      {
        s_LockDepth_u8 = 0;
        s_LockThreadID_t = ME_INVALID_PROCESS_ID;
        lockMutex_o.give_v();
      }
      else
      {
        mutex_o.take_b();
        s_LockThreadID_t = ME_Thread_GetCurrentID_t();
      }
    }
  }
  else if(s_LockThreadID_t == ME_Thread_GetCurrentID_t())
  {
    s_LockDepth_u8++;
    v_Result_b = true;
  }*/

  return v_Result_b;
}

bool_t FpgaLayerEngine::unlock_b()
{
  bool_t v_Result_b = false;
  /*static const uint32_t c_MaxReTries_u32 = 33U;

  if((s_LockThreadID_t == ME_Thread_GetCurrentID_t()) && (s_LockDepth_u8 == 1))
  {
    uint32_t v_Read_u32 = 0x00U;
    uint32_t v_ReTries_u32 = 0U;

    while((v_Result_b != true))
    {
      ME_IO_Out32_b(layerEngineBase_pv, 0x00U, 0x00U);
      ME_Thread_Sleep_t(1);
      ME_IO_In32_b(layerEngineBase_pv, 0x00U, &v_Read_u32);
      v_Result_b = ((v_Read_u32 & 0x01U) == 0x00U);

      v_ReTries_u32++;
      if(v_ReTries_u32 > c_MaxReTries_u32)
      {
        v_Result_b = false;
        break;
      }
    }

    if(true == v_Result_b)
    {
      s_LockDepth_u8 = 0;
      s_LockThreadID_t = ME_INVALID_PROCESS_ID;
      lockMutex_o.give_v();
      mutex_o.give_v();
    }
  }
  else if((s_LockThreadID_t == ME_Thread_GetCurrentID_t()) && s_LockDepth_u8 > 1)
  {
    s_LockDepth_u8--;
    v_Result_b = true;
  }*/

  return v_Result_b;
}

bool_t FpgaLayerEngine::configLayer_b(LayerConfig_s& i_LayerConfig_rs)
{
  bool_t v_Result_b = false;
  bool_t v_UpdateImm_b = false;

  /*// check, if we are still in view switching state
  bool_t v_AllLayerForView_b = isViewChangeConfigDone_b();

  mutex_o.take_b();

  // all layer are configured for view switch
  if(v_AllLayerForView_b == true)
  {
    if(i_LayerConfig_rs.viewID_t != screenRequest_t.ViewID_u8)
    {
      wasProcessedLayer_ab[i_LayerConfig_rs.layerID_e] = false;
      isProcessingLayer_ab[i_LayerConfig_rs.layerID_e] = false;
      isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] = false;

      mutex_o.give_v();

      return true;
    }
    else if((isProcessingLayer_ab[i_LayerConfig_rs.layerID_e] == true) && (isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] == false))
    {
      if(screenRequest_t.ZoomFactor_u8 != prevZoomFactor_u8)
      {
        if(NULL != memcpy(&cacheLayerConfig_as[i_LayerConfig_rs.layerID_e], &i_LayerConfig_rs, sizeof(LayerConfig_s)))
        {
          if(isOverlayLayer_b(i_LayerConfig_rs.layerID_e) || (i_LayerConfig_rs.layerID_e == e_OverlayLayer0))
          {
            cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].layerOffset_u32 = (i_LayerConfig_rs.layerID_e - c_AlphaLayerCount_u8) * ((1280 *720 * 4) / 1024); // Resolution * Channels /
          }

          isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] = true;

          s_Logger_o.log_b(logging::e_LogLvlInfo, "layer config (for viewswitch) %d - current view %d - viewid %d - bufferId %d\n",
                           i_LayerConfig_rs.layerID_e, screenRequest_t.ViewID_u8, cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].viewID_t,
                           cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].bufferID_u8);

          v_Result_b = true;
        }
      }
      else
      {
        v_UpdateImm_b = true;
      }
    }
  }
  // missing layers for view switch
  else
  {
    // this layer id was not configured and has valid view id
    if((i_LayerConfig_rs.viewID_t == screenRequest_t.ViewID_u8)
    && (cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].viewID_t != screenRequest_t.ViewID_u8))
    {
      if((isProcessingLayer_ab[i_LayerConfig_rs.layerID_e] == true) && (isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] == false))
      {
        if(NULL != memcpy(&cacheLayerConfig_as[i_LayerConfig_rs.layerID_e], &i_LayerConfig_rs, sizeof(LayerConfig_s)))
        {
          if(isOverlayLayer_b(i_LayerConfig_rs.layerID_e) || (i_LayerConfig_rs.layerID_e == e_OverlayLayer0))
          {
            cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].layerOffset_u32 = (i_LayerConfig_rs.layerID_e - c_AlphaLayerCount_u8) * ((1280 *720 * 4) / 1024); // Resolution * Channels /
          }

          isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] = true;

          s_Logger_o.log_b(logging::e_LogLvlInfo, "layer config (for viewswitch) %d - current view %d - viewid %d - bufferId %d\n",
                           i_LayerConfig_rs.layerID_e, screenRequest_t.ViewID_u8, cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].viewID_t, cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].bufferID_u8);

          v_Result_b = true;
        }
      }
    }
    else if((i_LayerConfig_rs.viewID_t != screenRequest_t.ViewID_u8)
    && (cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].viewID_t != screenRequest_t.ViewID_u8))
    {
      wasProcessedLayer_ab[i_LayerConfig_rs.layerID_e] = false;
      isProcessingLayer_ab[i_LayerConfig_rs.layerID_e] = false;
      isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] = false;

      mutex_o.give_v();
      return true;
    }
  }

  mutex_o.give_v();

  if(v_UpdateImm_b == true)
  {
    while(lock_b() != true);

    if(NULL != memcpy(&cacheLayerConfig_as[i_LayerConfig_rs.layerID_e], &i_LayerConfig_rs, sizeof(LayerConfig_s)))
    {
      if(isOverlayLayer_b(i_LayerConfig_rs.layerID_e) || (i_LayerConfig_rs.layerID_e == e_OverlayLayer0))
      {
        cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].layerOffset_u32 = (i_LayerConfig_rs.layerID_e - c_AlphaLayerCount_u8) * ((1280 *720 * 4) / 1024); // Resolution * Channels /
      }

      if(isOverlayLayer_b(i_LayerConfig_rs.layerID_e) || (i_LayerConfig_rs.layerID_e == e_OverlayLayer0))
      {
        updateOverlayLayer_b(cacheLayerConfig_as[i_LayerConfig_rs.layerID_e]);

        wasProcessedLayer_ab[i_LayerConfig_rs.layerID_e] = false;
        isProcessingLayer_ab[i_LayerConfig_rs.layerID_e] = false;
        isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] = false;
      }

      v_Result_b = true;
    }

    unlock_b();

    s_Logger_o.log_b(logging::e_LogLvlInfo, "layer config immediately %d - current view %d - viewid %d - bufferId %d\n",
                     i_LayerConfig_rs.layerID_e, screenRequest_t.ViewID_u8, cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].viewID_t,
                     cacheLayerConfig_as[i_LayerConfig_rs.layerID_e].bufferID_u8);
  }

  if(v_Result_b == true)
  {
    // don't swap buffers for 3D, buffer swap is handled in DataProviderOvl3D
    if (i_LayerConfig_rs.layerID_e != e_OverlayLayer0)
    {
      i_LayerConfig_rs.bufferID_u8 = ((i_LayerConfig_rs.bufferID_u8 + 1) % 2);
    }
  }
  else
  {
    wasProcessedLayer_ab[i_LayerConfig_rs.layerID_e] = false;
    isProcessingLayer_ab[i_LayerConfig_rs.layerID_e] = false;
    isConfigLayerDone_ab[i_LayerConfig_rs.layerID_e] = false;
  }*/

  return v_Result_b;
}

void* FpgaLayerEngine::getOverlayLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_BufferIdx_u8) const
{
  uint8_t* v_Buffer_pv = NULL;

  if(i_BufferIdx_u8 < c_OverlayBufferCount_u8)
  {
    v_Buffer_pv = reinterpret_cast<uint8_t*>(layerBuffer_apv[i_LayerID_e][i_BufferIdx_u8]);
  }

  return v_Buffer_pv;
}

void* FpgaLayerEngine::getAlphaLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_BufferIdx_u8) const
{
  uint8_t* v_Buffer_pv = NULL;

  if(i_BufferIdx_u8 < c_AlphaBufferCount_u8)
  {
    v_Buffer_pv = reinterpret_cast<uint8_t*>(layerBuffer_apv[i_LayerID_e][i_BufferIdx_u8]);
  }

  return v_Buffer_pv;
}

bool_t FpgaLayerEngine::getLayerConfig_b(FpgaLayerID_e i_LayerID_e, LayerConfig_s& o_LayerConfig_rs)
{
  bool_t v_Result_b = false;
  uint32_t v_Offset_u32 = 0x400U + (static_cast<uint8_t>(i_LayerID_e) << 6);

  uint32_t v_ReadVal_u32 = 0;

  if(lock_b() == true)
  {
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + ( 5 << 2), &v_ReadVal_u32);
    o_LayerConfig_rs.enable_b = static_cast<bool_t>(v_ReadVal_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + ( 6 << 2), &o_LayerConfig_rs.xPos_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + ( 7 << 2), &o_LayerConfig_rs.xSize_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + ( 8 << 2), &o_LayerConfig_rs.yPos_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + ( 9 << 2), &o_LayerConfig_rs.ySize_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + (10 << 2), &v_ReadVal_u32);
    o_LayerConfig_rs.alphaValue_u16 = static_cast<uint16_t>(v_ReadVal_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + (11 << 2), &o_LayerConfig_rs.xOffset_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + (12 << 2), &o_LayerConfig_rs.yOffset_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + (13 << 2), &v_ReadVal_u32);
    o_LayerConfig_rs.bufferID_u8 = static_cast<uint8_t>(v_ReadVal_u32);
    ME_IO_In32_b(layerEngineBase_pv, v_Offset_u32 + (14 << 2), &o_LayerConfig_rs.layerOffset_u32);

    unlock_b();

    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t FpgaLayerEngine::setLayerProcessed_b(FpgaLayerID_e i_LayerID_e)
{
  bool_t v_Result_b = false;
/*
  mutex_o.take_b();

  bool_t isVideoLayerProcessed_b =     ((isProcessingLayer_ab[e_VideoLayer0] == true) && (isConfigLayerDone_ab[e_VideoLayer0] == false))
                                    || ((isProcessingLayer_ab[e_VideoLayer1] == true) && (isConfigLayerDone_ab[e_VideoLayer1] == false))
                                    || ((isProcessingLayer_ab[e_VideoLayer2] == true) && (isConfigLayerDone_ab[e_VideoLayer2] == false));

  bool_t isOverlay0Processed_b =        (isProcessingLayer_ab[e_OverlayLayer0] == true) && (isConfigLayerDone_ab[e_OverlayLayer0] == false);

  bool_t isOverlay1and2Processed_b =   ((isProcessingLayer_ab[e_OverlayLayer1] == true) && (isConfigLayerDone_ab[e_OverlayLayer1] == false))
                                    || ((isProcessingLayer_ab[e_OverlayLayer2] == true) && (isConfigLayerDone_ab[e_OverlayLayer2] == false));

  v_Result_b = (isConfigLayerDone_ab[i_LayerID_e] == false) && (screenRequest_t.ViewID_u8 < variants::e_ViewIdCount);

  if((v_Result_b == true))
  {
    isProcessingLayer_ab[i_LayerID_e] = true;
  }
  else
  {
    s_Logger_o.log_b(logging::e_LogLvlInfo, "layer already configured %d\n", i_LayerID_e);
  }

  mutex_o.give_v();

  if(false == v_Result_b)
  {
    ME_Thread_Sleep_t(32);
  }*/

  return v_Result_b;
}

bool_t FpgaLayerEngine::updateVideoLayer_b(const LayerConfig_s& i_LayerConfig_rs) const
{
  uint32_t v_Offset_u32 = 0x400U + (static_cast<uint8_t>(i_LayerConfig_rs.layerID_e) << 6);

  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 5 << 2), i_LayerConfig_rs.enable_b);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 6 << 2), i_LayerConfig_rs.xPos_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 7 << 2), i_LayerConfig_rs.xPos_u32 + i_LayerConfig_rs.xSize_u32 - 1);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 8 << 2), i_LayerConfig_rs.yPos_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 9 << 2), i_LayerConfig_rs.yPos_u32 + i_LayerConfig_rs.ySize_u32 - 1);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (10 << 2), i_LayerConfig_rs.alphaValue_u16);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (11 << 2), i_LayerConfig_rs.xOffset_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (12 << 2), i_LayerConfig_rs.yOffset_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (13 << 2), i_LayerConfig_rs.bufferID_u8);

  return true;
}

bool_t FpgaLayerEngine::updateOverlayLayer_b(const LayerConfig_s& i_LayerConfig_rs) const
{
  uint32_t v_Offset_u32 = 0x400U + (static_cast<uint8_t>(i_LayerConfig_rs.layerID_e) << 6);

  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 5 << 2), i_LayerConfig_rs.enable_b);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 6 << 2), i_LayerConfig_rs.xPos_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 7 << 2), i_LayerConfig_rs.xPos_u32 + i_LayerConfig_rs.xSize_u32 - 1);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 8 << 2), i_LayerConfig_rs.yPos_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + ( 9 << 2), i_LayerConfig_rs.yPos_u32 + i_LayerConfig_rs.ySize_u32 - 1);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (10 << 2), i_LayerConfig_rs.alphaValue_u16);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (11 << 2), i_LayerConfig_rs.xOffset_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (12 << 2), i_LayerConfig_rs.yOffset_u32);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (13 << 2), i_LayerConfig_rs.bufferID_u8);
  ME_IO_Out32_b(layerEngineBase_pv, v_Offset_u32 + (14 << 2), i_LayerConfig_rs.layerOffset_u32);

  return true;
}

void FpgaLayerEngine::printLayer_v()
{
  s_Logger_o.log_b(logging::e_LogLvlInfo, "Fpga Layer\n");
  s_Logger_o.log_b(logging::e_LogLvlInfo, "-----------------------------------------------------------------------------\n");
  bsp::LayerConfig_s v_LayerConfig_s;
  for(uint32_t v_I_u32 = 0; v_I_u32 < bsp::c_LayerEngineLayerCount_u8; v_I_u32++)
  {
    getLayerConfig_b(static_cast<bsp::FpgaLayerID_e>(v_I_u32), v_LayerConfig_s);
    s_Logger_o.log_b(logging::e_LogLvlInfo, "ID [%d], Buf [%d], En [%d], xP [%d], xS [%d], xO [%d], yP [%d], yS [%d], yO [%d], alpha [%d], offsetKb [0x%x]\n"
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
}


} // namespace bsp

#endif // ME_PLATFORM_QNX

