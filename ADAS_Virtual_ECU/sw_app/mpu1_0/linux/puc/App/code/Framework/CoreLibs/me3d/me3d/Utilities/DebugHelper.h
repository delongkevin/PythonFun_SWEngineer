//--------------------------------------------------------------------------                                                                                                           
/// @file DebugHelper.h                                                                         
/// @brief Used by DebugRenderer to create Geometry
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEBUGHELPER_H
#define DEBUGHELPER_H

#include <platform/PlatformAPI.h>

namespace me3d
{
  // 30 vertices
  uint32_t getArrowLines_v(float32_t i_Radius_f32, float32_t i_Length_f32, float32_t* b_Vertices_pf32);
  
  // 72 vertices
  uint32_t getBoxLines_v(float32_t i_CenterX_f32, float32_t i_CenterY_f32, float32_t i_CenterZ_f32,
                         float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, float32_t i_ExtentsZ_f32,
                         float32_t* b_Vertices_pf32);
  
  // 24 vertices, 24 indices
  void getBoxLines_v(float32_t i_CenterX_f32, float32_t i_CenterY_f32, float32_t i_CenterZ_f32,
                     float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, float32_t i_ExtentsZ_f32,
                     float32_t* b_Vertices_pf32, uint16_t* b_Indices_pu16, 
                     uint32_t& o_NumVertices_ru32, uint32_t& o_NumIndices_ru32);
  
  // 42 vertices, 36 indices
  void getBoxTriangles_v(float32_t i_MinX_f32, float32_t i_MinY_f32, float32_t i_MinZ_f32,
                         float32_t i_MaxX_f32, float32_t i_MaxY_f32, float32_t i_MaxZ_f32,
                         float32_t* b_Vertices_pf32, uint16_t* b_Indices_pu16,
                          uint32_t& o_NumVertices_ru32, uint32_t& o_NumIndices_ru32);
  
  // 42 vertices
  uint32_t getPLaneLines_v(float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, float32_t* b_Vertices_pf32);

  // 223 vertices
  uint32_t getCircleLines_v(float32_t i_Radius_f32, float32_t* b_Vertices_pf32);

  // 684 vertices
  uint32_t getSphereLines_v(float32_t i_Radius_f32, float32_t* b_Vertices_pf32);

  // 474 vertices (cylinder) + 456 = 930
  uint32_t getCapsuleLines_v(float32_t i_Radius_f32, float32_t i_Height_f32, float32_t* b_Vertices_pf32);

  // 474 vertices
  uint32_t getCylinderLines_v(float32_t i_Radius_f32, float32_t i_Height_f32, float32_t* b_Vertices_pf32);

  // vertices unknown at compile time, number of vertices is returned here
  uint32_t getArcLines_v(float32_t i_Radius1_f32, float32_t i_Radius2_f32, 
                         float32_t i_Angle1_f32, float32_t i_Angle2_f32, float32_t* b_Vertices_pf32);


  uint32_t getConeLines_v(float32_t i_Angle_f32, float32_t i_Height_f32, float32_t* b_Vertices_pf32);

} // namespace me3d


#endif
