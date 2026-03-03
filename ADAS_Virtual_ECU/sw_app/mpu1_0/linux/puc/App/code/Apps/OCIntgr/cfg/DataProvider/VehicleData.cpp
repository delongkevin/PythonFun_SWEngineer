#include "VehicleData.h"

namespace oc
{
VehicleData::VehicleData() :
    speed( 0.0f ),
    steeringWheelAngle( 0.0f ),
    wheelAngle( 0.0f ),
    yawrate( 0.0f ),
    timeStamp( 0.0f ),
    timeElapsed( 0.0f )
{}

VehicleData::VehicleData( float32_t i_speed,
                          float32_t i_steeringWheelAngle,
                          float32_t i_wheelAngle,
                          float32_t i_yawrate,
                          float32_t i_timeStamp,
                          float32_t i_timeElapsed
                        ) :
    speed( i_speed ),
    steeringWheelAngle( i_steeringWheelAngle ),
    wheelAngle( i_wheelAngle ),
    yawrate( i_yawrate ),
    timeStamp( i_timeStamp ),
    timeElapsed( i_timeElapsed )
{}

VehicleData::VehicleData( const VehicleData& in ) :
    speed( in.speed ),
    steeringWheelAngle( in.steeringWheelAngle ),
    wheelAngle( in.wheelAngle ),
    yawrate( in.yawrate ),
    timeStamp( in.timeStamp ),
    timeElapsed( in.timeElapsed )
{}

VehicleData::~VehicleData() {}

void VehicleData::Reset()
{
  /* DD-ID: {A37A4440-4F66-4d83-9702-05C4715FDBE7}*/
    speed = 0.0f;
    steeringWheelAngle = 0.0f;
    wheelAngle = 0.0f;
    yawrate = 0.0f;
    timeStamp = 0;
    timeElapsed = 0.0f;
}
}
