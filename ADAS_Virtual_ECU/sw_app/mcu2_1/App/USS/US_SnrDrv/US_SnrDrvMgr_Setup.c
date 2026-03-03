/*
 * US_SnrDrvMgr_F_Setup.c
 *
 *  Created on: Feb 18, 2021
 *      Author: e39960
 */
#include "US_ME_Typedefs_Global.h"
#include "US_SnrDrv.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
uint32_t US_Read_MarriageSensorID(void);
void UssCtrl_PerformSnrMarIdxMapping(void);

static uint8_t US_SnrDrvMgr_F_CmdCnt = ZERO;
static uint8_t US_SnrDrvMgr_F_DSI_SndBuf[MAX_USS_DRV_CMD][MAX_SEND_SIZE];
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetProfilePlusCmd - Asynchronous command  .
* used to setup ProfilePlus to Sensors.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: ProfileType: Profile Type, STGFixValue: STG Fix Value, STCShift: STC Shift
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetProfilePlusCmd
 * Remarks:  DD-ID: {2C79FAAC-8081-4e0d-A1D2-F9DC019EAD5C}
 * Traceability to source Code: Req.-ID: 13427670
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetProfilePlusCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
	US_S_ProfilePlus_IndexCfg_t const *ProfilePlusCfg =(US_S_ProfilePlus_IndexCfg_t const *)(sndData);     
	(void)rcvlen;
	(void)sndData;
	cnt = US_SnrDrvMgr_F_CmdCnt & USSQUEUEMASK;
	if(sndlen >= sizeof(US_S_ProfilePlusCfg_t))
	{
		US_SnrDrvMgr_F_CmdCnt = (US_SnrDrvMgr_F_CmdCnt + ONE) & USSQUEUEMASK;
		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = ProfilePlusCfg->STGFixValue;
		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ProfilePlusCfg->STCShift;
		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = (uint8_t)(((ProfilePlusCfg->Profile) << FOUR) & 0xffu);
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_PROFILE_PLUS,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}
	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetProfileCmd - Asynchronous command  .
* used to setup Profile to Sensors.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: ProfileType: Profile Type, Number: Number of Parameters to setup, Cfg: profile configure
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetProfileCmd
 * Remarks:  DD-ID: {218BA213-0A1F-4ae1-BEF4-5D635FAE2A94}
 * Traceability to source Code: Req.-ID: 13427661
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetProfileCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint16_t len;
	uint32_t ret = ME_OK;
    uint8_t cnt;
	(void)rcvlen;
 	if(sndlen >= sizeof(US_S_ProfileCfg_Index_t))
 	{
 		US_S_ProfileCfg_Index_t const *cfg_index = (US_S_ProfileCfg_Index_t const *)(sndData);    
 		US_S_ProfileCfg_t const *Cfg = &(cfg_index->ProfileCfg);
     	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (US_SnrDrvMgr_F_CmdCnt + ONE) & USSQUEUEMASK;
    	len = THREE;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = ((cfg_index->Index)<<FOUR)|((cfg_index->ProfileType)<<TWO);
    	switch(cfg_index->Index)
    	{
			case ONE:
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = Cfg->nPulses_N;
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = Cfg->nPulses_C;

				break;
			case TWO:
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = Cfg->Current;
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = Cfg->BW;
				break;
			case THREE:
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = Cfg->G_dig;
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = Cfg->G_ana;
				break;
			case FOUR:
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = ((Cfg->CN1)<<FOUR)|(Cfg->CW1);
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ((Cfg->CN2)<<FOUR)|(Cfg->CW2);
				break;
			case FIVE:
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = ((Cfg->ATG_on)<<SEVEN)|((Cfg->STC_on)<<SIX)|((Cfg->FTC_on)<<FIVE)|((Cfg->NFD_on)<<FOUR);
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ZERO;
				break;
			default:
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = Cfg->nPulses_N;
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = Cfg->G_dig;
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][THREE]  = Cfg->nPulses_C;
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR]   = ((Cfg->CN1)<<FOUR)|(Cfg->CW1);
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIVE]    = ((Cfg->Current)<<THREE);
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIX]    =  ((Cfg->G_ana)<<FOUR)|(Cfg->BW);
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVEN]   = ((Cfg->CN2)<<FOUR)|(Cfg->CW2);
				US_SnrDrvMgr_F_DSI_SndBuf[cnt][EIGHT]    = ((Cfg->ATG_on)<<SEVEN)|((Cfg->STC_on)<<SIX)|((Cfg->FTC_on)<<FIVE)|((Cfg->NFD_on)<<FOUR);
				len = NINE;
				break;
    	}
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_PROFILE,len,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
 	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}
	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetChirpBWCmd - Asynchronous command  .
* used to Setup Sensors Chirp BW parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
*\param: ChirpBW: Chirp BW parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetChirpBWCmd
 * Remarks:  DD-ID: {A533224A-B34B-4d14-A5CA-EECE6FE829D6}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetChirpBWCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_ChirpCfg_t const  *Chirp =(US_S_ChirpCfg_t const *)sndData;               
	(void)rcvlen;
 	if(sndlen >= sizeof(US_S_ProfilePlusCfg_t))
 	{
 		cnt = US_SnrDrvMgr_F_CmdCnt;
 		US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;

 		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]   = ((Chirp->Type) << ONE) |((Chirp->BW)<<FOUR)|((Chirp->Dsr)<<THREE);
 		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]    = Chirp->BurstNum;
 		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    =  ZERO;

 		ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_CHIRP_BW,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
 	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}
	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetBurstTypeCfgCmd - Asynchronous command  .
* used to Setup Sensors Burst Type Cfg parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: BTypeC: Burst Type Cfg parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetBurstTypeCfgCmd
 * Remarks:  DD-ID: {1C102245-59FB-46cc-987E-016EDF90762F}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetBurstTypeCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_BurstTypeCCfg_t const *BTypeC = (US_S_BurstTypeCCfg_t const *)sndData;
	(void)rcvlen;
 	if(sndlen >= sizeof(US_S_BurstTypeCCfg_t))
 	{
 		cnt = US_SnrDrvMgr_F_CmdCnt;
 		US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;

 		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = (uint8_t)(((BTypeC->Code)>>EIGHT)&0xFFu);
 		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] = (uint8_t)((BTypeC->Code)&0xFFu);
 		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO] = (BTypeC->CodeLen)<<FOUR;

 		ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_BURST_TYPE_CONFIG,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
 	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetCurrentCmd - Asynchronous command  .
* used to Setup Sensors current  Cfg parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: CurCfg: current  Cfg parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetCurrentCmd
 * Remarks:  DD-ID: {8A3C259E-0326-4801-B290-9BF4D3C1D202}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetCurrentCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
     uint8_t cnt;
     US_S_CurrentCfg_t const *CurCfg =(US_S_CurrentCfg_t const *)sndData;     
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_CurrentCfg_t))
  	{
  		cnt = US_SnrDrvMgr_F_CmdCnt;
  		US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;

  		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = CurCfg->Idrive;
  		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] = (CurCfg->ReduceCurrent)<<SEVEN;
  		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO] = ZERO;

  		ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_CURRENT_CFG,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
  	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetGainCmd - Asynchronous command  .
* used to Setup Sensors Gain parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: GainCfg: Gain  Cfg parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetGainCmd
 * Remarks:  DD-ID: {1BC73E6F-AD51-4cc1-B947-165B36679BDB}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetGainCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
     uint8_t cnt;
     US_S_GainCfg_t const *GainCfg =(US_S_GainCfg_t const *)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_GainCfg_t))
  	{
  		cnt = US_SnrDrvMgr_F_CmdCnt;
  		US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
   
  		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = GainCfg->G_dig;
  		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = GainCfg->G_ana;
  		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ((GainCfg->FCx2)<<SEVEN)|( (GainCfg->G_reduce)<<SIX);

  		ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_GAIN,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
  	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetCalGainCmd - Asynchronous command  .
* used to Setup Sensors cal Gain parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: CalGain: cal Gain  parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetCalGainCmd
 * Remarks:  DD-ID: {54C67FED-C78D-4507-8323-C28CAB40CC9F}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetCalGainCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
     uint8_t cnt, CalGain;
	(void)rcvlen;
	if(sndlen >= sizeof(uint8_t))
   	{
   		CalGain =*(uint8_t const *)sndData;  
   		cnt = US_SnrDrvMgr_F_CmdCnt;
   		US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    
   		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = CalGain;
   		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = ZERO;
   		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ZERO;

   		ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_G_CAL,ONE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
   	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetEnvCfgCmd - Asynchronous command  .
* used to Setup Sensors ENVELOPE CONFIG parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: EnvCfg: ENVELOPE CONFIG  parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetEnvCfgCmd
 * Remarks:  DD-ID: {3FBED6DB-1C0A-4c76-8442-CD8FEEB3EB99}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetEnvCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EnvCfg_t const *EnvCfg =(US_S_EnvCfg_t const *)sndData;  
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EnvCfg_t))
    {
   		cnt = US_SnrDrvMgr_F_CmdCnt;
   		US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    
   		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]  = ((EnvCfg->AspiSel) <<TWO)| ((EnvCfg->FspiSel)<<ONE)|((EnvCfg->EnvAfc)<<THREE)|((EnvCfg->EnvCfg)<<FOUR);
   		US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] = ZERO;
   		US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ZERO;

   		ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_ENVELOPE_CONFIG,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetEnvFiltCfgCmd - Asynchronous command  .
* used to Setup Sensors ENVELOPE filter CONFIG parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
*\param: EnvFiltCfg: ENVELOPE filter CONFIG  parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetEnvFiltCfgCmd
 * Remarks:  DD-ID: {B343F5F0-5259-49e4-91B6-C85C360767C5}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetEnvFiltCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EnvFiltCfg_t const *EnvFiltCfg =(US_S_EnvFiltCfg_t const *)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EnvFiltCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = EnvFiltCfg->FiltLenCode;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = EnvFiltCfg->FiltLenFix;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ((EnvFiltCfg->F2CoeffSel)<<SIX)|((EnvFiltCfg->F1CoeffSel)<<SEVEN);

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_ENVELOPE_FILTER_CONFIG,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetMaxEchoNumCmd - Asynchronous command  .
* used to Setup Sensors echo config parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: EchoCfg:  echo config parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetMaxEchoNumCmd
 * Remarks:  DD-ID: {0C7AE84F-76C1-4418-9BFB-3AE2697A8055}
 * Req.-ID: 14214192
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetMaxEchoNumCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EchoCfg_t const *EchoCfg =(US_S_EchoCfg_t const*)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EchoCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
     
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = EchoCfg->MaxNum;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = ((EchoCfg->Type)<<FOUR)|((EchoCfg->mode)<<TWO);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ZERO;

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_MAX_ECHO_NUMBER,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetFixPathCfgCmd - Asynchronous command  .
* used to Setup Sensors Fix Path Cfg parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: FixPathCfg:  Fix Path Cfg parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetFixPathCfgCmd
 * Remarks:  DD-ID: {5868C21E-39E6-4e39-ACEE-327DDE43B53C}
 * Traceability to source Code: Req.-ID: 13427607
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetFixPathCfgCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_FixPathCfg_t const *FixPathCfg =(US_S_FixPathCfg_t const*)sndData;    
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EchoCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = (FixPathCfg->EevalSel)|((FixPathCfg->EevalSens)<<FOUR);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] =   ZERO;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO] =   ZERO;
	
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_FIX_PATH_CFG,ONE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetEDIChannelCmd - Asynchronous command  .
* used to Setup Sensors EDI channel parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: EDICfg:  EDI channel parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetEDIChannelCmd
 * Remarks:  DD-ID: {9519E49A-4795-43cc-B341-8A534D92BB08}
 * Traceability to source Code: Req.-ID: 13427616
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetEDIChannelCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EDICfg_t const *SetEDICfg =(US_S_EDICfg_t const *)sndData;   
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EDICfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
   
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = (uint8_t)((SetEDICfg->StartTime>>8)&0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = (uint8_t)((SetEDICfg->StartTime)&0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ((SetEDICfg->Mode)<<FOUR)|((SetEDICfg->SampleTime<<TWO));
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_EDI_CHANNEL,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSensorAmbiTempCmd - Asynchronous command  .
* used to Setup Sensors ambient temperature parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Temperature:  ambient temperature parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSensorAmbiTempCmd
 * Remarks:  DD-ID: {076C1B89-091B-4727-82ED-5DC048E701D9}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSensorAmbiTempCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    sint16_t Temperature =*(sint16_t const*)sndData;  
	(void)rcvlen;
	if(sndlen >= sizeof(sint16_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = (uint8_t)((((uint16_t)Temperature)>>EIGHT)&0xffu);   
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = (uint8_t)((((uint16_t)Temperature))&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ZERO;
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_AMBIENT_TEMPERATURE,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSensorRegisterCmd - Asynchronous command  .
* used to Setup Sensors register parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: RegCfg:  register cfg parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSensorEEPROMCmd
 * Remarks:  DD-ID: {AAADF975-7D4D-4c81-9808-3263B61F1CD0}
 * Traceability to source Code: Req.-ID: 13427620
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSensorEEPROMCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EEPROMCfg_t const *SetEEPROMCfg =(US_S_EEPROMCfg_t const*)sndData;     
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EEPROMCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = SetEEPROMCfg->Addr;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = ZERO;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO] = ZERO;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][THREE]  = (uint8_t)((SetEEPROMCfg->Data>>EIGHT)&0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR] = (uint8_t)((SetEEPROMCfg->Data)&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIVE]  = ZERO;
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_EEPROM,SIX,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSensorOPModeCmd - Asynchronous command  .
* used to Setup Sensors operation mode parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: mode:  operation mode parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSensorOPModeCmd
 * Remarks:  DD-ID: {53B6FEE8-A161-464d-BD7D-691757CF8FC6}
 * Traceability to source Code: Req.-ID: 13414460
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSensorOPModeCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    uint8_t mode =*(uint8_t const *)sndData;
 	(void)rcvlen;
	if(sndlen >= sizeof(uint8_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = mode;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = ZERO;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ZERO;
	
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_OPERATURE_MODE,ONE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSensorRegisterCmd - Asynchronous command  .
* used to Setup Sensors register parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: RegCfg:  register cfg parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSensorRegisterCmd
 * Remarks:  DD-ID: {ED699DCE-62C3-491d-9D30-52CE129DFD4A}
 * Traceability to source Code: Req.-ID: 13427656
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSensorRegisterCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_RegCfg_t const *RegCfg =(US_S_RegCfg_t const*)sndData;  
 	(void)rcvlen;if(sndlen >= sizeof(US_S_RegCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = RegCfg->ModAddr;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = RegCfg->Addr;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO] = ZERO;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][THREE]  = (uint8_t)((RegCfg->Data>>EIGHT)&0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR] = (uint8_t)((RegCfg->Data)&0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIVE]  = ZERO;

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_REGISTER,SIX,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetFTCCmd - Asynchronous command  .
* used to Setup Sensors FTC parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Ftc: FTC parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetFTCCmd
 * Remarks:  DD-ID: {3BE31308-BC84-4a2f-8B01-0F8EE6E8F338}
 * Traceability to source Code: Req.-ID: 13427488
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetFTCCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_FTCfg_t const *Ftc =(US_S_FTCfg_t const *)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_FTCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = (Ftc->Cfg)|((Ftc->Enable)<<FOUR);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ZERO;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    =  ZERO;
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_FTC,ONE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetATGCmd - Asynchronous command  .
* used to Setup Sensors ATG parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Atg: ATG parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetATGCmd
 * Remarks:  DD-ID: {742D2F31-0293-4cdb-9C1B-C692C55875BB}
 * Traceability to source Code: Req.-ID: 13427319
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetATGCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_ATGCfg_t const *Atg =(US_S_ATGCfg_t const*)sndData;  
	(void)rcvlen;
if(sndlen >= sizeof(US_S_ATGCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = ((Atg->Tau)<<FOUR)|(Atg->Int);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ((Atg->Alpha)<<FOUR)|((((Atg->On)==0u)?0u:1u)<<3u);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    =  ZERO;                                 /*pad data, align to three bytes */

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_ATG,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetAATG1Cmd - Asynchronous command  .
* used to Setup Sensors AATG1 parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Aatg1: AATG1 parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetAATG1Cmd
 * Remarks:  DD-ID: {5C2F1960-5CCE-4b67-976E-C9A16227BE81}
 * Traceability to source Code: Req.-ID: 13427399
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetAATG1Cmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_AATGCfg_t const *Aatg1 =(US_S_AATGCfg_t const*)sndData;  
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_AATGCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = ((Aatg1->CW)<<FOUR)|(Aatg1->CN);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = (Aatg1->Alpha)<<FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = ZERO;


    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_AATG1,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetAATG2Cmd - Asynchronous command  .
* used to Setup Sensors AATG2 parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Aatg2: AATG1 parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetAATG2Cmd
 * Remarks:  DD-ID: {062997AA-A0DD-4267-886B-2961CCA9DA76}
 * Traceability to source Code: Req.-ID: 13427476
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetAATG2Cmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_AATGCfg_t const *Aatg2 =(US_S_AATGCfg_t const*)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_AATGCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = ((Aatg2->CW)<<FOUR)|(Aatg2->CN);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = (Aatg2->Alpha)<<FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = ZERO;


    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_AATG2,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetAATG2Cmd - Asynchronous command  .
* used to Setup Sensors AATG2 parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Aatg2: AATG1 parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetFCCmd
 * Remarks:  DD-ID: {56C9D6A1-D741-4a61-9F5F-02C72B5C33BD}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetFCCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
     uint8_t cnt;
     uint16_t fc =*(uint16_t const*)sndData;    
	(void)rcvlen;
	if(sndlen >= sizeof(uint16_t))
     {
    	 cnt = US_SnrDrvMgr_F_CmdCnt;
    	 US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
         US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = (uint8_t)((fc >> EIGHT)&0xffu);
         US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = (uint8_t)(fc &0xffu);
    	 US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    =  ZERO;                       /*pad data, align to three bytes */
	
    	 ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_FC,TWO,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
     }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}


/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetNormalBurstNumCmd - Asynchronous command  .
* used to Setup Sensors Normal Burst Num parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: BurstNum: Normal Burst Num parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetNormalBurstNumCmd
 * Remarks:  DD-ID: {4C71D2E3-BC34-4df0-95A9-7F76AA62005D}
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetNormalBurstNumCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    uint8_t BurstNum =*(uint8_t const*)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(uint8_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = BurstNum;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ZERO;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = ZERO;                                    /*pad data, align to three bytes */
	
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_NORMAL_BURST_NUMBER,ONE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetNFDCmd - Asynchronous command  .
* used to Setup Sensors NFD parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: NFDCfg: NFD parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetNFDCmd
 * Remarks:  DD-ID: {D3EC0CC1-CDE7-4827-920E-0E2CCD330A58}
 * Traceability to source Code: Req.-ID: 13427611
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetNFDCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_NFDCfg_t const *NFDCfg =(US_S_NFDCfg_t const*)sndData; 
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_NFDCfg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = NFDCfg->LimitTime;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = NFDCfg->RingDev;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    =  ZERO;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][THREE] = (uint8_t)((NFDCfg->Th>>EIGHT)&0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR] = (uint8_t)((NFDCfg->Th)&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIVE] = (NFDCfg->Sen)<<FOUR;

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_NFD,SIX,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetGanaMeasBeginCmd - Asynchronous command  .
* used to Setup Sensors Gana Measurement Begin parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: GanaMeasBegin: Gana Measurement Begin parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetGanaMeasBeginCmd
 * Remarks:  DD-ID: {A898A185-02A2-4c0b-8D27-8DB566506900}
 * Traceability to source Code: Req.-ID: 13427732
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetGanaMeasBeginCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_GanaMeasBegin_t const *GanaMeasBegin =(US_S_GanaMeasBegin_t const*)sndData;   
   	(void)rcvlen;
	if(sndlen >= sizeof(US_S_GanaMeasBegin_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = (uint8_t)(((GanaMeasBegin->EndTime)>>EIGHT)& 0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = (uint8_t)((GanaMeasBegin->EndTime) & 0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    =  ((GanaMeasBegin->Gana_Dig)<<SEVEN)|((GanaMeasBegin->Gana)<<FOUR);

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_GANA_MEAS_BEGIN,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetEEVALSENSMEASCmd - Asynchronous command  .
* used to Setup Sensors EEVALMeasurement.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: GanaMeasBegin: Gana Measurement Begin parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetEEVALSENSMEASCmd
 * Remarks:  DD-ID: {913C035D-53EB-471e-909E-38C2ADDC6903}
 * Traceability to source Code: Req.-ID: 13427737
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetEEVALSENSMEASCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_EEVALSENSMEAS_t const *EevalSenMeas =(US_S_EEVALSENSMEAS_t const*)sndData;  
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_EEVALSENSMEAS_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = (uint8_t)(((EevalSenMeas->val)>>24) & 0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = (uint8_t)(((EevalSenMeas->val)>>16) & 0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = (uint8_t)(((EevalSenMeas->val)>>EIGHT) & 0xc0u);                                    /*pad data, align to three bytes */

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_EEVAL_SENS_MEAS,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetEEVALSENSMEASCmd - Asynchronous command  .
* used to Setup Sensors EEVALMeasurement.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: GanaMeasBegin: Gana Measurement Begin parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetADDRBYEEPROMCmd
 * Remarks:  DD-ID: {BE65D1CE-7E02-4e64-A7DE-669637ECF510}
 * Traceability to source Code: Req.-ID: 13427661
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetADDRBYEEPROMCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
	(void)rcvlen;
	if(sndlen >= ONE)
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = *(uint8_t const*)sndData;  
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = ZERO;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = ZERO;                                    /*pad data, align to three bytes */

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_ENABLE_ADDRBYEEP,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}


/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSensorEEFlagVarCTRLCmd - Asynchronous command  .
* used to Setup Sensors EEFlagVarCTRL parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: EEFlagVarCTRL: EEFlagVarCTRL parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSensorEEFlagVarCTRLCmd
 * Remarks:  DD-ID: {5B3D8484-D90C-4a7a-A60F-80599DA9BD6A}
 * Traceability to source Code: Req.-ID: 13427737
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSensorEEFlagVarCTRLCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_SensorEEFlagVarCTRL_t const *SetEEFlagVarCTRL =(US_S_SensorEEFlagVarCTRL_t const*)sndData;  
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_SensorEEFlagVarCTRL_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]   = (uint8_t)(((SetEEFlagVarCTRL->val)>>24) & 0xffu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]    = (uint8_t)(((SetEEFlagVarCTRL->val)>>16) & 0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]    = ZERO;                                    /*pad data, align to three bytes */
	
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_EEFLAG_VARCTRL,THREE,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}
	return ret;
}
/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSTGCmd - Asynchronous command  .
* used to Setup Sensors STG parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Stg: STG parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSTGCmd
 * Remarks:  DD-ID: {CDF0F0AF-4D4A-48eb-AE32-064425C7161F}
 * Traceability to source Code: Req.-ID: 13427496
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSTGCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_StgSeg_t const *Stg =(US_S_StgSeg_t const *)sndData;   
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_StgSeg_t))
    {
        cnt = US_SnrDrvMgr_F_CmdCnt;
        US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
    
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO]  = Stg->seg[0].th;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE]  = Stg->seg[0].time;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO]  = ZERO;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][THREE]  = (uint8_t)Stg->seg[0].step;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR]   =  (uint8_t)(Stg->seg[0].tb>>EIGHT) &0xFFu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR]   <<= SIX;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR]   |= (uint8_t)((Stg->seg[0].tb>>TWO) & 0x3Fu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIVE]  = (uint8_t)((((uint8_t)(Stg->seg[0].tb & THREE))<<SIX)|((Stg->start)<<TWO));   
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIX]  = Stg->seg[1].th;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVEN]  = Stg->seg[1].time;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][EIGHT]  = ZERO;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][NINE]  = (uint8_t)(Stg->seg[1].step)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TEN]  =  (uint8_t)(Stg->seg[1].tb>>EIGHT)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TEN]  <<= SIX;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TEN]  |= (uint8_t)((Stg->seg[1].tb>>TWO) & 0x3Fu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][ELEVEN]  = (uint8_t)((((uint8_t)(Stg->seg[1].tb & THREE))<<SIX)|((Stg->start+ONE)<<TWO));    

        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWELVE]  = Stg->seg[2].th;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][THIRTEEN]  = Stg->seg[2].time;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOURTEEN]  = ZERO;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIFTEEN]  = (uint8_t)(Stg->seg[2].step)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIXTEEN]  =  (uint8_t)(Stg->seg[2].tb>>EIGHT)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIXTEEN]  <<= SIX;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIXTEEN]  |= (uint8_t)((Stg->seg[2].tb>>TWO) & 0x3Fu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVENTEEN]  = (uint8_t)((((uint8_t)(Stg->seg[2].tb&THREE))<<SIX)|((Stg->start+TWO)<<TWO));    

        US_SnrDrvMgr_F_DSI_SndBuf[cnt][EIGHTEEN]  = Stg->seg[3].th;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][NINETEEN]  = Stg->seg[3].time;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY]    = (uint8_t)(((uint8_t)Stg->profile)<<FOUR)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_ONE]  = (uint8_t)(Stg->seg[3].step)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_TWO]  =  (uint8_t)(Stg->seg[3].tb>>EIGHT)&0xffu;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_TWO]  <<= SIX;
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_TWO]  |= (uint8_t)((Stg->seg[3].tb>>TWO) & 0x3Fu);
        US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_THREE]  = (uint8_t)(((Stg->seg[3].tb & THREE)<<SIX)|(((uint16_t)Stg->start+THREE)<<TWO));

    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_STG,TWENTY_FOUR,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvMgr_F_SetSTGCmd - Asynchronous command  .
* used to Setup Sensors STG parameter.
* \param: SnrMap: Specify the Sensors will be applied this cmd, UseData: for user pass data to callback, Call back function, it is called with error code when cmd is completed or abort
* \param: Stg: STG parameter is setup to Sensors
* \return: if successful(ME_OK), the cmd is put into Cmd Queue or begin executing successful, fail: cmd queue is full
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetSTCCmd
 * Remarks:  DD-ID: {6D12F3D7-78FA-446c-8F9E-69E957D176C7}
 * Traceability to source Code: Req.-ID: 13427492
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetSTCCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t ret = ME_OK;
    uint8_t cnt;
    US_S_StcSeg_t const *Stc =(US_S_StcSeg_t const*)sndData;     
	(void)rcvlen;
	if(sndlen >= sizeof(US_S_StcSeg_t))
    {
    	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
 
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ZERO] = ((Stc->seg[0].target)<<ONE)|(Stc->seg[0].mode);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] = (uint8_t)((Stc->seg[0].tb>>EIGHT)&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] <<=  FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ONE] |=  ((uint8_t)(Stc->seg[0].tb)&0xffu)>>FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWO] = (uint8_t)(Stc->seg[0].tb & 0xfu)<<FOUR;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][THREE] =  Stc->seg[0].time;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOUR] =   (Stc->start)<<FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIVE] =   ZERO;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIX] = ((Stc->seg[ONE].target)<<ONE)|(Stc->seg[1].mode);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVEN] = (uint8_t)((Stc->seg[1].tb>>EIGHT)&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVEN] <<=  FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVEN] |=  ((uint8_t)(Stc->seg[1].tb)&0xffu)>>FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][EIGHT] = (uint8_t)(Stc->seg[1].tb & 0xfu)<<FOUR;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][NINE] =  Stc->seg[1].time;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TEN] =   (Stc->start+ONE)<<FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][ELEVEN] =   ZERO;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWELVE] = ((Stc->seg[2].target)<<ONE)|(Stc->seg[2].mode);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][THIRTEEN] = (uint8_t)((Stc->seg[2].tb>>EIGHT)&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][THIRTEEN] <<=  FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][THIRTEEN] |=  ((uint8_t)(Stc->seg[2].tb)&0xffu)>>FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][FOURTEEN] = (uint8_t)(Stc->seg[2].tb & 0xfu)<<FOUR;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][FIFTEEN] =  Stc->seg[2].time;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][SIXTEEN] =   (Stc->start+TWO)<<FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][SEVENTEEN] =   ZERO;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][EIGHTEEN]= ((Stc->seg[3].target)<<ONE)|(Stc->seg[3].mode);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][NINETEEN] = (uint8_t)((Stc->seg[3].tb>>EIGHT)&0xffu);
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][NINETEEN] <<=  FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][NINETEEN] |=  ((uint8_t)(Stc->seg[3].tb)&0xffu)>>FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY] = (uint8_t)(Stc->seg[3].tb & 0xfu)<<FOUR;

    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_ONE] =  Stc->seg[3].time;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_TWO] =   (Stc->start+THREE)<<FOUR;
    	US_SnrDrvMgr_F_DSI_SndBuf[cnt][TWENTY_THREE] =   ((uint8_t)(Stc->profile))<<FOUR;

	
    	ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,SETUP_SENSOR_STC,TWENTY_FOUR,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
    }
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}

	return ret;
}

/* ===========================================================================
 * Name:	 US_SnrDrvMgr_F_SetDSIMasterRegByTableCmd
 * Remarks:  DD-ID: {8A53810A-64B3-48ab-958B-C06DF55FEB37}
 * Traceability to source Code: Req.-ID: 13427492
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetDSIMasterRegByTableCmd(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t CmdId,RegAddr;
	uint32_t ret = ME_OK;
    uint8_t cnt,i;
 	(void)rcvlen;
	if(sndlen >= FOUR)
    {
     	cnt = US_SnrDrvMgr_F_CmdCnt;
    	US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
		for(i = ZERO; i <( sndlen-TWO); i++)
		{
     	   US_SnrDrvMgr_F_DSI_SndBuf[cnt][i] = sndData[i+TWO];
		}
		RegAddr = sndData[ONE];
		RegAddr = (RegAddr << EIGHT) | sndData[ZERO];
		CmdId  = DSI_CMD_WRITE_MASTER_REG | RegAddr;
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,CmdId,sndlen,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,rcvData,CallBack);
	}
	else
	{
		  ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
	}
    return ret;
}
/* ===========================================================================
 * Name:     US_SnrDrvMgr_F_SetDSIMasterRegCmd
 * Remarks: {8678EEB7-02BD-4551-BC2D-B7BBC5F616F1}
 * Traceability to source Code: Req.-ID:
 * ===========================================================================*/
uint32_t US_SnrDrvMgr_F_SetDSIMasterRegCmd(uint32_t SnrMap,uint32_t UserData,uint16_t RegAddr,uint16_t len,uint8_t const *sndData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
    uint32_t CmdId;
    uint32_t ret = ME_OK;
    uint8_t cnt,i;
    if(len >= TWO)
    {
        cnt = US_SnrDrvMgr_F_CmdCnt;
        US_SnrDrvMgr_F_CmdCnt = (cnt+ ONE)  & USSQUEUEMASK;
        for(i=ZERO;i<len;i++)
        {
            US_SnrDrvMgr_F_DSI_SndBuf[cnt][i] = sndData[i];
        }
        CmdId  =(uint32_t) DSI_CMD_WRITE_MASTER_REG|RegAddr;
        ret = US_SnrDrvCom_F_CmdSnd(SnrMap,UserData,CmdId,len,US_SnrDrvMgr_F_DSI_SndBuf[cnt],0,NULL,CallBack);
    }
    else
    {
          ret = ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
    }
    return ret;
}
/* ===========================================================================*/
/**US_SnrCfg_F_SensorMarrage.
 * used to setup STCs and STGs to sensors according to Type.
 * \param SnrMAp: sensor maps
 * \param Stc: pointer to STCs parameters, Stg: pointer to STGs parameters,
 * \return: returns error code
 * \remarks  no remarks
 */
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrCfg_F_SensorMarrage
 * Remarks:  {7C86A67C-BCF0-4fe6-9297-8A385E34BD67}
 * Traceability to source Code:
 * KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity 
 * ===========================================================================*/

uint32_t US_SnrDrvMgr_F_SensorMarrage(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen,uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
	   uint32_t ret;
	   void (*pCallback)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);
  	(void)rcvlen;
	(void)SnrMap;
	(void)UserData;
	(void)sndData;
	(void)sndlen;

	  /*
       * Perform Sensor Marriage sensor marriage index mapping
       * Must be performed after getting sensor IDs to adjust maps
       */
          ret = US_Read_MarriageSensorID(); /*read sensor IDs from NVRAM */
      	  UssCtrl_PerformSnrMarIdxMapping();
      	  pCallback = CallBack;
		  if(pCallback != NULL)
		  {
				(*pCallback)(ret,US_READ_SENSORS_MARRIAGE_MAPPING, 0, 0,rcvData);
	      }
		  return ME_OK;
}
