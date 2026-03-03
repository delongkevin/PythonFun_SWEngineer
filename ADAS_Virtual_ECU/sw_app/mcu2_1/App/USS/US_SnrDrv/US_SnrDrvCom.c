/*
 * US_SnrDrvCom.c
 *
 *  Created on: Feb 18, 2021
 *      Author: e39960
 */
#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_SnrDrv.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SysMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"
#include "US_Ctrl_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Dsi3Trcv_CsmIf.h"
#include "Us_Platform_CsmIf.h"
#endif

#define TRCVR_STOP_CMD_ENABLE      (ME_TRUE)

#define US_SNRDRVCOM_CMD_TIMEOUT   (100U)         /*200ms for cmd timeout */
#define DATA_LEN_PERIOD            (90U)
#define MAX_DSI_MASTER_WAIT        (0x8000U)
#define DSI_HW_ERROR               (0xA288U)     /*CLKREF_ERR,DSI_0_UV,VCCUV_RFCB,DSI_1_UV,OT */
#define PDCM_HEAD_SIZE             (8u)
#define DSI3_ERROR_MASK            (DSI_HW_ERROR) 

#if (QAC_WARNING_FIX  ==  ME_FALSE) 
#define DSI_CMD_ERROR              (0x4107)    /*DSI_1_CMD_OVER,DSI_0_CMD_OVER,CMD_INC,CRC_ERR,UND_CMD */
#define PDCM_ERROR                 (0x3C00)    /*ND,OR,DL,PC */
#define DSI_1_CMD_OVER_BIT         (BIT14)
#define DSI_0_CMD_OVER_BIT         (BIT8)
#endif

#define MAX_NUMBER_SENSOR_ON_BUS     (SIX)

#define     DSI3_SPI_UNDCMD                               (BIT0)
#define     DSI3_SPI_CRC                                  (BIT1)
#define     DSI3_SPI_CMDINC                               (BIT2)
#define     DSI3_SPI_CLKREF                               (BIT3)

#define     DSI3_CH0_UV                                   (BIT7)
#define     DSI3_CH0_CMDOVR                               (BIT8)
#define     DSI3_VCCUV_RFC                                (BIT9)
#define     DSI3_CH1_UV                                   (BIT13)
#define     DSI3_CH1_CMDOVR                               (BIT14)
#define     DSI3_OV_TEMP                                  (BIT15)

#define BIT_MSK_SC                                        (BIT3)
#define BIT_MSK_SE                                        (BIT2)
#define BIT_MSK_UV                                        (BIT1)
#define BIT_MSK_CE                                        (BIT0)

#define DSI3_CH0_DATA_ERR_SHIFT     (3u)
#define DSI3_CH1_DATA_ERR_SHIFT     (6u)

static volatile uint16_t US_SnrDrvCom_timeout_timer;
static volatile US_SnrDrvCom_CmdState_t US_SnrDrvCom_CmdState;
static US_SnrDrvCom_Cmd_t US_SnrDrvCom_V_ExecCmd,US_SnrDrvCom_V_CmdQueue[MAX_USS_DRV_CMD];
static uint8_t US_SnrDrvCom_QueueHeader,US_SnrDrvCom_Queuetail,US_SnrDrvCom_QueueState,DeQueueDelay,Burst_nPDCM =0,Burst_Period;
static US_SemaphoreHandle_t US_SnrDrvCom_xSemaphore;
static US_S_SensorsCfg_t const *pSnrCfg = NULL;
static volatile uint16_t US_SnrDrvCom_state;
static uint16_t US_SnrDrvCom_V_PDCM_datalen[FOUR],SPI_Data[EIGHT];
static uint8_t DevMask,Bus_Map_Snr, SnrResp[FOUR],US_SnrDrvCom_V_CRM[MAX_DSI3_BUS/TWO][TEN][TEN];

static uint8_t spi_DMA_state[FOUR] = {ZERO,ZERO,ZERO,ZERO};
static uint16_t US_DrvDSI3Err_Count = ZERO;

#if(US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
#define MAX_ELMOS_SPI_DEV          (2u)
#else
#define MAX_ELMOS_SPI_DEV          (1u)
#endif
static uint32_t DSI3Drv_Snd_Buf[MAX_ELMOS_SPI_DEV][DSI3DRV_SEND_BUFFER_SIZE/FOUR] __attribute__ ((aligned (128)));
static uint32_t DSI3Drv_Rcv_Buf[MAX_ELMOS_SPI_DEV][DSI3DRV_RECEIVE_BUFFER_SIZE/FOUR] __attribute__ ((aligned (128)));
static uint8_t pdcm_delay = 0u;
void US_SPIDMA_ByEvent(uint8_t dev,uint8_t* Data,uint16_t inLen,uint16_t outLen);
static void US_DSI3Drv_SetBusChn(uint8_t dev,uint8_t value);
static uint8_t* US_SnrDrvCom_F_DSI3Drv_Snd(uint8_t nDev,uint8_t const *buffer, uint16_t inLen,uint16_t outLen);

static const US_SnrDrvCom_CmdTable_t US_SnrDrvCom_CmdTable[] =
{
        /*    Cmd,                           dcm period per snr,           Wait time,        packet size           data length per snr,          No BRC                  start addr          */
        {REQ_SENSOR_FW_VER,                       147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_FC,                           147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_NORMAL_BURST_NUMBER,          147u,                  2u,                 8u,                       2u,                        1u,                     13u},
        {REQ_SENSOR_CHIRP_BW,                     147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_RINGINGCOMPARATOR,            147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_BURST_TYPE_CONFIG,            147u,                  2u,                 8u,                       4u,                        1u,                     12u},
        {REQ_SENSOR_CURRENT_CFG,                  147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_GAIN,                         147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_G_CAL,                        147u,                  2u,                 8u,                       2u,                        1u,                     13u},
        {REQ_SENSOR_ENVELOPE_CONFIG,              147u,                  2u,                 8u,                       2u,                        1u,                     13u},
        {REQ_SENSOR_ENVELOPE_FILTER_CONFIG,       147u,                  2u,                 8u,                       4u,                        1u,                     12u},
        {REQ_SENSOR_MAX_ECHO_NUMBER,              147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_ATG,                          147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_AATG1,                        147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_AATG2,                        147u,                  2u,                 8u,                       3u,                        1u,                     13u},
        {REQ_SENSOR_FTC,                          147u,                  2u,                 8u,                       2u,                        1u,                     13u},
        {REQ_SENSOR_STC,                          147u,                  2u,                 10u,                       5u,                        1u,                     13u},
        {REQ_SENSOR_STG,                          147u,                  2u,                 11u,                       6u,                        1u,                     13u},       /*??? */
        {REQ_SENSOR_FIX_PATH_CFG,                 147u,                  2u,                 8u,                      2u,                      1u,                     13u},
        {REQ_SENSOR_NFD,                          (147u+72u),             2u,                 12u,                      6u,                    1u,                     13u},     /*??? */
        {REQ_SENSOR_EDI_CHANNEL,                  (147u+36u),             2u,                 10u,                      4u,                    1u,                     13u},
        {REQ_SENSOR_OUTPUT_SIGNAL_SEL,            99u,                   2u,                 52u,                      2u,                     1u,                     13u},
        {REQ_SENSOR_OUTPUT_SIGNAL_DATA,           1000u,                  2u,                 48u,                      43u,                   20u,                     13u},
        {REQ_SENSOR_ID,                           (147u+36u),             2u,                 10u,                      5u,                    1u,                     13u},
        {REQ_SENSOR_AMBIENT_TEMPATURE,            147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_REGISTER,                     147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_EEPROM,                       147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_OPERATION_MODE,               147u,                  2u,                 8u,                       2u,                     1u,                     13u},
        {REQ_SENSOR_TEMPATURE,                    147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_FREQUENCY,                    (147u+36u),             2u,                 10u,                      5u,                    1u,                     13u},
        {REQ_SENSOR_RESULT,                       147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_PROFILE,                      (180u+75u),             2u,                 14u,                      9u,                    1u,                     13u},
        {REQ_SENSOR_PROFILE_PLUS,                 147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_GANA_MEAS_BEGIN,              (147u+36u),             2u,                 10u,                     4u,                     1u,                     13u},
        {REQ_SENSOR_SNR_DIAGNOSTIC_RESULT_F11A,   (147u+150u),            2u,                 12u,                     7u,                     1u,                     13u},
        {REQ_SENSOR_SNR_DIAGNOSTIC_RESULT,        (147u+150u),            2u,                 16u,                     11u,                    1u,                     13u},
        {REQ_SENSOR_EEFLAG_VARCTRL,               147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {REQ_SENSOR_CPS_MEAS_GAIN,                (147u+(72u*3u)),           2u,                 20u,                      14u,                  1u,                     13u},
        {REQ_SENSOR_STOP_MEASUREMENT,             147u,                  2u,                 8u,                       5u,                     1u,                     13u},
        {REQ_SENSOR_RFM_CTRL,                     (147u+36u),             2u,                 10u,                      4u,                    1u,                     13u},
        {REQ_SENSOR_EEVAL_SENS_MEAS,              (147u+36u),             2u,                 10u,                      4u,                    1u,                     13u},
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
        {REQ_SENSOR_DETECTION_SAME_MEASUREMENT,   1700u,                 2u,                12u,                       7u,                    20u,                     13u},
        {REQ_SENSOR_DETECTION_INDIVIDUAL_MEASUREMENT,   1700u,           2u,                12u,                       5u,                    20u,                     13u},
        {REQ_SENSOR_DETECTIPON_QUICK,             1700u,                 2u,                12u,                       7u,                    20u,                     13u},
#else
        {REQ_SENSOR_DETECTION_SAME_MEASUREMENT,   2000u,                 2u,                12u,                       7u,                    20u,                     13u},
        {REQ_SENSOR_DETECTION_INDIVIDUAL_MEASUREMENT,   2000u,           2u,                12u,                       5u,                    20u,                     13u},
        {REQ_SENSOR_DETECTIPON_QUICK,             2000u,                 2u,                12u,                       7u,                    20u,                     13u},
#endif
        {REQ_SENSOR_AD_VOLTAGE,                   147u,                  2u,                 8u,                       3u,                     1u,                     13u},
        {0u,                                        0u,                    0u,                 0u,                       0u,                    0u,                       0u}
};


static uint32_t US_SnrDrvCom_F_ProcessCRM(US_SnrDrvCom_Cmd_t const *cmd);
static void US_SnrDrvCom_F_ProcessCmd(void);
static uint16_t US_SnrDrvCom_F_DeCmdQueue(US_SnrDrvCom_Cmd_t *Cmd);
static uint32_t US_SnrDrvCom_F_EnCmdQueue(uint32_t SnrMap,uint32_t UserData,uint32_t CmdID,uint16_t SndSize,uint8_t *SndData,uint16_t RcvSize,uint8_t *RcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
static uint16_t US_SnrDrvCom_F_SwapHL(uint8_t* ptr, uint16_t length);
static uint16_t US_SnrDrvCom_F_SPI_CRC(uint8_t const *ptr, uint16_t len);
static uint32_t US_SnrDrvCom_F_StartPDCM(US_SnrDrvCom_Cmd_t const *cmd);
static uint32_t US_SnrDrvCom_F_ProcessBRCCMD(US_SnrDrvCom_Cmd_t const *cmd,uint16_t nBRC,uint16_t pdcm_len);
static void US_SnrDrvCom_F_SPI_SndData(uint16_t nDev,uint8_t type,uint8_t chn,uint8_t nCnt,uint16_t len,uint8_t const *data);
static void US_SnrDrvCom_F_SPIReadMasterData(uint8_t dev,uint8_t chn);
static uint32_t US_SnrDrvCom_F_ProcessPDCMData(uint8_t dev,uint8_t nBurst,US_SnrDrvCom_Cmd_t const *cmd,uint8_t *pRcv);

/* bus/chn */
static uint8_t US_DSI3Drv_buschn[FOUR]  = {ZERO,ZERO,ZERO,ZERO};
/* bus flag*/
static uint8_t US_DSI3Drv_cur_busflag[FOUR]  = {ZERO,ZERO,ZERO,ZERO};
#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
/* ===========================================================================
 * Name:     US_SnrDrvCom_GetDSI3ErrCnt
 * Remarks:  DD-ID:{7C39C016-5D4C-455e-B0FB-91AA28ED553A}
 * Traceability to source Code: Req.-ID: 13427737
 * Req.-ID: 19487922
 * ===========================================================================*/

uint16_t US_SnrDrvCom_GetDSI3ErrCnt(void)
{
	return US_DrvDSI3Err_Count;
}
#endif
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_DSI3Drv_GetSpiSndBuffer.
* used to get Spi Send buffer.
* \param None
*  \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_DSI3Drv_GetSpiSndBuffer
 * Remarks:  DD-ID: {6056A417-C65B-423a-8A27-83BA07175795}
 * ===========================================================================*/
uint8_t *US_DSI3Drv_GetSpiSndBuffer(void)
{

	return (uint8_t*)DSI3Drv_Snd_Buf[ZERO];
}
/* ===========================================================================*/
/**US_DSI3Drv_GetSpiRcvBuffer.
* used to get Spi Receive  buffer.
* \param None
*  \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_DSI3Drv_GetSpiRcvBuffer
 * Remarks:  DD-ID: {5633255E-D1D2-4419-B400-B4EA34C800B7}
 * ===========================================================================*/
uint8_t *US_DSI3Drv_GetSpiRcvBuffer(void)
{

	return (uint8_t*)DSI3Drv_Rcv_Buf[ZERO];
}
#endif 
/* ===========================================================================*/
/**DSI3Drv_SetCurBusFlag.
* used to set up DSI3 bus Data state flag.
* \param dev: Master DSI3 device Id, value: bus flag
*  \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_DSI3Drv_SetCurBusFlag
 * Remarks:  DD-ID: {1748E8C2-FEA6-45cd-ACA0-43D1D7EC68FA}
 * ===========================================================================*/
void US_DSI3Drv_SetCurBusFlag(uint8_t dev,uint8_t value)
{
    if(dev <= DevMask)
	{
	  US_DSI3Drv_cur_busflag[dev] |=  value;
	}
	else
	{
	}
}
/* ===========================================================================*/
/**DSI3Drv_GetCurBusFlag.
* used to get current bus flag.
* \param dev: Master DSI3 device Id
* \return : current bus flag
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_DSI3Drv_GetCurBusFlag
 * Remarks:  DD-ID: {C268840D-6A34-4627-AC93-B25A022AD68F}
 * ===========================================================================*/
uint8_t US_DSI3Drv_GetCurBusFlag(uint8_t dev)
{
	uint8_t ret =ZERO;
    if(dev <= DevMask)
	{
	  ret =US_DSI3Drv_cur_busflag[dev];
	}
	else
	{
	}
	return ret;
}
/* ===========================================================================*/
/**DSI3Drv_SetBusChn.
* used to set device DSI3 bus state.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_DSI3Drv_SetBusChn
 * Remarks:  DD-ID: {17ADCB93-A689-477e-91B7-08970DCB508B}
 * ===========================================================================*/
static void US_DSI3Drv_SetBusChn(uint8_t dev,uint8_t value) 
{
    if(dev <= DevMask)
	{
	US_DSI3Drv_buschn[dev] =  value;
	}
	else
	{
	}
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**US_DSI3Drv_GetBusChn.
* used to Get device DSI3 bus state.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_DSI3Drv_GetBusChn
 * Remarks:  DD-ID: {42B7DD8B-8F13-44f5-8DD7-943BD911D345}
 * ===========================================================================*/
uint8_t US_DSI3Drv_GetBusChn(uint8_t dev)
{
    uint8_t ret = ZERO;
	if(dev <= DevMask)
	{
      ret = US_DSI3Drv_buschn[dev];
	}
	return ret;
}
#endif 
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SwapHL
 * used to swap High/low bytes.
 * Remarks:  DD-ID: {6C879718-83F3-4265-A81D-961865FA0D96}
 * ===========================================================================*/
static uint16_t US_SnrDrvCom_F_SwapHL(uint8_t* ptr, uint16_t length)
{
	uint16_t ret = ME_OK;
	uint16_t i;
	uint8_t temp;

    if ((length%2u) != 0u)   /* make sure word align */
    {
        ret = ME_NOT_OK;
    }
    else
    {
        for (i=0u;i<length;i=i+2u)     /* swap High/low bytes */
        {
            temp = ptr[i];
            ptr[i] = ptr[i+1u];
            ptr[i+1u] = temp;
        }
    }

	return ret;
}

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SPI_CRC
 * Used to calculate SPI TX/RX data CRC
 * Remarks:  DD-ID: {FB8D4C55-81AE-41c2-910D-B4B440C34C09}
 * Req.-ID: 16134166
 * ===========================================================================*/
static uint16_t US_SnrDrvCom_F_SPI_CRC(uint8_t const *ptr, uint16_t len)
{
   /* CRC seed */
   static const uint16_t US_SnrDrvCom_crc_table[SIXTEEN] =  
   {0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef};

   uint16_t temp_length, crc = 0xFFFFu;
   uint8_t const *temp_ptr;
    uint8_t crc_H4; 
    
    temp_length = len;
    temp_ptr = ptr;

    while(temp_length!= 0u)   /* make sure data length >0 */
    {
       temp_length--;
        crc_H4 = (uint8_t)(crc >> 12u);
        crc = (uint16_t)((crc << 4u) & 0xffffu);
        crc = crc ^ US_SnrDrvCom_crc_table[ crc_H4 ^ (*temp_ptr >> 4u)];
        crc_H4 = (uint8_t)(crc >> 12u);
        crc = (uint16_t)((crc << 4u) & 0xffffu);
        crc = crc ^ US_SnrDrvCom_crc_table[ crc_H4 ^ (*temp_ptr & 0x0fu)];
        temp_ptr++;
    }

	return(crc);
}

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_DSI3Drv_Snd
 * Remarks:  DD-ID: {3D9A8864-AE36-4000-9AE5-77D2777C34DB}
 * ===========================================================================*/
static uint8_t* US_SnrDrvCom_F_DSI3Drv_Snd(uint8_t nDev,uint8_t const *buffer, uint16_t inLen,uint16_t outLen)
{
	uint16_t crc,cnt;
    uint8_t  *pSrc,*ret = NULL;
    if((nDev < MAX_ELMOS_SPI_DEV)&&(spi_DMA_state[nDev]==ZERO))
    {
        pSrc    =  (uint8_t*)DSI3Drv_Snd_Buf[nDev];
        for(cnt = ZERO;cnt < inLen; cnt++)
        {
            pSrc[cnt]  = buffer[cnt];
        }
        crc = US_SnrDrvCom_F_SPI_CRC(pSrc,inLen);        /* Calculate CRC */
        /*KPK-QAC Fix : Need to suppress, Intended implemetation */
        pSrc[inLen]  = (uint8_t)((crc>>8u)&(0xffu));      /* put CRC into send buffer */
        pSrc[inLen+1u]  = (uint8_t)(crc&0xffu);

        (void)US_SnrDrvCom_F_SwapHL(pSrc, inLen+FOUR);    /* swap High/Low byte for Big endian */ 
        (void)memset((uint8_t*)DSI3Drv_Rcv_Buf[nDev],0,TWENTY);   /*clear header in Receive buffer  */  
        US_DSI3Drv_cur_busflag[nDev] = ZERO;
        if(US_SnrDrvCom_state != (uint16_t)ZERO)   /* make sure command is not canceled */
        {
		    /* Trigger SPI DMA  */
            (void)US_DSI3Drv_triggerDmaSpiTxRx(nDev,(uint8_t*)DSI3Drv_Snd_Buf[nDev],(uint8_t*)DSI3Drv_Rcv_Buf[nDev],((uint32_t)outLen+FOUR));
        }
        ret = (uint8_t*)DSI3Drv_Rcv_Buf;
    }
    return ret; 
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SetDequeueDelay,interface function.
* used to Setup delay time for dequeue
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SetCalCfg
 * Remarks:  DD-ID: {89B96B23-71B2-42e1-BCD9-86B041A06AF8}
 * ===========================================================================*/
void US_SnrDrvCom_F_SetCalCfg(void)
{
    uint16_t cnt;
    pSnrCfg = US_SnrCfg_F_Get_SnrCfg();
    Bus_Map_Snr = ZERO;
    for(cnt = ZERO;cnt < pSnrCfg-> Max_nSnr_ON_SINGLE_BUS; cnt++)
    {
        Bus_Map_Snr |= (BIT0<<cnt);
    }
    DevMask = ((pSnrCfg->nBusCfg)/TWO) - ONE;
}

/* ===========================================================================*/
/**US_SnrDrvCom_F_Set_BurstnPDCM,interface function.
* used to Setup num od PDCM for Burst cmd
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_Set_BurstnPDCM
 * Remarks:  DD-ID:{D1D0CFF8-A6CD-4d66-913A-FCA1D3755397}
 * ===========================================================================*/
void US_SnrDrvCom_F_Set_BurstnPDCM(uint8_t nPDCM,uint8_t period)
{
	Burst_nPDCM = nPDCM;
	Burst_Period = period;
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SetDequeueDelay,interface function.
* used to Setup delay time for dequeue
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SetDequeueDelay
 * Remarks:  DD-ID: {BB632A47-2625-4a6f-B994-DAFC3E3B65E9}
 * ===========================================================================*/
void US_SnrDrvCom_F_SetDequeueDelay(uint8_t delay)
{
	DeQueueDelay = delay;
}
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_AddAdditionalDequeueDelay
 * Remarks:  DD-ID: {20B756D7-3734-40dc-A663-EBB186A6E857}
 * ===========================================================================*/
void US_SnrDrvCom_F_AddAdditionalDequeueDelay(uint8_t delay)
{
	DeQueueDelay += delay;
}
/* ===========================================================================*/
/**Uss_Drv_Init,interface function.
* used to initialize UssDrv module hardware and parameters
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_Init
 * Remarks:  DD-ID: {B7336088-3BEB-4eb5-8EC5-413AF597FF48}
 * Req.-ID: 13396023
 * ===========================================================================*/
uint16_t US_SnrDrvCom_F_Init(void)
{
    /* initialize Uss drv queue */
    US_SnrDrvCom_CmdState.CmdState = (uint64_t)CMD_IDLE;
    US_SnrDrvCom_state    =  (uint16_t)CMD_IDLE;
    US_SnrDrvCom_QueueHeader = ZERO;
    US_SnrDrvCom_Queuetail   = ZERO;
    US_SnrDrvCom_QueueState  = ME_EMPTY;
    /* initialize Current cmd */
    US_SnrDrvCom_V_ExecCmd.CmdID       = ZERO;
    US_SnrDrvCom_V_ExecCmd.SnrMap      = ZERO;
    DeQueueDelay = ZERO;
    US_SnrDrvCom_timeout_timer        = ZERO;
    US_DrvDSI3Err_Count               = ZERO;
     (void)memset(DSI3Drv_Snd_Buf,0,(MAX_ELMOS_SPI_DEV*DSI3DRV_SEND_BUFFER_SIZE));
    (void)memset(SPI_Data,0,(EIGHT*sizeof(uint16_t)));
    (void)memset(SnrResp,0,FOUR);  
    if(pSnrCfg == NULL)
    {
        Bus_Map_Snr = ZERO;
        DevMask = ZERO;
    }
    US_SnrDrvCom_xSemaphore = US_SemaphoreCreate(ONE);
    return ME_OK;
}

/* ===========================================================================*/
/**USS_Drv_Task,interface function.
* used to process command from cmd queue, called by schedule task.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_Task
 * Remarks:  DD-ID: {61120E0F-B224-44c2-B3BC-6C06ECFA0CC2}
 * Req.-ID: 13389468
 * ===========================================================================*/
void US_SnrDrvCom_F_Task(void) 
{
     uint32_t error;
	 void (*pCallback)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);

		US_SnrDrvCom_timeout_timer = US_SnrDrvCom_timeout_timer + 1u;
		error = ZERO;
	switch((US_SnrDrv_cmdstate_t)US_SnrDrvCom_state)
		{
		case CMD_IDLE:
			US_SnrDrvCom_timeout_timer =ZERO;
		    US_SnrDrvCom_F_ProcessCmd();    /* dequeue from Command queue */
			break;
		case CMD_EXEC_CRM:
			break;
		case CMD_EXEC_PDCM:

			if(pdcm_delay > ZERO)     /* delay for starting PDCM*/
			{
				pdcm_delay--;
			}
			else
			{
				error = US_SnrDrvCom_F_StartPDCM(&US_SnrDrvCom_V_ExecCmd);    /* start PDCM pulse, it returns error when data buffer is not enough */
			}
			break;
		default:
                /* empty */
			break;
		}
		if(DeQueueDelay > ZERO)       /*App can setup it only previous Burst cmd is completed */
		{
		   DeQueueDelay --;
		}
        if(US_SnrDrvCom_timeout_timer >= (uint16_t)US_SNRDRVCOM_CMD_TIMEOUT)  /* if command timeout happens */ 
        {
            error = ERROR_US_SNRDRVCOM_CMD_TIMEOUT;
		}else{}
		
		if(error != ZERO)    /* exit command if error happens */
		{
 		   US_DrvDSI3Err_Count++;   
			pCallback = US_SnrDrvCom_V_ExecCmd.CallBack;
			if(pCallback != NULL)
			{
			     US_SnrDrvCom_V_ExecCmd.CallBack = NULL;	
			     if(US_SnrDrvCom_state !=(uint16_t) ZERO)
			     {
			         (*pCallback)(error,US_SnrDrvCom_V_ExecCmd.CmdID,US_SnrDrvCom_V_ExecCmd.UserData, US_SnrDrvCom_V_ExecCmd.RcvSize,US_SnrDrvCom_V_ExecCmd.RcvData);
		         }
	    	}
        	US_SnrDrvCom_timeout_timer = ZERO;
		    US_SnrDrvCom_V_ExecCmd.CallBack = NULL;
        	US_SnrDrvCom_V_ExecCmd.SnrMap = ZERO;
    		US_SnrDrvCom_V_ExecCmd.CmdID = ZERO;
			US_SnrDrvCom_CmdState.CmdState = ZERO;
    		US_SnrDrvCom_state = ZERO;
        }
	
}

/* ===========================================================================*/
/**Uss_Cmd_Snd,interface function.
* used to get command from higher layer and put it to cmd queue, called by higher layer.
* \param: SnrMap,CmdID,SndSize,,SndData[],RcvSize, RcvData[], *CallBack()
* \return: successful or fail
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_CmdSnd
 * Remarks:  DD-ID: {1A2A5081-7265-47eb-8F2A-F857AB2328AE}
 * Req.-ID: 13411731
 * ===========================================================================*/
uint32_t US_SnrDrvCom_F_CmdSnd(uint32_t SnrMap,uint32_t UserData,uint32_t CmdID,uint16_t SndSize,uint8_t *SndData,uint16_t RcvSize,uint8_t *RcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData)) 
{
    uint32_t ret = ME_OK;
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN)
   bool_t  bPlaybackMode   = UssCtrl_bIsSysInPlaybackMode();
  UssMgr_e_SysState_t SysState  =  UssMgr_eGetSysState();

    if( (bPlaybackMode == (bool_t)ME_FALSE) || ((bPlaybackMode == (bool_t)ME_TRUE) && ((SysState != SYSMGR_SYS_READY)&& (SysState != SYSMGR_SYS_DIAGNOSTIC))))
#endif
	{
        ret = US_SnrDrvCom_F_EnCmdQueue(SnrMap,UserData,CmdID,SndSize,SndData,RcvSize,RcvData,CallBack);
        US_SnrDrvCom_F_ProcessCmd();
    }

    return ret;
}

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SndRcvDSIMasterCMD
 * Remarks:  DD-ID: {5054C22C-8943-403e-891C-F97884CFCD41}
 * ===========================================================================*/

static uint32_t US_SnrDrvCom_F_SndRcvDSIMasterCMD(uint8_t nDev,uint16_t CmdID,uint16_t *CurSnd,uint16_t SndSize,uint8_t const* SndData,uint16_t Bus,uint16_t RcvSize,uint8_t* RcvData)
{
    uint8_t data[TEN],SPI_Cmd,Cmd;
    uint8_t const *pRcvbuf;
    uint16_t len; 
    uint32_t ret = ME_OK;
    (void) RcvSize;
    data[ZERO]          =   (uint8_t)((CmdID>>8) & 0xffu);     /*Low*/
    data[ONE]          =   (uint8_t)(CmdID & 0xffu);          /*cmd and CRC on */
    len = FOUR;

    SPI_Cmd = (uint8_t)((CmdID & DSI_CMD_MASTER_REG_MASK) >> EIGHT);
    if(SPI_Cmd == DSI_CMD_WRITE_MASTER_REG8)                /* Write Transceiver register */
    {
        if((SndSize & BIT15) != ZERO)
        {
            if(((*CurSnd) + ONE) < SndSize)                 /*check if send data is enough */
            {
                data[THREE]   = SndData[(*CurSnd)];
                (*CurSnd)++;
                data[TWO]   = SndData[(*CurSnd)];
              (*CurSnd)++;
            }
            else
            {

                ret     =      ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH;
            }
        }
        else
        {
            data[THREE]   = SndData[(*CurSnd)];
            data[TWO]   = SndData[(*CurSnd)+ ONE];
        }

    }

    if(ret     ==  ME_OK)
    {

		  US_SnrDrvCom_F_SPI_SndData(nDev,SPI_Cmd,THREE,ONE,len,data);
		  ret  = ZERO;
         
          do{
                           Cmd = US_SnrDrvCom_CmdState.Dev[nDev].SPI_CMD;        	  
                           ret++;
          } while((Cmd  != (uint8_t)ZERO)&&(ret <(uint32_t) MAX_DSI_MASTER_WAIT));
          ret     =  ME_OK;
          if(Cmd == (uint8_t)ZERO )
          {
       		  pRcvbuf   = (uint8_t*)DSI3Drv_Rcv_Buf[nDev];
      		  if(SPI_Cmd == DSI_CMD_READ_MASTER_REG8)
        	  {
                RcvData[((uint16_t)nDev*FOUR) + (Bus*TWO)]   = pRcvbuf[4];
                RcvData[((uint16_t)nDev*FOUR) + (Bus*TWO) + ONE]   = pRcvbuf[5];
          	    ret  = (((uint32_t)pRcvbuf[1] & 0xa0u)<<TWO)|(((uint32_t)pRcvbuf[0]>>THREE)&BIT4)|BIT1;
        	  }
       		  else
       		  {
       		  }
          }
          else
          {
      
            ret = (uint32_t)DIAG_FLAG_ECU_MAX_CODE;    /*TODO-KPK-Need to confirm the reason mapped is correct?*/
          }
	  }
	   return ret;
  }
/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessDSIMasterCMD.
* \used to process read/write Transceiver register command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_ProcessDSIMasterCMD
 * Remarks:  DD-ID: {8B413852-B866-4314-8ACC-CAD51A44F107}
 * ===========================================================================*/
static uint16_t US_SnrDrvCom_F_ProcessDSIMasterCMD(US_SnrDrvCom_Cmd_t *cmd)
{
uint8_t const *SndData;
uint8_t cnt,map,*RcvData;
uint32_t SnrMap;
uint16_t SndSize,RcvSize,CmdID,temp, pnSnd,pnRcv;
uint32_t ret = ME_OK;
void (*pCallback)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData); /* call back function prototype*/

CmdID  = (uint16_t)((cmd->CmdID) & 0xffffu);
SnrMap = cmd->SnrMap;
SndSize = cmd->SndSize;
SndData = cmd->SndData;
RcvSize = cmd->RcvSize;
RcvData = cmd->RcvData;

pnSnd  = ZERO;
pnRcv  = ZERO;
if(SnrMap != ZERO)   /* SnrMap should be zero, zero --- No need to read/write*/
{
    for(cnt = ZERO; ((cnt< RcvSize) && (cnt <TWO)); cnt++)
    {
        RcvData[cnt] = ZERO;
    }
    for(cnt = ZERO; cnt < pSnrCfg->nBusCfg; cnt++)     /*check bus configure */
    {
        map   = (uint8_t)((SnrMap >> ((pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * cnt))& Bus_Map_Snr);
        if(map != 0u)   /*cmd apply to this bus */
        {
            if((cnt%TWO)!= 0u)
            {
                if (((CmdID & (~DSI_CMD_MASTER_REG_MASK))>=DSI3_CH1_BASE)&&((CmdID & (~DSI_CMD_MASTER_REG_MASK))<DSI3_CH2_BASE))
                {
                    temp                         =    CmdID +   DSI3_CH2_OFFSET;
                    ret = US_SnrDrvCom_F_SndRcvDSIMasterCMD(cnt/TWO,temp,&pnSnd,SndSize,SndData,((uint16_t)cnt%TWO),RcvSize,RcvData+TWO); /* rear bus */
                }
                else
                {
                    ret = ME_OK;
                }
            }
            else
            {
                ret = US_SnrDrvCom_F_SndRcvDSIMasterCMD(cnt/TWO,CmdID,&pnSnd,SndSize,SndData,((uint16_t)cnt%TWO),RcvSize,RcvData+TWO);    /* front bus*/
            }
            if((ret != ME_OK)&&((ret & 0x0fu) != TWO))  /* only one register */
            {
                break;
            }
            pnRcv += (uint16_t)(ret & 0xfu);
           	ret &= (~0xfu);
        }
    }
    if(((CmdID & DSI_CMD_MASTER_REG_MASK) == DSI_CMD_READ_MASTER_REG)&&(RcvSize > TWO))   /* Read command */
    {
        RcvData[ZERO]  = (uint8_t)(pnRcv & 0xffu);
        RcvData[ONE]   = (uint8_t)((pnRcv>>8u) & 0xffu); 
    }
    if(US_SnrDrvCom_state == (uint16_t)CMD_EXEC_OP_MASTER_IC)
    {
        pCallback = cmd->CallBack;
        US_SnrDrvCom_V_ExecCmd.CallBack = NULL;    
        if(pCallback != NULL)
        {
            if(US_SnrDrvCom_state !=(uint16_t) ZERO)
            {
                (*pCallback)(ret,US_SnrDrvCom_V_ExecCmd.CmdID,US_SnrDrvCom_V_ExecCmd.UserData,US_SnrDrvCom_V_ExecCmd.RcvSize,US_SnrDrvCom_V_ExecCmd.RcvData);
            }
        }
        US_SnrDrvCom_timeout_timer = ZERO;
        cmd->SnrMap = ZERO;
        cmd->CmdID = ZERO;
        US_SnrDrvCom_state = ZERO;
        US_SnrDrvCom_CmdState.CmdState = ZERO;
        ret = ME_OK;
    }
}
else    /* do nothing, return*/
{
    ret = ME_OK;
    pCallback = cmd->CallBack;
    US_SnrDrvCom_V_ExecCmd.CallBack = NULL;
    if(pCallback != NULL)
    {
        if(US_SnrDrvCom_state != (uint16_t)ZERO)
        {
            (*pCallback)(ret,US_SnrDrvCom_V_ExecCmd.CmdID,US_SnrDrvCom_V_ExecCmd.UserData,US_SnrDrvCom_V_ExecCmd.RcvSize,US_SnrDrvCom_V_ExecCmd.RcvData);
        }
    }
    US_SnrDrvCom_timeout_timer = ZERO;
    cmd->SnrMap = ZERO;
    cmd->CmdID = ZERO;
    US_SnrDrvCom_state = ZERO;
    US_SnrDrvCom_CmdState.CmdState = ZERO;

}
return (uint16_t)ret;
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessPDCMCMD.
* used to count total sensors for configured or installed.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_CountSnr
 * Remarks:  DD-ID: {1B6ADEE4-12B0-4671-822E-6F49A83BE653}
 * Req.-ID: 13473277
 * ===========================================================================*/
uint16_t US_SnrDrvCom_F_CountSnr(uint8_t nBus,uint8_t *nSnrBus,uint8_t *TotalSnr,uint32_t SnrMap,uint8_t isActual)
{
    uint8_t map,cnt,i,MaxSnr,SnrCnt,nSnr,nCfg, temp_Actual;
    MaxSnr = ZERO;
    SnrCnt  = ZERO;
    if(isActual > ONE)     /* zero = configured, else installed*/
    {
        temp_Actual = ONE;
    }
    else
    {
        temp_Actual = isActual;
    }
    for(cnt = ZERO; ((cnt < pSnrCfg->nBusCfg) && (cnt < nBus)); cnt++)     /*check bus configure */
    {
        map   = (uint8_t)((SnrMap >> ((pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * cnt))& Bus_Map_Snr);   /*get snr map on single bus */
        nSnr  = ZERO;
        nCfg  = US_SnrCfg_F_Get_nSensor(cnt, NULL,temp_Actual);
        for(i=ZERO; ((i< (pSnrCfg->Max_nSnr_ON_SINGLE_BUS)) && (i< nCfg)); i++)
        {
            if(((map>>i)&BIT0)!= 0u)
            {
                SnrCnt ++;
                nSnr++;
            }
        }
        if(MaxSnr <nSnr)
        {
            MaxSnr = nSnr;
        }
        if(nSnrBus != NULL)
        {
            *nSnrBus = nSnr;
        }
    }
    if(TotalSnr != NULL)
    {
        *TotalSnr = SnrCnt;
    }
    return MaxSnr;
}

/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessBRCCMD.
* used to process BRC command .
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_ProcessBRCCMD
 * Remarks:  DD-ID: {11E412BD-65DC-4a9d-A07A-26F4F8E8892A}
 * ===========================================================================*/

static uint32_t US_SnrDrvCom_F_ProcessBRCCMD(US_SnrDrvCom_Cmd_t const *cmd,uint16_t nBRC,uint16_t pdcm_len)
{
	uint8_t cnt,map,ch0Snr,ch1Snr, SPI_Cmd,chn,data[MAX_DSI3_BUS/TWO][TEN];
	uint32_t SnrMap,ret = ME_OK;
	uint16_t len;

    ch0Snr  = ZERO;
    ch1Snr  = ZERO;
    SPI_Cmd  = (uint8_t)(((cmd->CmdID)>>EIGHT) & 0xffu);
    SnrMap = cmd->SnrMap;
    chn    = ZERO;
    for(cnt = ZERO; cnt < pSnrCfg->nBusCfg; cnt++)     /*check bus configure */
    {
        map   = (uint8_t)((SnrMap >> ((pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * cnt))& Bus_Map_Snr);
        if(map != 0u)   /*cmd apply to this bus */
        {
            if( (cnt%TWO) != 0u  )   /* BUS 1 */
            {
                chn   |=  BIT1;
                ch1Snr = (uint8_t)US_SnrDrvCom_F_CountSnr(TEN,NULL,NULL,SnrMap,ZERO);  /* sensors on bus 1 */
                
            }
            else    /* BUS 0 */
            {
                chn   |=   BIT0;
                ch0Snr = (uint8_t)US_SnrDrvCom_F_CountSnr(TEN,NULL,NULL,SnrMap,ZERO);  /* sensors on bus 0 */
                
            }
        }
        if((((uint8_t)cnt%TWO)!= 0u) && (chn != (uint8_t)ZERO))
        {
            if(ch0Snr < ch1Snr)  /* choose max number of sensors on BUS to calculate data size*/
            {
                ch0Snr = ch1Snr;
             }
            US_SnrDrvCom_V_PDCM_datalen[cnt/TWO] = (ch0Snr * pdcm_len )+ TWO;
            if(chn == THREE)
            {
                US_SnrDrvCom_V_PDCM_datalen[cnt/TWO] *= TWO;
            }
		   if(US_SnrDrvCom_V_PDCM_datalen[cnt/TWO] > DSI3DRV_RECEIVE_BUFFER_SIZE)  /*DMA buffer size is not enough for this cmd */
		   {
				   US_SnrDrvCom_V_PDCM_datalen[cnt/TWO] = DSI3DRV_RECEIVE_BUFFER_SIZE;
				   ret = ERROR_US_SNRDRVCOM_DMA_BUFFER_OVERFLOW;
				   break;
		   }
            US_SnrDrvCom_V_PDCM_datalen[cnt/TWO] += EIGHT;
            data[cnt/TWO][ZERO]   = SPI_Cmd;
            data[cnt/TWO][ONE]    = chn;
            data[cnt/TWO][TWO]    = ZERO;
            data[cnt/TWO][THREE]  = (uint8_t)nBRC;
            len = 4;
            US_SnrDrvCom_F_SPI_SndData((uint16_t)cnt/TWO,SPI_Cmd,chn,(uint8_t)nBRC,len,data[cnt/TWO]);
        }

      }
	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessPDCMData.
* used to Process PDCM data
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_ProcessPDCMData
 * Remarks:  DD-ID: {7A89D4A8-24CF-409d-8DF3-7DD55BE52D8E}
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, even though there are 5 if statements present in the function, doesn't always go through them all times */
static uint32_t US_SnrDrvCom_F_ProcessPDCMData(uint8_t dev,uint8_t nBurst,US_SnrDrvCom_Cmd_t const  *cmd,uint8_t *pRcv)
{
    uint8_t cnt,map0,map1,i,snr_index,index0,index1,all_snrs,nSnr0,nSnr1,*pData,data_valid,End_pdcm,mode;
    uint16_t ReqDataLen,datacnt,PacketSize,offset,all_offset,addr,crc,snrver;
    uint16_t SnrCmd = (uint16_t)((cmd->CmdID)&0xFFFFu);
    uint32_t err = ME_OK,ret =ME_OK;
    cnt  = ZERO;
    datacnt = ZERO;
    End_pdcm = ME_TRUE;
    pData  = pRcv;
    US_SnrDrvCom_state  = (uint16_t)CMD_EXEC_PDCM_DATA;
    while((SnrCmd != US_SnrDrvCom_CmdTable[cnt].cmd) && (US_SnrDrvCom_CmdTable[cnt].cmd != ZERO))
    {
                  cnt++;
    }
    if((SnrCmd != US_SnrDrvCom_CmdTable[cnt].cmd) || (SnrCmd == ZERO))
    {
		ret = ERROR_US_SNRDRVCOM_INVLID_CMD;
    }
    if(ret == ME_OK)
    {
        PacketSize = US_SnrDrvCom_CmdTable[cnt].PacketSize;
        ReqDataLen = US_SnrDrvCom_CmdTable[cnt].DataLen;
        if((SnrCmd == REQ_SENSOR_EEPROM)||(SnrCmd == REQ_SENSOR_STG)||(SnrCmd == REQ_SENSOR_STC))
        {
            PacketSize -= ReqDataLen;
            ReqDataLen = ((cmd->SndData[ONE]) * (ReqDataLen -ONE) )+ ONE;
            PacketSize += ReqDataLen;
        }
           if((pRcv[ZERO] & THREE) == THREE)
           {
               nSnr0 = pRcv[FOUR];  /*ch0 count */
            offset = (uint16_t)((nSnr0 * PacketSize) + PDCM_HEAD_SIZE -TWO);    /*ch1 count offset*/
            nSnr1 = pRcv[offset];             /*ch1 count */
            err =  (uint32_t)(((uint32_t)pRcv[FIVE]>>TWO) & BIT_MSK_SC)|((uint32_t)pRcv[FIVE] & (BIT_MSK_SE|BIT_MSK_UV|BIT_MSK_CE));   /*bit3:SC0 bit2:SE0 bit1:UV0,bit0:CE0 */
            err |=  (uint32_t)((((uint32_t)pRcv[offset+ ONE]>>TWO) & BIT_MSK_SC) | ((uint32_t)pRcv[offset+ ONE] & (BIT_MSK_SE|BIT_MSK_UV|BIT_MSK_CE)))<<FOUR;  /*bit7:SC1 bit6:SE1 bit5:UV1,bit4:CE1 */
           }
           else if((pRcv[ZERO] & BIT0) !=ZERO)
        {
               nSnr1 = ZERO;
               nSnr0 = pRcv[FOUR];  /*ch0 count */
               err =  (uint32_t)(((uint32_t)pRcv[FIVE]>>TWO) & BIT_MSK_SC)|((uint32_t)pRcv[FIVE] & (BIT_MSK_SE|BIT_MSK_UV|BIT_MSK_CE));    /*bit3:SC0 bit2:SE0 bit1:UV0,bit0:CE0 */
        }
           else if((pRcv[ZERO] & BIT1) !=ZERO)
           {
               nSnr0 = ZERO;
               nSnr1 = pRcv[FOUR];
               err =  (uint32_t)((((uint32_t)pRcv[FIVE]>>TWO) & BIT_MSK_SC) | ((uint32_t)pRcv[FIVE] & (BIT_MSK_SE|BIT_MSK_UV|BIT_MSK_CE)))<<FOUR;   /*bit7:SC1 bit6:SE1 bit5:UV1,bit4:CE1 */
           }
           else
           {
               nSnr0 = ZERO;
               nSnr1 = ZERO;
           }
     }
    if(ret == ME_OK)
    {
        offset = (((uint16_t)nSnr0 +(uint16_t) nSnr1) * PacketSize) + PDCM_HEAD_SIZE;             /*CRC offset */
           if((offset > (DSI3DRV_RECEIVE_BUFFER_SIZE - TWO))||(nSnr0 > MAX_NUMBER_SENSOR_ON_BUS) || (nSnr1 > MAX_NUMBER_SENSOR_ON_BUS))
           {
            ret = ERROR_US_SNRDRVCOM_DSI_BUS_ERROR;
           }
    }
    if((ret == ME_OK)&&((nSnr0 + nSnr1) > ZERO))
    {
        (void)US_SnrDrvCom_F_SwapHL(pRcv,offset);
        crc = US_SnrDrvCom_F_SPI_CRC(pRcv,offset);
       /*KPK-QAC Fix : Need to suppress, pointer casted to uint16_t to match the aligment */
        if(crc != (*(uint16_t*)(pRcv+offset)))
        {
            ret = ERROR_US_SNRDRVCOM_DSI_SPI_CRC;
        }
        else if(err != ME_OK)
        {
            ret = err | ERROR_US_SNRDRVCOM_PDCM_CH_ERR;
        }
        else
        {
            /* Do Nothing */
        }
    }
    if(ret == ME_OK)
    {
        cnt   = (pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * dev*TWO;
        map0   = (uint8_t)(((cmd->SnrMap) >> cnt) & Bus_Map_Snr);
        map1   = (uint8_t)(((cmd->SnrMap) >> (cnt+ pSnrCfg->Max_nSnr_ON_SINGLE_BUS)) & Bus_Map_Snr);
        (void)US_SnrDrvCom_F_CountSnr(TEN,NULL,&all_snrs,cmd->SnrMap,ZERO);
        (void)US_SnrCfg_F_Get_nSensor(dev * TWO, &index0, ONE);
        (void)US_SnrCfg_F_Get_nSensor((dev * TWO) + ONE, &index1, ONE);
        pData  = cmd->RcvData;                         /*get cmd rec buffer */
        all_offset = (((uint16_t)all_snrs * (uint16_t)nBurst) + (uint16_t)index0) * ReqDataLen;
        datacnt = (((uint16_t)nSnr0 +(uint16_t) nSnr1) * ReqDataLen )+ all_offset;
        if((datacnt + TWO) <= cmd->RcvSize)          /*check ifbuffer size is enough */
        {
            for(cnt=ZERO;cnt<(nSnr0+nSnr1);cnt++)
            {
                data_valid = ME_FALSE;
                offset =(uint16_t)(((cnt < nSnr0)||(map0 == ZERO))?((cnt * PacketSize) + PDCM_HEAD_SIZE+TWO):((cnt * PacketSize) + PDCM_HEAD_SIZE + FOUR));
                snr_index =  (pRcv[offset] & 0x0Fu);
                if((snr_index == (uint8_t)((pRcv[offset]>>4) & 0x0Fu))&&(snr_index > 0u))
                {
                    if((cnt < nSnr0)&&(map0 != ZERO))      /*check if channel 0 data */
                            {
                        if(((map0 >> (snr_index-ONE))&BIT0)!=0u)
                        {
                            pData[(cnt*ReqDataLen) + TWO  + all_offset] = index0 + snr_index-ONE;
                            data_valid = ME_TRUE;
                        }
                            }
                    else if(map1 != ZERO)  /*check if channel 1 data */
                    {
                        if(((map1 >> (snr_index-ONE))&BIT0)!=0u)
                        {
                            pData[(cnt*ReqDataLen) + TWO  + all_offset] = index1 + snr_index-ONE;
                            data_valid = ME_TRUE;
                        }
                    }
                    else
                    {            /*do nothing */
                    }
                    if((data_valid == (uint8_t)ME_TRUE)&&(pData[(cnt*ReqDataLen) + TWO + all_offset] != (uint8_t)0xff))   /*copy data */
                    {
                        for(i=ZERO;i<(ReqDataLen - ONE);i++)
                        {
                            addr  = offset + ONE +i;
                            pData[i + (cnt*ReqDataLen )+ TWO + ONE + all_offset] = pRcv[addr];
                        }
                        /*KPK-QAC Fix : Need to suppress, No issue in using enum( which is signed type value) in comparison */
                        snrver = US_SnrCfg_Get_SnrFWVer();
                        mode  =US_SnrCfg_Get_Sensor_opmode();     
                        if((snrver != QM_SNR_FW_VER)&&(mode == SENSOR_OP_NORMAL)&&((pRcv[offset + ONE] & 0xc0u) != ZERO))
                        {
                            End_pdcm = ME_FALSE;
                        }
                    }
                }
            }
        }
		else      /* Receive buffer size is not enough */
		{
			ret = ERROR_US_SNRDRVCOM_RECEIVE_BUFFER_NOT_ENOUGH;
		}
    }
   all_offset = pData[ONE];
    all_offset = (all_offset << EIGHT)|pData[ZERO];
    if(all_offset < datacnt)    /* update data size if data more  */
    {
        pData[ZERO] = (uint8_t)((datacnt) & 0xffu);
        pData[ONE] = (uint8_t)(((datacnt)>>EIGHT) & 0xffu);
    }
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SendCRM_ByEvent.
* used to send data, called by High priority task because SPI send data can not be called in ISR(TI SDK limitation)
* \param none
* \return no returns
* \remarks  no remarks
*/
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
   void US_SnrDrvCom_F_SendCRM_ByEvent(uint8_t dev,uint8_t const * Data,uint16_t inLen,uint16_t outLen)    
#else
   void US_SPIDMA_ByEvent(uint8_t dev,uint8_t* Data,uint16_t inLen,uint16_t outLen)
#endif
{
     (void)US_SnrDrvCom_F_DSI3Drv_Snd(dev,Data,inLen,outLen);
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SPIDMACall.
* used to read DSI master data from Sensors, called by DSI3 bus interrupt ISR
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SPIDMACall
 * Used to response DMA complete ISR
 * Remarks:  DD-ID: {83C9F773-49B0-4847-B3A8-5BF04039FBC7}
 * ===========================================================================*/
void US_SnrDrvCom_F_SPIDMACall(uint8_t dev)
{
   uint16_t temp = 0u,CmdState = US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD;
    uint8_t  *pRcvbuf,*pbuf,count;
    uint32_t ret,error,dataerror;
   uint64_t State;
    void (*pCallback)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);
    pRcvbuf   = (uint8_t*)DSI3Drv_Rcv_Buf[dev];
    ret  = ME_NOT_OK;
    dataerror = ME_OK;
    /*KPK-QAC Fix : Need to suppress, No issue in pointer casting to uint16_t type */
    error = *(uint16_t*)pRcvbuf;       /* Error code from SPI return */
    switch(CmdState)
    {
    case DSI_CRM_TRANSMIT:          
    case DSI_CRM_AUTOADDR:         /* CRM DMA */
        spi_DMA_state[dev] = ZERO;
        break;
    case DSI_CMD_READ_CRM_RESPONSE:   /* CRM response DMA */
        spi_DMA_state[dev] = ZERO;
        US_SnrDrvCom_CmdState.Dev[dev].Count =   US_SnrDrvCom_CmdState.Dev[dev].Count -1u;
        SnrResp[dev]++;
       count = US_SnrDrvCom_CmdState.Dev[dev].Count;
        if(count == (uint8_t)ZERO)           /*if CRM commands complete */
        {
            SnrResp[dev] = ZERO;
            US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD = ZERO;
            /*KPK-QAC Fix : Need to suppress, No side effects with && or || here */
           State = US_SnrDrvCom_CmdState.CmdState;
            if((State == (uint64_t)CMD_IDLE)&&(US_SnrDrvCom_state == (uint16_t)CMD_EXEC_CRM)) 
            {
                if((US_SnrDrvCom_V_ExecCmd.CmdID & DSI_CMD_MASK) == DSI_CMD_READ_PDCM_BUFFER)
                {
                    if(US_SnrDrvCom_V_ExecCmd.CmdID == REQ_SENSOR_DETECTION_SAME_MEASUREMENT)
                    {
                        pdcm_delay = ONE;
                    }
                    else
                    {
                        pdcm_delay = ZERO;
                    }
                    US_SnrDrvCom_state  = (uint16_t)CMD_EXEC_PDCM;
                    
                }
                if((US_SnrDrvCom_V_ExecCmd.CmdID & DSI_CMD_MASK) != DSI_CMD_READ_PDCM_BUFFER) 
                {
                    ret = ME_OK;
                }
            }
       }
       else   /* next CRM command */
       {
			US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD = DSI_CRM_TRANSMIT;
			if(((US_SnrDrvCom_V_CRM[dev][SnrResp[dev]][ONE] & THREE) == THREE) && ((US_SnrDrvCom_V_CRM[dev][SnrResp[dev]][ZERO] & BIT2) != ZERO))
			{
				temp  =   TEN;
			}
			else
			{
				temp  =   SIX;
			}
			US_SPIDMA_ByEvent(dev,(uint8_t*)US_SnrDrvCom_V_CRM[dev][SnrResp[dev]],temp,temp+FOUR);
       }
       break;
  case DSI_CMD_WRITE_MASTER_REG8:
  case DSI_CMD_READ_MASTER_REG8:              /* Transceiver Register read/write */
        spi_DMA_state[dev] = ZERO;
        US_SnrDrvCom_CmdState.Dev[dev].Count = US_SnrDrvCom_CmdState.Dev[dev].Count -1u;    
        count = US_SnrDrvCom_CmdState.Dev[dev].Count;
        if(count == (uint8_t)ZERO)
        {
           US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD = ZERO;
        }
         break;
  case DSI_CMD_STOP_DSI3_CH0:           /* Stop DSI3 ch0 command */
        SPI_Data[ZERO] =  DSI_CMD_WRITE_MASTER_REG8|((DSI3_STOP_REG_CH1>>EIGHT)&0x1u)|((DSI3_STOP_REG_CH1 & 0xffu)<<EIGHT);
        SPI_Data[ONE] =   (uint16_t)ONE<<EIGHT;
        US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_STOP_DSI3_CH1;
   	    US_SPIDMA_ByEvent(dev,(uint8_t*)SPI_Data,FOUR,US_SnrDrvCom_V_PDCM_datalen[dev]);
      break;
  case DSI_CMD_STOP_DSI3_CH1:   /* Stop DSI3 ch1 command */
        temp = (uint16_t)US_DSI3Drv_buschn[dev];
        temp = temp<<EIGHT;
        SPI_Data[ZERO] =  (uint16_t)(DSI_CMD_READ_PDCM_BUFFER8|temp);
        US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_CLEAR_DSI3_BUFFER;
  	    US_SPIDMA_ByEvent(dev,(uint8_t*)SPI_Data,TWO,US_SnrDrvCom_V_PDCM_datalen[dev]);
        break;
  case DSI_CMD_CLEAR_DSI3_BUFFER:   /* Stop ch0 and ch1 complete */
	  	US_SnrDrvCom_timeout_timer = ZERO;
		US_SnrDrvCom_V_ExecCmd.CallBack = NULL;
		US_SnrDrvCom_V_ExecCmd.SnrMap = ZERO;
		US_SnrDrvCom_V_ExecCmd.CmdID  = ZERO;
		US_SnrDrvCom_CmdState.CmdState = ZERO;
	    US_SnrDrvCom_state = ZERO;
	   break;
  case DSI_CMD_PDCM_BUFFER8_OVERLAP:    /* read PDCM data overlap, error may happen */
       US_DrvDSI3Err_Count++;
        US_SnrDrvCom_CmdState.Dev[dev].Count = US_SnrDrvCom_CmdState.Dev[dev].Count -1u;  
        pbuf  =  pRcvbuf+TWO;
        dataerror = US_SnrDrvCom_F_ProcessPDCMData(dev,SnrResp[dev],(US_SnrDrvCom_Cmd_t*)&US_SnrDrvCom_V_ExecCmd,pbuf);
        SnrResp[dev]++;
         count =   US_SnrDrvCom_CmdState.Dev[dev].Count;
       if(count == (uint8_t)ZERO)  /* PDCM complete ?*/
       {
             US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD = ZERO;
             SnrResp[dev] = ZERO;
            if((US_SnrDrvCom_CmdState.CmdState == (uint64_t)CMD_IDLE)&&(US_SnrDrvCom_state == (uint16_t)CMD_EXEC_PDCM_DATA)&&(US_SnrDrvCom_CmdState.CmdState == (uint64_t)CMD_IDLE ))
            {
                ret = ME_OK;
            }
       }
       else
#if (TRCVR_STOP_CMD_ENABLE == ME_TRUE)
		   if(dataerror == ME_OK)        /* data error happens? */
#endif
       {
                temp = (uint16_t)US_DSI3Drv_buschn[dev];
                temp = temp<<EIGHT;
                SPI_Data[ZERO] = (DSI_CMD_READ_PDCM_BUFFER8|temp);
                US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_READ_PDCM_BUFFER8_DMA;
  	            US_SPIDMA_ByEvent(dev,(uint8_t*)SPI_Data,TWO,US_SnrDrvCom_V_PDCM_datalen[dev]);
         }
#if (TRCVR_STOP_CMD_ENABLE == ME_TRUE)
        else { /* Intentionally Empty */ }
#endif
        spi_DMA_state[dev] = ZERO;
        break;

   case DSI_CMD_READ_PDCM_BUFFER8_DMA:   /* read pdcm data */
        US_SnrDrvCom_CmdState.Dev[dev].Count = US_SnrDrvCom_CmdState.Dev[dev].Count-1u;    
       pbuf = pRcvbuf+TWO;
        dataerror = US_SnrDrvCom_F_ProcessPDCMData(dev,SnrResp[dev],(US_SnrDrvCom_Cmd_t*)&US_SnrDrvCom_V_ExecCmd,pbuf);
        SnrResp[dev]++;
      count  =  US_SnrDrvCom_CmdState.Dev[dev].Count;
       if(count == (uint8_t)ZERO)   /* PDCM complete ?*/
       {
              US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD = ZERO;
           SnrResp[dev] = ZERO;
            if((US_SnrDrvCom_CmdState.CmdState == (uint64_t)CMD_IDLE)&&(US_SnrDrvCom_state == (uint16_t)CMD_EXEC_PDCM_DATA)&&(US_SnrDrvCom_CmdState.CmdState == (uint64_t)CMD_IDLE ))
            {
                ret = ME_OK;
            }
       }
       else 
#if (TRCVR_STOP_CMD_ENABLE == ME_TRUE)
		   if(dataerror == ME_OK)   /* data error happens? */
#endif
       {
              US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_READ_PDCM_BUFFER8;
       }
#if (TRCVR_STOP_CMD_ENABLE == ME_TRUE)
        else { /* Intentionally Empty */ }
#endif
       spi_DMA_state[dev] = ZERO;
	   break;

   default:
       spi_DMA_state[dev] = ZERO;
          break;
   }
    error  = (uint32_t)(error & DSI3_ERROR_MASK);    /* check DSI3 error */
   count  =  US_SnrDrvCom_CmdState.Dev[dev].Count;
    if(((dataerror !=(uint32_t) ME_OK)||(error != (uint32_t)ME_OK))&&(count !=(uint8_t) ZERO)
            &&(CmdState != (uint16_t)DSI_CMD_STOP_DSI3_CH0)&&(CmdState != (uint16_t)DSI_CMD_STOP_DSI3_CH1)&&(CmdState != (uint16_t)DSI_CMD_CLEAR_DSI3_BUFFER))
    {
	/* send stop command when Error  happens  */
#if (TRCVR_STOP_CMD_ENABLE == ME_TRUE)
        SPI_Data[ZERO] =  DSI_CMD_WRITE_MASTER_REG8|((DSI3_STOP_REG_CH0>>EIGHT)&0x1u)|((DSI3_STOP_REG_CH0 & 0xffu)<<EIGHT);
        SPI_Data[ONE] =   (uint16_t)ONE<<EIGHT;
        US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_STOP_DSI3_CH0;
        US_SPIDMA_ByEvent(dev,(uint8_t*)SPI_Data,FOUR,US_SnrDrvCom_V_PDCM_datalen[dev]);
#endif		
        /*KPK-QAC Fix : Need to suppress,  implemented intentionally  */
        if((dataerror == ERROR_US_SNRDRVCOM_PDCM_END)&&(error==ME_OK))
        {
            dataerror = ME_OK;
            ret = ME_OK;
        }
    }
   
   if(((error != ME_OK)||(dataerror != ME_OK)||(ret == ME_OK))&&(CmdState != DSI_CMD_WRITE_MASTER_REG8)&&(CmdState != DSI_CMD_READ_MASTER_REG8)
           &&(CmdState != DSI_CMD_STOP_DSI3_CH0)&&(CmdState != DSI_CMD_STOP_DSI3_CH1)&&(CmdState != DSI_CMD_CLEAR_DSI3_BUFFER))
   {
        pCallback = US_SnrDrvCom_V_ExecCmd.CallBack;   /* complete command when error happens or command is successful completed */
        if(pCallback != NULL)
        {
            if(error != ME_OK)      /* return error code */
            {
                ret =  (uint32_t)dev<<TWELVE;          /*put dev ID to high bits */
                ret |= (error & (DSI3_SPI_UNDCMD|DSI3_SPI_CRC|DSI3_SPI_CMDINC|DSI3_SPI_CLKREF));                   /*ERROR_US_SNRDRVCOM_DSI_SPI_UNDCMD/ERROR_US_SNRDRVCOM_DSI_SPI_CRC/ERROR_US_SNRDRVCOM_DSI_SPI_CMDINC/ERROR_US_SNRDRVCOM_DSI_CLKREF */
                ret |= (error & (DSI3_VCCUV_RFC|DSI3_CH0_CMDOVR|DSI3_CH0_UV))>>DSI3_CH0_DATA_ERR_SHIFT;   /*shift ch0 flag to specified in error bit ERROR_US_SNRDRVCOM_DSI_CH0_UV/ERROR_US_SNRDRVCOM_SPI_CH0_CMDOVR/ERROR_US_SNRDRVCOM_DSI_CH0_RFC */
                ret |= (error & (DSI3_OV_TEMP|DSI3_CH1_CMDOVR|DSI3_CH1_UV))>>DSI3_CH1_DATA_ERR_SHIFT;   /*shift ch1 flag to specified in error bit ERROR_US_SNRDRVCOM_DSI_CH1_UV/ERROR_US_SNRDRVCOM_SPI_CH1_CMDOVR/ERROR_US_SNRDRVCOM_SPI_OV_TEMPERATURE */
            }
            else if(dataerror != ME_OK)
            {
                ret  = dataerror;
            }
            else
            {
                /* Do Nothing */
            }

              if(US_SnrDrvCom_state != (uint16_t)ZERO)
            {
                US_SnrDrvCom_V_ExecCmd.CallBack = NULL;
            
                   (*pCallback)(ret,US_SnrDrvCom_V_ExecCmd.CmdID,US_SnrDrvCom_V_ExecCmd.UserData, US_SnrDrvCom_V_ExecCmd.RcvSize,US_SnrDrvCom_V_ExecCmd.RcvData);
            }
        }
        if(ret != ME_OK)
        {
            US_DrvDSI3Err_Count++;
        }
       count = US_SnrDrvCom_CmdState.Dev[dev].Count;
        if(count ==(uint16_t) ZERO)
        {
              US_SnrDrvCom_timeout_timer = ZERO;
            US_SnrDrvCom_V_ExecCmd.SnrMap = ZERO;
            US_SnrDrvCom_V_ExecCmd.CmdID  = ZERO;
            US_SnrDrvCom_CmdState.CmdState = ZERO;
            US_SnrDrvCom_state = ZERO;

        }
        else{ /* Intentionally Empty */ }
    }
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SPIDCRProcess.
* used to DCR interrupt process, called by DSI3 bus interrupt ISR
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SPIDCRProcess
 * Remarks:  DD-ID: {2DFD2E33-9F45-45fe-9E3A-44A8BF82E036}
 * ===========================================================================*/
uint16_t US_SnrDrvCom_F_SPIDCRProcess(uint8_t dev)  /* DCR interrupt ISR*/
{
    uint16_t ret = ME_NOT_OK;
	if(US_DSI3Drv_buschn[dev] == US_DSI3Drv_cur_busflag[dev])   /* get enough interrupts? */
    {
           US_SnrDrvCom_F_SPIReadMasterData(dev,US_DSI3Drv_buschn[dev]);   
		   ret = ME_OK;
    }
	return ret;
}

/* ===========================================================================*/
/**US_SnrDrvCom_F_SPIReadMasterData.
* used to read DSI master data from Sensors, called by DSI3 bus interrupt ISR
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SPIReadMasterData
 * Used to DCR ISR 
 * Remarks:  DD-ID: {3750A843-021F-422c-A319-C87222394B2F}
 * ===========================================================================*/
static void US_SnrDrvCom_F_SPIReadMasterData(uint8_t dev,uint8_t chn)
{
    uint8_t CmdState = US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD;
    uint8_t data[32];
    switch(CmdState)
    {
    case DSI_CRM_TRANSMIT:
    case DSI_CRM_AUTOADDR:     /* DCR of CRM command */
        if(spi_DMA_state[dev] == ZERO)
        {
            US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_READ_CRM_RESPONSE;
            data[ZERO] =  US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD;
            data[ONE] = chn;
            (void)US_SnrDrvCom_F_DSI3Drv_Snd(dev,data,TWO,CRM_RESPONSE_LENGTH);
        }
        break;
    case DSI_CMD_BRC_PDCM8:
    case DSI_CMD_READ_PDCM_BUFFER8:   /* DCR of PDCM */
        if(spi_DMA_state[dev] == ZERO)
        {
            data[ZERO] =  DSI_CMD_READ_PDCM_BUFFER8;
            data[ONE] = chn;
            US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD =  DSI_CMD_READ_PDCM_BUFFER8_DMA;
            (void)US_SnrDrvCom_F_DSI3Drv_Snd(dev,data,TWO,US_SnrDrvCom_V_PDCM_datalen[dev]);
        }
        break;
    case DSI_CMD_READ_PDCM_BUFFER8_DMA:  /* DCR of PDCM overlap */
        US_SnrDrvCom_CmdState.Dev[dev].SPI_CMD = DSI_CMD_PDCM_BUFFER8_OVERLAP;
        break;
    default:
        /* no action */
        break;
    }
    US_DSI3Drv_cur_busflag[dev]  = ZERO;
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SPI_SndData.
* used to Send data.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_SPI_SndData
 * Remarks:  DD-ID: {93D83CE4-4921-4cd3-8DC4-1D3A4D276EF9}
 * ===========================================================================*/
static void US_SnrDrvCom_F_SPI_SndData(uint16_t nDev,uint8_t type,uint8_t chn,uint8_t nCnt,uint16_t len,uint8_t const *data)
{
    if(US_SnrDrvCom_state != (uint16_t)ZERO)
    {
        US_SnrDrvCom_CmdState.Dev[nDev].SPI_CMD  = type;     /* DSI command */
        US_SnrDrvCom_CmdState.Dev[nDev].Count = nCnt;        /* repeat count*/
        US_DSI3Drv_SetBusChn((uint8_t)nDev,chn);
        (void)US_SnrDrvCom_F_DSI3Drv_Snd((uint8_t)nDev,data,len,len+FOUR);
    }
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessCRM.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_ProcessCRM
 * Remarks:  DD-ID: {F56BAB02-393A-41f1-AAE7-4C4F282A8596}
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, even though there are 5 if statements present in the function, doesn't always go through them all times */
static uint32_t US_SnrDrvCom_F_ProcessCRM(US_SnrDrvCom_Cmd_t const*cmd)
{
    uint8_t cnt,CrmCnt,map,map0,SPI_Cmd,nbus,bc_bit,i,datacnt;
    uint8_t const *SndData;
    uint32_t CmdID,SnrMap,ret = ME_OK;
    uint16_t len,SndSize, packetsize;
    void (*pCallback)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData);
    CmdID  = cmd->CmdID;
    SnrMap = cmd->SnrMap;
    SndSize = (cmd->SndSize) & (~BIT15);
    SndData = cmd->SndData;
    bc_bit  = ZERO;
    map0 = ZERO;
    SPI_Cmd     =  (uint8_t)((CmdID & DSI_CMD_MASK)>>8);
    US_SnrDrvCom_CmdState.CmdState = ZERO;
    if((SnrMap != ZERO)||(SPI_Cmd     ==  DSI_CRM_AUTOADDR))   /* the command is invalid if Snrmap =0 and not auto address command */
    {
        (void)memset(US_SnrDrvCom_V_CRM,0,(MAX_DSI3_BUS/TWO)*TEN*TEN); 
        if((cmd->RcvSize)>=2u)
        {
            (void)memset(cmd->RcvData,0xff,cmd->RcvSize);    
            cmd->RcvData[ZERO] = ZERO;
            cmd->RcvData[ONE] = ZERO;
        }
        packetsize = THREE;
        CrmCnt  = (uint8_t) (SndSize/packetsize);
        if((SndSize%packetsize)!=0u)
        {
            CrmCnt++;
        }
        len = ZERO;
        nbus = ZERO;

        for(cnt = ZERO; cnt < pSnrCfg->nBusCfg; cnt++)     /*check bus configure */
                {
            map   = (uint8_t)((SnrMap >> ((pSnrCfg->Max_nSnr_ON_SINGLE_BUS) * cnt))& Bus_Map_Snr);
            if((cnt%TWO) == ZERO)
            {
                map0 = map;
            }
            if((map != 0u) ||(SPI_Cmd == (uint8_t)DSI_CRM_AUTOADDR))  /*cmd apply to this bus */
            {
                US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ZERO]          =   (SPI_Cmd)|(BIT3|bc_bit);     /*cmd and  CRC on for Master calculation */
                if(( ((uint8_t)cnt%TWO) != 0u ) && (((US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ONE] & BIT0)!=ZERO)  &&(SPI_Cmd != DSI_CRM_AUTOADDR)))
                {
                    US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ONE] |=  BIT1;                                /*ch2 on */
                    if((map0 != ZERO)&&((map0 != map)||(((cmd->SndSize) & BIT15)!=ZERO)))
                    {
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ZERO] |=  BIT2;                               /*two command for two chs */
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][SIX] =  CrmCnt;           /*or  (phyaddr << FOUR)|(CrmCnt) , phyaddr =0, phys addr and following data */
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][SEVEN] =   (uint8_t)(CmdID & 0xffu);                    /*cmd id */
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][EIGHT] =   (uint8_t)((map << TWO) | USS_DRV_CRM_HEADER );/*sensor map and type is header */
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][NINE] =   ZERO;    /*sensor map and type is header */
                        len = TEN;
                    }
                    for(i=ZERO;i<CrmCnt;i++)
                    {
                        US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][ONE]       |=  BIT1;                               /* */
                        if((map0 != (uint8_t)ZERO)&&((map0 != map)||(((cmd->SndSize) & BIT15) != ZERO)))
                        {
                            datacnt = (uint8_t)((nbus * SndSize) + (i * packetsize));
                            US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][ZERO]      |=  BIT2;                               /*two command for two chs */
                            US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][SIX]       =   SndData[datacnt];
                            US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][SEVEN]     =   SndData[datacnt + ONE];
                            US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][EIGHT]     =   (SndData[datacnt  +TWO])|USS_DRV_CRM_DATA;
                        }
                    }

                }
                else
                {
                    if((cnt%TWO)!=0u)
                    {
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ONE]       |=    BIT1;                              /*ch1 on */
                    }
                    else
                    {
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ONE]       |=    BIT0;                              /*ch1 on */

                    }
                    if(SPI_Cmd     ==  DSI_CRM_AUTOADDR)
                    {
                        US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ONE]   |=    BIT1;
                    }
                    US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][TWO]         =    CrmCnt;           /*or (phyaddr << FOUR)|(CrmCnt), phyaddr =0, phys addr and following data */
                    US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][THREE]     =   (uint8_t)(CmdID & 0xffu);
                    US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][FOUR]      =   (uint8_t)((map << TWO) | USS_DRV_CRM_HEADER );
                    US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][FIVE]      =   ZERO;
                    for(i=ZERO;i<CrmCnt;i++)
                    {
                        datacnt =(uint8_t) ((nbus * SndSize) + (i * packetsize));
                        US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][ZERO]   =    (SPI_Cmd)|(BIT3|bc_bit);               /*cmd and  CRC on for Master calculation */
                        if((cnt%TWO )!=0u)
                        {
                            US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][ONE]       |=    BIT1;                              /*ch1 on */
                        }
                        else
                        {
                            US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][ONE]       |=    BIT0;                              /*ch0 on */
                        }
                        US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][TWO]    =   SndData[datacnt];
                        US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][THREE]  =   SndData[datacnt + ONE];
                        US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][FOUR]   =   (SndData[datacnt+ TWO ])|USS_DRV_CRM_DATA;
                        US_SnrDrvCom_V_CRM[cnt/TWO][i +ONE][FIVE]   =   ZERO;
                    }
                    len = SIX;
                }
            }
            if(((cmd->SndSize) & BIT15)!=0u)
            {
                nbus ++;
            }
            if(((cnt%TWO)!= ZERO) && (len != (uint16_t)ZERO))     /*calculate CRC & transmit */
            {
                SnrResp[cnt/TWO] = ZERO;
                US_SnrDrvCom_F_SPI_SndData((uint16_t)cnt/TWO,SPI_Cmd,(US_SnrDrvCom_V_CRM[cnt/TWO][ZERO][ONE] & THREE),CrmCnt + ONE,len,US_SnrDrvCom_V_CRM[cnt/TWO][ZERO]);
                len = ZERO;
            }
        }
    }
    else   /* complete command if command is invalid*/
    {
        pCallback = US_SnrDrvCom_V_ExecCmd.CallBack;
        ret = ERROR_US_SNRDRVCOM_INVLID_SNRMAP;
        US_SnrDrvCom_V_ExecCmd.CallBack = NULL;
        if(pCallback != NULL)
        {
            if(US_SnrDrvCom_state != (uint16_t)ZERO)
            {
                (*pCallback)(ret,US_SnrDrvCom_V_ExecCmd.CmdID,US_SnrDrvCom_V_ExecCmd.UserData, US_SnrDrvCom_V_ExecCmd.RcvSize,US_SnrDrvCom_V_ExecCmd.RcvData);
            }
        }
        US_SnrDrvCom_timeout_timer = ZERO;
        US_SnrDrvCom_V_ExecCmd.SnrMap = ZERO;
        US_SnrDrvCom_V_ExecCmd.CmdID  = ZERO;
        US_SnrDrvCom_CmdState.CmdState = ZERO;
        US_SnrDrvCom_state = ZERO;
        ret  = ME_OK;
    }
    return ret;
}

/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessPDCMCMD.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_ProcessPDCMCMD
 * Remarks:  DD-ID: {D4C0A6F2-E202-44be-AF7D-D8777F82CE15}
 * Req.-ID: 16134166
 * ===========================================================================*/
static uint32_t US_SnrDrvCom_F_ProcessPDCMCMD(US_SnrDrvCom_Cmd_t const *cmd)
{
    uint32_t temp,ret = ME_OK;
    US_SnrDrvCom_Cmd_t tempCmd;
    temp = ((uint32_t)DSI_CRM_TRANSMIT<<EIGHT);
    tempCmd.CmdID  = (temp) | ((cmd->CmdID)&0xFFu);
    tempCmd.SnrMap = cmd->SnrMap;
    tempCmd.SndData = cmd->SndData;
    tempCmd.SndSize = cmd->SndSize;
    tempCmd.RcvData = cmd->RcvData;
    tempCmd.RcvSize = cmd->RcvSize;
    tempCmd.UserData = cmd->UserData;
    tempCmd.CallBack = NULL;

   	ret = US_SnrDrvCom_F_ProcessCRM(&tempCmd);       /*send CRM cmd first*/
    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessPDCM.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_StartPDCM
 * Remarks:  DD-ID: {74B5C693-4AEF-4126-B0E7-4AE923760258}
 *
 *Req.-ID: 13410142
 *Req.-ID: 13411731
 * ===========================================================================*/
static uint32_t US_SnrDrvCom_F_StartPDCM(US_SnrDrvCom_Cmd_t const *cmd)
{
    uint8_t EnvOutput,mode;
    uint16_t SnrCmd = (uint16_t)((cmd->CmdID)&0xFFFFu);
    uint16_t PDCM_Len,PDCMPeriod,maxSnrCnt,cnt,nBRC,measuretime,NoiseChktime,snrver;
    uint32_t ret = ERROR_US_SNRDRVCOM_INVLID_CMD;
	US_SnrDrvCom_CmdTable_t const *cmdparam;
    US_SnrDrvCom_Cmd_t tempCmd;

    cnt  = ZERO;
    US_SnrDrvCom_state  = (uint16_t)CMD_EXEC_PDCM_DATA;
    while((SnrCmd != US_SnrDrvCom_CmdTable[cnt].cmd) && (US_SnrDrvCom_CmdTable[cnt].cmd != ZERO))  /* get command parameters, PDCM interval, packet size etc. from table*/
    {
        cnt++;
    }
    if((SnrCmd == US_SnrDrvCom_CmdTable[cnt].cmd)&&(SnrCmd != ZERO))   /* found cmd from table */
    {  
        cmdparam  = (US_SnrDrvCom_CmdTable_t const *)&US_SnrDrvCom_CmdTable[cnt];
        maxSnrCnt = US_SnrDrvCom_F_CountSnr(TEN,NULL,NULL,cmd->SnrMap,ZERO);        /*get max num of sensors of buses */
        tempCmd.CmdID  = DSI_CMD_WRITE_MASTER_REG | DSI3_REG_PDCMPERIOD;            /* for writing PDCM interval */
        tempCmd.SnrMap = cmd->SnrMap;
        EnvOutput      = (cmd->SndData[TWO]>>TWO) & BIT0;
        PDCMPeriod = cmdparam->PDCMPeriod;
        PDCM_Len = (cmdparam->PacketSize);
        nBRC    = cmdparam ->nBRC;                           /* Number of PDCM */

        if((SnrCmd == REQ_SENSOR_EEPROM)||(SnrCmd == REQ_SENSOR_STG)||(SnrCmd == REQ_SENSOR_STC))  /* calculate PDCM interval for different command*/
        {
       		PDCMPeriod = 200u +( maxSnrCnt * ((((uint16_t)cmd->SndData[ONE]) * DATA_LEN_PERIOD) + PDCMPeriod));
            PDCM_Len   = ((cmdparam->PacketSize) - (cmdparam->DataLen))  + ((cmdparam->DataLen - ONE) * (cmd->SndData[ONE])) + ONE;
        }
        else if(((SnrCmd != REQ_SENSOR_DETECTION_SAME_MEASUREMENT)&&(SnrCmd != REQ_SENSOR_DETECTIPON_QUICK))||(EnvOutput != ZERO))
        {
            PDCMPeriod = 200u + (PDCMPeriod *maxSnrCnt);
        }
        /*KPK-QAC Fix : Need to suppress,  There is no such chance for always TRUE this condition      */
        else if((SnrCmd == REQ_SENSOR_DETECTION_SAME_MEASUREMENT)||(SnrCmd == REQ_SENSOR_DETECTIPON_QUICK))
        {
            PDCMPeriod = ((uint16_t)Burst_Period *100u);
        }
        else{ /* Intentionally Empty */ }

        tempCmd.SndData = (uint8_t*)&PDCMPeriod;
        tempCmd.SndSize = TWO;                   /*all chns are same data */
        tempCmd.RcvData = NULL;
        tempCmd.RcvSize = ZERO;
        tempCmd.CallBack = NULL;
        ret = US_SnrDrvCom_F_ProcessDSIMasterCMD(&tempCmd);   /*set up PDCM period as same */
        if(ret == ME_OK)
        {
            tempCmd.CmdID  = DSI_CMD_BRC_PDCM;
            tempCmd.SnrMap = cmd->SnrMap;
            tempCmd.SndData = NULL;
            tempCmd.SndSize = ZERO;                   /*all chns are same data */
            tempCmd.RcvData = NULL;
            tempCmd.RcvSize = ZERO;
            tempCmd.CallBack = NULL;
            if((SnrCmd == REQ_SENSOR_DETECTION_SAME_MEASUREMENT)||(SnrCmd == REQ_SENSOR_DETECTIPON_QUICK))   /*get nBRC from sending data[5] */
            {
                snrver = US_SnrCfg_Get_SnrFWVer();
                mode = US_SnrCfg_Get_Sensor_opmode();
                if((snrver == QM_SNR_FW_VER)||(mode != SENSOR_OP_NORMAL)) 
                {
                    nBRC = ((uint16_t)cmd->SndData[FIVE]>>TWO);
                }
                else
                {
                    /* 2983: Is 'measuretime' and 'NoiseChktime' required?? not used in code */
                    measuretime =  ((uint16_t)cmd->SndData[FOUR] & 0x7fu); 
                    NoiseChktime = ((((uint16_t)cmd->SndData[FOUR]<<3u) & 0x8u)|(((uint16_t)cmd->SndData[FIVE]>>5u) & 0x7u));
                    nBRC = Burst_nPDCM;
                }
            }
            ret = US_SnrDrvCom_F_ProcessBRCCMD(&tempCmd,nBRC,PDCM_Len);
        }
    }

    return ret;
}
/* ===========================================================================*/
/**US_SnrDrvCom_F_ProcessCmd. 
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_ProcessCmd
 * Remarks:  DD-ID: {C78A4DB7-12AD-4d2d-9763-F05E43F559A4}
 * Req.-ID: 16134166
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
static void US_SnrDrvCom_F_ProcessCmd(void)
{
	static uint8_t cmd_lock = ME_FALSE;
	uint16_t SPI_CMD,Queue_status;
    uint8_t DSI3Ready;
    DSI3Ready = US_CheckDSI3Ready();
	if(DSI3Ready != ZERO)   /* check RFC is ready*/
	{
        if(cmd_lock == (uint8_t)ME_FALSE)    /* avoid re-entering here immediately */
        {
            cmd_lock = ME_TRUE;  
            /* check if previous command complete*/

            if((DeQueueDelay == (uint8_t)ZERO)&&(US_SnrDrvCom_state == (uint16_t)CMD_IDLE)&&(US_SnrDrvCom_V_ExecCmd.CmdID == (uint32_t)ZERO)&&(US_SnrDrvCom_V_ExecCmd.SnrMap == (uint32_t)ZERO)&&(US_SnrDrvCom_CmdState.CmdState == (uint64_t)CMD_IDLE)) /*previous cmd is completed*/
            {
                Queue_status = US_SnrDrvCom_F_DeCmdQueue(&US_SnrDrvCom_V_ExecCmd);
				if(Queue_status  == (uint16_t)ME_OK)   /*Get cmd from cmd queue */
                {

                    US_SnrDrvCom_state   = (uint16_t)CMD_READY;
                    US_SnrDrvCom_CmdState.CmdState = (uint64_t)CMD_READY;
                     SPI_CMD  = (uint16_t)((US_SnrDrvCom_V_ExecCmd.CmdID & DSI_CMD_MASK)>>EIGHT);
                    switch(SPI_CMD)
                    {
                    case DSI_CRM_TRANSMIT:
                    case DSI_CRM_AUTOADDR:                               /* CRM command */
                        US_SnrDrvCom_state   = (uint16_t)CMD_EXEC_CRM;
                        (void)US_SnrDrvCom_F_ProcessCRM(&US_SnrDrvCom_V_ExecCmd);    /*send cmd CRM header */
                        break;
                    case DSI_CMD_READ_MASTER_REG8:
                    case DSI_CMD_WRITE_MASTER_REG8:                    /* Read/write Transceiver Register command */
                        US_SnrDrvCom_state   = (uint16_t)CMD_EXEC_OP_MASTER_IC;
                        (void)US_SnrDrvCom_F_ProcessDSIMasterCMD(&US_SnrDrvCom_V_ExecCmd);
                        break;
                    case DSI_CMD_READ_PDCM_BUFFER8:                   /* CRM with PDCM command */
                        US_SnrDrvCom_state   = (uint16_t)CMD_EXEC_CRM;
                        (void)US_SnrDrvCom_F_ProcessPDCMCMD(&US_SnrDrvCom_V_ExecCmd);
                        break;
                    default:
                        /* no action */
							break;
						}
					}
				}
				cmd_lock = ME_FALSE;
			}
            US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_RFC_ERR);        
	}
}
/* ===========================================================================*/
/**EnCmdQueue. 
* used to put command into cmd queue.
* \param SnrMap,CmdID,SndSize,SndData[],RcvSize, RcvData[], *CallBack()
* \return successful or fail
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_EnCmdQueue
 * Remarks:  DD-ID: {FD8098F4-3EE6-47ee-A3D7-8C26DDC2997E}
 * ===========================================================================*/

static uint32_t US_SnrDrvCom_F_EnCmdQueue(uint32_t SnrMap,uint32_t UserData,uint32_t CmdID,uint16_t SndSize,uint8_t *SndData,uint16_t RcvSize,uint8_t *RcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData))
{
		   uint32_t ret = ME_OK; 
		   uint8_t nCmd;
           bool_t bLock;
		   US_SnrDrvCom_Cmd_t *pCmd;
    if((pSnrCfg != NULL)&&((pSnrCfg->nBusCfg) != ZERO)&&((pSnrCfg->SnrMap) != ZERO)&&((pSnrCfg->Max_nSnr_ON_SINGLE_BUS) != ZERO))
    {
        bLock = US_SemaphoreLock( US_SnrDrvCom_xSemaphore );
        if( bLock == (bool_t)ME_TRUE )   /* lock semaphore*/
        {
            if(US_SnrDrvCom_QueueState == (uint8_t)ME_FULL)        /* Check if Queue is full*/
            {
                US_SemaphoreUnlock( US_SnrDrvCom_xSemaphore);
                ret = ME_FULL;
            }
            else
            {
                /* put cmd into queue*/
                US_SnrDrvCom_V_CmdQueue[US_SnrDrvCom_Queuetail].SnrMap  = SnrMap;
                pCmd   = &US_SnrDrvCom_V_CmdQueue[US_SnrDrvCom_Queuetail];
                pCmd->SnrMap  = SnrMap;
                pCmd->CmdID  = CmdID;
                pCmd->UserData = UserData;
                pCmd->SndSize  = SndSize;
                pCmd->SndData  = SndData;
                pCmd->RcvSize  = RcvSize;
                pCmd->RcvData  = RcvData;
                pCmd->CallBack  = CallBack;
                ++US_SnrDrvCom_Queuetail;
                US_SnrDrvCom_Queuetail = ((US_SnrDrvCom_Queuetail) & USSQUEUEMASK);
                /* Check if Queue is full*/
                nCmd = ((US_SnrDrvCom_Queuetail- US_SnrDrvCom_QueueHeader) & USSQUEUEMASK);
                if(nCmd == ZERO)
                {
                    US_SnrDrvCom_QueueState = ME_FULL;
                }
                else
                {
                    US_SnrDrvCom_QueueState = ME_OK;
                }
                US_SemaphoreUnlock( US_SnrDrvCom_xSemaphore);

				}
			}
			else
			{
				ret = ME_SEMAPHORE_LOCK_FAIL;
			}
		   }
		   else
		   {
				ret = ERROR_US_SNRDRVCOM_SYSTEM_NOT_INIT;

		   }
			return ret;
    
}


/* ===========================================================================*/
/**DeCmdQueue. 
* used to dequeue command from cmd queue.
* \param USSDrvCmd_t *Cmd
* \return successful or fail
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_F_DeCmdQueue
 * Remarks:  DD-ID: {756191C3-8C83-4db7-B340-468F1589D9C5}
 * ===========================================================================*/
static uint16_t US_SnrDrvCom_F_DeCmdQueue(US_SnrDrvCom_Cmd_t *Cmd)
{
    uint32_t ret;
    bool_t bLock;
    US_SnrDrvCom_Cmd_t *pCmd;
    bLock  = US_SemaphoreLock( US_SnrDrvCom_xSemaphore );
    if( bLock == (bool_t)ME_TRUE )   /* lock semaphore*/
    {
        if(US_SnrDrvCom_QueueState == (uint8_t)ME_EMPTY)        /* Check if Queue is full*/
        {
              /*release semaphore*/
            US_SemaphoreUnlock( US_SnrDrvCom_xSemaphore);
            ret = ME_EMPTY;
        }
        else
        {
            pCmd   = &US_SnrDrvCom_V_CmdQueue[US_SnrDrvCom_QueueHeader];

            /* get cmd from queue*/
            Cmd->SnrMap     =   pCmd->SnrMap;
            Cmd->CmdID      =   pCmd->CmdID;
            Cmd->UserData   =   pCmd->UserData;
            Cmd->SndSize    =   pCmd->SndSize;
            Cmd->SndData    =   pCmd->SndData;
            Cmd->RcvSize    =   pCmd->RcvSize;
            Cmd->RcvData    =   pCmd->RcvData;
            Cmd->CallBack   =   pCmd->CallBack;
            pCmd->SnrMap = ZERO;
            pCmd->CmdID  = ZERO;
            ++US_SnrDrvCom_QueueHeader;
            US_SnrDrvCom_QueueHeader = (uint8_t)((US_SnrDrvCom_QueueHeader) & USSQUEUEMASK);
            /* Check if Queue is EMPTY*/
            if(US_SnrDrvCom_Queuetail == US_SnrDrvCom_QueueHeader)
            {
                US_SnrDrvCom_QueueState = ME_EMPTY;
            }
            else
            {
                US_SnrDrvCom_QueueState = ME_OK; /* do nothing */
            }
            US_SemaphoreUnlock( US_SnrDrvCom_xSemaphore);

            ret = ME_OK;
        }
    }
    else
    {
        ret = ME_SEMAPHORE_LOCK_FAIL;
    }
    return (uint16_t)ret;

}
