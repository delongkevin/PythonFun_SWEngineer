/*
 * File: TbTRSC_MEProxiToIpc.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TbTRSC_MEProxiToIpc_h_
#define RTW_HEADER_TbTRSC_MEProxiToIpc_h_
#include "TeTRSC_e_VehWhlBase.h"
#include "TeTRSC_e_RadDsplyTyp.h"
#include "TeTRSC_e_StrRackPinTyp.h"
#include "rtwtypes.h"

typedef struct {
  real32_T IePRX_mm_VehTyreSize;
  TeTRSC_e_VehWhlBase IePRX_e_VehWhlBase;
  TeTRSC_e_RadDsplyTyp IePRX_e_RadDsplyTyp;
  TeTRSC_e_StrRackPinTyp IePRX_e_StrRackPinTyp;
  uint8_T IePRX_e_BoxDelete;
  boolean_T IePRX_b_CanNode63Ttm;
  boolean_T IePRX_b_CanNode95ItbmItcm;
  boolean_T IePRX_b_CanNode27AsmAscm;
  boolean_T IePRX_b_SRT;
  boolean_T IePRX_b_SVSPresent;
  boolean_T IePRX_b_AuxTrlrCam;
  boolean_T IePRX_b_TrlrSurroundPresence;
  boolean_T IePRX_b_TRSCPresent;
} TbTRSC_MEProxiToIpc;

#endif                                 /* RTW_HEADER_TbTRSC_MEProxiToIpc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
