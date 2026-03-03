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
#include "US_Ctrl_Global.h"
#include "US_ComOutputBuffer_Global.h"


#define DSI3_UV_MASK                               (0x2000u)
#define DSI3_OC_MASK                               (0x800u)
#define DSI3_RAM_BIST_MASK                         (0x4u)
#define DSI3_FSM_RST_MASK                          (0x400u)
#define DSI3_OT_MASK                               (0x4000u)
#define DSI3_VCCUV_MASK                            (0x8000u)
#define DSI3_VDSIUV_MASK                           (0x800u)

#if (QAC_WARNING_FIX  ==  ME_FALSE)
#define US_RECFG_SENSOR_DELAY                      (10u)
#define US_SNRCFG_WAIT                             (10000u)
#define SNR_NEW_ID_ADDR                            (0xA6u)         /*need to be updated when it is available */
#define SNR_RESET_REASON_ADDR                      (0xC8u)         /*need to be updated when it is available */
#define SENSOR_CFG_OPMODE                          (SENSOR_OP_NORMAL)                     /*(SENSOR_OP_NORMAL)   (SENSOR_OP_MFG) */
#endif

#define MAX_RFC_DELAY                               (20000u)
#define AFTER_RFC_DELAY                               (200u)
#define READ_REG_DSI3_SPI_IRQ_EN                    (0x1000u)
#define READ_REG_DSI3_DSI_IRQ_EN                    (0x1001u)
#define READ_REG_DSI3_IRQ_EN                        (0x1002u)
#define READ_REG_DSI3_PDCMPERIOD                    (0x1003u)
#define READ_REG_DSI3_CTLR_REG                      (0x1006u)
#define READ_REG_DSI3_CFG_REG                       (0x804u)

#define  MAX_RFC_RETRY                               (16u)
#define  MAX_REG_MISMATCH_RETRY                      (16u)
#define  MAX_WAIT_DSI3TRCVR_CFG                      (4u)

#define TRCVR_ERR_CHECK_PERIOD                       (2u)
#define TRCVR_ERR_RESET_PERIOD                       (TRCVR_ERR_CHECK_PERIOD *4u)


#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Dsi3Trcv_CsmIf.h"
#endif

enum                   /*US_E_Transceiver_STATE_ID_e*/
{
    US_TRANSCEIVER_RESET = 0,
	US_TRANSCEIVER_RELESE_RESET,
	US_CFG_DSI3TRCVRREGISTERS,
	US_TRANSCEIVER_MAX
};


typedef struct                   /*US_Trcver_ResetTable_s*/
{
	uint16_t          state;                  /* Reset state */
	void          (*US_Trcver_ResetTable_CfgFxn)(void);
}US_Trcver_ResetTable_t;



static void US_SnrDrv_F_Cfg_DSI3TransceiverCmd(void);
static void US_SnrDrv_F_Reset_DSI3TransceiverCmd(void);
static void US_SnrDrv_F_ReleaseReset_DSI3TransceiverCmd(void);
static uint32_t US_SnrDrv_F_ReCfg_Delay(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
static uint32_t US_SnrDrv_F_Reset_DSI3Trciver(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
static uint32_t US_SnrDrv_F_Reset_DSI3Trciver_check(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));




static uint16_t dsi3_irqstat_reg[16];
static const uint16_t DSI3_REG_CHECK[] ={0x20,0x2800,0xCE07,0x55aa,0x8,0x0,0x1};
static uint8_t US_SnrDrv_ReCfg_need = ME_FALSE;
static uint8_t US_SnrDrv_DSI3Trcv_Configuring = ME_FALSE,US_SnrDrv_registers_mismatch = ME_FALSE;

static uint16_t US_SnrDrv_Transciver_State =  (uint16_t)US_TRANSCEIVER_MAX;

static uint8_t  US_SnDrv_TrcvChnStatus = DSI3_CHANNEL_ENABLED;

static void  US_SnrDrv_F_Init_DSI3INTB(void);

static void US_SnrDrv_E521_24_ProcessError(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);
static uint16_t  US_SnrDrv_Clr_DSI3INTB(void);
static void US_SnrDrv_Trciver_Reset_task(void);
static uint16_t  US_SnrDrv_Clr_DSI3INTB(void);


#if(US_CSM_ENABLE == ME_TRUE)
	
static UsCsm_LocalStateId_Type UsDsirTrcv_State = US_CSM_LOCAL_STATE_UN_INIT;

/**
 * \brief This function request to dsi3 transreceiver to change state.
 * DD-ID: 
 * \param instanceId 
 * \param reqState 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name:  Us_Dsi3Trcv_ReqState_Csm   
 * Remarks:  DD-ID: {294670CC-1BB0-42d5-8B21-11BE2E11ECDE}
 * ===========================================================================*/
 UsCsm_StdReturn_Type Us_Dsi3Trcv_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState)
 {
	(void)instanceId;
	 UsDsirTrcv_State  = reqState;
	 if(UsDsirTrcv_State == US_CSM_LOCAL_STATE_SHUTDOWN)
	 {
		 	 US_Reset_DSI3Tranceiver();
	 }
	return US_CSM_STD_RET_OK;
 }

/**
 * \brief This function returns the dsi3 trcv driver state.
 * DD-ID: 
 * \param instanceId 
 * \return UsCsm_LocalStateId_Type 
 */
/* ===========================================================================
 * Name: Us_Dsi3Trcv_GetState_Csm    
 * Remarks:  DD-ID: {3563E268-2851-429b-AF84-B78A8B3366BE}
 * ===========================================================================*/
 UsCsm_LocalStateId_Type Us_Dsi3Trcv_GetState_Csm(UsCsm_InstanceId_Type instanceId)
 {
	(void)instanceId;
	return UsDsirTrcv_State;
 }
#endif

/**
 * \brief This function returns DSI3 channel enabled/disabled status.
 * DD-ID:
 * \param instanceId 
 * \return UsCsm_LocalStateId_Type 
 */
/* ===========================================================================
 * Name: US_SnrDrv_GetChnStatus    
 * Remarks:  DD-ID: {2EC73280-6BCE-4aa3-8977-E379A4A9DEEB}
 * ===========================================================================*/

uint8_t US_SnrDrv_GetChnStatus(void)
{
	return US_SnDrv_TrcvChnStatus;
}
/* ===========================================================================
 * Name:     US_SnrDrv_Check_TransceiverResetState
 * used to check if Transceiver is in reset process
 * Remarks:  DD-ID: {3C1D7A5A-9145-4bf7-BAE1-C4EA0CB7172C}
 * ===========================================================================*/
uint8_t US_SnrDrv_Check_TransceiverResetState(void)
 {
	uint8_t ret = ME_FALSE;
	if(US_SnrDrv_Transciver_State < (uint16_t)US_TRANSCEIVER_MAX )  
	{
		ret = ME_TRUE;  /* in reset process */
	}
	return ret;
 }
/* ===========================================================================
 * Name:     US_SnrDrv_Start_DSI3Transceiver_Reset
 * Remarks:  DD-ID: {3C1D7A5A-9145-4bf7-BAE1-C4EA0CB7172C}
 * ===========================================================================*/
void US_SnrDrv_Start_DSI3Transceiver_Reset(void)
{
	if(US_SnrDrv_Transciver_State >= (uint16_t)US_TRANSCEIVER_MAX )  /* transceiver is in reset process? */
	{
		US_SnrDrv_Transciver_State = (uint16_t)US_TRANSCEIVER_RESET;
		US_Reset_DSI3Tranceiver();            /* set pin to low */
		if(US_SnrDrv_Transciver_State < ((uint16_t)0xFFFF))
		{
				US_SnrDrv_Transciver_State++;
		}
		else{
			/* Do nothing */
		}
	    
	}
}
/************************************************************
* DSI3 Error process from INTB pin 
*************************************************************/
/* ===========================================================================
 * Name: US_SnrDrv_E521_24_ProcessError    
 * Remarks:  DD-ID: {925EE665-ADF3-4bc8-8EF6-496DA519817E} 
 * ===========================================================================*/
static void US_SnrDrv_E521_24_ProcessError(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData)
{
    /*KPK-QAC Fix : Need to suppress, no impact on pointer casting to uint16_t */
    uint16_t len;
    uint16 const*pData = (uint16_t const*)RcvData;
    static uint8_t cfg_register_err = ME_FALSE;
	static uint16_t DSI3_Stat_reg[TWO]={0};
    if((RcvData != NULL)&&((Cmd &0xC000u)== DSI_CMD_READ_MASTER_REG))  /* read transceiver register cmd? */
    {
    	len = pData[ZERO];
      	if(((UserData & (uint32_t)0xff00u) == 0x800u)&&(len >= TWO)&&(len < RcvSize))  /* configure transceiver complete? */
      	{   /*check if DSI3 channel is disabled */
    		if((DSI3_REG_CHECK[UserData & (uint32_t)0x07] != pData[ONE])||((DSI3_REG_CHECK[UserData & (uint32_t)0x07] != pData[TWO])&&(len>TWO))) 
    		{
    			US_SnrDrv_ReCfg_need        =  ME_TRUE;
    			US_SnDrv_TrcvChnStatus = DSI3_CHANNEL_DISABLED;
    		}
			else
			{
				US_SnDrv_TrcvChnStatus = DSI3_CHANNEL_ENABLED;
			}
    		if(US_SnrDrv_Check_TransceiverResetState() != (uint8_t)ME_FALSE)  /*transceiver reset complete ?*/
    		{
    			US_SnrDrv_DSI3Trcv_Configuring  = ME_FALSE;
    		}
       	}
      	else if(((UserData & (uint32_t)0xff00u) == 0x1000u)&&(len >= TWO)&&(len < RcvSize))	
    	{   /* any register is not matched configure? */ 
     		if((DSI3_REG_CHECK[UserData & (uint32_t)0x07u] != pData[ONE])||((DSI3_REG_CHECK[UserData & (uint32_t)0x07u] != pData[TWO])&&(len>TWO))) 
    		{
     			   cfg_register_err = ME_TRUE;    /* match error happened*/
    		}
     		if(Cmd  == (DSI3_CTLR_REG|DSI_CMD_READ_MASTER_REG))   /* last register read */
     		{
    			if(cfg_register_err == (uint8_t)ME_TRUE)
    			{
				    US_SnrDrv_registers_mismatch = ME_TRUE;
					US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI3_registers_mismatch);
    	    	}
    		    else
    		    {
				    US_SnrDrv_registers_mismatch = ME_FALSE;
   			        US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI3_registers_mismatch);
    		    }
			    cfg_register_err = ME_FALSE;
     		}
    	}
		else
		{
			/* Do nothing */
		}
    	if(US_SnrDrv_Check_TransceiverResetState() == (uint8_t)ME_FALSE)  /* transceiver is not in reset */
    	{
			if(((UserData & (uint32_t)0x3ff) == DSI3_IRQ_STAT)&&(len >= TWO)&&(len < RcvSize))
			{
				if((pData[ONE] & DSI3_RAM_BIST_MASK) != ZERO)    /* RAM BIST error */
			   {
				   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL);
			   }
			   else
			   {
				   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL);
			   }
				if((pData[ONE] & DSI3_FSM_RST_MASK) != ZERO)     /* FSM reset happened*/
			   {
				   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_FSM_RESET);
			   }
			   else
			   {
				   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_FSM_RESET);
			   }
				if((pData[ONE] & DSI3_OT_MASK) != ZERO)         /* transceiver over temperature */
			   {
				   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_OT_ERR);
			   }
			   else
			   {
				   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_OT_ERR);
			   }
				if((pData[ONE] & DSI3_VDSIUV_MASK) != ZERO)   /* VDSI under voltage */
			   {
				   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_DSIUV_ERR);
			   }
			   else
			   {
				   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_DSIUV_ERR);
			   }
				if((pData[ONE] & DSI3_VCCUV_MASK) != ZERO)    /* VCC under voltage */
			   {
				   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_VCCUV_ERR);
			   }
			   else
			   {
				   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_VCCUV_ERR);
			   }
			}
			else if(((UserData & (uint32_t)0x3ff) == DSI3_REG_STAT)&&(len >= FOUR)&&(len < RcvSize))
			{
				DSI3_Stat_reg[ZERO] = pData[ONE];
				DSI3_Stat_reg[ONE] = pData[TWO];
			}
			else if(((UserData & (uint32_t)0x3ff) == DSI3_DSI_IRQ_STAT)&& (len >= FOUR)&&(len < RcvSize))
			{
					   if(((pData[ONE] & DSI3_UV_MASK) != ZERO)&&((DSI3_Stat_reg[ZERO] & DSI3_UV_MASK) != ZERO)&&((ErrorCode & ERROR_US_SNRDRVCOM_DSI_CH0_UV) != ZERO)) /* ch0 under voltage */
					   {
						   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI0_UV_ERR);
					   }
					   else
					   {
						   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI0_UV_ERR);
					   }
					   if(((pData[ONE] & DSI3_OC_MASK) != ZERO)&&((DSI3_Stat_reg[ZERO] & DSI3_OC_MASK) != ZERO)) /* ch0 over current */
					   {
						   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI0_OC_ERR);
					   }
					   else
					   {
						   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI0_OC_ERR);
					   }
					  if(((pData[TWO] & DSI3_UV_MASK) != ZERO)&&((DSI3_Stat_reg[ONE] & DSI3_UV_MASK) != ZERO)&&((ErrorCode & ERROR_US_SNRDRVCOM_DSI_CH1_UV) != ZERO)) /* ch1 under voltage */
					   {
						   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI1_UV_ERR);
					   }
					   else
					   {
						   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI1_UV_ERR);
					   }
					  if(((pData[TWO]& DSI3_OC_MASK) != ZERO)&&((DSI3_Stat_reg[ONE] & DSI3_OC_MASK) != ZERO)) /* ch0 over current */
					   {
						   US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI1_OC_ERR);
					   }
					   else
					   {
						   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI1_OC_ERR);
					   }
			}
			else
			{ /* empty */		
			}
    	}
		else
		{   /* empty */
		}
    }
 }

/***************************************************************************
* check if intB or RFC is low  
****************************************************************************/
/* ===========================================================================
 * Name: US_SnrDrv_DSI3_Check    
 * Remarks:  DD-ID: {0D84B7B9-7007-4114-BAD4-B85AB5A800A3}
 * ===========================================================================*/
void US_SnrDrv_DSI3_Check(void)
{
	static uint16_t Intb_cnt =ZERO,DSI3_Err_cnt =ZERO;
	uint32_t snrmap;
	uint16_t data;
	uint8_t intb_pin,DSI3Ready;
	UssMgr_e_SysState_t SysState;
	SysState = UssMgr_eGetSysState();

	if((SysState != SYSMGR_SYS_INIT)&&(SysState != SYSMGR_SYS_POWERON)&&(SysState != SYSMGR_SYS_INIT_CALIDATA))  /*after hardwarea and data init */
	{
		intb_pin = US_DSI3_Check_INTB_State(); 
                                           DSI3Ready = US_CheckDSI3Ready();
		if(US_SnrDrv_Check_TransceiverResetState() == (uint8_t)ME_TRUE )   /* process tranceiver reset */
		{
			DSI3_Err_cnt = ZERO;
			UssCtrl_ClearReceiveErrorCnt();
			US_SnrDrv_Trciver_Reset_task();               /*reset task */
		}
		else if((intb_pin != (uint8_t)ZERO)&&(DSI3Ready != (uint8_t)ZERO)&&(US_SnDrv_TrcvChnStatus == (uint8_t)DSI3_CHANNEL_ENABLED))  /*normal operation*/
		{
			Intb_cnt++;
			DSI3_Err_cnt = ZERO;
			if(US_SnrDrv_ReCfg_need  != (uint8_t) ME_FALSE)  /* need to configure sensors because transceiver just complete reset*/
			{
				US_SnrDrv_ReCfg_need  =  ME_FALSE;
				UssCtrl_TriggerSnrCfg();
			}
			else if((Intb_cnt%FOUR) == ZERO)     
			{   /* clear DSI3 error flag */
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_OT_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_VCCUV_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI0_UV_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI1_UV_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI0_OC_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI1_OC_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_RFC_ERR);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_FSM_RESET);
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL);
			}
			else
			{ /*empty */
			}
		}
		else   /* error happened */
		{                 
            DSI3Ready    =  US_CheckDSI3Ready();
			if((DSI3_Err_cnt%TRCVR_ERR_RESET_PERIOD) == (TRCVR_ERR_RESET_PERIOD -ONE))
			{
				US_SnrDrv_Start_DSI3Transceiver_Reset();
			}
			else if(DSI3Ready  == (uint8_t)ZERO)     /* RFC is low */
			{
		        US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_RFC_ERR);
				US_SnrDrv_Start_DSI3Transceiver_Reset();
			}
			else if((DSI3_Err_cnt%TRCVR_ERR_CHECK_PERIOD) == ZERO) /* start to check error register */
			{
				data = 0xffffu;
				snrmap = US_SnrCfg_F_Get_SnrBusMap(US_ALL_POS);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,DSI3_REG_STAT,DSI3_REG_STAT,8u,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
		        (void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,DSI3_DSI_IRQ_STAT,DSI3_DSI_IRQ_STAT,8u,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,DSI3_IRQ_STAT,DSI3_IRQ_STAT,8u,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
		        (void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,DSI3_DSI_IRQ_STAT,DSI3_DSI_IRQ_STAT,2u,(uint8_t*)&data,US_SnrDrv_E521_24_ProcessError);
		        (void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,DSI3_IRQ_STAT,DSI3_IRQ_STAT,2u,(uint8_t*)&data,US_SnrDrv_E521_24_ProcessError);
		        (void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_CFG_REG,DSI3_CFG_REG_CH0,8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
			}
            else{/*empty*/}
		    DSI3_Err_cnt++;
		}
	}
 }
/* ===========================================================================
 * Name:	 US_SnrDrv_Clr_DSI3INTB
 * Used to clear intB flags
 * Remarks:  DD-ID: 
 * Traceability to source Code: Req.-ID:
 * Req.-ID:
 * Req.-ID:
 * ===========================================================================*/
/* ===========================================================================
 * Name: US_SnrDrv_Clr_DSI3INTB    
 * Remarks:  DD-ID: {7DA84DDD-19AD-4f74-89D2-5D201F090EDD}
 * ===========================================================================*/
static uint16_t  US_SnrDrv_Clr_DSI3INTB(void) 
{
    static const uint16_t DSI3_INTB_STAT[] ={DSI3_SPI_IRQ_STAT,DSI3_DSI_IRQ_STAT,DSI3_IRQ_STAT};      
	uint32_t temp;
	uint16_t cnt,data;
	uint16_t ret  =  ME_OK;
	for(cnt =ZERO;  cnt<THREE;   cnt++ )
	{
	   data = 0xffff;
	   temp = US_SnrCfg_F_Get_SnrBusMap(US_ALL_POS);
	   (void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(temp,ZERO,DSI3_INTB_STAT[cnt],2u,(uint8_t*)&data,NULL);
	   temp =US_SnrDrvMgr_F_ReqDSIMasterRegCmd(temp,0x0005u,DSI3_INTB_STAT[cnt],8u,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
	   if(temp != ME_OK)
	   {
		  ret = ME_NOT_OK;
	   }
	}
	return ret;
}

/* ===========================================================================
 * Name:     US_SnrDrvMgr_F_Reset_DSI3TransceiverCmd
 * Remarks:  DD-ID: {12FA8245-2C70-423a-8C5C-4C14489A70E1}
 * Traceability to source Code: Req.-ID:
 * ===========================================================================*/
static void US_SnrDrv_F_Reset_DSI3TransceiverCmd(void)
{
	 US_Reset_DSI3Tranceiver();
	 if(US_SnrDrv_Transciver_State < ((uint16_t)0xFFFF))
	 {
	 	US_SnrDrv_Transciver_State++;
	 }
	 else{
		/*  Overflow error handling  */
	 }
}
/* ===========================================================================
 * Name:     US_SnrDrvMgr_F_Reset_DSI3TransceiverCmd
 * Remarks:  DD-ID: {E19829BF-18DA-4bb9-82F3-686B15B0328E} 
 * Traceability to source Code: Req.-ID:
 * ===========================================================================*/
static void US_SnrDrv_F_ReleaseReset_DSI3TransceiverCmd(void)
{
	 static uint8_t retry = 0;
	 uint8_t DSI3Ready;
	 uint16_t cnt;
	 US_Release_Reset_DSI3Tranceiver();
	 for(cnt=ZERO;cnt<MAX_RFC_DELAY;cnt++)
	 {
		 DSI3Ready = US_CheckDSI3Ready();
		 if(DSI3Ready != (uint8_t)ZERO)
		 {
			 break;
		 }
	 }
	 DSI3Ready = US_CheckDSI3Ready();
	 if(DSI3Ready != (uint8_t)ZERO)
	 {
        for(cnt=ZERO;cnt<AFTER_RFC_DELAY;cnt++)   /*add delay */
	    {
		  (void)US_CheckDSI3Ready();
	    }
	    DSI3Ready = US_CheckDSI3Ready();
		if(DSI3Ready != (uint8_t)ZERO)
		{
		 US_SnrDrv_F_Init_DSI3INTB();
		 US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_RFC_ERR);
		 retry = ZERO;
		}
	 }
	  DSI3Ready = US_CheckDSI3Ready();
	 if((DSI3Ready == (uint8_t)ZERO)&&(retry < MAX_RFC_RETRY))
	 {
		 US_SnrDrv_Transciver_State = (uint16_t)US_TRANSCEIVER_RESET;
		 US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_RFC_ERR);
		 retry ++;
	 }
	 else
	 {
		if(US_SnrDrv_Transciver_State < ((uint16_t)0xFFFF))
		{
		 	US_SnrDrv_Transciver_State++;
		}
		else{
			/*  Overflow error handling  */
		}
		 retry = ZERO;
	 }
}


/* ===========================================================================
 * Name:	 US_SnrDrv_F_Init_DSI3INTB
 * Remarks:  DD-ID: {4752CB8E-3F77-4da3-B181-7CCD58FAD209}
 * Traceability to source Code: Req.-ID:
 * Req.-ID:
 * Req.-ID:
 * ===========================================================================*/
static void  US_SnrDrv_F_Init_DSI3INTB(void)
{
                        static const uint16_t DSI3_INTB_EN[]   ={DSI3_SPI_IRQ_EN,DSI3_DSI_IRQ_EN,DSI3_IRQ_EN};
	   uint32_t snrmap;
	   uint16_t data;
	            US_SnrDrv_DSI3Trcv_Configuring = ME_TRUE;
				US_SnrDrv_registers_mismatch = ME_TRUE;
				data = 0;
				snrmap = US_SnrCfg_F_Get_SnrBusMap(US_ALL_POS);
				/*Disable IRQ_EN */
				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_INTB_EN[2],2,(uint8_t const*)&data,US_SnrDrv_E521_24_ProcessError);
				/*disable	DSI IRQ_EN */
				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_INTB_EN[1],2,(uint8_t const*)&data,US_SnrDrv_E521_24_ProcessError);
				/*disable	SPI IRQ_EN */
				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_INTB_EN[0],2,(uint8_t const*)&data,US_SnrDrv_E521_24_ProcessError);
				/*Clear IRQ,DSI IRQ,SPI IRQ FLAGS */
				(void)US_SnrDrv_Clr_DSI3INTB();
				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_INTB_EN[0],2,(uint8_t const*)&DSI3_REG_CHECK[0],US_SnrDrv_E521_24_ProcessError);    
				  /*0x0800 for OC. 0x2000 for UV */
				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_INTB_EN[1],2,(uint8_t const*)&DSI3_REG_CHECK[1],US_SnrDrv_E521_24_ProcessError);   
					  /*0xdc07;    0xc803 */
				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_INTB_EN[2],2,(uint8_t const*)&DSI3_REG_CHECK[2],US_SnrDrv_E521_24_ProcessError);   

				(void)US_SnrDrvMgr_F_SetDSIMasterRegCmd(snrmap,ZERO,DSI3_REG_PDCMPERIOD,2,(uint8_t const*)&DSI3_REG_CHECK[3],US_SnrDrv_E521_24_ProcessError); 
                 /* read register back to check if they are matched */
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_SPI_IRQ_EN,DSI3_INTB_EN[0],8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_DSI_IRQ_EN,DSI3_INTB_EN[1],8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_IRQ_EN,DSI3_INTB_EN[2],8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_PDCMPERIOD,DSI3_REG_PDCMPERIOD,8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_CTLR_REG,DSI3_CTLR_REG,8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);
				(void)US_SnrDrvMgr_F_ReqDSIMasterRegCmd(snrmap,READ_REG_DSI3_CFG_REG,DSI3_CFG_REG_CH0,8,(uint8_t*)dsi3_irqstat_reg,US_SnrDrv_E521_24_ProcessError);

}

/* ===========================================================================
 * Name:     US_SnrDrv_F_Cfg_DSI3TransceiverCmd
 * Remarks:  DD-ID: {E39956E2-3CF0-493e-AADF-016E45AEDC0C}
 * Traceability to source Code: Req.-ID:
 * ===========================================================================*/
static void US_SnrDrv_F_Cfg_DSI3TransceiverCmd(void)
{
    static uint16_t reset_try = 0,tries =0;
	  if(US_SnrDrv_DSI3Trcv_Configuring ==(uint8_t) ME_FALSE)   /* configure transceiver complete? */
      {
    	  if(US_SnrDrv_registers_mismatch != (uint8_t)ME_FALSE)  /* transceiver registers matched? */
    	  {
     		  if(reset_try < MAX_REG_MISMATCH_RETRY)           /* tried max times */
    		  {
     			 US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI3_registers_mismatch);
    			 US_SnrDrv_Transciver_State = (uint8_t)US_TRANSCEIVER_RESET;;   /* reset transceiver again*/
    			 reset_try++;
  		      }
    		  else   /* give up re-try */
    		  {
				if(US_SnrDrv_Transciver_State < ((uint16_t)0xFFFF))
				{
    				US_SnrDrv_Transciver_State ++;
				}
				else{
					/*  Overflow error handling  */
				}
    			  reset_try = ZERO;
    		  }
    	  }
    	  else   /* configure transceiver successful*/
    	  {
  			US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI3_registers_mismatch);
			if(US_SnrDrv_Transciver_State < ((uint16_t)0xFFFF))
			{
  				US_SnrDrv_Transciver_State ++;
			}
			else{
				/*  Overflow error handling  */
			}
   			reset_try = ZERO;

    	  }
    	  tries = 0;
      }
      else if(tries >= MAX_WAIT_DSI3TRCVR_CFG)            /*reach max waiting time */
      {
 			if(reset_try < MAX_REG_MISMATCH_RETRY)
 			{
    	      US_SnrDrv_Transciver_State = (uint16_t)US_TRANSCEIVER_RESET;  /* reset transceiver again*/
 			  reset_try++;
 			}
 			else
 			{
				if(US_SnrDrv_Transciver_State < ((uint16_t)0xFFFF))
				{
  			    	US_SnrDrv_Transciver_State ++;
				}
				else{
					/*  Overflow error handling  */
				}
				reset_try = 0;
 			}
 			 tries = 0;
      }
      else{
	      	  tries++;
      }
#if(US_CSM_ENABLE == ME_TRUE)
	if(US_SnrDrv_Transciver_State >= (uint16_t)US_TRANSCEIVER_MAX)
	{
		UsDsirTrcv_State = US_CSM_LOCAL_STATE_ACTIVE;
	}
#endif
}

/* ===========================================================================
 * Name:     US_SnrDrv_Trciver_Reset_task
 * Remarks:  DD-ID: {64ED0818-2CAA-438c-96B7-DE8A2BBD2E10}
 * Traceability to source Code: Req.-ID:
 * ===========================================================================*/
static void US_SnrDrv_Trciver_Reset_task(void)
{
	static const US_Trcver_ResetTable_t US_Trcver_ResetTable[] =
	{
		{(uint16_t)US_TRANSCEIVER_RESET,                       US_SnrDrv_F_Reset_DSI3TransceiverCmd},
		{(uint16_t)US_TRANSCEIVER_RELESE_RESET,                US_SnrDrv_F_ReleaseReset_DSI3TransceiverCmd},
		{(uint16_t)US_CFG_DSI3TRCVRREGISTERS,                  US_SnrDrv_F_Cfg_DSI3TransceiverCmd},
		{(uint16_t)US_TRANSCEIVER_MAX,                                            NULL}
	};

	if(US_SnrDrv_Transciver_State < (uint16_t)US_TRANSCEIVER_MAX)   /* in reset process*/
	{
		if(US_Trcver_ResetTable[US_SnrDrv_Transciver_State].US_Trcver_ResetTable_CfgFxn != NULL)
		{
			US_Trcver_ResetTable[US_SnrDrv_Transciver_State].US_Trcver_ResetTable_CfgFxn();
		}
	}
	
}


