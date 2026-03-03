/*
 * US_MgrBlockage.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_SRC_US_MGRBLOCKAGE_H_
#define USSMGR_SRC_US_MGRBLOCKAGE_H_

#include "US_Data_Typedefs_Global.h"
#include "US_Platform_Global.h"

#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
    #define US_D_MGR_BHM_FULL_TIME_NFD  (ME_OFF) /* Try to ref ModeControl.h settings */

    typedef struct US_Mgr_HailBlockData_s
    {
        uint8_t uNormalDistRAvg_10cm;
        uint8_t uNormalDistRAvgMax_10cm;
        uint8_t uNormalDistRAvgMin_10cm;
    #if (US_D_MGR_BHM_FULL_TIME_NFD == ME_ON)
        uint8_t uNormalRingMax_20us;
        uint8_t uNFDRingCur_20us;
        uint8_t uNFDDistCur_10cm;
    #else
        uint8_t uSamplesTaken;
    #endif
    } US_Mgr_HailBlockData_t;
    
    #define US_D_MGR_BHM_ENABLE_SPEED   2.0f
    #define US_D_MGR_BHM_CONF_MAX       50u
    #define US_D_MGR_BHM_CONF_INIT      5u
    #define US_D_MGR_BHM_NORM_MIN_SAMPLES       3u      //number of starting samples needed
    #define US_D_MGR_BHM_NORM_RESET_SAMPLES     12u
    #define US_D_MGR_BHM_BAD_NORM_RING_20us     90u     //1800 in 1us
    #define US_D_MGR_BHM_CLOSE_NORM_RANGE_10cm  9u     //90cm in 1cm
    #define US_D_MGR_BHM_AVG_FLUX_10cm          3u      //30cm between min/max of avg
    #define US_D_MGR_BHM_BAD_NFD_RING_20us      65u     /* 1300 in 1us */
#endif /* US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON */

uint16_t aUSSMgr_F_BlockageCheck(uint8_t loc_ground);
void UssMgr_CheckBlockage(void);
void UssMgr_BlockageInit(void);
#if BLOCKAGE_NN
void USSMgr_BlockageEstimationNN(void);
void USSMgr_InitBlockageEstimationNN(void);
#endif


#endif /* USSMGR_SRC_US_MGRBLOCKAGE_H_ */
