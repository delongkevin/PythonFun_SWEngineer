/*
 * USSDrv_SnrCfg.c
 *
 *  Created on: Feb 18, 2021
 *      Author: e39960
 */


#include "US_ME_Typedefs_Global.h"

#include "US_Data_Typedefs_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SysMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Ctrl_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_CtrlMain.h"
#include "US_ComInputBuffer_Global.h"
#include "US_SnrDynAdjust.h"

/* Variables */
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
static US_S_ProfileCfg_t   g_LAUD_UsedProfileCfg[THREE];
static US_S_Stg_t          g_LAUD_UsedSTG[16u];
static US_S_Stc_t          g_LAUD_UsedSTC[14u];
static uint32_t            g_LAUD_Overran[10] = {0};
#endif

/* Debug to be externed */
static uint8_t g_UssDbg_AdjResultCounters[THREE] = {0};


#if (QAC_WARNING_FIX  ==  ME_FALSE)
#define  US_RECFG_SENSOR_DELAY                      (10u)
#define  MAX_CONFIGURE_DSI3TRCEIVER_RETRY            (16u)
#define  MAX_CONFIGURE_DSI3TRCEIVER_DELAY            (10u)
#endif
#define SNR_NEW_ID_ADDR                            (0xA6u)         /* need to be updated when it is available*/
#define SNR_RESET_REASON_ADDR                      (0xC8u)         /* need to be updated when it is available*/
#define SENSOR_CFG_OPMODE                          (SENSOR_OP_NORMAL)                     /*(SENSOR_OP_NORMAL)   (SENSOR_OP_MFG)*/

#define US_CTRL_SNRCAL_CMD_BUSY                      (0u)
#define US_CTRL_SNRCAL_CMD_COMPLETED                 (1u)

#define  MAX_AUTOADDRESS_RETRY                       (6u)
#define  MAX_SETUP_OPMODE_RETRY                      (6u)
#define  MAX_DIAGNOSTIC_FAIL_RETRY                   (8u)
#define  MAX_READ_VERSION_RETRY                      (6u)
#define  MAX_READ_SENSORID_RETRY                     (6u)
#define  MAX_CFGCMD_RETRY                            (8u)

#define SENSOR_CFG_CRM_ERROR                         (1u)
#define SENSOR_OPMODE_CRC_ERROR                      (2u)
#define SENSOR_OPMODE_CRC_BITS                       (0x60)
#define SENSOR_BLOCKCFG_CRC_BITS                     (0x6)
#define SENSOR_BLOCKMFG_CRC_BITS                     (0x18)
#define SENSOR_CFGERR_BIT                            (0x80)
#define SENSOR_LAST_CFGCMD_BIT                       (0x8000)


enum  /*\US_E_ADJ_STATE_ID_e */
{
    US_SNRCALADJ_INIT  = 0,
    US_SNRCALADJ_PROFILEA,
    US_SNRCALADJ_FRONT_SIDE_STC,
    US_SNRCALADJ_FRONT_SIDE_STG,
    US_SNRCALADJ_FRONT_INNER_STC,
    US_SNRCALADJ_FRONT_INNER_STG,
    US_SNRCALADJ_FRONT_OUTER_STC,
    US_SNRCALADJ_FRONT_OUTER_STG,
    US_SNRCALADJ_REAR_SIDE_STC,
    US_SNRCALADJ_REAR_SIDE_STG,
    US_SNRCALADJ_REAR_INNER_STC,
    US_SNRCALADJ_REAR_INNER_STG,
    US_SNRCALADJ_REAR_OUTER_STC,
    US_SNRCALADJ_REAR_OUTER_STG,
#if (US_D_ENABLE_DNN_PROFC_ALL_ADJUST == ME_TRUE)
    US_SNRCALADJ_PFC_FS_STC,
    US_SNRCALADJ_PFC_FS_STG,
    US_SNRCALADJ_PFC_FI_STC,
    US_SNRCALADJ_PFC_FI_STG,
    US_SNRCALADJ_PFC_FO_STC,
    US_SNRCALADJ_PFC_FO_STG,
    US_SNRCALADJ_PFC_RS_STC,
    US_SNRCALADJ_PFC_RS_STG,
    US_SNRCALADJ_PFC_RI_STC,
    US_SNRCALADJ_PFC_RI_STG,
    US_SNRCALADJ_PFC_RO_STC,
    US_SNRCALADJ_PFC_RO_STG,
#endif
#if (US_D_ENABLE_PBUTTON_PROFC_ADJUST == ME_TRUE)
    US_SNRCALADJ_PFC_SCANFRONT_STC,
    US_SNRCALADJ_PFC_SCANREAR_STC,
#endif
	US_SNRCALADJ_DIAGNOSTIC_RESULT,
	US_SNRCALADJ_MAX
};
/*\typedef enum US_E_ADJ_STATE_ID_e US_E_Adj_STATE_t;*/

typedef struct /*\US_SnrAdj_CmdTable_s */
{
	uint16_t          state;                /* adj state */
	uint8_t           nSeg;
	uint8_t           Index;                /* for Profile */
	uint32_t          SensorLoc;            /*specified Sensor location (!!!CAN'T MIX FRONT AND REAR, ONLY SENSOR PAIRS!!)*/
    uint32_t          UserInfo;             /* Put whatever you want to tell the adjustment algo what to do */
	uint32_t          CalData_Type;         /* JR guess: type to match for cal data lookup */
	uint32_t          CalData_ID;
	uint32_t          DataLen;
	uint32_t          (*US_Snr_SetupAdjFxn)(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
    void              *UsedDataCopyPtr;
#endif
}US_SnrAdj_CmdTable_t;

static uint16_t US_SnrCalAdj_State = (uint16_t)US_SNRCALADJ_MAX;    /* Stop ensor Cal data Adjust */

#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
const static US_SnrAdj_CmdTable_t US_SnrAdj_CmdTable[] =
{
    {(uint16_t)US_SNRCALADJ_PROFILEA,                1, 6,    (US_ALL_POS),                   US_D_DYNADJ_USERINFO_NONE,  ((uint32_t)US_E_PROFILE_A),                               PROFILE_CFG_ID,     sizeof(US_S_ProfileCfg_t)+FOUR,      US_SnrDrvMgr_F_SetProfileCmd, &g_LAUD_UsedProfileCfg[0u]},
    {(uint16_t)US_SNRCALADJ_FRONT_SIDE_STC,          2, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_USERINFO_NONE,  (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[0u]},
    {(uint16_t)US_SNRCALADJ_FRONT_SIDE_STG,          4, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_USERINFO_NONE,  (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[0u]},
    {(uint16_t)US_SNRCALADJ_FRONT_INNER_STC,         2, 0,    (US_FRONT_POS | US_INNER_POS),  US_D_DYNADJ_USERINFO_NONE,  (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[1u]},
    {(uint16_t)US_SNRCALADJ_FRONT_INNER_STG,         4, 0,    (US_FRONT_POS | US_INNER_POS),  US_D_DYNADJ_USERINFO_NONE,  (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[1u]},
    {(uint16_t)US_SNRCALADJ_FRONT_OUTER_STC,         2, 0,    (US_FRONT_POS | US_OUTER_POS),  US_D_DYNADJ_USERINFO_NONE,  (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[2u]},
    {(uint16_t)US_SNRCALADJ_FRONT_OUTER_STG,         4, 0,    (US_FRONT_POS | US_OUTER_POS),  US_D_DYNADJ_USERINFO_NONE,  (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[2u]},
    {(uint16_t)US_SNRCALADJ_REAR_SIDE_STC,           2, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_USERINFO_NONE,  (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),     STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[3u]},
    {(uint16_t)US_SNRCALADJ_REAR_SIDE_STG,           4, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_USERINFO_NONE,  (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),     STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[3u]},
    {(uint16_t)US_SNRCALADJ_REAR_INNER_STC,          2, 0,    (US_REAR_POS | US_INNER_POS),   US_D_DYNADJ_USERINFO_NONE,  (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[4u]},
    {(uint16_t)US_SNRCALADJ_REAR_INNER_STG,          4, 0,    (US_REAR_POS | US_INNER_POS),   US_D_DYNADJ_USERINFO_NONE,  (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[4u]},
    {(uint16_t)US_SNRCALADJ_REAR_OUTER_STC,          2, 0,    (US_REAR_POS | US_OUTER_POS),   US_D_DYNADJ_USERINFO_NONE,  (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[5u]},
    {(uint16_t)US_SNRCALADJ_REAR_OUTER_STG,          4, 0,    (US_REAR_POS | US_OUTER_POS),   US_D_DYNADJ_USERINFO_NONE,  (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[5u]},
#if (US_D_ENABLE_DNN_PROFC_ALL_ADJUST == ME_TRUE)
    {(uint16_t)US_SNRCALADJ_PFC_FS_STC,              2, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[6u]},
    {(uint16_t)US_SNRCALADJ_PFC_FS_STG,              4, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[6u]},
    {(uint16_t)US_SNRCALADJ_PFC_FI_STC,              2, 0,    (US_FRONT_POS | US_INNER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[7u]},
    {(uint16_t)US_SNRCALADJ_PFC_FI_STG,              4, 0,    (US_FRONT_POS | US_INNER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[7u]},
    {(uint16_t)US_SNRCALADJ_PFC_FO_STC,              2, 0,    (US_FRONT_POS | US_OUTER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[8u]},
    {(uint16_t)US_SNRCALADJ_PFC_FO_STG,              4, 0,    (US_FRONT_POS | US_OUTER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[8u]},
    {(uint16_t)US_SNRCALADJ_PFC_RS_STC,              2, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),     STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[9u]},
    {(uint16_t)US_SNRCALADJ_PFC_RS_STG,              4, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),     STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[9u]},
    {(uint16_t)US_SNRCALADJ_PFC_RI_STC,              2, 0,    (US_REAR_POS | US_INNER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[10u]},
    {(uint16_t)US_SNRCALADJ_PFC_RI_STG,              4, 0,    (US_REAR_POS | US_INNER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[10u]},
    {(uint16_t)US_SNRCALADJ_PFC_RO_STC,              2, 0,    (US_REAR_POS | US_OUTER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[11u]},
    {(uint16_t)US_SNRCALADJ_PFC_RO_STG,              4, 0,    (US_REAR_POS | US_OUTER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd, &g_LAUD_UsedSTG[11u]},
#endif
#if (US_D_ENABLE_PBUTTON_PROFC_ADJUST == ME_TRUE)
    {(uint16_t)US_SNRCALADJ_PFC_SCANFRONT_STC,       2, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_UI_PFC_SCAN,                             ((uint32_t)US_E_PROFILE_C),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[12u]},
    {(uint16_t)US_SNRCALADJ_PFC_SCANREAR_STC,        2, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_UI_PFC_SCAN,                             ((uint32_t)US_E_PROFILE_C),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd, &g_LAUD_UsedSTC[13u]},
#endif
    {(uint16_t)US_SNRCALADJ_DIAGNOSTIC_RESULT,       1, 0,                    (US_ALL_POS),   US_D_DYNADJ_USERINFO_NONE,                   0,              0,                          0,                  US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd, g_LAUD_Overran},
    {(uint16_t)US_SNRCALADJ_MAX,                     0, 0,                              0,    US_D_DYNADJ_USERINFO_NONE,                  0,              0,                          0,                  NULL,   g_LAUD_Overran}
};
#else
const static US_SnrAdj_CmdTable_t US_SnrAdj_CmdTable[] =               
{
    {(uint16_t)US_SNRCALADJ_PROFILEA,                1, 6,     (US_ALL_POS),                  US_D_DYNADJ_USERINFO_NONE,     ((uint32_t)US_E_PROFILE_A),                              PROFILE_CFG_ID,    sizeof(US_S_ProfileCfg_t)+FOUR,      US_SnrDrvMgr_F_SetProfileCmd},
    {(uint16_t)US_SNRCALADJ_FRONT_SIDE_STC,          2, 0,     (US_FRONT_POS | US_SIDE_POS),  US_D_DYNADJ_USERINFO_NONE,     (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,        sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_FRONT_SIDE_STG,          4, 0,     (US_FRONT_POS | US_SIDE_POS),  US_D_DYNADJ_USERINFO_NONE,     (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,        sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_FRONT_INNER_STC,         2, 0,     (US_FRONT_POS | US_INNER_POS), US_D_DYNADJ_USERINFO_NONE,     (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),  STC_CFG_ID,        sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_FRONT_INNER_STG,         4, 0,     (US_FRONT_POS | US_INNER_POS), US_D_DYNADJ_USERINFO_NONE,     (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),  STG_CFG_ID,        sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_FRONT_OUTER_STC,         2, 0,     (US_FRONT_POS | US_OUTER_POS), US_D_DYNADJ_USERINFO_NONE,     (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),  STC_CFG_ID,        sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_FRONT_OUTER_STG,         4, 0,     (US_FRONT_POS | US_OUTER_POS), US_D_DYNADJ_USERINFO_NONE,     (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),  STG_CFG_ID,        sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_REAR_SIDE_STC,           2, 0,     (US_REAR_POS | US_SIDE_POS),   US_D_DYNADJ_USERINFO_NONE,     (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,        sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_REAR_SIDE_STG,           4, 0,     (US_REAR_POS | US_SIDE_POS),   US_D_DYNADJ_USERINFO_NONE,     (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,        sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_REAR_INNER_STC,          2, 0,     (US_REAR_POS | US_INNER_POS),  US_D_DYNADJ_USERINFO_NONE,     (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,        sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_REAR_INNER_STG,          4, 0,     (US_REAR_POS | US_INNER_POS),  US_D_DYNADJ_USERINFO_NONE,     (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,        sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_REAR_OUTER_STC,          2, 0,     (US_REAR_POS | US_OUTER_POS),  US_D_DYNADJ_USERINFO_NONE,     (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,        sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_REAR_OUTER_STG,          4, 0,     (US_REAR_POS | US_OUTER_POS),  US_D_DYNADJ_USERINFO_NONE,     (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,        sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
#if (US_D_ENABLE_DNN_PROFC_ALL_ADJUST == ME_TRUE)
    {(uint16_t)US_SNRCALADJ_PFC_FS_STC,              2, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_FS_STG,              4, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_PFC_FI_STC,              2, 0,    (US_FRONT_POS | US_INNER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_FI_STG,              4, 0,    (US_FRONT_POS | US_INNER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_PFC_FO_STC,              2, 0,    (US_FRONT_POS | US_OUTER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_FO_STG,              4, 0,    (US_FRONT_POS | US_OUTER_POS),  US_D_DYNADJ_UI_PFC_COPY,  (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),   STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_PFC_RS_STC,              2, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),     STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_RS_STG,              4, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),     STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_PFC_RI_STC,              2, 0,    (US_REAR_POS | US_INNER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_RI_STG,              4, 0,    (US_REAR_POS | US_INNER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
    {(uint16_t)US_SNRCALADJ_PFC_RO_STC,              2, 0,    (US_REAR_POS | US_OUTER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_RO_STG,              4, 0,    (US_REAR_POS | US_OUTER_POS),   US_D_DYNADJ_UI_PFC_COPY,  (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),    STG_CFG_ID,         sizeof(US_S_Stg_t),                  US_SnrDrvMgr_F_SetSTGCmd},
#endif
#if (US_D_ENABLE_PBUTTON_PROFC_ADJUST == ME_TRUE)
    {(uint16_t)US_SNRCALADJ_PFC_SCANFRONT_STC,       2, 0,    (US_FRONT_POS | US_SIDE_POS),   US_D_DYNADJ_UI_PFC_SCAN,                             ((uint32_t)US_E_PROFILE_C),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
    {(uint16_t)US_SNRCALADJ_PFC_SCANREAR_STC,        2, 0,    (US_REAR_POS | US_SIDE_POS),    US_D_DYNADJ_UI_PFC_SCAN,                             ((uint32_t)US_E_PROFILE_C),    STC_CFG_ID,         sizeof(US_S_Stc_t),                  US_SnrDrvMgr_F_SetSTCCmd},
#endif
    {(uint16_t)US_SNRCALADJ_DIAGNOSTIC_RESULT,       1, 0,               (US_ALL_POS),        US_D_DYNADJ_USERINFO_NONE,                         0,                         0,                 0,                                   US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd},
    {(uint16_t)US_SNRCALADJ_MAX,                     0, 0,         0,                         US_D_DYNADJ_USERINFO_NONE,           0,                                              0,          0,                                         NULL}
};
#endif /* US_D_LAUTERBACH_DEBUG_VARS */


enum /* \US_E_SnrCfg_STATE_ID_e */
{
	US_SNRCALCFG_INIT  = 0,
	US_SNRCALCFG_TRANCEIVER_RESET,
	US_SNRCALCFG_TRANCEIVER_RESET_CHECK,
	US_SNRCALCFG_AUTOADDRESSING,
	US_SNRCALCFG_AUTOADDRESSING_READ,

	US_SNRCALCFG_REQ_SENSORS_ID,
	US_SNRCALCFG_READ_SENSORS_MARRIAGE_MAPPING,
	US_SNRCALCFG_REQ_SENSORS_VER,
	US_SNRCALCFG_REQ_SENSORS_OPMODE,
	US_SNRCALCFG_SET_SENSORS_OPMODE,
	US_SNRCALCFG_SET_0_OPMODE_DELAY,
	US_SNRCALCFG_RESET_SENSORS,
	US_SNRCALCFG_RESET_OPMODE_DELAY,
	US_SNRCALCFG_REQ_SENSORS_1_OPMODE,
	US_SNRCALCFG_DIAGNOSTIC_RESULT_CHK,
	US_SNRCALCFG_REQ_SENSORS_SENSITIVITY,
	US_SNRCALCFG_REQ_SENSORS_RESET_REASON,
	US_SNRCALCFG_SETPROFILEPLUS_6,
	US_SNRCALCFG_SETPROFILEPLUS_5,
	US_SNRCALCFG_SETPROFILEPLUS_4,
	US_SNRCALCFG_SET_FTC,
	US_SNRCALCFG_SET_AATG1,
	US_SNRCALCFG_SET_AATG2,
	US_SNRCALCFG_SET_ATG,
	US_SNRCALCFG_SET_NFD,
	US_SNRCALCFG_SET_GANAMEASBEGIN,
	US_SNRCALCFG_SET_EDI,
	US_SNRCALCFG_SET_SENSORCOMP,

	US_SNRCALCFG_PROFILE_C,
	US_SNRCALCFG_PROFILE_C_STC,
	US_SNRCALCFG_PROFILE_C_STG,

	US_SNRCALCFG_PROFILE_B,
	US_SNRCALCFG_PROFILE_B_STC,
	US_SNRCALCFG_PROFILE_B_STG,

	US_SNRCALCFG_PROFILE_A,
	US_SNRCALCFG_PA_FRONT_SIDE_STC,
	US_SNRCALCFG_PA_FRONT_SIDE_STG,
	US_SNRCALCFG_PA_FRONT_INNER_STC,
	US_SNRCALCFG_PA_FRONT_INNER_STG,
	US_SNRCALCFG_PA_FRONT_OUTER_STC,
	US_SNRCALCFG_PA_FRONT_OUTER_STG,
	US_SNRCALCFG_PA_REAR_SIDE_STC,
	US_SNRCALCFG_PA_REAR_SIDE_STG,
	US_SNRCALCFG_PA_REAR_INNER_STC,
	US_SNRCALCFG_PA_REAR_INNER_STG,
	US_SNRCALCFG_PA_REAR_OUTER_STC,
	US_SNRCALCFG_PA_REAR_OUTER_STG,
	US_SNRCALCFG_DIAGNOSTIC_RESULT,
	US_SNRCALCFG_MAX
};

/*\typedef enum US_E_SnrCfg_STATE_ID_e US_E_SnCalCfg_STATE_t; */

typedef struct /*\US_SnrCalCfg_CmdTable_s */
{
	uint16_t          state;                  /* adj state */
	uint16_t          nSeg;
	uint32_t          param;                 /* for Profile */
	uint32_t          SensorLoc;              /*specified Sensor location*/
	uint32_t          CalData_Type;
	uint32_t          CalData_ID;
	uint32_t          inDataLen;
	uint32_t          (*UssCtrl_SnrCalCfgFxn)(uint32_t SnrMap,uint32_t UserData,uint16_t inlength,uint8_t const *inData,uint16_t outLength,uint8_t *outData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
}US_SnrCalCfg_CmdTable_t;


static uint32_t UssCtrl_SnrAdj_Cmd_Complete = US_CTRL_SNRCAL_CMD_COMPLETED,UssCtrl_SnrCalCfg_Cmd_Completed = US_CTRL_SNRCAL_CMD_COMPLETED;

static void UssCtrl_Cfg_DSI3TransceiverCmd(void);
static void UssCtrl_Reset_DSI3TransceiverCmd(void);
static void UssCtrl_ReleaseReset_DSI3TransceiverCmd(void);
static uint32_t UssCtrl_ReCfg_Delay(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
static uint32_t UssCtrl_Reset_DSI3Trciver(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
static uint32_t UssCtrl_Reset_DSI3Trciver_check(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));


const static US_SnrCalCfg_CmdTable_t US_SnrCalCfg_CmdTable[] =
{
		{(uint16_t)US_SNRCALCFG_TRANCEIVER_RESET,                 1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     UssCtrl_Reset_DSI3Trciver},
		{(uint16_t)US_SNRCALCFG_TRANCEIVER_RESET_CHECK,           1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     UssCtrl_Reset_DSI3Trciver_check},


		{(uint16_t)US_SNRCALCFG_AUTOADDRESSING,                   1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     US_SnrDrvMgr_F_AutoAddressingCmd},
		{(uint16_t)US_SNRCALCFG_AUTOADDRESSING_READ,              1, DSI3_REG_STAT,   (US_ALL_POS),                                 0,            DSI_CMD_READ_MASTER_REG,         TWO,            	                     US_SnrDrvMgr_F_ReqDSIMasterRegByTableCmd},

		{(uint16_t)US_SNRCALCFG_REQ_SENSORS_ID,                   1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     US_SnrDrvMgr_F_ReqSensorIDCmd},
		{(uint16_t)US_SNRCALCFG_READ_SENSORS_MARRIAGE_MAPPING,    1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     US_SnrDrvMgr_F_SensorMarrage},
		{(uint16_t)US_SNRCALCFG_REQ_SENSORS_VER,                  1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     US_SnrDrvMgr_F_ReqSnrFWVer},
		{(uint16_t)US_SNRCALCFG_REQ_SENSORS_OPMODE,               1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     US_SnrDrvMgr_F_ReqSensorOPModeCmd},
		{(uint16_t)US_SNRCALCFG_SET_SENSORS_OPMODE,               1, (SENSOR_CFG_OPMODE), (US_ALL_POS),                             0,            SETUP_SENSOR_OPERATURE_MODE,    sizeof(uint8_t),                         US_SnrDrvMgr_F_SetSensorOPModeCmd},
		{(uint16_t)US_SNRCALCFG_SET_0_OPMODE_DELAY,         20, 0,             (US_ALL_POS),                                 0,            (uint32_t)US_SNRCALCFG_SET_0_OPMODE_DELAY,    0,                            UssCtrl_ReCfg_Delay},
		{(uint16_t)US_SNRCALCFG_RESET_SENSORS,                1, (SENSOR_OP_SWRESET), (US_ALL_POS),                                 0,            SETUP_SENSOR_OPERATURE_MODE,    sizeof(uint8_t),                         US_SnrDrvMgr_F_SetSensorOPModeCmd},
		{(uint16_t)US_SNRCALCFG_RESET_OPMODE_DELAY,         20, 0,             (US_ALL_POS),                                 0,            (uint32_t)US_SNRCALCFG_RESET_OPMODE_DELAY,    0,                          UssCtrl_ReCfg_Delay},
		{(uint16_t)US_SNRCALCFG_REQ_SENSORS_1_OPMODE,              1, 0,               (US_ALL_POS),                                 0,                            0,                0,            	                     US_SnrDrvMgr_F_ReqSensorOPModeCmd},
		{(uint16_t)US_SNRCALCFG_DIAGNOSTIC_RESULT_CHK,     1, 0,               (US_ALL_POS),                                 0,                         0,                 0,                            US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd},
		{(uint16_t)US_SNRCALCFG_REQ_SENSORS_SENSITIVITY,        1,(SNR_NEW_ID_ADDR),  (US_ALL_POS),                                 0,            SETUP_SENSOR_EEPROM,            THREE,            	                     US_SnrDrvMgr_F_ReqSensorEEPROMCmd},
		{(uint16_t)US_SNRCALCFG_REQ_SENSORS_RESET_REASON,  1,(SNR_RESET_REASON_ADDR), (US_ALL_POS),                                 0,            SETUP_SENSOR_EEPROM,            ONE,            	                     US_SnrDrvMgr_F_ReqSensorEEPROMCmd},
		{(uint16_t)US_SNRCALCFG_SETPROFILEPLUS_6,                 1, (0x060514),      (US_ALL_POS),                                 0,            SETUP_SENSOR_PROFILE_PLUS,sizeof(US_S_ProfilePlus_IndexCfg_t),           US_SnrDrvMgr_F_SetProfilePlusCmd},
		{(uint16_t)US_SNRCALCFG_SETPROFILEPLUS_5,                 1, (0x050000),      (US_ALL_POS),                                 0,            SETUP_SENSOR_PROFILE_PLUS,sizeof(US_S_ProfilePlus_IndexCfg_t),           US_SnrDrvMgr_F_SetProfilePlusCmd},
		{(uint16_t)US_SNRCALCFG_SETPROFILEPLUS_4,                 1, (0x040000),      (US_ALL_POS),                                 0,            SETUP_SENSOR_PROFILE_PLUS,sizeof(US_S_ProfilePlus_IndexCfg_t),           US_SnrDrvMgr_F_SetProfilePlusCmd},
		{(uint16_t)US_SNRCALCFG_SET_FTC,                          1, 0,               (US_ALL_POS),                                 0,                        FTC_CFG_ID,         sizeof(US_S_FTCfg_t),                    US_SnrDrvMgr_F_SetFTCCmd},
		{(uint16_t)US_SNRCALCFG_SET_AATG1,                        1, 0,               (US_ALL_POS),                                 0,                        AATG1_CFG_ID,       sizeof(US_S_AATGCfg_t),                  US_SnrDrvMgr_F_SetAATG1Cmd},
		{(uint16_t)US_SNRCALCFG_SET_AATG2,                        1, 0,               (US_ALL_POS),                                 0,                        AATG2_CFG_ID,       sizeof(US_S_AATGCfg_t),                  US_SnrDrvMgr_F_SetAATG2Cmd},
		{(uint16_t)US_SNRCALCFG_SET_ATG,                          1, 0,               (US_ALL_POS),                                 0,                        ATG_CFG_ID,         sizeof(US_S_ATGCfg_t),                   US_SnrDrvMgr_F_SetATGCmd},
		{(uint16_t)US_SNRCALCFG_SET_NFD,                          1, 0,               (US_ALL_POS),                                 0,                        NFD_CFG_ID,         sizeof(US_S_NFDCfg_t),                   US_SnrDrvMgr_F_SetNFDCmd},
		{(uint16_t)US_SNRCALCFG_SET_GANAMEASBEGIN,                1, 0,               (US_ALL_POS),                                 0,                        GANAMEASBEGIN_CFG_ID,sizeof(US_S_GanaMeasBegin_t),           US_SnrDrvMgr_F_SetGanaMeasBeginCmd},
		{(uint16_t)US_SNRCALCFG_SET_EDI,                          1, 0,               (US_ALL_POS),                                 0,                        EDI_CFG_ID,         sizeof(US_S_EDICfg_t),                   US_SnrDrvMgr_F_SetEDIChannelCmd},
		{(uint16_t)US_SNRCALCFG_SET_SENSORCOMP,                   1, 0,               (US_ALL_POS),                                 0,                        SENSORCOMP_CFG_ID,  sizeof(US_S_SensorEEFlagVarCTRL_t),      US_SnrDrvMgr_F_SetSensorEEFlagVarCTRLCmd},

		{(uint16_t)US_SNRCALCFG_PROFILE_C,                        1, 6,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_C),                    PROFILE_CFG_ID,    sizeof(US_S_ProfileCfg_Index_t),         US_SnrDrvMgr_F_SetProfileCmd},
		{(uint16_t)US_SNRCALCFG_PROFILE_C_STC,                    2, 0,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_C),                    STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PROFILE_C_STG,                    4, 0,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_C),                    STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},

		{(uint16_t)US_SNRCALCFG_PROFILE_B,                        1, 6,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_B),                    PROFILE_CFG_ID,    sizeof(US_S_ProfileCfg_Index_t),         US_SnrDrvMgr_F_SetProfileCmd},
		{(uint16_t)US_SNRCALCFG_PROFILE_B_STC,                    2, 0,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_B),                    STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PROFILE_B_STG,                    4, 0,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_B),                    STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},

		{(uint16_t)US_SNRCALCFG_PROFILE_A,                        1, 6,               (US_ALL_POS),                       ((uint32_t)US_E_PROFILE_A),                    PROFILE_CFG_ID,    sizeof(US_S_ProfileCfg_Index_t),         US_SnrDrvMgr_F_SetProfileCmd},
		{(uint16_t)US_SNRCALCFG_PA_FRONT_SIDE_STC,         2, 0,  (US_FRONT_POS | US_SIDE_POS),       (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),      STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PA_FRONT_SIDE_STG,         4, 0,  (US_FRONT_POS | US_SIDE_POS),       (US_FRONT_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),      STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},
		{(uint16_t)US_SNRCALCFG_PA_FRONT_INNER_STC,        2, 0,  (US_FRONT_POS | US_INNER_POS),      (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),     STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PA_FRONT_INNER_STG,        4, 0,  (US_FRONT_POS | US_INNER_POS),      (US_FRONT_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),     STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},
		{(uint16_t)US_SNRCALCFG_PA_FRONT_OUTER_STC,        2, 0,  (US_FRONT_POS | US_OUTER_POS),      (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),     STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PA_FRONT_OUTER_STG,        4, 0,  (US_FRONT_POS | US_OUTER_POS),      (US_FRONT_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),     STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},
		{(uint16_t)US_SNRCALCFG_PA_REAR_SIDE_STC,          2, 0,  (US_REAR_POS | US_SIDE_POS),        (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),       STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PA_REAR_SIDE_STG,          4, 0,  (US_REAR_POS | US_SIDE_POS),        (US_REAR_POS | US_SIDE_POS|(uint32_t)US_E_PROFILE_A),       STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},
		{(uint16_t)US_SNRCALCFG_PA_REAR_INNER_STC,         2, 0,  (US_REAR_POS | US_INNER_POS),       (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),      STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PA_REAR_INNER_STG,         4, 0,  (US_REAR_POS | US_INNER_POS),       (US_REAR_POS | US_INNER_POS|(uint32_t)US_E_PROFILE_A),      STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},
		{(uint16_t)US_SNRCALCFG_PA_REAR_OUTER_STC,         2, 0,  (US_REAR_POS | US_OUTER_POS),       (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),      STC_CFG_ID,        sizeof(US_S_Stc_t),                      US_SnrDrvMgr_F_SetSTCCmd},
		{(uint16_t)US_SNRCALCFG_PA_REAR_OUTER_STG,         4, 0,  (US_REAR_POS | US_OUTER_POS),       (US_REAR_POS | US_OUTER_POS|(uint32_t)US_E_PROFILE_A),      STG_CFG_ID,        sizeof(US_S_Stg_t),                      US_SnrDrvMgr_F_SetSTGCmd},
		{(uint16_t)US_SNRCALCFG_DIAGNOSTIC_RESULT,                1, 0,               (US_ALL_POS),                                 0,                         0,                 0,                                       US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd},
		{(uint16_t)US_SNRCALCFG_MAX,                              0, 0,         0,                                    0,                                    0,          0,                                                 NULL}
};

static uint8_t USS_CfgErr_Flag = ME_FALSE;
static uint16_t USS_CfgErr_State = US_SNRCALCFG_MAX,US_SnrCalCfg_State = (uint16_t)US_SNRCALCFG_MAX;    /* Stop ensor Cal data Adjust*/

static void UssCtrl_SnrCfgCallBack(uint32_t ErrorCode, uint32_t Cmd,uint32_t UserData, uint16_t RcvSize, uint8_t *RcvData);
static void UssCtrl_SnrAdj_Callback(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);

static void US_Trciver_Reset_task(void);
static uint8_t UssCtrl_DiagProcess(uint16_t len,  uint8_t *RcvData,uint32_t UserData);



static void  UssCtrl_Init_DSI3INTB(void); /* JWR3: What is this for? */


/* ===========================================================================
 * Name:     UssCtrl_ReCfg_Delay
 * Remarks:  DD-ID: {89B1C738-569F-4e0a-B5B8-6A040523EC13}
 * Traceability to source Code: Req.-ID:
 * ===========================================================================*/

static uint32_t UssCtrl_ReCfg_Delay(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    void (*pCallback)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);
	(void)sndlen;
	(void)rcvlen;
	(void)SnrMap;
	(void)rcvData;
	(void)sndData;

	 pCallback = CallBack;
	 if(pCallback != NULL)
	  {
			(*pCallback)(ME_OK,US_CONFIGURE_SENSOR_DELAY, UserData, 0,NULL);
      }
	  return ME_OK;
}

 /* ===========================================================================
 * Name: UssCtrl_Reset_DSI3Trciver    
 * Remarks:  DD-ID:{58B77433-706D-40ce-B4EA-66AFBA5F6B4A} 
 * ===========================================================================*/
static uint32_t UssCtrl_Reset_DSI3Trciver(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
	(void)sndlen;
	(void)rcvlen;
	(void)SnrMap;
	(void)rcvData;
	(void)sndData;
	(void)UserData;
    (void)(*CallBack);
 	 US_SnrDrv_Start_DSI3Transceiver_Reset();
	if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
	{
		US_SnrCalCfg_State++;
	}
	else{
		/* Overflow error handling */
	}
	 
     UssCtrl_SnrCalCfg_Cmd_Completed = ME_TRUE;
	 return ME_OK;
}
/* ===========================================================================
 * Name: UssCtrl_Reset_DSI3Trciver_check    
 * Remarks:  DD-ID: {DB0ECC24-55C9-46ac-A5D3-7BA0A88E51F1}
 * ===========================================================================*/
static uint32_t UssCtrl_Reset_DSI3Trciver_check(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
	(void)sndlen;
	(void)rcvlen;
	(void)SnrMap;
	(void)rcvData;
	(void)sndData;
	(void)UserData;
    (void)(*CallBack);
     uint8_t TrcvrState;
     TrcvrState  = US_SnrDrv_Check_TransceiverResetState();
	 if( TrcvrState == (uint8_t)ME_FALSE )
	 {
		if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
		{
			US_SnrCalCfg_State++;
		}
		else{
			/*  Overflow error handling  */
		}		
	 }
     UssCtrl_SnrCalCfg_Cmd_Completed = ME_TRUE;
	 return ME_OK;
}
/* DD-ID: */
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
/* ===========================================================================
 * Name: UssCtrl_SnrCfgCallBack    
 * Remarks:  DD-ID: {CEFD8A29-0EE4-4d7a-9E84-A91CB96EA0A8}
 * ===========================================================================*/
static void UssCtrl_SnrCfgCallBack(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData)/* PRQA S 2755 */
{
	
    UssMgr_e_SysState_t systate; 
    static uint16_t Retry = ZERO,OPMode_WR_Retry = ZERO,ErrRetry = ZERO,Cfg_retry=ZERO,cfg_error = ME_OK,FMVer_mismatch = ME_FALSE;
	uint32_t installedmap,temp32,OpModeMask,Bitmsk;
    uint64_t temp64;
	uint8_t const * pauSnrIdxList;
    uint8_t *pSensorInfo,*pData;
    uint8_t snr_index,cnt,TotalSensors,nSeg,TotalSeg,opmode,Err;
    uint16_t len,temp,tempData,ver=0;
    US_S_SensorsCfg_t const *pSnrCfg;
    (void)RcvSize;
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
    uint32_t tem32_index =0;
#endif
	pSnrCfg = US_SnrCfg_F_Get_SnrCfg();
	(void)US_SnrDrvCom_F_CountSnr(TEN,NULL,&TotalSensors,pSnrCfg->SnrMap,ZERO);
	pauSnrIdxList  = UssCtrl_pauGetSnrIdxList();    /*Get pointer to the sensor index list.*/
    installedmap   = US_SnrCfg_F_Get_InstSnrMap(US_ALL_POS);   /* get installed sensor map */
     /*KPK-QAC Fix : Need to suppress, no impact on pointer casting to uint16_t */
    len = *(uint16_t*)RcvData;
    pData  = &RcvData[TWO];
    if(ErrorCode == ME_OK)
    {
		if((USS_CfgErr_Flag == ME_TRUE)&&(USS_CfgErr_State == US_SnrCalAdj_State))
		{
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
			US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,(pSnrCfg->SnrMap));
#else
			for(cnt = ZERO; cnt < TotalSensors; cnt++ )
			{
				temp32 = ((pSnrCfg->SnrMap)>>cnt)&BIT0;
				if(temp32 != ZERO)
                {
				   snr_index = pauSnrIdxList[cnt];
				   US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,snr_index);
                }
			}
#endif
		}
        switch(Cmd)
        {
        case US_CONFIGURE_SENSOR_DELAY:
           	    TotalSeg = (uint8_t)((UserData>>24u) & 0x7fu);
            	nSeg = (uint8_t)((UserData>>16u) & 0x7fu);
            	if(nSeg >= TotalSeg)
            	{
            		if((UserData & 0x7fffu) == (uint32_t)US_SNRCALCFG_RESET_OPMODE_DELAY)
            		{
            			US_SnrCalCfg_State = (uint16_t)US_SNRCALCFG_AUTOADDRESSING;
            		}
            		else
            		{
            		    if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
						{
							US_SnrCalCfg_State++;
						}
						else{
							/* Overflow error handling */
						}
            		}
            	}

        	 break;
        case (DSI_CMD_READ_MASTER_REG|DSI3_REG_STAT):
               temp  = US_SnrCfg_F_AutoAddressCheck((uint16_t*)RcvData);
             if((temp != ME_OK)&&(Retry <= (uint16_t) MAX_AUTOADDRESS_RETRY))  
             {
                	 if((Retry%THREE) == TWO)
                 	 {
                       	  US_SnrCalCfg_State = (uint16_t)US_SNRCALCFG_TRANCEIVER_RESET;
                 	 }else
                 	 {
                       	  US_SnrCalCfg_State = (uint16_t)US_SNRCALCFG_AUTOADDRESSING;
                 	 }
						Retry++;
					
              }
             else
             {

					if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
					{
						US_SnrCalCfg_State++;
					}
					else{
						/* Overflow error handling */
					}					
            	 UssCtrl_PopulatePhysTopologyInfo();
            	 Retry = ZERO;
             }
        	break;
        case REQ_SENSOR_SNR_DIAGNOSTIC_RESULT:          /* get Sensor Diagnostic result */
        	Err = UssCtrl_DiagProcess(len,pData,UserData);
            if(Err == SENSOR_CFG_CRM_ERROR)
            {
            	if(Cfg_retry < MAX_DIAGNOSTIC_FAIL_RETRY)
            	{
            	    US_SnrCalCfg_State = US_SNRCALCFG_AUTOADDRESSING;
           	        Cfg_retry++;
            	}else{
              	    US_SnrCalCfg_State++;
            		Cfg_retry = ZERO;
            	}
            }else if(Err == SENSOR_OPMODE_CRC_ERROR)
            {       if(OPMode_WR_Retry < MAX_SETUP_OPMODE_RETRY)
                    {
           	           US_SnrCalCfg_State = US_SNRCALCFG_SET_SENSORS_OPMODE;
           	           OPMode_WR_Retry++;
                    }else{
                        if(US_SnrCalCfg_State <(uint16_t)0xffffu)
                       {
                 	            US_SnrCalCfg_State++;
                         }else{
                             /* do nothing*/
                        }
                 	   OPMode_WR_Retry = ZERO;
                    }
             }
            else
            {
         	   if(US_SnrCalCfg_State  < (uint16_t)US_SNRCALCFG_MAX)
                       {
                           US_SnrCalCfg_State++;
                       }
         	   if(US_SnrCalCfg_State  >= (uint16_t)US_SNRCALCFG_MAX)
         	    {
          	        Cfg_retry = ZERO;
          	        OPMode_WR_Retry     = ZERO;
         	    }
            }
        	break;
        case REQ_SENSOR_SNR_DIAGNOSTIC_RESULT_F11A:          /* get Sensor Diagnostic result*/
                               if(US_SnrCalCfg_State <(uint16_t)0xffffu)
                           {
				US_SnrCalCfg_State++;
                         }
  			else{
				/* Overflow error handling */
			}
            break;

        case REQ_SENSOR_OPERATION_MODE:
		   Err = ZERO;
     	   pSensorInfo = (uint8_t*)US_SnrCfg_Get_AllSensors_opmode();
      	   (void)memset(pSensorInfo, 0, MAX_NUM_SENSORS * sizeof(uint8_t));
      	    OpModeMask = ZERO;
        	opmode = SENSOR_CFG_OPMODE;
			ver = US_SnrCfg_Get_SnrFWVer();
          	for (cnt = ZERO; (cnt < TotalSensors); cnt++) {
				temp = (uint16_t)cnt<<ONE;
				if(temp < len)
				{
						snr_index = pData[temp] & 0x7fu;
						Bitmsk =((uint32_t)BIT0<<snr_index);
						if (snr_index < TotalSensors) {
							snr_index = pauSnrIdxList[snr_index];
							 pSensorInfo[snr_index] = pData[temp + ONE];
							if(pSensorInfo[snr_index] != ZERO)
							{
								Err = ONE;
							}
							if(( pSensorInfo[snr_index] != SENSOR_CFG_OPMODE)&&(ver != (uint16_t)QM_SNR_FW_VER))  
							{
								opmode = (SENSOR_CFG_OPMODE==SENSOR_OP_NORMAL)?(SENSOR_OP_MFG):(SENSOR_OP_NORMAL);   
		#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									tem32_index = (1<<snr_index);
									US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_OPMODE_ERROR,SnrfwmismatchMap);
		#else
									US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_OPMODE_ERROR,snr_index);
		#endif
									OpModeMask |= Bitmsk;
							}
							else
							{
		 #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									tem32_index = (1<<snr_index);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_OPMODE_ERROR,SnrfwmismatchMap);
		#else
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_OPMODE_ERROR,snr_index);
		#endif
							}
						}
				}
          	}
          	pSensorInfo[MAX_NUM_SENSORS - ONE] =  SENSOR_CFG_OPMODE;
          	if((opmode != SENSOR_CFG_OPMODE)&&(OPMode_WR_Retry < MAX_SETUP_OPMODE_RETRY))
          	{
           	        if(opmode != SENSOR_CFG_OPMODE){
					  if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
					  {
						US_SnrCalCfg_State ++;
					  }
					  else{
						/* Overflow error handling */
					  }
					}
                                       OPMode_WR_Retry++;
           	}
          	else
          	{
          		     US_SnrCfg_SetOpModeMask(OpModeMask);
         		if(US_SnrCalCfg_State< (uint16_t)US_SNRCALCFG_MAX)
                                           {
            	                          US_SnrCalCfg_State += SIX;
                                            }else{
                                           /* do nothing */
                                          }
          	}
         	break;
        case REQ_SENSOR_FW_VER:          /* get Sensor firmware version*/
		   Err = ZERO;
      	   pSensorInfo = (uint8_t*)US_SnrCfg_Get_AllSnrFWVer();
     	   (void)memset(pSensorInfo, 0, MAX_NUM_SENSORS * sizeof(uint16_t));   
          	FMVer_mismatch = ME_FALSE;
           	ver = 0;
        	for (cnt = ZERO; (cnt < TotalSensors); cnt++) {
                                    temp =  (uint16_t)cnt * THREE;
                                   if(temp < len)
                                   {
      		snr_index = pData[temp] & 0x7fu;
        		if (snr_index < TotalSensors) {
        			snr_index = pauSnrIdxList[snr_index];
        			tempData = pData[temp + ONE];
        			tempData = (tempData << EIGHT) | pData[temp + TWO];
        			if (tempData != ZERO) {
        				*((uint16_t*)((uint16_t*)pSensorInfo + snr_index)) = tempData;   
						Err = ONE;
        				if(ver == ZERO)
        				{
        					/*Copy the first FW Version*/
        					ver = tempData;
        					*((uint16_t*)((uint16_t*)pSensorInfo +MAX_NUM_SENSORS - ONE)) = tempData; 
       				     }
        				/*check the FW version with the FW version received first sensor on the bus*/
        				if(ver != tempData)
        				{
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
        					tem32_index = (1<<snr_index);
        					US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_FW_MISMATCH,SnrfwmismatchMap);
#else
                            US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_FW_MISMATCH,snr_index);
#endif
                            FMVer_mismatch = ME_TRUE;
        				}
        				else
        				{
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
        					tem32_index = (1<<snr_index);
        					US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_FW_MISMATCH,SnrfwmismatchMap);
#else
                            US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_FW_MISMATCH,snr_index);
#endif
        				}
        			}
        		}
        	}
	        	}
         	if(((FMVer_mismatch != (uint16_t)ME_FALSE)||((Err == ZERO)&&(installedmap!=(uint32_t)ZERO)))&&(Retry < (uint16_t)MAX_READ_VERSION_RETRY))
          	{
            	                  Retry++;
          	}
          	else
          	{
          	         if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
					 {
						US_SnrCalCfg_State++;
					 }
					 else{
						/* Overflow error handling */
					 }
          		     Retry = ZERO;
          	}
            break;
        case REQ_SENSOR_EEPROM:
           if((UserData & 0xffffu)== (uint32_t)US_SNRCALCFG_REQ_SENSORS_SENSITIVITY)      
           {
        	   pSensorInfo = (uint8_t*)US_SnrCfg_Get_AllNewSensorID();
        	   (void)memset(pSensorInfo, 0, MAX_NUM_SENSORS * sizeof(uint64_t));
        	/*get new Sensor ID*/
                for (cnt = ZERO; (cnt < TotalSensors); cnt++) {
                        temp = (uint16_t)cnt * SEVEN;
                      if(temp < len)
                     {
                          snr_index = pData[temp] & 0x7fu;
                        if (snr_index < TotalSensors) {
                             snr_index = pauSnrIdxList[snr_index];
                                 temp64 = RcvData[temp + THREE];
                                 temp64 = (temp64 << EIGHT) | RcvData[temp + FOUR];
                                 temp64 = (temp64 << EIGHT) | RcvData[temp + FIVE];
                                 temp64 = (temp64 << EIGHT) | RcvData[temp + SIX];
                                 temp64 = (temp64 << EIGHT) | RcvData[temp + SEVEN];
                                 temp64 = (temp64 << EIGHT) | RcvData[temp + EIGHT];
                             if (temp64 != ZERO) {
                            	 *((uint64_t*)((uint64_t*)pSensorInfo +snr_index)) = temp64;   
                              }
                        }
                  }
                }
	      }
           else if((UserData & 0xffffu) == (uint32_t)US_SNRCALCFG_REQ_SENSORS_RESET_REASON)   
           {
        	   pSensorInfo = (uint8_t*)US_SnrCfg_Get_AllReset_reason();
        	   (void)memset(pSensorInfo, 0, MAX_NUM_SENSORS * sizeof(uint16_t));
                 for (cnt = ZERO; cnt < TotalSensors; cnt++) {
                        temp = (uint16_t)cnt*THREE;
                      if(temp < len)
                     {
                      snr_index = pData[temp] & 0x7fu;
                       if (snr_index < TotalSensors) {
                             snr_index = pauSnrIdxList[snr_index];
                                 tempData = RcvData[temp + THREE];
                                 tempData = (tempData << EIGHT) | RcvData[temp + FOUR];
                                 *((uint16_t*)((uint16_t*)pSensorInfo+ snr_index))  =  tempData;   
                        }
                }
             }
           }
          else{/*empty*/}
     	  if(US_SnrCalCfg_State < ((uint16_t)UINT16_MAX))
		  {
			US_SnrCalCfg_State++;
		  }
		  else{
			/* Overflow error handling */
		  }
            break;

        case REQ_SENSOR_ID:       /* get Sensor ID*/
		   Err = ZERO;
     	   pSensorInfo = (uint8_t*)US_SnrCfg_Get_AllSensorID();
     	   (void)memset(pSensorInfo, 0, MAX_NUM_SENSORS * sizeof(uint32_t));
             for (cnt = ZERO; cnt < TotalSensors; cnt++) {
                         temp = (uint16_t)cnt*FIVE;
                      if(temp < len)
                     {
                  snr_index = pData[temp] & (uint8_t)0x7fu;
                if (snr_index < TotalSensors) {
                    snr_index = pauSnrIdxList[snr_index];
                    temp32 = RcvData[temp + THREE];
                    temp32 = (temp32 << EIGHT) | RcvData[temp + FOUR];
                    temp32 = (temp32 << EIGHT) | RcvData[temp + FIVE];
                    temp32 = (temp32 << EIGHT) | RcvData[temp + SIX];
                    if (temp32 != ZERO) {
                    	*((uint32_t*)((uint32_t*)pSensorInfo+ snr_index))  = temp32;   
						Err = ONE;
                    }
                }
             }
            }
        	if((Err == ZERO)&&(installedmap!=(uint32_t)ZERO)&&(Retry <= (uint16_t)MAX_READ_SENSORID_RETRY))
			{
						Retry++;
			}
			else{				
          	         if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
					 {
						US_SnrCalCfg_State++;
					 }
					 else{
						/* Overflow error handling */
					 }
          		     Retry = ZERO;
			}
            break;
        default:
        	TotalSeg = (uint8_t)((UserData>>24u) & 0x7fu);
        	nSeg = (uint8_t)((UserData>>16u) & 0x7fu);
        	if(nSeg >= TotalSeg)
        	{
        		if(US_SnrCalCfg_State < ((uint16_t)0xFFFF))
				{
					US_SnrCalCfg_State++;
				}
				else{
					/* Overflow error handling */
				}
        	}
        	break;
        }
        UssCtrl_SnrCalCfg_Cmd_Completed = US_CTRL_SNRCAL_CMD_COMPLETED;
    }
    else if((ErrorCode != ERROR_US_SNRDRVCOM_INVLID_SNRMAP)&&(ErrRetry <= MAX_CFGCMD_RETRY))
    {

    	        cfg_error = (uint16_t)ErrorCode;
		ErrRetry ++;
		        UssCtrl_SnrCalCfg_Cmd_Completed = ErrorCode;
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
							US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,(pSnrCfg->SnrMap));
#else
							for(cnt = ZERO; cnt < TotalSensors; cnt++ )
							{
								temp32 = ((pSnrCfg->SnrMap)>>cnt)&BIT0;
								if(temp32 != ZERO)
		                        {
								   snr_index = pauSnrIdxList[cnt];
							       US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,snr_index);
		                        }
							}
#endif
							USS_CfgErr_Flag  = ME_TRUE;
							USS_CfgErr_State = US_SnrCalAdj_State;


    }
    else
    {
    	if(Cmd == REQ_SENSOR_OPERATION_MODE)
    	{
    		US_SnrCalCfg_State = US_SNRCALCFG_DIAGNOSTIC_RESULT_CHK;
    	}
    	else if(US_SnrCalCfg_State <0xffffu)
    	{
     	    US_SnrCalCfg_State++;
    	}else{/* empty */}
    	ErrRetry = ZERO;
        UssCtrl_SnrCalCfg_Cmd_Completed = US_CTRL_SNRCAL_CMD_COMPLETED;
    }

    if((UserData & ((uint32_t)SENSOR_LAST_CFGCMD_BIT)) != 0u)
    {
        systate = UssMgr_eGetSysState();
		if((cfg_error == (uint16_t)ME_OK)&&(systate != SYSMGR_SYS_CALIBRATION))  
        {
           opmode  =  US_SnrCfg_Get_OperationMode();
            if(FMVer_mismatch != (uint8_t)ME_FALSE)
            {
            	UssMgr_SetSysState(SYSMGR_SYS_CALIBRATION);
            }
            else if(installedmap == pSnrCfg->SnrMap)
            {
                UssMgr_SetSysState(SYSMGR_SYS_READY);
            }
            else if(opmode != (uint8_t)US_NORMAL_MODE)
            {
                UssMgr_SetSysState(SYSMGR_SYS_DIAGNOSTIC);
            }
            else
            {
                UssMgr_SetSysState(SYSMGR_SYS_CALIBRATION);
            }
        }
        else
        {
           cfg_error = ME_OK;
           UssMgr_SetSysState(SYSMGR_SYS_DIAGNOSTIC);
        }
    }
}

/* ===========================================================================
 * Name: UssCtrl_SnrCfg_GetDoneStatus    
 * Remarks:  DD-ID: {08C349FE-714A-4c26-A483-D01E1F40F89F}
 * ===========================================================================*/
bool_t UssCtrl_SnrCfg_GetDoneStatus(void)
{
	 bool_t ret = (bool_t)ME_FALSE;
	 if(US_SnrCalCfg_State >= (uint16_t)US_SNRCALCFG_MAX)
	 {
		 ret = (bool_t)ME_TRUE;
	 }
	return ret;
}


/* ===========================================================================
 * Name: UssCtrl_SnrConfigure_Start    
 * Remarks:  DD-ID: {722B3F14-014B-4540-8867-FBE4AAEFFD21}
 * ===========================================================================*/
void UssCtrl_SnrConfigure_Start(void)
{
	UssMgr_SetSysState(SYSMGR_SYS_CONFIG);
    if(US_SnrCalCfg_State >= (uint16_t)US_SNRCALCFG_MAX)
    {
    	USS_CfgErr_Flag = ME_FALSE;
    	US_SnrCalCfg_State = US_SNRCALCFG_AUTOADDRESSING;
    }
}


/* ===========================================================================
 * Name: UssCtrl_CfgSensor_Task    
 * Remarks:  DD-ID: {919F8DD6-AAD1-4b2a-9CDD-F82FD4922D26}
 * ===========================================================================*/
void UssCtrl_CfgSensor_Task(void)
{
    static uint8_t USS_PowerON = ME_TRUE;
	static uint8_t *RcvData = NULL;
	static uint16_t nSeg = ZERO;
	uint32_t seqId,state,map,type,DataID,len,seqsize,ret = ME_NOT_OK;
	uint16_t temp_index = ZERO;

	US_SnrCalCfg_CmdTable_t const *pItem;
	uint32_t tempData[(sizeof(US_S_ProfileCfg_Index_t)/FOUR)+ONE];
    uint8_t const *pCfgData = NULL;
    if(RcvData == NULL)
    {
    	RcvData  = (uint8_t*)US_SnrCfg_F_Cali_GetBuffer();
    }
	if(US_SnrCalCfg_State == (uint16_t)US_SNRCALCFG_INIT)
	{
		US_SnrCalCfg_State = (uint16_t)US_SNRCALCFG_TRANCEIVER_RESET;        /*US_SNRCALCFG_AUTOADDRESSING;*/
	}
    temp_index = (uint16_t)UssCtrl_Get_Temperature_Index();

	if(US_SnrCalCfg_State < (uint16_t)US_SNRCALCFG_MAX)
	{
        if(UssCtrl_SnrCalCfg_Cmd_Completed != US_CTRL_SNRCAL_CMD_BUSY)
        {
        	for(state = (uint16_t)US_SNRCALCFG_INIT; state <(uint16_t)US_SNRCALCFG_MAX; state++)
			{
				pItem = (US_SnrCalCfg_CmdTable_t*)&US_SnrCalCfg_CmdTable[state];    
				if(US_SnrCalCfg_State == pItem->state)
				{
					break;
				}
			}
        	if((UssCtrl_SnrCalCfg_Cmd_Completed != ONE)&&(nSeg > ZERO))   /* command fails, need to re-try same Seqment data*/
        	{
        		nSeg --;
        	}
			if((US_SnrCalCfg_State == pItem->state)&&(US_SnrCalCfg_State < (uint16_t)US_SNRCALCFG_MAX))     
			{
				if(US_SnrCalCfg_State == (uint16_t)US_SNRCALCFG_AUTOADDRESSING_READ)     
				{
					map = US_SnrCfg_F_Get_SnrBusMap((uint16_t)pItem->SensorLoc);
				}
 				else
				{
				    map = US_SnrCfg_F_Get_CfgSnrMap((uint16_t)pItem->SensorLoc);
				}
				type = pItem->CalData_Type;
				DataID = pItem->CalData_ID;
				len    = pItem->inDataLen;
				seqsize = len/(pItem->nSeg);
				pCfgData = (uint8_t*)US_SnrCfg_SnrCalAdjust(temp_index,type,(uint16_t)DataID,USERINFO_NONE);
				if(pCfgData != NULL)
				{
				  pCfgData += (nSeg*seqsize);
				}
				if(nSeg < ((uint16_t)0xFFFF))
				{
					nSeg++;
				}
				else{
					/* Overflow error handling */
				}
				seqId = (uint32_t)US_SnrCalCfg_State |((uint32_t)nSeg << 16u)|(((uint32_t)(pItem->nSeg)&0x7fu)<<24u);   /* assume Segment less than 128*/
				if(US_SnrCalCfg_State  == (((uint16_t)US_SNRCALCFG_MAX )-ONE) )
				{
					USS_PowerON = ME_FALSE;
					seqId = seqId|((uint32_t)SENSOR_LAST_CFGCMD_BIT);           // last setup
				}
				if(DataID == SETUP_SENSOR_PROFILE_PLUS)
				{
					US_S_ProfilePlus_IndexCfg_t *ProfilePlus =(US_S_ProfilePlus_IndexCfg_t*)tempData;   
					ProfilePlus->Profile = (uint8_t)((pItem->param >>16u)& 0xffu);
					ProfilePlus->STCShift = (uint8_t)((pItem->param >>8u)& 0xffu);
					ProfilePlus->STGFixValue = (uint8_t)(pItem->param & 0xffu);
					pCfgData = (uint8_t*)tempData;
				}
				else if((DataID == SETUP_SENSOR_OPERATURE_MODE)||(DataID == DSI_CMD_READ_MASTER_REG)||(DataID == DSI_CMD_WRITE_MASTER_REG))
				{
						tempData[0] = (pItem->param);
						pCfgData = (uint8_t*)tempData;
				}
				else if(DataID == SETUP_SENSOR_EEPROM)
				{
						US_S_EEPROMCfg_t *eep = (US_S_EEPROMCfg_t*)tempData ;  
						eep->Addr     =   (uint8_t)((pItem->param) & 0xffu);
						eep->length   =   (uint8_t)len;
						len = sizeof(US_S_EEPROMCfg_t);
						pCfgData = (uint8_t*)tempData;
				}
				else if((DataID == PROFILE_CFG_ID)&&(pCfgData != NULL))
				{
						tempData[0] = (uint32_t)(type<<16)|(pItem->param);
						(void)memcpy((uint8_t*)&tempData[ONE],pCfgData,sizeof(US_S_ProfileCfg_t));
						pCfgData = (uint8_t*)tempData;
				}
				else{
					/*do nothing*/		}
				if((pCfgData !=NULL)||(len == ZERO))
				{
					if((pItem->UssCtrl_SnrCalCfgFxn != NULL)&&(map != ZERO))
					{
						   UssCtrl_SnrCalCfg_Cmd_Completed = ME_OK;
						   ret = (pItem->UssCtrl_SnrCalCfgFxn)(map,seqId,(uint16_t)len,pCfgData,3072u,RcvData,UssCtrl_SnrCfgCallBack);
						   if(ret != ME_OK){
						       UssCtrl_SnrCalCfg_Cmd_Completed = US_CTRL_SNRCAL_CMD_COMPLETED;
						   }else if(nSeg >= (pItem->nSeg)){
									nSeg =ZERO;
							}else{  /*do nothing*/
							}
					}
					else                     /* it does not stuck here*/
					{
						US_SnrCalCfg_State++;
						nSeg =ZERO;
					}
				}
				else                     /* it does not stuck here*/
				{
					US_SnrCalCfg_State++;
					nSeg =ZERO;
					US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_NO_CALI_DATA);/*KPK-Reason Code*/
				}
			}
			else                     /* it does not stuck here*/
			{
				if(US_SnrCalCfg_State < ((uint16_t)0xFFFFu))
				{
					US_SnrCalCfg_State++;
				}
				else{
					/* Overflow error handling */
				}
				nSeg =ZERO;
			}
       }
	}
	else
	{
		nSeg =ZERO;
	}
}



/* ===========================================================================
 * Name: UssCtrl_DiagProcess    
 * Remarks:  DD-ID: {741089A8-3E8C-4289-976F-8FD7C7762FD5}
 * ===========================================================================*/
static uint8_t UssCtrl_DiagProcess(uint16_t len,  uint8_t *RcvData,uint32_t UserData)
{
				US_S_SensorsCfg_t const *pSnrCfg;
				uint8_t snr_index,TotalSensors,cnt,CRM_CMD_Fail,tempData;
				uint8_t const * pauSnrIdxList;
 				uint32_t temp32;
				uint16_t loc,loc_tmp;
				pSnrCfg = US_SnrCfg_F_Get_SnrCfg();
				(void)US_SnrDrvCom_F_CountSnr(TEN,NULL,&TotalSensors,pSnrCfg->SnrMap,ZERO);
				CRM_CMD_Fail = (uint8_t)ME_OK;
				pauSnrIdxList  = UssCtrl_pauGetSnrIdxList();    /* Get pointer to the sensor index list.*/
				for(cnt = ZERO;(cnt<TotalSensors) && (((uint16_t)cnt*ELEVEN) < len);cnt++)
				{
					loc =(uint16_t) cnt *(uint16_t) ELEVEN;
					snr_index = RcvData[loc] & 0x7fu;
					 if(snr_index < TotalSensors)
					 {
							snr_index = pauSnrIdxList[snr_index];
							loc_tmp = loc + FIVE;
   							tempData = RcvData[loc_tmp] & (uint8_t)SENSOR_CFGERR_BIT;
							temp32  = UserData & (uint32_t)SENSOR_LAST_CFGCMD_BIT; 
							if(temp32 != ZERO){
								if(tempData != ZERO)
								{
									   CRM_CMD_Fail = SENSOR_CFG_CRM_ERROR;
			#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
										temp32 = (1<<snr_index);
										US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,temp32);
			#else
										US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,snr_index);
			#endif
								}
								else if(USS_CfgErr_Flag == ME_FALSE)
								{
			#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
										temp32 = (1<<snr_index);
										US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,temp32);
			#else
										US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,snr_index);
			#endif
								}else{/* empty */}
							}else
							{
 							loc_tmp = loc + SEVEN;
   							tempData = RcvData[loc_tmp] & (uint8_t)SENSOR_OPMODE_CRC_BITS;
							if(tempData == (uint8_t)SENSOR_OPMODE_CRC_BITS)
							{
	#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
								     temp32 = (1<<snr_index);
									 US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE1,temp32);
									 US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2,temp32);
	#else
									 US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE1,snr_index);
									 US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE2,snr_index);
	#endif
									 CRM_CMD_Fail = SENSOR_OPMODE_CRC_ERROR;
							}else{
		#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									temp32 = (1<<snr_index);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE1,temp32);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2,temp32);
		#else
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE1,snr_index);
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE2,snr_index);
		#endif
									}
							        tempData = RcvData[loc_tmp] & (uint8_t)SENSOR_BLOCKCFG_CRC_BITS;
									if(tempData == (uint8_t)SENSOR_BLOCKCFG_CRC_BITS)
									{
		#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									temp32 = (1<<snr_index);
										  US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG1,temp32);
										  US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2,temp32);
		#else
										  US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG1,snr_index);
										  US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG2,snr_index);
		#endif
										  
									}else{
		#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									temp32 = (1<<snr_index);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG1,temp32);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2,temp32);
		#else
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG1,snr_index);
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG2,snr_index);
		#endif
									}
							        tempData = RcvData[loc_tmp] & ((uint8_t)SENSOR_BLOCKMFG_CRC_BITS);
									if(tempData == (uint8_t)SENSOR_BLOCKMFG_CRC_BITS)
									{
		#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									temp32 = (1<<snr_index);SENSOR_BLOCKMFG_CRC_BITS
										  US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG1,temp32);
										  US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2,temp32);
		#else
										  US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG1,snr_index);
										  US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG2,snr_index);
		#endif
										  
									}else{
		#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
									temp32 = (1<<snr_index);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG1,temp32);
									US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2,temp32);
		#else
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG1,snr_index);
									US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG2,snr_index);
		#endif
									}
							}
					 }
				}
   return CRM_CMD_Fail;
}

/* ===========================================================================
 * Name: UssCtrl_SnrAdj_Callback    
 * Remarks:  DD-ID: {86E57919-4C0E-424a-99E1-3D951BFEBC4E}
 * ===========================================================================*/
static void UssCtrl_SnrAdj_Callback(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData)
{
    static uint8_t Adj_retry =ZERO;
	const US_S_SensorsCfg_t *pSnrCfg;
	uint32_t temp32;
	uint8_t  nSeg,TotalSeg,snr_index,TotalSensors,cnt,CRM_CMD_Fail;
    uint8_t const *pauSnrIdxList;
	uint16_t len;
    (void)RcvSize;
    len = *(uint16_t*)RcvData;
	pSnrCfg = (const US_S_SensorsCfg_t *)US_SnrCfg_F_Get_SnrCfg();
	US_SnrDrvCom_F_CountSnr(TEN,NULL,&TotalSensors,pSnrCfg->SnrMap,ZERO);
	pauSnrIdxList  =(uint8_t const *) UssCtrl_pauGetSnrIdxList();    // Get pointer to the sensor index list.
	if(ErrorCode == ME_OK)
     {
		if((USS_CfgErr_Flag == ME_TRUE)&&(USS_CfgErr_State == US_SnrCalAdj_State))
		{
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
			US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,(pSnrCfg->SnrMap));
#else
			for(cnt = ZERO; cnt < TotalSensors; cnt++ )
			{
				temp32 = ((pSnrCfg->SnrMap)>>cnt)&BIT0;
				if(temp32 != ZERO)
                {
				   snr_index = pauSnrIdxList[cnt];
				   US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,snr_index);
                }
			}
#endif
		}

	    switch(Cmd)
		{
		  case REQ_SENSOR_SNR_DIAGNOSTIC_RESULT:             /* get Sensor Diagnostic result*/
				 CRM_CMD_Fail = UssCtrl_DiagProcess(len,&RcvData[TWO],UserData);
				if((CRM_CMD_Fail == (uint8_t)SENSOR_CFG_CRM_ERROR)&&(Adj_retry <= (uint8_t)MAX_DIAGNOSTIC_FAIL_RETRY))
				{
						 US_SnrCalAdj_State = (uint16_t)US_SNRCALADJ_INIT;
						Adj_retry++;
				 }
				else
				{
					if(US_SnrCalAdj_State < ((uint16_t)0xFFFF))
					{
						US_SnrCalAdj_State++;
					}
					else{
						/* Overflow error handling */
					}
					Adj_retry = ZERO;
				}
				break;
			case REQ_SENSOR_SNR_DIAGNOSTIC_RESULT_F11A:          /* get Sensor Diagnostic result*/
				if(US_SnrCalAdj_State < ((uint16_t)0xFFFF))
				{
					US_SnrCalAdj_State++;
				}
				else{
					/* Overflow error handling */
				}
				break;
			default:
        	TotalSeg = (uint8_t)((UserData>>24u) & 0x7fu);
        	nSeg = (uint8_t)((UserData>>16u) & 0x7fu);
        	if(nSeg >= TotalSeg)
			{
				if(US_SnrCalAdj_State < ((uint16_t)0xFFFF))
				{
					US_SnrCalAdj_State++;
                    g_UssDbg_AdjResultCounters[ZERO]++;
				}
				else{
					/* Overflow error handling */
				}
			}
				break;
		}
    	UssCtrl_SnrAdj_Cmd_Complete = US_CTRL_SNRCAL_CMD_COMPLETED;
     }
    else if((ErrorCode != ERROR_US_SNRDRVCOM_INVLID_SNRMAP)&&(Adj_retry <= MAX_CFGCMD_RETRY))
    {
		Adj_retry ++;
    	    UssCtrl_SnrAdj_Cmd_Complete = ErrorCode;
			pauSnrIdxList  = UssCtrl_pauGetSnrIdxList();    // Get pointer to the sensor index list.

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
							US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,(pSnrCfg->SnrMap));
#else
							for(cnt = ZERO; cnt < TotalSensors; cnt++ )
							{
								temp32 = ((pSnrCfg->SnrMap)>>cnt)&BIT0;
								if(temp32 != ZERO)
		                        {
								   snr_index = pauSnrIdxList[cnt];
							       US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,snr_index);
		                        }
							}
#endif
							USS_CfgErr_Flag  = ME_TRUE;
							USS_CfgErr_State = US_SnrCalAdj_State;
    }
    else{
    	if(US_SnrCalAdj_State < ((uint16_t)0xFFFF))
		{
			US_SnrCalAdj_State++;
		}
		else{
			/* Overflow error handling */
		}
    	Adj_retry = ZERO;
    	UssCtrl_SnrAdj_Cmd_Complete = US_CTRL_SNRCAL_CMD_COMPLETED;
    }
}



/* ===========================================================================
 * Name: UssCtrl_SnrCalAdj_GetDoneStatus    
 * Remarks:  DD-ID: {83F14329-5C17-4ba0-B012-23C2FA407F9A} 
 * ===========================================================================*/
 bool_t UssCtrl_SnrCalAdj_GetDoneStatus(void)
{
	 bool_t ret = (bool_t)ME_FALSE;
	 if(US_SnrCalAdj_State >= (uint16_t)US_SNRCALADJ_MAX)
	 {
		 ret = (bool_t)ME_TRUE;
	 }
	return ret;
}

/* ===========================================================================
 * Name: UssCtrl_SnrCalAdj_Start    
 * Remarks:  DD-ID: {54B5FA0E-2AC0-4f3c-BBD1-7641948D124F}
 * ===========================================================================*/
void UssCtrl_SnrCalAdj_Start(void)
{
	if(US_SnrCalAdj_State >= (uint16_t)US_SNRCALADJ_MAX)
	{
			US_SnrCalAdj_State = (uint16_t)US_SNRCALADJ_INIT;
	    	USS_CfgErr_Flag = ME_FALSE;
			UssCtrl_SnrCalAdj_Task();
	}
}

/* ===========================================================================
 * Name: UssCtrl_SnrCalAdj_Task     
 * Remarks:  DD-ID: {54B5FA0E-2AC0-4f3c-BBD1-7641948D124F} 
 * ===========================================================================*/
void UssCtrl_SnrCalAdj_Task(void)
{
    static uint8_t *RcvData = NULL;
	static uint16_t nSeg = ZERO;
	uint32_t seqId,state,map,type,DataID,len,seqsize,userinfo,ret = ME_NOT_OK;
	uint16_t temp_index = ZERO;
	US_SnrAdj_CmdTable_t const *pItem;
	uint32_t tempData[(sizeof(US_S_ProfileCfg_Index_t)/FOUR)+ONE];
    uint8_t const *pAdjData = NULL;
    if(RcvData == NULL)
    {
    	RcvData  = (uint8_t*)US_SnrCfg_F_Cali_GetBuffer();
    }
	if(US_SnrCalAdj_State < (uint16_t)US_SNRCALADJ_MAX)
	{
		if(US_SnrCalAdj_State == (uint16_t)US_SNRCALADJ_INIT)
		{
            /* Required to avoid interpolation bug. This triggers the correct calculation with 0 hysteresis */
		    (void)UssCtrl_GetSnrCfgIndex();
			US_SnrCalAdj_State ++;
            g_UssDbg_AdjResultCounters[ZERO] = ZERO;
            g_UssDbg_AdjResultCounters[ONE] = ZERO;
            g_UssDbg_AdjResultCounters[TWO] = ZERO;
		}
	    temp_index = UssCtrl_Get_Temperature_Index();
        if(UssCtrl_SnrAdj_Cmd_Complete != ZERO)
        {
        	for(state = (uint16_t)US_SNRCALADJ_INIT; state <(uint16_t)US_SNRCALADJ_MAX; state++)
			{
				pItem =(US_SnrAdj_CmdTable_t*) &US_SnrAdj_CmdTable[state];
				if(US_SnrCalAdj_State == pItem->state)
				{
					break;
				}
			}
			if((US_SnrCalAdj_State == pItem->state)&&(US_SnrCalAdj_State < (uint16_t)US_SNRCALADJ_MAX))
			{
				map = US_SnrCfg_F_Get_CfgSnrMap((uint16_t)pItem->SensorLoc);
				type = pItem->CalData_Type;
				DataID = pItem->CalData_ID;
                userinfo = pItem->UserInfo;
				len    = pItem->DataLen;
				seqsize = len/(pItem->nSeg);
				pAdjData = (uint8_t*)US_SnrCfg_SnrCalAdjust(temp_index,type,(uint16_t)DataID,userinfo);
				if((pAdjData !=NULL)||(len == ZERO))
				{
                    if(pAdjData !=NULL)
                    {
                        pAdjData += (nSeg*seqsize);
#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
                        if(pItem->UsedDataCopyPtr != NULL)
                        {
                            (void)memcpy(((void*)(((uint8_t*)pItem->UsedDataCopyPtr)+(nSeg*seqsize))),(void*)pAdjData,seqsize);
                        }
#endif
                    }
					if(nSeg < ((uint16_t)0xFFFF))
					{
						nSeg++;
					}
					else{
						 /* Overflow error handling */
					}
					seqId = (uint32_t)US_SnrCalAdj_State |((uint32_t)nSeg << 16u)|((((uint32_t)pItem->nSeg)&0x7fu)<<24u);   /* assume Segment less than 128*/
					if(US_SnrCalAdj_State ==(((uint16_t)US_SNRCALADJ_MAX) - ONE) )
					{
						seqId = seqId|(uint32_t)SENSOR_LAST_CFGCMD_BIT;           // last setup
					}
					if((DataID == PROFILE_CFG_ID)&&(pAdjData !=NULL))
					{
						tempData[0] = (uint32_t)(type<<16)|(pItem->Index);
						(void)memcpy((uint8_t*)&tempData[ONE],pAdjData,sizeof(US_S_ProfileCfg_t));
						pAdjData = (uint8_t*)tempData;
					}
					if((pItem->US_Snr_SetupAdjFxn != NULL)&&(map != ZERO))
					{
						   UssCtrl_SnrAdj_Cmd_Complete = ME_OK;
						   ret = (pItem->US_Snr_SetupAdjFxn)(map,seqId,(uint16_t)len,pAdjData,3072u,(uint8_t*)RcvData,UssCtrl_SnrAdj_Callback);
						   if(ret != ME_OK){
						       UssCtrl_SnrCalCfg_Cmd_Completed = US_CTRL_SNRCAL_CMD_COMPLETED;
						   }else if(nSeg >= (pItem->nSeg)){
									nSeg =ZERO;
							}else{  /*empty */
							}
					}
					else                     /* it does not stuck here*/
					{
						US_SnrCalAdj_State++;
						nSeg =ZERO;
                        g_UssDbg_AdjResultCounters[ONE]++;
					}
				}
				else                     /* it does not stuck here*/
				{
					if(US_SnrCalAdj_State < ((uint16_t)0xFFFF))
					{
						US_SnrCalAdj_State++;
					}
					else{
						/* Overflow error handling */
					}
					nSeg =ZERO;
					US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_NO_CALI_DATA);/*KPK-Reason Code*/
                    g_UssDbg_AdjResultCounters[TWO]++;
				}
			}
			else /* comment_out_if((US_SnrCalAdj_State == pItem->state)&&(US_SnrCalAdj_State < (uint16_t)US_SNRCALADJ_MAX)) */
			{
                /* this can happen with table size mismatch!!
                 * currently will freeze the system in an idle state while this check keeps failing
                 * Since we have no "assert" or error reported for this - let it fail loudly */
#if 0
                if(US_SnrCalAdj_State < ((uint16_t)0xFFFF))
                {
                    US_SnrCalAdj_State++;
                }
                else{
                    /* Overflow error handling */
                }
                nSeg =ZERO;
#endif
			}
        }
	}
	else
	{
		nSeg =ZERO;
	}
}
/* ===========================================================================
	* Name:	 UssCtrl_uGetSnrCalAdjState
	* Remarks:  DD-ID: {EA4E6C61-0183-49ae-9324-9BFBFE3AA987}
	* ===========================================================================*/
#if (QAC_WARNING_FIX  ==  ME_FALSE)
uint16_t UssCtrl_uGetSnrCalAdjState(void)
{
    return US_SnrCalAdj_State;
}
#endif


