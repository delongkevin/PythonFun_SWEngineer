/*
 * File: mod_GIkes8zg.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "mod_jpURcOT9.h"
#include "mod_GIkes8zg.h"

/* Function for Chart: '<S59>/Chart1' */
void mod_GIkes8zg(const real32_T x[250], real32_T y, real32_T r[250])
{
  int32_T k;
  for (k = 0; k < 250; k++) {
    r[k] = mod_jpURcOT9(x[k], y);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
