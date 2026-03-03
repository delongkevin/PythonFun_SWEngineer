// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "CalibrationState.h"
#include "TADStateMachine.h"
#include "common/config.h"
#include "Scanning.h"
#include "VehicleKinematics.h"
#include "PreProcessing.h"
#include "ImageThresholding.h"
#include "FeatureExtraction.h"
#include "CollisionAngleDetection.h"
#include "TADStateMachine.h"

#ifdef DIAGNOSTICS
    #include "global.h"
    #include "common/db.h"
    #include "fo.h"
#endif

#if DEBUG_HITCH_POINT
    #include <fsdata/fsdata.h>
    const uint32_t ImageSize_u32 = 640 * 400;
#endif
/*
* Constructor.
*/
namespace Calibration
{
    CalibrationState::CalibrationState( const tad2config::CalibrationConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* i_pVehicleKinematics, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction, cAngleDetection::CollisionAngleDetection* i_pCollisionAngleDetection ) :
        TAD2::State( parent ),
        m_config( i_config ),
        m_initialized( false ),
        m_timePassedInState_s( 0.0f ),
        m_distTravelledInState_m( 0.0f ),
        m_pVehicle( i_pVehicleKinematics ),
        m_pPreProcessing( i_preProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( i_pFeatureExtraction ),
        m_pCollisionAngleDetection( i_pCollisionAngleDetection ),
        // DummyAngle
        m_trailerTrackingObjDummy1(),
        m_trailerTrackingObjDummy2(),
        m_trailerTrackingObjDummy3(),
        m_trailerTrackingObjDummy4()

    {
    }
    /*
    * Destructor.
    */
    CalibrationState::~CalibrationState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t CalibrationState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *   Name:Calibration
        //DT
        *  Remarks: DD-ID: {0CC0F133-8A9E-434a-93A6-9343C669F27B}
        //BEV
        *  Remarks: DD-ID: {52250A8B-FEA7-4598-A65E-97EEB96EF987}
        //HD
        *  Remarks: DD-ID: {2AD4B994-5642-4cd5-B60B-55A9A4B2EF8E}
        */
        TAD2::State::Enum returnState = TAD2::State::Calibration;
        // Set dummy Hitch Point:
        static bool_t usingDummyHitchInited = false;
        float32_t averageIllumination = super->FindAverageIllumination( e.topView, e.roi );
        super->Set_averageillumination( averageIllumination );
        Drive_Fail = false;
        CameraBlocked = false;

        if( ( !usingDummyHitchInited ) && ( ( m_config.getHitchDetectionConfigData().getEnabled() || !m_hitchCalibrated ) && super->IsCalibratingHitch() ) )
        {
            o.detectedHitchPoint = Point2i( m_config.getHitchDetectionConfigData().getHitchX(), static_cast <uint32_t>( ( super->GetbumperPos() + super->GethitchendrangePos() ) / 2 ) ); //PRQA S 3706
            o.usingDummyHitchPoint = true;
            usingDummyHitchInited = true;
        }

        // --- Run sub-state machine
        switch( m_subState )
        {
            case TAD2::calibration::State::DriveStraight:
            {
                StateDriveStraight( e, o );
                break;
            }

            case TAD2::calibration::State::TurnLeftOrRight:
            {
                StateTurnLeftOrRight( e, o );
                break;
            }

            case TAD2::calibration::State::Wait:
            {
                StateWait( e, o );
                break;
            }

            case CalibrationState_MAX:
            {
                //do nothing
            }
        }

        // --- Kinematics
        if( super->KinematicsEnabled() && m_pVehicle->valid() )
        {
            m_timePassedInState_s += m_pVehicle->timePassed_s();
            m_distTravelledInState_m += mecl::math::abs_x( m_pVehicle->distanceTravelled_m() );
        }

        o.timeInState_s = m_timePassedInState_s;
        o.distanceTravelledInState_m = m_distTravelledInState_m;
        // Calibration Reset
        int32_t gear_dir = m_pVehicle->gearDir();

        if( minwheelangle > m_pVehicle->wheelAngle_deg() )
        {
            minwheelangle = m_pVehicle->wheelAngle_deg();
        }

        if( maxwheelangle < m_pVehicle->wheelAngle_deg() )
        {
            maxwheelangle = m_pVehicle->wheelAngle_deg();
        }

        if( ( abs( minwheelangle ) > 20.0f ) && ( abs( maxwheelangle ) > 20.0f ) )
        {
            Drive_Fail = true;
        }

        if( ( ( last_geardir == 1 ) && ( gear_dir != 1 ) ) )
        {
            OnExit();
            OnEnter();
            /*super->SetCalibrationFailReason( TrailerCalibrationFailInfo_t::Gear_IN_Reverse );
            super->SetCalibrationFailCount( super->GetCalibrationFailCount() + 1 );*/
        }

        if( CameraBlocked )
        {
            OnExit();
            OnEnter();
            super->SetCalibrationFailReason( TrailerCalibrationFailInfo_t::Camera_Blocked );
            super->SetCalibrationFailCount( super->GetCalibrationFailCount() + 1 );
        }

        // --- Return next state if finished
        if( m_collisionangleCalibrated && m_trailerCalibrated && m_hitchCalibrated )
        {
            super->SetCalibrationFailReason( TrailerCalibrationFailInfo_t::No_Failure );
            returnState = TAD2::State::ScanningForTrailer;
        }

        last_geardir = gear_dir;
        return returnState;
    }

    /*
    * Called once when entering this state.
    */
    void CalibrationState::OnEnter()
    {
        first_frame = true;
        bool_t ret_val = true;
        m_trailerCalibrated = super->WasTrailerLoadedSuccessfully();
        m_hitchCalibrated = super->WasHitchLoadedSuccessfully();
        super->ResetCalibrationState();
        minwheelangle = 90.0f;
        maxwheelangle = -90.0f;

        if( super->CollisonAngleDetectionEnabled() )
        {
            m_collisionangleCalibrated = super->WascollisionangleLoadedSuccessfully();
        }
        else
        {
            m_collisionangleCalibrated = true;
        }

        first = true;
        second = false;
        third = false;
        fourth = false;
        warpedEdges1 = TAD2::WarpedImage<uint8_t>( super->GetWarpedTopViewParams(), memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        super->SetHitchPos( 0 );
        super->SetDummyAngle( 90.0f, 90.0f, 90.0f, 90.0f );
        m_hitchrangedetectionstarted = false;
        m_timePassedInState_s = 0.0f;
        m_distTravelledInState_m = 0.0f;
        m_subState = CalibrationState_t::CalibrationState_DriveStraight;

        // --- Check for early return
        if( m_trailerCalibrated && m_hitchCalibrated && m_collisionangleCalibrated )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_config.getTrailerAngleDetectionConfigData().getOutputFilterSize() > c_bufSize )
            {
                super->SetError( 0, "Angle filter size is too large." );
            }

            m_hitch_offset_start = super->GetbumperPos() + 5; //PRQA S 3706
            m_hitch_offset_finish = super->GethitchendrangePos(); //PRQA S 3706
            hitchdiff = m_hitch_offset_finish - m_hitch_offset_start;
            m_dummyangle_hitchPoint1 = m_hitch_offset_start + ( 1 * ( hitchdiff / 5 ) );
            m_dummyangle_hitchPoint2 = m_hitch_offset_start + ( 2 * ( hitchdiff / 5 ) );
            m_dummyangle_hitchPoint3 = m_hitch_offset_start + ( 3 * ( hitchdiff / 5 ) );
            m_dummyangle_hitchPoint4 = m_hitch_offset_start + ( 4 * ( hitchdiff / 5 ) );

            // --- Initialize modules
            if( !m_initialized )
            {
                m_initialized = true;
                float32_t beamLengthPtr[2] = { super->GetVehicleConfigData().getBeamLengthRange_mmRef()[0], super->GetVehicleConfigData().getBeamLengthRange_mmRef()[1] };
                m_initialized = m_initialized && m_trailerAngleCalibrationObj.Init( super->GetVehicleParams(), super->GetVehicleConfigData() );
                uint32_t hitchYOffset[2];
                hitchYOffset[0] = super->GetbumperPos();
                hitchYOffset[1] = super->GethitchendrangePos();
                m_initialized = m_initialized && m_templateBuildUpObj.Init( m_config.getHitchDetectionConfigData().getHitchX(), reinterpret_cast<uint32_t*>( hitchYOffset ) );
                const TAD2::VehicleParameters v_vehicleParam_st = super->GetVehicleParams();
                m_initialized = m_initialized && m_angleSamplingObj.Init( v_vehicleParam_st, m_pPreProcessing, beamLengthPtr, m_config.getHitchDetectionConfigData().getHitchX(), m_hitch_offset_start, m_hitch_offset_finish, hitchdiff ); //PRQA S 3840
                m_initialized = m_initialized && m_hitchDetectionObj.Init( m_config.getHitchDetectionConfigData(), m_pPreProcessing, m_config.getHitchDetectionConfigData().getHitchX(), reinterpret_cast<uint32_t*>( hitchYOffset ) );
                const TAD2::WarpedTopViewParameters v_parameter_st = super->GetWarpedTopViewParams();
                m_initialized = m_initialized && m_trailerTrackingObjDummy1.Init( v_parameter_st, m_config.getTrailerAngleDetectionConfigData().getWeightFactor() );
                m_initialized = m_initialized && m_trailerTrackingObjDummy2.Init( v_parameter_st, m_config.getTrailerAngleDetectionConfigData().getWeightFactor() );
                m_initialized = m_initialized && m_trailerTrackingObjDummy3.Init( v_parameter_st, m_config.getTrailerAngleDetectionConfigData().getWeightFactor() );
                m_initialized = m_initialized && m_trailerTrackingObjDummy4.Init( v_parameter_st, m_config.getTrailerAngleDetectionConfigData().getWeightFactor() );

                if( !m_initialized )
                {
                    super->SetError( 2, "Couldn't initialize Calibration state." );
                }
            }

            m_trailerTemplate = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            m_trailerTemplate1 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            m_trailerTemplate2 = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_Template_U8C1 );
            // --- Initializing the wheel angle buffer
            uint32_t v_wheelAngle_u32 = m_wheelangle.size();

            for( uint32_t i = 0; i < v_wheelAngle_u32; i++ )
            {
                m_wheelangle.push( 0.0f );
            }

            // --- Start modules
            bool_t result = true;
            result = result && m_trailerAngleCalibrationObj.Start( m_config.getTrailerAngleCalConfigParams().getInitialAngle(), m_config.getTrailerAngleCalConfigParams().getToleranceDeg() );
            result = result && m_templateBuildUpObj.Start();

            if( !result )
            {
                super->SetError( 1, "Couldn't start Calibration state." );
            }
        }

        return;
    }

    /*
    * Called once when exiting this state.
    */
    void CalibrationState::OnExit()
    {
        first_frame = true;
        m_initialized = false;
        first = true;
        second = false;
        third = false;
        fourth = false;
        m_trailerAngleCalibrationObj.Finish();
        m_templateBuildUpObj.Finish();
        m_angleSamplingObj.Finish();
        m_hitchDetectionObj.Finish();
        m_trailerTrackingObjDummy1.Finish();
        m_trailerTrackingObjDummy2.Finish();
        m_trailerTrackingObjDummy3.Finish();
        m_trailerTrackingObjDummy4.Finish();
        memory::MemoryPool::ReleaseImage( m_calibratedTrailerImage );
        memory::MemoryPool::ReleaseImage( m_trailerTemplate );
        memory::MemoryPool::ReleaseImage( m_trailerTemplate1 );
        memory::MemoryPool::ReleaseImage( m_trailerTemplate2 );
        memory::MemoryPool::ReleaseImage( warpedEdges1 );
    }

    /*
    * Get the enum for this state.
    */
    int32_t CalibrationState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_Calibration;
    }

    /*
    * Get the enum for this states current sub-state.
    */
    CalibrationState_t CalibrationState::GetSubState()const
    {
        return m_subState;
    }

    /*
    * Get the amount of time passed in this state
    */
    float32_t CalibrationState::GetTimeInCalibration()const
    {
        return m_timePassedInState_s;
    }

    /*
    * Get the distance travelled (m) while in this state.
    */
    float32_t CalibrationState::GetDistTravelledInCalibration()const
    {
        return m_distTravelledInState_m;
    }

    void CalibrationState::GetThresholdVal()
    {
        m_thresh = m_angleSamplingObj.GetThresholdVal();
    }

    void CalibrationState::GetDummyAngle()
    {
        m_Dummy_angle = m_angleSamplingObj.GetDummyAngle();
    }
    /*
    * Process function for the sub-state "Drive Stright."
    */
    void CalibrationState::StateDriveStraight( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name:Calibration_DriveState
        //DT
        *  Remarks: DD-ID: {AC9D91B5-C34C-4cae-B84B-9A7E1E3A8D71}
        //BEV
        *  Remarks: DD-ID: {8F722D92-51D6-459c-82F4-8B2422277A2D}
        //HD
        *  Remarks: DD-ID: {BC539678-23BB-45fa-9CF7-664A8FE2E43F}
        */
        bool_t ret_val = true;
        //cv::Mat img = processing::ImageProcessing::ConvertToCV( e.rearView );

        if( m_trailerCalibrated && m_collisionangleCalibrated )
        {
            //m_subState = TAD2::calibration::State::TurnLeftOrRight;
            ret_val = false;
        }

        if( ret_val )
        {
            bool_t speedAboveThreshold1 = true;
            bool_t speedAboveThreshold2 = true;
            bool_t trailerStraight = true;
            m_wheelangle.push( m_pVehicle->wheelAngle_deg() );

            // --- Calibrate trailer angle
            if( m_config.getTrailerAngleCalConfigParams().getEnabled() && super->KinematicsEnabled() )
            {
                m_trailerAngleCalibrationObj.Run( e.frame, m_pVehicle, false );

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

            if( trailerStraight && speedAboveThreshold1 && !m_templateBuildUpObj.IsTemplateFound() )
            {
                // --- Pre-processing
                m_pPreProcessing->Run( e.frame, e.topView, e.roi );
                image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
                //
                // --- Edge detection
                image::Image<uint16_t> lowThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
                image::Image<uint16_t> highThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
                image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
                image::Image<uint8_t> gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
                //
                bool_t warpedimg = false;
                m_pImageThresholding->Run( e.frame, topView, e.roi, m_hitchDetectionObj.GetROICentrePoint(), e.currentTrailerAngle_deg, e.trailerAngleKnown, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
                m_pFeatureExtraction->Run( e.frame, topView, lowThresh, highThresh, e.roi, gradMag, gradDir );
                edges = m_pFeatureExtraction->GetEdges();
                memory::MemoryPool::ReleaseImage( lowThresh );
                memory::MemoryPool::ReleaseImage( highThresh );
                memory::MemoryPool::ReleaseImage( gradMag );
                memory::MemoryPool::ReleaseImage( gradDir );
                //
                //
                // --- Build trailer template
                m_templateBuildUpObj.Run( e.frame, edges );
            }
            else if( super->CollisonAngleDetectionEnabled() && trailerStraight && speedAboveThreshold2 && !m_pCollisionAngleDetection->IsCollisionAngleFound() )
            {
                _roi::ROI roi;
                roi.setX( 0 );
                roi.setY( 0 );
                roi.setWidth( 640 );
                roi.setHeight( 300 );
                Point2i hitch_point = m_hitchDetectionObj.GetROICentrePoint();
                hitch_point.y = m_dummyangle_hitchPoint2;
                // --- Pre-processing
                m_pPreProcessing->Run( e.frame, e.topView, roi );
                image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
                // --- Edge detection
                image::Image<uint16_t> lowThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
                image::Image<uint16_t> highThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
                image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
                image::Image<uint8_t> gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
                //
                bool_t warpedimg = false;
                m_pImageThresholding->Run( e.frame, topView, e.roi, hitch_point, e.currentTrailerAngle_deg, e.trailerAngleKnown, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
                m_pFeatureExtraction->Run( e.frame, topView, lowThresh, highThresh, roi, gradMag, gradDir );
                edges = m_pFeatureExtraction->GetEdges();
                memory::MemoryPool::ReleaseImage( lowThresh );
                memory::MemoryPool::ReleaseImage( highThresh );
                memory::MemoryPool::ReleaseImage( gradMag );
                memory::MemoryPool::ReleaseImage( gradDir );
                TAD2::WarpedImage<uint8_t> warpedEdges2 = TAD2::WarpedImage<uint8_t>( super->GetWarpedTopViewParams(), memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
                // -- warping the image
                m_pPreProcessing->WarpImage( edges, warpedEdges2, hitch_point );
                // --- Collision Angle Detection
                m_pCollisionAngleDetection->Run( e.frame, warpedEdges2, m_pImageThresholding->_getotsuthresh(), hitch_point );
                memory::MemoryPool::ReleaseImage( warpedEdges2 );
                o.detectedCollisionAngleValid = false;
            }
            else
            {
            }

            if( !super->CollisonAngleDetectionEnabled() )
            {
                super->SetCollisionAngle( 0.0, 0.0, 0.0 );
                m_pCollisionAngleDetection->Finish();
                o.detectedCollisionAngleValid = true;
                o.detectedCollisionAngle = 0.0;
                m_collisionangleCalibrated = true;
            }

            // --- Send calibration angles to state machine
            float32_t left;
            float32_t right;
            m_trailerAngleCalibrationObj.GetCalibrationAngles( left, right );
            super->SetCalibrationAngles( left, right );

            /*if( ( abs( 90.0f - left ) > 30.0f ) || ( abs( 90.0f - right ) > 30.0f ) )
            {
                DriveFail = true;
            }*/

            // --- Check if finished
            if( m_templateBuildUpObj.IsTemplateFound() && ( m_pCollisionAngleDetection->IsCollisionAngleFound() || !super->CollisonAngleDetectionEnabled() ) )
            {
                super->SetCollisionAngle( m_pCollisionAngleDetection->GetCollisionAngle(), m_pCollisionAngleDetection->GetLeftCollisionAngle(), m_pCollisionAngleDetection->GetRightCollisionAngle() );
                m_pCollisionAngleDetection->Finish();
                o.detectedCollisionAngleValid = true;
                o.detectedCollisionAngle = m_pCollisionAngleDetection->GetCollisionAngle();
                m_collisionangleCalibrated = true;
                minwheelangle = 90.0f;
                maxwheelangle = -90.0f;
                // --- Create trailer template image
                m_calibratedTrailerImage = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
                m_templateBuildUpObj.CreateInitialTemplate( m_calibratedTrailerImage );
                super->SetCalibratedunwarpedTrailerImage( m_calibratedTrailerImage );
                m_trailerCalibrated = true;
                m_hitch_range = m_dummyangle_hitchPoint2;
                //
                m_trailerAngleCalibrationObj.Finish();
                m_templateBuildUpObj.Finish();

                if( !m_hitchCalibrated )
                {
                    if( !m_angleSamplingObj.Start() )
                    {
                        super->SetError( 1, "Couldn't start Angle Sampling object." );
                    }
                }

                // DummyAngle
                initialize_dummy_angle();
                // --- Change states
                //m_subState = TAD2::calibration::State::TurnLeftOrRight;
            }

            if( trailerStraight )
            {
                o.detectedAngle_deg = 90.0f;
                o.detectedAngleValid = true;
                o.angleScore = 0.99f;
            }
        }
        else if( m_templateBuildUpObj.IsTemplateFound() )
        {
            // Dummy Angle Tracking
            DummyAngleTracking( e );
            // --- Set output
            o.detectedAngle_deg = _GetDummyAngle();
            o.detectedAngleValid = true;
            o.angleScore = m_trailerTrackingObjDummy2.GetTrackingScore();
            o.detectedhitchrangeValid = false;
            // Hitch range detection
            hitchrangedetection( e );
            //  --- Change states
            m_subState = CalibrationState_t::CalibrationState_TurnLeftOrRight;
        }

        return;
    }

    /*
    * Process function for the sub-state "Turn Left Or Right."
    */
    void CalibrationState::StateTurnLeftOrRight( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: Calibration_TurnLeftorRight
        //DT
        *  Remarks: DD-ID: {DC45BC87-085E-4433-B40F-F1A51A659456}
        //BEV
        *  Remarks: DD-ID: {A5EE2CF4-A8EA-4e13-8800-3D4A7C65D786}
        //HD
        *  Remarks: DD-ID: {4BFDD50B-9F63-493e-BC20-E0993AD546BC}
        */
        bool_t ret_val = true;

        if( m_hitchCalibrated )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            // Dummy Angle Tracking
            DummyAngleTracking( e );
            // --- Set output
            o.detectedAngle_deg = _GetDummyAngle();
            o.detectedAngleValid = true;
            o.angleScore = m_trailerTrackingObjDummy2.GetTrackingScore();
            // Hitch range detection
            hitchrangedetection( e );
            //
            m_wheelangle.push( m_pVehicle->wheelAngle_deg() );

            if( m_angleSamplingObj.IsComplete() || m_hitchCalibrated )
            {
                first = false;
                second = false;
                third = false;
                fourth = false;
                super->SetHitchPos( m_angleSamplingObj.GetHitchPos() );
                super->SetHitchrangecalculated( m_angleSamplingObj.IsComplete() );
                // finding wheather the trailer is straight for a certain distance
                float32_t average_ang = 0.0;
                uint32_t i;

                for( i = 0; i < m_wheelangle.size(); i++ )
                {
                    average_ang += mecl::math::abs_x( m_wheelangle[i] );
                }

                average_ang = average_ang / static_cast<float32_t>( i );

                if( ( mecl::math::abs_x( average_ang ) < 1.0f ) && ( m_pVehicle->currentSpeed_mps() > 0.5f ) )
                {
                    image::Image<uint8_t> angle_images[sampling::AngleSampling::c_numImages];
                    m_angleSamplingObj.GetSampleImages( &angle_images[0] );
                    bool_t is_left_side = m_angleSamplingObj.IsLeftSide();

                    if( !m_hitchCalibrated )
                    {
                        GetThresholdVal();
                        GetDummyAngle();

                        if( !m_hitchDetectionObj.Start( m_calibratedTrailerImage, reinterpret_cast<image::Image_u8*>( angle_images ), is_left_side, m_thresh , m_Dummy_angle, m_hitch_range, m_angleSamplingObj.GetRangeDiff(), m_angleSamplingObj.GetHitchPos() ) )
                        {
                            super->SetError( 1, "Couldn't start Hitch Detection object." );
                        }
                    }
                    else
                    {
                        m_hitchDetectionObj.SethitchPoint( super->GetHitchPoint() );
                    }

                    // --- Change states
                    m_subState = CalibrationState_t::CalibrationState_Wait;
                }
            }
        }
    }

    /*
    * Process function for the "Wait" sub-state.
    */
    void CalibrationState::StateWait( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name:Calibration_DriveState
        //DT
        *  Remarks: DD-ID: {6660F6E9-F3A1-47fa-94F9-6DD17CB8BAD0}
        //BEV
        *  Remarks: DD-ID: {AE82DE69-8887-4833-A3AC-A7BC4EAD162F}
        //HD
        *  Remarks: DD-ID: {E7517470-961E-4969-BA70-FFE79449162A}
        */
        bool_t ret_val = true;

        if( m_hitchCalibrated )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( ( !m_hitchDetectionObj.IsHitchPointFound() ) && ( !m_hitchCalibrated ) )
            {
                m_hitchDetectionObj.Run( e.frame );
            }

            // Dummy Angle Tracking
            DummyAngleTracking( e );
            // --- Set output
            o.detectedAngle_deg = _GetDummyAngle();
            o.detectedAngleValid = true;
            o.angleScore = m_trailerTrackingObjDummy2.GetTrackingScore();
            // Hitch range detection
            hitchrangedetection( e );

            //
            if( m_hitchDetectionObj.IsHitchPointFound() || m_hitchCalibrated )
            {
                m_hitchCalibrated = true;
                super->SetHitchCalibrated();
                // hitch length conversion
                super->SetCalculateHitchLength( m_hitchDetectionObj.GetHitchPoint().y );
                o.detectedHitchPoint = m_hitchDetectionObj.GetHitchPoint();
#if DEBUG_HITCH_POINT
                static bool firstTime = true;

                if( true == firstTime )
                {
                    printf( "TAD2: detectedHitchPoint: %d, %d\n", o.detectedHitchPoint.x, o.detectedHitchPoint.y );
                    char buffer[100];
                    FILE* fp;
                    fp = fopen( "/ti_sd/TAD_algo_view_stateWait.bin", "wb" );
                    fwrite( ( void* )e.topView.getData(), 1, ImageSize_u32, fp );
                    fclose( fp );
                    firstTime = false;
                }

#endif
                o.detectedHitchPointValid = true;
                o.detectedAngleValid = false; // needs to be checked wheather it needs to be set false
                //
                o.usingDummyHitchPoint = false;
                o.detectedhitchrangeValid = true;
                m_angleSamplingObj.Finish();
                m_hitchDetectionObj.Finish();
                super->SetTempHitchPos( m_hitchDetectionObj.GetHitchPoint(), true );
                super->UpdateWarpedTemplate();
                // --- Change states
                m_subState = CalibrationState_t::CalibrationState_TurnLeftOrRight;
            }
        }
    }
    /*
    * Dummy Angle Tracking
    */
    void CalibrationState::DummyAngleTracking( TAD2::Event& e )
    {
        // --- Edge Detection
        image::Image<uint16_t> lowThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint16_t> highThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
        image::Image<uint8_t> gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );

        // --- Pre-processing
        if( m_config.getHitchDetectionConfigData().getPreprocessingEnabled() )
        {
            m_pPreProcessing->Run( e.frame, e.topView, e.roi );
            image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
            //
            bool_t warpedimg = false;
            m_pImageThresholding->Run( e.frame, topView, e.roi, m_hitchDetectionObj.GetROICentrePoint(), e.currentTrailerAngle_deg, e.trailerAngleKnown, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
            m_pFeatureExtraction->Run( e.frame, topView, lowThresh, highThresh, e.roi, gradMag, gradDir );
        }
        else
        {
            bool_t warpedimg = false;
            m_pImageThresholding->Run( e.frame, e.topView, e.roi, m_hitchDetectionObj.GetROICentrePoint(), e.currentTrailerAngle_deg, e.trailerAngleKnown, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
            m_pFeatureExtraction->Run( e.frame, e.topView, lowThresh, highThresh, e.roi, gradMag, gradDir );
        }

        edges = m_pFeatureExtraction->GetEdges();
        memory::MemoryPool::ReleaseImage( lowThresh );
        memory::MemoryPool::ReleaseImage( highThresh );
        memory::MemoryPool::ReleaseImage( gradMag );
        memory::MemoryPool::ReleaseImage( gradDir );

        //
        // --- Warp edges
        if( first || ( m_angleSamplingObj.GetHitchPos() == 1 ) )
        {
            m_pPreProcessing->WarpImage( edges, warpedEdges1, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint1 ) );
            m_trailerTrackingObjDummy1.Run( e.frame, warpedEdges1, m_pImageThresholding->_getotsuthresh(), true, true );
            TrailerAngle = abs( 90.0f - m_trailerTrackingObjDummy1.GetTrailerAngle() );

            if( !m_angleSamplingObj.IsComplete() )
            {
                first = false;
                second = true;
                third = false;
                fourth = false;
            }
        }
        else if( second || ( m_angleSamplingObj.GetHitchPos() == 2 ) )
        {
            m_pPreProcessing->WarpImage( edges, warpedEdges1, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint2 ) );
            m_trailerTrackingObjDummy2.Run( e.frame, warpedEdges1, m_pImageThresholding->_getotsuthresh(), true, true );
            TrailerAngle = abs( 90.0f - m_trailerTrackingObjDummy2.GetTrailerAngle() );

            if( !m_angleSamplingObj.IsComplete() )
            {
                first = false;
                second = false;
                third = true;
                fourth = false;
            }
        }
        else if( third || ( m_angleSamplingObj.GetHitchPos() == 3 ) )
        {
            m_pPreProcessing->WarpImage( edges, warpedEdges1, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint3 ) );
            m_trailerTrackingObjDummy3.Run( e.frame, warpedEdges1, m_pImageThresholding->_getotsuthresh(), true, true );
            TrailerAngle = abs( 90.0f - m_trailerTrackingObjDummy3.GetTrailerAngle() );

            if( !m_angleSamplingObj.IsComplete() )
            {
                first = false;
                second = false;
                third = false;
                fourth = true;
            }
        }
        else if( fourth || ( m_angleSamplingObj.GetHitchPos() == 4 ) )
        {
            m_pPreProcessing->WarpImage( edges, warpedEdges1, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint4 ) );
            m_trailerTrackingObjDummy4.Run( e.frame, warpedEdges1, m_pImageThresholding->_getotsuthresh(), true, true );
            TrailerAngle = abs( 90.0f - m_trailerTrackingObjDummy4.GetTrailerAngle() );

            if( !m_angleSamplingObj.IsComplete() )
            {
                first = true;
                second = false;
                third = false;
                fourth = false;
            }
        }
        else
        {
        }

        //
        // --- Run angle detection
        m_trailerAngleBufDummy.push( m_trailerTrackingObjDummy2.GetTrailerAngle() );
    }
    /*
    * Hitch range algo
    */
    void CalibrationState::hitchrangedetection( TAD2::Event& e )
    {
        // ++ hitch range dummy mask ++ //
        float32_t v_TrailerAngle1_f32 = m_trailerTrackingObjDummy1.GetTrailerAngle();
        float32_t v_TrailerAngle2_f32 = m_trailerTrackingObjDummy2.GetTrailerAngle();
        float32_t v_TrailerAngle3_f32 = m_trailerTrackingObjDummy3.GetTrailerAngle();
        float32_t v_TrailerAngle4_f32 = m_trailerTrackingObjDummy4.GetTrailerAngle();
        super->SetDummyAngle( v_TrailerAngle1_f32, v_TrailerAngle2_f32, v_TrailerAngle3_f32, v_TrailerAngle4_f32 );
        m_angleSamplingObj.Set_Dummy_angles( v_TrailerAngle1_f32, v_TrailerAngle2_f32, v_TrailerAngle3_f32, v_TrailerAngle4_f32 );
        // -- hitch range dummy mask -- //
        //
        image::Image<uint8_t> dynamic_img_1 = m_trailerTrackingObjDummy1._Getdynamictemplate();
        image::Image<uint8_t> dynamic_img_2 = m_trailerTrackingObjDummy2._Getdynamictemplate();
        image::Image<uint8_t> dynamic_img_3 = m_trailerTrackingObjDummy3._Getdynamictemplate();
        image::Image<uint8_t> dynamic_img_4 = m_trailerTrackingObjDummy4._Getdynamictemplate();
        // --- Sample for images of trailer at different angles
        bool_t kinematic_ON = m_angleSamplingObj.IsComplete();
        uint16_t otsu_thresh = m_pImageThresholding->_getotsuthresh();
        m_angleSamplingObj.Run( e.frame, edges, m_pVehicle, otsu_thresh, _GetDummyAngle(), dynamic_img_1, dynamic_img_2, dynamic_img_3, dynamic_img_4, m_calibratedTrailerImage, m_hitch_range, kinematic_ON );
        super->SetHitchCalibrationAngle( m_angleSamplingObj.GetCalibrationAngle() );

        if( kinematic_ON )
        {
            if( m_angleSamplingObj.GetHitchPos() == 1 )
            {
                super->SetHitchCalibrationAngle( v_TrailerAngle1_f32 );
            }
            else if( m_angleSamplingObj.GetHitchPos() == 2 )
            {
                super->SetHitchCalibrationAngle( v_TrailerAngle2_f32 );
            }
            else if( m_angleSamplingObj.GetHitchPos() == 3 )
            {
                super->SetHitchCalibrationAngle( v_TrailerAngle3_f32 );
            }
            else if( m_angleSamplingObj.GetHitchPos() == 4 )
            {
                super->SetHitchCalibrationAngle( v_TrailerAngle4_f32 );
            }
        }
    }
    /*
    * Take weighted average of most recent trailer angles to reduce jittering. For DummyAngle:
    */
    float32_t CalibrationState::_GetDummyAngle()
    {
        float32_t sum = 0.0f;
        float32_t totalWeight = 0.0f;
        float32_t w;
        uint32_t startInd = 0;
        m_config.getTrailerAngleDetectionConfigData().getOutputFilterSize();

        if( m_trailerAngleBufDummy.fill() > m_config.getTrailerAngleDetectionConfigData().getOutputFilterSize() )
        {
            startInd = m_trailerAngleBufDummy.fill() - m_config.getTrailerAngleDetectionConfigData().getOutputFilterSize();
        }

        for( uint32_t i = 0; i < m_config.getTrailerAngleDetectionConfigData().getOutputFilterSize(); i++ )
        {
            if( i >= m_trailerAngleBufDummy.fill() )
            {
                break;
            }

            w = 2.0f * static_cast<float32_t>( ( i + 1 ) );
            sum += w * m_trailerAngleBufDummy[startInd + i];
            totalWeight += w;
        }

        return sum / totalWeight;
    }
    /*
    * initialize dummy angle
    */
    void CalibrationState::initialize_dummy_angle()
    {
        // --- Initialize template and topview parameters
        float32_t initialTrailerAngle = 90.0f;
        //
        // --- Initialize angle history
        m_trailerAngleBufDummy.clear();
        m_trailerAngleBufDummy.push( initialTrailerAngle );
        // --- Warp trailer calibration
        TAD2::WarpedImage<uint8_t> warpedTrailerImage = TAD2::WarpedImage<uint8_t>( memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        image::Image_u8 unWarpedTrailerTemplate = super->GetUnwarpedTrailerTemplate();
        // -- Dummy angle 1
        m_pPreProcessing->WarpImage( unWarpedTrailerTemplate, warpedTrailerImage, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint1 ) );
        int32_t xAt90 = warpedTrailerImage.Angle2XPos( 90.0f );
        t_m::TemplateMatching::ExtractTemplate( warpedTrailerImage, m_trailerTemplate, xAt90 - m_trailerTemplate.getWidth() / 2, 0 );
        bool_t result = m_trailerTrackingObjDummy1.Start( m_trailerTemplate, 90.0f );
        // -- Dummy angle 2
        result = result && m_trailerTrackingObjDummy2.Start( super->GetTrailerTemplate(), 90.0f );
        // -- Dummy angle 3
        m_pPreProcessing->WarpImage( unWarpedTrailerTemplate, warpedTrailerImage, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint3 ) );
        t_m::TemplateMatching::ExtractTemplate( warpedTrailerImage, m_trailerTemplate1, xAt90 - m_trailerTemplate1.getWidth() / 2, 0 );
        result = result && m_trailerTrackingObjDummy3.Start( m_trailerTemplate1, 90.0f );
        // -- Dummy angle 4
        m_pPreProcessing->WarpImage( unWarpedTrailerTemplate, warpedTrailerImage, Point2i( m_config.getHitchDetectionConfigData().getHitchX(), m_dummyangle_hitchPoint4 ) );
        t_m::TemplateMatching::ExtractTemplate( warpedTrailerImage, m_trailerTemplate2, xAt90 - m_trailerTemplate2.getWidth() / 2, 0 );
        memory::MemoryPool::ReleaseImage( warpedTrailerImage );
        result = result && m_trailerTrackingObjDummy4.Start( m_trailerTemplate2, 90.0f );

        if( !result )
        {
            super->SetError( 1, "Couldn't start Dummy Angle." );
        }

        m_trailerTrackingObjDummy2.Set_IsDummy( true );
    }
}
