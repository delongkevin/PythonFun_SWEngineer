// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "AngleDetectionState.h"
#include "TADStateMachine.h"
#include "common/config.h"
#include "Image.h"

#include "TADAlgoObject.h"
#include "TemplateMatching.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "CollisionAngleDetection.h"

#ifdef _WINDOWS
    #include <math.h>
#endif

#ifdef WIN_2015_CODE
    #ifdef DIAGNOSTICS
        #include "global.h"
        #include "common/db.h"
        #include "fo.h"
    #endif
#endif

namespace TAD2
{

    /*
    * Constructor.
    */
    AngleDetectionState::AngleDetectionState( const tad2config::TrailerPresenceDetectionConfigData& i_AbsencePresenceconfig, const tad2config::TrailerAngleDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* i_kinematics, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction ):

        TAD2::State( parent ),
        m_config( i_config ),
        m_AbsencePresenceconfig( i_AbsencePresenceconfig ),
        m_initialized( false ),
        m_implicitCalibrationRunning( false ),
        m_initialized_kinematic( false ),
        m_pVehicle( i_kinematics ),
        m_pPreProcessing( i_preProcessing ),
        m_pFeatureExtraction( i_pFeatureExtraction ),
        m_pImageThresholding( i_pImageThresholding ),
        m_trailerTrackingObj(),
        m_trailerPresenceDetectionObj( i_preProcessing, i_kinematics )
    {
        for( uint32_t windowItr_u32 = 0; windowItr_u32 < window_size; ++windowItr_u32 )
        {
            angle_interpolation_weights[windowItr_u32] = 0;
        }
    }

    /*
    * Destructor.
    */
    AngleDetectionState::~AngleDetectionState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t AngleDetectionState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*Name : AngleDetection
        //DT
        *   Remarks: DD-ID: {D263AC46-EC4D-41dd-9EF3-78020C7FAAFA
        //BEV
        *  Remarks:DD-ID: {35F5F7CF-23DF-41b7-9234-2125F5922DE1
        //HD
        *   Remarks:DD-ID: {991255F3-B01F-4c2c-BFBD-D2208C2DDF47}
        */
        bool_t possibleChangeInAngle = true;

        // If event's trailer angle is changed by the implicit calibration,
        //Need to change the angle within trailerTracking to reflect that.
        if( ( e.trailerAngleKnown && static_cast<bool_t>( e.currentTrailerAngle_deg ) ) == static_cast<uint32_t>( m_trailerTrackingObj.GetTrailerAngle() ) )
        {
            m_trailerTrackingObj.SetTrailerAngle( e.currentTrailerAngle_deg );
        }

        if( super->IsTrailerImplicitlyCalibrated() )
        {
            m_trailerTrackingObj.SetCurrentTrailerAngle( 90.0f );
        }

        // --- Restart tracking object if template is updated so that it can reload
        if( e.trailerTemplateUpdated )
        {
            m_trailerTrackingObj.Finish();
            float32_t v_TrailerAngle_f32 = super->GetTrailerAngle_deg();
            m_trailerTrackingObj.Start( super->GetTrailerTemplate(), v_TrailerAngle_f32 );
        }

        // --- Check kinematics
        if( m_config.getStopMatchingWhenVehicleStopped() && super->KinematicsEnabled() && m_pVehicle->valid() && m_pVehicle->Is_Vehicle_Neutral() )
        {
            possibleChangeInAngle = false;
        }

        // ++ kinematic angle ++ //
        // --- Calibrate trailer angle
        m_vehiclespeed.push( m_pVehicle->currentSpeed_mps() );
        float32_t current_angle;

        if( m_config.getAngleFilerEnable() )
        {
            current_angle = _GetTrailerAngle1();
        }
        else
        {
            current_angle = _GetTrailerAngle();
        }

        m_trailerAngleCalibration.Run( e.frame, m_pVehicle, false );
        m_trailerAngleCalibration.QuickCalibrate( current_angle, 5.0 );
        // --- Send calibration angles to state machine
        float32_t left;
        float32_t right;
        m_trailerAngleCalibration.GetCalibrationAngles( left, right );
        bool_t dynamic_window_size = false;

        // dynamic window
        if( ( abs( KMPreviousleft - left ) > dynamic_window_thresh ) || ( abs( KMPreviousright - right ) > dynamic_window_thresh ) )
        {
            dynamic_window_size = true;
        }

        KMPreviousleft = left;
        KMPreviousright = right;
        Point2i hitchPoint = super->GetHitchPoint();
        /*std::fstream file1;
        std::fstream timefile1;
        timefile1.open( "TAD\\topview_2855.csv", file1.out | file1.app );

        if( e.frame == 2855 )
        {
            for( uint32_t y = 0; y < e.topView.getHeight(); y++ )
            {
                for( uint32_t x = 0; x < e.topView.getWidth(); x++ )
                {
                    int val = *e.topView.at( x, y );
                    timefile1 << val;
                    timefile1 << ",";
                }

                timefile1 << "\n";
            }

            timefile1.close();
            file1.close();
        }*/
        // --- Warp edges
        m_pPreProcessing->WarpImage( e.topView, warpedEdges, hitchPoint );
        //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( warpedEdges );
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
        float32_t otsu_offset = ( averageIllumination / 255.0f ) * 10.0f;

        if( otsu_offset < 1.0f )
        {
            otsu_offset = otsu_offset * 2.0f;
        }

        //
        // --- Run angle detection
        if( m_config.getDynamicWindowSize() )
        {
            m_trailerTrackingObj.Run( e.frame, warpedEdges, m_pImageThresholding->_getotsuthresh() * otsu_offset, false, dynamic_window_size );
        }
        else
        {
            m_trailerTrackingObj.Run( e.frame, warpedEdges, m_pImageThresholding->_getotsuthresh() * otsu_offset, false, false );
        }

        m_trailerAngleBuf.push( m_trailerTrackingObj.GetTrailerAngle() );
        uint32_t startInd = m_trailerAngleBuf.fill();

        if( m_pVehicle->currentSpeed_mps() > 0.01f )
        {
            if( m_config.getAngleFilerEnable() )
            {
                current_angle = _GetTrailerAngle1();
            }
            else
            {
                current_angle = _GetTrailerAngle();
            }

            super->Set_IsTrailerAngleUpdating( true );
        }
        else
        {
            current_angle = previous_angle;
            super->Set_IsTrailerAngleUpdating( false );
        }

        m_trailerAngleBuf[startInd - 1] = current_angle;
        //
        TAD2::State::Enum nextState = TAD2::State::AngleDetection;
        // finding angle difference
        angle_diff = mecl::math::abs_x( previous_angle - current_angle );
        // finding tracking score confidence
        trackingScore = m_trailerTrackingObj.GetTrackingScore();
        trackingScore = trackingScore * 2.0f;

        if( trackingScore >= 1.0f )
        {
            trackingScore = 0.99f;
        }

        if( averageIllumination < 20.0f )
        {
            trackingScore = trackingScore / 2.0f;
        }

        m_trailerConfidenceBuf.push( trackingScore );
        avg_val = average_trailerconfidence();

        // checking if trailer is disconnected
        if( ( mecl::math::abs_x( 90.0f - current_angle ) > 25.0f ) || ( mecl::math::abs_x( m_InitialAverageIllumination - averageIllumination ) > 10.0f ) )
        {
            m_TrailerAbsencePresenceInitializationDone = false;
        }

        if( m_TrailerAbsencePresenceInitializationDone )
        {
            if( m_pVehicle->gearDir() == TAD2::GearForward )
            {
                m_trailerPresenceDetectionObj.Run( e.frame, e.topView, hitchPoint, e.roi );
            }
        }
        else
        {
            if( super->GetVehicleSpeed() < 0.1f )
            {
                m_InitialAverageIllumination = averageIllumination;
                m_TrailerAbsencePresenceInitializationDone = true;
                m_trailerPresenceDetectionObj.Finish();
                m_trailerPresenceDetectionObj.Start();
            }
        }

        if( IsTrackingLost() )
        {
            previous_angle = current_angle;
            // --- Set output
            o.detectedAngle_deg = current_angle;
            o.detectedAngleValid = false;
            o.angleScore = avg_val;
            // --- Return next state
            nextState = TAD2::State::Trackinglost;
        }
        else if( m_trailerPresenceDetectionObj.IsComplete() )
        {
            if( !m_trailerPresenceDetectionObj.IsTrailerPresent() )
            {
                if( m_TotalRetry > m_AbsencePresenceconfig.getNoOfRetry() )
                {
                    m_TotalRetry = 0;
                    m_TrailerAbsencePresenceInitializationDone = false;
                    super->SetCalibrationDataReset();
                    // --- Set output
                    o.detectedAngle_deg = current_angle;
                    o.detectedAngleValid = false;
                    o.angleScore = avg_val;
                    // --- Return next state
                    nextState = TAD2::State::TrailerRecognition;
                }
                else
                {
                    m_TotalRetry++;
                    m_TrailerAbsencePresenceInitializationDone = true;
                    m_trailerPresenceDetectionObj.Finish();
                    m_trailerPresenceDetectionObj.Start();
                    // --- Set output
                    o.detectedAngle_deg = current_angle;
                    o.detectedAngleValid = true;
                    o.angleScore = avg_val;
                    // --- Return next state
                    nextState = TAD2::State::AngleDetection;
                }
            }
            else
            {
                m_TrailerAbsencePresenceInitializationDone = false;
                previous_angle = current_angle;
                // --- Set output
                o.detectedAngle_deg = current_angle;
                o.detectedAngleValid = true;
                o.angleScore = avg_val;
                // --- Return next state
                nextState = TAD2::State::AngleDetection;
            }
        }
        else
        {
            previous_angle = current_angle;
            // --- Set output
            o.detectedAngle_deg = current_angle;
            o.detectedAngleValid = true;
            o.angleScore = avg_val;
            // --- Return next state
            nextState = TAD2::State::AngleDetection;
        }

        return nextState;
    }

    /*
    * Called once when entering this state.
    */
    void AngleDetectionState::OnEnter()
    {
        // buffer resetting
        for( uint32_t i = 0; i < m_trailerConfidenceBuf.size(); i++ )
        {
            m_trailerConfidenceBuf.push( 1.0f );
        }

        //
        initial_total_frame = 0;
        m_TotalRetry = 0;
        m_InitialAverageIllumination = 0.0f;
        super->SetTrailerPresenceDetectionDone( false );
        // --- Initialize template and topview parameters
        m_warpedTopViewParams = super->GetWarpedTopViewParams();
        m_trailerTemplate = super->GetTrailerTemplate();
        float32_t initialTrailerAngle = super->GetTrailerAngle_deg();
        previous_angle = initialTrailerAngle;
        dynamic_window_thresh = super->GetWarpedTopViewParams().degreesPerPixel * ( static_cast<float32_t>( trailer::c_steady_numTemplates - 1 ) / 2.0f );
        //
        // --- Initialize angle history
        m_trailerAngleBuf.clear();
        m_trailerAngleBuf.push( initialTrailerAngle );
        float32_t total_sum = 0.0f;
        warpedEdges = TAD2::WarpedImage<uint8_t>( m_warpedTopViewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        super->SetCalibrationFailCount( 0 );

        // ++ initializing weights for angle interpolation
        for( uint32_t i = 0; i < window_size; i++ )
        {
            angle_interpolation_weights[i] = ( 1.0f / ( static_cast<float32_t>( i ) + 1.0f ) );
            total_sum += angle_interpolation_weights[i];
        }

        for( uint32_t i = 0; i < window_size; i++ )
        {
            angle_interpolation_weights[i] = angle_interpolation_weights[i] / total_sum;
        }

        // -- Initialize the value in Cirular Buffer
        uint32_t v_TrailerBuf_u32 = m_trailerConfidenceBuf.size();

        for( uint32_t i = 0; i < v_TrailerBuf_u32; i++ )
        {
            m_trailerConfidenceBuf.push( 1.0 );
            m_vehiclespeed.push( 1.0 );
        }

        if( m_config.getOutputFilterSize() > c_bufSize )
        {
            super->SetError( 0, "Angle filter size is too large." );
        }

        // --- Initialize modules
        if( !m_initialized )
        {
            m_initialized = true;
            m_initialized = m_initialized && m_trailerTrackingObj.Init( m_warpedTopViewParams, m_config.getWeightFactor() );
            m_initialized = m_initialized && m_trailerPresenceDetectionObj.Init( m_AbsencePresenceconfig, super->GetWarpedTopViewParams() );

            if( !m_initialized )
            {
                super->SetError( 2, "Couldn't initialize Angle Detection state." );
            }
        }

        bool_t result = m_trailerTrackingObj.Start( m_trailerTemplate, initialTrailerAngle );
        result = result && m_trailerPresenceDetectionObj.Start();
        m_TrailerAbsencePresenceInitializationDone = true;

        if( !result )
        {
            super->SetError( 1, "Couldn't start Angle Detection state." );
        }

        // --- Initialize modules for Kinematic model
        if( !m_initialized_kinematic )
        {
            m_initialized_kinematic = true;
            const tad2config::CANAndVehicleConfigData& CANcfg = super->GetVehicleConfigData();
            bool_t v_init_b = m_trailerAngleCalibration.Init( super->GetVehicleParams(), super->GetVehicleConfigData() );
            m_initialized_kinematic = m_initialized_kinematic && v_init_b;

            if( !m_initialized_kinematic )
            {
                super->SetError( 2, "Couldn't initialize Kinematic model" );
            }
        }

        // --- Start modules
        bool_t result2 = true;
        result = result && m_trailerAngleCalibration.Start( mecl::math::abs_x( 90.0f - initialTrailerAngle ), 3.0f );
        m_trailerAngleCalibration.Run( 0, m_pVehicle, false );
        m_trailerAngleCalibration.QuickCalibrate( initialTrailerAngle, 5.0 );
        // --- Send calibration angles to state machine
        m_trailerAngleCalibration.GetCalibrationAngles( KMPreviousleft, KMPreviousright );

        if( !result2 )
        {
            super->SetError( 1, "Couldn't start Kinematic model" );
        }
    }

    /*
    * Called once when exiting this state.
    */
    void AngleDetectionState::OnExit()
    {
        m_TrailerAbsencePresenceInitializationDone = false;
        m_trailerTrackingObj.Finish();
        m_trailerAngleCalibration.Finish();
        memory::MemoryPool::ReleaseImage( warpedEdges );
    }

    /*
    * Get the enum for this state.
    */
    int32_t AngleDetectionState::GetEnum()
    {
        return TAD2::State::AngleDetection;
    }
    /*
    * set the angle buffer to the given value
    */
    bool_t AngleDetectionState::IsTrackingLost()
    {
        bool_t ret_val;
        float32_t threshold = m_config.getTrackingLostThreshold();

        if( ( ( avg_val < threshold ) ) && !m_implicitCalibrationRunning && m_config.getTrackingLost() )
        {
            ret_val = true;
        }
        else
        {
            ret_val = false;
        }

        return ret_val;
    }
    /*
    * Take weighted average of most recent trailer angles to reduce jittering.
    */
    float32_t AngleDetectionState::_GetTrailerAngle1()
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
    * Take weighted average of most recent trailer angles to reduce jittering.
    */
    float32_t AngleDetectionState::_GetTrailerAngle()
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

        for( uint32_t i = 0; i < outputFilterSize_u32; i++ )
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
    * Finds the average of circular buffer
    */
    float32_t AngleDetectionState::average_trailerconfidence()
    {
        float32_t avg_value = 0;

        for( uint32_t i = 0; i < m_trailerConfidenceBuf.size(); i++ )
        {
            avg_value += m_trailerConfidenceBuf[i];
        }

        return avg_value / ( static_cast<float32_t>( m_trailerConfidenceBuf.size() ) );
    }
    /*
    * set the flag for implicit calibration running
    */
    void AngleDetectionState::Setimplicitcalbration( bool_t running )
    {
        m_implicitCalibrationRunning = running;
    }
    /*
    * set the angle buffer to the given value
    */
    void AngleDetectionState::SetAngleBuffer( float32_t angle )
    {
        for( uint32_t i = 0; i < m_trailerAngleBuf.size(); i++ )
        {
            m_trailerAngleBuf.push( angle );
        }
    }

}
