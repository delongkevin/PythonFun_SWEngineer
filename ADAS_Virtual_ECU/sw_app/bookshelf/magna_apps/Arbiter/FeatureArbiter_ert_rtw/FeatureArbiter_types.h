/*
 * File: FeatureArbiter_types.h
 *
 * Code generated for Simulink model 'FeatureArbiter'.
 *
 * Model version                  : 1.304
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Oct 19 19:24:47 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FeatureArbiter_types_h_
#define RTW_HEADER_FeatureArbiter_types_h_
#include "rtwtypes.h"
#include "TeAutoPark_e_AutoParkStatus.h"
#include "TeTHA_e_THAState.h"
#include "TeTHA_e_THASpdLimReq.h"
#include "TeTHA_e_PamVol.h"
#include "TeTHA_e_PamChimeTyp.h"
#include "TeTHA_e_PamChimeRepRateSts.h"
#include "TeTHA_e_THASteerTrqReq.h"
#include "TeTHA_e_THARmpUpDwnSpd.h"
#include "TeTHA_e_EPBReq.h"
#include "TeTHA_e_THAStateInfo.h"
#include "TeTHA_e_ScreenRequest.h"
#include "TeTHA_e_RearBrkSupprInfo.h"
#include "THAFeatureOutputs.h"
#include "TeAP_e_USSSupplyPwrSt.h"
#include "TeAP_e_USSSystemMode.h"
#include "TeAP_e_USSSystemState.h"
#include "SM_ModelOutput.h"
#include "TeAutoPark_e_ChimeReq.h"
#include "TeAutoPark_e_ScanDir.h"
#include "TeAP_e_AlgoState.h"
#include "TeAP_e_ParKMnvrActv.h"
#include "TeAP_e_InterfaceBSM.h"
#include "TeAP_e_SPMLatCtrlReqSts.h"
#include "TeAP_e_PAMLedCtrlStatus.h"
#include "TeAP_e_SPMActvStat.h"
#include "TeAP_e_DispView2.h"
#include "TeAP_e_GearShiftReq.h"
#include "TeAP_e_PAMVolSig.h"
#include "TeAP_e_PAMChimeTyp.h"
#include "TeAP_e_PAMChimeRepnRate.h"
#include "TeAP_e_Alert.h"
#include "TeAP_e_GraphicFlshRate.h"
#include "APA_ModelOutput.h"
#include "TeAP_e_PAMVolume.h"
#include "TeAP_e_PAMPopUpReq.h"
#include "TeAP_e_HMIPopUp.h"
#include "TeAP_e_ParkAssistStatus.h"
#include "TeAutoPark_e_GearCmd.h"
#include "PlatformDataTypes.h"
#include "FOD_Input_Output.h"
#include "FeatureArbiterOutputs.h"
#ifndef DEFINED_TYPEDEF_FOR_TbFA_ChimeStatus_
#define DEFINED_TYPEDEF_FOR_TbFA_ChimeStatus_

typedef struct {
  boolean_T MeFA_b_ChimeActvLhf;
  boolean_T MeFA_b_ChimeActvRhf;
  boolean_T MeFA_b_ChimeActvLhr;
  boolean_T MeFA_b_ChimeActvRhr;
  TeFA_e_PamChimeRepRateSts MeFA_e_PamChimeRepRateSts;
  TeFA_e_PamChimeTyp MeFA_e_PamChimeTyp;
  TeFA_e_PamVol MeFA_e_PamVol;
} TbFA_ChimeStatus;

#endif
#endif                                 /* RTW_HEADER_FeatureArbiter_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
