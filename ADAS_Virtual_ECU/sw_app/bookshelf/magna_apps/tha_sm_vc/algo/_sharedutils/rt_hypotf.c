/*
 * File: rt_hypotf.c
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.2042
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:34 2025
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotf.h"

real32_T rt_hypotf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T a;
  real32_T b;
  a = fabsf(u0);
  b = fabsf(u1);
  if (a < b) {
    a /= b;
    y = sqrtf(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = sqrtf(b * b + 1.0F) * a;
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
