//--------------------------------------------------------------------------
/// @file IDataProviderAP.h
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
/// @author Kedar Naphad (kedar.naphad@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef _IDATA_PROVIDER_AP_
#define _IDATA_PROVIDER_AP_

#define DEBUG_PRINTS 0

extern "C" {
#include "DT24_CVADAS_AP_CodGen.h"
};

namespace AP
{

    class IDataProviderAP
    {
    public:
        explicit IDataProviderAP()
        {
        }

        virtual ~IDataProviderAP()
        {
        }
    };
} // namespace AP

#endif // _IDATA_PROVIDER_AP_
