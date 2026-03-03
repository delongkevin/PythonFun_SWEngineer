//--------------------------------------------------------------------------
/// @file IDataProviderArbiter.h
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
/// @author Dipti Natu (dipti.natu@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef _IDATA_PROVIDER_ARBITER_
#define _IDATA_PROVIDER_ARBITER_

#define DEBUG_PRINTS 0

extern "C" {
#include "FeatureArbiter.h"
};

namespace Arbiter
{

    class IDataProviderArbiter
    {
    public:
        explicit IDataProviderArbiter()
        {
        }

        virtual ~IDataProviderArbiter()
        {
        }
    };
} // namespace Arbiter

#endif // _IDATA_PROVIDER_ARBITER_
