/*
 * US_MgrModeControl.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRMODECONTROL_H_
#define USSMGR_SRC_US_MGRMODECONTROL_H_


//#define USSMGR_GLOBAL_NFD_DISABLE
//#define USSMGR_GLOBAL_CHIRP_DISABLE
#define USSMGR_MODE_HACKED_SCAN_MODES
#ifdef USSMGR_MODE_HACKED_SCAN_MODES
    #define USSMGR_MODE_HSM_MODE_UNKNOWN    0x00
    #define USSMGR_MODE_HSM_MODE_SIDEONLY   0x01
    #define USSMGR_MODE_HSM_MODE_MIXMODE    0x02
    #define USSMGR_MODE_HSM_GEAR_BASED  (ME_TRUE)
    #define USSMGR_MODE_HSM_SPEED_BASED (ME_TRUE)
    #if (USSMGR_MODE_HSM_SPEED_BASED == ME_TRUE)
        #define USSMGR_MODE_HSM_SPD_DN_LIMIT    12.5f
        #define USSMGR_MODE_HSM_SPD_UP_LIMIT    13.5f
    #endif
#endif

#define USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE
#ifdef USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE
    #define USSMGR_MODE_NSL_SPEED_EXIT    2.5f
    #define USSMGR_MODE_NSL_SPEED_ENTER    2.0f
#endif

typedef enum
{
    FIREMODE_DEFAULT = ZERO,
    FIREMODE_NORMAL,
    FIREMODE_PSM_ONLY,
    FIREMODE_SIDES_ONLY,
    FIREMODE_SPECIAL,
    FIREMODE_SPECIAL_2,
    FIREMODE_OFF,
    FIREMODE_MAX    
} US_E_FireMode_t;


void UssMgr_ModeControlInit(void);

/* Functionality runtime options */
Std_ReturnType UssMgr_ModeControl_NFDOption(bool_t Enabled);

#endif /* USSMGR_SRC_US_MGRMODECONTROL_H_ */
