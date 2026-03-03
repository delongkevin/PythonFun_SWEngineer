/*
 * US_CtrlEnvCheckFsm.h
 *
 *  Created on: Mar 11, 2021
 *      Author: jonapais
 */

#ifndef USSCTRL_SRC_US_CTRLENVCHECKFSM_H_
#define USSCTRL_SRC_US_CTRLENVCHECKFSM_H_

/*comment out extern pUS_E_USSCtrl_CheckEnvStage_t eUssCtrl_CheckEnvStage;*/
/*comment out extern pUS_E_ENVType_Mod_t aJobUSSCtrl_ENVMode;*/
/*comment out extern pUS_E_ChkBlock_Mod_t aJobUSSMgr_ChkBlock;*/

void UssCtrl_EnvCheckingFsm(void);
void UssCtrl_UpdateSnrIntTemperature(void);

/* Rate at which to update sensor temperature.  30 sec in ms.*/
#define US_D_SNR_TEMP_UPDATE_INTERVAL ((uint32_t) (30u * 1000u))

#endif /* USSCTRL_SRC_US_CTRLENVCHECKFSM_H_ */
