/*
 * US_SnrCfg_Calibration.c
 *
 *  Created on: Apr 9, 2021
 *      Author: e39960
 */


#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrCfg_data_struct.h"
#include "US_SysMgr_Global.h"
#include "US_Ctrl_Global.h"
#include "US_SnrCfg_Calibration.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Calib_CsmIf.h"
#endif

extern uint8_t UssStubOutput_SnrCfg_CmdReq(uint8_t *ptrCmd, uint8 cmdSize,uint8 snrTuneId);

#define MAX_REQ_CMD_SIZE (3072u)
#define CAL_SNR_DISCOUNT (0xF800u)
static uint8_t Tuning_Intf = ZERO,Cali_Exit_Mode = ZERO;

static uint32_t US_SnrCfg_F_Cali_ReqCfgCmd(uint16_t Cmd,uint32_t UserData,uint32_t *Buffer,uint16_t Len);
static uint32_t US_SnrCfg_F_Cali_ReqFlashDataCmd(uint16_t Cmd,uint32_t UserData,uint32_t *Data,uint16_t Len);
static uint32_t US_SnrCfg_F_Cali_SetCfgCmd(uint16_t Cmd,uint32_t UserData,uint32_t *Buffer,uint16_t Len);
static uint16_t CalculateChksum16(uint16_t *buf,uint16_t size,uint8_t isCmp);
static void US_SnrCfg_F_CaliCmd_Process(void);
uint16_t ID_Send_ME_CalibrationData(uint8_t *SndData,uint16_t len,uint8_t ID);

static uint16_t US_SnrCfg_CaliCmd_Response(uint8_t *SndData,uint16_t len,uint8_t ID);

typedef enum US_SnrCfg_CmdTable_Function_Type_s
{
 SENSOR_CFG_CMD,
 ECU_CFG_CMD
}US_SnrCfg_CmdTable_Function_Type_t;
const static US_S_SnrCfg_cal_Item_Header_t US_S_TuneFlashCfg_item =
{
  .ItemID  = 2,
  .Length  = sizeof(US_S_TuneFlashCfg_t) + sizeof(uint32_t),
  .Descr   = 0
};
const static US_S_TuneFlashCfg_t US_S_TuneFlashCfg =
{
   .SizeBufferCmd = 2048,
   .MaxCmds      = 16,
   #if((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM)
   .DIDType      = 0,
   .AddressType  = 0,      /*0:Absolute address,1:relative address */
    .StartBlockAddress = 0xE0000,
   #elif(US_D_CUR_PLATFORM == US_D_PLATFORM_AMAZON)
   .DIDType      = 0,
   .AddressType  = 0,      /*0:Absolute address,1:relative address */
   .StartBlockAddress = 0x160000,
   #else
   .DIDType      = 2,
   .AddressType  = 1,      /*0:Absolute address,1:relative address */
   .StartBlockAddress = 0x00000,
   #endif
   .SizeBlock    = 0x10000,
   .SizeEraseBlock = 0x1000
};
const static US_SnrCfg_CmdTable_t US_SnrCfg_CmdTable[] =
{                   
/*	Cmd,                                  index                           function0                                 function1*/
  {REQ_CALIBRATION_CFG,                      (uint16_t)ECU_CFG_CMD,                 NULL,                               US_SnrCfg_F_Cali_ReqCfgCmd},
  {REQ_FLASH_MEMORY_DATA,                    (uint16_t)ECU_CFG_CMD,                 NULL,                               US_SnrCfg_F_Cali_ReqFlashDataCmd},
  {SET_CALIBRATION_CFG,                      (uint16_t)ECU_CFG_CMD,                 NULL,                               US_SnrCfg_F_Cali_SetCfgCmd},
  {REQ_SENSOR_AUTO_ADDRESSING,               (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_AutoAddressingCmd,                 NULL},

  {REQ_SENSOR_ID,                            (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorIDCmd,                    NULL},
  {REQ_SENSOR_AMBIENT_TEMPATURE,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorAmbiTempCmd,              NULL},
  {REQ_SENSOR_FW_VER,                        (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSnrFWVer,                       NULL},
  {REQ_SENSOR_OPERATION_MODE,                (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorOPModeCmd,                NULL},
  {REQ_SENSOR_TEMPATURE,                     (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorTempCmd,                  NULL},
  {REQ_SENSOR_FREQUENCY,                     (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorFreqCmd,                  NULL},
  {REQ_SENSOR_GANA_MEAS_BEGIN,               (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqGanaMeasBeginCmd,               NULL},
  {REQ_SENSOR_EEFLAG_VARCTRL,                (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorEEFlagCTRL,               NULL},
  {REQ_SENSOR_RFM_CTRL,                      (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqRFMCtrlCmd,                     NULL},
  {REQ_SENSOR_EEVAL_SENS_MEAS,               (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqEEVALSensMeasCmd,               NULL},
  {REQ_SENSOR_CPS_MEAS_GAIN,                 (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqCPSMeasGainCmd,                 NULL},
  {REQ_SENSOR_OUTPUT_SIGNAL_DATA,            (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqEnvDataCmd,                     NULL},
  {REQ_SENSOR_EDI_CHANNEL,                   (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqEDIChannelCmd,                  NULL},
  {REQ_SENSOR_NFD,                           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqNFDCmd,                         NULL},
  {REQ_SENSOR_FIX_PATH_CFG,                  (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqFixPathCfgCmd,                  NULL},
  {REQ_SENSOR_MAX_ECHO_NUMBER,               (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqMaxEchoNumCmd,                  NULL},
  {REQ_SENSOR_ENVELOPE_FILTER_CONFIG,        (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqEnvFiltCfgCmd,                  NULL},
  {REQ_SENSOR_ENVELOPE_CONFIG,               (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqEnvCfgCmd,                      NULL},
  {REQ_SENSOR_G_CAL,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqCalGainCmd,                     NULL},
  {REQ_SENSOR_GAIN,                          (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqGainCmd,                        NULL},
  {REQ_SENSOR_CURRENT_CFG,                   (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqCurrentCmd,                     NULL},
  {REQ_SENSOR_BURST_TYPE_CONFIG,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqBurstTypeCfgCmd,                NULL},
  {REQ_SENSOR_RINGINGCOMPARATOR,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqRingingCompCmd,                 NULL},
  {REQ_SENSOR_CHIRP_BW,                      (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqChirpBWCmd,                     NULL},
  {REQ_SENSOR_NORMAL_BURST_NUMBER,           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqNormalBurstNumCmd,              NULL},
  {REQ_SENSOR_FC,                            (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqFCCmd,                          NULL},
  {REQ_SENSOR_AATG2,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqAATG2Cmd,                       NULL},
  {REQ_SENSOR_AATG1,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqAATG1Cmd,                       NULL},
  {REQ_SENSOR_ATG,                           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqATGCmd,                         NULL},
  {REQ_SENSOR_FTC,                           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqFTCCmd,                         NULL},
  {REQ_SENSOR_SNR_DIAGNOSTIC_RESULT_F11A,    (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd,      NULL},
  {REQ_SENSOR_SNR_DIAGNOSTIC_RESULT,         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd,      NULL},
  {REQ_SENSOR_AD_VOLTAGE,                    (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqADVoltager,                     NULL},
  {REQ_SENSOR_STC,                           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSTCCmd,                         NULL},
  {REQ_SENSOR_STG,                           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSTGCmd,                         NULL},
  {REQ_SENSOR_EEPROM,                        (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorEEPROMCmd,                NULL},
  {REQ_SENSOR_DETECTION_SAME_MEASUREMENT,    (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSendBurstCmd,                   NULL},
  {REQ_SENSOR_DETECTIPON_QUICK,              (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSendBurstCmd,                   NULL},
  {REQ_SENSOR_PROFILE,                       (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqProfileCmd,                     NULL},
  {REQ_SENSOR_PROFILE_PLUS,                  (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqProfilePlusCmd,                 NULL},
  {REQ_SENSOR_REGISTER,                      (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqSensorRegisterCmd,              NULL},
  {DSI_CMD_READ_MASTER_REG,                  (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_ReqDSIMasterRegByTableCmd,         NULL},

  {SETUP_SENSOR_PROFILE_PLUS,                (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetProfilePlusCmd,                 NULL},
  {SETUP_SENSOR_PROFILE,                     (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetProfileCmd,                     NULL},
  {SETUP_SENSOR_CHIRP_BW,                    (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetChirpBWCmd,                     NULL},
  {SETUP_SENSOR_BURST_TYPE_CONFIG,           (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetBurstTypeCfgCmd,                NULL},
  {SETUP_SENSOR_CURRENT_CFG,                 (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetCurrentCmd,                     NULL},
  {SETUP_SENSOR_GAIN,                        (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetGainCmd,                        NULL},
  {SETUP_SENSOR_G_CAL,                       (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetCalGainCmd,                     NULL},
  {SETUP_SENSOR_ENVELOPE_CONFIG,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetEnvCfgCmd,                      NULL},
  {SETUP_SENSOR_ENVELOPE_FILTER_CONFIG,      (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetEnvFiltCfgCmd,                  NULL},
  {SETUP_SENSOR_MAX_ECHO_NUMBER,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetMaxEchoNumCmd,                  NULL},
  {SETUP_SENSOR_FIX_PATH_CFG,                (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetFixPathCfgCmd,                  NULL},
  {SETUP_SENSOR_EDI_CHANNEL,                 (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetEDIChannelCmd,                  NULL},
  {SETUP_SENSOR_AMBIENT_TEMPERATURE,         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSensorAmbiTempCmd,              NULL},
  {SETUP_SENSOR_EEPROM,                      (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSensorEEPROMCmd,                NULL},
  {SETUP_SENSOR_OPERATURE_MODE,              (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSensorOPModeCmd,                NULL},
  {SETUP_SENSOR_REGISTER,                    (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSensorRegisterCmd,              NULL},
  {SETUP_SENSOR_FTC,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetFTCCmd,                         NULL},
  {SETUP_SENSOR_ATG,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetATGCmd,                         NULL},
  {SETUP_SENSOR_AATG1,                       (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetAATG1Cmd,                       NULL},
  {SETUP_SENSOR_AATG2,                       (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetAATG2Cmd,                       NULL},
  {SETUP_SENSOR_FC,                          (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetFCCmd,                          NULL},
  {SETUP_SENSOR_NORMAL_BURST_NUMBER,         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetNormalBurstNumCmd,              NULL},
  {SETUP_SENSOR_NFD,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetNFDCmd,                         NULL},
  {SETUP_SENSOR_GANA_MEAS_BEGIN,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetGanaMeasBeginCmd,               NULL},
  {SETUP_SENSOR_EEFLAG_VARCTRL,              (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSensorEEFlagVarCTRLCmd,         NULL},
  {SETUP_SENSOR_STG,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSTGCmd,                         NULL},
  {SETUP_SENSOR_STC,                         (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetSTCCmd,                         NULL},
  {SETUP_SENSOR_ENABLE_ADDRBYEEP,            (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetADDRBYEEPROMCmd,                NULL},
  {SETUP_SENSOR_EEVAL_SENS_MEAS,             (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetEEVALSENSMEASCmd,               NULL},
  {DSI_CMD_WRITE_MASTER_REG,                 (uint16_t)SENSOR_CFG_CMD,      US_SnrDrvMgr_F_SetDSIMasterRegByTableCmd,         NULL},

  {0,                                        0,                                NULL,                                NULL}
};

#if((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM)
__attribute__((section(".DataBuff"))) static uint32_t US_SnrCfg_Cali_data[70],US_SnrCfg_Req_data[1024],AutoUseID;
#else
  static uint32_t US_SnrCfg_Cali_data[70],US_SnrCfg_Req_data[1024],AutoUseID;
#endif
static uint16_t US_SnrCfg_Cali_Cmd_Len,US_SnrCfg_Cali_Output_Offset;
static uint8_t US_SnrCfg_Cali_Req_Ready =ME_FALSE,US_SnrCfg_Cali_Cmd_Ready = ME_FALSE,US_Cali_AutoAddress = ME_FALSE;

static uint8_t US_SnrCfg_EMC_Cmd_Ready= ME_FALSE;
static uint8_t *AutoAddr;

extern uint16_t USS_Send_UssTunningDataByIPC(const uint8_t *SndData,uint16_t len,uint8_t ID);

#if(US_CSM_ENABLE == ME_TRUE)
static UsCsm_LocalStateId_Type LocalStateId_Calib = US_CSM_LOCAL_STATE_UN_INIT;
#endif

#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM)||(US_D_CUR_PLATFORM == US_D_PLATFORM_AMAZON))
/* ===========================================================================
 * Name:    US_Get_CalNVMData
 * Remarks: DD-ID: {FCA2B23A-BAB8-4fa5-AF6E-43CBAAD66683}
 * Req.-ID:16134127
 * Req.-ID:16134106
 * ===========================================================================*/
uint8_t *US_Get_CalNVMData(void)
{
		return (uint8_t*)US_S_TuneFlashCfg.StartBlockAddress;
}
#endif

#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_SnrCfg_F_Cali_GetOutputFlag.
* interface function: get flag if there is data output to CAN bus.
* \param: None
* \return return flag: true: data is ready in data buffer for CAN transmission, it will be automatically cleared
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:     US_SnrCfg_F_Cali_GetOutputFlag
 * Remarks:  DD-ID: {75E03B4F-E70B-4809-BFC1-7A176E23A492}
 * ===========================================================================*/

uint8_t US_SnrCfg_F_Cali_GetOutputFlag(void)		
{
	uint8_t ret = US_SnrCfg_Cali_Req_Ready;
	US_SnrCfg_Cali_Req_Ready = ME_FALSE;
	return ret;
	
}
#endif
/* ===========================================================================*/
/**US_SnrCfg_F_Get_SnrCfg.
* used to Init Sensor MAP cfg.
* param none
* return no returns
* remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_Init
 * Remarks:  DD-ID: {5EFAFFA9-B95A-4a91-808F-95BCFC7E8E57}
 * ===========================================================================*/
void US_SnrCfg_Calib_F_Init(void)
{
	Cali_Exit_Mode = ZERO;
	US_SnrCfg_EMC_Cmd_Ready= ME_FALSE;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Cali_GetBuffer.
* interface function: get data buffer pointer, First two bytes is data length.
* \param: None
* \return return Data buffer pointer
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:    US_SnrCfg_F_Cali_GetBuffer
 * Remarks: DD-ID: {897BE875-AE92-44e0-BEC1-5D47D2ED8CF4}
 * Req.-ID: 14959893
 * Req.-ID: 13396023
 * Req.-ID: 13523824
 * ===========================================================================*/
uint8_t* US_SnrCfg_F_Cali_GetBuffer(void)
{
	return (uint8_t*)US_SnrCfg_Req_data;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Cali_Callback.
* Call back function of Sensor cmd: process cmd return status and data.
* \param: ErrorCode: Cmd return status,Cmd: the Cmd ID of sending to Sensor, UserData:Cmd Sequence Id
* \param: RcvSize: Receive data buffer size, RcvData: Receive data buffer
* \return None
* \remarks  no remarks
*/
/* ========================================================================= */

 /* ===========================================================================
  * Name:    US_SnrCfg_F_Cali_Callback
  * Remarks: DD-ID: {F0B57B7E-86B3-4559-8DE4-A3E062057E02}
  * Req.-ID:14959893
  * Req.-ID:13396023
  * Req.-ID:13523824
  * ===========================================================================*/
static void US_SnrCfg_F_Cali_Callback(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData)
{
	uint16_t *pSndBuf;
	uint8_t *pData;
    (void)RcvSize;
    if((ErrorCode == ME_OK)&&(Cmd == REQ_SENSOR_AUTO_ADDRESSING))
    {
    	AutoUseID = UserData;
    	AutoAddr = RcvData;
    	US_Cali_AutoAddress = ME_TRUE;
    }
    else if(US_SnrCfg_Cali_Output_Offset < (MAX_REQ_CMD_SIZE - EIGHT))
	{	
		pSndBuf = (uint16_t *)US_SnrCfg_Req_data;
		if((US_Cali_AutoAddress == (uint8_t)ME_TRUE)&&(Cmd == (DSI3_REG_STAT|DSI_CMD_READ_MASTER_REG)))
		{
			pSndBuf[US_SnrCfg_Cali_Output_Offset/TWO] = REQ_SENSOR_AUTO_ADDRESSING;                /*return cmdid */
		}
		else
		{
			pSndBuf[US_SnrCfg_Cali_Output_Offset/TWO] =(uint16_t)(Cmd & 0xffffu);                /*return cmdid */
		}
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO )+ ONE] = (uint16_t)(UserData & (~BIT15));      /*return sequence id */
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + TWO] = (uint16_t)(ErrorCode & 0xffffu);                           /*cmd is successful */
		if(((ErrorCode == ME_OK)&&(((Cmd & 0xFF00u) == 0x7000u)||((US_Cali_AutoAddress == (uint8_t)ME_TRUE)&&(Cmd == (DSI3_REG_STAT|DSI_CMD_READ_MASTER_REG)))))&&(pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] +EIGHT < (MAX_REQ_CMD_SIZE-TWO)))
		{
			if((US_Cali_AutoAddress == (uint8_t)ME_TRUE)&&(Cmd == (DSI3_REG_STAT|DSI_CMD_READ_MASTER_REG)))
			{
				(void)US_SnrCfg_F_AutoAddressCheck((uint16_t*)RcvData);   
			    pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] = EIGHT*TWO;
				pData = US_SnrCfg_Get_nSensor();
				(void)memcpy((uint8_t*)&pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + FOUR],pData,EIGHT*TWO);
			    US_SnrCfg_Cali_Output_Offset += (EIGHT*TWO) + EIGHT;
			    US_Cali_AutoAddress = ME_FALSE;
		    }
			else
			{
				US_SnrCfg_Cali_Output_Offset += pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] +EIGHT;
			}
		}
		else
		{
			pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] = ZERO;
			US_SnrCfg_Cali_Output_Offset +=  EIGHT;
		}
		if((UserData & BIT15)!= 0u)                                          /*Last cmd */
		{
			pData = (uint8_t*)pSndBuf;
			if((US_SnrCfg_Cali_Output_Offset%TWO)!= 0u)
			{
				pData[US_SnrCfg_Cali_Output_Offset] = ZERO;
				US_SnrCfg_Cali_Output_Offset++;
			}
			pData[US_SnrCfg_Cali_Output_Offset++] = 0xA5;
			pData[US_SnrCfg_Cali_Output_Offset++] = 0x5A;
			pSndBuf[ZERO] = US_SnrCfg_Cali_Output_Offset-TWO;
			pSndBuf[ONE] = ZERO;
			pSndBuf[ONE] = CalculateChksum16(pSndBuf,US_SnrCfg_Cali_Output_Offset/TWO,ONE);
			US_SnrCfg_Cali_Req_Ready = ME_TRUE;
		}
	}
	else
	{/*nothing*/}
}
/* ===========================================================================*/
/**US_SnrCfg_F_Cali_task.
* Calibration module task, it is periodically called by system task. process calibration cmd and sensor cfg cmd
* \param: NOne
* \return None
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:    US_SnrCfg_F_Cali_task
 * Remarks: DD-ID: {292E2927-365F-4ae9-8A3E-7EB780BABB28}
 * Req.-ID:14959893
 * Req.-ID:13396023
 * Req.-ID:13523824
 * ===========================================================================*/
void US_SnrCfg_F_Cali_task(void)
{
        static uint16_t RspDatalen = ZERO;
	uint32_t SnrMap;
	uint8_t SysState;
        uint16_t len;
	SysState = (uint8_t)UssMgr_eGetSysState();
	if((SysState == (uint8_t)SYSMGR_SYS_READY)||(SysState == (uint8_t)SYSMGR_SYS_CALIBRATION)||(SysState == (uint8_t)SYSMGR_SYS_DIAGNOSTIC))
	{
		US_SnrCfg_F_CaliCmd_Process();
		if((SysState == (uint8_t)SYSMGR_SYS_CALIBRATION)&&(US_SnrCfg_Cali_Req_Ready == (uint8_t)ME_TRUE))
		{
			if(RspDatalen < US_SnrCfg_Cali_Output_Offset)
			{
			   len = US_SnrCfg_CaliCmd_Response((uint8_t*)US_SnrCfg_Req_data + RspDatalen,US_SnrCfg_Cali_Output_Offset - RspDatalen,US_SNR_TUNE_OUT_ID);
			   RspDatalen += len;                                 
			   if(RspDatalen >= US_SnrCfg_Cali_Output_Offset)     
			   {
					US_SnrCfg_Cali_Output_Offset = ZERO;
					RspDatalen = ZERO;
					US_SnrCfg_Cali_Req_Ready = ME_FALSE;
			   }
			}
			else
			{
				US_SnrCfg_Cali_Output_Offset = ZERO;
				RspDatalen = ZERO;
				US_SnrCfg_Cali_Req_Ready = ME_FALSE;
			}
		}
		else if(US_Cali_AutoAddress == (uint8_t)ME_TRUE)
		{
	    	SnrMap = US_SnrCfg_F_Get_SnrBusMap(US_ALL_POS);
	    	(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(SnrMap,AutoUseID,DSI3_REG_STAT,64,AutoAddr,US_SnrCfg_F_Cali_Callback);
		}
		else{/*empty*/}
        if( (US_SnrCfg_EMC_Cmd_Ready!= (uint8_t)ME_FALSE)&&(US_SnrCfg_Get_OperationMode() == US_SNR_TEST_MODE)) 
        {
        	US_SnrCfg_EMC_Cmd_Ready = ME_FALSE;
        	US_Diagnostic_Init();
        	/* Req.-ID: 13396045 */
        	US_ECUDiagnostic_Init();

        }
        else{/*empty*/}
	}
	else{/*empty*/}
}

/* ===========================================================================*/
/**US_SnrCfg_F_CaliCmd_Process.
* Process calibration cmd
* \param: NOne
* \return None
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:    US_SnrCfg_F_CaliCmd_Process
 * Remarks: DD-ID: {D25CE65F-5B93-44b4-8412-0E35491B4D28}
 * Traceability to source Code: Req.-ID: 14959893
 * Req.-ID: 14959893
 * Req.-ID: 13396023
 * Req.-ID: 13523824
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexity */
static void US_SnrCfg_F_CaliCmd_Process(void)
{
	  uint16_t *pCmdBuf16,*pSndBuf,cnt,CmdID,CmdLen,offset;
	  uint32_t SnrMap,seqid,*pCmdbuf32;
	  if(US_SnrCfg_Cali_Cmd_Ready == (uint8_t)ME_TRUE)
	  {
		  
		  pCmdBuf16 = (uint16_t*)US_SnrCfg_Cali_data;
		  pCmdbuf32 = US_SnrCfg_Cali_data;
		  seqid = ZERO;
		  if(CalculateChksum16(pCmdBuf16,US_SnrCfg_Cali_Cmd_Len/TWO,ZERO) == ZERO)    /*check chksum */
		  {
			    offset = FOUR;
			    US_SnrCfg_Cali_Output_Offset = FOUR;
			    while((offset + EIGHT )<=  US_SnrCfg_Cali_Cmd_Len)
	            {
					CmdID = pCmdBuf16[offset/TWO];
			        CmdLen = pCmdBuf16[(offset/TWO) + ONE];
			        cnt = ZERO;
			        while(US_SnrCfg_CmdTable[cnt].cmd != ZERO)
			        {
				       if(US_SnrCfg_CmdTable[cnt].cmd == CmdID)
					   {
						   break;
					   }
				       cnt++;
			        }
					if(US_SnrCfg_CmdTable[cnt].cmd == CmdID)
					{

						if( (offset + CmdLen + FOUR)>=  US_SnrCfg_Cali_Cmd_Len)
						{
							seqid |= BIT15;   /*set last cmd flag */
						}
						SnrMap = pCmdbuf32[(offset/FOUR) + TWO];
						switch(US_SnrCfg_CmdTable[cnt].index_fxn)
						{
						 case ((uint16_t)SENSOR_CFG_CMD):   
	 					       (*US_SnrCfg_CmdTable[cnt].US_Snr_Fxn)(SnrMap,seqid,CmdLen-FOUR,(uint8_t*)&pCmdbuf32[(offset/FOUR) + THREE],3072u,((uint8_t*)US_SnrCfg_Req_data) + ((seqid&0x7fffu)*EIGHT) + US_SnrCfg_Cali_Output_Offset+SIX,US_SnrCfg_F_Cali_Callback);
	                         break;
						 case ((uint16_t)ECU_CFG_CMD):      
						       (*US_SnrCfg_CmdTable[cnt].US_ECUFxn)(CmdID,seqid,(uint32_t*)&pCmdbuf32[(offset/FOUR) + TWO],CmdLen-FOUR);
	                         break;
						default:
							/* Empty */
							break;
						}
						UssMgr_SetSysState(SYSMGR_SYS_CALIBRATION);
					}
					else
					{
						/*send cmd error */
					}
					seqid++;
					offset += CmdLen + FOUR;
				}
		  }
		  else
		  {
			    pSndBuf = (uint16_t *)US_SnrCfg_Req_data;
		    	pSndBuf[ZERO]    = TEN;
		    	pSndBuf[ONE]     = ZERO;            /*chksum */
		    	pSndBuf[TWO]     = pCmdBuf16[ZERO];            /*cmd */
		    	pSndBuf[THREE]   = pCmdBuf16[ONE];            /*user ID */
		    	pSndBuf[FOUR]     = (uint16_t)(ERROR_US_SNRDRVCOM_CMD_CHECKSUM_ERROR & (uint32_t)0xffff);
		    	pSndBuf[FIVE]     = ZERO;
			    US_SnrCfg_Cali_Output_Offset = TEN + TWO;
		        pSndBuf[ONE]     = CalculateChksum16(pSndBuf,US_SnrCfg_Cali_Output_Offset/TWO,ONE);
		       	US_SnrCfg_Cali_Req_Ready = ME_TRUE;

		  }
		  US_SnrCfg_Cali_Cmd_Ready = ME_FALSE;
	  }

}
/* ===========================================================================*/
/**CalculateChksum16.
* Calculate 16 bit checksum
* \param: buf: data buffer for calculation of checksum, 16 bit data size for calculation of checksum, isCmp:true-- compliment checksum output
* \return 16 bit checksum result
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:    CalculateChksum16
 * Remarks: DD-ID: {80FA6049-2BC5-4965-9C3C-2874AD0D54C9}
 * Req.-ID:13523824
 * Req.-ID:13425669
 * ===========================================================================*/
static uint16_t CalculateChksum16(uint16_t *buf,uint16_t size,uint8_t isCmp)
{
	uint16_t cnt,chksum;
	chksum= ZERO;
	for(cnt=0;cnt<size;cnt++)
	{
		chksum += buf[cnt];
	}
	if((isCmp)!= 0u)   /*if it is compliment */
	{
		chksum = (~chksum) + 1u;		
	}
	return chksum;
}
/* ===========================================================================*/
/**US_SnrCfg_F_Cali_SetCfgCmd.
* Setup Sensors cfg cmd
* \param: Cmd: cmd Id, UserData: cmd sequence Id,Buffer: cmd data buffer, len: cmd data size
* \return: cmd status
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_F_Cali_SetCfgCmd
 * Remarks: DD-ID: {D6C75247-145A-4bfe-9BEF-8FAA1B962D17}
 * Req.-ID:14959893
 * Req.-ID:13396023
 *
 * ===========================================================================*/

static uint32_t US_SnrCfg_F_Cali_SetCfgCmd(uint16_t Cmd,uint32_t UserData,uint32_t *Buffer,uint16_t Len)
{
	uint16_t *pSndBuf;
	uint8_t *Snrcfg;
	uint32_t ret = ME_NOT_OK;
	if(US_SnrCfg_Cali_Output_Offset < 1024u)
	{	
		pSndBuf = (uint16_t *)US_SnrCfg_Req_data;
		pSndBuf[US_SnrCfg_Cali_Output_Offset/TWO] = Cmd;                /*return cmdid */
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + ONE] = (uint16_t)(UserData &(~BIT15));      /*return sequence id(mask bit15) */
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + TWO] = ME_OK;                           /*cmd is successful */
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] = ZERO;                           /*cmd is successful */
		if(Len >= (sizeof(US_S_SensorsCfg_t) + sizeof(uint32_t)))                     /*if data length is enough */
		{
			Snrcfg = (uint8_t*)US_SnrCfg_F_Get_SnrCfg();
                        /*KPK-QAC Fix : Need to suppress, Destination buffer have engh memory to copy the data */
			(void)memcpy((void*)Snrcfg,(void*)Buffer,sizeof(US_S_SensorsCfg_t) - sizeof(pUS_S_Sensor_coordinate_t));
		}
		else
		{
			pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + TWO] = (uint16_t)(ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH & (uint32_t)0xffff);                           /*Data is not enough */

		}
		US_SnrCfg_Cali_Output_Offset +=  EIGHT;
		if((UserData & BIT15)!= 0u)   /*last cmd? */
		{
	    	pSndBuf[ZERO] = US_SnrCfg_Cali_Output_Offset-TWO;
	       	pSndBuf[ONE] = ZERO;
	       	pSndBuf[ONE] = CalculateChksum16(pSndBuf,US_SnrCfg_Cali_Output_Offset/TWO,ONE);
	       	US_SnrCfg_Cali_Req_Ready = ME_TRUE;
		}
		ret = ME_OK;
	}
	else
	{
		
	}
	return ret;

}
/* ===========================================================================*/
/**US_SnrCfg_F_Cali_ReqCfgCmd.
* Request Sensors cfg and flash cfg
* \param: Cmd: cmd Id, UserData: cmd sequence Id,Buffer: cmd data buffer, len: cmd data size
* \return: cmd status
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_F_Cali_ReqCfgCmd
 * Remarks: DD-ID: {6A7CB19A-B67F-4f0e-B148-8D18CC31CE01}
 * Req.-ID:14959893
 * Req.-ID:13396023
 *
 * ===========================================================================*/
static uint32_t US_SnrCfg_F_Cali_ReqCfgCmd(uint16_t Cmd,uint32_t UserData,uint32_t *Buffer,uint16_t Len)
{
	uint16_t *pSndBuf,offset;
	uint8_t *Snrcfg;
	uint32_t ret = ME_OK;
    (void)Len;(void)Buffer;
	if(US_SnrCfg_Cali_Output_Offset < 1024u)
	{
		US_S_SnrCfg_cal_Item_Header_t *pItemHeader;
		pSndBuf = (uint16_t *)US_SnrCfg_Req_data;
		pSndBuf[US_SnrCfg_Cali_Output_Offset/TWO] = Cmd;                /*return cmdid */
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + ONE] = (uint16_t)(UserData &(uint32_t)0x7fff);      /*return sequence id */
		pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + TWO] = ME_OK;                           /*cmd is successful */
                /*KPK-QAC Fix : Need to suppress, no impact on pointer casting to US_S_SnrCfg_cal_Item_Header_t */
		pItemHeader = (US_S_SnrCfg_cal_Item_Header_t*)&pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + FOUR]; 	    /*snr cfg*/
		pItemHeader->ItemID = SENSOR_MAP_CFG_ID;
		pItemHeader->Length = sizeof(US_S_SensorsCfg_t) + sizeof(uint32_t);
		pItemHeader->Descr  = ZERO;
		Snrcfg = (uint8_t*)US_SnrCfg_F_Get_SnrCfg();
	    offset =(US_SnrCfg_Cali_Output_Offset/TWO) + FOUR + (sizeof(US_S_SnrCfg_cal_Item_Header_t)/TWO);
	    (void)memcpy((void*)&pSndBuf[offset],(void*)Snrcfg,sizeof(US_S_SensorsCfg_t));
	    offset += sizeof(US_S_SensorsCfg_t)/TWO;
	    (void)memcpy((void*)&pSndBuf[offset],(void*)&US_S_TuneFlashCfg_item,sizeof(US_S_SnrCfg_cal_Item_Header_t));			
	    offset += (sizeof(US_S_SnrCfg_cal_Item_Header_t))/TWO;		
	    (void)memcpy((void*)&pSndBuf[offset],(void*)&US_S_TuneFlashCfg,sizeof(US_S_TuneFlashCfg_t));							
	    offset += (sizeof(US_S_TuneFlashCfg_t))/TWO;			
	    pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] = (offset *TWO) -US_SnrCfg_Cali_Output_Offset -EIGHT;
	    US_SnrCfg_Cali_Output_Offset =  offset * TWO;
       if((UserData & BIT15)!= 0u)
       {
    	  pSndBuf[ZERO] = US_SnrCfg_Cali_Output_Offset-TWO;
       	  pSndBuf[ONE] = ZERO;
       	  pSndBuf[ONE] = CalculateChksum16(pSndBuf,US_SnrCfg_Cali_Output_Offset/TWO,ONE);
          US_SnrCfg_Cali_Req_Ready = ME_TRUE;
      }
	}
	else
	{
		ret = ME_NOT_OK;
	}
	return ret;

}


/* ===========================================================================*/
/**US_SnrCfg_F_Cali_ReqFlashDataCmd.
* Request flash data of Calibration block
* \param: Cmd: cmd Id, UserData: cmd sequence Id,Data: cmd data buffer, len: cmd data size
* \return: cmd status
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_F_Cali_ReqFlashDataCmd
 * Remarks: DD-ID: {7E7CC833-2D6D-4875-8FCE-AAC6DC4DC3B2}
 * Req.-ID: 13473275
 * ===========================================================================*/
static uint32_t US_SnrCfg_F_Cali_ReqFlashDataCmd(uint16_t Cmd,uint32_t UserData,uint32_t *Data,uint16_t Len)
{
	uint16_t *pSndBuf;
	uint32_t Addr,Size,ret = ME_OK;
	uint8_t *pFlash;
	if((US_SnrCfg_Cali_Output_Offset < 1024u) &&(Data != NULL))
	{	
	  pSndBuf = (uint16_t *)US_SnrCfg_Req_data;
	  pSndBuf[US_SnrCfg_Cali_Output_Offset/TWO] = Cmd;                /*return cmdid */
	  pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + ONE] = (uint16_t)(UserData &(uint32_t)0x7fff);      /*return sequence id */
	  if(Len >= EIGHT)
	  {
	    Addr = (*Data) - US_S_TuneFlashCfg.StartBlockAddress;  		                                  /*flash address */
	    Size =*(Data + ONE);
	    /*size of reading flash */
	    pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + TWO] = ME_OK;                           /*cmd is successful */
        if((Size%TWO)!= 0u)
        {
        	Size++;
        }
	    pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] = (uint16_t)Size;
	    pFlash = Addr + US_SnrCfg_GetDataAddr();
	    (void)memcpy((void*)&pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + FOUR],pFlash,Size);
	    US_SnrCfg_Cali_Output_Offset += (uint16_t)Size + EIGHT;

	  }
	  else
	  {
		  /*pSndBuf[US_SnrCfg_Cali_Output_Offset/TWO + TWO] = DTC_SNR_DISCONNECT;       Data is not enough */
		  pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + TWO] = (uint16_t)SNR_DIAG_FLG_SENSOR_DISCONNECT;       /*Data is not enough */

		  pSndBuf[(US_SnrCfg_Cali_Output_Offset/TWO) + THREE] = ZERO;
		  US_SnrCfg_Cali_Output_Offset +=  EIGHT;

	  }
      if(( UserData & BIT15)!= 0u)     /*Last cmd */
      {
    	pSndBuf[ZERO] = US_SnrCfg_Cali_Output_Offset-TWO;
       	pSndBuf[ONE] = ZERO;
       	pSndBuf[ONE] = CalculateChksum16(pSndBuf,US_SnrCfg_Cali_Output_Offset/TWO,ONE);
       	US_SnrCfg_Cali_Req_Ready = ME_TRUE;
      }
    }
	else
	{
		ret = ME_NOT_OK;
	}
	return ret;

}


/* ===========================================================================*/
/**US_SnrCfg_F_Cali_RcvCmd.
* interface function: Receive calibration cmd from CAN bus and copy to internal buffer
* \param: Cmdbuf: cmd data buffer, len: cmd data size
* \return: none
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_RcvCmd
 * Remarks: DD-ID: {7BBB586F-ABE1-446a-A21F-FB56FE7EE055}
 * Req.-ID:13523824
 * ===========================================================================*/
static  uint16_t US_SnrCfg_RcvCmd(uint8_t *cmdbuf,uint16_t len,uint8_t header_len)
{
	uint16_t ret = ME_NOT_OK;
	static UssMgr_e_SysState_t uss_cur_state;
	switch(cmdbuf[0])
	{
		case US_SNR_TUNE_IN_ID:
			(void)memcpy((void*)US_SnrCfg_Cali_data,cmdbuf+header_len,len);  /*shift two bytes for 32 bit align */
			US_SnrCfg_Cali_Cmd_Len =len;
			US_SnrCfg_Cali_Cmd_Ready = ME_TRUE;
			ret = ME_OK;
			break;

		case US_SNR_TUNE_EXIT_IN_ID:
			 if(cmdbuf[ONE] == ZERO)
			 {
				 switch(cmdbuf[TWO] & (uint8_t)0xC0)
				 {
				 case 0x40:
					 Cali_Exit_Mode = cmdbuf[TWO];
				     if(uss_cur_state == SYSMGR_SYS_CALIBRATION)
				     {
				    	 uss_cur_state =  SYSMGR_SYS_CONFIG;
				    	 UssMgr_SetSysState(uss_cur_state);
				    	 UssCtrl_TriggerSnrCfg();
				     }
			       ret = ME_OK;
				    break;
				 case 0x80:
					 Cali_Exit_Mode = cmdbuf[TWO];
				     if(uss_cur_state == SYSMGR_SYS_CALIBRATION)
				     {
					    uss_cur_state = SYSMGR_SYS_READY;
				     }
				    UssMgr_SetSysState(uss_cur_state);
			        ret = ME_OK;
				    break;

				 case 0x00:
					 cmdbuf[TWO] = Cali_Exit_Mode;
			        ret = ME_OK;
				    break;
				 default:
				    cmdbuf[ONE] = cmdbuf[ZERO];
				    (void)US_SnrCfg_CaliCmd_Response((uint8_t*)&cmdbuf[header_len],len+header_len,0xffu);
					 break;
				 }

			 }
			 else
			 {
				    cmdbuf[ONE] = cmdbuf[ZERO];
				    (void)US_SnrCfg_CaliCmd_Response((uint8_t*)&cmdbuf[header_len],len+header_len,0xffu);
			 }
			 if( ret == ME_OK)
			 {
				(void)US_SnrCfg_CaliCmd_Response((uint8_t*)&cmdbuf[header_len],len+header_len,US_SNR_TUNE_EXIT_OUT_ID);
			 }
			break;

		case US_SNR_TUNE_ENTER_IN_ID:
			uss_cur_state = UssMgr_eGetSysState();
			UssMgr_SetSysState(SYSMGR_SYS_CALIBRATION);
			(void)US_SnrCfg_CaliCmd_Response((uint8_t*)&cmdbuf[header_len],len+header_len,US_SNR_TUNE_ENTER_OUT_ID);
			 ret = ME_OK;
			break;
		default:
			cmdbuf[ONE] = cmdbuf[ZERO];
			(void)US_SnrCfg_CaliCmd_Response((uint8_t*)&cmdbuf[header_len],len+header_len,0xffu);
			break;
	}
    return ret;
}

/* ===========================================================================*/
/**US_SnrCfg_F_Cali_RcvCmd.
* interface function: Receive calibration cmd from CAN bus and copy to internal buffer
* \param: Cmdbuf: cmd data buffer, len: cmd data size
* \return: none
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_F_Cali_RcvCmd
 * Remarks: DD-ID: {7E58F08B-2F19-440c-B1DF-8468FE40D774}
 * ===========================================================================*/
uint16_t US_SnrCfg_F_Cali_RcvCmd(uint8_t *cmdbuf,uint16_t len,uint8_t from)
{
  uint16_t ret = ME_NOT_OK;
  uint16_t cmdPackLen=0;
  Tuning_Intf = from;
 
   if(cmdbuf[ZERO]!= (uint8_t)US_SNR_TUNE_IN_ID)
   {
     ret = US_SnrCfg_RcvCmd(cmdbuf,len-ONE,ONE);
   }
   else
   {
		cmdPackLen = ((uint16_t)cmdbuf[ONE+1u]);
		cmdPackLen = cmdPackLen << 8u;
		cmdPackLen =(uint16_t) (cmdPackLen + cmdbuf[ONE+0u]);
 
  		/*\cmdPackLen  = (uint16_t)((cmdbuf[ONE+1u]<<8u) + cmdbuf[ONE+0u]);	 */		
  		/*cmdPackLen += (cmdbuf[ONE+0]%2); append to 2 bytes for check sum */
  		if((cmdPackLen>=8u )&& (cmdPackLen<=(len - ONE)))
  		{
  			  ret =US_SnrCfg_RcvCmd(cmdbuf,cmdPackLen + TWO, ONE);
  		}
   }
 return ret;
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_SnrCfg_Get_CaliExitMode.
*
* \param:
* \return: none
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_Get_CaliExitMode
 * Remarks: DD-ID:
 * ===========================================================================*/

bool_t US_SnrCfg_Get_CaliExitMode(void)   
{
   bool_t ret = ME_FALSE;
   if((Cali_Exit_Mode & (uint8_t)0xc0u) == 0x80u)
   {
	   ret = ME_TRUE;
   }
   return ret;
}
/* ===========================================================================*/
/**US_SnrCfg_F_EMC_RcvCmd.
* interface function: for EMC only for clear DTC flags and re-configure sensors
* \param:
* \return: none
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_F_EMC_RcvCmd
 * Remarks: DD-ID: {9774DE44-639D-47bd-A382-A3F8C9E50D4E}
 * ===========================================================================*/
void US_SnrCfg_F_EMC_RcvCmd(void)
{
	US_SnrCfg_EMC_Cmd_Ready = ME_TRUE;
}
#endif
/* ========================================================================= */
/* ===========================================================================
 * Name:    US_SnrCfg_CaliCmd_Response
 * Remarks: DD-ID:{E64D04B7-2F3C-4ed1-9943-471133E2801A} 
 * ===========================================================================*/

static uint16_t US_SnrCfg_CaliCmd_Response(uint8_t *SndData,uint16_t len,uint8_t ID)
{
	uint16_t ret  = ZERO;
	if(Tuning_Intf == ZERO)
	{
	/*\ret = UssStubOutput_SnrCfg_CmdReq(SndData,len,ID); */
	}
	else
	{
		ret = USS_Send_UssTunningDataByIPC(SndData,len,ID);
    }
	return ret;
}

#if(US_CSM_ENABLE == ME_TRUE)
/* ===========================================================================
 * Name:    Us_Calib_ReqState_Csm
 * Remarks: DD-ID:{C742B076-3075-49fc-BFE4-670EBA1A2D19} 
 * ===========================================================================*/
 UsCsm_StdReturn_Type Us_Calib_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState)
 {
	(void)instanceId;  
	LocalStateId_Calib = reqState;
	return US_CSM_STD_RET_OK;
 }
/* ===========================================================================
 * Name:    Us_Calib_GetState_Csm

 * Remarks: DD-ID:{D3488777-4F76-4c2a-8308-EFD001C21BC1} 
 * ===========================================================================*/
 UsCsm_LocalStateId_Type Us_Calib_GetState_Csm(UsCsm_InstanceId_Type instanceId)
 {
	(void)instanceId;
	return (LocalStateId_Calib);
 }
#endif
