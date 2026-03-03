//--------------------------------------------------------------------------
/// @file FpgaLayerEngineDefines.cpp
/// @brief Defines Fpga layer engine interface 
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_LAYER_ENGINE_DEFINES_H_
#define FPGA_LAYER_ENGINE_DEFINES_H_

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

namespace bsp
{


enum LayerType_e
{
  e_LayerTypeVideo = 0,
  e_LayerTypeOverlay,
  e_LayerTypeAnalog,
  e_LayerTypeCount,
  e_LayerTypeInvalid
};

enum FpgaLayerID_e
{
  e_VideoLayer0 = 0,
  e_VideoLayer1,
  e_VideoLayer2,
  e_OverlayLayer0,
  e_OverlayLayer1,
  e_OverlayLayer2,
  e_LayerIdCount,
  e_LayerIdInvalid
};

enum FpgaLayerProcessState_e
{
  e_FlpsNoLayerProcessed = 0,
  e_FlpsVideoLayerProcessed,
  e_FlpsOverlayLayerProcessed,
  e_FlpsAllLayerProcessed,
  e_FlpsCount,
  e_FlpsInvalid
};

struct LayerConfig_s
{
  FpgaLayerID_e      layerID_e;
  uint8_t            bufferID_u8;
  uint16_t           alphaValue_u16;
  bool_t             enable_b;
  uint32_t           xPos_u32;
  uint32_t           yPos_u32;
  uint32_t           xSize_u32;
  uint32_t           ySize_u32;
  uint32_t           xOffset_u32;
  uint32_t           yOffset_u32;
  uint32_t           layerOffset_u32; // overlays only
  variants::ViewId_t viewID_t;

  LayerConfig_s()
  : layerID_e(e_LayerIdInvalid)
  , bufferID_u8(0)
  , alphaValue_u16(0)
  , enable_b(0)
  , xPos_u32(0)
  , yPos_u32(0)
  , xSize_u32(0)
  , ySize_u32(0)
  , xOffset_u32(0)
  , yOffset_u32(0)
  , layerOffset_u32(0)
  , viewID_t(variants::e_ViewIdInvalid)
  {
  }

  LayerConfig_s(FpgaLayerID_e i_LayerID_e, uint32_t i_XPos_u32, uint32_t i_YPos_u32, uint32_t i_XSize_u32, uint32_t i_YSize_u32,
                bool_t i_Enable_b, uint8_t i_BufferID_u8, uint16_t i_AlphaValue_u16, uint32_t i_XOffset_u32, uint32_t i_YOffset_u32)
    : layerID_e(i_LayerID_e)
    , bufferID_u8(i_BufferID_u8)
    , alphaValue_u16(i_AlphaValue_u16)
    , enable_b(i_Enable_b)
    , xPos_u32(i_XPos_u32)
    , yPos_u32(i_YPos_u32)
    , xSize_u32(i_XSize_u32)
    , ySize_u32(i_YSize_u32)
    , xOffset_u32(i_XOffset_u32)
    , yOffset_u32(i_YOffset_u32)
    , layerOffset_u32(0)
    , viewID_t(variants::e_ViewIdInvalid)
  {

  }

  LayerConfig_s(FpgaLayerID_e i_LayerID_e, uint32_t i_XPos_u32, uint32_t i_YPos_u32, uint32_t i_XSize_u32, uint32_t i_YSize_u32,
                bool_t i_Enable_b, uint8_t i_BufferID_u8, uint16_t i_AlphaValue_u16, uint32_t i_LayerOffset_u32)
    : layerID_e(i_LayerID_e)
    , bufferID_u8(i_BufferID_u8)
    , alphaValue_u16(i_AlphaValue_u16)
    , enable_b(i_Enable_b)
    , xPos_u32(i_XPos_u32)
    , yPos_u32(i_YPos_u32)
    , xSize_u32(i_XSize_u32)
    , ySize_u32(i_YSize_u32)
    , xOffset_u32(0)
    , yOffset_u32(0)
    , layerOffset_u32(i_LayerOffset_u32)
    , viewID_t(variants::e_ViewIdInvalid)
  {

  }
};



} // namespace bsp



#endif // FPGA_LAYER_ENGINE_DEFINES_H_
