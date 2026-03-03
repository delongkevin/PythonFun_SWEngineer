/*
 * File: FeatureArbiter.h
 *
 * Code generated for Simulink model 'FeatureArbiter'.
 *
 * Model version                  : 1.309
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov  9 17:38:22 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FeatureArbiter_h_
#define RTW_HEADER_FeatureArbiter_h_
#include <string.h>
#ifndef FeatureArbiter_COMMON_INCLUDES_
# define FeatureArbiter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FeatureArbiter_COMMON_INCLUDES_ */

#include "FOD_Input_Output.h" //Added here as currently definition is available here
#include "FeatureArbiter_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  TbAP_DriveAssistStatOut_t MbFA_DriveAssistStatOut;/* '<S12>/Data Store Read2' */
  TbTHASmVc_FeatureOutputs_t MbFA_THASmVcOut;/* '<S12>/Data Store Read1' */
  TbAP_RPAWarnOut_t MbFA_RPAWarnOut;   /* '<S12>/Data Store Read4' */
  TbAP_PAStateOut_t MbFA_PAStateOut;   /* '<S12>/Data Store Read5' */
  TbAP_FPAWarnOut_t MbFA_FPAWarnOut;   /* '<S12>/Data Store Read3' */
  TbFA_ChimeStatus MbFA_DefaultChimeData;/* '<S7>/Bus Creator3' */
  TbFA_ChimeStatus MbFA_APAChimeData;  /* '<S13>/Bus Creator2' */
  TbFA_ChimeStatus MbFA_THAChimeData;  /* '<S13>/Bus Creator1' */
  TbFA_ChimeStatus Switch1;            /* '<S4>/Switch1' */
  TbFA_ChimeStatus Switch2;            /* '<S4>/Switch2' */
  TbFA_ChimeStatus MbFA_SelChimeData;  /* '<S4>/Switch' */
  TbFA_ArbiterOutput_t TbFA_ArbiterOutput_t_bnzj;/* '<S3>/Bus Creator1' */
  TbAP_USSStateOut_t MbFA_USSFiringModeOut;/* '<S12>/Data Store Read7' */
  TbAP_SMPAInternalOut_t MbFA_SMPAInternalOut;/* '<S12>/Data Store Read6' */
  TbAP_SMDAInternalOut_t MbFA_SMDAInternalOut;/* '<S12>/Data Store Read8' */
  TbFA_USSStateOutput_t BusCreator;    /* '<S3>/Bus Creator' */
  TbFA_ResetKM_t BusCreator2;          /* '<S3>/Bus Creator2' */
  IFOD_Outputs_Arbitration_t FOD_Outputs_Arbitration;/* '<S12>/Data Store Read9' */
  TeFA_e_PamVol IeFA_e_PamVol;         /* '<S3>/Data Type Conversion13' */
  TeFA_e_PamChimeTyp IeFA_e_PamChimeTyp;/* '<S3>/Data Type Conversion2' */
  TeFA_e_PamChimeRepRateSts IeFA_e_PamChimeRepRateSts;/* '<S3>/Data Type Conversion1' */
  TeAutoPark_e_AutoParkStatus IeAP_e_AutoParkStatus;/* '<S13>/Data Type Conversion11' */
  uint8_T Switch4;                     /* '<S6>/Switch4' */
  uint8_T MeFOD_e_USSFiringMode;       /* '<S13>/Data Type Conversion8' */
  uint8_T IeFA_e_USSFiringMode;        /* '<S3>/Data Type Conversion7' */
  boolean_T MeFA_b_ChimeActvLhf;       /* '<S13>/Data Type Conversion3' */
  boolean_T MeFA_b_ChimeActvRhf;       /* '<S13>/Data Type Conversion4' */
  boolean_T LogicalOperator;           /* '<S4>/Logical Operator' */
  boolean_T Switch6;                   /* '<S5>/Switch6' */
  boolean_T RelationalOperator1;       /* '<S6>/Relational Operator1' */
  boolean_T IeFOD_b_ResetKM;           /* '<S13>/Data Type Conversion9' */
  boolean_T RelationalOperator3;       /* '<S5>/Relational Operator3' */
  boolean_T MeFA_b_THAChimeReq;        /* '<S13>/Logical Operator1' */
  boolean_T LogicalOperator1;          /* '<S4>/Logical Operator1' */
  boolean_T IeFA_b_ChimeActvRhr;       /* '<S3>/Data Type Conversion12' */
  boolean_T LogicalOperator_lhui;      /* '<S5>/Logical Operator' */
  boolean_T MeFA_b_RPAStatus;          /* '<S13>/Data Type Conversion6' */
  boolean_T MeFA_b_FPAStatus;          /* '<S13>/Data Type Conversion7' */
} B_FeatureArbiter_T;

/* Block signals (default storage) */
extern B_FeatureArbiter_T FeatureArbiter_B;

/* Model entry point functions */
extern "C" void FeatureArbiter_initialize(void);
extern "C" void FeatureArbiter_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FeatureArbiter'
 * '<S1>'   : 'FeatureArbiter/FeatureArbiter_Core'
 * '<S2>'   : 'FeatureArbiter/Input_Adapter'
 * '<S3>'   : 'FeatureArbiter/Output_Adapter'
 * '<S4>'   : 'FeatureArbiter/FeatureArbiter_Core/Chime_Arbitration'
 * '<S5>'   : 'FeatureArbiter/FeatureArbiter_Core/ResetKM_Arbitration'
 * '<S6>'   : 'FeatureArbiter/FeatureArbiter_Core/USSFiringMode_Arbitration'
 * '<S7>'   : 'FeatureArbiter/FeatureArbiter_Core/Chime_Arbitration/Default_Value'
 * '<S8>'   : 'FeatureArbiter/FeatureArbiter_Core/Chime_Arbitration/Default_Value/Enumerated Constant'
 * '<S9>'   : 'FeatureArbiter/FeatureArbiter_Core/Chime_Arbitration/Default_Value/Enumerated Constant1'
 * '<S10>'  : 'FeatureArbiter/FeatureArbiter_Core/Chime_Arbitration/Default_Value/Enumerated Constant2'
 * '<S11>'  : 'FeatureArbiter/FeatureArbiter_Core/ResetKM_Arbitration/Enumerated Constant'
 * '<S12>'  : 'FeatureArbiter/Input_Adapter/DataStoreMemoryRead'
 * '<S13>'  : 'FeatureArbiter/Input_Adapter/FA_Translater'
 */

/*-
 * Requirements for '<Root>': FeatureArbiter
 */
#endif                                 /* RTW_HEADER_FeatureArbiter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
