//--------------------------------------------------------------------------
/// @file DataProviderHMI.h
/// @brief Contains
///
/// DataProvider is an interface between HMI module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef _DATA_PROVIDER_HMI_
#define _DATA_PROVIDER_HMI_

#include "IDataProviderHMI.h"
#include "TRSC_SM_VC_Int_types.h"

namespace HMI
{
class DataProviderHMI: public IDataProviderHMI
{
public:
    explicit DataProviderHMI();
    virtual ~DataProviderHMI();

    void get_vehicle_signal_input(void);
    int set_HMI_output_signal(aSigConverterTypes_S_Tx_HmiMRelatedData_t hmi_output);
    
};
}//namespace HMI
	
#endif //_DATA_PROVIDER_HMI_
