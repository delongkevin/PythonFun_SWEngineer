

/*
 * USSDrv_SnrCfg.c
 *
 *  Created on: Feb 18, 2021
 *      Author: e39960
 */
/*PRQA S 0310,3305,0311,1496,4391 EOF */
#include "US_ME_Typedefs_Global.h"

#include "US_Data_Typedefs_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrCfg_data_struct.h"
#include "US_SysMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"
#include "US_Ctrl_Global.h"
#include "US_ComOutputBuffer_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Calib_CsmIf.h"
#include "Us_SnrDrv_CsmIf.h"
#endif

#define MAX_CAL_IPC_TIME   (300u)

#if(QAC_WARNING_FIX == ME_FALSE)
#define US_SNRCFG_WAIT     (10000u)
#define DSI3_UV_MASK       (0x2000u)
#define DSI3_OC_MASK       (0x800u)
#define DSI3_RAM_BIST_MASK       (0x4u)
#define DSI3_FSM_RST_MASK       (0x400u)
#define DSI3_OT_MASK                        (0x4000u)
#define DSI3_VCCUV_MASK                     (0x8000u)
#define DSI3_VDSIUV_MASK                     (0x800u)
#define US_RECFG_SENSOR_DELAY  (10u)
#define SNR_NEW_ID_ADDR                            (0xA6u)         /*need to be updated when it is available */
#define SNR_RESET_REASON_ADDR                      (0xC8u)         /*need to be updated when it is available */
#define SENSOR_CFG_OPMODE                          (SENSOR_OP_NORMAL)                     /*(SENSOR_OP_NORMAL)   (SENSOR_OP_MFG) */
#endif

#define INVALID_CALI_VER        (0xffffffffu)
#define VEH_CAL_CHOICE          (0xffffU)

#if(QAC_WARNING_FIX == ME_FALSE)
typedef struct s_req_stg
{
    uint32_t Profile_Type;
    US_S_reqStcStgCfg_t reqstg;
}req_stg_t;
#endif


#if(QAC_WARNING_FIX == ME_FALSE)
bool_t US_SnrCfg_Get_CaliExitMode(void);
static uint8_t US_SnrCfg_F_Range_Check(int16_t Value,int16_t Limit);
#endif


static uint16_t US_SnrCfg_F_Set_CalData(uint16_t nCal);
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER))
static uint8_t US_SnrCfg_nSensor[EIGHT][TWO] __attribute__ ((section (".uss_isr_data")));
#else
static uint8_t US_SnrCfg_nSensor[EIGHT][TWO];
#endif
static volatile bool_t bPopulateSensorSensitivity = ME_FALSE;
static uint8_t US_SnrCfg_OPmode[MAX_NUM_SENSORS];
static uint16_t US_SnrCfg_reset_reason[MAX_NUM_SENSORS];
static uint16_t US_SnrCfg_FW_Ver[MAX_NUM_SENSORS];
static uint32_t US_SnrCfg_SensorID[MAX_NUM_SENSORS];
static uint64_t US_SnrCfg_NewSensorID[MAX_NUM_SENSORS];
/*static uint16_t nTemp_ProfileCfg = ZERO;
static uint8_t US_SnrCfgASILSnrDetected= ME_FALSE; */
static uint8_t USS_PowerON = ME_TRUE;                     

static uint8_t  US_x_offset_index = 0;

static US_S_Sensor_coordinate_t SnrCoordinate[MAX_NUM_SENSORS];             

static US_S_SnrCfg_Cali_Data_t Cali_Head[10]={0},Cali_Data[MAX_CALI_ITEMS];
static US_S_SensorsCfg_t US_SnrCfg_SnrCfg; /*sensor configure info from Configure_data */
static uint32_t US_Install_SnrMap = ZERO,nCal_Data_Veh = ZERO;

static uint8_t gSensorCfg = (uint8_t)TWELVE;

static uint16_t Cal_Data_Set = VEH_CAL_CHOICE;   /*0xffff; */

static uint32_t SnrOpModeMask = ZERO;   /*0xffff; */

uint16_t uUsed_Cal_Data_Set = 0xFFFF;

extern void UssOdo_OdometryInit(void);

   #ifdef CALIBRATION_DATA_NVM  
extern uint8_t *US_Get_CalNVMData(void);
   #else
uint8_t* US_Get_Hardcode_Caldata(void);
   #endif
static uint16_t US_SnrCfg_F_Check_CfgData(void);
static uint16_t US_SnrCfg_F_Get_CfgVer(uint32_t BlockID);

uint16_t US_SnrCfg_F_GetCalData(uint16_t ReTrival);

/* ===========================================================================
 * Name:     US_SnrCfg_SetOpModeMask
 * Remarks:  DD-ID:
 * ===========================================================================*/
void US_SnrCfg_SetOpModeMask(uint32_t OpModeMask)
{
	SnrOpModeMask = OpModeMask;
}

/* ===========================================================================
 * Name:     US_SnrCfg_Get_AllNewSensorID
 * Remarks:  DD-ID:{9070F58E-6583-441f-9400-4215A6873E23}
 * ===========================================================================*/
uint64_t* US_SnrCfg_Get_AllNewSensorID(void)
{
	return &US_SnrCfg_NewSensorID[ZERO];
}

/* ===========================================================================
 * Name:     US_SnrCfg_Get_AllSensorID
 * Remarks:  DD-ID:{163C15AA-7A96-47c6-9A9B-AC4DA9848E9C}
 * ===========================================================================*/
uint32_t* US_SnrCfg_Get_AllSensorID(void)
{
		return &US_SnrCfg_SensorID[ZERO];
}
#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
/* ===========================================================================
 * Name:     US_SnrCfg_Get_Variant
 * Remarks:  DD-ID:{8BC7215A-819A-4bd5-96E0-0874424459DE}
 * ===========================================================================*/
uint16_t US_SnrCfg_Get_Variant(void)
{
	return Cal_Data_Set;
}
#endif
/* ===========================================================================
 * Name:     US_SnrCfg_Get_AllReset_reason
 * Remarks:  DD-ID:{576BC134-0CBD-4500-9FBA-F36A5F9A7A31}
 * ===========================================================================*/
uint16_t* US_SnrCfg_Get_AllReset_reason(void)
{
    return &US_SnrCfg_reset_reason[ZERO];
}
/* ===========================================================================
 * Name:     US_SnrCfg_Get_AllSensors_opmode
 * Remarks:  DD-ID:{ED43F70D-3739-40ea-BE5A-0BD253711C2E}
 * ===========================================================================*/
uint8_t* US_SnrCfg_Get_AllSensors_opmode(void)
{
    return &US_SnrCfg_OPmode[ZERO];
}
/* ===========================================================================
 * Name:     US_SnrCfg_Get_Sensor_opmode
 * Remarks:  DD-ID:{837E8A3D-BA9D-4753-9B10-14BD8F4C72AB}
 * ===========================================================================*/
uint8_t US_SnrCfg_Get_Sensor_opmode(void)
{
    return US_SnrCfg_OPmode[MAX_NUM_SENSORS - ONE];
}
/* ===========================================================================
 * Name:     US_SnrCfg_Get_nSensor
 * Remarks:  DD-ID:{DD294B90-33D2-455d-84F5-05EF136024AD}
 * ===========================================================================*/
uint8_t *US_SnrCfg_Get_nSensor(void)
{
    return &US_SnrCfg_nSensor[ZERO][ZERO];
}
/* ===========================================================================
 * Name:     US_SnrCfg_Get_AllSnrFWVer
 * Remarks:  DD-ID: {BD98FFFC-A891-45d2-8647-35E5DD67081D}
 * ===========================================================================*/
uint16_t* US_SnrCfg_Get_AllSnrFWVer(void)
{
    return &US_SnrCfg_FW_Ver[ZERO];
}
/* ===========================================================================
 * Name:     US_SnrCfg_Get_SnrFWVer
 * Remarks:  DD-ID: {E32898B4-1E02-4952-B2BE-A8F37FDE4049}
 * ===========================================================================*/
uint16_t US_SnrCfg_Get_SnrFWVer(void)
{
    return US_SnrCfg_FW_Ver[MAX_NUM_SENSORS - ONE];
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================
 * Name:     US_SnrCfg_Get_Platform
 * Remarks:  DD-ID: {918C6371-E813-4d14-AD6F-463860956CF4}
 * ===========================================================================*/
uint16_t US_SnrCfg_Get_Platform(void)
{
    return US_SnrCfg_SnrCfg.PlatformID;
}
#endif
/* ===========================================================================*/
/**US_SnrCfg_F_Get_nSensor.
* used to Get number of sensor on bus.
* \param chn: channel bus, isActual: actual or cfg number of sensor on bus
* \return number of sensors
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_nSensor
 * Remarks:  DD-ID: {6F807BB5-5FCD-4642-9FC5-092607FE59B2}
 * Req.-ID: 13473277
 * ===========================================================================*/
uint8_t US_SnrCfg_F_Get_nSensor(uint8_t chn,uint8_t *Index,uint8_t isActual)
{
   uint8_t cnt,ret;
   cnt = ZERO;		
   if((chn <EIGHT)&&(isActual<TWO))
   {
	   if(Index != NULL)
	   {
		   (*Index) = ZERO;
		   for(cnt =0;cnt<chn;cnt++)
		   {
			   (*Index) += US_SnrCfg_nSensor[cnt][ZERO];
		   }
	   }
	   ret = US_SnrCfg_nSensor[chn][isActual];
   }
   else
   {
       ret = ZERO;
   }
   return ret;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Get_CfgSnrMap.
* used to Get Sensor MAP for specified position sensors that are configured.
* \param positions, return all sensors if positions is ZERO
* \return Sensor Map for input position
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_CfgSnrMap
 * Remarks:  DD-ID: {54D19FBC-9014-4f5c-A9FE-8A87086F585E}
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Get_CfgSnrMap(uint16_t position)
{
    uint32_t map;
    uint8_t cnt;
    map = ZERO;

    if(position == US_ALL_POS)
    {
        map = US_SnrCfg_SnrCfg.SnrMap; /*get all sensors configured */
    }
    else
    {
        for(cnt=ZERO; cnt<32u; cnt ++)
        {
            if(((US_SnrCfg_SnrCfg.SnrMap>>cnt) & BIT0 ) != ZERO)
            {
                if((US_SnrCfg_SnrCfg.Snr_Positions[cnt] & position) == position)
                {
                    map |= (uint32_t)(((uint32_t)BIT0)<<cnt);    
                }
            }
        }
    }
    map &= (~SnrOpModeMask);
    return map;

}

/* ===========================================================================*/
/**US_SnrCfg_F_Get_InstSnrMap.
* used to Get Sensor MAP for specified position sensors that are installed.
* \param positions, return all sensors if positions is ZERO
* \return Sensor Map for input position
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_InstSnrMap
 * Remarks:  DD-ID: {295C8F8A-E66E-4190-ACE0-99A775C4113C}
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Get_InstSnrMap(uint16_t position)
{
    uint32_t map;
    uint8_t cnt;
    map = ZERO;

    if(position == US_ALL_POS)
    {
        map = US_Install_SnrMap;             /*get all sensors installed */
    }
    else
    {
        for(cnt=ZERO; cnt<32u; cnt ++)
        {
            if(((US_SnrCfg_SnrCfg.SnrMap>>cnt) & BIT0 ) != ZERO)
            {
                if((US_SnrCfg_SnrCfg.Snr_Positions[cnt] & position) == position)
                {
                    map |= (uint32_t)(((uint32_t)BIT0)<<cnt);         
                }
            }
        }
    }
    map &= (~SnrOpModeMask);
    return map;
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_SnrCfg_F_Get_SnrLoc.
* used to Get Sensor Location for specified Index of sensor.
* \param Index of Sensor
* \return Sensor location for input index of sensor, return ZERO if the index of sensor is not exist
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_SnrLoc
 * Remarks:  DD-ID: {4FB68961-C389-45d6-9DA1-E8D862E54681}
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Get_SnrLoc(uint32_t Snr_Index)
{
    uint32_t loc = ZERO;
    if(Snr_Index < 32u)
    {
        loc = US_SnrCfg_SnrCfg.Snr_Positions[Snr_Index];
    }
    return loc;
}
#endif

/* ===========================================================================
 * Name:	 US_SnrCfg_GetDataAddr
 * Remarks:  DD-ID:{93AA2B11-64F2-4e49-96E8-195FD4B9B96E}
 * ===========================================================================*/
uint8_t * US_SnrCfg_GetDataAddr(void)
{
	uint8_t *ret;
   #ifdef CALIBRATION_DATA_NVM  
       ret =  	US_Get_CalNVMData();
   #else
     ret = US_Get_Hardcode_Caldata();
   #endif 
   return ret;
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================
 * Name:	 US_SnrCfg_Get_gNumSensorsCfg
 * Remarks:  DD-ID: {ACD43775-CCF9-4335-B28A-3630256F406D}
 * ===========================================================================*/
uint8_t US_SnrCfg_Get_gNumSensorsCfg(void)
{
   return gSensorCfg;
}
#endif
/* ===========================================================================
 * Name:     US_SnrCfg_F_Check_CfgData
 * Remarks:  DD-ID: {9E032A7D-64C5-4e1f-9038-71CE143FCB3F}
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
static uint16_t US_SnrCfg_F_Check_CfgData(void)
{
    US_S_SnrCfg_Cali_Data_t *pCalStruct = NULL;
	static uint32_t *pCal_Data_Veh = NULL;
	uint32_t *pBlock32,Chksum,BlockLen,cnt,BlocKID;
    uint16_t ItemCnt,Rev;
    uint8_t *pCalData,*pCalDataStart;
    uint32_t cal_ver,ret = ME_OK;

    US_S_SnrCfg_cal_Block_Header_t *pBlock;
    US_S_SnrCfg_cal_Item_Header_t *pItem;
   (void)memset(Cali_Data,0, MAX_CALI_ITEMS * sizeof(US_S_SnrCfg_Cali_Data_t));
    pCalDataStart = US_SnrCfg_GetDataAddr();
	pCalData  =  pCalDataStart;
    pBlock32 = (uint32_t*)(pCalData);
    ItemCnt = ZERO;
	 if(pCalDataStart == NULL)
	 {
		 ret = CALI_DATA_INVAILID;
	 }
     while(ret == ME_OK)
	 {
		BlockLen = pBlock32[ONE];
		pBlock = (US_S_SnrCfg_cal_Block_Header_t *)pBlock32;
		if((BlockLen == ZERO)&&(pBlock-> CheckSum == ZERO)&&(pBlock-> ID == ZERO))
		{
			ret  = CALI_DATA_INVAILID;
		}
		else
		{
			if((BlockLen == (uint32_t)ZERO)||(BlockLen > (uint32_t)MAX_CALI_DATA_SIZE)||(pBlock->ID >=(uint16_t) MAX_BLOCK_ID))
			{
				ret  = CALI_DATA_INVAILID;
			}
			else
			{
				Chksum = ZERO;
				for(cnt = ZERO; cnt < ((BlockLen/sizeof(uint32_t))+TWO); cnt++)
				{
					Chksum  +=  pBlock32[cnt];
				}
#ifndef CALIBRATION_DATA_NVM
				Chksum = ZERO;
#endif       
				if(Chksum != ZERO)
				{
					ret  = CALI_DATA_INVAILID;
				}
				else
				{
					pBlock = (US_S_SnrCfg_cal_Block_Header_t *)pBlock32;
					if(pBlock->Rev < BLOCK_VER_LIMIT)
					{
						ret  = CALI_DATA_INVAILID;
					}
					else
					{
						BlocKID = pBlock->ID;
						Rev     = pBlock->Rev;
						pCalData += sizeof(US_S_SnrCfg_cal_Block_Header_t);
						pItem  =(US_S_SnrCfg_cal_Item_Header_t*)(pCalData);
						BlockLen -= ((sizeof(US_S_SnrCfg_cal_Block_Header_t)) - (TWO * sizeof(uint32_t)));   /*skip checksum and length self */
						if(BlocKID == (uint32_t)BLOCK_CONFIGURE_ID)
						{
							ItemCnt = ZERO;
							pCalStruct = Cali_Data;
						}
						else if (BlocKID == (uint32_t)BLOCK_HEAD_ID)
						{
							nCal_Data_Veh  = ZERO;
							pCal_Data_Veh = NULL;
							pCalStruct = Cali_Head;
						}
						else
						{
							pCalStruct = Cali_Data;
						}

						while(((BlockLen > ZERO)&&(BlockLen >= (uint32_t)((pItem->Length) + (TWO * sizeof(uint16_t)))))&&(ItemCnt<(uint16_t) MAX_CALI_ITEMS))
						{
							pCalStruct[ItemCnt].BlockId = BlocKID;
							pCalStruct[ItemCnt].Rev = Rev;
							pCalStruct[ItemCnt].ItemID  = pItem->ItemID;
							pCalStruct[ItemCnt].Desc    = pItem->Descr;
							pCalStruct[ItemCnt].ItemData = (void*)pItem;
							BlockLen -= (pItem->Length) + (TWO * sizeof(uint16_t));
							pCalData += (pItem->Length) + (TWO * sizeof(uint16_t));
							pItem  =(US_S_SnrCfg_cal_Item_Header_t*)(pCalData);
							ItemCnt++;
						}

						if((nCal_Data_Veh == ZERO)||(pCal_Data_Veh == NULL))
						{
							for(cnt =0;cnt <TEN; cnt++)
							{
								if((Cali_Head[cnt].BlockId ==(uint32_t) BLOCK_HEAD_ID) &&(Cali_Head[cnt].ItemID == (uint16_t)CAL_HEAD_CFG_ID ))
								{
									pItem = (US_S_SnrCfg_cal_Item_Header_t*)Cali_Head[cnt].ItemData;
									nCal_Data_Veh = (pItem->Length -sizeof(pItem->Descr))/sizeof(uint32_t);
									pCal_Data_Veh = (uint32_t*)(pItem+ONE);
									ItemCnt = ZERO;
									break;
								}
							}

				if((ItemCnt >(uint16_t)0)&&(BlocKID == (uint32_t)BLOCK_CONFIGURE_ID))
							{
								if(pCal_Data_Veh == NULL)
								{
									pCal_Data_Veh = (uint32_t*)pCalDataStart;
								}
								if(nCal_Data_Veh == ZERO)
								{
									nCal_Data_Veh = ONE;
									Cal_Data_Set = ZERO;
								}
							}
							else if(Cal_Data_Set   <  nCal_Data_Veh)
							{
								pCalData = pCalDataStart;
								if(pCal_Data_Veh != NULL)
								{
									pCalData  +=  pCal_Data_Veh[Cal_Data_Set];
									if((((uint32_t)(((uint32_t)Cal_Data_Set)) + ONE)< nCal_Data_Veh)&&(pCalData >=(pCalDataStart + pCal_Data_Veh[Cal_Data_Set + ONE])))
									{
										ret  = CALI_DATA_NOT_CHOSEN;
									}
								}
							}
							else
							{
								ret  = CALI_DATA_NOT_CHOSEN;
							}
						}
						pBlock32 = (uint32_t*)(pCalData);
					}
				}
			}
		}
	 }/* End While*/

     if(ItemCnt >ZERO)
     {
            cal_ver = US_SnrCfg_F_Get_CaliVer();
			if(cal_ver != INVALID_CALI_VER)
			{
				ret = ME_OK;
			}
			else
			{
				ret = CALI_DATA_INVAILID;
			}
     }
    
       return  (uint16_t)ret;
     
}
/* ===========================================================================*/
/**US_SnrCfg_F_Get_CfgData.
* used to get  Calibration data .
* \param BlockID,ItemID, Descr
* \return pointer of calibration data that matches BlockID,ItemID, Descr
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_CfgData
 * Remarks:  DD-ID: {33A35BDF-E70F-48c6-ABBB-A78EDED47DAD}
 * ===========================================================================*/

static void* US_SnrCfg_F_Get_CfgData(uint32_t BlockID,uint32_t Descr,uint16_t ItemID)
{
    void *ret = NULL;
    uint16_t cnt;

    cnt = ZERO;
    while(((Cali_Data[cnt].BlockId != ZERO)&&(Cali_Data[cnt].ItemID != ZERO))&&(cnt<(uint16_t)MAX_CALI_ITEMS))
    {
        if((Cali_Data[cnt].BlockId == BlockID)&&(Cali_Data[cnt].ItemID == ItemID )&&(Cali_Data[cnt].Desc == Descr ))
        {
            ret = Cali_Data[cnt].ItemData;
        }
        cnt++;
    }
    return ret;
}
/* =======================================================================================*/
/**US_SnrCfg_F_Get_CaliItemData.
* used to get  ecu operation mode.
* param BlockID,ItemID, Descr
* return operation mode
* remarks  no remarks
*/
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_CaliItemData
 * Remarks:  DD-ID: {B0A05947-A445-4c43-8C9D-FB6B31E08CD4}
 * ===========================================================================*/
void* US_SnrCfg_F_Get_CaliItemData(uint16_t* Data_Len,uint32_t BlockID,uint32_t Type,uint16_t ItemID)
{
    void* ret = NULL;
    US_S_SnrCfg_cal_Item_Header_t *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData(BlockID,Type,ItemID);
    if(Block != NULL)
     {
         ret = (void*)&Block[ONE];
         *Data_Len    = (uint16_t)(Block->Length - sizeof(uint32_t));
     }
     else
     {
     	*Data_Len = ZERO;
     }
    return ret;
}

/* =======================================================================================*/
/**US_SnrCfg_Get_SectorEdgeCfg.
* used to get  ecu operation mode.
* \param BlockID,ItemID, Descr
* \return operation mode
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_Get_SectorEdgeCfg
 * Remarks:  DD-ID:{018980B4-2BC5-433d-BD7D-9C8E7A54F5E5}
 * ===========================================================================*/

void* US_SnrCfg_Get_SectorEdgeCfg(uint16_t* len)
{
    void* ret = NULL;
    US_S_SnrCfg_cal_Item_Header_t *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,SECTOREDGECFG_ID);
    if(Block != NULL)
    {
        ret = (void*)&Block[ONE];
        *len    = (uint16_t)(Block->Length - sizeof(Block->Descr));	
    }
    else
    {
    	*len = ZERO;
    }

    return ret;
}

/* =======================================================================================*/
/**US_SnrCfg_Get_SectorEdgeCfg.
* used to get  ecu operation mode.
* \param BlockID,ItemID, Descr
* \return operation mode
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:     US_SnrCfg_Get_ZoneBoundsCfg
 * Remarks:  DD-ID:{787CB594-395C-47aa-93FB-EE38133C1229}
 * ===========================================================================*/
void* US_SnrCfg_Get_ZoneBoundsCfg(uint16_t* len)
{
	void* ret = NULL;
    US_S_SnrCfg_cal_Item_Header_t *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,ZONEBOUNDCFG_ID);
     if(Block != NULL)
     {
         ret = (void*)&Block[ONE];
         *len    =(uint16_t)( Block->Length - sizeof(Block->Descr));		
     }
     else
     {
     	*len = ZERO;
     }
    return ret;
}

/* =======================================================================================*/
/**US_SnrCfg_Get_SectorEdgeCfg.
* used to get  ecu operation mode.
* \param BlockID,ItemID, Descr
* \return operation mode
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_Get_KinematicCfg
 * Remarks:  DD-ID:{9042A196-F7E6-4e8d-BDF5-5C42BA48809C}
 * ===========================================================================*/

void* US_SnrCfg_Get_KinematicCfg(uint16_t* len)
{
    void* ret = NULL;
    US_S_SnrCfg_cal_Item_Header_t *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,KINEMATIC_ID);
    if(Block != NULL)
    {
        ret = (void*)&Block[ONE];
        *len    = (uint16_t)(Block->Length - sizeof(Block->Descr));		
    }
    else
    {
    	*len = ZERO;
    }

    return ret;
}

/* ======================================================================================*/
/**US_SnrCfg_Get_OperationMode.
* used to get  ecu operation mode.
* \param BlockID,ItemID, Descr
* \return operation mode
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrCfg_Get_OperationMode
 * Remarks:  DD-ID: {741E00E6-F6B3-4db6-86C4-0BE75EFBEFBF}
 * ===========================================================================*/
uint8_t US_SnrCfg_Get_OperationMode(void)
{
    uint8_t ret = ZERO;
    US_S_ECU_Operation_Mode_t const *OperationMode;
    US_S_SnrCfg_cal_Item_Header_t const *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,ECU_OPERATION_MODE_ID);
    if(Block != NULL)
    {
        OperationMode = (US_S_ECU_Operation_Mode_t*)&Block[ONE];
        ret    = OperationMode->ECU_Operation_Mode;
    }

    return ret;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Get_SnrPN.
* used to get  Calibration data version.
* \param BlockID,ItemID, Descr
* \return pointer of calibration data that matches BlockID,ItemID, Descr
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_SnrPN
 * Remarks:  DD-ID: {E28BA9B8-E431-4082-8275-C042030064FD}
 * 
 * ===========================================================================*/
uint8_t* US_SnrCfg_F_Get_SnrPN(void)
{
    uint8_t *SnrPN = NULL;
    US_S_SnrCfg_cal_Item_Header_t *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,SENSOR_TYPE_PN_CFG_ID);
    if(Block != NULL)
    {
       SnrPN= (uint8_t*)((uint8_t*)Block + sizeof(US_S_SnrCfg_cal_Item_Header_t));
    }
    return SnrPN;
}
/* ===========================================================================*/
/**US_SnrCfg_F_Get_CaliVer.
* used to get  Calibration data version.
* \param BlockID,ItemID, Descr
* \return pointer of calibration data that matches BlockID,ItemID, Descr
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_CaliVer
 * Remarks:  DD-ID: {57BC706F-922A-4d81-A8BD-47140A79800E}
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Get_CaliVer(void)
{
    uint32_t Cal_ver = INVALID_CALI_VER;
    US_S_SnrCfg_cal_Item_Header_t const *Block;
    Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,CALIBRATION_VER_ID);
    if(Block != NULL)
    {
       Cal_ver= *(uint32_t*)((uint8_t*)Block + sizeof(US_S_SnrCfg_cal_Item_Header_t));
    }
    return Cal_ver;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Get_CfgVer block version.
* used to get  Calibration data  block version.
* \param BlockID
* \return pointer of calibration data that matches BlockID,ItemID, Descr
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_CfgVer
 * Remarks:  DD-ID: {C86F45C0-3489-466a-BA46-B9119B10AF4A}
 * ===========================================================================*/

static uint16_t US_SnrCfg_F_Get_CfgVer(uint32_t BlockID)
{

    uint16_t ret=ME_OK,cnt;

    cnt = ZERO;
    while(((Cali_Data[cnt].BlockId != ZERO)&&(Cali_Data[cnt].ItemID != ZERO))&&(cnt<(uint16_t)MAX_CALI_ITEMS))
    {
        if(Cali_Data[cnt].BlockId == BlockID)
        {
            ret = Cali_Data[cnt].Rev;
        }
        cnt++;
    }
    return ret;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Get_CalData.
* used to Get Cal data.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_GetCalData
 * Remarks:  DD-ID: {618F15B5-35D0-40a3-BA06-56E0A7892E6A}
 * Traceability to source Code: Req.-ID:  16134127
 * ===========================================================================*/
  uint16_t US_SnrCfg_F_GetCalData(uint16_t ReTrival)
{
  static uint16_t cali_data_retry = ZERO;
  uint8_t nOffset;
  uint16_t nBus,cnt;
  uint32_t temp,ret = ME_OK;
  float32_t *pOffset= NULL;
  US_S_SnrCfg_cal_Item_Header_t *Block;
  if(ReTrival == (uint16_t)ME_TRUE)
  {
	ret = US_SnrCfg_F_Check_CfgData();
  }
  if(ret == ME_OK)
  {
		Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,(uint32_t)gSensorCfg,SENSOR_MAP_CFG_ID);
		if(Block != NULL)
		{
             /*JL-QAC Fix : Need to suppress,*/
			(void)memcpy((void*)&US_SnrCfg_SnrCfg,(void*)((uint8_t*)Block + sizeof(US_S_SnrCfg_cal_Item_Header_t)), sizeof(US_SnrCfg_SnrCfg)- sizeof(pUS_S_Sensor_coordinate_t)); 
			if(US_SnrCfg_F_Get_CfgVer((uint32_t)BLOCK_CONFIGURE_ID) >= (uint16_t)0x101)
			{
				(void)memcpy((uint8_t*)SnrCoordinate,(uint8_t*)((uint8_t*)Block + sizeof(US_S_SnrCfg_cal_Item_Header_t) + sizeof(US_SnrCfg_SnrCfg)- sizeof(pUS_S_Sensor_coordinate_t)),sizeof(SnrCoordinate));
		        Block = (US_S_SnrCfg_cal_Item_Header_t*)US_SnrCfg_F_Get_CfgData((uint32_t)BLOCK_CONFIGURE_ID,ZERO,SENSOR_OFFSET_CFG_ID);
                if(Block != NULL)
				{
					nOffset = *(uint8_t*)((uint8_t*)Block + sizeof(US_S_SnrCfg_cal_Item_Header_t));
					pOffset = (float32_t*)((uint8_t*)Block + sizeof(US_S_SnrCfg_cal_Item_Header_t)+sizeof(uint32_t));
					if(US_x_offset_index < nOffset)
					{
						for(cnt = ZERO; cnt < SIX; cnt++)
						{
						   SnrCoordinate[cnt].fX += pOffset[US_x_offset_index * 2u];            /*front sensors */
						   SnrCoordinate[cnt+ SIX].fX += pOffset[(US_x_offset_index * 2u )+ ONE];      /*rear sensors */
						}
					}
				}
				US_SnrCfg_SnrCfg.pSnrCoordinate = (US_S_Sensor_coordinate_t*)SnrCoordinate;
			}
			else
			{
				US_SnrCfg_SnrCfg.pSnrCoordinate = NULL;
			}
			if((US_SnrCfg_SnrCfg.Max_nSnr_ON_SINGLE_BUS != ZERO)&&(US_SnrCfg_SnrCfg.SnrMap != ZERO)&&(US_SnrCfg_SnrCfg.nBusCfg != ZERO))
			{
				(void)memset(US_SnrCfg_nSensor,0,EIGHT*TWO);
                for(nBus = ZERO; nBus<US_SnrCfg_SnrCfg.nBusCfg; nBus++ )
				{
					for(cnt = ZERO; cnt<US_SnrCfg_SnrCfg.Max_nSnr_ON_SINGLE_BUS; cnt++ )
					{
						temp = US_SnrCfg_SnrCfg.SnrMap >> ((US_SnrCfg_SnrCfg.Max_nSnr_ON_SINGLE_BUS * nBus )+ cnt);
						if((temp & BIT0) == (uint32_t)ME_TRUE)
						{
							US_SnrCfg_nSensor[nBus][ZERO]++;
						}
					}
				}
				US_SnrDrvCom_F_SetCalCfg();
                /* TODO JWR: Move these to Mgr, change a state, etc */
				UssOdo_OdometryInit();
				(void)UssCtrl_GetSnrCfgIndex();
				UssOD_InitCalData();
                /*end of TODO*/
  			    ret = ME_OK;
			}
			else
			{
				ret  = CALI_DATA_INVAILID;
			}
		}
		else
		{
			ret  = CALI_DATA_INVAILID;
		}
	}
	if(ret  == ME_OK)
	{ 
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_NO_CALI_DATA);/*KPK-Reason Code */
		  cali_data_retry = ZERO;
	}
	else
	{
		 if(cali_data_retry > MAX_CAL_IPC_TIME){
		     US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_NO_CALI_DATA);/*KPK-Reason Code */
			 ret = ME_OK;
		 }
		 else{
			 cali_data_retry++;
		 }
	}
    return  (uint16_t)ret;

}
/* ===========================================================================*/
/**US_SnrCfg_F_Get_SnrCfg.
* used to Init Sensor MAP cfg.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Init
 * Remarks:  DD-ID: {847D0CA8-C29E-4afc-AD82-0EB25288CF23}
 * Req.-ID: 13396023
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Init(void)
{
    uint32_t ret = ME_ERROR;
    (void)memset(US_SnrCfg_nSensor,0,EIGHT*TWO);
    (void)memset((void*)&US_SnrCfg_SnrCfg,0,sizeof(US_SnrCfg_SnrCfg));
	(void)memset(Cali_Data,0, MAX_CALI_ITEMS * sizeof(US_S_SnrCfg_Cali_Data_t));      /*set all data to ZERO */
    (void)memset(Cali_Head,0, 10U * sizeof(US_S_SnrCfg_Cali_Data_t));
    (void)memset(SnrCoordinate,0, MAX_NUM_SENSORS * sizeof(US_S_Sensor_coordinate_t));
    (void)memset(US_SnrCfg_reset_reason,0,MAX_NUM_SENSORS * sizeof(uint16_t));
    nCal_Data_Veh = ZERO;  
    USS_PowerON = ME_TRUE; 
   return ret;
}
/* ===========================================================================*/
/**US_SnrCfg_F_Set_CalData.
* used to Init Sensor MAP cfg.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Set_CalData
 * Remarks:  DD-ID: {782549C4-2587-41fa-97BC-436C2322ABCF}
 * ===========================================================================*/
static uint16_t US_SnrCfg_F_Set_CalData(uint16_t nCal) 
{
	  uint16_t ret = ME_OK;
	  if((Cal_Data_Set != nCal)||(nCal == (uint16_t)0xffffu))
	  {
		  if(nCal == (uint16_t)0xffffu)
		  {
			 ret = US_SnrCfg_F_GetCalData(ME_FALSE);
		  }
		  else
		  {
	         Cal_Data_Set = nCal;
		  	 ret = US_SnrCfg_F_GetCalData(ME_TRUE);
		  }
		  uUsed_Cal_Data_Set = Cal_Data_Set;
	  }
	  if(ret == ME_OK)
	  {
		  UssCtrl_TriggerSnrCfg();
	  }
	return ret;
}
/* ===========================================================================
 * Name:     US_SnrCfg_Set_gNumSensorsCfg
 * Remarks:  DD-ID:{35F2C1B0-D7A4-4906-AE0B-FA824326ED77}
 * ===========================================================================*/
void US_SnrCfg_Set_gNumSensorsCfg(uint8_t NumofSensor,uint16_t Variant,uint16_t offset_index)
{
    uint16_t sVariant;
	if((Cal_Data_Set == Variant)&&((NumofSensor != gSensorCfg)||(US_x_offset_index != offset_index)))
	{
	   sVariant = 0xffffu;
	}
 	else
	{
	   sVariant = Variant;
	}
	gSensorCfg = NumofSensor;
	US_x_offset_index =(uint8_t) offset_index;
	(void)US_SnrCfg_F_Set_CalData(sVariant);
}

/* ===========================================================================*/
/**GetTemperatureCfg.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 GetTemperatureCfg
 * Remarks:  DD-ID: {FA967886-A3B1-4eb0-A794-3E58412CFB2F}
 * Req.-ID:  14993481
 * ===========================================================================*/
US_S_TemperatureCompensation_t* GetTemperatureCfg(void) 
{
    US_S_TemperatureCompensation_t *pTempCompcfg = NULL;
    US_S_SnrCfg_cal_Item_Header_t *Block;

    Block = (US_S_SnrCfg_cal_Item_Header_t*) US_SnrCfg_F_Get_CfgData(
            (uint32_t)BLOCK_TUNE_ID, ZERO, TEMPCOMP_CFG_ID);
   if(Block != NULL)
   {
       pTempCompcfg = (US_S_TemperatureCompensation_t*)((uint8_t*) Block + sizeof(US_S_SnrCfg_cal_Item_Header_t));
       
   }
   return pTempCompcfg;
}
/* ===========================================================================*/
/**US_SnrCfg_F_Get_SnrCfg.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_SnrCfg
 * Remarks:  DD-ID: {C5DA5A26-7FDA-47c4-9E71-F10E17FF254D}
 * ===========================================================================*/
US_S_SensorsCfg_t* US_SnrCfg_F_Get_SnrCfg(void)
{

    return &US_SnrCfg_SnrCfg;
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_SnrCfg_F_Range_Check.
* used to check STC or STG over range.
* \param Value: STC or STG value, Limit: limit value
* \return STC or STG value with limited
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Range_Check
 * Remarks:  DD-ID: {36CCDD00-32DE-494c-8230-7857BED24C92}
 * ===========================================================================*/

static uint8_t US_SnrCfg_F_Range_Check(int16_t Value,int16_t Limit)  
{
  uint8_t ret;

  if(Value<0)
  {
      ret = ZERO;
  }
  else if(Value>Limit)
  {
      ret =(uint8_t) Limit;
  }
  else
  {
      ret = (uint8_t)Value;
  }
  return ret;
}
/* ===========================================================================*/

/**US_SnrCfg_F_Get_uSnrID.
* get sensor ID.
* \param uint8_t Sensor index.
* \return uint32_t Sensor ID.
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_uSnrID
 * Remarks:  DD-ID: {9030BA66-27E5-4b52-BCCF-94619ADB4DFA}
 * Req.-ID: 13410142
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Get_uSnrID(uint8_t uSnrIdx)
{
    return US_SnrCfg_SensorID[uSnrIdx];
}
#endif
/* ===========================================================================*/
/**US_SnrCfg_F_Get_uSnrIDList.
* get sensor ID.
* \param none
* \return uint32_t Pointer to Sensor ID List;
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_uSnrIDList
 * Remarks:  DD-ID: {FE415007-D265-4389-8A5E-C5DE8DE5952A}
 * Req.-ID: 13410142
 * ===========================================================================*/
uint32_t * US_SnrCfg_F_Get_uSnrIDList(void)
{
    return US_SnrCfg_SensorID;
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_SnrCfg_F_Get_uNewSnrID.
* get sensor ID.
* \param uint8_t Sensor index.
* \return uint32_t Sensor ID.
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_uNewSnrID
 * Remarks:  DD-ID: {2B918851-A08E-4aaa-ADBF-2AEF22A543DE}
 * ===========================================================================*/
uint64_t US_SnrCfg_F_Get_uNewSnrID(uint8_t uSnrIdx)
{
    return US_SnrCfg_NewSensorID[uSnrIdx];
}
#endif
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Get_uNewSnrIDList
 * Remarks:  DD-ID: {B89E516C-4204-4d2e-9467-305504D0D906}
 * Req.-ID:13410142
 * ===========================================================================*/
uint64_t * US_SnrCfg_F_Get_uNewSnrIDList(void)
{
    return US_SnrCfg_NewSensorID;
}

/* ===========================================================================
 * Name:	 US_SnrCfg_F_bPopulateSnrSensitivity
 * Remarks:  DD-ID: {FC8DCBEA-E946-44ce-9662-C98F0811BD28}
 * ===========================================================================*/
bool_t US_SnrCfg_F_bPopulateSnrSensitivity(void)
{
    return bPopulateSensorSensitivity;
}

/* ===========================================================================
 * Name:	 US_SnrCfg_F_ClrPopulateSnrSensitivityFlag
 * Remarks:  DD-ID: {12206C76-4085-48c1-B46F-0A54B951F98A}
 * ===========================================================================*/
void US_SnrCfg_F_ClrPopulateSnrSensitivityFlag(void)
{
    bPopulateSensorSensitivity = ME_FALSE;
}

/* ===========================================================================
 * Name:	 US_SnrCfg_Get_NoiseReaction
 * Remarks:  DD-ID: {1ED4D566-18E4-4570-94B6-F1CE1F07EADE}
 * Req.-ID: 13424090
 * ===========================================================================*/
/* Placeholder for future calibration get function */
/*\TODO - update when this is  in calibration*/
UssMgr_E_NoiseReaction_t US_SnrCfg_Get_NoiseReaction(void)
{
    return SYSMGR_NOISEREACT_DYN_CHIRP;
}

/* ===========================================================================
 * Name:	 US_SnrCfg_F_AutoAddressCheck
 * Remarks:  DD-ID:{F6B7D04F-7C5F-4d43-A3B1-9EF2A7E7F550}
 * Req.-ID:
 * ===========================================================================*/

uint16_t US_SnrCfg_F_AutoAddressCheck(uint16_t *RcvData)
{
	 uint16_t cnt,len,temp,ret = ME_OK,chn_status;
	 uint32_t SnrMap;
	 len = RcvData[ZERO];
	 chn_status = US_SnrDrv_GetChnStatus();
	 SnrOpModeMask = ZERO;
     if(len == (uint16_t)((((uint16_t)US_SnrCfg_SnrCfg.nBusCfg)) * TWO))
     {
          temp = ZERO;
         for(cnt = ZERO;cnt < US_SnrCfg_SnrCfg.nBusCfg; cnt++  )
         {
             US_SnrCfg_nSensor[cnt][ONE] =(uint8_t)(RcvData[cnt+ONE] & 0xfu);
             if(US_SnrCfg_nSensor[cnt][ZERO] != US_SnrCfg_nSensor[cnt][ONE])
             {
                 temp ++;
             }
         }
         if((temp == ZERO)||(chn_status != DSI3_CHANNEL_ENABLED))
         {
             US_Install_SnrMap = US_SnrCfg_SnrCfg.SnrMap;
             ret = ME_OK;                    /*All Sensors are installed */
             US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_CFG_SENSOR_ERR);
         }
         else
         {
        	 US_Install_SnrMap = ZERO;
				ret = (uint16_t)SNR_DIAG_FLG_SENSOR_DISCONNECT;
              for(cnt =ZERO;cnt< US_SnrCfg_SnrCfg.nBusCfg; cnt++)
              {
                  SnrMap = ZERO;
                  for(temp = ZERO;temp<US_SnrCfg_nSensor[cnt][ONE];temp++ )
                  {
                          SnrMap |= ((uint32_t)(((uint32_t)BIT0)<<temp));
                  }
                  SnrMap <<= cnt * US_SnrCfg_SnrCfg.Max_nSnr_ON_SINGLE_BUS;
                  US_Install_SnrMap |=  SnrMap;
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)||((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
	              if(US_SnrCfg_nSensor[cnt][ZERO] < US_SnrCfg_nSensor[cnt][ONE])
				 {
		                ret = (uint16_t)DIAG_FLAG_ECU_CFG_SENSOR_ERR;
				 }
#endif
              }
				if((USS_PowerON != (uint8_t)ME_FALSE)&&(ret == (uint16_t)DIAG_FLAG_ECU_CFG_SENSOR_ERR))  
				{
		             US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_CFG_SENSOR_ERR);       
				}
         }
     }
     else
     {
          ret = (uint16_t)SNR_DIAG_FLG_SENSOR_DISCONNECT;
     }
     return ret;
}


/* ===========================================================================
 * Name:     US_SnrCfg_F_Get_SnrBusMap
 * Remarks:  DD-ID:{CA75AC01-59A6-4473-8A75-5D6989179081} 
 * ===========================================================================*/
uint32_t US_SnrCfg_F_Get_SnrBusMap(uint16_t position)
{
    uint32_t map,map_ch,mask;
    uint8_t cnt;
    map = ZERO;
	map_ch = ZERO;
    for(cnt=ZERO; cnt<US_SnrCfg_SnrCfg.Max_nSnr_ON_SINGLE_BUS; cnt ++)
    {
	    map_ch |= ((uint32_t)(((uint32_t)BIT0)<<cnt));
    }
    for(cnt=ZERO; cnt<US_SnrCfg_SnrCfg.nBusCfg; cnt ++)
    {
		map |= (map_ch<<(cnt*US_SnrCfg_SnrCfg.Max_nSnr_ON_SINGLE_BUS));
    }
    mask = (uint32_t)position;
	if(position == US_ALL_POS)
    {
		mask =(~mask);
    }
	map = map&mask;
    return map;
}
