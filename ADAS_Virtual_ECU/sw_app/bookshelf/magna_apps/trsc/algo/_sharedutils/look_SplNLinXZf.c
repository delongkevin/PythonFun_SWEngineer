/*
 * File: look_SplNLinXZf.c
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 */

#include "rtwtypes.h"
#include "plook_u32ff_linx.h"
#include "intrp_NSplf.h"
#include "rtsplntypes.h"
#include "look_SplNLinXZf.h"

/* n-D Spline interpolation function */
real32_T look_SplNLinXZf(uint32_T numDims, const real32_T* u, const
  rt_LUTSplineWork * const SWork)
{
  /*
   *   n-D column-major table lookup operating on real32_T with:
   *       - Spline interpolation
   *       - Linear extrapolation
   *       - Linear breakpoint search
   *       - Index search starts at the same place each time
   */
  rt_LUTnWork * const TWork_look = SWork->m_TWork;
  real32_T* const fraction = (real32_T*) TWork_look->m_bpLambda;
  uint32_T* const bpIdx = TWork_look->m_bpIndex;
  const uint32_T* const maxIndex = TWork_look->m_maxIndex;
  uint32_T k;
  for (k = 0U; k < numDims; k++) {
    const real32_T* const bpData = ((const real32_T * const *)
      TWork_look->m_bpDataSet)[k];
    bpIdx[k] = plook_u32ff_linx(u[k], bpData, maxIndex[k], &fraction[k]);
  }

  return(intrp_NSplf(numDims, SWork, 2U));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
