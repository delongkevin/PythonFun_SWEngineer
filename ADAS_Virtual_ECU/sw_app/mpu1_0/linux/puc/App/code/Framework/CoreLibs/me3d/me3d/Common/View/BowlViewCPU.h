//--------------------------------------------------------------------------                                                                                                           
/// @file BowlViewCPU.h                                                                         
/// @brief BowlView class Projects Camera Images on the Bowl surface on the CPU.
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BOWL_VIEW_CPU_H
#define BOWL_VIEW_CPU_H

#include <mecl/model/Camera.h>

#include "MeclTypeDefs.h"
#include "Math/Transform.h"
#include "Common/Resources/Constant.h"
#include "Common/Resources/VertexDeclarationTypes.h"
#include "Common/View/BaseBowlView.h"
#include "Common/Manager/ShaderManager.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

class EffectFile;
class ITextureConstantData;
class VertexBuffer;
class IndexBuffer;
class RenderEngine;
class EffectFileRenderStateBlock;

struct BowlSegment_s
{
  Cameraf*              realCamera_po;
  VertexBuffer*         vertexBuffer_po;
  IndexBuffer*          indexBuffer_po;
  uint32_t              indexCount_u32;
  BBox2D_s              bounds_o;
  VertexBowlViewCPU_s*  vertices_as;
  uint16_t*             indices_au16;

  BowlSegment_s()
    : realCamera_po(NULL)
    , vertexBuffer_po(NULL)
    , indexBuffer_po(NULL)
    , indexCount_u32(0)
    , bounds_o()
    , vertices_as(NULL)
    , indices_au16(NULL)
  {

  }
};

struct ObscurationZone_s
{
  static const uint32_t   c_NumObscurationVertices_u32 = 6U;
  BBox2D_s                bounds_s;
  VertexBuffer*           vertexBuffer_po;
  EffectFile*             effect_po;
  Constant*               constantGuideLineWVP_po;
  Constant*               constantColor_po;
  VertexPos_s             vertices_as[c_NumObscurationVertices_u32];

  ObscurationZone_s()
    : bounds_s()
    , vertexBuffer_po(NULL)
    , effect_po(NULL)
    , constantGuideLineWVP_po(NULL)
    , constantColor_po(NULL)
  {
  }

};

class BowlViewCPU : public BaseBowlView
{
public:
  BowlViewCPU();
  virtual ~BowlViewCPU();

  bool_t create_b(const BowlViewDesc_s& i_Desc_rs, RenderEngine* b_RenderEngine_po, EffectFileRenderStateBlock* i_RSBAlpha_po, EffectFileRenderStateBlock* i_RSBNoDepth_po);
  virtual void release_v() ME_OVERRIDE;

  static VertexBowlViewCPU_s* getVertex_ps(float32_t i_X_f32, float32_t i_Z_f32);
  static bool getHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t& o_Height_rf32);
  virtual bool_t setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32) ME_OVERRIDE;
  virtual bool_t intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro) ME_OVERRIDE;

  virtual void render_v() ME_OVERRIDE;

  virtual void createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b) ME_OVERRIDE;
  virtual void update_v(uint32_t i_Flags_u32) ME_OVERRIDE;

  virtual const BBox2D_s& getObscurationZone_rs() const ME_OVERRIDE;
  virtual void setObscurationZone_v(const BBox2D_s& i_Bounds_rs) ME_OVERRIDE;




protected:
  static Shaders_e getShader_e();
  void createStitching_v();

private:
  void createVertices_v();
  void createIndices_v();
  void createTexCoords_v();
  void createObscurationZone_v(bool_t i_GenerateBounds_b);

protected:
  EffectFile*                   effect_po;
  EffectFileRenderStateBlock*   renderStateAlphaBlend_po;
  EffectFileRenderStateBlock*   renderStateDisableDepth_po;
  Constant*                     constantWVP_po;
  Constant*                     constantTex0_po;
  Constant*                     constantTex1_po;
  Constant*                     constantTex2_po;
  Constant*                     constantTex3_po;
  BowlSegment_s                 segments_as[e_RcCount];
  ObscurationZone_s             obscurationZone_s;
};

} // namespace me3d

#endif
