// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TurnaroundState.h"
#include "TADStateTypes.h"
#include "common/config.h"
#include "Image.h"

#include "TemplateMatching.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "CollisionAngleDetection.h"
#include "TADStateMachine.h"


#include "db.h"

namespace TurnAround
{
    /*
    * Constructor.
    */
    TurnaroundState::TurnaroundState( const tad2config::CalibrationConfigData& i_Calib_config, const tad2config::TrailerAngleDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction, cAngleDetection::CollisionAngleDetection* i_pCollisionAngleDetection ) :
        TAD2::State( parent ),
        m_Calibconfig( i_Calib_config ),
        m_timePassedInState_s( 0.0f ),
        m_distTravelledInState_m( 0.0f ),
        m_turnaroundcompleted( false ),
        m_TemplateGenerated( false ),
        m_config( i_config ),
        m_initialized( false ),
        m_pVehicle( kinematic ),
        m_pPreProcessing( i_preProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( i_pFeatureExtraction ),
        m_pCollisionAngleDetection( i_pCollisionAngleDetection ),
        m_trailerTrackingObj()

    {
        for( uint32_t windowItr_u32 = 0; windowItr_u32 < window_size; ++windowItr_u32 )
        {
            angle_interpolation_weights[windowItr_u32] = 0;
        }
    }

    /*
    * Destructor.
    */
    TurnaroundState::~TurnaroundState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t TurnaroundState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: TurnaroundState
        //DT
        *  Remarks: DD-ID: {166BD0BB-2E7F-44b0-94EE-9E4D3C52FA31}
        //BEV
        *  Remarks: DD-ID: {3B9A7CE8-AA0B-40f4-9C1B-8DE80FABD1B1}
        //HD
        *  Remarks: DD-ID: {6868C23E-3185-4a40-BBD3-4A57F1522AD9}
        */
        TAD2::State::Enum returnState = TAD2::State::Turnaround;
        Drive_Fail = false;
        CameraBlocked = false;

        // --- Run sub-state machine
        switch( m_subState )
        {
            case TAD2::turnaround::State::DriveStraight:
            {
                StateDriveStraight( e, o );
                break;
            }

            case TAD2::turnaround::State::TurnLeftOrRight:
            {
                StateTurnLeftOrRight( e, o );
                break;
            }

            case TAD2::turnaround::State::Wait:
            {
                StateWait( e, o );
                break;
            }

            case CalibrationState_MAX:
            {
                //do nothing
            }
        }

        // Calibration Reset
        if( minwheelangle > m_pVehicle->wheelAngle_deg() )
        {
            minwheelangle = m_pVehicle->wheelAngle_deg();
        }

        if( maxwheelangle < m_pVehicle->wheelAngle_deg() )
        {
            maxwheelangle = m_pVehicle->wheelAngle_deg();
        }

        if( TrailerAngle > 75.0f )
        {
            CameraBlocked = true;
        }

        if( ( abs( minwheelangle ) > 20.0f ) && ( abs( maxwheelangle ) > 20.0f ) )
        {
            Drive_Fail = true;
        }

        // --- Kinematics
        if( super->KinematicsEnabled() && m_pVehicle->valid() )
        {
            m_timePassedInState_s += m_pVehicle->timePassed_s();
            m_distTravelledInState_m += mecl::math::abs_x( m_pVehicle->distanceTravelled_m() );
        }

        o.timeInState_s = m_timePassedInState_s;
        o.distanceTravelledInState_m = m_distTravelledInState_m;

        // --- Return next state if finished
        if( !m_turnaroundcompleted )
        {
            // Calibration Reset
            int32_t gear_dir = m_pVehicle->gearDir();

            if( ( last_geardir == 1 ) && ( gear_dir != 1 ) )
            {
                /*super->SetCalibrationFailReason( TrailerCalibrationFailInfo_t::Gear_IN_Reverse );
                super->SetCalibrationFailCount( super->GetCalibrationFailCount() + 1 );*/
                returnState = TAD2::State::TrailerDetection;
            }
            else
            {
                returnState = TAD2::State::Turnaround;
            }

            if( CameraBlocked )
            {
                super->SetCalibrationFailReason( TrailerCalibrationFailInfo_t::Camera_Blocked );
                super->SetCalibrationFailCount( super->GetCalibrationFailCount() + 1 );
                returnState = TAD2::State::TrailerDetection;
            }
        }
        else
        {
            returnState = TAD2::State::ScanningForTrailer;
        }

        last_geardir = m_pVehicle->gearDir();
        return returnState;
    }
    /*
    * Process function for the sub-state "Drive Stright."
    */
    void TurnaroundState::StateDriveStraight( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: TurnaroundState_DriveState
        //DT
        *  Remarks: DD-ID: {4E9EBAC0-8F42-4432-81A7-AED96BE7D449}
        //BEV
        *  Remarks: DD-ID: {613D5359-DA80-493b-8FAD-E0C80EF1B492}
        //HD
        *  Remarks: DD-ID: {D40E2368-9014-44c5-A442-89E0F12F3955}
        */
        bool_t ret_val = true;
        AngleTracking( e, o );
        bool_t speedAboveThreshold1 = true;
        bool_t speedAboveThreshold2 = true;
        bool_t trailerStraight = true;
        m_wheelangle.push( m_pVehicle->wheelAngle_deg() );
        super->SetTurnCompletedDuringTurnAround( false );
        TBL_WaitCount = 0;

        // --- Calibrate trailer angle
        if( m_Calibconfig.getTrailerAngleCalConfigParams().getEnabled() && super->KinematicsEnabled() )
        {
            m_trailerAngleCalibrationObj.Run( e.frame, m_pVehicle, false );
            m_trailerAngleCalibrationObj.QuickCalibrate( o.detectedAngle_deg, 5.0 );

            if( !m_trailerAngleCalibrationObj.TrailerAngleCalibrated() )
            {
                trailerStraight = false;
            }
        }

        // --- Check kinematics
        if( super->KinematicsEnabled() && ( m_pVehicle->currentSpeed_mps() < vehspeed::c_minVehSpeedDuringTemplateBuildUp ) )
        {
            speedAboveThreshold1 = false;
        }

        // distance travelled has been added so that the trailer will be in straight position when the collision algo kicks in
        if( super->KinematicsEnabled() && ( m_pVehicle->currentSpeed_mps() < 0.7f ) )
        {
            speedAboveThreshold2 = false;
        }

        if( super->KinematicsEnabled() && !m_pVehicle->valid() )
        {
            speedAboveThreshold1 = false;
            speedAboveThreshold2 = false;
        }

        if( trailerStraight && speedAboveThreshold1 && !m_templateBuildUpObj.IsTemplateFound() && !m_TemplateGenerated )
        {
            // --- Build trailer template
            m_templateBuildUpObj.Run( e.frame, warpedEdges );
        }

        // --- Send calibration angles to state machine
        float32_t left;
        float32_t right;
        m_trailerAngleCalibrationObj.GetCalibrationAngles( left, right );
        super->SetCalibrationAngles( left, right );

        // --- Check if finished
        if( !m_TemplateGenerated )
        {
            if( m_templateBuildUpObj.IsTemplateFound() && ( m_pCollisionAngleDetection->IsCollisionAngleFound() || !super->CollisonAngleDetectionEnabled() ) )
            {
                super->SetCollisionAngle( m_pCollisionAngleDetection->GetCollisionAngle(), m_pCollisionAngleDetection->GetLeftCollisionAngle(), m_pCollisionAngleDetection->GetRightCollisionAngle() );
                m_pCollisionAngleDetection->Finish();
                o.detectedCollisionAngleValid = true;
                m_TemplateGenerated = true;
                minwheelangle = 90.0f;
                maxwheelangle = -90.0f;
                o.detectedCollisionAngle = m_pCollisionAngleDetection->GetCollisionAngle();
                // --- Create trailer template image
                m_calibratedWarpedTrailerImage = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
                m_templateBuildUpObj.CreateInitialTemplate( m_calibratedWarpedTrailerImage );
                // --- cropping Template
                uint8_t data[global::TEMPLATE_IMAGE_SIZE];
                memset( reinterpret_cast<uint8_t*>( data ), 0, sizeof( uint8_t ) * global::TEMPLATE_IMAGE_SIZE );
                image::Image<uint8_t> crop_template = image::Image<uint8_t>( super->GetTrailerTemplate().getWidth(), super->GetTrailerTemplate().getHeight(), data, 1 );
                int32_t xAt90 = m_calibratedWarpedTrailerImage.Angle2XPos( 90.0f );
                t_m::TemplateMatching::ExtractTemplate( m_calibratedWarpedTrailerImage, crop_template, xAt90 - super->GetTrailerTemplate().getWidth() / 2, 0 );
                super->SetTrailerTemplate( crop_template );
                //
                m_trailerTrackingObj.Finish();
                bool_t result = m_trailerTrackingObj.Start( super->GetTrailerTemplate(), 90.0f );

                if( !result )
                {
                    super->SetError( 1, "Couldn't start Angle Tracking - Turnaround state." );
                }

                //
                m_trailerAngleCalibrationObj.Finish();
                m_templateBuildUpObj.Finish();
                m_avgTrailerModel.Start( 90.0f );
                m_subState = TurnAroundState_t::TurnAroundState_TurnLeftOrRight;
            }
        }
        else
        {
            if( trailerStraight || ( mecl::math::abs_x( o.detectedAngle_deg - 90.0f ) < 3.0f ) )
            {
                minwheelangle = 90.0f;
                maxwheelangle = -90.0f;
                m_trailerAngleCalibrationObj.Finish();
                m_templateBuildUpObj.Finish();
                m_avgTrailerModel.Start( 90.0f );
                m_subState = TurnAroundState_t::TurnAroundState_TurnLeftOrRight;
            }
        }
    }
    /*
    * Process function for the sub-state "Turn Left Or Right."
    */
    void TurnaroundState::StateTurnLeftOrRight( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: TurnaroundState_TurnLeftOrRight
        //DT
        *  Remarks: DD-ID: {E01F7629-CE2F-45f6-8653-6AA863824874}
        //BEV
        *  Remarks: DD-ID: {840C7D35-79A0-4496-9603-BE8B13F72575}
        //HD
        *  Remarks: DD-ID: {DA8331E5-455D-4877-9904-9998A0ACCF31}
        */
        m_subState = TurnAroundState_t::TurnAroundState_TurnLeftOrRight;
        bool_t ret_val = true;
        AngleTracking( e, o );
        m_avgTrailerModel.Run( e.frame, *m_pVehicle, false );
        float32_t curAngle_deg = mecl::math::abs_x( 90.0f - m_avgTrailerModel.getAngle_deg() );
        //
        m_wheelangle.push( m_pVehicle->wheelAngle_deg() );

        if( m_max_wheelAngle < mecl::math::abs_x( m_pVehicle->wheelAngle_deg() ) )
        {
            m_max_wheelAngle = mecl::math::abs_x( m_pVehicle->wheelAngle_deg() );
        }

        if( ( curAngle_deg > sampling::AngleSampling::c_largestAngleThresh_deg ) && ( m_max_wheelAngle > 25.0f ) )
        {
            super->SetTurnCompletedDuringTurnAround( true );
            turn_completed = true;
        }

        if( maxTrailerAngle < TrailerAngle )
        {
            maxTrailerAngle = TrailerAngle;
        }

        if( turn_completed )
        {
            if( maxTrailerAngle < 10.0f )
            {
                CameraBlocked = true;
            }

            float32_t average_ang = 0.0;
            uint32_t i;

            for( i = 0; i < m_wheelangle.size(); i++ )
            {
                average_ang += mecl::math::abs_x( m_wheelangle[i] );
            }

            average_ang = average_ang / static_cast<float32_t>( i );

            if( ( mecl::math::abs_x( average_ang ) < 1.0f ) && ( m_pVehicle->currentSpeed_mps() > 0.5f ) )
            {
                if( TrailerAngle > 20.0f )
                {
                    CameraBlocked = true;
                }

                m_subState = TurnAroundState_t::TurnAroundState_Wait;
            }
        }
    }
    /*
    * Process function for the "Wait" sub-state.
    */
    void TurnaroundState::StateWait( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: TurnaroundState_Wait
        //DT
        *  Remarks: DD-ID: {E01F7629-CE2F-45f6-8653-6AA863824874}
        //BEV
        *  Remarks: DD-ID: {C7608875-15DD-4c13-BF90-505CF1AFCD42}
        //HD
        *  Remarks: DD-ID: {E9CACA44-D055-42fd-8C71-E0038BAA936A}
        */
        bool_t ret_val = true;
        AngleTracking( e, o );
        TBL_WaitCount++;

        if( e.StatemachineInput.MeTRSC_b_OTBLReset || ( TBL_WaitCount > 100 ) )
        {
            TBL_WaitCount = 0;
            turn_completed = false;
            super->SetTurnCompletedDuringTurnAround( false );
            m_trailerAngleCalibrationObj.Init( super->GetVehicleParams(), super->GetVehicleConfigData() );
            m_trailerAngleCalibrationObj.Start( o.detectedAngle_deg, m_Calibconfig.getTrailerAngleCalConfigParams().getToleranceDeg() );
            m_subState = TurnAroundState_t::TurnAroundState_DriveStraight;
        }
        else if( e.StatemachineInput.MeTRSC_b_TBLComputationDone )
        {
            TBL_WaitCount = 0;
            super->Set_NewTrailerFeatures( super->GetTrailerTemplate(), super->GetHitchPoint(), 0, e.StatemachineInput.MeTRSC_m_TrailerBeamLen, e.StatemachineInput.MeTRSC_deg_JackKnifeAngle, ( e.StatemachineInput.MeTRSC_deg_JackKnifeAngle * 0.9f ) );
#if DUMP_TRAILER_TEMPLATE
            FILE* fp, *fp1;
            fp = fopen( "/ti_sd/before-calib-trailerImage.csv", "a+" );
            fp1 = fopen( "/ti_sd/before-calib-trailerImage.bin", "a+" );
            fwrite( ( void* )super->GetTrailerTemplate().getData(), 1, 203 * 150, fp1 );

            for( uint32_t y = 0; y < super->GetTrailerTemplate().getHeight(); y++ )
            {
                for( uint32_t x = 0; x < super->GetTrailerTemplate().getWidth(); x++ )
                {
                    int val = *super->GetTrailerTemplate().at( x, y );
                    fprintf( fp, "%d,", val );
                }

                fprintf( fp, "\n" );
            }

            fclose( fp );
#endif
            o.detectedBeamLengthValid = true;
            o.detectedBeamLength = e.StatemachineInput.MeTRSC_m_TrailerBeamLen;
            o.detectedJacknifeAngle = e.StatemachineInput.MeTRSC_deg_JackKnifeAngle;
            o.detectedJacknifeThreshAngle = ( e.StatemachineInput.MeTRSC_deg_JackKnifeAngle * 0.9f );
            m_turnaroundcompleted = true;
            super->SetTurnaroundComplete();
            super->SetTrailerCalibrated();
            super->SetBeamLengthEstimationDone();
            m_subState = TurnAroundState_t::TurnAroundState_TurnLeftOrRight;
        }
    }

    /*
    * function for angle tracking
    */
    void TurnaroundState::AngleTracking( TAD2::Event& e, TAD2::Output& o )
    {
        Point2i hitchPoint = super->GetHitchPoint();
        // --- Warp edges
        m_pPreProcessing->WarpImage( e.topView, warpedEdges, hitchPoint );
        //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( warpedEdges );
        float32_t averageIllumination = FindAverageIllumination( warpedEdges, e.roi );
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
        float32_t otsu_offset = ( averageIllumination / 255.0f ) * 10.0f;
        m_trailerTrackingObj.Run( e.frame, warpedEdges, m_pImageThresholding->_getotsuthresh() * otsu_offset, false, false );
        TrailerAngle = abs( 90.0f - m_trailerTrackingObj.GetTrailerAngle() );
        m_trailerAngleBuf.push( m_trailerTrackingObj.GetTrailerAngle() );
        uint32_t startInd = m_trailerAngleBuf.fill();
        float32_t current_angle;

        if( m_config.getAngleFilerEnable() )
        {
            current_angle = _GetTrailerAngle1();
        }
        else
        {
            current_angle = _GetTrailerAngle();
        }

        m_trailerAngleBuf[startInd - 1] = current_angle;
        //
        // finding tracking score confidence
        float32_t trackingScore = m_trailerTrackingObj.GetTrackingScore();
        trackingScore = trackingScore * 2.;

        if( trackingScore >= 1.0f )
        {
            trackingScore = 0.99f;
        }

        if( averageIllumination < 30.0f )
        {
            trackingScore = trackingScore / 2.0f;
        }

        m_trailerConfidenceBuf.push( trackingScore );
        // --- Set output
        o.detectedAngle_deg = current_angle;
        o.detectedAngleValid = true;
        o.angleScore = trackingScore;
    }

    /*
    * Called once when entering this state.
    */
    void TurnaroundState::OnEnter()
    {
        // --- Initialize template and topview parameters
        turn_completed = false;
        m_warpedTopViewParams = super->GetWarpedTopViewParams();
        m_trailerTemplate = super->GetTrailerTemplate();
        minwheelangle = 90.0f;
        maxwheelangle = -90.0f;
        m_max_wheelAngle = 0.0f;
        //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( m_trailerTemplate );
        float32_t initialTrailerAngle = super->GetTrailerAngle_deg();
        m_timePassedInState_s = 0.0f;
        m_distTravelledInState_m = 0.0f;
        TBL_WaitCount = 0;
        maxTrailerAngle = 0.0f;
        m_TemplateGenerated = false;
        m_turnaroundcompleted = false;
        m_subState = TurnAroundState_s::TurnAroundState_DriveStraight;
        warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        // --- Initialize angle history
        m_trailerAngleBuf.clear();
        m_trailerAngleBuf.push( initialTrailerAngle );

        if( m_config.getOutputFilterSize() > c_bufSize )
        {
            super->SetError( 0, "Angle filter size is too large." );
        }

        // -- Initialize kinematic model
        float32_t beamLengthPtr[2] = { super->GetVehicleConfigData().getBeamLengthRange_mmRef()[0], super->GetVehicleConfigData().getBeamLengthRange_mmRef()[1] };
        float32_t avg_beamlength = ( beamLengthPtr[0] + beamLengthPtr[1] ) / 2.0f;                      /* PRQA S 3706*/
        m_avgTrailerModel.Init( super->GetVehicleParams(), avg_beamlength, avg_beamlength, 200.0f, -20.0f );

        // --- Initialize modules
        if( !m_initialized )
        {
            m_initialized = true;
            m_initialized = m_initialized && m_trailerTrackingObj.Init( m_warpedTopViewParams, m_config.getWeightFactor() );
            m_initialized = m_initialized && m_trailerAngleCalibrationObj.Init( super->GetVehicleParams(), super->GetVehicleConfigData() );
            uint32_t hitchYOffset[2];
            hitchYOffset[0] = 0;
            hitchYOffset[1] = super->GethitchendrangePos();
            m_initialized = m_initialized && m_templateBuildUpObj.Init( m_Calibconfig.getHitchDetectionConfigData().getHitchX(), reinterpret_cast<uint32_t*>( hitchYOffset ) );

            if( !m_initialized )
            {
                super->SetError( 2, "Couldn't initialize Turnaround state." );
            }
        }

        bool_t result = m_trailerTrackingObj.Start( m_trailerTemplate, initialTrailerAngle );
        result = result && m_trailerAngleCalibrationObj.Start( m_Calibconfig.getTrailerAngleCalConfigParams().getInitialAngle(), m_Calibconfig.getTrailerAngleCalConfigParams().getToleranceDeg() );
        result = result && m_templateBuildUpObj.Start();

        if( !result )
        {
            super->SetError( 1, "Couldn't start Turnaround state." );
        }
    }

    /*
    * Called once when exiting this state.
    */
    void TurnaroundState::OnExit()
    {
        m_trailerTrackingObj.Finish();
        m_trailerAngleCalibrationObj.Finish();
        m_templateBuildUpObj.Finish();
        m_avgTrailerModel.Finish();
        memory::MemoryPool::ReleaseImage( m_calibratedWarpedTrailerImage );
        memory::MemoryPool::ReleaseImage( warpedEdges );
    }
    /*
    * Get the enum for this states current sub-state.
    */
    TurnAroundState_t TurnaroundState::GetSubState()const
    {
        return m_subState;
    }

    /*
    * Get the enum for this state.
    */
    int32_t TurnaroundState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround;
    }
    /*
    * Finds the average illumination of given image
    */
    float32_t TurnaroundState::FindAverageIllumination( image::Image<uint8_t>& i_warpedview, _roi::ROI& i_roi )
    {
        float32_t avgValue = 0.0f;
        int32_t startX = 321;
        int32_t startY = 25;
        int64_t count = 0;

        for( uint32_t y = i_roi.getY(); y < i_roi.getHeight(); y++ )
        {
            for( uint32_t x = i_roi.getX(); x < ( i_roi.getX() + i_roi.getWidth() ); x++ )
            {
                avgValue = avgValue + static_cast<float32_t>( *i_warpedview.at( x, y ) ); //PRQA S 3706
                count++;
            }
        }

        avgValue = ( avgValue / static_cast<float32_t>( count ) );
        return( avgValue );
    }
    /*
    * Take weighted average of most recent trailer angles to reduce jittering.
    */
    float32_t TurnaroundState::_GetTrailerAngle()
    {
        float32_t sum = 0.0f;
        float32_t totalWeight = 0.0f;
        float32_t w;
        uint32_t startInd = 0;
        uint32_t outputFilterSize_u32 = m_config.getOutputFilterSize();

        if( m_trailerAngleBuf.fill() > outputFilterSize_u32 )
        {
            startInd = m_trailerAngleBuf.fill() - outputFilterSize_u32;
        }

        for( uint32_t i = 0; i < m_config.getOutputFilterSize(); i++ )
        {
            if( i >= m_trailerAngleBuf.fill() )
            {
                break;
            }

            w = 2.0f * static_cast<float32_t>( ( i + 1 ) );
            sum += w * m_trailerAngleBuf[startInd + i];
            totalWeight += w;
        }

        return sum / totalWeight;
    }
    /*
    * Take weighted average of most recent trailer angles to reduce jittering.
    */
    float32_t TurnaroundState::_GetTrailerAngle1()
    {
        float32_t sum = 0.0f;
        float32_t totalWeight = 0.0f;
        float32_t w;
        uint32_t startInd = 0;
        uint32_t outputFilterSize_u32 = m_config.getOutputFilterSize();

        if( m_trailerAngleBuf.fill() > outputFilterSize_u32 )
        {
            startInd = m_trailerAngleBuf.fill() - outputFilterSize_u32;
        }

        float32_t interpolated_val[100] = { 0 };
        float32_t start_val = 0.0f;
        float32_t end_val = 0.0f;

        for( uint32_t i = 0; i < m_config.getOutputFilterSize(); i++ )
        {
            if( i >= m_trailerAngleBuf.fill() )
            {
                break;
            }

            if( i == 0 )
            {
                start_val = m_trailerAngleBuf[startInd + i];
                end_val = m_trailerAngleBuf[startInd + i];
                continue;
            }

            end_val = m_trailerAngleBuf[startInd + i];
        }

        float32_t diff_val = mecl::math::abs_x( start_val - end_val );
        float32_t diff_val_interp = 0.0f;

        if( mecl::math::isAboutZero_b( diff_val - 0.0f ) )
        {
            diff_val_interp = ( mecl::math::abs_x( start_val - round( start_val ) ) / 10000.0f ) / ( static_cast<float32_t>( window_size ) );
        }
        else
        {
            diff_val_interp = diff_val / ( static_cast<float32_t>( window_size ) );
        }

        interpolated_val[0] = start_val;
        bool_t turn_right = false;

        if( end_val < start_val )
        {
            turn_right = true;
        }

        for( uint32_t i = 1; i < window_size; i++ )
        {
            if( turn_right )
            {
                interpolated_val[i] = interpolated_val[i - 1] - ( angle_interpolation_weights[i - 1] * diff_val );
            }
            else
            {
                interpolated_val[i] = interpolated_val[i - 1] + ( angle_interpolation_weights[i - 1] * diff_val );
            }
        }

        for( uint32_t i = 0; i < window_size; i++ )
        {
            w = 3.0f * static_cast<float32_t>( ( i + 1 ) );
            sum += w * interpolated_val[i];
            totalWeight += w;
        }

        return sum / totalWeight;
    }
    /*
    * Get the amount of time passed in this state
    */
    float32_t TurnaroundState::GetTimeInCalibration()const
    {
        return m_timePassedInState_s;
    }

    /*
    * Get the distance travelled (m) while in this state.
    */
    float32_t TurnaroundState::GetDistTravelledInCalibration()const
    {
        return m_distTravelledInState_m;
    }
}
