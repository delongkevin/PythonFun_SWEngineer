/*
 * US_MgrUtility.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRUTILITY_H_
#define USSMGR_SRC_US_MGRUTILITY_H_

#include "US_SnrData_Typedefs_Global.h"

#define US_D_MGRUTIL_DEFAULT_VEHMOVING      (ME_TRUE)

void UssMgr_Util_UpdateInputs(void);


uint32_t aUSSMgr_Rand(uint32_t MaxVal);
bool_t CheckConf(uint8_t conf, uint16_t echo);
bool_t CheckHeight(uint16_t height, uint16_t echo);
bool_t UssMgr_IsSensSide(uint8_t Sensor_Index);

#endif /* USSMGR_SRC_US_MGRUTILITY_H_ */
