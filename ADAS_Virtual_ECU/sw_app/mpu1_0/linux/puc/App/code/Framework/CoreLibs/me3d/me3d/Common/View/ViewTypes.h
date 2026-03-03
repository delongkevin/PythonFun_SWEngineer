//--------------------------------------------------------------------------                                                                                                           
/// @file ViewTypes.h                                                                         
/// @brief Defines all the Types used in View class
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 1120 EOF // we are using c++14 autsoar standard, scoped enumarations are legit.

#ifndef VIEW_TYPES_H
#define VIEW_TYPES_H

#include <platform/PlatformAPI.h>
#include "MeclCfg.h"
#include "Math/BBox2D.h"
#include "Math/Line2D.h"

namespace me3d
{

class Texture;
struct TextureResource_s;

enum BowlViewType_e
{
  e_BvtBowl = 0,   // Camera Surround View System ( 4 cameras ), Projection Calculated on GPU
  e_BvtBowlCPU,    // Projection Calculated on CPU
  e_BvtCount       // Count / Invalid
};

enum RealCamera_e
{
  e_RcLeft = 0,
  e_RcRight,
  e_RcFront, 
  e_RcRear,
  e_RcCount
};

enum StitchingArea_e
{
  e_SaFrontLeft = 0,
  e_SaFrontRight,
  e_SaRearLeft,
  e_SaRearRight,
  e_SaCount
};

enum ViewUpdateFlag_e : uint32_t
{
  e_VufConstants            = 1 << 0, // 0000 0000 0000 0000 0000 0000 0000 0001
  e_VufVertices             = 1 << 1, // 0000 0000 0000 0000 0000 0000 0000 0010
  e_VufIndices              = 1 << 2, // 0000 0000 0000 0000 0000 0000 0000 0100
  e_VufCamBounds            = 1 << 3, // 0000 0000 0000 0000 0000 0000 0000 1000
  e_VufDefaultStitching     = 1 << 4, // 0000 0000 0000 0000 0000 0000 0001 0000
  e_VufStitching            = 1 << 5, // 0000 0000 0000 0000 0000 0000 0010 0000
  e_VufResizeBuffers        = 1 << 6, // 0000 0000 0000 0000 0000 0000 0100 0000
  e_VufDefaultObscuration   = 1 << 7, // 0000 0000 0000 0000 0000 0000 1000 0000

  e_VufAll = e_VufConstants | e_VufVertices | e_VufIndices | e_VufCamBounds | e_VufDefaultStitching | e_VufStitching | e_VufResizeBuffers | e_VufDefaultObscuration
};

enum BowlDeformationMethod_e : uint32_t
{
  e_BdmEllipseParameters,
  e_BdmEllipseSpline,
  e_BdmTwoSplines
};

struct StitchingArea_s
{
  BBox2D_s bounds_o;
  Line2D   line0_o;
  Line2D   line1_o;
};

struct BowlViewDesc_s
{
  BowlViewType_e type_e;
  float32_t imageWidth_f32;
  float32_t imageHeight_f32;
  float32_t ellipseA_f32;
  float32_t ellipseB_f32;
  float32_t ellipseK_f32;
  bool useHeightMap_b;
  float32_t heightScale_f32;
  float32_t frontAxisOffsetX_f32;
  float32_t frontAxisOffsetY_f32;
  Vector3f  projectionScale_o;

  uint32_t xlength_u32;
  uint32_t ylength_u32;

  Vector3f controlPointLeftRight0_o;
  Vector3f controlPointLeftRight1_o;
  Vector3f controlPointLeftRight2_o;
  Vector3f controlPointLeftRight3_o;

  Vector3f controlPointFrontRear0_o;
  Vector3f controlPointFrontRear1_o;
  Vector3f controlPointFrontRear2_o;
  Vector3f controlPointFrontRear3_o;

  BowlDeformationMethod_e bowlDeformationMethod_e;


  Texture* textures_apo[e_RcCount];
  Cameraf* realCams_apo[e_RcCount];

  BowlViewDesc_s()
    : type_e(e_BvtBowlCPU)
    , imageWidth_f32(1280.0F)
    , imageHeight_f32(800.0F)
    , ellipseA_f32(25.0F)
    , ellipseB_f32(40.0F)
    , ellipseK_f32(100.0F)
    , useHeightMap_b(false)
    , heightScale_f32(1.0F)
    , frontAxisOffsetX_f32(0.0F)
    , frontAxisOffsetY_f32(0.0F)
    , projectionScale_o(17000.0F, 17000.0F, 17000.0F)
    , xlength_u32(128U)
    , ylength_u32(128U)
    , controlPointLeftRight0_o(0.0F,    40.0F, 0.0F)
    , controlPointLeftRight1_o(40.0F,    0.0F, 0.0F)
    , controlPointLeftRight2_o(130.0F,  40.0F, 0.0F)
    , controlPointLeftRight3_o(20.0F,  260.0F, 0.0F)
    , controlPointFrontRear0_o(0.0F,    40.0F, 0.0F)
    , controlPointFrontRear1_o(40.0F,    0.0F, 0.0F)
    , controlPointFrontRear2_o(130.0F,  40.0F, 0.0F)
    , controlPointFrontRear3_o(20.0F,  260.0F, 0.0F)
    , bowlDeformationMethod_e(e_BdmEllipseParameters)
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < static_cast<uint32_t>(e_RcCount); ++v_I_u32)
    {
      textures_apo[v_I_u32]  = NULL;
      realCams_apo[v_I_u32]  = NULL;
    }
  }
};

struct SingleViewDesc_s
{
  float32_t width_f32;
  float32_t height_f32;

  uint32_t numVerticesX_u32;
  uint32_t numVerticesY_u32;

  Texture* texture_po;
  Cameraf* realCam_po;
  Cameraf* syntCam_po;

  SingleViewDesc_s()
    : width_f32(512.0F)
    , height_f32(512.0F)
    , numVerticesX_u32(32U)
    , numVerticesY_u32(32U)
    , texture_po(NULL)
    , realCam_po(NULL)
    , syntCam_po(NULL)
  {
  }
};

} // namespace me3d



#endif
