/*
 * File: LookUp_real32_T_S32.c
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.1843
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Apr 15 11:32:47 2024
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_S32.h"
#include "LookUp_real32_T_S32.h"

/* Lookup Utility LookUp_real32_T_S32 */
void LookUp_real32_T_S32(real32_T *pY, const real32_T *pYData, int32_T u, const
  int32_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_S32( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      int32_T num;
      int32_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = ((real_T)num) / ((real_T)den);
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = (real_T)pYData[iLeft];
      yRghtCast = (real_T)pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = (real32_T)yLeftCast;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
