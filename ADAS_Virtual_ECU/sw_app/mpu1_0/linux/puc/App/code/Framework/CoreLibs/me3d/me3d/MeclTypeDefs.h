//--------------------------------------------------------------------------                                                                                                           
/// @file MeclTypeDefs.h                                                                         
/// @brief Mecl Types Configuration
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef ME3D_MECL_TYPES
#define ME3D_MECL_TYPES

#include <platform/PlatformAPI.h>
#include <osal/system/String.h>
#include <mecl/core/Matrix.h>
#include <mecl/core/Projection4D.h>
#include <mecl/core/Matrix3x3.h>
#include <mecl/core/Quaternion.h>

namespace me3d
{
  typedef osal::String                MEString;

  typedef mecl::core::Matrix3x3<float32_t>    Matrix3f;
  typedef mecl::core::Projection4D<float32_t> Matrix4f;

  typedef mecl::core::Point2D<float32_t>      Vector2f;
  typedef mecl::core::Point3D<float32_t>      Vector3f;
  typedef mecl::core::Point4D<float32_t>      Vector4f; 

  typedef mecl::core::Point2D<sint32_t>       Vector2i;
  typedef mecl::core::Point3D<sint32_t>       Vector3i;
  typedef mecl::core::Point4D<sint32_t>       Vector4i;

  typedef mecl::core::Quaternion<float32_t>   Quaternionf;

} // namespace me3d

#endif
