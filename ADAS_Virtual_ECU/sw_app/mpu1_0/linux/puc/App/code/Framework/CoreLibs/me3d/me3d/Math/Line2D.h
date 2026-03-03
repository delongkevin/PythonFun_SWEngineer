//--------------------------------------------------------------------------
/// @file Line2D.h
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

#ifndef LINE2D_H
#define LINE2D_H

#include "MeclTypeDefs.h"

namespace me3d
{
  class Line2D
  {
  public:
    Line2D();
    Line2D(const Vector2f& i_Start_ro, const Vector2f& i_End_ro);
    Line2D(float32_t i_X1_f32, float32_t i_Y1_f32, float32_t i_X2_f32, float32_t i_Y2_f32);

    void set_v(const Vector2f& i_Start_ro, const Vector2f& i_End_ro);

    float32_t getX_f32(float32_t i_Y_f32) const;
    float32_t getY_f32(float32_t i_X_f32) const;

    Vector2f getStart_ro() const;
    Vector2f getEnd_ro() const;

    Line2D getNormalizedLine_o() const;

    void setLength_f32(float32_t i_Length_f32);
    float32_t getLength_f32() const;

    // Positive values for the angles mean counter-clockwise while negative values mean the clockwise direction
    float32_t getAngle_f32() const;

    // Set angle in degrees
    void setAngle_f32(float32_t i_Angle_f32);

    ME_INLINE float32_t getDeltaX_f32() const { return end_o.getPosX() - start_o.getPosX(); }
    ME_INLINE float32_t getDeltaY_f32() const { return end_o.getPosY() - start_o.getPosY(); }

  private:
    // calculates slope and intercept parameter description of the line
    void calcSlopeAndIntercept_v();

  private:
    float32_t slope_f32; // slope of the line
    float32_t icept_f32; // intercept of the line
    Vector2f  start_o;   // Start point of the line
    Vector2f  end_o;     // End point of the line
  };

} // namespace me3d

#endif // VDG_LINE2D_H_
