// ----------------------------------------------------------------------------
// --- Written by Prasanna AnanthaKrishnan [11-Nov-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifndef __TRACKING_LOST_H
#define __TRACKING_LOST_H

#ifdef __QNX__
    #include "../common/Image.h"
    #include "../common/CircularBuffer.h"
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
#else
    #include "common/Image.h"
    #include "common/CircularBuffer.h"
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
#endif
#include "TrailerTracking.h"
#include "Scanning.h"
#include "TrailerAngleCalibration.h"
#include "FeatureExtraction.h"
#include "ImageThresholding.h"
#include "PreProcessing.h"
#include "VehicleKinematics.h"

namespace tad2config
{
    struct TADConfigData;
}

namespace TAD2
{
    class TADAlgoObject;
    struct TrailerAngleDetectionConfigData;
}

/** TrackingLost state. Part of the TAD state machine. **/
namespace TrackingState
{
    class TrackingLostState : public TAD2::State
    {
    public:
        TrackingLostState( const tad2config::TrailerAngleDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* featureExtraction );
        virtual ~TrackingLostState();

        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;

    private:
        const tad2config::TrailerAngleDetectionConfigData& m_config;
        bool_t m_initialized;
        bool_t m_initialized_angle;
        bool_t m_initialized_kinematic;
        bool_t m_first_scanning_done;

        TAD2::WarpedTopViewParameters m_warpedTopViewParams;
        TAD2::TrailerTemplate m_trailerTemplate;

        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;

        // --- Sub modules
        TAD2::TrailerAngleCalibration m_trailerAngleCalibration;
        Scan::Scanning m_scanningObj;

        static float32_t FindAverageIllumination( const uint8_t* i_topViewPtr );
        float32_t previous_left;
        float32_t previous_right;
        float32_t first_scanning_angle;
        uint32_t frame_no;
    };
}
#endif // !__TRACKING_LOST_H