/*
 * File: ComputeWheelSpeed_Rw46Mgmr.c
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.2042
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:34 2025
 */

#include "rtwtypes.h"
#include "ComputeWheelSpeed_Rw46Mgmr.h"

/*
 * Function for MATLAB Function: '<S36>/ComputeTickBasedWhlSpeed'
 * Function is made for incremental encoder with value rollover between a predefined min and max
 */
real32_T ComputeWheelSpeed_Rw46Mgmr(uint8_T currTick, uint8_T prevTick, real32_T
  deltaT, uint8_T ppr, uint8_T gear_value, real32_T wheel_radius)
{
  real32_T wheelSpeed;
  int32_T tickDifference;
  uint32_T qY;
  tickDifference = 0;
  if (currTick >= prevTick) {
    qY = (uint32_T)currTick - /*MW:OvSatOk*/ (uint32_T)prevTick;
    if (qY > (uint32_T)currTick) {
      qY = 0U;
    }

    tickDifference = (int32_T)qY;
  } else if (currTick < prevTick) {
    qY = 254U - /*MW:OvSatOk*/ (uint32_T)prevTick;
    if (qY > 254U) {
      qY = 0U;
    }

    tickDifference = (int32_T)(uint32_T)(qY + (uint32_T)currTick);
    if ((uint32_T)tickDifference > 255U) {
      tickDifference = 255;
    }

    tickDifference = (int32_T)(uint32_T)((uint32_T)tickDifference + 1U);
    if ((uint32_T)tickDifference > 255U) {
      tickDifference = 255;
    }
  } else {
    /* Do nothing, either speed is 0 or greater than 1rev/deltaT */
  }

  wheelSpeed = wheel_radius * (real32_T)tickDifference / (real32_T)ppr *
    6.28318548F / deltaT;
  if (2 != (int32_T)gear_value) {
    wheelSpeed = -wheelSpeed;
  }

  return wheelSpeed;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
