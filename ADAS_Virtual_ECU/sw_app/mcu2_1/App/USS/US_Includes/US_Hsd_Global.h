/*
 * US_Hsd_Global.h
 *
 */

#ifndef US_HSD_GLOBAL_H_
#define US_HSD_GLOBAL_H_

#include "US_ME_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "VoltageCurrent_data.h"

typedef struct UssHsd_S_Diagnostics_Flags_s
{
    bool_t Uss_Hsd_Pwr_Open_Circuit_Failure;
    bool_t Uss_Hsd_Pwr_Short_To_Battery;
    bool_t Uss_Hsd_Pwr_Short_To_Ground;
    bool_t Uss_Hsd_Pwr_Voltage_Out_Of_Range;
}UssHsd_S_Diagnostics_Flags_t;

typedef enum UssHsd_State_e
{
    Uss_Hsd_State_Init = 0,
    Uss_Hsd_State_OutputOnOff,
    Uss_Hsd_State_OutputOnCheck,
    Uss_Hsd_State_OutputOffCheck,
    Uss_Hsd_State_OutputOn,
    Uss_Hsd_State_OutputOff,
	Uss_Hsd_State_Multiple_Fault_Check,
    Uss_Hsd_State_Fault,
    Uss_Hsd_State_Fault_Recovery,
    Uss_Hsd_State_Max
}UssHsd_E_State_t;

typedef enum UssHsd_E_SetOnOffRequest_e
{
    SetOnOffRequest_OFF = 0,
    SetOnOffRequest_ON,
	SetOnOffRequest_NONE

}UssHsd_E_SetOnOffRequest_t;

typedef enum UssHsd_E_SetOnOffStatus_e
{
    SetOnOffStatus_OFF = 0,
    SetOnOffStatus_ON
}UssHsd_E_SetOnOffStatus_t;

typedef void (*fPtrHsdGpioWriteCbk_Type)(uint8_t pinVal);

/************************************************************************************************************************
* HSD stae machine struct
************************************************************************************************************************/
typedef struct USS_HSD_S_State_Machine_s
{
    UssHsd_E_ChannelID_t eChannelID;
    UssHsd_E_State_t eHSDState;
    UssHsd_E_State_t eHSDPrvState;
    uint8_t eHSDOnConfirmError;
    uint8_t eHSDOffConfirmError;
    uint8_t eHSDOnError;
    uint8_t eHSDOffError;
    UssHsd_E_SetOnOffStatus_t eHSDStatus;
    UssHsd_E_SetOnOffRequest_t eHSDOnOffReq;
    fPtrHsdGpioWriteCbk_Type fPtrHsdGpioWriteCbk;
	uint8_t eHSDOnPrevError;
	uint8_t eHSDOffPrevError;
    uint16_t vVoltage;
    uint16_t vCurrent;
    uint8_t UssHsd_OutputOnTimer;
    uint8_t UssHsd_OutputOffTimer;
    uint8_t UssHsd_OutputOnFaultTimer;
    uint8_t UssHsd_OutputOffFaultTimer;
    uint8_t UssHsd_OutputOnFaultRecoveryTimer;
    uint8_t UssHsd_OutputOffFaultRecoveryTimer;
    UssHsd_S_Diagnostics_Flags_t HSD_Diagnostics_Flags;
}USS_HSD_S_State_Machine_t;

extern USS_HSD_S_State_Machine_t Uss_HsdStateMachine[Uss_Hsd_Channel_Max];


extern void UssHsd_F_ReadADCValue(uint8_t ChannelID);

extern void UssHsd_F_ADC_RawValueConversion(uint8_t Channel_Id);
extern uint16_t UssHsd_F_psGet_Pwr_Vtg_mV(const uint8_t ChannelID);
extern uint16_t UssHsd_F_psGet_Pwr_Ct_mA(const uint8_t ChannelID);
extern UssHsd_S_Diagnostics_Flags_t UssHsd_F_psGet_Diagnostics_Flags(const uint8_t ChannelID);
extern void UssHsd_F_StateMachine(void);
extern UssHsd_E_SetOnOffStatus_t CDD_HSD_F_GetOnOffStatus(UssHsd_E_ChannelID_t ChannelID);
extern uint32_t CDD_HSD_GetOnOffStatus(UssHsd_E_ChannelID_t ChannelID);
extern void HsdGpIoWriteCbk_ChannelA(const uint8_t pinVal);
extern void HsdGpIoWriteCbk_ChannelB(const uint8_t pinVal);
extern void UssHsd_F_CopyVoltageMonitorValueFromIPC(const USS_Curr_Volt_Monitor_t * const sUSS_Curr_Volt_Monitor_l );
uint8_t UssHsd_F_CheckOnStatus(void);

#endif /*US_HSD_GLOBAL_H_ */
