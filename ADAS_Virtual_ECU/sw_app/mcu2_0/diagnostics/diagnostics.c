/** @file diagnostics.c
 *  @brief diagnostics data
 *
 *  diagnostics data
 *
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */
/*==================[inclusions]============================================*/


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "diagnostics.h"
#include "safety.h"
#include <utils/iss/include/app_iss.h>
#include <utils/console_io/include/app_log.h>
#include "PlatformDataTypes.h"

#include "ProxiMgrIpcDataTypes.h"
#include "VoltageCurrent_data.h"
#include "ME_CalibSVS.h"
#include "iss_sensors.h"
#include <ti/csl/csl_gpio.h>


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define IMAGER_JUNCTION_TEMP_FLT_THRESHOLD (125.0f)
#define CAMERA_FAULT_DEBOUNCE_COUNT_ENABLE
#define CAMERA_STG_FAULT_MIN_CURRENT (212u)
#define CAMERA_STB_FAULT_MAX_CURRENT (15u)
#define CAMERA_POWER_EN (1u)

#if defined CAMERA_FAULT_DEBOUNCE_COUNT_ENABLE
#define DEBOUNCE_COUNT (70u)
#endif
/* Test application stack size */

/*< Task Priority Levels */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/*static uint8_t diag_read_dms_deser_reg(uint32_t reg);*/
extern void getCamCurrVoltData(uint32 chId,CAM_Curr_Volt_Monitor_t *CAM_CurrVoltData_Arg);
extern bool_t SigMgr_Data_ME_SetCameraErrorData_t_Put(ME_SetCameraErrorData_t *data);
extern void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data);
extern bool_t SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(Cam_and_Ser_EN_Status_t *data);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

Cam_and_Ser_EN_Status_t Cam_Ser_EN_Stat;
Cam_and_Ser_EN_Status_t Prev_Cam_Ser_EN_Stat;

static uint8_t CamPwrEnSts[4] = {0, 0, 0, 0};

void send_cameraErrorIPCData(void);

enum ErrorMapDict
{
  CAM_FAIL_STG,
  CAM_FAIL_STB,
  CAM_I2C_BACK_CH_ERR,
  LOCK_LOST_ERR,
  CSI_RX_ERR,
  CSI_TX_ERR,
  FRAME_CNTR_FLT,
  MAX_SVS_ERRMGR_FLAG,
};

typedef enum Sensor_e
{  
  SensorId1=0u, // Left Camera
  SensorId2, // Right Camera
  SensorId3, // Front Camera
  SensorId4, // Rear Camera  
  SensorMax
} Sensor_t;

/*
Coax to Cameras
CON4 : Quad-Fakra : AMS29A-40MZ25-B
Following is the pin out View looking into connector
See Req:14162687
  [1] [4]
  [2] [3]
CON4_ID | CAMERA | SCHEMATIC | CH_ID
  1     |   Rt   | CAM2_LVDS |   1
  2     |   Lt   | CAM1_LVDS |   0
  3     |   Rr   | CAM4_LVDS |   3
  4     |   Fr   | CAM3_LVDS |   2
*/

ldef_ErrorMgr_enErrorNo FiskerSVSCamErrorMap[MAX_SVS_CAM][MAX_SVS_ERRMGR_FLAG] =
{
    {
        ldef_ErrorMgr_Error_LeftCamFailure_STG,
        ldef_ErrorMgr_Error_LeftCamFailure_STB,
        ldef_ErrorMgr_Error_Left_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_DS90UB962_RX1_LOCK_STS,
        ldef_ErrorMgr_Error_DS90UB962_RX1_CSI_RX_ERR,
        ldef_ErrorMgr_Error_DS90UB962_CSI_TX0_DETECT_B23C6,
        ldef_ErrorMgr_Error_SVC_Left_Frame_Cntr_Fault
    },
    {
        ldef_ErrorMgr_Error_RightCamFailure_STG,
        ldef_ErrorMgr_Error_RightCamFailure_STB,
        ldef_ErrorMgr_Error_Right_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_DS90UB962_RX0_LOCK_STS,
        ldef_ErrorMgr_Error_DS90UB962_RX0_CSI_RX_ERR,
        ldef_ErrorMgr_Error_DS90UB962_CSI_TX0_DETECT_B23C7,
        ldef_ErrorMgr_Error_SVC_Right_Frame_Cntr_Fault
    },
    {
        ldef_ErrorMgr_Error_FrontCamFailure_STG,
        ldef_ErrorMgr_Error_FrontCamFailure_STB,
        ldef_ErrorMgr_Error_Front_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_DS90UB962_RX3_LOCK_STS,
        ldef_ErrorMgr_Error_DS90UB962_RX3_CSI_RX_ERR,
        ldef_ErrorMgr_Error_DS90UB962_CSI_TX0_DETECT_B23C5,
        ldef_ErrorMgr_Error_SVC_Front_Frame_Cntr_Fault
    },
    {
        ldef_ErrorMgr_Error_RearCamFailure_STG,
        ldef_ErrorMgr_Error_RearCamFailure_STB,
        ldef_ErrorMgr_Error_Rear_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_DS90UB962_RX2_LOCK_STS,
        ldef_ErrorMgr_Error_DS90UB962_RX2_CSI_RX_ERR,
        ldef_ErrorMgr_Error_DS90UB962_CSI_TX0_DETECT_B217A,
        ldef_ErrorMgr_Error_SVC_Rear_Frame_Cntr_Fault
    }                    
};
/*========================================================================== */

/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */
/*uint8_t dms_deser_locksts;
uint8_t dms_deser_locksts_chg;*/

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*static uint8_t diag_read_dms_deser_reg(uint32_t reg)
{
    uint8_t reg_val;
    if (appReadDMSDeserPortReg(CAMPORT_DMS, reg, &reg_val))
    {
        reg_val = 0x0;
    }
    return reg_val;
}*/

void send_cameraErrorIPCData()
{
  /* DD-ID: {D4F8BA86-9579-46cf-9CB1-EA682F2BF6C0}*/

  uint8_t chId;

  ME_SetCameraErrorData_t ipcData;
  memset(&ipcData, 0, sizeof(ME_SetCameraErrorData_t));
  for (chId = 0u; chId < 4u; chId++)
  {
    uint8_t streamStatus = getStreamStatus(chId);
    uint8_t lockStatus = (getPortSts1Reg(chId) & (1u << 0u));
    ;

    ipcData.CameraErrorData[chId].EepromCrcError_b = 0;
    ipcData.CameraErrorData[chId].CamDataError_b = 0;
    ipcData.CameraErrorData[chId].CamOperationError_b = (streamStatus & (1 << chId)) ? (0) : (1);
    ipcData.CameraErrorData[chId].DESError_b = 0;
    ipcData.CameraErrorData[chId].I2CError_b = 0;
    ipcData.CameraErrorData[chId].RunningStatus_b = (streamStatus & (1 << chId)) ? (1) : (0);
    ipcData.CameraErrorData[chId].PowerStatus_b = (lockStatus == 0x1) ? (1) : (0);
    ipcData.CameraErrorData[chId].Tested_b = 1;
  }

  SigMgr_Data_ME_SetCameraErrorData_t_Put(&ipcData);
}

void Diagnostics_Run()
{
  /* DD-ID: {BF1E4F02-79CB-469b-AC2B-BB49CA497856}*/
  // uint8_t AdditionalData[16]; - TODO : Should be implemented to give data on type of fault in each DTC
  uint8_t LineCntChgSet;
  uint8_t NoFpd3ClkDet;
  uint8_t FreqStable;
  uint8_t CsiRxErrSet;
  uint8_t PktBufErrDet;
  uint8_t Fpd3EncodeErrSet;
  uint8_t LineLengthUnstable;
  static uint8_t frozenStateCounter = 0;
  CAM_Curr_Volt_Monitor_t CamCurrVoltData;
  uint32_t chId;
  uint32_t frameCounter[4] = {0, 0, 0, 0};
  static uint32_t prevframeCounter[4] = {0, 0, 0, 0};
  static uint16_t Camera_Current_Arr[4] = {0,0,0,0};
  ME_ProxiToMCU2_0_Def_t CameraConfig = {0};
  static uint8_t debounce_count = 0; //Adding delay for reporting camera faults.

  SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(&CameraConfig);
  if(TRUE == CameraConfig.PRX_SurroundViewCamera_b) /* Requirement ID:18768256 Four camera configuration */
  {
    chId = SensorId1;
  }
  else /* Requirement ID:18642819 Single Camera configuration*/
  {
    chId = SensorId4; /* Rear Camera*/
  }

#if defined CAMERA_FAULT_DEBOUNCE_COUNT_ENABLE
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
  if(debounce_count < DEBOUNCE_COUNT)
  /* VCAST Jenkins requirement - do not modify */
  /* VCAST Jenkins requirement - do not modify */
  {
    debounce_count++;
  }
  else
  {
    //Do Nothing
  }
#endif 

  Get_Cam_Power_EN_Stat();

  for (; chId < 4; chId++) 
  {    
    (void)getCamCurrVoltData(chId, &CamCurrVoltData);
  
    if (CamCurrVoltData.FreshnessCounter == 0){ 
    //appLogPrintf("debounce_count:%u\n",debounce_count);  
    break;
    }

    /* Save the current information per channel and send it over IPC to mcu1_0 for recording in FD46 */
    Camera_Current_Arr[chId] = CamCurrVoltData.CAM_CS_A;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ((CamPwrEnSts[chId] == CAMERA_POWER_EN) && (CAM_RESET_NOT_SCHEDULED == camera_is_set_for_action(chId)) && (CamCurrVoltData.CAM_CS_A >= CAMERA_STG_FAULT_MIN_CURRENT))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
#if defined CAMERA_FAULT_DEBOUNCE_COUNT_ENABLE
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if(debounce_count == DEBOUNCE_COUNT)
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
#endif
      {
        appLogPrintf("\nq-CAM[%u]:STGfault:sts:0x%u;CamCurr:%u,dc:%u,FC:%u\n", chId, CamPwrEnSts[chId],CamCurrVoltData.CAM_CS_A,debounce_count,CamCurrVoltData.FreshnessCounter);
        (void)ErrorMgrSatellite_ReportErrorStatus(FiskerSVSCamErrorMap[chId][CAM_FAIL_STG], ldef_ErrorMgr_ErrorActive, NULL);
      }
    }
    else
    {
      (void)ErrorMgrSatellite_ReportErrorStatus(FiskerSVSCamErrorMap[chId][CAM_FAIL_STG], ldef_ErrorMgr_ErrorInactive, NULL);
    }
    #if defined(VCAST)
    static bool camera_set_action_result = 0;
    camera_set_action_result = camera_is_set_for_action(chId);
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ((CamPwrEnSts[chId] == CAMERA_POWER_EN) && (CAM_RESET_NOT_SCHEDULED == camera_set_action_result) && (CamCurrVoltData.CAM_CS_A <= CAMERA_STB_FAULT_MAX_CURRENT))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    #else
    if ((CamPwrEnSts[chId] == CAMERA_POWER_EN) && (CAM_RESET_NOT_SCHEDULED == camera_is_set_for_action(chId)) && (CamCurrVoltData.CAM_CS_A <= CAMERA_STB_FAULT_MAX_CURRENT))
    #endif
    {
#if defined CAMERA_FAULT_DEBOUNCE_COUNT_ENABLE
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if(debounce_count == DEBOUNCE_COUNT)
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
#endif 
      {
        appLogPrintf("\nq-CAM[%u]:STBfault:sts:0x%u;CamCurr:%u,dc:%u,FC:%u\n", chId, CamPwrEnSts[chId],CamCurrVoltData.CAM_CS_A, debounce_count,CamCurrVoltData.FreshnessCounter);
        (void)ErrorMgrSatellite_ReportErrorStatus(FiskerSVSCamErrorMap[chId][CAM_FAIL_STB], ldef_ErrorMgr_ErrorActive, NULL);
      }
    }
    else
    {
      (void)ErrorMgrSatellite_ReportErrorStatus(FiskerSVSCamErrorMap[chId][CAM_FAIL_STB], ldef_ErrorMgr_ErrorInactive, NULL);
    }

  }

  // send_cameraErrorIPCData(); /* TODO commented code for dev later */
}

void Get_Cam_Power_EN_Stat(void)
{
  /* DD-ID: {70AF4FDB-622A-43b5-B0CE-D4236771D30D}*/
    
        appGetI2cExpPinVal(0, 4u, &Cam_Ser_EN_Stat.Cam1_en_stat);//CAM1 power EN status - Pin IO1_4
        appGetI2cExpPinVal(0, 5u, &Cam_Ser_EN_Stat.Cam2_en_stat);//CAM2 power EN status - Pin IO1_5
        appGetI2cExpPinVal(0, 6u, &Cam_Ser_EN_Stat.Cam3_en_stat);//CAM3 power EN status - Pin IO1_6
        appGetI2cExpPinVal(0, 7u, &Cam_Ser_EN_Stat.Cam4_en_stat);//CAM4 power EN status - Pin IO1_7
        appGetI2cExpPinVal(1, 0u, &Cam_Ser_EN_Stat.SER_en_stat);//SER power EN status - Pin IO2_0

        CamPwrEnSts[0] = Cam_Ser_EN_Stat.Cam1_en_stat;
        CamPwrEnSts[1] = Cam_Ser_EN_Stat.Cam2_en_stat;
        CamPwrEnSts[2] = Cam_Ser_EN_Stat.Cam3_en_stat;
        CamPwrEnSts[3] = Cam_Ser_EN_Stat.Cam4_en_stat;

        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if(Prev_Cam_Ser_EN_Stat.Cam1_en_stat != Cam_Ser_EN_Stat.Cam1_en_stat || Prev_Cam_Ser_EN_Stat.Cam2_en_stat != Cam_Ser_EN_Stat.Cam2_en_stat || 
           Prev_Cam_Ser_EN_Stat.Cam3_en_stat != Cam_Ser_EN_Stat.Cam3_en_stat || Prev_Cam_Ser_EN_Stat.Cam4_en_stat != Cam_Ser_EN_Stat.Cam4_en_stat ||
           Prev_Cam_Ser_EN_Stat.SER_en_stat != Cam_Ser_EN_Stat.SER_en_stat)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
           {
              SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put(&Cam_Ser_EN_Stat);
              Prev_Cam_Ser_EN_Stat.Cam1_en_stat = Cam_Ser_EN_Stat.Cam1_en_stat;
              Prev_Cam_Ser_EN_Stat.Cam2_en_stat = Cam_Ser_EN_Stat.Cam2_en_stat;
              Prev_Cam_Ser_EN_Stat.Cam3_en_stat = Cam_Ser_EN_Stat.Cam3_en_stat;
              Prev_Cam_Ser_EN_Stat.Cam4_en_stat = Cam_Ser_EN_Stat.Cam4_en_stat;
              Prev_Cam_Ser_EN_Stat.SER_en_stat  = Cam_Ser_EN_Stat.SER_en_stat;
           }
           else
           {
            //Do Nothing
           }

}
