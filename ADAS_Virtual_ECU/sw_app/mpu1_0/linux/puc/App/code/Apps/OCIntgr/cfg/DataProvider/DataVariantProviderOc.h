//--------------------------------------------------------------------------
/// @file DataVariantProviderOc.h
/// @brief Contains

/// DataProvider is an interface between the application module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes from
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Detlef Hafer (detlef.hafer.extern@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup OcIntgr
/// @{

#ifndef DATAVARIANTPROVIDEROC_X_
#define DATAVARIANTPROVIDEROC_X_

#include "SetupOcCfgTypes.h"

namespace oc
{
typedef struct VarOCKinematics_s
{
  float32_t straightMotionDistanceThresh_f32;
  float32_t tireCircumferencePerPulse_f32;
  float32_t distanceCoG2FrontAxis_f32;
  float32_t distanceCoG2RearAxis_f32;
}
VarOCKinematics_t;

typedef struct VarOCRect_s
{
  sint32_t left;
  sint32_t top;
  sint32_t width;
  sint32_t height;
} VarOCRect_t;



typedef struct VarOCroiPool_s
{
  uint32_t numRoi_u32;
  VarOCRect_t m_VarOCRect_at[ variants :: e_ROIPoolRectECount ];
} VarOCroiPool_t;


typedef struct VarOCroiSets_s
{
  uint32_t useCycleRois_u32;
  uint32_t numRoiPools_u32;
  VarOCroiPool_t m_VarOCroiPool_at[ variants :: e_ROIPoolECount ];
} VarOCroiSets_t;


typedef struct VarOCTrajectory_s
{
  uint32_t m_MinimumPixelMotion_u32;
  float32_t m_SlopeDifferenceThresh_f32;
  float32_t m_AngleThresh_f32;
  float32_t m_DeviationPercentage_f32;
  uint32_t m_UseCombinations_u32;
  float32_t m_CombinationsDiffThreshold_f32;
  uint32_t m_UseSfMFilter_u32;
  float32_t m_MaxHeightDiff_f32;
} VarOCTrajectory_t;


typedef struct VarOCAlgoCfg_s
{
  uint32_t m_MinNumRawFrames_u32;
  uint32_t m_MaxNumValidFrames_u32;
  float32_t m_limitXMM_f32;
  float32_t m_limitYMM_f32;
  float32_t m_limitZMM_f32;
  float32_t m_fundMatOutlierThresh_f32;
  uint32_t m_DownSampleFactor_u32;
} VarOCAlgoCfg_t;




typedef struct VarOCBMALFC_s
{
  uint32_t m_NumROIs_u32;           // hard coded ( 2 )
  uint32_t m_NumPatchesPerROI_u32;  // hard coded ( NUM_PATCHES_PER_ROI = 1 )    // PRQA S 1051 2
  uint32_t m_PatchSize_u32;         // hard coded ( PATCH_SIZE = 16 )    // PRQA S 1051 2
  uint32_t m_UseRandomPatches_u32;     // hard coded ( USE_RANDOM_PATCHES_VAL = 1 )    // PRQA S 1051 2
  uint32_t m_FrameSkip_u32;         // hard coded ( DETECTOR_FRAME_SKIP_VAL = 0 )    // PRQA S 1051 2
  uint32_t m_TrackLength_u32;       // hard coded ( 3 )
  uint32_t m_SearchRadius_u32;      // hard coded ( 7 )
  uint32_t m_UseMad_u32;            // hard coded (USE_MAD_VAL = 0 )    // PRQA S 1051 2
  uint32_t m_Thresh1_u32;
  uint32_t m_Thresh2_u32;

  float32_t m_SpeedRanges_af32[ variants :: e_SpeedrangesECount ];
  uint32_t m_FrameSkips_au32[ variants :: e_FrameSkipsECount ];
  VarOCroiSets_t m_OCroiSets_t;

} VarOCBMALFC_t;


typedef struct OCCameraCfg_s
{
  uint32_t m_RoiID_u32;
  VarOCRect_t m_RoiRect_t;
  VarOCBMALFC_t m_ocBMALFC_t;
  VarOCTrajectory_t m_ocTrajectory_t;
  VarOCAlgoCfg_t m_ocAlgoCfg_t;
} OCCameraCfg_t;



  bool_t VariantData_Init_b ( SetupOcCfgTypes :: SetupOcCfgStructuredData_t& o_SetupOcCfgStructuredData_rt );
  bool_t variantOc_GetCameraOCcalibration_b ( const variants :: Camera_t i_Camera_t, OCCameraCfg_t* o_OCCameraCfg_pt );
  bool_t variantOc_GetOCKinematics_b ( VarOCKinematics_t* o_Kinematics_pt );
};

#endif // DATAVARIANTPROVIDEROC_X_
/// @}
