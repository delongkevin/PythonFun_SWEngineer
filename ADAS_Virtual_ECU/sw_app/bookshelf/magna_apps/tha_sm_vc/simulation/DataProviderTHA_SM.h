//--------------------------------------------------------------------------
/// @file DataProviderTHA_SM.h
/// @brief Contains
///
/// DataProvider is an interface between THA_SM module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef DATA_PROVIDER_THA_SM_ 
#define DATA_PROVIDER_THA_SM_

#include  "../THA_SWC_ert_rtw/THA_SWC_types.h"
#include "THA_SM_V1_Inputs.h"

// Get Set data.
void get_THADetectionOutput(TbTHASmVc_InputFromThaDet_t* b_input0);
void get_HMISVS_t_data(TbTHASmVc_InputFromHmiSvs_t* b_input1);
void get_SWCVCANMgr_t_Data(TbTHASmVc_InputFromVehInp_t* b_input2);
void get_SMModelOutput_t_Data(TbTHASmVc_InputFromApSmPa_t* b_input3);
void get_SWCProxiMgr_t(TbTHASmVc_InputFromProxiMgr_t* b_input4);
void get_MECalibSVS_t_Data(TbTHASmVc_InputFromDegrdMgr_t* b_input5);
void put_THA_output();

#endif //_DATA_PROVIDER_THA_SM_
