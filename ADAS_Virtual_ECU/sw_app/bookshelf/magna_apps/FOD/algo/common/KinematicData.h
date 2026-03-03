//--------------------------------------------------------------------------
/// @file KinematicData.h
//--------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author
///
//--------------------------------------------------------------------------

#ifndef __KINEMATIC_DATA_LMD_H__
#define __KINEMATIC_DATA_LMD_H__

#include "mecl/core/MeclTypes.h"


typedef struct Veh_MoveData
{
    Veh_MoveData()
    {
        m_DeltaKM_X_m = 0;
        m_DeltaKM_Y_m = 0;
        m_DeltaKM_Yaw_rad = 0;
    }

    float32_t m_DeltaKM_X_m;
    float32_t m_DeltaKM_Y_m;
    float32_t m_DeltaKM_Yaw_rad;

} _Veh_MoveData;


class KinematicDataFOD
{
public:
    float32_t IeVBII_delta_Dx;             //ExtY_KinematicModel_T.IeVBII_delta_Dx
    float32_t IeVBII_delta_Dy;             //ExtY_KinematicModel_T.IeVBII_delta_Dy
    float32_t IeVBII_delta_Dyaw;           //ExtY_KinematicModel_T.IeVBII_delta_Dyaw
    float32_t timestamp_s;

    // Constructors
    KinematicDataFOD();
    KinematicDataFOD( const float32_t i_dx_m, const float32_t i_dy_m, const float32_t i_dyaw_rad, const float32_t i_timestamp_s );
    KinematicDataFOD( const KinematicDataFOD& in );

    // Destructor
    ~KinematicDataFOD();

    // Methods
    void Reset();
};

#endif // !__KINEMATIC_DATA_LMD_H__
