#ifndef ME3D_GUIDE_LINE_OBJECT_H
#define ME3D_GUIDE_LINE_OBJECT_H

#include "MeclTypeDefs.h"
#include "Common/GuideLine/GuideLineTypes.h"
#include "Common/Resources/Constant.h"

namespace me3d
{
  class VertexBuffer;
  class IndexBuffer;
  class RenderEngine;
  struct VertexPos_s;

  class GuideLineObject
  {

  public:
    GuideLineObject();
    ~GuideLineObject();

    bool_t create_b(RenderEngine* b_RenEng_po, const GuideLineObjectDesc_s& i_Desc_rs);
    void   release_v();  

    bool_t update_b(uint32_t i_Flags_u32);
    bool_t updatePath_b(const mepl::vector<Vector3f>& i_Path_ro);

    ME_INLINE VertexBuffer*    getVertexBuffer_po() const { return vertexBuffer_po;       }
    ME_INLINE IndexBuffer*     getIndexBuffer_po()  const { return indexBuffer_po;        }
    ME_INLINE uint32_t         getNumVertices_u32() const { return desc_s.path_ao.size(); }
    ME_INLINE uint32_t         getIndexCount_u32()  const { return indexCount_u32;        }
    ME_INLINE const BBox3D_s&  getBounds_ro()       const { return bounds_s;              }

    // get / set color
    ME_INLINE const Color&     getColor_ro() const                 { return desc_s.color_o;       }
    ME_INLINE void             setColor_v(const Color& i_Color_ro) { desc_s.color_o = i_Color_ro; }

    // get / set World Matrix
    ME_INLINE const Matrix4f&  getWorldMatrix_ro() const                    { return desc_s.world_o;       }
    ME_INLINE void             setWorldMatrix_v(const Matrix4f& i_World_ro) { desc_s.world_o = i_World_ro; }

    ME_INLINE bool             getUseOrthoProj_b() const                    { return desc_s.useOrthoProj_b; }
    ME_INLINE void             setUseOrthoProj_v(bool i_UseOrthoProj_b)     { desc_s.useOrthoProj_b = i_UseOrthoProj_b; }

  private:
    void createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b);
    void createVertices_v();
    void createIndices_v();

  private:
    RenderEngine*         renderEngine_po;
    VertexBuffer*         vertexBuffer_po;
    IndexBuffer*          indexBuffer_po;
    uint16_t*             indices_au16;
    VertexPos_s*          vertices_as;
    uint32_t              indexCount_u32;
    BBox3D_s              bounds_s;
    GuideLineObjectDesc_s desc_s;

  };
} // namespace me3d

#endif // ME3D_GUIDE_LINE_OBJECT_H