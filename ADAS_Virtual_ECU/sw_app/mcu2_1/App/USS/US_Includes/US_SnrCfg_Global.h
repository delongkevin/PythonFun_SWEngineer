/*
 * US_SnrCfg_Global.h
 *
 *  Created on: Apr 6, 2021
 *      Author: e39960
 */

#ifndef SRC_US_INCLUDES_US_SNRCFG_GLOBAL_H_
#define SRC_US_INCLUDES_US_SNRCFG_GLOBAL_H_

#include "US_Data_Typedefs_Global.h"
#include "US_SysMgr_Global.h"


#define CALIBRATION_DATA_NVM
//#undef CALIBRATION_DATA_NVM

#define US_PSM_SENSOR_TYPE         (0x10000U)   //bit16 17: Sensor type PDC: 0 ,PSM :1, 2,3: reserved
#define US_PDC_SENSOR_TYPE         (0x00000U)

/*position bit masks*/
#define US_ALL_POS                 (0x0000U)
#define US_FRONT_POS               (0x0010U)
#define US_REAR_POS                (0x0020U)
#define US_INNER_POS               (0x0040U)
#define US_OUTER_POS               (0x0080U)
#define US_LEFT_POS                (0x0100U)
#define US_RIGHT_POS               (0x0200U)
#define US_SIDE_POS                (0x0400U)
#define US_A_POS                   (0x0800U)
#define US_B_POS                   (0x1000U)


#define CAL_HEAD_CFG_ID                                    (0x80U)
#define SENSOR_TYPE_PN_CFG_ID                              (5U)
#define SENSOR_MAP_CFG_ID                                  (1U)
#define CALIBRATION_VER_ID                                 (0x55aaU)
#define ECU_OPERATION_MODE_ID                              (3U)
#define TEMPCOMP_CFG_ID                                    (4U)
#define SENSOR_OFFSET_CFG_ID                               (6U)
#define KINEMATIC_ID                                       (0x101U)
#define SECTOREDGECFG_ID                                   (0x102U)
#define ZONEBOUNDCFG_ID                                    (0x103U)
#define PROFILE_CFG_ID                                     SETUP_SENSOR_PROFILE
#define FTC_CFG_ID                                         SETUP_SENSOR_FTC
#define STC_CFG_ID                                         SETUP_SENSOR_STC
#define STG_CFG_ID                                         SETUP_SENSOR_STG
#define GANAMEASBEGIN_CFG_ID                               SETUP_SENSOR_GANA_MEAS_BEGIN
#define ATG_CFG_ID                                         SETUP_SENSOR_ATG
#define AATG1_CFG_ID                                       SETUP_SENSOR_AATG1
#define AATG2_CFG_ID                                       SETUP_SENSOR_AATG2
#define EDI_CFG_ID                                         SETUP_SENSOR_EDI_CHANNEL
#define SENSORCOMP_CFG_ID                                  SETUP_SENSOR_EEFLAG_VARCTRL
#define NFD_CFG_ID                                         SETUP_SENSOR_NFD

#define MAX_TEMP_POINTS                                    (20U)

enum US_E_CFG_BLOCK_ID
{
	UNUSED_BLOCK_ID  = 0,
	BLOCK_CONFIGURE_ID,
	BLOCK_TUNE_ID,
	BLOCK_HEAD_ID,
	MAX_BLOCK_ID
};

#define US_SNR_TUNE_IN_ID  0x10
#define US_SNR_TUNE_ENTER_IN_ID  0x50
#define US_SNR_TUNE_EXIT_IN_ID  0x90
#define US_SNR_TUNE_OUT_ID  0x20
#define US_SNR_TUNE_ENTER_OUT_ID  0x60
#define US_SNR_TUNE_EXIT_OUT_ID  0xA0
#define US_EMC_CLEAR_FLAG 0x11

extern uint16_t uUsed_Cal_Data_Set;

#if(QAC_WARNING_FIX == ME_FALSE)
extern uint32_t US_SnrCfg_F_Get_SnrLoc(uint32_t Snr_Index);
#endif
extern uint32_t US_SnrCfg_F_Get_CfgSnrMap(uint16_t position);
extern uint32_t US_SnrCfg_F_Get_InstSnrMap(uint16_t position);
extern uint16_t US_SnrCfg_Get_SnrFWVer(void);
extern uint8_t US_SnrCfg_Get_Sensor_opmode(void);
extern void US_SnrCfg_Calibration_Process(uint8_t *cmdbuf);
#if(QAC_WARNING_FIX == ME_FALSE)
extern uint32_t US_SnrCfg_F_Get_uSnrID(uint8_t uSnrIdx);
#endif
extern uint32_t * US_SnrCfg_F_Get_uSnrIDList(void);
extern uint32_t US_SnrCfg_F_Get_CaliVer(void);
#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
extern uint16_t US_SnrCfg_Get_Variant(void);
#endif
extern void US_SnrCfg_F_Init_Snr(void);
extern uint32_t US_SnrCfg_F_Init(void);
extern void US_SnrCfg_Calib_F_Init(void);
extern uint8_t US_SnrCfg_F_Get_nSensor(uint8_t chn,uint8_t *Index,uint8_t isActual);
extern uint8_t US_SnrCfg_Get_OperationMode(void);
#if(QAC_WARNING_FIX == ME_FALSE)
extern uint16_t US_SnrCfg_Get_Platform(void);
extern uint8_t US_SnrCfg_Get_gNumSensorsCfg(void);
#endif
extern void US_SnrCfg_F_Cali_task(void);
extern uint16_t US_SnrCfg_F_Cali_RcvCmd(uint8_t *cmdbuf,uint16_t len,uint8_t from);
extern uint8_t US_SnrCfg_Get_CanOutputMode(void);
extern uint16_t US_SnrCfg_F_Update_ProfileA(sint16_t Temp);
extern void US_SnrCfg_F_ReInit_SnrCfg(uint16_t Temperature_table_index,uint8_t bTemp);
extern US_S_TemperatureCompensation_t* GetTemperatureCfg(void);
#if(QAC_WARNING_FIX == ME_FALSE)
extern uint64_t US_SnrCfg_F_Get_uNewSnrID(uint8_t uSnrIdx);
#endif
extern void* US_SnrCfg_F_Get_STGCfg(uint32_t Type);
extern uint64_t * US_SnrCfg_F_Get_uNewSnrIDList(void);
extern bool_t US_SnrCfg_F_bPopulateSnrSensitivity(void);
extern void US_SnrCfg_F_ClrPopulateSnrSensitivityFlag(void);
extern US_S_SensorsCfg_t* US_SnrCfg_F_Get_SnrCfg(void);
extern UssMgr_E_NoiseReaction_t US_SnrCfg_Get_NoiseReaction(void);
extern uint8_t* US_SnrCfg_F_Get_SnrPN(void);
extern void* US_SnrCfg_Get_SectorEdgeCfg(uint16_t* len);
extern void* US_SnrCfg_Get_ZoneBoundsCfg(uint16_t* len);
extern void* US_SnrCfg_Get_KinematicCfg(uint16_t* len);
extern uint8_t * US_SnrCfg_GetDataAddr(void);
extern void US_SnrCfg_Set_gNumSensorsCfg(uint8_t NumofSensor,uint16_t Variant,uint16_t offset_index);
extern void* US_SnrCfg_F_Get_CaliItemData(uint16_t* Data_Len,uint32_t BlockID,uint32_t Type,uint16_t ItemID);
extern uint16_t* US_SnrCfg_Get_AllReset_reason(void);
extern uint8_t* US_SnrCfg_Get_AllSensors_opmode(void);
extern uint8_t *US_SnrCfg_Get_nSensor(void);
extern uint16_t* US_SnrCfg_Get_AllSnrFWVer(void);
uint64_t* US_SnrCfg_Get_AllNewSensorID(void);
uint32_t* US_SnrCfg_Get_AllSensorID(void);
uint16_t US_SnrCfg_F_AutoAddressCheck(uint16_t *RcvData);
uint8_t* US_SnrCfg_F_Cali_GetBuffer(void);
const uint8_t *US_SnrCfg_SnrCalAdjust(uint16_t TempIndex,uint32_t Type,uint16_t ItemID, uint32_t UserInfo);
uint32_t US_SnrCfg_F_Get_SnrBusMap(uint16_t position);
void US_SnrCfg_SetOpModeMask(uint32_t OpModeMask);

#endif /* SRC_US_INCLUDES_US_SNRCFG_GLOBAL_H_ */
