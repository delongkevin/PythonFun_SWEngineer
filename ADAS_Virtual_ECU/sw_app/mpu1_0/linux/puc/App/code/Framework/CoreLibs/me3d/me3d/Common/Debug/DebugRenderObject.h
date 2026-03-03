//--------------------------------------------------------------------------                                                                                                           
/// @file DebugRenderObject.h                                                                         
/// @brief Simple Debug Object holding Vertex-, IndexBuffers, Color and world Matrix
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEBUG_RENDER_OBJECT_H
#define DEBUG_RENDER_OBJECT_H

#include "Common/Device/Device3DTypes.h"
#include "MeclTypeDefs.h"
#include "Math/Color.h"

namespace me3d
{
  class VertexBuffer;
  class IndexBuffer;
  class RenderEngine;
}

namespace me3d
{

class DebugRenderObject
{
public:
  DebugRenderObject();
  ~DebugRenderObject();

  void release_v(const RenderEngine* i_RenEng_po);  
  void releaseVertexBuffer_v(const RenderEngine* i_RenEng_po);
  void releaseIndexBuffer_v(const RenderEngine* i_RenEng_po);
  
  void fillVertexBuffer_v(const RenderEngine* i_RenEng_po, const float32_t* i_Vertices_pf32, uint32_t i_NumVertices_u32);
  void fillIndexBuffer_v(const RenderEngine* i_RenEng_po, const uint16_t* i_Indices_pu16, uint32_t i_NumIndices_u32);

  void setParams_v(const Matrix4f& i_World_ro, const Color& i_Color_ro, PrimitiveType_e i_PrimType_e);

  inline VertexBuffer*    getVertexBuffer_po() const { return vertexBuffer_po; }
  inline IndexBuffer*     getIndexBuffer_po()  const { return indexBuffer_po;  }
  inline uint32_t         getNumVertices_u32() const { return numVertices_u32; }
  inline uint32_t         getNumIndices_u32()  const { return numIndices_u32;  }
  inline PrimitiveType_e  getPrimitiveTye_e()  const { return primitiveType_e; }
  inline const Color&     getColor_ro()        const { return color_o;         }
  inline const Matrix4f&  getWorldMatrix_ro()  const { return world_o;         }

private:
  VertexBuffer*   vertexBuffer_po;
  IndexBuffer*    indexBuffer_po;
  uint32_t        numVertices_u32;
  uint32_t        numIndices_u32;
  PrimitiveType_e primitiveType_e;
  Matrix4f        world_o;
  Color           color_o;

};

} // namespace me3d

#endif
