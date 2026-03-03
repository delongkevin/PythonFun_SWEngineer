/*
 * File: FrontObjectDetection_types.h
 *
 * Code generated for Simulink model 'FrontObjectDetection'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Dec 29 15:26:53 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FrontObjectDetection_types_h_
#define RTW_HEADER_FrontObjectDetection_types_h_
#include "rtwtypes.h"
#include "PlatformDataTypes.h"
#include "US_Interface_Output.h"

#include "JobKM.h"
//#include "AP_VrntTunParam.h"
#include "stdint.h"
#include "CalDataProvider_defs.h"
#ifndef DEFINED_TYPEDEF_FOR_TbFOD_InputVrntTunParam_t_
#define DEFINED_TYPEDEF_FOR_TbFOD_InputVrntTunParam_t_

typedef struct {
  int16_T KeFOD_cm_VehContour_FSL_x;
  int16_T KeFOD_cm_VehContour_FOL_x;
  int16_T KeFOD_cm_VehContour_FIL_x;
  int16_T KeFOD_cm_VehContour_FIR_x;
  int16_T KeFOD_cm_VehContour_FOR_x;
  int16_T KeFOD_cm_VehContour_FSR_x;
  int16_T KeFOD_cm_VehContour_FSL_y;
  int16_T KeFOD_cm_VehContour_FOL_y;
  int16_T KeFOD_cm_VehContour_FIL_y;
  int16_T KeFOD_cm_VehContour_FIR_y;
  int16_T KeFOD_cm_VehContour_FOR_y;
  int16_T KeFOD_cm_VehContour_FSR_y;
  int16_T KeFOD_cm_VehContour_RSR_x;
  int16_T KeFOD_cm_VehContour_ROR_x;
  int16_T KeFOD_cm_VehContour_RIR_x;
  int16_T KeFOD_cm_VehContour_RIL_x;
  int16_T KeFOD_cm_VehContour_ROL_x;
  int16_T KeFOD_cm_VehContour_RSL_x;
  int16_T KeFOD_cm_VehContour_RSR_y;
  int16_T KeFOD_cm_VehContour_ROR_y;
  int16_T KeFOD_cm_VehContour_RIR_y;
  int16_T KeFOD_cm_VehContour_RIL_y;
  int16_T KeFOD_cm_VehContour_ROL_y;
  int16_T KeFOD_cm_VehContour_RSL_y;
  int16_T KeFOD_cm_DistZone1;
  int16_T KeFOD_cm_DistZone2;
  int16_T KeFOD_cm_DistZone3;
  int16_T KeFOD_cm_DistZone4;
  int16_T KeFOD_cm_DistZone5;
  int16_T KeFOD_cm_DistZone6;
  int16_T KeFOD_cm_HalfVehicleWidth;
} TbFOD_InputVrntTunParam_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_FrontObjectDetection_T RT_MODEL_FrontObjectDetection_T;

#endif                            /* RTW_HEADER_FrontObjectDetection_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
