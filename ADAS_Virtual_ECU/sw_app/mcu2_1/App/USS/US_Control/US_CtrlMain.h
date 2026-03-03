/*
 * US_CtrlMain.h
 *
 *  Created on: Mar 3, 2021
 *      Author: jonapais
 */

#ifndef US_CTRLMAIN_H_
#define US_CTRLMAIN_H_

#include "US_ME_Typedefs_Global.h"

typedef enum UssCtrl_eMainState
{
    USSCTRL_FSM_IDLE,
    USSCTRL_FSM_DATA_PLAYBACK,
    USSCTRL_FSM_SEND_BURST,
    USSCTRL_FSM_CHECK_SNR_RETURN,
    USSCTRL_FSM_SNR_ERROR,
	USSCTRL_FSM_CAL_SNRS
} UssCtrl_eMainState_t;


bool_t UssCtrl_SnrCfg_GetDoneStatus(void);
bool_t UssCtrl_SnrCalAdj_GetDoneStatus(void);
void UssCtrl_SnrCalAdj_Start(void);
void UssCtrl_SnrConfigure_Start(void);
void UssCtrl_CfgSensor_Task(void);
void UssCtrl_SnrCalAdj_Task(void);

#endif /* US_CTRLMAIN_H_ */
