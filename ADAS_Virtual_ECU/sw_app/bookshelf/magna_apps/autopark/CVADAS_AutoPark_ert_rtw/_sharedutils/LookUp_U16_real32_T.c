/*
 * File: LookUp_U16_real32_T.c
 *
 * Code generated for Simulink model 'SWC_APA'.
 *
 * Model version                  : 1.591
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:53:24 2025
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_real32_T.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "LookUp_U16_real32_T.h"

/* Lookup Utility LookUp_U16_real32_T */
void LookUp_U16_real32_T(uint16_T *pY, const uint16_T *pYData, real32_T u, const
  real32_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real32_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = (real_T)pYData[iLeft];
      yRghtCast = (real_T)pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );

      {
        real_T rtb_dbl_tmp;
        rtb_dbl_tmp = floor(yLeftCast);
        if (rtIsNaN(rtb_dbl_tmp) || rtIsInf(rtb_dbl_tmp)) {
          rtb_dbl_tmp = 0.0;
        } else {
          rtb_dbl_tmp = fmod(rtb_dbl_tmp, 65536.0);
        }

        (*pY) = rtb_dbl_tmp < 0.0 ? (uint16_T)(int16_T)-(int16_T)(uint16_T)
          -rtb_dbl_tmp : (uint16_T)rtb_dbl_tmp;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
