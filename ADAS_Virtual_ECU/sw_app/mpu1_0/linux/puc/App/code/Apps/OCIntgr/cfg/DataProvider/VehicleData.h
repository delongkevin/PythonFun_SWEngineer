//--------------------------------------------------------------------------
/// @file VehicleData.h
//--------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author 
///
//--------------------------------------------------------------------------
#ifndef __OC_VEHICLE_DATA_H__
#define __OC_VEHICLE_DATA_H__

#include "CrossplatformCommon.h"
namespace oc
{


class VehicleData
{
public:
    float32_t speed;
    float32_t steeringWheelAngle;
    float32_t wheelAngle;
    float32_t yawrate;
    float32_t timeStamp; //??? Could be uint32_t
    float32_t timeElapsed;
    // constructors
    VehicleData();
    VehicleData( float32_t i_speed,
                 float32_t i_steeringWheelAngle,
                 float32_t i_wheelAngle,
                 float32_t i_yawrate,
                 float32_t i_timeStamp,
                 float32_t i_timeElapsed );
    VehicleData( const VehicleData& in );
    ~VehicleData();
    // Methods
    void Reset();
};
}

#endif
