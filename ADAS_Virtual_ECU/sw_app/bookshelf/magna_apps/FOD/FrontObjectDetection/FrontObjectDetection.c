/*
 * File: FrontObjectDetection.c
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

#include "FrontObjectDetection.h"
#include "FrontObjectDetection_private.h"
#define TEST_FOD_OFFLINE 0
/* Named constants for Chart: '<S9>/DistDbnc' */
#define FrontObjectDetection_IN_DBNC_DISABLED ((uint8_T)1U)
#define FrontObjectDetection_IN_DBNC_ENABLED ((uint8_T)2U)
#define FrontObjectDetection_IN_RESET_DBNC ((uint8_T)1U)
#define FrontObjectDetection_IN_SET_DBNC ((uint8_T)2U)

/* Exported data definition */

/* Definition for custom storage class: Default */
boolean_T KeFOD_b_DbncEnabld = 1;      /* Referenced by: '<S9>/Constant2' */

/* Debounce for FOD Distance enabled */
int16_T KeFOD_cm_CenterWarnLatThreshold = 62;/* Referenced by: '<S6>/Constant2' */

/* Parameter to decide center region */
int16_T KeFOD_cm_DistZone1 = 30;   /* Referenced by: '<S5>/KeAP_cm_DistZone1' */

/* Warning Zone 1 Dist */
int16_T KeFOD_cm_DistZone2 = 65;       /* Referenced by:
                                        * '<S5>/KeAP_cm_DistZone2'
                                        * '<S6>/CalculateMinDistances'
                                        * '<S6>/Constant3'
                                        * '<S12>/Constant3'
                                        */

/* Warning Zone 2 Dist */
int16_T KeFOD_cm_DistZone3 = 100;  /* Referenced by: '<S5>/KeAP_cm_DistZone3' */

/* Warning Zone 3 Dist */
int16_T KeFOD_cm_DistZone4 = 120;      /* Referenced by:
                                        * '<S5>/KeAP_cm_DistZone4'
                                        * '<S6>/Constant4'
                                        */

/* Warning Zone 4 Dist */
int16_T KeFOD_cm_DistZone5 = 150;  /* Referenced by: '<S5>/KeAP_cm_DistZone5' */

/* Warning Zone 5 Dist */
int16_T KeFOD_cm_DistZone6 = 200;      /* Referenced by:
                                        * '<S5>/KeAP_cm_DistZone6'
                                        * '<S6>/Constant5'
                                        */

/* Warning Zone 6 Dist */
int16_T KeFOD_cm_HalfVehicleWidth = 103;
                                   /* Referenced by: '<S5>/KeAP_cm_DistZone7' */

/* Ego Vehicle Car Half Width */
int16_T KeFOD_cm_SideDetectionRange = 100;/* Referenced by: '<S6>/Constant' */

/* FOD Lateral Detection range */
int16_T KeFOD_cm_VehContour_FIL_x = 462;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur1' */

/* X-coordinate for FIL Edge */
int16_T KeFOD_cm_VehContour_FIL_y = 32;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur2' */

/* Y-coordinate for FIL Edge */
int16_T KeFOD_cm_VehContour_FIR_x = 462;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur1' */

/* X-coordinate for FIR Edge */
int16_T KeFOD_cm_VehContour_FIR_y = -32;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur2' */

/* Y-coordinate for FIR Edge */
int16_T KeFOD_cm_VehContour_FOL_x = 448;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd1' */

/* X-coordinate for FOL Edge */
int16_T KeFOD_cm_VehContour_FOL_y = 77;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd2' */

/* Y-coordinate for FOL Edge */
int16_T KeFOD_cm_VehContour_FOR_x = 448;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur1' */

/* X-coordinate for FOR Edge */
int16_T KeFOD_cm_VehContour_FOR_y = -77;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur2' */

/* Y-coordinate for FOR Edge */
int16_T KeFOD_cm_VehContour_FSL_x = 436;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout1' */

/* X-coordinate for FSL Edge */
int16_T KeFOD_cm_VehContour_FSL_y = 92;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout2' */

/* Y-coordinate for FSL Edge */
int16_T KeFOD_cm_VehContour_FSR_x = 436;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur1' */

/* X-coordinate for FSR Edge */
int16_T KeFOD_cm_VehContour_FSR_y = -92;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur2' */

/* Y-coordinate for FSR Edge */
int16_T KeFOD_cm_VehContour_RIL_x = -122;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur3' */

/* X-coordinate for RIL Edge */
int16_T KeFOD_cm_VehContour_RIL_y = 33;
                    /* Referenced by: '<S5>/KeAP_s_PausedPressBtnTimeoutDur4' */

/* Y-coordinate for RIL Edge */
int16_T KeFOD_cm_VehContour_RIR_x = -122;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur3' */

/* X-coordinate for RIR Edge */
int16_T KeFOD_cm_VehContour_RIR_y = -33;
                         /* Referenced by: '<S5>/KeAP_s_ObjInPathTimeoutDur4' */

/* Y-coordinate for RIR Edge */
int16_T KeFOD_cm_VehContour_ROL_x = -116;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur3' */

/* X-coordinate for ROL Edge */
int16_T KeFOD_cm_VehContour_ROL_y = 81;
                         /* Referenced by: '<S5>/KeAP_s_SeekPhaseTimeoutDur4' */

/* Y-coordinate for ROL Edge */
int16_T KeFOD_cm_VehContour_ROR_x = -116;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd3' */

/* X-coordinate for ROR Edge */
int16_T KeFOD_cm_VehContour_ROR_y = -81;
                        /* Referenced by: '<S5>/KeAP_s_MaxStandstillTimeThd4' */

/* Y-coordinate for ROR Edge */
int16_T KeFOD_cm_VehContour_RSL_x = -95;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur3' */

/* X-coordinate for RSL Edge */
int16_T KeFOD_cm_VehContour_RSL_y = 92;
                                /* Referenced by: '<S5>/KeAP_s_SpdExceedDur4' */

/* Y-coordinate for RSL Edge */
int16_T KeFOD_cm_VehContour_RSR_x = -95;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout3' */

/* X-coordinate for RSR Edge */
int16_T KeFOD_cm_VehContour_RSR_y = -92;
                     /* Referenced by: '<S5>/KeAP_s_GearShiftWaitCntTimeout4' */

/* Y-coordinate for RSR Edge */
int16_T KeFOD_cm_WarnOffset = 30;  /* Referenced by: '<S6>/KeAP_cm_DistZone1' */

/* Warn Offset Distance  */
uint16_T KeFOD_ms_DbncTimeThsd = 230U; /* Referenced by: '<S9>/Constant1' */

/* Debounce time for detected object */
uint8_T KeFOD_pct_ObjConfidenceThd = 45U;/* Referenced by: '<S6>/Constant11' */

/* Detected Object Confidence threshold */
uint8_T KeFOD_pct_ObjConfidenceThd_Closer = 100U;/* Referenced by: '<S6>/Constant6' */

/* Detected Object Confidence threshold closer objects */
uint8_T KeFOD_pct_ObjConfidenceThd_Far = 100U;/* Referenced by: '<S6>/Constant1' */

/* Detected Object Confidence threshold for farther objects */
uint8_T KeFOD_pct_ObjConfidenceThd_Nearest = 45U;/* Referenced by: '<S6>/Constant7' */

/* Detected Object Confidence threshold for nearest objects */
int16_T MeFOD_cm_FrntCenterMinXDist;   /* '<S16>/Switch' */
int16_T MeFOD_cm_FrntSideMinXDist;     /* '<S17>/Switch' */

/* Block signals (default storage) */
B_FrontObjectDetection_T FrontObjectDetection_B;

/* Block states (default storage) */
DW_FrontObjectDetection_T FrontObjectDetection_DW;

/* Real-time model */
RT_MODEL_FrontObjectDetection_T FrontObjectDetection_M_;
RT_MODEL_FrontObjectDetection_T *const FrontObjectDetection_M =
  &FrontObjectDetection_M_;

/* Forward declaration for local functions */
static void FrontObjectDetection_IsValidObjectDistance(void);
static void FrontObjectDetection_CalculateDistance(void);
static void FrontObjectDetection_GetObjectPointRegion(void);

/* Function for Chart: '<S6>/CalculateMinDistances' */
static void FrontObjectDetection_IsValidObjectDistance(void)
{
  int32_T tmp;
  if (FrontObjectDetection_DW.ObjInFront &&
      (FrontObjectDetection_DW.DistanceToObject < 0)) {
    FrontObjectDetection_DW.DistanceToObject = FrontObjectDetection_DW.MaxDist;
  } else if (FrontObjectDetection_DW.ObjInFront &&
             ((FrontObjectDetection_DW.DistanceToObject > 300) &&
              (FrontObjectDetection_DW.current_point_confidence <
               KeFOD_pct_ObjConfidenceThd_Far))) {
    FrontObjectDetection_DW.DistanceToObject = FrontObjectDetection_DW.MaxDist;
  } else if (FrontObjectDetection_DW.ObjInFront &&
             ((FrontObjectDetection_DW.DistanceToObject > 200) &&
              (FrontObjectDetection_DW.DistanceToObject <= 300) &&
              (FrontObjectDetection_DW.current_point_confidence <
               KeFOD_pct_ObjConfidenceThd_Closer))) {
    FrontObjectDetection_DW.DistanceToObject = FrontObjectDetection_DW.MaxDist;
  } else if (FrontObjectDetection_DW.ObjInFront &&
             ((FrontObjectDetection_DW.DistanceToObject > 0) &&
              (FrontObjectDetection_DW.DistanceToObject <= 200) &&
              (FrontObjectDetection_DW.current_point_confidence <
               KeFOD_pct_ObjConfidenceThd_Nearest))) {
    FrontObjectDetection_DW.DistanceToObject = FrontObjectDetection_DW.MaxDist;
  } else {
    if ((!FrontObjectDetection_DW.ObjInFront) &&
        (FrontObjectDetection_DW.DistanceToObject > 0)) {
      tmp = -FrontObjectDetection_DW.MaxDist;
      if (tmp > 32767) {
        tmp = 32767;
      }

      FrontObjectDetection_DW.DistanceToObject = (int16_T)tmp;
    }
  }
}

/* Function for Chart: '<S6>/CalculateMinDistances' */
static void FrontObjectDetection_CalculateDistance(void)
{
  uint8_T ContourPtIdx;
  uint8_T NumberOfIterations;
  real32_T tmp;
  uint32_T qY;
  int32_T q0;
  int8_T tmp_0;
  int16_T tmp_1;
  int32_T tmp_2;
  boolean_T exitg1;
  NumberOfIterations = ((uint8_T)8U);
  tmp_0 = 1;
  if (1 < 0) {
    tmp_0 = 0;
  }

  ContourPtIdx = (uint8_T)tmp_0;
  FrontObjectDetection_DW.DistanceToObject = FrontObjectDetection_DW.MaxDist;
  FrontObjectDetection_DW.ObjInFront = true;
  if (FrontObjectDetection_DW.current_point_x < 0) {
    q0 = (int32_T)((uint32_T)((uint8_T)9U) + ((uint8_T)8U));
    if ((uint32_T)q0 > 255U) {
      q0 = 255;
    }

    tmp_0 = 1;
    if (1 < 0) {
      tmp_0 = 0;
    }

    qY = (uint32_T)q0 - /*MW:OvSatOk*/ tmp_0;
    if (qY > (uint32_T)q0) {
      qY = 0U;
    }

    NumberOfIterations = (uint8_T)qY;
    ContourPtIdx = ((uint8_T)9U);
    q0 = -FrontObjectDetection_DW.MaxDist;
    if (q0 > 32767) {
      q0 = 32767;
    }

    FrontObjectDetection_DW.DistanceToObject = (int16_T)q0;
    FrontObjectDetection_DW.ObjInFront = false;
  }

  exitg1 = false;
  while ((!exitg1) && (ContourPtIdx < NumberOfIterations)) {
    tmp_0 = 1;
    if (1 < 0) {
      tmp_0 = 0;
    }

    q0 = (int32_T)((uint32_T)ContourPtIdx + tmp_0);
    if ((uint32_T)q0 > 255U) {
      q0 = 255;
    }

    tmp_2 = ContourPtIdx - 1;
    if ((FrontObjectDetection_DW.current_point_y <=
         FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[tmp_2]) &&
        ((FrontObjectDetection_DW.current_point_y >=
          FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[q0 - 1]) &&
         FrontObjectDetection_DW.ObjInFront)) {
      q0 = FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[tmp_2] -
        FrontObjectDetection_DW.current_point_y;
      if (q0 > 32767) {
        q0 = 32767;
      } else {
        if (q0 < -32768) {
          q0 = -32768;
        }
      }

      FrontObjectDetection_B.Nominator = (real32_T)q0;
      tmp_0 = 1;
      if (1 < 0) {
        tmp_0 = 0;
      }

      q0 = (int32_T)((uint32_T)ContourPtIdx + tmp_0);
      if ((uint32_T)q0 > 255U) {
        q0 = 255;
      }

      q0 = FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[tmp_2] -
        FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[q0 - 1];
      if (q0 > 32767) {
        q0 = 32767;
      } else {
        if (q0 < -32768) {
          q0 = -32768;
        }
      }

      FrontObjectDetection_B.Denominator = (real32_T)q0;
      FrontObjectDetection_B.Switch = fabsf(FrontObjectDetection_B.Denominator);
      FrontObjectDetection_B.RelationalOperator = (FrontObjectDetection_B.Switch
        > 0.0001F);
      if (FrontObjectDetection_B.RelationalOperator) {
        FrontObjectDetection_B.Switch = FrontObjectDetection_B.Denominator;
      } else {
        FrontObjectDetection_B.Switch = 0.0001F;
      }

      FrontObjectDetection_B.DivResult = FrontObjectDetection_B.Nominator /
        FrontObjectDetection_B.Switch;
      tmp_0 = 1;
      if (1 < 0) {
        tmp_0 = 0;
      }

      q0 = (int32_T)((uint32_T)ContourPtIdx + tmp_0);
      if ((uint32_T)q0 > 255U) {
        q0 = 255;
      }

      q0 = FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[tmp_2] -
        FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[q0 - 1];
      if (q0 > 32767) {
        q0 = 32767;
      } else {
        if (q0 < -32768) {
          q0 = -32768;
        }
      }

      tmp = roundf(FrontObjectDetection_B.DivResult * (real32_T)q0);
      q0 = FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[tmp_2] -
        FrontObjectDetection_DW.current_point_x;
      if (q0 > 32767) {
        q0 = 32767;
      } else {
        if (q0 < -32768) {
          q0 = -32768;
        }
      }

      if (tmp < 32768.0F) {
        if (tmp >= -32768.0F) {
          tmp_1 = (int16_T)tmp;
        } else {
          tmp_1 = MIN_int16_T;
        }
      } else {
        tmp_1 = MAX_int16_T;
      }

      q0 = tmp_1 - q0;
      if (q0 > 32767) {
        q0 = 32767;
      } else {
        if (q0 < -32768) {
          q0 = -32768;
        }
      }

      FrontObjectDetection_DW.DistanceToObject = (int16_T)q0;
      FrontObjectDetection_IsValidObjectDistance();
      exitg1 = true;
    } else {
      tmp_0 = 1;
      if (1 < 0) {
        tmp_0 = 0;
      }

      q0 = (int32_T)((uint32_T)ContourPtIdx + tmp_0);
      if ((uint32_T)q0 > 255U) {
        q0 = 255;
      }

      ContourPtIdx = (uint8_T)q0;
    }
  }
}

/* Function for Chart: '<S6>/CalculateMinDistances' */
static void FrontObjectDetection_GetObjectPointRegion(void)
{
  boolean_T b;
  int32_T tmp;
  int32_T tmp_0;

  /* Constant: '<S6>/KeAP_cm_DistZone1' */
  tmp_0 =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_HalfVehicleWidth +
    KeFOD_cm_WarnOffset;
  tmp = tmp_0;
  if (tmp_0 > 32767) {
    tmp = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp = -32768;
    }
  }

  tmp = -tmp;
  if (tmp > 32767) {
    tmp = 32767;
  }

  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  b = ((FrontObjectDetection_DW.current_point_y >= tmp) &&
       (FrontObjectDetection_DW.current_point_y <= tmp_0));
  if ((FrontObjectDetection_DW.current_point_x > 0) && b &&
      (FrontObjectDetection_DW.DistanceToObject <
       FrontObjectDetection_DW.PrevCenterFront_MeFOD_cm_ObjXPon)) {
    FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist =
      FrontObjectDetection_DW.DistanceToObject;
    FrontObjectDetection_DW.PrevCenterFront_MeFOD_cm_ObjXPon =
      FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
  } else {
    if ((!b) && (FrontObjectDetection_DW.DistanceToObject <
                 FrontObjectDetection_DW.PrevSideFront_MeFOD_cm_ObjXPon)) {
      FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist =
        FrontObjectDetection_DW.DistanceToObject;
      FrontObjectDetection_DW.PrevSideFront_MeFOD_cm_ObjXPon =
        FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
    }
  }
}

/* Model step function */
void FrontObjectDetection_step(void)
{
  uint8_T point_index;
  int16_T tmp;
  uint32_T tmp_0;
  real32_T tmp_1;
  real32_T tmp_2;
  int32_T current_point_x_tmp;
  real32_T Abs4_tmp;

  /* DataStoreRead: '<S2>/VrntTunParam_data3' */
  SigMgr_Data_IKinematicData_t_Get(&FrontObjectDetection_B.IbKM_KinematicData);

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant'
   */
  FrontObjectDetection_B.Abs4_j = FrontObjectDetection_B.IbKM_KinematicData.dx_m
    * 100.0F;

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  FrontObjectDetection_B.Abs4_j *= 0.03F;

  /* Gain: '<S4>/Gain' */
  FrontObjectDetection_B.dx_cm = (-1.0F) * FrontObjectDetection_B.Abs4_j;

  /* DataStoreRead: '<S2>/VrntTunParam_data' */
  //FrontObjectDetection_B.IbAP_VrntTunParam = SigMgr_Data_AP_VrntTunParam_t_Get();
  SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(&FrontObjectDetection_B.IbAP_VrntTunParam );
  /* DataTypeConversion: '<S5>/Data Type Conversion100' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FSL_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSL_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion101' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FOL_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOL_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion102' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FIL_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIL_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion103' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FIR_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIR_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion104' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FOR_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOR_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion105' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FSR_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSR_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion106' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FSL_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSL_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion107' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FOL_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOL_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion108' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FIL_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIL_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion109' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FIR_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIR_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion110' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FOR_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOR_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion111' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_FSR_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSR_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion112' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RSR_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSR_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion113' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_ROR_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROR_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion114' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RIR_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIR_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion115' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RIL_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIL_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion116' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_ROL_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROL_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion117' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RSL_x =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSL_x;

  /* DataTypeConversion: '<S5>/Data Type Conversion118' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RSR_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSR_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion119' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_ROR_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROR_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion120' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RIR_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIR_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion121' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RIL_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIL_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion122' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_ROL_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROL_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion123' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_VehContour_RSL_y =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSL_y;

  /* DataTypeConversion: '<S5>/Data Type Conversion53' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_DistZone1 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_DistZone1;

  /* DataTypeConversion: '<S5>/Data Type Conversion33' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_DistZone2 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_DistZone2;

  /* DataTypeConversion: '<S5>/Data Type Conversion54' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_DistZone3 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_DistZone3;

  /* DataTypeConversion: '<S5>/Data Type Conversion55' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_DistZone4 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_DistZone4;

  /* DataTypeConversion: '<S5>/Data Type Conversion56' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_DistZone5 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_DistZone5;

  /* DataTypeConversion: '<S5>/Data Type Conversion57' */
  FrontObjectDetection_B.Add7 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_DistZone6;

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  FrontObjectDetection_B.Saturation14 =
    FrontObjectDetection_B.IbAP_VrntTunParam.CalData1.KeAP_cm_HalfVehicleWidth;

  /* BusCreator: '<S5>/Bus Creator1' */
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_DistZone6 =
    FrontObjectDetection_B.Add7;
  FrontObjectDetection_B.BusCreator1.KeFOD_cm_HalfVehicleWidth =
    FrontObjectDetection_B.Saturation14;

  /* BusCreator: '<S5>/Bus Creator' incorporates:
   *  Constant: '<S5>/KeAP_cm_DistZone1'
   *  Constant: '<S5>/KeAP_cm_DistZone2'
   *  Constant: '<S5>/KeAP_cm_DistZone3'
   *  Constant: '<S5>/KeAP_cm_DistZone4'
   *  Constant: '<S5>/KeAP_cm_DistZone5'
   *  Constant: '<S5>/KeAP_cm_DistZone6'
   *  Constant: '<S5>/KeAP_cm_DistZone7'
   *  Constant: '<S5>/KeAP_s_GearShiftWaitCntTimeout1'
   *  Constant: '<S5>/KeAP_s_GearShiftWaitCntTimeout2'
   *  Constant: '<S5>/KeAP_s_GearShiftWaitCntTimeout3'
   *  Constant: '<S5>/KeAP_s_GearShiftWaitCntTimeout4'
   *  Constant: '<S5>/KeAP_s_MaxStandstillTimeThd1'
   *  Constant: '<S5>/KeAP_s_MaxStandstillTimeThd2'
   *  Constant: '<S5>/KeAP_s_MaxStandstillTimeThd3'
   *  Constant: '<S5>/KeAP_s_MaxStandstillTimeThd4'
   *  Constant: '<S5>/KeAP_s_ObjInPathTimeoutDur1'
   *  Constant: '<S5>/KeAP_s_ObjInPathTimeoutDur2'
   *  Constant: '<S5>/KeAP_s_ObjInPathTimeoutDur3'
   *  Constant: '<S5>/KeAP_s_ObjInPathTimeoutDur4'
   *  Constant: '<S5>/KeAP_s_PausedPressBtnTimeoutDur1'
   *  Constant: '<S5>/KeAP_s_PausedPressBtnTimeoutDur2'
   *  Constant: '<S5>/KeAP_s_PausedPressBtnTimeoutDur3'
   *  Constant: '<S5>/KeAP_s_PausedPressBtnTimeoutDur4'
   *  Constant: '<S5>/KeAP_s_SeekPhaseTimeoutDur1'
   *  Constant: '<S5>/KeAP_s_SeekPhaseTimeoutDur2'
   *  Constant: '<S5>/KeAP_s_SeekPhaseTimeoutDur3'
   *  Constant: '<S5>/KeAP_s_SeekPhaseTimeoutDur4'
   *  Constant: '<S5>/KeAP_s_SpdExceedDur1'
   *  Constant: '<S5>/KeAP_s_SpdExceedDur2'
   *  Constant: '<S5>/KeAP_s_SpdExceedDur3'
   *  Constant: '<S5>/KeAP_s_SpdExceedDur4'
   */
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FSL_x =
    KeFOD_cm_VehContour_FSL_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FOL_x =
    KeFOD_cm_VehContour_FOL_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FIL_x =
    KeFOD_cm_VehContour_FIL_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FIR_x =
    KeFOD_cm_VehContour_FIR_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FOR_x =
    KeFOD_cm_VehContour_FOR_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FSR_x =
    KeFOD_cm_VehContour_FSR_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FSL_y =
    KeFOD_cm_VehContour_FSL_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FOL_y =
    KeFOD_cm_VehContour_FOL_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FIL_y =
    KeFOD_cm_VehContour_FIL_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FIR_y =
    KeFOD_cm_VehContour_FIR_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FOR_y =
    KeFOD_cm_VehContour_FOR_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_FSR_y =
    KeFOD_cm_VehContour_FSR_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RSR_x =
    KeFOD_cm_VehContour_RSR_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_ROR_x =
    KeFOD_cm_VehContour_ROR_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RIR_x =
    KeFOD_cm_VehContour_RIR_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RIL_x =
    KeFOD_cm_VehContour_RIL_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_ROL_x =
    KeFOD_cm_VehContour_ROL_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RSL_x =
    KeFOD_cm_VehContour_RSL_x;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RSR_y =
    KeFOD_cm_VehContour_RSR_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_ROR_y =
    KeFOD_cm_VehContour_ROR_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RIR_y =
    KeFOD_cm_VehContour_RIR_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RIL_y =
    KeFOD_cm_VehContour_RIL_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_ROL_y =
    KeFOD_cm_VehContour_ROL_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_VehContour_RSL_y =
    KeFOD_cm_VehContour_RSL_y;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_DistZone1 = KeFOD_cm_DistZone1;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_DistZone2 = KeFOD_cm_DistZone2;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_DistZone3 = KeFOD_cm_DistZone3;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_DistZone4 = KeFOD_cm_DistZone4;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_DistZone5 = KeFOD_cm_DistZone5;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_DistZone6 = KeFOD_cm_DistZone6;
  FrontObjectDetection_B.BusCreator.KeFOD_cm_HalfVehicleWidth =
    KeFOD_cm_HalfVehicleWidth;

  /* Switch: '<S5>/Switch' */
  if (FrontObjectDetection_B.IbAP_VrntTunParam.bValid) {
    FrontObjectDetection_B.IbAP_InputVrntTunParam =
      FrontObjectDetection_B.BusCreator1;
  } else {
    FrontObjectDetection_B.IbAP_InputVrntTunParam =
      FrontObjectDetection_B.BusCreator;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Saturate: '<S10>/Saturation1' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSL_y >
      200) {
    FrontObjectDetection_B.Saturation1 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSL_y <
       (-200)) {
    FrontObjectDetection_B.Saturation1 = (-200);
  } else {
    FrontObjectDetection_B.Saturation1 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSL_y;
  }

  /* End of Saturate: '<S10>/Saturation1' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (KeFOD_cm_SideDetectionRange > 200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if (KeFOD_cm_SideDetectionRange < (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 = KeFOD_cm_SideDetectionRange;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Sum: '<S10>/Add8' */
  FrontObjectDetection_B.Add8 = (int16_T)(FrontObjectDetection_B.Saturation14 +
    FrontObjectDetection_B.Saturation1);

  /* Saturate: '<S10>/Saturation2' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOL_y >
      200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOL_y <
       (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOL_y;
  }

  /* End of Saturate: '<S10>/Saturation2' */

  /* Sum: '<S10>/Add' */
  FrontObjectDetection_B.Add7 = (int16_T)(FrontObjectDetection_B.Saturation1 +
    FrontObjectDetection_B.Saturation14);

  /* Gain: '<S10>/Gain' */
  FrontObjectDetection_B.Gain = (int16_T)((16384 * FrontObjectDetection_B.Add7) >>
    15);

  /* Saturate: '<S10>/Saturation3' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIL_y >
      200) {
    FrontObjectDetection_B.Add7 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIL_y <
       (-200)) {
    FrontObjectDetection_B.Add7 = (-200);
  } else {
    FrontObjectDetection_B.Add7 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIL_y;
  }

  /* End of Saturate: '<S10>/Saturation3' */

  /* Sum: '<S10>/Add1' */
  FrontObjectDetection_B.Saturation14 += FrontObjectDetection_B.Add7;

  /* Gain: '<S10>/Gain1' */
  FrontObjectDetection_B.Gain1 = (int16_T)((16384 *
    FrontObjectDetection_B.Saturation14) >> 15);

  /* Saturate: '<S10>/Saturation4' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIR_y >
      200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIR_y <
       (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIR_y;
  }

  /* End of Saturate: '<S10>/Saturation4' */

  /* Saturate: '<S10>/Saturation5' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOR_y >
      200) {
    FrontObjectDetection_B.Add7 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOR_y <
       (-200)) {
    FrontObjectDetection_B.Add7 = (-200);
  } else {
    FrontObjectDetection_B.Add7 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOR_y;
  }

  /* End of Saturate: '<S10>/Saturation5' */

  /* Sum: '<S10>/Add2' */
  FrontObjectDetection_B.Saturation14 += FrontObjectDetection_B.Add7;

  /* Gain: '<S10>/Gain2' */
  FrontObjectDetection_B.Gain2 = (int16_T)((16384 *
    FrontObjectDetection_B.Saturation14) >> 15);

  /* Saturate: '<S10>/Saturation6' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSR_y >
      200) {
    FrontObjectDetection_B.Saturation6 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSR_y <
       (-200)) {
    FrontObjectDetection_B.Saturation6 = (-200);
  } else {
    FrontObjectDetection_B.Saturation6 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSR_y;
  }

  /* End of Saturate: '<S10>/Saturation6' */

  /* Sum: '<S10>/Add3' */
  FrontObjectDetection_B.Add7 += FrontObjectDetection_B.Saturation6;

  /* Gain: '<S10>/Gain3' */
  FrontObjectDetection_B.Gain3 = (int16_T)((16384 * FrontObjectDetection_B.Add7)
    >> 15);

  /* Saturate: '<S10>/Saturation7' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (KeFOD_cm_SideDetectionRange > 200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if (KeFOD_cm_SideDetectionRange < (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 = KeFOD_cm_SideDetectionRange;
  }

  /* End of Saturate: '<S10>/Saturation7' */

  /* Sum: '<S10>/Add9' */
  FrontObjectDetection_B.Add9 = (int16_T)(FrontObjectDetection_B.Saturation6 -
    FrontObjectDetection_B.Saturation14);

  /* Saturate: '<S10>/Saturation8' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROR_y >
      200) {
    FrontObjectDetection_B.Saturation8 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROR_y <
       (-200)) {
    FrontObjectDetection_B.Saturation8 = (-200);
  } else {
    FrontObjectDetection_B.Saturation8 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROR_y;
  }

  /* End of Saturate: '<S10>/Saturation8' */

  /* Saturate: '<S10>/Saturation9' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIR_y >
      200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIR_y <
       (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIR_y;
  }

  /* End of Saturate: '<S10>/Saturation9' */

  /* Sum: '<S10>/Add4' */
  FrontObjectDetection_B.Add7 = (int16_T)(FrontObjectDetection_B.Saturation8 +
    FrontObjectDetection_B.Saturation14);

  /* Gain: '<S10>/Gain4' */
  FrontObjectDetection_B.Gain4 = (int16_T)((16384 * FrontObjectDetection_B.Add7)
    >> 15);

  /* Saturate: '<S10>/Saturation10' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIL_y >
      200) {
    FrontObjectDetection_B.Add7 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIL_y <
       (-200)) {
    FrontObjectDetection_B.Add7 = (-200);
  } else {
    FrontObjectDetection_B.Add7 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIL_y;
  }

  /* End of Saturate: '<S10>/Saturation10' */

  /* Sum: '<S10>/Add5' */
  FrontObjectDetection_B.Saturation14 += FrontObjectDetection_B.Add7;

  /* Gain: '<S10>/Gain5' */
  FrontObjectDetection_B.Gain5 = (int16_T)((16384 *
    FrontObjectDetection_B.Saturation14) >> 15);

  /* Saturate: '<S10>/Saturation11' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROL_y >
      200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROL_y <
       (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROL_y;
  }

  /* End of Saturate: '<S10>/Saturation11' */

  /* Saturate: '<S10>/Saturation12' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSL_y >
      200) {
    FrontObjectDetection_B.Add7 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSL_y <
       (-200)) {
    FrontObjectDetection_B.Add7 = (-200);
  } else {
    FrontObjectDetection_B.Add7 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSL_y;
  }

  /* End of Saturate: '<S10>/Saturation12' */

  /* Sum: '<S10>/Add6' */
  FrontObjectDetection_B.Saturation14 += FrontObjectDetection_B.Add7;

  /* Gain: '<S10>/Gain6' */
  FrontObjectDetection_B.Gain6 = (int16_T)((16384 *
    FrontObjectDetection_B.Saturation14) >> 15);

  /* Saturate: '<S10>/Saturation13' */
  if (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSR_y >
      200) {
    FrontObjectDetection_B.Saturation13 = 200;
  } else if
      (FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSR_y <
       (-200)) {
    FrontObjectDetection_B.Saturation13 = (-200);
  } else {
    FrontObjectDetection_B.Saturation13 =
      FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSR_y;
  }

  /* End of Saturate: '<S10>/Saturation13' */

  /* Sum: '<S10>/Add7' */
  FrontObjectDetection_B.Add7 += FrontObjectDetection_B.Saturation13;

  /* Gain: '<S10>/Gain7' */
  FrontObjectDetection_B.Gain7 = (int16_T)((16384 * FrontObjectDetection_B.Add7)
    >> 15);

  /* Saturate: '<S10>/Saturation14' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (KeFOD_cm_SideDetectionRange > 200) {
    FrontObjectDetection_B.Saturation14 = 200;
  } else if (KeFOD_cm_SideDetectionRange < (-200)) {
    FrontObjectDetection_B.Saturation14 = (-200);
  } else {
    FrontObjectDetection_B.Saturation14 = KeFOD_cm_SideDetectionRange;
  }

  /* End of Saturate: '<S10>/Saturation14' */

  /* Sum: '<S10>/Add10' */
  FrontObjectDetection_B.Add10 = (int16_T)(FrontObjectDetection_B.Saturation13 +
    FrontObjectDetection_B.Saturation14);

  /* DataStoreRead: '<S2>/USS_2DPointMap_data' */
  //FrontObjectDetection_B.USS_2DPointMap =
  //  SigMgr_PpUSS_PointMapGroup_US_S_PointMapGroup_t_Get();
  SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(&FrontObjectDetection_B.USS_2DPointMap);

#if TEST_FOD_OFFLINE
  ME_VehInp_to_IpcSignals_t opVehSignals;
  SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&opVehSignals);
  float32_t Speed = 0.0f;
  Speed = opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
  int8_t i = 0;

for (i=0; i<96; i++)
{
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[i].confidence = (uint8_t)0;
}

if ((Speed  >= 1.0f) && (Speed  < 2.0f))
{  
  //TC1
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].confidence = uint8_t(80);
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].x = int16_t(552); 
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].y = int16_t(80); 
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].confidence = uint8_t(80); 
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].x = int16_t(705); 
  FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].y = int16_t(-100);  
}
else if ((Speed  >= 2.0f) && (Speed < 3.0f))
{
  //TC2
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].confidence = uint8_t(0);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].x = int16_t(552);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].y = int16_t(80);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].confidence = uint8_t(80);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].x = int16_t(705);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].y = int16_t(-100);  
}
else if ((Speed  >= 3.0f) && (Speed < 4.0f))
{
//TC3 :   
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].confidence = uint8_t(0);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].x = int16_t(552);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].y = int16_t(80);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].confidence = uint8_t(80);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].x = int16_t(852);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].y = int16_t(100);  
}
else if ((Speed  >= 4.0f) && (Speed < 5.0f))   
{
  //TC4 :
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].confidence = uint8_t(0);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].x = int16_t(552);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].y = int16_t(80);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].confidence = uint8_t(60);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].x = int16_t(1552);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].y = int16_t(100);  
}
else if ((Speed  >= 5.0f) && (Speed < 6.0f))
{
//TC5 :   
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].confidence = uint8_t(0);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].x = int16_t(552);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[0].y = int16_t(80);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].confidence = uint8_t(60);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].x = int16_t(300);
FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[1].y = int16_t(50);  
}
else
{
  /* SignalConversion: '<S1>/Signal Conversion2' */
  FrontObjectDetection_B.IbUSS_2DPointMap =
    FrontObjectDetection_B.USS_2DPointMap.PointMap;
}
#else
  /* SignalConversion: '<S1>/Signal Conversion2' */
  FrontObjectDetection_B.IbUSS_2DPointMap =
    FrontObjectDetection_B.USS_2DPointMap.PointMap;
#endif

  /* Abs: '<S7>/Abs4' */
  FrontObjectDetection_B.Abs4_j = fabsf(FrontObjectDetection_B.dx_cm);

  /* RelationalOperator: '<S7>/Relational Operator4' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  FrontObjectDetection_B.RelationalOperator4 = (FrontObjectDetection_B.Abs4_j >
    0.0F);

  /* Logic: '<S7>/Logical Operator4' */
  FrontObjectDetection_B.LogicalOperator4 =
    !FrontObjectDetection_B.RelationalOperator4;

  /* UnitDelay: '<S23>/Unit Delay1' */
  FrontObjectDetection_B.Compare = FrontObjectDetection_DW.UnitDelay1_DSTATE;

  /* Logic: '<S23>/Logical Operator' */
  FrontObjectDetection_B.Compare = !FrontObjectDetection_B.Compare;

  /* Logic: '<S23>/Logical Operator1' */
  FrontObjectDetection_B.Compare = (FrontObjectDetection_B.LogicalOperator4 &&
    FrontObjectDetection_B.Compare);

  /* UnitDelay: '<S22>/Unit Delay2' */
  FrontObjectDetection_B.UnitDelay2 = FrontObjectDetection_B.Switch3;

  /* Switch: '<S22>/Switch3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (FrontObjectDetection_B.Compare) {
    FrontObjectDetection_B.Switch3 = ((uint16_T)50U);
  } else {
    /* Logic: '<S22>/Logical Operator1' */
    FrontObjectDetection_B.LogicalOperator1 =
      !FrontObjectDetection_B.RelationalOperator4;

    /* RelationalOperator: '<S22>/Relational Operator' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    FrontObjectDetection_B.ElapseTimer = (((uint16_T)3U) <=
      FrontObjectDetection_B.UnitDelay2);

    /* Logic: '<S22>/Logical Operator3' */
    FrontObjectDetection_B.ElapseTimer = (FrontObjectDetection_B.ElapseTimer &&
      FrontObjectDetection_B.LogicalOperator1);

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant'
     */
    if (FrontObjectDetection_B.ElapseTimer) {
      /* Sum: '<S22>/Subtract' incorporates:
       *  Constant: '<S7>/Constant1'
       */
      FrontObjectDetection_B.Subtract_a = (uint16_T)
        (FrontObjectDetection_B.UnitDelay2 - ((uint16_T)3U));
      FrontObjectDetection_B.Switch1 = FrontObjectDetection_B.Subtract_a;
    } else {
      FrontObjectDetection_B.Switch1 = ((uint16_T)0U);
    }

    /* End of Switch: '<S22>/Switch1' */
    FrontObjectDetection_B.Switch3 = FrontObjectDetection_B.Switch1;
  }

  /* End of Switch: '<S22>/Switch3' */

  /* RelationalOperator: '<S22>/Relational Operator1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  FrontObjectDetection_B.Compare = (((uint16_T)3U) >
    FrontObjectDetection_B.Switch3);

  /* Logic: '<S22>/Logical Operator4' */
  FrontObjectDetection_B.Compare = !FrontObjectDetection_B.Compare;

  /* SignalConversion: '<S7>/Signal Conversion' */
  FrontObjectDetection_B.MeAP_b_StandstillTimerRunning =
    FrontObjectDetection_B.Compare;

  /* SignalConversion generated from: '<S8>/ SFunction ' */
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[0] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[1] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[2] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[3] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[4] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FIR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[5] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[6] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FOR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[7] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_FSR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[8] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[9] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[10] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[11] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIR_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[12] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RIL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[13] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[14] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_ROL_x;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport1[15] =
    FrontObjectDetection_B.IbAP_InputVrntTunParam.KeFOD_cm_VehContour_RSL_x;

  /* SignalConversion generated from: '<S8>/ SFunction ' */
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[0] =
    FrontObjectDetection_B.Add8;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[1] =
    FrontObjectDetection_B.Saturation1;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[2] =
    FrontObjectDetection_B.Gain;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[3] =
    FrontObjectDetection_B.Gain1;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[4] =
    FrontObjectDetection_B.Gain2;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[5] =
    FrontObjectDetection_B.Gain3;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[6] =
    FrontObjectDetection_B.Saturation6;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[7] =
    FrontObjectDetection_B.Add9;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[8] =
    FrontObjectDetection_B.Add9;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[9] =
    FrontObjectDetection_B.Saturation8;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[10] =
    FrontObjectDetection_B.Gain4;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[11] =
    FrontObjectDetection_B.Gain5;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[12] =
    FrontObjectDetection_B.Gain6;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[13] =
    FrontObjectDetection_B.Gain7;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[14] =
    FrontObjectDetection_B.Saturation13;
  FrontObjectDetection_B.TmpSignalConversionAtSFunctionInport2[15] =
    FrontObjectDetection_B.Add10;
  point_index = 1U;
  tmp_2 = roundf(1023.0F);
  if (tmp_2 < 32768.0F) {
    if (tmp_2 >= -32768.0F) {
      FrontObjectDetection_DW.MaxDist = (int16_T)tmp_2;
    } else {
      FrontObjectDetection_DW.MaxDist = MIN_int16_T;
    }
  } else {
    FrontObjectDetection_DW.MaxDist = MAX_int16_T;
  }

  FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist =
    FrontObjectDetection_DW.MaxDist;
  FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist =
    FrontObjectDetection_DW.MaxDist;
  FrontObjectDetection_DW.PrevCenterFront_MeFOD_cm_ObjXPon =
    FrontObjectDetection_DW.MaxDist;
  FrontObjectDetection_DW.PrevSideFront_MeFOD_cm_ObjXPon =
    FrontObjectDetection_DW.MaxDist;
  while (point_index <= ((uint8_T)96U)) {
    current_point_x_tmp = point_index - 1;
    FrontObjectDetection_DW.current_point_x =
      FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[current_point_x_tmp].x;
    FrontObjectDetection_DW.current_point_y =
      FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[current_point_x_tmp].y;
    FrontObjectDetection_DW.current_point_confidence =
      FrontObjectDetection_B.IbUSS_2DPointMap.pointMap[current_point_x_tmp].
      confidence;
    if (FrontObjectDetection_DW.current_point_x < 0) {
      current_point_x_tmp = -FrontObjectDetection_DW.current_point_x;
      if (current_point_x_tmp > 32767) {
        current_point_x_tmp = 32767;
      }

      tmp = (int16_T)current_point_x_tmp;
    } else {
      tmp = FrontObjectDetection_DW.current_point_x;
    }

    /* Constant: '<S6>/Constant11' */
    if ((tmp <= FrontObjectDetection_DW.MaxDist) &&
        (FrontObjectDetection_DW.current_point_confidence >
         KeFOD_pct_ObjConfidenceThd)) {
      FrontObjectDetection_CalculateDistance();
      FrontObjectDetection_GetObjectPointRegion();
    }

    /* End of Constant: '<S6>/Constant11' */
    current_point_x_tmp = (int32_T)(point_index + 1U);
    if ((uint32_T)current_point_x_tmp > 255U) {
      current_point_x_tmp = 255;
    }

    point_index = (uint8_T)current_point_x_tmp;
  }

  FrontObjectDetection_B.RawDist =
    FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
  FrontObjectDetection_B.LastGoodDist =
    FrontObjectDetection_DW.LastGood_FrntCenterMinDist;
  FrontObjectDetection_B.VehTravelDist = FrontObjectDetection_B.dx_cm;
  FrontObjectDetection_B.ZoneDist = KeFOD_cm_DistZone2;
  FrontObjectDetection_B.HoldTracking =
    FrontObjectDetection_B.MeAP_b_StandstillTimerRunning;

  /* Chart: '<S6>/CalculateMinDistances' incorporates:
   *  SubSystem: '<S8>/UpdateDistNoDetection'
   */
  /* Abs: '<S12>/Abs1' */
  if (FrontObjectDetection_B.RawDist < 0) {
    FrontObjectDetection_B.Abs1_h = (int16_T)-FrontObjectDetection_B.RawDist;
  } else {
    FrontObjectDetection_B.Abs1_h = FrontObjectDetection_B.RawDist;
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant'
   */
  tmp_2 = floorf(1022.0F);
  if (rtIsNaNF(tmp_2) || rtIsInfF(tmp_2)) {
    tmp_1 = 0.0F;
  } else {
    tmp_1 = fmodf(tmp_2, 65536.0F);
  }

  FrontObjectDetection_B.Abs2 = (int16_T)(tmp_1 < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp_1 : (int32_T)(int16_T)(uint16_T)tmp_1);

  /* RelationalOperator: '<S12>/Relational Operator1' */
  FrontObjectDetection_B.TrackObj = (FrontObjectDetection_B.Abs1_h >
    FrontObjectDetection_B.Abs2);

  /* Abs: '<S12>/Abs3' */
  FrontObjectDetection_B.Abs3 = fabsf(FrontObjectDetection_B.LastGoodDist);

  /* DataTypeConversion: '<S12>/Data Type Conversion4' */
  FrontObjectDetection_B.Abs4 = FrontObjectDetection_B.ZoneDist;

  /* RelationalOperator: '<S12>/Relational Operator' */
  FrontObjectDetection_B.LastObjDetectedInZone2 = (FrontObjectDetection_B.Abs3 <=
    FrontObjectDetection_B.Abs4);

  /* RelationalOperator: '<S12>/Relational Operator2' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  FrontObjectDetection_B.USSObjDetectedInZone2 = (FrontObjectDetection_B.Abs3 >
    0);

  /* Abs: '<S12>/Abs4' */
  Abs4_tmp = fabsf(FrontObjectDetection_B.VehTravelDist);
  FrontObjectDetection_B.Abs4 = Abs4_tmp;

  /* RelationalOperator: '<S12>/Relational Operator4' incorporates:
   *  Constant: '<S12>/Constant4'
   */
  FrontObjectDetection_B.LogicalOperator4_h = (FrontObjectDetection_B.Abs4 >
    0.0F);

  /* Logic: '<S12>/Logical Operator4' */
  FrontObjectDetection_B.LogicalOperator4_h =
    (FrontObjectDetection_B.LogicalOperator4_h ||
     FrontObjectDetection_B.HoldTracking);

  /* Logic: '<S12>/Logical Operator' */
  FrontObjectDetection_B.TrackObj = (FrontObjectDetection_B.TrackObj &&
    FrontObjectDetection_B.LastObjDetectedInZone2 &&
    FrontObjectDetection_B.USSObjDetectedInZone2 &&
    FrontObjectDetection_B.LogicalOperator4_h);

  /* Sum: '<S12>/Subtract' */
  FrontObjectDetection_B.Subtract = FrontObjectDetection_B.LastGoodDist -
    FrontObjectDetection_B.VehTravelDist;

  /* Abs: '<S12>/Abs2' */
  if (FrontObjectDetection_B.RawDist < 0) {
    FrontObjectDetection_B.Abs2 = (int16_T)-FrontObjectDetection_B.RawDist;
  } else {
    FrontObjectDetection_B.Abs2 = FrontObjectDetection_B.RawDist;
  }

  /* RelationalOperator: '<S12>/Relational Operator3' incorporates:
   *  Constant: '<S12>/Constant3'
   */
  FrontObjectDetection_B.USSObjDetectedInZone2 = (FrontObjectDetection_B.Abs2 <
    KeFOD_cm_DistZone2);

  /* Logic: '<S12>/Logical Operator1' */
  FrontObjectDetection_B.SaveObjInfo =
    (FrontObjectDetection_B.USSObjDetectedInZone2 &&
     FrontObjectDetection_B.LogicalOperator4_h);

  /* Switch generated from: '<S12>/Switch' */
  if (FrontObjectDetection_B.TrackObj) {
    /* DataTypeConversion: '<S12>/Data Type Conversion2' */
    tmp_1 = floorf(FrontObjectDetection_B.Subtract);
    if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
      tmp_1 = 0.0F;
    } else {
      tmp_1 = fmodf(tmp_1, 65536.0F);
    }

    FrontObjectDetection_B.UpdatedDist_k = (int16_T)(tmp_1 < 0.0F ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-tmp_1 : (int32_T)(int16_T)(uint16_T)tmp_1);
    FrontObjectDetection_B.UpdatedDist = FrontObjectDetection_B.UpdatedDist_k;

    /* SignalConversion: '<S12>/Signal Conversion' */
    FrontObjectDetection_B.UpdatedLastGoodDist_f =
      FrontObjectDetection_B.Subtract;
    FrontObjectDetection_B.UpdatedLastGoodDist =
      FrontObjectDetection_B.UpdatedLastGoodDist_f;
  } else {
    /* Switch generated from: '<S12>/Switch1' */
    FrontObjectDetection_B.UpdatedDist_g = FrontObjectDetection_B.RawDist;
    FrontObjectDetection_B.UpdatedDist = FrontObjectDetection_B.UpdatedDist_g;

    /* Switch generated from: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    if (FrontObjectDetection_B.SaveObjInfo) {
      /* DataTypeConversion: '<S12>/Data Type Conversion1' */
      FrontObjectDetection_B.UpdatedLastGoodDist_a =
        FrontObjectDetection_B.RawDist;
      FrontObjectDetection_B.UpdatedLastGoodDist_fv =
        FrontObjectDetection_B.UpdatedLastGoodDist_a;
    } else {
      FrontObjectDetection_B.UpdatedLastGoodDist_fv = 1023.0F;
    }

    FrontObjectDetection_B.UpdatedLastGoodDist =
      FrontObjectDetection_B.UpdatedLastGoodDist_fv;
  }

  FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist =
    FrontObjectDetection_B.UpdatedDist;
  FrontObjectDetection_DW.LastGood_FrntCenterMinDist =
    FrontObjectDetection_B.UpdatedLastGoodDist;
  if (FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist < 0) {
    FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist =
      FrontObjectDetection_DW.MaxDist;
  }

  FrontObjectDetection_B.RawDist =
    FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
  FrontObjectDetection_B.LastGoodDist =
    FrontObjectDetection_DW.LastGood_FrntSideMinDist;

  /* Chart: '<S6>/CalculateMinDistances' incorporates:
   *  SubSystem: '<S8>/UpdateDistNoDetection'
   */
  /* Abs: '<S12>/Abs1' */
  if (FrontObjectDetection_B.RawDist < 0) {
    FrontObjectDetection_B.Abs1_h = (int16_T)-FrontObjectDetection_B.RawDist;
  } else {
    FrontObjectDetection_B.Abs1_h = FrontObjectDetection_B.RawDist;
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (rtIsNaNF(tmp_2) || rtIsInfF(tmp_2)) {
    tmp_2 = 0.0F;
  } else {
    tmp_2 = fmodf(tmp_2, 65536.0F);
  }

  FrontObjectDetection_B.Abs2 = (int16_T)(tmp_2 < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp_2 : (int32_T)(int16_T)(uint16_T)tmp_2);

  /* RelationalOperator: '<S12>/Relational Operator1' */
  FrontObjectDetection_B.TrackObj = (FrontObjectDetection_B.Abs1_h >
    FrontObjectDetection_B.Abs2);

  /* Abs: '<S12>/Abs3' */
  FrontObjectDetection_B.Abs3 = fabsf(FrontObjectDetection_B.LastGoodDist);

  /* DataTypeConversion: '<S12>/Data Type Conversion4' */
  FrontObjectDetection_B.Abs4 = FrontObjectDetection_B.ZoneDist;

  /* RelationalOperator: '<S12>/Relational Operator' */
  FrontObjectDetection_B.LastObjDetectedInZone2 = (FrontObjectDetection_B.Abs3 <=
    FrontObjectDetection_B.Abs4);

  /* RelationalOperator: '<S12>/Relational Operator2' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  FrontObjectDetection_B.USSObjDetectedInZone2 = (FrontObjectDetection_B.Abs3 >
    0);

  /* Abs: '<S12>/Abs4' */
  FrontObjectDetection_B.Abs4 = Abs4_tmp;

  /* RelationalOperator: '<S12>/Relational Operator4' incorporates:
   *  Constant: '<S12>/Constant4'
   */
  FrontObjectDetection_B.LogicalOperator4_h = (FrontObjectDetection_B.Abs4 >
    0.0F);

  /* Logic: '<S12>/Logical Operator4' */
  FrontObjectDetection_B.LogicalOperator4_h =
    (FrontObjectDetection_B.LogicalOperator4_h ||
     FrontObjectDetection_B.HoldTracking);

  /* Logic: '<S12>/Logical Operator' */
  FrontObjectDetection_B.TrackObj = (FrontObjectDetection_B.TrackObj &&
    FrontObjectDetection_B.LastObjDetectedInZone2 &&
    FrontObjectDetection_B.USSObjDetectedInZone2 &&
    FrontObjectDetection_B.LogicalOperator4_h);

  /* Sum: '<S12>/Subtract' */
  FrontObjectDetection_B.Subtract = FrontObjectDetection_B.LastGoodDist -
    FrontObjectDetection_B.VehTravelDist;

  /* Abs: '<S12>/Abs2' */
  if (FrontObjectDetection_B.RawDist < 0) {
    FrontObjectDetection_B.Abs2 = (int16_T)-FrontObjectDetection_B.RawDist;
  } else {
    FrontObjectDetection_B.Abs2 = FrontObjectDetection_B.RawDist;
  }

  /* RelationalOperator: '<S12>/Relational Operator3' incorporates:
   *  Constant: '<S12>/Constant3'
   */
  FrontObjectDetection_B.USSObjDetectedInZone2 = (FrontObjectDetection_B.Abs2 <
    KeFOD_cm_DistZone2);

  /* Logic: '<S12>/Logical Operator1' */
  FrontObjectDetection_B.SaveObjInfo =
    (FrontObjectDetection_B.USSObjDetectedInZone2 &&
     FrontObjectDetection_B.LogicalOperator4_h);

  /* Switch generated from: '<S12>/Switch' */
  if (FrontObjectDetection_B.TrackObj) {
    /* DataTypeConversion: '<S12>/Data Type Conversion2' */
    tmp_2 = floorf(FrontObjectDetection_B.Subtract);
    if (rtIsNaNF(tmp_2) || rtIsInfF(tmp_2)) {
      tmp_2 = 0.0F;
    } else {
      tmp_2 = fmodf(tmp_2, 65536.0F);
    }

    FrontObjectDetection_B.UpdatedDist_k = (int16_T)(tmp_2 < 0.0F ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-tmp_2 : (int32_T)(int16_T)(uint16_T)tmp_2);
    FrontObjectDetection_B.UpdatedDist = FrontObjectDetection_B.UpdatedDist_k;

    /* SignalConversion: '<S12>/Signal Conversion' */
    FrontObjectDetection_B.UpdatedLastGoodDist_f =
      FrontObjectDetection_B.Subtract;
    FrontObjectDetection_B.UpdatedLastGoodDist =
      FrontObjectDetection_B.UpdatedLastGoodDist_f;
  } else {
    /* Switch generated from: '<S12>/Switch1' */
    FrontObjectDetection_B.UpdatedDist_g = FrontObjectDetection_B.RawDist;
    FrontObjectDetection_B.UpdatedDist = FrontObjectDetection_B.UpdatedDist_g;

    /* Switch generated from: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    if (FrontObjectDetection_B.SaveObjInfo) {
      /* DataTypeConversion: '<S12>/Data Type Conversion1' */
      FrontObjectDetection_B.UpdatedLastGoodDist_a =
        FrontObjectDetection_B.RawDist;
      FrontObjectDetection_B.UpdatedLastGoodDist_fv =
        FrontObjectDetection_B.UpdatedLastGoodDist_a;
    } else {
      FrontObjectDetection_B.UpdatedLastGoodDist_fv = 1023.0F;
    }

    FrontObjectDetection_B.UpdatedLastGoodDist =
      FrontObjectDetection_B.UpdatedLastGoodDist_fv;
  }

  FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist =
    FrontObjectDetection_B.UpdatedDist;
  FrontObjectDetection_DW.LastGood_FrntSideMinDist =
    FrontObjectDetection_B.UpdatedLastGoodDist;
  if (FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist < 0) {
    FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist =
      FrontObjectDetection_DW.MaxDist;
  }

  /* Chart: '<S9>/DistDbnc' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   */
  if (FrontObjectDetection_DW.is_active_c3_FrontObjectDetection == 0U) {
    FrontObjectDetection_DW.is_active_c3_FrontObjectDetection = 1U;
    FrontObjectDetection_DW.is_c3_FrontObjectDetection =
      FrontObjectDetection_IN_DBNC_DISABLED;
    FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
      FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
    FrontObjectDetection_DW.Timer_m = 0U;
  } else if (FrontObjectDetection_DW.is_c3_FrontObjectDetection ==
             FrontObjectDetection_IN_DBNC_DISABLED) {
    if (KeFOD_b_DbncEnabld) {
      FrontObjectDetection_DW.is_c3_FrontObjectDetection =
        FrontObjectDetection_IN_DBNC_ENABLED;
      FrontObjectDetection_DW.is_DBNC_ENABLED_h =
        FrontObjectDetection_IN_SET_DBNC;
      FrontObjectDetection_DW.Timer_m = 0U;
      if (FrontObjectDetection_DW.Timer_m > KeFOD_ms_DbncTimeThsd) {
        FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
          FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
      } else {
        tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer_m + ((uint16_T)30U);
        if (tmp_0 > 65535U) {
          tmp_0 = 65535U;
        }

        FrontObjectDetection_DW.Timer_m = (uint16_T)tmp_0;
      }
    } else {
      FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
        FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
      FrontObjectDetection_DW.Timer_m = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeFOD_b_DbncEnabld) {
      FrontObjectDetection_DW.is_DBNC_ENABLED_h = 0;
      FrontObjectDetection_DW.is_c3_FrontObjectDetection =
        FrontObjectDetection_IN_DBNC_DISABLED;
      FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
        FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
      FrontObjectDetection_DW.Timer_m = 0U;
    } else if (FrontObjectDetection_DW.is_DBNC_ENABLED_h ==
               FrontObjectDetection_IN_RESET_DBNC) {
      if (FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist < 1023) {
        FrontObjectDetection_DW.is_DBNC_ENABLED_h =
          FrontObjectDetection_IN_SET_DBNC;
        FrontObjectDetection_DW.Timer_m = 0U;
        if (FrontObjectDetection_DW.Timer_m > KeFOD_ms_DbncTimeThsd) {
          FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
            FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
        } else {
          tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer_m + ((uint16_T)30U);
          if (tmp_0 > 65535U) {
            tmp_0 = 65535U;
          }

          FrontObjectDetection_DW.Timer_m = (uint16_T)tmp_0;
        }
      } else if (FrontObjectDetection_DW.Timer_m > KeFOD_ms_DbncTimeThsd) {
        FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
          FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
      } else {
        tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer_m + ((uint16_T)30U);
        if (tmp_0 > 65535U) {
          tmp_0 = 65535U;
        }

        FrontObjectDetection_DW.Timer_m = (uint16_T)tmp_0;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist == 1023) {
        FrontObjectDetection_DW.is_DBNC_ENABLED_h =
          FrontObjectDetection_IN_RESET_DBNC;
        FrontObjectDetection_DW.Timer_m = 0U;
        if (FrontObjectDetection_DW.Timer_m > KeFOD_ms_DbncTimeThsd) {
          FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
            FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
        } else {
          tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer_m + ((uint16_T)30U);
          if (tmp_0 > 65535U) {
            tmp_0 = 65535U;
          }

          FrontObjectDetection_DW.Timer_m = (uint16_T)tmp_0;
        }
      } else if (FrontObjectDetection_DW.Timer_m > KeFOD_ms_DbncTimeThsd) {
        FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut =
          FrontObjectDetection_B.MeFOD_cm_FrntCenterMinXRawDist;
      } else {
        tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer_m + ((uint16_T)30U);
        if (tmp_0 > 65535U) {
          tmp_0 = 65535U;
        }

        FrontObjectDetection_DW.Timer_m = (uint16_T)tmp_0;
      }
    }
  }

  /* End of Chart: '<S9>/DistDbnc' */

  /* Chart: '<S9>/DistDbncSide' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   */
  if (FrontObjectDetection_DW.is_active_c2_FrontObjectDetection == 0U) {
    FrontObjectDetection_DW.is_active_c2_FrontObjectDetection = 1U;
    FrontObjectDetection_DW.is_c2_FrontObjectDetection =
      FrontObjectDetection_IN_DBNC_DISABLED;
    FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
      FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
    FrontObjectDetection_DW.Timer = 0U;
  } else if (FrontObjectDetection_DW.is_c2_FrontObjectDetection ==
             FrontObjectDetection_IN_DBNC_DISABLED) {
    if (KeFOD_b_DbncEnabld) {
      FrontObjectDetection_DW.is_c2_FrontObjectDetection =
        FrontObjectDetection_IN_DBNC_ENABLED;
      FrontObjectDetection_DW.is_DBNC_ENABLED = FrontObjectDetection_IN_SET_DBNC;
      FrontObjectDetection_DW.Timer = 0U;
      if (FrontObjectDetection_DW.Timer > KeFOD_ms_DbncTimeThsd) {
        FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
          FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
      } else {
        tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer + ((uint16_T)30U);
        if (tmp_0 > 65535U) {
          tmp_0 = 65535U;
        }

        FrontObjectDetection_DW.Timer = (uint16_T)tmp_0;
      }
    } else {
      FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
        FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
      FrontObjectDetection_DW.Timer = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeFOD_b_DbncEnabld) {
      FrontObjectDetection_DW.is_DBNC_ENABLED = 0;
      FrontObjectDetection_DW.is_c2_FrontObjectDetection =
        FrontObjectDetection_IN_DBNC_DISABLED;
      FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
        FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
      FrontObjectDetection_DW.Timer = 0U;
    } else if (FrontObjectDetection_DW.is_DBNC_ENABLED ==
               FrontObjectDetection_IN_RESET_DBNC) {
      if (FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist < 1023) {
        FrontObjectDetection_DW.is_DBNC_ENABLED =
          FrontObjectDetection_IN_SET_DBNC;
        FrontObjectDetection_DW.Timer = 0U;
        if (FrontObjectDetection_DW.Timer > KeFOD_ms_DbncTimeThsd) {
          FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
            FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
        } else {
          tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer + ((uint16_T)30U);
          if (tmp_0 > 65535U) {
            tmp_0 = 65535U;
          }

          FrontObjectDetection_DW.Timer = (uint16_T)tmp_0;
        }
      } else if (FrontObjectDetection_DW.Timer > KeFOD_ms_DbncTimeThsd) {
        FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
          FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
      } else {
        tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer + ((uint16_T)30U);
        if (tmp_0 > 65535U) {
          tmp_0 = 65535U;
        }

        FrontObjectDetection_DW.Timer = (uint16_T)tmp_0;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist == 1023) {
        FrontObjectDetection_DW.is_DBNC_ENABLED =
          FrontObjectDetection_IN_RESET_DBNC;
        FrontObjectDetection_DW.Timer = 0U;
        if (FrontObjectDetection_DW.Timer > KeFOD_ms_DbncTimeThsd) {
          FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
            FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
        } else {
          tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer + ((uint16_T)30U);
          if (tmp_0 > 65535U) {
            tmp_0 = 65535U;
          }

          FrontObjectDetection_DW.Timer = (uint16_T)tmp_0;
        }
      } else if (FrontObjectDetection_DW.Timer > KeFOD_ms_DbncTimeThsd) {
        FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut =
          FrontObjectDetection_B.MeFOD_cm_FrntSideMinXRawDist;
      } else {
        tmp_0 = (uint32_T)FrontObjectDetection_DW.Timer + ((uint16_T)30U);
        if (tmp_0 > 65535U) {
          tmp_0 = 65535U;
        }

        FrontObjectDetection_DW.Timer = (uint16_T)tmp_0;
      }
    }
  }

  /* End of Chart: '<S9>/DistDbncSide' */

  /* Abs: '<S9>/Abs1' */
  if (FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut < 0) {
    FrontObjectDetection_B.Abs1 = (int16_T)
      -FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut;
  } else {
    FrontObjectDetection_B.Abs1 =
      FrontObjectDetection_B.MeAP_cm_FrntSideMinXDistOut;
  }

  /* End of Abs: '<S9>/Abs1' */

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   */
  FrontObjectDetection_B.Compare = (FrontObjectDetection_B.Abs1 == 1023);

  /* UnitDelay: '<S17>/Unit Delay' */
  FrontObjectDetection_B.UnitDelay = MeFOD_cm_FrntSideMinXDist;

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  FrontObjectDetection_B.LogicalOperator = (FrontObjectDetection_B.UnitDelay ==
    1023);

  /* Logic: '<S17>/Logical Operator' */
  FrontObjectDetection_B.Compare = (FrontObjectDetection_B.Compare ||
    FrontObjectDetection_B.LogicalOperator);

  /* Switch: '<S17>/Switch' */
  if (FrontObjectDetection_B.Compare) {
    MeFOD_cm_FrntSideMinXDist = FrontObjectDetection_B.Abs1;
  } else {
    /* Sum: '<S17>/Add' */
    FrontObjectDetection_B.Add = (int16_T)(FrontObjectDetection_B.Abs1 +
      FrontObjectDetection_B.UnitDelay);

    /* Product: '<S17>/Divide' incorporates:
     *  Constant: '<S17>/Constant'
     */
    current_point_x_tmp = 2;
    current_point_x_tmp = current_point_x_tmp == 0 ? FrontObjectDetection_B.Add >=
      0 ? MAX_int32_T : MIN_int32_T : FrontObjectDetection_B.Add /
      current_point_x_tmp;
    if (current_point_x_tmp > 32767) {
      current_point_x_tmp = 32767;
    } else {
      if (current_point_x_tmp < -32768) {
        current_point_x_tmp = -32768;
      }
    }

    FrontObjectDetection_B.Divide = (int16_T)current_point_x_tmp;

    /* End of Product: '<S17>/Divide' */
    MeFOD_cm_FrntSideMinXDist = FrontObjectDetection_B.Divide;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Abs: '<S9>/Abs' */
  if (FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut < 0) {
    FrontObjectDetection_B.Abs = (int16_T)
      -FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut;
  } else {
    FrontObjectDetection_B.Abs =
      FrontObjectDetection_B.MeAP_cm_FrntCenterMinXDistOut;
  }

  /* End of Abs: '<S9>/Abs' */

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  FrontObjectDetection_B.LogicalOperator = (FrontObjectDetection_B.Abs == 1023);

  /* UnitDelay: '<S16>/Unit Delay' */
  FrontObjectDetection_B.UnitDelay_h = MeFOD_cm_FrntCenterMinXDist;

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  FrontObjectDetection_B.Compare = (FrontObjectDetection_B.UnitDelay_h == 1023);

  /* Logic: '<S16>/Logical Operator' */
  FrontObjectDetection_B.LogicalOperator =
    (FrontObjectDetection_B.LogicalOperator || FrontObjectDetection_B.Compare);

  /* Switch: '<S16>/Switch' */
  if (FrontObjectDetection_B.LogicalOperator) {
    MeFOD_cm_FrntCenterMinXDist = FrontObjectDetection_B.Abs;
  } else {
    /* Sum: '<S16>/Add' */
    FrontObjectDetection_B.Add_f = (int16_T)(FrontObjectDetection_B.Abs +
      FrontObjectDetection_B.UnitDelay_h);

    /* Product: '<S16>/Divide' incorporates:
     *  Constant: '<S16>/Constant'
     */
    current_point_x_tmp = 2;
    current_point_x_tmp = current_point_x_tmp == 0 ?
      FrontObjectDetection_B.Add_f >= 0 ? MAX_int32_T : MIN_int32_T :
      FrontObjectDetection_B.Add_f / current_point_x_tmp;
    if (current_point_x_tmp > 32767) {
      current_point_x_tmp = 32767;
    } else {
      if (current_point_x_tmp < -32768) {
        current_point_x_tmp = -32768;
      }
    }

    FrontObjectDetection_B.Divide_o = (int16_T)current_point_x_tmp;

    /* End of Product: '<S16>/Divide' */
    MeFOD_cm_FrntCenterMinXDist = FrontObjectDetection_B.Divide_o;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  FrontObjectDetection_DW.UnitDelay1_DSTATE =
    FrontObjectDetection_B.LogicalOperator4;
}

/* Model initialize function */
void FrontObjectDetection_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Chart: '<S6>/CalculateMinDistances' */
  FrontObjectDetection_DW.LastGood_FrntCenterMinDist = 1023.0F;
  FrontObjectDetection_DW.LastGood_FrntSideMinDist = 1023.0F;
}

/* Model terminate function */
void FrontObjectDetection_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
