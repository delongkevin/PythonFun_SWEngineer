/*
 * File: Rear_ObjectDection.c
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

#include "Rear_ObjectDection.h"
#include "Rear_ObjectDection_private.h"
#include "look1_iflf_binlxpw.h"
#include "rt_hypotf_snf.h"

/* Named constants for Chart: '<S2>/CalculateRearBrakingDistance1' */
extern uint8 UssOD_bIsLowObjectRear(void); //keep
#define Rear_ObjectDection_RearBinSize ((uint8_T)10U)

MdlrefDW_Rear_ObjectDection_T Rear_ObjectDection_MdlrefDW;

/* Block signals (default storage) */
B_Rear_ObjectDection_c_T Rear_ObjectDection_B;

/* Block states (default storage) */
DW_Rear_ObjectDection_f_T Rear_ObjectDection_DW;

/* Forward declaration for local functions */
static void Rear_ObjectDection_CheckForCurbLikePatternRear(const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData);
static void Rear_ObjectDection_CheckForWallLikePatternRear(const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData);
static void Rear_ObjectDection_GetRearBrakingRegionPoints(void);
static void Rear_ObjectDection_CheckNeaighbourHoodForRAEB(const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData);

/*
 * Output and update for function-call system:
 *    '<S21>/GetPointData'
 *    '<S23>/GetPointData'
 */
void Rear_ObjectDection_GetPointData(const US_S_PointOutputBuff_t
  rtu_PointMapData[96], real32_T rtu_PointMapIndex, real32_T *rty_pt_x, real32_T
  *rty_pt_y, US_S_PointOutputBuff_t *rty_pt_confidence,
  B_GetPointData_Rear_ObjectDection_T *localB)
{
  /* Selector: '<S22>/Selector' */
  *rty_pt_confidence = rtu_PointMapData[(int32_T)rtu_PointMapIndex];

  /* Saturate: '<S22>/Saturation' */
  if (rty_pt_confidence->x > 1023) {
    localB->Saturation1 = 1023;
  } else if (rty_pt_confidence->x < (-1023)) {
    localB->Saturation1 = (-1023);
  } else {
    localB->Saturation1 = rty_pt_confidence->x;
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  *rty_pt_x = localB->Saturation1;

  /* Saturate: '<S22>/Saturation1' */
  if (rty_pt_confidence->y > 1023) {
    localB->Saturation1 = 1023;
  } else if (rty_pt_confidence->y < (-1023)) {
    localB->Saturation1 = (-1023);
  } else {
    localB->Saturation1 = rty_pt_confidence->y;
  }

  /* End of Saturate: '<S22>/Saturation1' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  *rty_pt_y = localB->Saturation1;
}

/* Output and update for function-call system: '<S7>/CalcDistToObjStraight' */
void Rear_ObjectDection_CalcDistToObjStraight(real32_T rtu_pt_x, real32_T
  rtu_pt_y, real32_T rtu_AdjDist, real32_T *rty_DistanceObject,
  B_CalcDistToObjStraight_Rear_ObjectDection_T *localB)
{
  /* Abs: '<S12>/Abs' */
  localB->Abs = fabsf(rtu_pt_y);

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S12>/Constant2'
   */
  localB->Switch = ((K_e_RAEB_VehicleWidth / CeAP_k_SingleTwo +
                     K_e_RAEB_DrawingTubeOffset) + K_e_RAEB_WarnOffset) * 100.0F;

  /* RelationalOperator: '<S12>/Relational Operator' */
  localB->RelationalOperator = (localB->Abs <= localB->Switch);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Constant3'
   */
  if (localB->RelationalOperator) {
    /* Sum: '<S12>/Subtract' */
    localB->Subtract = rtu_pt_x - rtu_AdjDist;
    localB->Switch = localB->Subtract;
  } else {
    localB->Switch = 1023.0F;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Saturate: '<S12>/Saturation' */
  if (localB->Switch > 1023.0F) {
    *rty_DistanceObject = 1023.0F;
  } else if (localB->Switch < CeAP_k_SingleZero) {
    *rty_DistanceObject = CeAP_k_SingleZero;
  } else {
    *rty_DistanceObject = localB->Switch;
  }

  /* End of Saturate: '<S12>/Saturation' */
}

/* Output and update for function-call system: '<S7>/GetPointData' */
void Rear_ObjectDection_GetPointData_n(const US_S_PointOutputBuff_t
  rtu_PointMapData[96], uint8_T rtu_PointMapIndex, real32_T *rty_pt_x, real32_T *
  rty_pt_y, US_S_PointOutputBuff_t *rty_pt_confidence, uint8_T
  *rty_pt_CruisingAge, uint8_T *rty_pt_height,
  B_GetPointData_Rear_ObjectDection_n_T *localB)
{
  /* Selector: '<S13>/Selector' */
  *rty_pt_confidence = rtu_PointMapData[rtu_PointMapIndex];

  /* Saturate: '<S13>/Saturation' */
  if (rty_pt_confidence->x > 1023) {
    localB->Saturation1 = 1023;
  } else if (rty_pt_confidence->x < (-1023)) {
    localB->Saturation1 = (-1023);
  } else {
    localB->Saturation1 = rty_pt_confidence->x;
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  *rty_pt_x = localB->Saturation1;

  /* Saturate: '<S13>/Saturation1' */
  if (rty_pt_confidence->y > 1023) {
    localB->Saturation1 = 1023;
  } else if (rty_pt_confidence->y < (-1023)) {
    localB->Saturation1 = (-1023);
  } else {
    localB->Saturation1 = rty_pt_confidence->y;
  }

  /* End of Saturate: '<S13>/Saturation1' */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  *rty_pt_y = localB->Saturation1;

  /* SignalConversion generated from: '<S13>/pt_CruisingAge' */
  *rty_pt_CruisingAge = rty_pt_confidence->Cruising_Age;

  /* SignalConversion generated from: '<S13>/pt_height' */
  *rty_pt_height = rty_pt_confidence->height;
}

/* Function for Chart: '<S2>/CalculateRearBrakingDistance1' */
static void Rear_ObjectDection_CheckForCurbLikePatternRear(const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData)
{
  uint8_T RearPtSeparationCount;
  uint8_T InnerIdx;
  uint8_T fidx;
  uint8_T RearCurbCount;
  int32_T u;
  int16_T u_0;
  int16_T u_1;
  uint8_T tmp;
  int32_T exitg1;
  int32_T exitg2;
  RearCurbCount = 0U;
  fidx = 0U;
  do {
    exitg1 = 0;
    if (10 < Rear_ObjectDection_DW.RearIdx) {
      tmp = 10U;
    } else {
      tmp = Rear_ObjectDection_DW.RearIdx;
    }

    if (fidx < tmp) {
      memcpy(&Rear_ObjectDection_B.PointMapData_l[0],
             &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
             (US_S_PointOutputBuff_t));
      Rear_ObjectDection_B.PointMapIndex_h =
        Rear_ObjectDection_DW.RearPointsArray[fidx];
      Rear_ObjectDection_GetPointData_n(Rear_ObjectDection_B.PointMapData_l,
        Rear_ObjectDection_B.PointMapIndex_h,
        &Rear_ObjectDection_B.DataTypeConversion_j,
        &Rear_ObjectDection_B.DataTypeConversion1_o,
        &Rear_ObjectDection_B.Selector_d, &Rear_ObjectDection_B.Cruising_Age,
        &Rear_ObjectDection_B.height, &Rear_ObjectDection_B.GetPointData);
      Rear_ObjectDection_DW.current_point_x =
        Rear_ObjectDection_B.DataTypeConversion_j;
      Rear_ObjectDection_DW.current_point_y =
        Rear_ObjectDection_B.DataTypeConversion1_o;
      Rear_ObjectDection_DW.current_point_confidence =
        Rear_ObjectDection_B.Selector_d.confidence;
      u = Rear_ObjectDection_DW.RrBrk_Pt_x - (int16_T)
        Rear_ObjectDection_DW.current_point_x;
      if (u < 0) {
        u = -u;
      }

      if (u <= ((int16_T)KePA_cm_RearCurbDetectLongThd)) {
        RearPtSeparationCount = 0U;
        InnerIdx = 0U;
        do {
          exitg2 = 0;
          if (10 < Rear_ObjectDection_DW.RearIdx) {
            tmp = 10U;
          } else {
            tmp = Rear_ObjectDection_DW.RearIdx;
          }

          if (InnerIdx < tmp) {
            memcpy(&Rear_ObjectDection_B.PointMapData_l[0],
                   &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
                   (US_S_PointOutputBuff_t));
            Rear_ObjectDection_B.PointMapIndex_h =
              Rear_ObjectDection_DW.RearPointsArray[InnerIdx];
            Rear_ObjectDection_GetPointData_n
              (Rear_ObjectDection_B.PointMapData_l,
               Rear_ObjectDection_B.PointMapIndex_h,
               &Rear_ObjectDection_B.DataTypeConversion_j,
               &Rear_ObjectDection_B.DataTypeConversion1_o,
               &Rear_ObjectDection_B.Selector_d,
               &Rear_ObjectDection_B.Cruising_Age, &Rear_ObjectDection_B.height,
               &Rear_ObjectDection_B.GetPointData);
            u_0 = (int16_T)(Rear_ObjectDection_B.DataTypeConversion_j -
                            Rear_ObjectDection_DW.current_point_x);
            u_1 = (int16_T)(Rear_ObjectDection_B.DataTypeConversion1_o -
                            Rear_ObjectDection_DW.current_point_y);
            if (u_0 < 0) {
              u_0 = (int16_T)-u_0;
            }

            if (u_1 < 0) {
              u_1 = (int16_T)-u_1;
            }

            if ((u_0 <= ((int16_T)KePA_cm_RearCurbDetectLongThd)) && (u_1 >=
                 ((int16_T)KePA_cm_RearCurbDetectLatThd))) {
              RearPtSeparationCount++;
            }

            InnerIdx++;
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);

        if (RearPtSeparationCount >= 2) {
          /* Increament Rear Curb Count */
          RearCurbCount++;
        }
      }

      fidx++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if ((RearCurbCount >= ((uint8_T)KePA_cnt_RearCurbPntCntThd)) &&
      (Rear_ObjectDection_B.HeighConfCounts <= 3)) {
    /*  Rear object is Curb - 1 */
    Rear_ObjectDection_B.MeAP_b_IsCurb = 1U;
  }
}

/* Function for Chart: '<S2>/CalculateRearBrakingDistance1' */
static void Rear_ObjectDection_CheckForWallLikePatternRear(const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData)
{
  uint8_T RearPtSeparationCount;
  uint8_T InnerIdx;
  uint8_T fidx;
  uint8_T RearWallCount;
  int32_T u;
  int16_T u_0;
  int16_T u_1;
  uint8_T tmp;
  int32_T exitg1;
  int32_T exitg2;
  RearWallCount = 0U;
  fidx = 0U;
  do {
    exitg1 = 0;
    if (10 < Rear_ObjectDection_DW.RearHighIdx) {
      tmp = 10U;
    } else {
      tmp = Rear_ObjectDection_DW.RearHighIdx;
    }

    if (fidx < tmp) {
      memcpy(&Rear_ObjectDection_B.PointMapData_l[0],
             &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
             (US_S_PointOutputBuff_t));
      Rear_ObjectDection_B.PointMapIndex_h =
        Rear_ObjectDection_DW.RearHighPointsArray[fidx];
      Rear_ObjectDection_GetPointData_n(Rear_ObjectDection_B.PointMapData_l,
        Rear_ObjectDection_B.PointMapIndex_h,
        &Rear_ObjectDection_B.DataTypeConversion_j,
        &Rear_ObjectDection_B.DataTypeConversion1_o,
        &Rear_ObjectDection_B.Selector_d, &Rear_ObjectDection_B.Cruising_Age,
        &Rear_ObjectDection_B.height, &Rear_ObjectDection_B.GetPointData);
      Rear_ObjectDection_DW.current_point_x =
        Rear_ObjectDection_B.DataTypeConversion_j;
      Rear_ObjectDection_DW.current_point_y =
        Rear_ObjectDection_B.DataTypeConversion1_o;
      Rear_ObjectDection_DW.current_point_confidence =
        Rear_ObjectDection_B.Selector_d.confidence;
      u = Rear_ObjectDection_DW.RrBrk_Pt_x - (int16_T)
        Rear_ObjectDection_DW.current_point_x;
      if (u < 0) {
        u = -u;
      }

      if (u <= ((int16_T)KePA_cm_RearCurbDetectLongThd)) {
        RearPtSeparationCount = 0U;
        InnerIdx = 0U;
        do {
          exitg2 = 0;
          if (10 < Rear_ObjectDection_DW.RearHighIdx) {
            tmp = 10U;
          } else {
            tmp = Rear_ObjectDection_DW.RearHighIdx;
          }

          if (InnerIdx < tmp) {
            memcpy(&Rear_ObjectDection_B.PointMapData_l[0],
                   &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
                   (US_S_PointOutputBuff_t));
            Rear_ObjectDection_B.PointMapIndex_h =
              Rear_ObjectDection_DW.RearHighPointsArray[InnerIdx];
            Rear_ObjectDection_GetPointData_n
              (Rear_ObjectDection_B.PointMapData_l,
               Rear_ObjectDection_B.PointMapIndex_h,
               &Rear_ObjectDection_B.DataTypeConversion_j,
               &Rear_ObjectDection_B.DataTypeConversion1_o,
               &Rear_ObjectDection_B.Selector_d,
               &Rear_ObjectDection_B.Cruising_Age, &Rear_ObjectDection_B.height,
               &Rear_ObjectDection_B.GetPointData);
            u_0 = (int16_T)(Rear_ObjectDection_B.DataTypeConversion_j -
                            Rear_ObjectDection_DW.current_point_x);
            u_1 = (int16_T)(Rear_ObjectDection_B.DataTypeConversion1_o -
                            Rear_ObjectDection_DW.current_point_y);
            if (u_0 < 0) {
              u_0 = (int16_T)-u_0;
            }

            if (u_1 < 0) {
              u_1 = (int16_T)-u_1;
            }

            if ((u_0 <= ((int16_T)KePA_cm_RearCurbDetectLongThd)) && (u_1 >=
                 ((int16_T)KePA_cm_RearCurbDetectLatThd))) {
              RearPtSeparationCount++;
            }

            InnerIdx++;
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);

        if (RearPtSeparationCount >= 2) {
          /* Increament Rear Wall Count */
          RearWallCount++;
        }
      }

      fidx++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (RearWallCount >= 4) {
    Rear_ObjectDection_B.WallLikeStructure = 1U;
  }
}

/* Function for Chart: '<S2>/CalculateRearBrakingDistance1' */
static void Rear_ObjectDection_GetRearBrakingRegionPoints(void)
{
  /*  2D point in center region */
  if ((Rear_ObjectDection_DW.current_point_y <= 150.0F) &&
      (Rear_ObjectDection_DW.current_point_y >= -150.0F) &&
      (Rear_ObjectDection_DW.RearIdx < Rear_ObjectDection_RearBinSize)) {
    /*  Rear 2D points */
    /* Increament Rear Wall Count */
    Rear_ObjectDection_DW.RearPointsArray[Rear_ObjectDection_DW.RearIdx] =
      Rear_ObjectDection_DW.point_index;
    Rear_ObjectDection_DW.RearIdx++;
  } else {
    /*  2D Point not in center region */
    /*  Points Not aligned */
  }
}

/* Function for Chart: '<S2>/CalculateRearBrakingDistance1' */
static void Rear_ObjectDection_CheckNeaighbourHoodForRAEB(const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData)
{
  uint8_T pt_i;
  int16_T x_min;
  int16_T x_max;
  int16_T y_min;
  int16_T y_max;
  int16_T cp_x;
  int16_T cp_y;

  /*  NeighbourHood check enabled */
  if (KePA_b_EnFeatPointSplitImp != 0) {
    /* check front center point */
    Rear_ObjectDection_DW.Current_Pt.x = (int16_T)
      Rear_ObjectDection_DW.current_point_x;
    Rear_ObjectDection_DW.Current_Pt.y = (int16_T)
      Rear_ObjectDection_DW.current_point_y;
    Rear_ObjectDection_DW.Current_Pt.confidence =
      Rear_ObjectDection_DW.current_point_confidence;

    /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
     *  EnablePort: '<Root>/Enable'
     */
    /* Chart: '<S2>/CalculateRearBrakingDistance1' */
    memcpy(&Rear_ObjectDection_B.PointMapData[0],
           &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
           (US_S_PointOutputBuff_t));
    Rear_ObjectDection_B.CurrentPoint = Rear_ObjectDection_DW.Current_Pt;

    /* Outputs for Function Call SubSystem: '<S7>/NeighbourHoodCheck' */
    /* Saturate: '<S15>/Saturation' incorporates:
     *  Constant: '<S15>/Constant'
     */
    if (KeAP_cm_NhXminOffset > 100) {
      Rear_ObjectDection_B.Saturation_g = 100;
    } else if (KeAP_cm_NhXminOffset < (-100)) {
      Rear_ObjectDection_B.Saturation_g = (-100);
    } else {
      Rear_ObjectDection_B.Saturation_g = KeAP_cm_NhXminOffset;
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* Saturate: '<S15>/Saturation1' incorporates:
     *  Constant: '<S15>/Constant1'
     */
    if (KeAP_cm_NhXmaxOffset > 100) {
      Rear_ObjectDection_B.Saturation1_p = 100;
    } else if (KeAP_cm_NhXmaxOffset < (-100)) {
      Rear_ObjectDection_B.Saturation1_p = (-100);
    } else {
      Rear_ObjectDection_B.Saturation1_p = KeAP_cm_NhXmaxOffset;
    }

    /* End of Saturate: '<S15>/Saturation1' */

    /* Saturate: '<S15>/Saturation2' incorporates:
     *  Constant: '<S15>/Constant2'
     */
    if (KeAP_cm_NhYminOffset > 100) {
      Rear_ObjectDection_B.Saturation2_a = 100;
    } else if (KeAP_cm_NhYminOffset < (-100)) {
      Rear_ObjectDection_B.Saturation2_a = (-100);
    } else {
      Rear_ObjectDection_B.Saturation2_a = KeAP_cm_NhYminOffset;
    }

    /* End of Saturate: '<S15>/Saturation2' */

    /* Saturate: '<S15>/Saturation3' incorporates:
     *  Constant: '<S15>/Constant3'
     */
    if (KeAP_cm_NhYmaxOffset > 100) {
      Rear_ObjectDection_B.Saturation3_l = 100;
    } else if (KeAP_cm_NhYmaxOffset < (-100)) {
      Rear_ObjectDection_B.Saturation3_l = (-100);
    } else {
      Rear_ObjectDection_B.Saturation3_l = KeAP_cm_NhYmaxOffset;
    }

    /* End of Saturate: '<S15>/Saturation3' */

    /* Chart: '<S15>/NeighbourCheck' */
    Rear_ObjectDection_B.DiscardPoint = ((uint8_T)CeAP_k_Uint8Zero);
    pt_i = 0U;
    x_min = (int16_T)(Rear_ObjectDection_B.CurrentPoint.x -
                      Rear_ObjectDection_B.Saturation_g);
    x_max = (int16_T)(Rear_ObjectDection_B.CurrentPoint.x +
                      Rear_ObjectDection_B.Saturation1_p);
    y_min = (int16_T)(Rear_ObjectDection_B.CurrentPoint.y -
                      Rear_ObjectDection_B.Saturation2_a);
    y_max = (int16_T)(Rear_ObjectDection_B.CurrentPoint.y +
                      Rear_ObjectDection_B.Saturation3_l);
    if ((0 < ((uint8_T)96U)) && (Rear_ObjectDection_B.DiscardPoint == ((uint8_T)
          CeAP_k_Uint8Zero))) {
      memcpy(&Rear_ObjectDection_B.PointMapData_k[0],
             &Rear_ObjectDection_B.PointMapData[0], 96U * sizeof
             (US_S_PointOutputBuff_t));
    }

    while ((pt_i < ((uint8_T)96U)) && (Rear_ObjectDection_B.DiscardPoint ==
            ((uint8_T)CeAP_k_Uint8Zero))) {
      Rear_ObjectDection_B.PointMapIndex_n = pt_i;

      /* Outputs for Function Call SubSystem: '<S21>/GetPointData' */
      Rear_ObjectDection_GetPointData(Rear_ObjectDection_B.PointMapData_k,
        Rear_ObjectDection_B.PointMapIndex_n,
        &Rear_ObjectDection_B.DataTypeConversion_e,
        &Rear_ObjectDection_B.DataTypeConversion1_p,
        &Rear_ObjectDection_B.Selector_e, &Rear_ObjectDection_B.GetPointData_n);

      /* End of Outputs for SubSystem: '<S21>/GetPointData' */
      cp_x = (int16_T)Rear_ObjectDection_B.DataTypeConversion_e;
      cp_y = (int16_T)Rear_ObjectDection_B.DataTypeConversion1_p;
      if ((cp_x <= x_max) && (cp_x >= x_min) && (cp_y <= y_max) && (cp_y >=
           y_min) && (Rear_ObjectDection_B.Selector_e.confidence >
                      Rear_ObjectDection_B.CurrentPoint.confidence)) {
        Rear_ObjectDection_B.DiscardPoint = ((uint8_T)CeAP_k_Uint8One);
      }

      pt_i += ((uint8_T)CeAP_k_Uint8One);
    }

    /* End of Chart: '<S15>/NeighbourCheck' */

    /* SignalConversion generated from: '<S15>/DiscardPoint' */
    Rear_ObjectDection_B.OutportBufferForDiscardPoint =
      Rear_ObjectDection_B.DiscardPoint;

    /* End of Outputs for SubSystem: '<S7>/NeighbourHoodCheck' */
    if (Rear_ObjectDection_B.OutportBufferForDiscardPoint != 0) {
      Rear_ObjectDection_DW.DistanceToObject = Rear_ObjectDection_DW.MaxDist;
    }
  }
}

/* System initialize for referenced model: 'Rear_ObjectDection' */
void Rear_ObjectDection_Init(real32_T *rty_MeAP_cm_RearDist, int16_T
  *rty_MeAP_cm_RawRearDist)
{
  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  Rear_ObjectDection_DW.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  Rear_ObjectDection_DW.UnitDelay_DSTATE = 1023.0F;

  /* SystemInitialize for Chart: '<S2>/CalculateRearBrakingDistance1' */
  Rear_ObjectDection_DW.Current_Pt.x = 0;
  Rear_ObjectDection_DW.Current_Pt.y = 0;
  Rear_ObjectDection_DW.Current_Pt.height = 0U;
  Rear_ObjectDection_DW.Current_Pt.Cruising_Age = 0U;
  Rear_ObjectDection_DW.Current_Pt.confidence = 0U;
  Rear_ObjectDection_DW.Current_Pt.age = 0U;

  /* SystemInitialize for Outport: '<Root>/MeAP_cm_RearDist' */
  *rty_MeAP_cm_RearDist = 1023.0F;

  /* SystemInitialize for Outport: '<Root>/MeAP_cm_RawRearDist' */
  *rty_MeAP_cm_RawRearDist = 1023;
}

/* System reset for referenced model: 'Rear_ObjectDection' */
void Rear_ObjectDection_Reset(void)
{
  int32_T i;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  Rear_ObjectDection_DW.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  Rear_ObjectDection_DW.UnitDelay_DSTATE = 1023.0F;

  /* SystemReset for Chart: '<S2>/CalculateRearBrakingDistance1' */
  Rear_ObjectDection_DW.MaxDist = 0.0F;
  Rear_ObjectDection_DW.current_point_x = 0.0F;
  Rear_ObjectDection_DW.current_point_y = 0.0F;
  Rear_ObjectDection_DW.current_point_confidence = 0U;
  Rear_ObjectDection_DW.DistanceToObject = 0.0F;
  Rear_ObjectDection_DW.point_index = 0U;
  Rear_ObjectDection_DW.Current_Pt.x = 0;
  Rear_ObjectDection_DW.Current_Pt.y = 0;
  Rear_ObjectDection_DW.Current_Pt.height = 0U;
  Rear_ObjectDection_DW.Current_Pt.Cruising_Age = 0U;
  Rear_ObjectDection_DW.Current_Pt.confidence = 0U;
  Rear_ObjectDection_DW.Current_Pt.age = 0U;
  Rear_ObjectDection_DW.RearIdx = 0U;
  Rear_ObjectDection_DW.RrBrk_Pt_x = 0;
  Rear_ObjectDection_DW.RearHighIdx = 0U;
  for (i = 0; i < 10; i++) {
    Rear_ObjectDection_DW.RearPointsArray[i] = 0U;
    Rear_ObjectDection_DW.RearHighPointsArray[i] = 0U;
  }

  Rear_ObjectDection_B.MeAP_cm_RearBrakingDist = 0.0F;
  Rear_ObjectDection_B.MeAP_b_ObjDetected = 0.0F;
  Rear_ObjectDection_B.MeAP_b_IsCurb = 0U;
  Rear_ObjectDection_B.HeighConfCounts = 0U;
  Rear_ObjectDection_B.CurbDist = 0.0F;
  Rear_ObjectDection_B.WallLikeStructure = 0U;
  Rear_ObjectDection_B.IsPoleStructure = 0U;

  /* End of SystemReset for Chart: '<S2>/CalculateRearBrakingDistance1' */

  /* SystemReset for Chart: '<S2>/Curb_Dbnc' */
  Rear_ObjectDection_DW.is_active_c35_Rear_ObjectDection = 0U;
  Rear_ObjectDection_DW.FCDbncCount = 0U;
  Rear_ObjectDection_DW.CurbBrkDistLatch = 0U;
  Rear_ObjectDection_DW.CurbDistStart = 0.0F;
  Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
  Rear_ObjectDection_DW.WallDistLatch = 0U;
  Rear_ObjectDection_DW.WallDistStart = 0.0F;
  Rear_ObjectDection_DW.WallDetectCount = 0U;
  Rear_ObjectDection_DW.PoleDistLatch = 0U;
  Rear_ObjectDection_DW.PoleDistStart = 0.0F;
  Rear_ObjectDection_B.MeAP_b_CurbFiltered = 0.0F;
}

/* Disable for referenced model: 'Rear_ObjectDection' */
void Rear_ObjectDection_Disable(real32_T *rty_MeAP_cm_RearDist, boolean_T
  *rty_MeAP_b_ObjInPath, int16_T *rty_MeAP_cm_RawRearDist)
{
  if (Rear_ObjectDection_DW.TmpModelReferenceSubsystem_MODE) {
    /* Disable for Chart: '<S2>/CalculateRearBrakingDistance1' incorporates:
     *  SubSystem: '<S7>/NeighbourHoodCheck'
     */
    /* Disable for Outport: '<S15>/DiscardPoint' */
    Rear_ObjectDection_B.OutportBufferForDiscardPoint = ((uint8_T)0U);

    /* Disable for Chart: '<S2>/CalculateRearBrakingDistance1' incorporates:
     *  SubSystem: '<S7>/NeighbourHoodCheckForPole'
     */
    /* Disable for Outport: '<S16>/IsPole' */
    Rear_ObjectDection_B.OutportBufferForIsPole = ((uint8_T)0U);

    /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
     *  EnablePort: '<Root>/Enable'
     */
    /* Disable for Outport: '<Root>/MeAP_cm_RearDist' */
    *rty_MeAP_cm_RearDist = 1023.0F;

    /* Disable for Outport: '<Root>/MeAP_b_ObjInPath' */
    *rty_MeAP_b_ObjInPath = false;

    /* Disable for Outport: '<Root>/MeAP_cm_RawRearDist' */
    *rty_MeAP_cm_RawRearDist = 1023;
    Rear_ObjectDection_DW.TmpModelReferenceSubsystem_MODE = false;
  }
}

/* Output and update for referenced model: 'Rear_ObjectDection' */
void Rear_ObjectDection(const TbVBIA_VehState_AP *rtu_VehStates, const
  US_S_PointMapOutputBuff_t *rtu_IaInpAdpr_k_envData, const real32_T
  *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const
  TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const uint8_T
  *rtu_EnableBrakingTriggered, const boolean_T *rtu_Enable, real32_T
  *rty_MeAP_cm_RearDist, boolean_T *rty_MeAP_b_ObjInPath, int16_T
  *rty_MeAP_cm_RawRearDist)
{
  int16_T MinRearBrakingDistance;
  real32_T CurbDistInt;
  real32_T DiffCurbPt;
  real32_T CurbDistSaturate;
  uint8_T FC_FollowInput;
  int16_T x_min;
  int16_T x_max;
  int16_T y_min;
  int16_T y_max;
  int16_T cp_x;
  int16_T cp_y;
  uint8_T ObjPtCounts;
  uint8_T LatDiff;
  int16_T LeftMax;
  int16_T RightMax;
  int32_T i;

  /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
   *  EnablePort: '<Root>/Enable'
   */
  if (*rtu_Enable) {
    if (!Rear_ObjectDection_DW.TmpModelReferenceSubsystem_MODE) {
      Rear_ObjectDection_Reset();
      Rear_ObjectDection_DW.TmpModelReferenceSubsystem_MODE = true;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion1' */
    Rear_ObjectDection_B.DataTypeConversion1_d = (uint8_T)
      rtu_MbNVM_ProxyParam->KeAP_e_WhlBas;

    /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     */
    switch (Rear_ObjectDection_B.DataTypeConversion1_d) {
     case 0:
      Rear_ObjectDection_B.MeAP_cm_RrAxlRadius = 3.5687F;
      break;

     case 1:
      Rear_ObjectDection_B.MeAP_cm_RrAxlRadius = 3.6703F;
      break;

     case 2:
      Rear_ObjectDection_B.MeAP_cm_RrAxlRadius = 3.8989F;
      break;

     default:
      Rear_ObjectDection_B.MeAP_cm_RrAxlRadius = 3.6703F;
      break;
    }

    /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

    /* Gain: '<S6>/Gain' */
    Rear_ObjectDection_B.MeAP_cm_RrAxlRadius *= 100.0F;

    /* Saturate: '<S6>/Saturation4' */
    if (rtu_VehStates->IeVBII_deg_StrWhlAng > 720.0F) {
      Rear_ObjectDection_B.Subtract3_p = 720.0F;
    } else if (rtu_VehStates->IeVBII_deg_StrWhlAng < (-720.0F)) {
      Rear_ObjectDection_B.Subtract3_p = (-720.0F);
    } else {
      Rear_ObjectDection_B.Subtract3_p = rtu_VehStates->IeVBII_deg_StrWhlAng;
    }

    /* End of Saturate: '<S6>/Saturation4' */

    /* Abs: '<S6>/Abs' */
    Rear_ObjectDection_B.Abs = fabsf(Rear_ObjectDection_B.Subtract3_p);

    /* Lookup_n-D: '<S10>/steering_XXc.mat2' */
    Rear_ObjectDection_B.steering_XXcmat2 = look1_iflf_binlxpw
      (Rear_ObjectDection_B.Abs, rtCP_steering_XXcmat2_bp01Data,
       rtCP_steering_XXcmat2_tableData, 8U);

    /* MultiPortSwitch: '<S10>/Multiport Switch' */
    switch (rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp) {
     case TeAP_e_SteerRatRackPinionTyp_Type_1:
      /* Lookup_n-D: '<S10>/steering_XXc.mat' */
      Rear_ObjectDection_B.steering_XXcmat = look1_iflf_binlxpw
        (Rear_ObjectDection_B.Abs, rtCP_steering_XXcmat_bp01Data,
         rtCP_steering_XXcmat_tableData, 8U);
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius =
        Rear_ObjectDection_B.steering_XXcmat;
      break;

     case TeAP_e_SteerRatRackPinionTyp_Type_2:
      /* Lookup_n-D: '<S10>/steering_XXc.mat1' */
      Rear_ObjectDection_B.steering_XXcmat1 = look1_iflf_binlxpw
        (Rear_ObjectDection_B.Abs, rtCP_steering_XXcmat1_bp01Data,
         rtCP_steering_XXcmat1_tableData, 8U);
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius =
        Rear_ObjectDection_B.steering_XXcmat1;
      break;

     default:
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius =
        Rear_ObjectDection_B.steering_XXcmat2;
      break;
    }

    /* End of MultiPortSwitch: '<S10>/Multiport Switch' */

    /* Saturate: '<S10>/Saturation1' */
    if (Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius > 360.0F) {
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius = 360.0F;
    } else {
      if (Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius < 0.0F) {
        Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius = 0.0F;
      }
    }

    /* End of Saturate: '<S10>/Saturation1' */

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/whl_base3'
     *  Constant: '<S6>/whl_base4'
     */
    if (Rear_ObjectDection_B.Subtract3_p > CeAP_k_SingleZero) {
      Rear_ObjectDection_B.Subtract3_p = CeAP_k_SingleOne;
    } else {
      Rear_ObjectDection_B.Subtract3_p = CeAP_k_SingleNegOne;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Product: '<S6>/Product1' */
    Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius *=
      Rear_ObjectDection_B.Subtract3_p;

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S6>/whl_base5'
     */
    if (CONST_DPS2RPS > 100.0F) {
      Rear_ObjectDection_B.Subtract3_p = 100.0F;
    } else if (CONST_DPS2RPS < 0.0F) {
      Rear_ObjectDection_B.Subtract3_p = 0.0F;
    } else {
      Rear_ObjectDection_B.Subtract3_p = CONST_DPS2RPS;
    }

    /* End of Saturate: '<S6>/Saturation1' */

    /* Product: '<S6>/Product2' */
    Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius *=
      Rear_ObjectDection_B.Subtract3_p;

    /* Trigonometry: '<S6>/Trigonometric Function' */
    Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius = tanf
      (Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius);

    /* Abs: '<S9>/Abs' */
    Rear_ObjectDection_B.Subtract3_p = fabsf
      (Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius);

    /* RelationalOperator: '<S9>/Relational Operator' incorporates:
     *  Constant: '<S9>/Constant'
     */
    Rear_ObjectDection_B.LogicalOperator3 = (Rear_ObjectDection_B.Subtract3_p >
      0.0001F);

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if (!Rear_ObjectDection_B.LogicalOperator3) {
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius = 0.0001F;
    }

    /* End of Switch: '<S9>/Switch' */

    /* Product: '<S9>/Divide' */
    Rear_ObjectDection_B.MeAP_cm_RrAxlRadius /=
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius;

    /* Abs: '<S6>/Abs1' */
    Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius = fabsf
      (Rear_ObjectDection_B.MeAP_cm_RrAxlRadius);

    /* Product: '<S6>/Divide' incorporates:
     *  Constant: '<S6>/Constant8'
     */
    Rear_ObjectDection_B.Subtract3_p =
      *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth / CeAP_k_SingleTwo;

    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    Rear_ObjectDection_B.Subtract3_p += K_e_RAEB_DrawingTubeOffset +
      K_e_RAEB_WarnOffset;

    /* Saturate: '<S6>/Saturation2' */
    if (Rear_ObjectDection_B.Subtract3_p > 1000.0F) {
      Rear_ObjectDection_B.Subtract3_p = 1000.0F;
    } else {
      if (Rear_ObjectDection_B.Subtract3_p < 0.0F) {
        Rear_ObjectDection_B.Subtract3_p = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation2' */

    /* Gain: '<S6>/Gain4' */
    Rear_ObjectDection_B.Subtract3_p *= 100.0F;

    /* Sum: '<S6>/Add2' */
    Rear_ObjectDection_B.Add2 = Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius +
      Rear_ObjectDection_B.Subtract3_p;

    /* Saturate: '<S6>/Saturation3' */
    if (*rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj > 1000) {
      Rear_ObjectDection_B.Saturation3_j = 1000;
    } else if (*rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj < 0) {
      Rear_ObjectDection_B.Saturation3_j = 0;
    } else {
      Rear_ObjectDection_B.Saturation3_j =
        *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj;
    }

    /* End of Saturate: '<S6>/Saturation3' */

    /* DataTypeConversion: '<S6>/Data Type Conversion4' */
    Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc_c =
      Rear_ObjectDection_B.Saturation3_j;

    /* Math: '<S6>/sq7' */
    Rear_ObjectDection_B.MeAP_cm_RearMaxRadius = rt_hypotf_snf
      (Rear_ObjectDection_B.Add2,
       Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc_c);

    /* Sum: '<S6>/Subtract3' */
    Rear_ObjectDection_B.Subtract3_p =
      Rear_ObjectDection_B.MeAP_cm_AbsRrAxlRadius -
      Rear_ObjectDection_B.Subtract3_p;

    /* Math: '<S6>/sq8' */
    Rear_ObjectDection_B.MeAP_cm_RearMinRadius = rt_hypotf_snf
      (Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc_c,
       Rear_ObjectDection_B.Subtract3_p);

    /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
     *  Constant: '<S6>/Constant'
     */
    Rear_ObjectDection_B.MeAP_cm_RotCenterX = 0;

    /* SignalConversion: '<S6>/Signal Conversion' */
    Rear_ObjectDection_B.MeAP_cm_RotCenterY =
      Rear_ObjectDection_B.MeAP_cm_RrAxlRadius;

    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    Rear_ObjectDection_B.DataTypeConversion4 =
      *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj;

    /* Saturate: '<S2>/Saturation' */
    if (rtu_VehStates->IeVBII_kph_VehSpeedVSOSig > 20.0F) {
      Rear_ObjectDection_B.Saturation = 20.0F;
    } else if (rtu_VehStates->IeVBII_kph_VehSpeedVSOSig < 0.0F) {
      Rear_ObjectDection_B.Saturation = 0.0F;
    } else {
      Rear_ObjectDection_B.Saturation = rtu_VehStates->IeVBII_kph_VehSpeedVSOSig;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* UnitDelay: '<S2>/Unit Delay1' */
    Rear_ObjectDection_B.UnitDelay1 = Rear_ObjectDection_DW.UnitDelay1_DSTATE;

    /*  initialise Outputs to max dist */
    Rear_ObjectDection_DW.point_index = ((uint8_T)CeAP_k_Uint8Zero);
    Rear_ObjectDection_DW.MaxDist = 1023.0F;
    Rear_ObjectDection_B.MeAP_b_ObjDetected = 0.0F;
    Rear_ObjectDection_DW.RearIdx = 0U;
    Rear_ObjectDection_B.MeAP_b_IsCurb = 0U;
    Rear_ObjectDection_DW.RrBrk_Pt_x = 0;
    Rear_ObjectDection_B.HeighConfCounts = 0U;
    CurbDistInt = Rear_ObjectDection_DW.MaxDist;
    CurbDistSaturate = fminf(fmaxf(0.0F, Rear_ObjectDection_B.CurbDist),
      Rear_ObjectDection_DW.MaxDist);
    Rear_ObjectDection_DW.RearHighIdx = 0U;
    for (i = 0; i < 10; i++) {
      Rear_ObjectDection_DW.RearPointsArray[i] = CeAP_k_CurbArrayInit[i];
      Rear_ObjectDection_DW.RearHighPointsArray[i] = CeAP_k_CurbArrayInit[i];
    }

    Rear_ObjectDection_B.WallLikeStructure = 0U;

    /*  initialise distance signals to max dist */
    Rear_ObjectDection_DW.DistanceToObject = Rear_ObjectDection_DW.MaxDist;
    MinRearBrakingDistance = (int16_T)Rear_ObjectDection_DW.MaxDist;

    /* Chart: '<S2>/CalculateRearBrakingDistance1' incorporates:
     *  SubSystem: '<S7>/InitalisePointData'
     */
    /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
     *  Constant: '<S14>/Constant'
     */
    Rear_ObjectDection_B.BusCreator1.height = (uint8_T)0;

    /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
     *  Constant: '<S14>/Constant'
     */
    Rear_ObjectDection_B.BusCreator1.x = 0;

    /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
     *  Constant: '<S14>/Constant'
     */
    Rear_ObjectDection_B.BusCreator1.y = 0;

    /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
     *  Constant: '<S14>/Constant'
     */
    Rear_ObjectDection_B.BusCreator1.Cruising_Age = (uint8_T)0;

    /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
     *  Constant: '<S14>/Constant'
     */
    Rear_ObjectDection_B.BusCreator1.confidence = (uint8_T)0;

    /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
     *  Constant: '<S14>/Constant'
     */
    Rear_ObjectDection_B.BusCreator1.age = (uint8_T)0;
    Rear_ObjectDection_DW.Current_Pt = Rear_ObjectDection_B.BusCreator1;
    if (Rear_ObjectDection_DW.point_index < ((uint8_T)96U)) {
      memcpy(&Rear_ObjectDection_B.PointMapData_l[0],
             &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
             (US_S_PointOutputBuff_t));
    }

    while (Rear_ObjectDection_DW.point_index < ((uint8_T)96U)) {
      Rear_ObjectDection_DW.DistanceToObject = fabsf
        (Rear_ObjectDection_DW.MaxDist);

      /* current_point_x=single(pointMap[point_index].x);
         current_point_y=single(pointMap[point_index].y);
         current_point_confidence = pointMap[point_index].confidence; */
      Rear_ObjectDection_B.PointMapIndex_h = Rear_ObjectDection_DW.point_index;

      /* Outputs for Function Call SubSystem: '<S7>/GetPointData' */
      Rear_ObjectDection_GetPointData_n(Rear_ObjectDection_B.PointMapData_l,
        Rear_ObjectDection_B.PointMapIndex_h,
        &Rear_ObjectDection_B.DataTypeConversion_j,
        &Rear_ObjectDection_B.DataTypeConversion1_o,
        &Rear_ObjectDection_B.Selector_d, &Rear_ObjectDection_B.Cruising_Age,
        &Rear_ObjectDection_B.height, &Rear_ObjectDection_B.GetPointData);

      /* End of Outputs for SubSystem: '<S7>/GetPointData' */
      Rear_ObjectDection_DW.current_point_x =
        Rear_ObjectDection_B.DataTypeConversion_j;
      Rear_ObjectDection_DW.current_point_y =
        Rear_ObjectDection_B.DataTypeConversion1_o;
      Rear_ObjectDection_DW.current_point_confidence =
        Rear_ObjectDection_B.Selector_d.confidence;

      /* Constant: '<S2>/Constant11' */
      if ((Rear_ObjectDection_DW.current_point_x >
           -Rear_ObjectDection_DW.MaxDist) &&
          (Rear_ObjectDection_DW.current_point_x <
           -Rear_ObjectDection_B.DataTypeConversion4) &&
          (Rear_ObjectDection_DW.current_point_confidence >
           KeAP_pct_ObjConfidenceThd)) {
        if (fabsf(rtu_VehStates->IeVBII_deg_StrWhlAng) >
            CeAP_deg_MinSteerCurvature) {
          Rear_ObjectDection_B.pt_x = Rear_ObjectDection_DW.current_point_x;
          Rear_ObjectDection_B.pt_y = Rear_ObjectDection_DW.current_point_y;
          Rear_ObjectDection_B.Cx = Rear_ObjectDection_B.MeAP_cm_RotCenterX;
          Rear_ObjectDection_B.Cy = Rear_ObjectDection_B.MeAP_cm_RotCenterY;
          Rear_ObjectDection_B.Rmax = Rear_ObjectDection_B.MeAP_cm_RearMaxRadius;
          Rear_ObjectDection_B.Rmin = Rear_ObjectDection_B.MeAP_cm_RearMinRadius;
          Rear_ObjectDection_B.AdjDist =
            -Rear_ObjectDection_B.DataTypeConversion4;

          /* Outputs for Function Call SubSystem: '<S7>/CalcDistToObjCurved' */
          /* Sum: '<S11>/Subtract1' */
          Rear_ObjectDection_B.Subtract1 = Rear_ObjectDection_B.pt_x -
            Rear_ObjectDection_B.Cx;

          /* Sum: '<S11>/Subtract2' */
          Rear_ObjectDection_B.Subtract2 = Rear_ObjectDection_B.pt_y -
            Rear_ObjectDection_B.Cy;

          /* Math: '<S11>/sq' */
          Rear_ObjectDection_B.Dist_pt2c = rt_hypotf_snf
            (Rear_ObjectDection_B.Subtract1, Rear_ObjectDection_B.Subtract2);

          /* Sum: '<S11>/Subtract3' */
          Rear_ObjectDection_B.Subtract3 = Rear_ObjectDection_B.AdjDist -
            Rear_ObjectDection_B.Cx;

          /* RelationalOperator: '<S11>/Relational Operator1' */
          Rear_ObjectDection_B.LogicalOperator = (Rear_ObjectDection_B.Dist_pt2c
            < Rear_ObjectDection_B.Rmax);

          /* RelationalOperator: '<S11>/Relational Operator2' */
          Rear_ObjectDection_B.Compare = (Rear_ObjectDection_B.Dist_pt2c >
            Rear_ObjectDection_B.Rmin);

          /* Logic: '<S11>/Logical Operator' */
          Rear_ObjectDection_B.LogicalOperator =
            (Rear_ObjectDection_B.LogicalOperator &&
             Rear_ObjectDection_B.Compare);

          /* RelationalOperator: '<S17>/Compare' incorporates:
           *  Constant: '<S17>/Constant'
           */
          Rear_ObjectDection_B.Compare = (Rear_ObjectDection_B.Cy >
            CeAP_k_SingleZero);

          /* Product: '<S11>/Product1' */
          Rear_ObjectDection_B.Abs_i = Rear_ObjectDection_B.Dist_pt2c *
            Rear_ObjectDection_B.Dist_pt2c;

          /* Product: '<S11>/Product2' */
          Rear_ObjectDection_B.Merge = Rear_ObjectDection_B.Subtract3 *
            Rear_ObjectDection_B.Subtract3;

          /* Sum: '<S11>/Subtract6' */
          Rear_ObjectDection_B.Abs_i -= Rear_ObjectDection_B.Merge;

          /* Abs: '<S11>/Abs' */
          Rear_ObjectDection_B.Abs_i = fabsf(Rear_ObjectDection_B.Abs_i);

          /* Sqrt: '<S11>/Sqrt' */
          Rear_ObjectDection_B.Sqrt = sqrtf(Rear_ObjectDection_B.Abs_i);

          /* Switch: '<S11>/Switch' */
          if (Rear_ObjectDection_B.Compare) {
            /* Gain: '<S11>/Gain' */
            Rear_ObjectDection_B.Gain = CeAP_k_SingleNegOne *
              Rear_ObjectDection_B.Sqrt;
            Rear_ObjectDection_B.Switch = Rear_ObjectDection_B.Gain;
          } else {
            Rear_ObjectDection_B.Switch = Rear_ObjectDection_B.Sqrt;
          }

          /* End of Switch: '<S11>/Switch' */

          /* If: '<S11>/If' */
          if (Rear_ObjectDection_B.LogicalOperator) {
            /* Outputs for IfAction SubSystem: '<S11>/ObjPtInPath' incorporates:
             *  ActionPort: '<S18>/Action Port'
             */
            /* Trigonometry: '<S18>/Cos' incorporates:
             *  Product: '<S18>/Product'
             */
            Rear_ObjectDection_B.Abs1 = Rear_ObjectDection_B.Subtract1 *
              Rear_ObjectDection_B.Subtract3;

            /* Product: '<S18>/Product1' */
            Rear_ObjectDection_B.Switch_e = Rear_ObjectDection_B.Subtract2 *
              Rear_ObjectDection_B.Switch;

            /* Trigonometry: '<S18>/Cos' incorporates:
             *  Sum: '<S18>/Subtract1'
             */
            Rear_ObjectDection_B.Abs1 += Rear_ObjectDection_B.Switch_e;

            /* Math: '<S18>/sq' */
            Rear_ObjectDection_B.Switch_e = rt_hypotf_snf
              (Rear_ObjectDection_B.Subtract3, Rear_ObjectDection_B.Switch);

            /* Product: '<S18>/Product2' */
            Rear_ObjectDection_B.Switch_e *= Rear_ObjectDection_B.Dist_pt2c;

            /* Abs: '<S20>/Abs' */
            Rear_ObjectDection_B.Abs_d = fabsf(Rear_ObjectDection_B.Switch_e);

            /* RelationalOperator: '<S20>/Relational Operator' incorporates:
             *  Constant: '<S20>/Constant'
             */
            Rear_ObjectDection_B.RelationalOperator =
              (Rear_ObjectDection_B.Abs_d > 0.0001F);

            /* Switch: '<S20>/Switch' incorporates:
             *  Constant: '<S20>/Constant'
             */
            if (!Rear_ObjectDection_B.RelationalOperator) {
              Rear_ObjectDection_B.Switch_e = 0.0001F;
            }

            /* End of Switch: '<S20>/Switch' */

            /* Trigonometry: '<S18>/Cos' incorporates:
             *  Product: '<S20>/Divide'
             */
            Rear_ObjectDection_B.Abs1 /= Rear_ObjectDection_B.Switch_e;

            /* Saturate: '<S18>/Saturation' */
            if (Rear_ObjectDection_B.Abs1 > CeAP_k_SingleOne) {
              /* Trigonometry: '<S18>/Cos' */
              Rear_ObjectDection_B.Abs1 = CeAP_k_SingleOne;
            } else {
              if (Rear_ObjectDection_B.Abs1 < CeAP_k_SingleNegOne) {
                /* Trigonometry: '<S18>/Cos' */
                Rear_ObjectDection_B.Abs1 = CeAP_k_SingleNegOne;
              }
            }

            /* End of Saturate: '<S18>/Saturation' */

            /* Trigonometry: '<S18>/Cos' incorporates:
             *  Abs: '<S18>/Abs1'
             *  Product: '<S18>/Product3'
             */
            if (Rear_ObjectDection_B.Abs1 > 1.0F) {
              Rear_ObjectDection_B.Abs1 = 1.0F;
            } else {
              if (Rear_ObjectDection_B.Abs1 < -1.0F) {
                Rear_ObjectDection_B.Abs1 = -1.0F;
              }
            }

            Rear_ObjectDection_B.Abs1 = acosf(Rear_ObjectDection_B.Abs1);
            Rear_ObjectDection_B.Abs1 *= Rear_ObjectDection_B.Dist_pt2c;
            Rear_ObjectDection_B.Abs1 = fabsf(Rear_ObjectDection_B.Abs1);

            /* Sum: '<S18>/Subtract' incorporates:
             *  Constant: '<S11>/Constant'
             */
            Rear_ObjectDection_B.Merge = Rear_ObjectDection_B.Abs1 -
              CeAP_k_SingleZero;

            /* End of Outputs for SubSystem: '<S11>/ObjPtInPath' */
          } else {
            /* Outputs for IfAction SubSystem: '<S11>/ObjPtNotInPath' incorporates:
             *  ActionPort: '<S19>/Action Port'
             */
            /* SignalConversion: '<S19>/Signal Conversion' incorporates:
             *  Constant: '<S19>/Constant1'
             */
            Rear_ObjectDection_B.Merge = 1023.0F;

            /* End of Outputs for SubSystem: '<S11>/ObjPtNotInPath' */
          }

          /* End of If: '<S11>/If' */

          /* Switch: '<S11>/Switch1' incorporates:
           *  Constant: '<S11>/Constant1'
           */
          if (Rear_ObjectDection_B.Merge > 1023.0F) {
            Rear_ObjectDection_B.DistanceObject_i = 1023.0F;
          } else {
            Rear_ObjectDection_B.DistanceObject_i = Rear_ObjectDection_B.Merge;
          }

          /* End of Switch: '<S11>/Switch1' */
          /* End of Outputs for SubSystem: '<S7>/CalcDistToObjCurved' */
          Rear_ObjectDection_DW.DistanceToObject =
            Rear_ObjectDection_B.DistanceObject_i;
        } else {
          Rear_ObjectDection_B.pt_x_i = -Rear_ObjectDection_DW.current_point_x;
          Rear_ObjectDection_B.pt_y_p = Rear_ObjectDection_DW.current_point_y;
          Rear_ObjectDection_B.AdjDist_h =
            Rear_ObjectDection_B.DataTypeConversion4;

          /* Outputs for Function Call SubSystem: '<S7>/CalcDistToObjStraight' */
          Rear_ObjectDection_CalcDistToObjStraight(Rear_ObjectDection_B.pt_x_i,
            Rear_ObjectDection_B.pt_y_p, Rear_ObjectDection_B.AdjDist_h,
            &Rear_ObjectDection_B.DistanceObject,
            &Rear_ObjectDection_B.CalcDistToObjStraight);

          /* End of Outputs for SubSystem: '<S7>/CalcDistToObjStraight' */
          Rear_ObjectDection_DW.DistanceToObject =
            Rear_ObjectDection_B.DistanceObject;
        }

        Rear_ObjectDection_CheckNeaighbourHoodForRAEB(rtu_IaInpAdpr_k_envData);
        if (Rear_ObjectDection_DW.DistanceToObject < MinRearBrakingDistance) {
          Rear_ObjectDection_DW.RrBrk_Pt_x = (int16_T)
            Rear_ObjectDection_DW.current_point_x;
          DiffCurbPt = fabsf(((CurbDistSaturate -
                               Rear_ObjectDection_B.Saturation / 3.6F) + fminf
                              (fmaxf(0.0F,
            Rear_ObjectDection_B.DataTypeConversion4), 1023.0F)) + (real32_T)
                             Rear_ObjectDection_DW.RrBrk_Pt_x);
          if ((Rear_ObjectDection_B.UnitDelay1 != 0.0F) &&
              (Rear_ObjectDection_B.height == 2) && (DiffCurbPt > 0.0F) &&
              (CurbDistSaturate < 300.0F)) {
            MinRearBrakingDistance = (int16_T)
              Rear_ObjectDection_DW.DistanceToObject;
            Rear_ObjectDection_B.MeAP_b_ObjDetected = 1.0F;
          } else {
            if (((!(DiffCurbPt <= 10.0F)) || (!(Rear_ObjectDection_B.UnitDelay1
                   != 0.0F)) || (!(CurbDistSaturate < 300.0F))) &&
                ((Rear_ObjectDection_B.Cruising_Age <= ((uint8_T)
                   KeAP_k_RaebCruiseAgeThd)) ||
                 (!(Rear_ObjectDection_B.UnitDelay1 != 0.0F)))) {
              MinRearBrakingDistance = (int16_T)
                Rear_ObjectDection_DW.DistanceToObject;
              Rear_ObjectDection_B.MeAP_b_ObjDetected = 1.0F;
            }
          }
        } else {
          /* No Change */
        }
      } else {
        /*  Do Not Update Min Distance */
      }

      if ((Rear_ObjectDection_DW.current_point_x > -470.0F) &&
          (Rear_ObjectDection_DW.current_point_x <
           -Rear_ObjectDection_B.DataTypeConversion4) &&
          (Rear_ObjectDection_DW.current_point_confidence <= ((uint8_T)
            KeAP_pct_CurbConfThd)) && (Rear_ObjectDection_B.height == 1)) {
        Rear_ObjectDection_B.pt_x_i = -Rear_ObjectDection_DW.current_point_x;
        Rear_ObjectDection_B.pt_y_p = Rear_ObjectDection_DW.current_point_y;
        Rear_ObjectDection_B.AdjDist_h =
          Rear_ObjectDection_B.DataTypeConversion4;

        /* Outputs for Function Call SubSystem: '<S7>/CalcDistToObjStraight' */
        Rear_ObjectDection_CalcDistToObjStraight(Rear_ObjectDection_B.pt_x_i,
          Rear_ObjectDection_B.pt_y_p, Rear_ObjectDection_B.AdjDist_h,
          &Rear_ObjectDection_B.DistanceObject,
          &Rear_ObjectDection_B.CalcDistToObjStraight);

        /* End of Outputs for SubSystem: '<S7>/CalcDistToObjStraight' */
        Rear_ObjectDection_GetRearBrakingRegionPoints();
        if (Rear_ObjectDection_B.DistanceObject < CurbDistInt) {
          CurbDistInt = Rear_ObjectDection_B.DistanceObject;
        }
      }

      if ((Rear_ObjectDection_DW.current_point_x > -470.0F) &&
          (Rear_ObjectDection_DW.current_point_x <
           -Rear_ObjectDection_B.DataTypeConversion4) &&
          ((Rear_ObjectDection_DW.current_point_confidence >= 78) ||
           ((Rear_ObjectDection_DW.current_point_confidence > 10) &&
            (Rear_ObjectDection_B.height != 1)))) {
        /* WallLikeStructureCount = WallLikeStructureCount + uint8(1); */
        /*  2D point in center region */
        if ((Rear_ObjectDection_DW.current_point_y <= 150.0F) &&
            (Rear_ObjectDection_DW.current_point_y >= -150.0F) &&
            (Rear_ObjectDection_DW.RearHighIdx < Rear_ObjectDection_RearBinSize))
        {
          /*  Rear 2D points */
          /* Increament Rear Wall Count */
          Rear_ObjectDection_DW.RearHighPointsArray[Rear_ObjectDection_DW.RearHighIdx]
            = Rear_ObjectDection_DW.point_index;
          Rear_ObjectDection_DW.RearHighIdx++;
        } else {
          /*  2D Point not in center region */
          /*  Points Not aligned */
        }

        Rear_ObjectDection_DW.Current_Pt.x = (int16_T)
          Rear_ObjectDection_DW.current_point_x;
        Rear_ObjectDection_DW.Current_Pt.y = (int16_T)
          Rear_ObjectDection_DW.current_point_y;
        Rear_ObjectDection_DW.Current_Pt.confidence =
          Rear_ObjectDection_DW.current_point_confidence;
        Rear_ObjectDection_DW.Current_Pt.Cruising_Age =
          Rear_ObjectDection_B.Cruising_Age;
        memcpy(&Rear_ObjectDection_B.PointMapData_c[0],
               &rtu_IaInpAdpr_k_envData->pointMap[0], 96U * sizeof
               (US_S_PointOutputBuff_t));
        Rear_ObjectDection_B.CurrentPoint_j = Rear_ObjectDection_DW.Current_Pt;

        /* Outputs for Function Call SubSystem: '<S7>/NeighbourHoodCheckForPole' */
        /* Saturate: '<S16>/Saturation' incorporates:
         *  Constant: '<S16>/Constant'
         */
        if (15 > 200) {
          Rear_ObjectDection_B.Saturation_e = 200;
        } else if (15 < (-200)) {
          Rear_ObjectDection_B.Saturation_e = (-200);
        } else {
          Rear_ObjectDection_B.Saturation_e = 15;
        }

        /* End of Saturate: '<S16>/Saturation' */

        /* Saturate: '<S16>/Saturation1' incorporates:
         *  Constant: '<S16>/Constant1'
         */
        if (15 > 200) {
          Rear_ObjectDection_B.Saturation1 = 200;
        } else if (15 < (-200)) {
          Rear_ObjectDection_B.Saturation1 = (-200);
        } else {
          Rear_ObjectDection_B.Saturation1 = 15;
        }

        /* End of Saturate: '<S16>/Saturation1' */

        /* Saturate: '<S16>/Saturation2' incorporates:
         *  Constant: '<S16>/Constant2'
         */
        if (300 > 200) {
          Rear_ObjectDection_B.Saturation2 = 200;
        } else if (300 < (-200)) {
          Rear_ObjectDection_B.Saturation2 = (-200);
        } else {
          Rear_ObjectDection_B.Saturation2 = 300;
        }

        /* End of Saturate: '<S16>/Saturation2' */

        /* Saturate: '<S16>/Saturation3' incorporates:
         *  Constant: '<S16>/Constant3'
         */
        if (300 > 200) {
          Rear_ObjectDection_B.Saturation3 = 200;
        } else if (300 < (-200)) {
          Rear_ObjectDection_B.Saturation3 = (-200);
        } else {
          Rear_ObjectDection_B.Saturation3 = 300;
        }

        /* End of Saturate: '<S16>/Saturation3' */

        /* Chart: '<S16>/NeighbourCheck' */
        Rear_ObjectDection_B.IsPole = ((uint8_T)CeAP_k_Uint8Zero);
        FC_FollowInput = 0U;
        x_min = (int16_T)(Rear_ObjectDection_B.CurrentPoint_j.x -
                          Rear_ObjectDection_B.Saturation_e);
        x_max = (int16_T)(Rear_ObjectDection_B.CurrentPoint_j.x +
                          Rear_ObjectDection_B.Saturation1);
        y_min = (int16_T)(Rear_ObjectDection_B.CurrentPoint_j.y -
                          Rear_ObjectDection_B.Saturation2);
        y_max = (int16_T)(Rear_ObjectDection_B.CurrentPoint_j.y +
                          Rear_ObjectDection_B.Saturation3);
        ObjPtCounts = ((uint8_T)CeAP_k_Uint8Zero);
        LeftMax = 0;
        RightMax = 0;
        if (0 < ((uint8_T)96U)) {
          memcpy(&Rear_ObjectDection_B.PointMapData_b[0],
                 &Rear_ObjectDection_B.PointMapData_c[0], 96U * sizeof
                 (US_S_PointOutputBuff_t));
        }

        while ((FC_FollowInput < ((uint8_T)96U)) && (ObjPtCounts == ((uint8_T)
                 CeAP_k_Uint8Zero))) {
          Rear_ObjectDection_B.PointMapIndex = FC_FollowInput;

          /* Outputs for Function Call SubSystem: '<S23>/GetPointData' */
          Rear_ObjectDection_GetPointData(Rear_ObjectDection_B.PointMapData_b,
            Rear_ObjectDection_B.PointMapIndex,
            &Rear_ObjectDection_B.DataTypeConversion,
            &Rear_ObjectDection_B.DataTypeConversion1,
            &Rear_ObjectDection_B.Selector,
            &Rear_ObjectDection_B.GetPointData_nj);

          /* End of Outputs for SubSystem: '<S23>/GetPointData' */
          cp_x = (int16_T)Rear_ObjectDection_B.DataTypeConversion;
          cp_y = (int16_T)Rear_ObjectDection_B.DataTypeConversion1;
          if ((cp_x <= x_max) && (cp_x >= x_min)) {
            if ((cp_y <= y_max) && (cp_y > Rear_ObjectDection_B.CurrentPoint_j.y))
            {
              i = cp_y - Rear_ObjectDection_B.CurrentPoint_j.y;
              if (i < 0) {
                LatDiff = (uint8_T)-i;
              } else {
                LatDiff = (uint8_T)i;
              }

              if ((Rear_ObjectDection_B.Selector.confidence > 40) && (LatDiff >
                   15)) {
                ObjPtCounts += ((uint8_T)CeAP_k_Uint8One);
              }

              if (LeftMax < LatDiff) {
                LeftMax = LatDiff;
              }
            }

            if ((cp_y < Rear_ObjectDection_B.CurrentPoint_j.y) && (cp_y >= y_min))
            {
              i = cp_y - Rear_ObjectDection_B.CurrentPoint_j.y;
              if (i < 0) {
                LatDiff = (uint8_T)-i;
              } else {
                LatDiff = (uint8_T)i;
              }

              if ((Rear_ObjectDection_B.Selector.confidence > 40) && (LatDiff >
                   15)) {
                ObjPtCounts += ((uint8_T)CeAP_k_Uint8One);
              }

              if (RightMax < LatDiff) {
                RightMax = LatDiff;
              }
            }
          }

          FC_FollowInput += ((uint8_T)CeAP_k_Uint8One);
        }

        i = LeftMax - RightMax;
        if (i < 0) {
          i = -i;
        }

        if ((i < 100) && (ObjPtCounts == ((uint8_T)CeAP_k_Uint8Zero)) &&
            (Rear_ObjectDection_B.CurrentPoint_j.Cruising_Age < 8)) {
          Rear_ObjectDection_B.IsPole = ((uint8_T)CeAP_k_Uint8One);
        }

        /* End of Chart: '<S16>/NeighbourCheck' */

        /* SignalConversion generated from: '<S16>/IsPole' */
        Rear_ObjectDection_B.OutportBufferForIsPole =
          Rear_ObjectDection_B.IsPole;

        /* End of Outputs for SubSystem: '<S7>/NeighbourHoodCheckForPole' */
        Rear_ObjectDection_B.IsPoleStructure =
          Rear_ObjectDection_B.OutportBufferForIsPole;
      }

      /* Constant: '<S2>/Constant11' */
      if ((Rear_ObjectDection_DW.current_point_x > -470.0F) &&
          (Rear_ObjectDection_DW.current_point_x <
           -Rear_ObjectDection_B.DataTypeConversion4) &&
          ((Rear_ObjectDection_DW.current_point_confidence >= 70) ||
           ((Rear_ObjectDection_DW.current_point_confidence >
             KeAP_pct_ObjConfidenceThd) && (Rear_ObjectDection_B.height != 1))))
      {
        Rear_ObjectDection_B.HeighConfCounts++;
      }

      Rear_ObjectDection_DW.point_index += ((uint8_T)CeAP_k_Uint8One);
    }

    Rear_ObjectDection_B.MeAP_cm_RearBrakingDist = MinRearBrakingDistance;
    if ((Rear_ObjectDection_B.CurbDist < 75.0F) && (CurbDistInt > 1022.0F)) {
      Rear_ObjectDection_B.CurbDist = CurbDistSaturate -
        Rear_ObjectDection_B.Saturation / 3.6F;
    } else {
      Rear_ObjectDection_B.CurbDist = fminf(fmaxf(0.0F, CurbDistInt),
        Rear_ObjectDection_DW.MaxDist);
    }

    Rear_ObjectDection_CheckForCurbLikePatternRear(rtu_IaInpAdpr_k_envData);
    Rear_ObjectDection_CheckForWallLikePatternRear(rtu_IaInpAdpr_k_envData);

    /* Logic: '<S4>/Logical Operator3' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    Rear_ObjectDection_B.LogicalOperator3 =
      (!UssOD_bIsLowObjectRear() || (KeAP_b_SupprsUssGlblHght
        != 0)); //Keep

    /* Logic: '<S4>/Logical Operator2' */
    Rear_ObjectDection_B.MeAP_b_ObjDetected_p =
      ((Rear_ObjectDection_B.MeAP_b_ObjDetected != 0.0F) &&
       Rear_ObjectDection_B.LogicalOperator3);

    /* Switch generated from: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    if (Rear_ObjectDection_B.MeAP_b_ObjDetected_p) {
      /* SignalConversion: '<S4>/Signal Conversion3' */
      Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc =
        Rear_ObjectDection_B.MeAP_cm_RearBrakingDist;
      Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc_c =
        Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc;
    } else {
      Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc_c = 1023.0F;
    }

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    CurbDistInt = floorf(Rear_ObjectDection_B.MeAP_cm_floatRearDistCalc_c);
    if (rtIsNaNF(CurbDistInt) || rtIsInfF(CurbDistInt)) {
      CurbDistInt = 0.0F;
    } else {
      CurbDistInt = fmodf(CurbDistInt, 65536.0F);
    }

    *rty_MeAP_cm_RawRearDist = (int16_T)(CurbDistInt < 0.0F ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-CurbDistInt : (int32_T)(int16_T)(uint16_T)CurbDistInt);

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* UnitDelay: '<Root>/Unit Delay' */
    Rear_ObjectDection_B.UnitDelay = Rear_ObjectDection_DW.UnitDelay_DSTATE;

    /* Switch generated from: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    if (Rear_ObjectDection_B.MeAP_b_ObjDetected_p) {
      /* SignalConversion: '<S4>/Signal Conversion1' */
      Rear_ObjectDection_B.MeAP_b_ObjPresent =
        Rear_ObjectDection_B.MeAP_b_ObjDetected_p;
      *rty_MeAP_b_ObjInPath = Rear_ObjectDection_B.MeAP_b_ObjPresent;
    } else {
      *rty_MeAP_b_ObjInPath = false;
    }

    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    if (*rty_MeAP_b_ObjInPath) {
      /* Product: '<S3>/Divide' incorporates:
       *  Constant: '<S3>/Kmph_to_mps_ConvFact'
       */
      Rear_ObjectDection_B.Dist_CMPSampleTime =
        rtu_VehStates->IeVBII_kph_VehSpeedVSOSig / 3.6F;

      /* Product: '<S3>/Divide1' incorporates:
       *  Constant: '<S3>/m_to_cm_ConvFact'
       */
      Rear_ObjectDection_B.Dist_CMPSampleTime *= 100.0F;

      /* Product: '<S3>/Divide2' incorporates:
       *  Constant: '<S3>/Sample_Time'
       */
      Rear_ObjectDection_B.Dist_CMPSampleTime *= 0.03F;

      /* Selector: '<S1>/Selector' incorporates:
       *  Constant: '<S1>/DelayFact2'
       */
      Rear_ObjectDection_B.Selector_eb = rtu_IaInpAdpr_k_envData->pointMap
        [((uint8_T)92U)];

      /* RelationalOperator: '<S5>/Compare' incorporates:
       *  Constant: '<S5>/Constant'
       */
      Rear_ObjectDection_B.LogicalOperator_m =
        (Rear_ObjectDection_B.Selector_eb.Cruising_Age != ((uint8_T)2U));

      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/DelayFact3'
       */
      if (Rear_ObjectDection_B.LogicalOperator_m) {
        Rear_ObjectDection_B.MeAP_cnt_RRDistCompFactor =
          KeAP_cnt_RearDistCompTimeThd;
      } else {
        /* Sum: '<S1>/Add' incorporates:
         *  Constant: '<S1>/DelayFact1'
         *  Constant: '<S1>/DelayFact3'
         */
        Rear_ObjectDection_B.Add = KeAP_cnt_RearDistCompTimeThd +
          KeAP_cnt_NoiseModeRearDistComp;
        Rear_ObjectDection_B.MeAP_cnt_RRDistCompFactor =
          Rear_ObjectDection_B.Add;
      }

      /* End of Switch: '<S1>/Switch' */

      /* Product: '<S3>/Divide3' */
      Rear_ObjectDection_B.Divide3 = Rear_ObjectDection_B.Dist_CMPSampleTime *
        Rear_ObjectDection_B.MeAP_cnt_RRDistCompFactor;

      /* RelationalOperator: '<Root>/Relational Operator' */
      Rear_ObjectDection_B.LogicalOperator_m = (Rear_ObjectDection_B.Divide3 <
        *rty_MeAP_cm_RawRearDist);

      /* Logic: '<Root>/Logical Operator' incorporates:
       *  Constant: '<Root>/Constant'
       */
      Rear_ObjectDection_B.LogicalOperator_m =
        (Rear_ObjectDection_B.LogicalOperator_m &&
         KeAP_b_RearDistCorrBasedVehSpd);

      /* Switch: '<Root>/Switch1' */
      if (Rear_ObjectDection_B.LogicalOperator_m) {
        /* Sum: '<Root>/Subtract2' */
        Rear_ObjectDection_B.Subtract2_c = (real32_T)*rty_MeAP_cm_RawRearDist -
          Rear_ObjectDection_B.Divide3;
        Rear_ObjectDection_B.MeAP_cm_RearDist = Rear_ObjectDection_B.Subtract2_c;
      } else {
        Rear_ObjectDection_B.MeAP_cm_RearDist = Rear_ObjectDection_B.UnitDelay;
      }

      /* End of Switch: '<Root>/Switch1' */
      *rty_MeAP_cm_RearDist = Rear_ObjectDection_B.MeAP_cm_RearDist;
    } else {
      *rty_MeAP_cm_RearDist = 1023.0F;
    }

    /* End of Switch: '<Root>/Switch2' */

    /* Chart: '<S2>/Curb_Dbnc' */
    Rear_ObjectDection_DW.MeAP_b_IsCurb_prev =
      Rear_ObjectDection_DW.MeAP_b_IsCurb_start;
    Rear_ObjectDection_DW.MeAP_b_IsCurb_start =
      Rear_ObjectDection_B.MeAP_b_IsCurb;
    Rear_ObjectDection_DW.WallLikeStructure_prev =
      Rear_ObjectDection_DW.WallLikeStructure_start;
    Rear_ObjectDection_DW.WallLikeStructure_start =
      Rear_ObjectDection_B.WallLikeStructure;
    Rear_ObjectDection_DW.IsPoleStructure_prev =
      Rear_ObjectDection_DW.IsPoleStructure_start;
    Rear_ObjectDection_DW.IsPoleStructure_start =
      Rear_ObjectDection_B.IsPoleStructure;
    if (Rear_ObjectDection_DW.is_active_c35_Rear_ObjectDection == 0U) {
      Rear_ObjectDection_DW.MeAP_b_IsCurb_prev =
        Rear_ObjectDection_B.MeAP_b_IsCurb;
      Rear_ObjectDection_DW.WallLikeStructure_prev =
        Rear_ObjectDection_B.WallLikeStructure;
      Rear_ObjectDection_DW.IsPoleStructure_prev =
        Rear_ObjectDection_B.IsPoleStructure;
      Rear_ObjectDection_DW.is_active_c35_Rear_ObjectDection = 1U;
      Rear_ObjectDection_B.MeAP_b_CurbFiltered = 0.0F;
      Rear_ObjectDection_DW.FCDbncCount = 0U;
      Rear_ObjectDection_DW.CurbBrkDistLatch = 0U;
      Rear_ObjectDection_DW.CurbDistStart = 0.0F;
      Rear_ObjectDection_DW.WallDistStart = 0.0F;
      Rear_ObjectDection_DW.WallDistLatch = 0U;
      Rear_ObjectDection_DW.WallDetectCount = 0U;
      Rear_ObjectDection_DW.PoleDistStart = 0.0F;
      Rear_ObjectDection_DW.PoleDistLatch = 0U;
      if ((Rear_ObjectDection_B.MeAP_b_IsCurb == 0) &&
          (Rear_ObjectDection_B.MeAP_b_CurbFiltered != 0.0F)) {
        i = Rear_ObjectDection_DW.FCDbncCount + 1;
        if (i < 255) {
          Rear_ObjectDection_DW.FCDbncCount = (uint8_T)i;
        } else {
          Rear_ObjectDection_DW.FCDbncCount = MAX_uint8_T;
        }

        if ((Rear_ObjectDection_DW.FCDbncCount > ((uint8_T)CeAP_k_CurbDbnc)) &&
            (((Rear_ObjectDection_B.CurbDist > CeAP_cm_CurbLatchDist) &&
              (Rear_ObjectDection_B.CurbDist < 300.0F)) ||
             ((Rear_ObjectDection_DW.CurbBrkDistLatch == 0) ||
              (Rear_ObjectDection_B.HeighConfCounts > 3)))) {
          FC_FollowInput = 1U;
          Rear_ObjectDection_DW.FCDbncCount = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
        } else {
          FC_FollowInput = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
        }
      } else {
        Rear_ObjectDection_DW.FCDbncCount = 0U;
        if (((Rear_ObjectDection_DW.MeAP_b_IsCurb_prev !=
              Rear_ObjectDection_DW.MeAP_b_IsCurb_start) &&
             (Rear_ObjectDection_DW.MeAP_b_IsCurb_start == 1)) ||
            ((Rear_ObjectDection_B.MeAP_b_IsCurb != 0) &&
             (!(Rear_ObjectDection_B.MeAP_b_CurbFiltered != 0.0F)))) {
          Rear_ObjectDection_DW.CurbDistStart = Rear_ObjectDection_B.CurbDist;
          FC_FollowInput = 1U;
        } else if (Rear_ObjectDection_B.MeAP_b_IsCurb != 0) {
          FC_FollowInput = 1U;
          if (Rear_ObjectDection_DW.CurbDistStart -
              Rear_ObjectDection_B.CurbDist > 35.0F) {
            Rear_ObjectDection_DW.CurbBrkDistLatch1 = 1.0F;
          }
        } else {
          FC_FollowInput = 1U;
          Rear_ObjectDection_DW.FCDbncCount = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
        }
      }

      if (((Rear_ObjectDection_DW.WallLikeStructure_prev !=
            Rear_ObjectDection_DW.WallLikeStructure_start) &&
           (Rear_ObjectDection_DW.WallLikeStructure_start == 1)) ||
          ((*rtu_EnableBrakingTriggered == 1) &&
           (Rear_ObjectDection_B.WallLikeStructure != 0))) {
        Rear_ObjectDection_DW.WallDistStart = Rear_ObjectDection_B.CurbDist;
        if (Rear_ObjectDection_B.CurbDist > 170.0F) {
          Rear_ObjectDection_DW.WallDetectCount++;
        }
      } else {
        if ((Rear_ObjectDection_B.WallLikeStructure != 0) &&
            (Rear_ObjectDection_DW.WallDistStart - Rear_ObjectDection_B.CurbDist
             > 30.0F)) {
          Rear_ObjectDection_DW.WallDistLatch = 1U;
        }
      }

      if (((Rear_ObjectDection_DW.IsPoleStructure_prev !=
            Rear_ObjectDection_DW.IsPoleStructure_start) &&
           (Rear_ObjectDection_DW.IsPoleStructure_start == 1)) ||
          ((*rtu_EnableBrakingTriggered == 1) &&
           (Rear_ObjectDection_B.IsPoleStructure != 0))) {
        Rear_ObjectDection_DW.PoleDistStart = Rear_ObjectDection_B.CurbDist;
      } else {
        if ((Rear_ObjectDection_B.IsPoleStructure != 0) &&
            (Rear_ObjectDection_DW.PoleDistStart - Rear_ObjectDection_B.CurbDist
             > 50.0F)) {
          Rear_ObjectDection_DW.PoleDistLatch = 1U;
        }
      }

      if ((Rear_ObjectDection_B.CurbDist < CeAP_cm_CurbLatchDist) &&
          (Rear_ObjectDection_DW.CurbBrkDistLatch1 != 0.0F)) {
        Rear_ObjectDection_DW.CurbBrkDistLatch = (uint8_T)
          Rear_ObjectDection_DW.CurbBrkDistLatch1;
      }

      if (FC_FollowInput == 1) {
        Rear_ObjectDection_B.MeAP_b_CurbFiltered =
          Rear_ObjectDection_B.MeAP_b_IsCurb;
      }

      if ((Rear_ObjectDection_DW.WallDistLatch == 1) ||
          (Rear_ObjectDection_DW.WallDetectCount >= 2) ||
          (Rear_ObjectDection_DW.PoleDistLatch == 1)) {
        Rear_ObjectDection_B.MeAP_b_CurbFiltered = 0.0F;
      }
    } else {
      if ((Rear_ObjectDection_B.MeAP_b_IsCurb == 0) &&
          (Rear_ObjectDection_B.MeAP_b_CurbFiltered != 0.0F)) {
        i = Rear_ObjectDection_DW.FCDbncCount + 1;
        if (i < 255) {
          Rear_ObjectDection_DW.FCDbncCount = (uint8_T)i;
        } else {
          Rear_ObjectDection_DW.FCDbncCount = MAX_uint8_T;
        }

        if ((Rear_ObjectDection_DW.FCDbncCount > ((uint8_T)CeAP_k_CurbDbnc)) &&
            (((Rear_ObjectDection_B.CurbDist > CeAP_cm_CurbLatchDist) &&
              (Rear_ObjectDection_B.CurbDist < 300.0F)) ||
             ((Rear_ObjectDection_DW.CurbBrkDistLatch == 0) ||
              (Rear_ObjectDection_B.HeighConfCounts > 3)))) {
          FC_FollowInput = 1U;
          Rear_ObjectDection_DW.FCDbncCount = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
        } else {
          FC_FollowInput = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
        }
      } else {
        Rear_ObjectDection_DW.FCDbncCount = 0U;
        if (((Rear_ObjectDection_DW.MeAP_b_IsCurb_prev !=
              Rear_ObjectDection_DW.MeAP_b_IsCurb_start) &&
             (Rear_ObjectDection_DW.MeAP_b_IsCurb_start == 1)) ||
            ((Rear_ObjectDection_B.MeAP_b_IsCurb != 0) &&
             (!(Rear_ObjectDection_B.MeAP_b_CurbFiltered != 0.0F)))) {
          Rear_ObjectDection_DW.CurbDistStart = Rear_ObjectDection_B.CurbDist;
          FC_FollowInput = 1U;
        } else if (Rear_ObjectDection_B.MeAP_b_IsCurb != 0) {
          FC_FollowInput = 1U;
          if (Rear_ObjectDection_DW.CurbDistStart -
              Rear_ObjectDection_B.CurbDist > 35.0F) {
            Rear_ObjectDection_DW.CurbBrkDistLatch1 = 1.0F;
          }
        } else {
          FC_FollowInput = 1U;
          Rear_ObjectDection_DW.FCDbncCount = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch = 0U;
          Rear_ObjectDection_DW.CurbBrkDistLatch1 = 0.0F;
        }
      }

      if (((Rear_ObjectDection_DW.WallLikeStructure_prev !=
            Rear_ObjectDection_DW.WallLikeStructure_start) &&
           (Rear_ObjectDection_DW.WallLikeStructure_start == 1)) ||
          ((*rtu_EnableBrakingTriggered == 1) &&
           (Rear_ObjectDection_B.WallLikeStructure != 0))) {
        Rear_ObjectDection_DW.WallDistStart = Rear_ObjectDection_B.CurbDist;
        if (Rear_ObjectDection_B.CurbDist > 170.0F) {
          Rear_ObjectDection_DW.WallDetectCount++;
        }
      } else {
        if ((Rear_ObjectDection_B.WallLikeStructure != 0) &&
            (Rear_ObjectDection_DW.WallDistStart - Rear_ObjectDection_B.CurbDist
             > 30.0F)) {
          Rear_ObjectDection_DW.WallDistLatch = 1U;
        }
      }

      if (((Rear_ObjectDection_DW.IsPoleStructure_prev !=
            Rear_ObjectDection_DW.IsPoleStructure_start) &&
           (Rear_ObjectDection_DW.IsPoleStructure_start == 1)) ||
          ((*rtu_EnableBrakingTriggered == 1) &&
           (Rear_ObjectDection_B.IsPoleStructure != 0))) {
        Rear_ObjectDection_DW.PoleDistStart = Rear_ObjectDection_B.CurbDist;
      } else {
        if ((Rear_ObjectDection_B.IsPoleStructure != 0) &&
            (Rear_ObjectDection_DW.PoleDistStart - Rear_ObjectDection_B.CurbDist
             > 50.0F)) {
          Rear_ObjectDection_DW.PoleDistLatch = 1U;
        }
      }

      if ((Rear_ObjectDection_B.CurbDist < CeAP_cm_CurbLatchDist) &&
          (Rear_ObjectDection_DW.CurbBrkDistLatch1 != 0.0F)) {
        Rear_ObjectDection_DW.CurbBrkDistLatch = (uint8_T)
          Rear_ObjectDection_DW.CurbBrkDistLatch1;
      }

      if (FC_FollowInput == 1) {
        Rear_ObjectDection_B.MeAP_b_CurbFiltered =
          Rear_ObjectDection_B.MeAP_b_IsCurb;
      }

      if ((Rear_ObjectDection_DW.WallDistLatch == 1) ||
          (Rear_ObjectDection_DW.WallDetectCount >= 2) ||
          (Rear_ObjectDection_DW.PoleDistLatch == 1)) {
        Rear_ObjectDection_B.MeAP_b_CurbFiltered = 0.0F;
      }
    }

    /* End of Chart: '<S2>/Curb_Dbnc' */

    /* Constant: '<S6>/Constant1' */
    Rear_ObjectDection_B.Constant1 = KeAP_cm_RearLongDistAdj;

    /* Update for UnitDelay: '<S2>/Unit Delay1' */
    Rear_ObjectDection_DW.UnitDelay1_DSTATE =
      Rear_ObjectDection_B.MeAP_b_CurbFiltered;

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    Rear_ObjectDection_DW.UnitDelay_DSTATE = *rty_MeAP_cm_RearDist;
  } else {
    Rear_ObjectDection_Disable(rty_MeAP_cm_RearDist, rty_MeAP_b_ObjInPath,
      rty_MeAP_cm_RawRearDist);
  }
}

/* Model initialize function */
void Rear_ObjectDection_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_Rear_ObjectDection_T *const Rear_ObjectDection_M =
    &(Rear_ObjectDection_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(Rear_ObjectDection_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
