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


#ifdef ME_PLATFORM_AUTOSAR

namespace bsp
{

  static uint8_t v_LayerBuffer_aau8[c_LayerEngineLayerCount_u8][2][2048*2048];

  FpgaLayerEngine::FpgaLayerEngine()
    : layerEngineCommon_pv(NULL)
    , layerEngineBase_pv(NULL)
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < c_AlphaLayerCount_u8; v_I_u32++)
    {
      layerBuffer_apv[v_I_u32][0] = NULL;
      layerBuffer_apv[v_I_u32][1] = NULL;
    }
  }

  FpgaLayerEngine::~FpgaLayerEngine()
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


  bool_t FpgaLayerEngine::isEnabled_b()
  {
    return isLayerEngineEnabled_b;
  }

  bool_t FpgaLayerEngine::enableLayerEngine_b(bool_t i_Enable_b)
  {
    isLayerEngineEnabled_b = true;
    return true;
  }

  bool_t FpgaLayerEngine::lockLayerEngine_b(bool_t i_Lock_b)
  {
    bool_t v_Result_b = true;

    return v_Result_b;
  }

  bool_t FpgaLayerEngine::configVideoLayer_b(const LayerConfig_s& i_LayerConfig_rs)
  {
    return true;
  }

  bool_t FpgaLayerEngine::configOverlayLayer_b(const LayerConfig_s& i_LayerConfig_rs)
  {
    return true;
  }

  void FpgaLayerEngine::configVideoLayerDone_v()
  {
    isConfigVideoLayerDone_b = true;
  }

  void* FpgaLayerEngine::getOverlayLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_Buffer_u8)
  {
    static uint8_t v_Buffer_au8[1280*720*4];

    return reinterpret_cast<void*>(v_Buffer_au8);
  }

  void* FpgaLayerEngine::getAlphaLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_Buffer_u8)
  {
    return v_LayerBuffer_aau8[i_LayerID_e][i_Buffer_u8];
  }

} // namespace bsp

#endif // ME_PLATFORM_AUTOSAR

