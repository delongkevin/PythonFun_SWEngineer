/*
 * File: abs_NgDyBNHZ.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "abs_NgDyBNHZ.h"

/* Function for Chart: '<S59>/Chart1' */
int16_T abs_NgDyBNHZ(int16_T x)
{
  int16_T y;
  int32_T tmp;
  if (x < 0) {
    tmp = -x;
    if (tmp > 32767) {
      tmp = 32767;
    }

    y = (int16_T)tmp;
  } else {
    y = x;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
