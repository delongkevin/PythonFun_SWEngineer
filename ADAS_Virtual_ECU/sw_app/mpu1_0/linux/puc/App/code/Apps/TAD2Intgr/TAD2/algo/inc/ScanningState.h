// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __SCANNING_STATE_H
#define __SCANNING_STATE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
#endif

#include "Scanning.h"

#include "AngleDetectionState.h"
#include "FeatureExtraction.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"

namespace Scanning
{
    /** Scanning state. Part of the TAD state machine. **/
    class ScanningState : public TAD2::State
    {
    public:
        ScanningState( TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematics1, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* featureExtraction );
        virtual ~ScanningState();

        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;

    private:
        bool_t m_initialized;

        TAD2::WarpedTopViewParameters m_warpedTopViewParams;
        TAD2::TrailerTemplate m_trailerTemplate;
        TAD2::WarpedImage<uint8_t> warpedEdges;

        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::FeatureExtraction* m_pFeatureExtraction;
        TAD2::ImageThresholding* m_pImageThresholding;

        // --- Sub modules
        Scan::Scanning m_scanningObj;

    };
}
#endif // !__SCANNING_STATE_H
