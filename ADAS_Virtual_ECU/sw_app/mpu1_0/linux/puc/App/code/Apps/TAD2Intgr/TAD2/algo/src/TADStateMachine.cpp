// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TADStateMachine.h"
#include "TADAlgoObject.h"
#include "common/config.h"
#include "WarpLUT.h"

#include "CollisionAngleDetection.h"

namespace TAD2
{
    /**
    * Constructor.
    */
    TADStateMachine::TADStateMachine( tad2config::TADConfigData& i_config, const TAD2::VehicleParameters& i_vehicleParams, TADAlgoObject* i_pAlgoObj, TAD2::VehicleKinematics* i_pVehicleKinematics, TAD2::PreProcessing* i_pPreProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction, cAngleDetection::CollisionAngleDetection* i_pCollisionAngleDetection ) :
        m_isRunning( false ),
        m_trailerTemplateUpdated( false ),
        m_state( nullptr ),
        m_config( i_config ),
        m_vehicleParams( i_vehicleParams ),
        m_warpedTopViewParams( TAD2::getWarpedTopViewParams() ),
        m_trailerLoadedSuccessfully( false ),
        m_hitchLoadedSuccessfully( false ),
        m_collisionangleLoadedSuccessfully( false ),
        m_beamLengthLoadedSuccessfully( false ),
        m_detectCollisionAngle( false ),
        m_CalibrateTrailer( false ),
        m_trailerDetectionComplete( false ),
        m_trailerDetected( false ),
        m_trailerDetectedrecognitionstate( false ),
        m_hitchCalibrated( false ),
        m_dynamicTemplateEnabled( false ),
        m_turnaroundComplete( false ),
        m_beamLengthEstimationDone( false ),
        m_trailerImplicitlyCalibrated( false ),
        m_turnCompletedDuringTurnAroundState( false ),
        m_trailerPredictionCompleted( false ),
        m_trailerPresenceDetectionDone( false ),
        m_trailerAngleKnown( false ),
        m_collisionAngleKnown( false ),
        m_hitchrangevalid( false ),
        m_trailerAngle_deg( 90.0f ),
        m_trackingScore( 0.0f ),
        m_scanningScore( 0.0f ),
        m_collisionAngle( 0.0f ),
        m_leftcollisionangle( 0.0f ),
        m_rightcollisionangle( 0.0f ),
        m_leftCalibrationAngle( 90.0f ),
        m_rightCalibrationAngle( 90.0f ),
        m_hitchCalibrationAngle( 90.0f ),
        m_hitch_pos( 0 ),
        m_bumper_pos( 0 ),
        m_hitch_range_calculated( false ),
        m_dummy_angle_1( 90.0f ),
        m_dummy_angle_2( 90.0f ),
        m_dummy_angle_3( 90.0f ),
        m_dummy_angle_4( 90.0f ),
        m_calibrationFailCount( 0 ),
        InputTrailerID( -1 ),
        ConfigTrailerID( -1 ),
        m_pVehicle( i_pVehicleKinematics ),
        m_pPreProcessing( i_pPreProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( i_pFeatureExtraction ),
        m_pCollisionAngleDetection( i_pCollisionAngleDetection ),
        m_stateIdle( this, i_pVehicleKinematics ),
        m_stateTrailerDetection( i_config.getTrailerDetectionConfigParamsRef(), this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction ),
        m_stateTrailerRecognition( i_config.getTrailerRecognitionConfigParamsRef(), i_config.getTrailerDetectionConfigParamsRef(), this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction ), // need to add config
        m_stateCalibration( i_config.getCalibrationConfigParamsRef(), this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction, i_pCollisionAngleDetection ),
        m_stateAngleDetection( i_config.getTrailerDetectionConfigParamsRef(), i_config.getTadConfigParamsRef(), this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction ),
        m_stateScanning( this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction ),
        m_TrackingLost( i_config.getTadConfigParamsRef(), this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction ),
        m_stateTurnaround( i_config.getCalibrationConfigParamsRef(), i_config.getTadConfigParamsRef(), this, i_pVehicleKinematics, i_pPreProcessing, i_pImageThresholding, i_pFeatureExtraction, i_pCollisionAngleDetection ),
        m_pAlgoObj( i_pAlgoObj )

    {
    }

    /**
    * Destructor.
    */
    TADStateMachine::~TADStateMachine()
    {
    }

    /**
    * Start this state machine.
    */
    void TADStateMachine::Start( TAD2::State::Enum i_entryState, TAD2::JobTADInput& i_jobinput )
    {
        bool_t ret_val = true;
        m_isRunning = true;
        m_trailerLoadedSuccessfully = false;
        m_beamLengthLoadedSuccessfully = false;
        m_hitchLoadedSuccessfully = false;
        m_collisionangleLoadedSuccessfully = false;
        m_bumper_pos = m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchYOffsetRef()[0];//PRQA S 3706
        m_hitchendrangePos = m_bumper_pos + ( m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchYOffsetRef()[1] - m_bumper_pos ); //PRQA S 3706
        m_Pixel2mmconversionval = 5.6f;
        LoadCalibration( i_jobinput.NVMInput.trailerFeatures );
        m_CalibrateTrailer = i_jobinput.NVMInput.calibrateNewTrailer || i_jobinput.NVMInput.calibrateHitchPoint;
        InputTrailerID = i_jobinput.NVMInput.InputTrailerID;
        ConfigTrailerID = i_jobinput.NVMInput.ConfigTrailerID;
        m_trailerDetectionComplete = false;
        m_trailerDetectedrecognitionstate = false;
        m_trailerDetected = false;
        m_trailerCalibrated = false;
        m_dynamicTemplateEnabled = false;
        m_hitchCalibrated = false;
        m_trailerAngleKnown = false;
        m_collisionAngleKnown = false;
        m_turnCompletedDuringTurnAroundState = false;
        m_trailerPredictionCompleted = false;
        m_trailerImplicitlyCalibrated = false;
        m_trailerPresenceDetectionDone = false;
        m_hitchrangevalid = true;
        m_averageIllumination = 0.0f;
        //m_turnaroundComplete = !m_config.getCalibrationConfigParamsRef().getTurnaroundConfigData().getEnabled();
        m_turnaroundComplete = false;
        m_beamLengthEstimationDone = false;
        m_IsTrailerAngleUpdating = false;
        // --- Get
        m_state = StateMap( i_entryState );
        m_calibrationFailCount = 0;
        TrailerCalFailInfo = TrailerCalibrationFailInfo_e::No_Failure;
        CurrentTrailer_ID = TrailerID_t::Trailer_MAX;

        if( m_state == nullptr )
        {
            Stop();
            ret_val = false;
        }

        if( ret_val )
        {
            m_state->OnEnter();
            m_trailerTemplateUpdated = false;
        }

        return;
    }

    /**
    * Stop the state machine.
    */
    void TADStateMachine::Stop()
    {
        if( m_state != nullptr )
        {
            m_state->OnExit();
            m_state = nullptr;
        }

        for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
        {
            memory::MemoryPool::ReleaseImage( m_trailerFeatures.TrailerData[i].trailerTemplate );
        }

        memory::MemoryPool::ReleaseImage( m_trailerCalibration.UnwarpedImage );
        memory::MemoryPool::ReleaseImage( m_trailerCalibration.trailerTemplate );
        m_isRunning = false;
    }

    /**
    * Run the state machine.
    */
    void TADStateMachine::Run( uint32_t i_frame, image::Image<uint8_t>& i_topView, _roi::ROI& i_roi, Detection_Inputs_from_TRSC_t StatemachineInput )

    {
        bool_t ret_val = true;

        if( ( m_state == nullptr ) || ( !m_isRunning ) )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            TAD2::Event e = { i_frame, i_topView, i_roi, m_trailerAngle_deg,
                              m_trailerAngleKnown, m_trailerTemplateUpdated, StatemachineInput
                            };
            Point2i x( 0, 0 );
            TAD2::Output o;
            o.detectedAngleValid = false;
            o.detectedCollisionAngleValid = false;
            o.detectedHitchPointValid = false;
            o.usingDummyHitchPoint = false;
            o.detectedAbsencePresenceValid = false;
            o.detectedBeamLengthValid = false;
            m_trailerPredictionCompleted = false;
            int32_t nextState = m_state->Process( e, o );
            ProcessOutput( o );

            // --- Check for state change
            if( nextState != m_state->GetEnum() )
            {
                m_state->OnExit();
                m_state = StateMap( nextState );

                if( m_state )
                {
                    m_state->OnEnter();
                }
            }

            m_trailerTemplateUpdated = false;
            ret_val = false;
        }

        return;
    }

    namespace pointstatemachine
    {
        static Point2i project( Point2i p, int32_t r, float32_t theta_deg )
        {
            float32_t theta_rad = mecl::math::toRadians_x( theta_deg );
            int32_t x = static_cast <int32_t>( static_cast <float32_t>( p.x ) + static_cast <float32_t>( r ) * mecl::math::trigonometry<float32_t>::cos_x( theta_rad ) );
            int32_t y = static_cast <int32_t>( static_cast <float32_t>( p.y ) + static_cast <float32_t>( r ) * mecl::math::trigonometry<float32_t>::sin_x( theta_rad ) );
            return Point2i( x, y );
        }
    }


    /*
    * Calculate the necessary region where all processing will be done, depending
    * on the current state, hitchpoint, and angle of the state machine.
    */
    _roi::ROI TADStateMachine::GetProcessingROI()
    {
        _roi::ROI ret_val;
        bool_t isReturned = true;
        // --- Get the hitch and angle range
        Point2i hitch_range[2];
        float32_t trailer_angle_range_deg[2];
        TeTRSC_e_TADState cur_state = GetState();
        int32_t template_radius = global::TEMPLATE_IMAGE_HEIGHT + m_warpedTopViewParams.yOffset;
        int32_t w = global::TOPVIEW_IMAGE_WIDTH;
        int32_t h = global::TOPVIEW_IMAGE_HEIGHT;
        TAD2::WarpedImage<uint8_t> warpedTrailerImage;
        warpedTrailerImage.setDegreesPixel( GetWarpedTopViewParams().degreesPerPixel );
        warpedTrailerImage.setRange_Deg( GetWarpedTopViewParams().range_deg );
        warpedTrailerImage.setStart_Deg( GetWarpedTopViewParams().start_deg );

        if( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::Idle ) )
        {
            ret_val = _roi::ROI( 0, 0, 0, 0 );
            isReturned = false;
        }
        else if( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::TrailerDetection ) )
        {
            ret_val = _roi::ROI( 0, 0, global::TOPVIEW_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT );
            isReturned = false;
        }
        else if( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::Calibration ) )
        {
            CalibrationState_t sub_state = m_stateCalibration.GetSubState();

            if( ( static_cast<int8_t>( sub_state ) == static_cast<int8_t>( TAD2::calibration::State::DriveStraight ) ) && !m_trailerCalibrated )
            {
                trailer_angle_range_deg[0] = 90.0f;
                trailer_angle_range_deg[1] = 90.0f;
                uint32_t hitch_x = m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchX();
                hitch_range[0] = Point2i( hitch_x, m_bumper_pos ); //PRQA S 3706
                hitch_range[1] = Point2i( hitch_x, m_hitchendrangePos ); //PRQA S 3706
            }
            else
            {
                trailer_angle_range_deg[0] = m_hitchCalibrationAngle + static_cast<float32_t>( trailer::c_steady_templateOffsets[0] ) * m_warpedTopViewParams.degreesPerPixel;
                trailer_angle_range_deg[1] = m_hitchCalibrationAngle + static_cast<float32_t>( trailer::c_steady_templateOffsets[trailer::c_steady_numTemplates - 1] ) * m_warpedTopViewParams.degreesPerPixel;
                uint32_t hitch_x = m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchX();
                hitch_range[0] = Point2i( hitch_x, m_bumper_pos ); /*PRQA S 3706*/
                hitch_range[1] = Point2i( hitch_x, m_hitchendrangePos ); /*PRQA S 3706*/
            }
        }
        else if( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::Turnaround ) )
        {
            trailer_angle_range_deg[0] = 90.0f + static_cast<float32_t>( trailer::c_dynamic_templateOffsets[0] ) * m_warpedTopViewParams.degreesPerPixel * 2.0f;
            trailer_angle_range_deg[1] = 90.0f + static_cast<float32_t>( trailer::c_dynamic_templateOffsets[trailer::c_dynamic_numTemplates - 1] ) * m_warpedTopViewParams.degreesPerPixel * 2.0f;
            uint32_t hitch_x = warpedTrailerImage.Angle2XPos( m_trailerAngle_deg );
            hitch_range[0] = Point2i( hitch_x, 0 ); /*PRQA S 3706*/
            hitch_range[1] = hitch_range[0];
            h = global::TEMPLATE_IMAGE_HEIGHT;
        }
        else if( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::AngleDetection ) )
        {
            trailer_angle_range_deg[0] = 90.0f + static_cast<float32_t>( trailer::c_dynamic_templateOffsets[0] ) * m_warpedTopViewParams.degreesPerPixel * 3.0f ;
            trailer_angle_range_deg[1] = 90.0f + static_cast<float32_t>( trailer::c_dynamic_templateOffsets[trailer::c_dynamic_numTemplates - 1] ) * m_warpedTopViewParams.degreesPerPixel * 3.0f;
            uint32_t hitch_x = warpedTrailerImage.Angle2XPos( m_trailerAngle_deg );
            hitch_range[0] = Point2i( hitch_x, 0 ); /*PRQA S 3706*/
            hitch_range[1] = hitch_range[0];
            h = global::TEMPLATE_IMAGE_HEIGHT;
        }
        else if( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::TrailerRecognition ) )
        {
            trailer_angle_range_deg[0] = m_warpedTopViewParams.start_deg + m_warpedTopViewParams.range_deg;
            trailer_angle_range_deg[1] = m_warpedTopViewParams.start_deg;
            uint32_t hitch_x = m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchX();
            hitch_range[0] = Point2i( hitch_x, 0 ); /*PRQA S 3706*/
            hitch_range[1] = hitch_range[0];
        }
        else if( ( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::ScanningForTrailer ) ) || ( static_cast<int8_t>( cur_state ) == static_cast<int8_t>( TAD2::State::Trackinglost ) ) /*|| (cur_state == TAD2::State::TrailerRecognition)*/ )
        {
            trailer_angle_range_deg[0] = m_warpedTopViewParams.start_deg + m_warpedTopViewParams.range_deg;
            trailer_angle_range_deg[1] = m_warpedTopViewParams.start_deg;
            uint32_t hitch_x = m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchX();
            hitch_range[0] = Point2i( hitch_x, 0 ); /*PRQA S 3706*/
            hitch_range[1] = hitch_range[0];
            h = global::TEMPLATE_IMAGE_HEIGHT;
        }
        else
        {
            trailer_angle_range_deg[0] = m_warpedTopViewParams.start_deg + m_warpedTopViewParams.range_deg;
            trailer_angle_range_deg[1] = m_warpedTopViewParams.start_deg;
        }

        if( isReturned )
        {
            //
            // --- Get the boundaries of the roi
            int32_t margin = 3;
            float32_t template_range_deg = static_cast<float32_t>( global::TEMPLATE_IMAGE_WIDTH ) * m_warpedTopViewParams.degreesPerPixel;
            float32_t total_angle_range_deg[2] = { trailer_angle_range_deg[0] - ( template_range_deg / 2.0f ) , trailer_angle_range_deg[1] + ( template_range_deg / 2.0f ) };
            int32_t top;
            int32_t bottom;
            int32_t left;
            int32_t right;
            //
            Point2i p1 = pointstatemachine::project( hitch_range[0], template_radius, total_angle_range_deg[0] );
            Point2i p2 = pointstatemachine::project( hitch_range[0], template_radius, total_angle_range_deg[1] );
            Point2i p3 = pointstatemachine::project( hitch_range[1], template_radius, total_angle_range_deg[0] );
            Point2i p4 = pointstatemachine::project( hitch_range[1], template_radius, total_angle_range_deg[1] );

            // top
            if( ( total_angle_range_deg[0] <= 270.0f ) && ( 270.0f <= total_angle_range_deg[1] ) )
            {
                top = hitch_range[0].y - template_radius;
            }
            else
            {
                top = mms::minimum( p1.y, p2.y );
            }

            // bottom
            if( ( total_angle_range_deg[0] <= 90.0f ) && ( 90.0f <= total_angle_range_deg[1] ) )
            {
                bottom = hitch_range[1].y + template_radius;
            }
            else
            {
                bottom = mms::maximum( p3.y, p4.y );
            }

            // left
            if( ( total_angle_range_deg[0] <= 180.0f ) && ( 180.0f <= total_angle_range_deg[1] ) )
            {
                left = hitch_range[0].x - template_radius;
            }
            else
            {
                left = mms::minimum( p1.x, p2.x );
            }

            // right
            if( ( total_angle_range_deg[0] <= 0.0f ) && ( 0.0f <= total_angle_range_deg[1] ) )
            {
                right = hitch_range[0].x + template_radius;
            }
            else
            {
                right = mms::maximum( p1.x, p2.x );
            }

            top = mms::maximum( 0, mms::minimum( top, hitch_range[0].y ) - margin );
            bottom = mms::minimum( h, mms::maximum( bottom, hitch_range[1].y ) + margin );
            left = mms::maximum( 0, mms::minimum( left, hitch_range[0].x ) - margin );
            right = mms::minimum( w, mms::maximum( right, hitch_range[1].x ) + margin );
            ret_val = _roi::ROI( left, top, right - left, bottom - top );
        }

        return ret_val;
    }

    /**
    * Return whether kinematics are enabled.
    */
    bool_t TADStateMachine::KinematicsEnabled() const
    {
        return m_config.getCanAndVehicleConfigParams().getKinematics();
    }

    /**
    * Return whether collision angle is to be calculated.
    */
    bool_t TADStateMachine::CollisonAngleDetectionEnabled() const
    {
        return m_config.getCollisionAngleDetectionConfigParamsRef().getEnabled();
    }
    /**
    * Return config hitch x and y point
    */
    Point2i TADStateMachine::Get_hitch_Config_Point() const
    {
        return Point2i( m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchX(), m_hitchendrangePos ); //PRQA S 3706
    }
    /**
    * Return config hitch x and y point
    */
    float32_t TADStateMachine::Get_averageillumination() const
    {
        return m_averageIllumination;
    }
    /**
    * Set hitch X pos
    */
    void TADStateMachine::Set_averageillumination( float32_t val )
    {
        m_averageIllumination = val;
    }
    /*
    * Finds the average illumination of given image
    */
    float32_t TADStateMachine::FindAverageIllumination( image::Image<uint8_t>& i_warpedview, _roi::ROI& i_roi )
    {
        float32_t avgValue = 0.0f;
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

    /**
    * Set hitch X pos
    */
    void TADStateMachine::Set_confighitchXpos( uint32_t val ) const
    {
        m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().setHitchX( val );
    }

    /**
    * Set bumper pos
    */
    void TADStateMachine::Set_configbumperpos( uint32_t val ) const
    {
        m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().setHitchYOffset_bumperRef( val );
    }

    /**
    * Return whether the state machine is currently running.
    */
    bool_t TADStateMachine::IsRunning() const
    {
        return m_isRunning;
    }



    /**
    * Get vehicle parameters.
    */
    const TAD2::VehicleParameters& TADStateMachine::GetVehicleParams() const
    {
        return m_vehicleParams;
    }

    /**
    * Get the parameters used to warp the topview.
    */
    const TAD2::WarpedTopViewParameters& TADStateMachine::GetWarpedTopViewParams() const
    {
        return m_warpedTopViewParams;
    }

    /**
    * Get vehicle config data.
    */
    tad2config::CANAndVehicleConfigData TADStateMachine::GetVehicleConfigData()
    {
        return m_config.getCanAndVehicleConfigParams();
    }

    /**
    * Return whether the trailer angle is knwon.
    */
    bool_t TADStateMachine::IsTrailerAngleKnown() const
    {
        return m_trailerAngleKnown;
    }
    /**
    * set the implicit calibration running flag in Tracking lost
    */
    void TADStateMachine::SetImplicitTrackingLostFlag( bool_t running )
    {
        m_stateAngleDetection.Setimplicitcalbration( running );
    }
    /**
    * set the Calibration fail count
    */
    void TADStateMachine::SetCalibrationFailCount( uint32_t count )
    {
        m_calibrationFailCount = count;
    }
    /**
    * set the Calibration fail count
    */
    void TADStateMachine::SetCalibrationFailReason( TrailerCalibrationFailInfo_t i_TrailerCalFailInfo )
    {
        TrailerCalFailInfo = i_TrailerCalFailInfo;
    }
    /**
    * set the Calibration data reset
    */
    void TADStateMachine::SetCalibrationDataReset()
    {
        memset( m_trailerCalibration.trailerTemplate.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
        m_trailerCalibration.Is_Valid = false;
        m_trailerCalibration.UsedCount = 0;
        m_trailerCalibration.hitchPointValid = false;
        m_trailerCalibration.hitchPoint.x = 0;
        m_trailerCalibration.hitchPoint.y = 0;
        m_trailerCalibration.HitchLength = 0;
        m_trailerCalibration.CollisionAngleValid = false;
        m_trailerCalibration.CollisionAngle = 0;
        m_trailerCalibration.AbsencePresenceValid = false;
        m_trailerCalibration.Trailer_Present = false;
        m_trailerCalibration.beamlengthValid = false;
        m_trailerCalibration.BeamLength = 0.0f;
        m_trailerCalibration.JacknifeAngle = 0;
        m_trailerCalibration.JacknifeThreshAngle = 0;
        m_hitchCalibrated = false;
        m_trailerCalibrated = false;
    }

    /**
    * set the trailer absence algo detected
    */
    void TADStateMachine::SetTrailerPresenceDetectionDone( bool_t _iscomplete )
    {
        m_trailerPresenceDetectionDone = _iscomplete;
    }
    /**
    * Return the trailer absence algo detected
    */
    bool_t TADStateMachine::GetTrailerPresenceDetectionDone() const
    {
        return m_trailerPresenceDetectionDone;
    }

    /**
    * set the angle buffer to the set value
    */
    void TADStateMachine::SetAnlgeBuffer( float32_t angle )
    {
        m_stateAngleDetection.SetAngleBuffer( angle );
    }
    /**
    * Return whether the collision angle is knwon.
    */
    bool_t TADStateMachine::IsCollisionAngleKnown() const
    {
        return m_collisionAngleKnown;
    }

    /**
    * Return whether the trailer template was loaded successfully on start.
    *
    * Determines whether or not we will calibrate a new template.
    */
    bool_t TADStateMachine::WasTrailerLoadedSuccessfully() const
    {
        return m_trailerLoadedSuccessfully;
    }

    /**
    * Return whether the hitchpoint was loaded successfully on start.
    *
    * Determines whether or not we will calibrate a new hitchpoint.
    */
    bool_t TADStateMachine::WasHitchLoadedSuccessfully() const
    {
        return m_hitchLoadedSuccessfully;
    }
    /**
    * Return whether the collision angle was loaded successfully on start.
    *
    */
    bool_t TADStateMachine::WascollisionangleLoadedSuccessfully() const
    {
        return m_collisionangleLoadedSuccessfully;
    }

    /**
    * Return whether trailer detection has been completed.
    */
    bool_t TADStateMachine::IsTrailerDetectionComplete() const
    {
        return m_trailerDetectionComplete;
    }

    /**
    * Return whether trailer detection has been completed.
    */
    bool_t TADStateMachine::Get_IsTrailerAngleUpdating() const
    {
        return m_IsTrailerAngleUpdating;
    }
    /**
    * Return whether trailer angle updation is happening
    */
    void TADStateMachine::Set_IsTrailerAngleUpdating( bool_t _isUpdating )
    {
        m_IsTrailerAngleUpdating = _isUpdating;
    }

    /**
    * Return Input Trailer ID
    */
    int32_t TADStateMachine::GetInputTrailerID() const
    {
        return InputTrailerID;
    }

    /**
    * Return Trailer Pass Count
    */
    int32_t TADStateMachine::GetTrailerPassCount()
    {
        int32_t PassCount = 0;

        for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
        {
            if( m_trailerFeatures.TrailerData[i].Is_Valid )
            {
                PassCount++;
            }
        }

        return PassCount;
    }
    
    /**
    * Return Config Trailer ID
    */
    int32_t TADStateMachine::GetConfigTrailerID() const
    {
        return ConfigTrailerID;
    }

    /**
    * Return whether to calibrate trailer or not
    */
    bool_t TADStateMachine::CalibrateTrailer() const
    {
        return m_CalibrateTrailer;
    }

    /**
    * Return whether the trailer is present (only valid if 'IsTrailerDetectionComplete()' returns true).
    */
    bool_t TADStateMachine::IsTrailerPresent() const
    {
        return m_trailerDetected;
    }

    /**
    * Return whether the trailer is present during recognition state
    */
    bool_t TADStateMachine::IsTrailerPresentRecognitionState() const
    {
        return m_trailerDetectedrecognitionstate;
    }

    /**
    * Return whether the trailer has been calibrated.
    */
    bool_t TADStateMachine::IsTrailerCalibrated() const
    {
        return m_trailerCalibrated;
    }

    /**
    * Return whether the hitch has been calibrated.
    */
    bool_t TADStateMachine::IsHitchCalibrated() const
    {
        return m_hitchCalibrated;
    }
    /**
    * Return true if currently calibrating the trailer.
    */
    bool_t TADStateMachine::IsCalibratingTrailer() const
    {
        bool_t isdrivestraight = ( static_cast<int8_t>( GetSubState() ) == static_cast<int8_t>( TAD2::calibration::State::DriveStraight ) );
        return ( ( static_cast<TAD2::State::Enum>( GetState() ) == TAD2::State::Calibration ) && isdrivestraight );
    }
    /**
    * Return true if current state is Tracking Lost
    */
    bool_t TADStateMachine::IsTrackingLostRunning() const
    {
        return static_cast<int8_t>( GetState() ) == static_cast<int8_t>( TAD2::State::Trackinglost );
    }
    /**
    * Return true if currently calibrating the hitch.
    */
    bool_t TADStateMachine::IsCalibratingHitch() const
    {
        bool_t isdrivestraight = ( static_cast<int8_t>( GetSubState() ) != static_cast<int8_t>( TAD2::calibration::State::DriveStraight ) );
        return ( ( static_cast<TAD2::State::Enum>( GetState() ) == TAD2::State::Calibration ) && isdrivestraight );
    }

    bool_t TADStateMachine::IsTurnaroundComplete() const
    {
        return m_turnaroundComplete;
    }
    bool_t TADStateMachine::IsBeamLenghtEstimationDone() const
    {
        return m_beamLengthEstimationDone;
    }

    bool_t TADStateMachine::IsTrailerImplicitlyCalibrated() const
    {
        return m_trailerImplicitlyCalibrated;
    }

    bool_t TADStateMachine::IsTurncompletedduringTurnAroundState() const
    {
        return m_turnCompletedDuringTurnAroundState;
    }
    bool_t TADStateMachine::IsTrailerPrecitionCompleted() const
    {
        return m_trailerPredictionCompleted;
    }

    /**
    * set the Calibration fail count
    */
    uint32_t TADStateMachine::GetCalibrationFailCount() const
    {
        return m_calibrationFailCount;
    }
    /**
    * set the Calibration fail count
    */
    TrailerCalibrationFailInfo_e TADStateMachine::GetCalibrationFailReason() const
    {
        return TrailerCalFailInfo;
    }

    /*
    * Get current Trailer ID
    */
    TrailerID_t TADStateMachine::GetCurrentTraielrID() const
    {
        return CurrentTrailer_ID;
    }

    /**
    * Get the current trailer angle.
    */
    float32_t TADStateMachine::GetTrailerAngle_deg()
    {
        if( !m_trailerAngleKnown )
        {
            m_trailerAngle_deg = -0.0f;
        }

        return m_trailerAngle_deg;
    }

    /**
    * Get the current trailer angle score.
    */
    float32_t TADStateMachine::GetTrackingScore() const
    {
        return m_trackingScore;
    }
    /**
    * Get the hitch range valide
    */
    float32_t TADStateMachine::GetHitchrangevalid() const
    {
        return m_hitchrangevalid;
    }
    /**
    * Get the hitch range valide
    */
    float32_t TADStateMachine::GetBeamLength() const
    {
        return m_trailerCalibration.BeamLength;
    }
    /**
    * Get the hitch Length
    */
    uint32_t TADStateMachine::GetHitchLength() const
    {
        return m_trailerCalibration.HitchLength;
    }
    /**
    * Get the Jacknife thresholdAngle
    */
    uint32_t TADStateMachine::GetJacknifeThresAngle() const
    {
        return m_trailerCalibration.JacknifeThreshAngle;
    }

    /**
    * Get the hitch range valide
    */
    float32_t TADStateMachine::GetJacknifeAngle() const
    {
        return m_trailerCalibration.JacknifeAngle;
    }

    /**
    * Get the Pixel2mm Conversion
    */
    float32_t TADStateMachine::GetPixel2mmconversion() const
    {
        return m_Pixel2mmconversionval;
    }

    /**
    * Get score from the most recent scan.
    */
    float32_t TADStateMachine::GetScanningScore() const
    {
        return m_scanningScore;
    }

    /**
    * Get the collision angle.
    */
    float32_t TADStateMachine::GetCollisionAngle_deg() const
    {
        return m_collisionAngle;
    }
    /**
    * Get the left collision angle.
    */
    float32_t TADStateMachine::GetleftCollisionAngle_deg() const
    {
        return m_leftcollisionangle;
    }
    /**
    * Get the right collision angle.
    */
    float32_t TADStateMachine::GetrightCollisionAngle_deg() const
    {
        return m_rightcollisionangle;
    }
    /**
    * Get the current trailer calibration.
    */
    TAD2::TrailerFeatures TADStateMachine::GetTrailerFeatures() const
    {
        return m_trailerFeatures;
    }
    /**
    * Get original trailer unwarped trailer template
    */
    TAD2::TrailerFeatures::Trailers TADStateMachine::GettrailerCalibration() const
    {
        return m_trailerCalibration;
    }
    /**
    * Get unwapredTrailer Template
    */
    image::Image<uint8_t> TADStateMachine::GetUnwarpedTrailerTemplate() const
    {
        return m_trailerCalibration.UnwarpedImage;
    }
    /**
    * Get the current trailer template.
    */
    TAD2::TrailerTemplate TADStateMachine::GetTrailerTemplate() const
    {
        return m_trailerCalibration.trailerTemplate;
    }
    /**
    * Set the trailer template.
    */
    void TADStateMachine::SetTrailerTemplate( image::Image<uint8_t> i_templates )
    {
        if( m_trailerCalibration.trailerTemplate.getData() == NULL )
        {
            m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
        }

        memcpy( m_trailerCalibration.trailerTemplate.getData(), i_templates.getData(), global::TEMPLATE_IMAGE_SIZE );
    }
    /**
    * Set the current trailer template.
    */
    void TADStateMachine::SetTrailerTemplatefeatures( TAD2::TrailerFeatures::Trailers i_features )
    {
        if( m_trailerCalibration.trailerTemplate.getData() == NULL )
        {
            m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
        }

        memcpy( m_trailerCalibration.trailerTemplate.getData(), i_features.trailerTemplate.getData(), global::TEMPLATE_IMAGE_SIZE );
        m_trailerCalibration.Is_Valid = i_features.Is_Valid;
        m_trailerCalibration.hitchPointValid = i_features.hitchPointValid;
        m_trailerCalibration.hitchPoint = i_features.hitchPoint;
        m_trailerCalibration.HitchLength = i_features.HitchLength;
        m_trailerCalibration.CollisionAngleValid = i_features.CollisionAngleValid;
        m_trailerCalibration.CollisionAngle = i_features.CollisionAngle;
        m_trailerCalibration.beamlengthValid = i_features.beamlengthValid;
        m_trailerCalibration.BeamLength = i_features.BeamLength;
        m_trailerCalibration.JacknifeAngle = i_features.JacknifeAngle;
        m_trailerCalibration.JacknifeThreshAngle = i_features.JacknifeThreshAngle;
        m_trailerCalibration.Trailer_ID = i_features.Trailer_ID;
        m_trailerCalibration.UsedCount = i_features.UsedCount;
    }
    /**
    * Set trailer used count
    */
    void TADStateMachine::SetTrailerUsedCount( uint32_t i_trailerCount )
    {
        for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
        {
            if( m_trailerFeatures.TrailerData[i].Is_Valid )
            {
                if( i == i_trailerCount )
                {
                    m_trailerFeatures.TrailerData[i].UsedCount += 1;
                }
                else
                {
                    m_trailerFeatures.TrailerData[i].UsedCount -= 1;
                }
            }
        }
    }

    /**
    * Get hitch-point.
    */
    Point2i TADStateMachine::GetHitchPoint()
    {
        Point2i ret_val;

        if( m_trailerCalibration.hitchPointValid )
        {
            ret_val = m_trailerCalibration.hitchPoint;
        }
        else
        {
            SetError( 3, "Requested hitchpoint before calibrated." );
            ret_val = Point2i();
        }

        return ret_val;
    }

    /**
    * Get the calibrating angles output by the calibration state.
    */
    void TADStateMachine::GetCalibrationAngles( float32_t& o_left, float32_t& o_right ) const
    {
        o_left = m_leftCalibrationAngle;
        o_right = m_rightCalibrationAngle;
    }

    /**
    * Get the calibrating angle output by the hitch detection module.
    */
    float32_t TADStateMachine::GetHitchCalibrationAngle() const
    {
        return m_hitchCalibrationAngle;
    }

    /**
    * Get the hitch range pos
    */
    uint8_t TADStateMachine::GetHitchrangePos() const
    {
        return m_hitch_pos;
    }
    /**
    * Get the bumper pos
    */
    uint32_t TADStateMachine::GetbumperPos() const
    {
        return m_bumper_pos;
    }
    /**
    * Get the hitch end range pos
    */
    uint32_t TADStateMachine::GethitchendrangePos() const
    {
        return m_hitchendrangePos ;
    }
    /**
    * Get the hitch range pos
    */
    bool_t TADStateMachine::IsHitchrangcalculationdone() const
    {
        return m_hitch_range_calculated;
    }

    /**
    * Get the dummy angle 1
    */
    float32_t TADStateMachine::GetDummyAngle1() const
    {
        return m_dummy_angle_1;
    }

    /**
    * Get the dummy angle 2
    */
    float32_t TADStateMachine::GetDummyAngle2() const
    {
        return m_dummy_angle_2;
    }

    /**
    * Get the dummy angle 1
    */
    float32_t TADStateMachine::GetDummyAngle3() const
    {
        return m_dummy_angle_3;
    }

    /**
    * Get the dummy angle 1
    */
    float32_t TADStateMachine::GetDummyAngle4() const
    {
        return m_dummy_angle_4;
    }

    /**
    * Return the current state (as an enum).
    */
    TeTRSC_e_TADState TADStateMachine::GetState() const
    {
        TeTRSC_e_TADState ret_val;

        if( m_state )
        {
            ret_val = static_cast<TeTRSC_e_TADState>( m_state->GetEnum() );
        }
        else
        {
            ret_val = TeTRSC_e_TADState::TeTRSC_e_TADState_Idle;
        }

        return ret_val;
    }

    /**
    * Return the current states substate if it exists, else return 0.
    */
    CalibrationState_t TADStateMachine::GetSubState() const
    {
        CalibrationState_t ret_val;
        bool_t iscalirationstate = m_state->GetEnum() == TeTRSC_e_TADState::TeTRSC_e_TADState_Calibration;

        if( static_cast<bool_t>( m_state ) && iscalirationstate )
        {
            //Calibration State is the only state with sub states, adding virtual getters to all other states not recommended
            ret_val = dynamic_cast<Calibration::CalibrationState*>( m_state )->GetSubState(); //PRQA S 3077
        }
        else
        {
            ret_val = CalibrationState_t::CalibrationState_Wait;
        }

        return ret_val;
    }
    /**
    * Return the current states of TurnAround substate if it exists, else return 0.
    */
    TurnAroundState_t TADStateMachine::GetTurnAroundSubState() const
    {
        TurnAroundState_t ret_val;
        bool_t isturnaroundstate = m_state->GetEnum() == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround;

        if( static_cast<bool_t>( m_state ) && isturnaroundstate )
        {
            //Calibration State is the only state with sub states, adding virtual getters to all other states not recommended
            ret_val = dynamic_cast<TurnAround::TurnaroundState*>( m_state )->GetSubState(); //PRQA S 3077
        }
        else
        {
            ret_val = TurnAroundState_t::TurnAroundState_Wait;
        }

        return ret_val;
    }

    float32_t TADStateMachine::GetVehicleSpeed() const
    {
        return m_pVehicle->currentSpeed_mps();
    }

    /*
    * Set the calibrated unwarped image used to extract the trailer template.
    */
    void TADStateMachine::SetCalibratedunwarpedTrailerImage( const image::Image<uint8_t>& i_trailerImage )
    {
        bool_t ret_val = true;

        if( ( i_trailerImage.getWidth() > global::TOPVIEW_IMAGE_WIDTH ) || ( i_trailerImage.getHeight() > global::TOPVIEW_IMAGE_HEIGHT ) )
        {
            m_pAlgoObj->SetError( 3, "Couldn't load trailer calibration. Image size too large." );
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_trailerCalibration.UnwarpedImage.getData() == NULL )
            {
                m_trailerCalibration.UnwarpedImage = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            }

            processing::ImageProcessing::Copy( i_trailerImage, m_trailerCalibration.UnwarpedImage );
            m_trailerCalibration.Is_Valid = true;

            if( !m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getEnabled() && !m_config.getTrailerRecognitionConfigParamsRef().getEnabled() )
            {
                m_trailerCalibration.hitchPoint = m_config.getDefaultHitchPointRef();
                SetCalculateHitchLength( m_trailerCalibration.hitchPoint.y );
                m_trailerCalibration.hitchPointValid = true;
                m_hitchLoadedSuccessfully = m_trailerCalibration.hitchPointValid;
            }

            UpdateWarpedTemplate();
            UpdateTrailerTemplate();
        }

        return;
    }
    /*
    * Set the calibrated image used to extract the trailer template.
    */
    void TADStateMachine::SetCalibratedTrailerImage( const image::Image<uint8_t>& i_trailerImage )
    {
        bool_t ret_val = true;

        if( ( i_trailerImage.getWidth() > global::TEMPLATE_IMAGE_WIDTH ) || ( i_trailerImage.getHeight() > global::TEMPLATE_IMAGE_HEIGHT ) )
        {
            m_pAlgoObj->SetError( 3, "Couldn't load trailer calibration. Image size too large." );
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_trailerCalibration.trailerTemplate.getData() == NULL )
            {
                m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            }

            processing::ImageProcessing::Copy( i_trailerImage, m_trailerCalibration.trailerTemplate );
            m_trailerCalibration.Is_Valid = true;
        }

        return;
    }

    /*
    * Set trailer detection to complete.
    */
    void TADStateMachine::SetTrailerDetectionComplete( bool_t is_complete )
    {
        m_trailerDetectionComplete = is_complete;
    }

    void TADStateMachine::SetTurnaroundComplete()
    {
        m_turnaroundComplete = true;
    }
    void TADStateMachine::ResetTurnaroundState()
    {
        m_turnaroundComplete = false;
    }
    void TADStateMachine::ResetCalibrationState()
    {
        m_trailerCalibration.Is_Valid = false;
        m_trailerCalibration.hitchPointValid = false;
        m_hitchLoadedSuccessfully = false;

        if( ( !m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getEnabled() ) && ( !m_config.getTrailerRecognitionConfigParamsRef().getEnabled() ) )
        {
            m_trailerCalibration.hitchPoint = m_config.getDefaultHitchPointRef();
            SetCalculateHitchLength( m_trailerCalibration.hitchPoint.y );
            m_trailerCalibration.hitchPointValid = true;
            m_hitchLoadedSuccessfully = m_trailerCalibration.hitchPointValid;
        }
    }

    void TADStateMachine::SetBeamLengthEstimationDone()
    {
        m_beamLengthEstimationDone = true;
    }

    void TADStateMachine::SetCalculateHitchLength( uint32_t hitchYpos )
    {
        m_trailerCalibration.HitchLength = ( uint32_t )( m_vehicleParams.rearOverhang_mm + ( ( float32_t )( hitchYpos - m_bumper_pos ) * GetPixel2mmconversion() ) );
#if DEBUG_HITCH_POINT
        printf( "TAD2: rOvrHng: %f, htcPos: %d, bmprPos: %d, Pxl2mm: %f\n", m_vehicleParams.rearOverhang_mm, hitchYpos, m_bumper_pos, GetPixel2mmconversion() );
#endif
    }

    void TADStateMachine::SetTurnCompletedDuringTurnAround( bool_t i_turncompleted )
    {
        m_turnCompletedDuringTurnAroundState = i_turncompleted;
    }

    /*
    * Set Prediction Completed.
    */
    void TADStateMachine::SetTrailerPredictionCompleted()
    {
        m_trailerPredictionCompleted = true;
    }

    /*
    * Set whether trailer is detected.
    */
    void TADStateMachine::SetTrailerDetected( bool_t i_trailerDetected )
    {
        m_trailerDetected = i_trailerDetected;
    }

    /*
    * Set whether trailer is detected during recognition state.
    */
    void TADStateMachine::SetTrailerDetectedRecognitionState( bool_t i_trailerDetected )
    {
        m_trailerDetectedrecognitionstate = i_trailerDetected;
    }

    /*
    * Set trailer calibrated flag to true.
    */
    void TADStateMachine::SetTrailerCalibrated()
    {
        m_trailerCalibrated = true;
    }

    /*
    * Set hitch calibrated flag to true.
    */
    void TADStateMachine::SetHitchCalibrated()
    {
        m_hitchCalibrated = true;
    }

    void TADStateMachine::SetTrailerImplicitlyCalibrated()
    {
        m_trailerImplicitlyCalibrated = true;
    }
    void TADStateMachine::ResetTrailerImplicitlyCalibrated()
    {
        m_trailerImplicitlyCalibrated = false;
    }

    /*
    * Set the current trailer angle. Will restart the angle detection state if
    * that was the current state.
    */
    void TADStateMachine::SetTrailerAngle( float32_t i_trailerAngle )
    {
        m_trailerAngle_deg = i_trailerAngle;
        m_trailerAngleKnown = true;
        // Can't do the same to turnaround state: turnaround will do beam length cali again.
        // changed logic in the states instead, so that the state checks if lowlevel trailerTracking angle = high level angle.
    }

    /*
    * Set the scanning score.
    */
    void TADStateMachine::SetScanningScore( float32_t i_score )
    {
        m_scanningScore = i_score;
    }

    /*
    * Set the collision angle of the trailer.
    */
    void TADStateMachine::SetCollisionAngle( float32_t i_collisionAngle, float32_t i_leftcollisionangle, float32_t i_rightcollisionangle )
    {
        m_collisionAngle = i_collisionAngle;
        m_leftcollisionangle = i_leftcollisionangle;
        m_rightcollisionangle = i_rightcollisionangle;
        m_collisionAngleKnown = true;
    }

    /*
    * Set the calibrating angles output by the calibration state.
    */
    void TADStateMachine::SetCalibrationAngles( float32_t i_left, float32_t i_right )
    {
        m_leftCalibrationAngle = i_left;
        m_rightCalibrationAngle = i_right;
    }

    /**
    * Set the calibrating angle output by the hitch detection module.
    */
    void TADStateMachine::SetHitchCalibrationAngle( float32_t i_angle )
    {
        m_hitchCalibrationAngle = i_angle;
    }
    /**
    * Set temp hitch pos
    */
    void TADStateMachine::SetTempHitchPos( Point2i hitchPos, bool_t i_valid )
    {
        m_temphitch_pos = hitchPos;
        m_trailerCalibration.hitchPoint = m_temphitch_pos;
        m_trailerCalibration.hitchPointValid = i_valid;
    }
    /**
    * Set the hitch pos
    */
    void TADStateMachine::SetHitchPos( uint8_t Pos )
    {
        m_hitch_pos = Pos;
    }
    /**
    * Set the bumper pos
    */
    void TADStateMachine::SetbumperPos( uint32_t Pos )
    {
        m_bumper_pos = Pos;
        m_hitchendrangePos = m_bumper_pos + ( m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchYOffsetRef()[1] - m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchYOffsetRef()[0] );//PRQA S 3706
    }
    /**
    * Set the hitch range done
    */
    void TADStateMachine::SetHitchrangecalculated( bool_t val )
    {
        m_hitch_range_calculated = val;
    }

    /**
    * Set the dummy angle.
    */
    void TADStateMachine::SetDummyAngle( float32_t i_angle1, float32_t i_angle2, float32_t i_angle3, float32_t i_angle4 )
    {
        m_dummy_angle_1 = i_angle1;
        m_dummy_angle_2 = i_angle2;
        m_dummy_angle_3 = i_angle3;
        m_dummy_angle_4 = i_angle4;
    }

    /*
    * Send an error with message to the algo object.
    */
    void TADStateMachine::SetCurrentTraielrID( TrailerID_t i_CurrentTrailer_ID )
    {
        CurrentTrailer_ID = i_CurrentTrailer_ID;
    }

    /*
    * Send an error with message to the algo object.
    */
    void TADStateMachine::SetError( int32_t i_error, const char* i_errorMessage )
    {
        m_isRunning = m_isRunning;  //added the line for resolving MISRA 4212
        m_pAlgoObj->SetError( i_error, i_errorMessage );
    }

    /**
    * Load calibration for this state machine.
    */
    void TADStateMachine::LoadCalibration( TAD2::TrailerFeatures& i_trailerFeatures )
    {
        bool_t ret_val = true;

        if( !m_isRunning )
        {
            ret_val = false;
        }

        m_trailerLoadedSuccessfully = false;
        m_hitchLoadedSuccessfully = false;
        m_collisionangleLoadedSuccessfully = false;
        m_beamLengthLoadedSuccessfully = false;

        if( ret_val )
        {
            TrailerID_t TrailerID;

            // -- Load the Features
            for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
            {
                // template
                if( m_trailerFeatures.TrailerData[i].trailerTemplate.getData() == NULL )
                {
                    m_trailerFeatures.TrailerData[i].Is_Valid = false;
                    m_trailerFeatures.TrailerData[i].trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
                    memset( m_trailerFeatures.TrailerData[i].trailerTemplate.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
                    m_trailerFeatures.TrailerData[i].hitchPointValid = false;
                    m_trailerFeatures.TrailerData[i].hitchPoint.x = 0;
                    m_trailerFeatures.TrailerData[i].hitchPoint.y = 0;
                    m_trailerFeatures.TrailerData[i].HitchLength = 0;
                    m_trailerFeatures.TrailerData[i].CollisionAngleValid = false;
                    m_trailerFeatures.TrailerData[i].CollisionAngle = 0;
                    m_trailerFeatures.TrailerData[i].beamlengthValid = false;
                    m_trailerFeatures.TrailerData[i].BeamLength = 0.0f;
                    m_trailerFeatures.TrailerData[i].JacknifeAngle = 0;
                    m_trailerFeatures.TrailerData[i].JacknifeThreshAngle = 0;
                    m_trailerFeatures.TrailerData[i].UsedCount = 0;
                    m_trailerFeatures.TrailerData[i].Trailer_ID = static_cast<TrailerID_t>( i );
                }

                if( i_trailerFeatures.TrailerData[i].trailerTemplate.getData() != NULL )
                {
                    processing::ImageProcessing::Copy( i_trailerFeatures.TrailerData[i].trailerTemplate, m_trailerFeatures.TrailerData[i].trailerTemplate );
                    m_trailerFeatures.TrailerData[i].Is_Valid = i_trailerFeatures.TrailerData[i].Is_Valid;
                    m_trailerFeatures.TrailerData[i].hitchPointValid = i_trailerFeatures.TrailerData[i].hitchPointValid;
                    m_trailerFeatures.TrailerData[i].hitchPoint = i_trailerFeatures.TrailerData[i].hitchPoint;
                    m_trailerFeatures.TrailerData[i].HitchLength = i_trailerFeatures.TrailerData[i].HitchLength;
                    m_trailerFeatures.TrailerData[i].CollisionAngleValid = i_trailerFeatures.TrailerData[i].CollisionAngleValid;
                    m_trailerFeatures.TrailerData[i].CollisionAngle = i_trailerFeatures.TrailerData[i].CollisionAngle;
                    m_trailerFeatures.TrailerData[i].beamlengthValid = i_trailerFeatures.TrailerData[i].beamlengthValid;
                    m_trailerFeatures.TrailerData[i].BeamLength = i_trailerFeatures.TrailerData[i].BeamLength;
                    m_trailerFeatures.TrailerData[i].JacknifeAngle = i_trailerFeatures.TrailerData[i].JacknifeAngle;
                    m_trailerFeatures.TrailerData[i].JacknifeThreshAngle = i_trailerFeatures.TrailerData[i].JacknifeThreshAngle;
                    m_trailerFeatures.TrailerData[i].UsedCount = i_trailerFeatures.TrailerData[i].UsedCount;
                    m_trailerFeatures.TrailerData[i].Trailer_ID = static_cast<TrailerID_t>( i );
                }
            }

            // Initialize memory for Trailer Template
            if( m_trailerCalibration.trailerTemplate.getData() == NULL )
            {
                m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
                memset( m_trailerCalibration.trailerTemplate.getData(), 0, global::TEMPLATE_IMAGE_SIZE );
                m_trailerCalibration.Is_Valid = false;
                m_trailerCalibration.UsedCount = 0;
                m_trailerCalibration.hitchPointValid = false;
                m_trailerCalibration.hitchPoint.x = 0;
                m_trailerCalibration.hitchPoint.y = 0;
                m_trailerCalibration.HitchLength = 0;
                m_trailerCalibration.CollisionAngleValid = false;
                m_trailerCalibration.CollisionAngle = 0;
                m_trailerCalibration.AbsencePresenceValid = false;
                m_trailerCalibration.Trailer_Present = false;
                m_trailerCalibration.beamlengthValid = false;
                m_trailerCalibration.BeamLength = 0.0f;
                m_trailerCalibration.JacknifeAngle = 0;
                m_trailerCalibration.JacknifeThreshAngle = 0;
            }

            // --- Attempt to load hitch-point
            if( !m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getEnabled() && !m_config.getTrailerRecognitionConfigParamsRef().getEnabled() )
            {
                m_trailerCalibration.hitchPoint = m_config.getDefaultHitchPointRef();
                SetCalculateHitchLength( m_trailerCalibration.hitchPoint.y );
                m_trailerCalibration.hitchPointValid = true;
                m_hitchLoadedSuccessfully = m_trailerCalibration.hitchPointValid;
            }
        }

        return;
    }
    /*
    * Update the trailer template used in template matching.
    */
    void TADStateMachine::Set_NewTrailerFeatures( TAD2::TrailerTemplate i_trailerTemplate, Point2i i_hitch_point, uint32_t i_CollisionAngle, float32_t i_BeamLength, uint32_t i_JacknifeAngle, uint32_t i_jacknifethreshAngle )
    {
        int32_t minCount = 100000;
        int32_t max_count = -100000;
        int32_t min_ind = 0;
        int32_t max_ind = 0;

        for( uint32_t i = 0; i < static_cast<uint32_t>( TrailerID_t::Trailer_MAX ); i++ )
        {
            if( m_trailerFeatures.TrailerData[i].Is_Valid )
            {
                if( minCount > m_trailerFeatures.TrailerData[i].UsedCount )
                {
                    minCount = m_trailerFeatures.TrailerData[i].UsedCount;
                    min_ind = i;
                }

                if( max_count < m_trailerFeatures.TrailerData[i].UsedCount )
                {
                    max_count = m_trailerFeatures.TrailerData[i].UsedCount;
                    max_ind = i;
                }
            }
        }

        if( max_count < 0 )
        {
            max_count = 0;
        }

        bool_t TemplateCopied = false;

        for( uint32_t i = 0; i < static_cast<uint32_t>( TrailerID_t::Trailer_MAX ); i++ )
        {
            if( m_trailerFeatures.TrailerData[i].Is_Valid == false )
            {
                processing::ImageProcessing::Copy( i_trailerTemplate, m_trailerFeatures.TrailerData[i].trailerTemplate );
                m_trailerFeatures.TrailerData[i].Is_Valid = true;
                m_trailerFeatures.TrailerData[i].hitchPointValid = true;
                m_trailerFeatures.TrailerData[i].hitchPoint = i_hitch_point;
                m_trailerFeatures.TrailerData[i].HitchLength = m_trailerCalibration.HitchLength;
                m_trailerFeatures.TrailerData[i].CollisionAngleValid = true;
                m_trailerFeatures.TrailerData[i].CollisionAngle = i_CollisionAngle;
                m_trailerFeatures.TrailerData[i].beamlengthValid = true;
                m_trailerFeatures.TrailerData[i].BeamLength = i_BeamLength;
                m_trailerFeatures.TrailerData[i].JacknifeAngle = i_JacknifeAngle;
                m_trailerFeatures.TrailerData[i].JacknifeThreshAngle = i_jacknifethreshAngle;
                m_trailerFeatures.TrailerData[i].UsedCount = max_count + 1;

                for( uint32_t j = 0; j < static_cast<uint32_t>( TrailerID_t::Trailer_MAX ); j++ )
                {
                    if( j == i )
                    {
                        continue;
                    }

                    if( m_trailerFeatures.TrailerData[j].Is_Valid )
                    {
                        m_trailerFeatures.TrailerData[j].UsedCount -= 1;
                    }
                }

                CurrentTrailer_ID = m_trailerFeatures.TrailerData[i].Trailer_ID;
                TemplateCopied = true;
                break;
            }
        }

        if( !TemplateCopied )
        {
            processing::ImageProcessing::Copy( i_trailerTemplate, m_trailerFeatures.TrailerData[min_ind].trailerTemplate );
            m_trailerFeatures.TrailerData[min_ind].Is_Valid = true;
            m_trailerFeatures.TrailerData[min_ind].hitchPointValid = true;
            m_trailerFeatures.TrailerData[min_ind].hitchPoint = i_hitch_point;
            m_trailerFeatures.TrailerData[min_ind].HitchLength = m_trailerCalibration.HitchLength;
            m_trailerFeatures.TrailerData[min_ind].CollisionAngleValid = true;
            m_trailerFeatures.TrailerData[min_ind].CollisionAngle = i_CollisionAngle;
            m_trailerFeatures.TrailerData[min_ind].beamlengthValid = true;
            m_trailerFeatures.TrailerData[min_ind].BeamLength = i_BeamLength;
            m_trailerFeatures.TrailerData[min_ind].JacknifeAngle = i_JacknifeAngle;
            m_trailerFeatures.TrailerData[min_ind].JacknifeThreshAngle = i_jacknifethreshAngle;
            m_trailerFeatures.TrailerData[min_ind].UsedCount = max_count + 1;
            CurrentTrailer_ID = m_trailerFeatures.TrailerData[min_ind].Trailer_ID;

            for( uint32_t j = 0; j < static_cast<uint32_t>( TrailerID_t::Trailer_MAX ); j++ )
            {
                if( static_cast<int32_t>( j ) == min_ind )
                {
                    continue;
                }

                if( m_trailerFeatures.TrailerData[j].Is_Valid )
                {
                    m_trailerFeatures.TrailerData[j].UsedCount -= 1;
                }
            }
        }
    }

    /*
    * Process state execution output.
    */
    void TADStateMachine::ProcessOutput( TAD2::Output& o )
    {
        m_trailerAngle_deg = o.detectedAngle_deg;
        m_trailerAngleKnown = o.detectedAngleValid;
        m_trackingScore = o.angleScore;

        if( o.detectedHitchPointValid )
        {
            m_trailerCalibration.hitchPoint = o.detectedHitchPoint;
            m_trailerCalibration.hitchPointValid = true;
            m_hitchrangevalid = o.detectedhitchrangeValid;
            UpdateTrailerTemplate();
        }
        else if( o.usingDummyHitchPoint )
        {
            m_trailerCalibration.hitchPoint = o.detectedHitchPoint;
            m_trailerCalibration.hitchPointValid = false;
            UpdateTrailerTemplate();
        }
        else
        {
        }

        if( o.detectedCollisionAngleValid )
        {
            m_trailerCalibration.CollisionAngle = o.detectedCollisionAngle;
            m_trailerCalibration.CollisionAngleValid = true;
        }

        if( o.detectedAbsencePresenceValid )
        {
            m_trailerCalibration.Trailer_Present = o.Trailer_Present;
            m_trailerCalibration.AbsencePresenceValid = true;
        }

        if( o.detectedBeamLengthValid )
        {
            m_trailerCalibration.BeamLength = o.detectedBeamLength;
            m_trailerCalibration.JacknifeAngle = o.detectedJacknifeAngle;
            m_trailerCalibration.JacknifeThreshAngle = o.detectedJacknifeThreshAngle;
            m_trailerCalibration.beamlengthValid = true;
        }
    }

    /**
    * Maps enum state to state class.
    */
    TAD2::State* TADStateMachine::StateMap( int32_t i )
    {
        TAD2::State* returnValue = nullptr;

        switch( static_cast<TAD2::State::Enum>( i ) )
        {
            case State::Idle:
            {
                returnValue = &m_stateIdle;
                break;
            }

            case State::TrailerRecognition:
            {
                returnValue = &m_stateTrailerRecognition;
                break;
            }

            case State::TrailerDetection:
            {
                returnValue = &m_stateTrailerDetection;
                break;
            }

            case State::Calibration:
            {
                returnValue = &m_stateCalibration;
                break;
            }

            case State::ScanningForTrailer:
            {
                returnValue = &m_stateScanning;
                break;
            }

            case State::Trackinglost:
            {
                returnValue = &m_TrackingLost;
                break;
            }

            case State::Turnaround:
            {
                returnValue = &m_stateTurnaround;
                break;
            }

            case State::AngleDetection:
            {
                returnValue = &m_stateAngleDetection;
                break;
            }

            default:
            {
                break;
            }
        }

        return returnValue;
    }
    /*
    * Update the trailer template used in template matching.
    */
    void TADStateMachine::UpdateTrailerTemplate()
    {
        bool_t ret_val = true;

        if( ( !m_trailerCalibration.Is_Valid ) || ( !m_trailerCalibration.hitchPointValid ) )
        {
            // For dummyAngle to work, must create template regardless if the hitchpoint is valid.
            if( m_trailerCalibration.Is_Valid && !m_trailerCalibration.hitchPointValid )
            {
                if( m_trailerCalibration.trailerTemplate.getData() == NULL )
                {
                    m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
                }

                // --- Warp trailer calibration
                uint32_t start_range = ( m_bumper_pos + 5 );
                uint32_t end_range = m_hitchendrangePos;
                TAD2::WarpedImage<uint8_t> warpedTrailerImage = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
                m_pPreProcessing->WarpImage( m_trailerCalibration.UnwarpedImage, warpedTrailerImage,
                                             Point2i( m_config.getCalibrationConfigParamsRef().getHitchDetectionConfigData().getHitchX(),
                                                      static_cast <uint32_t>( start_range + ( 2 * ( ( end_range - start_range ) / 5 ) ) ) ) ); //PRQA S 3706
                //
                // --- Extract template
                int32_t xAt90 = warpedTrailerImage.Angle2XPos( 90.0f );
                t_m::TemplateMatching::ExtractTemplate( warpedTrailerImage, m_trailerCalibration.trailerTemplate, xAt90 - m_trailerCalibration.trailerTemplate.getWidth() / 2, 0 );
                memory::MemoryPool::ReleaseImage( warpedTrailerImage );
                //
                m_trailerTemplateUpdated = true;
            }

            ret_val = false;
        }

        //if( ret_val )
        //{
        //    if( m_trailerCalibration.trailerTemplate.getData() == NULL )
        //    {
        //        m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
        //    }
        //    // --- Warp trailer calibration
        //    TAD2::WarpedImage<uint8_t> warpedTrailerImage = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        //    m_pPreProcessing->WarpImage( m_trailerCalibration.UnwarpedImage, warpedTrailerImage, m_trailerCalibration.hitchPoint );
        //    //
        //    // --- Extract template
        //    int32_t xAt90 = warpedTrailerImage.Angle2XPos( 90.0f );
        //    t_m::TemplateMatching::ExtractTemplate( warpedTrailerImage, m_trailerCalibration.trailerTemplate, xAt90 - m_trailerCalibration.trailerTemplate.getWidth() / 2, 0 );
        //    memory::MemoryPool::ReleaseImage( warpedTrailerImage );
        //    //
        //    m_trailerTemplateUpdated = true;
        //}
        return;
    }
    /*
    * Update the trailer template used in template matching.
    */
    void TADStateMachine::UpdateWarpedTemplate()
    {
        bool_t ret_val = true;

        if( m_trailerCalibration.trailerTemplate.getData() == NULL )
        {
            m_trailerCalibration.trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
        }

        // --- Warp trailer calibration
        TAD2::WarpedImage<uint8_t> warpedTrailerImage = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        m_pPreProcessing->WarpImage( m_trailerCalibration.UnwarpedImage, warpedTrailerImage, m_trailerCalibration.hitchPoint );
        //
        // --- Extract template
        int32_t xAt90 = warpedTrailerImage.Angle2XPos( 90.0f );
        t_m::TemplateMatching::ExtractTemplate( warpedTrailerImage, m_trailerCalibration.trailerTemplate, xAt90 - m_trailerCalibration.trailerTemplate.getWidth() / 2, 0 );
        memory::MemoryPool::ReleaseImage( warpedTrailerImage );
        //
        m_trailerTemplateUpdated = true;
        return;
    }

}
