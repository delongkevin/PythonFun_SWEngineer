//--------------------------------------------------------------------------
/// @file SetupOcCfgTypes.h
/// @brief Oc setup data
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Detlef Hafer (Detlef.Hafer.Extern@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef __SETUPOCCFGTYPES_H_
#define __SETUPOCCFGTYPES_H_


#include "mecl/core/MeclTypes.h"

#define MAX_SPEEDRANGES 10
#define MAX_FRAMESKIPS 10
#define MAX_ROIPOOLS 4
#define MAX_ROI_PER_POOLS 4

namespace SetupOcCfgTypes
{

  typedef struct OcRect_s
  {
    sint32_t X;
    sint32_t Y;
    sint32_t Width;
    sint32_t Height;
  } OcRect_t;


  typedef struct ROIPool_s
  {
    uint32_t m_Count_u32;
    OcRect_t m_ROI_at[ MAX_ROI_PER_POOLS ];
  } ROIPool_t;


  typedef struct ROISets_s
  {
    uint32_t m_UseCycleRois_u32;     // hard coded ( CYCLE_THROUGH_ROIS_VAL = 0)
    uint32_t m_Count_u32;
    ROIPool_t m_ROIPools_at[ MAX_ROIPOOLS ];
  } ROISets_t;

  typedef struct SpeedRanges_s
  {
    uint32_t m_Count_u32;
    float32_t m_SpeedRanges_af32[ MAX_SPEEDRANGES ];
  } SpeedRanges_t;

  typedef struct FrameSkips_s
  {
    uint32_t m_Count_u32;
    uint32_t m_FrameSkips_au32[ MAX_FRAMESKIPS ];
  } FrameSkips_t;


  typedef struct Trajectory_s
  {
    uint32_t m_MinimumPixelMotion_u32;
    float32_t m_SlopeDifferenceThresh_f32;
    float32_t m_AngleThresh_f32;
    float32_t m_DeviationPercentage_f32;
    uint32_t m_UseCombinations_u32;
    float32_t m_CombinationsDiffThreshold_f32;
    uint32_t m_UseSfMFilter_u32;
    float32_t m_MaxHeightDiff_f32;
  } Trajectory_t;


  typedef struct BMALFC_s
  {
    uint32_t m_NumROIs_u32;           // hard coded ( 2 )
    uint32_t m_NumPatchesPerROI_u32;  // hard coded ( NUM_PATCHES_PER_ROI = 1 )
    uint32_t m_PatchSize_u32;         // hard coded ( PATCH_SIZE = 16 )
    uint32_t m_UseRandomPatches_u32;     // hard coded ( USE_RANDOM_PATCHES_VAL = 1 )
    uint32_t m_FrameSkip_u32;         // hard coded ( DETECTOR_FRAME_SKIP_VAL = 0 )
    uint32_t m_TrackLength_u32;       // hard coded ( 3 )
    uint32_t m_SearchRadius_u32;      // hard coded ( 7 )
    uint32_t m_UseMad_u32;            // use Mad
    uint32_t m_Thresh1_u32;
    uint32_t m_Thresh2_u32;

    SpeedRanges_t m_SpeedRanges_t;
    FrameSkips_t m_FrameSkips_t;
    ROISets_t m_ROISets_t;
  } BMALFC_t;


  typedef struct SofMCfg_s
  {
    float32_t limitXMM_f32;
    float32_t limitYMM_f32;
    float32_t limitZMM_f32;
    float32_t fundMatOutlierThresh_f32;
  } SofMCfg_t;


  typedef struct AlgoCfg_s
  {
    uint32_t m_MinNumRawFrames_u32;  // 100 U
    uint32_t m_MaxNumValidFrames_u32;  // 900 U
    uint32_t m_DownSampleFactor_u32;
    SofMCfg_t m_SofMCfg_t;
  } AlgoCfg_t;


  typedef struct KinematicsCfg_s
  {
    float32_t m_straightMotionDistanceThresh_f32;
    float32_t m_tireCircumferencePerPulseMM_f32;
    float32_t m_distanceCoG2FrontAxisMM_f32;
    float32_t m_distanceCoG2RearAxisMM_f32;
  } KinematicsCfg_t;


  typedef struct SetupOcCfg_s
  {
    uint32_t m_ID_u32;                   // hard coded ID = 0
    OcRect_t m_Rect_t;                 // hard coded search area,
    BMALFC_t m_BMALFC_t;
    Trajectory_t m_Trajectory_t;
    AlgoCfg_t m_AlgoCfg_t;
  } SetupOcCfg_t;


  struct SetupOcCfgStructuredData_s
  {
    static const uint32_t c_SetupOcCfgVersion_u32 = 1U;

    uint32_t m_SetupOcCfgVersion_u32;
    KinematicsCfg_t m_KinematicsCfg_t;
    SetupOcCfg_t m_SetupOcCfg_at[ 4U ];
  };
  typedef struct SetupOcCfgStructuredData_s SetupOcCfgStructuredData_t;

}; // SetupOcCfgTypes

#endif // __SETUPOCCFGTYPES_H_


