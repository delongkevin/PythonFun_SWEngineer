/*
 * US_MgrInterface.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRINTERFACE_H_
#define USSMGR_SRC_US_MGRINTERFACE_H_

#include "US_ComInputBuffer_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_SnrData_Typedefs_Global.h"

bool_t UssMgr_PopulateComOutputBuffer(void);
bool_t UssMgr_PopulateDiagFlagsInComOutBuff(void);

#if 0
typedef struct _UssMgr_sInterfaceData
{
    bool_t OD_Blockage_ValidJudge;                  // R:  OD
    uint8_t OD_Blockage_SndBurstCnt;                // R:  OD
    pUS_S_SnrBurstMode_t BurstMode;                 // R:  OD

    pUS_E_DEGROWLER_MOD_t USS_DeGrowlerMod;         // R:  OD, Ctrl
    pUS_E_USSCtrlSytStatus_t USSC_SysStatus;        // R:  OD, W: Ctrl
    pUS_E_APAType_Mod_t USS_APAMod;                 // R:  OD, W: Ctrl

    uint8_t OD_SingleSnrBlockage[12];               // W:  OD
    bool_t OD_Blockage_SingleBlockageRS;            // W:  OD
    uint16_t OD_Blockage_AllSnrLockRS;              // W:  OD
    bool_t USSC_NFDburst_b[2]; // Front/Rea         // R:  OD - should use direct from sensor data
    bool_t SnrDataNoisy[2];                         // W:  OD


    pUS_S_BlockageTrack_t OD_BlockageTrack[12];     // RW: OD

    pUS_E_USSCtrl_CheckEnvStage_t USSC_EnvStage_CountBackUp;    // W:  Ctrl
    pUS_E_VehSpeed_Mod_t USSC_SpdMode;                      // W:  Ctrl
    pUS_E_USSCtrl_CheckEnvStage_t USS_CheckEnvStage;            // W:  Ctrl
    pUS_E_ProfileType_t USS_BurstProfileTypeF;                  // W:  Ctrl
    pUS_E_ProfileType_t USS_BurstProfileTypeR;                  // W:  Ctrl
    //bool_t USSC_CycleEndSend_b[2];  // Front/Rear               // W:  Ctrl
    //bool_t USSC_NFDburstSend_b[2];  // Front/Rear               // W:  Ctrl
    //bool_t USSC_isRandomSilence_b;                              // W:  Ctrl

    uint8_t USS_TempGainType;                       // RW: Ctrl
    sint8_t USS_TempGain_Mod;                       // RW: Ctrl
    uint32_t USS_TempGain_Times;                    // RW: Ctrl

    bool_t MalfunctionOnlyBlockage;                 // R:  Ctrl
    bool_t SnrDataNotOK;                            // R:  Ctrl

    pUS_E_ENVType_Mod_t USSC_GroundType;            // R:  Ctrl

    uint8_t USSC_BlockageStatus;                    // W:  Ctrl
    uint8_t USSC_GroundType_DiffCnt;                // W:  Ctrl
    bool_t USSC_GroundType_ConfirmRocky;            // W:  Ctrl
    bool_t USSC_Blockage_LockRS; //BTRS             // W:  Ctrl
    bool_t USSC_ResetPara;  // SysStatus Reset      // W:  Ctrl
    bool_t NeedUpdateTempFromSnr;                   // W:  Ctrl

    bool_t ReqSnrFeatureFlag;                       // R:  Ctrl
    bool_t ReqSnrCompGain;                          // R:  Ctrl
    uint8_t ReqSnr;                                 // R:  Ctrl
    bool_t DSI_CFG_TRE_DOWN;                        // R:  Ctrl

    // ================ SET CMD ===============================
    pUS_E_AmazonECUmode_t AmzEcuMod;                // R:  Ctrl
    bool_t SetCmd_Received;                         // RW: Ctrl
    pUS_S_EDICfg_t SetCmd_EDIcfg_t;                 // R:  Ctrl
    uint8_t SetCmd_Envelope_SendingSensor;          // R:  Ctrl
    uint8_t SetCmd_Envelope_Profile;                // R:  Ctrl
    pUS_E_AmazonSetCmd_t SetCmd;                    // R:  Ctrl
    pUS_S_NFDCfg_t SetCmd_NFDcfg_t;                 // R:  Ctrl


    // \TODO: jp ------------------These need further examination as to whether they should be here -----------
    uint32_t EnvInfoReceivedTime;                                   // Input Buffer  - Direct Access
    pUS_E_GROWLER_TYPE_t USS_Front_GlowlerType;                     // Output Buffer - Direct Access
    //pUS_E_GROWLER_TYPE_t USS_Rear_GlowlerType;                      // Output Buffer - Direct Access
    US_E_UssCtrl_GrowlerStage_t USS_GrowlerStage;                  // Output Buffer - Direct Access - mgr not ctrl as in type name
    pUS_E_SnrFwSync_t USSC_IsSnrFwNotSync;                          // Output Buffer - Direct Access - not used
    uint8_t USSC_SndSensor;                                         // Output Buffer - Direct Access - mgr not ctrl as in name
    bool_t InitErr_b;                                               // R:  Ctrl, W: Direct connect with Drv \TODO: Accessor for drv

    bool_t USSC_isRandomSilenceBk_b;                                // SensorProc - Direct Access
    pUS_E_USSCtrl_CheckEnvStage_t USSC_EnvStage_CountBackUp_pre;    // Env Check - Direct Access - Only use, move

    pUS_E_AmazonTestMode_t SetTestMode;                             // Output Buffer - Direct Access
    //----------------------------------------------------------------------

} UssMgr_sInterfaceData_t;
#endif

/*
 * The following extern exists only for the use of UssMgr compilation units.
 * These are considered private data when accessed via this extern.
 * PLEASE! Create a setter or a getter for the information you require.
 * Then include this file for the interface.  Thank you!
 *
 */


void UssMgr_InitInterface(void);
#if(QAC_WARNING_FIX == ME_FALSE)
void UssMgr_InitSensorsInClusterList(void);
#endif
/*
 * ==============================================================================================
 * Interface to Mrg data that is not in the interface structure.
 * \TODO jp - see how to bring these pieces of data into compliance with the interface.\
 * The exception may be the cluster buffer.  Make determination. -jp
 */



Std_ReturnType aUSSMgr_F_IsPowerOn(void);  // accessor exists - but no one is asking - unused

void UssMgr_SetSnrDataNoisy(bool_t *isNoisy);  // used by output buffer only

/* Global accessors to input/output buffers */
/*KPK-not in use*/
/*MEUssMgr_S_InputSignals20ms_t *   UssMgr_psGetInputBuffer(void);*/
/*KPK: move the interfaces to the Owner module */
/*UssMgr_s_OutputSignals_t * UssMgr_psGetOutBuffer(void);*/

/*
 * =================================================================================
 * UssMgr_sInterfaceData Setters / Getters
 * Note: Add here if they do not exist. Do not use extern pointer access outside of Mgr.
 * =================================================================================
 */

/*
 * =============================== SETTERS ===============================
 */

void UssMgr_SetSnrBlockage(bool_t *SnrBlockage);
uint8_t * UssMgr_GetSnrBlockage(void);
void UssMgr_SetTempDeltaGainType(uint8_t uTempGainType);
void UssMgr_SetTempGainTime(uint32_t uTempGainTime);
void UssMgr_SetCycleEndFlags(bool_t bFrontCycleEnd, bool_t bRearCycleEnd);
void UssMgr_SetNFDburstSendFlags(bool_t bFrontNFDburst, bool_t bRearNFDburst);
void UssMgr_SetRandomSilenceFlag(bool_t bIsRandomSilence);
void UssMger_SetCheckEnvStage(uint8_t uCheckEnvStage);
void UssMgr_SetClearSensorBlockageErr(void);
void UssMgr_SetBlockageStatusFlag(uint8_t uBlockageStatus);
bool_t UssMgr_bIsResetParamsNeeded(void);
void UssMgr_SetClearTestDataReq(void);

/*
 * =============================== GETTERS ===============================
 */
uint8_t UssMgr_uGetBlockageSndBurstCnt(void);
bool_t UssMgr_bGetBlockageValidJudge(void);

uint8_t UssMgr_uGetTempDeltaGainType(void);
sint8_t UssMgr_sGetTempDeltaGain(void);
uint32_t UssMgr_uGetTempGainTime(void);
void UssMgr_abGetCycleEndFlags(bool_t *abCycleEnd);
void UssMgr_abGetNFDburstFlags(bool_t *abNFDburst);

bool_t UssMgr_bGetBlockageLockRS(void);
bool_t UssMgr_bGetIsTempSnrUpdateNeeded(void);
bool_t UssMgr_bGetReqSnrFeatureFlag(void);
bool_t UssMgr_bGetReqSnrCompGain(void);
bool_t UssMgr_bGetReqSnr(void);
bool_t UssMgr_bGetDSIerrFlag(void);


float32_t UssMgr_fGetAirTemp(void);
//KPK: added

void SetAmzEcuMode(void);
#endif /* USSMGR_SRC_US_MGRINTERFACE_H_ */
