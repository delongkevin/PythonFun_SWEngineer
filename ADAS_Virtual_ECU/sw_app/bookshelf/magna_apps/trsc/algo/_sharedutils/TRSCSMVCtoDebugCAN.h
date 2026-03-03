/*
 * File: TRSCSMVCtoDebugCAN.h
 *
 * Code generated for Simulink model 'TRSC_OutputAdapter'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:50 2025
 */

#ifndef RTW_HEADER_TRSCSMVCtoDebugCAN_h_
#define RTW_HEADER_TRSCSMVCtoDebugCAN_h_
#include "rtwtypes.h"

typedef struct {
  /* Steering Angle Command from TRSC VC */
  real32_T MeTRSC_deg_StrCMD;

  /* Reseved signal */
  real32_T ReservedTRSCSig1;

  /* Reseved signal */
  real32_T ReservedTRSCSig2;

  /* TRSC SMVC Periodicity */
  uint16_T MeTRSC_s_TRSCPeriodicity;

  /* TRSC SMVC Time Taken */
  uint16_T MeTRSC_s_TRSCTimeTaken;

  /* TRSC SMVC Alive counter */
  uint16_T MeTRSC_cnt_TRSCAliveCounter;

  /* Calibration Popup Information */
  boolean_T MeTRSC_b_TrlrCalibPopInfo;
} TRSCSMVCtoDebugCAN_t;

#endif                                 /* RTW_HEADER_TRSCSMVCtoDebugCAN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
