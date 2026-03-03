/// @file DataProviderFOD.h
/// @brief
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Nisheegandha Bhookan (nisheegandha.bhookan@magna.com)


#ifndef WIN_DATA_PROVIDER_FOD_H
#define WIN_DATA_PROVIDER_FOD_H

#include "../algo/inc/IDataProviderFOD.h"
#include "../algo/common/KinematicData.h"
#include "../algo/common/VehicleData.h"
#include "../algo/inc/FODAlgo.h"

#define FOD_OFFLINE_TEST 0

namespace fod
{
    class DataProviderFOD : public IDataProviderFOD
    {
    public:
        explicit DataProviderFOD(FODCONFIGData &config,
                                 TbFOD_VrntTunParam_t& tuningParam,
                                 Job_Inputs_t &jobInput,
                                 JobFODOutput_t &jobFodOutput_s);

        virtual ~DataProviderFOD() {};

        /*
        * Get Config
        */
        virtual const FODCONFIGData& c_getFODConfig() const override;       //change to FODCONFIG

        /*
        * Get Vehicle Data
        */
        virtual VehicleDataFOD c_getVehicleData() const override;

        /*
        * Get Kinematic Data
        */
        virtual KinematicDataFOD c_getKinematicData() const override;

        /*
        * Get FOD input data
        */
        Job_Inputs_t getFODInput() override;

        /*
        * Get FOD output data from dataprovider
        */
        JobFODOutput_t getFODOutput() const override;

        /*
        * Set FOD output data to dataprovider
        */
        void putFODOutput( JobFODOutput_t& i_FodOutput ) override;

        virtual TbFOD_VrntTunParam_t getFODTunningParams(FODCONFIGData& m_FODCfg) override;

    private:
        /*
        * Input Config
        */
        FODCONFIGData& m_FODconfig;

        /*
        * Tuning Parameters
        */
        TbFOD_VrntTunParam_t& m_FODTuningParam;

        /*
        * FOD Input structure initialization
        */
        Job_Inputs_t& m_JobInput_s;

        /*
        * FOD Output structures initialization
        */
        JobFODOutput_t& m_JobFodOutput_s;

        FODAlgo fodAlgo;
    };
}
#endif // !WIN_DATA_PROVIDER_FOD_H
