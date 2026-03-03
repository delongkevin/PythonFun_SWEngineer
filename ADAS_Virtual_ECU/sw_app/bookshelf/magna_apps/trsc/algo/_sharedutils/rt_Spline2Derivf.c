/*
 * File: rt_Spline2Derivf.c
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 */

#include "rtwtypes.h"
#include "rtsplntypes.h"
#include "rt_Spline2Derivf.h"

/*
 * Second derivative initialization function for spline
 * for last dimension.
 */
void rt_Spline2Derivf(const real32_T *x, const real32_T *y, uint32_T n, real32_T
                      *u, real32_T *y2)
{
  real32_T p, qn, sig, un;
  uint32_T n1, i, k;
  n1 = n - 1U;
  y2[0U] = 0.0F;
  u[0U] = 0.0F;
  for (i = 1U; i < n1; i++) {
    real32_T dxm1 = x[i] - x[i - 1U];
    real32_T dxp1 = x[i + 1U] - x[i];
    real32_T dxpm = dxp1 + dxm1;
    sig = dxm1 / dxpm;
    p = (sig * y2[i - 1U]) + 2.0F;
    y2[i] = (sig - 1.0F) / p;
    u[i] = ((y[i + 1U] - y[i]) / dxp1) - ((y[i] - y[i - 1U]) / dxm1);
    u[i] = (((6.0F * u[i]) / dxpm) - (sig * u[i - 1U])) / p;
  }

  qn = 0.0F;
  un = 0.0F;
  y2[n1] = (un - (qn * u[n1 - 1U])) / ((qn * y2[n1 - 1U]) + 1.0F);
  for (k = n1; k > 0U; k--) {
    y2[k-1U] = (y2[k-1U] * y2[k]) + u[k-1U];
  }

  return;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
