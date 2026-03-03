
#include "DebugHelper.h"

#include "MeclTypeDefs.h"

// PRQA S 3706 EOF // Subscript operator is ok here, the working buffer used in debugRenderer is big enough for all of these operations.
// PRQA S 3361 EOF // Post-increment operator improves readability in this case

namespace me3d
{

  uint32_t getArrowLines_v(float32_t i_Radius_f32, float32_t i_Length_f32, float32_t* b_Vertices_pf32)
  {
    uint32_t v_VertexCount_u32 = 0U;

    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;

    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++]  = i_Length_f32;
    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;


    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++]  = i_Length_f32;
    b_Vertices_pf32[v_VertexCount_u32++]  = 0.0F;

    b_Vertices_pf32[v_VertexCount_u32++]  = -i_Radius_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32 - i_Radius_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;


    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;

    b_Vertices_pf32[v_VertexCount_u32++] = i_Radius_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32 - i_Radius_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;


    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;

    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32 - i_Radius_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Radius_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;

    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_Length_f32 - i_Radius_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_Radius_f32;

    return v_VertexCount_u32 / 3U;
  }

  uint32_t getBoxLines_v(float32_t i_CenterX_f32, float32_t i_CenterY_f32, float32_t i_CenterZ_f32, 
                     float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, float32_t i_ExtentsZ_f32,
                     float32_t* b_Vertices_pf32)
  {
    uint32_t v_VertexCount_u32 = 0U;

    // first 
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32; // 1
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32; // 2
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32; // 3
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32; // 4
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32; // 5
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32; // 6
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32; // 7
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32; // 8
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    // second
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    // third
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 - i_ExtentsZ_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;
  
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[v_VertexCount_u32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    return v_VertexCount_u32 / 3U;
  }

  void getBoxLines_v(float32_t i_CenterX_f32, float32_t i_CenterY_f32, float32_t i_CenterZ_f32, 
                     float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, float32_t i_ExtentsZ_f32, 
                     float32_t* b_Vertices_pf32, uint16_t* b_Indices_pu16, 
                     uint32_t& o_NumVertices_ru32, uint32_t& o_NumIndices_ru32)
  {
    //   4----------0
    //  /|         /|
    // 5----------1 |
    // | |        | |
    // | 6--------|-2
    // |/         |/
    // 7----------3

    o_NumVertices_ru32 = 0U;

    // 0
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterX_f32 + i_ExtentsX_f32; 
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterZ_f32 + i_ExtentsZ_f32;

    // 1
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterX_f32 + i_ExtentsX_f32; 
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterZ_f32 - i_ExtentsZ_f32;

    // 2
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterZ_f32 + i_ExtentsZ_f32;

    // 3
    b_Vertices_pf32[o_NumVertices_ru32++]  = i_CenterX_f32 + i_ExtentsX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterZ_f32 - i_ExtentsZ_f32;


    // 4 
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    // 5
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterY_f32 + i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    // 6
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterZ_f32 + i_ExtentsZ_f32;

    // 7
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterX_f32 - i_ExtentsX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterY_f32 - i_ExtentsY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_CenterZ_f32 - i_ExtentsZ_f32;

    o_NumVertices_ru32 /= 3U;

    b_Indices_pu16[0]  = 0U; b_Indices_pu16[1]  = 1U;
    b_Indices_pu16[2]  = 0U; b_Indices_pu16[3]  = 2U;
    b_Indices_pu16[4]  = 1U; b_Indices_pu16[5]  = 3U;
    b_Indices_pu16[6]  = 2U; b_Indices_pu16[7]  = 3U;
                                              
    b_Indices_pu16[8]  = 4U; b_Indices_pu16[9]  = 5U;
    b_Indices_pu16[10] = 4U; b_Indices_pu16[11] = 6U;
    b_Indices_pu16[12] = 5U; b_Indices_pu16[13] = 7U;
    b_Indices_pu16[14] = 6U; b_Indices_pu16[15] = 7U;
                          
    b_Indices_pu16[16] = 0U; b_Indices_pu16[17] = 4U;
    b_Indices_pu16[18] = 1U; b_Indices_pu16[19] = 5U;
    b_Indices_pu16[20] = 2U; b_Indices_pu16[21] = 6U;
    b_Indices_pu16[22] = 3U; b_Indices_pu16[23] = 7U;

    o_NumIndices_ru32 = 24U;
  }

  void getBoxTriangles_v(float32_t i_MinX_f32, float32_t i_MinY_f32, float32_t i_MinZ_f32, 
                         float32_t i_MaxX_f32, float32_t i_MaxY_f32, float32_t i_MaxZ_f32, 
                         float32_t* b_Vertices_pf32, uint16_t* b_Indices_pu16,
                         uint32_t& o_NumVertices_ru32, uint32_t& o_NumIndices_ru32)
  {
    o_NumVertices_ru32 = 0U;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinZ_f32;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinZ_f32;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinZ_f32;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinZ_f32;


    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxZ_f32;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxZ_f32;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MinX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxZ_f32;

    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxX_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxY_f32;
    b_Vertices_pf32[o_NumVertices_ru32++] = i_MaxZ_f32;


    o_NumIndices_ru32 = 0U;
    
    // -x
    b_Indices_pu16[o_NumIndices_ru32++] = 2U;
    b_Indices_pu16[o_NumIndices_ru32++] = 0U;
    b_Indices_pu16[o_NumIndices_ru32++] = 4U;
    b_Indices_pu16[o_NumIndices_ru32++] = 2U;
    b_Indices_pu16[o_NumIndices_ru32++] = 4U;
    b_Indices_pu16[o_NumIndices_ru32++] = 6U;
                          
    // +x                 
    b_Indices_pu16[o_NumIndices_ru32++] = 5U;
    b_Indices_pu16[o_NumIndices_ru32++] = 1U;
    b_Indices_pu16[o_NumIndices_ru32++] = 3U;
    b_Indices_pu16[o_NumIndices_ru32++] = 5U;
    b_Indices_pu16[o_NumIndices_ru32++] = 3U;
    b_Indices_pu16[o_NumIndices_ru32++] = 7U;
                          
    // -y                 
    b_Indices_pu16[o_NumIndices_ru32++] = 4U;
    b_Indices_pu16[o_NumIndices_ru32++] = 0U;
    b_Indices_pu16[o_NumIndices_ru32++] = 1U;
    b_Indices_pu16[o_NumIndices_ru32++] = 4U;
    b_Indices_pu16[o_NumIndices_ru32++] = 1U;
    b_Indices_pu16[o_NumIndices_ru32++] = 5U;
                          
    // +y                 
    b_Indices_pu16[o_NumIndices_ru32++] = 3U;
    b_Indices_pu16[o_NumIndices_ru32++] = 2U;
    b_Indices_pu16[o_NumIndices_ru32++] = 6U;
    b_Indices_pu16[o_NumIndices_ru32++] = 3U;
    b_Indices_pu16[o_NumIndices_ru32++] = 6U;
    b_Indices_pu16[o_NumIndices_ru32++] = 7U;
                          
    // -z                 
    b_Indices_pu16[o_NumIndices_ru32++] = 1U;
    b_Indices_pu16[o_NumIndices_ru32++] = 0U;
    b_Indices_pu16[o_NumIndices_ru32++] = 2U;
    b_Indices_pu16[o_NumIndices_ru32++] = 1U;
    b_Indices_pu16[o_NumIndices_ru32++] = 2U;
    b_Indices_pu16[o_NumIndices_ru32++] = 3U;
                          
    // +z                 
    b_Indices_pu16[o_NumIndices_ru32++] = 4U;
    b_Indices_pu16[o_NumIndices_ru32++] = 5U;
    b_Indices_pu16[o_NumIndices_ru32++] = 6U;
    b_Indices_pu16[o_NumIndices_ru32++] = 6U;
    b_Indices_pu16[o_NumIndices_ru32++] = 5U;
    b_Indices_pu16[o_NumIndices_ru32++] = 7U;
  }

  uint32_t getPLaneLines_v(float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, float32_t* b_Vertices_pf32)
  {
    uint32_t v_VertexCount_u32 = 0U;

    // Normal
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;

    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = mecl::math::min_x(i_ExtentsX_f32, i_ExtentsY_f32) / 4.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;

    // Quad
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsX_f32; // Bottom Left
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsX_f32; // Top Left
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsY_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsX_f32; // Top Left
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsX_f32; // Top Right
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsY_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsX_f32; // Top Right
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsX_f32; // Bottom Right
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsY_f32;


    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsX_f32; // Bottom Right
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsX_f32; // Bottom Left
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsY_f32;

    // Cross
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsX_f32; // Bottom Left
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsX_f32; // Top Right
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsX_f32; // Bottom Right
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsY_f32;

    b_Vertices_pf32[v_VertexCount_u32++] = -i_ExtentsX_f32; // Top Left
    b_Vertices_pf32[v_VertexCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertexCount_u32++] = i_ExtentsY_f32;

    return v_VertexCount_u32;
  }

  uint32_t getCircleLines_v(float32_t i_Radius_f32, float32_t* b_Vertices_pf32)
  {
    float32_t v_X0_f32 = i_Radius_f32;
    float32_t v_Z0_f32 = 0.0F;

    float32_t v_X1_f32 = i_Radius_f32;
    float32_t v_Z1_f32 = 0.0F;

    uint32_t v_VertexCount_u32 = 0U;

    for (uint32_t v_Angle_u32 = 0U; v_Angle_u32 <= 360U; v_Angle_u32 += 10U)
    {
      float32_t v_S_f32 = static_cast<float32_t>(v_Angle_u32) * mecl::math::constants<float32_t>::pi_x() / 180.0F;

      v_X1_f32 = mecl::math::trigonometry<float32_t>::cos_x(v_S_f32) * i_Radius_f32;
      v_Z1_f32 = mecl::math::trigonometry<float32_t>::sin_x(v_S_f32) * i_Radius_f32;

      b_Vertices_pf32[v_VertexCount_u32++] = v_X0_f32;
      b_Vertices_pf32[v_VertexCount_u32++] = 0.0F; 
      b_Vertices_pf32[v_VertexCount_u32++] = v_Z0_f32;

      b_Vertices_pf32[v_VertexCount_u32++] = v_X1_f32;
      b_Vertices_pf32[v_VertexCount_u32++] = 0.0F; 
      b_Vertices_pf32[v_VertexCount_u32++] = v_Z1_f32;

      v_X0_f32 = v_X1_f32;
      v_Z0_f32 = v_Z1_f32;
    }

    return v_VertexCount_u32 / 3U;
  }

  uint32_t getSphereLines_v(float32_t i_Radius_f32, float32_t* b_Vertices_pf32)
  {
    Vector3f v_Lxy_ao[2];
    Vector3f v_Lxz_ao[2];
    Vector3f v_Lyz_ao[2];

    v_Lxy_ao[1] = Vector3f(i_Radius_f32, 0.0F, 0.0F);
    v_Lxz_ao[1] = Vector3f(i_Radius_f32, 0.0F, 0.0F);
    v_Lyz_ao[1] = Vector3f(0.0F, i_Radius_f32, 0.0F);

    v_Lxy_ao[0] = v_Lxy_ao[1];
    v_Lxz_ao[0] = v_Lxz_ao[1];
    v_Lyz_ao[0] = v_Lyz_ao[1];

    uint32_t v_VertCount_u32 = 0U;

    for (uint32_t v_Angle_u32 = 0U; v_Angle_u32 <= 360U; v_Angle_u32 += 10U)
    {
      float32_t v_S_f32          = static_cast<float32_t>(v_Angle_u32) * mecl::math::constants<float32_t>::pi_x() / 180.0F; 
      float32_t v_CosSRadius_f32 = mecl::math::trigonometry<float32_t>::cos_x(v_S_f32) * i_Radius_f32;
      float32_t v_SinSradius_f32 = mecl::math::trigonometry<float32_t>::sin_x(v_S_f32) * i_Radius_f32;

      // xy
      v_Lxy_ao[1].setPosX(v_CosSRadius_f32);
      v_Lxy_ao[1].setPosY(v_SinSradius_f32);

      b_Vertices_pf32[v_VertCount_u32++] = v_Lxy_ao[0].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxy_ao[0].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxy_ao[0].getPosZ();

      b_Vertices_pf32[v_VertCount_u32++] = v_Lxy_ao[1].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxy_ao[1].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxy_ao[1].getPosZ();

      v_Lxy_ao[0].setPosX(v_Lxy_ao[1].getPosX());
      v_Lxy_ao[0].setPosY(v_Lxy_ao[1].getPosY());

      // xz
      v_Lxz_ao[1].setPosX(v_CosSRadius_f32);
      v_Lxz_ao[1].setPosZ(v_SinSradius_f32);

      b_Vertices_pf32[v_VertCount_u32++] = v_Lxz_ao[0].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxz_ao[0].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxz_ao[0].getPosZ();

      b_Vertices_pf32[v_VertCount_u32++] = v_Lxz_ao[1].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxz_ao[1].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lxz_ao[1].getPosZ();

      v_Lxz_ao[0].setPosX(v_Lxz_ao[1].getPosX());
      v_Lxz_ao[0].setPosZ(v_Lxz_ao[1].getPosZ());

      // yz
      v_Lyz_ao[1].setPosY(v_CosSRadius_f32);
      v_Lyz_ao[1].setPosZ(v_SinSradius_f32);

      b_Vertices_pf32[v_VertCount_u32++] = v_Lyz_ao[0].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lyz_ao[0].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lyz_ao[0].getPosZ();
                                            
      b_Vertices_pf32[v_VertCount_u32++] = v_Lyz_ao[1].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lyz_ao[1].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Lyz_ao[1].getPosZ();

      v_Lyz_ao[0].setPosY(v_Lyz_ao[1].getPosY());
      v_Lyz_ao[0].setPosZ(v_Lyz_ao[1].getPosZ());
    }

    // add center lines
    b_Vertices_pf32[v_VertCount_u32++] = -i_Radius_f32;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;

    b_Vertices_pf32[v_VertCount_u32++] = i_Radius_f32;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;


    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = -i_Radius_f32;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;

    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = i_Radius_f32;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;


    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = -i_Radius_f32;

    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCount_u32++] = i_Radius_f32;

    return v_VertCount_u32 / 3U;
  }

  uint32_t getCapsuleLines_v(float32_t i_Radius_f32, float32_t i_Height_f32, float32_t* b_Vertices_pf32)
  {
    float32_t v_HalfHeight_f32 = i_Height_f32 * 0.5F;

    // Create top half sphere

    Vector3f v_Lxy_ao[2];
    Vector3f v_Lzy_ao[2];

    v_Lxy_ao[1] = Vector3f(i_Radius_f32, v_HalfHeight_f32, 0.0F);
    v_Lzy_ao[1] = Vector3f(0.0F, v_HalfHeight_f32, i_Radius_f32);

    v_Lxy_ao[0] = v_Lxy_ao[1];
    v_Lzy_ao[0] = v_Lzy_ao[1];

    // Generate 2 circular arcs, one for x and one for z axis

    uint32_t v_VertexCount_u32 = 0U;

    for (uint32_t v_A_u32 = 0U; v_A_u32 <= 180U; v_A_u32 += 10U)
    {
      float32_t v_S_f32 = static_cast<float32_t>(v_A_u32) * mecl::math::constants<float32_t>::pi_x() / 180.0F;

      v_Lxy_ao[1].setPosX(mecl::math::trigonometry<float32_t>::cos_x(v_S_f32) * i_Radius_f32);
      v_Lxy_ao[1].setPosY(mecl::math::trigonometry<float32_t>::sin_x(v_S_f32) * i_Radius_f32 + v_HalfHeight_f32);

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[0].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[0].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[0].getPosZ();

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[1].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[1].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[1].getPosZ();

      v_Lxy_ao[0].setPosX(v_Lxy_ao[1].getPosX());
      v_Lxy_ao[0].setPosY(v_Lxy_ao[1].getPosY());

      v_Lzy_ao[1].setPosZ(v_Lxy_ao[1].getPosX());
      v_Lzy_ao[1].setPosY(v_Lxy_ao[1].getPosY());

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[0].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[0].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[0].getPosZ();

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[1].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[1].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[1].getPosZ();

      v_Lzy_ao[0].setPosZ(v_Lzy_ao[1].getPosZ());
      v_Lzy_ao[0].setPosY(v_Lzy_ao[1].getPosY());
    }

    // Create bottom half sphere

    v_Lxy_ao[1] = Vector3f(-i_Radius_f32, -v_HalfHeight_f32, 0.0F);
    v_Lzy_ao[1] = Vector3f(0.0F, -v_HalfHeight_f32, -i_Radius_f32);

    v_Lxy_ao[0] = v_Lxy_ao[1];
    v_Lzy_ao[0] = v_Lzy_ao[1];

    // Generate 2 circular arcs, one for x and one for z axis

    for (uint32_t v_A_u32 = 180U; v_A_u32 <= 360U; v_A_u32 += 10U)
    {
      float32_t v_S_f32 = static_cast<float32_t>(v_A_u32) * mecl::math::constants<float32_t>::pi_x() / 180.0F;

      v_Lxy_ao[1].setPosX(mecl::math::trigonometry<float32_t>::cos_x(v_S_f32) * i_Radius_f32);
      v_Lxy_ao[1].setPosY(mecl::math::trigonometry<float32_t>::sin_x(v_S_f32) * i_Radius_f32 - v_HalfHeight_f32);

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[0].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[0].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[0].getPosZ();

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[1].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[1].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lxy_ao[1].getPosZ();

      v_Lxy_ao[0].setPosX(v_Lxy_ao[1].getPosX());
      v_Lxy_ao[0].setPosY(v_Lxy_ao[1].getPosY());

      v_Lzy_ao[1].setPosZ(v_Lxy_ao[1].getPosX());
      v_Lzy_ao[1].setPosY(v_Lxy_ao[1].getPosY());

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[0].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[0].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[0].getPosZ();

      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[1].getPosX();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[1].getPosY();
      b_Vertices_pf32[v_VertexCount_u32++] = v_Lzy_ao[1].getPosZ();

      v_Lzy_ao[0].setPosZ(v_Lzy_ao[1].getPosZ());
      v_Lzy_ao[0].setPosY(v_Lzy_ao[1].getPosY());
    }

    // Fill the gap between the half spheres with a cylinder
    v_VertexCount_u32 += getCylinderLines_v(i_Radius_f32, i_Height_f32, &b_Vertices_pf32[v_VertexCount_u32]);

    return v_VertexCount_u32 / 3U;
  }

  uint32_t getCylinderLines_v(float32_t i_Radius_f32, float32_t i_Height_f32, float32_t* b_Vertices_pf32)
  {
    Vector3f v_Top_ao[2];
    Vector3f v_Bottom_ao[2];

    float32_t v_Top_f32 = i_Height_f32 * 0.5F;

    v_Top_ao[0]    = Vector3f(i_Radius_f32,  v_Top_f32, 0.0F);
    v_Top_ao[1]    = Vector3f(i_Radius_f32,  v_Top_f32, 0.0F);   

    v_Bottom_ao[0] = Vector3f(i_Radius_f32, -v_Top_f32, 0.0F);
    v_Bottom_ao[1] = Vector3f(i_Radius_f32, -v_Top_f32, 0.0F);   

    uint32_t v_VertCount_u32 = 0U;

    for (uint32_t v_Angle_u32 = 0U; v_Angle_u32 <= 360U; v_Angle_u32 += 10U)
    {
      float32_t v_S_f32 = static_cast<float32_t>(v_Angle_u32) * mecl::math::constants<float32_t>::pi_x() / 180.0F;

      // Generate top circle
      v_Top_ao[1].setPosX(mecl::math::trigonometry<float32_t>::cos_x(v_S_f32) * i_Radius_f32);
      v_Top_ao[1].setPosZ(mecl::math::trigonometry<float32_t>::sin_x(v_S_f32) * i_Radius_f32);

      b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[0].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[0].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[0].getPosZ();

      b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[1].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[1].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[1].getPosZ();

      v_Top_ao[0].setPosX(v_Top_ao[1].getPosX());
      v_Top_ao[0].setPosZ(v_Top_ao[1].getPosZ());

      // Generate bottom circle
      v_Bottom_ao[1].setPosX(v_Top_ao[1].getPosX());
      v_Bottom_ao[1].setPosZ(v_Top_ao[1].getPosZ());

      b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[0].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[0].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[0].getPosZ();
      
      b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[1].getPosX();
      b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[1].getPosY();
      b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[1].getPosZ();

      v_Bottom_ao[0].setPosX(v_Bottom_ao[1].getPosX());
      v_Bottom_ao[0].setPosZ(v_Bottom_ao[1].getPosZ());

      // Generate lines along the cylinder
      if (0U == (v_Angle_u32 % 90U))
      {
        b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[1].getPosX();
        b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[1].getPosY();
        b_Vertices_pf32[v_VertCount_u32++] = v_Top_ao[1].getPosZ();

        b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[1].getPosX();
        b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[1].getPosY();
        b_Vertices_pf32[v_VertCount_u32++] = v_Bottom_ao[1].getPosZ();
      }
    }

    return v_VertCount_u32 / 3U;
  }

  uint32_t getArcLines_v(float32_t i_Radius1_f32, float32_t i_Radius2_f32, 
                         float32_t i_Angle1_f32, float32_t i_Angle2_f32, float32_t* b_Vertices_pf32)
  {
    if (i_Angle1_f32 > i_Angle2_f32)
    {
      float32_t v_Temp_f32 = i_Angle1_f32;
      i_Angle1_f32 = i_Angle2_f32;
      i_Angle2_f32 = v_Temp_f32;
    }

    uint32_t v_VertCnt_u32 = 0U;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;

    // start
    b_Vertices_pf32[v_VertCnt_u32++] = mecl::math::trigonometry<float32_t>::cos_x(i_Angle1_f32) * i_Radius1_f32;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = mecl::math::trigonometry<float32_t>::sin_x(i_Angle1_f32) * i_Radius2_f32;

    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;

    // end
    b_Vertices_pf32[v_VertCnt_u32++] = mecl::math::trigonometry<float32_t>::cos_x(i_Angle2_f32) * i_Radius1_f32;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = mecl::math::trigonometry<float32_t>::sin_x(i_Angle2_f32) * i_Radius2_f32;

    float32_t v_X0_f32 = 0.0F;
    float32_t v_Z0_f32 = 0.0F;

    float32_t v_X1_f32 = 0.0F;
    float32_t v_Z1_f32 = 0.0F;

    float32_t v_Angle_f32 = i_Angle1_f32;

    // PRQA S 4234 1 // Ok here, need the precision
    while (v_Angle_f32 <= i_Angle2_f32)
    {
      v_X1_f32 = mecl::math::trigonometry<float32_t>::cos_x(v_Angle_f32) * i_Radius1_f32;
      v_Z1_f32 = mecl::math::trigonometry<float32_t>::sin_x(v_Angle_f32) * i_Radius2_f32;

      b_Vertices_pf32[v_VertCnt_u32++] = v_X0_f32;
      b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
      b_Vertices_pf32[v_VertCnt_u32++] = v_Z0_f32;

      b_Vertices_pf32[v_VertCnt_u32++] = v_X1_f32;
      b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
      b_Vertices_pf32[v_VertCnt_u32++] = v_Z1_f32;

      v_X0_f32 = v_X1_f32;
      v_Z0_f32 = v_Z1_f32;

      v_Angle_f32 += 0.1F;
    }


    // close gap between last point and end points
    b_Vertices_pf32[v_VertCnt_u32++] = v_X0_f32;
    b_Vertices_pf32[v_VertCnt_u32++] = 0.0F;
    b_Vertices_pf32[v_VertCnt_u32++] = v_Z0_f32;

    b_Vertices_pf32[v_VertCnt_u32++] =  b_Vertices_pf32[ 9];
    b_Vertices_pf32[v_VertCnt_u32++] =  b_Vertices_pf32[10];
    b_Vertices_pf32[v_VertCnt_u32++] =  b_Vertices_pf32[11];

    return v_VertCnt_u32 / 3U;
  }

  uint32_t getConeLines_v(float32_t i_Angle_f32, float32_t i_Height_f32, float32_t* b_Vertices_pf32)
  {
    //      |\
    //      |Ó\
    //      |  \            tan Ó = a/b --> a = tan Ó * b
    //      |   \   
    //     b|    \ c
    //      |     \
    //      |90°  ß\
    //      |-------\
    //          a

    Vector3f v_Lxz_ao[2];

    i_Height_f32 = -i_Height_f32; // The cone starts at 0,0,0 and points to -y

    float32_t v_Radius_f32 = 0.0F;
    float32_t v_Factor_f32 = (i_Height_f32 / 3.0F);

    // Create 3 circles, each with different height

    uint32_t v_VertexCount_u32 = 0U;

    for (sint32_t v_I_s32 = 1; v_I_s32 < 4; v_I_s32++)
    {
        i_Height_f32 = v_Factor_f32 * static_cast<float32_t>(v_I_s32);
        v_Radius_f32 = mecl::math::trigonometry<float32_t>::tan_x(i_Angle_f32) * i_Height_f32;

        v_Lxz_ao[0] = Vector3f(v_Radius_f32, i_Height_f32, 0.0F);
        v_Lxz_ao[1] = Vector3f(v_Radius_f32, i_Height_f32, 0.0F);

        for (uint32_t v_Angle_u32 = 0U; v_Angle_u32 <= 360U; v_Angle_u32 += 10U)
        {
            float32_t v_S_f32 = static_cast<float32_t>(v_Angle_u32) * mecl::math::constants<float32_t>::pi_x() / 180.0F;

            v_Lxz_ao[1].setPosX(mecl::math::trigonometry<float32_t>::cos_x(v_S_f32) * v_Radius_f32);
            v_Lxz_ao[1].setPosZ(mecl::math::trigonometry<float32_t>::sin_x(v_S_f32) * v_Radius_f32);

            b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosX();
            b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosY();
            b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosZ();

            b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosX();
            b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosY();
            b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosZ();

            v_Lxz_ao[0].setPosX(v_Lxz_ao[1].getPosX());
            v_Lxz_ao[0].setPosZ(v_Lxz_ao[1].getPosZ());
        }
    }

    // Create lines connecting the circles

    v_Lxz_ao[0] = Vector3f(0.0F, 0.0F, 0.0F);
    v_Lxz_ao[1] = Vector3f(v_Radius_f32, i_Height_f32, 0.0F);

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosZ();

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosZ();

    v_Lxz_ao[1] = Vector3f(-v_Radius_f32, i_Height_f32, 0.0F);

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosZ();

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosZ();

    v_Lxz_ao[1] = Vector3f(0.0F, i_Height_f32, v_Radius_f32);

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosZ();

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosZ();

    v_Lxz_ao[1] = Vector3f(0.0F, i_Height_f32, -v_Radius_f32);

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[0].getPosZ();

    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosX();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosY();
    b_Vertices_pf32[v_VertexCount_u32++] = v_Lxz_ao[1].getPosZ();

    return v_VertexCount_u32 / 3U;
  }


}

