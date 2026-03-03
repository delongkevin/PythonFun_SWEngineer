/*
 * File: TRSCtoDiagMgr.h
 *
 * Code generated for Simulink model 'TRSC_OutputAdapter'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:50 2025
 */

#ifndef RTW_HEADER_TRSCtoDiagMgr_h_
#define RTW_HEADER_TRSCtoDiagMgr_h_
#include "TeVBII_e_EnblBtnSts.h"
#include "TeTRSC_e_TRSKMBtnSts_DID.h"
#include "TeVBII_e_CenterBtnSts.h"
#include "TeTRSC_e_TRSKMCenBtnSts_DID.h"
#include "TeTRSC_e_TRSKMSts.h"
#include "TeTRSC_e_TRSKMSts_DID.h"
#include "TeVBII_e_GearEngagedForDsply.h"
#include "TeTRSC_e_GearShiftSts_DID.h"
#include "TeTRSC_e_TRSCUnavailReas_DID.h"
#include "TeTRSC_e_TRSCAbortReason_DID.h"
#include "TeTRSC_e_DispView2_DID.h"
#include "TeTRSC_e_GraphicOverlay_Sts.h"
#include "rtwtypes.h"
#include "../code/TRSC_SMVC_Defines.h"

typedef struct {
  TeVBII_e_EnblBtnSts IeTRSC_e_TRSKMBtnSts;
  TeTRSC_e_TRSKMBtnSts_DID IeTRSC_e_TRSKMBtnSts_DID;
  TeVBII_e_CenterBtnSts IeTRSC_e_TRSKMCenBtnSts;
  TeTRSC_e_TRSKMCenBtnSts_DID IeTRSC_e_TRSKMCenBtnSts_DID;
  TeTRSC_e_TRSKMSts IeTRSC_e_TRSKMSts;
  TeTRSC_e_TRSKMSts_DID IeTRSC_e_TRSKMSts_DID;
  TeVBII_e_GearEngagedForDsply IeTRSC_e_GearShiftSts;
  TeTRSC_e_GearShiftSts_DID IeTRSC_e_GearShiftSts_DID;
  uint32_T IeTRSC_e_TRSCUnavailReas;
  TeTRSC_e_TRSCUnavailReas_DID IeTRSC_e_TRSCUnavailReas_DID;
  uint32_T IeTRSC_e_TRSCAbortReas;
  TeTRSC_e_TRSCAbortReason_DID IeTRSC_e_TRSCAbortReas_DID;
  real32_T IeTRSC_kph_VehSpeedVSOSig;
  real32_T IeTRSC_m_TrlrWhlBaseEff;
  real32_T IeTRSC_deg_FrntWhlAng;
  real32_T IeTRSC_deg_TrlrAngKnob;
  real32_T IeTRSC_deg_JackknifeThrAngle;
  real32_T IeTRSC_M_TRSCStrTrq;
  uint16_T IeTRSC_cnt_KnobPos;
  TeTRSC_e_DispView2_DID MeSVS_e_DispView2Info_DID;
  TeTRSC_e_GraphicOverlay_Sts IeTRSC_e_GraphicOverlay_Sts;
} TRSCtoDiagMgr_t;

#endif                                 /* RTW_HEADER_TRSCtoDiagMgr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
