#ifndef ME3D_GUIDE_LINE_TYPES_H
#define ME3D_GUIDE_LINE_TYPES_H

#include "Math/Color.h"
#include "Math/BBox3D.h"

namespace me3d
{
  struct GuideLineObjectDesc_s
  {
    bool_t                  useOrthoProj_b;
    Matrix4f                world_o;     ///< Transformation Matrix
    Color                   color_o;     ///< Guide Line Color
    mepl::vector<Vector3f>  path_ao;     ///< Guide Line Polygon Path in OpenGL Coordinates 
  };

  enum GuideLineUpdateFlag_e
  {
    e_GlufVertices        = 1 << 0, // 0000 0000 0000 0000 0000 0000 0000 0001
    e_GlufIndices         = 1 << 1, // 0000 0000 0000 0000 0000 0000 0000 0010
    e_GlufConstants       = 1 << 2, // 0000 0000 0000 0000 0000 0000 0000 0100
    e_GlufResizeBuffers   = 1 << 3, // 0000 0000 0000 0000 0000 0000 0000 1000

    e_GlufAll             = e_GlufVertices | e_GlufIndices | e_GlufConstants | e_GlufResizeBuffers
  };


} // namespace me3d

#endif // ME3D_GUIDELINE_TYPES_H