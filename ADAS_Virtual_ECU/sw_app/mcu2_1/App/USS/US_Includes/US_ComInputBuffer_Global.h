/*
 * US_MgrInputBuffer.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRINPUTBUFFER_H_
#define USSMGR_SRC_US_MGRINPUTBUFFER_H_

#include "US_ME_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"

/*comment out  #define MAX_TEMP_UPDATE_INTERVAL (10000) ms*/

# ifndef RTE_MODE_MEUssMgr_UssMgrMod_aUSSMgr_D_ACTIVE
#  define RTE_MODE_MEUssMgr_UssMgrMod_aUSSMgr_D_ACTIVE (1U)
# endif


# ifndef RTE_MODE_MEUssMgr_UssMgrMod_aUSSMgr_D_DEACTIVATED
#  define RTE_MODE_MEUssMgr_UssMgrMod_aUSSMgr_D_DEACTIVATED (3U)
# endif

/*comment out #define US_D_CTRL_PRNDL_PARK   (1u)   VDM_Prndl_Status_Park */

#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
#include "SignalDef.h"

typedef enum US_E_TempValidityFlag_e
{
    US_TEMPVALID_UNKNOWN = ZERO,
    US_TEMPVALID_VALID,
    US_TEMPVALID_INVALID
}US_E_TempValidityFlag_t;

typedef enum
{
    US_SIGNALVALIDITY_UNKNOWN = ZERO,
    US_SIGNALVALIDITY_VALID,
    US_SIGNALVALIDITY_INVALID
}US_E_GenericSignalValidityFlag_e;

typedef enum
{
    US_PRNDL_UNKNOWN = ZERO,
    US_PRNDL_PARK,
    US_PRNDL_NEUTRAL,
    US_PRNDL_REVERSE,
    US_PRNDL_DRIVE
} US_E_App_Prndl_Status_e;

#else
typedef enum US_E_TempValidityFlag_e
{
    US_TEMPVALID_UNKNOWN = ZERO,
    US_TEMPVALID_INVALID,
    US_TEMPVALID_VALID
}US_E_TempValidityFlag_t;

typedef enum
{
    US_SIGNALVALIDITY_UNKNOWN = ZERO,
    US_SIGNALVALIDITY_INVALID,
    US_SIGNALVALIDITY_VALID
}US_E_GenericSignalValidityFlag_e;

typedef enum
{
    US_PRNDL_UNKNOWN = ZERO,
    US_PRNDL_PARK,
    US_PRNDL_REVERSE,
    US_PRNDL_NEUTRAL,
    US_PRNDL_DRIVE
} US_E_App_Prndl_Status_e;

#endif

typedef enum
{
	US_WHEEL_DIR_FORWARD,
	US_WHEEL_DIR_BACKWARD,
	US_WHEEL_DIR_STANDSTILL,
	US_WHEEL_DIR_NOT_DEFINED
}US_E_WheelDir_e;

typedef struct s_MEUssMgr_NumClusters_s
{
  uint8_t RearNum_u8;
  uint8_t FrontNum_u8;
  uint8_t SideNum_u8;
} S_MEUssMgr_NumClusters_t;

#if 0
typedef struct s_MEUssMgr_SnrClsList_s
{
  pUS_S_SensorClusterList_t RearSnrList_t;
  pUS_S_SensorClusterList_t FrontSnrList_t;
  pUS_S_SensorClusterList_t SideSnrList_t;
} S_MEUssMgr_SnrClsList_t;

typedef struct s_MEUssMgr_CalibData_s
{
  pUS_S_ClusterCalib_t RearCalib_t;
  pUS_S_ClusterCalib_t FrontCalib_t;
  pUS_S_ClusterCalib_t SideCalib_t;
} S_MEUssMgr_CalibData_t;

typedef struct s_MEUssMgr_EEData_s
{
  pUS_S_ClusterCalib_t RearEE_t;
  pUS_S_ClusterCalib_t FrontEE_t;
  pUS_S_ClusterCalib_t SideEE_t;
} S_MEUssMgr_EEData_t;

typedef struct s_MEUssMgr_Temp_s
{
  pUS_S_ClusterTemp_t RearTemp_t;
  pUS_S_ClusterTemp_t FrontTemp_t;
  pUS_S_ClusterTemp_t SideTemp_t;
} S_MEUssMgr_Temp_t;
#endif

typedef struct s_MEUssMgr_InputBuffer_s
{
  S_MEUssMgr_NumClusters_t    NumCluster_t;
  Std_ReturnType              IsPowerOn_u8;
  US_E_GenericSignalValidityFlag_e GearSpeed_ValidityFlag;
  US_E_App_Prndl_Status_e     Veh_Prndl_Gear_Status;
  US_E_GenericSignalValidityFlag_e VehicleSpeed_ValidityFlag;
  float32_t                   Veh_VehicleSpeed_1Kph_F32;
  float32_t                   VehicleHeading_Rad;
  float32_t                   Veh_AmbAirTemp_1Deg_F32;
  US_E_TempValidityFlag_t     Veh_AmbAirTemp_ValidityFlag;
  uint8_t                     OutsideHumidity;
  bool_t                      ReqSnrFeatureFlag;
  bool_t                      ReqSnrCompGain;
  uint8_t                     ReqSnr;
  uint32_t					  ReceivedParkingMode;
  /*comment out UssCom_S_PntDebugCtrl_t     sPntDebugCtrl;*/
  float32_t 			      WSpeedLeftRear;
  float32_t 			      WSpeedRightRear;
  uint8_t 					  WheelPulseRightRear;
  uint8_t 					  WheelPulseLeft_Rear;
  float32_t					  SASStatusAngleSafe;
  US_E_WheelDir_e			  WheelDirRightRear;
  US_E_WheelDir_e			  WheelDirLeftRear;
  bool_t                      ReCfgAllowFlag;

} UssCom_S_InputSignals_t;

extern uint8_t MEUssMgr_v_AirHumiOutsd;
extern float32_t MEUssMgr_v_AirTempOutsd;
extern UssCom_S_InputSignals_t UssCom_v_InputBuffer;


/*APIs to fill out the Input data received from the PAM Application*/
void UssCom_CopyAmbientAirTemperatureInputBuffer(float tempValue);
void UssCom_CopyAmbientAirTempValidtyFlagInputBuffer(US_E_TempValidityFlag_t tempValid);
void UssCom_CopyVehGearValidityFlagInputBuffer(US_E_GenericSignalValidityFlag_e validflag);
void UssCom_CopyVehSpeedValidity(US_E_GenericSignalValidityFlag_e tempValue);
void UssCom_CopyVehSpeedInputBuffer(float tempValue);
void UssCom_CopyVehPrndlInputBuffer(US_E_App_Prndl_Status_e tempValue);
void UssCom_RecvEnvironmentStatusFromPA(void);
void UssCom_CopyReceivedParkingMode(uint32_t ReceivedParkingMode);
void UssCom_CopyReCfgFlagBuffer(bool_t recfgflag);
float32_t UssCom_F_GetWSpeedRightRear(void);
float32_t UssCom_F_GetWSpeedLeftRear(void);
uint8_t UssCom_F_GetWheelPulseRightRear(void);
uint8_t UssCom_F_GetWheelPulseLeft_Rear(void);
sint16_t UssCom_F_GetSASStatusAngleSafe(void);
bool_t UssCom_F_GetReCfgAllowFlag(void);

/*APIs to get the Input Values from the customer*/
float UssCom_F_GetAmbientTemp(void);
US_E_TempValidityFlag_t UssCom_F_GetAmbientTempValidity(void);
US_E_GenericSignalValidityFlag_e UssCom_F_GetGearSpeedValidity(void);
float UssCom_F_GetVehSpeed(void);
US_E_App_Prndl_Status_e UssCom_F_GetVehPrndl(void);
uint16_t UssCtrl_Get_Temperature_Index(void);
uint8 UssCom_F_GetParkingMode(void);
void US_Com_GetKinematicData(IKinematicData_t *pKinematicData);

#endif /* USSMGR_SRC_US_MGRINPUTBUFFER_H_ */
