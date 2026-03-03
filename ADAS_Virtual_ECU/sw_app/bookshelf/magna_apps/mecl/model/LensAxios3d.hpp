//--------------------------------------------------------------------------
/// @file LensAxios3d.hpp
/// @brief Contains the lens model implementation.
///
/// The lens model provides a warping and an un-warping function.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Hagen Marczok (hagen.marczok@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup mecl
/// @{
/// \addtogroup model
/// @{
#include <math.h>
#include "lensaxios3d.h"

namespace mecl {
namespace model {

LensAxios3D::LensAxios3D(void)
: a1_f32(0.0F)
, a2_f32(0.0F)
, a3_f32(0.0F)
, b1_f32(0.0F)
, b2_f32(0.0F)
, c1_f32(0.0F)
, c2_f32(0.0F)
, r0_f32(0.0F)
, pX_f32(0.0F)
, pY_f32(0.0F)
, configured_b(false)
{
}

LensAxios3D::LensAxios3D(const Config_s* i_LensConfig_ps)
: a1_f32(i_LensConfig_ps->a1_f32)
, a2_f32(i_LensConfig_ps->a2_f32)
, a3_f32(i_LensConfig_ps->a3_f32)
, b1_f32(i_LensConfig_ps->b1_f32)
, b2_f32(i_LensConfig_ps->b2_f32)
, c1_f32(i_LensConfig_ps->c1_f32)
, c2_f32(i_LensConfig_ps->c2_f32)
, r0_f32(i_LensConfig_ps->r0_f32)
, pX_f32(i_LensConfig_ps->pX_f32)
, pY_f32(i_LensConfig_ps->pY_f32)
, configured_b(true)
{
}

void LensAxios3D::config_v(const Config_s* i_LensConfig_ps)
{
  a1_f32 = i_LensConfig_ps->a1_f32;
  a2_f32 = i_LensConfig_ps->a2_f32;
  a3_f32 = i_LensConfig_ps->a3_f32;
  b1_f32 = i_LensConfig_ps->b1_f32;
  b2_f32 = i_LensConfig_ps->b2_f32;
  c1_f32 = i_LensConfig_ps->c1_f32;
  c2_f32 = i_LensConfig_ps->c2_f32;
  r0_f32 = i_LensConfig_ps->r0_f32;
  pX_f32 = i_LensConfig_ps->pX_f32;
  pY_f32 = i_LensConfig_ps->pY_f32;

  configured_b = true;

  return;
}

void LensAxios3D::warpVector_v(float32_t& b_PosX_rf32, float32_t& b_PosY_rf32, float32_t& b_PosZ_rf32, const float32_t& i_DistLevel_rf32) const
{
  if(true == configured_b)
  {
    // apply camera end of line calibration data
    applyEolData_v(b_PosX_rf32, b_PosY_rf32);

    // get pinhole radius
    float32_t v_Norm_f32      = b_PosX_rf32 * b_PosX_rf32 + b_PosY_rf32 * b_PosY_rf32;
    float32_t v_PinRadius_f32 = sqrt(v_Norm_f32);
    v_Norm_f32      = sqrt(v_Norm_f32 + 0.801025F); // 0.801025F = 0.895F * 0.895F

    // set design focal length
    float32_t v_Focal_f32 = 0.895F;

    // mirror coordinates having a negative z-value
    if(0.0F > b_PosZ_rf32)
    {
      b_PosX_rf32 = -b_PosX_rf32;
      b_PosY_rf32 = -b_PosY_rf32;
      v_Focal_f32 = -v_Focal_f32;
    }

    // get pinhole angle
    float32_t v_PinAngle1_f32 = acos(v_Focal_f32 / v_Norm_f32);
    float32_t v_PinAngle2_f32 = v_PinAngle1_f32 * v_PinAngle1_f32;
    float32_t v_PinAngle3_f32 = v_PinAngle2_f32 * v_PinAngle1_f32;

    const float32_t c_L5_f32 = -0.103107427814684F;
    const float32_t c_L4_f32 =  0.229182402913814F;
    const float32_t c_L3_f32 = -0.060232115075806F;
    const float32_t c_L2_f32 =  0.113431880193239F;
    const float32_t c_L1_f32 =  0.886515027524824F;
    const float32_t c_L0_f32 =  0.000141931846539F;

    // get distorted radius
    float32_t v_CorRadius_f32 = c_L5_f32 * v_PinAngle3_f32 * v_PinAngle2_f32
        + c_L4_f32 * v_PinAngle2_f32 * v_PinAngle2_f32
        + c_L3_f32 * v_PinAngle3_f32
        + c_L2_f32 * v_PinAngle2_f32
        + c_L1_f32 * v_PinAngle1_f32
        + c_L0_f32;

    if((0.0F < i_DistLevel_rf32) && (1.0F >= i_DistLevel_rf32))
    {
      // apply level of distortion
      v_PinRadius_f32 -= (v_PinRadius_f32 - v_CorRadius_f32) * i_DistLevel_rf32;
    }

    // Avoid division by zero
    if(0U != static_cast<uint32_t>(v_PinRadius_f32))
    {
      // get correction factor
      float32_t v_Scale_f32 = v_CorRadius_f32 / v_PinRadius_f32;

      // apply correction factor to pinhole pixel
      b_PosX_rf32 *= v_Scale_f32;
      b_PosY_rf32 *= v_Scale_f32;
    }
  }

  return;
}

void LensAxios3D::applyEolData_v(float32_t& b_PosX_rf32, float32_t& b_PosY_rf32) const
{
  float32_t R2 = r0_f32 * r0_f32;
  float32_t R4 = R2 * R2;
  float32_t R6 = R4 * R2;

  float32_t v_XY_f32 = b_PosX_rf32 * b_PosY_rf32;
  float32_t v_X2_f32 = b_PosX_rf32 * b_PosX_rf32;
  float32_t v_Y2_f32 = b_PosY_rf32 * b_PosY_rf32;

  float32_t v_PixRad2_f32 = v_X2_f32 + v_Y2_f32;
  float32_t v_PixRad4_f32 = v_PixRad2_f32 * v_PixRad2_f32;
  float32_t v_PixRad6_f32 = v_PixRad4_f32 * v_PixRad2_f32;

  // Radial symmetric distortion
  float32_t v_CorRad_f32 = (v_PixRad2_f32 - R2) * a1_f32
      + (v_PixRad4_f32 - R4) * a2_f32
      + (v_PixRad6_f32 - R6) * a3_f32;

  b_PosX_rf32 += b_PosX_rf32 * v_CorRad_f32;
  b_PosY_rf32 += b_PosY_rf32 * v_CorRad_f32;

  // Tangential asymmetric distortion
  b_PosX_rf32 += (2.0F * v_X2_f32 + v_PixRad2_f32) * b1_f32 + 2.0F * v_XY_f32 * b2_f32;
  b_PosY_rf32 += (2.0F * v_Y2_f32 + v_PixRad2_f32) * b2_f32 + 2.0F * v_XY_f32 * b1_f32;

  // Affinity and shear
  b_PosX_rf32 += b_PosX_rf32 * c1_f32 + b_PosY_rf32 * c2_f32;

  // Principal
  b_PosX_rf32 += pX_f32;
  b_PosY_rf32 += pY_f32;

  return;
}

}; // namespace model
}; // namespace mecl

/// @}
/// @}
