/*
 * File: uMultiWordCmp.c
 *
 * Code generated for Simulink model 'SWC_AP_StateMachine'.
 *
 * Model version                  : 1.2855
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:49:36 2025
 */

#include "rtwtypes.h"
#include "uMultiWordCmp.h"

int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T u1i;
  uint32_T u2i;
  int32_T i;
  y = 0;
  i = n;
  while ((y == 0) && (i > 0)) {
    i--;
    u1i = u1[i];
    u2i = u2[i];
    if (u1i != u2i) {
      y = u1i > u2i ? 1 : -1;
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
