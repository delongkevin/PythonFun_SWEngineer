/*
 * File: sign_dXEnEZRu.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "sign_dXEnEZRu.h"

/* Function for MATLAB Function: '<S82>/MATLAB Function PathSeparation' */
void sign_dXEnEZRu(int16_T x[11])
{
  int32_T k;
  for (k = 0; k < 11; k++) {
    if (x[k] > 0) {
      x[k] = 1;
    } else if (x[k] < 0) {
      x[k] = -1;
    } else {
      x[k] = 0;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
