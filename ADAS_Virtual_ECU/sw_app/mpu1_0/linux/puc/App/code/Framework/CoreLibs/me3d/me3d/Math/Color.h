//--------------------------------------------------------------------------                                                                                                           
/// @file Color.h                                                                         
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

#ifndef COLOR_H
#define COLOR_H

#include "MeclTypeDefs.h"

// PRQA S 2100 EOF // public members used here by design. (pre-defined colors result in more readability)
// PRQA S 6204 EOF // c_ is skipped for pre-defined colors for better readability

namespace me3d
{

class Color
{
public:   
  Color();
  explicit Color(float32_t i_RGB_f32);
  explicit Color(float32_t i_RGB_f32, float32_t i_Alpha_f32);
  explicit Color(float32_t i_Red_f32, float32_t i_Green_f32, float32_t i_Blue_f32);
  explicit Color(float32_t i_Red_f32, float32_t i_Green_f32, float32_t i_Blue_f32, float32_t i_Alpha_f32);
  explicit Color(uint32_t i_ARGB_u32);

  // Copy ctor and assignment operators
  Color(const Color& i_Color_ro);
  Color& operator=(const Color& i_Color_ro);

  // --- Conversion ---
  uint32_t toRGBA_u32() const;
  Vector4f toVec4_o() const;
  Vector3f toVec3_o() const;

  // --- Operators ---
  Color& operator-=(const Color& i_Color_ro);
  Color& operator+=(const Color& i_Color_ro);
  Color& operator*=(const Color& i_Color_ro);
  Color& operator/=(const Color& i_Color_ro);

  Color& operator-=(float32_t i_Scalar_f32);
  Color& operator+=(float32_t i_Scalar_f32);
  Color& operator*=(float32_t i_Scalar_f32);
  Color& operator/=(float32_t i_Scalar_f32);

  friend Color operator+(const Color& i_Color_ro);
  friend Color operator-(const Color& i_Color_ro);

  friend Color operator-(const Color& i_Color1_ro, const Color& i_Color2_ro);
  friend Color operator+(const Color& i_Color1_ro, const Color& i_Color2_ro);
  friend Color operator*(const Color& i_Color1_ro, const Color& i_Color2_ro);
  friend Color operator/(const Color& i_Color1_ro, const Color& i_Color2_ro);

  friend Color operator-(const Color& i_Color_ro, float32_t i_Scalar_f32);
  friend Color operator+(const Color& i_Color_ro, float32_t i_Scalar_f32);
  friend Color operator*(const Color& i_Color_ro, float32_t i_Scalar_f32);
  friend Color operator/(const Color& i_Color_ro, float32_t i_Scalar_f32);

  float32_t& operator[](uint32_t i_Index_u32);
  const float32_t& operator[](uint32_t i_Index_u32) const;

  friend bool operator==(const Color& i_Color1_ro, const Color& i_Color2_ro);
  friend bool operator!=(const Color& i_Color1_ro, const Color& i_Color2_ro);

  // utility functions
  static uint32_t colorToRGBA_u32(uint8_t i_Red_u8, uint8_t i_Green_u8, uint8_t i_Blue_u8, uint8_t i_Alpha_u8);
  static Color lerp_o(const Color& i_Color1_ro, const Color& i_Color2_ro, float32_t i_V_f32);

  // pre-defined colors
  static const Color White;
  static const Color Black;
  static const Color Red;
  static const Color Green;
  static const Color Blue;

protected: 

private: 
  float32_t red_f32;    // Has to be the first member. don't change the order -> see operator[]. 
  float32_t green_f32;
  float32_t blue_f32;
  float32_t alpha_f32;
};

} // namespace me3d

#endif

/* === End Of Header File ================================================= */