/*
 * US_PlatformCfg_Global.h
 *
 *  Created on: Jul 7, 2021
 *      Author: jonapais
 */
#ifndef SRC_US_INCLUDES_US_PLATFORMCFG_GLOBAL_H_
#define SRC_US_INCLUDES_US_PLATFORMCFG_GLOBAL_H_

#include "US_Data_Typedefs_Global.h"
#define US_D_DATACOLLECTION_PROTOCOL_VER (1u)
#define US_STD_OFF 0
#define US_STD_ON  1

/* to make switching between compile purposes easier */
#define US_D_DEBUG_CAN  (0xAAAA)
#define US_D_DEBUG_LAUD (0xBBBB) /* Assumes CAN debug as well */
#define US_D_RELEASE    (0x1111)
#define US_D_CUR_SW_PURPOSE	(US_D_DEBUG_CAN)
#define US_D_CUR_PLATFORM   (US_D_PLATFORM_CVADAS)
#define QAC_WARNING_FIX  ME_TRUE
/*CAN output platform selection: this is temporary & can be set with calibration type*/
//#define US_D_CUR_CAN_PLATFORM  (US_D_CAN_PLATFORM_CVADAS)  // (US_D_CAN_PLATFORM_CVADAS | US_D_CAN_PLATFORM_AMAZON | US_D_CAN_PLATFORM_RIVIAN)

#if (US_D_CUR_SW_PURPOSE == US_D_DEBUG_LAUD)
    #define US_D_LAUTERBACH_DEBUG_VARS  (ME_TRUE)
    /* Extra debug by taking over unused 2D point CAN FD messages (_# thru _11) */
    #define US_D_ENABLE_OVRWR_CANDBG    (ME_TRUE)
    #define US_D_ENABLE_EXT_ODOM_DEBUG  (ME_TRUE)
    #define US_D_GATHER_RUNTIME_STATS   (ME_TRUE)
#endif
#if (US_D_CUR_SW_PURPOSE == US_D_DEBUG_CAN)
    /* Extra debug by taking over unused 2D point CAN FD messages (_# thru _11) */
    #define US_D_ENABLE_OVRWR_CANDBG    (ME_TRUE)
    #define US_D_ENABLE_EXT_ODOM_DEBUG  (ME_TRUE)
    #define US_D_GATHER_RUNTIME_STATS   (ME_TRUE)
#endif

#define US_D_CUR_CAN_PLATFORM   (0u)

#define US_D_ENABLE_DYNCALADJ
#ifdef US_D_ENABLE_DYNCALADJ
    #define US_D_ENABLE_SNR_TEMPERATURE_INTERP      (ME_TRUE)
    #define US_D_ENABLE_FAPA_DYN_STG                (ME_FALSE)
    #define US_D_ENABLE_PBUTTON_PROFC_ADJUST        (ME_TRUE)
    #define US_D_ENABLE_DNN_PROFC_ALL_ADJUST        (ME_TRUE)
#endif

#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
    #define US_D_USE_EXTERNAL_ODOMETRY  (ME_FALSE)
#else
    #define US_D_USE_EXTERNAL_ODOMETRY  (ME_TRUE)
    #define US_D_ENABLE_EXT_ODOM_DEBUG  (ME_TRUE)
#endif


#if (US_D_LAUTERBACH_DEBUG_VARS == ME_TRUE)
    #define US_D_LAUD_QUAL  volatile
    #define US_D_DYNCAL_DEBUG_VARS (ME_FALSE) /* Uses ~3kb RAM only enable if needed (or possible in PAMs case) */
#else
    /* if not using lauterbach for debug, change variables to const to save RAM */
    #define US_D_LAUD_QUAL  const
#endif /* US_D_LAUTERBACH_DEBUG_VARS being ME_TRUE */




#if (US_D_ENABLE_OVRWR_CANDBG == ME_TRUE)
    #define US_D_DBG_QUAL
#else
    #define US_D_DBG_QUAL   static  /* Used for normal global variables that get externed for debug*/
#endif /* US_D_ENABLE_OVRWR_CANDBG */

//#define UART_SUPPORTED      (0u)


#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)||(US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN))
#define US_D_DATA_SHARE_CALLBACKS_ENABLE
#endif 

#define US_D_SIMULATION_ACTIVE  ME_FALSE

#define BLOCKAGE_DEBUG  ME_TRUE
/* RAEB Height issues settings START */
#define US_D_USE_HEIGHT_ESTIMATION  /* Global enable/disable. If disabled everything is sent as "high" */
#ifdef US_D_USE_HEIGHT_ESTIMATION
    /* enable to use geometry stats for height estimation: (comment out to disable) */
    #define US_D_OD_HEIGHT_GEOM_STATS
    #ifdef US_D_OD_HEIGHT_GEOM_STATS
        #define US_D_OD_HGEOM_COMPUTE_SIGMA  /* Code for "pole extractor" */
        #define US_D_OD_HGEOM_COMPUTE_GRPHEIGHT  /* Code for bumper height flag */
        #if ( (US_D_LAUTERBACH_DEBUG_VARS == ME_TRUE) || (US_D_ENABLE_OVRWR_CANDBG == ME_TRUE) )
            #define US_D_OD_HEIGHT_GEOM_DEBUG   (ME_TRUE)
        #else
            #define US_D_OD_HEIGHT_GEOM_DEBUG   (ME_FALSE)
        #endif
        #if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE)
            #define US_D_OD_HGEOM_USE_DBG_FUNCS     (ME_FALSE)
        #endif
        /* values for height filter levels: */
        #define US_D_OD_HEIGHT_GEOM_DO_REAR_ONLY    (ME_FALSE)
    #endif
#endif /* US_D_USE_HEIGHT_ESTIMATION */

/* Using echo based wall high flag outside just mgr filter */
#define US_D_LAUTERBACH_DEBUG_VARS  ME_FALSE
//#define US_D_MGR_WALL_HIGH_FLAGS
#ifdef US_D_MGR_WALL_HIGH_FLAGS
    /* settings */
    #define US_D_MWH_USE_INNER_ONLY         (ME_FALSE)
    #define US_D_MWH_NEEDED_HIGH_SENSORS    (1)
    #define US_D_MWH_AUTO_HIGH_DIST         (0) /* Zero to disable */
    #define US_D_MWH_PERSIST_FLAG           (ME_TRUE)
    #define US_D_MWH_REQ_OCC                (ME_TRUE)
        #if (US_D_MWH_REQ_OCC == ME_TRUE)
            #define US_D_MWH_OCC_MISSED_ALLOWED     (4u)
            #define US_D_MWH_OCC_VALUE_NEEDED       (1u)
            #define US_D_MWH_OCC_DEFAULT_DECRATE    (2u)
            #define US_D_MWH_OCC_MAX_VAL            (10u)
            //#define US_D_MWH_OCC_LOW_DECRATE        (2u)
            //#define US_D_MWH_OCC_HIGH_DECRATE       (10u)
        #endif
#endif /* US_D_MGR_WALL_HIGH_FLAGS */

//#define US_D_USE_SLOW_CONF_APP_3   /* SCA3 */
#ifdef US_D_USE_SLOW_CONF_APP_3
    #define US_D_OD_SCA3_USE_MIDSPD_ADAP_REDUC
    #define US_D_OD_SCA3_USE_ADAP_BOOST
#endif
/* RAEB Height issues settings END */

#define US_D_MGR_BLOCKAGE_ENABLE_HAILMARY   (ME_OFF)


#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
    #define US_D_MAX_NUM_SENSORS  (16u)
    #define US_D_MAX_NUM_BUS      (4u)
#else
    #define US_D_MAX_NUM_SENSORS  (12u)
    #define US_D_MAX_NUM_BUS      (2u)
#endif

#define US_D_ALL_SNR_BITMAP  (((uint32_t)BIT0 << US_D_MAX_NUM_SENSORS) - ONE)
/*
 * Physical sensor groups.
 */
 typedef enum UssHsd_E_ChannelID_e
{
    Uss_Hsd_Channel_PWR_A = 0,
    Uss_Hsd_Channel_PWR_B,
    Uss_Hsd_Channel_Max
}UssHsd_E_ChannelID_t;

#define US_MAX_NUM_SENSORS_PER_GRP  (6u)

#define US_D_PHYS_GRP_FRNT          (0u)
#define US_D_PHYS_GRP_REAR          (1u)
#define US_D_PHYS_GRP_LEFT_SIDE     (2u)
#define US_D_PHYS_GRP_RIGHT_SIDE    (3u)

#define US_D_PHYS_GRP_DBG_SPLIT     (0xFFu)

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN

#define US_D_PHYS_GRP_MAX           (4u)

#else

#define US_D_PHYS_GRP_MAX           (2u)

#endif

//enable for debugging objects:
//#define DEBUG_VISUAL_TOOL_WITH_USS_LOG_MSGS //use the DEBUG LOG MESSAGES to output the object info

//#if(US_D_CUR_CAN_PLATFORM != 0)
    //#define     US_D_CAN_ENABLE  //not used anymore?
    #define     DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE
    #define     DEBUG_VISUAL_GRP_CHOICE     (US_D_PHYS_GRP_DBG_SPLIT)
    //#define DEBUG_VISUAL_TOOL_OBJECT_MODE //use the visual tool's debug messages for objects 
    //#define PLAYBACK_SW_ENABLE
//#endif

#ifdef PLAYBACK_SW_ENABLE
	 #define 	US_D_CAN_OUTPUT_ENABLE
#endif
/* Extra debug by taking over 4 unused 2D point CAN FD messages (_8 thru _11) */
#define US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X


#define US_D_FAULT_DEBOUNCE_BY_TIME  (ME_FALSE)
/*
 * Names to lookup sensor address info.
 * Note: This is not the index to the actual sensor data, as received from driver.
 *       Use UssCtrl_pauGetSnrIdxList() to translate to app layer index.
 *       They may or may not match, depending on current calibration!!!
 *       These application layer indices are fixed to simply application layer.
 *       Sensor indices are translated to these indices when it is processed from SPI data.
 */
/* Front Sensors */
#define US_D_SENSOR_FSR  ( 0u)
#define US_D_SENSOR_FOR  ( 1u)
#define US_D_SENSOR_FIR  ( 2u)
#define US_D_SENSOR_FIL  ( 3u)
#define US_D_SENSOR_FOL  ( 4u)
#define US_D_SENSOR_FSL  ( 5u)

/* Rear Sensors */
#define US_D_SENSOR_RSR  ( 6u)
#define US_D_SENSOR_ROR  ( 7u)
#define US_D_SENSOR_RIR  ( 8u)
#define US_D_SENSOR_RIL  ( 9u)
#define US_D_SENSOR_ROL  (10u)
#define US_D_SENSOR_RSL  (11u)

/* Side PSM Sensors */
#define US_D_SENSOR_AOL  (12u)
#define US_D_SENSOR_BOL  (13u)
#define US_D_SENSOR_AOR  (14u)
#define US_D_SENSOR_BOR  (15u)

typedef struct US_S_SnrPhysGrp_s
{
    uint8_t   uNumSnrsInGrp;
    uint8_t   uSnrDataIdx[US_MAX_NUM_SENSORS_PER_GRP];
    uint32_t  uGrpDrvAddrBitMap;
    uint16_t  uGrpSnrIdxBitMap;
} US_S_SnrPhysGrp_t;

typedef struct US_S_PlatPhysInfo_s
{
    uint8_t  uNumCalSnrs;
    uint8_t  uNumActSnrs;
    uint32_t uInstSnrAppIdxBitMask;
    uint32_t uInstSnrDvrAddrMask;
    US_S_SnrPhysGrp_t psSnrPhysGrp[US_D_PHYS_GRP_MAX];
} US_S_PlatPhysInfo_t;

void UssCtrl_PopulatePhysTopologyInfo(void);
void UssCtrl_PerformSnrMarIdxMapping(void);
void UssCtrl_PerformSnrMarWriteChk(void);
US_S_PlatPhysInfo_t * UssCtrl_psGetPlatPhysInfo(void);
uint8_t * UssCtrl_psGetSensorType(void);
uint32_t * UssCtrl_pauGetSnrAddrList(void);
uint8_t  * UssCtrl_pauGetSnrIdxList(void);
uint8_t  * UssCtrl_pauGetSnrCfgIdxList(void);
uint8_t  * UssCtrl_pauGetSnrBusList(void);
uint8_t UssCtrl_GetGroupIdxFromSensorIdx(uint8_t uAppSnrIdx);

#endif /* SRC_US_INCLUDES_US_PLATFORMCFG_GLOBAL_H_ */
