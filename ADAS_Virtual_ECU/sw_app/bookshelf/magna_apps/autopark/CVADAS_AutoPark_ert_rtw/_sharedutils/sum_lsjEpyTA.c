/*
 * File: sum_lsjEpyTA.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "sum_lsjEpyTA.h"

/* Function for Chart: '<S59>/Chart1' */
uint8_T sum_lsjEpyTA(const uint8_T x[2])
{
  int32_T tmp;
  tmp = (int32_T)((uint32_T)x[0] + x[1]);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  return (uint8_T)tmp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
