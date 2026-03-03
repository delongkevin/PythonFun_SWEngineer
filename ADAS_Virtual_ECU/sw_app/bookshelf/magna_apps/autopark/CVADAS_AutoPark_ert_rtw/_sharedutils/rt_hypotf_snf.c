/*
 * File: rt_hypotf_snf.c
 *
 * Code generated for Simulink model 'Rear_ObjectDection'.
 *
 * Model version                  : 1.200
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:48:47 2025
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_hypotf_snf.h"

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T a;
  a = fabsf(u0);
  y = fabsf(u1);
  if (a < y) {
    a /= y;
    y *= sqrtf(a * a + 1.0F);
  } else if (a > y) {
    y /= a;
    y = sqrtf(y * y + 1.0F) * a;
  } else {
    if (!rtIsNaNF(y)) {
      y = a * 1.41421354F;
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
