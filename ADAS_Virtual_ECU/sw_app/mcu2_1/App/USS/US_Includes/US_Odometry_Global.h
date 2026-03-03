/*
 * US_Odometry_Global.h
 *
 *  Created on: Jun 8, 2022
 *      Author: jonapais
 */

#ifndef MAGNA_US_INCLUDES_US_ODOMETRY_GLOBAL_H_
#define MAGNA_US_INCLUDES_US_ODOMETRY_GLOBAL_H_

#include "US_ME_Typedefs_Global.h"

typedef struct UssOdo_OdometryData_s
{
    float32_t X_MABx;
    float32_t Y_MABx;
    float32_t heading_MABx;
    float32_t rearAxleSpeed;
    float32_t xVelocity;
    float32_t yVelocity;
    float32_t dAngle;
    uint32_t timestamp;
} UssOdo_OdometryData_t;

typedef struct UssOdo_OdoAccumOutput_s
{
    float32_t fXdelta;
    float32_t fYdelta;
    float32_t fAngleDelta;
	float32_t fTimestamp_s;
} UssOdo_OdoAccumOutput_t;

extern void UssOdo_PerformNextOdometryStep(void);
extern void UssOdo_OdometryInit(void);
extern UssOdo_OdoAccumOutput_t * UssOdo_psGetOdoAccumOut(void);
extern void UssOdo_ClearAccumulators(void);

#if (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
typedef struct UssOdo_DebugOutput_s
{
    float32_t fGlobalX;
    float32_t fGlobalY;
    float32_t fAngleCur;
    float32_t fAccuX;
    float32_t fAccuY;
    float32_t fAngleAvg;
} UssOdo_DebugOutput_t;

UssOdo_DebugOutput_t* UssOdo_psGetOdoDebug(void);
#endif /*(US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)*/

#endif /* MAGNA_US_INCLUDES_US_ODOMETRY_GLOBAL_H_ */
