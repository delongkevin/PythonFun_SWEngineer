/*
 * File: TbTRSC_VehInpFromCAN2.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TbTRSC_VehInpFromCAN2_h_
#define RTW_HEADER_TbTRSC_VehInpFromCAN2_h_
#include "TeVBII_e_CmdIgnSts.h"
#include "TeVBII_e_TrailerConnectionSts.h"
#include "TeVBII_e_TrlrPrsntSts.h"
#include "TeVBII_e_TchScrSts.h"
#include "TeVBII_e_TrscEnblBtnSts.h"
#include "TeVBII_e_GearRptState.h"
#include "TeVBII_e_SBR1RowDriverSeatSts.h"
#include "TeVBII_e_VehAscmSts.h"
#include "TeVBII_e_GearEngagedForDsply.h"
#include "TeVBII_e_CenterBtnSts.h"
#include "TeVBII_e_EnblBtnSts.h"
#include "TeVBII_e_ShiftLvrPos.h"
#include "TeVBII_e_TGWCamDispSts.h"
#include "TeVBII_e_CamDispSts.h"
#include "TeVBII_e_CustTrlrType.h"
#include "rtwtypes.h"

typedef struct {
  real32_T IeVBII_px_TchXCoord;
  real32_T IeVBII_px_TchYCoord;
  real32_T IeVBII_mm_VehFlLvl;
  real32_T IeVBII_mm_VehFrLvl;
  real32_T IeVBII_mm_VehRlLvl;
  real32_T IeVBII_mm_VehRrLvl;
  TeVBII_e_CmdIgnSts IeVBII_e_CmdIgnSts;
  TeVBII_e_TrailerConnectionSts IeVBII_e_TrailerConnectionSts;
  TeVBII_e_TrlrPrsntSts IeVBII_e_TrlrPrsntSts;
  TeVBII_e_TchScrSts IeVBII_e_TchScrSts;
  TeVBII_e_TrscEnblBtnSts IeVBII_e_TrscEnblBtnSts;
  TeVBII_e_GearRptState IeVBII_e_GearRptState;
  TeVBII_e_SBR1RowDriverSeatSts IeVBII_e_SBR1RowDriverSeatSts;
  TeVBII_e_VehAscmSts IeVBII_e_VehAscmSts;
  TeVBII_e_GearEngagedForDsply IeVBII_e_GearEngagedForDsply;
  TeVBII_e_CenterBtnSts IeVBII_e_CenterBtnSts;
  TeVBII_e_EnblBtnSts IeVBII_e_EnblBtnSts;
  TeVBII_e_ShiftLvrPos IeVBII_e_ShiftLvrPos;
  TeVBII_e_TGWCamDispSts IeVBII_e_TGWCamDispSts;
  TeVBII_e_CamDispSts IeVBII_e_CamDispSts;
  TeVBII_e_CustTrlrType IeVBII_e_CustTrlrType;
  uint16_T IeVBII_k_KnobAngl;
  boolean_T IeVBII_b_DriverDoorSts;
  boolean_T IeVBII_b_TrnkStatus;
  boolean_T IeVBII_e_VehFlLvlAdj;
  boolean_T IeVBII_e_VehFrLvlAdj;
  boolean_T IeVBII_e_VehRlLvlAdj;
  boolean_T IeVBII_e_VehRrLvlAdj;
  boolean_T IeVBII_b_VehAscmSysFail;
} TbTRSC_VehInpFromCAN2;

#endif                                 /* RTW_HEADER_TbTRSC_VehInpFromCAN2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
