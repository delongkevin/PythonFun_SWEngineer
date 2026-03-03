/*
 * File: TbTRSC_VehInpFromCAN14.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TbTRSC_VehInpFromCAN14_h_
#define RTW_HEADER_TbTRSC_VehInpFromCAN14_h_
#include "TeVBII_e_SPMLatCtrlRespSts.h"
#include "TeVBII_e_EscTrscBrkResp.h"
#include "TeVBII_e_WhlSpnSts.h"
#include "TeVBII_e_StrWhlAngleType.h"
#include "TeVBII_e_EngineSts.h"
#include "TeVBII_e_EcmTrscResp.h"
#include "TeVBII_e_VehStandStillSts.h"
#include "TeVBII_e_StrTrqResp.h"
#include "rtwtypes.h"

typedef struct {
  real32_T IeVBII_M_StrWhlTrq;
  real32_T IeVBII_a_VehLatAcc;
  real32_T IeVBII_a_VehLongAcc;
  real32_T IeVBII_ddeg_VehYawRate;
  real32_T IeVBII_kph_VehSpeedVSOSig;
  real32_T IeVBII_kph_LhfWhlSpd;
  real32_T IeVBII_kph_LhrWhlSpd;
  real32_T IeVBII_kph_RhfWhlSpd;
  real32_T IeVBII_kph_RhrWhlSpd;
  real32_T IeVBII_a_VehLatAccOffset;
  real32_T IeVBII_a_VehLongAccOffset;
  real32_T IeVBII_deg_StrWhlAng;
  real32_T IeVBII_ddeg_StrWhlSpd;
  real32_T IeVBII_kph_RefVehSpd;
  TeVBII_e_SPMLatCtrlRespSts IeVBII_e_SPMLatCtrlRespSts;
  TeVBII_e_EscTrscBrkResp IeVBII_e_EscTrscBrkResp;
  TeVBII_e_WhlSpnSts IeVBII_e_LhfWhlSpnSts;
  TeVBII_e_WhlSpnSts IeVBII_e_RhfWhlSpnSts;
  TeVBII_e_WhlSpnSts IeVBII_e_LhrWhlSpnSts;
  TeVBII_e_WhlSpnSts IeVBII_e_RhrWhlSpnSts;
  TeVBII_e_StrWhlAngleType IeVBII_e_StrWhlAngleType;
  TeVBII_e_EngineSts IeVBII_e_EngineSts;
  TeVBII_e_EcmTrscResp IeVBII_e_EcmTrscResp;
  TeVBII_e_VehStandStillSts IeVBII_e_VehStandStillSts;
  TeVBII_e_StrTrqResp IeVBII_e_StrTrqResp;
  uint8_T IeVBII_cnt_LhfPulseCtr;
  uint8_T IeVBII_cnt_LhrPulseCtr;
  uint8_T IeVBII_cnt_RhfPulseCtr;
  uint8_T IeVBII_cnt_RhrPulseCtr;
  boolean_T IeVBII_b_StrTchSts;
} TbTRSC_VehInpFromCAN14;

#endif                                /* RTW_HEADER_TbTRSC_VehInpFromCAN14_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
