/*
 * File: BINARYSEARCH_real_Treal32_T_Near_iL.c
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_real_Treal32_T_Near_iL.h"

/* Lookup Binary Search Utility BINARYSEARCH_real_Treal32_T_Near_iL */
void BINARYSEARCH_real_Treal32_T_Near_iL(uint32_T *piLeft, real_T u, const
  real32_T *pData, uint32_T iHi)
{
  uint32_T iRght;
  real32_T uCast;

  /* cast current input to the data type/scaling of the table data */
  uCast = (real32_T)u;

  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  iRght = iHi;
  if (uCast < pData[0] ) {
    /* Less than the smallest point in the table. */
  } else if (uCast >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( iRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + iRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (uCast < pData[i] ) {
        iRght = i;
      } else {
        *piLeft = i;
      }
    }

    /* Adjust the left index, if necessary, so that it always gives */
    /* the index of the data point nearest the current input value. */
    {
      real_T diffLeft, diffRght;

      /* cast the table data points to the data type/scaling of the input */
      diffLeft = pData[*piLeft];
      diffRght = pData[iRght];
      diffLeft = u - diffLeft;
      diffRght = diffRght - u;
      if (diffRght <= diffLeft ) {
        *piLeft = iRght;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
