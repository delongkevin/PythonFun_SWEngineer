/// --------------------------------------------------------------------------
/// @file DLDAlgo.h
/// @brief Contains DLD algo main
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
/// --------------------------------------------------------------------------

#ifndef DLD_ALGO_H
#define DLD_ALGO_H

#include "DLDKalmanFilter1D.h"
#include "meal/camera/core/inc/Camera.h"
#include "DLDOutput.h"

extern "C" {
  #include <app_init.h>
  #include "../../modules/include/DLD_TI.h"
}

namespace dld {

class DLDAlgo {
private:
  //bool m_isInitialised;
  AppObj_DLD m_TIObj;
  kalman::DLD_Kalman_Filter_1D m_filterOcc[DLD_Camera_ID::DLD_NUM_CAMS];
  kalman::DLD_Kalman_Filter_1D m_filterLum[DLD_Camera_ID::DLD_NUM_CAMS];
  const uint8_t m_occMedianPos = 2u;
  const uint8_t m_smootheningOutput = 1u;

#ifdef DLD_GRID_ALGO
  const float32_t m_occConfidenceThreshold = 0.25f;
  const float32_t m_llConfidenceThreshold = 0.20f;
  const float32_t m_blConfidenceThreshold = 0.12f;
#else
  const float32_t m_occConfidenceThreshold = 0.5f;
  const float32_t m_llConfidenceThreshold = 0.5f;
  const float32_t m_blConfidenceThreshold = 0.5f;
#endif

  vx_status tidlAppInit();
  DLDCamStatus_t processResults(DLD_Camera_ID camId, DNN_DLD_out dnnOutput);
  void softmax(float32_t* scores, const uint32_t number_of_scores);

#if ENABLE_DLD_DEBUG_DUMP
  FILE* ut_fp_dump;
#endif

public:
  DLDAlgo();
  ~DLDAlgo();

  bool_t init();
  //void deinit();
  //bool isInitialised() { return m_isInitialised; }
  DLDCamStatus_s ProcessDNN(DLD_Camera_ID camId, uint8_t* inputImgColor_pu8);
  void getInputPadSizes(uint32_t &inPadL, uint32_t &inPadT, uint32_t &inPadR, uint32_t &inPadB);
};

} // namespace dld

#endif // DLD_ALGO_H