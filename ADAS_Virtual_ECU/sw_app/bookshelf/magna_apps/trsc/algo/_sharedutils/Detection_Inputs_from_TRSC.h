/*
 * File: Detection_Inputs_from_TRSC.h
 *
 * Code generated for Simulink model 'TRSC_OutputAdapter'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:50 2025
 */

#ifndef RTW_HEADER_Detection_Inputs_from_TRSC_h_
#define RTW_HEADER_Detection_Inputs_from_TRSC_h_
#include "TeTRSC_e_TRSCStat.h"
#include "TeTRSC_e_TrlrPrsntInfo.h"
#include "rtwtypes.h"

typedef struct {
  TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;
  real32_T MeTRSC_deg_JackKnifeAngle;
  real32_T MeTRSC_m_TrailerBeamLen;
  TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfoCAN;

  /* TRSC button pressed status */
  boolean_T MeTRSC_b_TRSCSwitchPressed;
  boolean_T MeTRSC_b_OTBLReset;
  boolean_T MeTRSC_b_TBLComputationDone;
} Detection_Inputs_from_TRSC_t;

#endif                            /* RTW_HEADER_Detection_Inputs_from_TRSC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
