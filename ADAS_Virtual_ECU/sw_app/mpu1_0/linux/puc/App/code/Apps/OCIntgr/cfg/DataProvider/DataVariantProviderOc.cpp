//--------------------------------------------------------------------------
/// @file DataInputProviderOc.h
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

#include "variants/VariantHelper.h"
#include "DataVariantProviderOc.h"
#include "variants/Components.h"
#include "variants/Assets.h"

#ifdef __SIMULATE_DOWNSAMPLE
#undef __SIMULATE_DOWNSAMPLE 
#endif

namespace oc
{
	
#ifndef _U32
#define _U32(a) (static_cast<uint32_t>(a))
#endif

#ifndef __ARRAYSIZE
#define __ARRAYSIZE(a) (_U32(sizeof(a))/_U32(sizeof(a[0])))
#endif

#ifndef __MINRANGE
#define __MINRANGE(a,b) __min(__ARRAYSIZE(a), __ARRAYSIZE(b))
#endif



//----------------------------------------------------------------------------------------------------------
// Author: Detlef Hafer
  static uint32_t variantOc_GetOCKinematicsDataGUID_u32 ()
  {
  /* DD-ID: {F7E0CF91-9E85-4a2e-B303-BE8B2F042A54}*/
    bool_t v_Success_b = true;
    uint32_t v_OCKinematicsDataGUID_u32 = variants :: c_InvalidGUID_u32;

    if ( true == v_Success_b )
    {
      const variants :: VariantConfig* v_Config_po = NULL;

      // get variant config Asset
      v_Config_po = variants :: VariantConfig :: get_po( variants :: c_VariantConfig_u32 );
      v_Success_b = ( NULL != v_Config_po );

      if ( true == v_Success_b )
      {
        // get the linked GUID for this variant and camera
        v_OCKinematicsDataGUID_u32 = v_Config_po->getCompVariantConfig_po()->getOcCalibrationAllLink_u32();
      }
    }
    return v_OCKinematicsDataGUID_u32;
  }




//----------------------------------------------------------------------------------------------------------
// Author: Detlef Hafer
  bool_t variantOc_GetOCKinematics_b ( VarOCKinematics_t* o_Kinematics_pt )
  {
  /* DD-ID: {418FEC35-1D80-43c1-8A60-77DDD4610E9C}*/
    const variants :: KinematicsOC* v_KinematicsOC_po = NULL;
    bool_t v_Success_b = true;
    uint32_t v_KinematicsGUID_u32 = variantOc_GetOCKinematicsDataGUID_u32();

    // get Vehicle Data Asset
    v_KinematicsOC_po = variants :: KinematicsOC :: get_po( v_KinematicsGUID_u32 );
    v_Success_b = ( NULL != v_KinematicsOC_po );
    if ( true == v_Success_b )
    {
      const variants :: CompKinematics* v_CompKinematics_po = NULL;

      // get Vehicle Data Component
      v_CompKinematics_po = v_KinematicsOC_po->getCompKinematics_po();
      v_Success_b = ( NULL != v_CompKinematics_po );
      if ( true == v_Success_b )
      {
        if ( NULL != o_Kinematics_pt )
        {
          o_Kinematics_pt->distanceCoG2FrontAxis_f32 = v_CompKinematics_po->getProperties_rs().distanceCoG2FrontAxis_f32;
          o_Kinematics_pt->distanceCoG2RearAxis_f32 = v_CompKinematics_po->getProperties_rs().distanceCoG2RearAxis_f32;
          o_Kinematics_pt->tireCircumferencePerPulse_f32 = v_CompKinematics_po->getProperties_rs().tireCircumferencePerPulse_f32;
          o_Kinematics_pt->straightMotionDistanceThresh_f32 = v_CompKinematics_po->getProperties_rs().straightMotionDistanceThresh_f32;
        }
      }
    }
    return v_Success_b;
  }




  static void getBMALFC_v ( const variants :: CompCameraCfg :: OcBMALFC_s& i_Src_rt, VarOCBMALFC_t& o_Dest_rt )
  {
  /* DD-ID: {6433447F-963C-4b71-9D0B-2C25E3BCDFBC}*/
    o_Dest_rt.m_FrameSkip_u32 = i_Src_rt.frameSkip_u32;
    o_Dest_rt.m_NumPatchesPerROI_u32 = i_Src_rt.numPatchesPerROI_u32;
    o_Dest_rt.m_NumROIs_u32 = i_Src_rt.numROIs_u32;
    o_Dest_rt.m_PatchSize_u32 = i_Src_rt.patchSize_u32;
    o_Dest_rt.m_UseRandomPatches_u32 = i_Src_rt.useRandomPatches_u32;
    o_Dest_rt.m_SearchRadius_u32 = i_Src_rt.searchRadius_u32;
    o_Dest_rt.m_TrackLength_u32 = i_Src_rt.trackLength_u32;
    o_Dest_rt.m_UseMad_u32 = i_Src_rt.useMAD_u32;
    o_Dest_rt.m_Thresh1_u32 = i_Src_rt.thresh1_s32;
    o_Dest_rt.m_Thresh2_u32 = i_Src_rt.thresh2_s32;

    {
      const uint32_t c_NumFrameskips_u32 = __MINRANGE( i_Src_rt.aFrameSkips_as, o_Dest_rt.m_FrameSkips_au32 );
      for ( uint32_t v_I_u32 = 0 ; v_I_u32 < c_NumFrameskips_u32 ; v_I_u32++ )
      {
        o_Dest_rt.m_FrameSkips_au32[ v_I_u32 ] = i_Src_rt.aFrameSkips_as[ v_I_u32 ].eFrameSkips_u32;
      }
    }
    {
      const uint32_t c_NumSpeedRanges_u32 = __MINRANGE( i_Src_rt.aSpeedRanges_as, o_Dest_rt.m_SpeedRanges_af32 );
      for ( uint32_t v_I_u32 = 0 ; v_I_u32 < c_NumSpeedRanges_u32 ; v_I_u32++ )
      {
        o_Dest_rt.m_SpeedRanges_af32[ v_I_u32 ] = i_Src_rt.aSpeedRanges_as[ v_I_u32 ].eSpeedRange_f32;
      }
    }
    const variants :: CompCameraCfg :: RoiSets_s& c_SrcSets_rs = i_Src_rt.roiSets_s;
    VarOCroiSets_t& v_DestSets_t_rt = o_Dest_rt.m_OCroiSets_t;

    v_DestSets_t_rt.useCycleRois_u32 = c_SrcSets_rs.useCyclePerRoi_u32;
    const uint32_t c_NumPools_u32 = __min( __MINRANGE( c_SrcSets_rs.roiPools_as, v_DestSets_t_rt.m_VarOCroiPool_at ), c_SrcSets_rs.numRoiPools_u32 );
    Assert( c_NumPools_u32 == 2U );
    for ( uint32_t v_I_u32 = 0 ; v_I_u32 < c_NumPools_u32 ; v_I_u32++ )
    {
      const variants :: CompCameraCfg :: RoiPools_s& c_ScrRoiPool_rs = c_SrcSets_rs.roiPools_as[ v_I_u32 ];
      VarOCroiPool_t& v_DestRoiPool_t_rt = v_DestSets_t_rt.m_VarOCroiPool_at[ v_I_u32 ];
      const uint32_t c_NumRects_u32 = __min( __MINRANGE( c_ScrRoiPool_rs.roiPoolRects_as, v_DestRoiPool_t_rt.m_VarOCRect_at ), c_ScrRoiPool_rs.numRoiPoolRects_u32 );
      Assert( c_NumRects_u32 == 1U );
      for ( uint32_t v_K_u32 = 0 ; v_K_u32 < c_NumRects_u32 ; v_K_u32++ )
      {
        const variants :: CompCameraCfg :: RoiPoolRects_s& c_SrcRoiPoolItemRect_rs = c_ScrRoiPool_rs.roiPoolRects_as[ v_K_u32 ];
        VarOCRect_t& v_DestRoiPoolRect_t_rt = v_DestRoiPool_t_rt.m_VarOCRect_at[ v_K_u32 ];
        v_DestRoiPoolRect_t_rt.left = c_SrcRoiPoolItemRect_rs.left_s32;
        v_DestRoiPoolRect_t_rt.top = c_SrcRoiPoolItemRect_rs.top_s32;
        v_DestRoiPoolRect_t_rt.width = c_SrcRoiPoolItemRect_rs.width_s32;
        v_DestRoiPoolRect_t_rt.height = c_SrcRoiPoolItemRect_rs.height_s32;
      }
      v_DestRoiPool_t_rt.numRoi_u32 = c_NumRects_u32;
    }
    v_DestSets_t_rt.numRoiPools_u32 = c_NumPools_u32;
  }




  static void getAlgo ( const variants :: CompCameraCfg :: OcAlgoCfg_s& i_Src_rt, VarOCAlgoCfg_t& o_Dest_rt )
  {
  /* DD-ID: {61B59DFA-22B9-4b50-B1D3-70D66663A09D}*/
    o_Dest_rt.m_fundMatOutlierThresh_f32 = i_Src_rt.fundMatOutlierThresh_f32;
    o_Dest_rt.m_limitXMM_f32 = i_Src_rt.limitXMM_f32;
    o_Dest_rt.m_limitYMM_f32 = i_Src_rt.limitYMM_f32;
    o_Dest_rt.m_limitZMM_f32 = i_Src_rt.limitZMM_f32;
    o_Dest_rt.m_MaxNumValidFrames_u32 = i_Src_rt.maxNumValidFrames_u32;
    o_Dest_rt.m_MinNumRawFrames_u32 = i_Src_rt.minNumRawFrames_u32;
    o_Dest_rt.m_DownSampleFactor_u32 = i_Src_rt.downSampleFactor_u32;
  }




  static void getTrajectory ( const variants :: CompCameraCfg :: OcTrajectory_s& i_Src_rt, VarOCTrajectory_t& o_Dest_rt )
  {
  /* DD-ID: {12C04BE5-CCD9-431e-A4DB-F64B80B4C636}*/
    o_Dest_rt.m_AngleThresh_f32 = i_Src_rt.angleThresh_f32;
    o_Dest_rt.m_CombinationsDiffThreshold_f32 = i_Src_rt.combinationsDiffThreshold_f32;
    o_Dest_rt.m_DeviationPercentage_f32 = i_Src_rt.deviationPercentage_f32;
    o_Dest_rt.m_MaxHeightDiff_f32 = i_Src_rt.maxHeightDiff_f32;
    o_Dest_rt.m_MinimumPixelMotion_u32 = i_Src_rt.minimumPixelMotion_u32;
    o_Dest_rt.m_SlopeDifferenceThresh_f32 = i_Src_rt.slopeDifferenceThresh_f32;
    o_Dest_rt.m_UseCombinations_u32 = i_Src_rt.useCombinations_u8;
    o_Dest_rt.m_UseSfMFilter_u32 = i_Src_rt.useSfMFilter_u8;
  }




//----------------------------------------------------------------------------------------------------------
// Author: Detlef Hafer
  bool_t variantOc_GetCameraOCcalibration_b ( const variants :: Camera_t i_Camera_t, OCCameraCfg_t* o_OCCameraCfg_pt )
  {
  /* DD-ID: {D3AF6AE0-D3B6-43c0-B01E-2BCD4433CE4B}*/
    bool_t v_Success_b = false;
    uint32_t v_CamGUID_u32 = ME_VariantHelper_GetOCGUID_u32( i_Camera_t );
    if ( v_CamGUID_u32 != variants :: c_InvalidGUID_u32 )
    {
      // check if it's a radial lens camera
      const variants :: CameraOCcalibration* v_CameraOCcalibration_po = variants :: CameraOCcalibration :: get_po( v_CamGUID_u32 );
      v_Success_b = ( NULL != v_CameraOCcalibration_po );
      if ( true == v_Success_b )
      {
        const variants :: CompCameraCfg* v_CameraCfg_po = v_CameraOCcalibration_po->getCompCameraCfg_po();
        v_Success_b = ( NULL != v_CameraCfg_po );
        if ( true == v_Success_b )
        {
          o_OCCameraCfg_pt->m_RoiID_u32 = _U32( v_CameraCfg_po->getRoiID_s32());
          const variants :: CompCameraCfg :: RoiRect_s& c_RoiRect_rs = v_CameraCfg_po->getRoiRect_rs();
          o_OCCameraCfg_pt->m_RoiRect_t.left = c_RoiRect_rs.left_s32;
          o_OCCameraCfg_pt->m_RoiRect_t.top = c_RoiRect_rs.top_s32;
          o_OCCameraCfg_pt->m_RoiRect_t.width = c_RoiRect_rs.width_s32;
          o_OCCameraCfg_pt->m_RoiRect_t.height = c_RoiRect_rs.height_s32;

          getBMALFC_v( v_CameraCfg_po->getOcBMALFC_rs(), o_OCCameraCfg_pt->m_ocBMALFC_t );
          getAlgo ( v_CameraCfg_po->getOcAlgoCfg_rs(), o_OCCameraCfg_pt->m_ocAlgoCfg_t );
          getTrajectory ( v_CameraCfg_po->getOcTrajectory_rs(), o_OCCameraCfg_pt->m_ocTrajectory_t );
        }
      }
    }
    return v_Success_b;
  }

#if 0
  static void ShrinkRect_v( SetupOcCfgTypes ::OcRect_t& v_DestRect_rt )
  {
  /* DD-ID: {AC4C854D-BC2C-4c9b-BECB-B73735D84B77}*/
      v_DestRect_rt.Height /=2U;
      v_DestRect_rt.Width /=2U;
      v_DestRect_rt.X /=2U;
      v_DestRect_rt.Y /=2U;
  }
#endif

#if 0
  static void getBMALFC_v ( const VarOCBMALFC_t& i_Src_rt, SetupOcCfgTypes :: BMALFC_t& o_Dest_rt, const uint32_t i_DownSampleFactor_u32 )
  {
  /* DD-ID: {FD77C9AD-AE5D-44a8-A54B-097462927FF1}*/
    {
      SetupOcCfgTypes :: FrameSkips_t& v_DestFrameSkips_rt = o_Dest_rt.m_FrameSkips_t;
      const uint32_t c_NumFrameskips_u32 = __MINRANGE( i_Src_rt.m_FrameSkips_au32, v_DestFrameSkips_rt.m_FrameSkips_au32 );
      for ( uint32_t v_I_u32 = 0 ; v_I_u32 < c_NumFrameskips_u32 ; v_I_u32++ )
      {
        v_DestFrameSkips_rt.m_FrameSkips_au32[ v_I_u32 ] = i_Src_rt.m_FrameSkips_au32[ v_I_u32 ];
      }
      v_DestFrameSkips_rt.m_Count_u32 = c_NumFrameskips_u32;
    }


    {
      SetupOcCfgTypes :: SpeedRanges_t& v_DestSpeedRanges_rt = o_Dest_rt.m_SpeedRanges_t;
      const uint32_t c_NumSpeedRange_u32 = __MINRANGE( i_Src_rt.m_SpeedRanges_af32, v_DestSpeedRanges_rt.m_SpeedRanges_af32 );
      for ( uint32_t v_I_u32 = 0 ; v_I_u32 < c_NumSpeedRange_u32 ; v_I_u32++ )
      {
        v_DestSpeedRanges_rt.m_SpeedRanges_af32[ v_I_u32 ] = i_Src_rt.m_SpeedRanges_af32[ v_I_u32 ];
      }
      v_DestSpeedRanges_rt.m_Count_u32 = c_NumSpeedRange_u32;
    }

    o_Dest_rt.m_FrameSkip_u32 = i_Src_rt.m_FrameSkip_u32;
    o_Dest_rt.m_NumPatchesPerROI_u32 = i_Src_rt.m_NumPatchesPerROI_u32;
    o_Dest_rt.m_NumROIs_u32 = i_Src_rt.m_NumROIs_u32;
    o_Dest_rt.m_PatchSize_u32 = i_Src_rt.m_PatchSize_u32;
    o_Dest_rt.m_SearchRadius_u32 = i_Src_rt.m_SearchRadius_u32;
    o_Dest_rt.m_Thresh1_u32 = i_Src_rt.m_Thresh1_u32;
    o_Dest_rt.m_Thresh2_u32 = i_Src_rt.m_Thresh2_u32;
    o_Dest_rt.m_TrackLength_u32 = i_Src_rt.m_TrackLength_u32;
    o_Dest_rt.m_UseMad_u32 = i_Src_rt.m_UseMad_u32;
    o_Dest_rt.m_UseRandomPatches_u32 = i_Src_rt.m_UseRandomPatches_u32;

    {
      SetupOcCfgTypes :: ROISets_t& v_DestRoiSet_rt = o_Dest_rt.m_ROISets_t;
      const VarOCroiSets_t& c_SrcRoiSet_rt = i_Src_rt.m_OCroiSets_t;

      v_DestRoiSet_rt.m_UseCycleRois_u32 = c_SrcRoiSet_rt.useCycleRois_u32;

      const uint32_t c_NumRoiPool_u32 = __min( __MINRANGE( c_SrcRoiSet_rt.m_VarOCroiPool_at, v_DestRoiSet_rt.m_ROIPools_at ), c_SrcRoiSet_rt.numRoiPools_u32 );
      Assert( c_NumRoiPool_u32 == 2U );
      for ( uint32_t v_I_u32 = 0 ; v_I_u32 < c_NumRoiPool_u32 ; v_I_u32++ )
      {
        const VarOCroiPool_t& c_SrcRoiPool_rt = c_SrcRoiSet_rt.m_VarOCroiPool_at[ v_I_u32 ];
        SetupOcCfgTypes :: ROIPool_t& v_DestROIPool_t = v_DestRoiSet_rt.m_ROIPools_at[ v_I_u32 ];;
        const uint32_t c_NumRoiRects_u32 = __min( __MINRANGE( c_SrcRoiPool_rt.m_VarOCRect_at, v_DestROIPool_t.m_ROI_at ), c_SrcRoiPool_rt.numRoi_u32 );
        Assert( c_NumRoiRects_u32 == 1U );
        for ( uint32_t v_J_u32 = 0 ; v_J_u32 < c_NumRoiRects_u32 ; v_J_u32++ )
        {
          const VarOCRect_t& c_SrcRect_rt = c_SrcRoiPool_rt.m_VarOCRect_at[ v_J_u32 ];
          SetupOcCfgTypes :: OcRect_t& v_DestRect_t = v_DestROIPool_t.m_ROI_at[ v_J_u32 ];
          v_DestRect_t.Height = c_SrcRect_rt.height;
          v_DestRect_t.Width = c_SrcRect_rt.width;
          v_DestRect_t.X = c_SrcRect_rt.left;
          v_DestRect_t.Y = c_SrcRect_rt.top;
          if (  i_DownSampleFactor_u32  == 2U )
          {
            ShrinkRect_v(v_DestRect_t);
          }
        }
        v_DestROIPool_t.m_Count_u32 = c_NumRoiRects_u32;
      }
      v_DestRoiSet_rt.m_Count_u32 = c_NumRoiPool_u32;
    }
  }
#endif


#if 0
  static void getTrajectory_v ( const VarOCTrajectory_t& i_Src_rt, SetupOcCfgTypes :: Trajectory_t& o_Dest_rt )
  {
  /* DD-ID: {8D572859-5E9E-4644-91C5-244B495D7B10}*/
    o_Dest_rt.m_AngleThresh_f32 = i_Src_rt.m_AngleThresh_f32;
    o_Dest_rt.m_CombinationsDiffThreshold_f32 = i_Src_rt.m_CombinationsDiffThreshold_f32;
    o_Dest_rt.m_DeviationPercentage_f32 = i_Src_rt.m_DeviationPercentage_f32;
    o_Dest_rt.m_MaxHeightDiff_f32 = i_Src_rt.m_MaxHeightDiff_f32;
    o_Dest_rt.m_MinimumPixelMotion_u32 = i_Src_rt.m_MinimumPixelMotion_u32;
    o_Dest_rt.m_SlopeDifferenceThresh_f32 = i_Src_rt.m_SlopeDifferenceThresh_f32;
    o_Dest_rt.m_UseCombinations_u32 = i_Src_rt.m_UseCombinations_u32;
    o_Dest_rt.m_UseSfMFilter_u32 = i_Src_rt.m_UseSfMFilter_u32;
  }
#endif

#if 0
  static void getAlgo_v ( const VarOCAlgoCfg_t&  i_Src_rt, SetupOcCfgTypes :: AlgoCfg_t& o_Dest_rt )
  {
  /* DD-ID: {07CCBE12-758C-46d6-811F-7DB796A96247}*/
    o_Dest_rt.m_MaxNumValidFrames_u32 = i_Src_rt.m_MaxNumValidFrames_u32;
    o_Dest_rt.m_MinNumRawFrames_u32 = i_Src_rt.m_MinNumRawFrames_u32;
    o_Dest_rt.m_SofMCfg_t.fundMatOutlierThresh_f32 = i_Src_rt.m_fundMatOutlierThresh_f32;
    o_Dest_rt.m_SofMCfg_t.limitXMM_f32 = i_Src_rt.m_limitXMM_f32;
    o_Dest_rt.m_SofMCfg_t.limitYMM_f32 = i_Src_rt.m_limitYMM_f32;
    o_Dest_rt.m_SofMCfg_t.limitZMM_f32 = i_Src_rt.m_limitZMM_f32;
    o_Dest_rt.m_DownSampleFactor_u32 = i_Src_rt.m_DownSampleFactor_u32;
  }
#endif


  
#if 0
  bool_t VariantData_Init_b ( SetupOcCfgTypes :: SetupOcCfgStructuredData_t& o_SetupOcCfgStructuredData_rt )
  {
    // Kinematics
    o_SetupOcCfgStructuredData_rt = o_SetupOcCfgStructuredData_rt; // TODO: can this be removed?

    VarOCKinematics_t v_OCKinematics_t;
    bool_t v_Erg_b = variantOc_GetOCKinematics_b( &v_OCKinematics_t );
    if ( v_Erg_b == true )
    {
      SetupOcCfgTypes :: KinematicsCfg_t& v_KinematicsCfg_rt = o_SetupOcCfgStructuredData_rt.m_KinematicsCfg_t;
      v_KinematicsCfg_rt.m_distanceCoG2FrontAxisMM_f32 = v_OCKinematics_t.distanceCoG2FrontAxis_f32;
      v_KinematicsCfg_rt.m_distanceCoG2RearAxisMM_f32 = v_OCKinematics_t.distanceCoG2RearAxis_f32;
      v_KinematicsCfg_rt.m_tireCircumferencePerPulseMM_f32 = v_OCKinematics_t.tireCircumferencePerPulse_f32;
      v_KinematicsCfg_rt.m_straightMotionDistanceThresh_f32 = v_OCKinematics_t.straightMotionDistanceThresh_f32;
    }
    // CameraCfg
    for ( uint16_t v_Ix_u16 = 0 ; v_Ix_u16 < _U16( variants :: e_CameraCount ) ; v_Ix_u16++ )
    {
      OCCameraCfg_t v_OCCameraCfg_t;
      memset( &v_OCCameraCfg_t, 0, sizeof( v_OCCameraCfg_t ));
      variants :: Camera_t v_Camera_t = _ECAM( v_Ix_u16 );
      bool_t v_Erg_b = variantOc_GetCameraOCcalibration_b( v_Camera_t, &v_OCCameraCfg_t );
      if ( v_Erg_b == true )
      {
        // ROIsets
  #ifdef __SIMULATE_DOWNSAMPLE 
        v_OCCameraCfg_t.m_ocAlgoCfg_t.m_DownSampleFactor_u32 = 2U;
  #endif

        SetupOcCfgTypes :: SetupOcCfg_t& v_SetupOcCfg_rt = o_SetupOcCfgStructuredData_rt.m_SetupOcCfg_at[ v_Ix_u16 ];
        getBMALFC_v( v_OCCameraCfg_t.m_ocBMALFC_t, v_SetupOcCfg_rt.m_BMALFC_t, v_OCCameraCfg_t.m_ocAlgoCfg_t.m_DownSampleFactor_u32 );
        getTrajectory_v( v_OCCameraCfg_t.m_ocTrajectory_t, v_SetupOcCfg_rt.m_Trajectory_t );
        getAlgo_v( v_OCCameraCfg_t.m_ocAlgoCfg_t, v_SetupOcCfg_rt.m_AlgoCfg_t );

        v_SetupOcCfg_rt.m_ID_u32 = v_OCCameraCfg_t.m_RoiID_u32;
        v_SetupOcCfg_rt.m_Rect_t.X = v_OCCameraCfg_t.m_RoiRect_t.left;
        v_SetupOcCfg_rt.m_Rect_t.Y = v_OCCameraCfg_t.m_RoiRect_t.top;
        v_SetupOcCfg_rt.m_Rect_t.Width = v_OCCameraCfg_t.m_RoiRect_t.width;
        v_SetupOcCfg_rt.m_Rect_t.Height = v_OCCameraCfg_t.m_RoiRect_t.height;
        if ( v_OCCameraCfg_t.m_ocAlgoCfg_t.m_DownSampleFactor_u32 == 2U )
        {
          ShrinkRect_v( v_SetupOcCfg_rt.m_Rect_t );
        }
      }
    }
    return true;
  }
#endif



};
