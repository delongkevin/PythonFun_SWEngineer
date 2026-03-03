//--------------------------------------------------------------------------
/// @file FpgaLayerEngine_AUTOSAR.cpp
/// @brief Implementation of AUTOSAR Fpga layer engine interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------


#include "bsp/io/fpga/FpgaLayerEngine.h"


#ifdef ME_PLATFORM_RTOS

namespace bsp
{

static uint8_t v_LayerBuffer_aau8[c_LayerEngineLayerCount_u8][2][2048*2048];

FpgaLayerEngine::FpgaLayerEngine()
  : isLayerEngineEnabled_b(false)
  , layerEngineCommon_pv(NULL)
  , layerEngineBase_pv(NULL)
{
  for(uint32_t v_I_u32 = 0; v_I_u32 < c_AlphaLayerCount_u8; v_I_u32++)
  {
    layerBuffer_apv[v_I_u32][0] = v_LayerBuffer_aau8[v_I_u32][0];
    layerBuffer_apv[v_I_u32][1] = v_LayerBuffer_aau8[v_I_u32][1];
  }
}

FpgaLayerEngine::~FpgaLayerEngine()
{

}

bool_t FpgaLayerEngine::setScreenRequest_b(ScreenRequest_t i_ScreenRequest_t)
{
  screenRequest_t = i_ScreenRequest_t;
  return true;
}

bool_t FpgaLayerEngine::setVehicleState_b(VehicleStateRequest_t i_VehicleState_t)
{
  vehicleState_t = i_VehicleState_t;
  return true;
}

ScreenRequest_t FpgaLayerEngine::getScreenRequest_t()
{
  return screenRequest_t;
}

VehicleStateRequest_t FpgaLayerEngine::getVehicleState_t()
{
  return vehicleState_t;
}

bool_t FpgaLayerEngine::update_b()
{
  return true;
}

bool_t FpgaLayerEngine::updateNonLock_b()
{
  return true;
}

void FpgaLayerEngine::free_v()
{

}


void FpgaLayerEngine::freeLayer_v(FpgaLayerID_e i_LayerID_e)
{
}

bool_t FpgaLayerEngine::initLayerEngine_b()
{
  bool_t v_Result_b = true;

  for(uint32_t v_I_u32 = 0; v_I_u32 < c_AlphaLayerCount_u8; v_I_u32++)
  {
    memset(v_LayerBuffer_aau8[v_I_u32][0], 0x80, sizeof(v_LayerBuffer_aau8[v_I_u32][0]));
    memset(v_LayerBuffer_aau8[v_I_u32][1], 0x80, sizeof(v_LayerBuffer_aau8[v_I_u32][1]));
  }

  return v_Result_b;
}

bool_t FpgaLayerEngine::getLayerConfig_b(FpgaLayerID_e i_LayerId_e, LayerConfig_s& o_LayerConfig_rs)
{
  o_LayerConfig_rs = cacheLayerConfig_as[i_LayerId_e];

  return true;
}

bool_t FpgaLayerEngine::setLayerProcessed_b(FpgaLayerID_e i_LayerID_e)
{
  return (isProcessingLayer_ab[i_LayerID_e] = true);
}

bool_t FpgaLayerEngine::isEnabled_b() const
{
  return isLayerEngineEnabled_b;
}

bool_t FpgaLayerEngine::isLayerConfigDone_b(bool_t i_All_b)
{
  return true;
}

FpgaLayerProcessState_e FpgaLayerEngine::isLayerProcessed_e()
{
  return e_FlpsNoLayerProcessed;
}

bool_t FpgaLayerEngine::enableLayerEngine_b(bool_t i_Enable_b)
{
  isLayerEngineEnabled_b = true;
  return true;
}

bool_t FpgaLayerEngine::lock_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t FpgaLayerEngine::unlock_b()
{
  return true;
}

bool_t FpgaLayerEngine::configLayer_b(LayerConfig_s& i_LayerConfig_rs)
{
  cacheLayerConfig_as[i_LayerConfig_rs.layerID_e] = i_LayerConfig_rs;

  i_LayerConfig_rs.bufferID_u8 ^= 1;

  return true;
}

void* FpgaLayerEngine::getOverlayLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_Buffer_u8) const
{
  static uint8_t v_Buffer_au8[c_OverlayLayerCount_u8][c_OverlayBufferCount_u8][0x400000];
  return reinterpret_cast<void*>(&v_Buffer_au8[i_LayerID_e-3U][i_Buffer_u8][0]);
}

void* FpgaLayerEngine::getAlphaLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_Buffer_u8) const
{
  return v_LayerBuffer_aau8[i_LayerID_e][i_Buffer_u8];
}

} // namespace bsp

#endif // ME_PLATFORM_AUTOSAR

