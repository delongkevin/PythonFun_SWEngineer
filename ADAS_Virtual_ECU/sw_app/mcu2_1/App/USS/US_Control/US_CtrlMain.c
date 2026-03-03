
/*
 * \file UssCtrlMain.c
 *
 * \date Created on: Mar 3, 2021
 * \author jonapais
 * \brief Main Finite State Machine for USS Controller.
 *
 */
#include "US_CtrlMain.h"
#include "US_CtrlPlatformSpecific.h"
#include "US_CtrlEnvCheckFsm.h"
#include "US_CtrlFireSeqSelect.h"
#include "US_CtrlInterface.h"
#include "US_CtrlEnvCheckFsm.h"
#include "US_SysMgr_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_Ctrl_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_ME_Typedefs_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_Odometry_Global.h"
#include "US_SnrDynAdjust.h"

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
    #include "Siul2_Port_Ip.h"
    #include "Siul2_Dio_Ip.h"
    #include "Application_Header.h"
    static uint32 uDebugOutputCount;
#endif

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_SnrCntrl_CsmIf.h"
#include "Us_SnrDrv_CsmIf.h"
#endif

#ifdef PLAYBACK_SW_ENABLE
  #define US_D_IS_PLAYBACK_MODE           (ME_TRUE)
#else
  #define US_D_IS_PLAYBACK_MODE           (ME_FALSE)
#endif

#if(US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)
#define US_D_DIAG_MSG_PERIODIC_RATE (40u) /* 40 ms */
#endif
#define US_D_MAX_ERROR_CNT_BEFORE_XCVR_RESET  (4u)

static volatile uint8_t g_LAUD_Get1HzFreqData = 1u;

/* LOCAL STATIC VARIABLES */
static UssCtrl_eMainState_t eMainState = USSCTRL_FSM_IDLE;
static bool_t bSystemRunning = ME_FALSE;
static uint8_t uReceiveErrorCnt = ZERO;
static uint32_t uBurstStartTimeMs = ZERO;
static uint32_t uBurstSendTimeMs = ZERO;
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)               
static uint32_t uLastDiagCheckTimeMs = ZERO;
#endif
static uint32_t uBurstStatus = ME_OK;
static volatile bool_t bIsNewReceivedSnrData =(bool_t)ME_FALSE;
static bool_t bIsNewPlaybackDataAvailable = (bool_t)ME_FALSE;


#if(US_CSM_ENABLE == ME_TRUE)
static UsCsm_LocalStateId_Type ucfsmstatereq = US_CSM_LOCAL_STATE_INIT;
#endif

static UssCtrl_eTempAdjState_t  eTempAdjState = USSCTRL_TEMPADJ_IDLE;
static UssCtrl_eSensorCfgState_t  eSensorCfgState = USSCTRL_SENSORCFG_IDLE;

/* STATIC FN PROTOTYPES */
static void UssCtrl_MainFsmStart(void);
static void UssCtrl_MainFsmExecute(void);
static void UssCtrl_MainFsmPostProcessing(void);
static void UssCtrl_ProcessErrorFlags(void);
static void UssCtrl_ClearErrorFlags(void);
static void UssCtrl_TempAdjControl(void);
static void UssCtrl_SensorCfgControl(void);

/*===========================================================================
 * \brief Initialize the main USS control state machine.
 *
 * \param none
 * \param none
 * \return none
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_MainInit
 * Remarks:  DD-ID: {AD1AEC7A-8E4A-4649-830D-3D61642933E3}
 * ===========================================================================*/
void UssCtrl_MainInit(void)
{
    uBurstStartTimeMs = ZERO;   
    uBurstSendTimeMs = ZERO; 
    uBurstStatus = ME_OK;
#ifdef UART_SUPPORTED
    cMELog_F_LogDebug_v("UssCtrl: Main ===============================================");
#endif
    UssDynAdj_Init();
}

/*===========================================================================
 * \brief Entry point of main USS Control state machine.
 * Called by RTOS task at a periodic rate.
 *
 * \param none
 * \param none
 * \return none
 * \remarks UssCtrl_eMainState is the state of the Fsm.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_Main
 * Remarks:  DD-ID: {91A06E50-4E85-4ccc-A0CD-E903084D93FC}
 * ===========================================================================*/
void UssCtrl_Main(void)
{
    UssCtrl_MainFsmStart();
    UssCtrl_MainFsmExecute();
    UssCtrl_MainFsmPostProcessing();           
}

/*===========================================================================
 * \brief Execute the pre-processing of the USS Control FSM.
 *
 * \param none
 * \param none
 * \return none
 * \remarks UssCtrl_eMainState is the state of the Fsm.
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_MainFsmStart
 * Remarks:  DD-ID: {77968C08-2FC4-4164-BD4C-B0FF71BAFEA9}
 * ===========================================================================*/
 
static void UssCtrl_MainFsmStart(void)
{
	uint16_t SnrVer; 
	uint8_t Mode;
    bool_t  bPlaybackmode,bCmdDone,bHalt;
    UsCsm_LocalStateId_Type csm_state;
	UssMgr_e_SysState_t SysState = UssMgr_eGetSysState();
    if(  ((SysState == SYSMGR_SYS_READY)
       || (SysState == SYSMGR_SYS_DIAGNOSTIC))
	   #if(US_CSM_ENABLE == ME_TRUE)
       && (ucfsmstatereq == US_CSM_LOCAL_STATE_ACTIVE)
	   #endif
	   )
    {
        if (bSystemRunning == (bool_t)ME_FALSE) /*Detect first run*/
        {
            /*
             * Whenever we switch into the READY/DIAGNOSTIC state we should
             * start the fire sequence from initialization state.
             *
             * Initialize Fire Sequence Control Layer.
             */
            /* comment UssCtrl_SetFireSequenceInit()*/
            /* Init of mode control variables will force update of firing seq calls in UssMgr_ProcessModeControl() */
            UssMgr_MgrModePublicInit();
        }
        else
        {
          /*Do nothing*/
        }

        bSystemRunning =  (bool_t)ME_TRUE;
#if(US_CSM_ENABLE == ME_TRUE)
        ucfsmstatereq = US_CSM_LOCAL_STATE_ACTIVE;
#endif
    }
    else
    {
        bSystemRunning =  (bool_t)ME_FALSE;
        eMainState = USSCTRL_FSM_IDLE;  /*Ensure we are in idle if system is not ready.*/
		US_MgrSetup_PrevParkingMode(US_PARKMODE_STANDBY);
        csm_state  =   Us_SnrDrv_GetState_Csm(US_CSM_SNR_DRV_INSTANCE_ID_0);
 	    if(US_CSM_LOCAL_STATE_ACTIVE == csm_state)
          {
			if(SysState == SYSMGR_SYS_CONFIG)
			{
				if(eSensorCfgState != USSCTRL_SENSORCFG_IDLE)
				{
					UssCtrl_SensorCfgControl();
				}
			}
		}

    }

    /* If the system is up and running, we can begin USS measurements */
    if ((bool_t)ME_TRUE == bSystemRunning)
    {
        UssCtrl_PerformSnrMarWriteChk(); /* Always check, in case initiated via direct request via CAN.*/

        /* Update Cals when appropriate */
       (void)UssCtrl_CheckForSnrCalChange(); 

        /* Update odometry next step */

        UssOdo_PerformNextOdometryStep(); /*assuming that UssMgr_Main is called every 10 ms*/
         SnrVer  = US_SnrCfg_Get_SnrFWVer();
		 Mode = US_SnrCfg_Get_Sensor_opmode();
        if ((SnrVer == (uint16_t)QM_SNR_FW_VER) || (Mode != (uint8_t)SENSOR_OP_NORMAL))
        {
			/* for old command format*/
            UssCtrl_UpdateSnrIntTemperature();  /* ASIL sensors receive temperature info as part of diag message response.*/
        }

        UssMgr_ProcessModeControl(); /* Select Mode */

        /* Kick off the Control Main State Machine */
        /*KPK-QAC Fix : Need to suppress, US_D_IS_PLAYBACK_MODE is used for custom build purpose*/
        bPlaybackmode =  UssCtrl_bIsSysInPlaybackMode();
        bCmdDone   =  UssSnrCmd_bIsCmdDone();
        bHalt   = UssCtrl_bIsCtrlFsmHalted();
        if (bPlaybackmode == (bool_t)ME_TRUE) /*PRQA S 2992,2996 */ /* Playback mode */
        {
            eMainState = USSCTRL_FSM_DATA_PLAYBACK;
        }
        else if ((bool_t)ME_TRUE == bHalt)
        {
            eMainState = USSCTRL_FSM_IDLE;
        }
        else if ((USSCTRL_FSM_IDLE == eMainState) && ((bool_t)ME_TRUE == bCmdDone))		 /*unsigned type is being used as right handed operand , logical operator(&&) */
        {
			if(eTempAdjState != USSCTRL_TEMPADJ_IDLE)
			{
				UssCtrl_TempAdjControl();
			}
			else
			{
				eMainState = USSCTRL_FSM_SEND_BURST; /* Redundant for Safety. Idle state should automatically transition to Burst.*/
			}
        }
        else
        {
          /* Do nothing */
        }
    }
}
/*===========================================================================
 * \brief Execute the sensor configure since temperature change
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SensorCfgControl
 * Remarks:  DD-ID:{65AECB98-D6E2-49c8-9E3A-42AAF9DED6E8}
 * Req.-ID:
 * ===========================================================================*/

static void UssCtrl_SensorCfgControl(void)
{
	bool_t status;
    switch(eSensorCfgState)
	{
	case USSCTRL_SENSORCFG_IDLE:
		break;
	case USSCTRL_SENSORCFG_PENDING:
		UssCtrl_SnrConfigure_Start();
		eSensorCfgState  = USSCTRL_SENSORCFG_DOING;
		break;
	case USSCTRL_SENSORCFG_DOING:
        status = UssCtrl_SnrCfg_GetDoneStatus();
		if(status == (bool_t)ME_FALSE)
		{
			UssCtrl_CfgSensor_Task();
		}
		else
		{
			eSensorCfgState  = USSCTRL_SENSORCFG_IDLE;
		}
		break;
	default:  /* empty */
		break;
	}
}
/*===========================================================================
 * \brief Execute the sensor configure since temperature change
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_TempAdjControl
 * Remarks:  DD-ID:{A8456964-1B2B-451d-98DA-AB86FFD64AE8}
 * Req.-ID:
 * ===========================================================================*/

static void UssCtrl_TempAdjControl(void)
{
	bool_t status;
 	switch(eTempAdjState)
	{
	case USSCTRL_TEMPADJ_IDLE:
		break;
	case USSCTRL_TEMPADJ_PENDING:
		UssCtrl_SnrCalAdj_Start();
		eTempAdjState  = USSCTRL_TEMPADJ_DOING;
		break;
	case USSCTRL_TEMPADJ_DOING:
        status =  UssCtrl_SnrCalAdj_GetDoneStatus();
		if(status == (bool_t)ME_FALSE)
		{
		    UssCtrl_SnrCalAdj_Task();
		}
		else
		{
			eTempAdjState  = USSCTRL_TEMPADJ_IDLE;
		}
		break;

	default: /* empty */
		break;
	}
}

/*===========================================================================
 * \brief Execute the main USS control state machine.
 * \param none
 * \param none
 * \return none
 * \remarks UssCtrl_eMainState is the state of the Fsm.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_MainFsmExecute
 * Remarks:  DD-ID: {6A761176-D118-472d-831F-79223995A255}
 * ===========================================================================*/
static void UssCtrl_MainFsmExecute(void)
{
    bool_t bExecuteFsmLoop = (bool_t)ME_TRUE;
   bool_t bIsError = (bool_t)ME_FALSE; /* No error.*/
   bool_t bCmdDone;
   uint32_t tmp;
   uint16_t delaytime;
   uint8_t TrcvrStatus,IntBState;
    while(((bool_t)ME_TRUE == bSystemRunning) && ((bool_t)ME_TRUE == bExecuteFsmLoop))  /*QAC : 4558,4115 unsigned type is being used as right handed operand , logical operator(&&) */
    {
        /*
         * Assume no follow on state, if needed it is manually activated by setting to bExecuteFsmLoop = ME_TRUE.
         * Set to ME_FALSE after immediately now.  Keep this a non Blocking loop, in general,
         * that may have a few states in a row, but nothing that takes too long.
         * Have exit strategy somewhat that is deterministic. - Jon
         */
        bExecuteFsmLoop = (bool_t)ME_FALSE;

        /*\cMELog_F_LogDebug_v("UssCtrl: CTRL MAIN FSM: bExec = %d, State = %d", bExecuteFsmLoop, eMainState); */
        switch (eMainState)
        {
            case USSCTRL_FSM_IDLE:
            {
                /* Stay in IDLE until system is up and running or when in standby. */
                UssCom_ClearTestDataOutputs();    /* clear output data*/
				
                /* Check diagnostics at a periodic rate even if we aren't taking measurements.*/
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)
                uint32_t uCurTimestamp = US_GetTimeStampTimeMs();
                if (((uCurTimestamp - uLastDiagCheckTimeMs) >= US_D_DIAG_MSG_PERIODIC_RATE)&&(US_DSI3_Check_INTB_State() != ME_OK))
                {
                    (void)UssSnrCmd_ReqDiagnosticResultsCmd(US_SnrCfg_F_Get_CfgSnrMap(US_ALL_POS)); 
                    uLastDiagCheckTimeMs = uCurTimestamp;
                }
#endif				
            }
            break;

            case USSCTRL_FSM_DATA_PLAYBACK:
            {
                /* Will eventually use a cal diagnostics byte:  normal, emctest, playback, etc */

                if (bIsNewPlaybackDataAvailable == (bool_t)ME_TRUE)
                {
                    /*
                     *  Failsafe to wait for manager to complete copying
                     *  new data into manager ring buffer.
                     */
                    if (bIsNewReceivedSnrData == (bool_t)ME_TRUE)
                    {
                        /*\cMELog_F_LogDebug_v("UssCtrl: Waiting for manager to get last data.  %d", METime1_GetGlobalTimeMs() - uBurstStartTimeMs);*/
                        break;
                    }
                    else /* We have new data to process.*/
                    {
                        bIsNewReceivedSnrData = (bool_t)ME_TRUE; /*Inform manager of new data.*/

                        /*
                         * Handshake to input buffer that data was received and
                         * copied into the manager ring buffer.
                         */
                        bIsNewPlaybackDataAvailable = (bool_t)ME_FALSE;
                    }
                }
                else
                {
                    ;/*Do nothing*/
                }
            }
            break;

            case USSCTRL_FSM_SEND_BURST:
            {
                bool_t bListenOnlyCycDelay = ME_FALSE;
                tmp  = US_GetTimeStampTimeMs() - uBurstStartTimeMs;
                delaytime  =   UssCtrl_uGetuFireSeqDelayMs();
                if (tmp < (uint32_t) delaytime)
                {
                    /*
                     * Delay next fire step by requested delay time.
                     * Stop blocking task and check again next cycle.
                     */
                }
                else
                {
                    uBurstStartTimeMs = US_GetTimeStampTimeMs();
                    /*\cMELog_F_LogDebug_v("UssCtrl: Main FSM - Send Burst, time = %d", uStartTimeMs);*/

                    /*
                     * Last burst OK.  Advance fire sequence.
                     */
                    if (uBurstStatus == ME_OK)
                    {
                        /* If function returns ME_TRUE, do nothing this controller task cycle */
                        bListenOnlyCycDelay = UssCtrl_SetNextFireSequenceStep();
                    }
                    else
                    {
                        ;/*Do nothing*/
                    }

                    /*
                     * 
                     * then attempt burst command (again).
                     */
                     TrcvrStatus = US_SnrDrv_Check_TransceiverResetState();
                    IntBState  = US_DSI3_Check_INTB_State();
                    if ((bListenOnlyCycDelay == (bool_t)ME_FALSE)&&(TrcvrStatus == (uint8_t)ME_OK)&&(IntBState != (uint8_t)ME_OK))  
                    {
                        /*
                         * Attempt to send burst command
                         * This burst will either be a new measurement or
                         * a retry of previous measurement.
                         */
                        uBurstStatus = UssSnrCmd_SendBurst();
                        /* timing logging */
                        US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_SnrFireTime, uBurstSendTimeMs);
                        if(uBurstSendTimeMs == ZERO) {US_ResetMaxProcTime(&US_psGetTaskProcTimes()->sProcTime_SnrFireTime);} //avoid startup time max
                        uBurstSendTimeMs = US_GetTimeStampTimeMs(); /* Update AFTER, so we get the gap between these calls */
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
                        /* Send a message on the UART each time the burst command is called.*/
                        /*\TODO jp - Make a function for this. */
                        uDebugOutputCount++;
                        if((uDebugOutputCount % TWENTY) == ZERO)
                        {
                            /*\SIUL2_0->GPDO18 ^= BIT0;*/
#ifdef USS_DEBUG
                            pam_uart_send_data("SNDBRST:\r\n");
#endif
                        }
						else
                        {
                            ;/*Do nothing */
                        }
#endif
                        /* If burst was ok, then wait for return callback */
                        if (uBurstStatus == ME_OK)
                        {
                            /*
                             * Put a diagnostics request into the driver queue.
                             * Eventually this should be at a reduced rate, once we get all bugs out.
                             */
                            (void)UssSnrCmd_ReqDiagnosticResultsCmd(US_SnrCfg_F_Get_CfgSnrMap(US_ALL_POS));
                            
                            if(g_LAUD_Get1HzFreqData == 1u)
                            {
                                /* Lets be wild and queue up another cmd, this to get the 1hz freq data of the burst that just happened */
                                (void)UssSnrCmd_ReqSensorFreqCmd(US_SnrCfg_F_Get_CfgSnrMap(US_ALL_POS)); /* will reducing the snr map to just fired sensors make this faster? */
                            }

                            eMainState = USSCTRL_FSM_CHECK_SNR_RETURN;
                        }
                        else
                        {
                            ;/*Do nothing*/
                        }
                    }
                    else
                    {
                        ;/*Do nothing*/
                    }
                }
            }
            break;

            case USSCTRL_FSM_CHECK_SNR_RETURN:
            {
                bCmdDone = UssSnrCmd_bIsCmdDone();
               if ((bool_t)ME_TRUE == bCmdDone)  /* Check if measurement command is complete.  From DMA callback.  QAC : 3344 already return bool_t but showing error.*/
                {
                    /*
                     * Make sure manager has copied new data into manager ring buffer.
                     */
                    if (bIsNewReceivedSnrData == (bool_t)ME_TRUE)
                    {
                        /*\cMELog_F_LogDebug_v("UssCtrl: Waiting for manager to get last data.  %d", METime1_GetGlobalTimeMs() - uBurstStartTimeMs); */
                        break;
                    }
                    else
                    {
                        ;/*Do nothing*/
                    }

                   
                     tmp =  UssSnrCmd_uGetuSnrMeasErrCode();
                    if (tmp == (uint32_t)ME_OK)
                    {
                        /*\cMELog_F_LogDebug_v("UssCtrl: Last sensor measurement time = %d", UssMgr_sDebugTaskProcTime.Debug_ProcTime_SnrMeasTime);*/

                        /* Parse the SPI buffer received.*/
                        UssSnrCmd_ProcessSensorMeasurments();
                        bIsNewReceivedSnrData = (bool_t)ME_TRUE;   /* We have new data.  Inform the manager!!*/
                    }
                    else
                    {
                        bIsError = (bool_t)ME_TRUE;  /*Other types of errors, such as bad command, or command timeout.*/
                    }

                    /*
                     * If Comm error timeout (ERROR_US_SNRDRVCOM_CMD_TIMEOUT) or other error,
                     * such as ERROR_US_SNRDRVCOM_INVLID_CMD, etc,
                     * then go to error state and reinitialize the sensors.
                     */
                    if (bIsError == (bool_t)ME_TRUE)
                    {
                        eMainState = USSCTRL_FSM_SNR_ERROR;
                    }
                    else
                    {
                         uReceiveErrorCnt = ZERO;
                         UssCtrl_ClearErrorFlags();

					    if ((eTempAdjState != USSCTRL_TEMPADJ_IDLE)||(eSensorCfgState != USSCTRL_SENSORCFG_IDLE))
					    {
					    	eMainState = USSCTRL_FSM_CAL_SNRS;
				    	}
				  	   else
					   {
                        eMainState = USSCTRL_FSM_SEND_BURST;
					   }
                    }

                    bExecuteFsmLoop = ME_TRUE; /* Perform the FSM tree one more time.*/
                }
                else
                {
                    /* Nothing/Pass */
                }
            }
            break;
			
			case USSCTRL_FSM_CAL_SNRS:
            {
    			if(eSensorCfgState != USSCTRL_SENSORCFG_IDLE)
    			{
    				UssCtrl_SensorCfgControl();
    			}
    			else if (eTempAdjState != USSCTRL_TEMPADJ_IDLE)
				{
					UssCtrl_TempAdjControl();
				}
                else {/* empty */ }
				if ((eTempAdjState == USSCTRL_TEMPADJ_IDLE) &&(eSensorCfgState == USSCTRL_SENSORCFG_IDLE))
				{
					eMainState = USSCTRL_FSM_IDLE;
				}
							
		    }
			break;

            case USSCTRL_FSM_SNR_ERROR:
            {
                /*
                 * Error has occurred.
                 */
#ifdef UART_SUPPORTED
                cMELog_F_LogDebug_v("UssCtrl: Main FSM - Sensor Disconnect or Driver Error.  Re-init sensors, Driver Error Code = %0X", UssSnrCmd_uGetuSnrMeasErrCode());
#endif

                /*
                 * Increment error counter and see if we have reached our max retries.
                 */
                UssCtrl_ProcessErrorFlags();  /*Set error flags.*/

                uReceiveErrorCnt++;
                if (uReceiveErrorCnt >= US_D_MAX_ERROR_CNT_BEFORE_XCVR_RESET)
                {
                    uReceiveErrorCnt = ZERO;
                    US_SnrDrv_Start_DSI3Transceiver_Reset();
                }
                else
                {
                    ;/*Do nothing*/
                }

                /* Re-execute same command without advancing firing-sequence on next Ctrl FSM execution */
                uBurstStatus =(bool_t) ME_NOT_OK;
                eMainState = USSCTRL_FSM_SEND_BURST;  /* Override re-initialization for sensor test.*/
            }
            break;

            default:
            {
                /* Got nothin'. Good place for SW fail code.*/
            }
            break;
        }
    }
}

/*===========================================================================
 * \brief Set DTC flags based on driver error codes.
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
 
/*===========================================================================
 * \brief Set DTC flags based on driver error codes.
 * Name:    UssCtrl_ProcessErrorFlags
 * Remarks: DD-ID: {C7391571-900D-429a-AD0D-16B739E1F297}
 * ==========================================================================
 */
 
static void UssCtrl_ProcessErrorFlags(void)
{
    uint32_t uDvrErrorCode = UssSnrCmd_uGetuSnrMeasErrCode();

    if((uDvrErrorCode ==  ERROR_US_SNRDRVCOM_DATAFORMAT_ERR)||(uDvrErrorCode == ERROR_US_SNRDRVCOM_DSI_BUS_ERROR)||(uDvrErrorCode == ERROR_US_SNRDRVCOM_CMD_TIMEOUT)||((uDvrErrorCode & US_DSI3_CH_BITERR_MASK)==ERROR_US_SNRDRVCOM_PDCM_CH_ERR))
    {
		US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_COMM_ERR);
	}
	else if((uDvrErrorCode & US_DSI3_BITERR_MASK) == ZERO)
	{
      if((uDvrErrorCode & (ERROR_US_SNRDRVCOM_DSI_SPI_UNDCMD|ERROR_US_SNRDRVCOM_DSI_SPI_CMDINC|ERROR_US_SNRDRVCOM_DSI_CH0_CMDOVR|ERROR_US_SNRDRVCOM_SPI_CH1_CMDOVR))!= ZERO) 
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_COMM_ERR);
	  }
      else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_COMM_ERR);
	  }
        if((uDvrErrorCode & ERROR_US_SNRDRVCOM_DSI_SPI_CRC)!= ZERO)
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_CRC_ERR);
	  }
	  else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_CRC_ERR);
	  }
        if((uDvrErrorCode & ERROR_US_SNRDRVCOM_DSI_CLKREF)!= ZERO)
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_CLKREF_ERR);
	  }
	  else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_CLKREF_ERR);
	  }
        if((uDvrErrorCode & ERROR_US_SNRDRVCOM_DSI_CH0_UV)!= ZERO)
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI0_UV_ERR);
	  }
	  else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI0_UV_ERR);
	  }
        if((uDvrErrorCode & ERROR_US_SNRDRVCOM_DSI_VCCUV_RFC)!= ZERO)
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_VCCUV_ERR);
	  }
	  else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_VCCUV_ERR);
	  }
            if((uDvrErrorCode & ERROR_US_SNRDRVCOM_DSI_CH1_UV)!= ZERO)
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI1_UV_ERR);
	  }
	  else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI1_UV_ERR);
	  }
        if((uDvrErrorCode & ERROR_US_SNRDRVCOM_SPI_OV_TEMPERATURE)!= ZERO)
	  {
		  US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_OT_ERR);
	  }
	  else
	  {
		  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_OT_ERR);
	  }
        }
     else
        {
          /* Do nothing */
        }
}

/*===========================================================================
 * \brief Clear all DTC flags related to driver error codes.
 * Name:    UssCtrl_ClearErrorFlags
 * Remarks: DD-ID: {494D68C9-57B9-4a77-A439-D595A9A9265F}
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
static void UssCtrl_ClearErrorFlags(void)
{
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_COMM_ERR);
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_CRC_ERR);
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_CLKREF_ERR);
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI0_UV_ERR);
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_VCCUV_ERR);
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI1_UV_ERR);
    US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_OT_ERR);

}


/*===========================================================================
 * \brief Post Processing after completion of USS control state machine.
 * \param none
 * \param none
 * \return none
 * \remarks UssCtrl_eMainState is the state of the Fsm.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_MainFsmPostProcessing
 * Remarks:  DD-ID: {F4DBF8F2-0B2B-4681-B8F9-48A0F5731488}
 * ===========================================================================*/
static void UssCtrl_MainFsmPostProcessing(void)
{
    /* Nothing assigned here yet.  Wonder if it is really worth having at all. */
}

/*===========================================================================
 * \brief Get flag that indicates if there is new sensor data available.
 * \param none
 * \param none
 * \return bool_t Flag that indicates if there is new sensor data available.
 * \remarks
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_bIsNewSensorData
 * Remarks:  DD-ID: {83FDED5D-DFE1-475a-860D-6DA03201249F}
 * ===========================================================================*/
 
bool_t UssCtrl_bIsNewSensorData(void)
{
    return bIsNewReceivedSnrData;
}

/*===========================================================================
 * \brief Clear flag that indicates if there is new sensor data available.
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_ClearNewSensorDataFlag
 * Remarks:  DD-ID: {1A648E68-9D83-43e9-803D-12E6FF00D5B0}
 * ===========================================================================*/
void UssCtrl_ClearNewSensorDataFlag(void)
{
    bIsNewReceivedSnrData = (bool_t)ME_FALSE;
}
#if (QAC_WARNING_FIX  ==  ME_FALSE)
/*===========================================================================
 * \brief Set flag that indicates if there is new sensor data available from CAN.
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_SetNewSnrPlaybackDataFlag
 * Remarks:  DD-ID: {D379D64C-BDDB-4073-BF26-5C34B08D024F}
 * ===========================================================================*/
 
void UssCtrl_SetNewSnrPlaybackDataFlag(void)
{
    bIsNewPlaybackDataAvailable = (bool_t)ME_TRUE;
}
#endif
/*===========================================================================
 * \brief Return flag that indicates if system is in data playback mode.
 * \param none
 * \param none
 * \return bool_t Return ME_TRUE if system is in data playback mode.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_bIsSysInPlaybackMode
 * Remarks:  DD-ID: {EB2B3959-0A3B-4f4e-8C22-3C5B669E8257}
 * ===========================================================================*/
bool_t UssCtrl_bIsSysInPlaybackMode(void)
{
    return  (bool_t)(US_D_IS_PLAYBACK_MODE);   /* \TODO jp - replace with check for calibration setting */
}

/*===========================================================================
 * \brief Set Sensor parameter adjust state.
 * \Adjust state
 * \return none.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetTemAdjState
 * Remarks:  DD-ID:{87A5F02E-B563-49ec-8ABA-A9AF29BE4417}
 * ===========================================================================*/

void UssCtrl_SetTemAdjState(UssCtrl_eTempAdjState_t eState)
{
	eTempAdjState = eState;
}

/*===========================================================================
 * \brief Trigger Sensor re-configure .
 * \Adjust state
 * \return none.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_TriggerSnrCfg
 * Remarks:  DD-ID: {7E0613C2-C66D-41cd-BB86-A0C6D7EF2641}
 * ===========================================================================*/

void UssCtrl_TriggerSnrCfg(void)
{
	eSensorCfgState = USSCTRL_SENSORCFG_PENDING;
}

/* ===========================================================================
 * Name:	 UssCtrl_ClearReceiveErrorCnt
 * Remarks:  DD-ID:{05AC2380-A82A-4895-B99C-15E4012B51C5}
 * ===========================================================================*/

void UssCtrl_ClearReceiveErrorCnt(void)
{
	uReceiveErrorCnt = ZERO;
}

#if(US_CSM_ENABLE == ME_TRUE)

/**
 * \brief 
 * Name: Us_SnrCntrl_ReqState_Csm   
 * Remarks: DD-ID: {7ED4339C-D68A-4b58-BF0D-6DF993DF8A0E}
 * \param instanceId 
 * \param reqState 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name:	 Us_SnrCntrl_ReqState_Csm
 * Remarks:  DD-ID:{FA39A591-28BF-47d2-8855-1FADDD2C3C86}
 * ===========================================================================*/

 UsCsm_StdReturn_Type Us_SnrCntrl_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState)
 {
    UsCsm_StdReturn_Type ret = US_CSM_STD_RET_OK;
    (void)instanceId;
    if(reqState == US_CSM_LOCAL_STATE_SHUTDOWN)
    {
        ucfsmstatereq = US_CSM_LOCAL_STATE_SHUTDOWN;
    }
    else  if(reqState == US_CSM_LOCAL_STATE_ACTIVE)
    {
        ucfsmstatereq = US_CSM_LOCAL_STATE_ACTIVE;
    }
    else
    {
        ret = US_CSM_STD_RET_NOK;
    }
    return ret;
 }


/* ===========================================================================
 * Name: Us_SnrCntrl_GetState_Csm	
 * Remarks:  DD-ID: {E969002F-22B1-42f7-9457-425273B2C85D}
 * ===========================================================================*/
 UsCsm_LocalStateId_Type Us_SnrCntrl_GetState_Csm(UsCsm_InstanceId_Type instanceId)
 {
    
    UsCsm_LocalStateId_Type retstate = US_CSM_LOCAL_STATE_UNDEFINED;
    UssMgr_e_SysState_t  SysState = UssMgr_eGetSysState();
    (void)instanceId; 
    if((bSystemRunning == (bool_t)ME_TRUE)||((SysState == SYSMGR_SYS_CONFIG)&&(eSensorCfgState != USSCTRL_SENSORCFG_IDLE)))
    {
        retstate = US_CSM_LOCAL_STATE_ACTIVE;
    }
    else
    {
        retstate = US_CSM_LOCAL_STATE_SHUTDOWN;
    }
    return retstate;
 }	

#endif
