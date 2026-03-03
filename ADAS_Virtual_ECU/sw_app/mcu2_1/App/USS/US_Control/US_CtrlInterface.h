/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   aUSSCtrlDP
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *   This component implements the input/output data interface of USSCtrl
 *   using IDataProvider. The functions are already declared at IUSSCtrl
 * ======================================================================== */

#ifndef _USS_CTRL_INTERFACE
#define _USS_CTRL_INTERFACE

#include "US_ME_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
/* +++ Public Typedefinitions, Enumerations, Defines ++++++++++++++++++++++ */

/* +++ Public Variables, Constants ++++++++++++++++++++++++++++++++++++++++ */

/* +++ Public Macros ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* +++ Public Function Prototypes +++++++++++++++++++++++++++++++++++++++++ */

/*comment out uint8_t aUSSCtrlDP_F_GetCmdQueue_u8(pUS_E_ClusterID_t i_ClusterID_e, const pUS_E_ClusterCmd_t* o_Queue_pat[]) */
uint8_t aUSSCtrlDP_F_GetMode_u8(void);
bool_t UssCtrl_bNeedResetPara(void);
void aUSSCtrlDP_F_SnrDisc_v(uint16_t SnrDisc);
void aUSSCtrlDP_F_SnrErrAuto_v(bool_t isErr);
float32_t aUSSCtrlDP_F_GetUpdate_SpeedCmMsF32_v(void);
uint8_t aUSSCtrlDP_F_GetTSLPosnTCMU8_v(void);
void aUSSCtrlDP_F_GetAirTempOutsd_v(float32_t *AirTempOutsd);
Std_ReturnType aUSSCtrlDP_F_IsPowerOn(void);
#if(QAC_WARNING_FIX == ME_FALSE)
/*comment out uint8_t aUSSCtrlDP_F_GetNumClusterRec_u8(pUS_E_ClusterID_t i_ClusterID_e) */
/* comment out bool_t aUSSCtrlDP_F_GetClusterRec_b(pUS_E_ClusterID_t i_ClusterID_e, uint8_t i_RecordID_u8, const pUS_S_ClusterRec_t** o_ClusterRec_ppt) ;*/
/* comment out void aUSSCtrlDP_F_GetCalib_v(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_ClusterCalib_t **o_Calib_ppt); */
/* comment out void aUSSCtrlDP_F_GetSnrTemp_v(pUS_E_ClusterID_t i_ClusterID_e, sint16_t* o_Temp_ps16) ;*/
/* comment out void aUSSCtrlDP_F_SnrFwNotSync_v(pUS_E_SnrFwSync_t SnrFwSync); */
/* comment out void aUSSCtrlDP_F_GetSetCmd_v(pUS_E_AmazonSetCmd_t *SetCmd; */
/* comment out void aUSSCtrlDP_F_GetEdiConfig_v(pUS_S_EDICfg_t *EdiCfg);*/
/* comment out void aUSSCtrlDP_F_GetNFDConfig_v(pUS_S_NFDCfg_t *NFDCfg); */
/* comment out void aUSSCtrlDP_F_GetEnvelopeSendingSnr_v(uint8_t *snr, pUS_E_ProfileType_t *profile); 1~12 F1~F6,R1~R6 */
/* comment out void UssCtrlDP_GetNeedUpdateTempFromSnr(bool_t *NeedUpdateTempFromSnr); */
/* comment out void UssCtrlDP_GetReqSnrFeatureFlag(bool_t *ReqSnrFeatureFlag); */
/* comment out void UssMgr_bGetReqSnrCompGain(bool_t *ReqSnrCompGain); */
/* comment out void aUSSCtrlDP_F_GetEEData_v(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_ClusterCalib_t** o_Calib_ppt);*/
/* comment out void aUSSCtrlDP_F_GetSensorsInCluster_v(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_SensorClusterList_t** o_SensorList_ppt);*/
/* comment out void aUSSCtrlDP_F_Get_DistMod_v(pUS_E_ClusterID_t i_ClusterID_e, pUS_E_Dist_Mod_t* o_DistMod_pt);*/
/* comment out void aUSSCtrlDP_F_Get_OBTypeMod_v(pUS_E_ClusterID_t i_ClusterID_e, pUS_E_OBType_Mod_t* o_OBTypeMod_pt); */
/* comment out void aUSSCtrlDP_F_Get_FilterMod_v(pUS_E_ClusterID_t i_ClusterID_e, pUS_E_EchoInfoType_t* o_FilterMod_pt); */
/* comment out void UssMgr_eGetIsBurstCleanData(pUS_E_CleanData_t *CleanData); */
/* comment out void UssMgr_eGetAPAMode(pUS_E_APAType_Mod_t* o_APAMod_pt, pUS_E_APAType_Mod_t o_pre_APAMod_pt );*/
/* comment out void UssMgr_eGetGrowlerMode(pUS_E_DEGROWLER_MOD_t* o_DeGROWLERMod_pt); */
/* comment out void UssMgr_SetTempDeltaGainType(uint8_t i_TempGainType) ;*/
/* comment out void UssMgr_SetTempGainTime(uint32_t i_TempGainTime); */
/* comment out uint8_t UssMgr_uGetTempDeltaGainType(void); */
/* comment out sint8_t UssMgr_sGetTempDeltaGain(void); */
/* comment out uint32_t UssMgr_uGetTempGainTime(void);*/
/* comment out Std_ReturnType aUSSCtrlDP_F_SetClusterCmd_b(pUS_E_ClusterID_t i_ClusterID_e, pUS_E_ClusterCmd_t i_ClusterCmd_e); */
/* comment out Std_ReturnType aUSSCtrlDP_F_SetSendBurstCmd_b(pUS_E_ClusterID_t ClusterID, pUS_E_ProfileType_t ProfileTypeF, pUS_E_ProfileType_t ProfileTypeR, pUS_S_ClusterBurstCmd_t* Cmd_pt); */
/* comment out Std_ReturnType aUSSCtrlDP_F_SetProfileCmd_b(pUS_E_ClusterID_t ClusterID, uint8_t SensorBitMap, pUS_E_ProfileType_t ProfileType, uint8_t Number, pUS_S_ProfileCfg_t* Cfg); */
/* comment out Std_ReturnType aUSSCtrlDP_F_SetMeasSetup_b(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_ClusterMeasSetup_t *i_MeasSetup_pt);*/
/* comment out Std_ReturnType aUSSCtrlDP_F_SetThresSetup_b(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_ClusterThresSetup_t *i_ThresSetup_pt); */
/* comment out Std_ReturnType aUSSCtrlDP_F_SetCalib_b(pUS_E_ClusterID_t i_ClusterID_e, const pUS_S_ClusterCalib_t *i_Calib_pt); */
/* comment out void aUSSCtrlDP_F_SetPowerOn(bool_t i_IsPowerOn_b) ;*/
/* comment out void aUSSCtrlDP_F_Set_InteralMod_v(pUS_E_USSCtrlSytStatus_t o_SysStatus, */
/* comment out pUS_E_USSCtrl_CheckEnvStage_t o_CheckEnvStage, */
/* comment out pUS_E_ProfileType_t o_ProfileTypeF, */
/* comment out pUS_E_ProfileType_t o_ProfileTypeR, */
/* comment out UssCtrl_eMainState_t o_USSC_Iter); */
/* comment out void UssMgr_SetCycleEndFlags(bool_t FrontCycleEnd_b, bool_t RearCycleEnd_b); */
/* comment out void UssMgr_SetNFDburstSendFlags(bool_t FrontNFDburst_b, bool_t RearNFDburst_b);*/
/* comment out void UssMgr_SetRandomSilenceFlag(bool_t isRandomSilence_b); */
/*Blockage */
/* comment out  comment out void UssMgr_uGetBlockageSndBurstCnt( uint8_t* OD_Blockage_SndBurstCnt) ;*/
/* comment out void UssMger_SetCheckEnvStage(uint8_t USSC_EnvStage_CountBackUp); */
/* comment out void UssMgr_SetBlockageAllSnrLockRS( uint16_t OD_Blockage_FinalRS;)*/
/* comment out void UssMgr_SetBlockageStatusFlag( uint8_t USSC_BlockageStatus); */
/*comment out void UssMgr_SetSingleBlockageRS( bool_t OD_Blockage_SingleBlockageRS); */
/*comment out void UssMgr_SetBlockageTrack( pUS_S_BlockageTrack_t *BlockageTrack); */
/*comment out void UssMgr_SetSnrBlockage(bool_t *SnrBlockage); */
/*comment out void aUSSCtrlDP_F_SetClearSensorBlockageErr(void); */
/*comment out void UssMgr_eGetGroundType( pUS_E_ENVType_Mod_t* o_GroundType_pt); */
/*comment out void UssMgr_bGetBlockageLockRS( bool_t* USSC_Blockage_LockRS); */
/*comment out void UssMgr_bGetBlockageValidJudge( bool_t* OD_Blockage_ValidJudge); */
/*comment out void UssMgr_bGetSnrDataNotOK( bool_t* SnrDataNotOK); */
/* comment out void UssMgr_sGetBlockageTrack( pUS_S_BlockageTrack_t* BlockageTrack); */
#endif
#endif /*_USS_CTRL_INTERFACE*/
