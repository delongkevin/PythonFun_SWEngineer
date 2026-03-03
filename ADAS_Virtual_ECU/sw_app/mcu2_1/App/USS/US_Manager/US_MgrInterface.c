/*
 * US_MgrInterface.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_MgrSensorProc.h"
#include "US_MgrInterface.h"
#include "US_MgrEnvCheck.h"
#include "US_MgrDiagnostic.h"
#include "US_SnrCfg_Global.h"

static bool_t UssMgr_bClearTestDataReq = ME_TRUE;

/*===========================================================================
 * \brief Populate com output buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks bool_t Whether or not data was successfully written.
 */
/* ===========================================================================
 * Name:	 UssMgr_PopulateComOutputBuffer
 * Remarks:  DD-ID: {F7C02B78-0CCC-43e1-84BE-10E988EB3A84}
 * Req.-ID: 13424090
 * ===========================================================================*/
bool_t UssMgr_PopulateComOutputBuffer(void)
{
    if (UssCom_LockOutputDataBuffer() == (bool_t)ME_TRUE)
    {	
		UssMgr_PopulateHardwareDiagnosticsInfo();
		UssCom_F_PopulateFiringModeInfo(US_GetTimeStampTimeMs(), (uint8_t)UssMgr_uGetCurParkingMode());
		UssCom_F_PopulateBlockageBit(US_GetTimeStampTimeMs());
        UssCom_F_PopulateFiringSensors();
        UssCom_F_PopulateSystemStatusInfo(US_GetTimeStampTimeMs());

        if (US_SnrCfg_F_bPopulateSnrSensitivity() == (bool_t)ME_TRUE)
        {
            UssCom_F_PopulateSensorSensitivityFlagList();
            US_SnrCfg_F_ClrPopulateSnrSensitivityFlag();
        }

        UssCom_F_PopulateFiringSequence();

		if (UssMgr_bClearTestDataReq == (bool_t)ME_TRUE)
		{
			UssCom_ClearTestDataOutputs();
			UssMgr_bClearTestDataReq = ME_FALSE;
		}
		else
		{
			UssCom_F_PopulateTestData();
		}

#if US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN
        UssCom_PopulateLogData();
#endif
        UssCom_UnlockOutputDataBuffer();

        return ME_TRUE; // Data was successfully written
    }
    else
    {
        return ME_FALSE; // Data was not written
    }
}


/*===========================================================================
 * \brief Populate diag flags only in com output buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks bool_t Whether or not data was successfully written.
 */
/* ===========================================================================
 * Name: UssMgr_PopulateDiagFlagsInComOutBuff    
 * Remarks:  DD-ID: {80A7C387-2267-4f1c-B258-B95889B472C7}
 * ===========================================================================*/
bool_t UssMgr_PopulateDiagFlagsInComOutBuff(void)
{
    if (UssCom_LockOutputDataBuffer() == (bool_t)ME_TRUE)
    {
        UssMgr_PopulateHardwareDiagnosticsInfo();

        UssCom_UnlockOutputDataBuffer();

        return ME_TRUE; // Data was successfully written
    }
    else
    {
        return ME_FALSE; // Data was not written
    }
}

/* ===========================================================================
 * Name: UssMgr_SetClearTestDataReq     
 * Remarks:  DD-ID: {CBB59468-6D60-484f-BD9C-A8F93871F126}
 * ===========================================================================*/
void UssMgr_SetClearTestDataReq(void)
{
	UssMgr_bClearTestDataReq = ME_TRUE;
}


/* ===========================================================================
 * Name:	 MEUssMgr_F_GetAirHumidity_v
 * Remarks:  DD-ID: {23FD0166-6DDB-4d51-A481-D2CB2B6937E4}
 * ===========================================================================*/

// no one calls this - doesn't anyone care about humidity???
#if(QAC_WARNING_FIX == ME_FALSE)
void MEUssMgr_F_GetAirHumidity_v(float32_t *AirHumidity)
{
    *AirHumidity = (float32_t)MEUssMgr_v_AirHumiOutsd;
}
#endif
/* ===========================================================================
 * Name:	 aUSSMgr_F_UssMgrMod_v
 * Remarks:  DD-ID: {A15E29A4-CB0E-487b-9CA5-014D1D888170}
 * ===========================================================================*/
#if(QAC_WARNING_FIX == ME_FALSE)
uint8_t aUSSMgr_F_UssMgrMod_v(void)
{
#if 0
    uint8_t RetValue;
    MEUssMgr_S_InputSignals20ms_t* Buff_pt = UssMgr_psGetInputBuffer();

    /* Check if the module is activated from outside. */
    if((RTE_MODE_MEUssMgr_UssMgrMod_aUSSMgr_D_ACTIVE == Buff_pt->ModState_u8) && TEST_COLLECT_DATA_FROM_CAN == 0)
    {
        RetValue = 1;
    }
    else
    {
        RetValue = 0;
    }

    return RetValue;
#endif
    return 0u;
}
#endif

#if 0
Std_ReturnType aUSSMgr_F_GetClusterRec_b(pUS_E_ClusterID_t i_ClusterID_e, uint8_t i_RecordID_u8, const pUS_S_ClusterRec_t** o_ClusterRec_ppt)
{
    Std_ReturnType Result = E_OK;
    switch (i_ClusterID_e)
    {
        case pUS_E_REAR_ID:
            *o_ClusterRec_ppt = &(UssMgr_sLegacyRearSnr_at[i_RecordID_u8]);
            break;
        case pUS_E_FRONT_ID:
            *o_ClusterRec_ppt = &(UssMgr_sLegacyFrntSnr_at[i_RecordID_u8]);
            break;
            /*case pUS_E_SIDE_ID:
             *o_ClusterRec_ppt  = &(MEUssMgr_v_SideCluster_at[i_RecordID_u8]);
             break;*/
        default:
            break;
    }
    return Result;
}
#endif

#if 0
Std_ReturnType aUSSMgr_F_CleanClusterRec_b(pUS_E_ClusterID_t i_ClusterID_e, uint8_t i_RecordID_u8)
{
    Std_ReturnType Result = E_OK;
    switch (i_ClusterID_e)
    {
        case pUS_E_REAR_ID:
            memset(&UssMgr_sLegacyRearSnr_at[i_RecordID_u8], 0, sizeof(pUS_S_ClusterRec_t));
            break;
        case pUS_E_FRONT_ID:
            memset(&UssMgr_sLegacyFrntSnr_at[i_RecordID_u8], 0, sizeof(pUS_S_ClusterRec_t));
            break;
            /*case pUS_E_SIDE_ID:
             memset(&MEUssMgr_v_SideCluster_at[i_RecordID_u8], 0, sizeof(pUS_S_ClusterRec_t));
             break;*/
        default:
            break;
    }
    return Result;
}
#endif

/* This will go away with new design */
#if(QAC_WARNING_FIX == ME_FALSE)
void UssMgr_InitSensorsInClusterList(void)
{
#if 0
    /*For Tmp use for OD*/
    MEUssMgr_v_Rear_SensorClusterList.NumSensors_u8 = 6;
    MEUssMgr_v_Rear_SensorClusterList.SensorIDs_at[0] = pUS_E_REAR_SIDE_LEFT_ID;
    MEUssMgr_v_Rear_SensorClusterList.SensorIDs_at[1] = pUS_E_REAR_OUTER_LEFT_ID;
    MEUssMgr_v_Rear_SensorClusterList.SensorIDs_at[2] = pUS_E_REAR_INNER_LEFT_ID;
    MEUssMgr_v_Rear_SensorClusterList.SensorIDs_at[3] = pUS_E_REAR_INNER_RIGHT_ID;
    MEUssMgr_v_Rear_SensorClusterList.SensorIDs_at[4] = pUS_E_REAR_OUTER_RIGHT_ID;
    MEUssMgr_v_Rear_SensorClusterList.SensorIDs_at[5] = pUS_E_REAR_SIDE_RIGHT_ID;

    MEUssMgr_v_Front_SensorClusterList.NumSensors_u8 = 6;
    MEUssMgr_v_Front_SensorClusterList.SensorIDs_at[0] = pUS_E_FRONT_SIDE_LEFT_ID;
    MEUssMgr_v_Front_SensorClusterList.SensorIDs_at[1] = pUS_E_FRONT_OUTER_LEFT_ID;
    MEUssMgr_v_Front_SensorClusterList.SensorIDs_at[2] = pUS_E_FRONT_INNER_LEFT_ID;
    MEUssMgr_v_Front_SensorClusterList.SensorIDs_at[3] = pUS_E_FRONT_INNER_RIGHT_ID;
    MEUssMgr_v_Front_SensorClusterList.SensorIDs_at[4] = pUS_E_FRONT_OUTER_RIGHT_ID;
    MEUssMgr_v_Front_SensorClusterList.SensorIDs_at[5] = pUS_E_FRONT_SIDE_RIGHT_ID;
#endif
}
#endif
#if 0
void aUSSMgr_F_GetSensorsInCluster_v(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_SensorClusterList_t** o_SensorList_ppt)
{
    switch (i_ClusterID_e)
    {
        case pUS_E_REAR_ID:
            *o_SensorList_ppt = &MEUssMgr_v_Rear_SensorClusterList;
            break;
        case pUS_E_FRONT_ID:
            *o_SensorList_ppt = &MEUssMgr_v_Front_SensorClusterList;
            break;

        default:
            break;
    }
}
#endif
//==========================================================================================
#if 0
void UssMgr_SetSnrDataNoisy(bool_t *isNoisy)
{
    UssMgr_sInterfaceData.SnrDataNoisy[pUS_E_FRONT_ID] = isNoisy[pUS_E_FRONT_ID];
    UssMgr_sInterfaceData.SnrDataNoisy[pUS_E_REAR_ID] = isNoisy[pUS_E_REAR_ID];
}

uint8_t UssMgr_uGetBlockageSndBurstCnt(void)
{
    return UssMgr_sInterfaceData.OD_Blockage_SndBurstCnt;
}

#if 0
void UssMgr_SetDistToObstacle(aUSOD_S_DistToSensor_t* psDistToObstacleList)
{
    aUSSCom_F_Set_ObsDirectEcho_v();  // \todo jp why is this here

    UssMgr_sInterfaceData.OD_DireDist_pt = psDistToObstacleList;
}
#endif


bool_t UssMgr_bGetBlockageValidJudge(void)
{
    return UssMgr_sInterfaceData.OD_Blockage_ValidJudge;
}

void UssMgr_SetSnrBlockage(bool_t *SnrBlockage)
{
    uint8_t i;
    for (i = 0; i < 12; i++)
    {
        UssMgr_sInterfaceData.OD_SingleSnrBlockage[i] = SnrBlockage[i];
    }
}

uint8_t * UssMgr_GetSnrBlockage(void)
{
    return &UssMgr_sInterfaceData.OD_SingleSnrBlockage[0];
}


void UssMgr_SetSingleBlockageRS(bool_t OD_Blockage_SingleBlockageRS)
{
    UssMgr_sInterfaceData.OD_Blockage_SingleBlockageRS = OD_Blockage_SingleBlockageRS;
}

void UssMgr_SetBlockageTrack(pUS_S_BlockageTrack_t *sBlockageTrack)
{
    uint8_t i;
    for (i = 0; i < 12; i++)
    {
        UssMgr_sInterfaceData.OD_BlockageTrack[i] = sBlockageTrack[i];
    }
}

void UssMgr_sGetBlockageTrack(pUS_S_BlockageTrack_t* sBlockageTrack)
{
    uint8_t i;
    for (i = 0; i < 12; i++)
    {
        sBlockageTrack[i] = UssMgr_sInterfaceData.OD_BlockageTrack[i];
    }
}

void UssMgr_SetBlockageAllSnrLockRS(uint16_t OD_Blockage_FinalRS)
{
    UssMgr_sInterfaceData.OD_Blockage_AllSnrLockRS = OD_Blockage_FinalRS;
}

pUS_E_DEGROWLER_MOD_t UssMgr_eGetGrowlerMode(void)
{
    return UssMgr_sInterfaceData.USS_DeGrowlerMod;
}

pUS_E_USSCtrlSytStatus_t UssMgr_eGetSysStatus(void)
{
    return UssMgr_sInterfaceData.USSC_SysStatus;
}

void UssMgr_sGetBurstMode(pUS_S_SnrBurstMode_t * sBurstMode)
{
    sBurstMode->PDC[0]    = UssMgr_sInterfaceData.BurstMode.PDC[0];
    sBurstMode->PDC[1]    = UssMgr_sInterfaceData.BurstMode.PDC[1];
    sBurstMode->PSM[0]    = UssMgr_sInterfaceData.BurstMode.PSM[0];
    sBurstMode->PSM[1]    = UssMgr_sInterfaceData.BurstMode.PSM[1];
    sBurstMode->CleanData = UssMgr_sInterfaceData.BurstMode.CleanData;
}

pUS_E_CleanData_t UssMgr_eGetIsBurstCleanData(void)
{
    return UssMgr_sInterfaceData.BurstMode.CleanData;
}

void UssMgr_SetApaMode(pUS_E_APAType_Mod_t eAPAMode)
{
    UssMgr_sInterfaceData.USS_APAMod    = eAPAMode;
}

void UssMgr_SetApaSpeedMode(pUS_E_VehSpeed_Mod_t eAPASpeedMode)
{
    UssMgr_sInterfaceData.USSC_SpdMode  = eAPASpeedMode;
}


void UssMgr_SetSysStatus(pUS_E_USSCtrlSytStatus_t eSysStatus)
{
    UssMgr_sInterfaceData.USSC_SysStatus  = eSysStatus;
}


void UssMgr_SetCheckEnvStage(pUS_E_USSCtrl_CheckEnvStage_t eCheckEnvStage)
{
    UssMgr_sInterfaceData.USS_CheckEnvStage  = eCheckEnvStage;
}

void UssMgr_SetProfileTypes(pUS_E_ProfileType_t eProfileTypeF, pUS_E_ProfileType_t eProfileTypeR)
{
    UssMgr_sInterfaceData.USS_BurstProfileTypeF  = eProfileTypeF;
    UssMgr_sInterfaceData.USS_BurstProfileTypeR  = eProfileTypeR;
}


void UssMgr_SetTempDeltaGainType(uint8_t uTempGainType)
{
    UssMgr_sInterfaceData.USS_TempGainType = uTempGainType;
}

uint8_t UssMgr_uGetTempDeltaGainType(void)
{
    return UssMgr_sInterfaceData.USS_TempGainType;
}

sint8_t UssMgr_sGetTempDeltaGain(void)
{
  return UssMgr_sInterfaceData.USS_TempGain_Mod;
}

void UssMgr_SetTempGainTime(uint32_t uTempGainTime)
{
    UssMgr_sInterfaceData.USS_TempGain_Times = uTempGainTime;
}

uint32_t UssMgr_uGetTempGainTime(void)
{
    return UssMgr_sInterfaceData.USS_TempGain_Times;
}


void UssMgr_abGetNFDburstFlags(bool_t *abNFDburst)
{
    abNFDburst[pUS_E_FRONT_ID] = UssMgr_sInterfaceData.USSC_NFDburst_b[pUS_E_FRONT_ID];
    abNFDburst[pUS_E_REAR_ID]  = UssMgr_sInterfaceData.USSC_NFDburst_b[pUS_E_REAR_ID];
}

pUS_E_APAType_Mod_t UssMgr_eGetAPAMode(void)
{
    return UssMgr_sInterfaceData.USS_APAMod;
}

pUS_E_APAType_Mod_t UssMgr_eGetCmdAPAMode(void)
{
    pUS_E_APAType_Mod_t eAPAMod = pUS_E_APA_RAEB;

    /*if (DisConnectProbablyF || DisConnectProbablyR || UssMgr_sInterfaceData.InitErr_b)
    {
        eAPAMod = pUS_E_APA_SNR_ERR;
    }
    else */
	if (UssMgr_sInterfaceData.MalfunctionOnlyBlockage)
    {
        eAPAMod = pUS_E_APA_RAEB;
    }
    else if (UssMgr_sInterfaceData.AmzEcuMod == pUS_E_AMZ_Mode_Malfunction)
    {
        eAPAMod = pUS_E_APA_Malfunction;
    }
    else if (UssMgr_sInterfaceData.AmzEcuMod == pUS_E_AMZ_Mode_EMItest)
    {
        eAPAMod = pUS_E_APA_EMI;
    }
    else if (UssMgr_sInterfaceData.AmzEcuMod == pUS_E_AMZ_Mode_EMStest)
    {
        eAPAMod = pUS_E_APA_EMS;
    }
    else if (UssMgr_sInterfaceData.AmzEcuMod == pUS_E_AMZ_Mode_Envelope)
    {
        eAPAMod = pUS_E_APA_Envelope;
    }
    else
    {
        eAPAMod = pUS_E_APA_RAEB;
    }

    return eAPAMod;
}

bool_t UssMgr_bGetSnrDataNotOK(void)
{
    return UssMgr_sInterfaceData.SnrDataNotOK;
}

void UssMger_SetCheckEnvStage(uint8_t uCheckEnvStage)
{
    UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp = uCheckEnvStage;
}

pUS_E_ENVType_Mod_t UssMgr_eGetGroundType(void)
{
    return UssMgr_sInterfaceData.USSC_GroundType;
}

void UssMgr_SetBlockageStatusFlag(uint8_t uBlockageStatus)
{
    UssMgr_sInterfaceData.USSC_BlockageStatus = uBlockageStatus;
    //MEUssMgr_v_BlockageDebugFlag.Debug_Blockage_7 = ME_TRUE;
}

void UssMgr_SetClearSensorBlockageErr(void)
{
    uint8_t i;
    for (i = 0; i < 12; i++)
    {
        UssMgr_sInterfaceData.OD_BlockageTrack[i].BlockageTrack_Cnt = 0;
    }
    UssMgr_sInterfaceData.USSC_GroundType_DiffCnt = 0;
    UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky = ME_FALSE;
}

bool_t UssMgr_bGetBlockageLockRS(void)
{
    return UssMgr_sInterfaceData.USSC_Blockage_LockRS;
}

bool_t UssMgr_bIsResetParamsNeeded(void)
{
    if (UssMgr_sInterfaceData.USSC_ResetPara == ME_TRUE)
    {
        UssMgr_sInterfaceData.USSC_ResetPara = ME_FALSE;  // Reset flag to false.
        return ME_TRUE;
    }
    return ME_FALSE;
}
bool_t UssMgr_bGetIsTempSnrUpdateNeeded(void)
{
    return UssMgr_sInterfaceData.NeedUpdateTempFromSnr;
}

bool_t UssMgr_bGetReqSnrFeatureFlag(void)
{
    return UssMgr_sInterfaceData.ReqSnrFeatureFlag;
}

bool_t UssMgr_bGetReqSnrCompGain(void)
{
    return UssMgr_sInterfaceData.ReqSnrCompGain;
}

bool_t UssMgr_bGetReqSnr(void)
{
    return UssMgr_sInterfaceData.ReqSnr;
}

bool_t UssMgr_bGetDSIerrFlag(void)
{
    return UssMgr_sInterfaceData.DSI_CFG_TRE_DOWN;
}

void UssMgr_psGetEdiConfig(pUS_S_EDICfg_t *psEdiCfg)
{
    psEdiCfg->Mode          = UssMgr_sInterfaceData.SetCmd_EDIcfg_t.Mode;
    psEdiCfg->SampleTime    = UssMgr_sInterfaceData.SetCmd_EDIcfg_t.SampleTime;
    psEdiCfg->StartTime     = UssMgr_sInterfaceData.SetCmd_EDIcfg_t.StartTime;
}


void UssMgr_GetEnvelopeSendingSnr(uint8_t *uSendingSensor,
                                  pUS_E_ProfileType_t *eEnvProfile) //1~12 F1~F6,R1~R6
{
    *uSendingSensor   = UssMgr_sInterfaceData.SetCmd_Envelope_SendingSensor;
    *eEnvProfile      = UssMgr_sInterfaceData.SetCmd_Envelope_Profile;
}

#if 0
uint8_t UssMgr_GetSendingSnr(pUS_E_ClusterID_t uSensorClusterID) //1~12 F1~F6,R1~R6
{
    return UssMgr_sInterfaceData.OD_DireDist_pt->SendingSnr[uSensorClusterID];
}
#endif

pUS_E_AmazonSetCmd_t UssMgr_eGetSetCmd(void)
{
    pUS_E_AmazonSetCmd_t eSetCmd = pUS_E_AMZ_SetCmd_None;

    if (UssMgr_sInterfaceData.SetCmd_Received == ME_TRUE)
    {
        eSetCmd = UssMgr_sInterfaceData.SetCmd;
        UssMgr_sInterfaceData.SetCmd_Received = ME_FALSE;
    }

    return eSetCmd;
}

void UssMgr_psGetNFDConfig(pUS_S_NFDCfg_t *psNFDCfg)
{
    psNFDCfg->LimitTime = UssMgr_sInterfaceData.SetCmd_NFDcfg_t.LimitTime;
    psNFDCfg->Sen =UssMgr_sInterfaceData.SetCmd_NFDcfg_t.Sen;
    psNFDCfg->Th = UssMgr_sInterfaceData.SetCmd_NFDcfg_t.Th;
}

/*
 * DIRECT ACCESS TO INPUT BUFFER - should clean that up
 */
float32_t UssMgr_fGetAirTemp(void)
{
    return MEUssMgr_v_AirTempOutsd; // comes from input
}

//extern aUSOD_S_DistToSensor_t aJobUSOD_v_OutAllDist;  // \TODO jp - Create accessor or do differently

void UssMgr_InitInterface()
{
   uint8_t i;
    memset(&UssMgr_sInterfaceData, 0, sizeof(UssMgr_sInterfaceData));

    UssMgr_sInterfaceData.USS_DeGrowlerMod = pUS_E_NO_DEGROWLER;
    UssMgr_sInterfaceData.USS_Front_GlowlerType = pUS_E_NO_GROWLER;
    UssMgr_sInterfaceData.USS_Rear_GlowlerType = pUS_E_NO_GROWLER;
    UssMgr_sInterfaceData.USS_GrowlerStage = US_GROWLER_DETECT;
    UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Initial;
    UssMgr_sInterfaceData.SetTestMode = pUS_E_AMZ_TestMode_Normal;

    /*Blocakge*/
    UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp = e_aJobUSSCtrl_Check_Finished;
    UssMgr_sInterfaceData.OD_Blockage_SndBurstCnt = 0;
    UssMgr_sInterfaceData.USSC_Blockage_LockRS = pUS_E_BlockageUnlock;
    UssMgr_sInterfaceData.OD_Blockage_AllSnrLockRS = 0;
    UssMgr_sInterfaceData.USSC_GroundType = pUS_E_FLAT;
    UssMgr_sInterfaceData.OD_Blockage_ValidJudge = ME_FALSE;
    UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_NOSND;
    UssMgr_sInterfaceData.OD_Blockage_SingleBlockageRS = pUS_E_NoBlockage;
    UssMgr_sInterfaceData.USSC_GroundType_DiffCnt = 0;
    UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky = ME_FALSE;
    UssMgr_sInterfaceData.USSC_BlockageStatus = pUS_E_NOACTIVE;
    for (i = 0; i < 12; i++)
    {

        UssMgr_sInterfaceData.OD_SingleSnrBlockage[i] = pUS_E_NOUSE;
        UssMgr_sInterfaceData.OD_BlockageTrack[i].BlockageTrack_Cnt = 0;
        UssMgr_sInterfaceData.OD_BlockageTrack[i].BlockageTrack_Lock = pUS_E_BlockageUnlock;
    }
#if UART_SUPPORTED
    UssCom_LogD("[%s(%d)][SysMode] Initial Mode!", __func__, __LINE__);
#endif


    USSCom_F_bUpdateSendOjectInfo(ME_TRUE);
    

    UssMgr_sInterfaceData.BurstMode.PDC[pUS_E_FRONT_ID] = pUS_E_BURST_LOW;
    UssMgr_sInterfaceData.BurstMode.PDC[pUS_E_REAR_ID] = pUS_E_BURST_LOW;
    UssMgr_sInterfaceData.BurstMode.PSM[pUS_E_FRONT_ID] = pUS_E_BURST_HIGH;
    UssMgr_sInterfaceData.BurstMode.PSM[pUS_E_REAR_ID] = pUS_E_BURST_HIGH;
    UssMgr_sInterfaceData.BurstMode.CleanData = pUS_E_CleanData_Not;
    UssMgr_sInterfaceData.USS_BurstProfileTypeF = pUS_E_PROFILE_A;
    UssMgr_sInterfaceData.USS_BurstProfileTypeR = pUS_E_PROFILE_A;
    UssMgr_sInterfaceData.SnrDataNotOK = ME_FALSE;
}

#if 0
uint16_t UssMgr_uGetDirectEchoAt(pUS_E_SensorID_t eSensorID)
{
    uint16_t DirectEcho;
    DirectEcho = UssMgr_sInterfaceData.OD_DireDist_pt->DistToSensor_at[eSensorID] >= 511 ?
                        0 : UssMgr_sInterfaceData.OD_DireDist_pt->DistToSensor_at[eSensorID];
    return DirectEcho;
}
#endif

UssMgr_sInterfaceData_t* UssMgr_sGetInterfaceDataptr(void)
{
    return &UssMgr_sInterfaceData;
}
#endif
#if 0
void SetAmzEcuMode(void)
{
    S_ErrHandling_DiagInfoSnr_t *lDiagInfoSnrErrorHandlePtr;

    lDiagInfoSnrErrorHandlePtr = aUSMgr_F_DiagInfoSnrErrorHandlePtr();

    if (lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_EEPROM_Fail || lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_RAM_Fail
            || (ME_TRUE == aUSMgr_F_DiagInfoEEPROMFailStatus()))
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_Fatal)
            UssCom_LogD("[%s(%d)][SysMode] Fatal Error Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Fatal;
        return;
    }
    UssMgr_sInterfaceData.MalfunctionOnlyBlockage = ME_FALSE;
    if (//UssMgr_sOutputBuffer.DiagInfo_ECU_High_Voltage || UssMgr_sOutputBuffer.DiagInfo_ECU_Low_Voltage
            (ME_TRUE == aUSSMgr_F_GetDiagInfoHighVtgStatus()) || (ME_TRUE == aUSSMgr_F_GetDiagInfoLowVtgStatus())
            || lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Disconnect || lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_High_Voltage
            || lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Low_Voltage || lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Blockage
            || (ME_TRUE == aUSSMgr_F_GetDiagInfoTransducerError()) || lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Comm_Error
            || lDiagInfoSnrErrorHandlePtr->DiagInfo_FW_Inconsistant_Snr)
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_Malfunction)
            UssCom_LogD("[%s(%d)][SysMode] Malfunction Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Malfunction;

        if (//UssMgr_sOutputBuffer.DiagInfo_ECU_High_Voltage == 0 && UssMgr_sOutputBuffer.DiagInfo_ECU_Low_Voltage == 0
                (ME_FALSE == aUSSMgr_F_GetDiagInfoHighVtgStatus()) && (ME_FALSE == aUSSMgr_F_GetDiagInfoLowVtgStatus())
                && lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Disconnect == 0 && lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_High_Voltage == 0
                && lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Low_Voltage == 0 && lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Blockage > 0
                && (ME_FALSE == aUSSMgr_F_GetDiagInfoTransducerError()) == 0 && lDiagInfoSnrErrorHandlePtr->DiagInfo_Snr_Comm_Error == 0
                && lDiagInfoSnrErrorHandlePtr->DiagInfo_FW_Inconsistant_Snr == 0)
        {
            UssMgr_sInterfaceData.MalfunctionOnlyBlockage = ME_TRUE;
        }
        return;
    }
    if (aUSSMgr_F_GetDiagInfoDisturbanceDetected())
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_Degrowler)
            UssCom_LogD("[%s(%d)][SysMode] De-growler Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Degrowler;
        return;
    }
    if (UssMgr_sInterfaceData.USSC_SysStatus != E_aJobUSSCtrl_RUNNING)
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_Initial)
            UssCom_LogD("[%s(%d)][SysMode] Initial Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Initial;
        return;
    }
    if (UssMgr_sInterfaceData.SetTestMode == pUS_E_AMZ_TestMode_EMI)
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_EMItest)
            UssCom_LogD("[%s(%d)][SysMode] EMI test Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_EMItest;
        return;
    }
    else if (UssMgr_sInterfaceData.SetTestMode == pUS_E_AMZ_TestMode_EMS)
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_EMStest)
            UssCom_LogD("[%s(%d)][SysMode] EMS test Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_EMStest;
        return;
    }
    else if (UssMgr_sInterfaceData.SetTestMode == pUS_E_AMZ_TestMode_DebugEnvelopeMode)
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_Envelope)
            UssCom_LogD("[%s(%d)][SysMode] Debug Envelope test Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Envelope;
        return;
    }
    else
    {
        if (UssMgr_sInterfaceData.AmzEcuMod != pUS_E_AMZ_Mode_Normal)
            UssCom_LogD("[%s(%d)][SysMode] Normal Mode!", __func__, __LINE__);
        UssMgr_sInterfaceData.AmzEcuMod = pUS_E_AMZ_Mode_Normal;
        return;
    }
}
#endif

#if 0
pUS_E_Dist_Mod_t* UssMgr_GetDistMod(pUS_E_ClusterID_t i_ClusterID_e, pUS_E_Dist_Mod_t* o_DistMod_pt)
{
    UssMgr_sInterfaceData_t* Buff_pt = NULL;
    MEUssMgr_F_GetIntermediateBuffer_v(&Buff_pt);

    pUS_E_Dist_Mod_t* pDistMod;

    switch (i_ClusterID_e)
    {
        case pUS_E_FRONT_ID:
            *pDistMod = Buff_pt->OD_Front_Dist_Mod;
            break;
        case pUS_E_REAR_ID:
            *pDistMod = Buff_pt->OD_Rear_Dist_Mod;
            break;
        case pUS_E_SIDE_ID:
            *pDistMod = Buff_pt->OD_Side_Dist_Mod;
            break;
        default:
            *pDistMod = Buff_pt->OD_Rear_Dist_Mod;
            break;
    }

    return pDistMod;
}

#endif
