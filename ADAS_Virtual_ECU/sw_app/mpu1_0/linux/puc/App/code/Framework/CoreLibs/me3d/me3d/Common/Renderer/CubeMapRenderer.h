//--------------------------------------------------------------------------                                                                                                           
/// @file CubeMapRenderer.h                                                                         
/// @brief Use 6 Texture to render a cube map.
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef CUBEMAP_RENDERER_H
#define CUBEMAP_RENDERER_H

#include "Common/Renderer/IRenderer.h"
#include "Common/Resources/Constant.h"
#include "MeclTypeDefs.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{
  class Texture;
  class ITextureConstantData;
  class EffectFile;
  class VertexBuffer;
  struct VertexPos_s;
}

namespace me3d
{

const uint32_t c_NumCubeMapPrimitives_u32 = 36U;

class CubeMapRenderer : public IRenderer
{
public:
  CubeMapRenderer();
  virtual ~CubeMapRenderer();

  // IRenderer
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   reset_v();

  void render_v()const;

  bool createCubeMap_b(const MEString& i_FileName_ro);

private:
  static void createCube_v(VertexPos_s* b_Vertices_ps, float32_t i_Extents_f32);


private:
  RenderEngine*  renderEngine_po;
  Constant*      constantCubeMapWVP_po;
  Constant*      constantCubeMap_po;
  EffectFile*    cubeMapEffect_po;
  Texture*       cubeMap_po;
  VertexBuffer*  vertexBuffer_po;
};

} // namespace me3d

#endif
