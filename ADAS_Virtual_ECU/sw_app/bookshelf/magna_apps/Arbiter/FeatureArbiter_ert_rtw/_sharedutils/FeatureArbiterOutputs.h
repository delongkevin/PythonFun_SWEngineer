/*
 * File: FeatureArbiterOutputs.h
 *
 * Code generated for Simulink model 'FeatureArbiter'.
 *
 * Model version                  : 1.304
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Oct 19 19:24:47 2023
 */

#ifndef RTW_HEADER_FeatureArbiterOutputs_h_
#define RTW_HEADER_FeatureArbiterOutputs_h_
#include "TeFA_e_PamChimeRepRateSts.h"
#include "TeFA_e_PamChimeTyp.h"
#include "TeFA_e_PamVol.h"
#include "rtwtypes.h"

typedef struct {
  boolean_T IeFA_b_ChimeActvLhf;
  boolean_T IeFA_b_ChimeActvRhf;
  boolean_T IeFA_b_ChimeActvLhr;
  boolean_T IeFA_b_ChimeActvRhr;
  TeFA_e_PamChimeRepRateSts IeFA_e_PamChimeRepRateSts;
  TeFA_e_PamChimeTyp IeFA_e_PamChimeTyp;
  TeFA_e_PamVol IeFA_e_PamVol;
} TbFA_ArbiterOutput_t;

typedef struct {
  uint8_T IeFA_e_USSFiringMode;
} TbFA_USSStateOutput_t;

typedef struct {
  boolean_T MeFA_b_ResetKM;
} TbFA_ResetKM_t;

#endif                                 /* RTW_HEADER_FeatureArbiterOutputs_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
