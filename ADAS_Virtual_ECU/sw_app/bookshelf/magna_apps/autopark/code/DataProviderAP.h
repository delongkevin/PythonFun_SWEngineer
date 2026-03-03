//--------------------------------------------------------------------------
/// @file DataProviderAP.h
/// @brief Contains
///
/// DataProvider is an interface between AP module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Kedar Naphad (kedar.naphad@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef _DATA_PROVIDER_AP_
#define _DATA_PROVIDER_AP_

#include "IDataProviderAP.h"

namespace AP
{
    class DataProviderAP : public IDataProviderAP
    {
    public:
        explicit DataProviderAP();
        virtual ~DataProviderAP();
    };
} // namespace AP

#endif //_DATA_PROVIDER_AP_
