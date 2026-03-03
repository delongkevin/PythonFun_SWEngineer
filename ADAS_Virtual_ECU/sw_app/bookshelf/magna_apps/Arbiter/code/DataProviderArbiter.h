//--------------------------------------------------------------------------
/// @file DataProviderArbiter.h
/// @brief Contains
///
/// DataProvider is an interface between Arbiter module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Dipti Natu (dipti.natu@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef _DATA_PROVIDER_ARBITER_
#define _DATA_PROVIDER_ARBITER_

#include "IDataProviderArbiter.h"

namespace Arbiter
{
    class DataProviderArbiter : public IDataProviderArbiter
    {
    public:
        explicit DataProviderArbiter();
        virtual ~DataProviderArbiter();
    };
} // namespace Arbiter

#endif //_DATA_PROVIDER_ARBITER_
