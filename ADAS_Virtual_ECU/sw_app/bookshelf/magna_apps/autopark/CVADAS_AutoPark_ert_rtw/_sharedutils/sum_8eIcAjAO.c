/*
 * File: sum_8eIcAjAO.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "sum_8eIcAjAO.h"

/* Function for Chart: '<S59>/Chart1' */
uint8_T sum_8eIcAjAO(const uint8_T x[7])
{
  uint8_T y;
  int32_T k;
  int32_T tmp;
  y = x[0];
  for (k = 0; k < 6; k++) {
    tmp = (int32_T)((uint32_T)x[k + 1] + y);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    y = (uint8_T)tmp;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
