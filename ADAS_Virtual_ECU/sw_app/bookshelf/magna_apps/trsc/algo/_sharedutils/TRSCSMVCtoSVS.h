/*
 * File: TRSCSMVCtoSVS.h
 *
 * Code generated for Simulink model 'TRSC_OutputAdapter'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:50 2025
 */

#ifndef RTW_HEADER_TRSCSMVCtoSVS_h_
#define RTW_HEADER_TRSCSMVCtoSVS_h_
#include "TeTRSC_e_TRSCStat.h"
#include "TeTRSC_e_TrlrCalInfo.h"
#include "rtwtypes.h"

typedef struct {
  TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;
  TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfoSMVC;
  real32_T MeTRSC_deg_JackKnifeAngle;
  real32_T MeTRSC_deg_JackknifeThrAngle;
  real32_T MeTRSC_deg_MaxAllowedTADAngle;
  real32_T MeTRSC_deg_KnobAngle;
  real32_T MeTRSC_M_SteeringTorqInfo;
  real32_T MeTRSC_deg_TADAngleSMVC;
  real32_T ReservedSignal1;
  real32_T ReservedSignal2;
  boolean_T MeTRSC_b_MoreCamSoftButtEnbl;
  boolean_T MeTRSC_b_TrlrRevSteeringStsInfo;
} TRSCSMVCtoSVS_t;

#endif                                 /* RTW_HEADER_TRSCSMVCtoSVS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
