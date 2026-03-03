#ifndef ME3D_MESH_H
#define ME3D_MESH_H

#include "Common/Materials/Material.h"
#include "Common/Model/ModelTypes.h"
#include "Math/BBox3D.h"

namespace me3d
{
  class RenderEngine;
}

namespace me3d
{
  class Mesh
  {
  public:
    Mesh();
    ~Mesh();


    void init_v(RenderEngine* b_RenderEngine_po, const MeshData_s& i_MeshData_rs);

    void release_v();

    // set material and vertex/indexbuffer
    void set_v()const;

    // getter
    ME_INLINE uint32_t        getIndicesCount_u32() const { return indexCount_u32; }
    ME_INLINE const BBox3D_s& getBounds_ro()        const { return bounds_s; }

  private:
    RenderEngine*               renderEngine_po;
    VertexBuffer*               vertexBuffer_po;
    IndexBuffer*                indexBuffer_po;
    uint32_t                    vertexCount_u32;
    uint32_t                    indexCount_u32;
    BBox3D_s                    bounds_s;
  };


} // namespace me3d

#endif
