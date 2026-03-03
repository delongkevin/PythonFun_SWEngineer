// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TRAILER_DETECTION_STATE_H
#define __TRAILER_DETECTION_STATE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
    #include "../common/TemplateMatching.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include "common/TemplateMatching.h"
#endif
#include "TrailerPresenceDetection.h"
#include "PreProcessing.h"
#include "VehicleKinematics.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"

#include "AngleDetectionState.h"

namespace TrailerState
{

    /** Trailer detection state. Part of the TAD state machine. **/
    class TrailerDetectionState : public TAD2::State
    {
    public:
        TrailerDetectionState( const tad2config::TrailerPresenceDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction );
        virtual ~TrailerDetectionState();

        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;

    private:
        const tad2config::TrailerPresenceDetectionConfigData& m_config;
        bool_t m_initialized;
        uint32_t fail_count;
        float32_t PreviousWheelAngle;

        float32_t speed_threshold;     // 0.27 mps or 1kmph

        // --- Sub modules
        TrailerPresence::TrailerPresenceDetection m_trailerPresenceDetectionObj;

        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;

    };
}
#endif // !__TRAILER_DETECTION_STATE_H
