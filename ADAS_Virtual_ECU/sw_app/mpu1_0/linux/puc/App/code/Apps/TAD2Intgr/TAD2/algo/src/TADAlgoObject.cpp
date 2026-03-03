// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TADAlgoObject.h"
#include "WarpLUT.h"
#include "CANData.h"
#include "TemplateWeightMask.h"
#include "MemoryPool.h"
#include "ImageProcessing.h"
#include <mecl/mecl.h>
TAD2::JobTADOutput tadOutput;
namespace TAD2
{
    /**
    * Constructor.
    */
    TADAlgoObject::TADAlgoObject() :
        initOK( false ),
        m_isRunning( false ),
        m_stateMachine( m_config, m_vehicleParams, this, &m_vehicleKinematicsObj, &m_preProcessingObj, &m_imageThresholdingObj, &m_featureExtractionObj, &m_collisionAngleDetectionObj ),
        m_implicitCalibrationObj( m_config, m_stateMachine.GetVehicleConfigData(), m_vehicleParams, this, &m_vehicleKinematicsObj, &m_preProcessingObj, &m_imageThresholdingObj, &m_featureExtractionObj )
    {
        m_processingROI.setX( 0 );
        m_processingROI.setY( 0 );
        m_processingROI.setHeight( 0 );
        m_processingROI.setWidth( 0 );
    }

    /**
    * Destructor.
    */
    TADAlgoObject::~TADAlgoObject()
    {
        try
        {
            Uninit();//
        }
        catch( const std::overflow_error& e )
        {
        }
        catch( const std::runtime_error& e )
        {
        }
        catch( const std::exception& e )
        {
        }
        catch( ... )
        {
        }
    }

    /**
    * Initialize TAD algo object and check inputs.
    */
    bool_t TADAlgoObject::Init( tad2config::TADConfigData i_config, TAD2::VehicleParameters i_vehParams )
    {
        bool_t ret_val = false;

        if( initOK )
        {
            ret_val = true;
        }

        if( !ret_val )
        {
            PreviousState = TeTRSC_e_TADState::TeTRSC_e_TADState_TrailerRecognition;
            bool_t result = true;
            m_jobDebugOutput.error = 0;
            //
            // --- Initialize warped topview parameters
            m_warpedTopViewParams = TAD2::getWarpedTopViewParams();
            //
            m_vehicleParams = i_vehParams;
            m_vehicleParams.hitchLength_mm = i_vehParams.rearOverhang_mm + i_config.getCanAndVehicleConfigParams().getBumper2Hitch_mm();
            m_config = i_config;
            //
            // --- Initialize top-level modules
            result = result && m_vehicleKinematicsObj.Init( m_vehicleParams, i_config.getCanAndVehicleConfigParams().getTime(), !i_config.getCanAndVehicleConfigParams().getAngleCW() );
            result = result && m_preProcessingObj.Init();
            result = result && m_imageThresholdingObj.Init();
            result = result && m_featureExtractionObj.Init();
            result = result && m_collisionAngleDetectionObj.Init( m_warpedTopViewParams );

            if( !result )
            {
                SetError( 2, "Couldn't initialize top-level modules." );
            }

            bool_t sanitycheck = SanityCheck();
            result = result && sanitycheck;
            initOK = result;
            ret_val = initOK;
        }

        return ret_val;
    }

    /**
    * Uninitialize and get ready for shut down.
    */
    bool_t TADAlgoObject::Uninit()
    {
        bool_t ret_val = true;

        if( !initOK )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_isRunning )
            {
                Stop();
            }

            initOK = false;
            ret_val = true;
        }

        return ret_val;
    }

    /**
    * Start TAD.
    */
    bool_t TADAlgoObject::Start( TAD2::JobTADInput& i_jobinput )
    {
        bool_t ret_val = true;

        if( !initOK )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            // --- Init flags / variables
            InitJobOutput();
            //
            // --- Start top-level modules
            m_vehicleKinematicsObj.Start();
            m_preProcessingObj.Start();
            m_imageThresholdingObj.Start();
            m_featureExtractionObj.Start();

            if( 1 )
            {
                m_collisionAngleDetectionObj.Start();
            }

            // --- Start state machine
            m_stateMachine.Start( TAD2::State::TrailerRecognition, i_jobinput );
            m_jobOutput.TRSC_DIDOutput.IeTRSC_e_CamBlockSts = TeTRSC_e_CamBlockSts::TeTRSC_e_CamBlockSts_CameraClear;
            m_jobOutput.TRSC_TAD_output.MeTRSC_b_TrlrCalibDelayInfo = false;
            bool_t isTrailerLoaded_b = m_stateMachine.WasTrailerLoadedSuccessfully();
            m_jobDebugOutput.trailerLoadedSuccessfully = isTrailerLoaded_b;
            bool_t isHitchLoaded_b = m_stateMachine.WasHitchLoadedSuccessfully();
            m_jobDebugOutput.hitchLoadedSuccessfully = isHitchLoaded_b;
            bool_t isCollisionAngleLoaded_b = m_stateMachine.WascollisionangleLoadedSuccessfully();
            m_jobDebugOutput.collisionangleLoadedSuccessfully = isCollisionAngleLoaded_b;
            //
            m_isRunning = ( m_jobDebugOutput.error == 0 );
            ret_val = true;
        }

        return ret_val;
    }
    TeTRSC_e_TADState TADAlgoObject::getTADStateMachineState() const
    {
        return m_stateMachine.GetState();
    }

    TAD2::calibration::State::Enum TADAlgoObject::getTADStateMachineSubState() const
    {
        return static_cast<TAD2::calibration::State::Enum>( m_stateMachine.GetSubState() );
    }
    _roi::ROI TADAlgoObject::getROI() const
    {
        return m_processingROI;
    }
    /**
    * Stop TAD.
    */
    void TADAlgoObject::Stop()
    {
        bool_t ret_val = true;

        if( ( !initOK ) || ( !m_isRunning ) )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            // -- Stop state machine
            m_stateMachine.Stop();
            m_implicitCalibrationObj.Stop();
            //
            // --- Stop top-level modules
            m_vehicleKinematicsObj.Finish();
            m_preProcessingObj.Finish();
            m_imageThresholdingObj.Finish();
            m_featureExtractionObj.Finish();
            m_collisionAngleDetectionObj.Finish();
            //
            m_isRunning = false;
        }

        return;
    }

    /**
    * Reset TAD.
    *
    * Called after video change.
    */
    void TADAlgoObject::Reset( TAD2::JobTADInput& i_jobinput )
    {
#ifdef ME_PLATFORM_QNX
        ME_Thread_Sleep_t( 5 );
#endif
        Stop();
        assert( !memory::MemoryPool::CheckForMemoryLeak() );
#ifdef ME_PLATFORM_QNX
        ME_Thread_Sleep_t( 5 );
#endif
        Start( i_jobinput );
#ifdef ME_PLATFORM_QNX
        ME_Thread_Sleep_t( 5 );
#endif
    }

    float32_t TADAlgoObject::FindAverageIllumination( const uint8_t* i_topViewPtr )
    {
        float32_t avgValue = 0.0f;
        int32_t startX = 321;
        int32_t startY = 25;
        int64_t count = 0;

        for( int32_t i = ( startX - 60 ); i < ( startX + 60 ); i++ )
        {
            for( int32_t j = startY; j < ( startY + 100 ); j++ )
            {
                avgValue = avgValue + static_cast <float32_t>( i_topViewPtr[j * global::TOPVIEW_IMAGE_WIDTH + i] ); /* PRQA S 3706*/
                count++;
            }
        }

        avgValue = avgValue / ( static_cast <float32_t>( count ) );
        return( avgValue );
    }

    /**
     * Run TAD.
     */
    /*
     *    Name: IgnitionON
     *    Remarks: DD-ID: {BD0DB210-9822-4bd0-A567-D5109F9F8F55}
     */
    /*
     *    Name: TrailerDetection
     *    Remarks: DD-ID: {DAA6E848-81CD-4048-8A90-4FC46E502AC0}
     */
    /*
     *    Name: TurnaroundState_Wait
     *    Remarks: DD-ID: {E9CACA44-D055-42fd-8C71-E0038BAA936A}
     */
    /*
     *    Name: Calibration_DriveState
     *    Remarks: DD-ID: {BC539678-23BB-45fa-9CF7-664A8FE2E43F}
     */
    /*
     *    Name: Calibration
     *    Remarks: DD-ID: {2AD4B994-5642-4cd5-B60B-55A9A4B2EF8E}
     */
    /*
     *    Name: TurnaroundState_DriveState
     *    Remarks: DD-ID: {D40E2368-9014-44c5-A442-89E0F12F3955}
     */
    /*
     *    Name: AngleDetection
     *    Remarks: DD-ID: {991255F3-B01F-4c2c-BFBD-D2208C2DDF47}
     */
    /*
     *    Name: Detection_Component_Manager
     *    Remarks: DD-ID: {64B59525-B69B-4567-BEC8-BB9A3C2A0FC6}
     */
    /*
     *    Name: ScanningForTrailer
     *    Remarks: DD-ID: {55181765-F091-4d9c-AD05-EA5D5572E7EA}
     */
    /*
     *    Name: TrailerRecognition
     *    Remarks: DD-ID: {F39A508D-2483-452a-9DFA-C83A96F0D678}
     */
    /*
     *    Name: Calibration_TurnLeftOrRight
     *    Remarks: DD-ID: {4BFDD50B-9F63-493e-BC20-E0993AD546BC}
     */
    /*
     *    Name: TurnaroundState
     *    Remarks: DD-ID: {6868C23E-3185-4a40-BBD3-4A57F1522AD9}
     */
    /*
     *    Name: Trackinglost
     *    Remarks: DD-ID: {78648F34-FF6F-4182-B2FF-F5831E61202E}
     */
    /*
     *    Name: TurnaroundState_TurnLeftOrRight
     *    Remarks: DD-ID: {DA8331E5-455D-4877-9904-9998A0ACCF31}
     */
    /*
     *    Name: Calibration_Wait
     *    Remarks: DD-ID: {E7517470-961E-4969-BA70-FFE79449162A}
     */
    /*
     *    Name: Detection_Component_ManagerInit
     *    Remarks: DD-ID: {01FC6CFA-A4DD-45d6-B604-4AFBD5A52E87}
     */
    void TADAlgoObject::Run( int32_t i_frame, uint8_t* i_topViewPtr, const TAD2::RawVehicleData& i_VehData, const TAD2::RawKinematicData& i_KMData, Detection_Inputs_from_TRSC_t StatemachineInput, bool_t camBlockStatus )

    {
        bool_t ret_val = true;

        // --- Check if initialized
        if( !initOK )
        {
            ret_val = false;
        }

        if( i_topViewPtr == NULL )
        {
            ret_val = false;
        }

#if DISABLED_CODE

        if( i_rearViewPtr == NULL )
        {
            ret_val = false;
        }

#endif

        if( !m_stateMachine.IsRunning() )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            // -- Job output init
            m_jobDebugOutput.trailerRecalibrated = false;
            // topview
            image::Image<uint8_t> topView = image::Image<uint8_t>( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, i_topViewPtr, 1 );
            _roi::ROI processingROI = GetProcessingROI();
            //
            // --- Run top-level modules
            m_vehicleKinematicsObj.Run( i_frame, i_VehData, i_KMData );
            // --- Run state machine
            m_stateMachine.Run( i_frame, topView, processingROI, StatemachineInput );
            bool_t trailer_recalibration_done = false;
            m_jobDebugOutput.averageIllumination = m_stateMachine.Get_averageillumination();
            PreviousState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState;
            m_stateMachine.ResetTrailerImplicitlyCalibrated();

            // --- Run implicit calibration
            if( m_implicitCalibrationObj.IsRunning() )
            {
                if( static_cast<int8_t>( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState ) == static_cast<int8_t>( TAD2::State::AngleDetection ) )
                {
                    float32_t trailerAngle_f32 = m_stateMachine.GetTrailerAngle_deg();
                    bool_t isTrailerAngleKnown_b = m_stateMachine.IsTrailerAngleKnown();
                    m_implicitCalibrationObj.Run( i_frame, topView,
#ifdef WIN_2015_CODE
                                                  processingROI,
#endif
                                                  trailerAngle_f32, isTrailerAngleKnown_b, m_stateMachine.GethitchendrangePos() );
                }

                // --- Check for completion
                if( m_implicitCalibrationObj.IsTrailerCalibrated() )
                {
                    m_stateMachine.SetCalibratedTrailerImage( m_implicitCalibrationObj.GetCalibratedImage() );
                    // CHanged inside SetTrailerAngle to fit turnaround state
                    m_stateMachine.SetTrailerAngle( 90.0f );
                    m_stateMachine.SetAnlgeBuffer( 90.0f );
                    m_implicitCalibrationObj.Reset( true, m_stateMachine.GethitchendrangePos() );

                    // --- Set job output
                    if( m_jobDebugOutput.trailerCalibrated )
                    {
                        m_jobDebugOutput.trailerRecalibrated = true;
                    }

                    trailer_recalibration_done = true;
                    m_stateMachine.SetTrailerImplicitlyCalibrated();
                    m_jobDebugOutput.trailerCalibrated = true;
                }
            }

            // --- setting Trailer Calibration Enums ---
            // --- Update the implicit calibration flag in Tracking Lost State
            m_stateMachine.SetImplicitTrackingLostFlag( trailer_recalibration_done );
            // ++ TRSC Output updation
            TeTRSC_e_TADState state_e = m_stateMachine.GetState();
            m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState = state_e;
            CalibrationState_t subState_e = m_stateMachine.GetSubState();
            m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate = subState_e;
            m_jobOutput.TRSC_TAD_output.MeTRSC_e_TurnAroundSubState = m_stateMachine.GetTurnAroundSubState();
            float32_t trailerAngle_f32 = m_stateMachine.GetTrailerAngle_deg();
            m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle = trailerAngle_f32;

            // Trailer Angle rate
            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngleRate = abs( m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle - PreviousTrailerAngle_f32 );
                PreviousTrailerAngle_f32 = m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle;
            }
            else
            {
                PreviousTrailerAngle_f32 = 0.0f;
                m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngleRate = 0.0f;
            }

            // Recognition and calibration info
            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrRecogInfo = TeTRSC_e_TrlrRecogInfo::TeTRSC_e_TrlrRecogInfo_Known;
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo = TeTRSC_e_TrlrCalInfo::TeTRSC_e_TrlrCalInfo_Calibrated;
            }
            else
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrRecogInfo = TeTRSC_e_TrlrRecogInfo::TeTRSC_e_TrlrRecogInfo_Unknown;
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo = TeTRSC_e_TrlrCalInfo::TeTRSC_e_TrlrCalInfo_NotCalibrated;
            }

            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo == TeTRSC_e_TrlrCalInfo::TeTRSC_e_TrlrCalInfo_Calibrated )
            {
                if( ( 90.0f - trailerAngle_f32 ) > 0 )
                {
                    m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrAngSign = TrailerAngleSign_e::TrailerAngleSign_Anticlockwise;
                }
                else if( ( 90.0f - trailerAngle_f32 ) < 0 )
                {
                    m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrAngSign = TrailerAngleSign_e::TrailerAngleSign_Clockwise;
                }
            }
            else
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrAngSign = TrailerAngleSign_e::TrailerAngleSign_None;
            }

            // present state
            if( ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection ) ||
                ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Calibration ) ||
                ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_ScanningForTrailer ) ||
                ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround ) )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrPrsntInfo = TeTRSC_e_TrlrPrsntInfo::TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt;
            }
            else
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrPrsntInfo = TeTRSC_e_TrlrPrsntInfo::TeTRSC_e_TrlrPrsntInfo_NoTrlr;
            }

            // OTBL Recalibrate
            if( ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround )
                && ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TurnAroundSubState == TurnAroundState_t::TurnAroundState_TurnLeftOrRight ) )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_b_OBTLRecalibrate = true;
            }
            else
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_b_OBTLRecalibrate = false;
            }

            // current ID
            m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrailerID = m_stateMachine.GetCurrentTraielrID();

            if( ( m_jobDebugOutput.hitchCalibrated == true ) || m_jobDebugOutput.hitchLoadedSuccessfully || ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState > TeTRSC_e_TADState::TeTRSC_e_TADState_Calibration ) )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_m_HitchLength = m_stateMachine.GetHitchLength(); //PRQA S 3706
            }
            else
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_m_HitchLength = 0.0f;
            }

            bool_t isbeamlengthestimationdone = m_stateMachine.IsBeamLenghtEstimationDone();
            m_jobDebugOutput.beamLengthEstimationDone = isbeamlengthestimationdone;
            m_jobOutput.TRSC_TAD_output.MeTRSC_m_DetTrailerBeamLen = m_stateMachine.GetBeamLength();
            m_jobOutput.TRSC_TAD_output.MeTRSC_deg_DetJackKnifeAngle = m_stateMachine.GetJacknifeAngle();
            m_jobOutput.TRSC_TAD_output.MeTRSC_deg_DetJackknifeThrAngle = m_stateMachine.GetJacknifeThresAngle();
            m_jobOutput.TRSC_TAD_output.MeTRSC_cnt_TrlrCalibFailCntInfo = m_stateMachine.GetCalibrationFailCount();

            if( ( m_stateMachine.IsHitchrangcalculationdone() &&
                  m_stateMachine.GetSubState() == CalibrationState_t::CalibrationState_TurnLeftOrRight ) ||
                ( m_stateMachine.IsTurncompletedduringTurnAroundState() &&
                  m_stateMachine.GetTurnAroundSubState() == TurnAroundState_t::TurnAroundState_TurnLeftOrRight ) )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_b_TrlrCalibDelayInfo = true;
            }
            else if( m_stateMachine.GetSubState() == CalibrationState_t::CalibrationState_DriveStraight ||
                     m_stateMachine.GetTurnAroundSubState() == TurnAroundState_t::TurnAroundState_DriveStraight )
            {
                m_jobOutput.TRSC_TAD_output.MeTRSC_b_TrlrCalibDelayInfo = false;
            }

            // -- TRSC Output updation

            // ++ DID value updation
            // Trailer Tracking Confidence
            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection )
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_tracking_confidence = m_stateMachine.GetTrackingScore() * 100.0f;
            }
            else
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_tracking_confidence = 0.0f;
            }

            // trailer recognition confidence
            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection )
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_Recognition_Confidence = m_jobDebugOutput.scanningScore;
            }
            else
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_Recognition_Confidence = 0.0f;
            }

            // trailer calibration status
            m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_Status = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo;

            // trailer maeuver state
            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Calibration )
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_maneuver_State = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate;
                //m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle = 0;
                m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrAngSign = TrailerAngleSign_t::TrailerAngleSign_None;
            }
            else if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround )
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_maneuver_State = ( CalibrationState_t )m_jobOutput.TRSC_TAD_output.MeTRSC_e_TurnAroundSubState;
            }

            // calibration fail count
            m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_Fail_Count_Current_key_cycle = m_stateMachine.GetCalibrationFailCount();
            // calibration fail reason
            m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_Fail_Reason = m_stateMachine.GetCalibrationFailReason();

            // trailer calibration pass count
            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo == TeTRSC_e_TrlrCalInfo::TeTRSC_e_TrlrCalInfo_Calibrated )
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_Pass_Count_Current_key_cycle = m_stateMachine.GetTrailerPassCount();
            }
            else
            {
                m_jobOutput.TRSC_DIDOutput.Trailer_Calibration_Pass_Count = 0;
            }

            // trailer presence detection
            m_jobOutput.TRSC_DIDOutput.Trailer_Presence_detection = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrPrsntInfo;
            // trailer ID
            m_jobOutput.TRSC_DIDOutput.Trailer_Recognition_ID = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrailerID;
            // trailer known or unknown
            m_jobOutput.TRSC_DIDOutput.Trailer_known_or_Unknown = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrRecogInfo;
            // trailer angle
            m_jobOutput.TRSC_DIDOutput.Trailer_Angle_current = m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle;

            //trailer Detection Fail Info
            if( camBlockStatus )
            {
                m_jobOutput.TRSC_DIDOutput.trailerDetectionFailReason = DetectionFailInfo_t::DetectionFailInfo_OCCULSION;
            }
            else
            {
                if( m_jobOutput.TRSC_DIDOutput.Trailer_Presence_detection == TeTRSC_e_TrlrPrsntInfo::TeTRSC_e_TrlrPrsntInfo_Unknown )
                {
                    m_jobOutput.TRSC_DIDOutput.trailerDetectionFailReason = DetectionFailInfo_t::DetectionFailInfo_SNA;
                }
                else
                {
                    m_jobOutput.TRSC_DIDOutput.trailerDetectionFailReason = DetectionFailInfo_t::DetectionFailInfo_NONE;
                }
            }

            // -- DID value updation
            // ++ HMI Debug updation
            // TAD2 angle
            m_jobOutput.HMIOutput.trailerAngle = m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle;
            // trailer ID
            m_jobOutput.HMIOutput.CurrentTrailer_ID = m_jobOutput.TRSC_DIDOutput.Trailer_Recognition_ID;
            // turnaround sub state
            m_jobOutput.HMIOutput.turnaroundSubState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TurnAroundSubState;
            // current state
            m_jobOutput.HMIOutput.curState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState;
            // calibration substate
            m_jobOutput.HMIOutput.calibrationSubState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate;
            //
            m_jobOutput.HMIOutput.hitchLength = m_jobOutput.TRSC_TAD_output.MeTRSC_m_HitchLength;
            m_jobOutput.HMIOutput.beamLength = m_jobOutput.TRSC_TAD_output.MeTRSC_m_DetTrailerBeamLen;
            m_jobOutput.HMIOutput.JackknifeAngle = m_jobOutput.TRSC_TAD_output.MeTRSC_deg_DetJackKnifeAngle;
            m_jobOutput.HMIOutput.JackknifeThrAngle = m_jobOutput.TRSC_TAD_output.MeTRSC_deg_DetJackknifeThrAngle;
            //
            m_jobOutput.HMIOutput.Trailer_tracking_confidence = m_jobOutput.TRSC_DIDOutput.Trailer_tracking_confidence;
            m_jobOutput.HMIOutput.Trailer_Recognition_Confidence = m_jobOutput.TRSC_DIDOutput.Trailer_Recognition_Confidence;
            // hitch point
            m_jobOutput.HMIOutput.hitchpoint.cordX = m_jobDebugOutput.trailerCalibration.hitchPoint.x;
            m_jobOutput.HMIOutput.hitchpoint.cordY = m_jobDebugOutput.trailerCalibration.hitchPoint.y;
            //
            m_jobOutput.HMIOutput.wheelAngle = mecl::math::toDegrees_x( i_VehData.wheelAngle_rad );
            m_jobOutput.HMIOutput.vehicle_speed = i_VehData.speed_kmPh;
            // TAD Angle line
            float32_t angle_rad = mecl::math::toRadians_x( m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle );
            int32_t line_len = 140;

            if( ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection )
                || ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround ) )
            {
                m_jobOutput.HMIOutput.AngleON = true;
                m_jobOutput.HMIOutput.KinematicsON = true;
                m_jobOutput.HMIOutput.Start_HitchPoint.cordX = m_jobDebugOutput.trailerCalibration.hitchPoint.x;
                m_jobOutput.HMIOutput.Start_HitchPoint.cordY = m_jobDebugOutput.trailerCalibration.hitchPoint.y;
                m_jobOutput.HMIOutput.End_AnglePoint.cordX = m_jobOutput.HMIOutput.Start_HitchPoint.cordX + line_len * cos( angle_rad );
                m_jobOutput.HMIOutput.End_AnglePoint.cordY = m_jobOutput.HMIOutput.Start_HitchPoint.cordY + line_len * sin( angle_rad );

                if( ( ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Calibration ) && ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate == CalibrationState_t::CalibrationState_DriveStraight ) ) ||
                    ( ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround ) && ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate == CalibrationState_t::CalibrationState_DriveStraight ) ) ||
                    ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState == TeTRSC_e_TADState::TeTRSC_e_TADState_AngleDetection ) )
                {
                    line_len = 220;
                    angle_rad = mecl::math::toRadians_x( m_jobDebugOutput.rightCalibrationAngle );
                    m_jobOutput.HMIOutput.End_KniematicsPoint1.cordX = m_jobOutput.HMIOutput.Start_HitchPoint.cordX + line_len * cos( angle_rad );
                    m_jobOutput.HMIOutput.End_KniematicsPoint1.cordY = m_jobOutput.HMIOutput.Start_HitchPoint.cordY + line_len * sin( angle_rad );
                    angle_rad = mecl::math::toRadians_x( m_jobDebugOutput.leftCalibrationAngle );
                    m_jobOutput.HMIOutput.End_KniematicsPoint2.cordX = m_jobOutput.HMIOutput.Start_HitchPoint.cordX + line_len * cos( angle_rad );
                    m_jobOutput.HMIOutput.End_KniematicsPoint2.cordY = m_jobOutput.HMIOutput.Start_HitchPoint.cordY + line_len * sin( angle_rad );
                }
                else
                {
                    m_jobOutput.HMIOutput.KinematicsON = false;
                    m_jobOutput.HMIOutput.End_KniematicsPoint1.cordX = 0;
                    m_jobOutput.HMIOutput.End_KniematicsPoint1.cordY = 0;
                    m_jobOutput.HMIOutput.End_KniematicsPoint2.cordX = 0;
                    m_jobOutput.HMIOutput.End_KniematicsPoint2.cordY = 0;
                }
            }
            else
            {
                m_jobOutput.HMIOutput.AngleON = false;
                m_jobOutput.HMIOutput.KinematicsON = false;
                m_jobOutput.HMIOutput.Start_HitchPoint.cordX = 0;
                m_jobOutput.HMIOutput.Start_HitchPoint.cordY = 0;
                m_jobOutput.HMIOutput.End_AnglePoint.cordX = 0;
                m_jobOutput.HMIOutput.End_AnglePoint.cordY = 0;
                m_jobOutput.HMIOutput.End_KniematicsPoint1.cordX = 0;
                m_jobOutput.HMIOutput.End_KniematicsPoint1.cordY = 0;
                m_jobOutput.HMIOutput.End_KniematicsPoint2.cordX = 0;
                m_jobOutput.HMIOutput.End_KniematicsPoint2.cordY = 0;
            }

            // -- HMI Debug updation
            // --- Update output
            m_jobDebugOutput.trackingScore = m_stateMachine.GetTrackingScore();
            m_jobDebugOutput.hitchrangevalid = m_stateMachine.GetHitchrangevalid();

            if( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState >= TeTRSC_e_TADState::TeTRSC_e_TADState_Turnaround )
            {
                m_jobDebugOutput.trackingScore = m_jobDebugOutput.trackingScore * 100.0f;
            }
            else
            {
                m_jobDebugOutput.trackingScore = 0.0f;
            }

            float32_t scanningScore_f32 = m_stateMachine.GetScanningScore();
            m_jobDebugOutput.scanningScore = scanningScore_f32;
            bool_t isTrailerAngleKnown_b = m_stateMachine.IsTrailerAngleKnown();
            m_jobDebugOutput.trailerAngleValid = isTrailerAngleKnown_b;
            float32_t collisionAngle_f32 = m_stateMachine.GetCollisionAngle_deg();
            m_jobDebugOutput.collisionAngle = collisionAngle_f32;
            float32_t leftcollisionangle_f32 = m_stateMachine.GetleftCollisionAngle_deg();
            m_jobDebugOutput.leftcollisionangle = leftcollisionangle_f32;
            float32_t rightcollisionangle_f32 = m_stateMachine.GetrightCollisionAngle_deg();
            m_jobDebugOutput.rightcollisionangle = rightcollisionangle_f32;
            bool_t IsCollisionAngleKnown_b = m_stateMachine.IsCollisionAngleKnown();
            m_jobDebugOutput.collisionAngleValid = IsCollisionAngleKnown_b;
            m_jobDebugOutput.stateChanged = ( m_jobDebugOutput.prevState != m_stateMachine.GetState() );
            m_jobDebugOutput.subStateChanged = ( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate != m_stateMachine.GetSubState() );
            m_jobDebugOutput.isTurnCompletedinTurnAround = m_stateMachine.IsTurncompletedduringTurnAroundState();
            m_jobDebugOutput.isTrailerPredictionCompleted = m_stateMachine.IsTrailerPrecitionCompleted();
            TAD2::TrailerFeatures::Trailers trailerCalibration_st = m_stateMachine.GettrailerCalibration();
            m_jobDebugOutput.trailerCalibration = trailerCalibration_st;
            TAD2::TrailerFeatures trailerFeatures_st = m_stateMachine.GetTrailerFeatures();
            m_jobOutput.TRSC_NVM_Output.trailerFeatures = trailerFeatures_st;
            bool_t isCalibratingTrailer_b = m_stateMachine.IsCalibratingTrailer();
            m_jobDebugOutput.isTrailerCalibrating = isCalibratingTrailer_b;
            bool_t isCalibratingHitch_b = m_stateMachine.IsCalibratingHitch();
            m_jobDebugOutput.isHitchCalibrating = isCalibratingHitch_b;
            m_jobDebugOutput.isImplicitlyCalibrating = m_implicitCalibrationObj.IsCalibrating();
            m_jobDebugOutput.trailerCalibrated = m_stateMachine.IsTrailerCalibrated();
            m_jobDebugOutput.hitchCalibrated = m_stateMachine.IsHitchCalibrated();
            bool_t isTrailerDetectionComplete_b = m_stateMachine.IsTrailerDetectionComplete();
            m_jobDebugOutput.trailerDetectionComplete = isTrailerDetectionComplete_b;
            bool_t isTrailerPresent_b = m_stateMachine.IsTrailerPresent();
            m_jobDebugOutput.trailerDetected = isTrailerPresent_b;
            bool_t isTrailerPresentRecognitionstate_b = m_stateMachine.IsTrailerPresentRecognitionState();
            m_jobDebugOutput.trailerDetectedRecognitionState = isTrailerPresentRecognitionstate_b;
            bool_t isTurnaroundComplete_b = m_stateMachine.IsTurnaroundComplete();
            m_jobDebugOutput.turnaroundComplete = isTurnaroundComplete_b;
            bool_t isTrackingLostRunning_b = m_stateMachine.IsTrackingLostRunning();
            m_jobDebugOutput.isTrackingLostRunning = isTrackingLostRunning_b;

            if( m_implicitCalibrationObj.IsCalibrating() )
            {
                m_implicitCalibrationObj.GetCalibrationAngles( m_jobDebugOutput.leftCalibrationAngle, m_jobDebugOutput.rightCalibrationAngle );
            }
            else
            {
                m_stateMachine.GetCalibrationAngles( m_jobDebugOutput.leftCalibrationAngle, m_jobDebugOutput.rightCalibrationAngle );
                float32_t HitchCalibrationAngle_f32 = m_stateMachine.GetHitchCalibrationAngle();
                m_jobDebugOutput.hitchCalibrationAngle = HitchCalibrationAngle_f32;
                m_jobDebugOutput.dummy_angle_1 = m_stateMachine.GetDummyAngle1();
                m_jobDebugOutput.dummy_angle_2 = m_stateMachine.GetDummyAngle2();
                m_jobDebugOutput.dummy_angle_3 = m_stateMachine.GetDummyAngle3();
                m_jobDebugOutput.dummy_angle_4 = m_stateMachine.GetDummyAngle4();
                m_jobDebugOutput.hitch_range_calculation_done = m_stateMachine.IsHitchrangcalculationdone();
                m_jobDebugOutput.hitch_range_pos = m_stateMachine.GetHitchrangePos();
            }

            m_jobDebugOutput.bumper_pos = m_stateMachine.GetbumperPos();
            m_jobDebugOutput.hitch_end_range_pos = m_stateMachine.GethitchendrangePos();
        }

        // --- Start implicit calibration

        if( m_jobDebugOutput.stateChanged && ( static_cast<int8_t>( m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState ) == static_cast<int8_t>( TAD2::State::AngleDetection ) ) )
        {
            if( m_config.getImplicitCalibrationConfigParamsRef().getEnableContinuousCalibration() && !m_implicitCalibrationObj.IsRunning() )
            {
                m_implicitCalibrationObj.Start( true, m_stateMachine.GethitchendrangePos() );
                m_implicitCalibrationObj.SetHitchPoint( m_jobDebugOutput.trailerCalibration.hitchPoint );
            }
        }

        tadOutput = m_jobOutput;

        if( m_jobDebugOutput.stateChanged && ( static_cast<int8_t>( m_jobDebugOutput.prevState ) == static_cast<int8_t>( TAD2::State::AngleDetection ) ) )
        {
            m_implicitCalibrationObj.Stop();
        }

        m_jobDebugOutput.prevState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState;
        m_jobDebugOutput.prevSubState = m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate;
        return;
    }

    /**
    * Get the most recent results.
    */
    void TADAlgoObject::GetOutput( TAD2::JobTADOutput& o_output ) const
    {
        o_output = m_jobOutput;
    }

    /**
    * Get the most recent results.
    */
    TAD2::JobTADOutput TADAlgoObject::GetOutput() const
    {
        return m_jobOutput;
    }

    /**
    * Get the most recent results.
    */
    void TADAlgoObject::GetDebugOutput( JobTADDebugOutput& o_Debugoutput ) const
    {
        o_Debugoutput = m_jobDebugOutput;
    }

    /**
    * Get the most recent results.
    */
    JobTADDebugOutput TADAlgoObject::GetDebugOutput() const
    {
        return m_jobDebugOutput;
    }

    /*
    * Set error and error message.
    */
    void TADAlgoObject::SetError( int32_t i_error, const char* i_errorMessage )
    {
        if( i_error > m_jobDebugOutput.error )
        {
            m_jobDebugOutput.error = i_error;
            strncpy( reinterpret_cast<char*>( m_jobDebugOutput.errorMessage ), i_errorMessage, sizeof( m_jobDebugOutput.errorMessage ) - 1 );
            m_jobDebugOutput.errorMessage[sizeof( m_jobDebugOutput.errorMessage ) - 1] = '\0';
        }
    }

    /*
    * Calculate the necessary region where all processing will be done, for
    * both state machines.
    */
    _roi::ROI TADAlgoObject::GetProcessingROI()
    {
        bool_t isReturned = true;
        _roi::ROI ret_val;

        if( !m_stateMachine.IsRunning() )
        {
            ret_val = _roi::ROI();
            isReturned = false;
        }

        if( isReturned )
        {
            _roi::ROI processingROI1 = m_stateMachine.GetProcessingROI();
            ret_val = processingROI1;
        }

        return ret_val;
    }



    /*
    * Perform a sanity check for invalid files or parameters.
    */
    bool_t TADAlgoObject::SanityCheck()

    {
        bool_t ret_val = true;

        if( ( m_warpedTopViewParams.height > global::TOPVIEW_IMAGE_HEIGHT ) || ( m_warpedTopViewParams.width > global::TOPVIEW_IMAGE_WIDTH ) )
        {
            SetError( 3, "Invalid warped topview look-up table." );
            ret_val = false;
        }

        if( ret_val )
        {
            if( ( mask::TemplateWeightMaskSize[0] != global::TEMPLATE_IMAGE_HEIGHT ) || ( mask::TemplateWeightMaskSize[1] != global::TEMPLATE_IMAGE_WIDTH ) )
            {
                SetError( 3, "Invalid template weight mask." );
                ret_val = false;
            }
        }

        return ret_val;
    }

    /**
    * Reset job output.
    */
    void TADAlgoObject::InitJobOutput()
    {
        for( uint32_t i = 0; i < TrailerID_e::Trailer_MAX; i++ )
        {
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].trailerTemplate.setData( NULL );
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].Is_Valid = false;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].hitchPoint.x = 0;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].hitchPoint.y = 0;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].UsedCount = 0;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].HitchLength = 0;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].CollisionAngle = 0;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].BeamLength = 0.0f;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].JacknifeAngle = 0;
            m_jobOutput.TRSC_NVM_Output.trailerFeatures.TrailerData[i].JacknifeThreshAngle = 0;
        }

        m_jobDebugOutput.trailerCalibration.trailerTemplate.setData( NULL );
        m_jobDebugOutput.trailerCalibration.UnwarpedImage.setData( NULL );
        m_jobDebugOutput.trailerCalibration.hitchPointValid = false;
        m_jobDebugOutput.trailerCalibration.CollisionAngleValid = false;
        m_jobOutput.TRSC_TAD_output.MeTRSC_deg_TADAngle = 0.0f;
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrPrsntInfo = TeTRSC_e_TrlrPrsntInfo::TeTRSC_e_TrlrPrsntInfo_Unknown;
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrCalInfo = TeTRSC_e_TrlrCalInfo::TeTRSC_e_TrlrCalInfo_Undefined;
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrlrAngSign = TrailerAngleSign_t::TrailerAngleSign_None;
        m_jobDebugOutput.trailerAngleValid = true;
        m_jobDebugOutput.hitchCalibrationAngle = 90.0f;
        m_jobDebugOutput.dummy_angle_1 = 90.0f;
        m_jobDebugOutput.dummy_angle_2 = 90.0f;
        m_jobDebugOutput.dummy_angle_3 = 90.0f;
        m_jobDebugOutput.dummy_angle_4 = 90.0f;
        m_jobDebugOutput.hitch_range_pos = 0;
        m_jobDebugOutput.bumper_pos = 0;
        m_jobDebugOutput.hitch_end_range_pos = 100;
        m_jobDebugOutput.hitch_range_calculation_done = false;
        m_jobOutput.TRSC_TAD_output.MeTRSC_m_DetTrailerBeamLen = 0.0f;
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TrailerID = TrailerID_t::Trailer_MAX;
        //
        m_jobDebugOutput.hitchrangevalid = true;
        m_jobDebugOutput.trailerLoadedSuccessfully = false;
        m_jobDebugOutput.hitchLoadedSuccessfully = false;
        m_jobDebugOutput.collisionangleLoadedSuccessfully = false;
        m_jobDebugOutput.isTrailerCalibrating = false;
        m_jobDebugOutput.isHitchCalibrating = false;
        m_jobDebugOutput.isImplicitlyCalibrating = false;
        m_jobDebugOutput.trailerCalibrated = false;
        m_jobDebugOutput.trailerRecalibrated = false;
        m_jobDebugOutput.hitchCalibrated = false;
        m_jobDebugOutput.isTurnCompletedinTurnAround = false;
        m_jobDebugOutput.isTrailerPredictionCompleted = false;
        m_jobDebugOutput.beamLengthEstimationDone = false;
        //
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADState = TeTRSC_e_TADState::TeTRSC_e_TADState_Idle;
        m_jobDebugOutput.prevState = TeTRSC_e_TADState::TeTRSC_e_TADState_Idle;
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TurnAroundSubState = TurnAroundState_t::TurnAroundState_DriveStraight;
        m_jobOutput.TRSC_TAD_output.MeTRSC_e_TADCalibrationSubstate = CalibrationState_t::CalibrationState_DriveStraight;
        m_jobDebugOutput.prevSubState = 0;
        m_jobDebugOutput.stateChanged = true;
        m_jobDebugOutput.subStateChanged = true;
        //
        m_jobDebugOutput.error = 0;
    }

}
