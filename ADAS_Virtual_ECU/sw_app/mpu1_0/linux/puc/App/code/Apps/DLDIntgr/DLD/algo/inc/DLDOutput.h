/// --------------------------------------------------------------------------
/// @file DLDOutput.h
/// @brief Contains DLD detection output structure definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
/// --------------------------------------------------------------------------

#ifndef DLD_OUTPUT_H
#define DLD_OUTPUT_H

#include "../common/DLDDef.h"
#include "DLD_Input_Output.h"

typedef struct DLDCamStatus_s {
  float32_t UnoccludedBinPerc; /* Unoccluded Percentage */
  float32_t OccludedBinPerc;   /* Occluded Percentage */
  float32_t LowlightPerc;      /* Low Light Percentage */
  float32_t HighlightPerc;     /* High Light Percentage */
  bool_t    OcclusionStatus;   /* Occlusion Status */
  bool_t    LowlightStatus;    /* Low Light Status */
  DLDCamSts_t DLD_CamSts_e;    /* Camera Status */
} DLDCamStatus_t;

typedef struct DLDOutput_s {
  DLDCamStatus_t DldCameraStatus[DLD_Camera_ID::DLD_NUM_CAMS];
} DLDOutput_t;

#endif // DLD_OUTPUT_H

