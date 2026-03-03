/*
 * File: diff_PkLl8BoA.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "diff_PkLl8BoA.h"

/* Function for Chart: '<S59>/Chart1' */
void diff_PkLl8BoA(const real32_T x[250], real32_T y[249])
{
  real32_T work;
  int32_T ixLead;
  int32_T iyLead;
  real32_T tmp2;
  int32_T m;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 249; m++) {
    tmp2 = work;
    work = x[ixLead];
    y[iyLead] = x[ixLead] - tmp2;
    ixLead++;
    iyLead++;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
