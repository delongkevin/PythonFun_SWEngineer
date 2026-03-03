/*
 * File: atan2d_4JrmYGtm.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "rt_atan2f_snf.h"
#include "atan2d_4JrmYGtm.h"

/* Function for Chart: '<S59>/Chart1' */
void atan2d_4JrmYGtm(const real32_T y[249], const real32_T x[249], real32_T r
                     [249])
{
  int32_T k;
  for (k = 0; k < 249; k++) {
    r[k] = 57.2957802F * rt_atan2f_snf(y[k], x[k]);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
