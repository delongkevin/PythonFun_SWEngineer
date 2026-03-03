//--------------------------------------------------------------------------
/// @file IDataProviderHMI.h
/// @brief Contains Interface class for Data Provider
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
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef _IDATA_PROVIDER_HMI_STATE_MACHINE_
#define _IDATA_PROVIDER_HMI_STATE_MACHINE_

#define DEBUG_PRINTS 1u
#define InitToZero 0U

#include "SignalDef.h"
#include "External_Dependency.h"
#ifdef __cplusplus
extern "C" {
#endif

namespace HMI
{

class IDataProviderHMI
{
public:
    explicit IDataProviderHMI()
    {
    }

    virtual ~IDataProviderHMI()
    {
    }
    virtual void get_vehicle_signal_input(void) = 0;
    virtual int set_HMI_output_signal(aSigConverterTypes_S_Tx_HmiMRelatedData_t hmi_output) = 0;
};
} // namespace HMI
#ifdef __cplusplus
}
#endif

#endif // _IDATA_PROVIDER_HMI_STATE_MACHINE_

