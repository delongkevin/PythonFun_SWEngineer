/// @file   THA_Detection_Inputs_Outputs.h
/// @brief  THA Detection IPC Interface Data Structure definition
///
///  THA Detection IPC Interface Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Dipti Natu (dipti.natu@magna.com)
/// --------------------------------------------------------------------------

#ifndef THA_Detection_INPUTS_OUTPUTS_H_INCGUARD
#define THA_Detection_INPUTS_OUTPUTS_H_INCGUARD

#include "HMI_SVS.h"
#include "THAFeatureOutputs.h"
#include "VehicleInputAdapterDataTypes.h"
#include "JobKM.h"
#include "JobTHAOutput.h"

/* ------------------- Inputs to THA_Detection ------------------- */

/* HMI SVS to THA_Detection, mcu2_0 to A72*/
/* SvsToTHADet_t */

/* THA SM VC to THA Detection, mcu2_1 to A72*/
/* TbTHASmVc_FeatureOutputs_t */

/* Vehicle CAN to THA_Detection, mcu1_0 to A72*/
/* ME_VehInp_to_IpcSignals_t */

/* KinematicData to THA_Detection, mcu1_0 to A72*/
/* IKinematicData_t */

/* Tunable parameter, mcu1_0 to A72*/
/* THADet_Inputs_from_CalData_t */

/* ------------------- Output from THA_SM_VC ------------------- */
/* THA Detection to THA_SM_VC, A72 to mcu2_1*/
/* JobTHADetOutput_t */

typedef struct THADet_Inputs_from_CalData_s
{
    float32_t THAVehSpeedThresh_f32;
    float32_t DefaultTrailerAngleDeg_f32;
    float32_t CouplerConfThresh_f32;
    float32_t CouplerToHitchThresh_f32;
    float32_t TrailerAngleThreshDeg_f32;
    float32_t KcfMinPeakValueThresh_f32;
    int32_t DefaultHitchXmm_s32;
    int32_t DefaultHitchYmm_s32;
    int32_t DefaultHitchZmm_s32;
    int32_t DefaultHitchXpix_s32;
    int32_t DefaultHitchYpix_s32;
    int32_t CouplerHeight_s32;
    uint16_t ROIWidth_u16;
    uint16_t ROIHeight_u16;
    uint8_t UtilizeTrailerTracker_b;
    uint8_t IsCouplerToHitchThreshInPix_b;
    uint8_t EnableKFSmooth_b;
    uint8_t EnableODONNXCrop_b;
    uint32_t DefaultBallDiameter_u32;
    uint32_t Dummy2_b;
    uint32_t Dummy3_b;
    uint32_t Dummy4_b[187];
} THADet_Inputs_from_CalData_t;



#endif // THA_Detections_INPUTS_OUTPUTS_H_INCGUARD
