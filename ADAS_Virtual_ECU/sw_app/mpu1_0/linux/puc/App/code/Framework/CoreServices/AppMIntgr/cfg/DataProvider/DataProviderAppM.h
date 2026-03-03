//--------------------------------------------------------------------------
/// @file DataProviderAppM.h
/// @brief Contains
///
/// DataProvider is an interface between EOL module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef DATAPROVIDERAPPM_H_
#define DATAPROVIDERAPPM_H_

#include "appm/IDataProviderAppM.h"
#include <cfg/IDataProvider.h>

namespace appm
{

class DataProviderAppM : public IDataProviderAppM
{

public:

    explicit DataProviderAppM(container::IDataProvider& b_DataProvider_ro);
    virtual ~DataProviderAppM();

    //----------------------------------------------------------------------------------------
    // // Data Input (only getter)
    //---------------------------------------------------------------------------------------

    virtual uint32_t                            getFrameID_u32() const;


    //----------------------------------------------------------------------------------------
    // Data Output (only setter)
    //----------------------------------------------------------------------------------------

    virtual void                                setFrameID_v(uint32_t i_FrameID_u32);  
    virtual void                                setBootState_v(uint8_t i_BootState_u8);
    virtual void                                setAppMRuntime(uint32_t u_Runtime_u32);
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

private:
    container::IDataProvider& dataProvider_ro;

};

} // namespace appm

#endif // DATAPROVIDERAPPM_H_

