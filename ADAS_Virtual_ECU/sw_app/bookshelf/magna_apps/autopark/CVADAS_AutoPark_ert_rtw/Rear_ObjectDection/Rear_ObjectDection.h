/*
 * File: Rear_ObjectDection.h
 *
 * Code generated for Simulink model 'Rear_ObjectDection'.
 *
 * Model version                  : 1.200
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:48:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rear_ObjectDection_h_
#define RTW_HEADER_Rear_ObjectDection_h_
#include <math.h>
#include <string.h>
#ifndef Rear_ObjectDection_COMMON_INCLUDES_
# define Rear_ObjectDection_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rear_ObjectDection_COMMON_INCLUDES_ */

#include "Rear_ObjectDection_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CeAP_cm_CurbLatchDist          170.0F                    /* Referenced by: '<S2>/Curb_Dbnc' */
#define CeAP_deg_MinSteerCurvature     10.0F                     /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */
#define CeAP_k_CurbDbnc                20U                       /* Referenced by: '<S2>/Curb_Dbnc' */
#define CeAP_k_SingleNegOne            -1.0F                     /* Referenced by:
                                                                  * '<S6>/whl_base4'
                                                                  * '<S11>/Gain'
                                                                  * '<S18>/Saturation'
                                                                  */
#define CeAP_k_SingleOne               1.0F                      /* Referenced by:
                                                                  * '<S6>/whl_base3'
                                                                  * '<S18>/Saturation'
                                                                  */
#define CeAP_k_SingleTwo               2.0F                      /* Referenced by:
                                                                  * '<S6>/Constant8'
                                                                  * '<S12>/Constant2'
                                                                  */
#define CeAP_k_SingleZero              2.0F                      /* Referenced by:
                                                                  * '<S6>/Switch'
                                                                  * '<S11>/Constant'
                                                                  * '<S12>/Saturation'
                                                                  * '<S17>/Constant'
                                                                  */
#define CeAP_k_Uint8One                1U                        /* Referenced by:
                                                                  * '<S2>/CalculateRearBrakingDistance1'
                                                                  * '<S15>/NeighbourCheck'
                                                                  * '<S16>/NeighbourCheck'
                                                                  */
#define CeAP_k_Uint8Zero               0U                        /* Referenced by:
                                                                  * '<S2>/CalculateRearBrakingDistance1'
                                                                  * '<S15>/NeighbourCheck'
                                                                  * '<S16>/NeighbourCheck'
                                                                  */
#define KeAP_k_RaebCruiseAgeThd        6U                        /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */
#define KeAP_pct_CurbConfThd           78U                       /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */
#define KePA_cm_RearCurbDetectLatThd   15                        /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */
#define KePA_cm_RearCurbDetectLongThd  10                        /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */
#define KePA_cnt_RearCurbPntCntThd     3U                        /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for system '<S21>/GetPointData' */
#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  int16_T Saturation1;                 /* '<S22>/Saturation1' */
} B_GetPointData_Rear_ObjectDection_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

/* Block signals for system '<S7>/CalcDistToObjStraight' */
#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Subtract;                   /* '<S12>/Subtract' */
  real32_T Abs;                        /* '<S12>/Abs' */
  real32_T Switch;                     /* '<S12>/Switch' */
  boolean_T RelationalOperator;        /* '<S12>/Relational Operator' */
} B_CalcDistToObjStraight_Rear_ObjectDection_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

/* Block signals for system '<S7>/GetPointData' */
#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  int16_T Saturation1;                 /* '<S13>/Saturation1' */
} B_GetPointData_Rear_ObjectDection_n_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

/* Block signals for model 'Rear_ObjectDection' */
#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  US_S_PointOutputBuff_t PointMapData[96];
                                      /* '<S2>/CalculateRearBrakingDistance1' */
  US_S_PointOutputBuff_t CurrentPoint;/* '<S2>/CalculateRearBrakingDistance1' */
  US_S_PointOutputBuff_t PointMapData_l[96];
                                      /* '<S2>/CalculateRearBrakingDistance1' */
  US_S_PointOutputBuff_t PointMapData_c[96];
                                      /* '<S2>/CalculateRearBrakingDistance1' */
  US_S_PointOutputBuff_t CurrentPoint_j;
                                      /* '<S2>/CalculateRearBrakingDistance1' */
  US_S_PointOutputBuff_t PointMapData_b[96];/* '<S16>/NeighbourCheck' */
  US_S_PointOutputBuff_t Selector;     /* '<S24>/Selector' */
  US_S_PointOutputBuff_t Selector_d;   /* '<S13>/Selector' */
  US_S_PointOutputBuff_t BusCreator1;  /* '<S14>/Bus Creator1' */
  US_S_PointOutputBuff_t PointMapData_k[96];/* '<S15>/NeighbourCheck' */
  US_S_PointOutputBuff_t Selector_e;   /* '<S22>/Selector' */
  US_S_PointOutputBuff_t Selector_eb;  /* '<S1>/Selector' */
  real32_T Abs;                        /* '<S6>/Abs' */
  real32_T steering_XXcmat2;           /* '<S10>/steering_XXc.mat2' */
  real32_T MeAP_cm_RearMaxRadius;      /* '<S6>/sq7' */
  real32_T MeAP_cm_RearMinRadius;      /* '<S6>/sq8' */
  real32_T MeAP_cm_RotCenterX;         /* '<S6>/Data Type Conversion3' */
  real32_T MeAP_cm_RotCenterY;         /* '<S6>/Signal Conversion' */
  real32_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  real32_T Saturation;                 /* '<S2>/Saturation' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay;                  /* '<Root>/Unit Delay' */
  real32_T MeAP_cm_floatRearDistCalc;  /* '<S4>/Signal Conversion3' */
  real32_T MeAP_b_CurbFiltered;        /* '<S2>/Curb_Dbnc' */
  real32_T MeAP_cm_RearBrakingDist;   /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T MeAP_b_ObjDetected;        /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T CurbDist;                  /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T pt_x;                      /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T pt_y;                      /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T Cx;                        /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T Cy;                        /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T Rmax;                      /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T Rmin;                      /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T AdjDist;                   /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T pt_x_i;                    /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T pt_y_p;                    /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T AdjDist_h;                 /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T PointMapIndex;              /* '<S16>/NeighbourCheck' */
  real32_T DataTypeConversion;         /* '<S24>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S24>/Data Type Conversion1' */
  real32_T DataTypeConversion_j;       /* '<S13>/Data Type Conversion' */
  real32_T DataTypeConversion1_o;      /* '<S13>/Data Type Conversion1' */
  real32_T DistanceObject;             /* '<S12>/Saturation' */
  real32_T Subtract1;                  /* '<S11>/Subtract1' */
  real32_T Subtract2;                  /* '<S11>/Subtract2' */
  real32_T Dist_pt2c;                  /* '<S11>/sq' */
  real32_T Subtract3;                  /* '<S11>/Subtract3' */
  real32_T Sqrt;                       /* '<S11>/Sqrt' */
  real32_T Switch;                     /* '<S11>/Switch' */
  real32_T DistanceObject_i;           /* '<S11>/Switch1' */
  real32_T Gain;                       /* '<S11>/Gain' */
  real32_T PointMapIndex_n;            /* '<S15>/NeighbourCheck' */
  real32_T DataTypeConversion_e;       /* '<S22>/Data Type Conversion' */
  real32_T DataTypeConversion1_p;      /* '<S22>/Data Type Conversion1' */
  real32_T steering_XXcmat;            /* '<S10>/steering_XXc.mat' */
  real32_T steering_XXcmat1;           /* '<S10>/steering_XXc.mat1' */
  real32_T Divide3;                    /* '<S3>/Divide3' */
  real32_T MeAP_cm_RearDist;           /* '<Root>/Switch1' */
  real32_T Subtract2_c;                /* '<Root>/Subtract2' */
  real32_T Add;                        /* '<S1>/Add' */
  real32_T Add2;                       /* '<S6>/Add2' */
  real32_T Abs_d;                      /* '<S20>/Abs' */
  real32_T MeAP_cnt_RRDistCompFactor;  /* '<S1>/Switch' */
  real32_T MeAP_cm_floatRearDistCalc_c;/* '<S4>/Switch' */
  real32_T Merge;                      /* '<S11>/Merge' */
  real32_T Abs_i;                      /* '<S11>/Abs' */
  real32_T Dist_CMPSampleTime;         /* '<S3>/Divide2' */
  real32_T MeAP_cm_RrAxlRadius;        /* '<S6>/Signal Conversion1' */
  real32_T Switch_e;                   /* '<S20>/Switch' */
  real32_T MeAP_cm_AbsRrAxlRadius;     /* '<S6>/Abs1' */
  real32_T Abs1;                       /* '<S18>/Abs1' */
  real32_T Subtract3_p;                /* '<S6>/Subtract3' */
  int16_T Constant1;                   /* '<S6>/Constant1' */
  int16_T Saturation_e;                /* '<S16>/Saturation' */
  int16_T Saturation1;                 /* '<S16>/Saturation1' */
  int16_T Saturation2;                 /* '<S16>/Saturation2' */
  int16_T Saturation3;                 /* '<S16>/Saturation3' */
  int16_T Saturation_g;                /* '<S15>/Saturation' */
  int16_T Saturation1_p;               /* '<S15>/Saturation1' */
  int16_T Saturation2_a;               /* '<S15>/Saturation2' */
  int16_T Saturation3_l;               /* '<S15>/Saturation3' */
  int16_T Saturation3_j;               /* '<S6>/Saturation3' */
  uint8_T DataTypeConversion1_d;       /* '<S6>/Data Type Conversion1' */
  uint8_T MeAP_b_IsCurb;              /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T HeighConfCounts;            /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T WallLikeStructure;          /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T IsPoleStructure;            /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T PointMapIndex_h;            /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T OutportBufferForIsPole;      /* '<S16>/NeighbourCheck' */
  uint8_T IsPole;                      /* '<S16>/NeighbourCheck' */
  uint8_T Cruising_Age;
  uint8_T height;
  uint8_T OutportBufferForDiscardPoint;/* '<S15>/NeighbourCheck' */
  uint8_T DiscardPoint;                /* '<S15>/NeighbourCheck' */
  boolean_T MeAP_b_ObjDetected_p;      /* '<S4>/Logical Operator2' */
  boolean_T MeAP_b_ObjPresent;         /* '<S4>/Signal Conversion1' */
  boolean_T RelationalOperator;        /* '<S20>/Relational Operator' */
  boolean_T LogicalOperator3;          /* '<S4>/Logical Operator3' */
  boolean_T LogicalOperator;           /* '<S11>/Logical Operator' */
  boolean_T Compare;                   /* '<S17>/Compare' */
  boolean_T LogicalOperator_m;         /* '<Root>/Logical Operator' */
  B_GetPointData_Rear_ObjectDection_T GetPointData_nj;/* '<S23>/GetPointData' */
  B_GetPointData_Rear_ObjectDection_n_T GetPointData;/* '<S7>/GetPointData' */
  B_CalcDistToObjStraight_Rear_ObjectDection_T CalcDistToObjStraight;/* '<S7>/CalcDistToObjStraight' */
  B_GetPointData_Rear_ObjectDection_T GetPointData_n;/* '<S21>/GetPointData' */
} B_Rear_ObjectDection_c_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'Rear_ObjectDection' */
#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  US_S_PointOutputBuff_t Current_Pt;  /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<Root>/Unit Delay' */
  real32_T CurbDistStart;              /* '<S2>/Curb_Dbnc' */
  real32_T CurbBrkDistLatch1;          /* '<S2>/Curb_Dbnc' */
  real32_T WallDistStart;              /* '<S2>/Curb_Dbnc' */
  real32_T PoleDistStart;              /* '<S2>/Curb_Dbnc' */
  real32_T MaxDist;                   /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T current_point_x;           /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T current_point_y;           /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T DistanceToObject;          /* '<S2>/CalculateRearBrakingDistance1' */
  real32_T Subtract2_DWORK1;           /* '<Root>/Subtract2' */
  int16_T RrBrk_Pt_x;                 /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T is_active_c35_Rear_ObjectDection;/* '<S2>/Curb_Dbnc' */
  uint8_T FCDbncCount;                 /* '<S2>/Curb_Dbnc' */
  uint8_T CurbBrkDistLatch;            /* '<S2>/Curb_Dbnc' */
  uint8_T WallDistLatch;               /* '<S2>/Curb_Dbnc' */
  uint8_T WallDetectCount;             /* '<S2>/Curb_Dbnc' */
  uint8_T PoleDistLatch;               /* '<S2>/Curb_Dbnc' */
  uint8_T MeAP_b_IsCurb_prev;          /* '<S2>/Curb_Dbnc' */
  uint8_T MeAP_b_IsCurb_start;         /* '<S2>/Curb_Dbnc' */
  uint8_T WallLikeStructure_prev;      /* '<S2>/Curb_Dbnc' */
  uint8_T WallLikeStructure_start;     /* '<S2>/Curb_Dbnc' */
  uint8_T IsPoleStructure_prev;        /* '<S2>/Curb_Dbnc' */
  uint8_T IsPoleStructure_start;       /* '<S2>/Curb_Dbnc' */
  uint8_T current_point_confidence;   /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T point_index;                /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T RearIdx;                    /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T RearPointsArray[10];        /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T RearHighIdx;                /* '<S2>/CalculateRearBrakingDistance1' */
  uint8_T RearHighPointsArray[10];    /* '<S2>/CalculateRearBrakingDistance1' */
  boolean_T TmpModelReferenceSubsystem_MODE;/* synthesized block */
} DW_Rear_ObjectDection_f_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'Rear_ObjectDection' */
#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  const boolean_T MeAP_b_IsObjHigh;    /* '<S4>/Logical Operator1' */
} ConstB_Rear_ObjectDection_h_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_Rear_ObjectDection_T {
  const char_T **errorStatus;
};

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Rear_ObjectDection_T rtm;
} MdlrefDW_Rear_ObjectDection_T;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

extern void Rear_ObjectDection_Init(real32_T *rty_MeAP_cm_RearDist, int16_T
  *rty_MeAP_cm_RawRearDist);
extern void Rear_ObjectDection_Reset(void);
extern void Rear_ObjectDection_Disable(real32_T *rty_MeAP_cm_RearDist, boolean_T
  *rty_MeAP_b_ObjInPath, int16_T *rty_MeAP_cm_RawRearDist);
extern void Rear_ObjectDection(const TbVBIA_VehState_AP *rtu_VehStates, const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData, const real32_T
  *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const
  TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const uint8_T
  *rtu_EnableBrakingTriggered, const boolean_T *rtu_Enable, real32_T
  *rty_MeAP_cm_RearDist, boolean_T *rty_MeAP_b_ObjInPath, int16_T
  *rty_MeAP_cm_RawRearDist);

/* Model reference registration function */
extern void Rear_ObjectDection_initialize(const char_T **rt_errorStatus);

#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

extern void Rear_ObjectDection_GetPointData(const US_S_PointOutputBuff_t
  rtu_PointMapData[96], real32_T rtu_PointMapIndex, real32_T *rty_pt_x, real32_T
  *rty_pt_y, US_S_PointOutputBuff_t *rty_pt_confidence,
  B_GetPointData_Rear_ObjectDection_T *localB);
extern void Rear_ObjectDection_CalcDistToObjStraight(real32_T rtu_pt_x, real32_T
  rtu_pt_y, real32_T rtu_AdjDist, real32_T *rty_DistanceObject,
  B_CalcDistToObjStraight_Rear_ObjectDection_T *localB);
extern void Rear_ObjectDection_GetPointData_n(const US_S_PointOutputBuff_t
  rtu_PointMapData[96], uint8_T rtu_PointMapIndex, real32_T *rty_pt_x, real32_T *
  rty_pt_y, US_S_PointOutputBuff_t *rty_pt_confidence, uint8_T
  *rty_pt_CruisingAge, uint8_T *rty_pt_height,
  B_GetPointData_Rear_ObjectDection_n_T *localB);

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern real32_T CONST_DPS2RPS;         /* Referenced by: '<S6>/whl_base5' */

/* conversion parameter from degree/s to rad/s */
extern real32_T K_e_RAEB_DrawingTubeOffset;/* Referenced by:
                                            * '<S6>/Constant2'
                                            * '<S12>/Constant2'
                                            */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_VehicleWidth; /* Referenced by: '<S12>/Constant2' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_WarnOffset;   /* Referenced by:
                                        * '<S6>/Constant2'
                                        * '<S12>/Constant2'
                                        */

/* To feed lateral offset to issue warning */
extern boolean_T KeAP_b_RearDistCorrBasedVehSpd;/* Referenced by: '<Root>/Constant' */
extern uint8_T KeAP_b_SupprsUssGlblHght;/* Referenced by: '<S4>/Constant3' */
extern int16_T KeAP_cm_DistZone2;      /* Referenced by: '<S2>/Curb_Dbnc' */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_NhXmaxOffset;   /* Referenced by: '<S15>/Constant1' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhXminOffset;   /* Referenced by: '<S15>/Constant' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYmaxOffset;   /* Referenced by: '<S15>/Constant3' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYminOffset;   /* Referenced by: '<S15>/Constant2' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_RearLongDistAdj;/* Referenced by: '<S6>/Constant1' */

/* Longitudanl Distance from Rear Axle to Rear edge of vehicle */
extern real32_T KeAP_cnt_NoiseModeRearDistComp;/* Referenced by: '<S1>/DelayFact1' */
extern real32_T KeAP_cnt_RearDistCompTimeThd;/* Referenced by: '<S1>/DelayFact3' */
extern uint8_T KeAP_pct_ObjConfidenceThd;/* Referenced by: '<S2>/Constant11' */

/* Detected Object Confidence threshold */
extern uint8_T KePA_b_EnFeatPointSplitImp;
                       /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */

/* Enable NeighboutHood Window */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint8_T CeAP_k_CurbArrayInit[10];
                       /* Referenced by: '<S2>/CalculateRearBrakingDistance1' */

#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

extern MdlrefDW_Rear_ObjectDection_T Rear_ObjectDection_MdlrefDW;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

#ifndef Rear_ObjectDection_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_Rear_ObjectDection_c_T Rear_ObjectDection_B;

/* Block states (default storage) */
extern DW_Rear_ObjectDection_f_T Rear_ObjectDection_DW;

#endif                                 /*Rear_ObjectDection_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Rear_ObjectDection'
 * '<S1>'   : 'Rear_ObjectDection/CompensationValue'
 * '<S2>'   : 'Rear_ObjectDection/RearBrakingDistCalc'
 * '<S3>'   : 'Rear_ObjectDection/Subsystem'
 * '<S4>'   : 'Rear_ObjectDection/ValidObjectDist'
 * '<S5>'   : 'Rear_ObjectDection/CompensationValue/Compare To Constant'
 * '<S6>'   : 'Rear_ObjectDection/RearBrakingDistCalc/CalcHeadingChange'
 * '<S7>'   : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1'
 * '<S8>'   : 'Rear_ObjectDection/RearBrakingDistCalc/Curb_Dbnc'
 * '<S9>'   : 'Rear_ObjectDection/RearBrakingDistCalc/CalcHeadingChange/DivWithZeroProtection'
 * '<S10>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalcHeadingChange/StrTypeSel'
 * '<S11>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/CalcDistToObjCurved'
 * '<S12>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/CalcDistToObjStraight'
 * '<S13>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/GetPointData'
 * '<S14>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/InitalisePointData'
 * '<S15>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/NeighbourHoodCheck'
 * '<S16>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/NeighbourHoodCheckForPole'
 * '<S17>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/CalcDistToObjCurved/Compare To Constant'
 * '<S18>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/CalcDistToObjCurved/ObjPtInPath'
 * '<S19>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/CalcDistToObjCurved/ObjPtNotInPath'
 * '<S20>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/CalcDistToObjCurved/ObjPtInPath/DivWithZeroProtection'
 * '<S21>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/NeighbourHoodCheck/NeighbourCheck'
 * '<S22>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/NeighbourHoodCheck/NeighbourCheck/GetPointData'
 * '<S23>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/NeighbourHoodCheckForPole/NeighbourCheck'
 * '<S24>'  : 'Rear_ObjectDection/RearBrakingDistCalc/CalculateRearBrakingDistance1/NeighbourHoodCheckForPole/NeighbourCheck/GetPointData'
 */
#endif                                 /* RTW_HEADER_Rear_ObjectDection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
