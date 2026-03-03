//--------------------------------------------------------------------------
/// @file FODAlgo.h
//--------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author
///
//--------------------------------------------------------------------------

#ifndef FOD_ALGO_H
#define FOD_ALGO_H

#include "../algo/common/FODConfig.h"
#include "../algo/common/VehicleData.h"
#include "../algo/inc/JobFODOutput.h"


namespace fod
{
    class FODAlgo
    {
    public:
        //Constructor
        FODAlgo();

        //Destructor
        ~FODAlgo() noexcept;

        void Init( const FODCONFIGData& i_FodConfig, const TbFOD_VrntTunParam_t& i_FodTuningParam );
        void Reset();
        void Run( const float32_t MeFOD_m_MinXDist, const float32_t MeFOD_m_MinXDistSide );

        //--- Pass data from algo to Ijob
        JobFODOutput_t getFODDetOutputAlgo()const;

    private:

        FODCONFIGData m_FODCfg;
        JobFODOutput_t m_JobFODOutput;
		float32_t vehWidth;
		float32_t roiLateral;

        //float32_t pietoRad; //Pankaj: commented to avoid compilation warning of not used anywhere
		 
        float32_t latDistance;
        float32_t longiDistance;
       
        float32_t wheelbase;
        float32_t frontOverhang;
        float32_t vehicleFrontBumper;
        float32_t vehiclePosI;
        float32_t vehiclePosII;
        float32_t vehicleMaxDist;
        float32_t objDetctXThd;

#if WINDOWS_CODE
        FODKPIOutputData m_FODKPIOutputData;
#endif
    };
} // !FOD

#endif // !FOD_ALGO_H
