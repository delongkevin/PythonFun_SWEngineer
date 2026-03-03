/*
 * US_MgrFilter.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRFILTER_H_
#define USSMGR_SRC_US_MGRFILTER_H_

#define aUSS_D_FDrv                     (49200) /*HZ B2*/  /*(48900)*/ /*HZ B1*/
#define aUSS_D_DistBurstNumCali         (1000000/aUSS_D_FDrv) /*us, one burst*/

uint8_t aUSSMgr_F_NarrowCheck(uint8_t is_narrow);

extern uint16_t aUSS_v_Far_DistBurstNumCali;

void UssMgr_InitDistBurstCali(void);

void UssMgr_CheckMeasurementRange(void);
void UssMgr_FilterGainAndCutoff(void);
void UssMgr_HandleMultipleEchoes(void);
void UssMgr_ClassifyMeasurementType(void);
void UssMgr_CalcSignalStrength(void);
void UssMgr_AddAndAdjustEchoes(void);

void UssMgr_FilterInit(void);

#endif /* USSMGR_SRC_US_MGRFILTER_H_ */
