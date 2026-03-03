/*
 * File: rt_remf_snf.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>
#include "rt_remf_snf.h"

real32_T rt_remf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T q;
  if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u1)) {
    y = u0;
  } else if ((u1 != 0.0F) && (u1 != truncf(u1))) {
    q = fabsf(u0 / u1);
    if (!(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q)) {
      y = 0.0F * u0;
    } else {
      y = fmodf(u0, u1);
    }
  } else {
    y = fmodf(u0, u1);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
