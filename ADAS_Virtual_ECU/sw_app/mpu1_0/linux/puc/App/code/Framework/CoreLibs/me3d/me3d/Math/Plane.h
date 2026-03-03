//--------------------------------------------------------------------------                                                                                                           
/// @file Plane.h                                                                         
/// @brief Simple Plane struct
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef PLANE_H
#define PLANE_H

#include "MeclTypeDefs.h"


// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

struct Plane_s
{
  Vector3f  normal_o;
  float32_t distance_f32;

  Plane_s();
  Plane_s(float32_t i_A_f32, float32_t i_B_f32, float32_t i_C_f32, float32_t i_D_f32);
  Plane_s(const Vector3f& i_Normal_ro, float32_t i_Distance_f32);
};

} // namespace me3d

#endif
