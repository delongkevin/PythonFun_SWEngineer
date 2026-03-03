//--------------------------------------------------------------------------
/// @file JobHMI.cpp
/// @brief Contains HMI Job implementation
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


#include "JobHMI.h"
#include "DataProviderHMI.h"
//VSI

extern "C" { 
void aHmiM_F_Init_v(void);
void aHmiM_STM_F_Init_v(void);
void aHmiM_F_Task10msec_v(void);
void aHmiM_STM_F_Task10msec_v(void);
}

//extern aSigConverterTypes_S_Tx_HmiMRelatedData_t aHmiM_STM_v_Tx_HmiMRelatedData_e;
extern aSigConverterTypes_S_Rx_HmiMRelatedData_t aHmiM_STM_v_Rx_HmiMRelatedData_e;

namespace HMI
{
JobHMI::JobHMI(IDataProviderHMI *b_DPHMI_ro)
{
    dataProvider_ro = b_DPHMI_ro;	
}

JobHMI::~JobHMI()
{

}



bool JobHMI::onInit_b()
{
  /* DD-ID: {D364D5B2-0EAC-4a7c-BEB8-6A9238EEFF14}*/

	aHmiM_F_Init_v();
	aHmiM_STM_F_Init_v();
	return true;
}

void JobHMI::onVariantChanged_v(bool_t i_FirstTime_b)
{
  /* DD-ID: {85ABDC7F-D4BF-4dbe-9C4D-140B83E9EAAE}*/
	return;
}

bool JobHMI::onRun_b()
{
  /* DD-ID: {33833B97-EF4E-410d-B690-11BD5BAC47A6}*/
	{
		start_v();
		execute_v();
		if (!hasNext_b())
		{
			/* Do nothing here */
		}
		end_v();
	}	

    return true;
}

void JobHMI::onCleanup_v()
{
  /* DD-ID: {1651D6D2-C77A-4b6a-87B1-DBBE00E525CF}*/
	return;
}

void JobHMI::start_v(void)
{
  /* DD-ID: {0CBD914E-844F-444d-A4E4-D756D3448907}*/
	/* Call the get Api here before the start of STM */
    dataProvider_ro->get_vehicle_signal_input();
    return;
}

bool JobHMI::hasNext_b()
{
  /* DD-ID: {02399011-2021-4d54-8418-413108818FD3}*/
	return true;
}

void JobHMI::execute_v()
{
  /* DD-ID: {8FDABEC8-6234-4273-8F17-7F05B0F4A2B1}*/
	aHmiM_F_Task10msec_v();
    aHmiM_STM_F_Task10msec_v();	
    return;
}

void JobHMI::end_v()
{
  /* DD-ID: {F1C5D6F8-ABC1-4598-B242-0440AC8F75CE}*/
    return;    
}

void JobHMI::dump_v()
{
  /* DD-ID: {528755C8-379C-47ff-AD7E-5A1BFC1F5E88}*/
    return;	
}

} // namespace HMI
