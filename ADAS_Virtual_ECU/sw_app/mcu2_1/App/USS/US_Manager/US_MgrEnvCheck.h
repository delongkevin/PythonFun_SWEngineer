/*
 * US_MgrEnvCheck.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRENVCHECK_H_
#define USSMGR_SRC_US_MGRENVCHECK_H_

#include "US_SnrData_Typedefs_Global.h"

void aUSSMgr_F_TemperatureReceive(void);
void aUSSMgr_F_TempratureCNT(void);
void aUSSMgr_F_TemperatureDeltaGainSet(void);
void aUSSMgr_F_TemperatureReceive(void);
void aUSSMgr_F_Temperature_Init(void);
void aUSSMgr_F_EnvCheckHandler(void);

uint8_t aUSSMgr_F_GroundCheck(void);
uint8_t aUSSMgr_F_TempHumiCheck(void);

void UssMgr_EnvCheckInit(void);
void UssMgr_CheckEnvironmentNoise(void);
const US_S_AllSnrNoiseData_t *UssMgr_GetAllSnrNoiseData(void);
#if(QAC_WARNING_FIX == ME_FALSE)
const US_S_AllSnrNoiseEchoHistory_t * UssMgr_GetAllSnrNoiseHistory(void);
#endif
const US_S_AllSnrChirpTypeHist_t * UssMgr_GetAllSnrChirpTypeHist(void);

//extern pUS_S_AmzDebugBlockageFlag_t MEUssMgr_v_BlockageDebugFlag;

#endif /* USSMGR_SRC_US_MGRENVCHECK_H_ */
