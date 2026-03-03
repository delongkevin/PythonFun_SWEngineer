// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TURNAROUND_STATE_H
#define __TURNAROUND_STATE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
    #include "../common/CircularBuffer.h"
    #include "TRSC_Inputs_Outputs.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include "common/CircularBuffer.h"
    #include "common/TRSC_Inputs_Outputs.h"
#endif
#include "TrailerTracking.h"
#include "FeatureExtraction.h"
#include "CollisionAngleDetection.h"
#include "ImageThresholding.h"
#include "PreProcessing.h"
#include "VehicleKinematics.h"
#include "AngleSampling.h"
#include "TemplateBuildUp.h"
#include "TrailerAngleCalibration.h"

namespace TurnAround
{
    /** Turnaround state. Part of the TAD state machine. **/
    class TurnaroundState : public TAD2::State
    {
    public:
        TurnaroundState( const tad2config::CalibrationConfigData& i_Calib_config, const tad2config::TrailerAngleDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction, cAngleDetection::CollisionAngleDetection* i_pCollisionAngleDetection );
        virtual ~TurnaroundState();

        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;

        // --- Getters
        TurnAroundState_t GetSubState()const;

    private:
        const tad2config::CalibrationConfigData& m_Calibconfig;
        TurnAroundState_t m_subState;
        float32_t m_timePassedInState_s;
        float32_t m_distTravelledInState_m;
        bool_t m_turnaroundcompleted;

        bool_t turn_completed;
        int32_t last_geardir;
        bool_t Drive_Fail;
        bool_t CameraBlocked;
        float32_t minwheelangle;
        float32_t maxwheelangle;
        float32_t TrailerAngle;
        float32_t maxTrailerAngle;
        bool_t m_TemplateGenerated;
        float32_t m_max_wheelAngle;
        uint32_t TBL_WaitCount;

        const tad2config::TrailerAngleDetectionConfigData& m_config;
        bool_t m_initialized;

        TAD2::WarpedTopViewParameters m_warpedTopViewParams;
        TAD2::TrailerTemplate m_trailerTemplate;
        TAD2::WarpedImage<uint8_t> m_calibratedWarpedTrailerImage;
        TAD2::WarpedImage<uint8_t> warpedEdges;

        static const uint32_t c_bufSize = 30;
        buffer::CircularBuffer<float32_t, c_bufSize> m_trailerAngleBuf;
        static const uint32_t c_bufSize1 = 15;
        buffer::CircularBuffer<float32_t, c_bufSize1> m_trailerConfidenceBuf;
        static const uint32_t c_bufSize2 = 120;
        buffer::CircularBuffer<float32_t, c_bufSize2> m_wheelangle;


        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;
        cAngleDetection::CollisionAngleDetection* m_pCollisionAngleDetection;

        // --- Kinematics Model
        TAD2::TrailerCalibrationModel m_avgTrailerModel;

        // --- Calibration modules
        TAD2::TrailerAngleCalibration m_trailerAngleCalibrationObj;
        TemplateBuild::TemplateBuildUp m_templateBuildUpObj;

        // --- Sub-modules
        TAD2::TrailerTracking m_trailerTrackingObj;

        // --- Sub functions
        void StateDriveStraight( TAD2::Event& e, TAD2::Output& o );
        void StateTurnLeftOrRight( TAD2::Event& e, TAD2::Output& o );
        void StateWait( TAD2::Event& e, TAD2::Output& o );

        static float32_t FindAverageIllumination( image::Image<uint8_t>& i_warpedview, _roi::ROI& i_roi );
        void AngleTracking( TAD2::Event& e, TAD2::Output& o );
        float32_t _GetTrailerAngle1();
        float32_t _GetTrailerAngle();
        float32_t GetDistTravelledInCalibration()const;
        float32_t GetTimeInCalibration()const;

        static const uint32_t window_size = 20;
        float32_t angle_interpolation_weights[window_size];
    };
}

#endif // !__ANGLE_DETECTION_STATE_H
