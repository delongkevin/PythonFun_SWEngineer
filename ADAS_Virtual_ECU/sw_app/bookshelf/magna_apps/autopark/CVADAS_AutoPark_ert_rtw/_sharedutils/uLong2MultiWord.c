/*
 * File: uLong2MultiWord.c
 *
 * Code generated for Simulink model 'DT24_CVADAS_AP_CodGen'.
 *
 * Model version                  : 1.1267
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:56:24 2025
 */

#include "rtwtypes.h"
#include "uLong2MultiWord.h"

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0U;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
