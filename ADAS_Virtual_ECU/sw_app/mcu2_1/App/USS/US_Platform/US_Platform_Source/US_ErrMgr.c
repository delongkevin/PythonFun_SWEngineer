/*
 * US_ErrMgr.c
 *
 *  Created on: Mar 17, 2022
 *      Author: kkotkar
 */
#include "US_Diagnostic_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_ErrMgr_Global.h"
#include "US_ErrMgrCfg.h"
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"

/***************************************************************************************************
 * 										Private Variables
 ***************************************************************************************************/
static bool_t SensorFlagGroupStatus[US_D_MAX_NUM_SENSORS][MAX_PER_SNR_FLAGS];
uint8_t g_DiagOutputFlag[12]={0};
/***************************************************************************************************
 * 										Private Functions
 ***************************************************************************************************/
static ldef_ErrorMgr_enErrorNo UssErrMgr_GetSnrErrNumber(uint8_t sensorID,uint8_t FlagGrp);
static ldef_ErrorMgr_enErrorNo UssErrMgr_GetECUErrNumber(uint8_t FlagGrp);
static void UssErrMgr_SetFlagGroup(uint8_t sensorID,US_E_DiagOuptutFlagGrp_t l_DiagOuptutFlagGrp);
static void UssErrMgr_ClearFlagGruop(uint8_t sensorID,US_E_DiagOuptutFlagGrp_t l_DiagOuptutFlagGrp);
static US_E_DiagOuptutFlagGrp_t UssErrMgr_GetOutputFlagGrp(US_E_SnrFaultReason_t l_DTCFaultNo);
static US_E_ECUDiagOuptutFlagGrp_t UssErrMgr_GetECUOutputFlagGrp(US_E_ECUFaultReason_t l_DTCFaultNo);
static uint8_t DTCSnrIdxlist[] ={5,4,3,2,1,0,6,7,8,9,10,11};   
/*===========================================================================
 * \brief Extract the Grouped flag assigned for passed Sensor Fault Reason.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
 /* ===========================================================================
 * Name: UssErrMgr_GetOutputFlagGrp    
 * Remarks:  DD-ID: {B7C6D74F-93C6-479a-B0E7-5F788F6EB0D7}
 * ===========================================================================*/
static US_E_DiagOuptutFlagGrp_t UssErrMgr_GetOutputFlagGrp(US_E_SnrFaultReason_t l_DTCFaultNo)
{
	return DiagConfg[l_DTCFaultNo].DiagOuptutFlagGrp;
}

/*===========================================================================
 * \brief Extract the ECU Grouped flag assigned for the Passed reason.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name: UssErrMgr_GetECUOutputFlagGrp    
 * Remarks:  DD-ID: {FB2169E6-41C0-43f7-8D28-3FD8B70169A3} 
 * ===========================================================================*/
static US_E_ECUDiagOuptutFlagGrp_t UssErrMgr_GetECUOutputFlagGrp(US_E_ECUFaultReason_t l_DTCFaultNo)
{
	return ECUDiagConfg[l_DTCFaultNo].ECUDiagOuptutFlagGrp;
}


/*===========================================================================
 * \brief Extract the error numbers which are arrange as per sensor & flags assignments.
 *
 * \param none
 * \param none
 * \return none
 * \remarks arranged(return) number is sensor specific to the customer(currently as per the Fisker error number arrangements)
 * ==========================================================================
 */
/* ===========================================================================
 * Name: UssErrMgr_GetSnrErrNumber    
 * Remarks:  DD-ID: {A51CA249-5F2F-492f-A69C-17EFCC36FEBA}
 * ===========================================================================*/
static ldef_ErrorMgr_enErrorNo UssErrMgr_GetSnrErrNumber(uint8_t sensorID,uint8_t FlagGrp)
{
	uint8_t cfgIdx = ZERO;
	if(sensorID < US_D_MAX_NUM_SENSORS)
	{
		cfgIdx = DTCSnrIdxlist[sensorID];
	} 
	else
	{
		;/* No Action */
	}
	return SensorErrMap[cfgIdx][FlagGrp];
}

/*===========================================================================
 * \brief Extract the error numbers which are arrange as per ECU error flag assignments
 *
 * \param none
 * \param none
 * \return none
 * \remarks arranged(return) number is sensor specific to the customer(currently as per the Fisker error number arrangements)
 * ==========================================================================
 */
/* ===========================================================================
 * Name: UssErrMgr_GetECUErrNumber    
 * Remarks:  DD-ID: {AEC0C34D-3964-4836-8BAB-ED7A6FC0A351}
 * ===========================================================================*/
static ldef_ErrorMgr_enErrorNo UssErrMgr_GetECUErrNumber(uint8_t FlagGrp)
{
	return ECUErrMap[FlagGrp];
}

/*===========================================================================
 * \brief Update the Grouped flag status for sensor faults .
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name: UssErrMgr_UpdateSensorDiagFlagStatus    
 * Remarks:  DD-ID: {51D8849E-22EE-4e49-9E84-3C12C0A10758}
 * ===========================================================================*/
void UssErrMgr_UpdateSensorDiagFlagStatus(uint8_t sensorID,US_E_SnrFaultReason_t Dtc_Type,bool_t status)
{
		US_E_DiagOuptutFlagGrp_t l_DiagOuptutFlagGrp;

		ldef_ErrorMgr_enErrorNo l_errorNumber;

		const uint8_t FaultReason = (uint8_t)Dtc_Type;

		l_DiagOuptutFlagGrp = UssErrMgr_GetOutputFlagGrp(Dtc_Type);

		/*If the status if set need to */
		if(l_DiagOuptutFlagGrp < MAX_DTC_SNR_FLAGS)
		{
			l_errorNumber = UssErrMgr_GetSnrErrNumber(sensorID,(uint8_t)l_DiagOuptutFlagGrp);

			if((bool_t)ME_TRUE == status)
			{
				UssErrMgr_SetFlagGroup(sensorID,l_DiagOuptutFlagGrp);
			}
			else
			{
				UssErrMgr_ClearFlagGruop(sensorID,l_DiagOuptutFlagGrp);
			}

			/*Call the RTE or API based on the Platform*/


			if((bool_t)ME_TRUE == status)
			{
				(void)ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo) l_errorNumber, ldef_ErrorMgr_ErrorActive,(const ldef_ErrorMgr_stAddData *)&FaultReason);/* PRQA S 0310 */
			}
			else if((bool_t)ME_FALSE == status)
			{
				(void)ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo) l_errorNumber, ldef_ErrorMgr_ErrorInactive,(const ldef_ErrorMgr_stAddData *)&FaultReason);/* PRQA S 0310 */
			}
			else
			{
				(void)ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo) l_errorNumber, ldef_ErrorMgr_Invalid,(const ldef_ErrorMgr_stAddData *)&FaultReason);/* PRQA S 0310 */
			}
		}
		else
		{
		}
}


/*===========================================================================
 * \brief update the grouped flag status of ECU flags.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
 /* ===========================================================================
 * Name: UssErrMgr_UpdateECUDiagFlagStatus    
 * Remarks:  DD-ID: {BD5B0ADF-E68D-426b-B9E0-8D920105FA87}
 * ===========================================================================*/
void UssErrMgr_UpdateECUDiagFlagStatus(US_E_ECUFaultReason_t Dtc_Type, bool_t status)
{
	US_E_ECUDiagOuptutFlagGrp_t l_ECUDiagOuptutFlagGrp;
	ldef_ErrorMgr_enErrorNo l_errorNumber;
	const uint8_t FaultReason = (uint8_t)Dtc_Type;

	l_ECUDiagOuptutFlagGrp = UssErrMgr_GetECUOutputFlagGrp(Dtc_Type);
	l_errorNumber = UssErrMgr_GetECUErrNumber((uint8_t)l_ECUDiagOuptutFlagGrp);
	/*Call the RTE or API based on the Platform*/
	if(l_ECUDiagOuptutFlagGrp < MAX_ECU_FLAGS)
	{
		if((bool_t)ME_TRUE == status)
		{
			(void)ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo) l_errorNumber, ldef_ErrorMgr_ErrorActive,(const ldef_ErrorMgr_stAddData *)&FaultReason);/* PRQA S 0310 */
		}
		else if((bool_t)ME_FALSE == status)
		{
			(void)ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo) l_errorNumber, ldef_ErrorMgr_ErrorInactive,(const ldef_ErrorMgr_stAddData *)&FaultReason);/* PRQA S 0310 */
		}
		else
		{
			(void)ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo) l_errorNumber, ldef_ErrorMgr_Invalid,(const ldef_ErrorMgr_stAddData *)&FaultReason);/* PRQA S 0310 */
		}
	}
	else
	{
		;/* No Action */
	}
}

/*===========================================================================
 * \brief Set Sensor Diagnostic Grouped Flags based on its existing status.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name: UssErrMgr_SetFlagGroup    
 * Remarks:  DD-ID: {E1A2136F-6427-4cd7-B50D-B39F2C3398E3}
 * ===========================================================================*/
static void UssErrMgr_SetFlagGroup(uint8_t sensorID,US_E_DiagOuptutFlagGrp_t l_DiagOuptutFlagGrp)
{
	/*Check if the flag group is set*/
	if((bool_t)ME_FALSE == SensorFlagGroupStatus[sensorID][l_DiagOuptutFlagGrp])
	{
		SensorFlagGroupStatus[sensorID][l_DiagOuptutFlagGrp] = ME_TRUE;
		if ( SNR_BLOCKAGE_FLAG == l_DiagOuptutFlagGrp)
		{
			g_DiagOutputFlag[sensorID] = ME_TRUE;
		}
	}
	else
	{
		;/* No Action */
	}
}

/*===========================================================================
 * \brief Clear the sensor diagnostic flag based on its existing status grouped flag & individual sensor fault status.
 *
 * \param none
 * \param none
 * \return none
 * \remarks this function keeps track of each individual flag of grouped fault clear the group flag only if all the flags are cleared
 * ==========================================================================
 */
 /* ===========================================================================
 * Name: UssErrMgr_ClearFlagGruop     
 * Remarks:  DD-ID: {08FD46C6-2852-47a9-8FD9-7F31722B2D6E}
 * ===========================================================================*/
static void UssErrMgr_ClearFlagGruop(uint8_t sensorID,US_E_DiagOuptutFlagGrp_t l_DiagOuptutFlagGrp)
{
	uint16_t SnrFlagType;
	bool_t FlagStatus = ME_TRUE;
	/*Check for all the flags in the same error group before clearing Error Flag Group*/
	for(SnrFlagType=0;SnrFlagType<(uint16_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE;SnrFlagType++)
	{
		/*check Error flags comes under same Error flag group*/
		if(l_DiagOuptutFlagGrp == DiagConfg[SnrFlagType].DiagOuptutFlagGrp)
		{
			/*if yes, then check that flag for given sensor ID is set*/
			if((bool_t)ME_TRUE == US_Diagnostics_GetSnrFaultFlagStatus((US_E_SnrFaultReason_t)SnrFlagType,sensorID))
			{
				/*if yes, since error flag is still present, no need to clear the groupFlag*/
				FlagStatus =  ME_FALSE;
				break;
			}
			else
			{
				/*No Flag set, check for next flag */
			}
		}
		else
		{
			/*Not fall under same group check for next flag*/
		}
	}

	/*All the flags are cleared then only clear the GruopFlag*/
	if((bool_t)ME_TRUE == FlagStatus)
	{
		SensorFlagGroupStatus[sensorID][l_DiagOuptutFlagGrp] = ME_FALSE;
		if ( SNR_BLOCKAGE_FLAG == l_DiagOuptutFlagGrp)
		{
			g_DiagOutputFlag[sensorID] = ME_TRUE;
		}
	}
	else
	{
		/*Do Nonthing*/
	}

}
