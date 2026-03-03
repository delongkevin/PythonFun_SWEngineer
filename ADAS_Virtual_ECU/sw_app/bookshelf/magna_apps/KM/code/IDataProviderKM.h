//--------------------------------------------------------------------------
/// @file IDataProviderKM.h
/// @brief Contains
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
#ifndef IDATAPROVIDER_KM_H
#define IDATAPROVIDER_KM_H

#include <KinematicModel.h>

#define SIGM_TESTING    1
#define DEBUG_PRINT     0

#include "SignalDef.h"
#if SIGM_TESTING
    #include "KM_Model.h"
#endif

#if !SIGM_TESTING
	extern int KM_FrameCount_i;
#endif

namespace KM
{
    class IDataProviderKM
    {
    public:
        explicit IDataProviderKM()
        {
        }

        virtual ~IDataProviderKM()
        {
        }
        IKinematicData_t km_output_sigm;
        virtual ExtU_KinematicModel_T get_vehicle_signal_input() = 0;
		virtual void transmit_kinematic_output(ExtY_KinematicModel_T* km_output) = 0;
    };

} // namespace KM

#endif // IDATAPROVIDER_KM_H
