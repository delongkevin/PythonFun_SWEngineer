/*
 * File: ME_VehOut_TRSC.h
 *
 * Code generated for Simulink model 'TRSC_OutputAdapter'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:50 2025
 */

#ifndef RTW_HEADER_ME_VehOut_TRSC_h_
#define RTW_HEADER_ME_VehOut_TRSC_h_
#include "TeTRSC_e_SpdLmtReq.h"
#include "TeTRSC_e_VehStpReq.h"
#include "TeTRSC_e_TRSCLedSts.h"
#include "TeTRSC_e_TRSCPopupDispInfo.h"
#include "TeTRSC_e_TRSCSts.h"
#include "TeTRSC_e_TRSCStrTrqActvReq.h"
#include "TeTRSC_e_TrlrHitchLightCtrl.h"
#include "TeTRSC_e_TADAngActSign.h"
#include "TeTRSC_e_TrlrCalInfo.h"
#include "TeTRSC_e_VehStpReq_DID.h"
#include "rtwtypes.h"

typedef struct {
  TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq;
  TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq;
  TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts;
  TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo;
  TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;
  TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq;
  TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl;
  real32_T IeTRSC_M_TRSCStrTrq;
  real32_T IeTRSC_pct_TRSCStrDmp;
  uint8_T IeTRSC_deg_TADAngAct;
  TeTRSC_e_TADAngActSign IeTRSC_e_TADAngActSign;
  TeTRSC_e_TrlrCalInfo IeTRSC_e_TrlrCalInfo;
  boolean_T IeTRSC_b_MoreCamReqSts;
  real32_T IeTRSC_kph_SpdLmtReq_DID;
  TeTRSC_e_VehStpReq_DID IeTRSC_e_VehStpReq_DID;
} ME_VehOut_TRSC_t;

#endif                                 /* RTW_HEADER_ME_VehOut_TRSC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
