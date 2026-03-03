// ----------------------------------------------------------------------------
// --- Written by Prasanna A [05-Jan-2022]
// --- Last Modified by Prasanna A [05-Jan-2022]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TRAILER_RECOGNITION__H_
#define __TRAILER_RECOGNITION__H_

#include "PreProcessing.h"
#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
    #include "TrailerPresenceDetection.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include <algo\inc\TrailerPresenceDetection.h>
#endif
#include "PreProcessing.h"
#include "VehicleKinematics.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "TrailerPresenceDetection.h"
#include "Scanning.h"
#include "ImageProcessing.h"
#include "db.h"


namespace RecognitionState
{
    /** Trailer Recognition state. Part of the TAD state machine. **/
    class TrailerRecognitionState : public TAD2::State
    {
    public:
        TrailerRecognitionState( const tad2config::TrailerRecognitionConfigData& i_config, const tad2config::TrailerPresenceDetectionConfigData& i_Presenceconfig, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction );
        virtual ~TrailerRecognitionState();

        virtual void OnEnter()override;
        virtual void OnExit()override;
        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o )override;
        virtual int32_t GetEnum() override;
    private:
        bool_t m_initialized;
        const tad2config::TrailerRecognitionConfigData& m_config;
        const tad2config::TrailerPresenceDetectionConfigData& m_PresenceConfig;

        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;

        // --- Sub modules
        Scan::Scanning m_scanningObj;

        TAD2::WarpedImage<uint8_t> warpedimage;
        TAD2::WarpedImage<uint8_t> warpedEdges;
        image::Image<uint8_t> warpedLabelImage;
        image::Image<bool_t> iswarpedlabeledImage;

        //variables
        uint32_t TotalRetry;
        uint32_t Trailer_count = 0;
        bool_t ScannindInitializationDone;
        _roi::ROI WarpedImageROI;
        TAD2::TrailerFeatures::Trailers TrailerFeat;

        // functions
        TAD2::TrailerFeatures::Trailers GetTrailerFeatureCalibration( uint32_t i_trailerCount, bool_t& trailerLoadedSuccessfully );
        TrailerID_t GetTrailerID( uint32_t i_trailerCount );
        void userinput_loadingtrailer( );
    };
}
#endif // !__TRAILER_RECOGNITION__H_
