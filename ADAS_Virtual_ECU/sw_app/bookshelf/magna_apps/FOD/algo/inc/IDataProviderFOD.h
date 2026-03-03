/// @file IDataProviderFOD.h
/// @brief FOD detection
// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Nisheegandha Bhookan (Dhananjay.Sharma@magna.com)
// --------------------------------------------------------------------------

#ifndef IDATAPROVIDER_FOD_H
#define IDATAPROVIDER_FOD_H

#include "mecl.h"
#include "../algo/inc/JobFODInput.h"
#include "../algo/inc/JobFODOutput.h"
#include "../algo/common/KinematicData.h"
#include "../algo/common/VehicleData.h"
#include "../algo/common/FODConfig.h"

namespace fod
{
    class IDataProviderFOD
    {
    public:
        explicit IDataProviderFOD()
        {
        }

        virtual ~IDataProviderFOD()
        {
        }

        //--- Get Config
        virtual const FODCONFIGData& c_getFODConfig() const = 0;

        //--- Get FOD input from CAN
        virtual Job_Inputs_t getFODInput() = 0;

        //--- Get Vehicle Data
        virtual VehicleDataFOD c_getVehicleData() const = 0;

        //--- Get Kinematic Data
        virtual KinematicDataFOD c_getKinematicData() const = 0;

        //--- Get FOD output
        virtual JobFODOutput_t getFODOutput() const = 0;

        //--- Put FOD output
        virtual void putFODOutput( JobFODOutput_t& i_FodOutput ) = 0;

        //---Get Feature tunning params
        virtual TbFOD_VrntTunParam_t getFODTunningParams(FODCONFIGData& m_FODCfg) = 0;
    };
}

#endif // !IDATAPROVIDER_FOD_H
