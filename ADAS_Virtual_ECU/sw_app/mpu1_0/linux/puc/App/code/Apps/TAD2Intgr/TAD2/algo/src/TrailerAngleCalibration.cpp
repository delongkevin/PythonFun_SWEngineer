// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [07-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "TrailerAngleCalibration.h"
#include "TADStructures.h"
#include "VehicleKinematics.h"
#include "WarpLUT.h"

namespace TAD2
{

    /*
    * Constructor.
    */
    TrailerAngleCalibration::TrailerAngleCalibration() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 ),
        m_angleTolerance_mm( 1.0f )
    {
    }

    /*
    * Destructor.
    */
    TrailerAngleCalibration::~TrailerAngleCalibration()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t TrailerAngleCalibration::Init( const TAD2::VehicleParameters& i_vehicleParams, tad2config::CANAndVehicleConfigData i_CANconfig )
    {
        // --- Initialize trailer models
        float32_t min_deg = TAD2::getWarpedTopViewParams().start_deg;
        float32_t max_deg = TAD2::getWarpedTopViewParams().start_deg + TAD2::getWarpedTopViewParams().range_deg;
        m_leftTrailer.Init( i_vehicleParams, i_CANconfig.getBeamLengthRange_mmRef()[1], i_CANconfig.getBeamLengthRange_mmRef()[0], min_deg, 90.0f ); //PRQA S 3706
        m_rightTrailer.Init( i_vehicleParams, i_CANconfig.getBeamLengthRange_mmRef()[1], i_CANconfig.getBeamLengthRange_mmRef()[0], 90.0f, max_deg ); //PRQA S 3706
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t TrailerAngleCalibration::Start( float32_t i_initialAngle, float32_t i_tolerance )
    {
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            if( m_isRunning )
            {
                Finish();
            }

            m_angleTolerance_mm = i_tolerance;
            // -- Initialize the value in Cirular Buffer
            uint32_t leftangle_u32 = m_leftangle.size();

            for( uint32_t i = 0; i < leftangle_u32; i++ )
            {
                m_leftangle.push( 100.0 );
                m_rightangle.push( 100.0 );
            }

            // debug
            bool_t result = true;

            if( i_initialAngle < 0.0f )
            {
                bool_t v_temp_b = m_leftTrailer.Start( 90.0f + constants::c_maxAbsTrailerAngle_deg );
                bool_t v_temp2_b = m_rightTrailer.Start( 90.0f - constants::c_maxAbsTrailerAngle_deg );
                result = v_temp_b && v_temp2_b;
            }
            else
            {
                float32_t initialAngle = mms::minimum( i_initialAngle, constants::c_maxAbsTrailerAngle_deg );
                bool_t v_temp_b = m_leftTrailer.Start( 90.0f + initialAngle );
                bool_t v_temp2_b = m_rightTrailer.Start( 90.0f - initialAngle );
                result = v_temp_b && v_temp2_b;
            }

            m_isRunning = result;
            ret_val = m_isRunning;
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void TrailerAngleCalibration::Finish()
    {
        m_leftTrailer.Finish();
        m_rightTrailer.Finish();
        //
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void TrailerAngleCalibration::Run( uint32_t i_frame, const VehicleKinematics* i_vehicle, bool_t i_isTrackingLost )
    {
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ( !m_isRunning ) || ( i_frame == m_lastFrameRun ) )
        {
            ret_val = false;
        }

        if( !i_vehicle->valid() )
        {
            ret_val = false;
        }

        if( ret_val )
        {
#ifdef DIAGNOSTICS
            diag::start( "Trailer Angle Calibration" );
#endif
            //
            m_leftTrailer.Run( i_frame, *i_vehicle, i_isTrackingLost );
            m_rightTrailer.Run( i_frame, *i_vehicle, i_isTrackingLost );
            m_leftangle.push( mecl::math::abs_x( m_leftTrailer.getAngle_deg() - 90.0f ) );
            m_rightangle.push( mecl::math::abs_x( m_rightTrailer.getAngle_deg() - 90.0f ) );
            //
            m_lastFrameRun = i_frame;
#ifdef DIAGNOSTICS
            diag::stop();
#endif
        }

        return;
    }

    /*
    * Used to speed up calibration by setting the calibration angles to some offset of
    * the given angle.
    */
    void TrailerAngleCalibration::QuickCalibrate( float32_t i_trailerAngle_deg, float32_t i_maxAngleOffset )
    {
        if( ( i_trailerAngle_deg + i_maxAngleOffset ) < m_leftTrailer.getAngle_deg() )
        {
            m_leftTrailer.setAngle_deg( i_trailerAngle_deg + i_maxAngleOffset );
        }

        if( ( i_trailerAngle_deg - i_maxAngleOffset ) > m_rightTrailer.getAngle_deg() )
        {
            m_rightTrailer.setAngle_deg( i_trailerAngle_deg - i_maxAngleOffset );
        }
    }

    /*
    * Get the current angles calibrated, both on the left and the right sides.
    */
    void TrailerAngleCalibration::GetCalibrationAngles( float32_t& o_left, float32_t& o_right ) const
    {
        o_left = m_leftTrailer.getAngle_deg();
        o_right = m_rightTrailer.getAngle_deg();
    }

    /*
    * Return whether or not the angle has been calibrated.
    */
    bool_t TrailerAngleCalibration::TrailerAngleCalibrated() const
    {
        return ( ( mecl::math::abs_x( m_leftTrailer.getAngle_deg() - 90.0f ) < m_angleTolerance_mm ) && ( mecl::math::abs_x( m_rightTrailer.getAngle_deg() - 90.0f ) < m_angleTolerance_mm ) );
    }
    /*
    * Return whether the trailer is straight or not
    */
    bool_t TrailerAngleCalibration::isTrailerStraight()
    {
        float32_t left_buffer = 0;
        float32_t right_buffer = 0;
        average_val_buffer( left_buffer, right_buffer );
        return ( ( left_buffer < m_angleTolerance_mm ) && ( right_buffer < m_angleTolerance_mm ) );
    }
    /*
    * Finds the average of circular buffer
    */
    void TrailerAngleCalibration::average_val_buffer( float32_t& left_buffer, float32_t& right_buffer )
    {
        for( uint32_t i = 0; i < m_leftangle.size(); i++ )
        {
            left_buffer += m_leftangle[i];
            right_buffer += m_rightangle[i];
        }

        left_buffer = left_buffer / ( static_cast <float32_t>( m_leftangle.size() ) );
        right_buffer = right_buffer / ( static_cast <float32_t>( m_rightangle.size() ) );
    }

    ///------------------------------------------------------------------------------
    /// TrailerCalibrationModel function definitions.
    ///------------------------------------------------------------------------------

    /*
    * Constructor.
    */
    TrailerCalibrationModel::TrailerCalibrationModel() :
        m_beamLengthWhenMovingForward_mm( 0.0f ),
        m_beamLengthWhenInReverse_mm( 0.0f )
    {
    }

    /*
    * Destructor.
    */
    TrailerCalibrationModel::~TrailerCalibrationModel()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t TrailerCalibrationModel::Init( const TAD2::VehicleParameters& i_vehicleParams, float32_t i_beamLengthWhenMovingForward_mm, float32_t i_beamLengthWhenInReverse_mm, float32_t i_maxTrailerAngle_deg, float32_t i_minTrailerAngle_deg )
    {
        bool_t returnValue = false;
        m_beamLengthWhenMovingForward_mm = i_beamLengthWhenMovingForward_mm;
        m_beamLengthWhenInReverse_mm = i_beamLengthWhenInReverse_mm;
        m_maxTrailerAngle_rad = mecl::math::toRadians_x( 90.0f - i_minTrailerAngle_deg );
        m_minTrailerAngle_rad = mecl::math::toRadians_x( 90.0f - i_maxTrailerAngle_deg );
        m_vehicleParams = i_vehicleParams;

        if( !( ( mecl::math::isAboutZero_b( m_beamLengthWhenMovingForward_mm ) ) || ( mecl::math::isAboutZero_b( m_beamLengthWhenInReverse_mm ) ) ) )
        {
            returnValue = true;
            m_initOK = true;
        }

        return returnValue;
    }

    bool_t TrailerCalibrationModel::Start( float32_t i_startAngle_deg )
    {
        bool_t returnValue = false;

        if( m_initOK )
        {
            if( m_isRunning )
            {
                Finish();
            }

            m_currentAngle_rad = mecl::math::toRadians_x( 90.0f - i_startAngle_deg );
            m_isRunning = true;
            returnValue = true;
        }

        return returnValue;
    }
    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void TrailerCalibrationModel::Finish()
    {
        m_isRunning = false;
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void TrailerCalibrationModel::Run( int32_t i_frame, const VehicleKinematics& i_vehicle, bool_t i_isTrackingLost )
    {
        bool_t ret_val = true;

        if( !m_initOK )
        {
            ret_val = false;
        }

        if( ( !m_isRunning ) || ( m_lastFrameRun == i_frame ) )
        {
            ret_val = false;
        }

        if( ret_val )
        {
            float32_t steadyStateAngle_rad;

            if( i_isTrackingLost )
            {
                m_trailerParams.setBeamLength( m_beamLengthWhenMovingForward_mm );
            }
            else
            {
                if( i_vehicle.gearDir() < 0 )
                {
                    m_trailerParams.setBeamLength( m_beamLengthWhenInReverse_mm );
                }
                else
                {
                    m_trailerParams.setBeamLength( m_beamLengthWhenMovingForward_mm );
                }
            }

            steadyStateAngle_rad = _CalculateSteadyStateAngle( i_vehicle.wheelAngle_deg() );
            float32_t sinAngleDif = mecl::math::trigonometry<float32_t>::sin_x( steadyStateAngle_rad - m_currentAngle_rad );
            float32_t deltaAngle_rad = sinAngleDif * i_vehicle.distanceTravelled_m() / ( m_trailerParams.getBeamLength() / 1000.0f );
            m_currentAngle_rad += deltaAngle_rad;

            if( m_currentAngle_rad > m_maxTrailerAngle_rad )
            {
                m_currentAngle_rad = m_maxTrailerAngle_rad;
            }

            if( m_currentAngle_rad < m_minTrailerAngle_rad )
            {
                m_currentAngle_rad = m_minTrailerAngle_rad;
            }

            m_lastFrameRun = i_frame;
        }

        return;
    }

    /*
    * Get the current angle of the trailer model, in degrees.
    *
    * The polarity of the returned angle coincides with that of the TAD job output.
    */
    float32_t TrailerCalibrationModel::getAngle_deg() const
    {
        return 90.0f - mecl::math::toDegrees_x( m_currentAngle_rad );
    }

    /*
    * Set the current angle of this kinematic model manually. Will ensure that it is between
    * the min and max values.
    */
    void TrailerCalibrationModel::setAngle_deg( float32_t i_angle_deg )
    {
        m_currentAngle_rad = mecl::math::toRadians_x( 90.0f - i_angle_deg );

        if( m_currentAngle_rad > m_maxTrailerAngle_rad )
        {
            m_currentAngle_rad = m_maxTrailerAngle_rad;
        }

        if( m_currentAngle_rad < m_minTrailerAngle_rad )
        {
            m_currentAngle_rad = m_minTrailerAngle_rad;
        }
    }

    /*
        * Calculate the steady state angle of the trailer given the current vehicle wheel angle.
        */
    float32_t TrailerCalibrationModel::_CalculateSteadyStateAngle( float32_t i_wheelAngle_deg )const
    {
        float32_t ret_val;
        bool_t isReturned = true;

        if( mecl::math::abs_x<float32_t>( i_wheelAngle_deg ) < 0.1f )
        {
            ret_val = mecl::math::toRadians_x( mecl::math::abs_x( i_wheelAngle_deg ) );
            isReturned = false;
        }

        if( isReturned )
        {
            float32_t wheelAngle_rad = mecl::math::toRadians_x( mecl::math::abs_x( i_wheelAngle_deg ) );
            float32_t rearWheelTurnRadius = m_vehicleParams.wheelBase_mm / tanf( wheelAngle_rad );
            float32_t hitchTurnRadius = mecl::math::algebra<float32_t>::sqrt_x( ( rearWheelTurnRadius * rearWheelTurnRadius ) + ( m_vehicleParams.hitchLength_mm * m_vehicleParams.hitchLength_mm ) );
            float32_t hitchAngle_rad = atan2f( m_vehicleParams.hitchLength_mm, rearWheelTurnRadius );
            float32_t hitchTrailerAngle_rad;

            if( hitchTurnRadius > m_trailerParams.getBeamLength() )
            {
                hitchTrailerAngle_rad = asinf( m_trailerParams.getBeamLength() / hitchTurnRadius );
            }
            else
            {
                hitchTrailerAngle_rad = mecl::math::constants<float32_t>::pi_x() / 2.0f;
            }

            float32_t sign = ( i_wheelAngle_deg < 0.0f ) ? -1.0f : 1.0f;
            ret_val = sign * ( hitchAngle_rad + hitchTrailerAngle_rad );
        }

        return ret_val;
    }
}
