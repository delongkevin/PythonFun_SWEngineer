/*
 * US_SnrCmdSend.c
 *
 *  Created on: Apr 6, 2021
 *      Author: jonapais
 *      Jonathan Paisley
 */
#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_Ctrl_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_SnrCmd.h"
/* LOCAL DATA */

/*
 * Note:
 * Only one burst command is ever in the Sensor Driver queue at one time due to Ctrl state machine.
 * It's configuration remains in this static structure (eSendBurstCfg), until the callback is received,
 * and is used by the callback.   Do not remove.
 */

/* Current sensor Burst Data */
static US_S_ClusterBurstCmd_t sSendBurstCfg;

/* Current pdcm period */
static uint8_t uPdcmPeriod = 20u; /* 100 us * 20 = 2 ms */

/* Requested echo type for the current measurement */
static US_E_SendType_t eReqEchoType[US_D_MAX_NUM_SENSORS];

/* Measurement type per sensor */
static US_E_SendType_t eMeasEchoType[US_D_MAX_NUM_SENSORS];

/* Map of sending sensors */
static uint32_t uSendingSensors;

/* Receive profile for this measurement */
static US_E_ProfileType_t eaReceiveProfile[US_D_MAX_NUM_BUS];

/* SPI buffer data from Driver */
static uint8_t uSpiBurstDataBuff[US_D_SPI_BURST_DATA_BUFF_SIZE];

/* SPI command data from Driver */
static uint8_t uSpiCmdDataBuff[US_D_SPI_BURST_DATA_BUFF_SIZE];

/* Receive Sensor Freq buffer  */
static uint8_t uSensorFreqBuff[US_D_SENSORS_FREQ_DATA_BUFF_SIZE];

/* Quick lookup of app index, given bit number of sensor in driver index format */
static uint8_t  uSnrAddrIdxList[US_D_MAX_NUM_SENSORS_CONFIGURABLE];

/* Flag to indicate call back has been received, processing of data is done. */
static volatile uint16_t bBurstCmdDone   = ME_TRUE;

/* Sensor Bitfield Map of enabled sensors selection */
static uint32_t uDvrSnrEnableMap = ZERO;

/* Sensor Compressed Bitfield Map of enabled sensors selection, for sensor disconnect. */
static uint32_t uAppSnrEnableMap = ZERO;

/* Sensor driver bitmap of sensors to stay silent periodically. */
static uint32_t uDvrSilentBitMap = ZERO;

/* Sensor index bitmap of sensors to stay silent periodically.*/
static uint16_t uSnrSilentBitMap = ZERO;

/* Rate at which to override with silence */
static uint8_t uGrpSilenceRate = ZERO; /* off  */

/* Current count.  When reaches max, then silence. */
static uint8_t uGrpSilenceCnt = ZERO;

/* Number of PDCM counts to extend measurment.  */
static uint8_t uPDCM_CountExtention = ZERO;           

/* PDCM delay - 6 ms [in driver counts - 2ms each] */
static uint8_t uPDCM_DelayInDriverCnts = ONE;

#if UART_SUPPORTED
/* For UART output  */
static uint8_t uOutputCount = ZERO;
#endif

US_S_ClusterBurstCmd_t UssDBG_SendBurstCfgUsed;

/*===========================================================================
 * \brief Return pointer to the SPI burst data buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks uint8_t * uSpiBurstDataBuff
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_puGetSpiBurstDataBuff
 * Remarks:  DD-ID: {5AF09EFD-0405-4ca0-94D3-0B1F08F8C5D3}
 * ===========================================================================*/
uint8_t * UssSnrCmd_puGetSpiBurstDataBuff(void)
{
    return uSpiBurstDataBuff;
}

/* ===========================================================================
 * Name:	 UssSnrCmd_SetGrpForSilence
 * Remarks:  DD-ID: {829E6F1D-6B4F-48e0-8B55-047ED2493FBD}
 * Req.-ID: 17350852
 * ===========================================================================*/
void UssSnrCmd_SetGrpForSilence(uint8_t uGrpIdx)
{
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    uDvrSilentBitMap |= psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uGrpDrvAddrBitMap;
    uSnrSilentBitMap |= psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uGrpSnrIdxBitMap;
}

/* ===========================================================================
 * Name:	 UssSnrCmd_ClrGrpForSilence
 * Remarks:  DD-ID: {EFF41ECF-7D8E-40c9-9CA1-AE94BCC17E70}
 * ===========================================================================*/
void UssSnrCmd_ClrGrpForSilence(uint8_t uGrpIdx)
{
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    uDvrSilentBitMap &= ~psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uGrpDrvAddrBitMap;
    uSnrSilentBitMap &= ~psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uGrpSnrIdxBitMap;
}

/* ===========================================================================
 * Name:	 UssSnrCmd_Init
 * Remarks:  DD-ID: {CD9174E4-E2EC-480a-9BEF-3A7DD0943EA4}
 * ===========================================================================*/
void UssSnrCmd_Init(void)
{
    uint8_t uBusNum;
    uint8_t uSnrIdx;

    /* Set default receive profile */
    for(uBusNum = ZERO; uBusNum< US_D_MAX_NUM_BUS; uBusNum++)
    {
        eaReceiveProfile[uBusNum] = US_E_PROFILE_A;
    }

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        eMeasEchoType[uSnrIdx] = US_E_REQ_SEND_NORMAL;
    }
}

/*
 * Rate in cycles.
 * ie 2u = Pattern: Fire->Fire->Silence,
 * 0 = off,
 * US_D_CMD_ALWAYS_LISTENING (0xFF) = Always listen to this selection of groups
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SetGrpSilenceRate
 * Remarks:  DD-ID: {9E42F206-E76B-41d0-A5D8-D7D852407154}
 * Req.-ID: 17350852
 * ===========================================================================*/
void UssSnrCmd_SetGrpSilenceRate(uint8_t uSilenceRate)
{
    uGrpSilenceRate = uSilenceRate;
}

/* ===========================================================================
 * Name:	 UssSnrCmd_PopulateSnrAddrIdxList
 * Remarks:  DD-ID: {C739CA76-95D7-4557-978A-A8E4EDAA1CE3}
 * ===========================================================================*/
/*===========================================================================
 * \brief Build reverse lookup uAppSnrIdx = uSnrAddrIdxList[uDvrSnrIdx]
 *
 * \param none 
 * \param none
 * \return none
 * \remarks uOnly runs at init and only used by measurement send command
 * ==========================================================================
 */
/*
 * Note: This function was quickly done to serve a purpose \TODO incorporate into platform config for efficiency.
 */
void UssSnrCmd_PopulateSnrAddrIdxList(void)
{
    uint32_t uBitMask;
    uint8_t  uAddrBitIdx;
    uint8_t  uSnrIdx;

    const uint32_t * pauSnrAddrList = UssCtrl_pauGetSnrAddrList();      /* Get pointer to the sensor address list. */

    (void)memset(uSnrAddrIdxList, ZERO, sizeof(uint8_t) * US_D_MAX_NUM_SENSORS_CONFIGURABLE);

    uBitMask = BIT0;
    for (uAddrBitIdx = ZERO; uAddrBitIdx < US_D_MAX_NUM_SENSORS_CONFIGURABLE; uAddrBitIdx++)
    {
        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
        {
            if (uBitMask == pauSnrAddrList[uSnrIdx])
            {
                uSnrAddrIdxList[uAddrBitIdx] = uSnrIdx;
            }
        }
        uBitMask <<= ONE;
    }
}

/* ===========================================================================
 * Name:	 UssSnrCmd_ConvSndTypeToBrstType
 * Remarks:  DD-ID: {E2DF5BF0-6B40-4d85-8971-A13557A5CD0B}
 *  Req.-ID:13389468
 * ===========================================================================*/
static US_E_SendBurstType_t UssSnrCmd_ConvSndTypeToBrstType(US_E_SendType_t eSndType)
{
    US_E_SendBurstType_t eBurstType;
    
    switch(eSndType)
    {
        case US_E_REQ_STANDBY:
            eBurstType = US_E_SEND_STANDBY;
            break;
        
        case US_E_REQ_SEND_NORMAL:
            eBurstType = US_E_SEND_NORMAL;
            break;
            
        case US_E_REQ_SEND_CHIRP_UP:
            eBurstType = US_E_SEND_CHIRP_UP;
            break;
            
        case US_E_REQ_SEND_CHIRP_DOWN:
            eBurstType = US_E_SEND_CHIRP_DOWN;
            break;
            
        case US_E_REQ_SEND_NFD:
            eBurstType = US_E_SEND_NORMAL;
            /*no need to force uNumPDCM to 3  */
            break;

        case US_E_REQ_RECEIVE:
            eBurstType = US_E_RECEIVE;
            break;
            
        default:
            eBurstType = US_E_SEND_STANDBY;   /* Unknown type specified  */
            break;
    }

    return eBurstType;
}

/*===========================================================================
 * \brief Populate burst command.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Uses current firing sequence states and burst config
 *          to populate burst date
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_PopulateBurstCommand
 * Remarks:  DD-ID: {DE8A3B15-3EA6-42a8-9E68-959BF3D914D1}
 * Req.-ID: 13520454
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch statements doesn't lead to any complexcity */
void UssSnrCmd_PopulateBurstCommand(void) /*  optomized */
{
    uint32_t uSnrAddr = ZERO;
    uint32_t uReceiveMap = ZERO;
    uint32_t uSendMap = ZERO;
    uint32_t uBitMask;
    uint16_t uAppSendMap;
    uint8_t  uNumOfFireSeqs = UssCtrl_uGetNumFireSequences();
    uint8_t  uSnrIdx;
    uint8_t  uStepIdx;
    uint8_t  uCurFireSeqIdx;
    uint8_t  uTypeIdx;

    US_S_FireSeqCmd_t    const   *psCurFireSeqCmd;
    const US_S_SensorLocs_t *psFireSeqRec;
    const uint8_t           *psSendSnrLocs;
    const uint8_t           *puRcvrSnrLocs;

    /* Create pointers for quick member access */
    US_S_FireSeqCmd_t const * pasFireSeqCmds = UssCtrl_pasGetFireSeqCmds();  /* Get pointer to fire sequence from controller  */
    const uint32_t * pauSnrAddrList = UssCtrl_pauGetSnrAddrList();      /* Get pointer to the sensor address list.   */
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo(); /* Get platform information about what sensors are installed.  */
    uint32_t uInstalledSnrMap = psPlatPhysInfo->uInstSnrDvrAddrMask;

    /*
     * Create Type Array from current Sensor Map
     *
     */
    /* Clear all sensor commands.  Sensor is Idle. (Correlation with Dvr Addr Bitmap) */
    (void)memset(sSendBurstCfg.TypeAry, (sint32_t)US_E_SEND_STANDBY, US_D_MAX_NUM_SENSORS_CONFIGURABLE);

    /* Clear all bit in request type array (Packed bits for use when data is returned by index.) */
    (void)memset(eReqEchoType, (sint32_t)US_E_REQ_STANDBY, US_D_MAX_NUM_SENSORS * sizeof(US_E_SendType_t));

    uSendingSensors = ZERO; /* Reset sending sensors.  */

    for (uCurFireSeqIdx = 0; uCurFireSeqIdx < uNumOfFireSeqs; uCurFireSeqIdx++)
    {
        psCurFireSeqCmd    = &pasFireSeqCmds[uCurFireSeqIdx]; /* we may have multiple sequences running.  Get current. */
        psFireSeqRec       = &psCurFireSeqCmd->psSensorLocSeq[psCurFireSeqCmd->uCurSeqRecord];  /* Get the current fire sequence step record  */
        psSendSnrLocs      = psFireSeqRec->psSendSnrs;  /* Get the sending sensors list */
        puRcvrSnrLocs      = psFireSeqRec->puRcvrSnrs;  /* get the receiving sensors list  */


#if UART_SUPPORTED
        /* UART DIAGNOSTICS */
        if ((uOutputCount++ % 25u) == ZERO)
        {
            cMELog_F_LogDebug_v("UssCtrl: Populate burst.  Seq:%d, Step:%d, Index:%d", uCurFireSeqIdx, psCurFireSeqCmd->uCurSeqStep, psCurFireSeqCmd->uCurSeqRecord);
        }
#endif

        uDvrSnrEnableMap = ZERO;
        uAppSnrEnableMap = ZERO;

        /* SET RECEIVING SENSORS */
        for (uStepIdx = ZERO; uStepIdx < psFireSeqRec->uNumRcvrSnrs; uStepIdx++)
        {
            /* Get sensor number for receive */
            uSnrIdx = puRcvrSnrLocs[uStepIdx];

            if (uSnrIdx < US_D_MAX_NUM_SENSORS)
            {
                /* Look up sensor location for receive, in address (32 bit bitmap). */
                uSnrAddr = pauSnrAddrList[uSnrIdx] & uInstalledSnrMap;  /* This is where we can set a sensor to standby. */

                /* Note:  If sensor is installed, and we are measuring, then it is receiving automatically */
                if (uSnrAddr != ZERO)
                {
                    /* Used for sensor disconnect checks */
                    uAppSnrEnableMap |= (uint32_t)US_IDX_TO_BIT_LOC((uint32_t)uSnrIdx);
                    /* Store the request type for later, to set sensor measurement record. */
                    eReqEchoType[uSnrIdx] =  US_E_REQ_RECEIVE;
                    uReceiveMap |= uSnrAddr;
                }
            }
        }

        /* SET SENDING SENSORS */
        for (uStepIdx = ZERO; uStepIdx < psFireSeqRec->uNumSendSnrs; uStepIdx++)
        {
            /* Get sensor number for send */
            uSnrIdx = psSendSnrLocs[uStepIdx];

            if (uSnrIdx < US_D_MAX_NUM_SENSORS)
            {
                /* Look up sensor location for send, in address (32 bit bitmap). */
                uSnrAddr = pauSnrAddrList[uSnrIdx] & uInstalledSnrMap;

                if (uSnrAddr != ZERO)
                {
                    /* Store the request type for later, to set sensor measurement record. */
                    eReqEchoType[uSnrIdx] = eMeasEchoType[uSnrIdx];

                    /* Used for sensor disconnect checks */
                    uAppSendMap = (uint32_t)US_IDX_TO_BIT_LOC((uint32_t)uSnrIdx);
                    uAppSnrEnableMap |= uAppSendMap;
                    uSendMap |= uSnrAddr;
                    uSendingSensors  |= uAppSendMap;
                }
            }
        }

        /*
         * Group silence processing
         */

        /* Advance group silence count */
        if (uGrpSilenceRate != ZERO)
        {
            if (   (uGrpSilenceRate != US_D_CMD_ALWAYS_LISTENING) /* Always or on periodic rate. */
                && (uGrpSilenceCnt < uGrpSilenceRate))
            {
                uGrpSilenceCnt++; /* Increment count.  No Silence this time! */
            }
            else
            {
                uGrpSilenceCnt = ZERO; /* Restart the count.  */

                /* Clear senders who have been requested muted */
                uSendMap &= ~uDvrSilentBitMap;
                uSendingSensors &= (uint32_t)(~uSnrSilentBitMap);    /* PRQA S 4391,4461*/
            }
        }


        /*
         *   ****PERFORM FIRE SEQUENCE ARBITRATION ****
         *
         *   Determine what actually goes out on bus to sensors.
         *
         *   Populate TypeArray, for use by driver, to determine measurement request type.
         *
         */
        uBitMask = BIT0;
        for (uTypeIdx = ZERO; uTypeIdx < US_D_MAX_NUM_SENSORS_CONFIGURABLE; uTypeIdx++)
        {
            if ((uSendMap & uBitMask)!= 0u) /* This sensor is sending. */
            {
                uSnrIdx = uSnrAddrIdxList[uTypeIdx];
                sSendBurstCfg.TypeAry[uTypeIdx] = (uint8_t) UssSnrCmd_ConvSndTypeToBrstType(eReqEchoType[uSnrIdx]);
                uDvrSnrEnableMap |= uBitMask;  /* Enable this sensor */
            }
            else if ((uReceiveMap & uBitMask)!= 0u) /* This sensor is receiving only.*/
            {
                if (sSendBurstCfg.TypeAry[uTypeIdx] == (uint8_t)US_E_SEND_STANDBY)  /* Sensor not in use yet?*/
                {
                    /* We just send a receive command on unused sensors that are installed. */
                    sSendBurstCfg.TypeAry[uTypeIdx] = (uint8_t)  US_E_RECEIVE;
                    uDvrSnrEnableMap |= uBitMask;  /* Enable this sensor   */
                }
            }
            else
            {
                 /* This sensor is in standby by default. Do not enable.  */
            }

            uBitMask <<= ONE;
        }
    }
}

/* ===========================================================================
 * Name:	 UssSnrCmd_PopulateBurstCommand_AllRcv
 * Remarks:  DD-ID: {E0117B7E-3B01-43ac-90EF-344BB7B05561}
 * Req.-ID: 13520454
 * ===========================================================================*/
void UssSnrCmd_PopulateBurstCommand_AllRcv(void)
{
    uint32_t uBitMask;
    uint8_t  uTypeIdx;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo(); /* Get platform information about what sensors are installed. */
    uint32_t uInstalledSnrMap = psPlatPhysInfo->uInstSnrDvrAddrMask;

    (void)memset(sSendBurstCfg.TypeAry,(sint32_t) US_E_SEND_STANDBY, 32u);  /* Clear all sensor commands.  Sensor is Idle.  */
    (void)memset(eReqEchoType, (sint32_t)US_E_REQ_RECEIVE, US_D_MAX_NUM_SENSORS * sizeof(US_E_SendType_t));
    uDvrSnrEnableMap = ZERO;
    uBitMask = BIT0;
    for (uTypeIdx = 0; uTypeIdx < US_D_MAX_NUM_SENSORS_CONFIGURABLE; uTypeIdx++)   /* Scan map and check if was receiving, if not enable receive. */
    {
        if ((uInstalledSnrMap & uBitMask) != ZERO)   /* If sensor installed, set to receive */
        {
            sSendBurstCfg.TypeAry[uTypeIdx] = (uint8_t) US_E_RECEIVE;
            uDvrSnrEnableMap |= uBitMask;  /* Enable this sensor */
        }
        uBitMask <<= ONE;
    }

    /* Used for sensor disconnect checks */
    uAppSnrEnableMap =  psPlatPhysInfo->uInstSnrAppIdxBitMask;

    uSendingSensors = ZERO;

#if UART_SUPPORTED
    cMELog_F_LogDebug_v("UssCtrl: Populate burst.  Measurement: ALL RECEIVE ONLY");
#endif
}
/*===========================================================================
 * \brief Send PDCM Burst request to driver.
 *
 * \param none
 * \param none
 * \return none
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SendBurst
 * Remarks:  DD-ID: {038B0FC6-F925-4ae5-B7E8-84D8F3F7ED1B}
 * ===========================================================================*/
uint32_t UssSnrCmd_SendBurst(void)
{
    uint32_t uStatus;
    UssSnrCmd_SetBurstCmdDone(ME_FALSE);
    UssSnrCmd_StartSnrMeasTimer();

    sSendBurstCfg.pdcm_period = uPdcmPeriod;
    UssDBG_SendBurstCfgUsed = sSendBurstCfg;
    uStatus  =  US_SnrDrvMgr_F_ReqSendBurstWDelayCmd(uDvrSnrEnableMap, 
                                                              uPDCM_DelayInDriverCnts,      /* See comments on variable.  */
                                                              ZERO,                         /* User Data  */
                                                              sizeof(US_S_ClusterBurstCmd_t),
                                                              (uint8_t*) &sSendBurstCfg,
                                                              US_D_SPI_BURST_DATA_BUFF_SIZE,
                                                              uSpiBurstDataBuff,
                                                              &UssSnrCmd_CmdCallback_SendBurst);
    if (uStatus != ME_OK)
    {
        /*
         * Possible errors:
         * ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH
         * ERROR_US_SNRDRVCOM_PARAMETER
         */

        UssSnrCmd_SetBurstCmdDone(ME_TRUE); /* Terminate the wait for the command finish.  */
    }

    return uStatus;
}

/*===========================================================================
 * \brief Get the last sensor enable map in application format.
 *
 * \param none
 * \param none
 * \return uint32_t uEnableMap
 * \remarks Bitfield compressed, no gaps.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_uGetAppEnableMap
 * Remarks:  DD-ID: {3F8C2AF2-7A6D-4876-8B84-AD0B50A5AF2A}
 * Req.-ID:15222445
 * ===========================================================================*/
uint32_t UssSnrCmd_uGetAppEnableMap(void)
{
    return uAppSnrEnableMap;
}

/*===========================================================================
 * \brief Get the last sensor enable map.
 *
 * \param none
 * \param none
 * \return uint32_t uEnableMap
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_uGetDvrEnableMap
 * Remarks:  DD-ID: {5E90C8E3-C4DE-4417-B4DF-9FDFA6ABA65B}
 *  Req.-ID: 13520454
 * ===========================================================================*/
uint32_t UssSnrCmd_uGetDvrEnableMap(void)
{
    return uDvrSnrEnableMap;
}

/*===========================================================================
 * \brief Status of the present burst command callback.
 *
 * \param none
 * \param none
 * \return bool_t Has burst callback been received?
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_bIsCmdDone
 * Remarks:  DD-ID: {D8371D51-62C9-4edc-B62E-5186C43A9489}
 * Req.-ID: 13396047
 * ===========================================================================*/
bool_t UssSnrCmd_bIsCmdDone(void)
{
    return (bool_t) bBurstCmdDone;
}

/*===========================================================================
 * \brief Set the present state of the burst command callback.
 *
 * \param bool_t set present state of the burst command callback.
 * \param none
 * \return none
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SetBurstCmdDone
 * Remarks:  DD-ID: {3CA22F75-2263-4018-B022-A485BD19A072}
 *  Req.-ID: 13395870
 * ===========================================================================*/
void UssSnrCmd_SetBurstCmdDone(bool_t _bBurstCmdDone)
{
    bBurstCmdDone = _bBurstCmdDone;
}

/*===========================================================================
 * \brief Get the present state of the sending sensors bitmap.
 *
 * \param none
 * \param none
 * \return  uint32_t uSendingSensors bitmap for this measurement cycle.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_uGetSendingSensors
 * Remarks:  DD-ID: {20152310-8E67-492a-B32D-19B4247CD58F}
 * Req.-ID: 13389484
 * ===========================================================================*/
uint32_t UssSnrCmd_uGetSendingSensors(void)
{
    return uSendingSensors;
}

/*===========================================================================
 * \brief Store burst config to local static structure..
 *
 * \param none
 * \param none
 * \return none
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SetBurstConfig
 * Remarks:  DD-ID: {602871FA-B3AD-4910-964F-7D899356F9CE}
 * ===========================================================================*/
void UssSnrCmd_SetBurstConfig(uint8_t uBusNum, const US_S_BurstConfig_t *psBurstConfig)
{
    /* Store burst configuration for this sequence step into local static struct eSendBurstCfg */
    /*\for(uBusNum = ZERO; uBusNum< US_D_MAX_NUM_BUS; uBusNum++) */

    /*
     * Put logic for uPDCM_CountExtention here.
     */
    uPDCM_CountExtention = ZERO;

    if( uBusNum < US_D_MAX_NUM_BUS )
    {
        sSendBurstCfg.ProfileType[uBusNum] = (uint8_t) eaReceiveProfile[uBusNum]; /*refresh  */

        sSendBurstCfg.SnrType             = psBurstConfig->SnrType;  /*not used - remove one day  */
        sSendBurstCfg.uNumPDCM[uBusNum]   = psBurstConfig->uNumPDCM + uPDCM_CountExtention;     /* PRQA S 2985*/

        sSendBurstCfg.Cfg[uBusNum].CompGain         = psBurstConfig->sSnrCfg.CompGain;
        sSendBurstCfg.Cfg[uBusNum].EchoInfo         = psBurstConfig->sSnrCfg.EchoInfo;
        sSendBurstCfg.Cfg[uBusNum].EnvOutput        = psBurstConfig->sSnrCfg.EnvOutput;
        sSendBurstCfg.Cfg[uBusNum].IsCalibration    = psBurstConfig->sSnrCfg.IsCalibration;
        sSendBurstCfg.Cfg[uBusNum].IsNFDMode        = psBurstConfig->sSnrCfg.IsNFDMode;
        sSendBurstCfg.Cfg[uBusNum].Update           = psBurstConfig->sSnrCfg.Update;
        sSendBurstCfg.Cfg[uBusNum].MeasurementTime  = psBurstConfig->sSnrCfg.MeasurementTime;
        sSendBurstCfg.Cfg[uBusNum].G_digBoost       = psBurstConfig->sSnrCfg.G_digBoost;

        /* PBNC missing - that is fine for F22A, add later */
    }
}

/* ===========================================================================
 * Name:	 UssSnrCmd_SetBurstConfigGlobally
 * Remarks:  DD-ID: {8CA2FFAA-DB56-40bf-AE99-F2C6607445A0}
 * Req.-ID: 17350940
 * ===========================================================================*/
void UssSnrCmd_SetBurstConfigGlobally(const US_S_BurstConfig_t *psBurstConfig)
{
    uint8_t uBusNum;

    for(uBusNum = ZERO; uBusNum< US_D_MAX_NUM_BUS; uBusNum++)
    {
        UssSnrCmd_SetBurstConfig(uBusNum, psBurstConfig);
    }
}

/* ===========================================================================
 * Name:	 UssSnrCmd_SetBurstConfigByGroupID
 * Remarks:  DD-ID: {F60CFEA8-91A9-41da-BC6C-1B73D1925F6A}
 * Req.-ID: 13396047
 * ===========================================================================*/
void UssSnrCmd_SetBurstConfigByGroupID(uint8_t uGrpIdx, const US_S_BurstConfig_t *psBurstConfig)
{
    uint8_t uSnrGrpIdx;
    uint8_t uSnrIdx;
    uint8_t uNumSnrsInGrp;
    uint8_t uBusNum;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    const uint8_t * pSnrBusList = UssCtrl_pauGetSnrBusList();
    
    if( uGrpIdx < US_D_PHYS_GRP_MAX )
    {
        uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

        /*
         * Perform for each sensor in group, with associated indirect sensors.
         */
        for (uSnrGrpIdx = ZERO; uSnrGrpIdx < uNumSnrsInGrp; uSnrGrpIdx++)
        {
            /* Retrieve the index to the sensor, from the physical group data */
            uSnrIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uSnrGrpIdx];

            /* Get the bus number of this sensor */
            uBusNum = pSnrBusList[uSnrIdx];

            /* Set the receive profile */
            if (uBusNum < US_D_MAX_NUM_BUS)
            {
                UssSnrCmd_SetBurstConfig(uBusNum, psBurstConfig);
            }
        }
    }
}
/*===========================================================================
 * \brief Set the present burst profiles.
 *
 * \param uint8_t uBusNum Bus number for which to set the profile.
 * \param US_E_ProfileType_t eReceiveProfile for current measurement cycle.
 * \return none
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SetRcvProfiles
 * Remarks:  DD-ID: {30A179AF-8A70-417b-A5C1-C8D92FCBD614}
 * Req.-ID: 13420748
 * ===========================================================================*/
void UssSnrCmd_SetRcvProfiles(uint8_t uBusNum, US_E_ProfileType_t eReceiveProfile)
{
    if (uBusNum < US_D_MAX_NUM_BUS)
    {
        eaReceiveProfile[uBusNum] = eReceiveProfile;
        sSendBurstCfg.ProfileType[uBusNum] = (uint8_t) eaReceiveProfile[uBusNum];
    }
}

/*===========================================================================
 * \brief Set the present burst profiles by group DD.
 *
 * \param uint8_t uGrpIdx Group indexfor which to set the profile.
 * \param US_E_ProfileType_t eReceiveProfile for current measurement cycle.
 * \return none
 * \remarks Will override any bus within the group specified.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SetRcvProfilesByGroupID
 * Remarks:  DD-ID: {08332186-8AC1-4817-A674-501111CC2D98}
 * Req.-ID: 14958936
 * ===========================================================================*/
void UssSnrCmd_SetRcvProfilesByGroupID(uint8_t uGrpIdx, US_E_ProfileType_t eReceiveProfile)
{
    uint8_t uSnrGrpIdx;
    uint8_t uSnrIdx;
    uint8_t uNumSnrsInGrp;
    uint8_t uBusNum;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    const uint8_t * pSnrBusList = UssCtrl_pauGetSnrBusList();

    if( uGrpIdx < US_D_PHYS_GRP_MAX )
    {
        uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

        /*
         * Perform for each sensor in group, with associated indirect sensors.
         */
        for (uSnrGrpIdx = ZERO; uSnrGrpIdx < uNumSnrsInGrp; uSnrGrpIdx++)
        {
            /* Retrieve the index to the sensor, from the physical group data */
            uSnrIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uSnrGrpIdx];

            /* Get the bus number of this sensor */
            uBusNum = pSnrBusList[uSnrIdx];

            /* Set the receive profile */
            if (uBusNum < US_D_MAX_NUM_BUS)
            {
                eaReceiveProfile[uBusNum] = eReceiveProfile;
                sSendBurstCfg.ProfileType[uBusNum] = (uint8_t) eaReceiveProfile[uBusNum];
            }
        }
    }
}

/* ===========================================================================
 * Name:	 UssSnrCmd_SetMeasEchoTypeBySnrIdx
 * Remarks:  DD-ID: {A8A1F847-7A3C-4248-827A-A850A34F96C9}
 * Req.-ID: 13414924
 * ===========================================================================*/

void UssSnrCmd_SetMeasEchoTypeBySnrIdx(uint8_t uSnrIdx, US_E_SendType_t eSndType)
{
    eMeasEchoType[uSnrIdx] = eSndType;
}

/* ===========================================================================
 * Name:	 UssSnrCmd_SetMeasEchoTypeByGroupIdx
 * Remarks:  DD-ID: {ACC7EC1E-6D1B-4765-901F-423B04A4EAB6}
 * ===========================================================================*/
void UssSnrCmd_SetMeasEchoTypeByGroupIdx(uint8_t uGrpIdx, US_E_SendType_t eSndType)
{
    uint8_t uSnrGrpIdx;
    uint8_t uSnrIdx;
    uint8_t uNumSnrsInGrp;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    
    if( uGrpIdx < US_D_PHYS_GRP_MAX )
    {
        uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

        /*
         * Perform for each sensor in group, with associated indirect sensors.
         */
        for (uSnrGrpIdx = ZERO; uSnrGrpIdx < uNumSnrsInGrp; uSnrGrpIdx++)
        {
            /* Retrieve the index to the sensor, from the physical group data */
            uSnrIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uSnrGrpIdx];

            /* Set the send type */
            eMeasEchoType[uSnrIdx] = eSndType;
        }
    }
}

/*===========================================================================
 * \brief Get the present state of the burst profiles
 *
 * \param none
 * \param none
 * \return uint32_t *eaReceiveProfile array for current measurement cycle.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_uGetRcvProfiles
 * Remarks:  DD-ID: {080CF196-7D69-4258-AEC2-C5E304A8ADDC}
 * Req.-ID: 13389484
 * ===========================================================================*/
US_E_ProfileType_t UssSnrCmd_uGetRcvProfiles(uint8_t uBusNum)
{
    if (uBusNum < US_D_MAX_NUM_BUS)
    {
        return eaReceiveProfile[uBusNum];
    }

    return US_E_PROFILE_NONE;  /*Intentionally sent different value considered as error value*/
}

/*===========================================================================
 * \brief Request temperature from all active sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSensorTempCmd
 * Remarks:  DD-ID: {4C12411A-8629-4467-AA4D-F8E9CE80489C}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSensorTempCmd(uint32_t uSnrMap)
{
    uint32_t uStatus = US_SnrDrvMgr_F_ReqSensorTempCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_SnrTempCmd);

    return uStatus;
}

/*===========================================================================
 * \brief Request diagnostic result from all active sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqDiagnosticResultsCmd
 * Remarks:  DD-ID: {05995105-7225-4664-9982-17E0865C2518}
  
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqDiagnosticResultsCmd(uint32_t uSnrMap)
{
    uint32_t uStatus = US_SnrDrvMgr_F_ReqSensorDiagnosticResultCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_DiagResultCmd);

    return uStatus;
}

/*===========================================================================
 * \brief Request SensorFreqCmd from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSensorFreqCmd
 * Remarks:  DD-ID: {067A481D-BD76-42d5-836E-807161673BD3}
 * Req.-ID: 13409667
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSensorFreqCmd(uint32_t uSnrMap)
{
    uint32_t uStatus,UserID;
    UserID = US_D_SENSORS_FREQ_DATA_PWD;
    uStatus = US_SnrDrvMgr_F_ReqSensorFreqCmd(uSnrMap, UserID, 0, NULL, US_D_SENSORS_FREQ_DATA_BUFF_SIZE, uSensorFreqBuff, UssSnrCmd_ReqFreqCmdCallback);
    return uStatus;
}


/*===========================================================================
 * \brief Request AATG1 from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint16_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqAATG1Cmd
 * Remarks:  DD-ID: {191896FC-66BF-4995-8979-FE697A5141F1}
 * Req.-ID: 13420535
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqAATG1Cmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqAATG1Cmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request AATG2 from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqAATG2Cmd
 * Remarks:  DD-ID: {93AF1F66-5683-4da7-A2B4-028C317D3296}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqAATG2Cmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqAATG2Cmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request BurstTypeCfg from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqBurstTypeCfgCmd
 * Remarks:  DD-ID: {9518D1A6-4C27-4ab1-AD84-91B6147AB27C}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqBurstTypeCfgCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqBurstTypeCfgCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request CalGain from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqCalGainCmd
 * Remarks:  DD-ID: {2F74CC78-8615-4638-A1B6-5061A2F477C2}
 * Req.-ID: 13520454
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqCalGainCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqCalGainCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request ChirpBW from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqChirpBWCmd
 * Remarks:  DD-ID: {013CFE14-4293-4265-8B7F-D3BEF365133E}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqChirpBWCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqChirpBWCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request CPSMeasGain from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqCPSMeasGainCmd
 * Remarks:  DD-ID: {B19FAC56-A97B-4313-8E12-36F3F4462E5F}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqCPSMeasGainCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqCPSMeasGainCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request Current from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqCurrentCmd
 * Remarks:  DD-ID: {6912495E-7F0E-4150-B237-81CFA4D4C521}
 * Req.-ID: 13411731
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqCurrentCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqCurrentCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);
    return uStatus;
}


#if (QAC_WARNING_FIX  ==  ME_FALSE)
/*===========================================================================
 * \brief Request EDIChannel from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqEDIChannelCmd
 * Remarks:  DD-ID: {EB9D24BA-03F7-44f1-BF5B-1A8770401F29}
 * Req.-ID: 13409997
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqEDIChannelCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqEDIChannelCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request EnvCfg from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqEnvCfgCmd
 * Remarks:  DD-ID: {BC1475E1-00CF-44c2-9FF9-2EB3373EBE74}
 * Req.-ID: 13427026
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqEnvCfgCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqEnvCfgCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request EnvData from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqEnvDataCmd
 * Remarks:  DD-ID: {3F0F0168-ACF0-45c7-8B3C-974ED9A0DA68}
 * Req.-ID: 13427026
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqEnvDataCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqEnvDataCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}

/*===========================================================================
 * \brief Request EnvFiltCfg from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqEnvFiltCfgCmd
 * Remarks:  DD-ID: {5C7EED39-4137-4391-82E9-D0E36E7DA0C1}
 * Req.-ID: 13411776
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqEnvFiltCfgCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqEnvFiltCfgCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request FC from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqFCCmd
 * Remarks:  DD-ID: {8075D492-0C0D-4ab9-9EDF-96C557E25981}
 * Req.-ID: 13408308
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqFCCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqFCCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request FixPathCfg from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqFixPathCfgCmd
 * Remarks:  DD-ID: {5E0A6D8F-21EE-400e-95B8-17E28D06904D}
 * Req.-ID: 13409758
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqFixPathCfgCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqFixPathCfgCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request FTC from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqFTCCmd
 * Remarks:  DD-ID: {3FE6338E-EC60-423e-9F45-78CE6C228C4A}
 * Req.-ID: 13420533
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqFTCCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqFTCCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request Gain from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqGainCmd
 * Remarks:  DD-ID: {20B9ACF6-ACFB-40a1-B997-3FC9C72A40DC}
 * Req.-ID:13420543
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqGainCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqGainCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request anaMeasBegin from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqGanaMeasBeginCmd
 * Remarks:  DD-ID: {26683EFD-FB62-4da2-9B4B-F3D49CC98446}
 * Req.-ID: 13427026
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqGanaMeasBeginCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqGanaMeasBeginCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request MaxEchoNum from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqMaxEchoNumCmd
 * Remarks:  DD-ID: {FE1BB84B-1A10-4aa5-9AAD-90651C9BE39D}
 * Req.-ID: 13409758
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqMaxEchoNumCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqMaxEchoNumCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request NFD from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqNFDCmd
 * Remarks:  DD-ID: {31A3419F-E38C-4913-8485-05A44474AEBD}
 * Req.-ID: 13409860
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqNFDCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqNFDCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request NormalBurstNum from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqNormalBurstNumCmd
 * Remarks:  DD-ID: {732AAD98-5560-4727-9B17-268FAF3DDF14}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqNormalBurstNumCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqNormalBurstNumCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request Profile from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqProfileCmd
 * Remarks:  DD-ID: {ED7465BE-2152-477b-A7CE-1E2A3B57787B}
 * Req.-ID: 13396025
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqProfileCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqProfileCmd(uSnrMap, ZERO, ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request ProfilePlus from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqProfilePlusCmd
 * Remarks:  DD-ID: {600F4BD9-E6FE-40de-8F5E-D91E30C95E44}
 *  Req.-ID:13420529
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqProfilePlusCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqProfilePlusCmd(uSnrMap, ZERO, ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request RingingComp from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqRingingCompCmd
 * Remarks:  DD-ID: {A5E41202-9DE5-4af2-932E-AF5B5D96825D}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqRingingCompCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqRingingCompCmd(uSnrMap, ZERO, ZERO,NULL,US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request SendBurstWDelay from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSendBurstWDelayCmd
 * Remarks:  DD-ID: {5415B435-A238-4cfe-8F04-EC0B025E66B7}
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSendBurstWDelayCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSendBurstWDelayCmd(uSnrMap, ZERO, ZERO, ZERO, (uint8_t *)ZERO, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request SensorEEFlagCTRL from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSensorEEFlagCTRLCmd
 * Remarks:  DD-ID: {E9583A89-ACCD-480c-B34F-1F85B9378E22}
 * Req.-ID: 13420547
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSensorEEFlagCTRLCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSensorEEFlagCTRL(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request SensorEEPROM from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSensorEEPROMCmd
 * Remarks:  DD-ID: {A9DC03D1-786F-4758-9A4E-71896F2303A4}
 * Req.-ID: 13409667
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSensorEEPROMCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSensorEEPROMCmd(uSnrMap, ZERO, ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request SensorOPMode from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSensorOPModeCmd
 * Remarks:  DD-ID: {58D9753C-98F4-462f-9602-3759E30D1FB4}
 * Req.-ID: 13409667
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSensorOPModeCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSensorFreqCmd(uSnrMap, ZERO,ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request SensorRegister from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSensorRegisterCmd
 * Remarks:  DD-ID: {879F1E9E-F01E-4c98-8058-5EAA9AE4EC57}
 * Req.-ID: 13409667
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSensorRegisterCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSensorEEPROMCmd(uSnrMap, ZERO, ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request STC from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSTCCmd
 * Remarks:  DD-ID: {F1CCE0DC-DF2C-4186-8A87-FA5985E88709}
 * Req.-ID: 13409667
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSTCCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSTCCmd(uSnrMap, ZERO, ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}


/*===========================================================================
 * \brief Request STG from selected sensors.
 *
 * \param uint32_t uSnrMap selected sensors.
 * \param none
 * \return uint32_t uStatus if command was a success.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ReqSTGCmd
 * Remarks:  DD-ID: {6E197C52-DEC2-4524-86DA-C710A6D9AF86}
 * Req.-ID: 13409667
 * ===========================================================================*/
uint32_t UssSnrCmd_ReqSTGCmd(uint32_t uSnrMap)
{
    /* NOT YET IMPLEMENTED */

    uint32_t uStatus = US_SnrDrvMgr_F_ReqSTGCmd(uSnrMap, ZERO, ZERO,NULL, US_D_CMD_RESP_DATA_BUFF_SIZE, uSpiCmdDataBuff, UssSnrCmd_CmdCallback_NotImplemented);

    return uStatus;
}
#endif
/* ===========================================================================
 * Name:	 peGetReqEchoType
 * Remarks:  DD-ID: {8C0E29A7-3ED7-439d-AFAD-1871A49F72E2}
 * ===========================================================================*/
US_E_SendType_t * peGetReqEchoType(void)
{
    return eReqEchoType;
}

/* ===========================================================================
 * Name:	 peGetMeasEchoType
 * Remarks:  DD-ID:{94AC6947-BE52-4a72-93A4-127DE802EFE3}
 * ===========================================================================*/
US_E_SendType_t * peGetMeasEchoType(void)
{
    return eMeasEchoType;
}

/* ===========================================================================
 * Name:	 psGetSendBurstCfg
 * Remarks:  DD-ID: {51DD5D4D-EC0F-4dbd-9E4A-ADA2FCD177E9}
 * Req.-ID: 13520454
 * ===========================================================================*/
US_S_ClusterBurstCmd_t * psGetSendBurstCfg(void)
{
    return &sSendBurstCfg;
}
#if (QAC_WARNING_FIX  ==  ME_FALSE)
/* DD-ID: {EAB70115-0802-49e2-971B-3680B3C4B67E} */
void UssSnrCmd_SetPdcmPeriod(uint8_t pdcm_period)
{
    uPdcmPeriod = pdcm_period;
}
#endif
/*
 * Sensor Commands with No Interface for App Layer
 */
#if 0

/* Not used at application layer. Used only by driver at initialization */
US_SnrDrvMgr_F_AutoAddressingCmd
US_SnrDrvMgr_F_ReqSnrFWVer
US_SnrDrvMgr_F_ReqSensorIDCmd

/* This command does not seem to work thus not implemented. */
US_SnrDrvMgr_F_ReqSensorAmbiTempCmd

/* These commands have a simple callback and are ready */
/* to call from the driver directly. */
/* Add commands as necessary.*/
US_SnrDrvMgr_F_SetAATG1Cmd
US_SnrDrvMgr_F_SetAATG2Cmd
US_SnrDrvMgr_F_SetATGCmd
US_SnrDrvMgrF_SetBurstTypeCfgCmd
US_SnrDrvMgr_F_SetCalGainCmd
US_SnrDrvMgr_F_SetChirpBWCmd
US_SnriNvMgr_F_SetCurrentCmd
US_SnriNvMgr_F_SetEDIChannelCmd
US_SnrDrvMgr_F_SetEnvCfgCmd
US_SnrDrvMgr_F_SetEnvFiltCfgCmd
US_SnriNvMgr_F_SetFCCmd
US_SnriNvMgr_F_SetFixPathCfgCmd
US_SnrDrvMgr_F_SetFTCCmd
US_SnrDrvMgr_F_SetGainCmd
US_SnriNvMgr_F_SetGanaMeasBeginCmd
US_SnriNvMgr_F_SetMaxEchoNumCmd
US_SnrDrvMgr_F_SetNFDCmd
US_SnrDrvMgr_F_SetNormalBurstNumCmd
US_SnriNvMgr_F_SetProfileCmd
US_SnriNvMgr_F_SetProfilePlusCmd
US_SnrDrvMgr_F_SetSensorAmbiTempCmd
US_SnrDrvMgr_F_SetSensorEEFlagVarCIRLCmd
US_SnriNvMgr_F_SetSensorEEPROMCmd
US_SnriNvMgr_F_SetSensorOPModeCmd
US_SnrDrvMgr_F_SetSensorRegisterCmd
US_SnrDrvMgr_F_SetSICCmd
US_SnriNvMgr_F_SetSTGCmd
US_SnrDrvMgr_F_ReqDSIMasterRegCmd

#endif




