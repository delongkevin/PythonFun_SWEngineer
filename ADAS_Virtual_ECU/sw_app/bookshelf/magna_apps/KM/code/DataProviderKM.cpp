//--------------------------------------------------------------------------
/// @file DataProviderKM.cpp
/// @brief ContainsW
///
/// DataProvider is an interface between KM module and the shared memory.
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


#include "DataProviderKM.h"

#if !SIGM_TESTING
  #include "../simulation/KMInputs.h"
#endif

#if !SIGM_TESTING
 int KM_FrameCount_i = 0;
#endif

#define MAX_NUM_OBJECTS_FROM_SENSOR 40
#define MAX_TEST_DATA               350

namespace KM
{

DataProviderKM::DataProviderKM()
{
}

DataProviderKM::~DataProviderKM()
{

}

/* ---------------------------------------------------------------------------- */

//***TBD: Return type has to be taken from signal manager, this file will need continuous updates

ExtU_KinematicModel_T DataProviderKM::get_vehicle_signal_input(void)
{
    ExtU_KinematicModel_T vsi;
#if SIGM_TESTING
  VehInpAdapter_opVehSignals data;
  
  SigMgr_VehicleAdapterSignals_data_Get(&data);
  vsi.potMap_reset_KM           = 0;//data.???
  vsi.WheelSpeed_ReportRR       = data.dt_ESP_0x116.ESP_WhlSpd_RR; // (km/h)
  vsi.WheelSpeed_ReportRL       = data.dt_ESP_0x116.ESP_WhlSpd_RL; // (km/h)
  vsi.WheelPosition_ReportRR    = data.dt_ESP_0x116.ESP_WhlMovgDir_RR; 
  vsi.WheelPosition_ReportRL    = data.dt_ESP_0x116.ESP_WhlMovgDir_RL;
  vsi.Gear_ReportGear_RPT_STATE = data.dt_VCU_0x214.VCU_GearSig;
  vsi.Steering_ReportANGLE      = data.dt_EPS_0x1C2.EPS_SteerWhlAgSig; // (deg)
#else
  vsi.potMap_reset_KM = 0;
  vsi.WheelSpeed_ReportRR           = aWhlSpd_ReportRR[KM_FrameCount_i];
  vsi.WheelSpeed_ReportRL           =  WhlSpd_ReportRL[KM_FrameCount_i];
  vsi.WheelPosition_ReportRR        = WhlPos_ReportRR[KM_FrameCount_i];
  vsi.WheelPosition_ReportRL        = WhlPos_ReportRL[KM_FrameCount_i];
  vsi.Gear_ReportGear_RPT_STATE     = Gear_RPT_State[KM_FrameCount_i];
  vsi.Steering_ReportANGLE          = Steering_ReportANGLE[KM_FrameCount_i];
  KM_FrameCount_i++;
  if (KM_FrameCount_i >= MAX_TEST_DATA)
  {
      KM_FrameCount_i = 0;
  }
#endif
  return vsi;
}

void DataProviderKM::transmit_kinematic_output(ExtY_KinematicModel_T* km_output_simulink)
{
    km_output_sigm.m_Global_dx = km_output_simulink->m_Global_x;
    km_output_sigm.m_Global_dy = km_output_simulink->m_Global_y;
    km_output_sigm.m_Global_dyaw_rad = km_output_simulink->m_Global_yaw_deg * 0.0174532924F;

    km_output_sigm.dx_m = km_output_simulink->dx_mps;
    km_output_sigm.dy_m = km_output_simulink->dy_mps;
    km_output_sigm.dyaw_rad = km_output_simulink->dyaw_degps * 0.0174532924F;

    km_output_sigm.timestamp_s = 0;

    // ExtY_Kinematic_T is an old struct, should be removed in future
    ExtY_Kinematic_T km_out_old_format;
    memcpy((void*)&km_out_old_format, (void*)&km_output_simulink, sizeof(km_out_old_format));
#if SIGM_TESTING
    SigMgr_Data_IKinematicData_t_Put(&km_output_sigm);
    SigMgr_Data_ExtY_Kinematic_T_Put(&km_out_old_format);
#endif
}

} // namespace KM
 
