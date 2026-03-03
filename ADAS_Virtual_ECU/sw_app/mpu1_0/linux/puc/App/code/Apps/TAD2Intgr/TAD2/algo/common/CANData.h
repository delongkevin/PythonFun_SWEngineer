#ifndef __CAN_DATA__H_
#define __CAN_DATA__H_

#include <mecl/core/MeclTypes.h>
#include "CrossplatformCommon.h"

#ifdef __QNX__
    #include "../../TAD2Defines.h"
#else
    #define APPCTRL_TEST 1
#endif
namespace TAD2
{
    /*
    * Vehicle gears used by TAD.
    */
    enum eVehicleGear
    {
#if TAD2_SIGM_TESTING
        GearReverse = -1,
        GearNeutral = 0,
        GearForward = 1,
        GearPark = 2
#elif ((APPCTRL_TEST) || !(TAD2_SIGM_TESTING))
        GearReverse,
        GearNeutral,
        GearForward,
        GearPark
#endif
    };

    /*
    * Kinematic data used by TAD.
    */
    struct RawKinematicData
    {
        float32_t dx_m;
        float32_t dy_m;
        float32_t dyaw_rad;
        float32_t timestamp_s;
    };

    /*
    * Vehicle data from CAN, used by TAD.
    */
    struct RawVehicleData
    {
        float32_t speed_kmPh;
        float32_t steeringWheelAngle_rad;
        float32_t wheelAngle_rad;
        eVehicleGear gear;
        float32_t timeStamp_s;
    };

    struct SteerRequestData
    {
        float32_t SPEED_f32;
        float32_t ANGLE_f32;
        uint8_t REPORTEN_u1;
        uint8_t REPORT_OVERRIDE_u1;
        float32_t TORQUE_f32;
    };
    struct VehicleControlData
    {

        uint8_t gearStatus;             //From Gear Report

        float32_t YawRate_fl;               //From Gyro Report

        float32_t LAT_s16;              //From Accel Report

        float32_t WheelPositionRL_f32;  //From WheelPosition Report
        float32_t WheelPositionRR_f32;

        float32_t WheelSpeedRL_fl;      //From WheelSpeed Report
        float32_t WheelSpeedRR_fl;

        float32_t WheelSpeedFL_fl;      //From WheelSpeed Report
        float32_t WheelSpeedFR_fl;

        float32_t FLrpm;
        float32_t FRrpm;
        float32_t RRrpm;
        float32_t RLrpm;

        float32_t RollRate;

        uint8_t TRANSTAT_u2;            //From MISC Report
        uint8_t GDEC_u1;
        uint8_t CANCEL_u1;
    };

}

#endif // !__CAN_DATA__H_
