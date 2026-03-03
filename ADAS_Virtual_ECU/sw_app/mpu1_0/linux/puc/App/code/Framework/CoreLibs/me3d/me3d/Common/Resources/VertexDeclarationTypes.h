#ifndef VERTEX_DECLARATION_TYPES_H
#define VERTEX_DECLARATION_TYPES_H

#include <platform/PlatformAPI.h>
#include <mecl/math/Math.h>
#include "Utilities/InOut.h"

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 4054 EOF // Initialization list without utilizing c++11 not possible?

namespace me3d
{
  struct VertexPos_s
  {
    float32_t position_af32[3];

    VertexPos_s()
    {
    }

    explicit VertexPos_s(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
    {
      position_af32[0] = i_X_f32;
      position_af32[1] = i_Y_f32;
      position_af32[2] = i_Z_f32;
    }
  };

  struct VertexPosTex_s
  {
    float32_t position_af32[3];
    float32_t texCoords_af32[2];

    VertexPosTex_s() 
    {
    }

    explicit VertexPosTex_s(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32, float32_t i_S_f32, float32_t i_T_f32)
    {
      position_af32[0]  = i_X_f32;
      position_af32[1]  = i_Y_f32;
      position_af32[2]  = i_Z_f32;

      texCoords_af32[0] = i_S_f32;
      texCoords_af32[1] = i_T_f32;
    }
  };

  struct VertexPosTexNorm_s
  {
    float32_t position_af32[3];
    float32_t texCoords_af32[2];
    float32_t normals_af32[3];

    VertexPosTexNorm_s() 
    {
      position_af32[0]    = 0.0F;  
      position_af32[1]    = 0.0F; 
      position_af32[2]    = 0.0F;

      texCoords_af32[0]   = 0.0F;  
      texCoords_af32[1]   = 0.0F;

      normals_af32[0]     = 0.0F;  
      normals_af32[1]     = 0.0F; 
      normals_af32[2]     = 0.0F;
    }

    void serialize_v(InOut& b_IO_ro)
    {
      b_IO_ro.serializeArray_v(&position_af32[0],     3U);
      b_IO_ro.serializeArray_v(&texCoords_af32[0],    2U);
      b_IO_ro.serializeArray_v(&normals_af32[0],      3U);
    }
  };

  struct VertexPosTexNormTangent_s
  {
    float32_t position_af32[3];
    float32_t texCoords_af32[2];
    float32_t normals_af32[3];
    float32_t tangent_af32[3];
    float32_t biTangent_af32[3];

    VertexPosTexNormTangent_s() 
    {
      position_af32[0]    = 0.0F;  
      position_af32[1]    = 0.0F; 
      position_af32[2]    = 0.0F;

      texCoords_af32[0]   = 0.0F;  
      texCoords_af32[1]   = 0.0F;

      normals_af32[0]     = 0.0F;  
      normals_af32[1]     = 0.0F; 
      normals_af32[2]     = 0.0F;

      tangent_af32[0]     = 0.0F;  
      tangent_af32[1]     = 0.0F; 
      tangent_af32[2]     = 0.0F;

      biTangent_af32[0]   = 0.0F;  
      biTangent_af32[1]   = 0.0F; 
      biTangent_af32[2]   = 0.0F;
    }

    void serialize_v(InOut& b_IO_ro)
    {
      b_IO_ro.serializeArray_v(&position_af32[0],     3U);
      b_IO_ro.serializeArray_v(&texCoords_af32[0],    2U);
      b_IO_ro.serializeArray_v(&normals_af32[0],      3U);
      b_IO_ro.serializeArray_v(&tangent_af32[0],      3U);
      b_IO_ro.serializeArray_v(&biTangent_af32[0],    3U);
    }
  };

  struct VertexAnimated_s
  {
    float32_t position_af32[3];
    float32_t texCoords_af32[2];
    float32_t normals_af32[3];
    float32_t boneWeights_af32[4];
    float32_t boneIndices_af32[4];

    bool operator == (const VertexAnimated_s& rhs) const
    {
      return mecl::math::equal_x(position_af32[0], rhs.position_af32[0]) &&
        mecl::math::equal_x(position_af32[1], rhs.position_af32[1]) && 
        mecl::math::equal_x(position_af32[2], rhs.position_af32[2]) &&
        mecl::math::equal_x(texCoords_af32[0], rhs.texCoords_af32[0]) &&
        mecl::math::equal_x(texCoords_af32[1], rhs.texCoords_af32[1]) &&
        mecl::math::equal_x(normals_af32[0], rhs.normals_af32[0]) &&
        mecl::math::equal_x(normals_af32[1], rhs.normals_af32[1]) && 
        mecl::math::equal_x(normals_af32[2], rhs.normals_af32[2]);
    }

    VertexAnimated_s() 
    {
      position_af32[0]    = 0.0F;  
      position_af32[1]    = 0.0F; 
      position_af32[2]    = 0.0F;

      texCoords_af32[0]   = 0.0F;  
      texCoords_af32[1]   = 0.0F;

      normals_af32[0]     = 0.0F;  
      normals_af32[1]     = 0.0F; 
      normals_af32[2]     = 0.0F;

      boneWeights_af32[0] = 0.0F;
      boneWeights_af32[1] = 0.0F;
      boneWeights_af32[2] = 0.0F;
      boneWeights_af32[3] = 0.0F;

      boneIndices_af32[0] = 0.0F;
      boneIndices_af32[1] = 0.0F;
      boneIndices_af32[2] = 0.0F;
      boneIndices_af32[3] = 0.0F;
    }

    void serialize_v(InOut& b_IO_ro)
    {
      b_IO_ro.serializeArray_v(&position_af32[0],     3U);
      b_IO_ro.serializeArray_v(&texCoords_af32[0],    2U);
      b_IO_ro.serializeArray_v(&normals_af32[0],      3U);
      b_IO_ro.serializeArray_v(&boneWeights_af32[0],  4U);
      b_IO_ro.serializeArray_v(&boneIndices_af32[0],  4U);
    }
  };


  struct VertexBowlViewCPU_s
  {
    float32_t position_af32[3];
    float32_t texCoords_af32[3];  // 0, 1 = UV, 2 = Alpha value to blend segments

    VertexBowlViewCPU_s() 
    {
      position_af32[0]  = 0.0F;
      position_af32[1]  = 0.0F;
      position_af32[2]  = 0.0F;

      texCoords_af32[0] = 0.0F;
      texCoords_af32[1] = 0.0F;
      texCoords_af32[2] = 0.0F;
    }
  };

  struct VertexBowlView_s
  {
    float32_t position_af32[3];
    float32_t stitchingValues_af32[4];

    VertexBowlView_s() 
    {
      position_af32[0]  = 0.0F;
      position_af32[1]  = 0.0F;
      position_af32[2]  = 0.0F;

      stitchingValues_af32[0] = -1.0F;
      stitchingValues_af32[1] = -1.0F;
      stitchingValues_af32[2] = -1.0F;
      stitchingValues_af32[3] = -1.0F;
    }
  };

  struct VertexSingleView_s
  {
    float32_t position_af32[2];
    float32_t texCoords_af32[2];

    VertexSingleView_s() 
    {
      position_af32[0]  = 0.0F;
      position_af32[1]  = 0.0F;

      texCoords_af32[0] = 0.0F;
      texCoords_af32[1] = 0.0F;
    }
  };

} // namespace me3d

#endif
