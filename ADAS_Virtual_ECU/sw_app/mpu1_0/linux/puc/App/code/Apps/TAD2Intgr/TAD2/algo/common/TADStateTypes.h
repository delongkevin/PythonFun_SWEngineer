// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TAD_STATE_TYPES__H_
#define __TAD_STATE_TYPES__H_

/*
* State events and output, state machine typedefs, state wrappers to
* make code more readable.
*/

#include "TADState.h"
#include "Image.h"
#include <mecl/core/MeclTypes.h>
#ifdef _WINDOWS_
    #include <TRSC_Inputs_Outputs.h>
#else
    #include "TRSC_Inputs_Outputs.h"
#endif

/// TAD2
namespace TAD2
{
    class TADStateMachine;

    /** Top level TAD state event. **/
    struct Event
    {
        uint32_t frame;
        image::Image<uint8_t> topView;
        _roi::ROI roi;

        float32_t currentTrailerAngle_deg;
        bool_t trailerAngleKnown;
        bool_t trailerTemplateUpdated;
        Detection_Inputs_from_TRSC_t StatemachineInput;
    };

    /** Top level TAD state output. **/
    struct Output
    {
        float32_t detectedAngle_deg;
        Point2i detectedHitchPoint;
        float32_t detectedhitchlength;
        float32_t detectedCollisionAngle;
        float32_t detectedBeamLength;
        float32_t detectedJacknifeAngle;
        float32_t detectedJacknifeThreshAngle;
        float32_t angleScore;
        float32_t timeInState_s;
        float32_t distanceTravelledInState_m;
        bool_t Trailer_Present;

        bool_t detectedhitchrangeValid;
        bool_t detectedAngleValid;
        bool_t detectedHitchPointValid;
        bool_t detectedCollisionAngleValid;
        bool_t detectedBeamLengthValid;
        bool_t detectedAbsencePresenceValid;
        bool_t usingDummyHitchPoint;
    };

    /** Top level TAD state machine. **/
    typedef TADStateMachine StateMachine;




    /// TRSC-statemachine state
    namespace Statemachine
    {
        /** TurnAround state. **/
        struct State
        {
            enum Enum
            {
                Off,
                Standby,
                Calibrating,
                PreActive,
                Active,
                ActiveHoldOvr,
                Fault,
                SNA
            };
        };
        struct TrailerPresent
        {
            enum Enum
            {
                Present,
                Not_Present,
                SNA,
            };
        };
    }
    /// TAD2::calibration
    namespace calibration
    {
        /** Calibration state. **/
        struct State
        {
            enum Enum
            {
                DriveStraight,
                TurnLeftOrRight,
                Wait
            };
        };
    } /// TAD2::calibration
    /// TAD2::TurnAround
    namespace turnaround
    {
        /** TurnAround state. **/
        struct State
        {
            enum Enum
            {
                DriveStraight,
                TurnLeftOrRight,
                Wait
            };
        };
    } /// TAD2::TurnAround

    /// TAD2::Recognition Info
    namespace trailerinfo
    {
        /** RecognitionInfo **/
        struct RecognitionInfo
        {
            enum Enum
            {
                unknown,
                known
            };
        };
        /** TrailerPresentInfo **/
        struct TrailerPresentInfo
        {
            enum Enum
            {
                UNKNOWN,
                NO_TRAILER,
                TRAILERPRESENT
            };
        };
        /** TrailerCalibrationFailInfo **/
        struct TrailerCalibrationFailInfo
        {
            enum Enum
            {
                No_Failure,
                Camera_Blocked,
                Gear_IN_Reverse
            };
        };
        struct DetectionFailInfo
        {
            enum Enum
            {
                SNA,
                NONE,
                OCCULSION
            };
        };
        /** TrlrCalInfo **/
        struct TrlrCalInfo
        {
            enum Enum
            {
                NotCalibrated,
                Calibrated,
                undefined
            };
        };
        /** TrailerAngleSign **/
        struct TrailerAngleSign
        {
            enum Enum
            {
                Clockwise,
                Anticlockwise,
                None
            };
        };
    } /// TAD2::RecognitionInfo

    /** Top level TAD state. **/
    struct State : public TADState<StateMachine, TAD2::Event, TAD2::Output>
    {
        explicit State( StateMachine* i_stateMachine ) :
            TADState<StateMachine, TAD2::Event, TAD2::Output>( i_stateMachine ) {};
        enum Enum
        {
            Idle,
            TrailerDetection,
            TrailerRecognition,
            Calibration,
            ScanningForTrailer,
            Turnaround,
            AngleDetection,
            Trackinglost
        };
    };

} /// TAD2

#endif // !__TAD_STATE_TYPES__H_
