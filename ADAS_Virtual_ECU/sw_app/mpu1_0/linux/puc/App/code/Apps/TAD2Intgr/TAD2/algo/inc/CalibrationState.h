// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __CALIBRATION_STATE_H
#define __CALIBRATION_STATE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
    #include "../common/CircularBuffer.h"
    #include "../common/Image.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include "common/CircularBuffer.h"
    #include "common/Image.h"
#endif

#include "TRSC_Inputs_Outputs.h"
#include "TrailerTracking.h"

#include "CollisionAngleDetection.h"
#include "TemplateBuildUp.h"
#include "HitchDetection.h"
#include "AngleSampling.h"
#include "Scanning.h"
#include "FeatureExtraction.h"
#include "ImageThresholding.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "CollisionAngleDetection.h"


namespace vehspeed
{
    static const float32_t c_minVehSpeedDuringTemplateBuildUp = 0.3f; // mps
}
namespace Calibration
{
    /** Calibration state. Part of the TAD state machine. **/
    class CalibrationState : public TAD2::State
    {
    public:
        CalibrationState( const tad2config::CalibrationConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* i_pVehicleKinematics, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction, cAngleDetection::CollisionAngleDetection* i_pCollisionAngleDetection );
        virtual ~CalibrationState();
        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;

        // --- Getters
        CalibrationState_t GetSubState()const;
        float32_t GetTimeInCalibration()const;
        float32_t GetDistTravelledInCalibration()const;
        void GetThresholdVal();
        void GetDummyAngle();

    private:
        const tad2config::CalibrationConfigData& m_config;
        bool_t m_initialized;

        bool_t first;
        bool_t second;
        bool_t third;
        bool_t fourth;
        bool_t Drive_Fail;
        bool_t CameraBlocked;
        float32_t minwheelangle;
        float32_t maxwheelangle;
        float32_t TrailerAngle;

        TAD2::TrailerTemplate m_trailerTemplate;
        TAD2::TrailerTemplate m_trailerTemplate1;
        TAD2::TrailerTemplate m_trailerTemplate2;
        float32_t m_timePassedInState_s;
        float32_t m_distTravelledInState_m;
        uint32_t m_dummyangle_hitchPoint1;
        uint32_t m_dummyangle_hitchPoint2;
        uint32_t m_dummyangle_hitchPoint3;
        uint32_t m_dummyangle_hitchPoint4;
        uint32_t m_hitch_offset_start;
        uint32_t m_hitch_offset_finish;
        uint32_t hitchdiff;
        uint32_t m_hitch_range;
        bool_t m_trailerCalibrated;//M_TADCalibrationDone
        bool_t m_collisionangleCalibrated;
        bool_t m_hitchrangedetectionstarted;
        bool_t m_hitchCalibrated;
        int32_t last_geardir;

        TAD2::WarpedImage<uint8_t> warpedEdges1;
        bool_t first_frame = true;

        const uint16_t* m_thresh;
        const float32_t* m_Dummy_angle;

        //edge image
        image::Image<uint8_t> edges;

        CalibrationState_t m_subState;

        image::Image<uint8_t> m_calibratedTrailerImage;

        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;
        cAngleDetection::CollisionAngleDetection* m_pCollisionAngleDetection;

        // --- DummyAngle
        static const uint32_t c_bufSize = 30;
        buffer::CircularBuffer<float32_t, c_bufSize> m_trailerAngleBufDummy;
        static const uint32_t c_bufSize1 = 60;
        buffer::CircularBuffer<float32_t, c_bufSize1> m_wheelangle;

        // --- Sub-modules
        TAD2::TrailerTracking m_trailerTrackingObjDummy1;
        TAD2::TrailerTracking m_trailerTrackingObjDummy2;
        TAD2::TrailerTracking m_trailerTrackingObjDummy3;
        TAD2::TrailerTracking m_trailerTrackingObjDummy4;


        // --- Calibration modules
        TAD2::TrailerAngleCalibration m_trailerAngleCalibrationObj;
        TemplateBuild::TemplateBuildUp m_templateBuildUpObj;
        sampling::AngleSampling m_angleSamplingObj;
        Hitch::HitchDetection m_hitchDetectionObj;

        // --- Sub-state functions
        void StateDriveStraight( TAD2::Event& e, TAD2::Output& o );
        void StateTurnLeftOrRight( TAD2::Event& e, TAD2::Output& o );
        void StateWait( TAD2::Event& e, TAD2::Output& o );

        // --- DummyAngle
        float32_t _GetDummyAngle();
        void initialize_dummy_angle();
        void DummyAngleTracking( TAD2::Event& e );
        void hitchrangedetection( TAD2::Event& e );
    };
}

#endif // !__CALIBRATION_STATE_H
