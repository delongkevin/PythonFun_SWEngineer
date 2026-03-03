
#include "US_CtrlInterface.h"
/*
* #uint8_t aUSSCtrlDP_F_GetMode_u8(void)
* #{
* #    uint8_t retVal;
* #    retVal = aUSSMgr_F_UssMgrMod_v();
* #    return retVal;
* #}
*/
#if 0
bool_t UssCtrl_bNeedResetPara(void)
{
    uint8_t retVal;
    retVal = UssMgr_bIsResetParamsNeeded();
    return retVal;
}
/*
* #void aUSSCtrlDP_F_SnrFwNotSync_v(pUS_E_SnrFwSync_t SnrFwSync)
* #{
* #    * #aUSSMgr_F_Set_SnrFwNotSync_v(SnrFwSync);
* #    \aUSSMgr_F_SetDiagInfoSnrFwNotSync(SnrFwSync);
* #}
*/
void aUSSCtrlDP_F_SnrDisc_v(uint16_t SnrDisc)
{
   /* #aUSSMgr_F_Set_SnrDisc_v(SnrDisc);  */
    aUSSMgr_F_SetDiagInfoSnrDisc(SnrDisc);
}

void aUSSCtrlDP_F_SnrErrAuto_v(bool_t isErr)
{
   /* #aUSSMgr_F_Set_SnrErrAuto_v(isErr);  */
    aUSSMgr_F_SetDiagInfoSnrErrAuto(isErr);
}
#endif
/*
* #Std_ReturnType aUSSCtrlDP_F_SetProfileCmd_b(pUS_E_ClusterID_t ClusterID, uint8_t SensorBitMap, pUS_E_ProfileType_t ProfileType, uint8_t Number,
* #        pUS_S_ProfileCfg_t* Cfg)
* #{
* #    Std_ReturnType retVal;
* #    retVal = aUSSMgr_F_SetProfileCmd_b(ClusterID, SensorBitMap, ProfileType, Number, Cfg);
* ##if 0
* #    aUSS_D_LogWarning( "SetProfileA \n ClusterID = %d \n SensorBitMap = %d \n nPulses_N = %d \n nPulses_C = %d \n Current = %d \n G_dig = %d \n G_ana = %d \n BW = %d"
* #            "\n CN1 = %d \n CW1 = %d \n CN2 = %d \n CW2 = %d \n ATG_on = %d \n STC_on = %d \n FTC_on = %d \n NFD_on = %d",
* #            ClusterID,
* #            SensorBitMap,
* #            Cfg->nPulses_N,
* #            Cfg->nPulses_C,
* #            Cfg->Current ,
* #            Cfg->G_dig ,
* #            Cfg->G_ana ,
* #            Cfg->BW ,
* #            Cfg->CN1 ,
* #            Cfg->CW1 ,
* #            Cfg->CN2 ,
* #            Cfg->CW2 ,
* #            Cfg->ATG_on ,
* #            Cfg->STC_on ,
* #            Cfg->FTC_on ,
* #            Cfg->NFD_on );
* ##endif
* #    return retVal;
* #}

* #bool_t aUSSCtrlDP_F_GetClusterRec_b(pUS_E_ClusterID_t i_ClusterID_e, uint8_t i_RecordID_u8, const pUS_S_ClusterRec_t** o_ClusterRec_ppt)
* #{
* #    bool_t retVal;
* #    retVal = (E_OK == aUSSMgr_F_GetClusterRec_b(i_ClusterID_e, i_RecordID_u8, o_ClusterRec_ppt)) ? E_OK : E_NOT_OK;
* #    return retVal;
* #}

* #void aUSSCtrlDP_F_GetAirTempOutsd_v(float32_t *AirTempOutsd)
* #{
* #   \ MEUssMgr_F_GetAirTemp_v(AirTempOutsd);
* #}

* #void aUSSCtrlDP_F_GetSensorsInCluster_v(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_SensorClusterList_t** o_SensorList_ppt)
* #{
* #   \ aUSSMgr_F_GetSensorsInCluster_v(i_ClusterID_e, o_SensorList_ppt);
* #}

* #Std_ReturnType aUSSCtrlDP_F_IsPowerOn(void)
* #{
* #    return aUSSMgr_F_IsPowerOn();
* #}
* #\TODO jp - NO!  Put buffer accessor with buffer
* #float32_t aUSSCtrlDP_F_GetUpdate_SpeedCmMsF32_v(void)
* #{
* #    float32_t ActValue = 0.0f;
* #    MEUssMgr_S_InputSignals20ms_t* Buff_pt = UssMgr_psGetInputBuffer();
* #    ActValue = Buff_pt->KM_Speed_cm_ms;
* #    return ActValue;
* #}
* #
* #* #\TODO jp - NO!  Put buffer accessor with buffer
* #uint8_t aUSSCtrlDP_F_GetTSLPosnTCMU8_v(void)
* #{
* #    MEUssMgr_S_InputSignals20ms_t* Buff_pt = UssMgr_psGetInputBuffer();
* #    return Buff_pt->Veh_TSLPosnTCM;
* #}
*/
