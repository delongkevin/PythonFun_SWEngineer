

#ifndef COMPONENTS
#define COMPONENTS

#include "Enums.h"
#include <platform/PlatformAPI.h>
#include <osal/io/InOut.h>

namespace variants
{

class PinholeComponent
{
      friend class CameraRadialLens;
      friend class VirtualCameraStretchLens;
      friend class VirtualCameraNoLens;
      friend class VirtualCameraRadialLens;
      friend class VirtualCameraCylinderLens;
      public:
            struct Intrinsic_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(focalLengthX_f32);
                        b_IO_ro.serialize_v(focalLengthY_f32);
                        b_IO_ro.serialize_v(principalPointX_f32);
                        b_IO_ro.serialize_v(principalPointY_f32);
                        b_IO_ro.serialize_v(pixelSizeX_f32);
                        b_IO_ro.serialize_v(pixelSizeY_f32);
                        b_IO_ro.serializeEnum_v(imageOrigin_e);
                        b_IO_ro.serialize_v(sensorAreaTopLeftX_f32);
                        b_IO_ro.serialize_v(sensorAreaTopLeftY_f32);
                        b_IO_ro.serialize_v(sensorAreaBottomRightX_f32);
                        b_IO_ro.serialize_v(sensorAreaBottomRightY_f32);
                  }
                  float32_t focalLengthX_f32;
                  float32_t focalLengthY_f32;
                  float32_t principalPointX_f32;
                  float32_t principalPointY_f32;
                  float32_t pixelSizeX_f32;
                  float32_t pixelSizeY_f32;
                  ImageOriginPosition_e imageOrigin_e;
                  float32_t sensorAreaTopLeftX_f32;
                  float32_t sensorAreaTopLeftY_f32;
                  float32_t sensorAreaBottomRightX_f32;
                  float32_t sensorAreaBottomRightY_f32;
            };
            struct Extrinsic_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(posX_f32);
                        b_IO_ro.serialize_v(posY_f32);
                        b_IO_ro.serialize_v(posZ_f32);
                        b_IO_ro.serialize_v(pitch_f32);
                        b_IO_ro.serialize_v(yaw_f32);
                        b_IO_ro.serialize_v(roll_f32);
                        b_IO_ro.serializeEnum_v(preRoll_e);
                        b_IO_ro.serializeEnum_v(rotationType_e);
                  }
                  float32_t posX_f32;
                  float32_t posY_f32;
                  float32_t posZ_f32;
                  float32_t pitch_f32;
                  float32_t yaw_f32;
                  float32_t roll_f32;
                  PreRoll_e preRoll_e;
                  RotationType_e rotationType_e;
            };
            const Extrinsic_s& getExtrinsic_rs( ) const { return extrinsic_s; }
            const Intrinsic_s& getIntrinsic_rs( ) const { return intrinsic_s; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  extrinsic_s.serialize_v(b_IO_ro);
                  intrinsic_s.serialize_v(b_IO_ro);
            }
            Extrinsic_s extrinsic_s;
            Intrinsic_s intrinsic_s;
};

class LensRadialComponent
{
      friend class CameraRadialLens;
      friend class VirtualCameraStretchLens;
      friend class VirtualCameraRadialLens;
      public:
            struct Image2World_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(coeff_f32);
                  }
                  float32_t coeff_f32;
            };
            struct World2Image_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(coeff_f32);
                  }
                  float32_t coeff_f32;
            };
            const float32_t getElevationMax_f32( ) const { return elevationMax_f32; }
            const World2Image_s* getWorld2Image_ps( ) const { return &world2Image_as[0]; }
            const Image2World_s* getImage2World_ps( ) const { return &image2World_as[0]; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(elevationMax_f32);
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_CoefficientsCount; ++v_I_u32)
                  {
                    world2Image_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_CoefficientsCount; ++v_I_u32)
                  {
                    image2World_as[v_I_u32].serialize_v(b_IO_ro);
                  }
            }
            float32_t elevationMax_f32;
            World2Image_s world2Image_as[e_CoefficientsCount];
            Image2World_s image2World_as[e_CoefficientsCount];
};

class CompVehicleData
{
      friend class VehicleData;
      public:
            const float32_t getWheelBase_f32( ) const { return wheelBase_f32; }
            const float32_t getFrontBumperPosX_f32( ) const { return frontBumperPosX_f32; }
            const float32_t getRearBumperPosX_f32( ) const { return rearBumperPosX_f32; }
            const float32_t getRightMirrorPosY_f32( ) const { return rightMirrorPosY_f32; }
            const float32_t getLeftMirrorPosY_f32( ) const { return leftMirrorPosY_f32; }
            const float32_t getVehicleWidthAtFender_f32( ) const { return vehicleWidthAtFender_f32; }
            const float32_t getFrontBumperProjectionOffset_f32( ) const { return frontBumperProjectionOffset_f32; }
            const float32_t getRearBumperProjectionOffset_f32( ) const { return rearBumperProjectionOffset_f32; }
            const float32_t getBedEndPosX_f32( ) const { return bedEndPosX_f32; }
            const float32_t getBedEndPosZ_f32( ) const { return bedEndPosZ_f32; }
            const float32_t getTrackWidth_f32( ) const { return trackWidth_f32; }
            const float32_t getTireWidth_f32( ) const { return tireWidth_f32; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(wheelBase_f32);
                  b_IO_ro.serialize_v(frontBumperPosX_f32);
                  b_IO_ro.serialize_v(rearBumperPosX_f32);
                  b_IO_ro.serialize_v(rightMirrorPosY_f32);
                  b_IO_ro.serialize_v(leftMirrorPosY_f32);
                  b_IO_ro.serialize_v(vehicleWidthAtFender_f32);
                  b_IO_ro.serialize_v(frontBumperProjectionOffset_f32);
                  b_IO_ro.serialize_v(rearBumperProjectionOffset_f32);
                  b_IO_ro.serialize_v(bedEndPosX_f32);
                  b_IO_ro.serialize_v(bedEndPosZ_f32);
                  b_IO_ro.serialize_v(trackWidth_f32);
                  b_IO_ro.serialize_v(tireWidth_f32);
            }
            float32_t wheelBase_f32;
            float32_t frontBumperPosX_f32;
            float32_t rearBumperPosX_f32;
            float32_t rightMirrorPosY_f32;
            float32_t leftMirrorPosY_f32;
            float32_t vehicleWidthAtFender_f32;
            float32_t frontBumperProjectionOffset_f32;
            float32_t rearBumperProjectionOffset_f32;
            float32_t bedEndPosX_f32;
            float32_t bedEndPosZ_f32;
            float32_t trackWidth_f32;
            float32_t tireWidth_f32;
};

class CompMirrorObscuration
{
      friend class MirrorObscuration;
      public:
            const float32_t getMirrorLeftOutPosX_f32( ) const { return mirrorLeftOutPosX_f32; }
            const float32_t getMirrorLeftOutPosY_f32( ) const { return mirrorLeftOutPosY_f32; }
            const float32_t getMirrorLeftOutPosZ_f32( ) const { return mirrorLeftOutPosZ_f32; }
            const float32_t getMirrorLeftMidPosX_f32( ) const { return mirrorLeftMidPosX_f32; }
            const float32_t getMirrorLeftMidPosY_f32( ) const { return mirrorLeftMidPosY_f32; }
            const float32_t getMirrorLeftMidPosZ_f32( ) const { return mirrorLeftMidPosZ_f32; }
            const float32_t getMirrorRightOutPosX_f32( ) const { return mirrorRightOutPosX_f32; }
            const float32_t getMirrorRightOutPosY_f32( ) const { return mirrorRightOutPosY_f32; }
            const float32_t getMirrorRightOutPosZ_f32( ) const { return mirrorRightOutPosZ_f32; }
            const float32_t getMirrorRightMidPosX_f32( ) const { return mirrorRightMidPosX_f32; }
            const float32_t getMirrorRightMidPosY_f32( ) const { return mirrorRightMidPosY_f32; }
            const float32_t getMirrorRightMidPosZ_f32( ) const { return mirrorRightMidPosZ_f32; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(mirrorLeftOutPosX_f32);
                  b_IO_ro.serialize_v(mirrorLeftOutPosY_f32);
                  b_IO_ro.serialize_v(mirrorLeftOutPosZ_f32);
                  b_IO_ro.serialize_v(mirrorLeftMidPosX_f32);
                  b_IO_ro.serialize_v(mirrorLeftMidPosY_f32);
                  b_IO_ro.serialize_v(mirrorLeftMidPosZ_f32);
                  b_IO_ro.serialize_v(mirrorRightOutPosX_f32);
                  b_IO_ro.serialize_v(mirrorRightOutPosY_f32);
                  b_IO_ro.serialize_v(mirrorRightOutPosZ_f32);
                  b_IO_ro.serialize_v(mirrorRightMidPosX_f32);
                  b_IO_ro.serialize_v(mirrorRightMidPosY_f32);
                  b_IO_ro.serialize_v(mirrorRightMidPosZ_f32);
            }
            float32_t mirrorLeftOutPosX_f32;
            float32_t mirrorLeftOutPosY_f32;
            float32_t mirrorLeftOutPosZ_f32;
            float32_t mirrorLeftMidPosX_f32;
            float32_t mirrorLeftMidPosY_f32;
            float32_t mirrorLeftMidPosZ_f32;
            float32_t mirrorRightOutPosX_f32;
            float32_t mirrorRightOutPosY_f32;
            float32_t mirrorRightOutPosZ_f32;
            float32_t mirrorRightMidPosX_f32;
            float32_t mirrorRightMidPosY_f32;
            float32_t mirrorRightMidPosZ_f32;
};

class OvlConfigComponent
{
      public:
            const char_t* getModeFileName_pc( ) const { return &modeFileName_ac[0]; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  uint32_t v_Size_u32 = 0U;
                  b_IO_ro.serializeArray_v(&modeFileName_ac[0], v_Size_u32);
            }
            char_t modeFileName_ac[256];
};

class CompVariantConfig
{
      friend class VariantConfig;
      public:
            struct Cams_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(camLink_u32);
                        b_IO_ro.serialize_v(eolcalibrationLink_u32);
                        b_IO_ro.serialize_v(ocCalibrationLink_u32);
                        b_IO_ro.serialize_v(scCalibrationLink_u32);
                  }
                  uint32_t camLink_u32;
                  uint32_t eolcalibrationLink_u32;
                  uint32_t ocCalibrationLink_u32;
                  uint32_t scCalibrationLink_u32;
            };
            const Cams_s* getCams_ps( ) const { return &cams_as[0]; }
            const uint32_t getVehicleDataLink_u32( ) const { return vehicleDataLink_u32; }
            const uint32_t getOcCalibrationAllLink_u32( ) const { return ocCalibrationAllLink_u32; }
            const VariantIds_e getCurrentVariantId_e( ) const { return currentVariantId_e; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_CameraCount; ++v_I_u32)
                  {
                    cams_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  b_IO_ro.serialize_v(vehicleDataLink_u32);
                  b_IO_ro.serialize_v(ocCalibrationAllLink_u32);
                  b_IO_ro.serializeEnum_v(currentVariantId_e);
            }
            Cams_s cams_as[e_CameraCount];
            uint32_t vehicleDataLink_u32;
            uint32_t ocCalibrationAllLink_u32;
            VariantIds_e currentVariantId_e;
};

class JobConfigComponent
{
      friend class JobConfig;
      public:
            struct Jobs_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(executionOrder_s32);
                  }
                  sint32_t executionOrder_s32;
            };
            struct SchedulingSchemes_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        for (uint32_t v_I_u32 = 0U; v_I_u32 < e_JobCount; ++v_I_u32)
                        {
                          jobs_as[v_I_u32].serialize_v(b_IO_ro);
                        }
                  }
                  Jobs_s jobs_as[e_JobCount];
            };
            const SchedulingSchemes_s* getSchedulingSchemes_ps( ) const { return &schedulingSchemes_as[0]; }
            const AppState_e getInitalizationScheme_e( ) const { return initalizationScheme_e; }
            const uint64_t getTargetSchedulingRate_u64( ) const { return targetSchedulingRate_u64; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_AppStateCount; ++v_I_u32)
                  {
                    schedulingSchemes_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  b_IO_ro.serializeEnum_v(initalizationScheme_e);
                  b_IO_ro.serialize_v(targetSchedulingRate_u64);
            }
            SchedulingSchemes_s schedulingSchemes_as[e_AppStateCount];
            AppState_e initalizationScheme_e;
            uint64_t targetSchedulingRate_u64;
};

class CompKinematics
{
      friend class KinematicsOC;
      public:
            struct Properties_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(tireCircumferencePerPulse_f32);
                        b_IO_ro.serialize_v(distanceCoG2FrontAxis_f32);
                        b_IO_ro.serialize_v(distanceCoG2RearAxis_f32);
                        b_IO_ro.serialize_v(straightMotionDistanceThresh_f32);
                  }
                  float32_t tireCircumferencePerPulse_f32;
                  float32_t distanceCoG2FrontAxis_f32;
                  float32_t distanceCoG2RearAxis_f32;
                  float32_t straightMotionDistanceThresh_f32;
            };
            const Properties_s& getProperties_rs( ) const { return properties_s; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  properties_s.serialize_v(b_IO_ro);
            }
            Properties_s properties_s;
};

class CompCameraCfg
{
      friend class CameraOCcalibration;
      public:
            struct RoiRect_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(left_s32);
                        b_IO_ro.serialize_v(top_s32);
                        b_IO_ro.serialize_v(width_s32);
                        b_IO_ro.serialize_v(height_s32);
                  }
                  sint32_t left_s32;
                  sint32_t top_s32;
                  sint32_t width_s32;
                  sint32_t height_s32;
            };
            struct OcAlgoCfg_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(minNumRawFrames_u32);
                        b_IO_ro.serialize_v(maxNumValidFrames_u32);
                        b_IO_ro.serialize_v(limitXMM_f32);
                        b_IO_ro.serialize_v(limitYMM_f32);
                        b_IO_ro.serialize_v(limitZMM_f32);
                        b_IO_ro.serialize_v(fundMatOutlierThresh_f32);
                        b_IO_ro.serialize_v(downSampleFactor_u32);
                  }
                  uint32_t minNumRawFrames_u32;
                  uint32_t maxNumValidFrames_u32;
                  float32_t limitXMM_f32;
                  float32_t limitYMM_f32;
                  float32_t limitZMM_f32;
                  float32_t fundMatOutlierThresh_f32;
                  uint32_t downSampleFactor_u32;
            };
            struct OcTrajectory_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(minimumPixelMotion_u32);
                        b_IO_ro.serialize_v(slopeDifferenceThresh_f32);
                        b_IO_ro.serialize_v(angleThresh_f32);
                        b_IO_ro.serialize_v(deviationPercentage_f32);
                        b_IO_ro.serialize_v(useCombinations_u8);
                        b_IO_ro.serialize_v(combinationsDiffThreshold_f32);
                        b_IO_ro.serialize_v(useSfMFilter_u8);
                        b_IO_ro.serialize_v(maxHeightDiff_f32);
                  }
                  uint32_t minimumPixelMotion_u32;
                  float32_t slopeDifferenceThresh_f32;
                  float32_t angleThresh_f32;
                  float32_t deviationPercentage_f32;
                  uint8_t useCombinations_u8;
                  float32_t combinationsDiffThreshold_f32;
                  uint8_t useSfMFilter_u8;
                  float32_t maxHeightDiff_f32;
            };
            struct RoiPoolRects_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(left_s32);
                        b_IO_ro.serialize_v(top_s32);
                        b_IO_ro.serialize_v(width_s32);
                        b_IO_ro.serialize_v(height_s32);
                  }
                  sint32_t left_s32;
                  sint32_t top_s32;
                  sint32_t width_s32;
                  sint32_t height_s32;
            };
            struct RoiPools_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        for (uint32_t v_I_u32 = 0U; v_I_u32 < e_ROIPoolRectECount; ++v_I_u32)
                        {
                          roiPoolRects_as[v_I_u32].serialize_v(b_IO_ro);
                        }
                        b_IO_ro.serialize_v(numRoiPoolRects_u32);
                  }
                  RoiPoolRects_s roiPoolRects_as[e_ROIPoolRectECount];
                  uint32_t numRoiPoolRects_u32;
            };
            struct RoiSets_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(numRoiPools_u32);
                        b_IO_ro.serialize_v(useCyclePerRoi_u32);
                        for (uint32_t v_I_u32 = 0U; v_I_u32 < e_ROIPoolECount; ++v_I_u32)
                        {
                          roiPools_as[v_I_u32].serialize_v(b_IO_ro);
                        }
                  }
                  uint32_t numRoiPools_u32;
                  uint32_t useCyclePerRoi_u32;
                  RoiPools_s roiPools_as[e_ROIPoolECount];
            };
            struct AFrameSkips_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(eFrameSkips_u32);
                  }
                  uint32_t eFrameSkips_u32;
            };
            struct ASpeedRanges_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(eSpeedRange_f32);
                  }
                  float32_t eSpeedRange_f32;
            };
            struct OcBMALFC_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SpeedrangesECount; ++v_I_u32)
                        {
                          aSpeedRanges_as[v_I_u32].serialize_v(b_IO_ro);
                        }
                        for (uint32_t v_I_u32 = 0U; v_I_u32 < e_FrameSkipsECount; ++v_I_u32)
                        {
                          aFrameSkips_as[v_I_u32].serialize_v(b_IO_ro);
                        }
                        b_IO_ro.serialize_v(useMAD_u32);
                        b_IO_ro.serialize_v(numROIs_u32);
                        b_IO_ro.serialize_v(numPatchesPerROI_u32);
                        b_IO_ro.serialize_v(patchSize_u32);
                        b_IO_ro.serialize_v(useRandomPatches_u32);
                        b_IO_ro.serialize_v(frameSkip_u32);
                        b_IO_ro.serialize_v(trackLength_u32);
                        b_IO_ro.serialize_v(searchRadius_u32);
                        roiSets_s.serialize_v(b_IO_ro);
                        b_IO_ro.serialize_v(thresh1_s32);
                        b_IO_ro.serialize_v(thresh2_s32);
                  }
                  ASpeedRanges_s aSpeedRanges_as[e_SpeedrangesECount];
                  AFrameSkips_s aFrameSkips_as[e_FrameSkipsECount];
                  uint32_t useMAD_u32;
                  uint32_t numROIs_u32;
                  uint32_t numPatchesPerROI_u32;
                  uint32_t patchSize_u32;
                  uint32_t useRandomPatches_u32;
                  uint32_t frameSkip_u32;
                  uint32_t trackLength_u32;
                  uint32_t searchRadius_u32;
                  RoiSets_s roiSets_s;
                  sint32_t thresh1_s32;
                  sint32_t thresh2_s32;
            };
            const OcBMALFC_s& getOcBMALFC_rs( ) const { return ocBMALFC_s; }
            const OcTrajectory_s& getOcTrajectory_rs( ) const { return ocTrajectory_s; }
            const OcAlgoCfg_s& getOcAlgoCfg_rs( ) const { return ocAlgoCfg_s; }
            const sint32_t getRoiID_s32( ) const { return roiID_s32; }
            const RoiRect_s& getRoiRect_rs( ) const { return roiRect_s; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  ocBMALFC_s.serialize_v(b_IO_ro);
                  ocTrajectory_s.serialize_v(b_IO_ro);
                  ocAlgoCfg_s.serialize_v(b_IO_ro);
                  b_IO_ro.serialize_v(roiID_s32);
                  roiRect_s.serialize_v(b_IO_ro);
            }
            OcBMALFC_s ocBMALFC_s;
            OcTrajectory_s ocTrajectory_s;
            OcAlgoCfg_s ocAlgoCfg_s;
            sint32_t roiID_s32;
            RoiRect_s roiRect_s;
};

class CompEOL
{
      friend class CameraEOLcalibration;
      friend class CameraSCcalibration;
      public:
            struct Targets_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(width_u32);
                        b_IO_ro.serialize_v(height_u32);
                        b_IO_ro.serialize_v(numberOfSquares_u32);
                        b_IO_ro.serialize_v(xCenter_f32);
                        b_IO_ro.serialize_v(yCenter_f32);
                        b_IO_ro.serialize_v(zCenter_f32);
                        b_IO_ro.serializeEnum_v(orientation_e);
                  }
                  uint32_t width_u32;
                  uint32_t height_u32;
                  uint32_t numberOfSquares_u32;
                  float32_t xCenter_f32;
                  float32_t yCenter_f32;
                  float32_t zCenter_f32;
                  Orientation_e orientation_e;
            };
            struct Calibration_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(dummy_f32);
                  }
                  float32_t dummy_f32;
            };
            struct Cornerdetection_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(targetRatio_f32);
                        b_IO_ro.serialize_v(startPattern_u32);
                        b_IO_ro.serialize_v(nx_u16);
                        b_IO_ro.serialize_v(ny_u16);
                        b_IO_ro.serialize_v(roiWidth_u16);
                        b_IO_ro.serialize_v(roiHeight_u16);
                        b_IO_ro.serialize_v(upperWeightLimit_u16);
                        b_IO_ro.serialize_v(lowerWeightLimit_u16);
                        b_IO_ro.serialize_v(blobThreshold_u16);
                  }
                  float32_t targetRatio_f32;
                  uint32_t startPattern_u32;
                  uint16_t nx_u16;
                  uint16_t ny_u16;
                  uint16_t roiWidth_u16;
                  uint16_t roiHeight_u16;
                  uint16_t upperWeightLimit_u16;
                  uint16_t lowerWeightLimit_u16;
                  uint16_t blobThreshold_u16;
            };
            const Cornerdetection_s& getCornerdetection_rs( ) const { return cornerdetection_s; }
            const Calibration_s& getCalibration_rs( ) const { return calibration_s; }
            const Targets_s* getTargets_ps( ) const { return &targets_as[0]; }
            const uint32_t getNumTargets_u32( ) const { return numTargets_u32; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  cornerdetection_s.serialize_v(b_IO_ro);
                  calibration_s.serialize_v(b_IO_ro);
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_TargetArrayCount; ++v_I_u32)
                  {
                    targets_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  b_IO_ro.serialize_v(numTargets_u32);
            }
            Cornerdetection_s cornerdetection_s;
            Calibration_s calibration_s;
            Targets_s targets_as[e_TargetArrayCount];
            uint32_t numTargets_u32;
};

class ErrorManagerConfigComponent
{
      friend class ErrorManagerConfig;
      public:
            struct Jobs_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(aliveTime_u64);
                  }
                  uint64_t aliveTime_u64;
            };
            const Jobs_s* getJobs_ps( ) const { return &jobs_as[0]; }
            const uint64_t getCheckAliveTimePeriod_u64( ) const { return checkAliveTimePeriod_u64; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_JobCount; ++v_I_u32)
                  {
                    jobs_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  b_IO_ro.serialize_v(checkAliveTimePeriod_u64);
            }
            Jobs_s jobs_as[e_JobCount];
            uint64_t checkAliveTimePeriod_u64;
};

class ScreenConfigComponent
{
      friend class ScreenConfig;
      public:
            struct ScreenConfig_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(screenWidth_u32);
                        b_IO_ro.serialize_v(screenHeight_u32);
                        b_IO_ro.serialize_v(fps_u32);
                        uint32_t v_StringSize_u32 = 0U;
                        b_IO_ro.serializeArray_v(&configFile_ac[0], v_StringSize_u32);
                  }
                  uint32_t screenWidth_u32;
                  uint32_t screenHeight_u32;
                  uint32_t fps_u32;
                  char_t configFile_ac[256];
            };
            const ScreenConfig_s& getScreenConfig_rs( ) const { return screenConfig_s; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  screenConfig_s.serialize_v(b_IO_ro);
            }
            ScreenConfig_s screenConfig_s;
};

class CombinedViewComponent
{
      friend class CombinedView;
      public:
            struct StitchParams_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(stitchParamsLink_u32);
                  }
                  uint32_t stitchParamsLink_u32;
            };
            struct VideoLayerAreas_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(videoLayerAreasLink_u32);
                  }
                  uint32_t videoLayerAreasLink_u32;
            };
            struct SingleViews_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(singleViewsLink_u32);
                  }
                  uint32_t singleViewsLink_u32;
            };
            const SingleViews_s* getSingleViews_ps( ) const { return &singleViews_as[0]; }
            const VideoLayerAreas_s* getVideoLayerAreas_ps( ) const { return &videoLayerAreas_as[0]; }
            const StitchParams_s* getStitchParams_ps( ) const { return &stitchParams_as[0]; }
            const uint32_t getSingleViewsCount_u32( ) const { return singleViewsCount_u32; }
            const uint32_t getVideoLayerAreasCount_u32( ) const { return videoLayerAreasCount_u32; }
            const uint32_t getStitchParamsCount_u32( ) const { return stitchParamsCount_u32; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SingleViewLinksCount; ++v_I_u32)
                  {
                    singleViews_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_VideoLayerCount; ++v_I_u32)
                  {
                    videoLayerAreas_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_StitchParamsLinksCount; ++v_I_u32)
                  {
                    stitchParams_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  b_IO_ro.serialize_v(singleViewsCount_u32);
                  b_IO_ro.serialize_v(videoLayerAreasCount_u32);
                  b_IO_ro.serialize_v(stitchParamsCount_u32);
            }
            SingleViews_s singleViews_as[e_SingleViewLinksCount];
            VideoLayerAreas_s videoLayerAreas_as[e_VideoLayerCount];
            StitchParams_s stitchParams_as[e_StitchParamsLinksCount];
            uint32_t singleViewsCount_u32;
            uint32_t videoLayerAreasCount_u32;
            uint32_t stitchParamsCount_u32;
};

class SingleViewComponent
{
      friend class SingleView;
      public:
            struct ZoomReferencePoint_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(pixelPosX_f32);
                        b_IO_ro.serialize_v(pixelPosY_f32);
                  }
                  float32_t pixelPosX_f32;
                  float32_t pixelPosY_f32;
            };
            const uint32_t getRealCameraLink_u32( ) const { return realCameraLink_u32; }
            const uint32_t getVirtualCameraLink_u32( ) const { return virtualCameraLink_u32; }
            const VideoLayer_e getVideoLayer_e( ) const { return videoLayer_e; }
            const Zoomable_e getZoomable_e( ) const { return zoomable_e; }
            const ZoomReferencePoint_s& getZoomReferencePoint_rs( ) const { return zoomReferencePoint_s; }
            const uint32_t getPixelAreaLink_u32( ) const { return pixelAreaLink_u32; }
            const SingleViews_e getEnumId_e( ) const { return enumId_e; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(realCameraLink_u32);
                  b_IO_ro.serialize_v(virtualCameraLink_u32);
                  b_IO_ro.serializeEnum_v(videoLayer_e);
                  b_IO_ro.serializeEnum_v(zoomable_e);
                  zoomReferencePoint_s.serialize_v(b_IO_ro);
                  b_IO_ro.serialize_v(pixelAreaLink_u32);
                  b_IO_ro.serializeEnum_v(enumId_e);
            }
            uint32_t realCameraLink_u32;
            uint32_t virtualCameraLink_u32;
            VideoLayer_e videoLayer_e;
            Zoomable_e zoomable_e;
            ZoomReferencePoint_s zoomReferencePoint_s;
            uint32_t pixelAreaLink_u32;
            SingleViews_e enumId_e;
};

class StitchParamsComponent
{
      friend class StitchParams;
      public:
            struct StitchLine1_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(point0PosX_f32);
                        b_IO_ro.serialize_v(point0PosY_f32);
                        b_IO_ro.serialize_v(point1PosX_f32);
                        b_IO_ro.serialize_v(point1PosY_f32);
                  }
                  float32_t point0PosX_f32;
                  float32_t point0PosY_f32;
                  float32_t point1PosX_f32;
                  float32_t point1PosY_f32;
            };
            struct StitchLine0_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(point0PosX_f32);
                        b_IO_ro.serialize_v(point0PosY_f32);
                        b_IO_ro.serialize_v(point1PosX_f32);
                        b_IO_ro.serialize_v(point1PosY_f32);
                  }
                  float32_t point0PosX_f32;
                  float32_t point0PosY_f32;
                  float32_t point1PosX_f32;
                  float32_t point1PosY_f32;
            };
            const uint32_t getAlpha_u32( ) const { return alpha_u32; }
            const StitchLine0_s& getStitchLine0_rs( ) const { return stitchLine0_s; }
            const StitchLine1_s& getStitchLine1_rs( ) const { return stitchLine1_s; }
            const uint32_t getSingleView0_u32( ) const { return singleView0_u32; }
            const uint32_t getSingleView1_u32( ) const { return singleView1_u32; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(alpha_u32);
                  stitchLine0_s.serialize_v(b_IO_ro);
                  stitchLine1_s.serialize_v(b_IO_ro);
                  b_IO_ro.serialize_v(singleView0_u32);
                  b_IO_ro.serialize_v(singleView1_u32);
            }
            uint32_t alpha_u32;
            StitchLine0_s stitchLine0_s;
            StitchLine1_s stitchLine1_s;
            uint32_t singleView0_u32;
            uint32_t singleView1_u32;
};

class PixelAreaComponent
{
      friend class PixelArea;
      public:
            struct BottomRight_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(pixelPosX_s32);
                        b_IO_ro.serialize_v(pixelPosY_s32);
                  }
                  sint32_t pixelPosX_s32;
                  sint32_t pixelPosY_s32;
            };
            struct TopLeft_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(pixelPosX_s32);
                        b_IO_ro.serialize_v(pixelPosY_s32);
                  }
                  sint32_t pixelPosX_s32;
                  sint32_t pixelPosY_s32;
            };
            const TopLeft_s& getTopLeft_rs( ) const { return topLeft_s; }
            const BottomRight_s& getBottomRight_rs( ) const { return bottomRight_s; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  topLeft_s.serialize_v(b_IO_ro);
                  bottomRight_s.serialize_v(b_IO_ro);
            }
            TopLeft_s topLeft_s;
            BottomRight_s bottomRight_s;
};

class ViewsMapComponent
{
      friend class ViewsMap;
      public:
            struct ViewsMap_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(combinedViewLink_u32);
                  }
                  uint32_t combinedViewLink_u32;
            };
            const ViewsMap_s* getViewsMap_ps( ) const { return &viewsMap_as[0]; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_ViewIdCount; ++v_I_u32)
                  {
                    viewsMap_as[v_I_u32].serialize_v(b_IO_ro);
                  }
            }
            ViewsMap_s viewsMap_as[e_ViewIdCount];
};

class SingleViewsMapComponent
{
      friend class SingleViewsMap;
      public:
            struct SingleViewsMap_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(singleViewLink_u32);
                  }
                  uint32_t singleViewLink_u32;
            };
            const SingleViewsMap_s* getSingleViewsMap_ps( ) const { return &singleViewsMap_as[0]; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SingleViewsCount; ++v_I_u32)
                  {
                    singleViewsMap_as[v_I_u32].serialize_v(b_IO_ro);
                  }
            }
            SingleViewsMap_s singleViewsMap_as[e_SingleViewsCount];
};

class LensStretchVerticalComponent
{
      friend class VirtualCameraStretchLens;
      public:
            struct StretchBase_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(coeff_f32);
                  }
                  float32_t coeff_f32;
            };
            struct StretchFactor_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(coeff_f32);
                  }
                  float32_t coeff_f32;
            };
            const StretchFactor_s* getStretchFactor_ps( ) const { return &stretchFactor_as[0]; }
            const StretchBase_s* getStretchBase_ps( ) const { return &stretchBase_as[0]; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_LensStretchCoefficientsCount; ++v_I_u32)
                  {
                    stretchFactor_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_LensStretchCoefficientsCount; ++v_I_u32)
                  {
                    stretchBase_as[v_I_u32].serialize_v(b_IO_ro);
                  }
            }
            StretchFactor_s stretchFactor_as[e_LensStretchCoefficientsCount];
            StretchBase_s stretchBase_as[e_LensStretchCoefficientsCount];
};

class LensCylinderComponent
{
      friend class VirtualCameraCylinderLens;
      public:
            const float32_t getExcentricity_f32( ) const { return excentricity_f32; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(excentricity_f32);
            }
            float32_t excentricity_f32;
};

class CarModelConfigComponent
{
      friend class CarModelConfig;
      public:
            struct CarColors_s
            {
                  void serialize_v( osal::InOut& b_IO_ro )
                  {
                        b_IO_ro.serialize_v(red_f32);
                        b_IO_ro.serialize_v(green_f32);
                        b_IO_ro.serialize_v(blue_f32);
                  }
                  float32_t red_f32;
                  float32_t green_f32;
                  float32_t blue_f32;
            };
            const CarColors_s* getCarColors_ps( ) const { return &carColors_as[0]; }
            const char_t* getCarModelFile_pc( ) const { return &carModelFile_ac[0]; }
            const DriverSide_e getDriverSideConfig_e( ) const { return driverSideConfig_e; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_CarColorSelectionCount; ++v_I_u32)
                  {
                    carColors_as[v_I_u32].serialize_v(b_IO_ro);
                  }
                  uint32_t v_Size_u32 = 0U;
                  b_IO_ro.serializeArray_v(&carModelFile_ac[0], v_Size_u32);
                  b_IO_ro.serializeEnum_v(driverSideConfig_e);
            }
            CarColors_s carColors_as[e_CarColorSelectionCount];
            char_t carModelFile_ac[256];
            DriverSide_e driverSideConfig_e;
};

class KinematicModelComponent
{
      friend class KinematicModelConfig;
      public:
            const float32_t getUnderfloorDistanceToShow_f32( ) const { return underfloorDistanceToShow_f32; }
            const float32_t getTimeElapsed_f32( ) const { return timeElapsed_f32; }
            const float32_t getMinSpeed_f32( ) const { return minSpeed_f32; }
            const float32_t getMaxSpeed_f32( ) const { return maxSpeed_f32; }
            const uint8_t getIsSpeedInMph_u8( ) const { return isSpeedInMph_u8; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  b_IO_ro.serialize_v(underfloorDistanceToShow_f32);
                  b_IO_ro.serialize_v(timeElapsed_f32);
                  b_IO_ro.serialize_v(minSpeed_f32);
                  b_IO_ro.serialize_v(maxSpeed_f32);
                  b_IO_ro.serialize_v(isSpeedInMph_u8);
            }
            float32_t underfloorDistanceToShow_f32;
            float32_t timeElapsed_f32;
            float32_t minSpeed_f32;
            float32_t maxSpeed_f32;
            uint8_t isSpeedInMph_u8;
};
} // namespace variants
#endif // COMPONENTS

