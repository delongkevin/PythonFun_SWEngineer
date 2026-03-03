/*
 * File: KM.h
 *
 * Code generated for Simulink model 'KM'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 29 21:10:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_KM_h_
#define RTW_HEADER_KM_h_
#include <math.h>
#include <string.h>
#ifndef KM_COMMON_INCLUDES_
# define KM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* KM_COMMON_INCLUDES_ */

#include "KM_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  real_T reset_KM;                     /* '<S1>/KM_Reset Decision Function' */
  real_T Delay5;                       /* '<S1>/Delay5' */
  real32_T DataTypeConversion2;        /* '<S1>/Data Type Conversion2' */
  real32_T DiscreteTimeIntegrator1[2]; /* '<S1>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator;     /* '<S1>/Discrete-Time Integrator' */
  real32_T MeKM_m_WhlCircum;           /* '<S1>/Gain' */
  real32_T Delay1;                     /* '<S1>/Delay1' */
  real32_T Delay2;                     /* '<S1>/Delay2' */
  real32_T Abs;                        /* '<S1>/Abs' */
  real32_T steering_XXcmat2;           /* '<S11>/steering_XXc.mat2' */
  real32_T whl_angl;                   /* '<S1>/Switch' */
  real32_T MeKM_m_WhlBase;             /* '<S12>/Multiport Switch' */
  real32_T speed_Rear_axle_mps;        /* '<S1>/Rear axle speed conversion ' */
  real32_T dx_dy_m[2];                 /* '<S1>/MATLAB Function3' */
  real32_T ds_Rear_axle_m;             /* '<S1>/MATLAB Function2' */
  real32_T direction;                  /* '<S1>/MATLAB Function' */
  real32_T whl_angl_n5um;              /* '<S1>/linear_gain' */
  real32_T Product;                    /* '<S1>/Product' */
  real32_T steering_XXcmat;            /* '<S11>/steering_XXc.mat' */
  real32_T steering_XXcmat1;           /* '<S11>/steering_XXc.mat1' */
  real32_T Delay8[2];                  /* '<S1>/Delay8' */
  real32_T Sign;                       /* '<S1>/Sign' */
  real32_T MeKM_deg_strAngtoWhlAng;    /* '<S11>/Multiport Switch' */
  boolean_T DataTypeConversion1;       /* '<S1>/Data Type Conversion1' */
  boolean_T LogicalOperator3;          /* '<S1>/Logical Operator3' */
  boolean_T RateTransition3;           /* '<S1>/Rate Transition3' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T Compare_b42h;              /* '<S4>/Compare' */
  boolean_T Delay7;                    /* '<S1>/Delay7' */
  boolean_T Delay6;                    /* '<S1>/Delay6' */
  boolean_T LogicalOperator5;          /* '<S1>/Logical Operator5' */
} B_KM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S1>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE;              /* '<S1>/Delay1' */
  real32_T Delay2_DSTATE;              /* '<S1>/Delay2' */
  boolean_T Delay4_DSTATE;             /* '<S1>/Delay4' */
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S1>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S1>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S1>/Delay1' */
  uint8_T icLoad_eoqx;                 /* '<S1>/Delay2' */
} DW_KM_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T heading_init;         /* '<S1>/heading_init' */
  const real32_T xy_init[2];           /* '<S1>/xy_init' */
} ConstB_KM_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: steering_XXcmat1_tableData
   * Referenced by: '<S11>/steering_XXc.mat1'
   */
  real32_T steering_XXcmat1_tableData[9];

  /* Computed Parameter: steering_XXcmat1_bp01Data
   * Referenced by: '<S11>/steering_XXc.mat1'
   */
  real32_T steering_XXcmat1_bp01Data[9];

  /* Computed Parameter: steering_XXcmat_tableData
   * Referenced by: '<S11>/steering_XXc.mat'
   */
  real32_T steering_XXcmat_tableData[9];

  /* Computed Parameter: steering_XXcmat_bp01Data
   * Referenced by: '<S11>/steering_XXc.mat'
   */
  real32_T steering_XXcmat_bp01Data[9];

  /* Computed Parameter: steering_XXcmat2_tableData
   * Referenced by: '<S11>/steering_XXc.mat2'
   */
  real32_T steering_XXcmat2_tableData[9];

  /* Computed Parameter: steering_XXcmat2_bp01Data
   * Referenced by: '<S11>/steering_XXc.mat2'
   */
  real32_T steering_XXcmat2_bp01Data[9];
} ConstP_KM_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T potMap_reset_KM;           /* '<Root>/potMap_reset_KM' */
  real32_T RHRWheelSpeedData;          /* '<Root>/RHRWheelSpeedData' */
  real32_T LHRWheelSpeedData;          /* '<Root>/LHRWheelSpeedData' */
  real32_T RHR_FastPulseCounterData;   /* '<Root>/RHR_FastPulseCounterData' */
  real32_T LHR_FastPulseCounterData;   /* '<Root>/LHR_FastPulseCounterData' */
  uint8_T GearEngagedData;             /* '<Root>/GearEngagedData' */
  real32_T LwsAngleData;               /* '<Root>/LwsAngleData' */
  uint8_T IePRX_e_VehWhlBase;          /* '<Root>/IePRX_e_VehWhlBase' */
  uint16_T IePRX_mm_TyreSize;          /* '<Root>/IePRX_mm_TyreSize' */
  uint8_T IePRX_e_StrRatRckPinionTyp;  /* '<Root>/IePRX_e_StrRatRckPinionTyp' */
} ExtU_KM_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T m_Global_x;                 /* '<Root>/m_Global_x ' */
  real32_T m_Global_y;                 /* '<Root>/m_Global_y ' */
  real32_T heading_MABx;               /* '<Root>/heading_MABx' */
  real32_T ds;                         /* '<Root>/ds' */
  real32_T dx_m;                       /* '<Root>/dx_m' */
  real32_T dy_m;                       /* '<Root>/dy_m' */
  real32_T dyaw;                       /* '<Root>/dyaw' */
} ExtY_KM_T;

/* Block signals (default storage) */
extern B_KM_T KM_B;

/* Block states (default storage) */
extern DW_KM_T KM_DW;

extern const ConstB_KM_T KM_ConstB;    /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_KM_T KM_ConstP;

/* Model entry point functions */
extern void KM_initialize(void);
extern void KM_step(void);

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
 * '<Root>' : 'KM'
 * '<S1>'   : 'KM/Kinematic Model1'
 * '<S2>'   : 'KM/Kinematic Model1/Compare To Zero'
 * '<S3>'   : 'KM/Kinematic Model1/Compare To Zero1'
 * '<S4>'   : 'KM/Kinematic Model1/Compare To Zero2'
 * '<S5>'   : 'KM/Kinematic Model1/KM_Reset Decision Function'
 * '<S6>'   : 'KM/Kinematic Model1/MATLAB Function'
 * '<S7>'   : 'KM/Kinematic Model1/MATLAB Function2'
 * '<S8>'   : 'KM/Kinematic Model1/MATLAB Function3'
 * '<S9>'   : 'KM/Kinematic Model1/MATLAB Function4'
 * '<S10>'  : 'KM/Kinematic Model1/Rear axle speed conversion '
 * '<S11>'  : 'KM/Kinematic Model1/StrTypeSel'
 * '<S12>'  : 'KM/Kinematic Model1/VCWhlBaseSel'
 */

/*-
 * Requirements for '<Root>': KM
 */
#endif                                 /* RTW_HEADER_KM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
