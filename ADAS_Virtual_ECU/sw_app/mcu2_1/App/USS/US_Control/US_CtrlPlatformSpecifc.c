/*
 * US_CtrlPlatformSpecifc.c
 *
 *  Created on: Mar 10, 2021
 *      Author: jonapais
 */

#include "US_CtrlMain.h"
#include "US_CtrlEnvCheckFsm.h"
#include "US_Ctrl_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_ObjDet_Global.h"
#include "US_SysMgr_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_Platform_Global.h"
#include "US_SnrCfg_Global.h"

#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)||((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM)||(US_D_CUR_PLATFORM == US_D_PLATFORM_AMAZON))
 #include "US_Interface_Output.h" 

#elif US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
    #include "Siul2_Port_Ip.h"
    #include "Siul2_Dio_Ip.h"
    #include "Application_header.h"
#endif

#define US_D_EEPROM_STORAGE_EXISTS (ME_TRUE)

/*
 * Physical sensor topology interface between driver and application.
 */
static US_S_PlatPhysInfo_t sPlatPhysInfo;
static uint32_t auSnrAddrList[US_D_MAX_NUM_SENSORS];
static uint8_t  auSnrIdxList[US_D_MAX_NUM_SENSORS];
static uint8_t  auSnrCfgIdxList[US_D_MAX_NUM_SENSORS];
static uint8_t  auSnrBusList[US_D_MAX_NUM_SENSORS];
static uint8_t  auSnrTypeList[US_D_MAX_NUM_SENSORS];

static uint32_t uMarriageStatApiBits = ZERO;
static uint8_t uMarriageStatBits = ZERO;

static uint8_t UssCtrl_uCalcSnrBusFromSnrMap(uint32_t uDvrSnrBitMap);
static uint8_t UssCtrl_uCalcSnrIdxFromSnrMap(uint32_t uDrvSnrBitMap, uint32_t uAllSnrBitMap);
static void UssCtrl_PopulateSnrInfoArrays(uint8_t uSnrAppIdx, uint16_t uSnrLoc);
static uint32_t UssCtrl_uCalcGroupDrvBitmap(uint8_t uGrpIdx);
static uint16_t UssCtrl_uCalcGroupSnrIdxBitmap(uint8_t uGrpIdx);
extern uint16_t NVMRead_SensorMarriage(US_S_MarriageSensorIDs_t *data);
extern uint16_t NVMWrite_SensorMarriage(US_S_MarriageSensorIDs_t *data);

#if US_D_EEPROM_STORAGE_EXISTS == ME_FALSE
static void UssCrtl_MoveSnrsToDsiEndOfBus(uint8_t uStartDrvSnrIdx,
                                          uint8_t uNumBusIndexes,
                                          uint8_t uNumMissingSnrs,
                                          uint32_t * puSnrIDList,
                                          uint32_t * puCopySnrIDList,
                                          uint32_t * puCopySnrAddrList);
#else
static void UssCrtl_RemapSensorPostions(uint8_t uStartSnrDvrIdx,
                                        uint8_t uNumBusIndexes,
                                        uint8_t uNumMissingSnrs,
                                        uint32_t const* puSnrIDList,
                                        uint32_t * puCopySnrIDList,
                                        uint32_t * puCopySnrAddrList,
                                        uint32_t const* puNvmIDList);
#endif

static volatile bool_t bSnrMarriageRequested = ME_FALSE;
static uint32_t uSnrMarriageMap = ZERO;
static uint8_t uUninstSnrDrvIdx;

/*
 * Must be called after auto addressing is complete by Dvr.
 * Topology specific.  Will change based on calibration.
 * Used to speed up lookup of index and map values for single sensors.
 * Called once after Dvr is initialized by Controller Main.
 */
/*===========================================================================
 * \brief Calculate sensor physical topology for quick lookup.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Only performed at (re)initialization.
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_PopulatePhysTopologyInfo
 * Remarks:  DD-ID: {DB9E29D5-5CC4-4405-9BC3-FF70EEB9EA91}
 * ===========================================================================*/
 
void UssCtrl_PopulatePhysTopologyInfo(void)
{
    US_S_SensorsCfg_t const *pSnrCfg = US_SnrCfg_F_Get_SnrCfg();

    sPlatPhysInfo.uNumCalSnrs = ZERO;
    sPlatPhysInfo.uNumActSnrs = ZERO;

    /*Count sensors on this platform */
    (void)US_SnrDrvCom_F_CountSnr(TEN, NULL, &sPlatPhysInfo.uNumCalSnrs, pSnrCfg->SnrMap, ZERO);   /*isActual = ZERO, from calibration */
    (void)US_SnrDrvCom_F_CountSnr(TEN, NULL, &sPlatPhysInfo.uNumActSnrs, (uint32_t) US_D_ALL_SNR_BITMAP, ONE);  /*isActual = ONE, installed at config (auto addressing) */  

    sPlatPhysInfo.uInstSnrDvrAddrMask = US_SnrCfg_F_Get_CfgSnrMap(US_ALL_POS); /*Record all installed sensors as Driver Address Map for easy lookup. */
    sPlatPhysInfo.uInstSnrAppIdxBitMask = ZERO; /*Reset application layer bit mask.  Will be built by calls to UssCtrl_PopulateSnrInfoArrays. */

    /*
     * \TODO FuSA - if (sPlatPhysInfo.uNumCalSnrs != expectation)  handle issue -- somehow?
     *
     * Verify correct cal config:
     *
     * if ((sPlatPhysInfo.uNumCalSnrs >= US_D_MAX_NUM_SENSORS) ||     array size
     *    (sPlatPhysInfo.uNumActSnrs > sPlatPhysInfo.uNumCalSnrs))    knowledge about sensor config
     * {
     *     Throw error that cal doesn't match platform!
     * }
     */

    /*
     * Setup for UssCtrl_PopulateSnrInfoArrays():
     * Point to first position after config array, unused positions, for non-installed sensor mapping.
     */
    uUninstSnrDrvIdx = sPlatPhysInfo.uNumCalSnrs;

    /* Connect enumerations with physical locations on bus via driver calls
     * Functional Description:  UssCtrl_PopulateSnrInfoArrays(Application_Index, Sensor_Name_Bitmap_Lookup)
     *
     * Application_Index should remain as canon, and Sensor_Name_Bitmap_Lookup is abstracted by driver!
     *
     */
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_RSR, (US_REAR_POS  |  US_SIDE_POS  | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_ROR, (US_REAR_POS  |  US_OUTER_POS | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_RIL, (US_REAR_POS  |  US_INNER_POS | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_RIR, (US_REAR_POS  |  US_INNER_POS | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_ROL, (US_REAR_POS  |  US_OUTER_POS | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_RSL, (US_REAR_POS  |  US_SIDE_POS  | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_FSR, (US_FRONT_POS |  US_SIDE_POS  | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_FOR, (US_FRONT_POS |  US_OUTER_POS | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_FIR, (US_FRONT_POS |  US_INNER_POS | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_FIL, (US_FRONT_POS |  US_INNER_POS | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_FOL, (US_FRONT_POS |  US_OUTER_POS | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_FSL, (US_FRONT_POS |  US_SIDE_POS  | US_LEFT_POS ));

    /* Rivian has 4 side panel sensors */
#if ((US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN) && (US_D_MAX_NUM_SENSORS > TWELVE) && (US_D_MAX_NUM_SENSORS <= SIXTEEN))
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_AOL, (US_A_POS     |  US_OUTER_POS | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_BOL, (US_B_POS     |  US_OUTER_POS | US_LEFT_POS ));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_AOR, (US_A_POS     |  US_OUTER_POS | US_RIGHT_POS));
    UssCtrl_PopulateSnrInfoArrays(US_D_SENSOR_BOR, (US_B_POS     |  US_OUTER_POS | US_RIGHT_POS));
#endif

    /* Preserve copy of original index list mapping for diagnostics function. */
   (void) memcpy(auSnrCfgIdxList, auSnrIdxList, US_D_MAX_NUM_SENSORS * sizeof(uint8_t));   /*PRQA S 1291 */

    /*Build reverse lookup such that:  uAppSnrIdx = uSnrAddrIdxList[uDvrSnrIdx] */
    UssSnrCmd_PopulateSnrAddrIdxList();

    /*
     * Physical topology of sensors for Triangulation and looping.
     * ** IMPORTANT : Define physical groups from left to right, if one was facing in the direction
     *                of that side of the vehicle, which defines the rotation basis of
     *                the coordinate system!!!!
     *                Basically, we want to be able to traverse around the vehicle in a
     *                clockwise direction, when considering all sensors, or a group of sensors,
     *                to keep a logical, consistent, pattern.
     *
     *                Clear all groups, first, in case of re-init.
     */
    (void)memset(&sPlatPhysInfo.psSnrPhysGrp[ZERO], 0, sizeof(US_S_SnrPhysGrp_t) * US_D_PHYS_GRP_MAX);

    /*
     * FRONT GROUP CONFIGURATION
     */
    if (sPlatPhysInfo.uNumCalSnrs > SIX)  /*Dynamic physical platform selection */
    {
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uNumSnrsInGrp = 6u;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uSnrDataIdx[0u] = US_D_SENSOR_FSL;  /*If Facing front: Leftmost Sensor!!! */
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uSnrDataIdx[1u] = US_D_SENSOR_FOL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uSnrDataIdx[2u] = US_D_SENSOR_FIL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uSnrDataIdx[3u] = US_D_SENSOR_FIR;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uSnrDataIdx[4u] = US_D_SENSOR_FOR;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uSnrDataIdx[5u] = US_D_SENSOR_FSR;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uGrpSnrIdxBitMap = UssCtrl_uCalcGroupSnrIdxBitmap((uint8_t)US_D_PHYS_GRP_FRNT);
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uGrpDrvAddrBitMap = UssCtrl_uCalcGroupDrvBitmap((uint8_t)US_D_PHYS_GRP_FRNT);
    }
    else  /*If there are 6 or less sensors then shut down the front group. */
    {
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uNumSnrsInGrp = ZERO;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uGrpSnrIdxBitMap = ZERO;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_FRNT].uGrpDrvAddrBitMap = ZERO;
    }

    /*
     * REAR GROUP CONFIGURATION
     */

    if (   (sPlatPhysInfo.uNumCalSnrs >= TWELVE)
        || (sPlatPhysInfo.uNumCalSnrs == SIX)) /*Dynamic physical platform selection */
    {
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uNumSnrsInGrp = 6u;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[0u] = US_D_SENSOR_RSR;  /*If Facing Rear: Leftmost Sensor!!! */
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[1u] = US_D_SENSOR_ROR;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[2u] = US_D_SENSOR_RIR;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[3u] = US_D_SENSOR_RIL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[4u] = US_D_SENSOR_ROL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[5u] = US_D_SENSOR_RSL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uGrpSnrIdxBitMap = UssCtrl_uCalcGroupSnrIdxBitmap((uint8_t)US_D_PHYS_GRP_REAR);
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uGrpDrvAddrBitMap = UssCtrl_uCalcGroupDrvBitmap((uint8_t)US_D_PHYS_GRP_REAR);
    }
    else /*sPlatPhysInfo.uNumCalSnrs == 10 or 4, presumably. */
    {
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uNumSnrsInGrp = 4u;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[0u] = US_D_SENSOR_ROR;  /*If Facing Rear: Leftmost Sensor!!! */
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[1u] = US_D_SENSOR_RIR;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[2u] = US_D_SENSOR_RIL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uSnrDataIdx[3u] = US_D_SENSOR_ROL;
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uGrpSnrIdxBitMap = UssCtrl_uCalcGroupSnrIdxBitmap((uint8_t)US_D_PHYS_GRP_REAR);
        sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_REAR].uGrpDrvAddrBitMap = UssCtrl_uCalcGroupDrvBitmap((uint8_t)US_D_PHYS_GRP_REAR);
    }

#if ((US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN) && (US_D_MAX_NUM_SENSORS > TWELVE) && (US_D_MAX_NUM_SENSORS <= SIXTEEN))
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_LEFT_SIDE].uNumSnrsInGrp = 2u;
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_LEFT_SIDE].uSnrDataIdx[0u] = US_D_SENSOR_BOL;  /*If facing Left: Leftmost Sensor!!! */
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_LEFT_SIDE].uSnrDataIdx[1u] = US_D_SENSOR_AOL;
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_LEFT_SIDE].uGrpSnrIdxBitMap = UssCtrl_uCalcGroupSnrIdxBitmap((uint8_t)US_D_PHYS_GRP_LEFT_SIDE);
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_LEFT_SIDE].uGrpDrvAddrBitMap = UssCtrl_uCalcGroupDrvBitmap((uint8_t)US_D_PHYS_GRP_LEFT_SIDE);

    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_RIGHT_SIDE].uNumSnrsInGrp = 2u;
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_RIGHT_SIDE].uSnrDataIdx[0u] = US_D_SENSOR_AOR; /*If facing Right: Leftmost Sensor!!! */
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_RIGHT_SIDE].uSnrDataIdx[1u] = US_D_SENSOR_BOR;
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_RIGHT_SIDE].uGrpSnrIdxBitMap = UssCtrl_uCalcGroupSnrIdxBitmap((uint8_t)US_D_PHYS_GRP_RIGHT_SIDE);
    sPlatPhysInfo.psSnrPhysGrp[US_D_PHYS_GRP_RIGHT_SIDE].uGrpDrvAddrBitMap = UssCtrl_uCalcGroupDrvBitmap((uint8_t)US_D_PHYS_GRP_RIGHT_SIDE);
#endif

    UssOD_FovPreprocessing();
#if (USS_FEATURE_ZONE_INFO == US_STD_ON)
    UssOD_SectorPreprocessing();
#endif
}

/*===========================================================================
 * \brief Calculate sensor index from sensor bitmap.
 *
 * \param uint32_t uSnrMap (Only one bit should be set.)
 * \param none
 * \return uint8_t uSnrIdx  Defaults to zero if sensor is not configured.
 * \remarks Only performed at (re)initialization.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uCalcSnrIdxFromSnrMap
 * Remarks:  DD-ID: {6B914BF3-7BD1-47c3-9513-6F019DDF9D78}
 * Req.-ID: 13477648
 * ===========================================================================*/
 
static uint8_t UssCtrl_uCalcSnrIdxFromSnrMap(uint32_t uDrvSnrBitMap, uint32_t uAllSnrBitMap)
{
    uint8_t uIdx;
    uint8_t uSnrIdx = ZERO;

    uint32_t uSnrBitMask = BIT0;

    for (uIdx = 0u; uIdx < US_D_MAX_NUM_SENSORS_CONFIGURABLE; uIdx++)
    {
        if ((uAllSnrBitMap & uSnrBitMask) != ZERO)  /*A sensor exists at this bit location */
        {
            if ((uDrvSnrBitMap & uSnrBitMask) != ZERO)  /*This is the sensor we want the index for. */
            {
                break;  /*We have the index. */
            }
            uSnrIdx++;  // Only increment index is sensor if populated in sensor map.
        }
        uSnrBitMask <<= ONE; /*Advance to next bit */

    }

    if (uSnrIdx >= US_D_MAX_NUM_SENSORS)
    {
        uSnrIdx = (US_D_MAX_NUM_SENSORS - ONE);
    }

    return uSnrIdx;
}

/*===========================================================================
 * \brief Calculate sensor Type from sensor position.
 *
 * \param uint8_t uSnrIdx
 * \return uint8_t Sensor Type. 
 * \remarks Only performed at (re)initialization.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uGetSnrTypeFromSnrPosition
 * Remarks:  DD-ID: {2A530750-1D1B-4182-88C9-5D0D5B88119C}
 * Req.-ID: 13473303
 * ===========================================================================*/
 
static uint8_t UssCtrl_uGetSnrTypeFromSnrPosition(uint8_t uSnrIdx)
{
    uint8_t SnrType;
    US_S_SensorsCfg_t const *pSnrCfg = US_SnrCfg_F_Get_SnrCfg();
	SnrType = (uint8_t)((pSnrCfg->Snr_Positions[uSnrIdx] >> SIXTEEN) & THREE);           /*Bit 16, bit 17. */

    return SnrType;
}
/*===========================================================================
 * \brief Calculate sensor bus index from sensor bitmap.
 *
 * \param uint32_t uSnrMap (Only one bit should be set.)
 * \param uint8_t uNumSnrPerBus
 * \return uint8_t Sensor bus index. Defaults to zero if sensor is not configured.
 * \remarks Only performed at (re)initialization.
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_uCalcSnrBusFromSnrMap
 * Remarks:  DD-ID: {D9099F39-F5DB-4d92-8BFB-53DC54A783EE}
 * Req.-ID: 13473277
 * ===========================================================================*/
 
static uint8_t UssCtrl_uCalcSnrBusFromSnrMap(uint32_t uDvrSnrBitMap)
{
    uint8_t uBus = ZERO;
    uint8_t uCount = ZERO;
    uint8_t uSnrIdx;

    US_S_SensorsCfg_t const *pSnrCfg = US_SnrCfg_F_Get_SnrCfg();

    uint32_t uSnrBitMask = BIT0;
    for (uSnrIdx = 0u; uSnrIdx < US_D_MAX_NUM_SENSORS_CONFIGURABLE; uSnrIdx++)
    {
        if ((uDvrSnrBitMap & uSnrBitMask) != ZERO) /*Is this the sensor of interest? */
        {
            break;  /*Ok this is the sensor of interest, exit function. */
        }

        uCount++;  // If not, advance count of sensors positions on this bus
        if (uCount >= pSnrCfg->Max_nSnr_ON_SINGLE_BUS)
        {
            uBus++;         // Advance to next bus
            uCount = ZERO;  /*Restart count for the new bus of interest. */
        }
        uSnrBitMask <<= ONE;
    }
    return uBus;
}

/*===========================================================================
 * \brief Calculate driver address bitmap for entire group.
 *
 * \param uint32_t uSnrMap (Only one bit should be set.)
 * \param uint8_t uNumSnrPerBus
 * \return uint8_t Sensor bus index. Defaults to zero if sensor is not configured.
 * \remarks Only performed at (re)initialization.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uCalcGroupDrvBitmap
 * Remarks:  DD-ID: {B810CC89-D420-4b05-9332-9C295C84B0FB}
 * Req.-ID: 13473275
 * ===========================================================================*/
 
static uint32_t UssCtrl_uCalcGroupDrvBitmap(uint8_t uGrpIdx)
{
    const uint32_t * pauSnrAddrList = UssCtrl_pauGetSnrAddrList();      /*Get pointer to the sensor address list. */
    uint8_t uSnrGrpIdx;
    uint8_t uSnrDataIdx;
    uint8_t uNumSnrsInGrp;
    uint32_t uGrpBitMap = ZERO;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();

    uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

    /*
     * Perform for each sensor in group
     */
    for (uSnrGrpIdx = ZERO; uSnrGrpIdx < uNumSnrsInGrp; uSnrGrpIdx++)
    {
        /*Retrieve the index to the sensor, from the physical group data */
        uSnrDataIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uSnrGrpIdx];
        uGrpBitMap |= pauSnrAddrList[uSnrDataIdx];
    }

    return uGrpBitMap;
}

/*===========================================================================
 * \brief Calculate application level sensor index bitmap for entire group.
 *
 * \param uint8_t uGrpIdx - group id using #def US_D_PHYS_GRP_
 * \return uint16_t uGrpBitMap - all sensor index bits for a group
 * \remarks Only performed at (re)initialization.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uCalcGroupSnrIdxBitmap
 * Remarks:  DD-ID: {46E45D03-7D3D-4ac9-81D2-885DB13E7DAD}
 * Req.-ID: 13473275
 * ===========================================================================*/
 
static uint16_t UssCtrl_uCalcGroupSnrIdxBitmap(uint8_t uGrpIdx)
{
    uint8_t uGrpSnrIdx;
    uint8_t uAppSnrIdx;
    uint8_t uNumSnrsInGrp;
    uint32_t uGrpBitMap = ZERO;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();

    uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

    /*
     * Perform for each sensor in group
     */
    for (uGrpSnrIdx = ZERO; uGrpSnrIdx < uNumSnrsInGrp; uGrpSnrIdx++)
    {
        /* Retrieve the index to the sensor, from the physical group data*/
          uAppSnrIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uGrpSnrIdx];
            uGrpBitMap |= (uint32_t)US_IDX_TO_BIT_LOC(uAppSnrIdx);   
    }

    return (uint16_t)(uGrpBitMap & 0xffffu);
}

/*===========================================================================
* \brief Calculate sensor index, driver addr, bus, & bitmap for quick lookup.
*
* \param none
* \param none
* \return none
* \remarks Only performed at (re)initialization.
* ==========================================================================
*/
/* ===========================================================================
 * Name:	 UssCtrl_PopulateSnrInfoArrays
 * Remarks:  DD-ID: {3759B154-C5A0-4bce-9F58-8852A708CCD2}
 * Req.-ID: 13473275
 * ===========================================================================*/
 
static void UssCtrl_PopulateSnrInfoArrays(uint8_t uSnrAppIdx, uint16_t uSnrLoc)
{
    uint32_t uAllSnrBitMap = sPlatPhysInfo.uInstSnrDvrAddrMask;
    uint32_t uDrvSnrAddr = US_SnrCfg_F_Get_CfgSnrMap(uSnrLoc);
    uint32_t uSnrDvrIdx;

    /* Insure index is within bounds of array.  (Protects against electrical calibration mistakes.)  */
    if (uSnrAppIdx < US_D_MAX_NUM_SENSORS)
    {
        if (uDrvSnrAddr == ZERO)  /* Sensor not in electrical calibration map.*/
        {
            /* Sensor not installed. */
            if (uUninstSnrDrvIdx < US_D_MAX_NUM_SENSORS)
            {
                auSnrIdxList[uUninstSnrDrvIdx]  = uSnrAppIdx; /* Application incoming data index mapping, and move index to next position at top of map */
                uUninstSnrDrvIdx++;
             }
            auSnrAddrList[uSnrAppIdx] = 0x0;                    /* No Bitmap for driver addressing */
            auSnrBusList[uSnrAppIdx]  = 0xFF;                   /* Not found on buses */
            auSnrTypeList[uSnrAppIdx] = SNR_TYPE_PDC;           /* Sensor Type (PSM/PDC)   Take PDC as default. */
    	}
        else
        {
            sPlatPhysInfo.uInstSnrAppIdxBitMask |= (uint32_t)US_IDX_TO_BIT_LOC(uSnrAppIdx); 

            /* Get sensor index from sensor address. */
            uSnrDvrIdx = UssCtrl_uCalcSnrIdxFromSnrMap(uDrvSnrAddr, uAllSnrBitMap);

            /* Get other important interface values */
            auSnrIdxList[uSnrDvrIdx]  = uSnrAppIdx;                                     /*  Application incoming data index mapping */
            auSnrAddrList[uSnrAppIdx] = uDrvSnrAddr;                                    /* Bitmap for driver addressing  */
            auSnrBusList[uSnrAppIdx]  = UssCtrl_uCalcSnrBusFromSnrMap(uDrvSnrAddr);     /* Bus number  */

            auSnrTypeList[uSnrAppIdx] = UssCtrl_uGetSnrTypeFromSnrPosition((uint8_t)uSnrDvrIdx);  /*Sensor Type (PSM/PDC)*/
        }
    }
    /* else It just get's thrown out, not mapped at all.   Should throw a cal/config error, if there was one.  FUSA issue! */
    /*      Too many sensors configured for allocated US_D_MAX_NUM_SENSORS array size.  Again a FuSa concern.  */
    /*      What error or action do we perform in this instance?  */
}


/*
 * Sensor Marriage.
 * Note: Since no one's indexes will match mine,
 *       the default behavior of the routine is to leave map as is.
 *       As if this function was never being called.
 */

/*===========================================================================
* \brief Perform sensor marriage index re-mapping.
*
* \param none
* \param none
* \return none
* \remarks Only performed at (re)initialization.
* ==========================================================================
*/
/* ===========================================================================
 * Name:	 UssCtrl_PerformSnrMarIdxMapping
 * Remarks:  DD-ID: {D2CA571D-EEC9-4e21-B272-EC668BD79F36}
 * Traceability to source Code:
 * Req.-ID: 14962234
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
void UssCtrl_PerformSnrMarIdxMapping(void)
{
    /*
     * Although this algo could work within the existing space of the original arrays,
     * the logic is so complicated to do it that way, that it is worth sacrificing a
     * small amount of stack to great simplify the sensor index matching process is worth it.
     * Thusly, create a copy of all critical arrays, while making rearrangements to them.
     * Back-Annotate the original arrays with the copies, once the algo completes.
     */
    uint32_t uCopySnrIDList[US_D_MAX_NUM_SENSORS];   /* Copy of puSnrIDList */
    uint32_t uCopySnrAddrList[US_D_MAX_NUM_SENSORS]; /* Copy of auSnrAddrList */

    /* System information */
    US_S_MarriageSensorIDs_t sNvmSnrIds;
    US_S_PlatPhysInfo_t const * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    uint32_t * puSnrIDList = US_SnrCfg_F_Get_uSnrIDList();

    /* Working variables */
    uint16_t uSnrIdHash;
    uint16_t uRetStat;
    uint8_t  uAppSnrIdx;
    uint8_t  uDvrSnrIdx;
    uint8_t  uMarriageDrvSnrIdx;
    uint8_t  uCurBusIdx;
    uint8_t  uStartDvrSnrIdx;
    uint8_t  uNumBusIndexes;
    uint8_t  uNumMissingSnrs;
    uint8_t  uCurMarriageStatBits = ZERO;
    bool_t   bIdsAllMatch;
    bool_t   bListsModified = ME_FALSE;
    bool_t   bLastSensorOnBus;

    /* Try to Read Nvm */
#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
    uRetStat = Rivian_NVMRead_SensorMarriage(&sNvmSnrIds);
#else
    uRetStat = NVMRead_SensorMarriage(&sNvmSnrIds);
#endif
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
#ifdef USS_DEBUG
    if (uRetStat != ME_OK)
    {
        pam_uart_send_data("NVM READ NOK\r\n");
    }
    else
    {
        pam_uart_send_data("NVM READ OK\r\n");
    }

#endif
#endif

    if (uRetStat == ME_OK)
    {
        uCurMarriageStatBits = (uint8_t)((sNvmSnrIds.uMarriageStatus & 0xF000u) >> (uint8_t)TWELVE); /* Get current NVM Marriage status bits.   */
        uMarriageStatBits = uCurMarriageStatBits; /* Updated NVM Marriage status bits.*/
    }

    /*
     * If we have all (full count) of sensors then make sure, as a safety, they haven't been rearranged or replaced.
     * If so, then request marriage to ECU NVM.
     */
    if ( (psPlatPhysInfo->uNumActSnrs == psPlatPhysInfo->uNumCalSnrs)
        && (puSnrIDList[ZERO] != ZERO)) /* Protection against sensor ID read failure writing zeros to NVM.  */
    {
        uMarriageStatApiBits = US_D_ALL_SENSORS_MARRIAGE_DONE_API_BITS; /* For now, all considered Done on API.  If NVM write fails later than change to Error. */
        uMarriageStatBits = US_D_ALL_SENSORS_MARRIAGE_DONE_NVM_BITS;    /* For now, all considered Done in NVM.  If NVM write fails later, bits will remain unchanged. */


        /* Full busses but NVM read was no good.  Don't know what to do.  Try writing them again? Open to suggestions. - JP */
        if (uRetStat != ME_OK)
        {
            uSnrMarriageMap = (uint32_t) US_D_ALL_SNR_BITMAP;
            bSnrMarriageRequested = ME_TRUE;  /* Command NVM Write */
        }
        else
        {
            /* Scan all the IDs from NVM for validity. */
            uSnrIdHash = ZERO;
            for (uAppSnrIdx = ZERO; uAppSnrIdx < US_D_MAX_NUM_SENSORS; uAppSnrIdx++)
            {
                if (   (sNvmSnrIds.uSavedSensorIDs[uAppSnrIdx] != puSnrIDList[uAppSnrIdx])  /* Does installed sensor ID not match NVM?*/
                    || (sNvmSnrIds.uSavedSensorIDs[uAppSnrIdx] == ZERO))                    /* or Does NVM data have zeros instead of IDS? */
                {
                    uSnrMarriageMap = (uint32_t)US_D_ALL_SNR_BITMAP;	 /*QAC : 0499 bits shifting is equal to data type may be trunkate . */
                    bSnrMarriageRequested = ME_TRUE;  /* Command NVM Write */
                }

                /* While checking data, add up ID hash, both 16 bit words of address get added to hash, for final check. */
                uSnrIdHash += (uint16_t)(sNvmSnrIds.uSavedSensorIDs[uAppSnrIdx] & 0xFFFFu) + (uint16_t)(sNvmSnrIds.uSavedSensorIDs[uAppSnrIdx] >> SIXTEEN); /*QAC : 4461 data type converted to narrower unsigned type. */
            }

            /* Check uSnrIdHash against stored sensor IDs hash */
            if ((uint16_t) (sNvmSnrIds.uMarriageStatus >> SIXTEEN) != uSnrIdHash)
            {
                uSnrMarriageMap = (uint32_t)US_D_ALL_SNR_BITMAP;  /*QAC : 0499 bits shifting is equal to data type may be trunkate .*/
                bSnrMarriageRequested = ME_TRUE;  /* Command NVM Write */
            }

            /* Check marriage stat bits to insure they are up to date */
            if (uCurMarriageStatBits != (uint8_t)US_D_ALL_SENSORS_MARRIAGE_DONE_NVM_BITS)
            {
                uSnrMarriageMap = (uint32_t)US_D_ALL_SNR_BITMAP;	 /*QAC : 0499 bits shifting is equal to data type may be trunkate .*/
                bSnrMarriageRequested = ME_TRUE;  /* Command NVM Write */
            }
        }

        /* No re-mapping required. */
        return; /**************** DONE.  NO FURTHER ANALYSIS REQUIRED. EARLY RETURN! ********************/
    }

    /*
     * ***** SENSOR ID MATCHING *****
     * Less than all calibrated sensors are installed.
     * Match them to previous IDs stored in NVM.
     *
     * Copy of the sensor IDs and address translation for rearrangement are created.
     * Original lists maintained until index mapping complete,
     * then back-annotated to reflect marriage positions.
     * This brute force approach is more expensive on memory, but much
     * simpler logic to follow.
     */
    (void)memcpy(uCopySnrIDList, puSnrIDList, (uint32_t)US_D_MAX_NUM_SENSORS * sizeof(uint32_t));
    (void)memcpy(uCopySnrAddrList, auSnrAddrList, (uint32_t)US_D_MAX_NUM_SENSORS * sizeof(uint32_t));

    /* Initial values for this bus */
    uCurBusIdx       = auSnrBusList[auSnrCfgIdxList[ZERO]];     /* Start with bus associated with first sensor driver index.*/
    uStartDvrSnrIdx  = ZERO;                   /* Start with driver sensor index zero.*/
    uNumBusIndexes   = ZERO;                   /* Count sensors expected on this bus.*/
    uNumMissingSnrs  = ZERO;                   /* Count sensors with an ID of zero, ie missing.*/
    bIdsAllMatch     = ME_TRUE;                /* Indication if all IDs on bus match expected in NVM.*/
    bLastSensorOnBus = ME_FALSE;               /* Is this the last sensor on the bus*/

    /* Scan sensors in driver index order, and mark first idx, last idx, and count number of sensors on bus. */
    for (uDvrSnrIdx = ZERO; uDvrSnrIdx < US_D_MAX_NUM_SENSORS; uDvrSnrIdx++)
    {
        uAppSnrIdx = auSnrCfgIdxList[uDvrSnrIdx];  /* Get the application sensor index for this sensor*/

        /* Check if sensor installed.  Ignore otherwise.*/
        if ((psPlatPhysInfo->uInstSnrAppIdxBitMask & US_IDX_TO_BIT_LOC(uAppSnrIdx)) != ZERO)
        {
            /* This ID doesn't match NVM.  Invalidate IDs IsAllMatch flag */
            if (   (sNvmSnrIds.uSavedSensorIDs[uAppSnrIdx] != puSnrIDList[uAppSnrIdx])
                || (sNvmSnrIds.uSavedSensorIDs[uAppSnrIdx] == ZERO))
            {
                bIdsAllMatch = ME_FALSE;
            }
            else
            {
                ;/*Do nothing*/
            }
            /* Count up number of sensor indexes for this bus. */
            uNumBusIndexes++;//PRQA S    We want variable to rollover,required behaviour

            /* Count missing sensors on this bus. */
            if (puSnrIDList[uAppSnrIdx] == ZERO)
            {
                uNumMissingSnrs++;//PRQA S    We want variable to rollover,required behaviour
            }
            else
            {
                ;/*Do nothing*/
            }
        }
        else
        {
           ;/* Do nothing */
        }

        if (uDvrSnrIdx == (US_D_MAX_NUM_SENSORS - ONE))   /* Last sensor in array, so conclude now.*/
        {
            bLastSensorOnBus = ME_TRUE;
        }
        else if (uCurBusIdx != auSnrBusList[auSnrCfgIdxList[uDvrSnrIdx + ONE]])      /* Check for bus index change.*/
        {
            bLastSensorOnBus = ME_TRUE;
        }
      else{ /*empty */ }

        /*
         *   ************ PROCESS THE BUS *************
         * If new bus detected then it's time to process the bus we just scanned.
         *
         */
        if (bLastSensorOnBus == (bool_t)ME_TRUE)      /* If last sensor on bus.*/
        {
            if (uCurBusIdx != 0xFFu) /* If this is not a configured sensor area then skip.*/
            {
                /* If there are missing sensors try to match them with NVM.*/
                if (uNumMissingSnrs != ZERO)
                {

#if US_D_EEPROM_STORAGE_EXISTS == ME_FALSE
                    UssCrtl_MoveSnrsToDsiEndOfBus(uStartDvrSnrIdx,
                                                  uNumBusIndexes,
                                                  uNumMissingSnrs,
                                                  puSnrIDList,
                                                  uCopySnrIDList,
                                                  uCopySnrAddrList);
#else
                    UssCrtl_RemapSensorPostions(uStartDvrSnrIdx,
                                                uNumBusIndexes,
                                                uNumMissingSnrs,
                                                puSnrIDList,
                                                uCopySnrIDList,
                                                uCopySnrAddrList,
                                                sNvmSnrIds.uSavedSensorIDs);
#endif

                    bListsModified = ME_TRUE;

                    /* Set Marriage status API to Pending for this bus */
                    /*uCurBusIdx  uCurMarriageStatBits */
                }
                else /*No missing sensors on this bus. */
                {
                    /* Bus is full but check if sensors have been replaced */
                    if (bIdsAllMatch == (bool_t)ME_FALSE)
                    {
                        /* Bus is full but IDs have changed.  Request write to NVM for just this bus.
                         * Other busses with replacement might also set bits in marriage map, but it will always be a full bus.
                         */
                        for (uMarriageDrvSnrIdx = uStartDvrSnrIdx; uMarriageDrvSnrIdx <= uDvrSnrIdx; uMarriageDrvSnrIdx++)
                        {
                            uAppSnrIdx = auSnrCfgIdxList[uMarriageDrvSnrIdx];  /* Get the application sensor index for this sensor*/
                            uSnrMarriageMap |= US_IDX_TO_BIT_LOC(uAppSnrIdx);
                        }

                        uMarriageStatBits |= (BIT0 << uCurBusIdx);  /* Set marriage status bit to Written, for this bus.*/
                        bSnrMarriageRequested = ME_TRUE;
                    }
                    else
                    {
                        /* All IDs match, so no need to write NVM IDs again, unless status bits are not up to date, then write them to NVM (safety). */
                        if ((uCurMarriageStatBits & (BIT0 << uCurBusIdx)) == ZERO)
                        {
                            uMarriageStatBits |= (BIT0 << uCurBusIdx);  /* Set marriage status bit to Written, for this bus.*/
                            bSnrMarriageRequested = ME_TRUE;
                        }
                    }
                }

                /* Set API status bits accordingly */
                uMarriageStatApiBits &= ~((uint32_t) 0xFF << (uCurBusIdx << THREE)); /* Clear the status bits for this bus.*/

                if ((uMarriageStatBits & (BIT0 << uCurBusIdx)) == ZERO) /* No marriage status on record in NVM, thus Pending Status.*/
                {
                    uMarriageStatApiBits |= ((uint32_t)((uint32_t)US_D_ALL_SENSORS_MARRIAGE_PENDING << (uCurBusIdx << THREE)));  /* Sensor position mapped without marriage.*/
                }
                else /* Marriage status on record in NVM, thus Done Status.*/
                {
                    uMarriageStatApiBits |= ((uint32_t)((uint32_t)US_D_ALL_SENSORS_MARRIAGE_DONE << (uCurBusIdx << THREE)));  /* Sensor position mapped with marriage. */
                }
            }

            /* Prepare to match next bus with NVM */
            if (uDvrSnrIdx != (US_D_MAX_NUM_SENSORS - ONE))
            {
                uCurBusIdx = auSnrBusList[auSnrCfgIdxList[uDvrSnrIdx + ONE]];  /* Advance bus index.*/
                uStartDvrSnrIdx  = uDvrSnrIdx + ONE;          /* Set start driver index of next bus.*/
            }

            uNumBusIndexes   = ZERO;                      /* Reset number of indexes count.*/
            uNumMissingSnrs  = ZERO;                      /* Reset missing sensors count.*/
            bIdsAllMatch     = ME_TRUE;                   /* Assume all IDs match to start.*/
            bLastSensorOnBus = ME_FALSE;                  /* Reset last sensor on bus flag.*/
        }

        /*
         *   ************ END OF PROCESSING THE BUS *************
         *
         *   Below, continues the scan of the bus until end of bus reached.
         */
    }

    /* If we have moved any sensor indexes around we need to lock in the new translation interface */
    if (bListsModified == (bool_t)ME_TRUE)
    {
        (void) memcpy(puSnrIDList, uCopySnrIDList, (uint32_t)US_D_MAX_NUM_SENSORS * sizeof(uint32_t));
        (void)memcpy(auSnrAddrList, uCopySnrAddrList, (uint32_t)US_D_MAX_NUM_SENSORS * sizeof(uint32_t));

        UssSnrCmd_PopulateSnrAddrIdxList();
    }
}

/* ===========================================================================
 * Name:	 UssCrtl_MoveSnrsToDsiEndOfBus
 * Remarks:  DD-ID: {4C8FAE5D-D4EC-4825-8373-9CC922DDD479}
 * Req.-ID: 13411429
 * ===========================================================================*/
 
#if US_D_EEPROM_STORAGE_EXISTS == ME_FALSE

static void UssCrtl_MoveSnrsToDsiEndOfBus(uint8_t uStartDrvSnrIdx,
                                          uint8_t uNumBusIndexes,
                                          uint8_t uNumMissingSnrs,
                                          uint32_t * puSnrIDList,
                                          uint32_t * puCopySnrIDList,
                                          uint32_t * puCopySnrAddrList)
{
    uint8_t uDvrSnrIdx;
    uint8_t uNumActiveSnrs = uNumBusIndexes - uNumMissingSnrs;
    uint8_t uDvrPosIdx;
    uint8_t uSrcAppIdx;
    uint8_t uDestAppIdx;

    for (uDvrPosIdx = ZERO; uDvrPosIdx < uNumBusIndexes; uDvrPosIdx++)
    {
        uDvrSnrIdx = uStartDrvSnrIdx + uDvrPosIdx;
        uSrcAppIdx = auSnrCfgIdxList[uDvrSnrIdx];

        if (uDvrPosIdx < uNumActiveSnrs)
        {
            uDestAppIdx = auSnrCfgIdxList[uDvrSnrIdx + uNumMissingSnrs];

            auSnrIdxList[uDvrSnrIdx]       = auSnrCfgIdxList[uDvrSnrIdx + uNumMissingSnrs];
            puCopySnrAddrList[uDestAppIdx] = auSnrAddrList[uSrcAppIdx];
            puCopySnrIDList[uDestAppIdx]   = puSnrIDList[uSrcAppIdx];
        }
        else
        {
            uDestAppIdx = auSnrCfgIdxList[uDvrSnrIdx - uNumActiveSnrs];

            auSnrIdxList[uDvrSnrIdx]        = auSnrCfgIdxList[uDvrSnrIdx - uNumActiveSnrs];
            puCopySnrAddrList[uDestAppIdx]  = auSnrAddrList[uSrcAppIdx];
            puCopySnrIDList[uDestAppIdx]    = puSnrIDList[uSrcAppIdx];
        }
    }

    (void)memcpy((auSnrAddrList + uStartDrvSnrIdx), (puCopySnrAddrList + uStartDrvSnrIdx), uNumBusIndexes * sizeof(uint32_t));
    (void)memcpy((puSnrIDList + uStartDrvSnrIdx), (puCopySnrIDList + uStartDrvSnrIdx), uNumBusIndexes * sizeof(uint32_t));
}
#else


/*===========================================================================
* \brief When auto-addressing occurs, all active sensor occupy lowest indexes.
*        Slide all sensor indexes to final locations if possible.
*
* \param uint8_t uStartDrvSnrIdx Start index of this bus in driver index ie. Untranslated to app idxes.
* \param uint8_t uNumBusIndexes Number of sensors that should have been on this bus.
* \param uint8_t uNumMissingSnrs Number of missing sensors on this bus.
* \param uint8_t * puCopySnrIdxList  Pointer to copy of the sensor index translation list.
* \param uint32_t * puCopySnrIDList  Pointer to copy of of sensor ID List
* \param uint32_t * puNvmIDList  Pointer to the ID list currently in NVM.
* \return none
* \remarks Only performed at (re)initialization.
* ==========================================================================
*/
/* ===========================================================================
 * Name:	 UssCrtl_RemapSensorPostions
 * Remarks:  DD-ID: {536EC325-000F-43f5-BD41-346BC6E37E3E}
 * Req.-ID: 13411429
 * ===========================================================================*/
 
static void UssCrtl_RemapSensorPostions(uint8_t uStartSnrDvrIdx,
                                        uint8_t uNumBusIndexes,
                                        uint8_t uNumMissingSnrs,
                                        uint32_t const * puSnrIDList,
                                        uint32_t * puCopySnrIDList,
                                        uint32_t * puCopySnrAddrList,
                                        uint32_t const * puNvmIDList)
{
    uint8_t uSnrAppIdx;
    uint8_t uSnrDvrIdx;
    uint8_t uNumSnrSearch;
    uint8_t uNoMarriageDvrIdx;
    uint8_t uNextMissingSnrDvrIdx;
    uint8_t uMissingSnrAppIdx;
    uint8_t uSnrMatchOffset;
    uint8_t uSnrMatchDvrIdx;
    uint8_t uSnrMatchAppIdx;
    uint8_t uGapDvrIdx;
	uint8_t uSnrCnt;

   /*comment  bool_t  bMatchingIdFound; */

    uNumSnrSearch = uNumBusIndexes - uNumMissingSnrs;               /* Number of installed sensors on this bus. */
    uNoMarriageDvrIdx = uStartSnrDvrIdx + uNumBusIndexes - ONE;     /* Default location for sensor not married.*/

    uNextMissingSnrDvrIdx =  uNoMarriageDvrIdx;  /* Next location from which to retrieve a missing sensor index. */

    /*
     * Outer loop walks backwards through all installed sensors.
     */
	uSnrMatchOffset = uNumSnrSearch - ONE;
    for (uSnrCnt = ZERO; uSnrCnt < uNumSnrSearch; uSnrCnt++, uSnrMatchOffset--)
    {
        uSnrMatchDvrIdx = uStartSnrDvrIdx + uSnrMatchOffset;  /* Driver idx of sensor to search for match for marriage. */
        uSnrMatchAppIdx = auSnrCfgIdxList[uSnrMatchDvrIdx];   /* Application idx of sensor to search for match for marriage.*/

        /* Check sensor at its present location, and up to one before its default location. */
        for (uSnrDvrIdx = uSnrMatchDvrIdx;  uSnrDvrIdx < uNoMarriageDvrIdx; uSnrDvrIdx++)
        {
            uSnrAppIdx = auSnrCfgIdxList[uSnrDvrIdx];  /* App sensor index of marriage search location. */

            /* Compare current sensor active sensor ID with next NVM Location: Note: Uninstalled sensors will report Zero as ID and not match. */
            if (puSnrIDList[uSnrMatchAppIdx] == puNvmIDList[uSnrAppIdx])
            {
                /* Transcribe data for this sensor to the correct locations */
                auSnrIdxList[uSnrMatchDvrIdx] = uSnrAppIdx;
                puCopySnrAddrList[uSnrAppIdx] = auSnrAddrList[uSnrMatchAppIdx];
                puCopySnrIDList[uSnrAppIdx]   = puSnrIDList[uSnrMatchAppIdx];

                /* If there are any unused locations, including the default location, up to,
                 * but not including the found location, then fill in with dead sensor indices.
                 * If a sensor lands in its default location, this loop will not execute.
                 */
                for (uGapDvrIdx = (uSnrDvrIdx + ONE); uGapDvrIdx <= uNoMarriageDvrIdx; uGapDvrIdx++)
                {
                    uSnrAppIdx = auSnrCfgIdxList[uGapDvrIdx];  /* App idx of next gap location to fill. */
                    uMissingSnrAppIdx = auSnrCfgIdxList[uNextMissingSnrDvrIdx];

                    /* Transcribe data for this sensor to the correct locations */
                    auSnrIdxList[uNextMissingSnrDvrIdx] = uSnrAppIdx;
                    puCopySnrAddrList[uSnrAppIdx]       = auSnrAddrList[uMissingSnrAppIdx];
                    puCopySnrIDList[uSnrAppIdx]         = puSnrIDList[uMissingSnrAppIdx];

                    uNextMissingSnrDvrIdx--;//PRQA S    We want variable to rollover,required behaviour
                }

                /* I'm not technically modifying the loop limit within the loop because the loop is immediately exits! */
                /* This modification is for the next new loop. */
                uNoMarriageDvrIdx = uSnrDvrIdx - ONE;
                break;
            }
            else
            {
                /*Do nothing*/
            }
        }

        /*
         * No marriage match found, or match exists in default location.
         * Either way, store data in default location.
         */
        if (uSnrDvrIdx == uNoMarriageDvrIdx)
        {
            uSnrAppIdx = auSnrCfgIdxList[uSnrDvrIdx];   /* App sensor index of marriage default location. */

            auSnrIdxList[uSnrMatchDvrIdx] = uSnrAppIdx;
            puCopySnrAddrList[uSnrAppIdx] = auSnrAddrList[uSnrMatchAppIdx];
            puCopySnrIDList[uSnrAppIdx]   = puSnrIDList[uSnrMatchAppIdx];

            uNoMarriageDvrIdx = uSnrDvrIdx - ONE;
        }
    }

    if (uNoMarriageDvrIdx != 0xFFu)
    {
        /* All sensors that are alive have been placed, now moving towards tip of bus,
         * fill in unused locations as sensor disconnects.
         * Use uNextMissingSnrDvrIdx to choose unused sensor indices to use to fill
         * disconnected sensor locations.
         */
        for (uSnrDvrIdx = uStartSnrDvrIdx; uSnrDvrIdx <= uNoMarriageDvrIdx; uSnrDvrIdx++)
        {
            uMissingSnrAppIdx = auSnrCfgIdxList[uNextMissingSnrDvrIdx];  /* App sensor index of next missing sensor index.*/
            uSnrAppIdx = auSnrCfgIdxList[uSnrDvrIdx];  /* App idx of next gap location to fill.*/

            /* Transcribe data for this sensor to the correct locations */
            auSnrIdxList[uNextMissingSnrDvrIdx] = uSnrAppIdx;
            puCopySnrAddrList[uSnrAppIdx]       = auSnrAddrList[uMissingSnrAppIdx];
            puCopySnrIDList[uSnrAppIdx]         = puSnrIDList[uMissingSnrAppIdx];

            uNextMissingSnrDvrIdx--;//PRQA S    We want variable to rollover,required behaviour
        }
    }
}

#endif

/* ===========================================================================
 * Name:	 UssCtrl_PerformSnrMarWriteChk
 * Remarks:  DD-ID: {2B32724B-36A6-4dc3-9CE7-F2FE6E3A1563}
 * Req.-ID:
 * Req.-ID:
 * Req.-ID:
 * Req.-ID:
 * Req.-ID:
 * ===========================================================================*/
 
void UssCtrl_PerformSnrMarWriteChk(void)
{
    uint32_t const * puSnrIDList;
    uint16_t uSnrIdHash;
    uint16_t uWriteCount;
    uint16_t uRetStat;
    uint16_t uBitMask;
    uint8_t  uSnrIdx;
    US_S_MarriageSensorIDs_t sNvmSnrIds;

    if (bSnrMarriageRequested ==(bool_t) ME_TRUE)
    {
        /* Try to Read Nvm */
#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
        uRetStat = Rivian_NVMRead_SensorMarriage(&sNvmSnrIds);
#else
        uRetStat = NVMRead_SensorMarriage(&sNvmSnrIds);
#endif

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
#ifdef USS_DEBUG
    if (uRetStat == ME_OK)
    {
        pam_uart_send_data("NVM READ OK\r\n");
    }
    else
    {
        pam_uart_send_data("NVM READ NOK\r\n");
    }
#endif
#endif

        /*
         *  If fail, don't do anything? Try again next time I guess?
         *  This could take the system down. :(
         *  Maybe it would be good to limit write tries? - JP
         */
        if (uRetStat == ME_OK)
        {
            puSnrIDList = US_SnrCfg_F_Get_uSnrIDList();

            /* Update sensor IDs that have full busses and have changed */
            uBitMask = BIT0;
            for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
            {
                if ((uSnrMarriageMap & uBitMask) != ZERO)
                {
                    sNvmSnrIds.uSavedSensorIDs[uSnrIdx] = puSnrIDList[uSnrIdx];
                }
                uBitMask <<= ONE;
            }

            /* Get write count to increment, and eventually store*/
            uWriteCount = (uint16_t) (sNvmSnrIds.uMarriageStatus & 0x0FFFu);

            /* Calculate Hash-16 value from sensor IDs to be written. */
            uSnrIdHash = ZERO;
            for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
            {
                uSnrIdHash += (uint16_t) (puSnrIDList[uSnrIdx] & 0xFFFFu) + (uint16_t) (puSnrIDList[uSnrIdx] >> SIXTEEN);
            }

            /* Not sure if the desired behavior is to prevent overflow of write count, but seems logical */
            if (uWriteCount < 0x0FFFu)
            {
                uWriteCount++; /* Increment out write count*/
            }

            /* Pack up the status to send to NVM */
            sNvmSnrIds.uMarriageStatus = (uint32_t) (((uint32_t)uSnrIdHash << SIXTEEN) | (((uint32_t)uMarriageStatBits & 0x0Fu) << TWELVE) | (uint32_t)uWriteCount);

            /* Write NVM - BLOCKING - Up to one second. */
#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
            uRetStat = Rivian_NVMWrite_SensorMarriage(&sNvmSnrIds);
#else
            uRetStat = NVMWrite_SensorMarriage(&sNvmSnrIds);
#endif

            /* It worked, so stop trying to write duplicate data */
            if (uRetStat == ME_OK)
            {
                bSnrMarriageRequested = ME_FALSE;
            }
            else
            {
                uMarriageStatApiBits = US_D_ALL_SENSORS_MARRIAGE_ERROR_API_BITS;
                /* Leave the bSnrMarriageRequested set to try again next cycle. */
            }
        }
        else
        {
            /* NVM could not be read, thus could also not be written.
             * Set Error on API.
             */
            uMarriageStatApiBits = US_D_ALL_SENSORS_MARRIAGE_ERROR_API_BITS;
            /* Leave the bSnrMarriageRequested set to try again next cycle.*/
        }
    }
   /* Update status on API */
  /*   UssCom_F_PopulateMarriageStatApiBits(uMarriageStatApiBits) */
}

/* ===========================================================================
 * Name:	 USS_TriggerSensorMarriage
 * Remarks:  DD-ID:
 * ===========================================================================*/
 
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
/*===========================================================================
 * \brief Request sensor NVM write.
 *
 * \param none
 * \param none
 * \return uint16_t status.
 * \remarks
 * ==========================================================================
 */
uint16_t USS_TriggerSensorMarriage(void)
{
    if(   (UssMgr_eGetSysState() == SYSMGR_SYS_READY)
       || (UssMgr_eGetSysState() == SYSMGR_SYS_DIAGNOSTIC))
    {
        bSnrMarriageRequested = ME_TRUE;
        UssCtrl_PerformSnrMarWriteChk();
        return ME_OK;
    }
    else
    {
        return ME_NOT_OK;
    }
}
#endif

/*===========================================================================
 * \brief Get platform groups and sensor counts.
 *
 * \param none
 * \param none
 * \return Sensor type
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_psGetSensorType
 * Remarks:  DD-ID: {7F5C6A23-AAAC-4328-BD54-2E4A5161EF75}
 * Req.-ID: 15735934
 * Req.-ID: 15736713
 * ===========================================================================*/
 
uint8_t * UssCtrl_psGetSensorType(void)
{
    return auSnrTypeList;
}

/*===========================================================================
 * \brief Get platform groups and sensor counts.
 *
 * \param none
 * \param none
 * \return pointer to US_S_PlatPhysInfo_t
 * \remarks
 * ==========================================================================*/

/* ===========================================================================
 * Name:	 UssCtrl_psGetPlatPhysInfo
 * Remarks:  DD-ID: {AA22DA2C-B93C-42ab-8352-92BEB15E663F}
 * Req.-ID: 13473275
 * ===========================================================================*/
US_S_PlatPhysInfo_t * UssCtrl_psGetPlatPhysInfo(void)
{
    return &sPlatPhysInfo;
}


/*===========================================================================
 * \brief Get pointer to sensor address array.
 *
 * \param none
 * \param none
 * \return uint8_t * pointer to sensor address array
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_pauGetSnrAddrList
 * Remarks:  DD-ID: {4477AB99-75A3-45ba-A3D2-4EE85EFD1DEA}
 * Req.-ID: 13473275
 * ===========================================================================*/
 
uint32_t * UssCtrl_pauGetSnrAddrList(void)
{
    return auSnrAddrList;
}

/*===========================================================================
 * \brief Get pointer to sensor index array.  May be remapped!
 *
 * \param none
 * \param none
 * \return uint8_t * pointer to sensor index array.  May be remapped!
 * \remarks
 * ==========================================================================*/
/* ===========================================================================
 * Name:	 UssCtrl_pauGetSnrIdxList
 * Remarks:  DD-ID: {6AFA0255-B994-4afb-AC6C-3A1D35AE488C}
 * Req.-ID: 13473275
 * ===========================================================================*/
 
uint8_t * UssCtrl_pauGetSnrIdxList(void)
{
    return auSnrIdxList;
}

/*===========================================================================
 * \brief Get pointer to sensor index array. Configuration map.
 *
 * \param none
 * \param none
 * \return uint8_t * pointer to sensor index array.  Configuration map.
 * \remarks
 * ==========================================================================
 */

/* ===========================================================================
 * Name:	 UssCtrl_pauGetSnrCfgIdxList
 * Remarks:  DD-ID: {17C602C1-A8B5-4d38-946E-1557ECFBC356}
 * Req.-ID: 13477648
 * ===========================================================================*/
uint8_t * UssCtrl_pauGetSnrCfgIdxList(void)
{
    return auSnrCfgIdxList;
}

/*===========================================================================
 * \brief Get pointer to sensor bus array.
 *
 * \param none
 * \param none
 * \return uint8_t * pointer to sensor bus array
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_pauGetSnrBusList
 * Remarks:  DD-ID: {E2FBDF2F-B63D-4ea7-87D0-FED5CDEEFAFB}
 * Req.-ID: 13473277
 * ===========================================================================*/
 
uint8_t * UssCtrl_pauGetSnrBusList(void)
{
    return auSnrBusList;
}

/* ===========================================================================
 * Name:	 UssCtrl_GetGroupIdxFromSensorIdx
 * Remarks:  DD-ID: {4D383025-3DCA-4a13-9645-986DA7BA74D0}
 * Req.-ID: 13477648
 * ===========================================================================*/
 
/* Get which group a sensor is in */
uint8_t UssCtrl_GetGroupIdxFromSensorIdx(uint8_t uAppSnrIdx)
{
    uint8_t uGrpIdx;
    uint32_t uSnrBitMask;
    
    if(uAppSnrIdx < US_D_MAX_NUM_SENSORS)
    {
        uSnrBitMask = (uint32_t)US_IDX_TO_BIT_LOC(uAppSnrIdx);
        
        for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
        {
            if( (sPlatPhysInfo.psSnrPhysGrp[uGrpIdx].uGrpSnrIdxBitMap & uSnrBitMask) == uSnrBitMask )
            {
                break;
            }
        }
    }
    else
    {
        uGrpIdx = 0xFF;
    }
    
    return uGrpIdx;
}

