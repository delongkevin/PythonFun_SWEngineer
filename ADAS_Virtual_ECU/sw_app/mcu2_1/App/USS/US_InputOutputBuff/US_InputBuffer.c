/*
 * US_MgrInputBuffer.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */
#include "US_ComInputBuffer_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_Platform_Global.h"
#include"US_PlatformCfg_Global.h"

/*Currently not in use*/
UssCom_S_InputSignals_t UssCom_v_InputBuffer;

#define AIRTEMP_OUTSD_INIT_VALUE         (24.0f)
#define HUMIDITY_OUTSD_INIT_VALUE        (50U)
uint8_t ReplayRxSnrMeasData[420];
uint8_t ReplayRxSnrTempData[64];
#if(QAC_WARNING_FIX == ME_FALSE)
bool_t ReplayDataReadyFlag;
#endif
uint8_t MEUssMgr_v_AirHumiOutsd = HUMIDITY_OUTSD_INIT_VALUE;

#if(USS_FEATURE_INPUT_PROCESS_AMBIENT_TEMP == US_FEATURE_ON)
/* ===========================================================================
 * Name:	 UssCom_CopyAmbientAirTemperatureInputBuffer
 * Remarks:  DD-ID: {4662BF62-DB27-421a-A4A0-21F3667FEE19}
 * ===========================================================================*/

void UssCom_CopyAmbientAirTemperatureInputBuffer(float tempValue) 
{
	UssCom_v_InputBuffer.Veh_AmbAirTemp_1Deg_F32 = tempValue;
}

/* ===========================================================================
 * Name:	 UssCom_CopyAmbientAirTempValidtyFlagInputBuffer
 * Remarks:  DD-ID: {A432DADD-D25E-4adf-8895-30912C83D4A3}
 * ===========================================================================*/
void UssCom_CopyAmbientAirTempValidtyFlagInputBuffer(US_E_TempValidityFlag_t tempValid)
{
	UssCom_v_InputBuffer.Veh_AmbAirTemp_ValidityFlag = tempValid;
}

/* ===========================================================================
 * Name:	 UssCom_F_GetAmbientTemp
 * Remarks:  DD-ID: {5702EBCF-9FE2-4281-BEEC-3384C510FB51}
 *  Req.-ID: 14993481
 *  Req.-ID: 14993902
 *  Req.-ID: 14958936
 *  Req.-ID: 14959188
 *  Req.-ID: 14959191
 *  Req.-ID: 14959203
 * ===========================================================================*/
float UssCom_F_GetAmbientTemp(void)
{
	return UssCom_v_InputBuffer.Veh_AmbAirTemp_1Deg_F32;
}

/* ===========================================================================
 * Name:	 UssCom_F_GetAmbientTempValidity
 * Remarks:  DD-ID: {F45091CC-9205-4617-979B-98D8938375CF}
 *  Req.-ID: 14993481
 *  Req.-ID: 14993902
 *  Req.-ID: 14958936
 *  Req.-ID: 14959188
 *  Req.-ID: 14959191
 *  Req.-ID: 14959203
 * ===========================================================================*/
US_E_TempValidityFlag_t UssCom_F_GetAmbientTempValidity(void)
{
    return UssCom_v_InputBuffer.Veh_AmbAirTemp_ValidityFlag;
}
#endif /*USS_FEATURE_INPUT_PROCESS_AMBIENT_TEMP*/



/* ===========================================================================
 * Name:	 UssCom_CopyReceivedParkingMode
 * Remarks:  DD-ID: {0A0D0842-7717-4aa3-AAF0-9E9087090D37}
 * Req.-ID: 13396023
 * ===========================================================================*/
void UssCom_CopyReceivedParkingMode(uint32_t ReceivedParkingMode)
{
	UssCom_v_InputBuffer.ReceivedParkingMode = ReceivedParkingMode;
}

#if(USS_FEATURE_INPUT_PROCESS_GEAR == US_FEATURE_ON)
/* ===========================================================================
 * Name:	 UssCom_CopyVehGearValidityFlagInputBuffer
 * Remarks:  DD-ID: {16815C6E-72B7-4788-9D27-37F2FD840497}
 * ===========================================================================*/
void UssCom_CopyVehGearValidityFlagInputBuffer(US_E_GenericSignalValidityFlag_e validflag)
{
	UssCom_v_InputBuffer.GearSpeed_ValidityFlag = validflag;
}
#endif /*USS_FEATURE_INPUT_PROCESS_GEAR*/

/* ===========================================================================
 * Name:	 UssCom_F_GetGearSpeedValidity
 * Remarks:  DD-ID: {B59FE368-FFE0-4a95-83A4-B6043026562F}
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 *  Req.-ID: 14959555
 *  Req.-ID: 14959230
 *  Req.-ID: 13393741
 *  Req.-ID: 13396016
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 * ===========================================================================*/
US_E_GenericSignalValidityFlag_e UssCom_F_GetGearSpeedValidity(void)
{
	return UssCom_v_InputBuffer.GearSpeed_ValidityFlag;
}

#if(USS_FEATURE_INPUT_PROCESS_VEH_SPEED == US_FEATURE_ON)
/* ===========================================================================
 * Name:	 UssCom_CopyVehSpeedValidity
 * Remarks:  DD-ID: {3B1842E9-F19F-4e90-94EC-22A12F7A2609}
 * ===========================================================================*/
void UssCom_CopyVehSpeedValidity(US_E_GenericSignalValidityFlag_e tempValue)
{
	UssCom_v_InputBuffer.VehicleSpeed_ValidityFlag = tempValue;
}
/* ===========================================================================
 * Name:	 UssCom_CopyVehSpeedInputBuffer
 * Remarks:  DD-ID: {0D11D640-444C-45c7-B7B0-CB52ED1156BD}
 * Req.-ID: 14995319
 * Req.-ID: 14995521
 * ===========================================================================*/
void UssCom_CopyVehSpeedInputBuffer(float tempValue)
{
	UssCom_v_InputBuffer.Veh_VehicleSpeed_1Kph_F32 = tempValue;
}
#endif /*USS_FEATURE_INPUT_PROCESS_VEH_SPEED*/

/* ===========================================================================
 * Name:	 UssCom_F_GetVehSpeed
 * Remarks:  DD-ID: {3EC511DE-2926-4dd3-8C86-4B235EDCD383}
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 *  Req.-ID: 14959555
 *  Req.-ID: 14959230
 *  Req.-ID: 13393741
 *  Req.-ID: 13396016
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 * ===========================================================================*/
float UssCom_F_GetVehSpeed(void)
{
	return UssCom_v_InputBuffer.Veh_VehicleSpeed_1Kph_F32;
}

/* ===========================================================================
 * Name:	 UssCom_F_GetVehicleSpeedValidity
 * Remarks:  DD-ID: {8923A39D-DBF9-4798-8B15-8E63A7FBA946}
 * ===========================================================================*/
#if(QAC_WARNING_FIX == ME_FALSE)
US_E_GenericSignalValidityFlag_e UssCom_F_GetVehicleSpeedValidity(void)
{
	return UssCom_v_InputBuffer.VehicleSpeed_ValidityFlag;
}
#endif
/* ===========================================================================
 * Name:	 UssCom_CopyVehPrndlInputBuffer
 * Remarks:  DD-ID: {A1623A55-4199-45da-AD88-984C98BDAEE8}
 * ===========================================================================*/
void UssCom_CopyVehPrndlInputBuffer(US_E_App_Prndl_Status_e tempValue)
{
	UssCom_v_InputBuffer.Veh_Prndl_Gear_Status = (US_E_App_Prndl_Status_e)tempValue;
}

/* ===========================================================================
 * Name:	 UssCom_F_GetVehPrndl
 * Remarks:  DD-ID: {5467318D-5DD5-4428-BAED-D07C6E208CFE}
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 *  Req.-ID: 14959555
 *  Req.-ID: 14959230
 *  Req.-ID: 13393741
 *  Req.-ID: 13396016
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 * ===========================================================================*/
US_E_App_Prndl_Status_e UssCom_F_GetVehPrndl(void)
{
	return UssCom_v_InputBuffer.Veh_Prndl_Gear_Status;
}
#if (US_D_USE_EXTERNAL_ODOMETRY == ME_FALSE)
/* ===========================================================================
 * Name:	 UssCom_F_GetWSpeedRightRear
 * Remarks:  DD-ID: {A03B9D5F-C388-42c4-AB29-99D76B2A9639}
 * ===========================================================================*/
float32_t UssCom_F_GetWSpeedRightRear(void)
{
    return UssCom_v_InputBuffer.WSpeedRightRear;
}
/* ===========================================================================
 * Name: 	 UssCom_F_GetWSpeedLeftRear
 * Remarks:  DD-ID: {8383B4CC-8BF9-4c0f-A891-92C8EAC64A77}
 * ===========================================================================*/
float32_t UssCom_F_GetWSpeedLeftRear(void)
{
    return UssCom_v_InputBuffer.WSpeedLeftRear;
}
/* ===========================================================================
 * Name:	 UssCom_F_GetWheelPulseRightRear
 * Remarks:  DD-ID: {47A40B13-B96B-47bb-97C5-0DAA3B060A48}
 * ===========================================================================*/
uint8_t UssCom_F_GetWheelPulseRightRear(void)
{
    return UssCom_v_InputBuffer.WheelPulseRightRear;
}
/* ===========================================================================
 * Name:	 UssCom_F_GetWheelPulseLeft_Rear
 * Remarks:  DD-ID: {7C9E884B-89BB-401d-A278-1109E41A4613}
 * ===========================================================================*/
uint8_t UssCom_F_GetWheelPulseLeft_Rear(void)
{
    return UssCom_v_InputBuffer.WheelPulseLeft_Rear;
}
/* ===========================================================================
 * Name:	 UssCom_F_GetSASStatusAngleSafe
 * Remarks:  DD-ID: {55C5ABCD-8E37-4ee0-B1EA-11E3E1254582}
 * ===========================================================================*/
sint16_t UssCom_F_GetSASStatusAngleSafe(void)
{
    return (sint16_t)UssCom_v_InputBuffer.SASStatusAngleSafe;
}
/* ===========================================================================
 * Name: UssCom_F_GetWheelDirRightRear    
 * Remarks:  DD-ID: {0D7BF35E-65ED-458f-8069-A701CFB14059}
 * ===========================================================================*/
US_E_WheelDir_e UssCom_F_GetWheelDirRightRear(void)
{
	return UssCom_v_InputBuffer.WheelDirRightRear;
}
/* ===========================================================================
 * Name: UssCom_F_GetWheelDirLeftRear    
 * Remarks:  DD-ID: {FE1343C8-81D9-47ba-B709-7A8A80F798E9}
 * ===========================================================================*/
US_E_WheelDir_e UssCom_F_GetWheelDirLeftRear(void)
{
	return UssCom_v_InputBuffer.WheelDirLeftRear;
}
#endif
/* ===========================================================================
 * Name:	 ComInput_Init
 * Remarks:  DD-ID: {CE45985E-8F6A-4754-815D-F09371A52E27}
 * Req.-ID: 13396023
 * ===========================================================================*/

void ComInput_Init(void)
{
	US_S_TemperatureCompensation_t* pTempTable = NULL;

	//clear all to zero as baseline
	(void)memset(&UssCom_v_InputBuffer, 0, sizeof(UssCom_S_InputSignals_t));
	
	//set some default values
	UssCom_v_InputBuffer.Veh_AmbAirTemp_ValidityFlag = US_TEMPVALID_UNKNOWN;
	UssCom_v_InputBuffer.GearSpeed_ValidityFlag = US_SIGNALVALIDITY_UNKNOWN;
    UssCom_v_InputBuffer.Veh_VehicleSpeed_1Kph_F32 = 0.0f;
    
	/* Get temperature ranges for Calibration bins*/
    pTempTable = GetTemperatureCfg();
	if(pTempTable != NULL)
	{
       UssCom_v_InputBuffer.Veh_AmbAirTemp_1Deg_F32 = ((float)pTempTable->default_temp)/10.0f;
	}
	UssCom_v_InputBuffer.ReceivedParkingMode =(uint32_t) US_PARKMODE_PARKING;
    UssCom_v_InputBuffer.ReCfgAllowFlag = ME_FALSE;
    if(US_SnrCfg_Get_OperationMode() == (uint8_t)US_SNR_TEST_MODE)
    {
    	UssCom_v_InputBuffer.Veh_Prndl_Gear_Status = US_PRNDL_PARK;
    	UssCom_v_InputBuffer.GearSpeed_ValidityFlag =  (US_E_GenericSignalValidityFlag_e)US_SIGNALVALIDITY_VALID;
    }

}
/* ===========================================================================
 * Name:	 UssCom_F_GetParkingMode
 * Remarks:  DD-ID: {992CA76B-06F6-48c9-942B-C1069CF2BF28}
 * Req.-ID: 
 * ===========================================================================*/
/*Interface to get the Parking mode*/
uint8 UssCom_F_GetParkingMode(void)
{
	return UssCom_v_InputBuffer.ReceivedParkingMode;
}
/* ===========================================================================
 * Name:	 UssCom_CopyReCfgFlagBuffer
 * Remarks:  DD-ID: {DBC91A3E-07BB-40e5-9F8B-6DCE33C28125}
 * Req.-ID: 
 * ===========================================================================*/
void UssCom_CopyReCfgFlagBuffer(bool_t recfgflag)
{
	UssCom_v_InputBuffer.ReCfgAllowFlag = recfgflag;
}
/* ===========================================================================
 * Name:	 UssCom_F_GetReCfgAllowFlag
 * Remarks:  DD-ID: {198027A2-CDA9-4052-AB9F-742BD6E1E706}
 * Req.-ID: 13396023
 * ===========================================================================*/
bool_t UssCom_F_GetReCfgAllowFlag(void)
{
    return UssCom_v_InputBuffer.ReCfgAllowFlag;
}
