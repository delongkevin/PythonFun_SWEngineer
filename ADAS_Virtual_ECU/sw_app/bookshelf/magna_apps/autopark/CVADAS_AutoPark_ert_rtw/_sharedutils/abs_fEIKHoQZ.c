/*
 * File: abs_fEIKHoQZ.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "abs_fEIKHoQZ.h"

/* Function for Chart: '<S59>/Chart1' */
void abs_fEIKHoQZ(const int16_T x[10], int16_T y[10])
{
  int32_T k;
  int32_T tmp;
  for (k = 0; k < 10; k++) {
    if (x[k] < 0) {
      tmp = -x[k];
      if (tmp > 32767) {
        tmp = 32767;
      }

      y[k] = (int16_T)tmp;
    } else {
      y[k] = x[k];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
