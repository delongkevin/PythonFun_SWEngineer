/*
 * File: power_WcQaq5Rj.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "power_WcQaq5Rj.h"

/* Function for Chart: '<S59>/Chart1' */
void power_WcQaq5Rj(const real32_T a[249], real32_T y[249])
{
  int32_T k;
  for (k = 0; k < 249; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
