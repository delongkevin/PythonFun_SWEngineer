/*
 * File: FrontObjectDetection.h
 *
 * Code generated for Simulink model 'FrontObjectDetection'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Sep 26 17:23:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FrontObjectDetection_h_
#define RTW_HEADER_FrontObjectDetection_h_
#include <math.h>
#ifndef FrontObjectDetection_COMMON_INCLUDES_
# define FrontObjectDetection_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* FrontObjectDetection_COMMON_INCLUDES_ */

#include "FrontObjectDetection_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals (default storage) */
typedef struct {
  US_S_PointMapGroup_t USS_2DPointMap; /* '<S2>/USS_2DPointMap_data' */
  US_S_PointMapOutputBuff_t IbUSS_2DPointMap;/* '<S1>/Signal Conversion2' */
  APA_Calibration_data_MCU2_1_t IbAP_VrntTunParam;/* '<S2>/VrntTunParam_data' */
  TbFOD_InputVrntTunParam_t IbAP_InputVrntTunParam;/* '<S5>/Switch' */
  TbFOD_InputVrntTunParam_t BusCreator1;/* '<S5>/Bus Creator1' */
  TbFOD_InputVrntTunParam_t BusCreator;/* '<S5>/Bus Creator' */
  IKinematicData_t IbKM_KinematicData; /* '<S2>/VrntTunParam_data3' */
  real_T SFunction_o4;                 /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o5;                 /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o6;                 /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o7;                 /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o10;                /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o11;                /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o12;                /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o13;                /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o19;                /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o20;                /* '<S6>/CalculateMinDistances' */
  real_T SFunction_o21;                /* '<S6>/CalculateMinDistances' */
  real32_T dx_cm;                      /* '<S4>/Gain' */
  real32_T Nominator;                  /* '<S6>/CalculateMinDistances' */
  real32_T Denominator;                /* '<S6>/CalculateMinDistances' */
  real32_T LastGoodDist;               /* '<S6>/CalculateMinDistances' */
  real32_T VehTravelDist;              /* '<S6>/CalculateMinDistances' */
  real32_T Subtract;                   /* '<S12>/Subtract' */
  real32_T UpdatedLastGoodDist;        /* '<S12>/Switch' */
  real32_T UpdatedLastGoodDist_f;      /* '<S12>/Signal Conversion' */
  real32_T UpdatedLastGoodDist_fv;     /* '<S12>/Switch1' */
  real32_T UpdatedLastGoodDist_a;      /* '<S12>/Data Type Conversion1' */
  real32_T DivResult;                  /* '<S13>/Divide' */
  real32_T Abs3;                       /* '<S12>/Abs3' */
  real32_T Abs4;                       /* '<S12>/Abs4' */
  real32_T Switch;                     /* '<S13>/Switch' */
  real32_T Abs4_j;                     /* '<S7>/Abs4' */
  uint16_T UnitDelay2;                 /* '<S22>/Unit Delay2' */
  uint16_T Switch3;                    /* '<S22>/Switch3' */
  uint16_T Switch1;                    /* '<S22>/Switch1' */
  uint16_T Subtract_a;                 /* '<S22>/Subtract' */
  int16_T Saturation1;                 /* '<S10>/Saturation1' */
  int16_T Add8;                        /* '<S10>/Add8' */
  int16_T Gain;                        /* '<S10>/Gain' */
  int16_T Gain1;                       /* '<S10>/Gain1' */
  int16_T Gain2;                       /* '<S10>/Gain2' */
  int16_T Saturation6;                 /* '<S10>/Saturation6' */
  int16_T Gain3;                       /* '<S10>/Gain3' */
  int16_T Add9;                        /* '<S10>/Add9' */
  int16_T Saturation8;                 /* '<S10>/Saturation8' */
  int16_T Gain4;                       /* '<S10>/Gain4' */
  int16_T Gain5;                       /* '<S10>/Gain5' */
  int16_T Gain6;                       /* '<S10>/Gain6' */
  int16_T Saturation13;                /* '<S10>/Saturation13' */
  int16_T Gain7;                       /* '<S10>/Gain7' */
  int16_T Add10;                       /* '<S10>/Add10' */
  int16_T Abs1;                        /* '<S9>/Abs1' */
  int16_T UnitDelay;                   /* '<S17>/Unit Delay' */
  int16_T Abs;                         /* '<S9>/Abs' */
  int16_T UnitDelay_h;                 /* '<S16>/Unit Delay' */
  int16_T Divide;                      /* '<S17>/Divide' */
  int16_T Divide_o;                    /* '<S16>/Divide' */
  int16_T MeAP_cm_FrntSideMinXDistOut; /* '<S9>/DistDbncSide' */
  int16_T MeAP_cm_FrntCenterMinXDistOut;/* '<S9>/DistDbnc' */
  int16_T TmpSignalConversionAtSFunctionInport1[16];/* '<S6>/CalculateMinDistances' */
  int16_T TmpSignalConversionAtSFunctionInport2[16];/* '<S6>/CalculateMinDistances' */
  int16_T MeFOD_cm_FrntCenterMinXRawDist;/* '<S6>/CalculateMinDistances' */
  int16_T MeFOD_cm_FrntSideMinXRawDist;/* '<S6>/CalculateMinDistances' */
  int16_T RawDist;                     /* '<S6>/CalculateMinDistances' */
  int16_T ZoneDist;                    /* '<S6>/CalculateMinDistances' */
  int16_T UpdatedDist;                 /* '<S12>/Switch' */
  int16_T UpdatedDist_k;               /* '<S12>/Data Type Conversion2' */
  int16_T UpdatedDist_g;               /* '<S12>/Switch1' */
  int16_T Add;                         /* '<S17>/Add' */
  int16_T Add_f;                       /* '<S16>/Add' */
  int16_T Abs1_h;                      /* '<S12>/Abs1' */
  int16_T Abs2;                        /* '<S12>/Abs2' */
  int16_T Add7;                        /* '<S10>/Add7' */
  int16_T Saturation14;                /* '<S10>/Saturation14' */
  boolean_T RelationalOperator4;       /* '<S7>/Relational Operator4' */
  boolean_T LogicalOperator4;          /* '<S7>/Logical Operator4' */
  boolean_T MeAP_b_StandstillTimerRunning;/* '<S7>/Signal Conversion' */
  boolean_T HoldTracking;              /* '<S6>/CalculateMinDistances' */
  boolean_T SaveObjInfo;               /* '<S12>/Logical Operator1' */
  boolean_T LogicalOperator1;          /* '<S22>/Logical Operator1' */
  boolean_T LastObjDetectedInZone2;    /* '<S12>/Relational Operator' */
  boolean_T RelationalOperator;        /* '<S13>/Relational Operator' */
  boolean_T ElapseTimer;               /* '<S22>/Logical Operator3' */
  boolean_T TrackObj;                  /* '<S12>/Logical Operator' */
  boolean_T USSObjDetectedInZone2;     /* '<S12>/Relational Operator3' */
  boolean_T LogicalOperator4_h;        /* '<S12>/Logical Operator4' */
  boolean_T LogicalOperator;           /* '<S16>/Logical Operator' */
  boolean_T Compare;                   /* '<S18>/Compare' */
} B_FrontObjectDetection_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T LastGood_FrntCenterMinDist; /* '<S6>/CalculateMinDistances' */
  real32_T LastGood_FrntSideMinDist;   /* '<S6>/CalculateMinDistances' */
  int16_T MaxDist;                     /* '<S6>/CalculateMinDistances' */
  int16_T current_point_x;             /* '<S6>/CalculateMinDistances' */
  int16_T current_point_y;             /* '<S6>/CalculateMinDistances' */
  int16_T PrevSideFront_MeFOD_cm_ObjXPon;/* '<S6>/CalculateMinDistances' */
  int16_T PrevCenterFront_MeFOD_cm_ObjXPon;/* '<S6>/CalculateMinDistances' */
  int16_T DistanceToObject;            /* '<S6>/CalculateMinDistances' */
  uint16_T Timer;                      /* '<S9>/DistDbncSide' */
  uint16_T Timer_m;                    /* '<S9>/DistDbnc' */
  boolean_T UnitDelay1_DSTATE;         /* '<S23>/Unit Delay1' */
  uint8_T is_active_c2_FrontObjectDetection;/* '<S9>/DistDbncSide' */
  uint8_T is_c2_FrontObjectDetection;  /* '<S9>/DistDbncSide' */
  uint8_T is_DBNC_ENABLED;             /* '<S9>/DistDbncSide' */
  uint8_T is_active_c3_FrontObjectDetection;/* '<S9>/DistDbnc' */
  uint8_T is_c3_FrontObjectDetection;  /* '<S9>/DistDbnc' */
  uint8_T is_DBNC_ENABLED_h;           /* '<S9>/DistDbnc' */
  uint8_T current_point_confidence;    /* '<S6>/CalculateMinDistances' */
  boolean_T ObjInFront;                /* '<S6>/CalculateMinDistances' */
} DW_FrontObjectDetection_T;

/* Real-time Model Data Structure */
struct tag_RTM_FrontObjectDetection_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_FrontObjectDetection_T FrontObjectDetection_B;

/* Block states (default storage) */
extern DW_FrontObjectDetection_T FrontObjectDetection_DW;

/* Model entry point functions */
extern "C" void FrontObjectDetection_initialize(void);
extern "C" void FrontObjectDetection_step(void);
extern "C" void FrontObjectDetection_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern boolean_T KeFOD_b_DbncEnabld;   /* Referenced by: '<S9>/Constant2' */

/* Debounce for FOD Distance enabled */
extern int16_T KeFOD_cm_CenterWarnLatThreshold;/* Referenced by: '<S6>/Constant2' */

/* Parameter to decide center region */
extern int16_T KeFOD_cm_DistZone1; /* Referenced by: '<S5>/KeAP_cm_DistZone1' */

/* Warning Zone 1 Dist */
extern int16_T KeFOD_cm_DistZone2;     /* Referenced by:
                                        * '<S5>/KeAP_cm_DistZone2'
                                        * '<S6>/CalculateMinDistances'
                                        * '<S6>/Constant3'
                                        * '<S12>/Constant3'
                                        */

/* Warning Zone 2 Dist */
extern int16_T KeFOD_cm_DistZone3; /* Referenced by: '<S5>/KeAP_cm_DistZone3' */

/* Warning Zone 3 Dist */
extern int16_T KeFOD_cm_DistZone4;     /* Referenced by:
                                        * '<S5>/KeAP_cm_DistZone4'
                                        * '<S6>/Constant4'
                                        */

/* Warning Zone 4 Dist */
extern int16_T KeFOD_cm_DistZone5; /* Referenced by: '<S5>/KeAP_cm_DistZone5' */

/* Warning Zone 5 Dist */
extern int16_T KeFOD_cm_DistZone6;     /* Referenced by:
                                        * '<S5>/KeAP_cm_DistZone6'
                                        * '<S6>/Constant5'
                                        */

/* Warning Zone 6 Dist */
extern int16_T KeFOD_cm_HalfVehicleWidth;
                                   /* Referenced by: '<S5>/KeAP_cm_DistZone7' */

/* Ego Vehicle Car Half Width */
extern int16_T KeFOD_cm_SideDetectionRange;/* Referenced by: '<S6>/Constant' */

/* FOD Lateral Detection range */
extern int16_T KeFOD_cm_VehContour_FIL_x;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur1' */

/* X-coordinate for FIL Edge */
extern int16_T KeFOD_cm_VehContour_FIL_y;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur2' */

/* Y-coordinate for FIL Edge */
extern int16_T KeFOD_cm_VehContour_FIR_x;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur1' */

/* X-coordinate for FIR Edge */
extern int16_T KeFOD_cm_VehContour_FIR_y;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur2' */

/* Y-coordinate for FIR Edge */
extern int16_T KeFOD_cm_VehContour_FOL_x;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd1' */

/* X-coordinate for FOL Edge */
extern int16_T KeFOD_cm_VehContour_FOL_y;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd2' */

/* Y-coordinate for FOL Edge */
extern int16_T KeFOD_cm_VehContour_FOR_x;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur1' */

/* X-coordinate for FOR Edge */
extern int16_T KeFOD_cm_VehContour_FOR_y;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur2' */

/* Y-coordinate for FOR Edge */
extern int16_T KeFOD_cm_VehContour_FSL_x;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout1' */

/* X-coordinate for FSL Edge */
extern int16_T KeFOD_cm_VehContour_FSL_y;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout2' */

/* Y-coordinate for FSL Edge */
extern int16_T KeFOD_cm_VehContour_FSR_x;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur1' */

/* X-coordinate for FSR Edge */
extern int16_T KeFOD_cm_VehContour_FSR_y;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur2' */

/* Y-coordinate for FSR Edge */
extern int16_T KeFOD_cm_VehContour_RIL_x;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur3' */

/* X-coordinate for RIL Edge */
extern int16_T KeFOD_cm_VehContour_RIL_y;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur4' */

/* Y-coordinate for RIL Edge */
extern int16_T KeFOD_cm_VehContour_RIR_x;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur3' */

/* X-coordinate for RIR Edge */
extern int16_T KeFOD_cm_VehContour_RIR_y;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur4' */

/* Y-coordinate for RIR Edge */
extern int16_T KeFOD_cm_VehContour_ROL_x;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur3' */

/* X-coordinate for ROL Edge */
extern int16_T KeFOD_cm_VehContour_ROL_y;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur4' */

/* Y-coordinate for ROL Edge */
extern int16_T KeFOD_cm_VehContour_ROR_x;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd3' */

/* X-coordinate for ROR Edge */
extern int16_T KeFOD_cm_VehContour_ROR_y;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd4' */

/* Y-coordinate for ROR Edge */
extern int16_T KeFOD_cm_VehContour_RSL_x;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur3' */

/* X-coordinate for RSL Edge */
extern int16_T KeFOD_cm_VehContour_RSL_y;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur4' */

/* Y-coordinate for RSL Edge */
extern int16_T KeFOD_cm_VehContour_RSR_x;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout3' */

/* X-coordinate for RSR Edge */
extern int16_T KeFOD_cm_VehContour_RSR_y;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout4' */

/* Y-coordinate for RSR Edge */
extern int16_T KeFOD_cm_WarnOffset;/* Referenced by: '<S6>/KeAP_cm_DistZone1' */

/* Warn Offset Distance  */
extern uint16_T KeFOD_ms_DbncTimeThsd; /* Referenced by: '<S9>/Constant1' */

/* Debounce time for detected object */
extern uint8_T KeFOD_pct_ObjConfidenceThd;/* Referenced by: '<S6>/Constant11' */

/* Detected Object Confidence threshold */
extern uint8_T KeFOD_pct_ObjConfidenceThd_Closer;/* Referenced by: '<S6>/Constant6' */

/* Detected Object Confidence threshold closer objects */
extern uint8_T KeFOD_pct_ObjConfidenceThd_Far;/* Referenced by: '<S6>/Constant1' */

/* Detected Object Confidence threshold for farther objects */
extern uint8_T KeFOD_pct_ObjConfidenceThd_Nearest;/* Referenced by: '<S6>/Constant7' */

/* Detected Object Confidence threshold for nearest objects */
extern int16_T MeFOD_cm_FrntCenterMinXDist;/* '<S16>/Switch' */
extern int16_T MeFOD_cm_FrntSideMinXDist;/* '<S17>/Switch' */

/* Real-time Model object */
extern RT_MODEL_FrontObjectDetection_T *const FrontObjectDetection_M;

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
 * '<Root>' : 'FrontObjectDetection'
 * '<S1>'   : 'FrontObjectDetection/InputProcessing'
 * '<S2>'   : 'FrontObjectDetection/Input_Adapter'
 * '<S3>'   : 'FrontObjectDetection/ObjectMinDistanceCalculator'
 * '<S4>'   : 'FrontObjectDetection/InputProcessing/KM_InputProcessing'
 * '<S5>'   : 'FrontObjectDetection/InputProcessing/VrntTunParam'
 * '<S6>'   : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance'
 * '<S7>'   : 'FrontObjectDetection/ObjectMinDistanceCalculator/StandstillTimer'
 * '<S8>'   : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances'
 * '<S9>'   : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist'
 * '<S10>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/VehicleContourXY'
 * '<S11>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances/CalculateDistance.DivisionWithZeroProtection'
 * '<S12>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances/UpdateDistNoDetection'
 * '<S13>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances/CalculateDistance.DivisionWithZeroProtection/DivWithZeroProtection'
 * '<S14>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/DistDbnc'
 * '<S15>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/DistDbncSide'
 * '<S16>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg'
 * '<S17>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg'
 * '<S18>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg/Compare To Constant'
 * '<S19>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg/Compare To Constant1'
 * '<S20>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg/Compare To Constant'
 * '<S21>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg/Compare To Constant1'
 * '<S22>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/StandstillTimer/OffTimer'
 * '<S23>'  : 'FrontObjectDetection/ObjectMinDistanceCalculator/StandstillTimer/OffTimer/DetectIncChange'
 */
#endif                                 /* RTW_HEADER_FrontObjectDetection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
