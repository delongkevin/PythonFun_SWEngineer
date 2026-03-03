//--------------------------------------------------------------------------                                                                                                           
/// @file MeclCfg.h                                                                         
/// @brief Mecl Configuration
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef ME3D_MECL_CFG
#define ME3D_MECL_CFG

#include "Utilities/InputHandler.h"

#include <mecl/core/Singleton.h>
#include <mecl/model/Camera.h>
#include <mecl/model/SingleView.h>
#include <mecl/model/LensPrism.h>

namespace me3d
{
  enum LensType_e
  {
    e_LensTypeNoLens,
    e_LensTypeRadial,
    e_LensTypeStretchVertical,
    e_LensTypePrism,
    e_LensTypeCylinder
  };

  const uint32_t c_W2IPolySize_u32 = 5U;
  const uint32_t c_I2WPolySize_u32 = 5U;
  const uint32_t c_StretchFactorSize_u32 = 6U;
  const uint32_t c_StretchBaseSize_u32 = 6U;

  typedef mecl::model::LensRadial<float32_t, c_W2IPolySize_u32, c_I2WPolySize_u32>                  LensRadialf;
  typedef mecl::model::LensCylinder<float32_t>                                                      LensCylinderf;
  typedef mecl::model::LensPrism<float32_t>                                                         LensPrismf;
  typedef mecl::model::LensStretchVertical<float32_t, 
    c_W2IPolySize_u32, c_I2WPolySize_u32, c_StretchFactorSize_u32, c_StretchBaseSize_u32>           LensStretchVerticalf;
  typedef mecl::model::Sensor<float32_t>                                                            Sensorf;
  typedef mecl::model::Pinhole<float32_t>                                                           Pinholef;   
  typedef mecl::model::Camera<float32_t>                                                            Cameraf;
  typedef mecl::model::SingleView<float32_t>                                                        SingleViewf;

  typedef mecl::core::RotationMatrix<float32_t>                                                     RotMatf;
  typedef mecl::core::Singleton<InputHandler>                                                       SingletonInput;

  typedef mecl::core::Point2D<float32_t>                                                            Point2Df;
  
} // namespace me3d

#endif 
