/*
 * US_MgrSensorProc.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */
#ifndef USSMGR_SRC_US_MGRSENSORPROC_H_
#define USSMGR_SRC_US_MGRSENSORPROC_H_

#include "US_SnrData_Typedefs_Global.h"

#define CLUSTER_REC_BUFF      (3)

void UssMgr_SensorDataProc(void);
void UssMgr_CopyNewSnrDataToBuffer(void);

/* Echo modification */
void UssMgr_DeleteAllEchoesFromCalcRecord(uint8_t uSnrIdx);
void UssMgr_UpdateCalcProperties(uint8_t uSnrIdx, US_E_EchoType_t eNewEchoType, US_E_EchoClass_t eNewEchoClass);
void UssMgr_DeleteEchoFromCalcRecord(uint8_t uSnrIdx, uint8_t uEchoDelIdx);
void UssMgr_InsertFirstEchoIntoCalcRecord(uint8_t uSnrIdx, const US_S_EchoCalc_t * sNewEcho);
void UssMgr_ReplaceCalcRecordsWithEcho(uint8_t uSnrIdx, uint8_t uEchoRepIdx, const US_S_EchoCalc_t * sNewEcho);

#endif /* USSMGR_SRC_US_MGRSENSORPROC_H_ */
