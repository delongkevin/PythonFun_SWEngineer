/*
 * US_MgrUtility.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"
#include "US_MgrUtility.h"
#include "US_Platform_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_SysMgr_Global.h"
#if (US_D_USE_FAPA_API == ME_TRUE)
    #include "SignalDef.h"  /* comes from feature side?? terrible name */
#endif

/* Input result variables for returns - MUST HAVE DEFAULT */
#if (US_D_MGRUTIL_DEFAULT_VEHMOVING == ME_TRUE)
static bool_t g_bIsVehicleMoving = ME_TRUE;
#else
static bool_t g_bIsVehicleMoving = ME_FALSE;
#endif
static float32_t g_fCurVehSpeed_1kph = 0.0f;
static bool_t g_bIsFapaActive = ME_FALSE;


/* Local functions for runtime updates */
static void UpdateVehicleStatus(void);
static void UpdateFapaStatus(void);

/* Main cyclic function */
/* ===========================================================================
 * Name:	 UssMgr_Util_UpdateInputs
 * Remarks:  DD-ID: {3B2FACA8-D8BF-4626-BC2D-E1768B34B1EF}
 * ===========================================================================*/
void UssMgr_Util_UpdateInputs(void)
{
    UpdateVehicleStatus();
    UpdateFapaStatus();
}

/* ===========================================================================
 * Name:	 UpdateVehicleStatus
 * Remarks:  DD-ID: {EF6C18F9-FFE7-47c3-AFB5-36F1FCB01947}
 * ===========================================================================*/
static void UpdateVehicleStatus(void)
{
#if (US_D_MGRUTIL_DEFAULT_VEHMOVING == ME_TRUE)
    float32_t fVehSpeed = 100.0f;
#else
    float32_t fVehSpeed = 0.0f;
#endif

    if(UssCom_F_GetGearSpeedValidity() == US_SIGNALVALIDITY_VALID)
    {
        /*Read veh speed*/
        fVehSpeed = UssCom_F_GetVehSpeed();
    }
    /* TODO, get some sort of default here */
    
    g_fCurVehSpeed_1kph = fVehSpeed; /* Yes, this may be 100kph default */
    /* TODO jwr update this to be a bit more meaningful */
    g_bIsVehicleMoving = (fVehSpeed > 0.0f);
}

#if (US_D_USE_FAPA_API == ME_TRUE)
/* ===========================================================================
 * Name:	 UpdateFapaStatus
 * Remarks:  DD-ID: {B7BB08B5-999A-4c8a-94C2-2A74D1B0FAA0}
 * ===========================================================================*/
static void UpdateFapaStatus(void)
{
    TbAP_DriveAssistStatOut_t sDriveAssistStatOut;  /* from SignalDef.h */

    SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(&sDriveAssistStatOut);
    /* Do not perform mitigation in "FAPA mode" which is AP active and in PARK IN state. */
    g_bIsFapaActive = ( (TeAutoPark_e_AutoParkStatus_Active == sDriveAssistStatOut.IeAP_e_AutoParkStatus)
                        && (TeAP_e_AlgoState_Park_In == sDriveAssistStatOut.IeAP_e_AlgoState) );
}
#endif /* US_D_USE_FAPA_API == ME_TRUE */

/* ===========================================================================
 * Name:	 UssMgr_IsVehicleMoving
 * Remarks:  DD-ID: {B8B18E65-F451-4196-BB81-9C6082CAB094}
 * Req.-ID: 14992414
 * Req.-ID: 14992434
 * Req.-ID: 14992433
 * Req.-ID: 14992440
 * Req.-ID: 14992448
 * Req.-ID: 14992447
 * Req.-ID: 13475233
 * Req.-ID: 16132055
 * Req.-ID: 14992404
 * Req.-ID: 14992403
 * Req.-ID: 14992382
 * Req.-ID: 14992381
 * Req.-ID: 14992384
 * Req.-ID: 14992385
 * Req.-ID: 14992383
 * Req.-ID: 14992373
 * Req.-ID: 13420729
 * ===========================================================================*/
bool_t UssMgr_IsVehicleMoving(void)
{
    return g_bIsVehicleMoving;
}

#if (US_D_USE_FAPA_API == ME_TRUE)
/* ===========================================================================
 * Name:	 UssMgr_IsFeatureInFAPA
 * Remarks:  DD-ID: {587AF1A7-0C6A-407e-81FD-68B1A59D6D6D}
 * ===========================================================================*/
bool_t UssMgr_IsFeatureInFAPA(void)
{
    return g_bIsFapaActive;
}
#endif /* US_D_USE_FAPA_API */
/* ===========================================================================
 * Name:	 UssMgr_GetVehSpeed
 * Remarks:  DD-ID: {B88A1590-678E-4aa7-ACBA-AC04D800C4CF}
 * Req.-ID: 13396047
 * ===========================================================================*/
float32_t UssMgr_GetVehSpeed(void)
{
    return g_fCurVehSpeed_1kph;
}

/* ===========================================================================
 * Name:	 UssMgr_JKISS32RandAlgo
 * Remarks:  DD-ID: {47C70F09-EBA3-4e19-B964-73FCBA36F661}
 * Req.-ID: 13396047
 * ===========================================================================*/
uint32_t UssMgr_JKISS32RandAlgo(void)
{
    static sint32_t y = 234567891;
    static sint32_t z = 345678912;
    static sint32_t w = 456789123;
    static sint32_t c = 0;
    sint32_t t;
    uint32_t x = US_GetTimeStampTimeMs();

    y ^= (y << 5);
    y ^= (y >> 7);
    y ^= (y << 22);

    t = z + w + c;
    z = w;
    c = t < 0;
    w = t & 2147483647;

    x += 1411392427;
   /*KPK-QAC Fix : Need to suppress, 	Intentional implementaion */
    return ((uint32_t)x +(uint32_t) y +(uint32_t) w);
}

/* ===========================================================================
 * Name:	 aUSSMgr_Rand
 * Remarks:  DD-ID: {185F85A3-E7E1-455e-96C7-EB8124813AF0}
 * Req.-ID: 13396047
 * ===========================================================================*/
uint32_t aUSSMgr_Rand(uint32_t MaxVal)
{
    uint32_t rval;
    rval = UssMgr_JKISS32RandAlgo();
    rval = (rval % MaxVal);
    rval = rval + 1;
    return rval;
}

/* ===========================================================================
 * Name:	 UssMgr_IsSensSide
 * Remarks:  DD-ID: {2808FD8A-484F-4552-B048-4914FD0C4E91}
 * Req.-ID: 13396047
 * ===========================================================================*/
/* Got tired of doing this check manually in many places */
bool_t UssMgr_IsSensSide(uint8_t Sensor_Index)
{
    bool_t bRetVal = ME_FALSE;

    switch(Sensor_Index)
    {
        case US_D_SENSOR_FSL:
        case US_D_SENSOR_FSR:
        case US_D_SENSOR_RSL:
        case US_D_SENSOR_RSR:
            bRetVal = ME_TRUE;
            break;

        default:
            bRetVal = ME_FALSE;
            break;
    }

    return bRetVal;
}