/*
 * File: intrp_NSplf.c
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 */

#include "rtwtypes.h"
#include "rt_Spline2Derivf.h"
#include "rtsplntypes.h"
#include "intrp_NSplf.h"

/* n-D natural spline calculation function */
real32_T intrp_NSplf(uint32_T numDims, const rt_LUTSplineWork * const splWork,
                     uint32_T extrapMethod)
{
  uint32_T il;
  uint32_T iu, k, i;
  real32_T h, s, p, smsq, pmsq;

  /* intermediate results work areas "this" and "next" */
  const rt_LUTnWork *TWork_interp = (const rt_LUTnWork *)splWork->m_TWork;
  const real32_T *fraction = (real32_T *) TWork_interp->m_bpLambda;
  const real32_T *yp = (real32_T *) TWork_interp->m_tableData;
  real32_T *yyA = (real32_T *) splWork->m_yyA;
  real32_T *yyB = (real32_T *) splWork->m_yyB;
  real32_T *yy2 = (real32_T *) splWork->m_yy2;
  real32_T *up = (real32_T *) splWork->m_up;
  real32_T *y2 = (real32_T *) splWork->m_y2;
  const real32_T **bpDataSet = (const real32_T **) TWork_interp->m_bpDataSet;
  const real32_T *xp = bpDataSet[0U];
  real32_T *yy = yyA;
  uint32_T bufBank = 0U;
  uint32_T len = TWork_interp->m_maxIndex[0U] + 1U;

  /* Generate at-point splines in each dimension */
  for (k = 0U; k < numDims; k++ ) {
    /* this dimension's input setup */
    xp = bpDataSet[k];
    len = TWork_interp->m_maxIndex[k] + 1U;
    il = TWork_interp->m_bpIndex[k];
    iu = il + 1U;
    h = xp[iu] - xp[il];
    p = fraction[k];
    s = 1.0F - p;
    pmsq = p * ((p*p) - 1.0F);
    smsq = s * ((s*s) - 1.0F);

    /*
     * Calculate spline curves for input in this
     * dimension at each value of the higher
     * other dimensions\' points in the table.
     */
    if ((p > 1.0F) && (extrapMethod == 2U) ) {
      real32_T slope;
      for (i = 0U; i < splWork->m_numYWorkElts[k]; i++) {
        slope = (yp[iu] - yp[il]) + ((y2[il]*h*h)*(1.0F/6.0F));
        yy[i] = yp[iu] + (slope * (p-1.0F));
        yp = &yp[len];
        y2 = &y2[len];
      }
    } else if ((p < 0.0F) && (extrapMethod == 2U) ) {
      real32_T slope;
      for (i = 0U; i < splWork->m_numYWorkElts[k]; i++) {
        slope = (yp[iu] - yp[il]) - ((y2[iu]*h*h)*(1.0F/6.0F));
        yy[i] = yp[il] + (slope * p);
        yp = &yp[len];
        y2 = &y2[len];
      }
    } else {
      for (i = 0U; i < splWork->m_numYWorkElts[k]; i++) {
        yy[i] = yp[il] + p * (yp[iu] - yp[il]) +
          ((smsq * y2[il] + pmsq * y2[iu])*h*h)*(1.0F/6.0F);
        yp = &yp[len];
        y2 = &y2[len];
      }
    }

    /* set pointers to new result and calculate second derivatives */
    yp = yy;
    y2 = yy2;
    if (splWork->m_numYWorkElts[k+1U] > 0U ) {
      uint32_T nextLen = TWork_interp->m_maxIndex[k+1U] + 1U;
      const real32_T *nextXp = bpDataSet[k+1U];
      for (i = 0U; i < splWork->m_numYWorkElts[k+1U]; i++) {
        rt_Spline2Derivf(nextXp, yp, nextLen, up, y2);
        yp = &yp[nextLen];
        y2 = &y2[nextLen];
      }
    }

    /*
     * Set work vectors yp, y2 and yy for next iteration;
     * the yy just calculated becomes the yp in the
     * next iteration, y2 was just calculated for these
     * new points and the yy buffer is swapped to the space
     * for storing the next iteration\'s results.
     */
    yp = yy;
    y2 = yy2;

    /*
     * Swap buffers for next dimension and
     * toggle bufBank for next iteration.
     */
    if (bufBank == 0U) {
      yy = yyA;
      bufBank = 1U;
    } else {
      yy = yyB;
      bufBank = 0U;
    }
  }

  return( yp[0U] );
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
