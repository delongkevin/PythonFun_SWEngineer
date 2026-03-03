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
#ifndef VEHICLE_DATA_FOD_H_
#define VEHICLE_DATA_FOD_H_

#include "PlatformDataTypes.h"
#include "CrossplatformCommon.h"
#include "FODDef.h"
typedef m_GearValues eVehicleGear_t;

class VehicleDataFOD
{
public:
    // To covert kph into mph => (speed / 1.609)
    float32_t IeCANFD2_kph_VehicleSpeedVSOSig;      //ME_VehInp_BRAKE_FD_2.IeCANFD2_kph_VehicleSpeedVSOSig
    float32_t IeVBII_deg_StrWhlAng;                 //ME_VehInp_EPS_FD_1.IeVBII_deg_StrWhlAng
    float32_t wheelAngle_f32;                       //(IeVBII_deg_StrWhlAng / 16)
    float32_t timeStamp_f32;
    eVehicleGear_t IeVBII_e_GearRptState;           //ME_VehInp_to_IpcSignals_t.IeVBII_e_GearRptState

    // Constructors
    VehicleDataFOD();
    VehicleDataFOD( const float32_t i_speed,
                    const float32_t i_steeringWheelAngle,
                    const float32_t i_wheelAngle,
                    const float32_t i_timeStamp,
                    const eVehicleGear_t i_gear );
    VehicleDataFOD( const VehicleDataFOD& in );

    // Destructor
    ~VehicleDataFOD();

    // Methods
    void Reset();
};

#endif // !__VEHICLE_DATA_FOD_H__
