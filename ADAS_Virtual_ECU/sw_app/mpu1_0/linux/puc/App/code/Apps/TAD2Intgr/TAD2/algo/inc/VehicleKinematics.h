// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [08-Feb-2019]
// --- Last Modified by Joshua Teichroeb [08-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __VEHICLE_KINEMATICS__H_
#define __VEHICLE_KINEMATICS__H_

#ifdef __QNX__
    #include "../common/TADStructures.h"
    #include "../common/config.h"
    #include "../common/CANData.h"
    #include "../common/CircularBuffer.h"
#else
    #include "common/TADStructures.h"
    #include "common/config.h"
    #include "common/CANData.h"
    #include "common/CircularBuffer.h"
#endif

namespace kinematics
{
    // --- Constants
    static const float32_t c_kmPh_to_mPs = 1000.0f / ( 60.0f * 60.0f );
}

/** Vehicle kinematics model. Collects data from CAN and converts it to the desired units/format. **/
namespace TAD2
{
    class VehicleKinematics
    {
    public:
        VehicleKinematics();
        ~VehicleKinematics();

        // --- Exposed Functions
        bool_t Init( const TAD2::VehicleParameters& i_vehicleParams, bool_t i_simulateTimeStamp, bool_t i_mirrorWheelAngleDir );
        bool_t Start();
        void Finish();

        void Run( int32_t i_frame, const TAD2::RawVehicleData& i_vehData, const TAD2::RawKinematicData& i_KMData );

        // --- Getters
        bool_t valid() const;
        bool_t speed_valid() const;
        bool_t Is_Vehicle_Neutral();
        int32_t gearDir() const;
        float32_t currentSpeed_mps() const;
        float32_t timePassed_s() const;
        float32_t distanceTravelled_m() const;
        float32_t wheelAngle_deg() const;
        float32_t SteeringwheelAngle_deg() const;

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        int32_t m_lastFrameRun;
        int32_t m_lastFrameRun_calibration;

        // --- Config parameters
        TAD2::VehicleParameters m_vehicleParams;
        bool_t m_simulateTimeStamp;
        bool_t m_mirrorWheelAngleDir;

        // --- Other variables and flags
        bool_t m_kinematicsValid;
        int32_t m_gearDir;
        float32_t m_vehSpeed_mPs;
        float32_t m_lastTimeStamp;
        float32_t m_timePassed_s;
        float32_t m_dist_trav_m;
        float32_t m_vehAngle_deg;
        float32_t m_steeringWheelAnlge_deg;

        // -- circular buffer
        static const uint32_t c_bufSize = 50;
        buffer::CircularBuffer<int32_t, c_bufSize> m_Vehicle_gear;
        void initialize_circular_buffer( uint32_t val );

    };
}

#endif // !__VEHICLE_KINEMATICS__H_
