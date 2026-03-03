// ----------------------------------------------------------------------------
// --- Written by Prasanna AnanthaKrishnan [11-Nov-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "../inc/TrackingLostState.h"
#include "stdtad.h"
#include "ScanningState.h"
#include "TADStateMachine.h"
#include "common/config.h"
#include "WarpLUT.h"
#include "TADAlgoObject.h"

#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"

namespace TrackingState
{
    /*
    * Constructor.
    */
    TrackingLostState::TrackingLostState( const tad2config::TrailerAngleDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* featureExtraction ) :
        TAD2::State( parent ),
        m_config( i_config ),
        m_initialized( false ),
        m_initialized_angle( false ),
        m_initialized_kinematic( false ),
        m_warpedTopViewParams( TAD2::getWarpedTopViewParams() ),
        m_pVehicle( kinematic ),
        m_pPreProcessing( i_preProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( featureExtraction ),
        m_scanningObj()

    {
    }

    /*
    * Destructor.
    */
    TrackingLostState::~TrackingLostState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t TrackingLostState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: Trackinglost
        //DT
        *  Remarks: DD-ID: {040D7F86-20FB-4ea8-9F88-CFA348EA947B}
        //BEV
        *  Remarks: DD-ID: {4B84945A-C59D-4163-87C8-C2A11E69685D}
        //HD
        *  Remarks: DD-ID: {78648F34-FF6F-4182-B2FF-F5831E61202E}
        */
        int32_t ret_val;
        bool_t isReturned = true;
        TAD2::State::Enum nextState = TAD2::State::Trackinglost;
        ret_val = nextState;
        //
        // ++ kinematic angle ++ //
        // --- Calibrate trailer angle
        m_trailerAngleCalibration.Run( e.frame, m_pVehicle, true );
        // --- Send calibration angles to state machine
        float32_t left;
        float32_t right;
        m_trailerAngleCalibration.GetCalibrationAngles( left, right );
        super->SetCalibrationAngles( left, right );
        bool_t m_isTrailerStraight = true;

        if( ( !m_trailerAngleCalibration.TrailerAngleCalibrated() ) || !( abs( m_pVehicle->currentSpeed_mps() ) > 0 ) )
        {
            m_isTrailerStraight = false;
        }

        // --- Pre-processing
#ifdef WIN_2015_CODE
        Point2i hitchPoint = super->GetHitchPoint();
        TAD2::WarpedImage<uint8_t> warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        // --- Warp edges
        m_pPreProcessing->WarpImage( e.topView, warpedEdges, hitchPoint );
        float32_t averageIllumination = super->FindAverageIllumination( warpedEdges, e.roi );
        super->Set_averageillumination( averageIllumination );
        // --- Pre-processing
        m_pPreProcessing->Run( e.frame, warpedEdges, e.roi );
        image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
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
#else  // EMBD - TBD
        image::Image<uint8_t> topView = e.topView;
        //
        // --- Edge Detection
        Point2i hitchPoint = super->GetHitchPoint();
        //
        image::Image<uint8_t>& edges = m_pFeatureExtraction->GetEdges();
        //
        // --- Warp edges
        TAD2::WarpedImage<uint8_t> warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        m_pPreProcessing->WarpImage( edges, warpedEdges, hitchPoint );
#endif
        // --- Set output
        o.detectedAngle_deg = 90.0f;
        o.detectedAngleValid = true;
        o.angleScore = 0.0f;
        float32_t Rate_change_left = mecl::math::abs_x( left - previous_left );
        float32_t Rate_change_right = mecl::math::abs_x( right - previous_right );

        if( ( ( mecl::math::abs_x( 90.0f - left ) > 70.0f ) || ( mecl::math::abs_x( 90.0f - right ) > 70.0f ) ) || ( ( Rate_change_left > 1.0 ) || ( Rate_change_right > 1.0 ) ) )
        {
            if( !m_isTrailerStraight )
            {
                m_scanningObj.Finish();
                bool_t result1 = m_scanningObj.Start( m_trailerTemplate );
                previous_left = left;
                previous_right = right;

                if( !result1 )
                {
                    super->SetError( 1, "Couldn't start TrackingLost state." );
                }

                ret_val = nextState;
                isReturned = false;
            }
        }

        if( isReturned )
        {
            previous_left = left;
            previous_right = right;
            //
            // --- Run scanning
            m_scanningObj.Run( e.frame, warpedEdges, m_pImageThresholding->_getotsuthresh(), averageIllumination );

            //
            // --- Check if trailer found
            if( m_scanningObj.IsTrailerAngleFound() )
            {
                float32_t scanning_angle = abs( 90.0f - m_scanningObj.GetTrailerAngle() );

                if( ( m_scanningObj.GetScore() < 0.15f ) || ( scanning_angle > 35.0f ) )
                {
                    first_scanning_angle = 200.0f;
                    m_first_scanning_done = false;
                    m_scanningObj.Finish();
                    bool_t result1 = m_scanningObj.Start( m_trailerTemplate );
                    previous_left = left;
                    previous_right = right;

                    if( !result1 )
                    {
                        super->SetError( 1, "Couldn't start TrackingLost state." );
                    }

                    ret_val = nextState;
                    isReturned = false;
                }

                if( isReturned )
                {
                    if( m_first_scanning_done && ( mecl::math::abs_x( first_scanning_angle - m_scanningObj.GetTrailerAngle() ) < 1.0f ) )
                    {
                        o.detectedAngle_deg = m_scanningObj.GetTrailerAngle();
                        o.detectedAngleValid = true;
                        super->SetScanningScore( m_scanningObj.GetScore() );
                        nextState = TAD2::State::AngleDetection;
                    }
                    else
                    {
                        m_first_scanning_done = true;
                        first_scanning_angle = m_scanningObj.GetTrailerAngle();
                        m_scanningObj.Finish();
                        bool_t result1 = m_scanningObj.Start( m_trailerTemplate );
                        previous_left = left;
                        previous_right = right;
                        ret_val = nextState;

                        if( !result1 )
                        {
                            super->SetError( 1, "Couldn't start TrackingLost state." );
                        }
                    }
                }
            }
        }

        if( frame_no > m_config.getTrackingLostTimeOut() )
        {
            nextState = TAD2::State::TrailerRecognition;
            super->SetCalibrationDataReset();
        }

        // --- Return next state
        ret_val = nextState;
        frame_no++;
        memory::MemoryPool::ReleaseImage( warpedEdges );
        return ret_val;
    }

    /*
    * Called once when entering this state.
    */
    void TrackingLostState::OnEnter()
    {
        m_warpedTopViewParams = super->GetWarpedTopViewParams();
        m_trailerTemplate = super->GetTrailerTemplate();
        float32_t initialTrailerAngle = super->GetTrailerAngle_deg();
        previous_left = initialTrailerAngle;
        previous_right = initialTrailerAngle;
        m_first_scanning_done = false;
        first_scanning_angle = 200.0f;
        frame_no = 0;

        // --- Initialize modules for tracking Lost
        if( !m_initialized )
        {
            m_initialized = true;
            m_initialized = m_initialized && m_scanningObj.Init( m_warpedTopViewParams, m_pPreProcessing );

            if( !m_initialized )
            {
                super->SetError( 2, "Couldn't initialize TrackingLost state." );
            }
        }

        m_scanningObj.Finish();
        bool_t result1 = m_scanningObj.Start( m_trailerTemplate );

        if( !result1 )
        {
            super->SetError( 1, "Couldn't start TrackingLost state." );
        }

        // --- Initialize modules for Kinematic model
        if( !m_initialized_kinematic )
        {
            m_initialized_kinematic = true;
            const TAD2::VehicleParameters vehicleParams_st = super->GetVehicleParams();
            bool_t isTrailerAngleCalibration = m_trailerAngleCalibration.Init( vehicleParams_st, super->GetVehicleConfigData() );
            m_initialized_kinematic = m_initialized_kinematic && isTrailerAngleCalibration;

            if( !m_initialized_kinematic )
            {
                super->SetError( 2, "Couldn't initialize Kinematic model" );
            }
        }

        // --- Start modules
        bool_t result2 = true;
        result2 = m_trailerAngleCalibration.Start( mecl::math::abs_x( 90.0f - initialTrailerAngle ), 3.0f );

        if( !result2 )
        {
            super->SetError( 1, "Couldn't start Kinematic model" );
        }
    }
    /*
    * Called once when exiting this state.
    */
    void TrackingLostState::OnExit()
    {
        m_scanningObj.Finish();
        m_trailerAngleCalibration.Finish();
        m_first_scanning_done = false;
        first_scanning_angle = 0.0f;
        frame_no = 0;
    }
    /*
    * Get the enum for this state.
    */
    int32_t TrackingLostState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_Trackinglost;
    }
}
