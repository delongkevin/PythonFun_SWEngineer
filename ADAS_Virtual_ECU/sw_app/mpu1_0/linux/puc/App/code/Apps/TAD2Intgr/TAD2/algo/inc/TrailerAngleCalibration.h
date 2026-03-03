// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [07-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TRAILER_ANGLE_CALIBRATION_H
#define __TRAILER_ANGLE_CALIBRATION_H

#ifdef __QNX__
    #include "../common/config.h"
    #include "../common/CircularBuffer.h"
#else
    #include "common/config.h"
    #include "common/CircularBuffer.h"
#endif
#include "VehicleKinematics.h"

namespace constants
{
    // --- Constants
    static const float32_t c_maxTrailerBeamLength_mm = 20000.0f;
    static const float32_t c_minTrailerBeamLength_mm = 1000.0f;
    static const float32_t c_trailerBeamLengthAdj_mm = 1000.0f;
    static const float32_t c_maxAbsTrailerAngle_deg = 110.0f;
}
/*
* Modified version of 'TrailerKinematicModel' which can be used to calibrate the
* angle of a trailer.
*
* This model uses a different beamlength when the vehicle towing
* it is in reverse then when it is in drive. It also has a min and max angle value
* which it cannot go beyond.
*/
namespace TAD2
{
    class TrailerCalibrationModel
    {
    public:
        TrailerCalibrationModel();
        virtual ~TrailerCalibrationModel();

        // --- Exposed functions
        bool_t Init( const TAD2::VehicleParameters& i_vehicleParams, float32_t i_beamLengthWhenMovingForward_mm, float32_t i_beamLengthWhenInReverse_mm, float32_t i_maxTrailerAngle_deg, float32_t i_minTrailerAngle_deg );
        void Run( int32_t i_frame, const TAD2::VehicleKinematics& i_vehicle, bool_t i_isTrackingLost );
        bool_t Start( float32_t i_startAngle_deg );
        void Finish();


        // --- Setters
        float32_t getAngle_deg() const;
        void setAngle_deg( float32_t i_angle_deg );

    private:

        bool_t m_initOK;
        bool_t m_isRunning;
        int32_t m_lastFrameRun;
        // --- Module specific variables
        TAD2::VehicleParameters m_vehicleParams;
        TAD2::TrailerParameters m_trailerParams;
        float32_t m_currentAngle_rad;

        float32_t m_beamLengthWhenMovingForward_mm;
        float32_t m_beamLengthWhenInReverse_mm;

        float32_t m_maxTrailerAngle_rad;
        float32_t m_minTrailerAngle_rad;

        float32_t _CalculateSteadyStateAngle( float32_t i_wheelAngle_deg ) const;

    };

    /*
    * Trailer angle calibration module.
    *
    * Determines when the angle of the trailer is straight back, or 0 degrees.
    */
    class TrailerAngleCalibration
    {
    public:
        TrailerAngleCalibration();
        ~TrailerAngleCalibration();

        // --- Exposed functions
        bool_t Init( const TAD2::VehicleParameters& i_vehicleParams, tad2config::CANAndVehicleConfigData i_CANconfig );
        bool_t Start( float32_t i_initialAngle, float32_t i_tolerance );
        void Finish();

        void Run( uint32_t i_frame, const VehicleKinematics* i_vehicle, bool_t i_isTrackingLost );
        void QuickCalibrate( float32_t i_trailerAngle_deg, float32_t i_maxAngleOffset );

        // --- Getters / Setters
        void GetCalibrationAngles( float32_t& o_left, float32_t& o_right ) const;
        bool_t TrailerAngleCalibrated() const;
        bool_t isTrailerStraight();

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;



        // --- Module specific variables
        TrailerCalibrationModel m_leftTrailer;
        TrailerCalibrationModel m_rightTrailer;
        float32_t m_angleTolerance_mm;

        // -- buffer for left and right side angle
        static const uint32_t c_bufSize = 30;
        buffer::CircularBuffer<float32_t, c_bufSize> m_leftangle;
        buffer::CircularBuffer<float32_t, c_bufSize> m_rightangle;

        void average_val_buffer( float32_t& left_buffer, float32_t& right_buffer );

        // Original 1.0f

    };
}
#endif // !__TRAILER_ANGLE_CALIBRATION_H
