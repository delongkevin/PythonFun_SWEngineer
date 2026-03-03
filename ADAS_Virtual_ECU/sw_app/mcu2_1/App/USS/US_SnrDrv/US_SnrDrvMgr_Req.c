/*
 * USSDrvMgr.c
 *
 *  Created on: Feb 18, 2021
 *      Author: e39960
 */

#include "US_ME_Typedefs_Global.h"
#include "US_SnrDrv.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_Platform_Global.h"

static uint8_t US_SnrDrvMgr_F_Req_CmdCnt = ZERO;
static uint8_t US_SnrDrvMgr_F_DSI_Req_SndBuf[MAX_USS_DRV_CMD][MAX_SEND_SIZE];

/* ===========================================================================*/
/**US_SnrDrvMgr_F_AutoAddressingCmd - Asynchronous command  .
* used to Send Auto addressing cmd to Sensors to get Number of Sensors on each bus.
* \param: Call back function, it is called with error code when cmd is completed or abort
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_AutoAddressingCmd
 * Remarks:  DD-ID: {9D2F86A3-8601-4ce8-8D47-30DF7BB91116}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_AutoAddressingCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret;
   (void)sndData; (void)sndlen; (void)SnrMap;
    ret = US_SnrDrvCom_F_CmdSnd(ZERO,UserData,REQ_SENSOR_AUTO_ADDRESSING,0,NULL,rcvlen,rcvData,CallBack);

    return ret;

}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqDSIMasterRegCmd - Synchronous command  .
* used to Read DSI3 Master IC register.
* \param: BUSMAP: Specify the BUS will be applied this cmd,  RegAddr: register address, 
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is executed successful, fail: cmd is executed fail
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqDSIMasterRegCmd
 * Remarks:  DD-ID: {5D620128-8C9F-44e6-8866-A8164623D57B}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqDSIMasterRegCmd(uint32_t SnrMap,uint32_t UserData,uint16_t RegAddr,uint16_t len,uint8_t *data,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret;
    uint32_t CmdId;
    CmdId  = (uint32_t)DSI_CMD_READ_MASTER_REG;
    CmdId    |=  RegAddr;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,CmdId,0,NULL,len,data,CallBack);

    return ret;

}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqDSIMasterRegByTableCmd - ASynchronous command  .
* used to Read DSI3 Master IC register.
* \param: BUSMAP: Specify the BUS will be applied this cmd,  RegAddr: register address, 
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is executed successful, fail: cmd is executed fail
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqDSIMasterRegByTableCmd
 * Remarks:  DD-ID: {BF5B9E55-E798-45f5-A0B7-66CDDBF697C8} 
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqDSIMasterRegByTableCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    uint32_t CmdId;
    uint16_t RegAddr;
    if((sndlen >= TWO)&&(sndData != NULL)&&(rcvlen >= FOUR)&&(rcvData!= NULL))
    {
    	RegAddr = (uint16_t)sndData[1];
        RegAddr <<=   EIGHT;
    	RegAddr |= (uint16_t)sndData[0];
         CmdId  = (uint32_t)DSI_CMD_READ_MASTER_REG|RegAddr;
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,CmdId,0,NULL,rcvlen,rcvData,CallBack);
    }
    return ret;

}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqADVoltager - Asynchronous command  .
* used to Read Sensors FW version.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqADVoltager
 * Remarks:  DD-ID: {26162AD0-D2AC-480c-AC7F-FBCBBEEF7BEE}
 * Traceability to source Code: Req.-ID: 13389441
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqADVoltager(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
	uint32_t ret = ME_OK;
    uint8_t  nbuf;
    uint8_t choice= *(uint8_t const*)sndData;

     if(sndlen >= sizeof(uint8_t))
     {

         nbuf = US_SnrDrvMgr_F_Req_CmdCnt;
         US_SnrDrvMgr_F_Req_CmdCnt = (nbuf+ONE) & USSQUEUEMASK;

         US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][ZERO] = choice;

         ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_AD_VOLTAGE,ONE,US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf],rcvlen,rcvData,CallBack);
     }
     else
     {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
     }
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSnrFWVer - Asynchronous command  .
* used to Read Sensors FW version.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSnrFWVer
 * Remarks:  DD-ID: {4BDA6AB9-45E1-4fdf-A8B1-D5E2D571A7F6}
 * Traceability to source Code: Req.-ID: 13389441
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSnrFWVer(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_FW_VER,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorIDCmd - Asynchronous command  .
* used to Read Sensors ID.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorIDCmd
 * Remarks:  DD-ID: {4E602591-FF93-4ef1-AA18-87254A952F3D}
 * Traceability to source Code: Req.-ID: 13410142
 * Req.-ID: 13473310
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorIDCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
	(void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_ID,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorAmbiTempCmd - Asynchronous command  .
* used to Read Sensors Ambient temperature.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  This function may not be supported.  Seems to always return zero for all sensors.
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorAmbiTempCmd
 * Remarks:  DD-ID: {A3CF6303-568C-4dfe-B433-C0A192640DA5}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorAmbiTempCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
	uint32_t ret = ME_OK;
	(void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_AMBIENT_TEMPATURE,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd - Asynchronous command  .
* used to Read Sensors Diagnostic result.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd
 * Remarks:  DD-ID: {5F44E98B-5F11-4283-B61F-58E65183BB0C}
 * Traceability to source Code: Req.-ID: 13410409
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
	uint16_t  FWVer   =US_SnrCfg_Get_SnrFWVer();
	uint8_t Mode = US_SnrCfg_Get_Sensor_opmode();
	(void) sndData;(void)sndlen;
    if((FWVer == QM_SNR_FW_VER)||(Mode != SENSOR_OP_NORMAL))
    {
    	   ret = US_SnrDrvCom_F_CmdSnd(SnrMap, UserData, REQ_SENSOR_SNR_DIAGNOSTIC_RESULT_F11A, 0u, NULL, rcvlen, rcvData, CallBack);
     }
    else
    {
    	   ret = US_SnrDrvCom_F_CmdSnd(SnrMap, UserData, REQ_SENSOR_SNR_DIAGNOSTIC_RESULT, 0u, NULL, rcvlen, rcvData, CallBack);
    }
    return ret;
}
/* ===========================================================================*/
/**ReqSensorOPModeCmd - Asynchronous command  .
* used to Read Sensors operation mode.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorOPModeCmd
 * Remarks:  DD-ID: {835E6D83-3F0C-4c80-AC32-91BB97E69E5C}
 * Traceability to source Code: Req.-ID: 13411566
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorOPModeCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_OPERATION_MODE,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorTempCmd - Asynchronous command  .
* used to Read Sensors temperature
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorTempCmd
 * Remarks:  DD-ID: {214B68ED-59F2-4ce9-B892-86DE1722E3D0}
 * Traceability to source Code: Req.-ID: 13411731
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorTempCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_TEMPATURE,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorFreqCmd - Asynchronous command  .
* used to Read Sensors Frequency
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorFreqCmd
 * Remarks:  DD-ID: {0473F2CF-3774-43a6-A159-00FA290E4E58}
 * Traceability to source Code: Req.-ID: 13411776
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorFreqCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_FREQUENCY,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqGanaMeasBeginCmd - Asynchronous command  .
* used to Read Sensors Gana Measurement begin parameter
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqGanaMeasBeginCmd
 * Remarks:  DD-ID: {14267E26-2E20-4f97-84B5-314C707814ED}
 * Traceability to source Code: Req.-ID: 13427026
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqGanaMeasBeginCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_GANA_MEAS_BEGIN,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorEEFlagCTRL - Asynchronous command  .
* used to Read Sensors EEFlagCTRL parameter
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorEEFlagCTRL
 * Remarks:  DD-ID: {02A20514-B012-438a-BB27-187E5629A6B6}
 * Traceability to source Code: Req.-ID: 13427254
 * Req.-ID: 13420547
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorEEFlagCTRL(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_EEFLAG_VARCTRL,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqEEVALSensMeasCmd - Asynchronous command  .
* used to Read Sensors EEVAL Sens Meas
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqEEVALSensMeasCmd
 * Remarks:  DD-ID: {E5605365-8464-4524-ABE4-F142472FFD26}
 * Traceability to source Code: Req.-ID: 13427250
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqEEVALSensMeasCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_EEVAL_SENS_MEAS,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqRFMCtrlCmd - Asynchronous command  .
* used to Read Sensors Rfm Ctrl
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqRFMCtrlCmd
 * Remarks:  DD-ID: {69746D8B-9A26-4f7e-89B6-04E50B5122F5}
 * Traceability to source Code: Req.-ID: 13522716
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqRFMCtrlCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_RFM_CTRL,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqCPSMeasGainCmd - Asynchronous command  .
* used to Read Sensors CPS Measurement Gain
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqCPSMeasGainCmd
 * Remarks:  DD-ID: {D5C72D55-4690-43d0-ABF5-041FC3938A01}
 * Traceability to source Code: Req.-ID: 13427250
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqCPSMeasGainCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_CPS_MEAS_GAIN,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqEnvDataCmd - Asynchronous command  .
* used to Read Sensors output signal data
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqEnvDataCmd
 * Remarks:  DD-ID: {6A0F5FF7-D2F9-4a61-91BC-DBEA83E0761F}
 * Traceability to source Code: Req.-ID: 13410083
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqEnvDataCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_OUTPUT_SIGNAL_DATA,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqEDIChannelCmd - Asynchronous command  .
* used to Read Sensors EDI channel
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqEDIChannelCmd
 * Remarks:  DD-ID: {D2047492-54D7-4105-B622-9764FFFF69AB}
 * Traceability to source Code: Req.-ID: 13409997
 * Req.-ID: 13420545
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqEDIChannelCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_EDI_CHANNEL,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqNFDCmd - Asynchronous command  .
* used to Read Sensors EDI channel
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqNFDCmd
 * Remarks:  DD-ID: {FD4760C1-827A-48ec-83FB-B2EFC5D19319}
 * Traceability to source Code: Req.-ID: 13409860
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqNFDCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_NFD,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqFixPathCfgCmd - Asynchronous command  .
* used to Read Sensors fix path cfg
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqFixPathCfgCmd
 * Remarks:  DD-ID: {E2F577F5-51AF-4f9f-955E-77DEDE5C9EB2}
 * Traceability to source Code: Req.-ID: 13409758
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqFixPathCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_FIX_PATH_CFG,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqMaxEchoNumCmd - Asynchronous command  .
* used to Read Sensors max echo number
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqMaxEchoNumCmd
 * Remarks:  DD-ID: {F446CF9E-81A6-47ab-999D-0BE23ACC960D}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqMaxEchoNumCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_MAX_ECHO_NUMBER,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqEnvFiltCfgCmd - Asynchronous command  .
* used to Read Sensors envelope filter cfg
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqEnvFiltCfgCmd
 * Remarks:  DD-ID: {A687BC17-9B5F-4948-9257-BBB90F9C1046}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqEnvFiltCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_ENVELOPE_FILTER_CONFIG,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqEnvCfgCmd - Asynchronous command  .
* used to Read Sensors envelope cfg
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqEnvCfgCmd
 * Remarks:  DD-ID: {DB827927-ADA9-486f-892D-BEECD799E7DE}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqEnvCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_ENVELOPE_CONFIG,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqCalGainCmd - Asynchronous command  .
* used to Read Sensors cal gain
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqCalGainCmd
 * Remarks:  DD-ID: {0C57C175-7262-4de8-9A70-1EE7C1F72299}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqCalGainCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_G_CAL,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqGainCmd - Asynchronous command  .
* used to Read Sensors Gain
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqGainCmd
 * Remarks:  DD-ID: {7C6FCE01-A692-40f3-8124-EE07BB27A287}
 * Traceability to source Code: Req.-ID: 13420543
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqGainCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_GAIN,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqGainCmd - Asynchronous command  .
* used to Read Sensors current cfg
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqCurrentCmd
 * Remarks:  DD-ID: {69EAE1CA-E35F-457f-B124-47D7FBA45E6A}
 * Req.-ID: 13411731
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqCurrentCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_CURRENT_CFG,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqBurstTypeCfgCmd - Asynchronous command  .
* used to Read Sensors burst type config
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqBurstTypeCfgCmd
 * Remarks:  DD-ID: {0F04573C-AC41-4128-A232-1DCC23795C61}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqBurstTypeCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_BURST_TYPE_CONFIG,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqRingingCompCmd - Asynchronous command  .
* used to Read Sensors ringing comparator type config
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqRingingCompCmd
 * Remarks:  DD-ID: {8D0B238F-F63E-4335-863F-5684AD082DD4}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqRingingCompCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_RINGINGCOMPARATOR,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqChirpBWCmd - Asynchronous command  .
* used to Read Sensors chirp BW
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqChirpBWCmd
 * Remarks:  DD-ID: {BA68924F-E8C6-4f40-B542-A437840B3FDE}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqChirpBWCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_CHIRP_BW,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqNormalBurstNumCmd - Asynchronous command  .
* used to Read Sensors Normal Burst number
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqNormalBurstNumCmd
 * Remarks:  DD-ID: {06AD1E27-B739-41a1-B1D9-C4EE0D10C4C7}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqNormalBurstNumCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_NORMAL_BURST_NUMBER,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqNormalBurstNumCmd - Asynchronous command  .
* used to Read Sensors FC
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqFCCmd
 * Remarks:  DD-ID: {9AFD704C-2BE6-44e2-8010-D8F99459A0F6}
 * Traceability to source Code: Req.-ID: 13408308
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqFCCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_FC,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqAATG2Cmd - Asynchronous command  .
* used to Read Sensors AATG2
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqAATG2Cmd
 * Remarks:  DD-ID: {B25EE116-0E7B-48a7-9A09-3795BB0B3094}
 * Traceability to source Code: Req.-ID: 13409002
 * Req.-ID: 13420537
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqAATG2Cmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_AATG2,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqAATG1Cmd - Asynchronous command  .
* used to Read Sensors AATG1
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqAATG1Cmd
 * Remarks:  DD-ID: {16A16538-576F-4ed5-96B6-EFAA4ECF4DAF}
 * Traceability to source Code: Req.-ID: 13408937
 * Req.-ID: 13420535
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqAATG1Cmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_AATG1,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqATGCmd - Asynchronous command  .
* used to Read Sensors ATG
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqATGCmd
 * Remarks:  DD-ID: {7B826238-1C9E-4722-A28E-66A2CD6627AB}
 * Traceability to source Code: Req.-ID: 13408639
 * Req.-ID: 13420539
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqATGCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_ATG,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqFTCCmd - Asynchronous command  .
* used to Read Sensors FTC
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqFTCCmd
 * Remarks:  DD-ID: {F1E4CDA8-9A99-4852-AD4D-93AB925AB3F1}
 * Traceability to source Code: Req.-ID: 13409314
 * Req.-ID: 13420533
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqFTCCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
  (void) sndData;(void)sndlen;
    ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_FTC,0,NULL,rcvlen,rcvData,CallBack);
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSTCCmd - Asynchronous command  .
* used to Read Sensors STC
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: sndlen: size of US_S_reqStcStgCfg_t
* \param: sndData: request Stc Stg cfg data structure
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSTCCmd
 * Remarks:  DD-ID: {B6B47CC2-BD2E-4f45-859A-F90352196752}
 * Traceability to source Code: Req.-ID: 13409451
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSTCCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt,ProfileType;
    US_S_reqStcStgCfg_t const *reqCfg= (US_S_reqStcStgCfg_t const*)((uint8_t*)sndData+sizeof(uint32_t)); 
    ProfileType = *(uint8_t*)sndData;
      if(sndlen >= sizeof(US_S_reqStcStgCfg_t))
      {
        cnt = US_SnrDrvMgr_F_Req_CmdCnt;
        US_SnrDrvMgr_F_Req_CmdCnt = (cnt+ONE) & USSQUEUEMASK;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ZERO]   =  reqCfg->StartSeg;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ONE]    =  reqCfg->SegLen;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][TWO]    =  ProfileType<<FOUR;
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_STC,THREE,US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt],rcvlen,rcvData,CallBack);
      }
      else
      {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
      }
      return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSTGCmd - Asynchronous command  .
* used to Read Sensors STG
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: sndlen: size of US_S_reqStcStgCfg_t
* \param: sndData: request Stc Stg cfg data structure
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSTGCmd
 * Remarks:  DD-ID: {875EBF8C-70BB-4a15-8D80-AB8A31103298}
 * Traceability to source Code: Req.-ID: 13409667
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSTGCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
   uint32_t ret = ME_OK;
   uint8_t cnt,ProfileType;
   US_S_reqStcStgCfg_t const *reqCfg= (US_S_reqStcStgCfg_t const*)((uint8_t const*)sndData+sizeof(uint32_t));
   ProfileType = *(uint8_t const*)sndData;
     if(sndlen >= sizeof(US_S_reqStcStgCfg_t))
     {
        cnt = US_SnrDrvMgr_F_Req_CmdCnt;
        US_SnrDrvMgr_F_Req_CmdCnt = (cnt+ONE) & USSQUEUEMASK;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ZERO]   =  reqCfg->StartSeg;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ONE]    =  reqCfg->SegLen;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][TWO]    =  ProfileType<<FOUR;
    
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_STG,THREE,US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt],rcvlen,rcvData,CallBack);
     }
     else
     {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
     }
     return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorEEPROMCmd - Asynchronous command  .
* used to Read Sensors EEPROM content.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: sndlen: size of EEPROMCfg
* \param: sndData: EEPROM address and data length
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* * \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorEEPROMCmd
 * Remarks:  DD-ID: {E6D987E1-3D68-4139-96DC-7ADFD5056EC2}
 * Traceability to source Code: Req.-ID: 13411429
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorEEPROMCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EEPROMCfg_t const *RegEEPROMCfg= (US_S_EEPROMCfg_t const*)sndData;      

    if(sndlen >= sizeof(US_S_EEPROMCfg_t))
    {
        cnt = US_SnrDrvMgr_F_Req_CmdCnt;
        US_SnrDrvMgr_F_Req_CmdCnt = (cnt+ONE) & USSQUEUEMASK;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ZERO]   =  RegEEPROMCfg->Addr;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ONE]    =  RegEEPROMCfg->length;
        US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][TWO]    =  ZERO;
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_EEPROM,THREE,US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt],rcvlen,rcvData,CallBack);
     }
    else
    {
        ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    }
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSendBurstWDelayCmd - Asynchronous command  .
* used to Request Sensors Send Burst with delay.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: delay: Delay time of 2ms cycles for Dequeue cmd 
* \param: UserData: User data for passing through Call back function
* \param: sndlen: length of Burst configure data structure
* \param: sndData: Burst configure data structure
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
*  \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSendBurstWDelayCmd
 * Remarks:  DD-ID: {C69F747E-5A8F-4582-8C90-1FE23750D87F}
  
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSendBurstWDelayCmd(uint32_t SnrMap,uint8_t delay,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t CmdId,ret = ME_OK;
    uint16_t spilen,FWVer;
    uint8_t  Mode,offset,cnt,nbuf,nbus,nBRC = 0u;
    US_S_SensorsCfg_t const *pSnrCfg;
    US_S_ClusterBurstCmd_t const *SendBurstCfg_dpt= (US_S_ClusterBurstCmd_t const*)sndData; 
    FWVer   =  US_SnrCfg_Get_SnrFWVer();
    Mode      =  US_SnrCfg_Get_Sensor_opmode();
    if(sndlen >= sizeof(US_S_ClusterBurstCmd_t))
    {
        pSnrCfg =  US_SnrCfg_F_Get_SnrCfg();
        if((pSnrCfg == NULL)||(pSnrCfg->SnrMap == ZERO)||(pSnrCfg->nBusCfg == ZERO))
        {
            ret = ERROR_US_SNRDRVCOM_SYSTEM_NOT_INIT;
        }
        else if (pSnrCfg->nBusCfg > US_D_MAX_NUM_BUS)
        {
            ret = ERROR_US_SNRDRVCOM_PARAMETER;
        }
        else
        {
            nbuf = US_SnrDrvMgr_F_Req_CmdCnt;
            US_SnrDrvMgr_F_Req_CmdCnt = (nbuf+ONE) & USSQUEUEMASK;

            CmdId = REQ_SENSOR_DETECTIPON_QUICK; /*default to no update */
            for(nbus = ZERO; nbus < pSnrCfg->nBusCfg; nbus++)
            {
                if(((SendBurstCfg_dpt)->Cfg[nbus].Update) == (uint8_t)US_E_UPDATE)
                {
                    /*if any bus wants to update, send cmd as update */
                    CmdId = REQ_SENSOR_DETECTION_SAME_MEASUREMENT;  /*this name is a misnomer... */
                    break;
                }
             }

            nbus = ZERO;  /*VERY IMPORTANT TO RESET HERE */
            for(cnt = ZERO; cnt < pSnrCfg->nBusCfg; cnt++)     /*check bus configure */
            {
                nBRC = SendBurstCfg_dpt->uNumPDCM[cnt]; /*nBRC changes per bus */
                offset = (pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * cnt;
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) ] = (((SendBurstCfg_dpt)->TypeAry[offset+ZERO])<<FIVE)|(((SendBurstCfg_dpt)->TypeAry[offset+ONE])<<TWO)|(((SendBurstCfg_dpt)->TypeAry[offset+TWO])>>ONE);  
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) + ONE] = (((SendBurstCfg_dpt)->TypeAry[offset+TWO])<<SEVEN)|(((SendBurstCfg_dpt)->TypeAry[offset+THREE])<<FOUR)|(((SendBurstCfg_dpt)->TypeAry[offset+FOUR])<<ONE);
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX )+TWO] = (((SendBurstCfg_dpt)->TypeAry[offset+FIVE])<<FIVE)|(((SendBurstCfg_dpt)->Cfg[cnt].EnvOutput)<<TWO);
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) +THREE] = (((SendBurstCfg_dpt)->Cfg[cnt].EchoInfo)<<FOUR)|(((SendBurstCfg_dpt)->ProfileType[cnt]));
                if((FWVer == (uint16_t)QM_SNR_FW_VER)||(Mode != (uint8_t)SENSOR_OP_NORMAL))
 				{
                 	US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) + FOUR] = (uint8_t)((SendBurstCfg_dpt)->Cfg[cnt].CompGain);
                 	US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX)  +FIVE] = nBRC<<TWO;
                 }
 				else
 				{
 				    US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX )+ FOUR] = ((((SendBurstCfg_dpt)->Cfg[cnt].PreburstNoiseChkTime >> 3u)  & 0x01u) | (((SendBurstCfg_dpt)->Cfg[cnt].MeasurementTime << 0x01u) & 0xFEu));
                     US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX )+ FIVE] = ((((SendBurstCfg_dpt)->Cfg[cnt].G_digBoost << 2u) & 0x1Cu) | (((SendBurstCfg_dpt)->Cfg[cnt].PreburstNoiseChkTime << 5u) & 0xE0u));
 				}

                nbus++;
            }
            spilen =  SIX|BIT15;
            US_SnrDrvCom_F_Set_BurstnPDCM(nBRC,SendBurstCfg_dpt->pdcm_period);
            US_SnrDrvCom_F_AddAdditionalDequeueDelay(delay);
            ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,CmdId,spilen,US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf],rcvlen,rcvData,CallBack);
            ME_LED_Lighting();
        }
    }
    else
    {
        ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    }
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSendBurstCmd - Asynchronous command  .
* used to Request Sensors Send Burst.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: UserData: User data for passing through Call back function
* \param: sndlen: length of Burst configure data structure
* \param: sndData: Burst configure data structure
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* * \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSendBurstCmd
 * Remarks:  {100C353C-B183-4a7d-A2C3-DA5EBE83FD79}
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
uint32_t US_SnrDrvMgr_F_ReqSendBurstCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t CmdId,ret = ME_OK;
    uint16_t spilen,FWVer;
    uint8_t  Mode,offset,cnt,nbuf,nbus,nBRC = 0u;
    US_S_SensorsCfg_t const *pSnrCfg;
    US_S_ClusterBurstCmd_t const *SendBurstCfg_dpt= (US_S_ClusterBurstCmd_t const*)sndData;  
    FWVer   =  US_SnrCfg_Get_SnrFWVer();
    Mode      =  US_SnrCfg_Get_Sensor_opmode();

    if(sndlen >= sizeof(US_S_ClusterBurstCmd_t))
    {
        pSnrCfg =  US_SnrCfg_F_Get_SnrCfg();
        if((pSnrCfg == NULL)||(pSnrCfg->SnrMap == ZERO)||(pSnrCfg->nBusCfg == ZERO))
        {
            ret = ERROR_US_SNRDRVCOM_SYSTEM_NOT_INIT;
        }
        else if (pSnrCfg->nBusCfg > US_D_MAX_NUM_BUS)
        {
            ret = ERROR_US_SNRDRVCOM_PARAMETER;
        }
        else
        {
            nbuf = US_SnrDrvMgr_F_Req_CmdCnt;
            US_SnrDrvMgr_F_Req_CmdCnt = (nbuf+ONE) & USSQUEUEMASK;

            CmdId = REQ_SENSOR_DETECTIPON_QUICK; /*default to no update */
            for(nbus = ZERO; nbus < pSnrCfg->nBusCfg; nbus++)
            {
                if(((SendBurstCfg_dpt)->Cfg[nbus].Update) == (uint8_t)US_E_UPDATE)
                {
                    /*if any bus wants to update, send cmd as update */
                    CmdId = REQ_SENSOR_DETECTION_SAME_MEASUREMENT;  /*this name is a misnomer... */
                    break;
                }
            }
            nbus = ZERO;  /*VERY IMPORTANT TO RESET HERE */
            for(cnt = ZERO; cnt < pSnrCfg->nBusCfg; cnt++)     /*check bus configure */
            {
                  
                nBRC = SendBurstCfg_dpt->uNumPDCM[cnt]; /*nBRC changes per bus */

                offset = (pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * cnt;
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX )] = (((SendBurstCfg_dpt)->TypeAry[offset+ZERO])<<FIVE)|(((SendBurstCfg_dpt)->TypeAry[offset+ONE])<<TWO)|(((SendBurstCfg_dpt)->TypeAry[offset+TWO])>>ONE); 
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) + ONE] = (((SendBurstCfg_dpt)->TypeAry[offset+TWO])<<SEVEN)|(((SendBurstCfg_dpt)->TypeAry[offset+THREE])<<FOUR)|(((SendBurstCfg_dpt)->TypeAry[offset+FOUR])<<ONE);
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX )+TWO] = (((SendBurstCfg_dpt)->TypeAry[offset+FIVE])<<FIVE)|(((SendBurstCfg_dpt)->Cfg[cnt].EnvOutput)<<TWO);
                US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) +THREE] = (((SendBurstCfg_dpt)->Cfg[cnt].EchoInfo)<<FOUR)|(((SendBurstCfg_dpt)->ProfileType[cnt]));
                if((FWVer == (uint16_t)QM_SNR_FW_VER)||(Mode != (uint8_t)SENSOR_OP_NORMAL))
				{
                	US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) + FOUR] = (uint8_t)((SendBurstCfg_dpt)->Cfg[cnt].CompGain);
                	US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX ) +FIVE] = nBRC<<TWO;
                }
				else
				{
				    US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX )+ FOUR] = ((((SendBurstCfg_dpt)->Cfg[cnt].PreburstNoiseChkTime >> 3u)  & 0x01u) | (((SendBurstCfg_dpt)->Cfg[cnt].MeasurementTime << 0x01u) & 0xFEu));
                    US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][(nbus * SIX) +FIVE] = ((((SendBurstCfg_dpt)->Cfg[cnt].G_digBoost << 2u) & 0x1Cu) | (((SendBurstCfg_dpt)->Cfg[cnt].PreburstNoiseChkTime << 5u) & 0xE0u));
				}
                nbus++;
            }
            US_SnrDrvCom_F_Set_BurstnPDCM(nBRC,SendBurstCfg_dpt->pdcm_period);
            spilen =  SIX|BIT15;
            ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,CmdId,spilen,US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf],rcvlen,rcvData,CallBack);
            ME_LED_Lighting();
        }
    }
    else
    {
        ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    }
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqSensorRegisterCmd - Asynchronous command  .
* used to Read Sensors Register.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: sndlen: length of RegCfg structure
* \param: sndData: RegCfg--Register address
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* * \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqSensorRegisterCmd
 * Remarks:  DD-ID: {2B900A0A-CB2F-46cf-93C3-F9C09737CD41}
 * Traceability to source Code: Req.-ID: 13411313
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqSensorRegisterCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_RegCfg_t const *RegCfg= (US_S_RegCfg_t const*)sndData;            
    cnt = US_SnrDrvMgr_F_Req_CmdCnt;
    US_SnrDrvMgr_F_Req_CmdCnt = (cnt + ONE) & USSQUEUEMASK;
    if(sndlen >= sizeof(US_S_RegCfg_t))
    {
         US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ZERO]   =  RegCfg->ModAddr;
         US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt][ONE]    =  RegCfg->Addr;
         ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_REGISTER,TWO,US_SnrDrvMgr_F_DSI_Req_SndBuf[cnt],rcvlen,rcvData,CallBack);
    }
    else
    {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    }
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqProfileCmd - Asynchronous command  .
* used to read sensors profile cfg.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: ProfileType: profile type
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* * \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqProfileCmd
 * Remarks:  DD-ID: {82694CFF-5027-4f1e-A815-0A701363282B}
 * Traceability to source Code: Req.-ID: 13411875
 * Req.-ID: 13396025
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqProfileCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t  nbuf;
    uint8_t ProfileType= *(uint8_t*)sndData;

     if(sndlen >= sizeof(uint8_t))
     {

         nbuf = US_SnrDrvMgr_F_Req_CmdCnt;
         US_SnrDrvMgr_F_Req_CmdCnt = (nbuf+ONE) & USSQUEUEMASK;

         US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][ZERO] = ProfileType;

         ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_PROFILE,ONE,US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf],rcvlen,rcvData,CallBack);
     }
     else
     {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
     }
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_ReqProfilePlusCmd - Asynchronous command  .
* used to read sensors profile plus cfg.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: ProfileType: profile type
* \param: len: Receive buffer size = requester data size + 2, First two bytes is actual return data length, data:receive data buffer
* * \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_ReqProfilePlusCmd
 * Remarks:  DD-ID: {D84635C4-2D4F-4a8e-A0E9-6E45456D9A61}
 * Traceability to source Code: Req.-ID: 13412761
 * Req.-ID: 13420529
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_ReqProfilePlusCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t  nbuf;
    uint8_t ProfileType= *(uint8_t*)sndData;

    if(sndlen >= sizeof(uint8_t))
   {

        nbuf = US_SnrDrvMgr_F_Req_CmdCnt;
        US_SnrDrvMgr_F_Req_CmdCnt = (nbuf+ONE) & USSQUEUEMASK;

        US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf][ZERO] = ProfileType;

        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,REQ_SENSOR_PROFILE_PLUS,ONE,US_SnrDrvMgr_F_DSI_Req_SndBuf[nbuf],rcvlen,rcvData,CallBack);
    }
    else
    {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    }
    return ret;
}

