/*
 * US_MgrDataSim.c
 *
 *  Created on: Apr 4, 2022
 *      Author: jonapais
 */

#include "US_PlatformCfg_Global.h"

#if US_D_SIMULATION_ACTIVE == ME_TRUE

#include "US_SnrData_Typedefs_Global.h"
#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_ObjDet_Global.h"
#include "US_SysMgr_Global.h"

#include "US_SnrCfg_Global.h"
#include "US_MgrUtility.h"

#include "US_MgrDataSim.h"



int16_t iSimPntMinX =  -150;
int16_t iSimPntMinY =  -150;

int16_t iSimPntMaxX =  600;
int16_t iSimPntMaxY =  150;

int16_t iSimPntX =  650;
int16_t iSimPntY =  150;

uint16_t uSimCnt = 0;

#define US_D_DELTA_MOVMENT (5u)
int8_t iDirX = -US_D_DELTA_MOVMENT;
int8_t iDirY = 0;

/* ===========================================================================
 * Name:	 UssMgr_CreateSimulationMeas
 * Remarks:  DD-ID: {84DC6F86-B9E5-4f08-806C-46BA1CCCB8D2}
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
void UssMgr_CreateSimulationMeas(void)
{
    uint8_t  uGrpIdx;

    const US_S_IndirSnrIdxList_t * psIndirSnrList;
    const US_S_SnrAngleCalcs_t * psSnrAngleCalcs = UssOD_psGetSnrAngleCalcs(); /* Get angle calculations */

    //US_S_ObjDetCalcRec_t * psGetObjDetCalcRec =  UssOD_psGetObjDetCalcs();
    uint8_t uIndirSnrListIdx;
    uint8_t uDirSnrGrpIdx;
    uint8_t uSnrDirDataIdx;
    uint8_t uIndirSnrDataIdx;
//    uint8_t uDirEchoIdx;
    uint8_t uNumSnrsInGrp;
//    bool_t  bIsLeftIndir;

    float32_t fDeltaX;          // Distance between X's
    float32_t fDeltaY;          // Distance between Y's
    float32_t fDirDist;
    float32_t fIndirDist;
    float32_t fPntAng;
    float32_t fSnrAng;
    float32_t fMaxFovAng;
    float32_t fMinFovAng;

    US_S_SnrCalcs_t * psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();  // This is where the simulation modifies data to simulate echoes.
    const uint8_t * uSnrType = UssCtrl_psGetSensorType();
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    const US_S_SensorsCfg_t *pSnrCfg  = NULL;
    const US_S_Sensor_coordinate_t * pSnrCoord = NULL;

     /* Get the address of Sensor Coordinate from Calibration data */
    pSnrCfg = US_SnrCfg_F_Get_SnrCfg();
    pSnrCoord = pSnrCfg->pSnrCoordinate;

    if(pSnrCoord == NULL)      // Check if data exists
    {
        return;
    }

    uSimCnt++;
    if (uSimCnt > 8)
    {
        iSimPntX += iDirX;
        iSimPntY += iDirY;

        if (iSimPntX < iSimPntMinX)
        {
            iSimPntX = iSimPntMinX;
            iDirX = 0;
            iDirY = -US_D_DELTA_MOVMENT;

        }

        if (iSimPntY < iSimPntMinY)
        {
            iSimPntY =  iSimPntMinY;
            iDirX = US_D_DELTA_MOVMENT;
            iDirY = 0;
        }


        if (iSimPntX > iSimPntMaxX)
        {
            iSimPntX = iSimPntMaxX;
            iDirX = 0;
            iDirY = US_D_DELTA_MOVMENT;

        }

        if (iSimPntY > iSimPntMaxY)
        {
            iSimPntY = iSimPntMaxY;
            iDirX = -US_D_DELTA_MOVMENT;
            iDirY = 0;

            iSimPntMaxY += 50;
            iSimPntMaxX += 50;
            iSimPntMinY -= 50;
            iSimPntMinX -= 50;

        }

        uSimCnt = 0;
    }


    /* Perform OD Simulator for each sensor physical group */
    for (uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
    {

        uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

        /*
         * Clear echo data for each sensor in the group.
         */
        for (uDirSnrGrpIdx = ZERO; uDirSnrGrpIdx < uNumSnrsInGrp; uDirSnrGrpIdx++)
        {
            // Retrieve the index to the sensor, from the physical group data
            uSnrDirDataIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uDirSnrGrpIdx];

            psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ZERO].uDirectDist_cm = ZERO;
            psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ZERO].uTotalDist_cm = ZERO;
            psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ONE].uDirectDist_cm = ZERO;
            psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ONE].uTotalDist_cm = ZERO;
            psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].uNumEchoes = ZERO;
        }

        

        /*
         * Perform for each sensor in group, with associated indirect sensors.
         */
        for (uDirSnrGrpIdx = ZERO; uDirSnrGrpIdx < uNumSnrsInGrp; uDirSnrGrpIdx++)
        {
            // Retrieve the index to the sensor, from the physical group data
            uSnrDirDataIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uDirSnrGrpIdx];


            /* Get classification for this direct sensor */
            if (psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].eEchoClass == US_E_DIRECT)    // Check if sending sensor (Direct Echo)
            {
                /* Calculate distance between sensor and point */
                fDeltaX = iSimPntX - pSnrCoord[uSnrDirDataIdx].fX;
                fDeltaY = iSimPntY - pSnrCoord[uSnrDirDataIdx].fY;
                fDirDist = sqrtf(fDeltaX * fDeltaX + fDeltaY * fDeltaY);

                fSnrAng = psSnrAngleCalcs->fSnrAngInVehCoords_rad[uSnrDirDataIdx]; // Angle of sensor in vehicle coord system.

                // Direct FOV Calc - Direct is defines left FOV because Direct is always Left of Indirect
                if (uSnrType[uSnrDirDataIdx] == SNR_TYPE_PDC)
                {
                    fMaxFovAng = SNR_PDC_FOV_2_RAD;
                    fMinFovAng = -SNR_PDC_FOV_2_RAD;
                }
                else
                {
                    fMaxFovAng  = SNR_PSM_FOV_2_RAD;
                    fMinFovAng = -SNR_PSM_FOV_2_RAD;
                }

                if (fSnrAng < 0.0f)
                {
                    fSnrAng += 2.0f * M_PI;
                }
                fPntAng = atan2f(fDeltaY, fDeltaX);
                fPntAng -= fSnrAng;

                if (fPntAng > M_PI)
                {
                    fPntAng -= 2.0f * M_PI;
                }
                else if (fPntAng < -M_PI)
                {
                    fPntAng += 2.0f * M_PI;
                }

                if (uSnrDirDataIdx == US_D_SENSOR_FSL)
                {
                    uSnrDirDataIdx = US_D_SENSOR_FSL;
                }

                if (fPntAng < fMinFovAng || fPntAng > fMaxFovAng) continue;

                psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ZERO].uDirectDist_cm = fDirDist;

                psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ZERO].uTotalDist_cm = ZERO;
                psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ZERO].uSignalStrength = 100u;
                psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].sEchoCalc[ZERO].uTOF_us = ZERO;
                psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].eEchoType = US_E_FIXED;

                psSnrCalcs->sSnrCalcRec[uSnrDirDataIdx].uNumEchoes = ONE;

                psIndirSnrList = UssOD_psGetIndirSnrList(uGrpIdx, uDirSnrGrpIdx);

                // Try to triangulate the direct echos with the closest indirect echoes.
                for (uIndirSnrListIdx = ZERO; uIndirSnrListIdx < TWO; uIndirSnrListIdx++)
                {
                    uIndirSnrDataIdx = psIndirSnrList[uIndirSnrListIdx].uIndirSnrDataIdx;

                    if (uIndirSnrDataIdx != US_D_OD_NO_INDIR_SNR)
                    {
                        fSnrAng = psSnrAngleCalcs->fSnrAngInVehCoords_rad[uIndirSnrDataIdx]; // Angle of sensor in vehicle coord system.

                        // Direct FOV Calc - Direct is defines left FOV because Direct is always Left of Indirect
                        if (uSnrType[uIndirSnrDataIdx] == SNR_TYPE_PDC)
                        {
                            fMaxFovAng = SNR_PDC_FOV_2_RAD;
                            fMinFovAng = -SNR_PDC_FOV_2_RAD;
                        }
                        else
                        {
                            fMaxFovAng  = SNR_PSM_FOV_2_RAD;
                            fMinFovAng = -SNR_PSM_FOV_2_RAD;
                        }

                        if (fSnrAng < 0.0f)
                        {
                            fSnrAng += 2.0f * M_PI;
                        }

                        /* Calculate distance between sensor and point */
                        fDeltaX = iSimPntX - pSnrCoord[uIndirSnrDataIdx].fX;
                        fDeltaY = iSimPntY - pSnrCoord[uIndirSnrDataIdx].fY;
                        fIndirDist = sqrtf(fDeltaX * fDeltaX + fDeltaY * fDeltaY);

                        fPntAng = atan2f(fDeltaY, fDeltaX);
                        fPntAng -= fSnrAng;

                        if (fPntAng > M_PI)
                        {
                            fPntAng -= 2.0f * M_PI;
                        }
                        else if (fPntAng < -M_PI)
                        {
                            fPntAng += 2.0f * M_PI;
                        }

                        if (uIndirSnrDataIdx == US_D_SENSOR_FSL)
                        {
                            uIndirSnrDataIdx = US_D_SENSOR_FSL;
                        }

                        if (fPntAng < fMinFovAng || fPntAng > fMaxFovAng) continue;

                        psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].sEchoCalc[ZERO].uDirectDist_cm = ZERO;
                        psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].sEchoCalc[ZERO].uTotalDist_cm = fDirDist + fIndirDist;
                        psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].sEchoCalc[ZERO].uSignalStrength = 100u;
                        psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].sEchoCalc[ZERO].uTOF_us = ZERO;
                        psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].eEchoType = US_E_FIXED;


                        psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].uNumEchoes = ONE;
                    }
                }
            }
        }
    }
}

/*
 * Pseudocode:
 *
 * For this sensor set num echos = 0;
 * loop though each sensor in group, only do group front at the moment
 * for each sensor find closest point adn 2nd closest point, since there is only one
 * right now, we already know the answer to this
 * set dir2 = 0
 * set direct one to this dist
 * look up left indirect and set indirect dist, look up right sensor and set indirect dist
 * set num echos = 1
 * set sig strength = 100;
 */

#if 0
/* Get number of direct and indirect echoes */
uint8_t uNumDirEchoes = psSnrCalcs->sSnrCalcRec[uDirSnrDataIdx].uNumEchoes;
uint8_t uNumIndirEchoes = psSnrCalcs->sSnrCalcRec[uIndirSnrDataIdx].uNumEchoes;

/* Limit to OD max echos to be considered */
uNumDirEchoes = (uNumDirEchoes <= US_D_OD_MAX_ECHOS_FOR_TRIANG) ? uNumDirEchoes : US_D_OD_MAX_ECHOS_FOR_TRIANG;
uNumIndirEchoes = (uNumIndirEchoes <= US_D_OD_MAX_ECHOS_FOR_TRIANG) ? uNumIndirEchoes : US_D_OD_MAX_ECHOS_FOR_TRIANG;

/* Perform comparison between each direct echo with indirect echoes. */
for (uDirEchoIdx = 0; uDirEchoIdx < uNumDirEchoes; uDirEchoIdx++)
{
    /* Get direct echo distance and cross sectional acoustical strength approximation */
    uDirDist = psSnrCalcs->sSnrCalcRec[uDirSnrDataIdx].sEchoCalc[uDirEchoIdx].uDirectDist_cm;
    uSigStrength = psSnrCalcs->sSnrCalcRec[uDirSnrDataIdx].sEchoCalc[uDirEchoIdx].uSignalStrength;

#endif

#endif
