/*
 * File: LookUpEven_real_Treal32_T_real32_T.c
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.1843
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Apr 15 11:32:47 2024
 */

#include "rtwtypes.h"
#include "LookUpEven_real_Treal32_T_real32_T.h"

/* Lookup 1D UtilityLookUpEven_real_Treal32_T_real32_T */
void LookUpEven_real_Treal32_T_real32_T(real_T *pY, const real32_T *pYData,
  real32_T u, real32_T valueLo, uint32_T iHi, real32_T uSpacing)
{
  if (u <= valueLo ) {
    (*pY) = (real_T)(*pYData);
  } else {
    real32_T uAdjusted = u - valueLo;
    real32_T tmpIdxLeft = uAdjusted / uSpacing;
    uint32_T iLeft = (uint32_T)tmpIdxLeft;
    if ((tmpIdxLeft >= 4294967296.0f) || (iLeft >= iHi) ) {
      (*pY) = (real_T)pYData[iHi];
    } else {
      {
        real_T lambda;

        {
          real32_T num = (real32_T)uAdjusted - ( iLeft * uSpacing );
          lambda = ((real_T)num) / ((real_T)uSpacing);
        }

        {
          real_T yLeftCast;
          real_T yRghtCast;
          yLeftCast = (real_T)pYData[iLeft];
          yRghtCast = (real_T)pYData[((iLeft)+1)];
          yLeftCast += lambda * ( yRghtCast - yLeftCast );
          (*pY) = yLeftCast;
        }
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
