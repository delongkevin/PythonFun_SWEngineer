//--------------------------------------------------------------------------
/// @file JobKM.cpp
/// @brief Contains the KM job implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobKM.h"
#include "DataProviderKM.h"

#if DEBUG_PRINT
  #include "../../../../main_domain/console_io/include/app_log.h"
#endif

extern ExtU_KinematicModel_T KinematicModel_U;
extern ExtY_KinematicModel_T KinematicModel_Y;

namespace KM
{

// *************************************************************************
JobKM::JobKM(IDataProviderKM *b_DPKM_ro)
{
	dataProvider_ro = b_DPKM_ro;
}

// *************************************************************************
JobKM::~JobKM()
{
}

// *************************************************************************
bool_t JobKM::onInit_b()
{
    MdlStart();

    //UART_printf("\n ###### JobKM init done ######n");
    return true;
}

// *************************************************************************
void JobKM::onVariantChanged_v(bool_t i_FirstTime_b)
{
    //UART_printf("\n ###### JobKM onVariantChanged_v done ###### \n");
}

// *************************************************************************
bool_t JobKM::onRun_b()
{
    start_v();
    execute_v();
    if(!hasNext_b())
    {
     // UART_printf("\n\n ##### JobKM run: File Ended ###### \n \n");
      //break;
    }
    end_v();
  return true;
}
// *************************************************************************
void JobKM::onCleanup_v()
{
  //UART_printf("\n ###### JobKM onCleanup_v done ###### \n");
}

// *************************************************************************
void JobKM::start_v(void)
{
  KinematicModel_U = dataProvider_ro->get_vehicle_signal_input();
  return;
}

// *************************************************************************
bool_t JobKM::hasNext_b()
{
  bool out = true;
  return out;
}

// *************************************************************************
void JobKM::execute_v()
{
#if 0
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(Kinematic_M, "Overrun");
    return;
  }

  OverrunFlag = true;
#endif

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model for base rate */
  MdlOutputs(0);
  MdlUpdate(0);

  /* Get model outputs here */

  /* Indicate task complete */
//  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
  return;
}

// *************************************************************************
void JobKM::end_v()
{
  #if DEBUG_PRINT
  appLogPrintf(
    "KM-IN: Reset %f, SpdRR %f, SpdRL %f, PosRR %d, PosRL %d, Gr %d, Strw %f\n",
        KinematicModel_U.potMap_reset_KM,
        KinematicModel_U.WheelSpeed_ReportRR,
        KinematicModel_U.WheelSpeed_ReportRL,
        KinematicModel_U.WheelPosition_ReportRR,
        KinematicModel_U.WheelPosition_ReportRL,
        KinematicModel_U.Gear_ReportGear_RPT_STATE,
        KinematicModel_U.Steering_ReportANGLE
  );
  // appLogPrintf(
  //   "KM-SIMULINK-OUT: X %f, Y %f, Yaw %f, ds %f, dx %f, dy %f, dyaw %f\n",
  //       KinematicModel_Y.m_Global_x,
  //       KinematicModel_Y.m_Global_y,
  //       KinematicModel_Y.m_Global_yaw_deg,
  //       KinematicModel_Y.ds_mps,
  //       KinematicModel_Y.dx_mps,
  //       KinematicModel_Y.dy_mps,
  //       KinematicModel_Y.dyaw_degps
  // );
  appLogPrintf(
    "KM-SIGM-OUT: X %f, Y %f, Yaw %f, Time %f, dx %f, dy %f, dyaw %f\n",
        dataProvider_ro->km_output_sigm.m_Global_dx,
        dataProvider_ro->km_output_sigm.m_Global_dy,
        dataProvider_ro->km_output_sigm.m_Global_dyaw_rad,
        dataProvider_ro->km_output_sigm.timestamp_s,
        dataProvider_ro->km_output_sigm.dx_m,
        dataProvider_ro->km_output_sigm.dy_m,
        dataProvider_ro->km_output_sigm.dyaw_rad
  );
  #endif
  //Set the KM output data over signal manager so it can be utilized by other modules.
  dataProvider_ro->transmit_kinematic_output(&KinematicModel_Y);
  /* Terminate model */
  MdlTerminate();
  //UART_printf("\n ##### JobKM end_v ##### ");
}

// *************************************************************************
void JobKM::dump_v()
{
}

} //namespace KM
