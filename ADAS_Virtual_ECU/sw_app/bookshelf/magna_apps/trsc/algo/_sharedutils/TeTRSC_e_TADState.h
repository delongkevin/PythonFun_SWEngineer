/*
 * File: TeTRSC_e_TADState.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TeTRSC_e_TADState_h_
#define RTW_HEADER_TeTRSC_e_TADState_h_
#include "rtwtypes.h"

typedef enum {
  TeTRSC_e_TADState_Idle = 0,          /* Default value */
  TeTRSC_e_TADState_TrailerDetection = 1,
  TeTRSC_e_TADState_TrailerRecognition = 2,
  TeTRSC_e_TADState_Calibration = 3,
  TeTRSC_e_TADState_ScanningForTrailer = 4,
  TeTRSC_e_TADState_Turnaround = 5,
  TeTRSC_e_TADState_AngleDetection = 6,
  TeTRSC_e_TADState_Trackinglost = 7,
  TeTRSC_e_TADState_Dummy = MAX_int32_T
} TeTRSC_e_TADState;

#endif                                 /* RTW_HEADER_TeTRSC_e_TADState_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
