/*
 * File: mul_s32_sat.c
 *
 * Code generated for Simulink model 'DT24_CVADAS_AP_CodGen'.
 *
 * Model version                  : 1.1230
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Aug 13 21:05:45 2025
 */

#include "rtwtypes.h"
#include "mul_wide_s32.h"
#include "mul_s32_sat.h"

int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
