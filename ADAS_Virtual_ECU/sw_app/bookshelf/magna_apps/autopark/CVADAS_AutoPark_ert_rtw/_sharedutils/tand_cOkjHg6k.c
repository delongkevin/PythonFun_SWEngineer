/*
 * File: tand_cOkjHg6k.c
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "tand_cOkjHg6k.h"

/* Function for Chart: '<S59>/Chart1' */
void tand_cOkjHg6k(real_T *x)
{
  if (rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    *x = tan(0.017453292519943295 * *x);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
