//--------------------------------------------------------------------------
/// @file DataProviderSysMon.cpp
/// @brief Contains the System Monitor data provider implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#include "DataProviderSysMon.h"

namespace sysmon
{

DataProviderSysMon::DataProviderSysMon(container::IDataProvider& b_DataProvider_ro)
 : IDataProviderSysMon()
 , dataProvider_ro(b_DataProvider_ro)
{
}

DataProviderSysMon::~DataProviderSysMon()
{
}

void DataProviderSysMon::setCurrentSoCTemperature(const float32_t& i_CurrentSoCTemperature_rf32)
{
  dataProvider_ro.getSysMonData_po()->setCurrentSoCTemperature_v(i_CurrentSoCTemperature_rf32);
}

void DataProviderSysMon::setME_Proxi_MPU1_0_to_MCU1_0(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t)
{
  dataProvider_ro.getSigMData_po()->setME_Proxi_MPU1_0_to_MCU1_0_v(i_ME_Proxi_MPU1_0_to_MCU1_0_t);
}

ME_Proxi_MPU1_0_to_MCU1_0_t DataProviderSysMon::getME_Proxi_MPU1_0_to_MCU1_0()
{
	return dataProvider_ro.getSigMData_po()->getME_Proxi_MPU1_0_to_MCU1_0();
}

void DataProviderSysMon::setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt)
{
	dataProvider_ro.getSigMData_po()->setSSM_QNX_CoreStatus_v(i_SSM_QNX_CoreStatus_rt);
}
void DataProviderSysMon::setETFS_mount_status(const uint8_t& etfs)
{
  dataProvider_ro.getSigMData_po()->setETFS_mount_status(etfs);
}

uint8_t DataProviderSysMon::getETFS_mount_status(void)
{
	return dataProvider_ro.getSigMData_po()->getETFS_mount_status();
}

PerformanceStatsEnable_t DataProviderSysMon::getPerformanceStatsEnable_t(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}

void DataProviderSysMon::setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt)
{
	dataProvider_ro.getSigMData_po()->setRunTimeStats_MPU1_0_v(i_RunTimeStats_MPU1_0_rt);
}

uint32_t DataProviderSysMon::getCALSMRuntime(void)
{
	return dataProvider_ro.getCalSmMData_po()->getCALSMRuntime();
}

uint32_t DataProviderSysMon::getCALSMThreadRuntime(void)
{
	return dataProvider_ro.getCalSmMData_po()->getCALSMThreadRuntime();
}

uint32_t DataProviderSysMon::getDLDRuntime(void)
{
	return dataProvider_ro.getDLDData_po()->getDLDRuntime();
}

uint32_t DataProviderSysMon::getDLDThreadRuntime(void)
{
	return dataProvider_ro.getDLDData_po()->getDLDThreadRuntime();
}

uint32_t DataProviderSysMon::getEOLRuntime(void)
{
	return dataProvider_ro.getEolMData_po()->getEOLRuntime();
}

uint32_t DataProviderSysMon::getEOLThreadRuntime(void)
{
	return dataProvider_ro.getEolMData_po()->getEOLThreadRuntime();
}

uint32_t DataProviderSysMon::getOCRuntime(void)
{
	return dataProvider_ro.getOcMData_po()->getOCRuntime();
}

uint32_t DataProviderSysMon::getOCThreadRuntime(void)
{
	return dataProvider_ro.getOcMData_po()->getOCThreadRuntime();
}

uint32_t DataProviderSysMon::getOVL3DRuntime(void)
{
	return dataProvider_ro.getOVL3DData_po()->getOVL3DRuntime();
}

uint32_t DataProviderSysMon::getTAD2Runtime(void)
{
	return dataProvider_ro.getTAD2Data_po()->getTAD2Runtime();
}

uint32_t DataProviderSysMon::getTAD2ThreadRuntime(void)
{
	return dataProvider_ro.getTAD2Data_po()->getTAD2ThreadRuntime();
}

uint32_t DataProviderSysMon::getTHARuntime(void)
{
	return dataProvider_ro.getTHAData_po()->getTHARuntime();
}

uint32_t DataProviderSysMon::getTHAThreadRuntime(void)
{
	return dataProvider_ro.getTHAData_po()->getTHAThreadRuntime();
}

uint32_t DataProviderSysMon::getTIOVXRuntime(void)
{
	return dataProvider_ro.getTIOVXData_po()->getTIOVXRuntime();
}

uint32_t DataProviderSysMon::getTIOVXThreadRuntime(void)
{
	return dataProvider_ro.getTIOVXData_po()->getTIOVXThreadRuntime();
}

uint32_t DataProviderSysMon::getCamCalibRuntime(void)
{
	return dataProvider_ro.getTIOVXData_po()->getCamCalibRuntime();
}

uint32_t DataProviderSysMon::getAppMRuntime(void)
{
	return dataProvider_ro.getAppMData_po()->getAppMRuntime();
}

uint32_t DataProviderSysMon::getRenderThreadRuntime(void)
{
	return dataProvider_ro.getOVL3DData_po()->getRenderThreadRuntime();
}

uint32_t DataProviderSysMon::getVarMRuntime(void)
{
	return dataProvider_ro.getVarMData_po()->getVarMRuntime();
}

uint32_t DataProviderSysMon::getSigMRuntime(void)
{
	return dataProvider_ro.getSigMData_po()->getSigMRuntime();
}

uint32_t DataProviderSysMon::getThSigMRuntime(void)
{
	return dataProvider_ro.getSigMData_po()->getThSigMRuntime();
}

uint32_t DataProviderSysMon::getKeepAliveRuntime(void)
{
	return dataProvider_ro.getSigMData_po()->getKeepAliveRuntime();
}

uint32_t DataProviderSysMon::getAlgoViewRuntime(void)
{
	return dataProvider_ro.getOVL3DData_po()->getAlgoViewRuntime();
}

uint32_t DataProviderSysMon::getSysMonRuntime(void)
{
	return dataProvider_ro.getSysMonData_po()->getSysMonRuntime();
}

void DataProviderSysMon::setSysMonRuntime(uint32_t u_Runtime_u32)
{
	dataProvider_ro.getSysMonData_po()->setSysMonRuntime(u_Runtime_u32);
}

uint32_t DataProviderSysMon::getMsgSndrRuntime(void)
{
	return dataProvider_ro.getSigMData_po()->getMsgSndrRuntime();
}

uint32_t DataProviderSysMon::getLogMRuntime(void)
{
	return dataProvider_ro.getSigMData_po()->getLogMRuntime();
}

} // namespace sysmon
