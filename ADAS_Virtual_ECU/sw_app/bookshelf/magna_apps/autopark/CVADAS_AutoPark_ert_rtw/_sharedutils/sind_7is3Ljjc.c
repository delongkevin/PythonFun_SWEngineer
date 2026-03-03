/*
 * File: sind_7is3Ljjc.c
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
#include "rt_remf_snf.h"
#include "sind_7is3Ljjc.h"

/* Function for Chart: '<S59>/Chart1' */
void sind_7is3Ljjc(real32_T *x)
{
  int8_T n;
  real32_T c_x;
  real32_T absx;
  if (rtIsInfF(*x) || rtIsNaNF(*x)) {
    *x = (rtNaNF);
  } else {
    c_x = rt_remf_snf(*x, 360.0F);
    absx = fabsf(c_x);
    if (absx > 180.0F) {
      if (c_x > 0.0F) {
        c_x -= 360.0F;
      } else {
        c_x += 360.0F;
      }

      absx = fabsf(c_x);
    }

    if (absx <= 45.0F) {
      c_x *= 0.0174532924F;
      n = 0;
    } else if (absx <= 135.0F) {
      if (c_x > 0.0F) {
        c_x = (c_x - 90.0F) * 0.0174532924F;
        n = 1;
      } else {
        c_x = (c_x + 90.0F) * 0.0174532924F;
        n = -1;
      }
    } else if (c_x > 0.0F) {
      c_x = (c_x - 180.0F) * 0.0174532924F;
      n = 2;
    } else {
      c_x = (c_x + 180.0F) * 0.0174532924F;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = sinf(c_x);
      break;

     case 1:
      *x = cosf(c_x);
      break;

     case -1:
      *x = -cosf(c_x);
      break;

     default:
      *x = -sinf(c_x);
      break;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
