/*
 * File: uMultiWordNe.c
 *
 * Code generated for Simulink model 'SWC_AP_StateMachine'.
 *
 * Model version                  : 1.2855
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:49:36 2025
 */

#include "rtwtypes.h"
#include "uMultiWordCmp.h"
#include "uMultiWordNe.h"

boolean_T uMultiWordNe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) != 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
