/** /file US_Stub_Input.c
 *  /version 1.00
 *  /date 2013-06-05
 *  /author Amol Gore 
 *  /brief This file contains platform specific input interfaces.
 *
 *  /copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "US_ComOutputBuffer_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_Hsd_Global.h"
#include "VoltageCurrent_data.h"
#include "US_Stub_IfMap.h"
#include "US_PlatformCfg_Global.h"

/************************************************************************************************************************
                                                            Imported data
************************************************************************************************************************/

/************************************************************************************************************************
                                                            Local #defines
************************************************************************************************************************/

#if(USS_FEATURE_INPUT_PROCESS_AMBIENT_TEMP == US_FEATURE_ON)
	#define US_RANGE_MAX_AMBIENT_TEMP_IN_CELSIUS (170.0f)
	#define US_RANGE_MIN_AMBIENT_TEMP_IN_CELSIUS (-85.0f)
#endif

#if(USS_FEATURE_INPUT_PROCESS_VEH_SPEED == US_FEATURE_ON)
	#define US_RANGE_MAX_VEH_SPEED_IN_KM_PH (511.875f)
	#define US_RANGE_MIN_VEH_SPEED_IN_KM_PH (0.0f)
	#define US_RANGE_SNA_VEH_SPEED_IN_KM_PH (0x1FFF)
#endif

#if(USS_FEATURE_INPUT_PROCESS_GEAR == US_FEATURE_ON)
	#define US_RANGE_ENUM_GEAR_ENGAGED_NEUTRAL    (0x0U)
	#define US_RANGE_ENUM_ENGAGED_1_FWD_GEAR (0x1U)
	#define US_RANGE_ENUM_ENGAGED_2_FWD_GEAR (0x2U)
	#define US_RANGE_ENUM_ENGAGED_3_FWD_GEAR (0x3U)
	#define US_RANGE_ENUM_ENGAGED_4_FWD_GEAR (0x4U)
	#define US_RANGE_ENUM_ENGAGED_5_FWD_GEAR (0x5U)
	#define US_RANGE_ENUM_ENGAGED_6_FWD_GEAR (0x6U)
	#define US_RANGE_ENUM_ENGAGED_7_FWD_GEAR (0x7U)
	#define US_RANGE_ENUM_ENGAGED_8_FWD_GEAR (0x8U)
	#define US_RANGE_ENUM_ENGAGED_9_FWD_GEAR (0x9U)
	#define US_RANGE_ENUM_ENGAGED_PARK       (0xDU)
	#define US_RANGE_ENUM_ENGAGED_REV_GEAR   (0xEU)
	#define US_RANGE_ENUM_ENGAGED_SNA        (0xFU)
#endif

/************************************************************************************************************************
                                                            Global Variables
************************************************************************************************************************/
uint32_t US_CalData[15000+2700+10] ={0};
USS_Calibration_Data_t *US_CalData0;
USS_Calibration_data_2_t *US_CalData1;
extern USS_PowerSelect_t Dsi3BusPowerReq;

#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
float32_t g_LAUD_fExternalTemp = 0.0f;
uint8_t g_LAUD_bHardcodeTemp = 0;
#endif

/************************************************************************************************************************
                                                            Local Variables
************************************************************************************************************************/
static US_S_MarriageSensorIDs_t US_sMarriageSensordata={0};	
static uint8_t *CalData = NULL;
static  ME_ProxiToMCU2_1_Def_t *pProxi = NULL;
static uint8_t uReadType = ZERO;  /* ONE == Simulate already written NVM, TWO == Simulate unwritten NVM*/
static uint16_t TuningCmdSeqID;


/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
void Enable_ReCfgSensor(uint8_t enable); 
void RePlayDataReady(bool_t Ready);
void US_StubOuput_Init(void);
uint8_t US_Com_GetHsdPwrChannel_A(void);
uint8_t US_Com_GetHsdPwrChannel_B(void);
void ME_US_F_RegisterDataCopyCallBackInput(void);
void UssCom_F_InputDataShareMain(void);
uint16_t US_F_Get_DynamicCalMsgID(void);

/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/
static void US_Com_GetProxi(void);
static void US_Get_DynamicCalData(const UssTunningData_mcu1_0_t * const sUSS_DynamicCalData);

/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

/**
 * /brief This function reads the proxy data.
 * 
 */
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_HD)
	#define WHEEL_BASE_0                (0u)
	#define WHEEL_BASE_1                (3u)
	#define WHEEL_BASE_INVALID          (0xffffu)
	#define WHEEL_BASE_3                (1u)
	#define WHEEL_BASE_4                (3u)
	#define WHEEL_BASE_5                (2u)
	#define WHEEL_BASE_6                (0u)
	#define WHEEL_BASE_7                (2u)
	#define WHEEL_BASE_8                (1u)
	#define WHEEL_BASE_9                (4u)
	#define WHEEL_BASE_10               (6u)
	#define WHEEL_BASE_11               (8u)
	#define WHEEL_BASE_12               (5u)
	#define WHEEL_BASE_13               (7u)


	const static uint16_t Sensor_offset[] = {WHEEL_BASE_0,WHEEL_BASE_1,WHEEL_BASE_INVALID,WHEEL_BASE_3,WHEEL_BASE_4,WHEEL_BASE_5,
	                                WHEEL_BASE_6,WHEEL_BASE_7,WHEEL_BASE_8,WHEEL_BASE_9,WHEEL_BASE_10,WHEEL_BASE_11,
									WHEEL_BASE_12,WHEEL_BASE_13};
#endif 
/* ===========================================================================
 * Name: US_Com_GetProxi    
 * Remarks:  DD-ID: {F8125D4B-75CC-41dd-ABF0-43E4E766A6F1} 
 * ===========================================================================*/

static void US_Com_GetProxi(void)
{
	uint8_t NumofSensor;
	uint16_t Variant, offset_index;

	NumofSensor = 12u;         /* PRQA S 2982 */
	Variant = ZERO;                       /* PRQA S 2982 */
	offset_index = ZERO;          /* PRQA S 2982 */
	if(pProxi == NULL)
	{
	    pProxi = UsStubInput_ReadIf_Proxy();
		if(pProxi != NULL)
		{
		   if( pProxi->PRX_bValid_b ==(boolean) ME_TRUE)
		  {
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS)
				if((pProxi->PRX_FullAutoPrkgSys_b == TRUE) || (pProxi->PRX_PAMTunSet_u8 == FOUR))
		        { 
				   NumofSensor = TWELVE;
			    }
			    else
			    {
				   NumofSensor = TEN; 
			    }

			  if((pProxi->PRX_Wheelbase_u8 == ONE)&&(pProxi->PRX_PAMTunSet_u8 >= TWO)&&(pProxi->PRX_PAMTunSet_u8 <= FOUR)) 
			  {
				  if(pProxi->PRX_PAMTunSet_u8 < FIVE)
				  {	 
				     Variant = (uint16_t)pProxi->PRX_PAMTunSet_u8 + ONE;
				  }
				  else if(pProxi->PRX_PAMTunSet_u8 == FIVE)
				  {
					  Variant = ONE;
				  }
				  else
				  {
					  Variant = ONE;
				  }
				  
			  }
			  else if(pProxi->PRX_Wheelbase_u8 < FOUR)
			  {
				  Variant = (uint16_t)pProxi->PRX_Wheelbase_u8;
			  }
			  else
			  {
					  Variant = ONE;
			  }
#elif(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_HD)

               if((pProxi->PRX_Body_Types  == TWO )||(pProxi->PRX_Body_Types  == FIVE))   /* DD & DP*/
				{
					 Variant = ONE;
				}
				else
				{
					Variant = ZERO;           /*D2 & DJ*/
				}
				if((pProxi->PRX_Dual_Rear_Wheel_prsnt == (boolean)ME_TRUE) && (pProxi->PRX_PAMCfg_b == (boolean)ME_TRUE))
				{
					NumofSensor = TWELVE;
				}
				else if((pProxi->PRX_Dual_Rear_Wheel_prsnt ==(boolean) ME_FALSE) && (pProxi->PRX_PAMCfg_b ==(boolean) ME_TRUE))
				{
					NumofSensor = TEN; 
				}
				else if((pProxi->PRX_Dual_Rear_Wheel_prsnt == (boolean)ME_TRUE) && (pProxi->PRX_PAMCfg_b ==(boolean) ME_FALSE))
				{
					NumofSensor = SIX; 
				}
				else if((pProxi->PRX_Dual_Rear_Wheel_prsnt ==(boolean)ME_FALSE) && (pProxi->PRX_PAMCfg_b == (boolean)ME_FALSE))
				{
					NumofSensor = FOUR; 
				}
				else
				{
					NumofSensor = TWELVE;
				}

				if(pProxi->PRX_Wheelbase_u8 < (sizeof(Sensor_offset)/sizeof(uint16_t)))
				{
				   offset_index = Sensor_offset[pProxi->PRX_Wheelbase_u8];
				}
				else
				{
					offset_index = WHEEL_BASE_INVALID;
				}
			  
#elif(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_BEV)

			  if(pProxi->PRX_FullAutoPrkgSys_b == TRUE) 
		      { 
				   NumofSensor = TWELVE;
			  }
			  else
			  {
				   NumofSensor = TEN; 
			  }
			  if(pProxi->PRX_Wheelbase_u8 == ONE) 
			  {
				  if(pProxi->PRX_PAMTunSet_u8 == ONE)
				  {	 
				     Variant = ZERO;
				  }
				  else if(pProxi->PRX_PAMTunSet_u8 == FOUR)
				  {
					  Variant = ONE;
				  }
				  else
				  {
					  Variant = ZERO;
				  }
				  
			  }
			  else
			  {
			    Variant = ZERO;
			  }

#endif
			  US_SnrCfg_Set_gNumSensorsCfg(NumofSensor,Variant,offset_index);
		  }
		  else
		  {
			pProxi = NULL;
		  }
		}
	}else{}
}
/**
 * \brief This function reads the ultrasonic sensor calibrations data
 * DD-ID: 
 * \return uint8_t* 
 */
/* ===========================================================================
 * Name: US_Get_DynamicCalMsgID     
 * Remarks:  DD-ID: {B251185E-D745-4efe-9CDF-F39C82C7C378}
 * ===========================================================================*/
uint16_t US_Get_DynamicCalMsgID(void) 
{
	return TuningCmdSeqID;
}


/**
 * \brief This function reads the ultrasonic sensor calibrations data
 * 
 * \return uint8_t* 
 */
uint8_t *US_Get_CalNVMData(void)      
{
   static bool_t bValid1 = ME_FALSE;
   static bool_t bValid2 = ME_FALSE;
 /*comment out   uint16_t max_cnt;*/
   uint8_t *ret =NULL;
   USS_Calibration_Data_t *pCAlProvideDef = NULL;
   USS_Calibration_data_2_t *pCAlProvideDef2 = NULL;
/*  comment out  max_cnt = ZERO;*/

  /*    do{ */
 		if((bValid1 ==(bool_t) ME_FALSE)||(bValid2 == (bool_t)ME_FALSE))
	    {
		  if(bValid1 == (bool_t)ME_FALSE)
			{
				pCAlProvideDef = UsStubOutput_RefIf_CalibData();
				if((pCAlProvideDef->uss_caldata_start == 0x5A5Au)&&(pCAlProvideDef->uss_caldata_end == 0xA5A5u))
				{
					(void)memcpy((void*)&US_CalData[0],&pCAlProvideDef->CalData[0],4u*15000u); /* PRQA S 1495, 1496,0314 */
					bValid1 =(bool_t) ME_TRUE;
				}
				else
				{
					bValid1 =(bool_t) ME_FALSE;
				}
			}	
			if(bValid2 == (bool_t)ME_FALSE)
			{
				pCAlProvideDef2 = UsStubOutput_RefIf_CalibData_2();
				if((pCAlProvideDef2->uss_caldata_start == 0x5A5Au)&&(pCAlProvideDef2->uss_caldata_end == 0xA5A5u))
				{
					(void)memcpy((void*)&US_CalData[15000u],&pCAlProvideDef2->CalData[0],4u*2700u); /* PRQA S 1495, 1496,0314 */
					bValid2 = (bool_t)ME_TRUE;
				}
				else
				{
					bValid2 = (bool_t)ME_FALSE;
				}
			}

			if((bValid1 !=(bool_t) ME_FALSE)&&(bValid2 != (bool_t)ME_FALSE))
			{
				ret = (uint8_t*)US_CalData;
			}
		}
		else{
		  		ret = (uint8_t*)US_CalData;
		}
		if(pProxi == NULL)
        {
			US_Com_GetProxi();
		}			
      return ret;
}


/**
 * \brief This function read the saved senosor marraige id.
 * 
 */
/* ===========================================================================
 * Name: US_Read_MarriageSensorID    
 * Remarks:  DD-ID: {FAF9AA53-98AF-4232-AFE4-9FCD1342315A} 
 * ===========================================================================*/
uint32_t US_Read_MarriageSensorID(void)   
{
    uint16_t ret = ME_OK;
 /*comment out 	uint16_t max_cnt;
comment out 	max_cnt = ZERO;*/
	if(US_sMarriageSensordata.bValid == (bool_t)ME_FALSE)
	{
			UsStubInput_ReadIf_MarriageSnrId(&US_sMarriageSensordata);
			if(US_sMarriageSensordata.bValid ==(bool_t) ME_FALSE)
			{
					ret = ME_NOT_OK;
			}
			else{
				/* DO nothing */
			}
	}
	else{
		/* DO nothing */
	}
	return ret;
}

	
/**
 * \brief This function copies sensor marraige data based on read type
 * 
 * \param data 
 * \return uint16_t 
 */
/* ===========================================================================
 * Name: NVMRead_SensorMarriage    
 * Remarks:  DD-ID: {70977843-315E-48b9-ACBD-76B4F24EE59D}
 * ===========================================================================*/
uint16_t NVMRead_SensorMarriage(US_S_MarriageSensorIDs_t *data)    /*PRQA S 3408 */
{
	US_S_MarriageSensorIDs_t *pNvmSensorIDs = &US_sMarriageSensordata;
	
    if (uReadType == ONE)
    {
        pNvmSensorIDs->uSavedSensorIDs[0] = 0xd0011381u;
        pNvmSensorIDs->uSavedSensorIDs[1] = 0xd0011383u;
        pNvmSensorIDs->uSavedSensorIDs[2] = 0xd0011415u;
        pNvmSensorIDs->uSavedSensorIDs[3] = 0xd0011375u;
        pNvmSensorIDs->uSavedSensorIDs[4] = 0xd0011392u;
        pNvmSensorIDs->uSavedSensorIDs[5] = 0xd0011380u;

        pNvmSensorIDs->uSavedSensorIDs[6] = 0xd0011406u;
        pNvmSensorIDs->uSavedSensorIDs[7] = 0xd0011425u;
        pNvmSensorIDs->uSavedSensorIDs[8] = 0xd0011382u;
        pNvmSensorIDs->uSavedSensorIDs[9] = 0xd0011379u;
        pNvmSensorIDs->uSavedSensorIDs[10]= 0xd0011396u;
        pNvmSensorIDs->uSavedSensorIDs[11]= 0xd0011430u;


        pNvmSensorIDs->uMarriageStatus = ((uint32_t) 9931u << SIXTEEN) | 3u;

        uReadType = ZERO;
    }
    else if (uReadType == TWO)
    {
       (void) memset(pNvmSensorIDs, 0, sizeof(US_S_MarriageSensorIDs_t));
        uReadType = ZERO;
    }
else{
   /* empty */
}
   (void) memcpy(data, pNvmSensorIDs, sizeof(US_S_MarriageSensorIDs_t));

    return ME_OK;
}


/**
 * \brief This function read the kinematic data
 * 
 * \param pKinematicData 
 */
/* ===========================================================================
 * Name: US_Com_GetKinematicData    
 * Remarks:  DD-ID: {152F9A92-6696-4b28-90ED-241DC20CBAB4}
 * ===========================================================================*/
void US_Com_GetKinematicData(IKinematicData_t *pKinematicData)
{
    UsStubInput_ReadIf_IKinematicData(pKinematicData);
}


/**
 * \brief This function return the  status of power on/off request of Uss high side channel A/0 
 * 
 * \return uint8_t 
 */
/* ===========================================================================
 * Name: US_Com_GetHsdPwrChannel_A    
 * Remarks:  DD-ID: {0D43993B-786E-4480-BC46-0E24E77DB376} 
 * ===========================================================================*/
uint8_t US_Com_GetHsdPwrChannel_A(void)
{
    USS_PowerSelect_t power;
    uint8_t ret = ME_FALSE;

    UsStubInput_ReadIf_UsPowerSelect(&power);
    if(USS_PWR_ENABLED == power.status_A)
    {
        ret = ME_TRUE;
    }

    if ((power.status_A != USS_PWR_ENABLED) && (power.status_A != USS_PWR_DISABLED))
    {
        Dsi3BusPowerReq.status_A = 0xBBu; /*request status again*/
        (void)SigMgr_Data_USS_PowerSelect_t_Put(&Dsi3BusPowerReq);
    }
    else if (Dsi3BusPowerReq.status_A == 0xBBu)
    {
        Dsi3BusPowerReq.status_A = power.status_A;
        (void)SigMgr_Data_USS_PowerSelect_t_Put(&Dsi3BusPowerReq);
    }
    else
    {
        /*Do Nothing*/
    }

    return (ret);
}


/**
 * \brief This function return the  status of power on/off request of Uss high side channel B/1
 * 
 * \return uint8_t 
 */
/* ===========================================================================
 * Name: US_Com_GetHsdPwrChannel_B    
 * Remarks:  DD-ID: {8BC8F2F4-8E18-494f-99C8-9CC94D9CC883}
 * ===========================================================================*/
uint8_t US_Com_GetHsdPwrChannel_B(void)
{
    USS_PowerSelect_t power;
    uint8_t ret = ME_FALSE;

    UsStubInput_ReadIf_UsPowerSelect(&power);
    if(USS_PWR_ENABLED == power.status_B)
    {
        ret = ME_TRUE;
    }

    if ((power.status_B != USS_PWR_ENABLED) && (power.status_B != USS_PWR_DISABLED))
    {
        Dsi3BusPowerReq.status_B = 0xBBu; /*request status again*/
        (void)SigMgr_Data_USS_PowerSelect_t_Put(&Dsi3BusPowerReq);
    }
    else if (Dsi3BusPowerReq.status_B == 0xBBu)
    {
        Dsi3BusPowerReq.status_B = power.status_B;
        (void)SigMgr_Data_USS_PowerSelect_t_Put(&Dsi3BusPowerReq);
    }
    else
    {
        /*Do Nothing*/
    }

    return (ret);
}
 

/**
 * \brief This function reads tge vehicle information.
 * 
 * \param VehicleInfo 
 */
/* ===========================================================================
 * Name: US_Get_VehicleInfo    
 * Remarks:  DD-ID: {1ECBA422-88B5-4ba1-BBC9-E0B9531DCE95}
 * ===========================================================================*/
void US_Get_VehicleInfo(const ME_VehInp_to_IpcSignals_t * const VehicleInfo)        
{
	ME_VehInp_FromCAN2_IpcSignals *CAN2_to_IPC    = (ME_VehInp_FromCAN2_IpcSignals *)&(VehicleInfo->CAN2_to_IPC);        
	ME_VehInp_FromCAN14_IpcSignals  *CAN14_to_IPC = (ME_VehInp_FromCAN14_IpcSignals *)&(VehicleInfo->CAN14_to_IPC);   

#if(USS_FEATURE_INPUT_PROCESS_AMBIENT_TEMP == US_FEATURE_ON)
    ME_VehInp_BCM_FD_9    *BCM_FD_9; 
#endif

#if(USS_FEATURE_INPUT_PROCESS_VEH_SPEED == US_FEATURE_ON)
	ME_VehInp_FD14_BRAKE_FD_2 *FD14_BRAKE_FD_2;
#endif

#if(USS_FEATURE_INPUT_PROCESS_GEAR == US_FEATURE_ON)
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS)
	ME_VehInp_TRANSM_FD_4  *TRANSM_FD_4; 
#elif(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_BEV)
    ME_VehInp_FD14_PT_SYSTEM_FD_1 *PT_SYSTEM_FD_1;
#elif(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_HD)
	ME_VehInp_TRANSM_FD_1  *TRANSM_FD_1; 
#endif
	US_E_App_Prndl_Status_e Gearvalue = US_PRNDL_UNKNOWN;
#endif	

#if(USS_FEATURE_INPUT_PROCESS_VEH_SPEED == US_FEATURE_ON)
	FD14_BRAKE_FD_2 = &CAN14_to_IPC->DataInp_FD14_BRAKE_FD_2;
	/** Validate the vehical speed range */
	if((US_RANGE_MAX_VEH_SPEED_IN_KM_PH >= FD14_BRAKE_FD_2->FD14_VehicleSpeedVSOSig) &&
	   (US_RANGE_MIN_VEH_SPEED_IN_KM_PH <= FD14_BRAKE_FD_2->FD14_VehicleSpeedVSOSig))
	{
		UssCom_CopyVehSpeedInputBuffer(FD14_BRAKE_FD_2->FD14_VehicleSpeedVSOSig);
		UssCom_CopyVehSpeedValidity((US_E_GenericSignalValidityFlag_e)US_SIGNALVALIDITY_VALID);
    }
	else
	{
		/*mark signal as invalid and keep the signal values as pervious valid*/
		UssCom_CopyVehSpeedValidity((US_E_GenericSignalValidityFlag_e)US_TEMPVALID_INVALID);
	}
#endif

#if(USS_FEATURE_INPUT_PROCESS_AMBIENT_TEMP == US_FEATURE_ON)
	BCM_FD_9 = &CAN2_to_IPC->DataInp_BCM_FD_9;
	/** Validate the ambient tempreture range */
	if( ((US_RANGE_MAX_AMBIENT_TEMP_IN_CELSIUS >= BCM_FD_9->ExternalTemperature) && 
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
        (US_RANGE_MIN_AMBIENT_TEMP_IN_CELSIUS <= BCM_FD_9->ExternalTemperature)) || (g_LAUD_bHardcodeTemp != 0u) )
#else
        (US_RANGE_MIN_AMBIENT_TEMP_IN_CELSIUS <= BCM_FD_9->ExternalTemperature)) )
#endif
	{
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
		if(g_LAUD_bHardcodeTemp != 0u)
		{
			UssCom_CopyAmbientAirTemperatureInputBuffer(g_LAUD_fExternalTemp);
		}
		else
#endif
		{
			UssCom_CopyAmbientAirTemperatureInputBuffer(BCM_FD_9->ExternalTemperature);
		}
		
		UssCom_CopyAmbientAirTempValidtyFlagInputBuffer((US_E_TempValidityFlag_t)US_TEMPVALID_VALID);
    }
	else
	{
		/*mark signal as invalid and keep the signal values as pervious valid*/
		UssCom_CopyAmbientAirTempValidtyFlagInputBuffer((US_E_TempValidityFlag_t)US_TEMPVALID_INVALID);
	}
#endif

#if(USS_FEATURE_INPUT_PROCESS_GEAR == US_FEATURE_ON)
	/**Validate the gear value and update*/
	UssCom_CopyVehGearValidityFlagInputBuffer((US_E_GenericSignalValidityFlag_e)US_SIGNALVALIDITY_VALID);
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS)
	TRANSM_FD_4 = &CAN2_to_IPC->DataInp_TRANSM_FD_4;
	switch(TRANSM_FD_4->GearEngaged )
#elif (US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_BEV)	
    PT_SYSTEM_FD_1 = &CAN14_to_IPC->DataInp_FD14_PT_SYSTEM_FD_1;
	switch(PT_SYSTEM_FD_1->FD14_GearEngaged_PT )
#elif(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_HD)
	TRANSM_FD_1 = &CAN2_to_IPC->DataInp_TRANSM_FD_1;
	switch(TRANSM_FD_1->TargetGear )
#endif
	{
		case US_RANGE_ENUM_GEAR_ENGAGED_NEUTRAL   :
		Gearvalue = US_PRNDL_NEUTRAL;
		break;

		case US_RANGE_ENUM_ENGAGED_1_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_2_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_3_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_4_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_5_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_6_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_7_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_8_FWD_GEAR:
		case US_RANGE_ENUM_ENGAGED_9_FWD_GEAR:
		Gearvalue = US_PRNDL_DRIVE;
		break;

		case US_RANGE_ENUM_ENGAGED_PARK      :
		Gearvalue = US_PRNDL_PARK;
		break;

		case US_RANGE_ENUM_ENGAGED_REV_GEAR  :
		Gearvalue = US_PRNDL_REVERSE;
		break;

		default:
		Gearvalue = US_PRNDL_UNKNOWN;
		UssCom_CopyVehGearValidityFlagInputBuffer((US_E_GenericSignalValidityFlag_e)US_TEMPVALID_INVALID);
		break;
	}
	UssCom_CopyVehPrndlInputBuffer(Gearvalue);
#endif

}

/**
 * \brief This function read the parking mode.
 * 
 * \param ParkingMode 
 */
/* ===========================================================================
 * Name: US_Get_ParkingMode    
 * Remarks:  DD-ID: {EE741701-1B9C-4135-A24E-02A4FBF6ED81}
 * ===========================================================================*/
void US_Get_ParkingMode(const TbFA_USSStateOutput_t * const Parking_Mode)    
{
	bool_t PlantMode_Signal;
	DiagToParkAssist_t IbDiag_DiagToParkAssist;
	uint32_t ReceivedParkingMode = (uint32_t)Parking_Mode->IeFA_e_USSFiringMode;   /*KPK-QAC Fix : Need to suppress since intentionally type cast the pointer  */
	SigMgr_Data_DiagToParkAssist_t_Get(&IbDiag_DiagToParkAssist);
    PlantMode_Signal = (bool_t)(IbDiag_DiagToParkAssist.MbDiag_PlantModeOn);
	if((ReceivedParkingMode == ((uint32_t)US_PARKMODE_STANDBY))&&((PlantMode_Signal == ((bool_t)ME_TRUE)) || (IbDiag_DiagToParkAssist.MbDiag_SensorTestMode == ((bool_t)ME_TRUE))))
	{
		ReceivedParkingMode = ((uint32_t)US_PARKMODE_PARKING);
	}
	UssCom_CopyReceivedParkingMode(ReceivedParkingMode);
}


/**
 * \brief This function reads the current and voltage values of dsi3 power line.
 * 
 * \param sUSS_Curr_Volt_Monitor 
 */
/* ===========================================================================
 * Name: US_Get_CurrVoltValues     
 * Remarks:  DD-ID: {1853A22D-306F-4a05-B080-917CE17458F8}
 * ===========================================================================*/
void US_Get_CurrVoltValues(const USS_Curr_Volt_Monitor_t * const sUSS_Curr_Volt_Monitor)    
{
	UssHsd_F_CopyVoltageMonitorValueFromIPC(sUSS_Curr_Volt_Monitor);
}

/**
 * \brief This function reads the Dynamic Calibration through IPC.
 * DD-ID: 
 * \param sUSS_DynamicCalData 
 */
/* ===========================================================================
 * Name: US_Get_DynamicCalData	
 * Remarks:  DD-ID: {10EE17C1-FF3D-4f56-9010-F0F4D6E9C063}
 * ===========================================================================*/
static void US_Get_DynamicCalData(const UssTunningData_mcu1_0_t * const sUSS_DynamicCalData)
{
	 static uint16_t PrvSeqID = 0xffff;
     static uint8_t dynamic_cmd[3072u];
	 uint16_t Len;
	 TuningCmdSeqID = sUSS_DynamicCalData->UssTunningDataIn[THREE];
	 TuningCmdSeqID = (TuningCmdSeqID << EIGHT)| sUSS_DynamicCalData->UssTunningDataIn[TWO];
	 Len = sUSS_DynamicCalData->UssTunningDataIn[ONE];                                     /*get data length*/
	 Len = (Len << EIGHT)| sUSS_DynamicCalData->UssTunningDataIn[ZERO];
	 if((PrvSeqID != TuningCmdSeqID)&&(Len < (TUNING_DATA_MAX_SIZE-TWO)))   /*new cmd and Valid, Len is Ok?*/
	 {
		 PrvSeqID = TuningCmdSeqID;
		 (void)memcpy(dynamic_cmd,sUSS_DynamicCalData->UssTunningDataIn,3072u);
		 (void)US_SnrCfg_F_Cali_RcvCmd(&dynamic_cmd[SIX],Len,ONE);
	 }

}

#ifdef PLAYBACK_SW_ENABLE
/**
 * \brief 
 * 
 * \param Data 
 */
void US_Get_DataCollection(const US_S_USSDataCollectionData_t * const Data)
{
	
	uint8_t index,cnt,*pData;
	uint32_t RxReplaySnrMeasDataChecksum,Received_RxReplaySnrMeasDataChecksum;
    RxReplaySnrMeasDataChecksum = ZERO;
    pData  = (uint8_t*)Data->Log_SnrMeasData_01;
	for(index = 0;index<6;index++)
	{
		pData++;          /*skip Log_SnrMeasData_0x[0]*/
	  for(cnt=0;cnt<63;cnt++)
	  {
		RxReplaySnrMeasDataChecksum = RxReplaySnrMeasDataChecksum + (*pData++);
	  }
	}
    pData  = (uint8_t*)&Data->Log_SnrMeasData_07[ONE];
	
	for(cnt=0;cnt<42;cnt++)
	{
		RxReplaySnrMeasDataChecksum = RxReplaySnrMeasDataChecksum + (*pData++);
	}

	memcpy((uint8_t *)&Received_RxReplaySnrMeasDataChecksum,&Data->Log_SnrMeasData_07[43],4);

	if(Received_RxReplaySnrMeasDataChecksum ==RxReplaySnrMeasDataChecksum)
	{
		RxReplaySnrMeasDataChecksum = 0;
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_01((uint8_t *)&Data->Log_SnrMeasData_01[1]);
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_02((uint8_t *)&Data->Log_SnrMeasData_02[1]);
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_03((uint8_t *)&Data->Log_SnrMeasData_03[1]);
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_04((uint8_t *)&Data->Log_SnrMeasData_04[1]);
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_05((uint8_t *)&Data->Log_SnrMeasData_05[1]);
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_06((uint8_t *)&Data->Log_SnrMeasData_06[1]);
		Rte_MEUssMgr_Cyclic100ms_Rte_ReplayRxSnrMeasData_07((uint8_t *)&Data->Log_SnrMeasData_07[1]);
		RePlayDataReady(ME_TRUE);
	}
	else
	{
		RePlayDataReady(ME_FALSE);
	}

}
#endif


/**
 * \brief This function register callback for invoking vehicle, parking mode and current voltage values.
 * 
 */
/* ===========================================================================
 * Name: ME_US_F_RegisterDataCopyCallBackInput    
 * Remarks:  DD-ID: {7D6E430C-721C-4cd2-8120-20C435F574CD}
 * ===========================================================================*/
void ME_US_F_RegisterDataCopyCallBackInput(void)
{
	(void)UsStubCbk_RegisterCbk_VehicleInfo(US_Get_VehicleInfo);
    (void)UsStubCbk_RegisterCbk_ParkingMode(US_Get_ParkingMode);
    (void)UsStubCbk_RegisterCbk_CurrVoltValues(US_Get_CurrVoltValues);
    (void)UsStubCbk_RegisterCbk_DynamicCalData(US_Get_DynamicCalData);
  
  #ifdef PLAYBACK_SW_ENABLE
	UsStubCbk_RegisterCbk_DataCollection(US_Get_DataCollection);
  #endif 	
}


/**
 * \brief This function reads required data periodically 
 * 
 */
/* ===========================================================================
 * Name: UssCom_F_InputDataShareMain    
 * Remarks:  DD-ID: {2A10E55B-C1B6-4c81-9444-F75523557CE5}
 * ===========================================================================*/
void UssCom_F_InputDataShareMain(void)
{
	TbAP_USSStateOut_t USS_reCfgSensor;
	UsStubInput_ReadIf_TbAP_USSStateOut(&USS_reCfgSensor);
    
    /* external boolean to internal boolean safe conversion */
    if( (uint8_t)USS_reCfgSensor.MeAP_b_USSReInit == ZERO)
    {
        UssCom_CopyReCfgFlagBuffer(ME_FALSE);
    }
    else
    {
        UssCom_CopyReCfgFlagBuffer(ME_TRUE);
    }
    US_Com_GetProxi();
}    


/**
 * \brief This function reads the Environment data. This is place holder.
 * 
 */
/* ===========================================================================
 * Name: UssCom_RecvEnvironmentStatusFromPA     
 * Remarks:  DD-ID: 
 * ===========================================================================*/
void UssCom_RecvEnvironmentStatusFromPA(void)
{

}

