/*
 * File: sum_d5YRIYyL.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "sum_d5YRIYyL.h"

/* Function for Chart: '<S59>/Chart1' */
int16_T sum_d5YRIYyL(const int16_T x[10])
{
  int16_T y;
  int32_T k;
  int32_T tmp;
  y = x[0];
  for (k = 0; k < 9; k++) {
    tmp = x[k + 1] + y;
    if (tmp > 32767) {
      tmp = 32767;
    } else {
      if (tmp < -32768) {
        tmp = -32768;
      }
    }

    y = (int16_T)tmp;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
