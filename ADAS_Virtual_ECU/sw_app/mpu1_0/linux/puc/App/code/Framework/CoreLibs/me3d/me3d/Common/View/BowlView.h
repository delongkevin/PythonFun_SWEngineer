//--------------------------------------------------------------------------                                                                                                           
/// @file BowlView.h                                                                         
/// @brief BowlView class Projects Camera Images on the Bowl surface on the GPU.
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BOWL_VIEW_H
#define BOWL_VIEW_H

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


class BowlView : public BaseBowlView
{
public:
  BowlView();
  virtual ~BowlView();

  bool_t           create_b(const BowlViewDesc_s& i_Desc_rs, RenderEngine* b_RenderEngine_po);

  virtual void     release_v() ME_OVERRIDE;

  VertexBowlView_s* getVertex_ps(float32_t i_X_f32, float32_t i_Z_f32);
  bool             getHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t& o_Height_rf32);
  virtual bool_t   setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32) ME_OVERRIDE;
  virtual bool_t   intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro) ME_OVERRIDE;

  virtual void     render_v() ME_OVERRIDE;

  virtual void     createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b) ME_OVERRIDE;



  virtual void     update_v(uint32_t i_Flags_u32) ME_OVERRIDE;


  Matrix4f getCameraTransform_o(RealCamera_e i_Camera_e) const;
  Matrix3f getCameraPolyWorld2Image_o(RealCamera_e i_Camera_e) const;
  Vector4f getPrincipalPointAndPixelSize_o(RealCamera_e i_Camera_e) const;


protected:
  static Shaders_e getShader_e();
  void createStitching_v();

private:
  void      updateConstants_v();
  void      createVertices_v();
  void      createIndices_v();

protected:
  uint32_t indexCount_u32;

  EffectFile* effect_po;
  VertexBuffer* vertexBuffer_po;
  IndexBuffer*  indexBuffer_po;

  Constant*           constantWVP_po;
  Constant*           constantTex0_po;
  Constant*           constantTex1_po;
  Constant*           constantTex2_po;
  Constant*           constantTex3_po;
  Constant*           constantRealCamTransLeft_po;
  Constant*           constantRealCamTransRight_po;
  Constant*           constantRealCamTransFront_po;
  Constant*           constantRealCamTransRear_po;
  Constant*           constantW2iPolyLeft_po;
  Constant*           constantW2iPolyRight_po;
  Constant*           constantW2iPolyFront_po;
  Constant*           constantW2iPolyRear_po;
  Constant*           constantPppPszLeft_po;
  Constant*           constantPppPszRight_po;
  Constant*           constantPppPszRear_po;
  Constant*           constantPppPszFront_po;
  Constant*           constantImageSizeProjScale_po;
  Constant*           constantDimsAndCoordOffset_po;
  VertexBowlView_s*   vertices_as;
  uint16_t*           indices_au16;
};

} // namespace me3d

#endif
