/*
 * File: look1_iflftu16Df_binlcpw.c
 *
 * Code generated for Simulink model 'SWC_APA'.
 *
 * Model version                  : 1.591
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:53:24 2025
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "look1_iflftu16Df_binlcpw.h"

uint16_T look1_iflftu16Df_binlcpw(real32_T u0, const real32_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  frac = truncf(((real32_T)table[iLeft + 1U] - (real32_T)table[iLeft]) * frac);
  if (rtIsNaNF(frac) || rtIsInfF(frac)) {
    frac = 0.0F;
  } else {
    frac = fmodf(frac, 65536.0F);
  }

  return (uint16_T)((uint32_T)(uint16_T)(frac < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-frac : (int32_T)(uint16_T)frac) + table[iLeft]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
