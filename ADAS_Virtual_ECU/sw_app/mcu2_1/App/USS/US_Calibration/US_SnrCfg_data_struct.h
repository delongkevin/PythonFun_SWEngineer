/*
 * US_SnrCfg_data_struct.h
 *
 *  Created on: Mar 11, 2021
 *      Author: e39960
 */

#ifndef SRC_US_CALIBRATION_US_SNRCFG_DATA_STRUCT_H_
#define SRC_US_CALIBRATION_US_SNRCFG_DATA_STRUCT_H_
#include "US_SnrDrv_Global.h"
#include "US_SnrCfg_Global.h"

#define MAX_CALI_ITEMS             (100U)

#define CALI_DATA_START_ADDR       (0x200U)
#define MAX_CALI_DATA_SIZE         (0x100000U) 

#define CALI_DATA_INVAILID         (0xFF10U)
#define CALI_DATA_CONFIG_FAIL      (0xFF11U)
#define CALI_DATA_NOT_CHOSEN       (0xFF12U)
#define BLOCK_VER_LIMIT            (0x100U)

#define CFG_TEMP_POINTS            (3U)
#define MAX_TEMP_CFG_POINTS        (5U)

enum US_E_CAL_VEH_ID
{
	VEH_FISKER  = 0,
	MAX_CAL_DATA_VEH
};


typedef struct US_S_SnrCfg_Cali_Data_s
{
	   uint32_t BlockId;
	   uint32_t Desc;
	   uint16_t ItemID;
	   uint16_t Rev;
	   void*  ItemData;
}US_S_SnrCfg_Cali_Data_t;

typedef struct US_S_SnrCfg_cal_Block_Header_s
{
	   uint32_t CheckSum;
	   uint32_t Length;
	   uint16_t ID;
	   uint16_t Rev;
}US_S_SnrCfg_cal_Block_Header_t;

typedef struct US_S_SnrCfg_cal_Item_Header_s
{
	   uint16_t ItemID;
	   uint16_t Length;
	   uint32_t Descr;
}US_S_SnrCfg_cal_Item_Header_t;

typedef struct US_S_SnrCfg_cal_s
{
#ifdef CALIBRATION_DATA_NVM
	US_S_SnrCfg_cal_Block_Header_t  CalHeadBlockHeader;
    US_S_SnrCfg_cal_Item_Header_t ECU_CalData_Veh_Header;
	uint32_t ECU_CalData_Veh_Offset[1];
#endif
	US_S_SnrCfg_cal_Block_Header_t  ConfigureBlockHeader;
    US_S_SnrCfg_cal_Item_Header_t ECU_Operation_Mode_Header;
	US_S_ECU_Operation_Mode_t ECU_Operation_Cfg;
    US_S_SnrCfg_cal_Item_Header_t ZoneBoundsCfg_Header;
    US_S_ZoneBounds_t Cfg_ZoneBounds[8];
    US_S_SnrCfg_cal_Item_Header_t SectorEdgeCfg_Header;
    US_S_SectorEdge_t Cfg_SectorEdge[9];
    US_S_SnrCfg_cal_Item_Header_t KinematicCfg_Header;
	US_S_KinematicCfg_t Cfg_Kinematic;
    US_S_SnrCfg_cal_Item_Header_t SensorsCfg_Version_Header;
	uint32_t Cfg_Version;
    US_S_SnrCfg_cal_Item_Header_t Sensor_PN_Header;
	uint8_t Sensor_PN[4][14];
    US_S_SnrCfg_cal_Item_Header_t SensorsCfg_Header; 
    US_S_SensorsCfg1_t  SensorsCfg;
    US_S_SnrCfg_cal_Item_Header_t SensorsCfg_Header1; 
    US_S_SensorsCfg1_t  SensorsCfg1;
	US_S_SnrCfg_cal_Block_Header_t TuneBlockHeader;
	US_S_SnrCfg_cal_Item_Header_t  FTC_Cfg_header;
	US_S_FTCfg_t USSSENS_v_Basic_FTC_t;
	US_S_SnrCfg_cal_Item_Header_t  AATG1_Cfg_header;
	US_S_AATGCfg_t USSSENS_v_Basic_AATG1_t;
	US_S_SnrCfg_cal_Item_Header_t  AATG2_Cfg_header;
	US_S_AATGCfg_t USSSENS_v_Basic_AATG2_t;
	US_S_SnrCfg_cal_Item_Header_t  ATG_Cfg_header;
	US_S_ATGCfg_t USSSENS_v_Basic_ATG_t;
	US_S_SnrCfg_cal_Item_Header_t  NFD_Cfg_header;
	US_S_NFDCfg_t USSSENS_v_Basic_NFD_t;
	US_S_SnrCfg_cal_Item_Header_t  SnrComp_Cfg_header;
	US_S_SensorEEFlagVarCTRL_t USSSENS_v_Basic_SnrComp_t;
	US_S_SnrCfg_cal_Item_Header_t  GanaMeasBegin_Cfg_header;
	US_S_GanaMeasBegin_t USSSENS_v_Basic_GanaMeasBegin_t;
	US_S_SnrCfg_cal_Item_Header_t  EDI_Cfg_header;
	US_S_EDICfg_t USSSENS_v_Basic_EDI_t;
    US_S_SnrCfg_cal_Item_Header_t  ProfileCfgB_header;
	US_S_ProfileCfg_t USSSENS_v_ProfileCfgB_t;
	US_S_SnrCfg_cal_Item_Header_t  ProfileCfgC_header;
	US_S_ProfileCfg_t USSSENS_v_ProfileCfgC_t;
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgC_header;
	US_S_StcSeg_t USSSENS_v_ProfC_STC_Base_at[2];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgB_header;
	US_S_StcSeg_t USSSENS_v_ProfB_STC_Base_at[2];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgC_header;
	US_S_StgSeg_t USSSENS_v_ProfC_STG_Base_at[4];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgB_header;
	US_S_StgSeg_t USSSENS_v_ProfB_STG_Base_at[4];

	US_S_SnrCfg_cal_Item_Header_t  TempCompCfg_header;
	US_S_TemperatureCompensation_t TempCompCfg;
	US_S_SnrCfg_cal_Item_Header_t  ProfileCfgA_header;
	US_S_ProfileCfg_t USSSENS_v_ProfileCfgA_t[MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_FrontSide_header;
	US_S_StcSeg_t USSSENS_v_ProfA_FrontSide_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_RearSide_header;
	US_S_StcSeg_t USSSENS_v_ProfA_RearSide_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_FrontInner_header;
	US_S_StcSeg_t USSSENS_v_ProfA_FrontInner_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_RearInner_header;
	US_S_StcSeg_t USSSENS_v_ProfA_RearInner_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_FrontOuter_header;
	US_S_StcSeg_t USSSENS_v_ProfA_FrontOuter_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_RearOuter_header;
	US_S_StcSeg_t USSSENS_v_ProfA_RearOuter_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_A_OUTER_header;
	US_S_StcSeg_t USSSENS_v_ProfA_A_OUTER_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STC_ProfileCfgA_B_OUTER_header;
	US_S_StcSeg_t USSSENS_v_ProfA_B_OUTER_STC_Base_at[2*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_FrontSide_header;
	US_S_StgSeg_t USSSENS_v_ProfA_FrontSide_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_RearSide_header;
	US_S_StgSeg_t USSSENS_v_ProfA_RearSide_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_FrontInner_header;
	US_S_StgSeg_t USSSENS_v_ProfA_FrontInner_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_RearInner_header;
	US_S_StgSeg_t USSSENS_v_ProfA_RearInner_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_FrontOuter_header;
	US_S_StgSeg_t USSSENS_v_ProfA_FrontOuter_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_RearOuter_header;
	US_S_StgSeg_t USSSENS_v_ProfA_RearOuter_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_A_OUTER_header;
	US_S_StgSeg_t USSSENS_v_ProfA_A_OUTER_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Item_Header_t  STG_ProfileCfgA_B_OUTER_header;
	US_S_StgSeg_t USSSENS_v_ProfA_B_OUTER_STG_Base_at[4*MAX_TEMP_CFG_POINTS];
	US_S_SnrCfg_cal_Block_Header_t endCal;
	
}US_S_SnrCfg_cal_t;
extern const US_S_SnrCfg_cal_t  *cal_data[MAX_CAL_DATA_VEH];

#endif /* SRC_US_CALIBRATION_US_SNRCFG_DATA_STRUCT_H_ */
