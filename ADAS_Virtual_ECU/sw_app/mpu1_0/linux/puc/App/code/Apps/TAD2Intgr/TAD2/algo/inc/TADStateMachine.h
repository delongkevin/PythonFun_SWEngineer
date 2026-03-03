// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TAD_STATE_MACHINE_H
#define __TAD_STATE_MACHINE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
    #include "../common/TADStructures.h"
    #include "../common/Image.h"
    #include "TrailerRecognitionState.h"
#else
    #include "common/TADStateTypes.h"
    #include "common/TADStructures.h"
    #include "common/Image.h"
    #include <algo\inc\TrailerRecognitionState.h>
#endif
#include "JobTADInput.h"

#include "IdleState.h"
#include "TrailerDetectionState.h"
#include "CalibrationState.h"
#include "ScanningState.h"
#include "TrackingLostState.h"
#include "AngleDetectionState.h"
#include "TurnaroundState.h"
#include "FeatureExtraction.h"
#include "ImageThresholding.h"

namespace TAD2
{
    /** TAD state machine. **/
    class TADAlgoObject;

    class TADStateMachine
    {
    public:
        typedef TAD2::State State;
        typedef TAD2::Event Event;
        typedef TAD2::Output Output;

        TADStateMachine( tad2config::TADConfigData& i_config, const TAD2::VehicleParameters& i_vehicleParams, TAD2::TADAlgoObject* i_pAlgoObj, TAD2::VehicleKinematics* i_pVehicleKinematics, TAD2::PreProcessing* i_pPreProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction, cAngleDetection::CollisionAngleDetection* i_pCollisionAngleDetection );

        virtual ~TADStateMachine();

        // --- Exposed Functions
        void Start( TAD2::State::Enum i_entryState, TAD2::JobTADInput& i_jobinput );
        void Stop();
        void Run( uint32_t i_frame, image::Image<uint8_t>& i_topView, _roi::ROI& i_roi, Detection_Inputs_from_TRSC_t StatemachineInput );

        _roi::ROI GetProcessingROI();
        void UpdateWarpedTemplate();

        // --- Config getters
        bool_t KinematicsEnabled() const;
        bool_t CollisonAngleDetectionEnabled() const;
        bool_t IsRunning() const;
        const TAD2::VehicleParameters& GetVehicleParams() const;
        const TAD2::WarpedTopViewParameters& GetWarpedTopViewParams() const;
        tad2config::CANAndVehicleConfigData GetVehicleConfigData();


        // --- Variable getters
        bool_t IsTrailerAngleKnown() const;
        bool_t IsCollisionAngleKnown() const;
        bool_t WasTrailerLoadedSuccessfully() const;
        bool_t WasHitchLoadedSuccessfully() const;
        bool_t WascollisionangleLoadedSuccessfully() const;
        bool_t IsTrailerDetectionComplete() const;
        bool_t CalibrateTrailer() const;
        bool_t IsTrailerPresent() const;
        bool_t IsTrailerPresentRecognitionState() const;
        bool_t IsTrailerCalibrated() const;
        bool_t IsHitchCalibrated() const;
        bool_t IsCalibratingTrailer() const;
        bool_t IsTrackingLostRunning() const;
        bool_t IsCalibratingHitch() const;
        bool_t IsTurnaroundComplete() const;
        bool_t IsBeamLenghtEstimationDone() const;
        bool_t IsTrailerImplicitlyCalibrated() const;
        bool_t IsHitchrangcalculationdone() const;
        bool_t IsTurncompletedduringTurnAroundState() const;
        bool_t IsTrailerPrecitionCompleted() const;
        float32_t GetTrailerAngle_deg();
        float32_t GetHitchrangevalid() const;
        float32_t GetTrackingScore() const;
        float32_t GetBeamLength() const;
        int32_t GetInputTrailerID() const;
        int32_t GetConfigTrailerID() const;
        uint32_t GetHitchLength() const;
        float32_t GetJacknifeAngle() const;
        uint32_t GetJacknifeThresAngle() const;
        float32_t GetScanningScore() const;
        float32_t GetCollisionAngle_deg() const;
        float32_t GetleftCollisionAngle_deg() const;
        float32_t GetrightCollisionAngle_deg() const;
        uint8_t GetHitchrangePos() const;
        TAD2::TrailerFeatures GetTrailerFeatures() const;
        TAD2::TrailerFeatures::Trailers GettrailerCalibration() const;
        image::Image<uint8_t> GetUnwarpedTrailerTemplate() const;
        TAD2::TrailerTemplate GetTrailerTemplate() const;
        Point2i GetHitchPoint();
        int32_t GetTrailerPassCount();
        void GetCalibrationAngles( float32_t& o_left, float32_t& o_right ) const;
        float32_t GetHitchCalibrationAngle() const;
        float32_t GetDummyAngle1() const;
        float32_t GetDummyAngle2() const;
        float32_t GetDummyAngle3() const;
        float32_t GetDummyAngle4() const;
        TeTRSC_e_TADState GetState() const;
        CalibrationState_t GetSubState() const;
        TurnAroundState_t GetTurnAroundSubState() const;
        float32_t GetVehicleSpeed() const;
        Point2i Get_hitch_Config_Point() const;
        uint32_t GetbumperPos() const;
        uint32_t GethitchendrangePos() const;
        TrailerID_t GetCurrentTraielrID() const;
        float32_t GetPixel2mmconversion() const;
        uint32_t GetCalibrationFailCount() const;
        TrailerCalibrationFailInfo_e GetCalibrationFailReason() const;
        bool_t GetTrailerPresenceDetectionDone() const;
        float32_t Get_averageillumination() const;
        bool_t Get_IsTrailerAngleUpdating() const;

        // --- Setters
        void Set_IsTrailerAngleUpdating( bool_t _isUpdating );
        void SetTrailerPresenceDetectionDone( bool_t _iscomplete );
        void Set_averageillumination( float32_t val );
        void SetCalibrationFailCount( uint32_t count );
        void SetCalibrationFailReason( TrailerCalibrationFailInfo_e i_TrailerCalFailInfo );
        void SetTrailerTemplatefeatures( TAD2::TrailerFeatures::Trailers i_features );
        void SetImplicitTrackingLostFlag( bool_t running );
        void SetAnlgeBuffer( float32_t angle );
        void SetCalibratedTrailerImage( const image::Image<uint8_t>& i_trailerImage );
        void SetCalibratedunwarpedTrailerImage( const image::Image<uint8_t>& i_trailerImage );
        void SetTrailerDetectionComplete( bool_t is_complete );
        void SetTurnaroundComplete();
        void SetBeamLengthEstimationDone();
        void SetTurnCompletedDuringTurnAround( bool_t i_turncompleted );
        void SetTrailerPredictionCompleted();
        void SetTrailerDetected( bool_t i_trailerDetected );
        void SetTrailerDetectedRecognitionState( bool_t i_trailerDetected );
        void SetTrailerCalibrated();
        void SetHitchCalibrated();
        void SetTrailerImplicitlyCalibrated();
        void SetTrailerAngle( float32_t i_trailerAngle );
        void SetScanningScore( float32_t i_score );
        void SetCollisionAngle( float32_t i_collisionAngle, float32_t i_leftcollisionangle, float32_t i_rightcollisionangle );
        void SetCalibrationAngles( float32_t i_left, float32_t i_right );
        void SetHitchCalibrationAngle( float32_t i_angle );
        void SetHitchPos( uint8_t Pos );
        void SetHitchrangecalculated( bool_t val );
        void SetDummyAngle( float32_t i_angle1, float32_t i_angle2, float32_t i_angle3, float32_t i_angle4 );
        void SetError( int32_t i_error, const char* i_errorMessage );
        void SetbumperPos( uint32_t Pos );
        void Set_confighitchXpos( uint32_t val ) const;
        void Set_configbumperpos( uint32_t val ) const;
        void Set_NewTrailerFeatures( TAD2::TrailerTemplate i_trailerTemplate, Point2i i_hitch_point, uint32_t i_CollisionAngle, float32_t i_BeamLength, uint32_t i_JacknifeAngle, uint32_t i_jacknifethreshAngle );
        void SetCurrentTraielrID( TrailerID_e i_CurrentTrailer_ID );
        void SetCalculateHitchLength( uint32_t hitchYpos );
        void SetTempHitchPos( Point2i hitchPos, bool_t i_valid );
        void SetTrailerUsedCount( uint32_t i_trailerCount );
        void SetTrailerTemplate( image::Image<uint8_t> i_templates );
        void SetCalibrationDataReset();

        // Reset
        void ResetTurnaroundState();
        void ResetCalibrationState();
        void ResetTrailerImplicitlyCalibrated();

        //
        float32_t FindAverageIllumination( image::Image<uint8_t>& i_warpedview, _roi::ROI& i_roi );

    private:
        bool_t m_isRunning;
        bool_t m_trailerTemplateUpdated;

        // --- Current state
        TAD2::State* m_state;

        // --- Config params
        tad2config::TADConfigData& m_config;
        const TAD2::VehicleParameters& m_vehicleParams;
        TAD2::WarpedTopViewParameters m_warpedTopViewParams;

        // --- Variables and flags
        TrailerID_t CurrentTrailer_ID;
        TAD2::TrailerFeatures m_trailerFeatures;
        TAD2::TrailerFeatures::Trailers m_trailerCalibration;
        bool_t m_trailerLoadedSuccessfully;
        bool_t m_hitchLoadedSuccessfully;
        bool_t m_collisionangleLoadedSuccessfully;
        bool_t m_beamLengthLoadedSuccessfully;
        bool_t m_detectCollisionAngle;
        bool_t m_CalibrateTrailer;
        Point2i m_temphitch_pos;

        bool_t m_trailerDetectionComplete;
        bool_t m_trailerDetected;
        bool_t m_trailerDetectedrecognitionstate;//M_TrailerRecognized
        bool_t m_trailerCalibrated;
        bool_t m_hitchCalibrated;
        bool_t m_dynamicTemplateEnabled;
        bool_t m_turnaroundComplete;
        bool_t m_beamLengthEstimationDone;
        bool_t m_trailerImplicitlyCalibrated;
        bool_t m_turnCompletedDuringTurnAroundState;
        bool_t m_trailerPredictionCompleted;
        bool_t m_trailerPresenceDetectionDone;
        bool_t m_IsTrailerAngleUpdating;

        bool_t m_trailerAngleKnown;
        bool_t m_collisionAngleKnown;
        bool_t m_hitchrangevalid;
        float32_t m_trailerAngle_deg;
        float32_t m_trackingScore;
        float32_t m_scanningScore;
        float32_t m_collisionAngle;
        float32_t m_leftcollisionangle;
        float32_t m_rightcollisionangle;
        float32_t m_leftCalibrationAngle;
        float32_t m_rightCalibrationAngle;
        float32_t m_hitchCalibrationAngle;
        uint8_t m_hitch_pos;
        uint32_t m_bumper_pos;
        uint32_t m_hitch_end_pos;
        bool_t m_hitch_range_calculated;
        float32_t m_dummy_angle_1;
        float32_t m_dummy_angle_2;
        float32_t m_dummy_angle_3;
        float32_t m_dummy_angle_4;
        uint32_t m_hitchendrangePos;
        float32_t m_Pixel2mmconversionval;
        int32_t m_calibrationFailCount;
        TrailerCalibrationFailInfo_e TrailerCalFailInfo;
        float32_t m_averageIllumination;
        // trailer ID
        int32_t InputTrailerID;
        int32_t ConfigTrailerID;

        // --- Top-Level Modules
        TAD2::VehicleKinematics* m_pVehicle;
        TAD2::PreProcessing* m_pPreProcessing;
        TAD2::ImageThresholding* m_pImageThresholding;
        TAD2::FeatureExtraction* m_pFeatureExtraction;
        cAngleDetection::CollisionAngleDetection* m_pCollisionAngleDetection;

        // --- State objects
        Idle::IdleState m_stateIdle;
        TrailerState::TrailerDetectionState m_stateTrailerDetection;
        RecognitionState::TrailerRecognitionState m_stateTrailerRecognition;
        Calibration::CalibrationState m_stateCalibration;
        AngleDetectionState m_stateAngleDetection;
        Scanning::ScanningState m_stateScanning;
        TrackingState::TrackingLostState m_TrackingLost;
        TurnAround::TurnaroundState m_stateTurnaround;

        // --- Algo object
        TADAlgoObject* m_pAlgoObj;

        // --- Private functions
        void LoadCalibration( TAD2::TrailerFeatures& i_trailerFeatures );
        void ProcessOutput( TAD2::Output& o );
        TAD2::State* StateMap( int32_t i );
        void UpdateTrailerTemplate();

    };
}

#endif // !__TAD_STATE_MACHINE_H
