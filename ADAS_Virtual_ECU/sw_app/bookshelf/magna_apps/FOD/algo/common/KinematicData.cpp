#include "KinematicData.h"
#include "mecl/mecl.h"

KinematicDataFOD::KinematicDataFOD() :
    IeVBII_delta_Dx( 0.0f ),
    IeVBII_delta_Dy( 0.0f ),
    IeVBII_delta_Dyaw( 0.0f ),
    timestamp_s( 0.0f )
{}

KinematicDataFOD::KinematicDataFOD( const float32_t i_dx_m, const float32_t i_dy_m, const float32_t i_dyaw_rad, const float32_t i_timestamp_s ):

    IeVBII_delta_Dx( i_dx_m ),
    IeVBII_delta_Dy( i_dy_m ),
    IeVBII_delta_Dyaw( i_dyaw_rad ),
    timestamp_s( i_timestamp_s )
{}

KinematicDataFOD::KinematicDataFOD( const KinematicDataFOD& in ) :
    IeVBII_delta_Dx( in.IeVBII_delta_Dx ),
    IeVBII_delta_Dy( in.IeVBII_delta_Dy ),
    IeVBII_delta_Dyaw( in.IeVBII_delta_Dyaw ),
    timestamp_s( in.timestamp_s )
{}

KinematicDataFOD::~KinematicDataFOD() {}

void KinematicDataFOD::Reset()
{
    IeVBII_delta_Dx = 0.0f;
    IeVBII_delta_Dy = 0.0f;
    IeVBII_delta_Dyaw = 0.0f;
    timestamp_s = 0.0f;
}
