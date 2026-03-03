/*
 * US_SnrCfg_Data.c
 *
 *  Created on: Mar 10, 2021
 *      Author: e39960
 */

#ifndef SRC_US_CALIBRATION_US_SNRCFG_DATA_C_
#define SRC_US_CALIBRATION_US_SNRCFG_DATA_C_

#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrCfg_data_struct.h"

#ifndef CALIBRATION_DATA_NVM 

/*
const US_S_SnrCfg_cal_Block_Header_t __attribute__ ((section (".ro_calibration "))) ConfigureBlockHeader =
  {
	.CheckSum = 0x0,
	.Length   = sizeof(US_S_SensorsCfg_t) + 2 * sizeof(uint16_t),
	.ID       = BLOCK_CONFIGURE_ID,
	.Rev      = 0x100
   };
*/

const US_S_SnrCfg_cal_t __attribute__ ((aligned (4))) cal_data_CVADAS =
{
#ifdef CALIBRATION_DATA_NVM
		//Cal HEAD
   .CalHeadBlockHeader =
   {
	.CheckSum = 0x163e7680,         //0xf85f81e3,       // 0xf86dc847,          //0xf871c84b,                     //0xf871d54b,
	.Length   = 2*sizeof(uint16_t) + sizeof(US_S_SnrCfg_cal_Item_Header_t) + 1*sizeof(uint32_t),
	.ID       = BLOCK_HEAD_ID,
	.Rev      = 0x100,
   },
   .ECU_CalData_Veh_Header =
   {
	.ItemID  = CAL_HEAD_CFG_ID,
	.Length  = sizeof(uint32_t) + sizeof(uint32_t),
	.Descr   = 0,
   },
   .ECU_CalData_Veh_Offset = 
    {
     	sizeof(US_S_SnrCfg_cal_Block_Header_t) + sizeof(US_S_SnrCfg_cal_Item_Header_t) + sizeof(uint32_t),
    },
#endif
  // configure
   .ConfigureBlockHeader =
   {
	.CheckSum = 0x163e7680,         //0xf85f81e3,       // 0xf86dc847,          //0xf871c84b,                     //0xf871d54b,
	.Length   = 2*sizeof(uint16_t) + EIGHT * sizeof(US_S_SnrCfg_cal_Item_Header_t) + sizeof(uint32_t) + TWO * sizeof(US_S_SensorsCfg1_t) + sizeof(US_S_ECU_Operation_Mode_t) +4*14 \
	           + 8 * sizeof(US_S_ZoneBounds_t) + 9 * sizeof(US_S_SectorEdge_t) + sizeof(US_S_KinematicCfg_t),
	.ID       = BLOCK_CONFIGURE_ID,
	.Rev      = 0x104,
   },
   .ECU_Operation_Mode_Header =
   {
	.ItemID  = ECU_OPERATION_MODE_ID,
	.Length  = sizeof(uint32_t) + sizeof(uint32_t),
	.Descr   = 0,
   },
   .ECU_Operation_Cfg = 
    {
     	.ECU_Operation_Mode = 3,
    },
	.ZoneBoundsCfg_Header =
    {
	.ItemID  = ZONEBOUNDCFG_ID,
	.Length  = 8 * sizeof(US_S_ZoneBounds_t) + sizeof(uint32_t),
	.Descr   = 0,
    },
   .Cfg_ZoneBounds =
    {
		{.uNumZones = FOUR , .fZoneUpperBound = {25.0f, 50.0f, 75.0f, 150.0f, 0.0f, 0.0f, 0.0f, 0.0f }},
		{.uNumZones = FOUR , .fZoneUpperBound = {25.0f, 50.0f, 75.0f, 150.0f, 0.0f, 0.0f, 0.0f, 0.0f }},
		{.uNumZones = FOUR , .fZoneUpperBound = {25.0f, 50.0f, 75.0f, 150.0f, 0.0f, 0.0f, 0.0f, 0.0f }},

		{.uNumZones = ZERO , .fZoneUpperBound = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }},
		{.uNumZones = ZERO , .fZoneUpperBound = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }},

	    {.uNumZones = FOUR , .fZoneUpperBound = {25.0f, 50.0f, 75.0f, 150.0f, 0.0f, 0.0f, 0.0f, 0.0f }},
		{.uNumZones = FOUR , .fZoneUpperBound = {25.0f, 50.0f, 75.0f, 150.0f, 0.0f, 0.0f, 0.0f, 0.0f }},
		{.uNumZones = FOUR , .fZoneUpperBound = {25.0f, 50.0f, 75.0f, 150.0f, 0.0f, 0.0f, 0.0f, 0.0f }},
	 },
    .SectorEdgeCfg_Header =
    {
			.ItemID  = SECTOREDGECFG_ID,
			.Length  = 9 * sizeof(US_S_SectorEdge_t) + sizeof(uint32_t),
			.Descr   = 0,
    },
    .Cfg_SectorEdge =
	{
            {.iX =  3790, .iY =    0, .uDepthL = 150,   .uDepthR = 150,  .fAngle =   0.0},  
            {.iX =  3700, .iY =  467, .uDepthL = 150,   .uDepthR = 150,  .fAngle =  30.0},  
            {.iX =  3440, .iY =  770, .uDepthL = 150,   .uDepthR = 150,  .fAngle =  60.0},  
            {.iX =  3273, .iY =  830, .uDepthL = 150,   .uDepthR = 150,  .fAngle =  90.0},  
            {.iX =  1301, .iY =  906, .uDepthL = 150,   .uDepthR = 150,  .fAngle =  90.0},  
            {.iX =  -500, .iY =  790, .uDepthL = 150,   .uDepthR = 150,  .fAngle =  90.0},  
            {.iX =  -610, .iY =  760, .uDepthL = 150,   .uDepthR = 150,  .fAngle = 120.0},  
            {.iX =  -800, .iY =  545, .uDepthL = 150,   .uDepthR = 150,  .fAngle = 150.0},  
            {.iX =  -906, .iY =    0, .uDepthL = 150,   .uDepthR = 150,  .fAngle = 180.0}   
	},
	.KinematicCfg_Header =
	{
				.ItemID  = KINEMATIC_ID,
				.Length  = sizeof(US_S_KinematicCfg_t) + sizeof(uint32_t),
				.Descr   = 0,
	},
	.Cfg_Kinematic =
	{			  
       .whl_Circum=2.370F,
       .whl_Base=4.75F,
       .max_Tick=255.0F,
       .num_Pulses=96.0F,
	   .TestBasedLookupTable_tableData = {0, 6.34, 12.65, 19.15, 25.9, 32.95, 40.45},
	   .TestBasedLookupTable_bp01Data  = { 0, 110, 221, 331, 442, 552, 663},
	 },
 	.SensorsCfg_Version_Header =
     {
  	.ItemID  = CALIBRATION_VER_ID,
  	.Length  = sizeof(US_S_ECU_Operation_Mode_t) + sizeof(uint32_t),
  	.Descr   = 0,
     },
	.Cfg_Version = 0xe2209271,

    .Sensor_PN_Header =
	{
  	.ItemID  = SENSOR_TYPE_PN_CFG_ID,
  	.Length  = 4*14 + sizeof(uint32_t),
  	.Descr   = 0,
	},
    .Sensor_PN[0] = {13,'F','M','2','9','8','0','1','2','0','0','0','2','A'},   //PDC
    .Sensor_PN[1] = {13,'F','M','2','9','8','0','1','2','0','0','2','0','A'},   //PSM
   .SensorsCfg_Header =
   {
	.ItemID  = SENSOR_MAP_CFG_ID,
	.Length  = sizeof(US_S_SensorsCfg1_t) + sizeof(uint32_t),
	.Descr   = 12,
   },
   .SensorsCfg =
   {
	.PlatformID = 0x800,
    .nBusCfg  = 2,            // 4 bus
	.Max_nSnr_ON_SINGLE_BUS    = 6,   //Max 6 sensors in single bus
	.SnrMap                    = 0x00fff, //0xc3fff
    .Snr_Positions =
     //  FSR     FOR   FIR   FIL   FOL    FSL(close ECU)        RSL   ROL  RIL  RIR   ROR    RSR(close ECU)
	 {0x10610,0x290,0x250,0x150,0x190,0x10510,       0x520,0x1a0,0x160,0x260,0x2a0,0x620,
	                              0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
	.SnrCoordinate =
	{
        /* Front Sensors */
        {.fX = 436.6f,  .fY = -92.17f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 285.0f}, // FSR
        {.fX = 448.66f, .fY = -76.72f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 326.07f}, // FOR
        {.fX = 462.38f, .fY = -32.36f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 354.04f}, // FIR
        {.fX = 462.38f, .fY = 32.36f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg =  5.96f}, // FIL
        {.fX = 448.66f, .fY = 76.72f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg =  33.93f}, // FOL
        {.fX = 436.6f,  .fY = 92.17f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg =  75.0f}, // FSL
        /* Rear Sensors*/
        {.fX = -105.62f, .fY = -92.07f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 255.33f}, // RSR
        {.fX = -126.87f, .fY = -81.4f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 190.0f}, // ROR
        {.fX = -131.95f, .fY = -32.92f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 180.0f}, // RIR
        {.fX = -131.95f, .fY = 32.92f, .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 180.0f}, // RIL
        {.fX = -126.87f, .fY = 81.4f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 170.0f}, // ROL
        {.fX = -105.62f, .fY = 92.07f, .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 104.67f}, // RSL
    },
   },
   .SensorsCfg_Header1 =
   {
	.ItemID  = SENSOR_MAP_CFG_ID,
	.Length  = sizeof(US_S_SensorsCfg1_t) + sizeof(uint32_t),
	.Descr   = 10,
   },
   
	.SensorsCfg1 =
   {
	.PlatformID = 0x800,
    .nBusCfg  = 2,            // 4 bus
	.Max_nSnr_ON_SINGLE_BUS    = 6,   //Max 6 sensors in single bus
	.SnrMap                    = 0x003ff, //0xc3fff
    .Snr_Positions =
     //  FSR     FOR   FIR   FIL   FOL    FSL(close ECU)        ROL  RIL  RIR   ROR    (close ECU)
	 {0x10610,0x290,0x250,0x150,0x190,0x10510,       0x1a0,0x160,0x260,0x2a0,0,0,
	                              0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
	.SnrCoordinate =
	{
        /* Front Sensors */
        {.fX = 436.6f,  .fY = -92.17f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 285.0f}, // FSR
        {.fX = 448.66f, .fY = -76.72f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 326.07f}, // FOR
        {.fX = 462.38f, .fY = -32.36f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 354.04f}, // FIR
        {.fX = 462.38f, .fY = 32.36f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg =  5.96f}, // FIL
        {.fX = 448.66f, .fY = 76.72f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg =  33.93f}, // FOL
        {.fX = 436.6f,  .fY = 92.17f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg =  75.0f}, // FSL
        /* Rear Sensors*/
        {.fX = -105.62f, .fY = -92.07f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 255.33f}, // RSR
        {.fX = -126.87f, .fY = -81.4f,   .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 190.0f}, // ROR
        {.fX = -131.95f, .fY = -32.92f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 180.0f}, // RIR
        {.fX = -131.95f, .fY = 32.92f, .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 180.0f}, // RIL
        {.fX = -126.87f, .fY = 81.4f,  .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 170.0f}, // ROL
        {.fX = -105.62f, .fY = 92.07f, .fZ = 0.0f, .fAngAlpha =0.0f, .fAngBeta = 0.0f, .fAngDeg = 104.67f}, // RSL
    },                                                          
   },
   .TuneBlockHeader =
   {
	.CheckSum = 0x29350edb,   //0xed571a8a,    //0xecb5b8e1,                                    //0xecb5c5e1,
	.Length   = 2*sizeof(uint16_t) + (2+MAX_TEMP_CFG_POINTS)* sizeof(US_S_ProfileCfg_t) + (3+10+10+1+2+1+1+1+3)* sizeof(US_S_SnrCfg_cal_Item_Header_t) + (8 * MAX_TEMP_CFG_POINTS + 2)*2 *sizeof(US_S_StcSeg_t)+ (8 * MAX_TEMP_CFG_POINTS + 2)*4 *sizeof(US_S_StgSeg_t)+ sizeof(US_S_FTCfg_t) \
	          + 2*sizeof(US_S_AATGCfg_t)+sizeof(US_S_ATGCfg_t)+sizeof(US_S_NFDCfg_t)+sizeof(US_S_SensorEEFlagVarCTRL_t)+sizeof(US_S_GanaMeasBegin_t)+sizeof(US_S_EDICfg_t)+sizeof(US_S_TemperatureCompensation_t),
	.ID       = BLOCK_TUNE_ID,
	.Rev      = 0x101,

   },
   /*************** Basic Setting *****************************/
   /*********************************************************************/
   /* FTC Setting */
   /**********************************************************************/
   .FTC_Cfg_header =
   {
   	.ItemID  = FTC_CFG_ID,
   	.Length  = sizeof(US_S_FTCfg_t) + sizeof(uint32_t),
   	.Descr   = 0
   },

   .USSSENS_v_Basic_FTC_t =
   {
     .Cfg = 7,
     .Enable = 1
   },
   /*********************************************************************/
   /* AATG1 Setting */
   /**********************************************************************/
   .AATG1_Cfg_header =
   {
   	.ItemID  = AATG1_CFG_ID,
   	.Length  = sizeof(US_S_AATGCfg_t) + sizeof(uint32_t),
   	.Descr   = 0
   },
   .USSSENS_v_Basic_AATG1_t =
   {
     .CN = US_D_CHIRPCN,
     .CW = US_D_CHIRPCW,
     .Alpha = 2
   },
   /*********************************************************************/
   /* AATG2 Setting */
   /**********************************************************************/
   .AATG2_Cfg_header =
   {
   	.ItemID  = AATG2_CFG_ID,
   	.Length  = sizeof(US_S_AATGCfg_t) + sizeof(uint32_t),
   	.Descr   = 0
   },

   .USSSENS_v_Basic_AATG2_t =
   {
     .CN = US_D_CHIRPCN,
     .CW = US_D_CHIRPCW,
     .Alpha = 2
   },
   /*********************************************************************/
   /* ATG Setting */
   /**********************************************************************/
   .ATG_Cfg_header =
   {
   	.ItemID  = ATG_CFG_ID,
   	.Length  = sizeof(US_S_ATGCfg_t) + sizeof(uint32_t),
   	.Descr   = 0
   },


   .USSSENS_v_Basic_ATG_t =
   {
     .Tau   = 3,
     .Alpha = 3,
     .Int   = 5,
     .On    = 0 
   },
   /*********************************************************************/
   /* NFD Setting */
   /**********************************************************************/
   .NFD_Cfg_header =
   {
   	.ItemID  = NFD_CFG_ID,
   	.Length  = sizeof(US_S_NFDCfg_t) + sizeof(uint32_t),
   	.Descr   = 0
   },

   .USSSENS_v_Basic_NFD_t =
   {
     .LimitTime = 7, //7*300 = 2100us
     .Sen       = 5,
     .Th        = 3000,
     .RingDev   = 0 //unit: 10us
   },
   /*********************************************************************/
   /* SnrComp Setting */
   /**********************************************************************/
   .SnrComp_Cfg_header =
   {
   	.ItemID  = SENSORCOMP_CFG_ID,
   	.Length  = sizeof(US_S_SensorEEFlagVarCTRL_t) + sizeof(uint32_t),
   	.Descr   = 0
   },

   .USSSENS_v_Basic_SnrComp_t =
   {
     .val =0x0A00
   },
   /*********************************************************************/
   /* GanaMeasBegin Setting */
   /**********************************************************************/
   .GanaMeasBegin_Cfg_header =
   {
   	.ItemID  = GANAMEASBEGIN_CFG_ID,
   	.Length  = sizeof(US_S_GanaMeasBegin_t) + sizeof(uint32_t),
   	.Descr   = 0
   },

   .USSSENS_v_Basic_GanaMeasBegin_t = //for avoid spike
   {
     .EndTime  = 0, //us
     .Gana_Dig = 0,
     .Gana     = 0
   },
   /*********************************************
         edi_mode     | edi_debug0   | edi_debug1
   ---------------------------------------------
   0 EDI_SEL_FIX(def) | AMPD_ENV     | STG_TH
   1 EDI_SEL_FILT1    | FILT1        | AATG1_TH
   2 EDI_SEL_FILT2    | FILT2        | AATG2_TH
   3 EDI_SEL_CONF1    | FILT1        | CONF1
   4 EDI_SEL_CONF2    | FILT2        | CONF2
   5 EDI_SEL_ATG      | AMPD_ENV     | ATG_TH
   6 EDI_SEL_FIX_RAW  | ENVP_ENV_RAW | AMPD_ENV
   *********************************************/
   /*SampleTime = 0: 40us, 1:80us(def), 2:120us*/
   /*********************************************************************/
   /* EDI Setting */
   /**********************************************************************/
   .EDI_Cfg_header =
   {
   	.ItemID  = EDI_CFG_ID,
   	.Length  = sizeof(US_S_EDICfg_t) + sizeof(uint32_t),
   	.Descr   = 0
   },

   .USSSENS_v_Basic_EDI_t =
   {
     .StartTime  = 0,
     .Mode       = 0, //EDI_SEL_FIX
     .SampleTime = 0  //40us
   },


/*********************************************************************/
/* ProfileCfgB*/
/**********************************************************************/	
  .ProfileCfgB_header =
  {
	.ItemID  = PROFILE_CFG_ID,
	.Length  = sizeof(US_S_ProfileCfg_t) + sizeof(uint32_t),
	.Descr   = US_E_PROFILE_B,
  },
  .USSSENS_v_ProfileCfgB_t =
  {
    .nPulses_N = US_D_NFD_BURSTNUM,
    .nPulses_C = 64,
    .Current   = 31,
    .G_dig     = 0,
    .G_ana     = US_D_PROFILEb_GANA,
    .BW        = 8,
    .CN1       = US_D_CHIRPCN,
    .CW1       = US_D_CHIRPCW,
    .CN2       = US_D_CHIRPCN,
    .CW2       = US_D_CHIRPCW,
    .ATG_on    = ME_FALSE,
    .STC_on    = ME_TRUE,
    .FTC_on    = ME_TRUE,
    .NFD_on    = ME_TRUE,
  },
/*********************************************************************/
/* ProfileCfgC*/
/**********************************************************************/	
  .ProfileCfgC_header =
  {
	.ItemID  = PROFILE_CFG_ID,
	.Length  = sizeof(US_S_ProfileCfg_t) + sizeof(uint32_t),
	.Descr   = US_E_PROFILE_C,
  },

  .USSSENS_v_ProfileCfgC_t = 
  {
    .nPulses_N = US_D_FAR_BURSTNUM_FIX,
    .nPulses_C = 64,
    .Current   = 31,
    .G_dig     = 0,
    .G_ana     = 0,
    .BW        = 8,
    .CN1       = US_D_CHIRPCN,
    .CW1       = US_D_CHIRPCW,
    .CN2       = US_D_CHIRPCN,
    .CW2       = US_D_CHIRPCW,
    .ATG_on    = ME_FALSE,
    .STC_on    = ME_TRUE,
    .FTC_on    = ME_TRUE,
    .NFD_on    = ME_FALSE,
  },
/*************** STC Setting *****************************/
/*                                                        */
/*********************************************************/
/*********************************************************************/
/* STC Setting for ProfileCfgC*/
/**********************************************************************/	
  .STC_ProfileCfgC_header =
  {
	.ItemID  = STC_CFG_ID,
	.Length  = 2* sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
	.Descr   = US_E_PROFILE_C,
  },

  .USSSENS_v_ProfC_STC_Base_at =
  {
   {
    .start    = 0,
    .seg[0] =
    {
      .time   = 5,
      .mode   = 0,
      .target = 45,
      .tb     = 8,
    },
    .seg[1] =
    {
      .time   = 12,
      .mode   = 0,
      .target = 42,
      .tb     = 40,
    },
    .seg[2] =
    {
      .time   = 14,
      .mode   = 0,
      .target = 40,
      .tb     = 230,
    },
    .seg[3] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 30,
      .tb     = 350,
    },
    .profile  = US_E_PROFILE_C,
   },
   {
    .start    = 4,
    .seg[0] =
    {
      .time   = 65,
      .mode   = 0,
      .target = 74,
      .tb     = 375,
    },
    .seg[1] =
    {
      .time   = 75,
      .mode   = 0,
      .target = 82,
      .tb     = 109,
    },
    .seg[2] =
    {
      .time   = 79,
      .mode   = 0,
      .target = 85,
      .tb     = 600,
    },
    .seg[3] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 110,
      .tb     = 20,
    },
    .profile  = US_E_PROFILE_C,
   },
  },
/*********************************************************************/
/* STC Setting for ProfileCfgB*/
/**********************************************************************/	
  .STC_ProfileCfgB_header =
  {
	.ItemID  = STC_CFG_ID,
	.Length  = 2* sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
	.Descr   = US_E_PROFILE_B,
  },

  .USSSENS_v_ProfB_STC_Base_at =
  {
   {
    .start    = 0,
    .seg[0] =
    {
      .time   = 4,
      .mode   = 0,
      .target = 30,
      .tb     = 25,
    },
    .seg[1] =
    {
      .time   = 5,
      .mode   = 0,
      .target = 35,
      .tb     = 15,
    },
    .seg[2] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 44,
      .tb     = 450,
    },
    .seg[3] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 78,
      .tb     = 330,
    },
    .profile  = US_E_PROFILE_B
   },
   {
    .start    = 4,
    .seg[0] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 85,
      .tb     = 500,
    },
    .seg[1] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 86,
      .tb     = 600,
    },
    .seg[2] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 86,
      .tb     = 600,
    },
    .seg[3] =
    {
      .time   = 218,
      .mode   = 0,
      .target = 96,
      .tb     = 2048,
    },
    .profile  = US_E_PROFILE_B,
   }
 },
/*************** STG Setting *****************************/

/*********************************************************************/
/* STG Setting for ProfileCfgC*/
/**********************************************************************/	
.STG_ProfileCfgC_header =
{
	.ItemID  = STG_CFG_ID,
	.Length  = 4* sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
	.Descr   = (US_E_PROFILE_C)
},

.USSSENS_v_ProfC_STG_Base_at =
{
  {
    .start  = 0,
    .seg[0] =
    {
      .time = 0,
      .th   = 25,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 100,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 20,
      .th   = 90,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 24,
      .th   = 80,
      .step = -1,
      .tb   = 500,
    },
    .profile = US_E_PROFILE_C
  },
  {
    .start  = 4,
    .seg[0] =
    {
      .time = 83,
      .th   = 40,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 100,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 218,
      .th   = 80,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 70,
      .step = -10,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_C
  },
  {
    .start  = 8,
    .seg[0] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_C
  },
  {
    .start  = 12,
    .seg[0] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 218,
      .th   = 20,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 50,
      .step = -10,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_C
  }
},
/*********************************************************************/
/* STG Setting for ProfileCfgB*/
/**********************************************************************/	
.STG_ProfileCfgB_header =
{
	.ItemID  = STG_CFG_ID,
	.Length  = 4* sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
	.Descr   = (US_E_PROFILE_B)
},

.USSSENS_v_ProfB_STG_Base_at =
{
  {
    .start  = 0,
    .seg[0] =
    {
      .time = 0,
      .th   = 100,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 4,
      .th   = 40,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 40,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 250,
      .step = -1,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_B
  },
  {
    .start  = 4,
    .seg[0] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_B
  },
  {
    .start  = 8,
    .seg[0] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_B
  },
  {
    .start  = 12,
    .seg[0] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[1] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[2] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .seg[3] =
    {
      .time = 218,
      .th   = 250,
      .step = -10,
      .tb   = 0,
    },
    .profile = US_E_PROFILE_B
  }
},

  /*********************************************************************/
  /* ProfileCfgA Group for 5 temperature points   */
  /**********************************************************************/

   .TempCompCfg_header =
  {
	.ItemID  = TEMPCOMP_CFG_ID,
	.Length  = sizeof(US_S_TemperatureCompensation_t) + sizeof(uint32_t),
	.Descr   = 0,
  },
  .TempCompCfg =
  {
	 // below temperature value = temperature *10
	 // CFG_TEMP_POINTS should be less than 20
	.points_temp =  CFG_TEMP_POINTS,
	.default_temp = 200,                  //20C
	//below should be CFG_TEMP_POINTS + 1
	.temp_table[0] =50,
	.temp_table[1] =150,
	.temp_table[2] =280,
	//.temp_table[3] =350,

  },
   .ProfileCfgA_header =
  {
	.ItemID  = PROFILE_CFG_ID,
	.Length  = MAX_TEMP_CFG_POINTS * sizeof(US_S_ProfileCfg_t) + sizeof(uint32_t),
	.Descr   = US_E_PROFILE_A,
  },
  .USSSENS_v_ProfileCfgA_t =
  {
		   /******************************************/
		   /*  point 0 for(Min Temerature or less) ProfileCfgA          */
		   /**************************************** */
			{
		      .nPulses_N = US_D_FAR_BURSTNUM_FIX,
		      .nPulses_C = 64,
		      .Current   = 31,
		      .G_dig     = 0,
		      .G_ana     = 7, //US_D_GANA,
		      .BW        = 2,
		      .CN1       = US_D_CHIRPCN,
		      .CW1       = US_D_CHIRPCW,
		      .CN2       = US_D_CHIRPCN,
		      .CW2       = US_D_CHIRPCW,
		      .ATG_on    = ME_FALSE,
		      .STC_on    = ME_TRUE,
		      .FTC_on    = ME_TRUE,
		      .NFD_on    = ME_FALSE,
		    },
		   /******************************************/
		   /*  point 1 for  ProfileCfgA                          */
		   /**************************************** */
			{
		      .nPulses_N = US_D_FAR_BURSTNUM_FIX,
		      .nPulses_C = 64,
			  .Current   = 31,
		      .G_dig     = 0,
		      .G_ana     = 7, //US_D_GANA,
		      .BW        = 2,
		      .CN1       = US_D_CHIRPCN,
		      .CW1       = US_D_CHIRPCW,
		      .CN2       = US_D_CHIRPCN,
		      .CW2       = US_D_CHIRPCW,
		      .ATG_on    = ME_FALSE,
		      .STC_on    = ME_TRUE,
		      .FTC_on    = ME_TRUE,
		      .NFD_on    = ME_FALSE,
		    },
		   /******************************************/
		   /*  point 2 for  ProfileCfgA              */
		   /**************************************** */
			{
		      .nPulses_N = US_D_FAR_BURSTNUM_FIX,
		      .nPulses_C = 64,
		      .Current   = 31,
		      .G_dig     = 0,
		      .G_ana     = 7, //US_D_GANA,
		      .BW        = 2,
		      .CN1       = US_D_CHIRPCN,
		      .CW1       = US_D_CHIRPCW,
		      .CN2       = US_D_CHIRPCN,
		      .CW2       = US_D_CHIRPCW,
		      .ATG_on    = ME_FALSE,
		      .STC_on    = ME_TRUE,
		      .FTC_on    = ME_TRUE,
		      .NFD_on    = ME_FALSE,
		    },
		   /******************************************/
		   /*  point 3  for  ProfileCfgA                            */
		   /**************************************** */
	 	   {
	          .nPulses_N = US_D_FAR_BURSTNUM_FIX,
		      .nPulses_C = 64,
		      .Current   = 31,
		      .G_dig     = 0,
		      .G_ana     = 7, //US_D_GANA,
	          .BW        = 2,
		      .CN1       = US_D_CHIRPCN,
		      .CW1       = US_D_CHIRPCW,
		      .CN2       = US_D_CHIRPCN,
		      .CW2       = US_D_CHIRPCW,
		      .ATG_on    = ME_FALSE,
		      .STC_on    = ME_TRUE,
		      .FTC_on    = ME_TRUE,
		      .NFD_on    = ME_FALSE,
		   },

		   /******************************************/
		   /*  point 4 for  ProfileCfgA */
		   /**************************************** */
	 	   {
	          .nPulses_N = US_D_FAR_BURSTNUM_FIX,
		      .nPulses_C = 64,
		      .Current   = 31,
		      .G_dig     = 0,
		      .G_ana     = 7, //US_D_GANA,
	          .BW        = 2,
		      .CN1       = US_D_CHIRPCN,
		      .CW1       = US_D_CHIRPCW,
		      .CN2       = US_D_CHIRPCN,
		      .CW2       = US_D_CHIRPCW,
		      .ATG_on    = ME_FALSE,
		      .STC_on    = ME_TRUE,
		      .FTC_on    = ME_TRUE,
		      .NFD_on    = ME_FALSE,
		   },


  },

  /*********************************************************************/
  /* STC Setting for ProfileCfgA Front Side*/
  /**********************************************************************/
    .STC_ProfileCfgA_FrontSide_header =
    {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_FRONT_POS) |(US_SIDE_POS),
    },

    .USSSENS_v_ProfA_FrontSide_STC_Base_at =
   {
   /****************************************** */
   /*  point 0 for(Min Temerature) of STC Setting for ProfileCfgA Front Side */
   /**************************************** */

	 {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   /******************************************/
   /*  point 1  of STC Setting for ProfileCfgA Front Side */
   /**************************************** */

	 {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   /****************************************** */
   /*  point 2  of STC Setting for ProfileCfgA Front Side */
   /**************************************** */

	 {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   /******************************************/
   /*  point 3  of STC Setting for ProfileCfgA Front Side */
   /**************************************** */

	 {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   /******************************************/
   /*  point 4  of STC Setting for ProfileCfgA Front Side */
   /**************************************** */

	 {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   },
  /*********************************************************************/
  /* STC Setting for ProfileCfgA Rear Side*/
  /**********************************************************************/
  .STC_ProfileCfgA_RearSide_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_REAR_POS) |(US_SIDE_POS)
  },

  .USSSENS_v_ProfA_RearSide_STC_Base_at =
   {
	/******************************************/
    /*  point 0  of STC Setting for ProfileCfgA Rear Side */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Rear Side */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2  of STC Setting for ProfileCfgA Rear Side */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Rear Side */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Rear Side */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

   },
  /*********************************************************************/
  /* STC Setting for ProfileCfgA Front Inner*/
  /**********************************************************************/
  .STC_ProfileCfgA_FrontInner_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_FRONT_POS) |(US_INNER_POS)
  },

  .USSSENS_v_ProfA_FrontInner_STC_Base_at =
   {
	/******************************************/
    /*  point 0  of STC Setting for ProfileCfgA Front Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Front Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2  of STC Setting for ProfileCfgA Front Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Front Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Front Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

   },
  /*********************************************************************/
  /* STC Setting for ProfileCfgA Rear  Inner*/
  /**********************************************************************/
  .STC_ProfileCfgA_RearInner_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_REAR_POS) |(US_INNER_POS)
  },

  .USSSENS_v_ProfA_RearInner_STC_Base_at =
   {
     /******************************************/
     /*  point 0  of STC Setting for ProfileCfgA Rear Inner */
	 /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Rear Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2 of STC Setting for ProfileCfgA Rear Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Rear Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Rear Inner */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   },

  /*********************************************************************/
  /* STC Setting for ProfileCfgA Front Outer*/
  /**********************************************************************/
  .STC_ProfileCfgA_FrontOuter_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_FRONT_POS) |(US_OUTER_POS)
  },

  .USSSENS_v_ProfA_FrontOuter_STC_Base_at =
   { 
     /******************************************/
     /*  point 0  of STC Setting for ProfileCfgA Front Outer */
	 /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Front Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2 of STC Setting for ProfileCfgA Front Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Front Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Front Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   },
  
 
  /*********************************************************************/
  /* STC Setting for ProfileCfgA Rear Outer*/
  /**********************************************************************/
  .STC_ProfileCfgA_RearOuter_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_REAR_POS) |(US_OUTER_POS)
  },

  .USSSENS_v_ProfA_RearOuter_STC_Base_at =
     {
     /******************************************/
     /*  point 0  of STC Setting for ProfileCfgA Rear Outer */
	 /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Rear Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2 of STC Setting for ProfileCfgA Rear Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Rear Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Rear Outer */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   },
  
 
  /*********************************************************************/
  /* STC Setting for ProfileCfgA Front MID*/
  /**********************************************************************/
  .STC_ProfileCfgA_A_OUTER_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_A_POS) |(US_OUTER_POS)
  },

  .USSSENS_v_ProfA_A_OUTER_STC_Base_at =
     {
     /******************************************/
     /*  point 0  of STC Setting for ProfileCfgA Front MID */
	 /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Front MID */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2 of STC Setting for ProfileCfgA Front MID */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Front MID */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Front MID */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   },

  /*********************************************************************/
  /* STC Setting for ProfileCfgA Rear Mid*/
  /**********************************************************************/
  .STC_ProfileCfgA_B_OUTER_header =
  {
  	.ItemID  = STC_CFG_ID,
  	.Length  = 2* MAX_TEMP_CFG_POINTS * sizeof(US_S_StcSeg_t) + sizeof(uint32_t),
  	.Descr   = (US_E_PROFILE_A)|(US_B_POS) |(US_OUTER_POS)
  },

  .USSSENS_v_ProfA_B_OUTER_STC_Base_at =
     {
     /******************************************/
     /*  point 0  of STC Setting for ProfileCfgA Rear Mid */
	 /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 1  of STC Setting for ProfileCfgA Rear Mid */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 2 of STC Setting for ProfileCfgA Rear Mid */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
	/******************************************/
    /*  point 3  of STC Setting for ProfileCfgA Rear Mid */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },

	/******************************************/
    /*  point 4  of STC Setting for ProfileCfgA Rear Mid */
    /**************************************** */
    {
      .start    = 0,
      .seg[0] =
      {
        .time   = 20,
        .mode   = 0,
        .target = 24,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 33,
        .mode   = 0,
        .target = 34,
        .tb     = 320,
      },
      .seg[2] =
      {
        .time   = 47,
        .mode   = 0,
        .target = 44,
        .tb     = 320,
      },
      .seg[3] =
      {
        .time   = 59,
        .mode   = 0,
        .target = 50,
        .tb     = 320,
      },
      .profile  = US_E_PROFILE_A
    },
    {
      .start    = 4,
      .seg[0] =
      {
        .time   = 68,
        .mode   = 0,
        .target = 58,
        .tb     = 320,
      },
      .seg[1] =
      {
        .time   = 81,
        .mode   = 0,
        .target = 62,
        .tb     = 300,
      },
      .seg[2] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .seg[3] =
      {
        .time   = 218,
        .mode   = 0,
        .target = 110,
        .tb     = 20,
      },
      .profile  = US_E_PROFILE_A,
    },
   },
 

   /*********************************************************************/
   /* STG Setting for ProfileCfgA FrontSide*/
   /**********************************************************************/
   .STG_ProfileCfgA_FrontSide_header =
   {
   	.ItemID  = STG_CFG_ID,
   	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
   	.Descr   = (US_E_PROFILE_A)|(US_FRONT_POS) |(US_SIDE_POS)
   },

   .USSSENS_v_ProfA_FrontSide_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA FrontSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 5,
         .th   = 100,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A,
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 62,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 69,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 66,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 64,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 61,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 69,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 76,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA FrontSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 5,
         .th   = 100,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 62,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 59,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 58,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 56,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 54,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 53,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 51,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 59,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 58,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 66,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA FrontSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 5,
         .th   = 100,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 42,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 39,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 38,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 36,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 34,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 33,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 31,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 29,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 28,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 27,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 26,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA FrontSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 5,
         .th   = 100,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 42,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 39,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 38,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 36,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 34,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 33,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 31,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 29,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 18,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 17,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 16,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 15,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA FrontSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },
   /*********************************************************************/
   /* STG Setting for ProfileCfgA RearSide*/
   /**********************************************************************/
   .STG_ProfileCfgA_RearSide_header =
   {
   	.ItemID  = STG_CFG_ID,
   	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
   	.Descr   = (US_E_PROFILE_A)|(US_REAR_POS) |(US_SIDE_POS)
   },

   .USSSENS_v_ProfA_RearSide_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA RearSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 71,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 71,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 59,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 59,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA RearSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 62,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 62,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 61,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 61,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 49,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 49,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA RearSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 51,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 51,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 40,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 29,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 29,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA RearSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 51,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 51,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 19,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 19,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA RearSide */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },
   
 
   /*********************************************************************/
   /* STG Setting for ProfileCfgA Front Inner*/
   /**********************************************************************/
   .STG_ProfileCfgA_FrontInner_header =
   {
   	.ItemID  = STG_CFG_ID,
   	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
   	.Descr   = (US_E_PROFILE_A)|(US_FRONT_POS) |(US_INNER_POS)
   },
   .USSSENS_v_ProfA_FrontInner_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA Front Inner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA Front Inner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA Front Inner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA Front Inner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA Front Inner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },

   /*********************************************************************/
   /* STG Setting for ProfileCfgA RearInner*/
   /**********************************************************************/
   .STG_ProfileCfgA_RearInner_header =
   {
   	.ItemID  = STG_CFG_ID,
   	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
   	.Descr   = (US_E_PROFILE_A)|(US_REAR_POS) |(US_INNER_POS)
   },

   .USSSENS_v_ProfA_RearInner_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA RearInner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA RearInner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA RearInner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA RearInner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 45,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA RearInner */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },
   
 
   /*********************************************************************/
   /* STG Setting for ProfileCfgA FrontOuter*/
   /**********************************************************************/
   .STG_ProfileCfgA_FrontOuter_header =
   {
   	.ItemID  = STG_CFG_ID,
   	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
   	.Descr   = (US_E_PROFILE_A)|(US_FRONT_POS) |(US_OUTER_POS)
   },

   .USSSENS_v_ProfA_FrontOuter_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA FrontOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 95,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 64,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 61,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 66,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 74,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 73,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 81,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA FrontOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 95,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 54,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 51,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 58,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 56,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 54,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 53,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 61,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA FrontOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 95,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 44,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 41,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 38,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 36,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 34,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 33,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 32,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 31,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA FrontOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 95,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 11,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 17,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 23,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 29,
         .th   = 50,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 35,
         .th   = 44,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 40,
         .th   = 41,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 45,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 50,
         .th   = 26,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 55,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 60,
         .th   = 24,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 65,
         .th   = 23,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 70,
         .th   = 22,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 21,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 80,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA FrontOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },


         /*********************************************************************/
         /* STG Setting for ProfileCfgA RearOuter*/
         /**********************************************************************/
    .STG_ProfileCfgA_RearOuter_header =
    {
         	.ItemID  = STG_CFG_ID,
         	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
         	.Descr   = (US_E_PROFILE_A)|(US_REAR_POS) |(US_OUTER_POS)
    },

    .USSSENS_v_ProfA_RearOuter_STG_Base_at =
    {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA RearOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 95,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 74,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 81,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 76,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 74,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 82,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA RearOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 95,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 58,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 68,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 64,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 61,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 66,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 54,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 62,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA RearOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 48,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 48,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 48,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 44,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 41,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 36,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 34,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 32,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA RearOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 75,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 55,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 48,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 48,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 48,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 44,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 31,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 26,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 24,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 22,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA RearOuter */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },
	
 

         /*********************************************************************/
         /* STG Setting for ProfileCfgA FrontMID*/
         /**********************************************************************/
   .STG_ProfileCfgA_A_OUTER_header =
   {
         	.ItemID  = STG_CFG_ID,
         	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
         	.Descr   = (US_E_PROFILE_A)|(US_A_POS) |(US_OUTER_POS)
   },

   .USSSENS_v_ProfA_A_OUTER_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA FrontMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 83,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 83,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 82,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 82,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 90,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA FrontMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 73,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 73,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA FrontMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 47,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 40,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA FrontMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 37,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA FrontMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },
   
 
   /*********************************************************************/
   /* STG Setting for ProfileCfgA RearMID*/
   /**********************************************************************/
   .STG_ProfileCfgA_B_OUTER_header =
   {
   	.ItemID  = STG_CFG_ID,
   	.Length  = 4* MAX_TEMP_CFG_POINTS * sizeof(US_S_StgSeg_t) + sizeof(uint32_t),
   	.Descr   = (US_E_PROFILE_A)|(US_B_POS) |(US_OUTER_POS),
   },

   .USSSENS_v_ProfA_B_OUTER_STG_Base_at =
   {
	/******************************************/
    /*  point 0  of STG Setting for ProfileCfgA RearMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 83,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 83,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 82,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 82,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 87,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 80,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 85,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 90,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 1  of STG Setting for ProfileCfgA RearMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 73,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 73,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 77,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 70,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 65,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 60,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 2  of STG Setting for ProfileCfgA RearMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 47,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 40,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 35,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
 	/******************************************/
    /*  point 3  of STG Setting for ProfileCfgA RearMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 140,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 84,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 72,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 67,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 63,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 57,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 52,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 37,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 30,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 25,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 20,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
	/******************************************/
    /*  point 4  of STG Setting for ProfileCfgA RearMID */
    /**************************************** */
     {
       .start  = 0,
       .seg[0] =
       {
         .time = 0,
         .th   = 255,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 4,
         .th   = 254,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 8,
         .th   = 253,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 12,
         .th   = 252,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A,
     },
     {
       .start  = 4,
       .seg[0] =
       {
         .time = 16,
         .th   = 5u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 21,
         .th   = 6u,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 26,
         .th   = 7u,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 31,
         .th   = 8u,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 8,
       .seg[0] =
       {
         .time = 37,
         .th   = 9u,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 43,
         .th   = 0x0A,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 48,
         .th   = 0x0B,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 54,
         .th   = 0x0C,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
     {
       .start  = 12,
       .seg[0] =
       {
         .time = 61,
         .th   = 0x0D,
         .step = -10,
         .tb   = 0,
       },
       .seg[1] =
       {
         .time = 68,
         .th   = 0x0E,
         .step = -10,
         .tb   = 0,
       },
       .seg[2] =
       {
         .time = 75,
         .th   = 0x0F,
         .step = -10,
         .tb   = 0,
       },
       .seg[3] =
       {
         .time = 81,
         .th   = 0x10,
         .step = -10,
         .tb   = 0,
       },
       .profile = US_E_PROFILE_A
     },
  },
.endCal=
 {
			.CheckSum = 0,         //0xf85f81e3,       // 0xf86dc847,          //0xf871c84b,                     //0xf871d54b,
			.Length   = 0,
			.ID       = 0,
			.Rev      = 0,
 },
};

const US_S_SnrCfg_cal_t *cal_data[MAX_CAL_DATA_VEH]=
{
				&cal_data_CVADAS
				
};

#endif
#endif /* SRC_US_CALIBRATION_US_SNRCFG_DATA_C_ */
