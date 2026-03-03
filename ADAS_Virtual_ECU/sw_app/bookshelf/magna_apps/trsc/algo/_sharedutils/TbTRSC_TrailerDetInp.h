/*
 * File: TbTRSC_TrailerDetInp.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TbTRSC_TrailerDetInp_h_
#define RTW_HEADER_TbTRSC_TrailerDetInp_h_
#include "TeTRSC_e_TrlrCalInfo.h"
#include "TeTRSC_e_TrlrRecogInfo.h"
#include "TeTRSC_e_TrlrPrsntInfo.h"
#include "TeTRSC_e_TADState.h"
#include "TeTRSC_e_TADCalibrationSubstate.h"
#include "TeTRSC_e_TurnAroundSubState.h"
#include "rtwtypes.h"

typedef struct {
  real32_T MeTRSC_deg_TADAngle;
  real32_T MeTRSC_m_HitchLength;
  real32_T MeTRSC_deg_TADAngleRate;
  real32_T MeTRSC_deg_DetJackknifeThrAngle;
  real32_T MeTRSC_m_DetTrailerBeamLen;
  real32_T MeTRSC_deg_DetJackKnifeAngle;
  uint32_T MeTRSC_cnt_TrlrCalibFailCntInfo;
  TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfo;
  TeTRSC_e_TrlrRecogInfo MeTRSC_e_TrlrRecogInfo;
  TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfo;
  TeTRSC_e_TADState MeTRSC_e_TADState;
  TeTRSC_e_TADCalibrationSubstate MeTRSC_e_TADCalibrationSubstate;
  TeTRSC_e_TurnAroundSubState MeTRSC_e_TurnAroundSubState;
  boolean_T MeTRSC_b_OBTLRecalibrate;
  boolean_T MeTRSC_b_TrlrCalibDelayInfo;
} TbTRSC_TrailerDetInp;

#endif                                 /* RTW_HEADER_TbTRSC_TrailerDetInp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
