// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __ANGLE_DETECTION_STATE_H
#define __ANGLE_DETECTION_STATE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
    #include "../common/CircularBuffer.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include "common/CircularBuffer.h"
#endif

#include "TrailerTracking.h"
#include "TrailerAngleCalibration.h"
#include "TrailerPresenceDetection.h"
#include "CollisionAngleDetection.h"
#include "FeatureExtraction.h"
#include "ImageThresholding.h"
#include "PreProcessing.h"

namespace TAD2
{
    struct TrailerAngleDetectionConfigData;

    /** Angle detection state. Part of the TAD state machine. **/

    class AngleDetectionState : public TAD2::State
    {
    public:
        AngleDetectionState( const tad2config::TrailerPresenceDetectionConfigData& i_AbsencePresenceconfig, const tad2config::TrailerAngleDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* i_kinematics, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction );

        virtual ~AngleDetectionState();

        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;
        void Setimplicitcalbration( bool_t running );
        void SetAngleBuffer( float32_t angle );

    private:
        const tad2config::TrailerAngleDetectionConfigData& m_config;
        const tad2config::TrailerPresenceDetectionConfigData& m_AbsencePresenceconfig;
        bool_t m_initialized;
        bool_t m_implicitCalibrationRunning;

        TAD2::WarpedTopViewParameters m_warpedTopViewParams;
        TAD2::TrailerTemplate m_trailerTemplate;
        TAD2::WarpedImage<uint8_t> warpedEdges;

        static const uint32_t c_bufSize = 30;
        buffer::CircularBuffer<float32_t, c_bufSize> m_trailerAngleBuf;
        static const uint32_t c_bufSize1 = 15;
        buffer::CircularBuffer<float32_t, c_bufSize1> m_trailerConfidenceBuf;
        buffer::CircularBuffer<float32_t, c_bufSize1> m_vehiclespeed;
        float32_t previous_angle;
        bool_t m_initialized_kinematic;
        static const uint32_t window_size = 20;

        float32_t angle_diff;
        float32_t trackingScore;
        float32_t avg_val;
        uint32_t initial_total_frame = 0;
        float32_t KMPreviousleft;
        float32_t KMPreviousright;
        float32_t dynamic_window_thresh;
        bool_t m_TrailerAbsencePresenceInitializationDone;
        uint32_t m_TotalRetry;
        float32_t m_InitialAverageIllumination;


        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::FeatureExtraction* m_pFeatureExtraction;
        TAD2::ImageThresholding* m_pImageThresholding;

        // --- Sub-modules
        TAD2::TrailerAngleCalibration m_trailerAngleCalibration;
        TAD2::TrailerTracking m_trailerTrackingObj;
        TrailerPresence::TrailerPresenceDetection m_trailerPresenceDetectionObj;

        float32_t angle_interpolation_weights[window_size];
        float32_t _GetTrailerAngle();
        float32_t _GetTrailerAngle1();
        float32_t average_trailerconfidence();
        bool_t IsTrackingLost();

    };

}
#endif // !__ANGLE_DETECTION_STATE_H