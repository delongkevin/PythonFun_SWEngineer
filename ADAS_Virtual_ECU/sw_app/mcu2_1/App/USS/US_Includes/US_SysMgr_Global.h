/*
 * US_SysMgr_Global.h
 *
 *  Created on: Feb 20, 2021
 *      Author: e39960
 */

#ifndef SOURCES_PRJINCLUDES_SYSMGR_H_
#define SOURCES_PRJINCLUDES_SYSMGR_H_

#include "US_ME_Typedefs_Global.h"
#include "US_SnrData_Typedefs_Global.h"

/* Some default / init values */
#define US_D_MGR_UNKNOWN_ECHO_DIST_U16  (0x8000)
#define US_D_MGR_UNKNOWN_TOF_U16        (0x8000)
#define US_D_MGR_UNKNOWN_SIGSTR_U16     (0x8000)

#define US_D_USE_FAPA_API                   (ME_TRUE)
#define OD_D_USE_FAPA_FEATURE_WITH_NO_API   (ME_TRUE)


typedef enum UssMgr_E_SysState
{
    SYSMGR_SYS_INIT,
	SYSMGR_SYS_INIT_CALIDATA,
	SYSMGR_SYS_POWERON,
	SYSMGR_SYS_CFGTRCVR,
    SYSMGR_SYS_CONFIG,
    SYSMGR_SYS_CALIBRATION,
    SYSMGR_SYS_DIAGNOSTIC,
    SYSMGR_SYS_READY
} UssMgr_e_SysState_t;

typedef enum UssMgr_E_GroupState_e
{
    SYSMGR_GRPSTATE_OFF,
    SYSMGR_GRPSTATE_OK,
    SYSMGR_GRPSTATE_NOISY,
    SYSMGR_GRPSTATE_DEGRADED,
    SYSMGR_GRPSTATE_FAULTED
} UssMgr_E_GroupState_t;

typedef enum UssMgr_E_NoiseReaction_e
{
    SYSMGR_NOISEREACT_SILENCE,
    SYSMGR_NOISEREACT_STATIC_CHIRP,
    SYSMGR_NOISEREACT_DYN_CHIRP,
    SYSMGR_NOISEREACT_MAX
} UssMgr_E_NoiseReaction_t;

typedef enum UssMgr_E_NFDMode_e
{
    NFD_MODE_UNKNOWN = ZERO,
    NFD_MODE_OFF,
    NFD_MODE_ON
} UssMgr_E_NFDMode_t;

typedef enum US_E_NoiseCheckType_e
{
    NOISE_CHECK_NONE = ZERO,
    NOISE_CHECK_FIXED,
    NOISE_CHECK_CHIRP
} US_E_NoiseCheckType_t;

UssMgr_e_SysState_t UssMgr_eGetSysState(void);
void UssMgr_SetSysState(UssMgr_e_SysState_t eState);
const US_S_SensorMeasRecs_t *UssMgr_psGetSnrMeasRec(uint8_t uRecIdx);
const US_S_SensorMeasRecs_t *UssMgr_psGetCurSensorMeasRec(void);
const US_S_SensorMeasDist_t *UssMgr_psGetCurSnrMeasRecDist(void);
US_S_SnrCalcs_t *UssMgr_psGetCurSnrCalcsRec(void);
US_S_SnrCalcs_t *UssMgr_psGetSnrCalcsRec(uint8_t uRecIdx);

uint8_t UssMgr_uGetNumSnrMeasRecs(void);
uint8_t UssMgr_uGetCurSnrMeasRecIdx(void);
bool_t UssMgr_CheckSnrForErrors(void);
uint16_t UssMgr_CheckMeasurmentForErrors(const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRecPtr);
uint32_t UssMgr_JKISS32RandAlgo(void);
void UssMgr_Main(void);
void UssMgr_ManagerInit(void);
void UssMgr_MgrModePublicInit(void);
void UssMgr_SetListenOnlySettings(void);
void UssMgr_RestoreNonListenSettings(void);
bool_t UssMgr_bIsNewSnrData(void);
uint8_t UssMgr_uGetFiringMode(void);
void US_MgrSetup_PrevParkingMode(US_E_ParkingMode_t mode);
/* Utility */
bool_t UssMgr_IsVehicleMoving(void);
float32_t UssMgr_GetVehSpeed(void);
#if (US_D_USE_FAPA_API == ME_TRUE)
bool_t UssMgr_IsFeatureInFAPA(void);
#endif

/* Mode Control */
void UssMgr_ProcessModeControl(void);
US_E_ParkingMode_t UssMgr_uGetCurParkingMode(void);
void UssMgr_SetNextNoiseMitMode(uint8_t Group_Index, US_E_NoiseMitigationMode_t Requested_Mode);
US_E_NoiseMitigationMode_t UssMgr_GetUsedNoiseMitMode(uint8_t Group_Index);
bool_t UssMgr_IsGroupInNFDOnMode(uint8_t Group_Index);
US_E_NoiseCheckType_t UssMgr_GetNoiseCheckType(void);
UssMgr_E_NoiseReaction_t UssMgr_GetNoiseReactionCfg(void);

/* Group info */
UssMgr_E_GroupState_t UssMgr_eGetGrpState(uint8_t GroupIdx);
void UssMgr_SetGrpState(uint8_t GroupIdx, UssMgr_E_GroupState_t NewState);  //maybe
bool_t UssMgr_IsAnyGroupNoisy(void);

/* Customer API */
void USS_SetSelfTestEnable(uint32_t EnableOrDisable);
void USS_SetBumperEnable(/*ME_US_E_BumperLocation_t*/ uint32_t SelectedBumper, uint32_t EnableOrDisable);

/* Blockage */
uint8_t * UssMgr_uGetBlockCntArray(void);
uint8_t * UssMgr_uGetBlockClrCntArray(void);
#if BLOCKAGE_NN
uint8_t USSMgr_BlockageGetDbgVar(const USSMgr_E_BlockageVars_t uDbgID, const uint8_t uSnrIdx);
float32_t USSMgr_BlockageGeAlphaFilterVal( const uint8_t uSnrIdx);
#endif
uint8_t USSMgr_BlockageGetActiveFlag(void);
#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
uint8_t UssMgr_DBG_uGetBHM_DistRAvg(uint8_t sensor_index);
#endif

/* Other Echo Info */
const uint8_t * UssMgr_uGetCRNFDConf(void);
#ifdef US_D_MGR_WALL_HIGH_FLAGS
uint8_t UssMgr_uGetWallFlagsByGroup(uint8_t uGrpIdx);
bool_t UssMgr_bGetWallGuessbyBumper(uint8_t uBumperIndex);
bool_t UssMgr_bGetWallGuessbyBumper_Persist(uint8_t uBumperIndex);
#endif /*US_D_MGR_WALL_HIGH_FLAGS*/
/* Diag */
US_S_AllSnrFreqData_t * UssMgr_GetSnrFreqData(void);

bool_t USSMgr_Height_GetUnfilteredHeightFlag(const uint8_t uPhys_Grp);
bool_t USSMgr_Height_GetFilteredHeightFlag(const uint8_t uPhys_Grp);
uint8_t USSMgr_Height_GetHeightClass(const uint8_t uPhys_Grp);
#endif /* SOURCES_PRJINCLUDES_SYSMGR_H_ */
