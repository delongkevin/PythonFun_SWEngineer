/**
 *  \file     CDD_HSD_MainFunc.c
 *
 *  \brief    
 *
 *
 **/
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include "US_HsdLocal.h"
#include "US_Hsd_Global.h"
#include <ti/csl/src/ip/gpio/V0/gpio.h>
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include "US_Diagnostic_Global.h"                /*PRQA S 0380 */
#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Platform_Global.h"
#include "US_ErrMgr_Global.h"
#include "US_SysMgr_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Hsd_CsmIf.h"
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define USS_STUB_INPUT_TEST_HSD (US_STD_OFF)	

#define USS_HSD_NO_ERR_MASK					0x00						/* NO ERROR */ 
#define USS_HSD_OPN_CRKT_FAIL_MASK			0x01						/* OPEN CIRCUIT FAILURE */
#define USS_HSD_SHRT_TO_GND_MASK			0x02						/* SHORT TO GROUND */

#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
#define USS_HSD_VTG_OOR_LOW_MASK			0x04						/* VOLTAGE OUT OF RANGE LOW*/
#define USS_HSD_VTG_OOR_HIGH_MASK			0x08						/* VOLTAGE OUT OF RANGE HIGH*/
#endif

#if(US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)
#define USS_HSD_VTG_OOR_MASK				0x04						/* VOLTAGE OUT OF RANGE */
#endif

#define USS_HSD_SHRT_TO_BAT_MASK			0x01						/* SHORT TO BATTERY */
	

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* IMP NEED TO INITAILIZE eHSDOnOffReq to  SetOnOffRequest_NONE*/

USS_HSD_S_State_Machine_t Uss_HsdStateMachine[Uss_Hsd_Channel_Max]=
{
       {.eChannelID = Uss_Hsd_Channel_PWR_A, .eHSDState = Uss_Hsd_State_Init, .eHSDPrvState = Uss_Hsd_State_Init,  .eHSDOnOffReq = SetOnOffRequest_NONE,.fPtrHsdGpioWriteCbk = HsdGpIoWriteCbk_ChannelA},
       {.eChannelID = Uss_Hsd_Channel_PWR_B, .eHSDState = Uss_Hsd_State_Init, .eHSDPrvState = Uss_Hsd_State_Init,  .eHSDOnOffReq = SetOnOffRequest_NONE,.fPtrHsdGpioWriteCbk = HsdGpIoWriteCbk_ChannelB}
};

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND == US_FEATURE_ON)
	static HsdDiagErrConf_Type HsdDiagErr_ShortToGnd[Uss_Hsd_Channel_Max] =
	{
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_STG, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_STG, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STG, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STG},
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_STG, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_STG, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STG, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STG},
	};
#endif

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW == US_FEATURE_ON)
	static HsdDiagErrConf_Type HsdDiagErr_VtgOutOfRange_Low[Uss_Hsd_Channel_Max] =
	{
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_VTG_OOR_LOW, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_VTG_OOR_LOW, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_LOW, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_LOW},
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_VTG_OOR_LOW, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_VTG_OOR_LOW, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_LOW, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_LOW},
	};
#endif

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH == US_FEATURE_ON)
	static HsdDiagErrConf_Type HsdDiagErr_VtgOutOfRange_High[Uss_Hsd_Channel_Max] =
	{
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_VTG_OOR_HIGH, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_VTG_OOR_HIGH, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_HIGH, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_HIGH},
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_VTG_OOR_HIGH, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_VTG_OOR_HIGH, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_HIGH, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_HIGH},
	};
#endif

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_BAT == US_FEATURE_ON)
	static HsdDiagErrConf_Type HsdDiagErr_ShortToBatt[Uss_Hsd_Channel_Max] =
	{
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_STB, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_STB, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STB, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STB},
		{.RetryCntSet = HSD_ERR_SET_RETRY_CNT_STB, .RetryCntClr = HSD_ERR_CLR_RETRY_CNT_STB, .ThresholdLockSet = ME_FALSE, .ThresholdLockClr = ME_FALSE, .ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STB, .ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STB},
	};
#endif



#if(USS_STUB_INPUT_TEST_HSD == US_STD_ON)
	volatile uint16_t stub_HsdVtgval[Uss_Hsd_Channel_Max] = {12000,12000};
	volatile uint16_t stub_HsdCurval[Uss_Hsd_Channel_Max] = {70, 70};
#endif


static void UssHsd_f_SetHsdState(const UssHsd_E_State_t eHsdState ,const  uint8_t ChannelID);
static void UssHsd_f_OnFaultDetection(const uint8_t ChannelID);
static void UssHsd_f_OffFaultDetection(const uint8_t ChannelID);
static void UssHsd_f_SetOnFaultDetectedFlags(const uint8_t error_bitmask,const uint8_t ChannelID);
static bool UssHsd_f_GetOFFFaultDetectedFlags(const uint8_t ChannelID);
static void UssHsd_f_SetOffFaultDetectedFlags(const uint8_t error_bitmask, const uint8_t ChannelID);
static void UssHsd_f_ClearOnFaultDetectedFlags(const uint8_t error_bitmask,const uint8_t ChannelID);
static void UssHsd_f_ClearOffFaultDetectedFlags(const uint8_t error_bitmask,const uint8_t ChannelID);
static uint8_t UssHsd_f_Pwr_En_Status(const uint8_t ChannelID);
static void UssHsd_Shutdown(const uint8_t ChannelID);
static UssHsd_E_SetOnOffStatus_t UssHsd_F_GetOnOffStatus(const UssHsd_E_ChannelID_t ChannelID);

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_BAT == US_FEATURE_ON)
	static void UssHsd_f_ClearFaultValidation_ShortToBatt(const uint8_t ChannelID);
	static void UssHsd_f_SetFaultValidation_ShortToBatt(const uint8_t ChannelID);
	static void UssHsd_f_ResetSetCounters_ShortToBatt(const uint8_t ChannelID);
	static void UssHsd_f_ResetClrCounters_ShortToBatt(const uint8_t ChannelID);
#endif

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND == US_FEATURE_ON)
	static void UssHsd_f_ClearFaultValidation_ShortToGnd(uint8_t ChannelID);
	static void UssHsd_f_SetFaultValidation_ShortToGnd(uint8_t ChannelID);
	static void UssHsd_f_ResetSetCounters_ShortToGnd(uint8_t ChannelID);
	static void UssHsd_f_ResetClrCounters_ShortToGnd(uint8_t ChannelID);
#endif

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW == US_FEATURE_ON)
	static void UssHsd_f_ClearFaultValidation_VtgOutOfRange_Low(const uint8_t ChannelID);
	static void UssHsd_f_SetFaultValidation_VtgOutOfRange_Low(const uint8_t ChannelID);
	static void UssHsd_f_ResetSetCounters_VtgOutOfRange_Low(const uint8_t ChannelID);
	static void UssHsd_f_ResetClrCounters_VtgOutOfRange_Low(const uint8_t ChannelID);
#endif

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH == US_FEATURE_ON)
	static void UssHsd_f_ClearFaultValidationVltgOutOfRangeHigh(const uint8_t ChannelID);
	static void UssHsd_f_SetFaultValidation_VltgOutOfRangeHigh(const uint8_t ChannelID);
	static void UssHsd_f_ResetSetCounters_VltgOutOfRangeHigh(const uint8_t ChannelID);
	static void UssHsd_f_ResetClrCounters_VltgOutOfRangeHigh(const uint8_t ChannelID);
#endif

static void UssHsd_f_ChkONFaultRecovery(const uint8_t ChannelID);
static void UssHsd_f_ChkOFFFaultRecovery(const uint8_t ChannelID);

extern uint8_t US_Com_GetHsdPwrChannel_A(void);
extern uint8_t US_Com_GetHsdPwrChannel_B(void);
extern void UssHsd_Report_InternalError(uint8_t ChannelID,UsHsd_ErrId_Type errId, UsHsd_ErrState_Type errState);

/* ===========================================================================
* UssHsd_F_SetOnOffRequest.
* Brief: Send On/Off request for HSD channel.
* \param: ChannelID,SetOnOffRequest
* \return: None
* \remarks  no remarks
* Req.-ID: 15768224
* ========================================================================= */
/* ===========================================================================
 * Name: UssHsd_F_SetOnOffRequest     
 * Remarks:  DD-ID: {01D351D9-8518-49e0-AF8A-06F0C2D94B97}
 * ===========================================================================*/
static void UssHsd_F_SetOnOffRequest(const UssHsd_E_ChannelID_t ChannelID,const UssHsd_E_SetOnOffRequest_t SetOnOffRequest)
{
    if(ChannelID < Uss_Hsd_Channel_Max)
    {
		Uss_HsdStateMachine[ChannelID].eHSDOnOffReq = SetOnOffRequest;
        Uss_HsdStateMachine[ChannelID].eHSDStatus = SetOnOffStatus_OFF;
        UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOnOff,(uint8_t)ChannelID);
		/* Switch HSD Power enable pin HIGH or LOW based on request */
        switch(SetOnOffRequest)
        {
            case SetOnOffRequest_ON:
			    if(((void *)0) != Uss_HsdStateMachine[ChannelID].fPtrHsdGpioWriteCbk )
                {
                    /* Switch HSD Power enable pin HIGH */
				    Uss_HsdStateMachine[ChannelID].fPtrHsdGpioWriteCbk(ME_TRUE);
                }
                else
                {
                    ;  /* No Action */
                }
				break;
            case SetOnOffRequest_OFF:
			    if(((void *)0) != Uss_HsdStateMachine[ChannelID].fPtrHsdGpioWriteCbk )
                {
                    /* Switch HSD Power enable pin LOW */
                     Uss_HsdStateMachine[ChannelID].fPtrHsdGpioWriteCbk(0);
                }
                else
                {
                    ;/* No Action */
                }
                break;
            default:   /* empty */
                break;
        }
    }
	else
	{
	    ;  /* No Action */
	}
}
/* ===========================================================================*/
/* UssHsd_F_GetOnOffStatus.
* Brief: This function will return status of HSD_ChannelID_Type
* \param: UssHsd_E_ChannelID_t
* \return: UssHsd_E_SetOnOffStatus_t
* \remarks  no remarks
* Req.-ID: 15768224
 ===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_F_GetOnOffStatus     
 * Remarks:  DD-ID: {45E5E773-90C2-48b6-8436-3E65BF562181}
 * ===========================================================================*/
static UssHsd_E_SetOnOffStatus_t UssHsd_F_GetOnOffStatus(const UssHsd_E_ChannelID_t ChannelID)    /*PRQA S 3219*/
{
    UssHsd_E_SetOnOffStatus_t OnOffStatus = SetOnOffStatus_OFF;
    if(ChannelID < Uss_Hsd_Channel_Max)
    {
        OnOffStatus = Uss_HsdStateMachine[ChannelID].eHSDStatus;
    }
	else
	{
	    ;  /* No Action */
	}
    return OnOffStatus;
}
/* ===========================================================================*/
/* UssHsd_F_CheckOnStatus.
* Brief: This function will return status of HSD_ChannelID_Type
* \param: None
* \return: UssHsd_E_SetOnOffStatus_t
* \remarks  no remarks
* Req.-ID: 
 ===========================================================================*/
 /* ===========================================================================
 * Name: UssHsd_F_CheckOnStatus     
 * Remarks:  DD-ID: {5C8E6318-0C72-4a2c-B87E-6D65D001ADD5}
 * ===========================================================================*/
uint8_t UssHsd_F_CheckOnStatus(void)
{
	uint8_t ChannelID;
	uint8_t ret = ME_TRUE;
    for(ChannelID = 0; ChannelID <  (uint8_t)Uss_Hsd_Channel_Max; ChannelID++)
    {
        if(Uss_HsdStateMachine[ChannelID].eHSDStatus == SetOnOffStatus_OFF)
		{
			ret = ME_FALSE;
		}
		else
		{
	   		;  /* No Action */
		}
    }
    return ret;
}
/* ===========================================================================*/
/* UssHsd_F_StateMachine.
* Brief: This function will maintain state machine of HSD
* \param: None
* \return: None
* \remarks  no remarks
 ===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_F_StateMachine     
 * Remarks:  DD-ID: {6531AB12-7D6B-48e1-8429-15A9EC7C02A6}
 * ===========================================================================*/
void UssHsd_F_StateMachine(void)
{
	static uint8_t Pwr_ChannelID = 0;
	UssMgr_e_SysState_t uSysState;
	/*Run the statemachine for the number of Sensor BUS available*/
    for(Pwr_ChannelID = 0; Pwr_ChannelID < (uint8_t) Uss_Hsd_Channel_Max; Pwr_ChannelID++)    /*PRQA S 2461 */
    {
        switch(Uss_HsdStateMachine[Pwr_ChannelID].eHSDState)
        {
            case Uss_Hsd_State_Init:
                /* HSD Init State */
                Uss_HsdStateMachine[Pwr_ChannelID].eHSDStatus = SetOnOffStatus_OFF;
				uSysState = UssMgr_eGetSysState();
				if(uSysState != SYSMGR_SYS_INIT)
				{
					UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOnOff,Pwr_ChannelID);
				}
				else
				{
					;  /* No Action */
				}
                break;

            /*state to check the ON/OFF request for BUS */
            case Uss_Hsd_State_OutputOnOff:
                switch(Uss_HsdStateMachine[Pwr_ChannelID].eHSDOnOffReq)
                {

                    case SetOnOffRequest_ON:
                        UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOnCheck,Pwr_ChannelID);

                        break;

                    case SetOnOffRequest_OFF:
                        UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOffCheck,Pwr_ChannelID);

                        break;
                    default: /*empty */
                        break;
                }
                break;

            /*State to check the ON voltage stabilization*/
            case Uss_Hsd_State_OutputOnCheck:
				if(OUTPUTONCHECK_TIMEOUT > Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOnTimer)
				{
					/* Wait for HSD PWR Line to  activate  */
					if((USS_HSD_PWR_ON_VTG <= Uss_HsdStateMachine[Pwr_ChannelID].vVoltage) ||
						((uint8_t)UssHsd_Pwr_En_High == UssHsd_f_Pwr_En_Status(Pwr_ChannelID)))
					{
						/* If voltage is valid HSD will be in ON state */
						UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOn,Pwr_ChannelID);
						Uss_HsdStateMachine[Pwr_ChannelID].eHSDStatus = SetOnOffStatus_ON;
						Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOnTimer = ZERO;
					}
					else
					{
						/* If voltage is invalid increment error counter */
						Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOnTimer++;
						if((uint8_t)UssHsd_Pwr_En_Low == UssHsd_f_Pwr_En_Status(Pwr_ChannelID))
						{
							if(((void *)0) != Uss_HsdStateMachine[Pwr_ChannelID].fPtrHsdGpioWriteCbk )
							{
								/* Switch HSD Power enable pin HIGH */
								Uss_HsdStateMachine[Pwr_ChannelID].fPtrHsdGpioWriteCbk(ME_TRUE);
							}
							else
							{
								;/* No Action */
							}
						}
						else
						{
							;/* No Action */
						}
					}

				}
				else
				{
					/* If voltage is invalid and timeout occurs HSD will be in FAULT state */
					UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOnOff,Pwr_ChannelID);
					Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOnCheck;
					Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOnTimer = ZERO;
					Uss_HsdStateMachine[Pwr_ChannelID].eHSDStatus = SetOnOffStatus_OFF;
				}
                break;

             /*State to check OFF voltage stabilization*/
            case Uss_Hsd_State_OutputOffCheck:
                if(OUTPUTOFFCHECK_TIMEOUT >  Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOffTimer)
                {
                    /* Wait to check if HSD line is disabled */
                    //TBD As of now only voltage is considered
                    if(USS_HSD_PWR_OOR_MIN >= Uss_HsdStateMachine[Pwr_ChannelID].vVoltage)
                    {
                        /* If voltage meets off criteria then HSD will be in OFF state */
                        UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOff,Pwr_ChannelID);
                        Uss_HsdStateMachine[Pwr_ChannelID].eHSDStatus = SetOnOffStatus_OFF;
                        Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOffTimer = ZERO;
                    }
                    else
                    {
                        /* If voltage is invalid increment off error counter */
                        Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOffTimer++;
						if((uint8_t)UssHsd_Pwr_En_High == UssHsd_f_Pwr_En_Status(Pwr_ChannelID))
						{
							if(((void *)0) != Uss_HsdStateMachine[Pwr_ChannelID].fPtrHsdGpioWriteCbk )
							{
								/* Switch HSD Power enable pin HIGH */
								Uss_HsdStateMachine[Pwr_ChannelID].fPtrHsdGpioWriteCbk(ME_FALSE);
							}
							else
							{
								;  /* No Action */
							}
						}
						else
						{
							;/* No Action */
						}
                    }
                }
                else
                {
                    /* If voltage is invalid and timeout occurs HSD will be in FAULT state */
                    UssHsd_f_SetHsdState(Uss_Hsd_State_Fault,Pwr_ChannelID);
                    Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOff;
                    Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOffTimer = ZERO;
                    Uss_HsdStateMachine[Pwr_ChannelID].eHSDStatus = SetOnOffStatus_OFF;
                }
                break;
             /*BUS Monitoring state in ON condition*/
            case Uss_Hsd_State_OutputOn:
                UssHsd_f_OnFaultDetection(Pwr_ChannelID);
                if((uint8_t)USS_HSD_NO_ERR_MASK != Uss_HsdStateMachine[Pwr_ChannelID].eHSDOnConfirmError)
                {
                	/*Found ON Fault, enter to Fault state*/
                    UssHsd_f_SetHsdState(Uss_Hsd_State_Fault,Pwr_ChannelID);
                	Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOn;
                }
                else
                {
                    /* No Fault so Far..Stay in Uss_Hsd_State_OutputOn state */
                }
                break;

                /*BUS Monitoring state in OFF condition*/
            case Uss_Hsd_State_OutputOff:
                UssHsd_f_OffFaultDetection(Pwr_ChannelID);
                if((uint8_t)USS_HSD_NO_ERR_MASK != Uss_HsdStateMachine[Pwr_ChannelID].eHSDOffConfirmError)
                {
                	/*Found OFF Fault, enter to Fault state*/
                	UssHsd_f_SetHsdState(Uss_Hsd_State_Fault,Pwr_ChannelID);
                	Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOff;
                }
                else
                {
                    /* No Fault so Far..Stay in Uss_Hsd_State_OutputOff state */
                }
                break;

				/*state to check the other Fault when one fault already detected*/
			case Uss_Hsd_State_Multiple_Fault_Check:
				switch(Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState)
                {
					/*Fault Check State ON*/
					case Uss_Hsd_State_OutputOn:
							/*Check for ON Fault*/
							UssHsd_f_OnFaultDetection(Pwr_ChannelID);
							/*Go back to Fault state to monitor the Recovery*/
							UssHsd_f_SetHsdState(Uss_Hsd_State_Fault,Pwr_ChannelID);
							Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOn;

						break;
					/*Fault Check State OFF*/
					case Uss_Hsd_State_OutputOff:
							/*Check for OFF Fault*/
							UssHsd_f_OffFaultDetection(Pwr_ChannelID);
							/*Go back to Fault state to monitor the Recovery*/
							UssHsd_f_SetHsdState(Uss_Hsd_State_Fault,Pwr_ChannelID);
							Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOff;

						break;
						
					default:/*empty*/ 
						break;
				}
                break;
                /*Fault state checking for recovery of fault */
            case Uss_Hsd_State_Fault:
                switch(Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState)
                {
                	/*Fault Check State ON*/
                	case Uss_Hsd_State_OutputOn:
						/*Check for Instantaneous ON Fault Recovery*/
						UssHsd_f_ChkONFaultRecovery(Pwr_ChannelID);
						if((uint8_t)USS_HSD_NO_ERR_MASK == Uss_HsdStateMachine[Pwr_ChannelID].eHSDOnConfirmError)
						{
							/*Fault Recovered!!! Confirmed*/
							UssHsd_f_SetHsdState(Uss_Hsd_State_Fault_Recovery,Pwr_ChannelID);
							Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOn;
							Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOnFaultTimer = ZERO;
						}
						else
						{
							/*Jump to Multiple Fault check for the BUS to check other Faults if occurred */
							UssHsd_f_SetHsdState(Uss_Hsd_State_Multiple_Fault_Check,Pwr_ChannelID);
							Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOn;
						}

                        break;
                     /*Fault Check State ON*/
                    case Uss_Hsd_State_OutputOff:
				
						/*Check for Instantaneous ON Fault Recovery*/
						UssHsd_f_ChkOFFFaultRecovery(Pwr_ChannelID);
						if((uint8_t)USS_HSD_NO_ERR_MASK == Uss_HsdStateMachine[Pwr_ChannelID].eHSDOffConfirmError)
						{
							/* Fault Recovered!!!! confirming it*/
							/*Fault Recovered!!! Confirmed*/
							UssHsd_f_SetHsdState(Uss_Hsd_State_Fault_Recovery,Pwr_ChannelID);
							Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOff;
							Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOffFaultTimer = ZERO;
						}
						else
						{
							UssHsd_f_SetHsdState(Uss_Hsd_State_Multiple_Fault_Check,Pwr_ChannelID);
							Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState = Uss_Hsd_State_OutputOff;
						}

                        break;

                    default:
                        Uss_HsdStateMachine[Pwr_ChannelID].eHSDStatus = SetOnOffStatus_OFF;
                        UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOnOff,Pwr_ChannelID);
                        break;
                    }
                break;
         /*Transition state after After all Fault Recovered for the BUS*/
        case Uss_Hsd_State_Fault_Recovery:
            switch(Uss_HsdStateMachine[Pwr_ChannelID].eHSDPrvState)
            {
                case Uss_Hsd_State_OutputOn:
						/*All the ON Faults are Recovered */
						UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOn,Pwr_ChannelID);
						Uss_HsdStateMachine[Pwr_ChannelID].eHSDOnPrevError = Uss_HsdStateMachine[Pwr_ChannelID].eHSDOnConfirmError;
						Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOnFaultRecoveryTimer = ZERO;
                    break;

                case Uss_Hsd_State_OutputOff:
						/*All the OFF Faults Recovered*/
						Uss_HsdStateMachine[Pwr_ChannelID].eHSDOffPrevError = Uss_HsdStateMachine[Pwr_ChannelID].eHSDOffConfirmError;
						UssHsd_f_SetHsdState(Uss_Hsd_State_OutputOff,Pwr_ChannelID);
						Uss_HsdStateMachine[Pwr_ChannelID].UssHsd_OutputOffFaultRecoveryTimer = ZERO;

                    break;

                default: /*empty */
                    break;
            }
            break;

            default: /*empty */
                break;
        }
    }
}

/* ===========================================================================*/
/* UssHsd_f_OnFaultDetection.
* Brief: Detect fault for HSD On state
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Req.-ID: 15768392
* Req.-ID: 15768418
* Req.-ID: 15768440
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_OnFaultDetection     
 * Remarks:  DD-ID: {6CF69996-ADA2-4deb-9F66-3E926BAA8606}
 * ===========================================================================*/
static void UssHsd_f_OnFaultDetection(const uint8_t ChannelID)
{
	if((uint8_t)Uss_Hsd_Channel_Max > ChannelID)
    {
		/*Check All ON Fault Errors only when BUS is in ON condition */
        if((uint8_t)UssHsd_Pwr_En_High == UssHsd_f_Pwr_En_Status(ChannelID))
        {	

#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW == US_FEATURE_ON)				
			if((uint8_t)USS_HSD_NO_ERR_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_VTG_OOR_LOW_MASK))
			{
				UssHsd_f_SetFaultValidation_VtgOutOfRange_Low(ChannelID);
			}
			else
			{
				;  /* No Action */
			}
#endif

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH == US_FEATURE_ON)	
			if((uint8_t)USS_HSD_NO_ERR_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_VTG_OOR_HIGH_MASK))
			{
               UssHsd_f_SetFaultValidation_VltgOutOfRangeHigh(ChannelID);
			}
			else
			{
				;/* No Action */
			}
#endif			
#else
			if(USS_HSD_NO_ERR_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_VTG_OOR_MASK))
			{
				/*Voltage Out of range*/
				if(((USS_HSD_PWR_OOR_MIN > Uss_HsdStateMachine[ChannelID].vVoltage) ||
				   (USS_HSD_PWR_OOR_MAX <= Uss_HsdStateMachine[ChannelID].vVoltage)))
				{						
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError |= (uint8_t)USS_HSD_VTG_OOR_MASK;
					
					UssHsd_f_SetOnFaultDetectedFlags(USS_HSD_VTG_OOR_MASK,ChannelID);
				}
				else
				{
					/*Do Nothing*/
				}
			}
			else
			{
				/* do nothing*/
			}
#endif	

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND == US_FEATURE_ON)	
			if(USS_HSD_NO_ERR_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_SHRT_TO_GND_MASK))
			{
				UssHsd_f_SetFaultValidation_ShortToGnd(ChannelID);
			}
#endif

#if(US_FEATURE_HSD_FAULT_DET_OPEN_CIRCUIT == US_FEATURE_ON)			
			if(USS_HSD_NO_ERR_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_OPN_CRKT_FAIL_MASK))
			{
				//open circuit fault is detected when USS_PWR_MON > 9V and USS_PWR_IS1_MON < 54mA
				if(((USS_HSD_OCF <= Uss_HsdStateMachine[ChannelID].vVoltage)   &&
					   (USS_HSD_RAIL_CUR_MIN > Uss_HsdStateMachine[ChannelID].vCurrent)))
				{
					/* If PWR_EN pin HIGH and voltage is > 9V and current is below threshold i.e < 54 mA,  set ERROR as  Open Circuit fail*/
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError |= (uint8_t)USS_HSD_OPN_CRKT_FAIL_MASK;
					UssHsd_f_SetOnFaultDetectedFlags(USS_HSD_OPN_CRKT_FAIL_MASK,ChannelID);
				}
				else
				{

				}
			}
			
			else
			{

			}
#endif
        }
        /*TODO KPK- Need to check whether this condition is really needed*/
        else if((uint8_t)UssHsd_Pwr_En_Low == UssHsd_f_Pwr_En_Status(ChannelID))
        {
            if(USS_HSD_PWR_OOR_MIN > Uss_HsdStateMachine[ChannelID].vVoltage)
            {
                /* If PWR_EN pin LOW and voltage is below 9V set ERROR as  NOERROR*/
                Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError = (uint8_t)USS_HSD_NO_ERR_MASK;
                Uss_HsdStateMachine[ChannelID].eHSDOnError = (uint8_t)USS_HSD_NO_ERR_MASK;
            }
			else{

			}
        }
        else
        { /*empty*/
        }
    }
	else
	{
		;/* No Action */
	}
}

/* ===========================================================================*/
/* UssHsd_f_OffFaultDetection.
* Brief: Detect fault for HSD Off state
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Req.-ID: 13473432
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_OffFaultDetection     
 * Remarks:  DD-ID: {469E5880-229A-4f71-9A4F-37C20BE124D2}
 * ===========================================================================*/
static void UssHsd_f_OffFaultDetection(const uint8_t ChannelID)
{
    if((uint8_t)Uss_Hsd_Channel_Max > ChannelID)
    {
        if((uint8_t)UssHsd_Pwr_En_Low == UssHsd_f_Pwr_En_Status(ChannelID))    /* PRQA S 1881 */
        {
#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_BAT == US_FEATURE_ON)
			if((uint8_t)USS_HSD_NO_ERR_MASK == ((uint8_t)USS_HSD_SHRT_TO_BAT_MASK & Uss_HsdStateMachine[ChannelID].eHSDOffConfirmError))
			{
				UssHsd_f_SetFaultValidation_ShortToBatt(ChannelID);
			}
			else
			{
				;/* No Action */
			}
#endif
        }
        else if((uint8_t)UssHsd_Pwr_En_High == UssHsd_f_Pwr_En_Status(ChannelID))
        {
			/* If PWR_EN pin LOW and voltage is within off range set error NO ERROR*/
			Uss_HsdStateMachine[ChannelID].eHSDOffConfirmError = (uint8_t)USS_HSD_NO_ERR_MASK;
			Uss_HsdStateMachine[ChannelID].eHSDOffError = (uint8_t)USS_HSD_NO_ERR_MASK;
		}
        else
        {
        	/*Do Nothing*/
        }
    }
	else
	{
		;/* No Action */
	}
}

/* ===========================================================================*/
/* UssHsd_f_SetOnFaultDetectedFlags.
* Brief: Set fault flags if any in HSD ON condition
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 13473301
* Req.-ID: 13473374
* Req.-ID: 13473418
* Req.-ID: 13473420
* Req.-ID: 13394552
* Req.-ID: 13394152
* Req.-ID: 13394917
* Req.-ID: 13394914
* Req.-ID: 15768392
* Req.-ID: 15768418
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_SetOnFaultDetectedFlags     
 * Remarks:  DD-ID: {FF793205-29ED-4dde-9145-E7852E406053}
 * ===========================================================================*/
static void UssHsd_f_SetOnFaultDetectedFlags(const uint8_t error_bitmask,const  uint8_t ChannelID)   /*PRQA S 3219 */
{
	/* Set fault flags according to error */
	switch(error_bitmask)
	{
		case(USS_HSD_OPN_CRKT_FAIL_MASK):
            if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
            {
			    Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Open_Circuit_Failure =(bool_t) ME_TRUE;
            }
			else
			{
				;/* No Action */
			}
#ifdef US_HSD_SUPPORT_OC_FAULT_REPORT
			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_FRONT_BUMPER_OPEN);
			}
			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_REAR_BUMPER_OPEN);
			}
			else
			{/* empty */
				}
#endif

		break;

#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
		case(USS_HSD_VTG_OOR_LOW_MASK):
            /*KPK-QAC Fix : Need to suppress, ChannelID  boudary check has be done before calling this functions and no impact */
            if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
            {
			    Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Voltage_Out_Of_Range = (bool_t)ME_TRUE;
            }
			else
			{
				;/* No Action */
			}
			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR_LOW);  							
			}
			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_REAR_BUMPER_OOR_LOW);								
			}
			else
			{    /* empty */
			}
		break;
		
		
		case(USS_HSD_VTG_OOR_HIGH_MASK):
            if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
            {
			     Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Voltage_Out_Of_Range = (bool_t)ME_TRUE;  
            }
			else
			{
				;/* No Action */
			}
			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR_HIGH);  						
			}
			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_REAR_BUMPER_OOR_HIGH);					
			}
			else
			{ /* empty */
			}
		break;

		
#else
		case(USS_HSD_VTG_OOR_MASK):
			Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Voltage_Out_Of_Range = (bool_t) ME_TRUE;
			if(Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR);
			}
			else if(Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_REAR_BUMPER_OOR);
			}
			else
			{/* empty */
			}
		break;
		#endif
		
		case(USS_HSD_SHRT_TO_GND_MASK):
            if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
            {
				Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Short_To_Ground =(uint8_t) ME_TRUE;
            }
			else
			{
				;/* No Action */
			}
			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND);
			}
			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND);
			}
			else
			{/* empty */
			}
		break;
		default:  /* empty */
			break;
	}

}
/* ===========================================================================*/
/*UssHsd_f_GetOnFaultDetectedFlags
* Brief: Get the status of all the ON Fault status
* \param: ChannelID
* \return: Status TUE/FALSE
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 13473301
* Req.-ID: 13473374
* Req.-ID: 13473418
* Req.-ID: 13473420
* Req.-ID: 13394552
* Req.-ID: 13394152
* Req.-ID: 13394917
* Req.-ID: 13394914
* Req.-ID: 15768392
* Req.-ID: 15768418
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_GetOnFaultDetectedFlags     
 * Remarks:  DD-ID: {7B2AE376-0184-4817-A0F7-42C705E2EA47}
 * ===========================================================================*/
bool_t UssHsd_f_GetOnFaultDetectedFlags(const uint8_t ChannelID)   /* PRQA S 3219 */
{
    bool_t ret = (bool_t)ME_FALSE;
	if(Uss_HsdStateMachine[ChannelID].eHSDOnError != ME_OK)
	{
	   ret = (bool_t)ME_TRUE;
	}
	return ret;
#if 0
	/*changes required as per CVADAS and Fisker */
	if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
	{
		#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
		return (USDiagnostic_GetECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND) || USDiagnostic_GetECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR_LOW) || USDiagnostic_GetECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR_HIGH));    /* PRQA S 4558, 4115*/
		#else
		return (USDiagnostic_GetECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND) || USDiagnostic_GetECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR));   /* PRQA S 4558, 4115*/
		#endif
	}
	else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
	{
		#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
			return (USDiagnostic_GetECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND) || USDiagnostic_GetECUFlag(DIAG_FLAG_REAR_BUMPER_OOR_LOW) || USDiagnostic_GetECUFlag(DIAG_FLAG_REAR_BUMPER_OOR_HIGH));    /* PRQA S 4558, 4115*/
		#else
			return (USDiagnostic_GetECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND) || USDiagnostic_GetECUFlag(DIAG_FLAG_REAR_BUMPER_OOR));  /* PRQA S 4558, 4115*/
		#endif
	}
	else
	{
		return (bool_t)ME_FALSE;
	}
#endif
}

/* ===========================================================================*/
/* UssHsd_f_SetOffFaultDetectedFlags.
* Brief: Set fault flags if any in HSD OFF condition
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 13473432
* Req.-ID: 13473434
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_SetOffFaultDetectedFlags     
 * Remarks:  DD-ID: {1E5B83A5-6ACB-432a-BE71-EEFD1AC3F29F}
 * ===========================================================================*/
static void UssHsd_f_SetOffFaultDetectedFlags(const uint8_t error_bitmask, const uint8_t ChannelID)   /* PRQA S 3219*/
{

	switch(error_bitmask)
	{
		case USS_HSD_SHRT_TO_BAT_MASK:
            if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
            {
				Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Short_To_Battery =(bool_t) ME_TRUE;
            }
			else
			{
				;/* No Action */
			}
			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT);
			}
			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_SetECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT);
			}
			else
			{ /*empty*/
			}
			break;

		default: /*empty*/
			break;

	}


}

/* ===========================================================================*/
/* UssHsd_f_GetOFFFaultDetectedFlags.
* Brief: Get the status of all the OFF Fault status
* \param: ChannelID
* \return: Status TUE/FALSE
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 13473301
* Req.-ID: 13473374
* Req.-ID: 13473418
* Req.-ID: 13473420
* Req.-ID: 13394552
* Req.-ID: 13394152
* Req.-ID: 13394917
* Req.-ID: 13394914
* Req.-ID: 15768392
* Req.-ID: 15768418
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_GetOFFFaultDetectedFlags     
 * Remarks:  DD-ID: {B00B391D-0507-4fea-AC6D-9E70117DBE07}
 * ===========================================================================*/
static  bool UssHsd_f_GetOFFFaultDetectedFlags(const uint8_t ChannelID)   /* PRQA S 3219*/
{
	if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID){
		return (bool)USDiagnostic_GetECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT);
	}
	else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID){
		return  (bool)USDiagnostic_GetECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT);
	}
	else{
		return (bool)ME_FALSE;
	}
}
/* ===========================================================================*/
/* UssHsd_f_ClearOnFaultDetectedFlags.
* Brief: Clear fault flags if fault is recovered in HSD ON condition
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 15768198
* Req.-ID: 15768224
* Req.-ID: 15768291
* Req.-ID: 15768296
* Req.-ID: 15768434
* Req.-ID: 15768440
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_ClearOnFaultDetectedFlags     
 * Remarks:  DD-ID: {8F4B7E23-6313-4be9-AC6D-2947CA60E8EF}
 * ===========================================================================*/
static void UssHsd_f_ClearOnFaultDetectedFlags(const uint8_t error_bitmask,const uint8_t ChannelID)
{
    /* CLEAR fault flags */
   // Uss_HsdStateMachine[ChannelID].eHSDOnError = USS_HSD_NO_ERR_MASK;
    switch(error_bitmask)
    	{
    		case(USS_HSD_OPN_CRKT_FAIL_MASK):
				Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Open_Circuit_Failure = (bool_t)ME_FALSE;
#ifdef US_HSD_SUPPORT_OC_FAULT_REPORT
    			if(Uss_Hsd_Channel_PWR_A == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_FRONT_BUMPER_OPEN);
    			}
    			else if(Uss_Hsd_Channel_PWR_B == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_REAR_BUMPER_OPEN);
    			}
    			else
    			{ /*empty*/
    			}
#endif
    		break;

			
			#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
			case(USS_HSD_VTG_OOR_LOW_MASK):
                if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
                {
					Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Voltage_Out_Of_Range = (bool_t)ME_FALSE;
                }
				else
				{
					;/* No Action */
				}
    			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR_LOW); 
    			}
    			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_REAR_BUMPER_OOR_LOW); 
    			}
    			else
    			{/*empty*/
    			}
    		break;
			case(USS_HSD_VTG_OOR_HIGH_MASK):    //need changes
                if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
                {
					Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Voltage_Out_Of_Range = (bool_t)ME_FALSE;
                }
				else
				{
					;/* No Action */
				}
    			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR_HIGH);
    			}
    			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_REAR_BUMPER_OOR_HIGH);
    			}
    			else
    			{/*empty*/

    			}
    		break;			

			#else
    		case(USS_HSD_VTG_OOR_MASK):
				Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Voltage_Out_Of_Range =(bool_t) ME_FALSE;
    			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_FRONT_BUMPER_OOR);
    			}
    			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_REAR_BUMPER_OOR);
    			}
    			else
    			{/*empty*/
    			}
    		break;
			#endif
				

    		case(USS_HSD_SHRT_TO_GND_MASK):
                if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
                {
					Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Short_To_Ground = (bool_t)ME_FALSE;
    			}
				else
				{
					;/* No Action */
				}
                if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND);
    			}
    			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
    			{
    				US_Diagnostic_ClrECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND);
    			}
    			else
    			{/*empty*/
    			}
    		break; 
    		default:/*empty*/
    			break;
    	}
}
/* ===========================================================================*/
/* UssHsd_f_ClearOffFaultDetectedFlags.
* Brief: Clear fault flags if fault is recovered in HSD OFF condition
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 15768282
* Req.-ID: 15768288
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_ClearOffFaultDetectedFlags     
 * Remarks:  DD-ID: {EF947C09-A6B8-41ee-B7BC-6D46A954746C}
 * ===========================================================================*/
static void UssHsd_f_ClearOffFaultDetectedFlags(const uint8_t error_bitmask,const uint8_t ChannelID)
{
    /* CLEAR fault flags */
	switch(error_bitmask)
	{
		case(USS_HSD_SHRT_TO_BAT_MASK):
            if(ChannelID < (uint8_t) Uss_Hsd_Channel_Max)
            {
			       Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags.Uss_Hsd_Pwr_Short_To_Battery =(bool_t)ME_FALSE;
            }
			else
			{
				;/* No Action */
			}
			if((uint8_t)Uss_Hsd_Channel_PWR_A == ChannelID)
			{
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT);
			}
			else if((uint8_t)Uss_Hsd_Channel_PWR_B == ChannelID)
			{
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT);
			}
			else
			{ /*empty*/
			}
		break;

		default: /*empty*/
		break;
	}
}
/* ===========================================================================*/
/* UssHsd_f_SetHsdState.
* Brief: Set HSD current and previous state
* \param: ChannelID
* \return: None
* \remarks  no remarks
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_SetHsdState     
 * Remarks:  DD-ID: {B4CBC570-0476-4764-A7AA-C6D07037D084}
 * ===========================================================================*/
static void UssHsd_f_SetHsdState(const UssHsd_E_State_t eHsdState,const uint8_t ChannelID)
{
    /*save current HSD state into previous state variable  and  Set HSD state as per eHsdState */
	Uss_HsdStateMachine[ChannelID].eHSDPrvState = Uss_HsdStateMachine[ChannelID].eHSDState;
	Uss_HsdStateMachine[ChannelID].eHSDState = eHsdState;
}
/* ===========================================================================*/
/* UssHsd_f_Pwr_En_Status.
* Brief: Get PWR pin status
* \param: ChannelID
* \return: None
* \remarks  no remarks
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_f_Pwr_En_Status     
 * Remarks:  DD-ID: {B90C4BA6-11F7-4309-95CC-07F485D9EF3D}
 * ===========================================================================*/
static uint8_t UssHsd_f_Pwr_En_Status(const uint8_t ChannelID)
{
    uint8_t temp = 0;
    switch(ChannelID)
    {
        case (uint8_t)Uss_Hsd_Channel_PWR_A:
            temp = US_Com_GetHsdPwrChannel_A();
            break;

        case (uint8_t)Uss_Hsd_Channel_PWR_B:
            temp = US_Com_GetHsdPwrChannel_B();			
            break;

        default: /*empty*/
            break;
    }
    return temp;
}

/* ===========================================================================*/
/* UssHsd_F_psGet_Diagnostics_Flags.
* Brief: Return diagnostics flags
* \param: ChannelID
* \return: UssHsd_S_Diagnostics_Flags_t
* \remarks  no remarks
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_F_psGet_Diagnostics_Flags     
 * Remarks:  DD-ID: {D65C0746-124D-47ee-B283-6C955258B35A}
 * ===========================================================================*/
UssHsd_S_Diagnostics_Flags_t UssHsd_F_psGet_Diagnostics_Flags(const uint8_t ChannelID)
{
    return Uss_HsdStateMachine[ChannelID].HSD_Diagnostics_Flags;
}
/* ===========================================================================*/
/* UssHsd_F_psGet_Pwr_Vtg_mV.
* Brief: Return voltage in mV of ChannelID
* \param: ChannelID
* \return: uint16_t
* \remarks  no remarks
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_F_psGet_Pwr_Vtg_mV     
 * Remarks:  DD-ID: {4EFA0A9A-55ED-4486-A646-8050EF5011D8}
 * ===========================================================================*/
uint16_t UssHsd_F_psGet_Pwr_Vtg_mV(const uint8_t ChannelID)
{
    return Uss_HsdStateMachine[ChannelID].vVoltage;
}
/* ===========================================================================*/
/* UssHsd_F_psGet_Pwr_Ct_mA.
* Brief: Return current in mA of ChannelID
* \param: ChannelID
* \return: uint16_t
* \remarks  no remarks
* Req.-ID: 13394917
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_F_psGet_Pwr_Ct_mA     
 * Remarks:  DD-ID: {CBED5598-9244-4e03-99A6-FAF6300F35C3}
 * ===========================================================================*/
uint16_t UssHsd_F_psGet_Pwr_Ct_mA(const uint8_t ChannelID)
{
    return Uss_HsdStateMachine[ChannelID].vCurrent;
}

/* ===========================================================================*/
/* UssHsd_F_CopyVoltageMonitorValueFromIPC.
* Brief: Return current in mA of ChannelID
* \param: ChannelID
* \return: uint16_t
* \remarks  no remarks
===========================================================================*/
/* ===========================================================================
 * Name: UssHsd_F_CopyVoltageMonitorValueFromIPC     
 * Remarks:  DD-ID: {D01F47F5-C58C-4128-B0DB-2537706997CB}
 * ===========================================================================*/
void UssHsd_F_CopyVoltageMonitorValueFromIPC(const USS_Curr_Volt_Monitor_t * const sUSS_Curr_Volt_Monitor_l )  
{

#if(USS_STUB_INPUT_TEST_HSD == US_STD_ON)
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_A].vVoltage = stub_HsdVtgval[Uss_Hsd_Channel_PWR_A];	//sUSS_Curr_Volt_Monitor_l->Volt_A;
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_B].vVoltage = stub_HsdVtgval[Uss_Hsd_Channel_PWR_B];	//sUSS_Curr_Volt_Monitor_l->Volt_B;
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_A].vCurrent = stub_HsdCurval[Uss_Hsd_Channel_PWR_A];	//sUSS_Curr_Volt_Monitor_l->Curr_A;
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_B].vCurrent = stub_HsdCurval[Uss_Hsd_Channel_PWR_B];	//sUSS_Curr_Volt_Monitor_l->Curr_B;
#else
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_A].vVoltage = sUSS_Curr_Volt_Monitor_l->Volt_A;
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_B].vVoltage = sUSS_Curr_Volt_Monitor_l->Volt_B;
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_A].vCurrent = sUSS_Curr_Volt_Monitor_l->Curr_A;
	Uss_HsdStateMachine[Uss_Hsd_Channel_PWR_B].vCurrent = sUSS_Curr_Volt_Monitor_l->Curr_B;
#endif
}

/* ===========================================================================*/
/* UssHsd_f_ChkONFaultRecovery.
* Brief: Return current in mA of ChannelID
* \param: ChannelID
* \return: uint16_t
* \remarks  no remarks
* Req.-ID: 13394917
===========================================================================*/
/* ===========================================================================
* Name:	 UssHsd_f_ChkONFaultRecovery
* Remarks:  DD-ID: {858FBBD9-9073-433d-B46E-0DD43AE7642D}
* ===========================================================================*/
static void UssHsd_f_ChkONFaultRecovery(const uint8_t ChannelID)
{
	if((uint8_t)UssHsd_Pwr_En_High == UssHsd_f_Pwr_En_Status(ChannelID))
	{
#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW == US_FEATURE_ON)
		if((uint8_t)USS_HSD_VTG_OOR_LOW_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_VTG_OOR_LOW_MASK))
		{
			UssHsd_f_ClearFaultValidation_VtgOutOfRange_Low(ChannelID);
			UssMgr_SetSysState(SYSMGR_SYS_POWERON);
		}
		else
		{
			;/* No Action */
		}
#endif

#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH == US_FEATURE_ON)
		if((uint8_t)USS_HSD_VTG_OOR_HIGH_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_VTG_OOR_HIGH_MASK))
		{
			UssHsd_f_ClearFaultValidationVltgOutOfRangeHigh(ChannelID);
			UssMgr_SetSysState(SYSMGR_SYS_POWERON);
		}
		else
		{
			;/* No Action */
		}
#endif
		
		#else		
		if(USS_HSD_VTG_OOR_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_VTG_OOR_MASK))
		{
			if((Uss_HsdStateMachine[ChannelID].vVoltage > USS_HSD_PWR_OOR_CLR_HYST_LH
			&& Uss_HsdStateMachine[ChannelID].vVoltage <= USS_HSD_PWR_OOR_CLR_HYST_HL))
			{
				Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError &= (~(uint8_t)USS_HSD_VTG_OOR_MASK);
				UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_VTG_OOR_MASK,ChannelID);
				UssMgr_SetSysState(SYSMGR_SYS_POWERON);
			}
			else
			{
				/*Do Nothing*/
			}
		}
		else
		{
			/*Do Nothing*/
		}
#endif /*US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS*/

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND == US_FEATURE_ON)
		if(USS_HSD_SHRT_TO_GND_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_SHRT_TO_GND_MASK))
		{
			UssHsd_f_ClearFaultValidation_ShortToGnd(ChannelID);
			UssMgr_SetSysState(SYSMGR_SYS_POWERON);
		}
#endif

#if(US_FEATURE_HSD_FAULT_DET_OPEN_CIRCUIT == US_FEATURE_ON)
		if(USS_HSD_OPN_CRKT_FAIL_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError & (uint8_t)USS_HSD_OPN_CRKT_FAIL_MASK))
		{
			if ((USS_HSD_RAIL_CUR_HYST_MIN <= Uss_HsdStateMachine[ChannelID].vCurrent) && (USS_HSD_OCF_CLR_HYST <= Uss_HsdStateMachine[ChannelID].vVoltage))
			{
				Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError &= (~(uint8_t)USS_HSD_OPN_CRKT_FAIL_MASK);
				UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_OPN_CRKT_FAIL_MASK,ChannelID);
				UssMgr_SetSysState(SYSMGR_SYS_POWERON);
			}
			else
			{
				/*Do Nothing*/
			}
		}
		else
		{
			/*Do Nothing*/
		}
#endif/*US_FEATURE_HSD_FAULT_DET_OPEN_CIRCUIT*/
	}
	else if((uint8_t)UssHsd_Pwr_En_Low == UssHsd_f_Pwr_En_Status(ChannelID))
	{
		Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError = (uint8_t)USS_HSD_NO_ERR_MASK;
		Uss_HsdStateMachine[ChannelID].eHSDOnError = (uint8_t)USS_HSD_NO_ERR_MASK;
		/*Clear All fault*/
		#if((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
			UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_VTG_OOR_LOW_MASK,ChannelID);
			UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_VTG_OOR_HIGH_MASK,ChannelID);
		#else
			UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_VTG_OOR_MASK,ChannelID);
		#endif
		UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_SHRT_TO_GND_MASK,ChannelID);
		UssHsd_f_ClearOnFaultDetectedFlags(USS_HSD_OPN_CRKT_FAIL_MASK,ChannelID);
		UssMgr_SetSysState(SYSMGR_SYS_POWERON);
	}
	else
	{
		/*Do nothing*/
	}
}


/* ===========================================================================*/
/* UssHsd_f_ChkOFFFaultRecovery.
* Brief: Return current in mA of ChannelID
* \param: ChannelID
* \return: uint16_t
* \remarks  no remarks
* Req.-ID: 13394552
===========================================================================*/
/* ===========================================================================
* Name:	 UssHsd_f_ChkOFFFaultRecovery
* Remarks:  DD-ID: {0393841C-FF6D-4e67-8611-3891D75CD7CB}
* ===========================================================================*/
static void UssHsd_f_ChkOFFFaultRecovery(const uint8_t ChannelID)
{
	if((uint8_t)UssHsd_Pwr_En_Low == UssHsd_f_Pwr_En_Status(ChannelID))
	{
		if((uint8_t)USS_HSD_SHRT_TO_BAT_MASK == (Uss_HsdStateMachine[ChannelID].eHSDOffConfirmError &(uint8_t) USS_HSD_SHRT_TO_BAT_MASK))
		{
#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_BAT == US_FEATURE_ON)
			if((uint8_t)USS_HSD_NO_ERR_MASK == ((uint8_t)USS_HSD_SHRT_TO_BAT_MASK & Uss_HsdStateMachine[ChannelID].eHSDOffConfirmError))
			{
				UssHsd_f_ClearFaultValidation_ShortToBatt(ChannelID);
			}
			else
			{
				;/* No Action */
			}
#endif
		}
		else
		{
			;/* No Action */
		}
	}
	else if((uint8_t)UssHsd_Pwr_En_High == UssHsd_f_Pwr_En_Status(ChannelID))
	{
		Uss_HsdStateMachine[ChannelID].eHSDOffConfirmError = (uint8_t)USS_HSD_NO_ERR_MASK;
		Uss_HsdStateMachine[ChannelID].eHSDOffError = (uint8_t)USS_HSD_NO_ERR_MASK;
		UssHsd_f_ClearOffFaultDetectedFlags(USS_HSD_SHRT_TO_BAT_MASK,ChannelID);
	}
	else
	{
		/*Do nothing*/
	}
}

/**
 * \brief 
 * 
 * \param ChannelID 
 */
/* ===========================================================================
* Name:	 UssHsd_Shutdown
* Remarks:  DD-ID: {6A5D9CC2-4CB0-48e2-AC14-151D89C2BBD4}
* ===========================================================================*/
static void UssHsd_Shutdown(const  uint8_t ChannelID)
{
   UssHsd_F_SetOnOffRequest((UssHsd_E_ChannelID_t)ChannelID,SetOnOffRequest_OFF);
}


#if(US_CSM_ENABLE == ME_TRUE)
/**
 * \brief 
 * 
 * \param instanceId 
 * \param reqState 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
* Name:	 Us_Hsd_ReqState_Csm
* Remarks:  DD-ID: {DE31E3FF-958F-4708-BD64-F7505616DBFB}
* ===========================================================================*/
 UsCsm_StdReturn_Type Us_Hsd_ReqState_Csm(const UsCsm_InstanceId_Type instanceId, const UsCsm_LocalStateId_Type reqState)
 {
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;

	if((UsCsm_InstanceId_Type)Uss_Hsd_Channel_Max > instanceId)
	{
		if(US_CSM_LOCAL_STATE_SHUTDOWN == reqState)
		{
			UssHsd_Shutdown((uint8_t)instanceId);
		}
		else if (US_CSM_LOCAL_STATE_ACTIVE == reqState)
		{
			UssHsd_F_SetOnOffRequest((UssHsd_E_ChannelID_t)instanceId, SetOnOffRequest_ON);
		}
		else
		{  /*Do nothing*/
		}
	}
	else
	{
		;/* No Action */
	}
	
	return (stdRet);
 }

/**
 * \brief 
 * 
 * \param instanceId 
 * \return UsCsm_LocalStateId_Type 
 */
/* ===========================================================================
* Name:	 Us_Hsd_GetState_Csm
* Remarks:  DD-ID: {8D6B2912-EE98-481b-A255-AF1207D21CD8}
* ===========================================================================*/
 UsCsm_LocalStateId_Type Us_Hsd_GetState_Csm(const UsCsm_InstanceId_Type instanceId)
 {
	UsCsm_LocalStateId_Type localStateId = US_CSM_LOCAL_STATE_UN_INIT;

	if((UsCsm_InstanceId_Type)Uss_Hsd_Channel_Max > instanceId)
	{
		switch(Uss_HsdStateMachine[instanceId].eHSDState)
		{
			case Uss_Hsd_State_Init:
			localStateId = US_CSM_LOCAL_STATE_INIT;
			break;

			/*active blancet state for csm*/
			case Uss_Hsd_State_OutputOnOff:    
			case Uss_Hsd_State_OutputOnCheck:
			case Uss_Hsd_State_OutputOffCheck:
			localStateId = US_CSM_LOCAL_STATE_IDLE;
			break;

			//case Uss_Hsd_State_OutputOnCheck:
			case Uss_Hsd_State_OutputOn:       
			//case Uss_Hsd_State_OutputOffCheck:   
			localStateId = US_CSM_LOCAL_STATE_ACTIVE;
			break;

			case Uss_Hsd_State_Fault:
			case Uss_Hsd_State_Fault_Recovery:
			localStateId = US_CSM_LOCAL_STATE_FAULT;
			break;

			case Uss_Hsd_State_OutputOff: 
			localStateId = US_CSM_LOCAL_STATE_SHUTDOWN;
			break;

			default:
			localStateId = US_CSM_LOCAL_STATE_UNDEFINED;
			break;
		}
	}
	else
	{
		;/* No Action */
	}

	return (localStateId);
 }

#endif

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_BAT == US_FEATURE_ON)
/**
 * \brief This function validate if fault is clear 
*/
/* ===========================================================================
* Name:	 UssHsd_f_ClearFaultValidation_ShortToBatt
* Remarks:  DD-ID: {63D70756-2920-4295-B871-6F5C09F92A23}
* ===========================================================================*/
static void UssHsd_f_ClearFaultValidation_ShortToBatt(const uint8_t ChannelID)
{
	if((uint8_t)ME_TRUE == HsdDiagErr_ShortToBatt[ChannelID].ThresholdLockClr)
	{
		if(((uint32_t)USS_HSD_PWR_STB_MIN +(uint32_t) HSD_ERR_HYS_VTG_IN_mV_STB) > Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeClr)
			{
				HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STB;
				if(HsdDiagErr_ShortToBatt[ChannelID].RetryCntClr != ZERO)
				{
					HsdDiagErr_ShortToBatt[ChannelID].RetryCntClr--;
				}
				else
				{
				  Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError &= (~(uint8_t)USS_HSD_SHRT_TO_BAT_MASK);
				  Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_SHRT_TO_BAT_MASK);
				  UssHsd_f_ResetClrCounters_ShortToBatt(ChannelID);
				  UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_Short_to_Bat, US_HSD_ERR_STATE_PASSIVE);
				}
			}
			else
			{
				HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeClr = (HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeClr - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
           UssHsd_f_ResetClrCounters_ShortToBatt(ChannelID);
		}					
	}
	else
	{
		if(USS_HSD_PWR_STB_MIN > Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			UssHsd_f_ResetClrCounters_ShortToBatt(ChannelID);
			HsdDiagErr_ShortToBatt[ChannelID].ThresholdLockClr = ME_TRUE;	
		}
		else
		{
			;/* No Action */
		}
	}
}

/** This function reset the set counters of short to battery detection.
 * \brief 
 * 
 * \param ChannelID 
 */
/* ===========================================================================
* Name:	 UssHsd_f_ResetClrCounters_ShortToBatt
* Remarks:  DD-ID: {611161B0-4530-4ecd-A019-BF7273FBA574}
* ===========================================================================*/
static void UssHsd_f_ResetClrCounters_ShortToBatt(const uint8_t ChannelID)
{
	HsdDiagErr_ShortToBatt[ChannelID].ThresholdLockClr = ME_FALSE;	
	HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STB;
	HsdDiagErr_ShortToBatt[ChannelID].RetryCntClr = HSD_ERR_CLR_RETRY_CNT_STB;
}

/**
 * \brief This function validate if fault is set 
*/
/* ===========================================================================
* Name:	 UssHsd_f_SetFaultValidation_ShortToBatt
* Remarks:  DD-ID: {FC79F361-8FE0-4778-ADE9-795F63735F13}
* ===========================================================================*/
static void UssHsd_f_SetFaultValidation_ShortToBatt(const uint8_t ChannelID)
{
	/*Short to Ground*/
	if((uint8_t)ME_TRUE == HsdDiagErr_ShortToBatt[ChannelID].ThresholdLockSet)
	{
		if(((uint32_t)USS_HSD_PWR_STB_MAX -(uint32_t) HSD_ERR_HYS_VTG_IN_mV_STB) < Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |=(uint8_t) USS_HSD_SHRT_TO_BAT_MASK;
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeSet)
			{
				HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STB;
				if(HsdDiagErr_ShortToBatt[ChannelID].RetryCntSet != ZERO)
				{
					HsdDiagErr_ShortToBatt[ChannelID].RetryCntSet--;
					UssHsd_Report_InternalError(ChannelID,US_HSD_ERR_ID_Short_to_Bat,US_HSD_ERR_STATE_ACTIVE);
				}
				else
				{
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError |=(uint8_t) USS_HSD_SHRT_TO_BAT_MASK;
					UssHsd_f_ResetSetCounters_ShortToBatt(ChannelID);
					UssHsd_Report_InternalError(ChannelID,US_HSD_ERR_ID_Short_to_Bat,US_HSD_ERR_STATE_CONFIRM);
				}
			}
			else
			{
				HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeSet = (HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeSet - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
            UssHsd_f_ResetSetCounters_ShortToBatt(ChannelID);
			Uss_HsdStateMachine[ChannelID].eHSDOnError &=(~(uint8_t) USS_HSD_SHRT_TO_BAT_MASK);
		}					
	}
	else
	{
		if(USS_HSD_PWR_STB_MAX < Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |=(uint8_t) USS_HSD_SHRT_TO_BAT_MASK;
			UssHsd_f_ResetSetCounters_ShortToBatt(ChannelID);
			HsdDiagErr_ShortToBatt[ChannelID].ThresholdLockSet = ME_TRUE;	
		}
		else
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError &=(~(uint8_t) USS_HSD_SHRT_TO_BAT_MASK);
		}
	}
}

/** This function reset the set counters of short to battery detection.
 * \brief 
 * \param ChannelID 
 */
/* ===========================================================================
* Name:	 UssHsd_f_ResetSetCounters_ShortToBatt
* Remarks:  DD-ID: {F124595E-22D2-4e5f-845A-764DD3C9F521}
* ===========================================================================*/
static void UssHsd_f_ResetSetCounters_ShortToBatt(const uint8_t ChannelID)
{
	HsdDiagErr_ShortToBatt[ChannelID].ThresholdLockSet = ME_FALSE;	
	HsdDiagErr_ShortToBatt[ChannelID].RetryCntSet = HSD_ERR_SET_RETRY_CNT_STB;
	HsdDiagErr_ShortToBatt[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STB;
}
#endif

#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND == US_FEATURE_ON)
/**
 * \brief This function validate if fault is clear 
*/
static void UssHsd_f_ClearFaultValidation_ShortToGnd(uint8_t ChannelID)
{
	if(ME_TRUE == HsdDiagErr_ShortToGnd[ChannelID].ThresholdLockClr)
	{
		if((USS_HSD_PWR_STG_CLR_HYST + HSD_ERR_HYS_CURRENT_IN_mA_STG) > Uss_HsdStateMachine[ChannelID].vCurrent)
		{
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeClr)
			{
				HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STG;
				if(HsdDiagErr_ShortToGnd[ChannelID].RetryCntClr)
				{
					HsdDiagErr_ShortToGnd[ChannelID].RetryCntClr--;
				}
				else
				{
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError &= (~(uint8_t)USS_HSD_SHRT_TO_GND_MASK);
					Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_SHRT_TO_GND_MASK);
					UssHsd_f_ResetClrCounters_ShortToGnd(ChannelID);
					UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_short_to_GND, US_HSD_ERR_STATE_PASSIVE);
				}
			}
			else
			{
				HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeClr = (HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeClr - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
			UssHsd_f_ResetClrCounters_ShortToGnd(ChannelID);
		}					
	}
	else
	{
		if(USS_HSD_PWR_STG_CLR_HYST > Uss_HsdStateMachine[ChannelID].vCurrent)
		{
			UssHsd_f_ResetClrCounters_ShortToGnd(ChannelID);
			HsdDiagErr_ShortToGnd[ChannelID].ThresholdLockClr = ME_TRUE;	
		}
	}
}


/**
 * \brief 
 * 
 * \param ChannelID 
 */
static void UssHsd_f_ResetClrCounters_ShortToGnd(uint8_t ChannelID)
{
	HsdDiagErr_ShortToGnd[ChannelID].RetryCntClr = HSD_ERR_CLR_RETRY_CNT_STG;
	HsdDiagErr_ShortToGnd[ChannelID].ThresholdLockClr = ME_FALSE;	
	HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_STG;
}

/**
 * \brief This function validate if fault is set 
*/
static void UssHsd_f_SetFaultValidation_ShortToGnd(uint8_t ChannelID)
{
	/*Short to Ground*/
	if(ME_TRUE == HsdDiagErr_ShortToGnd[ChannelID].ThresholdLockSet)
	{
		if((USS_HSD_PWR_STG_THRSH - HSD_ERR_HYS_CURRENT_IN_mA_STG) < Uss_HsdStateMachine[ChannelID].vCurrent)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |= (uint8_t)USS_HSD_SHRT_TO_GND_MASK;
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeSet)
			{
				HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STG;
				if(HsdDiagErr_ShortToGnd[ChannelID].RetryCntSet)
				{
					HsdDiagErr_ShortToGnd[ChannelID].RetryCntSet--;
					UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_short_to_GND, US_HSD_ERR_STATE_ACTIVE);
				}
				else
				{
					UssHsd_f_ResetSetCounters_ShortToGnd(ChannelID);
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError |= (uint8_t)USS_HSD_SHRT_TO_GND_MASK;
					UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_short_to_GND, US_HSD_ERR_STATE_CONFIRM);
				}
			}
			else
			{
				HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeSet = (HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeSet - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
            UssHsd_f_ResetSetCounters_ShortToGnd(ChannelID);
		    Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_SHRT_TO_GND_MASK);
		}					
	}
	else
	{
		if(USS_HSD_PWR_STG_THRSH < Uss_HsdStateMachine[ChannelID].vCurrent)
		{
		    Uss_HsdStateMachine[ChannelID].eHSDOnError |= (uint8_t)USS_HSD_SHRT_TO_GND_MASK;
			UssHsd_f_ResetSetCounters_ShortToGnd(ChannelID);
			HsdDiagErr_ShortToGnd[ChannelID].ThresholdLockSet = ME_TRUE;	
		}
		else
		{
		    Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_SHRT_TO_GND_MASK);
		}
	}
}

/**
 * \brief 
 * 
 * \param ChannelID 
 */
static void UssHsd_f_ResetSetCounters_ShortToGnd(uint8_t ChannelID)
{
	HsdDiagErr_ShortToGnd[ChannelID].ThresholdLockSet = ME_FALSE;	
	HsdDiagErr_ShortToGnd[ChannelID].RetryCntSet = HSD_ERR_SET_RETRY_CNT_STG;
	HsdDiagErr_ShortToGnd[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_STG;
}
#endif /*US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND*/


#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW == US_FEATURE_ON)
/**
 * \brief This function validate if fault is clear 
*/
/* ===========================================================================
	* Name:	 UssHsd_f_ClearFaultValidation_VtgOutOfRange_Low
	* Remarks:  DD-ID: {C2375B8E-7517-456c-A1A9-9E4CB43D45C5}
	* ===========================================================================*/
static void UssHsd_f_ClearFaultValidation_VtgOutOfRange_Low(const uint8_t ChannelID)
{
	if((uint8_t)ME_TRUE == HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdLockClr)
	{
		if(((uint32_t)USS_HSD_PWR_OOR_LOW -(uint32_t) HSD_ERR_HYS_VOLTAGE_IN_mV_VTG_OOR_LOW) < Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeClr)
			{
				HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_LOW;
				if(HsdDiagErr_VtgOutOfRange_Low[ChannelID].RetryCntClr != ZERO)
				{
					HsdDiagErr_VtgOutOfRange_Low[ChannelID].RetryCntClr--;
				}
				else
				{					
					UssHsd_f_ResetClrCounters_VtgOutOfRange_Low(ChannelID);
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError &= (~(uint8_t)USS_HSD_VTG_OOR_LOW_MASK);    /* PRQA S 4434 */
					Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_VTG_OOR_LOW_MASK);    /* PRQA S 4434 */
					UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_voltage_OOR_Low, US_HSD_ERR_STATE_PASSIVE);
				}
			}
			else
			{
				HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeClr = (HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeClr - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
			UssHsd_f_ResetClrCounters_VtgOutOfRange_Low(ChannelID);
		}					
	}
	else
	{
		if(USS_HSD_PWR_OOR_LOW < Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			UssHsd_f_ResetClrCounters_VtgOutOfRange_Low(ChannelID);
			HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdLockClr = ME_TRUE;	
		}
		else
		{
			;/* No Action */
		}
	}
}

/**
 * \brief This functions clears the clear counters for out of range low
 * 
 * \param ChannelID 
 */
/* ===========================================================================
	* Name:	 UssHsd_f_ResetClrCounters_VtgOutOfRange_Low
	* Remarks:  DD-ID: {344B3AA1-BE6D-4eb7-B87E-DE46DF578134}
	* ===========================================================================*/
static void UssHsd_f_ResetClrCounters_VtgOutOfRange_Low(const uint8_t ChannelID)
{
	HsdDiagErr_VtgOutOfRange_Low[ChannelID].RetryCntClr = HSD_ERR_CLR_RETRY_CNT_VTG_OOR_LOW;
	HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdLockClr = ME_FALSE;	
	HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_LOW;
}


/**
 * \brief This function validate if fault is set 
*/
/* ===========================================================================
	* Name:	 UssHsd_f_SetFaultValidation_VtgOutOfRange_Low
	* Remarks:  DD-ID: {7AD62171-C3CD-4006-95AF-3804F0EA5FFB}
	* ===========================================================================*/
static void UssHsd_f_SetFaultValidation_VtgOutOfRange_Low(const uint8_t ChannelID)
{
	if((uint8_t)ME_TRUE == HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdLockSet)
	{
		if(((uint32_t)USS_HSD_PWR_OOR_LOW + (uint32_t)HSD_ERR_HYS_VOLTAGE_IN_mV_VTG_OOR_LOW) > Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |= (uint8_t)USS_HSD_VTG_OOR_LOW_MASK;
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeSet)
			{
				HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_LOW;
				if(HsdDiagErr_VtgOutOfRange_Low[ChannelID].RetryCntSet != ZERO)
				{
					HsdDiagErr_VtgOutOfRange_Low[ChannelID].RetryCntSet--;
					UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_voltage_OOR_Low, US_HSD_ERR_STATE_ACTIVE);
				}
				else
				{
					UssHsd_f_ResetSetCounters_VtgOutOfRange_Low(ChannelID);
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError |= (uint8_t)USS_HSD_VTG_OOR_LOW_MASK;
					UssHsd_Report_InternalError(ChannelID, US_HSD_ERR_ID_voltage_OOR_Low, US_HSD_ERR_STATE_CONFIRM);
				}
			}
			else
			{
				HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeSet = (HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeSet - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
            UssHsd_f_ResetSetCounters_VtgOutOfRange_Low(ChannelID);
			Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_VTG_OOR_LOW_MASK);
		}					
	}
	else
	{
		if(USS_HSD_PWR_OOR_LOW > Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |= (uint8_t)USS_HSD_VTG_OOR_LOW_MASK;
			UssHsd_f_ResetSetCounters_VtgOutOfRange_Low(ChannelID);
			HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdLockSet = ME_TRUE;	
		}
		else
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_VTG_OOR_LOW_MASK);
		}
			
	}
}

/**
 * \brief This functions clears the set counters for out of range Low
 * 
 * \param ChannelID 
 */
/* ===========================================================================
	* Name:	 UssHsd_f_ResetSetCounters_VtgOutOfRange_Low
	* Remarks:  DD-ID: {3A51C642-4E30-447b-94F8-DC61CF725E4B}
	* ===========================================================================*/
static void UssHsd_f_ResetSetCounters_VtgOutOfRange_Low(const uint8_t ChannelID)
{
	HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdLockSet = ME_FALSE;	
	HsdDiagErr_VtgOutOfRange_Low[ChannelID].RetryCntSet = HSD_ERR_SET_RETRY_CNT_VTG_OOR_LOW;
	HsdDiagErr_VtgOutOfRange_Low[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_LOW;
}

#endif /*US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW*/


#if(US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH == US_FEATURE_ON)
/**
 * \brief This function validate if fault is clear 
*/
/* ===========================================================================
	* Name:	 UssHsd_f_ClearFaultValidationVltgOutOfRangeHigh
	* Remarks:  DD-ID: {10603C4B-352D-4fcc-BAEE-E9D3E24E4ACF}
	* ===========================================================================*/
static void UssHsd_f_ClearFaultValidationVltgOutOfRangeHigh(const uint8_t ChannelID)
{
	if((uint8_t)ME_TRUE == HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdLockClr)
	{
		if(((uint32_t)USS_HSD_PWR_OOR_HIGH + (uint32_t)HSD_ERR_HYS_VOLTAGE_IN_mV_VTG_OOR_HIGH) > Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeClr)
			{
				HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_HIGH;
				if(HsdDiagErr_VtgOutOfRange_High[ChannelID].RetryCntClr !=ZERO)
				{
					HsdDiagErr_VtgOutOfRange_High[ChannelID].RetryCntClr--;
				}
				else
				{
                    UssHsd_f_ResetClrCounters_VltgOutOfRangeHigh(ChannelID);
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError &= (~(uint8_t)USS_HSD_VTG_OOR_HIGH_MASK);
					Uss_HsdStateMachine[ChannelID].eHSDOnError        &= (~(uint8_t)USS_HSD_VTG_OOR_HIGH_MASK);
					UssHsd_Report_InternalError(ChannelID,US_HSD_ERR_ID_voltage_OOR_High,US_HSD_ERR_STATE_PASSIVE);
				}
			}
			else
			{
				HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeClr = (HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeClr - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
			UssHsd_f_ResetClrCounters_VltgOutOfRangeHigh(ChannelID);
		}					
	}
	else
	{
		if(USS_HSD_PWR_OOR_HIGH > Uss_HsdStateMachine[ChannelID].vVoltage)
		{
            UssHsd_f_ResetClrCounters_VltgOutOfRangeHigh(ChannelID);
			HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdLockClr = ME_TRUE;	
		}
		else
		{
			;/* No Action */
		}
	}
}


/**
 * \brief This functions clears the clear counters for out of range high
 * 
 * \param ChannelID 
 */
/* ===========================================================================
	* Name:	 UssHsd_f_ResetClrCounters_VltgOutOfRangeHigh
	* Remarks:  DD-ID: {A9D0B294-3A78-49ef-A386-E7A42974CA58}
	* ===========================================================================*/
static void UssHsd_f_ResetClrCounters_VltgOutOfRangeHigh(const uint8_t ChannelID)
{
	HsdDiagErr_VtgOutOfRange_High[ChannelID].RetryCntClr = HSD_ERR_CLR_RETRY_CNT_VTG_OOR_HIGH;
	HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdLockClr = ME_FALSE;	
	HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeClr = HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_HIGH;
}


/**
 * \brief This function validate if fault is set 
*/
/* ===========================================================================
	* Name:	 UssHsd_f_SetFaultValidation_VltgOutOfRangeHigh
	* Remarks:  DD-ID: {5AA1A320-C90F-467d-B4EC-CE96A69F3CAE}
	* ===========================================================================*/
static void UssHsd_f_SetFaultValidation_VltgOutOfRangeHigh(const uint8_t ChannelID)
{
	if((uint8_t)ME_TRUE == HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdLockSet)
	{
		if(((uint32_t)USS_HSD_PWR_OOR_HIGH - (uint32_t)HSD_ERR_HYS_VOLTAGE_IN_mV_VTG_OOR_HIGH) < Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |= (uint8_t)USS_HSD_VTG_OOR_HIGH_MASK;
			if(HSD_TIME_CHECK_EXPIRE == HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeSet)
			{
				HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_HIGH;
				if(HsdDiagErr_VtgOutOfRange_High[ChannelID].RetryCntSet != ZERO)
				{
					HsdDiagErr_VtgOutOfRange_High[ChannelID].RetryCntSet--;
					UssHsd_Report_InternalError(ChannelID,US_HSD_ERR_ID_voltage_OOR_High,US_HSD_ERR_STATE_ACTIVE);
				}
				else
				{
					UssHsd_f_ResetSetCounters_VltgOutOfRangeHigh(ChannelID);
					Uss_HsdStateMachine[ChannelID].eHSDOnConfirmError |= (uint8_t)USS_HSD_VTG_OOR_HIGH_MASK;
					UssHsd_Report_InternalError(ChannelID,US_HSD_ERR_ID_voltage_OOR_High,US_HSD_ERR_STATE_CONFIRM);
				}
			}
			else
			{
				HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeSet = (HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeSet - HSD_MAIN_BASE_TIME_MS);
			}	
		}
		else
		{
 		   Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_VTG_OOR_HIGH_MASK);
           UssHsd_f_ResetSetCounters_VltgOutOfRangeHigh(ChannelID);
		}					
	}
	else
	{
		if(USS_HSD_PWR_OOR_HIGH < Uss_HsdStateMachine[ChannelID].vVoltage)
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError |= (uint8_t)USS_HSD_VTG_OOR_HIGH_MASK;
			UssHsd_f_ResetSetCounters_VltgOutOfRangeHigh(ChannelID);
			HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdLockSet = ME_TRUE;	
		}
		else
		{
			Uss_HsdStateMachine[ChannelID].eHSDOnError &= (~(uint8_t)USS_HSD_VTG_OOR_HIGH_MASK);
		}
	}
}

/**
 * \brief This functions clears set counters for out of range high
 * 
 * \param ChannelID 
 */
/* ===========================================================================
 * Name: UssHsd_f_ResetSetCounters_VltgOutOfRangeHigh    
 * Remarks:  DD-ID: {F3366D18-B851-4ef2-AE58-9900352C0F8C}
 * ===========================================================================*/
static void UssHsd_f_ResetSetCounters_VltgOutOfRangeHigh(const uint8_t ChannelID)
{
	HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdLockSet = ME_FALSE;	
	HsdDiagErr_VtgOutOfRange_High[ChannelID].RetryCntSet = HSD_ERR_SET_RETRY_CNT_VTG_OOR_HIGH;
	HsdDiagErr_VtgOutOfRange_High[ChannelID].ThresholdDebounceTimeSet = HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_HIGH;
}
#endif/*US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH*/

/********************************* End of file ******************************/
