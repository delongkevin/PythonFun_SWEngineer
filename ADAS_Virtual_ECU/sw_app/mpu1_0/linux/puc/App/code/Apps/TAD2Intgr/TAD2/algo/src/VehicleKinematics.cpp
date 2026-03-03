// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Feb-2019]
// --- Last Modified by Joshua Teichroeb [05-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "VehicleKinematics.h"
#include "CANData.h"
#include "db.h"


namespace TAD2
{
    /*
    * Constructor.
    */

    VehicleKinematics::VehicleKinematics() :
        m_initOK( false ),
        m_isRunning( false ),
        m_lastFrameRun( 0 ),
        m_kinematicsValid( false )
    {
    }

    /*
    * Destructor.
    */
    VehicleKinematics::~VehicleKinematics()
    {
    }

    /*
    * Initialize this module.
    *
    * Called once at the beginning of the program, before any other functions.
    */
    bool_t VehicleKinematics::Init( const TAD2::VehicleParameters& i_vehicleParams, bool_t i_simulateTimeStamp, bool_t i_mirrorWheelAngleDir )
    {
        m_vehicleParams = i_vehicleParams;
        m_simulateTimeStamp = i_simulateTimeStamp;
        m_mirrorWheelAngleDir = i_mirrorWheelAngleDir;
        m_initOK = true;
        return true;
    }

    /*
    * Signifies the beginning of a period of execution. Allocates any necessary
    * memory and sets any input parameters needed at runtime.
    */
    bool_t VehicleKinematics::Start()
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

            initialize_circular_buffer( 1 );
            m_lastTimeStamp = -1.0f;
            m_isRunning = true;
            ret_val = true;
        }

        return ret_val;
    }

    /*
    * Signifies the end of a period of execution. Deallocates any memory used.
    */
    void VehicleKinematics::Finish()
    {
        m_kinematicsValid = false;
        m_isRunning = false;
        initialize_circular_buffer( 1 );
    }

    /*
    * Run this module.
    *
    * Will only run if called between a call to Start() and a call to Finish(), respectively.
    * Records the given frame so as to not run the same frame multiple times.
    */
    void VehicleKinematics::Run( int32_t i_frame, const TAD2::RawVehicleData& i_vehData, const TAD2::RawKinematicData& i_KMData )
    {
        bool_t ret_val = true;

        if( i_frame == m_lastFrameRun )
        {
            ret_val = false;
        }

        if( ( !m_initOK ) || ( !m_isRunning ) )
        {
            m_kinematicsValid = false;
            ret_val = false;
        }

        if( ret_val )
        {
            m_kinematicsValid = true;

            // --- Process timestamp
            if( m_simulateTimeStamp )
            {
                m_timePassed_s = 0.030f;
            }
            else
            {
                if( mecl::math::isAboutZero_b( i_vehData.timeStamp_s - 0.0f ) )
                {
                    m_kinematicsValid = false;
                }

                if( ( m_lastTimeStamp < 0.0f ) || ( m_lastTimeStamp > i_vehData.timeStamp_s ) )
                {
                    m_lastTimeStamp = i_vehData.timeStamp_s;
                }

                m_timePassed_s = i_vehData.timeStamp_s - m_lastTimeStamp;
                m_lastTimeStamp = i_vehData.timeStamp_s;
            }

            // --- Process gear direction
            switch( i_vehData.gear )
            {
#if ((APPCTRL_TEST) || (!TAD2_SIGM_TESTING))

                case TAD2::GearReverse:
#else
                case GearReverse:
#endif
                    {
                        m_gearDir = TAD2::GearReverse;
                        m_Vehicle_gear.push( TAD2::GearReverse );
                        break;
                    }

#if ((APPCTRL_TEST) || (!TAD2_SIGM_TESTING))

                case TAD2::GearNeutral:
#else
                case GearNeutral:
#endif
                    {
                        m_gearDir = TAD2::GearNeutral;
                        m_Vehicle_gear.push( TAD2::GearNeutral );
                        break;
                    }

#if ((APPCTRL_TEST) || (!TAD2_SIGM_TESTING))

                case TAD2::GearForward:
#else
                case GearForward:
#endif
                    {
                        m_gearDir = TAD2::GearForward;
                        m_Vehicle_gear.push( TAD2::GearForward );
                        break;
                    }

#if ((APPCTRL_TEST) || (!TAD2_SIGM_TESTING))
#else

                case GearPark:
                {
                    m_gearDir = 0;
                    m_Vehicle_gear.push( 0 );
                    break;
                }

#endif
            }

            // --- Process everything else
            m_vehSpeed_mPs = i_vehData.speed_kmPh * kinematics::c_kmPh_to_mPs;
            m_dist_trav_m = m_vehSpeed_mPs * m_timePassed_s * ( ( m_gearDir < 0 ) ? -1.0f : 1.0f );
            m_steeringWheelAnlge_deg = ( m_mirrorWheelAngleDir ? -1.0f : 1.0f ) * i_vehData.steeringWheelAngle_rad;
            m_vehAngle_deg = ( m_mirrorWheelAngleDir ? -1.0f : 1.0f ) * mecl::math::toDegrees_x( i_vehData.wheelAngle_rad );
            m_vehAngle_deg = ( m_mirrorWheelAngleDir ? -1.0f : 1.0f ) * mecl::math::toDegrees_x( i_vehData.wheelAngle_rad );
#ifdef DIAGNOSTICS
            db::plot( "(KM-3) Vehicle Speed 3", i_vehData.speed_kmPh );
#endif

            // --- Final check for validity
            if( m_dist_trav_m > 1.0f )
            {
                m_kinematicsValid = false;
            }

            m_lastFrameRun = i_frame;
        }

        return;
    }
    /*
    * initialize the cirlcular buffer
    */
    void VehicleKinematics::initialize_circular_buffer( uint32_t val )
    {
        uint32_t vehicleGearSize_u32 = m_Vehicle_gear.size();

        for( uint32_t i = 0; i < vehicleGearSize_u32; i++ )
        {
            m_Vehicle_gear.push( val );
        }
    }
    /*
    * Return whether the vehilce is neutral or not
    */
    bool_t VehicleKinematics::Is_Vehicle_Neutral()
    {
        bool_t ret_val = true;
        uint32_t Gear_val = 0;

        for( uint32_t i = 0; i < m_Vehicle_gear.size(); i++ )
        {
            Gear_val += m_Vehicle_gear[i];
        }

        if( Gear_val > 0 )
        {
            ret_val = false;
        }
        else
        {
            ret_val = true;
        }

        return ret_val;
    }
    /*
    * Return whether the vehicle is above 3.5 km/hr
    */
    bool_t VehicleKinematics::speed_valid() const
    {
        bool_t ret_val = true;

        if( m_vehSpeed_mPs > 1.0 )
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
    * Return whether or not the currrent frames kinematics are valid.
    */
    bool_t VehicleKinematics::valid() const
    {
        return m_kinematicsValid;
    }

    /*
    * Return positive value if gear in forward, negative value if in reverse, and
    * 0 if in neutral.
    */
    int32_t VehicleKinematics::gearDir() const
    {
        return m_gearDir;
    }

    /*
    * Return the current speed of the vehicle, in meters per second.
    */
    float32_t VehicleKinematics::currentSpeed_mps() const
    {
        return m_vehSpeed_mPs;
    }

    /*
    * Return the time passed since the last processed frame, in seconds.
    */
    float32_t VehicleKinematics::timePassed_s() const
    {
        return m_timePassed_s;
    }

    /*
    * Return the approximate distance the vehicle travelled (in meters) since
    * the last processed frame.
    */
    float32_t VehicleKinematics::distanceTravelled_m() const
    {
        return m_dist_trav_m;
    }

    /*
    * Return the current wheel angle of the vehicle, in degrees.
    *
    * The wheel angle will be flipped from what is received through CAN if 'i_mirrorWheelAngleDir' was set to 'true'.
    */
    float32_t VehicleKinematics::wheelAngle_deg() const
    {
        return m_vehAngle_deg;
    }
    /*
    * Return the cSteeringwheelAngle_deg, in deg.
    */
    float32_t VehicleKinematics::SteeringwheelAngle_deg() const
    {
        return m_steeringWheelAnlge_deg;
    }
}
