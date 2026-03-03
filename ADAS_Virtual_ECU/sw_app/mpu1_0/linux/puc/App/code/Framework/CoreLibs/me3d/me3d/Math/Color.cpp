//--------------------------------------------------------------------------                                                                                                           
/// @file Color.cpp
/// @brief Provides some useful color functions                                               
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#include "Color.h"
#include "mecl/math/Math.h"


// PRQA S 1051 EOF // This is no code, it's documentation
// PRQA S 4054 EOF // Initializer list not used in all constructor due to readability.
// PRQA S 4222 EOF // by design

namespace me3d
{

// +++ Public Definitions ++++++++++++++++++++++++++++++++++++++++++++++++++
Color::Color()
  : red_f32(1.0F)
  , green_f32(1.0F)
  , blue_f32(1.0F)
  , alpha_f32(1.0F)
{
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color::Color(float32_t i_RGB_f32)
  : red_f32(i_RGB_f32)
  , green_f32(i_RGB_f32)
  , blue_f32(i_RGB_f32)
  , alpha_f32(1.0F)
{
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color::Color(float32_t i_RGB_f32, float32_t i_Alpha_f32)
  : red_f32(i_RGB_f32)
  , green_f32(i_RGB_f32)
  , blue_f32(i_RGB_f32)
  , alpha_f32(i_Alpha_f32)
{
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color::Color(float32_t i_Red_f32, float32_t i_Green_f32, float32_t i_Blue_f32)
  : red_f32(i_Red_f32)
  , green_f32(i_Green_f32)
  , blue_f32(i_Blue_f32)
  , alpha_f32(1.0F)
{

}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color::Color(float32_t i_Red_f32, float32_t i_Green_f32, float32_t i_Blue_f32, float32_t i_Alpha_f32)
  : red_f32(i_Red_f32)
  , green_f32(i_Green_f32)
  , blue_f32(i_Blue_f32)
  , alpha_f32(i_Alpha_f32)
{
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PRQA S 4054 1 // No initializer list, calling assignment operator already assigns all members
Color::Color(const Color& i_Color_ro)
{ 
  // call assignment operator
  *this = i_Color_ro;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PRQA S 5118 1 // easier to read and understand without initialization list
Color::Color(uint32_t i_ARGB_u32)
{
  alpha_f32 = static_cast<float32_t>((i_ARGB_u32 >> 24) & 0xFF) / 255.0F;
  red_f32   = static_cast<float32_t>((i_ARGB_u32 >> 16) & 0xFF) / 255.0F;
  green_f32 = static_cast<float32_t>((i_ARGB_u32 >>  8) & 0xFF) / 255.0F;
  blue_f32  = static_cast<float32_t>( i_ARGB_u32        & 0xFF) / 255.0F;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator=(const Color& i_Color_ro)
{
  red_f32   = i_Color_ro.red_f32;
  green_f32 = i_Color_ro.green_f32;
  blue_f32  = i_Color_ro.blue_f32;
  alpha_f32 = i_Color_ro.alpha_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
uint32_t Color::toRGBA_u32() const
{
  // Bring [0,1] to range [0,255]
  return colorToRGBA_u32(static_cast<uint8_t>(red_f32   * 255.0F + 0.5F), 
                         static_cast<uint8_t>(green_f32 * 255.0F + 0.5F), 
                         static_cast<uint8_t>(blue_f32  * 255.0F + 0.5F), 
                         static_cast<uint8_t>(alpha_f32 * 255.0F + 0.5F));
}

Vector4f Color::toVec4_o() const
{
  return Vector4f(red_f32, green_f32, blue_f32, alpha_f32);
}

me3d::Vector3f Color::toVec3_o() const
{
  return Vector3f(red_f32, green_f32, blue_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator-=(const Color& i_Color_ro)
{
  red_f32   -= i_Color_ro.red_f32;
  green_f32 -= i_Color_ro.green_f32;
  blue_f32  -= i_Color_ro.blue_f32;
  alpha_f32 -= i_Color_ro.alpha_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator+=(const Color& i_Color_ro)
{
  red_f32   += i_Color_ro.red_f32;
  green_f32 += i_Color_ro.green_f32;
  blue_f32  += i_Color_ro.blue_f32;
  alpha_f32 += i_Color_ro.alpha_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator*=(const Color& i_Color_ro)
{
  red_f32   *= i_Color_ro.red_f32;
  green_f32 *= i_Color_ro.green_f32;
  blue_f32  *= i_Color_ro.blue_f32;
  alpha_f32 *= i_Color_ro.alpha_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator/=(const Color& i_Color_ro)
{
  red_f32   /= i_Color_ro.red_f32;
  green_f32 /= i_Color_ro.green_f32;
  blue_f32  /= i_Color_ro.blue_f32;
  alpha_f32 /= i_Color_ro.alpha_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator-=(float32_t i_Scalar_f32)
{
  red_f32   -= i_Scalar_f32;
  green_f32 -= i_Scalar_f32;
  blue_f32  -= i_Scalar_f32;
  alpha_f32 -= i_Scalar_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator+=(float32_t i_Scalar_f32)
{
  red_f32   += i_Scalar_f32;
  green_f32 += i_Scalar_f32;
  blue_f32  += i_Scalar_f32;
  alpha_f32 += i_Scalar_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator*=(float32_t i_Scalar_f32)
{
  red_f32   *= i_Scalar_f32;
  green_f32 *= i_Scalar_f32;
  blue_f32  *= i_Scalar_f32;
  alpha_f32 *= i_Scalar_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color& Color::operator/=(float32_t i_Scalar_f32)
{
  red_f32   /= i_Scalar_f32;
  green_f32 /= i_Scalar_f32;
  blue_f32  /= i_Scalar_f32;
  alpha_f32 /= i_Scalar_f32;

  return *this;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator+(const Color& i_Color_ro)
{
  return i_Color_ro;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator-(const Color& i_Color_ro)
{
  return Color(-i_Color_ro.red_f32, 
               -i_Color_ro.green_f32,
               -i_Color_ro.blue_f32,
               -i_Color_ro.alpha_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator-(const Color& i_Color1_ro, const Color& i_Color2_ro)
{
  return Color(i_Color1_ro.red_f32   - i_Color2_ro.red_f32, 
               i_Color1_ro.green_f32 - i_Color2_ro.green_f32, 
               i_Color1_ro.blue_f32  - i_Color2_ro.blue_f32, 
               i_Color1_ro.alpha_f32 - i_Color2_ro.alpha_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator+(const Color& i_Color1_ro, const Color& i_Color2_ro)
{
  return Color(i_Color1_ro.red_f32   + i_Color2_ro.red_f32, 
               i_Color1_ro.green_f32 + i_Color2_ro.green_f32, 
               i_Color1_ro.blue_f32  + i_Color2_ro.blue_f32, 
               i_Color1_ro.alpha_f32 + i_Color2_ro.alpha_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator*(const Color& i_Color1_ro, const Color& i_Color2_ro)
{
  return Color(i_Color1_ro.red_f32   * i_Color2_ro.red_f32, 
               i_Color1_ro.green_f32 * i_Color2_ro.green_f32, 
               i_Color1_ro.blue_f32  * i_Color2_ro.blue_f32, 
               i_Color1_ro.alpha_f32 * i_Color2_ro.alpha_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator/(const Color& i_Color1_ro, const Color& i_Color2_ro)
{
  return Color(i_Color1_ro.red_f32   / i_Color2_ro.red_f32, 
               i_Color1_ro.green_f32 / i_Color2_ro.green_f32, 
               i_Color1_ro.blue_f32  / i_Color2_ro.blue_f32, 
               i_Color1_ro.alpha_f32 / i_Color2_ro.alpha_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator-(const Color& i_Color_ro, float32_t i_Scalar_f32)
{
  return Color(i_Color_ro.red_f32   - i_Scalar_f32, 
               i_Color_ro.green_f32 - i_Scalar_f32, 
               i_Color_ro.blue_f32  - i_Scalar_f32, 
               i_Color_ro.alpha_f32 - i_Scalar_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator+(const Color& i_Color_ro, float32_t i_Scalar_f32)
{
  return Color(i_Color_ro.red_f32   + i_Scalar_f32, 
               i_Color_ro.green_f32 + i_Scalar_f32, 
               i_Color_ro.blue_f32  + i_Scalar_f32, 
               i_Color_ro.alpha_f32 + i_Scalar_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator*(const Color& i_Color_ro, float32_t i_Scalar_f32)
{
  return Color(i_Color_ro.red_f32   * i_Scalar_f32, 
               i_Color_ro.green_f32 * i_Scalar_f32, 
               i_Color_ro.blue_f32  * i_Scalar_f32, 
               i_Color_ro.alpha_f32 * i_Scalar_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color operator/(const Color& i_Color_ro, float32_t i_Scalar_f32)
{
  return Color(i_Color_ro.red_f32   / i_Scalar_f32, 
               i_Color_ro.green_f32 / i_Scalar_f32, 
               i_Color_ro.blue_f32  / i_Scalar_f32, 
               i_Color_ro.alpha_f32 / i_Scalar_f32);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float32_t& Color::operator[](uint32_t i_Index_u32)
{
  Assert((i_Index_u32 >= 0U) && (i_Index_u32 < 4U));

  // PRQA S 3706 1 // Assert ensures valid memory access
  return (static_cast<float32_t*>(&red_f32))[i_Index_u32];
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const float32_t& Color::operator[](uint32_t i_Index_u32) const
{
  Assert((i_Index_u32 >= 0U) && (i_Index_u32 < 4U));

  // PRQA S 3706 1 // Assert ensures valid memory access
  return (static_cast<const float32_t*>(&red_f32))[i_Index_u32];
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool operator==(const Color& i_Color1_ro, const Color& i_Color2_ro)
{
  return (mecl::math::equal_x(i_Color1_ro.red_f32,   i_Color2_ro.red_f32)   &&
          mecl::math::equal_x(i_Color1_ro.green_f32, i_Color2_ro.green_f32) && 
          mecl::math::equal_x(i_Color1_ro.blue_f32,  i_Color2_ro.blue_f32)  &&
          mecl::math::equal_x(i_Color1_ro.alpha_f32, i_Color2_ro.alpha_f32) );
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool operator!=(const Color& i_Color1_ro, const Color& i_Color2_ro)
{
  return ((!mecl::math::equal_x(i_Color1_ro.red_f32,   i_Color2_ro.red_f32  )) ||
          (!mecl::math::equal_x(i_Color1_ro.green_f32, i_Color2_ro.green_f32)) || 
          (!mecl::math::equal_x(i_Color1_ro.blue_f32,  i_Color2_ro.blue_f32 )) ||
          (!mecl::math::equal_x(i_Color1_ro.alpha_f32, i_Color2_ro.alpha_f32)) );
}


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
uint32_t Color::colorToRGBA_u32(uint8_t i_Red_u8, uint8_t i_Green_u8, uint8_t i_Blue_u8, uint8_t i_Alpha_u8)
{
  return static_cast<uint32_t>((i_Red_u8   << 24U) | 
                               (i_Green_u8 << 16U) | 
                               (i_Blue_u8  <<  8U) | 
                               i_Alpha_u8); 
}

// --- static utility functions ---
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Color Color::lerp_o(const Color& i_Color1_ro, const Color& i_Color2_ro, float32_t i_V_f32)
{
  // c1 + v * (c2-c1)
  Color v_Color_o;

  v_Color_o = i_Color2_ro - i_Color1_ro;  // (c2-c1)
  v_Color_o *= i_V_f32;                   // v * (c2-c1)
  v_Color_o += i_Color1_ro;               // c1 + v * (c2-c1)

  return v_Color_o;
}

// --- pre-defined colors ---
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// PRQA S 6204 EOF // c_ is skipped for pre-defined colors for better readability

const Color Color::White  = Color(1.0F, 1.0F, 1.0F, 1.0F);
const Color Color::Black  = Color(0.0F, 0.0F, 0.0F, 1.0F);
const Color Color::Red    = Color(1.0F, 0.0F, 0.0F, 1.0F);
const Color Color::Green  = Color(0.0F, 1.0F, 0.0F, 1.0F);
const Color Color::Blue   = Color(0.0F, 0.0F, 1.0F, 1.0F);


} // namespace me3d

/* === End Of Source File ================================================== */