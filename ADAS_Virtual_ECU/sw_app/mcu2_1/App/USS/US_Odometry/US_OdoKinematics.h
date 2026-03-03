
/*PRQA S ALL EOF */
/*
 * File: US_OdoKinematic.h
 *
 * Code generated for Simulink model 'Kinematic'.
 *
 * Model version                  : 1.6980
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Dec  3 10:30:35 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. Traceability
 *    5. Safety precaution
 *    6. Debugging
 *    7. MISRA C:2012 guidelines
 *    8. Polyspace
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Kinematic_h_
#define RTW_HEADER_Kinematic_h_
//#include <float.h>
#include <math.h>
#include <string.h>
#ifndef Kinematic_COMMON_INCLUDES_
    #define Kinematic_COMMON_INCLUDES_
    #include "US_OdoRtwType.h"
#endif                                 /* Kinematic_COMMON_INCLUDES_ */

#include "US_OdoKinematics_types.h"
#include "US_PlatformCfg_Global.h"

#if (US_D_USE_EXTERNAL_ODOMETRY == ME_FALSE)


#define ME_FLT_EPSILON  1.19209290E-07F
#define ME_DBL_EPSILON  2.2204460492503131E-16

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Delay1;                       /* '<S1>/Delay1' */
  real_T Delay2;                       /* '<S1>/Delay2' */
  real_T whl_angl;                     /* '<S1>/Switch' */
  real_T Delay3;                       /* '<S1>/Delay3' */
  real_T Counter;                      /* '<S1>/Counter' */
  real_T whl_angl_e;                   /* '<S1>/linear_gain' */
  real_T Sign;                         /* '<S1>/Sign' */
  real_T Abs;                          /* '<S1>/Abs' */
  real_T TestBasedLookupTable;         /* '<S1>/Test Based Lookup Table' */
  real_T Product;                      /* '<S1>/Product' */
  real32_T Delay5;                     /* '<S1>/Delay5' */
  real32_T DiscreteTimeIntegrator1[2]; /* '<S1>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator;     /* '<S1>/Discrete-Time Integrator' */
  real32_T speed_Rear_axle_mps;        /* '<S1>/Rear axle speed conversion ' */
  real32_T heading_MABx;               /* '<S1>/MATLAB Function4' */
  real32_T dx_dy_m[2];                 /* '<S1>/MATLAB Function3' */
  real32_T ds_Rear_axle_m;             /* '<S1>/MATLAB Function2' */
  real32_T d_heading_deg;              /* '<S1>/MATLAB Function2' */
  real32_T reset_KM;                   /* '<S1>/KM_Reset Decision Function' */
  int8_T direction;                    /* '<S1>/MATLAB Function' */
  boolean_T DataTypeConversion1;       /* '<S1>/Data Type Conversion1' */
  boolean_T Delay4;                    /* '<S1>/Delay4' */
  boolean_T LogicalOperator4;          /* '<S1>/Logical Operator4' */
  boolean_T LogicalOperator3;          /* '<S1>/Logical Operator3' */
  boolean_T RateTransition3;           /* '<S1>/Rate Transition3' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T Compare_c;                 /* '<S3>/Compare' */
  boolean_T Compare_l;                 /* '<S4>/Compare' */
  boolean_T LogicalOperator5;          /* '<S1>/Logical Operator5' */
} B_Kinematic_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S1>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S1>/Delay3' */
  real32_T Delay5_DSTATE;              /* '<S1>/Delay5' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S1>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  boolean_T Delay4_DSTATE;             /* '<S1>/Delay4' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S1>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S1>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S1>/Delay1' */
  uint8_T icLoad_b;                    /* '<S1>/Delay2' */
  boolean_T RateTransition3_Buffer0;   /* '<S1>/Rate Transition3' */
} DW_Kinematic_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real32_T xy_init[2];           /* '<S1>/xy_init' */
  const real32_T heading_init;         /* '<S1>/heading_init' */
  const real32_T Jeep;                 /* '<S1>/Jeep' */
  const real32_T TestBasedLookupTable1;/* '<S1>/Test Based Lookup Table1' */
  const real32_T whl_ang_deg;          /* '<S1>/whl_ang_deg' */
} ConstB_Kinematic_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: [1.67 3.47 5.38 7.25 8.97 10.57 12.18 13.88 15.67 17.41 19.00 20.45 21.82 23.18 24.58 25.99 27.34 28.59 29.70 30.68 31.56 32.35 33.05 33.68 34.23 34.70 35.07]
   * Referenced by: '<S1>/Test Based Lookup Table'
   */
  real_T TestBasedLookupTable_tableData[7];

  /* Expression: [31.1 62.2 93.1 123.7 154.0 183.8 213.2 242.0 270.1 297.5 324.0 349.7 374.4 398.1 420.7 442.1 462.3 481.3 498.9 515.2 530.1 543.5 555.4 565.8 574.6 581.9 587.6]
   * Referenced by: '<S1>/Test Based Lookup Table'
   */
  real_T TestBasedLookupTable_bp01Data[7];
} ConstP_Kinematic_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T potMap_reset_KM;              /* '<Root>/potMap_reset_KM' */
  real_T RR;                           /* '<Root>/WheelSpeed_Report.RR' */
  real_T RL;                           /* '<Root>/WheelSpeed_Report.RL' */
  real_T RR_p;                         /* '<Root>/WheelPosition_Report.RR' */
  real_T RL_p;                         /* '<Root>/WheelPosition_Report.RL' */
  uint8_T Gear_RPT_STATE;              /* '<Root>/Gear_Report.Gear_RPT_STATE' */
  real_T ANGLE;                        /* '<Root>/Steering_Report.ANGLE' */
  real32_T whl_Circum;
  real32_T whl_Base;
  real32_T max_Tick;
  real32_T avg_Tick;
  real32_T num_Pulses;
} ExtU_Kinematic_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T X_MABx;                     /* '<Root>/X_MABx' */
  real32_T Y_MABx;                     /* '<Root>/Y_MABx' */
  real32_T heading_MABx;               /* '<Root>/heading_MABx' */
  real32_T Outport1;                   /* '<Root>/Outport1' */
  real32_T Outport2;                   /* '<Root>/Outport2' */
  real32_T Outport3;                   /* '<Root>/Outport3' */
  real32_T Outport4;                   /* '<Root>/Outport4' */
} ExtY_Kinematic_T;

/* Real-time Model Data Structure */
struct tag_RTM_Kinematic_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_Kinematic_T Kinematic_B;

/* Block states (auto storage) */
extern DW_Kinematic_T Kinematic_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Kinematic_T Kinematic_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Kinematic_T Kinematic_Y;

/* Model entry point functions */
extern void Kinematic_initialize(void);
extern void Kinematic_step(void);
extern void Kinematic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Kinematic_T *const Kinematic_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('AP_ver8_codeGen/Kinematic Model')    - opens subsystem AP_ver8_codeGen/Kinematic Model
 * hilite_system('AP_ver8_codeGen/Kinematic Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AP_ver8_codeGen'
 * '<S1>'   : 'AP_ver8_codeGen/Kinematic Model'
 * '<S2>'   : 'AP_ver8_codeGen/Kinematic Model/Compare To Zero'
 * '<S3>'   : 'AP_ver8_codeGen/Kinematic Model/Compare To Zero1'
 * '<S4>'   : 'AP_ver8_codeGen/Kinematic Model/Compare To Zero2'
 * '<S5>'   : 'AP_ver8_codeGen/Kinematic Model/KM_Reset Decision Function'
 * '<S6>'   : 'AP_ver8_codeGen/Kinematic Model/MATLAB Function'
 * '<S7>'   : 'AP_ver8_codeGen/Kinematic Model/MATLAB Function1'
 * '<S8>'   : 'AP_ver8_codeGen/Kinematic Model/MATLAB Function2'
 * '<S9>'   : 'AP_ver8_codeGen/Kinematic Model/MATLAB Function3'
 * '<S10>'  : 'AP_ver8_codeGen/Kinematic Model/MATLAB Function4'
 * '<S11>'  : 'AP_ver8_codeGen/Kinematic Model/Rear axle speed conversion '
 */


#endif

#endif                                 /* RTW_HEADER_Kinematic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
