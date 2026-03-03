// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "ScanningState.h"
#include "TADStateMachine.h"
#include "common/config.h"
#include "Image.h"

#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "common/db.h"
namespace Scanning
{
    /*
    * Constructor.
    */
    ScanningState::ScanningState( TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematics1, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* featureExtraction ) :
        TAD2::State( parent ),
        m_initialized( false ),
        m_pVehicle( kinematics1 ),
        m_pPreProcessing( i_preProcessing ),
        m_pFeatureExtraction( featureExtraction ),
        m_pImageThresholding( i_pImageThresholding ),
        m_scanningObj()

    {
    }

    /*
    * Destructor.
    */
    ScanningState::~ScanningState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t ScanningState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: ScanningForTrailer
        //DT
        *  Remarks: DD-ID: {791364E9-B469-4a53-B684-A370902FE594}
        //BEV
        *  Remarks: DD-ID: {2BA70919-1AB7-436a-B034-D654C725BE93}
        //HD
        *  Remarks: DD-ID: {55181765-F091-4d9c-AD05-EA5D5572E7EA}
        */
        TAD2::State::Enum nextState = TAD2::State::ScanningForTrailer;
        //
        Point2i hitchPoint = super->GetHitchPoint();
        // --- Warp edges
        m_pPreProcessing->WarpImage( e.topView, warpedEdges, hitchPoint );
        //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( warpedEdges );
        // --- Pre-processing
        m_pPreProcessing->Run( e.frame, warpedEdges, e.roi );
        image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
        float32_t averageIllumination = super->FindAverageIllumination( warpedEdges, e.roi );
        super->Set_averageillumination( averageIllumination );
        //cv::Mat im3 = processing::ImageProcessing::ConvertToCV( topView );
        //
        // --- Edge Detection
        image::Image<uint16_t> lowThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint16_t> highThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint8_t> gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
        //
        bool_t warpedimg = true;
        m_pImageThresholding->Run( e.frame, topView, e.roi, hitchPoint, e.currentTrailerAngle_deg, e.trailerAngleKnown, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
        m_pFeatureExtraction->Run( e.frame, topView, lowThresh, highThresh, e.roi, gradMag, gradDir );
        image::Image<uint8_t>& edges = m_pFeatureExtraction->GetEdges();
        //cv::Mat im4 = processing::ImageProcessing::ConvertToCV( edges );
        //cv::Mat im5 = processing::ImageProcessing::ConvertToCV( warpedEdges );
        memcpy( warpedEdges.getData(), edges.getData(), global::WARPED_TOPVIEW_IMAGE_HEIGHT * global::WARPED_TOPVIEW_IMAGE_WIDTH );
        //
        memory::MemoryPool::ReleaseImage( lowThresh );
        memory::MemoryPool::ReleaseImage( highThresh );
        memory::MemoryPool::ReleaseImage( gradMag );
        memory::MemoryPool::ReleaseImage( gradDir );
        //
#ifdef DIAGNOSTICS
        db::imshow( "(TAD 1) Warped Edges", edges, db::ImShow_Binary );
#endif
        // --- Run scan
        m_scanningObj.Run( e.frame, warpedEdges, m_pImageThresholding->_getotsuthresh(), averageIllumination );
        //

        // --- Check if trailer found
        if( m_scanningObj.IsTrailerAngleFound() )
        {
            o.detectedAngle_deg = m_scanningObj.GetTrailerAngle();
            o.detectedAngleValid = true;
            super->SetScanningScore( m_scanningObj.GetScore() );
            // Use cfg file. If runTurnaround is 1, nextState is turnaround.
            // Otherwise, go to AngleDetection.

            if( super->IsTurnaroundComplete() )
            {
                nextState = TAD2::State::AngleDetection;
            }
            else
            {
                if( !super->IsTrailerCalibrated() )
                {
                    nextState = TAD2::State::Turnaround;
                }
                else
                {
                    nextState = TAD2::State::AngleDetection;
                }
            }
        }

        // --- Return next state
        return nextState;
    }

    /*
    * Called once when entering this state.
    */
    void ScanningState::OnEnter()
    {
        m_warpedTopViewParams = super->GetWarpedTopViewParams();
        m_trailerTemplate = super->GetTrailerTemplate();
        warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );

        // --- Initialize modules
        if( !m_initialized )
        {
            m_initialized = true;
            m_initialized = m_initialized && m_scanningObj.Init( m_warpedTopViewParams, m_pPreProcessing );

            if( !m_initialized )
            {
                super->SetError( 2, "Couldn't initialize Scanning state." );
            }
        }

        bool_t result = m_scanningObj.Start( m_trailerTemplate );

        if( !result )
        {
            super->SetError( 1, "Couldn't start Scanning state." );
        }
    }

    /*
    * Called once when exiting this state.
    */
    void ScanningState::OnExit()
    {
        m_scanningObj.Finish();
        memory::MemoryPool::ReleaseImage( warpedEdges );
    }

    /*
    * Get the enum for this state.
    */
    int32_t ScanningState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_ScanningForTrailer;
    }
}
