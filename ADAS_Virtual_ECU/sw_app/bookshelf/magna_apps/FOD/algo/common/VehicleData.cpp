#include "VehicleData.h"

VehicleDataFOD::VehicleDataFOD() :
    IeCANFD2_kph_VehicleSpeedVSOSig( 0.0f ),
    IeVBII_deg_StrWhlAng( 0.0f ),
    wheelAngle_f32( 0.0f ),
    timeStamp_f32( 0.0f ),
    IeVBII_e_GearRptState( eVehicleGear_t::GearValues_E_GEAR_NEUTRAL )
{}

VehicleDataFOD::VehicleDataFOD( const float32_t i_speed,
                                const float32_t i_steeringWheelAngle,
                                const float32_t i_wheelAngle,
                                const float32_t i_timeStamp,
                                const eVehicleGear_t i_gear ) :
    IeCANFD2_kph_VehicleSpeedVSOSig( i_speed ),
    IeVBII_deg_StrWhlAng( i_steeringWheelAngle ),
    wheelAngle_f32( i_wheelAngle ),
    timeStamp_f32( i_timeStamp ),
    IeVBII_e_GearRptState( i_gear )
{}

VehicleDataFOD::VehicleDataFOD( const VehicleDataFOD& in ) :
    IeCANFD2_kph_VehicleSpeedVSOSig( in.IeCANFD2_kph_VehicleSpeedVSOSig ),
    IeVBII_deg_StrWhlAng( in.IeVBII_deg_StrWhlAng ),
    wheelAngle_f32( in.wheelAngle_f32 ),
    timeStamp_f32( in.timeStamp_f32 ),
    IeVBII_e_GearRptState( in.IeVBII_e_GearRptState )
{}

VehicleDataFOD::~VehicleDataFOD() {}

void VehicleDataFOD::Reset()
{
    IeCANFD2_kph_VehicleSpeedVSOSig = 0.0f;
    IeVBII_deg_StrWhlAng = 0.0f;
    timeStamp_f32 = 0;
    wheelAngle_f32 = 0.0f;
    IeVBII_e_GearRptState = eVehicleGear_t::GearValues_E_GEAR_NEUTRAL;
}
