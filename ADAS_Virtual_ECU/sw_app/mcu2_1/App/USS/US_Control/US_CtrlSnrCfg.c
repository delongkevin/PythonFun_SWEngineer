/*
 * US_CtrlSnrCfg.c
 *
 *  Created on: Nov 2, 2021
 *      Author: jonapais
 */


#include "US_CtrlMain.h"
#include "US_Ctrl_Global.h"
#include "US_ME_Typedefs_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_SnrDynAdjust.h"

/* Parameters/Limits for Cal change */
#define US_D_CTRL_MIN_VEHSPEED (17.0f)
#define US_D_INPUTTEMP_TO_CALTEMP_SCALE (10u) /* cal temp is in 0.1 degC scale */
#define US_D_REINIT_RETRY_DELAY (250u) /* value * 10ms task timer */
#define US_D_NO_CAL_BIN_FOUND (0xFFu)
#define US_D_DEFAULT_CAL_BIN    (3u)
#define US_D_TEMP_INIT_WAIT_TIMEOUT (100u) /*while loop timer..... \TODO REPLACE */

static uint8_t uUsed_Temperature_table_index = US_D_DEFAULT_CAL_BIN;  /*QAC : 3408 need previous declaration*/

#ifdef US_D_ENABLE_DYNCALADJ
//keep record of global ambient temperature when UssCtrl_GetSnrCfgIndex is called. 
static float32_t g_SnrCfg_fAmbTemp = 0.0f;
static float32_t g_SnrCfg_fTempBinFraction = 0.0f;
static sint16_t sTempBinCenters[4]; //just store 4 bin centers.
static float32_t fUsedAmbTemp = F_INVALID_AMB_TEMP; //set last used AmbTemp to 
#endif

#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
uint8_t UssCtrl_g_uisPerp = ME_FALSE;
uint8_t UssCtrl_g_uisActive = ME_FALSE;
uint8_t UssCtrl_g_uisAbortFault = ME_FALSE;
uint8_t UssCtrl_g_uisComplete = ME_FALSE;
uint8_t UssCtrl_g_uIsOverwritingActive = ME_FALSE;
uint8_t UssCtrl_g_uIsOverwritingAbortFault = ME_FALSE; 
uint8_t UssCtrl_g_uIsOverwritingComplete = ME_FALSE;
uint8_t UssCtrl_g_uIsOverwritingPerp = ME_FALSE;
#if (US_D_USE_FAPA_API == ME_TRUE)
IJobFPAOutput_t UssCtrl_g_sJobFPAOutputData;
TbAP_DriveAssistStatOut_t UssCtrl_g_sDriveAssistStatOut;
#endif
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
volatile uint8_t g_LAUD_DynCal_Enable = 1;
#endif
#endif /* (US_D_ENABLE_FAPA_DYN_STG ) */

uint8_t g_UssDbg_ReInitEntrance = 0x00;
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
volatile bool_t g_LAUD_ForceAllowFlag = ME_FALSE; //lauder debug
#endif

/* Local function declarations */
static uint8_t UssCtrl_GetCalibrationBin(float32_t fInputTemp, sint16_t sHysteresis);
#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
static void CheckFAPAOnlyConditions(void);
#endif

uint16_t UssCtrl_TriggerSnrCfgCntr1 = 0;
uint16_t UssCtrl_CheckForSnrCalChangeCntr = 0;

/*===========================================================================
 * \brief Check for sensor cal change and update at optimal time.
 * \param none
 * \param none
 * \return uint16_t Error code.
 * \remarks
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_CheckForSnrCalChange
 * Remarks:  DD-ID: {FDA6DF22-6366-4491-970F-9DAEE76CA347}
 * Traceability to source Code: Req.-ID: 14959476
 *  Req.-ID: 14959513
 *  Req.-ID: 14959555
 *  Req.-ID: 14959230
 *  Req.-ID: 13393741
 *  Req.-ID: 13396016
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 * ===========================================================================*/
 
uint8_t UssCtrl_CheckForSnrCalChange(void)
{
    uint8_t uRet = ME_OK;
    US_E_App_Prndl_Status_e ePrndl;
    float32_t fVehSpeed;
    float32_t fAmbTemp = 0.0f;
    uint8_t uNewTempTableIndex;
    uint32_t mask,discount,fault_unknow,fault_Fail;
    static uint32_t prev_discount = 0;
    static uint16_t re_Cfg_delay  = ZERO;
    static bool_t  bDisconnect =(bool_t)ME_FALSE, bFirstActionInCondtionsDone = (bool_t)ME_FALSE;
    bool_t ctl_state, bReCfgFlag;
	US_E_TempValidityFlag_t tempflag;
#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)!= US_D_PLATFORM_CVADAS)
	US_E_GenericSignalValidityFlag_e speedflag;
#endif
    /*When a new calibration to be downlaoded US magr has to send a command to stop firing to lower module*/
    /*\TODO ^? */
	tempflag  = UssCom_F_GetAmbientTempValidity();
    UssCtrl_CheckForSnrCalChangeCntr++;

    /* Check if we are in the conditions to allow calibration/re-init action */
#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)!= US_D_PLATFORM_CVADAS)
	speedflag  =  UssCom_F_GetGearSpeedValidity();
    if(speedflag == US_SIGNALVALIDITY_VALID)
#endif
    {
        /*Read Gear status*/
        ePrndl = UssCom_F_GetVehPrndl();   

        /*Read veh speed*/
        fVehSpeed = UssCom_F_GetVehSpeed(); 
         
		ctl_state =  UssCtrl_bIsCtrlFsmHalted();
        bReCfgFlag = UssCom_F_GetReCfgAllowFlag();

#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
    if( (bReCfgFlag != ME_FALSE) || (ME_TRUE == ctl_state)
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
         || (ME_TRUE == g_LAUD_ForceAllowFlag)
#endif
       )
#else		
        if((fVehSpeed >= US_D_CTRL_MIN_VEHSPEED) || (ePrndl == US_PRNDL_PARK) || ((bool_t)ME_TRUE == ctl_state))  
#endif
       {
           mask = 0xffffffffu;
           discount = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT)&mask;
           fault_unknow = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN)&mask;
            /* Check for sensor disconnect issues - overrides any temperature conditions */
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
         fault_Fail  = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_FAIL)&mask;
          if ((discount != ZERO)||(fault_unknow != ZERO)||( fault_Fail!= ZERO))
#else
            if ((discount != ZERO)||(fault_unknow != ZERO))
#endif
            {
                bDisconnect  = ME_TRUE;
				if((re_Cfg_delay  == ZERO)||(prev_discount != discount ))
                {
					if(tempflag == US_TEMPVALID_VALID)
                    {
                        fAmbTemp = UssCom_F_GetAmbientTemp();
                        uNewTempTableIndex = UssCtrl_GetCalibrationBin(fAmbTemp, (sint16_t)ZERO);
                    }
                    else
                    {
                        /*temperature data is not available, but we must pick a bin. Use prev */
                        uNewTempTableIndex = uUsed_Temperature_table_index;
                    }
#ifdef US_D_ENABLE_DYNCALADJ
                    fUsedAmbTemp = fAmbTemp; //set the used temp to the AmbTemp. 
#endif                    
                    g_UssDbg_ReInitEntrance = 0x01;
                    uUsed_Temperature_table_index = uNewTempTableIndex;
                    UssCtrl_TriggerSnrCfg();
                    UssCtrl_TriggerSnrCfgCntr1++;
                    re_Cfg_delay = US_D_REINIT_RETRY_DELAY;
                    bFirstActionInCondtionsDone = (bool_t)ME_TRUE;
                }
                else
                {
                    re_Cfg_delay -- ;
                }
				prev_discount = discount;
          }
			else if(bDisconnect == (bool_t)ME_TRUE)
			{
					if(tempflag == US_TEMPVALID_VALID)
                    {
                        fAmbTemp = UssCom_F_GetAmbientTemp();
                        uNewTempTableIndex = UssCtrl_GetCalibrationBin(fAmbTemp, (sint16_t)ZERO);
                    }
                    else
                    {
                        /*temperature data is not available, but we must pick a bin. Use prev */
                        uNewTempTableIndex = uUsed_Temperature_table_index;
                    }
                    if(uUsed_Temperature_table_index != uNewTempTableIndex)
					{
#ifdef US_D_ENABLE_DYNCALADJ
                        fUsedAmbTemp = fAmbTemp; //set the used temp to the AmbTemp. 
#endif                    
                        g_UssDbg_ReInitEntrance = (uint8_t)0x02;
						uUsed_Temperature_table_index = uNewTempTableIndex;
						UssCtrl_TriggerSnrCfg();
					}
                    re_Cfg_delay = US_D_REINIT_RETRY_DELAY;
                    bFirstActionInCondtionsDone =(bool_t) ME_TRUE;
					bDisconnect = (bool_t)ME_FALSE;
			}
            /* If all sensors are available, check temperature for updates */
            else if(tempflag == US_TEMPVALID_VALID)
            {
                fAmbTemp = UssCom_F_GetAmbientTemp();
                if( bFirstActionInCondtionsDone == (bool_t)ME_FALSE )
                {
                    /*first time taking action while conditions are valid - ignore hysteresis */
                    uNewTempTableIndex = UssCtrl_GetCalibrationBin(fAmbTemp, (sint16_t)ZERO);
                }
                else
                {
                    uNewTempTableIndex = UssCtrl_GetCalibrationBin(fAmbTemp, (sint16_t)20u); 
                }

                /* There is a chance no valid bin was found - if so set to previous */
                if ( uNewTempTableIndex == US_D_NO_CAL_BIN_FOUND)
                {
                    uNewTempTableIndex = uUsed_Temperature_table_index;
                }

#ifdef US_D_ENABLE_DYNCALADJ
                if ((uUsed_Temperature_table_index != uNewTempTableIndex) 
                    || ((fabs((fUsedAmbTemp-fAmbTemp)))>=US_D_SNR_TEMP_INTERP_HYST)) //or if change is greater than hysteresis amount 
#else
                if (uUsed_Temperature_table_index != uNewTempTableIndex)
#endif
                {
                    g_UssDbg_ReInitEntrance = (uint8_t)0x03;
                    uUsed_Temperature_table_index = uNewTempTableIndex;
#ifdef US_D_ENABLE_DYNCALADJ
                    fUsedAmbTemp = fAmbTemp; //set the used temp to the AmbTemp. 
#endif
                    /* Don't do normal snr config kickoff, instead do adj */
                    UssCtrl_SetTemAdjState(USSCTRL_TEMPADJ_PENDING);
                    bFirstActionInCondtionsDone = (bool_t)ME_TRUE;
                    uRet = ME_OK;  /*Temporary: Set uRet to return from function. */
                }
            }
            else
            {
                /*No error and no valid temp - no action possible */
            }
        }
        else
        {
            /*not in conditions for calibration/re-init actions */
            bFirstActionInCondtionsDone = ME_FALSE;
            re_Cfg_delay = ZERO;
        }
    }
#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS) != US_D_PLATFORM_CVADAS)
    else
    {
        /*no gear/speed data available - no action */
        bFirstActionInCondtionsDone = ME_FALSE;
    }
#endif

#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
    CheckFAPAOnlyConditions();
#endif

    return uRet;
}

/* ===========================================================================
 * Name:	 CheckFAPAOnlyConditions
 * Remarks:  DD-ID: {??}
 * Req.-ID: N/A
 * ===========================================================================*/
#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
static void CheckFAPAOnlyConditions(void)
{
#if (US_D_USE_FAPA_API == ME_TRUE)
    //SigMgr Calls for FAPA data
    SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(&UssCtrl_g_sDriveAssistStatOut);
    SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(&UssCtrl_g_sJobFPAOutputData);    
    SigMgr_Data_IFPAInfoToVC_t_Get(&(UssCtrl_g_sJobFPAOutputData.m_FpaInfoToVC));

    UssCtrl_g_uisActive = (TeAutoPark_e_AutoParkStatus_Active == UssCtrl_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus);
    UssCtrl_g_uisAbortFault = (TeAutoPark_e_AutoParkStatus_Abort == UssCtrl_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus || 
                               TeAutoPark_e_AutoParkStatus_Fault == UssCtrl_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus);
    UssCtrl_g_uisComplete = (TeAutoPark_e_AutoParkStatus_Complete == UssCtrl_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus);
    UssCtrl_g_uisPerp = (ParkingSlotType_E_PW_PERPENDICULAR == UssCtrl_g_sJobFPAOutputData.m_FpaInfoToVC.stFPALockedSlotData.m_SlotType);

    //Reset IsOverwriting flag
    if (!UssCtrl_g_uisActive)
    {
        UssCtrl_g_uIsOverwritingActive = ME_FALSE; 
    }

    if (!UssCtrl_g_uisAbortFault)
    {
        UssCtrl_g_uIsOverwritingAbortFault = ME_FALSE; 
    }

    if (!UssCtrl_g_uisComplete)
    {
        UssCtrl_g_uIsOverwritingComplete = ME_FALSE; 
    }

    if (!UssCtrl_g_uisPerp)
    {
        UssCtrl_g_uIsOverwritingPerp = ME_FALSE;
    }
    
    if(g_LAUD_DynCal_Enable == 1u)
    {
        //Logic to overwrite only ONCE when needed
        if (((UssCtrl_g_uisActive && !UssCtrl_g_uIsOverwritingActive) || (UssCtrl_g_uisComplete && !UssCtrl_g_uIsOverwritingComplete) ||
            (UssCtrl_g_uisAbortFault && !UssCtrl_g_uIsOverwritingAbortFault) || (UssCtrl_g_uisPerp && !UssCtrl_g_uIsOverwritingPerp)) /*&& (ME_FALSE == US_SnrCfg_Get_Doing())*/) 
        {
            //UssCtrl_SetFireSequence
            UssCtrl_SetTemAdjState(USSCTRL_TEMPADJ_PENDING);
            UssCtrl_g_uIsOverwritingActive = ME_TRUE;
            UssCtrl_g_uIsOverwritingComplete = ME_TRUE;
            UssCtrl_g_uIsOverwritingAbortFault = ME_TRUE;
            UssCtrl_g_uIsOverwritingPerp = ME_TRUE;
            //UssCtrl_g_uTemAdjState_ForcePending = ME_FALSE;
        }
    }
#endif /* #if (US_D_USE_FAPA_API == ME_TRUE) */
}
#endif /* #if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE) */

/* ===========================================================================
 * Name:	 UssCtrl_GetCalibrationBin
 * Remarks:  DD-ID: {123E287A-4222-44ed-A1A6-F345FE846B5F}
 * Req.-ID: 14959188
 * ===========================================================================*/

/* Function to calculate calibration bin from input temperature */
static uint8_t UssCtrl_GetCalibrationBin(float32_t fInputTemp, sint16_t sHysteresis)
{
    sint16_t sAmbTemp = 0;
    US_S_TemperatureCompensation_t const * pTempTable;
    uint8_t cnt, ret_BinVal = US_D_NO_CAL_BIN_FOUND;

#ifdef US_D_ENABLE_DYNCALADJ
    //g_SnrCfg_fTempBinFraction = 0.0f; /* Gets written to, no need to reset. Avoids issue when no cal bin found */
#endif


    /* Get temperature ranges for Calibration bins*/
    pTempTable = GetTemperatureCfg();
	if(pTempTable != NULL)
	{
    if(pTempTable->points_temp < MAX_TEMP_POINTS)
    {
        sAmbTemp = (sint16_t)((float32_t)US_D_INPUTTEMP_TO_CALTEMP_SCALE * fInputTemp);	/*PRQA S 4395 */
        

#ifdef US_D_ENABLE_DYNCALADJ
    	UssDynAdj_SetSnr_TempPoints((uint16_t)pTempTable->points_temp);
        /* determine bin centers (hardcoded for 4 bins for now)*/
        sTempBinCenters[0]=pTempTable->temp_table[0]; 
        sTempBinCenters[1]=(pTempTable->temp_table[0]+pTempTable->temp_table[1])/2; 
        sTempBinCenters[2]=(pTempTable->temp_table[1]+pTempTable->temp_table[2])/2; 
        sTempBinCenters[3]=pTempTable->temp_table[2]; 
        
#endif


        /* points_temp equals the number of temperature divisions/boundaries
         * meaning the number of bins should equal to (points_temp + 1)
         *  making the max bin INDEXto be (points_temp + 0) - due to zero indexing
         * while the max temp_table INDEX should be (points_temp - 1) - due to zero indexing */
        if( sAmbTemp <= (pTempTable->temp_table[ZERO] - sHysteresis) )
        {
            ret_BinVal = ZERO;
        }
        else if( sAmbTemp > (pTempTable->temp_table[pTempTable->points_temp - ONE] + sHysteresis) )
        {
            ret_BinVal = (uint8_t)(pTempTable->points_temp & 0xffu);
        }
        else
        {
            for(cnt = ZERO; cnt< (pTempTable->points_temp - ONE); cnt++)
            {
                    if((sAmbTemp > (pTempTable->temp_table[cnt] + sHysteresis))
                        && (sAmbTemp <= (pTempTable->temp_table[cnt + ONE] - sHysteresis)))
                    {
                        ret_BinVal = cnt + ONE;

#ifdef US_D_ENABLE_DYNCALADJ
                        //just record the fraction of how far into the current bin we are: 
                        g_SnrCfg_fTempBinFraction = ((float32_t)(sAmbTemp - ((sTempBinCenters[cnt]))))/((float32_t)(sTempBinCenters[cnt + TWO]-sTempBinCenters[cnt])); 
#endif
                        break;
                    }
            }

        }
    }
    else
    {
       ret_BinVal = US_D_DEFAULT_CAL_BIN;

    }
	}


#ifdef US_D_ENABLE_DYNCALADJ
    if(US_D_NO_CAL_BIN_FOUND != ret_BinVal)
    {
        UssDynAdj_SetSnrAdj_TempParam(g_SnrCfg_fTempBinFraction,(uint16_t)ret_BinVal);
    }
#endif    

    return ret_BinVal;
}

/* ===========================================================================*/
/**GetSnrCfgInitIndex.
 * get temp table index.
 * \param uint8_t Sensor index.
 * \return uint8_t temp table index.
 * \remarks  no remarks  \TODO Rename this function to indicate START UP ONLY 
 */
/* ========================================================================= */
/* ===========================================================================
 * Name:	 UssCtrl_GetSnrCfgIndex
 * Remarks:  DD-ID: {A0FA9079-14EC-4f3d-9094-7068B9EA2EAB}
 *  Req.-ID: 14959230
 *  Req.-ID: 14958936
 *  Req.-ID: 14959188
 *  Req.-ID: 14959191
 *  Req.-ID: 14959203
 * ===========================================================================*/
 
uint8_t UssCtrl_GetSnrCfgIndex(void)
{
    float32_t fAmbTemp =0.0f;
    bool_t bTempDataFound;
    uint32_t utimeout_cycles;
    uint8_t uNewTempTableIndex;
	US_E_TempValidityFlag_t tempflag;
    US_S_TemperatureCompensation_t const * pTempTable=NULL; 

    /* init values */
    bTempDataFound = ME_FALSE;
    utimeout_cycles = 0;

    /* \TODO move calibration startup to cyclic task, need Rivian system to be running */
    /*here is test  code   ---- while( (bTempDataFound == ME_FALSE) && (utimeout_cycles < US_D_TEMP_INIT_WAIT_TIMEOUT) ) */
    {
        /* Collect Input data from upper SW layer/CAN */
        UssCom_RecvEnvironmentStatusFromPA();

        /* check if temp data is valid */
		tempflag = UssCom_F_GetAmbientTempValidity();
        if (tempflag == US_TEMPVALID_VALID)
        {
            bTempDataFound = ME_TRUE;
        }
        else
        {
            /*not valid, try again*/
            utimeout_cycles++;//PRQA S    We want variable to rollover,required behaviour
            //add code to wait 200ms, pulling data every cycle
            //ISSUE - this runs during Init task - Rivian CAN code not running possibly?
            // Need to move calibration out of Init and into cyclic task...
        }
    }

    if (bTempDataFound == (bool_t)ME_TRUE)
    {
        /*Read temperature*/
        fAmbTemp = UssCom_F_GetAmbientTemp();
    }
    else
    {
		pTempTable =  GetTemperatureCfg();
        if(pTempTable != NULL)
		{
			fAmbTemp = (float32_t)(pTempTable->default_temp);
			fAmbTemp /= (float32_t)US_D_INPUTTEMP_TO_CALTEMP_SCALE;
		}
    }

    uNewTempTableIndex = UssCtrl_GetCalibrationBin(fAmbTemp, 0); /*no hysteresis for startup */
    if ( uNewTempTableIndex == US_D_NO_CAL_BIN_FOUND)
    {
        /*should never happen - ASSERT(TRUE); */
        uUsed_Temperature_table_index = US_D_DEFAULT_CAL_BIN;
    }
    else
    {
        uUsed_Temperature_table_index = uNewTempTableIndex;
    }

#ifdef US_D_ENABLE_DYNCALADJ
    g_SnrCfg_fAmbTemp = fAmbTemp; //for now just record this as a global. 
#endif 

    return uUsed_Temperature_table_index;
}

/* ===========================================================================
 * Name:	 UssCtrl_Get_Temperature_Index
 * Remarks:  DD-ID: {02063C04-76CC-4b61-8A9F-DC6DFB2967BB}
 * Req.-ID:
 * Req.-ID:
 * ===========================================================================*/

uint16_t UssCtrl_Get_Temperature_Index(void)
{
	return (uint16_t)uUsed_Temperature_table_index;
}
