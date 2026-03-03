//--------------------------------------------------------------------------
/// @file DataProviderLogM.cpp
/// @brief Contains the System Monitor data provider implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "DataProviderLogM.h"

namespace logm
{

DataProviderLogM::DataProviderLogM(container::IDataProvider& b_DataProvider_ro)
 : IDataProviderLogM()
 , dataProvider_ro(b_DataProvider_ro)
{
}

DataProviderLogM::~DataProviderLogM()
{
}

void DataProviderLogM::setLogMRuntime(uint32_t u_Runtime_u32)
{
	dataProvider_ro.getSigMData_po()->setLogMRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderLogM::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}

} // namespace sysmon
