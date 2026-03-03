/*
 * File: TbTRSC_InpBus.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TbTRSC_InpBus_h_
#define RTW_HEADER_TbTRSC_InpBus_h_
#include "TbTRSC_VehInpFromCAN2.h"
#include "TbTRSC_VehInpFromCAN14.h"
#include "TbTRSC_TrailerDetInp.h"
#include "TbTRSC_MEProxiToIpc.h"
#include "TbTRSC_SVStoTRSC.h"
#include "TbDDC_DegMgrToTRSC.h"
#include "TbTRSCSmVc_TunParam.h"
#include "rtwtypes.h"

typedef struct {
  TbTRSC_VehInpFromCAN2 IbTRSC_VehInpFromCAN2;
  TbTRSC_VehInpFromCAN14 IbTRSC_VehInpFromCAN14;
  TbTRSC_TrailerDetInp IbTRSC_TrailerDetInp;
  TbTRSC_MEProxiToIpc IbTRSC_MEProxiToIpc;
  TbTRSC_SVStoTRSC IbTRSC_SVStoTRSC;
  TbDDC_DegMgrToTRSC IbDDC_DegMgrToTRSC;
  TbTRSCSmVc_TunParam_t IbTRSCSmVc_TunParam;
  uint8_T MeTRSC_e_CamBlockSts;
  boolean_T MeTRSC_b_InternalFault;
} TbTRSC_InpBus;

#endif                                 /* RTW_HEADER_TbTRSC_InpBus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
