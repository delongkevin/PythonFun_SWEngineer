/*
 * File: tand_brbYAlcS.c
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rt_remf_snf.h"
#include "tand_brbYAlcS.h"

/* Function for MATLAB Function: '<S7>/MATLAB Function1' */
void tand_brbYAlcS(real32_T *x)
{
  int8_T n;
  real32_T b_x;
  real32_T absx;
  if (rtIsInfF(*x) || rtIsNaNF(*x)) {
    *x = (rtNaNF);
  } else {
    b_x = rt_remf_snf(*x, 360.0F);
    absx = fabsf(b_x);
    if (absx > 180.0F) {
      if (b_x > 0.0F) {
        b_x -= 360.0F;
      } else {
        b_x += 360.0F;
      }

      absx = fabsf(b_x);
    }

    if (absx <= 45.0F) {
      b_x *= 0.0174532924F;
      n = 0;
    } else if (absx <= 135.0F) {
      if (b_x > 0.0F) {
        b_x = (b_x - 90.0F) * 0.0174532924F;
        n = 1;
      } else {
        b_x = (b_x + 90.0F) * 0.0174532924F;
        n = -1;
      }
    } else if (b_x > 0.0F) {
      b_x = (b_x - 180.0F) * 0.0174532924F;
      n = 2;
    } else {
      b_x = (b_x + 180.0F) * 0.0174532924F;
      n = -2;
    }

    *x = tanf(b_x);
    if ((n == 1) || (n == -1)) {
      b_x = 1.0F / *x;
      *x = -(1.0F / *x);
      if (rtIsInfF(*x) && (n == 1)) {
        *x = b_x;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
