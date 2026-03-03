//--------------------------------------------------------------------------
/// @file Line2D.cpp
/// @brief Contains the two dimensional line description interface.
///
/// This class describes a two dimensional line in slope-intercept form.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert2 (Mark.Reichert2@Magna.com), Hagen Marczok (hagen.marczok@magna.com)
///
//  --------------------------------------------------------------------------


#include "Math/Line2D.h"

namespace me3d
{
  Line2D::Line2D()
    : slope_f32(1.0F)
    , icept_f32(0.0F)
  {
    set_v(Vector2f(0.0F), Vector2f(1.0F));
  }

  Line2D::Line2D(const Vector2f& i_Start_ro, const Vector2f& i_End_ro)
    : slope_f32(1.0F)
    , icept_f32(0.0F)
  {
    set_v(i_Start_ro, i_End_ro);
  }

  Line2D::Line2D(float32_t i_X1_f32, float32_t i_Y1_f32, float32_t i_X2_f32, float32_t i_Y2_f32)
    : slope_f32(1.0F)
    , icept_f32(0.0F)
  {
    set_v(Vector2f(i_X1_f32, i_Y1_f32), Vector2f(i_X2_f32, i_Y2_f32));
  }

  void Line2D::set_v(const Vector2f& i_Start_ro, const Vector2f& i_End_ro)
  {
    start_o = i_Start_ro;
    end_o   = i_End_ro;

    calcSlopeAndIntercept_v();
  }

  float32_t Line2D::getX_f32(float32_t i_Y_f32) const
  {
    return (i_Y_f32 - icept_f32) / slope_f32;
  }

  float32_t Line2D::getY_f32(float32_t i_X_f32) const
  {
    return slope_f32 * i_X_f32 + icept_f32;
  }

  Vector2f Line2D::getStart_ro() const
  {
    return start_o;
  }

  Vector2f Line2D::getEnd_ro() const
  {
    return end_o;
  }

  Line2D Line2D::getNormalizedLine_o() const
  {
    float32_t v_DX_f32      = getDeltaX_f32();
    float32_t v_DY_f32      = getDeltaY_f32();
    float32_t v_Length_f32  = getLength_f32();

    Vector2f v_End_o(start_o.getPosX() + v_DX_f32 / v_Length_f32, 
                     start_o.getPosY() + v_DY_f32 / v_Length_f32);

    return Line2D(start_o, v_End_o);
  }

  void Line2D::setLength_f32(float32_t i_Length_f32)
  {
    Line2D v_NormalizedLine_o = getNormalizedLine_o();

    end_o = Vector2f(start_o.getPosX() + v_NormalizedLine_o.getDeltaX_f32() * i_Length_f32,
                     start_o.getPosY() + v_NormalizedLine_o.getDeltaY_f32() * i_Length_f32);

    calcSlopeAndIntercept_v();
  }

  float32_t Line2D::getLength_f32() const
  {
    float32_t v_DX_f32 = getDeltaX_f32();
    float32_t v_DY_f32 = getDeltaY_f32();

    return mecl::math::algebra<float32_t>::sqrt_x(v_DX_f32 * v_DX_f32 + v_DY_f32 * v_DY_f32);
  }

  float32_t Line2D::getAngle_f32() const
  {
    float32_t v_DX_f32 = getDeltaX_f32();
    float32_t v_DY_f32 = getDeltaY_f32();

    float32_t v_ThetaRadians_f32 = mecl::math::trigonometry<float32_t>::atan2_x(v_DY_f32, v_DX_f32);

    float32_t v_Theta_f32 =  mecl::math::toDegrees_x<float32_t>(v_ThetaRadians_f32);

    float32_t v_ThetaNormalized_f32 = (v_Theta_f32 < 0.0F)   ? 
                                      (v_Theta_f32 + 360.0F) : 
                                       v_Theta_f32;

    float32_t v_RetAngle_f32 = 0.0F;

    if (false == mecl::math::equal_x<float32_t>(v_ThetaNormalized_f32, 360.0F) )
    {
      v_RetAngle_f32 = v_ThetaNormalized_f32;
    }

    return v_RetAngle_f32;
  }

  void Line2D::setAngle_f32(float32_t i_Angle_f32)
   {
    float32_t v_Angle_f32  = mecl::math::toRadians_x<float32_t>(i_Angle_f32);
    float32_t v_Length_f32 = getLength_f32();
  
    float32_t v_DX_f32 = mecl::math::trigonometry<float32_t>::cos_x(v_Angle_f32) * v_Length_f32;
    float32_t v_DY_f32 = mecl::math::trigonometry<float32_t>::sin_x(v_Angle_f32) * v_Length_f32;

    end_o.setPosX(start_o.getPosX() + v_DX_f32);
    end_o.setPosY(start_o.getPosY() + v_DY_f32);

    calcSlopeAndIntercept_v();
  }

  void Line2D::calcSlopeAndIntercept_v()
  {
    // calculate the slope
    slope_f32 = (end_o.getPosY() - start_o.getPosY()) / (end_o.getPosX() - start_o.getPosX());

    // calculate the intercept
    icept_f32 = start_o.getPosY() - slope_f32 * start_o.getPosX();
  }


} // namespace me3d
