//--------------------------------------------------------------------------
/// @file DataProviderCALSM.cpp
/// @brief Contains implementation of CALSM Dataprovider interface
///
/// DataProvider is an interface between calsm module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda kavrady(ananda.kavrady@magna.com)
//  --------------------------------------------------------------------------

#include "DataProviderCALSM.h"
#include "CalDataProvider_defs.h"
#include "DegManagerDef.h"
#include <fsdata/fsdata.h>

#define CALSM_DEBUG_ENABLE		      0
#define CALSM_ENABLE_ALGO		      1
#define CALSM_DEBUG_PRINTS_ENABLE     0
#define CALSM_ENABLE_ERASE_OCNVMDATA  0
#define EOL_CORNER_ENHANCEMENT    1

extern ME_Hydra3defs_S_AlgoControlHeader_t AlgoControl_header;
extern ME_Hydra3defs_S_AlgoControlData_t algoControl_data;
extern aSigConverterTypes_S_Rx_ZynqMRelatedData_t Rx_ZynqRelatedData;

extern ME_Hydra3defs_S_EOLStatus_t EOLrxStatus;
extern ME_Hydra3defs_S_OCStatus_t SCrxStatus;
extern ME_Hydra3defs_S_OCStatus_t OCrxStatus;

extern ME_Hydra3defs_E_CameraID_t aZynqM_v_EOLCurrentCam_e;
extern ME_Hydra3defs_E_CameraID_t aZynqM_v_SCCurrentCam_e;
extern ME_Hydra3defs_E_CameraID_t aZynqM_v_OCCurrentCam_e;

extern TbSVS_S_SVSCamEOLCalibDataToNVM_t EOLCalibDataToNVM;
extern TbSVS_S_SVSCamSCCalibDataToNVM_t SCCalibDataToNVM;
extern TbSVS_S_SVSCamOCCalibDataToNVM_t OCCalibDataToNVM;
extern TbSVS_S_SVSCamCurrentCalibDataToNVM_t CurrentCalibDataToNVM;
extern SVS_S_EOLTranslationData_t m_SCPosAdjustment;

extern TbSVS_e_SVSOutputToDiagMgrCamCalib_t       v_Calib_Diag_data;
extern TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t functionalSettingsNVM;
extern boolean aZynqM_v_NVMInitDone_e;
extern boolean aZynqM_v_ShutdownTriggered_b;
extern boolean bIsEolSuccessPrevCycle;
extern boolean bIsSCSuccessPrevCycle;

/* TSC Screen */
extern aZynqM_S_ScScreenType_t aZynqM_v_TscSetScreen;
extern aZynqM_S_ScScreenType_t aZynqM_v_TscGetScreen;

/* Calibration FIDs */
extern CalsmFIDs_t m_calsmFIDs;

extern boolean IsEOLFsdataUpdateReq;

namespace calsm
{
  DataProviderCALSM::DataProviderCALSM(container::IDataProvider& b_DataProvider_ro)
    : IDataProviderCALSM()
    , dataProvider_ro(b_DataProvider_ro)
  {

  }

  DataProviderCALSM::~DataProviderCALSM()
  {
  }

/**************************************************************************************************
 * Function Name : get_calib_vehicle_signal_input
 * Description   : Get vehicle data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::get_calib_vehicle_signal_input(void)
{
  /* DD-ID: {0B91C2D3-2FD1-46e6-9940-EAA50A4C5FE4}*/
  /* Receiving bus signals */ 
  ME_VehInp_to_IpcSignals_t v_vehData = dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
  static boolean PRX_CanNod27_b_prev = 0;
  static int ASCM_Stat_prev;


#if !CALSM_DEBUG_ENABLE
  /* Required vehicle signal for SVS camera calibration state machine */
  Rx_ZynqRelatedData.LeftFrontAJAR_e    = (TeSVS_e_DoorStsCamCalib)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.PsngrDoorSts;
  Rx_ZynqRelatedData.LeftRearAJAR_e     = (TeSVS_e_DoorStsCamCalib)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.LHRDoorSts;
  Rx_ZynqRelatedData.RightFrontAJAR_e   = (TeSVS_e_DoorStsCamCalib)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.DriverDoorSts;
  Rx_ZynqRelatedData.RightRearAJAR_e    = (TeSVS_e_DoorStsCamCalib)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.RHRDoorSts;
  Rx_ZynqRelatedData.tlgAJAR_e          = (TeSVS_e_DoorStsCamCalib)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts;
  Rx_ZynqRelatedData.hoodAJAR_e         = e_DoorCLOSED;
  Rx_ZynqRelatedData.mirrorLefStatus_u8 = MirrorDrivingPosition;
  Rx_ZynqRelatedData.mirrorRigStatus_u8 = MirrorDrivingPosition;

  Rx_ZynqRelatedData.gearStatus_e      = (TeSVS_e_GearPosCamCalib)v_vehData.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition;;
  Rx_ZynqRelatedData.vehSpeed_f32      = v_vehData.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig * 1.0f;
  Rx_ZynqRelatedData.steeringAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * 1.0f;
  Rx_ZynqRelatedData.ignitionStatus_e  = (TeSVS_e_PowerModeCamCalib)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts;

  /*Read Proxi data*/
  Rx_ZynqRelatedData.ProxiData_s       = dataProvider_ro.getSigMData_po()->getME_Proxi_to_IpcSignals_t();
  Rx_ZynqRelatedData.ASCMStatus_e      = (TeSVS_e_ASCMSts)v_vehData.CAN2_to_IPC.DataInp_ASCM_FD_2.ASCM_Stat;


#if CALSM_DEBUG_PRINTS_ENABLE
  if ((PRX_CanNod27_b_prev != Rx_ZynqRelatedData.ProxiData_s.PRX_CanNod27_b) || (ASCM_Stat_prev != Rx_ZynqRelatedData.ASCMStatus_e))
  {
    ME_Debugger_F_Printf_v("Proxi_CanNod27_b : %d,  ASCMStatus_e : %d  \n ", Rx_ZynqRelatedData.ProxiData_s.PRX_CanNod27_b , (TeSVS_e_ASCMSts)v_vehData.CAN2_to_IPC.DataInp_ASCM_FD_2.ASCM_Stat);
    PRX_CanNod27_b_prev = Rx_ZynqRelatedData.ProxiData_s.PRX_CanNod27_b;
    ASCM_Stat_prev      = Rx_ZynqRelatedData.ASCMStatus_e;
  }
#endif

#if CALSM_DEBUG_PRINTS_ENABLE
  if ( (TRUE == aZynqM_F_EOL_IsRequested_b()) || (TRUE == aZynqM_F_SC_IsRequested_b()) )
  {
    ME_Debugger_F_Printf_v("CALSM get_calib_vehicle_signal_input() ...\n");
    ME_Debugger_F_Printf_v("CALSM PsngrDoorSts = %d \n",Rx_ZynqRelatedData.LeftFrontAJAR_e);
    ME_Debugger_F_Printf_v("CALSM LHRDoorSts = %d \n",Rx_ZynqRelatedData.LeftRearAJAR_e);
    ME_Debugger_F_Printf_v("CALSM DriverDoorSts = %d \n",Rx_ZynqRelatedData.RightFrontAJAR_e);
    ME_Debugger_F_Printf_v("CALSM RHRDoorSts = %d \n",Rx_ZynqRelatedData.RightRearAJAR_e);
    ME_Debugger_F_Printf_v("CALSM RHatchSts = %d \n",Rx_ZynqRelatedData.tlgAJAR_e);
    ME_Debugger_F_Printf_v("CALSM ShiftLeverPosition = %d \n",Rx_ZynqRelatedData.gearStatus_e);
    ME_Debugger_F_Printf_v("CALSM CmdIgnSts = %d \n",Rx_ZynqRelatedData.ignitionStatus_e);
    ME_Debugger_F_Printf_v("CALSM vehSpeed_f32 = %f \n",Rx_ZynqRelatedData.vehSpeed_f32);
    ME_Debugger_F_Printf_v("CALSM steeringAngle_f32 = %f \n",Rx_ZynqRelatedData.steeringAngle_f32);
  }
#endif
#else

  Rx_ZynqRelatedData.LeftFrontAJAR_e = e_DoorCLOSED;
  Rx_ZynqRelatedData.LeftRearAJAR_e = e_DoorCLOSED;
  Rx_ZynqRelatedData.RightFrontAJAR_e = e_DoorCLOSED;
  Rx_ZynqRelatedData.RightRearAJAR_e = e_DoorCLOSED;
  Rx_ZynqRelatedData.tlgAJAR_e = e_DoorCLOSED;
  Rx_ZynqRelatedData.hoodAJAR_e = e_DoorCLOSED;
  Rx_ZynqRelatedData.mirrorLefStatus_u8 = MirrorDrivingPosition;
  Rx_ZynqRelatedData.mirrorRigStatus_u8 = MirrorDrivingPosition;
  Rx_ZynqRelatedData.gearStatus_e = e_D_GEAR;
  Rx_ZynqRelatedData.vehSpeed_f32 = 5.0f;
  Rx_ZynqRelatedData.steeringAngle_f32 = 5.0f;
  Rx_ZynqRelatedData.ignitionStatus_e  = e_PW_MODE_RUN;
  #endif
}

/**************************************************************************************************
 * Function Name : get_shutdown_input
 * Description   : Get voltage data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::get_shutdown_input(void)
{
  /* DD-ID: {F7115671-1DE9-4cc1-AB20-40A43DAE0DF7}*/
  static bool_t v_ShutdwnFlag = FALSE;

  /* Receiving the shutdown signal */
  SSM_SystemState v_SysState ;

  v_SysState.SystemState = dataProvider_ro.getSigMData_po()->getSSM_SystemState().SystemState;

  if( SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i == v_SysState.SystemState )
  {
    aZynqM_v_ShutdownTriggered_b = TRUE;
    
    if (FALSE == v_ShutdwnFlag )
    {
      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("aZynqM_v_ShutdownTriggered_b = 1 ...\n");
      #endif 

      v_ShutdwnFlag = TRUE;
    }
  }
}

/**************************************************************************************************
 * Function Name : get_calib_diagmgr_input
 * Description   : Get diag request
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::get_calib_diagmgr_input(void)
{
  /* DD-ID: {2E961369-196C-4cec-B7B8-76E40D6004F4}*/
#if !CALSM_DEBUG_ENABLE
  bool_t  v_status_b;

  /* System is generating an exception on enabling this function as there is no valid inputs */ 
  TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t DiagData = dataProvider_ro.getSigMData_po()->getTbSVS_e_DiagMgrOutputToSVSCamCalibSM_t(&v_status_b );

  /* Defines the new routine (start/stop) is requested */
  if (TRUE == v_status_b)
  {
    #if CALSM_DEBUG_PRINTS_ENABLE
      ME_Debugger_F_Printf_v("(CALSM GetDiagInput: isRoutineRequested=%d, camFront=%d, camLeft=%d, camRear=%d, camRight=%d, targetDistance=%d, targetID=%d, calibType=%d)\n",
		                  DiagData.isRoutineRequested,
						  DiagData.cameraMask.camFront, DiagData.cameraMask.camLeft, DiagData.cameraMask.camRear, DiagData.cameraMask.camRight,
						  DiagData.targetDistance, DiagData.targetID, DiagData.calibType);

      ME_Debugger_F_Printf_v("CALSM Erase Cal Data : EraseCamId=%d ,EraseCalibType=%d,  isCalibNVMEraseRequested=%d, isCalibResetRoutineEraseRequested=%d \n",
               DiagData.EraseCalibNVMData.EraseCamId, DiagData.EraseCalibNVMData.EraseCalibType ,
              DiagData.EraseCalibNVMData.isCalibNVMEraseRequested, DiagData.EraseCalibNVMData.isCalibResetRoutineEraseRequested);
    #endif

    uint16  DiagTargetDistance        = (uint16)DiagData.targetDistance;
    uint16  DiagTargetID              = (uint16)DiagData.targetID;
    aZynqM_S_CamMask_t DiagCamMask    = DiagData.cameraMask;


    /*Store the Erase Calibration info*/
    if ((DiagData.EraseCalibNVMData.isCalibNVMEraseRequested == TRUE) || (DiagData.EraseCalibNVMData.isCalibResetRoutineEraseRequested == TRUE))
    {
      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM Calling Get EraseCalibration info function \n ");
      #endif
      Get_EraseCalibration_info(DiagData);
    }

    if (CalibrationID_EOL == DiagData.calibType)
    {
      #if EOL_CORNER_ENHANCEMENT
      bsp::TIOVXHost &v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
      bsp::TIOVXVideoInput &v_videoInput_ro = v_host_ro.getVideoInput_ro();
      v_videoInput_ro.eeControl(FALSE);
      #endif
      
      aZynqM_F_EOL_Request_b(DiagData.isRoutineRequested, DiagCamMask);

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM EOL SM triggered \n");
      #endif
    }
    else if (CalibrationID_SC == DiagData.calibType)
    {
      aZynqM_F_SC_Request_b(DiagData.isRoutineRequested, DiagCamMask);

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM TSC SM triggered \n");
      #endif
    }
    else
    {
    	/* Do Nothing */
    }
  }
  else
  {
    /* Do Nothing */
  }

  /* Get the FID details from Diag Mgr */
  Get_Calib_FIDs();

  /* Get the functional settign parameter to be use for OC */
  Get_FunctionalSettings();

#else
    aZynqM_S_CamMask_t DiagCamMask;
    DiagCamMask.camFront = 1;
    DiagCamMask.camRear = 1;
    DiagCamMask.camLeft = 1;
    DiagCamMask.camRight = 1;
    
    static int counter = 0;

    if(counter < 51)
    {
      counter++;
      if (counter == 50)
      {
        aZynqM_F_SC_Request_b(TRUE, DiagCamMask);
    	counter = 52;
      }
    }
#endif

}

/**************************************************************************************************
 * Function Name : get_calib_nvmmgr_input
 * Description   : Get calib init data from NVM
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::get_calib_nvmmgr_input(void)
{
  /* DD-ID: {D657C9D2-A8A6-4afc-A700-E4606B25D60D}*/
  ME_Hydra3defs_E_CameraID_t v_LastOCCurrentCam = CamID_None;
  static bool_t v_IsLastCamReadSuccess = false;

  if(FALSE == aZynqM_v_NVMInitDone_e)
  {
    bool_t v_status_b;
    CalDataProvider_MPU_1_0_Def v_data;
    v_data = dataProvider_ro.getSigMData_po()->getCalDataProvider_MPU_1_0_Def();

    if(TRUE == v_data.bValid)
    {
      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("(CALSM NVMInit : %d ...\n)",v_data.bValid);
      #endif

      EOLCalibDataToNVM.bValid = FALSE;
      EOLCalibDataToNVM.FreshnessCount = 0;
      EOLCalibDataToNVM.CamEOL = v_data.CalData_SVSCamEOLCalibData;

      if ( (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.CalibStatus_e) &&
    	   (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.CalibStatus_e) &&
		   (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e) &&
		   (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e) )
      {
    	/* EOL is successfully calibrated for all four cameras in previous cycle */
        bIsEolSuccessPrevCycle = TRUE;
      }
      else
      {
    	/* EOL is not successfully calibrated for all four cameras in previous cycle */
        bIsEolSuccessPrevCycle = FALSE;
      }

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM EOL GetNVMInputCalib Front: (X=%f,Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.X_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.Y_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.Z_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.calibdata.Yaw_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.calibdata.Roll_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.calibdata.Pitch_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamFrontEOL.CamCalibData_STM.calibdata.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM EOL GetNVMInputCalib Left: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.X_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.Y_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.Z_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.calibdata.Yaw_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.calibdata.Roll_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.calibdata.Pitch_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamLeftEOL.CamCalibData_STM.calibdata.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM EOL GetNVMInputCalib Rear: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.X_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.Y_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.Z_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.calibdata.Yaw_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.calibdata.Roll_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.calibdata.Pitch_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM EOL GetNVMInputCalib Right: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.X_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.Y_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.Z_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.calibdata.Yaw_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.calibdata.Roll_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.calibdata.Pitch_f32,
			  v_data.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e);
      #endif

      SCCalibDataToNVM.bValid = FALSE;
      SCCalibDataToNVM.FreshnessCount = 0;
      SCCalibDataToNVM.CamSC = v_data.CalData_SVSCamSCCalibData;

      if ( (ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.CalibStatus_e) &&
    	   (ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.CalibStatus_e) &&
		   (ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.CalibStatus_e) &&
		   (ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e) )
      {
    	/* EOL is successfully calibrated for all four cameras in previous cycle */
    	bIsSCSuccessPrevCycle = TRUE;
      }
      else
      {
    	/* EOL is not successfully calibrated for all four cameras in previous cycle */
    	bIsSCSuccessPrevCycle = FALSE;
      }

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM TSC GetNVMInputCalib Front: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
		      v_data.CalData_SVSCamSCCalibData.CamFrontSC.CamCalibData_STM.Yaw_f32,
		      v_data.CalData_SVSCamSCCalibData.CamFrontSC.CamCalibData_STM.Roll_f32,
		      v_data.CalData_SVSCamSCCalibData.CamFrontSC.CamCalibData_STM.Pitch_f32,
		      v_data.CalData_SVSCamSCCalibData.CamFrontSC.CamCalibData_STM.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM TSC GetNVMInputCalib Left: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
		      v_data.CalData_SVSCamSCCalibData.CamLeftSC.CamCalibData_STM.Yaw_f32,
		      v_data.CalData_SVSCamSCCalibData.CamLeftSC.CamCalibData_STM.Roll_f32,
		      v_data.CalData_SVSCamSCCalibData.CamLeftSC.CamCalibData_STM.Pitch_f32,
		      v_data.CalData_SVSCamSCCalibData.CamLeftSC.CamCalibData_STM.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM TSC GetNVMInputCalib Rear: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
		      v_data.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.Yaw_f32,
		      v_data.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.Roll_f32,
		      v_data.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.Pitch_f32,
		      v_data.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM TSC GetNVMInputCalib Right: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
		      v_data.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.Yaw_f32,
		      v_data.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.Roll_f32,
		      v_data.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.Pitch_f32,
		      v_data.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.CalibStatus_e);
      #endif

      OCCalibDataToNVM.bValid = FALSE;
      OCCalibDataToNVM.FreshnessCount = 0;
      OCCalibDataToNVM.CamOC = v_data.CalData_SVSCamOCCalibData;

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM OC GetNVMInputCalib Front: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamOCCalibData.CamFrontOC.CamCalibData_STM.Yaw_f32,
	          v_data.CalData_SVSCamOCCalibData.CamFrontOC.CamCalibData_STM.Roll_f32,
	          v_data.CalData_SVSCamOCCalibData.CamFrontOC.CamCalibData_STM.Pitch_f32,
	          v_data.CalData_SVSCamOCCalibData.CamFrontOC.CamCalibData_STM.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM OC GetNVMInputCalib Left: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamOCCalibData.CamLeftOC.CamCalibData_STM.Yaw_f32,
	          v_data.CalData_SVSCamOCCalibData.CamLeftOC.CamCalibData_STM.Roll_f32,
	          v_data.CalData_SVSCamOCCalibData.CamLeftOC.CamCalibData_STM.Pitch_f32,
	          v_data.CalData_SVSCamOCCalibData.CamLeftOC.CamCalibData_STM.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM OC GetNVMInputCalib Rear: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamOCCalibData.CamRearOC.CamCalibData_STM.Yaw_f32,
	          v_data.CalData_SVSCamOCCalibData.CamRearOC.CamCalibData_STM.Roll_f32,
	          v_data.CalData_SVSCamOCCalibData.CamRearOC.CamCalibData_STM.Pitch_f32,
	          v_data.CalData_SVSCamOCCalibData.CamRearOC.CamCalibData_STM.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM OC GetNVMInputCalib Right: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamOCCalibData.CamRightOC.CamCalibData_STM.Yaw_f32,
	          v_data.CalData_SVSCamOCCalibData.CamRightOC.CamCalibData_STM.Roll_f32,
	          v_data.CalData_SVSCamOCCalibData.CamRightOC.CamCalibData_STM.Pitch_f32,
	          v_data.CalData_SVSCamOCCalibData.CamRightOC.CamCalibData_STM.CalibStatus_e);
      #endif

      CurrentCalibDataToNVM.bValid = FALSE;
      CurrentCalibDataToNVM.FreshnessCount = 0;
      CurrentCalibDataToNVM.CamCurrent = v_data.CalData_SVSCamCurrentCalibData;

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("CALSM CurrentCalib GetNVMInputCalib Front: (X=%f,Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.X_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.Y_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.Z_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Yaw_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Roll_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.Pitch_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM CurrentCalib GetNVMInputCalib Left: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.X_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.Y_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.Z_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.Yaw_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.Roll_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.Pitch_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM CurrentCalib GetNVMInputCalib Rear: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.X_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.Y_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.Z_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.Yaw_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.Roll_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.Pitch_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e);

        ME_Debugger_F_Printf_v("CALSM CurrentCalib GetNVMInputCalib Right: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.X_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.Y_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.Z_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.Yaw_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.Roll_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.Pitch_f32,
	          v_data.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
      #endif

      /* Reading the last OC stored cam id from the fs data system */
      fsdata::fsdata_read_data("/fs/OcCalib.txt", (char*)&m_SCPosAdjustment, sizeof (m_SCPosAdjustment));

      #if CALSM_DEBUG_PRINTS_ENABLE
        ME_Debugger_F_Printf_v("fsdata_read_data called :  FRONTX=%f, FRONTY=%f, FRONTZ=%f, FRONTP=%f, FRONTR=%f, FRONTY=%f\n", m_SCPosAdjustment.CamFrontEOL.X_f32, m_SCPosAdjustment.CamFrontEOL.Y_f32, m_SCPosAdjustment.CamFrontEOL.Z_f32, m_SCPosAdjustment.CamFrontEOL.Pitch_f32, m_SCPosAdjustment.CamFrontEOL.Roll_f32, m_SCPosAdjustment.CamFrontEOL.Yaw_f32);
        ME_Debugger_F_Printf_v("fsdata_read_data called :  LEFTX=%f, LEFTY=%f, LEFTZ=%f, LEFTP=%f, LEFTR=%f, LEFTY=%f\n", m_SCPosAdjustment.CamLeftEOL.X_f32, m_SCPosAdjustment.CamLeftEOL.Y_f32, m_SCPosAdjustment.CamLeftEOL.Z_f32, m_SCPosAdjustment.CamLeftEOL.Pitch_f32, m_SCPosAdjustment.CamLeftEOL.Roll_f32, m_SCPosAdjustment.CamLeftEOL.Yaw_f32);
        ME_Debugger_F_Printf_v("fsdata_read_data called :  REARX=%f, REARY=%f, REARZ=%f, REARP=%f, REARR=%f, REARY=%f\n", m_SCPosAdjustment.CamRearEOL.X_f32, m_SCPosAdjustment.CamRearEOL.Y_f32, m_SCPosAdjustment.CamRearEOL.Z_f32, m_SCPosAdjustment.CamRearEOL.Pitch_f32, m_SCPosAdjustment.CamRearEOL.Roll_f32, m_SCPosAdjustment.CamRearEOL.Yaw_f32);
        ME_Debugger_F_Printf_v("fsdata_read_data called :  RIGHTX=%f, RIGHTY=%f, RIGHTZ=%f, RIGHTP=%f, RIGHTR=%f, RIGHTY=%f\n", m_SCPosAdjustment.CamRightEOL.X_f32, m_SCPosAdjustment.CamRightEOL.Y_f32, m_SCPosAdjustment.CamRightEOL.Z_f32, m_SCPosAdjustment.CamRightEOL.Pitch_f32, m_SCPosAdjustment.CamRightEOL.Roll_f32, m_SCPosAdjustment.CamRightEOL.Yaw_f32);
      #endif
      aZynqM_v_NVMInitDone_e = TRUE;
    }
  }

  /* ME_Debugger_F_Printf_v("CALSM get_calib_nvmmgr_input() ...\n"); */
}

/**************************************************************************************************
 * Function Name : get_calib_algo_input
 * Description   : Get response from algorithm
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::get_calib_algo_input(void)
{
  /* DD-ID: {D6A0A742-5976-4e0c-8B70-F03DE467A440}*/
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t v_CalibAlgoData;

  #if CALSM_DEBUG_PRINTS_ENABLE
    static uint8 v_SCPrevCamId = 0;
    static uint8 v_SCPrevAlgoId = 0;
    static uint8 v_SCPrevErrId = 0;

    static uint8 v_OCPrevCamId = 0;
    static uint8 v_OCPrevAlgoId = 0;
    static uint8 v_OCPrevErrId = 0;
  #endif

  /* Receives the data from Algo */
  v_CalibAlgoData = dataProvider_ro.getCalSmMData_po()->getSVSCalibAlgoToSMCamCalib();

  if (v_CalibAlgoData.EOL_Status_STM.camID_e == aZynqM_v_EOLCurrentCam_e)
  {
    /* Providing the Algo received data to Calib state machine */
    EOLrxStatus = v_CalibAlgoData.EOL_Status_STM;
  }
  else
  {
    (void)memset(&EOLrxStatus, 0x00, sizeof(EOLrxStatus));
  }

    if ((v_CalibAlgoData.OC_Status_STM.camID_e == aZynqM_v_SCCurrentCam_e) && (AlgoID_SC == v_CalibAlgoData.CalibAlgoType) )
      {
        /* TODO: This condition needs to be manage in algo side as well */
    	SCrxStatus = v_CalibAlgoData.OC_Status_STM;

        #if CALSM_DEBUG_PRINTS_ENABLE
        if ((v_SCPrevCamId != v_CalibAlgoData.OC_Status_STM.camID_e) ||
            (v_SCPrevAlgoId != v_CalibAlgoData.OC_Status_STM.algoState_e) ||
    		(v_SCPrevErrId != v_CalibAlgoData.OC_Status_STM.errorCode_e) )
        {
          ME_Debugger_F_Printf_v("CALSM SC GetAlgoInputCalib: (ErrCode=%d,AlgoState=%d CamID=%d) \n",
    		                         v_CalibAlgoData.OC_Status_STM.errorCode_e,
    								 v_CalibAlgoData.OC_Status_STM.algoState_e,
    		                         v_CalibAlgoData.OC_Status_STM.camID_e);

          v_SCPrevCamId = v_CalibAlgoData.OC_Status_STM.camID_e;
          v_SCPrevAlgoId = v_CalibAlgoData.OC_Status_STM.algoState_e;
          v_SCPrevErrId = v_CalibAlgoData.OC_Status_STM.errorCode_e;
        }
        #endif
      }
      else
      {
        /* TODO: This may need to send the SC and OC and new interfaces has to be define for it */
        (void)memset(&SCrxStatus, 0x00, sizeof(SCrxStatus));

        #if CALSM_DEBUG_PRINTS_ENABLE
        if ((v_SCPrevCamId != v_CalibAlgoData.OC_Status_STM.camID_e) ||
            (v_SCPrevAlgoId != v_CalibAlgoData.OC_Status_STM.algoState_e) ||
    		(v_SCPrevErrId != v_CalibAlgoData.OC_Status_STM.errorCode_e) )
        {
          ME_Debugger_F_Printf_v("CALSM SC GetAlgoInputCalib RESET : (ErrCode=%d,AlgoState=%d CamID=%d) \n",
    		                         v_CalibAlgoData.OC_Status_STM.errorCode_e,
    								 v_CalibAlgoData.OC_Status_STM.algoState_e,
    		                         v_CalibAlgoData.OC_Status_STM.camID_e);

          v_SCPrevCamId = v_CalibAlgoData.OC_Status_STM.camID_e;
          v_SCPrevAlgoId = v_CalibAlgoData.OC_Status_STM.algoState_e;
          v_SCPrevErrId = v_CalibAlgoData.OC_Status_STM.errorCode_e;
        }
        #endif
      }

  if ( (v_CalibAlgoData.OC_Status_STM.camID_e == aZynqM_v_OCCurrentCam_e) && (AlgoID_OC == v_CalibAlgoData.CalibAlgoType) )
  {
    /* TODO: This condition needs to be manage in algo side as well */
	OCrxStatus = v_CalibAlgoData.OC_Status_STM;

    #if CALSM_DEBUG_PRINTS_ENABLE
    if ((v_OCPrevCamId != v_CalibAlgoData.OC_Status_STM.camID_e) ||
        (v_OCPrevAlgoId != v_CalibAlgoData.OC_Status_STM.algoState_e) ||
		(v_OCPrevErrId != v_CalibAlgoData.OC_Status_STM.errorCode_e) )
    {
      ME_Debugger_F_Printf_v("CALSM OC GetAlgoInputCalib: (ErrCode=%d,AlgoState=%d CamID=%d) \n",
		                         v_CalibAlgoData.OC_Status_STM.errorCode_e,
								 v_CalibAlgoData.OC_Status_STM.algoState_e,
		                         v_CalibAlgoData.OC_Status_STM.camID_e);

      v_OCPrevCamId = v_CalibAlgoData.OC_Status_STM.camID_e;
      v_OCPrevAlgoId = v_CalibAlgoData.OC_Status_STM.algoState_e;
      v_OCPrevErrId = v_CalibAlgoData.OC_Status_STM.errorCode_e;
    }
    #endif
  }
  else
  {
    /* TODO: This may need to send the SC and OC and new interfaces has to be define for it */
    (void)memset(&OCrxStatus, 0x00, sizeof(OCrxStatus));

    #if CALSM_DEBUG_PRINTS_ENABLE
    if ((v_OCPrevCamId != v_CalibAlgoData.OC_Status_STM.camID_e) ||
        (v_OCPrevAlgoId != v_CalibAlgoData.OC_Status_STM.algoState_e) ||
		(v_OCPrevErrId != v_CalibAlgoData.OC_Status_STM.errorCode_e) )
    {
      ME_Debugger_F_Printf_v("CALSM OC GetAlgoInputCalib RESET : (ErrCode=%d,AlgoState=%d CamID=%d) \n",
		                         v_CalibAlgoData.OC_Status_STM.errorCode_e,
								 v_CalibAlgoData.OC_Status_STM.algoState_e,
		                         v_CalibAlgoData.OC_Status_STM.camID_e);

      v_OCPrevCamId = v_CalibAlgoData.OC_Status_STM.camID_e;
      v_OCPrevAlgoId = v_CalibAlgoData.OC_Status_STM.algoState_e;
      v_OCPrevErrId = v_CalibAlgoData.OC_Status_STM.errorCode_e;
    }
    #endif
  }

#if 0
  if (v_CalibAlgoData.OC_Status_STM.camID_e == aZynqM_v_OCCurrentCam_e)
  {
    /* TODO: This condition needs to be manage in algo side as well */
    OCrxStatus = v_CalibAlgoData.OC_Status_STM;
  }
  else
  {
    /* TODO: This may need to send the SC and OC and new interfaces has to be define for it */
    (void)memset(&OCrxStatus, 0x00, sizeof(OCrxStatus));
  }
#endif
  #if CALSM_DEBUG_PRINTS_ENABLE
    static uint8 v_PrevCamId = 0;

    if( (TRUE == aZynqM_F_EOL_IsRequested_b()) && (v_PrevCamId != v_CalibAlgoData.EOL_Status_STM.camID_e) )
      {
        ME_Debugger_F_Printf_v("CALSM GetAlgoInputCalib: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, ErrCode=%d, CamID=%d) \n",
		                         v_CalibAlgoData.EOL_Status_STM.deltaX_f32,
		                         v_CalibAlgoData.EOL_Status_STM.deltaY_f32,
		                         v_CalibAlgoData.EOL_Status_STM.deltaZ_f32,
		                         v_CalibAlgoData.EOL_Status_STM.deltaYaw_f32,
		                         v_CalibAlgoData.EOL_Status_STM.deltaRoll_f32,
		                         v_CalibAlgoData.EOL_Status_STM.deltaPitch_f32,
		                         v_CalibAlgoData.EOL_Status_STM.errorCode_e,
		                         v_CalibAlgoData.EOL_Status_STM.camID_e);

      v_PrevCamId = v_CalibAlgoData.EOL_Status_STM.camID_e;
    }
    else if ((TRUE == aZynqM_F_SC_IsRequested_b()) && (v_PrevCamId != v_CalibAlgoData.OC_Status_STM.camID_e))
    {
      ME_Debugger_F_Printf_v("CALSM OC GetAlgoInputCalib: (IgnoredFeatures_u32=%f, InvalidFeatures_u32=%f, ValidFeatures_u32=%f, Yaw=%f, Roll=%f, Pitch=%f, ErrCode=%d,AlgoState=%d CamID=%d) \n",
		                         v_CalibAlgoData.OC_Status_STM.IgnoredFeatures_u32,
		                         v_CalibAlgoData.OC_Status_STM.InvalidFeatures_u32,
		                         v_CalibAlgoData.OC_Status_STM.ValidFeatures_u32,
		                         v_CalibAlgoData.OC_Status_STM.deltaYaw_f32,
		                         v_CalibAlgoData.OC_Status_STM.deltaRoll_f32,
		                         v_CalibAlgoData.OC_Status_STM.deltaPitch_f32,
		                         v_CalibAlgoData.OC_Status_STM.errorCode_e,
								 v_CalibAlgoData.OC_Status_STM.algoState_e,
		                         v_CalibAlgoData.OC_Status_STM.camID_e);

      v_PrevCamId = v_CalibAlgoData.OC_Status_STM.camID_e;
    }
  #endif

#if !CALSM_ENABLE_ALGO
  EOLrxStatus.algoState_e = e_EOLFinished;
  EOLrxStatus.errorCode_e = e_EOL_CALIBRATION_SUCCESS;
  
  OCrxStatus.algoState_e = e_OC_CalibrationCompleted;
  OCrxStatus.errorCode_e = e_OC_NoError;
#endif

  /* ME_Debugger_F_Printf_v("CALSM get_calib_algo_input() ...\n"); */
}

/**************************************************************************************************
 * Function Name : set_calib_algo_input
 * Description   : Set request to algorithm
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::set_calib_algo_input(void)
{
  /* DD-ID: {6883F328-9183-4892-933A-1A36A4873A7A}*/
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t v_CalibSMData;

  #if CALSM_DEBUG_PRINTS_ENABLE
    static ME_Hydra3defs_E_AlgoCommand_t v_PrevCmd = AlgoCommand_Unknown;
    static ME_Hydra3defs_E_CameraID_t v_PrevCamId  = CamID_None;
    static ME_Hydra3defs_E_AlgoID_t v_PrevAlgoID = AlgoID_None;
    if ((AlgoControl_header.CurrentCamID != v_PrevCamId) || (AlgoControl_header.AlgoCommand != v_PrevCmd))
    {
      ME_Debugger_F_Printf_v("CALSM SetAlgoInput: AlgoCmd: %d, AlgoId: %d, CamID: %d, (%d, %d)\n",
		                      AlgoControl_header.AlgoCommand,AlgoControl_header.AlgoID,AlgoControl_header.CurrentCamID,
		  	                  v_CalibSMData.AlgoCntrlData_t.data[0],v_CalibSMData.AlgoCntrlData_t.data[1]);
      v_PrevCmd   = AlgoControl_header.AlgoCommand;
      v_PrevCamId = AlgoControl_header.CurrentCamID;
      v_PrevAlgoID = AlgoControl_header.AlgoID;
    }
  #endif
  
  /* The algo control data[4] will intimate other algo, whether SC is running or not */
  algoControl_data.data[SC_ALGO_ACTIVE_BYTE] = (uint8)aZynqM_SC_F_IsAlgoSelected_b();

  /* The algo control data[5] will intimate other algo, whether EOL is running or not */
  algoControl_data.data[EOL_ALGO_ACTIVE_BYTE] = (uint8)aZynqM_EOL_F_IsAlgoSelected_b();
  
  /* The algo control data[6] will intimate other algo, whether OC is running or not */
  algoControl_data.data[OC_ALGO_ACTIVE_BYTE] = (uint8)aZynqM_OC_F_IsAlgoSelected_b();

  (void)memcpy(&v_CalibSMData.AlgoCntrlData_t, &algoControl_data, sizeof(algoControl_data));
  (void)memcpy(&v_CalibSMData.AlgoCntrlHeader_t, &AlgoControl_header, sizeof(AlgoControl_header));

#if CALSM_ENABLE_ALGO
  dataProvider_ro.getCalSmMData_po()->setSVSCalibSMToAlgoCamCalib(v_CalibSMData);
#endif
  /* ME_Debugger_F_Printf_v("CALSM set_calib_algo_input() ...\n"); */

}

/**************************************************************************************************
 * Function Name : set_NVM_CalibData
 * Description   : Set EOL calibrated data to NVM
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::set_NVM_CalibData(void)
{
  /* DD-ID: {242CEB08-6D26-4a07-BF54-CF898B5D8F9A}*/
  if (TRUE == EOLCalibDataToNVM.bValid)
  {
    dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamEOLCalibDataToNVM_v(EOLCalibDataToNVM);
    EOLCalibDataToNVM.bValid = FALSE;

    if ( (TRUE == aZynqM_F_EOL_IsRequested_b()) || ( (TRUE== aZynqM_F_SC_IsRequested_b()) && (TRUE == IsEOLFsdataUpdateReq) ) )
    {
      /* Store the dX, dY and dZ only once when the EOL is performed */
      fsdata::fsdata_store_data("/fs/OcCalib.txt", (char*)&m_SCPosAdjustment, sizeof (m_SCPosAdjustment));
      IsEOLFsdataUpdateReq = FALSE ;

      #if CALSM_DEBUG_PRINTS_ENABLE
       ME_Debugger_F_Printf_v("fsdata_store_data called :  FRONTX=%f, FrontY=%f, FrontZ=%f, FRONTP=%f, FrontR=%f, FrontY=%f\n", m_SCPosAdjustment.CamFrontEOL.X_f32, m_SCPosAdjustment.CamFrontEOL.Y_f32, m_SCPosAdjustment.CamFrontEOL.Z_f32, m_SCPosAdjustment.CamFrontEOL.Pitch_f32, m_SCPosAdjustment.CamFrontEOL.Roll_f32, m_SCPosAdjustment.CamFrontEOL.Yaw_f32);
       ME_Debugger_F_Printf_v("fsdata_store_data called :  LEFTX=%f, LEFTY=%f, LEFTZ=%f, LEFTP=%f, LEFTR=%f, LEFTY=%f\n", m_SCPosAdjustment.CamLeftEOL.X_f32, m_SCPosAdjustment.CamLeftEOL.Y_f32, m_SCPosAdjustment.CamLeftEOL.Z_f32, m_SCPosAdjustment.CamLeftEOL.Pitch_f32, m_SCPosAdjustment.CamLeftEOL.Roll_f32, m_SCPosAdjustment.CamLeftEOL.Yaw_f32);
       ME_Debugger_F_Printf_v("fsdata_store_data called :  REARX=%f, REARY=%f, REARZ=%f, REARP=%f, REARR=%f, REARY=%f\n", m_SCPosAdjustment.CamRearEOL.X_f32, m_SCPosAdjustment.CamRearEOL.Y_f32, m_SCPosAdjustment.CamRearEOL.Z_f32, m_SCPosAdjustment.CamRearEOL.Pitch_f32, m_SCPosAdjustment.CamRearEOL.Roll_f32, m_SCPosAdjustment.CamRearEOL.Yaw_f32);
       ME_Debugger_F_Printf_v("fsdata_store_data called :  RIGHTX=%f, RIGHTY=%f, RIGHTZ=%f, RIGHTP=%f, RIGHTR=%f, RIGHTY=%f\n", m_SCPosAdjustment.CamRightEOL.X_f32, m_SCPosAdjustment.CamRightEOL.Y_f32, m_SCPosAdjustment.CamRightEOL.Z_f32, m_SCPosAdjustment.CamRightEOL.Pitch_f32, m_SCPosAdjustment.CamRightEOL.Roll_f32, m_SCPosAdjustment.CamRightEOL.Yaw_f32);
      #endif
    }

    #if CALSM_DEBUG_PRINTS_ENABLE

    static uint8 v_eoldebugcntr = 0;

    if ( ((ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.CalibStatus_e) ||
         (ME_Hydra3defs_E_CalibAbortedFailed == EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.CalibStatus_e) ||
          (ME_Hydra3defs_E_CalibAbortedFailed == EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.CalibStatus_e)) &&

	     ((ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e) ||
	      (ME_Hydra3defs_E_CalibAbortedFailed == EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e) ||
		 (ME_Hydra3defs_E_CalibAbortedFailed == EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e)) &&

		 (0 == v_eoldebugcntr) )
    {
      ME_Debugger_F_Printf_v("CALSM SetNVM EOL: Front: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.X_f32,
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.Y_f32,
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.Z_f32,
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.Yaw_f32,
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.Roll_f32,
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.Pitch_f32,
            EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.CalibStatus_e,
			EOLCalibDataToNVM.FreshnessCount);

      ME_Debugger_F_Printf_v("CALSM SetNVM EOL: Left: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.X_f32,
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.Y_f32,
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.Z_f32,
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.Yaw_f32,
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.Roll_f32,
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.Pitch_f32,
            EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.CalibStatus_e,
			EOLCalibDataToNVM.FreshnessCount);

      ME_Debugger_F_Printf_v("CALSM SetNVM EOL: Rear: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.X_f32,
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.Y_f32,
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.Z_f32,
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.Yaw_f32,
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.Roll_f32,
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.Pitch_f32,
            EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e,
			EOLCalibDataToNVM.FreshnessCount);

      ME_Debugger_F_Printf_v("CALSM SetNVM EOL: Right: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.X_f32,
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.Y_f32,
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.Z_f32,
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.Yaw_f32,
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.Roll_f32,
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.Pitch_f32,
            EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e,
			EOLCalibDataToNVM.FreshnessCount);

      v_eoldebugcntr++;
    }
    #endif
  }

  if (TRUE == SCCalibDataToNVM.bValid)
  {
    dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamSCCalibDataToNVM_v(SCCalibDataToNVM);
    SCCalibDataToNVM.bValid = FALSE;

    #if CALSM_DEBUG_PRINTS_ENABLE

    static uint8 v_scdebugcntr = 0;

    if ( ((ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.CalibStatus_e) ||
         (ME_Hydra3defs_E_CalibAbortedFailed == SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.CalibStatus_e) ||
          (ME_Hydra3defs_E_CalibAbortedFailed == SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.CalibStatus_e)) &&

	     ((ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.CalibStatus_e) ||
	      (ME_Hydra3defs_E_CalibAbortedFailed == SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e) ||
		 (ME_Hydra3defs_E_CalibAbortedFailed == SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e)) &&

		 (0 == v_scdebugcntr) )
    {
      ME_Debugger_F_Printf_v("CALSM SetNVM TSC: Front: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
            SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.Yaw_f32,
            SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.Roll_f32,
            SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.Pitch_f32,
            SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.CalibStatus_e);

      ME_Debugger_F_Printf_v("CALSM SetNVM TSC: Left: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
            SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.Yaw_f32,
			SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.Roll_f32,
			SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.Pitch_f32,
			SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.CalibStatus_e);

      ME_Debugger_F_Printf_v("CALSM SetNVM TSC: Rear: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.Yaw_f32,
			SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.Roll_f32,
			SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.Pitch_f32,
			SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM.CalibStatus_e);

      ME_Debugger_F_Printf_v("CALSM SetNVM TSC: Right: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.Yaw_f32,
			SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.Roll_f32,
			SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.Pitch_f32,
			SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e);

      v_scdebugcntr++;
    }
    #endif
  }

  if (TRUE == OCCalibDataToNVM.bValid)
  {
	/* The OC data will be saved only during shutdown */
	if (TRUE == aZynqM_F_IsOcDataIPCReady_v())
	{
    /* ToDo :- If the Current Calib data is not getting clear on reset calib data request or reset nvm data request please enable this section. */
    #if CALSM_ENABLE_ERASE_OCNVMDATA
    static ME_Hydra3defs_E_EraseBlockReq_t OCBlock_prev;
    static boolean isCalibNVMEraseRequested_b_prevOC = 0;

    if ((EraseBlockInfo.OCBlock.isCalibResetRoutineEraseRequested == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
    {
      if ((EraseBlockInfo.OCBlock.EraseFront_b == TRUE) || (EraseBlockInfo.OCBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&OCCalibDataToNVM.CamOC.CamFrontOC, 0x00, sizeof(OCCalibDataToNVM.CamOC.CamFrontOC));
      }
      if ((EraseBlockInfo.OCBlock.EraseLeft_b == TRUE) || (EraseBlockInfo.OCBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&OCCalibDataToNVM.CamOC.CamLeftOC, 0x00, sizeof(OCCalibDataToNVM.CamOC.CamLeftOC));
      }
      if ((EraseBlockInfo.OCBlock.EraseRear_b == TRUE) || (EraseBlockInfo.OCBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&OCCalibDataToNVM.CamOC.CamRearOC, 0x00, sizeof(OCCalibDataToNVM.CamOC.CamRearOC));
      }
      if ((EraseBlockInfo.OCBlock.EraseRight_b == TRUE) || (EraseBlockInfo.OCBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&OCCalibDataToNVM.CamOC.CamRightOC, 0x00, sizeof(OCCalibDataToNVM.CamOC.CamRightOC));
      }
      else
      {
        /* Do Nothing : Cam ID None */
      }

    }
      /*Print only on new data */
      if ((0 != (memcmp(&OCBlock_prev, &EraseBlockInfo.OCBlock, sizeof(EraseBlockInfo.OCBlock))) ) || (isCalibNVMEraseRequested_b_prevOC != EraseBlockInfo.isCalibNVMEraseRequested_b))
      {
        #if CALSM_DEBUG_PRINTS_ENABLE
          ME_Debugger_F_Printf_v("CALSM Erasing Online calib data : isCalibResetRoutineEraseRequested=%d, EraseFront_b=%d, EraseLeft_b=%d, EraseRear_b=%d, EraseRight_b=%d, EraseAllCamera_b=%d, isCalibNVMEraseRequested_b=%d,  \n",
             EraseBlockInfo.OCBlock.isCalibResetRoutineEraseRequested,
             EraseBlockInfo.OCBlock.EraseFront_b, EraseBlockInfo.OCBlock.EraseLeft_b,
             EraseBlockInfo.OCBlock.EraseRear_b, EraseBlockInfo.OCBlock.EraseRight_b,
             EraseBlockInfo.OCBlock.EraseAllCamera_b, EraseBlockInfo.isCalibNVMEraseRequested_b);
        #endif
      }
      isCalibNVMEraseRequested_b_prevOC      = EraseBlockInfo.isCalibNVMEraseRequested_b;
      OCBlock_prev                           = EraseBlockInfo.OCBlock;
    #endif

      dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamOCCalibDataToNVM_v(OCCalibDataToNVM);
      OCCalibDataToNVM.bValid = FALSE;
    }

    #if CALSM_DEBUG_PRINTS_ENABLE

    static uint8 v_ocdebugcntr = 0;

    if ( ((ME_Hydra3defs_E_CalibCompletedSuccessful == OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM.CalibStatus_e) ||
         (ME_Hydra3defs_E_CalibAbortedFailed == OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM.CalibStatus_e) ||
          (ME_Hydra3defs_E_CalibAbortedFailed == OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM.CalibStatus_e)) &&

	     ((ME_Hydra3defs_E_CalibCompletedSuccessful == OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM.CalibStatus_e) ||
	      (ME_Hydra3defs_E_CalibAbortedFailed == OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM.CalibStatus_e) ||
		 (ME_Hydra3defs_E_CalibAbortedFailed == OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM.CalibStatus_e)) &&

		 (0 == v_ocdebugcntr) )
    {
      ME_Debugger_F_Printf_v("CALSM SetNVM OC: Front: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
			OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM.Yaw_f32,
			OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM.Roll_f32,
			OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM.Pitch_f32,
			OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM.CalibStatus_e);

      ME_Debugger_F_Printf_v("CALSM SetNVM OC: Left: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM.Yaw_f32,
			OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM.Roll_f32,
			OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM.Pitch_f32,
			OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM.CalibStatus_e);

      ME_Debugger_F_Printf_v("CALSM SetNVM OC: Rear: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM.Yaw_f32,
			OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM.Roll_f32,
			OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM.Pitch_f32,
			OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM.CalibStatus_e);

      ME_Debugger_F_Printf_v("CALSM SetNVM OC: Right: (Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d)\n",
    		OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM.Yaw_f32,
			OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM.Roll_f32,
			OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM.Pitch_f32,
			OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM.CalibStatus_e);

      v_ocdebugcntr++;
    }
    #endif
 }

  if (TRUE == CurrentCalibDataToNVM.bValid)
  {
    static ME_Hydra3defs_E_EraseBlockReq_t CurrentBlock_prev;
    static boolean isCalibNVMEraseRequested_b_prev = 0;

    /*Clear calibration data for selected camera*/
    if ((EraseBlockInfo.CurrentBlock.isCalibResetRoutineEraseRequested == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
    {
      if ((EraseBlockInfo.CurrentBlock.EraseFront_b == TRUE) || (EraseBlockInfo.CurrentBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent, 0x00, sizeof(CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent));
      }
      if ((EraseBlockInfo.CurrentBlock.EraseLeft_b == TRUE) || (EraseBlockInfo.CurrentBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent, 0x00, sizeof(CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent));
      }
      if ((EraseBlockInfo.CurrentBlock.EraseRear_b == TRUE) || (EraseBlockInfo.CurrentBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&CurrentCalibDataToNVM.CamCurrent.CamRearCurrent, 0x00, sizeof(CurrentCalibDataToNVM.CamCurrent.CamRearCurrent));
      }
      if ((EraseBlockInfo.CurrentBlock.EraseRight_b == TRUE) || (EraseBlockInfo.CurrentBlock.EraseAllCamera_b == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE))
      {
        memset(&CurrentCalibDataToNVM.CamCurrent.CamRightCurrent, 0x00, sizeof(CurrentCalibDataToNVM.CamCurrent.CamRightCurrent));
      }
      else
      {
        /* Do Nothing : Cam ID None */
      }

      /*Print only on new data */
      if (( 0 != (memcmp(&CurrentBlock_prev, &EraseBlockInfo.CurrentBlock, sizeof(EraseBlockInfo.CurrentBlock))) ) || (isCalibNVMEraseRequested_b_prev != EraseBlockInfo.isCalibNVMEraseRequested_b))
      {
        #if CALSM_DEBUG_PRINTS_ENABLE
          ME_Debugger_F_Printf_v("CALSM Erasing Current calib data : isCalibResetRoutineEraseRequested=%d, EraseFront_b=%d, EraseLeft_b=%d, EraseRear_b=%d, EraseRight_b=%d, EraseAllCamera_b=%d, isCalibNVMEraseRequested_b=%d,  \n",
             EraseBlockInfo.CurrentBlock.isCalibResetRoutineEraseRequested,
             EraseBlockInfo.CurrentBlock.EraseFront_b, EraseBlockInfo.CurrentBlock.EraseLeft_b,
             EraseBlockInfo.CurrentBlock.EraseRear_b, EraseBlockInfo.CurrentBlock.EraseRight_b,
             EraseBlockInfo.CurrentBlock.EraseAllCamera_b, EraseBlockInfo.isCalibNVMEraseRequested_b);
        #endif
      }
      isCalibNVMEraseRequested_b_prev      = EraseBlockInfo.isCalibNVMEraseRequested_b;
      CurrentBlock_prev                    = EraseBlockInfo.CurrentBlock;

    }

    dataProvider_ro.getSigMData_po()->setTbSVS_S_SVSCamCurrentCalibDataToNVM_v(CurrentCalibDataToNVM);
    CurrentCalibDataToNVM.bValid = FALSE;

    #if CALSM_DEBUG_PRINTS_ENABLE
    
    static uint8 v_currentdebugcntr = 0;

    if ( (((ME_Hydra3defs_E_CalibCompletedSuccessful == CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e) ||
         (ME_Hydra3defs_E_CalibAbortedFailed == CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e) ||
          (ME_Hydra3defs_E_CalibAbortedFailed == CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e)) &&

	     ((ME_Hydra3defs_E_CalibCompletedSuccessful == CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e) ||
	      (ME_Hydra3defs_E_CalibAbortedFailed == CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e)) &&

         ((ME_Hydra3defs_E_CalibCompletedSuccessful == CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e) ||
		 (ME_Hydra3defs_E_CalibAbortedFailed == CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e)) &&

		 (0 == v_currentdebugcntr)) ||

     (((EraseBlockInfo.CurrentBlock.isCalibResetRoutineEraseRequested == TRUE) || (EraseBlockInfo.isCalibNVMEraseRequested_b == TRUE)) && (0 == v_currentdebugcntr)) )

    {
      ME_Debugger_F_Printf_v("CALSM SetNVM Current: Front: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
    		CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.X_f32,
			CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Y_f32,
			CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Z_f32,
			CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.calibdata.Yaw_f32,
			CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.calibdata.Roll_f32,
			CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.calibdata.Pitch_f32,
			CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e,
			CurrentCalibDataToNVM.FreshnessCount);

      ME_Debugger_F_Printf_v("CALSM SetNVM Current: Left: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
    		CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.X_f32,
			CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Y_f32,
			CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Z_f32,
			CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.calibdata.Yaw_f32,
			CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.calibdata.Roll_f32,
			CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.calibdata.Pitch_f32,
			CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e,
			CurrentCalibDataToNVM.FreshnessCount);

      ME_Debugger_F_Printf_v("CALSM SetNVM Current: Rear: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
    		CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.X_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Y_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Z_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.calibdata.Yaw_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.calibdata.Roll_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.calibdata.Pitch_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e,
			CurrentCalibDataToNVM.FreshnessCount);

      ME_Debugger_F_Printf_v("CALSM SetNVM Current: Right: (X=%f, Y=%f, Z=%f, Yaw=%f, Roll=%f, Pitch=%f, CalibSts=%d, FreshCntr=%d)\n",
    		CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.X_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Y_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Z_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.calibdata.Yaw_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.calibdata.Roll_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.calibdata.Pitch_f32,
			CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e,
			CurrentCalibDataToNVM.FreshnessCount);

            v_currentdebugcntr++;
    }
    #endif
  }
  /* ME_Debugger_F_Printf_v("CALSM set_EOL_NVM_CalibData() ...\n"); */
}

/**************************************************************************************************
 * Function Name : set_EOL_DiagMgr_CalibData
 * Description   : Set EOL status to diag
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::set_DiagMgr_CalibData(void)
{
  /* DD-ID: {2D3AFB73-5D6D-49f4-BCD4-8DD3A56CC1AF}*/
  static TbSVS_e_SVSOutputToDiagMgrCamCalib_t v_Calib_Diag_data_Prev;

  Get_EOLSM_CalibData();
  Get_SCSM_CalibData();
  Get_OCSM_CalibData();

  boolean hasChange = (memcmp(&v_Calib_Diag_data_Prev, &v_Calib_Diag_data, sizeof(v_Calib_Diag_data)) == 0) ? false : true;

  if(hasChange)
  {
    dataProvider_ro.getSigMData_po()->setTbSVS_e_SVSOutputToDiagMgrCamCalib_v(v_Calib_Diag_data);
  }

  memcpy(&v_Calib_Diag_data_Prev, &v_Calib_Diag_data, sizeof(v_Calib_Diag_data));
}

/**************************************************************************************************
 * Function Name : set_EOL_DiagMgr_CalibData
 * Description   : Set EOL status to diag
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::Get_EOLSM_CalibData(void)
{
  /* DD-ID: {29F28AA8-D9CA-4f22-A07F-19849E8DCE0A}*/
  /* EOL data */
  v_Calib_Diag_data.EOL_v_IsRequestedByDiag_b = aZynqM_F_EOL_IsRequested_b();
  v_Calib_Diag_data.EOLCompletedCurrentCycle  = aZynqM_F_GetEOLStatusCurrentCycle();
  v_Calib_Diag_data.EOL_StartConditions_STM   = aZynqM_F_EOL_GetStartConditionDetails_s();
  v_Calib_Diag_data.EOL_ModuleState_STM       = aZynqM_F_ModuleState_EOL_STM_GetModuleState_e();

  /* Sends the data for all four cameras */
  if ((CamID_None < aZynqM_v_EOLCurrentCam_e) && (aZynqM_v_EOLCurrentCam_e <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
	v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].errorCode_e  = aZynqM_F_EOL_GetErrorCodeCam_e(aZynqM_v_EOLCurrentCam_e);
	v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].targetData_s = aZynqM_F_EOL_GetTargetDataCam_e(aZynqM_v_EOLCurrentCam_e);

	v_Calib_Diag_data.EOL_CalibStatus_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front] = aZynqM_F_EOL_GetResultCam_e(aZynqM_v_EOLCurrentCam_e);

	 if ( e_EOLFinished == aZynqM_F_EOL_GetAlgoState_e() )
	 {
	   if ( e_EOL_CALIBRATION_SUCCESS == aZynqM_F_EOL_GetErrorCode_e() )
	   {
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaX_f32     = EOLrxStatus.deltaX_f32;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaY_f32     = EOLrxStatus.deltaY_f32;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaZ_f32     = EOLrxStatus.deltaZ_f32;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaYaw_f32   = EOLrxStatus.deltaYaw_f32;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaRoll_f32  = EOLrxStatus.deltaRoll_f32;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaPitch_f32 = EOLrxStatus.deltaPitch_f32;
	   }
	   else
	   {
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaX_f32     = 0.0f;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaY_f32     = 0.0f;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaZ_f32     = 0.0f;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaYaw_f32   = 0.0f;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaRoll_f32  = 0.0f;
         v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaPitch_f32 = 0.0f;
	   }
	 }

    v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].camID_e = aZynqM_F_EOL_GetCurrentCam_e();

    #if CALSM_DEBUG_PRINTS_ENABLE
    static ME_Hydra3defs_E_CameraID_t camIDPrev_e = CamID_None;

    if ( v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].camID_e != camIDPrev_e )
    {
      ME_Debugger_F_Printf_v("CALSM SetDiagMgr EOL: (CS=%d, Y=%f, R=%f, P=%f, X=%f, Y=%f, Z=%f, EC=%d) \n",
    						  v_Calib_Diag_data.EOL_CalibStatus_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front],
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaYaw_f32,
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaRoll_f32,
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaPitch_f32,
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaX_f32,
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaY_f32,
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].deltaZ_f32,
    						  v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].errorCode_e);

      camIDPrev_e = v_Calib_Diag_data.EOL_Status_STM[aZynqM_v_EOLCurrentCam_e - CamID_Front].camID_e;
    }
    #endif
  }
  else
  {
	  /* Do Nothing */
  }

}

/**************************************************************************************************
 * Function Name : set_EOL_DiagMgr_CalibData
 * Description   : Set EOL status to diag
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::Get_SCSM_CalibData(void)
{
  /* DD-ID: {7D8CC853-B418-4a33-A03D-B091192E9131}*/
  uint32 validFeatures;
  uint32 ignoredFeatures;
  uint32 invalidFeatures;

  /* SC data */
  v_Calib_Diag_data.SC_v_IsRequestedByDiag_b  = aZynqM_F_SC_IsRequested_b();
  v_Calib_Diag_data.SCCompletedCurrentCycle   = aZynqM_F_GetSCStatusCurrentCycle();
  v_Calib_Diag_data.SC_StartConditions_STM    = aZynqM_F_SC_GetStartConditionDetails_s();
  v_Calib_Diag_data.SC_ModuleState_STM        = aZynqM_F_ModuleState_SC_STM_GetModuleState_e();

  if ((CamID_None < aZynqM_v_SCCurrentCam_e) && (aZynqM_v_SCCurrentCam_e <= ME_HYDRA3DEFS_D_CAMERACOUNT))
   {
	 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].errorCode_e = aZynqM_F_SC_GetErrorCodeCam_e(aZynqM_v_SCCurrentCam_e);

	 v_Calib_Diag_data.SC_CalibStatus_STM[aZynqM_v_SCCurrentCam_e - CamID_Front] = aZynqM_F_SC_GetResultCam_e(aZynqM_v_SCCurrentCam_e);

	 aZynqM_F_OC_GetFeatures_v(&validFeatures, &ignoredFeatures, &invalidFeatures);
	 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].ValidFeatures_u32 = validFeatures;
	 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].IgnoredFeatures_u32 = ignoredFeatures;
	 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].InvalidFeatures_u32 = invalidFeatures;
#if 0
	 if ( e_OC_CalibrationCompleted == aZynqM_F_OC_GetAlgoState_e() )
	 {
	   if ( e_OC_NoError == aZynqM_F_OC_GetErrorCode_e() )
	   {
         v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaYaw_f32   = OCrxStatus.deltaYaw_f32;
         v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaRoll_f32  = OCrxStatus.deltaRoll_f32;
         v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaPitch_f32 = OCrxStatus.deltaPitch_f32;
	   }
	 }
	 else if ( ( e_OC_Error == aZynqM_F_OC_GetAlgoState_e() ) ||
			   ( e_OC_Terminated == aZynqM_F_OC_GetAlgoState_e() ) )
	 {
	   v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaYaw_f32   = 0.0f;
	   v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaRoll_f32  = 0.0f;
	   v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaPitch_f32 = 0.0f;
	 }
	 else
	 {
	   /* Do Nothing */
	 }
#endif
     v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].camID_e = aZynqM_F_SC_GetCurrentCam_e();

     #if CALSM_DEBUG_PRINTS_ENABLE
     static uint8 v_PrevCamCntr = 0;

     if (v_PrevCamCntr != aZynqM_v_SCCurrentCam_e)
     {
       ME_Debugger_F_Printf_v("CALSM SetDiagMgr TSC: (CS=%d, Y=%f, R=%f, P=%f, EC=%d) \n",
                                 v_Calib_Diag_data.SC_CalibStatus_STM[aZynqM_v_SCCurrentCam_e - CamID_Front],
                                 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaYaw_f32,
                                 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaRoll_f32,
                                 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].deltaPitch_f32,
                                 v_Calib_Diag_data.SC_Status_STM[aZynqM_v_SCCurrentCam_e - CamID_Front].errorCode_e);

       v_PrevCamCntr = aZynqM_v_SCCurrentCam_e;
     }
  #endif
   }
   else
   {
     /* Do Nothing */
   }

}

/**************************************************************************************************
 * Function Name : set_EOL_DiagMgr_CalibData
 * Description   : Set EOL status to diag
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::Get_OCSM_CalibData(void)
{
  /* DD-ID: {CC8E6666-5810-4ebe-9358-854C0AB4DBB6}*/
  v_Calib_Diag_data.OC_ModuleState_STM = aZynqM_F_ModuleState_OC_STM_GetModuleState_e();

  uint32 validFeatures;
  uint32 ignoredFeatures;
  uint32 invalidFeatures;

  if ((CamID_None < aZynqM_v_OCCurrentCam_e) && (aZynqM_v_OCCurrentCam_e <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
	v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].errorCode_e = aZynqM_F_OC_GetErrorCodeCam_e(aZynqM_v_OCCurrentCam_e);

	v_Calib_Diag_data.OC_CalibStatus_STM[aZynqM_v_OCCurrentCam_e - CamID_Front] = aZynqM_F_OC_GetResultCam_e(aZynqM_v_OCCurrentCam_e);

	aZynqM_F_OC_GetFeatures_v(&validFeatures, &ignoredFeatures, &invalidFeatures);
	v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].ValidFeatures_u32 = validFeatures;
	v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].IgnoredFeatures_u32 = ignoredFeatures;
	v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].InvalidFeatures_u32 = invalidFeatures;
#if 0
	if ( e_OC_CalibrationCompleted == aZynqM_F_OC_GetAlgoState_e() )
	{
	  if ( e_OC_NoError == aZynqM_F_OC_GetErrorCode_e() )
	  {
        v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaYaw_f32   = OCrxStatus.deltaYaw_f32;
        v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaRoll_f32  = OCrxStatus.deltaRoll_f32;
        v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaPitch_f32 = OCrxStatus.deltaPitch_f32;
	  }
	}
	else if ( ( e_OC_Error == aZynqM_F_OC_GetAlgoState_e() ) ||
			  ( e_OC_Terminated == aZynqM_F_OC_GetAlgoState_e() ) )
	{
      v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaYaw_f32   = 0.0f;
      v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaRoll_f32  = 0.0f;
      v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaPitch_f32 = 0.0f;
	}
	else
	{
	  /* Do Nothing */
	}
#endif
    v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].camID_e = aZynqM_F_OC_GetCurrentCam_e();

    #if 0
      ME_Debugger_F_Printf_v(" CALSM SetDiagMgr OC: (CS=%d, Y=%f, R=%f, P=%f, EC=%d) \n",
                                v_Calib_Diag_data.CalibStatus_STM[aZynqM_v_OCCurrentCam_e - CamID_Front],
                                v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaYaw_f32,
                                v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaRoll_f32,
                                v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].deltaPitch_f32,
                                v_Calib_Diag_data.OC_Status_STM[aZynqM_v_OCCurrentCam_e - CamID_Front].errorCode_e);
    #endif
  }
  else
  {
    /* Do Nothing */
  }
}

/**************************************************************************************************
 * Function Name : get_screen
 * Description   : Get screen from OVL3D
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::get_HmiScreen(void)
{
  /* DD-ID: {B6E67E91-E14C-4baf-8ABD-537D873CA9E2}*/
  if(FALSE != aZynqM_F_SC_IsRequested_b())
  {
    bool_t  o_receive_status_b_p;

    ScreenRequest_t  v_ScreenRequest_t = dataProvider_ro.getSigMData_po()->getScreenRequest_t(&o_receive_status_b_p);

    /* The overlay bits received from HMI will be passed to CALSM */
    aZynqM_v_TscGetScreen.Tsc_OverlayBits = v_ScreenRequest_t.MbSVS_bf_OverlayBitsReq;
  }
  else
  {
    /* Do nothing */
  }
}
  
/**************************************************************************************************
 * Function Name : set_calib_algo_input
 * Description   : Set screen to OVL3D
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::set_TscScreen(void)
{
  /* DD-ID: {41E5179F-5FF9-4216-8590-C8D0556B3937}*/
  TbSVS_e_SVSCalibSMToHmi_t v_TscScreenReq;

  (void)memset(&v_TscScreenReq, 0x00, sizeof(v_TscScreenReq));

  v_TscScreenReq.IsScRequestedByDiag_b = aZynqM_F_SC_IsRequested_b();
  v_TscScreenReq.IsHmiActive_b = aZynqM_F_SC_IsHmiEnabled_b();

  (void)memcpy(&v_TscScreenReq.CalibScreen.Tsc_OverlayBits, &aZynqM_v_TscSetScreen.Tsc_OverlayBits, sizeof(aZynqM_v_TscSetScreen.Tsc_OverlayBits));

  if((FALSE != aZynqM_F_SC_IsRequested_b()) || (FALSE == aZynqM_F_SC_IsHmiEnabled_b()))
  {
    /* Sending the TSC CALSM overlay bits and calib flag to HMI */
    dataProvider_ro.getSigMData_po()->setTbSVS_e_SVSCalibSMToHmi_v(v_TscScreenReq);
  }
  else
  {
    /* Do Nothing */
  }
}

/**************************************************************************************************
 * Function Name : Get_Calib_FIDs
 * Description   : Get the calibration FID status for four cameras.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::Get_Calib_FIDs(void)
{
  /* DD-ID: {47D633B0-E36C-4281-B299-0263C9858166}*/
  FID_STRUCT_B v_FID_struct_B = dataProvider_ro.getSigMData_po()->getfid_struct();

  m_calsmFIDs.FID_CALSM_FRONT_DISABLED = v_FID_struct_B.m_B_FID_SV360_LIMITED_Mode8;
  m_calsmFIDs.FID_CALSM_LEFT_DISABLED  = v_FID_struct_B.m_B_FID_SV360_LIMITED_Mode9;
  m_calsmFIDs.FID_CALSM_REAR_DISABLED  = v_FID_struct_B.m_B_FID_SV360_LIMITED_Mode7;
  m_calsmFIDs.FID_CALSM_RIGHT_DISABLED = v_FID_struct_B.m_B_FID_SV360_LIMITED_Mode10;

}

/**************************************************************************************************
 * Function Name : Get_FunctionalSettings
 * Description   : Get the functional setting details from NVM
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::Get_FunctionalSettings(void)
{
  /* DD-ID: {3F57B513-FED2-4f45-972A-33859DC26FF8}*/
  bool_t  v_status_b;
  functionalSettingsNVM = dataProvider_ro.getSigMData_po()->getTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t(&v_status_b);

  #if CALSM_DEBUG_PRINTS_ENABLE
    static TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t v_PrevFunctionalSettingsNVM;

    if((functionalSettingsNVM.OC_ApplyResults_u8 != v_PrevFunctionalSettingsNVM.OC_ApplyResults_u8) ||
       (functionalSettingsNVM.OC_Control_u8 != v_PrevFunctionalSettingsNVM.OC_Control_u8) ||
       (functionalSettingsNVM.OC_SpeedLimit_u16 != v_PrevFunctionalSettingsNVM.OC_SpeedLimit_u16) ||
       (functionalSettingsNVM.OC_Weighting_u8 != v_PrevFunctionalSettingsNVM.OC_Weighting_u8))
    {
      ME_Debugger_F_Printf_v("OC_ApplyResults =%d \n",functionalSettingsNVM.OC_ApplyResults_u8);
      ME_Debugger_F_Printf_v("OC_Control =%d \n",functionalSettingsNVM.OC_Control_u8);
      ME_Debugger_F_Printf_v("OC_SpeedLimit =%d \n",functionalSettingsNVM.OC_SpeedLimit_u16);
      ME_Debugger_F_Printf_v("OC_Weighting =%d \n",functionalSettingsNVM.OC_Weighting_u8);

      v_PrevFunctionalSettingsNVM = functionalSettingsNVM;
	}
  #endif
}



/**************************************************************************************************
 * Function Name : Get_EraseCalibration_info
 * Description   : Storing the calibration erase information
 * Input         : DiagMgr Output To SVS CamCalib SM
 * Output        : None
 **************************************************************************************************/
void DataProviderCALSM::Get_EraseCalibration_info(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t DiagData)
{
  /* DD-ID: {79582737-1A6F-4b63-B716-DAEE7C8253D8}*/

  #if CALSM_DEBUG_PRINTS_ENABLE
    ME_Debugger_F_Printf_v("CALSM Inside Get_EraseCalibration_info()  \n");
  #endif

  switch(DiagData.EraseCalibNVMData.EraseCalibType)
  {
    case CalibrationID_EOL:
        #if CALSM_DEBUG_PRINTS_ENABLE
          ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_EOL \n");
        #endif
        EraseBlockInfo.EOLBlock.isCalibResetRoutineEraseRequested = TRUE;

        switch(DiagData.EraseCalibNVMData.EraseCamId)
        {
          case Erase_CalibrationID_front:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_EOL CAM :  Front \n");
              #endif
              EraseBlockInfo.EOLBlock.EraseFront_b = TRUE;
              break;
          case Erase_CalibrationID_left:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_EOL CAM :  Left \n");
              #endif
              EraseBlockInfo.EOLBlock.EraseLeft_b = TRUE;
              break;
          case Erase_CalibrationID_rear:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_EOL CAM :  Rear \n");
              #endif
              EraseBlockInfo.EOLBlock.EraseRear_b = TRUE;
              break;
          case Erase_CalibrationID_right:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_EOL CAM :  Right \n");
              #endif
              EraseBlockInfo.EOLBlock.EraseRight_b = TRUE;
              break;
          case Erase_CalibrationID_all:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_EOL CAM :  All Camera \n");
              #endif
              EraseBlockInfo.EOLBlock.EraseAllCamera_b = TRUE;
              break;
          //default:
        }
    break;

    case CalibrationID_SC:
        #if CALSM_DEBUG_PRINTS_ENABLE
          ME_Debugger_F_Printf_v("CALSM Inside Erase  CalibrationID_SC  \n");
        #endif
        EraseBlockInfo.SCBlock.isCalibResetRoutineEraseRequested = TRUE;

        switch(DiagData.EraseCalibNVMData.EraseCamId)
        {
          case Erase_CalibrationID_front:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_SC CAM :  Front \n");
              #endif
              EraseBlockInfo.SCBlock.EraseFront_b = TRUE;
              break;
          case Erase_CalibrationID_left:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_SC CAM :  left  \n");
              #endif
              EraseBlockInfo.SCBlock.EraseLeft_b = TRUE;
              break;
          case Erase_CalibrationID_rear:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_SC CAM :  Rear \n");
              #endif
              EraseBlockInfo.SCBlock.EraseRear_b = TRUE;
              break;
          case Erase_CalibrationID_right:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_SC CAM :  Right \n");
              #endif
              EraseBlockInfo.SCBlock.EraseRight_b = TRUE;
              break;
          case Erase_CalibrationID_all:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_SC CAM :  All Camera  \n");
              #endif
              EraseBlockInfo.SCBlock.EraseAllCamera_b = TRUE;
              break;
          //default:
        }
    break;

    case CalibrationID_OC:
        #if CALSM_DEBUG_PRINTS_ENABLE
          ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_OC  \n");
        #endif
        EraseBlockInfo.OCBlock.isCalibResetRoutineEraseRequested = TRUE;

        switch(DiagData.EraseCalibNVMData.EraseCamId)
        {
          case Erase_CalibrationID_front:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_OC CAM :  Front \n");
              #endif
              EraseBlockInfo.OCBlock.EraseFront_b = TRUE;
              break;
          case Erase_CalibrationID_left:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_OC CAM :  Left \n");
              #endif
              EraseBlockInfo.OCBlock.EraseLeft_b = TRUE;
              break;
          case Erase_CalibrationID_rear:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_OC CAM :  Rear \n");
              #endif
              EraseBlockInfo.OCBlock.EraseRear_b = TRUE;
              break;
          case Erase_CalibrationID_right:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_OC CAM :  Right \n");
              #endif
              EraseBlockInfo.OCBlock.EraseRight_b = TRUE;
              break;
          case Erase_CalibrationID_all:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_OC CAM :  All Camera \n");
              #endif
              EraseBlockInfo.OCBlock.EraseAllCamera_b = TRUE;
              break;
          //default:
        }
    break;

    case CalibrationID_Current:
        #if CALSM_DEBUG_PRINTS_ENABLE
          ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_Current \n");
        #endif
        EraseBlockInfo.CurrentBlock.isCalibResetRoutineEraseRequested = TRUE;

        switch(DiagData.EraseCalibNVMData.EraseCamId)
        {
          case Erase_CalibrationID_front:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_Current CAM :  Front \n");
              #endif
              EraseBlockInfo.CurrentBlock.EraseFront_b = TRUE;
              break;
          case Erase_CalibrationID_left:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_Current CAM :  Left  \n");
              #endif
              EraseBlockInfo.CurrentBlock.EraseLeft_b = TRUE;
              break;
          case Erase_CalibrationID_rear:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_Current CAM :  Rear \n");
              #endif
              EraseBlockInfo.CurrentBlock.EraseRear_b = TRUE;
              break;
          case Erase_CalibrationID_right:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_Current CAM :  Right \n");
              #endif
              EraseBlockInfo.CurrentBlock.EraseRight_b = TRUE;
              break;
          case Erase_CalibrationID_all:
              #if CALSM_DEBUG_PRINTS_ENABLE
                ME_Debugger_F_Printf_v("CALSM Erase CalibrationID_Current CAM :  All camera \n");
              #endif
              EraseBlockInfo.CurrentBlock.EraseAllCamera_b = TRUE;
              break;
          //default:
        }
    break;
  }

  if (DiagData.EraseCalibNVMData.isCalibNVMEraseRequested == TRUE)
  {
    #if CALSM_DEBUG_PRINTS_ENABLE
      ME_Debugger_F_Printf_v("CALSM  isCalibNVMEraseRequested :  TRUE \n");
    #endif
    EraseBlockInfo.isCalibNVMEraseRequested_b = TRUE;
  }

}

 void DataProviderCALSM::setCALSMRuntime(uint32_t u_CALSMRuntime_u32)
 {
    dataProvider_ro.getCalSmMData_po()->setCALSMRuntime(u_CALSMRuntime_u32);
 }

 void DataProviderCALSM::setCALSMThreadRuntime(uint32_t u_CALSMRuntime_u32)
 {
    dataProvider_ro.getCalSmMData_po()->setCALSMThreadRuntime(u_CALSMRuntime_u32);
 }

 PerformanceStatsEnable_t DataProviderCALSM::get_PerformanceStatsEnable(void)
  {
    return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
  }


} // namespace calsm
