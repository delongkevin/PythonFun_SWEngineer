/*
 * US_MgrDiagnostic.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRDIAGNOSTIC_H_
#define USSMGR_SRC_US_MGRDIAGNOSTIC_H_

void UssMgr_CheckSensorTemperature(void);
void UssMgr_PopulateHardwareDiagnosticsInfo(void);
uint32_t UssMgr_GetSnrFaultBitMap(void);

void UssMgr_DiagnosticInit(void);

#endif /*USSMGR_SRC_US_MGRDIAGNOSTIC_H_ */
