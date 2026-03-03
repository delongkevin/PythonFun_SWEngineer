/*
 * File: mod_jpURcOT9.c
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
#include <math.h>
#include "mod_jpURcOT9.h"

/* Function for Chart: '<S59>/Chart1' */
real32_T mod_jpURcOT9(real32_T x, real32_T y)
{
  real32_T r;
  boolean_T rEQ0;
  real32_T q;
  r = x;
  if (y == 0.0F) {
    if (x == 0.0F) {
      r = y;
    }
  } else if (rtIsNaNF(x)) {
    r = (rtNaNF);
  } else if (rtIsNaNF(y)) {
    r = (rtNaNF);
  } else if (rtIsInfF(x)) {
    r = (rtNaNF);
  } else if (x == 0.0F) {
    r = 0.0F / y;
  } else if (rtIsInfF(y)) {
    if ((y < 0.0F) != (x < 0.0F)) {
      r = y;
    }
  } else {
    r = fmodf(x, y);
    rEQ0 = (r == 0.0F);
    if ((!rEQ0) && (y > floorf(y))) {
      q = fabsf(x / y);
      rEQ0 = !(fabsf(q - floorf(q + 0.5F)) > 1.1920929E-7F * q);
    }

    if (rEQ0) {
      r = y * 0.0F;
    } else {
      if ((x < 0.0F) != (y < 0.0F)) {
        r += y;
      }
    }
  }

  return r;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
