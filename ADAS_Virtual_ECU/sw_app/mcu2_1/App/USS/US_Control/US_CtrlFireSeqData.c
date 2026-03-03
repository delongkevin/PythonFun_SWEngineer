/*
 * US_CtrlFireSeqData.c
 *
 *  Created on: Apr 14, 2021
 *      Author: jonapais
 */
#include "US_SysMgr_Global.h"
#include "US_Ctrl_Global.h"

/***** SENDING SENSOR(S) DECLARATIONS *****/

/*
 * FRONT AND REAR TOGETHER
 */
static const uint8_t sSendSnrs_FSL_RSL[TWO] = {US_D_SENSOR_FSL, US_D_SENSOR_RSL};/*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FOL_ROL[TWO] = {US_D_SENSOR_FOL, US_D_SENSOR_ROL};/*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FIL_RIL[TWO] = {US_D_SENSOR_FIL, US_D_SENSOR_RIL};/*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FIR_RIR[TWO] = {US_D_SENSOR_FIR, US_D_SENSOR_RIR};/*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FOR_ROR[TWO] = {US_D_SENSOR_FOR, US_D_SENSOR_ROR};/*QAC : 3408 need previous declaration*/ 
static const uint8_t sSendSnrs_FSR_RSR[TWO] = {US_D_SENSOR_FSR, US_D_SENSOR_RSR};/*QAC : 3408 need previous declaration*/

/*
 * FRONT ONLY
 */
static const uint8_t sSendSnrs_FSR[ONE] = {US_D_SENSOR_FSR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FOR[ONE] = {US_D_SENSOR_FOR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FIR[ONE] = {US_D_SENSOR_FIR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FIL[ONE] = {US_D_SENSOR_FIL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FOL[ONE] = {US_D_SENSOR_FOL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FSL[ONE] = {US_D_SENSOR_FSL}; /*QAC : 3408 need previous declaration*/

/*
 *
 * REAR ONLY
 */
static const uint8_t sSendSnrs_RSR[ONE] = {US_D_SENSOR_RSR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_ROR[ONE] = {US_D_SENSOR_ROR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_RIR[ONE] = {US_D_SENSOR_RIR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_RIL[ONE] = {US_D_SENSOR_RIL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_ROL[ONE] = {US_D_SENSOR_ROL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_RSL[ONE] = {US_D_SENSOR_RSL}; /*QAC : 3408 need previous declaration*/

/*
 * SIDE PANEL SENSORS
 */
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN 
const uint8_t sSendSnrs_AOL[ONE] = {US_D_SENSOR_AOL};
const uint8_t sSendSnrs_BOL[ONE] = {US_D_SENSOR_BOL};
const uint8_t sSendSnrs_AOR[ONE] = {US_D_SENSOR_AOR};
const uint8_t sSendSnrs_BOR[ONE] = {US_D_SENSOR_BOR};
#endif
/*
 * SIDES OF FRONT/REAR
 */
static const uint8_t sSendSnrs_FSR_FSL[TWO] = {US_D_SENSOR_FSR, US_D_SENSOR_FSL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_RSR_RSL[TWO] = {US_D_SENSOR_RSR, US_D_SENSOR_RSL}; /*QAC : 3408 need previous declaration*/

/*
 * FAST SCAN GROUPING
 */
static const uint8_t sSendSnrs_FOL_FSR_ROR_RSL[FOUR] = {US_D_SENSOR_FOL, US_D_SENSOR_FSR, US_D_SENSOR_ROR, US_D_SENSOR_RSL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FSL_FOR_RSR_ROL[FOUR] = {US_D_SENSOR_FSL, US_D_SENSOR_FOR, US_D_SENSOR_RSR, US_D_SENSOR_ROL}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FIL_RIR[TWO] = {US_D_SENSOR_FIL, US_D_SENSOR_RIR}; /*QAC : 3408 need previous declaration*/
static const uint8_t sSendSnrs_FIR_RIL[TWO] = {US_D_SENSOR_FIR, US_D_SENSOR_RIL}; /*QAC : 3408 need previous declaration*/
/* Front All + Rear side only grouping */
static const uint8_t sSendSnrs_FOL_FSR_RSL_RSR[FOUR] = {US_D_SENSOR_FOL, US_D_SENSOR_FSR, US_D_SENSOR_RSL, US_D_SENSOR_RSR};
static const uint8_t sSendSnrs_FSL_FOR_RSL_RSR[FOUR] = {US_D_SENSOR_FSL, US_D_SENSOR_FOR, US_D_SENSOR_RSL, US_D_SENSOR_RSR};
static const uint8_t sSendSnrs_FIL_RSL_RSR[THREE] = {US_D_SENSOR_FIL, US_D_SENSOR_RSL, US_D_SENSOR_RSR};
static const uint8_t sSendSnrs_FIR_RSL_RSR[THREE] = {US_D_SENSOR_FIR, US_D_SENSOR_RSL, US_D_SENSOR_RSR};
/* Rear All + Front side only grouping */
static const uint8_t sSendSnrs_FSL_FSR_ROR_RSL[FOUR] = {US_D_SENSOR_FSL, US_D_SENSOR_FSR, US_D_SENSOR_ROR, US_D_SENSOR_RSL};
static const uint8_t sSendSnrs_FSL_FSR_RSR_ROL[FOUR] = {US_D_SENSOR_FSL, US_D_SENSOR_FSR, US_D_SENSOR_RSR, US_D_SENSOR_ROL};
static const uint8_t sSendSnrs_FSL_FSR_RIR[THREE] = {US_D_SENSOR_FSL, US_D_SENSOR_FSR, US_D_SENSOR_RIR};
static const uint8_t sSendSnrs_FSL_FSR_RIL[THREE] = {US_D_SENSOR_FSL, US_D_SENSOR_FSR, US_D_SENSOR_RIL};

static const uint8_t sSendSnrs_ALL_FOUR_SIDES[FOUR] ={US_D_SENSOR_FSR,/*QAC : 3408 need previous declaration*/
                                               US_D_SENSOR_FSL,
                                               US_D_SENSOR_RSR,
                                               US_D_SENSOR_RSL};


static const uint8_t uRcvrSnrs_RearOnly[SIX] = {US_D_SENSOR_RSR,/*QAC : 3408 need previous declaration*/
                                         US_D_SENSOR_ROR,
                                         US_D_SENSOR_RIR,
                                         US_D_SENSOR_RIL,
                                         US_D_SENSOR_ROL,
                                         US_D_SENSOR_RSL};

static const uint8_t uRcvrSnrs_FrontOnly[SIX] = {US_D_SENSOR_FSR, /*QAC : 3408 need previous declaration*/
                                          US_D_SENSOR_FOR,
                                          US_D_SENSOR_FIR,
                                          US_D_SENSOR_FIL,
                                          US_D_SENSOR_FOL,
                                          US_D_SENSOR_FSL};

static const uint8_t sSendSnrs_FSL_FIL_FOR_RSR_RIR_ROL[SIX] =  {US_D_SENSOR_FSL, US_D_SENSOR_FIL, US_D_SENSOR_FOR, US_D_SENSOR_RSR, US_D_SENSOR_RIR, US_D_SENSOR_ROL}; /*QAC : 3408 need previous declaration*/ 
static const uint8_t sSendSnrs_FSR_FIR_FOL_RSL_RIL_ROR[SIX] =  {US_D_SENSOR_FSR, US_D_SENSOR_FIR, US_D_SENSOR_FOL, US_D_SENSOR_RSL, US_D_SENSOR_RIL, US_D_SENSOR_ROR}; /*QAC : 3408 need previous declaration*/

/***** RECEIVING SENSOR(S) DECLARATIONS *****/
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN

/*
 * FRONT AND REAR TOGETHER WITH SIDES
 */
const uint8_t sSendSnrs_FSL_RSL_AOL_AOR[FOUR] = {US_D_SENSOR_FSL, US_D_SENSOR_RSL, US_D_SENSOR_AOL, US_D_SENSOR_AOR};
const uint8_t sSendSnrs_FOL_ROL_BOL_BOL[FOUR] = {US_D_SENSOR_FOL, US_D_SENSOR_ROL, US_D_SENSOR_BOL, US_D_SENSOR_BOR};
const uint8_t sSendSnrs_FIL_RIL_AOL_AOR[FOUR] = {US_D_SENSOR_FIL, US_D_SENSOR_RIL, US_D_SENSOR_AOL, US_D_SENSOR_AOR};
const uint8_t sSendSnrs_FIR_RIR_BOL_BOL[FOUR] = {US_D_SENSOR_FIR, US_D_SENSOR_RIR, US_D_SENSOR_BOL, US_D_SENSOR_BOR};
const uint8_t sSendSnrs_FOR_ROR_AOL_AOR[FOUR] = {US_D_SENSOR_FOR, US_D_SENSOR_ROR, US_D_SENSOR_AOL, US_D_SENSOR_AOR};
const uint8_t sSendSnrs_FSR_RSR_BOL_BOL[FOUR] = {US_D_SENSOR_FSR, US_D_SENSOR_RSR, US_D_SENSOR_BOL, US_D_SENSOR_BOR};

/* SPECIAL PATTERNS FOR RIVIAN SIXTEEN SENSORS */
const uint8_t sSendSnrs_FOL_FSR_ROR_RSL[FOUR] = {US_D_SENSOR_FOL, US_D_SENSOR_FSR, US_D_SENSOR_ROR, US_D_SENSOR_RSL};
const uint8_t sSendSnrs_FSL_FOR_RSR_ROL[FOUR] = {US_D_SENSOR_FSL, US_D_SENSOR_FOR, US_D_SENSOR_RSR, US_D_SENSOR_ROL};
const uint8_t sSendSnrs_FIL_AOR_RIR_BOL[FOUR] = {US_D_SENSOR_FIL, US_D_SENSOR_AOR, US_D_SENSOR_RIR, US_D_SENSOR_BOL};
const uint8_t sSendSnrs_FIR_BOR_RIL_AOL[FOUR] = {US_D_SENSOR_FIR, US_D_SENSOR_BOR, US_D_SENSOR_RIL, US_D_SENSOR_AOL};

/* SPECIAL PATTERN FOR NFD */
const uint8_t sSendSnrs_FSL_FIL_FOR_RSR_RIR_ROL_AOR_BOL[EIGHT] = 
    {US_D_SENSOR_FSL, US_D_SENSOR_FIL, US_D_SENSOR_FOR, US_D_SENSOR_RSR, US_D_SENSOR_RIR, US_D_SENSOR_ROL, US_D_SENSOR_AOR, US_D_SENSOR_BOL};
const uint8_t sSendSnrs_FSR_FIR_FOL_RSL_RIL_ROR_AOL_BOR[EIGHT] = 
    {US_D_SENSOR_FSR, US_D_SENSOR_FIR, US_D_SENSOR_FOL, US_D_SENSOR_RSL, US_D_SENSOR_RIL, US_D_SENSOR_ROR, US_D_SENSOR_AOL, US_D_SENSOR_BOR};

/* Old fire seq.  To be deleted due to crosstalk */

/***************************************************
*\const uint8_t sSendSnrs_OL_SR_A[SIX]    = {US_D_SENSOR_FOL, US_D_SENSOR_FSR, US_D_SENSOR_ROL, US_D_SENSOR_RSR, US_D_SENSOR_AOL, US_D_SENSOR_AOR};
*\const uint8_t sSendSnrs_IL_B[FOUR]      = {US_D_SENSOR_FIL, US_D_SENSOR_RIL, US_D_SENSOR_BOL, US_D_SENSOR_BOR};
*\const uint8_t sSendSnrs_IR_A[FOUR]      = {US_D_SENSOR_FIR, US_D_SENSOR_RIR, US_D_SENSOR_AOL, US_D_SENSOR_AOR};
*\const uint8_t sSendSnrs_OR_SL_B[SIX]    = {US_D_SENSOR_FOR, US_D_SENSOR_FSL, US_D_SENSOR_ROR, US_D_SENSOR_RSL, US_D_SENSOR_BOL, US_D_SENSOR_BOR};
****************************************************/

const uint8_t uRcvrSnrs_All[SIXTEEN] = {US_D_SENSOR_RSR,
                                        US_D_SENSOR_ROR,
                                        US_D_SENSOR_RIR,
                                        US_D_SENSOR_RIL,
                                        US_D_SENSOR_ROL,
                                        US_D_SENSOR_RSL,
                                        US_D_SENSOR_FSR,
                                        US_D_SENSOR_FOR,
                                        US_D_SENSOR_FIR,
                                        US_D_SENSOR_FIL,
                                        US_D_SENSOR_FOL,
                                        US_D_SENSOR_FSL,
                                        US_D_SENSOR_AOL,
                                        US_D_SENSOR_BOL,
                                        US_D_SENSOR_AOR,
                                        US_D_SENSOR_BOR};

/* RIVIAN CUSTOM */
const uint8_t uRcvrSnrs_All_Except_IR[FOURTEEN] = {US_D_SENSOR_RSR,
                                                   US_D_SENSOR_ROR,
                                                   US_D_SENSOR_RIL,
                                                   US_D_SENSOR_ROL,
                                                   US_D_SENSOR_RSL,
                                                   US_D_SENSOR_FSR,
                                                   US_D_SENSOR_FOR,
                                                   US_D_SENSOR_FIL,
                                                   US_D_SENSOR_FOL,
                                                   US_D_SENSOR_FSL,
                                                   US_D_SENSOR_AOL,
                                                   US_D_SENSOR_BOL,
                                                   US_D_SENSOR_AOR,
                                                   US_D_SENSOR_BOR};

const uint8_t uRcvrSnrs_All_Except_SL_OR_SR[TEN]  = {US_D_SENSOR_RIR,
                                                     US_D_SENSOR_RIL,
                                                     US_D_SENSOR_ROL,
                                                     US_D_SENSOR_FIR,
                                                     US_D_SENSOR_FIL,
                                                     US_D_SENSOR_FOL,
                                                     US_D_SENSOR_AOL,
                                                     US_D_SENSOR_BOL,
                                                     US_D_SENSOR_AOR,
                                                     US_D_SENSOR_BOR};

const uint8_t uRcvrSnrs_All_Except_SL_OL_SR[TEN]  = {US_D_SENSOR_ROR,
                                                     US_D_SENSOR_RIR,
                                                     US_D_SENSOR_RIL,
                                                     US_D_SENSOR_FSR,
                                                     US_D_SENSOR_FIR,
                                                     US_D_SENSOR_FIL,
                                                     US_D_SENSOR_AOL,
                                                     US_D_SENSOR_BOL,
                                                     US_D_SENSOR_AOR,
                                                     US_D_SENSOR_BOR};

const uint8_t uRcvrSnrs_All_Except_IL[FOURTEEN]  = {US_D_SENSOR_RSR,
                                                    US_D_SENSOR_ROR,
                                                    US_D_SENSOR_RIR,
                                                    US_D_SENSOR_ROL,
                                                    US_D_SENSOR_RSL,
                                                    US_D_SENSOR_FSR,
                                                    US_D_SENSOR_FOR,
                                                    US_D_SENSOR_FIR,
                                                    US_D_SENSOR_FOL,
                                                    US_D_SENSOR_FSL,
                                                    US_D_SENSOR_AOL,
                                                    US_D_SENSOR_BOL,
                                                    US_D_SENSOR_AOR,
                                                    US_D_SENSOR_BOR};


/************* FIRE SEQ:  FRONT, SIZE, AND REAR CLUSTERS, ONE AT A TIME, 16-SENSOR ****************/
const US_S_SensorLocs_t US_SnrLocs_FrntSideRear_OneAtATime_16ST[US_SNRLOCS_SIXTEEN_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_ROR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_RIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_RIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},

    {.psSendSnrs = sSendSnrs_BOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_AOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},

    {.psSendSnrs = sSendSnrs_FSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},

    {.psSendSnrs = sSendSnrs_AOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_BOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIXTEEN}
};

/************* FIRE SEQ:  FRONT, REAR SIDES, SAME TIME ***************************/
const US_S_SensorLocs_t US_SnrLocs_FrontRearSides_SameTime[US_SNRLOCS_SIX_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSL_RSL_AOL_AOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FOL_ROL_BOL_BOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FIL_RIL_AOL_AOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FIR_RIR_BOL_BOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FOR_ROR_AOL_AOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FSR_RSR_BOL_BOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN}
};

/************* FIRE SEQ: RIVIAN 16 SENSOR - 4 STEP - FAST SCAN ***************************/
const US_S_SensorLocs_t US_SnrLocs_RivianFastScan_SameTime[US_SNRLOCS_FOUR_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSL_FOR_RSR_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FIR_BOR_RIL_AOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FIL_AOR_RIR_BOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FOL_FSR_ROR_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = SIXTEEN}
};

const US_S_SensorLocs_t US_SnrLocs_RivianNFDScan_SameTime[US_SNRLOCS_TWO_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSL_FIL_FOR_RSR_RIR_ROL_AOR_BOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = EIGHT, .uNumRcvrSnrs = SIXTEEN},
    {.psSendSnrs = sSendSnrs_FSR_FIR_FOL_RSL_RIL_ROR_AOL_BOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = EIGHT, .uNumRcvrSnrs = SIXTEEN},
};

#else
static const uint8_t uRcvrSnrs_All[TWELVE] = {US_D_SENSOR_RSR, 
                                       US_D_SENSOR_ROR,
                                       US_D_SENSOR_RIR,
                                       US_D_SENSOR_RIL,
                                       US_D_SENSOR_ROL,
                                       US_D_SENSOR_RSL,
                                       US_D_SENSOR_FSR,
                                       US_D_SENSOR_FOR,
                                       US_D_SENSOR_FIR,
                                       US_D_SENSOR_FIL,
                                       US_D_SENSOR_FOL,
                                       US_D_SENSOR_FSL};

/************* FIRE SEQ:  FRONT AND REAR CLUSTERS, ONE AT A TIME, 12-SENSOR ****************/
const US_S_SensorLocs_t US_SnrLocs_FrntRear_OneAtATime_12ST[US_SNRLOCS_TWELVE_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_ROR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_RIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_RIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE}
};

/************* FIRE SEQ:  FRONT AND REAR CLUSTERS, SAME TIME ***************************/
const US_S_SensorLocs_t US_SnrLocs_FrontAndRear_SameTime[US_SNRLOCS_SIX_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSL_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FOL_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIL_RIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIR_RIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FOR_ROR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSR_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE}
};

/************* FIRE SEQ: FRONT AND REAR CLUSTERS, - 4 STEP - FAST SCAN ***************************/
const US_S_SensorLocs_t US_SnrLocs_FastScan_SameTime[US_SNRLOCS_FOUR_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FOL_FSR_ROR_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL_FOR_RSR_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIL_RIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIR_RIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = TWO, .uNumRcvrSnrs = TWELVE}
};

/************* FIRE SEQ: FRONT AND REAR CLUSTERS, - 4 STEP - FAST SCAN - Drive Gear, Rears only side ***************************/
const US_S_SensorLocs_t US_SnrLocs_FastScan_SameTime_FrontSide_RearAll[US_SNRLOCS_FOUR_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSL_FSR_ROR_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL_FSR_RIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = THREE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL_FSR_RSR_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL_FSR_RIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = THREE, .uNumRcvrSnrs = TWELVE}
};

/************* FIRE SEQ: FRONT AND REAR CLUSTERS, - 4 STEP - FAST SCAN - Drive Gear, Rears only side ***************************/
const US_S_SensorLocs_t US_SnrLocs_FastScan_SameTime_FrontAll_RearSide[US_SNRLOCS_FOUR_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FOL_FSR_RSL_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIL_RSL_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = THREE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL_FOR_RSL_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIR_RSL_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = THREE, .uNumRcvrSnrs = TWELVE}
};

/*************  FIRE SRQ: NFD 3 sensor fire - 2 STEP - FAST SCAN ********************************/
const US_S_SensorLocs_t US_SnrLocs_NFDScan_SameTime[US_SNRLOCS_TWO_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSL_FIL_FOR_RSR_RIR_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = SIX, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSR_FIR_FOL_RSL_RIL_ROR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = SIX, .uNumRcvrSnrs = TWELVE},
};


/************* FIRE SEQ:  REAR CLUSTERS ONLY ***************************/
const US_S_SensorLocs_t US_SnrLocs_Rear_OneAtATime[US_SNRLOCS_SIX_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_RSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_ROR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_RIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_RIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_ROL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_RSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE}
};

/************* FIRE SEQ:  FRONT CLUSTERS ONLY ***************************/
const US_S_SensorLocs_t US_SnrLocs_Front_OneAtATime[US_SNRLOCS_SIX_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FOR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIR, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FIL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FOL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE},
    {.psSendSnrs = sSendSnrs_FSL, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = ONE, .uNumRcvrSnrs = TWELVE}
};

#endif

/************* FIRE SEQ:  SIDES ONLY ***************************/
const US_S_SensorLocs_t US_SnrLocs_FrontSidesOnly_OneAtATime[US_SNRLOCS_TWO_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSR, .puRcvrSnrs = uRcvrSnrs_FrontOnly, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIX},
    {.psSendSnrs = sSendSnrs_FSL, .puRcvrSnrs = uRcvrSnrs_FrontOnly, .uNumSendSnrs = ONE, .uNumRcvrSnrs = SIX}
};

const US_S_SensorLocs_t US_SnrLocs_FrontSidesOnly_SameTime[US_SNRLOCS_ONE_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_FSR_FSL, .puRcvrSnrs = uRcvrSnrs_FrontOnly, .uNumSendSnrs = TWO, .uNumRcvrSnrs = SIX}
};

const US_S_SensorLocs_t US_SnrLocs_RearSidesOnly_SameTime[US_SNRLOCS_ONE_STEP_SEQ_LEN] = 
{
    {.psSendSnrs = sSendSnrs_RSR_RSL, .puRcvrSnrs = uRcvrSnrs_RearOnly, .uNumSendSnrs = TWO, .uNumRcvrSnrs = SIX}
};

const US_S_SensorLocs_t US_SnrLocs_AllSidesOnly_SameTime[US_SNRLOCS_ONE_STEP_SEQ_LEN] =
{
    {.psSendSnrs = sSendSnrs_ALL_FOUR_SIDES, .puRcvrSnrs = uRcvrSnrs_All, .uNumSendSnrs = FOUR, .uNumRcvrSnrs = TWELVE}
};

const US_S_BurstConfig_t US_BrstCfg_Front_Rear_Fixed =
{
    .uNumPDCM       = 12u,
    .SnrType        = ZERO, /*TBD Future */
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t) ME_FALSE,
        .Update                 = (uint8_t)US_E_UPDATE,
	    .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_FIXPATH,
        .CompGain               = (sint8_t)ZERO,
        .MeasurementTime        = 30u,      /*343 m/s * 30 ms = 10.29 m (out and back) */
        .PreburstNoiseChkTime   = TWO,      /*2 * 300 us = 0.60 ms */
        .G_digBoost = THREE
    }
};

const US_S_BurstConfig_t US_BrstCfg_NFD =
{
    .uNumPDCM       = 4u,
    .SnrType        = ZERO, /*TBD Future */
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t)ME_TRUE,
        .Update                 = (uint8_t)US_E_UPDATE,
        .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_FIXPATH,
        .CompGain               = (sint8_t)ZERO,
        .MeasurementTime        = 6u,       /*343 m/s * 6 ms = 1.029 m  (out and back) */
        .PreburstNoiseChkTime   = TWO,      /*2 * 300 us = 0.60 ms */
        .G_digBoost = THREE
    }
};

const US_S_BurstConfig_t US_BrstCfg_Chirp_Down =
{
    .uNumPDCM       = 12u,
    .SnrType        = ZERO, /*not used - for different sensor ASICs */
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t)ME_FALSE,
	    .Update                 = (uint8_t)US_E_UPDATE, /*yes - for new profile change */
        .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_COMBINEPATH_FIL1, /*US_E_FILTERPATH_FIL1, chirp down */
        .CompGain               = (sint8_t) ZERO,
        .MeasurementTime        = 30u,
        .PreburstNoiseChkTime   = TWO,      /*2 * 300 us = 0.60 ms */
        .G_digBoost = THREE
    }
};

const US_S_BurstConfig_t US_BrstCfg_Chirp_Down_Strict =
{
    .uNumPDCM       = 12u,  /*doesn't change with chirp? */
    .SnrType        = ZERO, /*not used - for different sensor ASICs */
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t) ME_FALSE,
        .Update                 = (uint8_t)US_E_UPDATE, /*yes - for new profile change */
        .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_FILTERPATH_FIL1, /*chirp down */
        .CompGain               = (sint8_t)ZERO,
        .MeasurementTime        = 30u,
        .PreburstNoiseChkTime   = TWO,      /*2 * 300 us = 0.60 ms */
        .G_digBoost = THREE
    }
};

const US_S_BurstConfig_t US_BrstCfg_Chirp_Up =
{
    .uNumPDCM       = 12u,  /*doesn't change with chirp? */
    .SnrType        = ZERO, /*not used - for different sensor ASICs */
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t) ME_FALSE,
        .Update                 = (uint8_t)US_E_UPDATE, /*yes - for new profile change */
        .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_COMBINEPATH_FIL2, /*US_E_FILTERPATH_FIL1, chirp down */
        .CompGain               = (sint8_t)ZERO,
        .MeasurementTime        = 30u,
        .PreburstNoiseChkTime   = TWO,      /*2 * 300 us = 0.60 ms */
        .G_digBoost = THREE
    }
};

const US_S_BurstConfig_t US_BrstCfg_Chirp_Up_Strict =
{
    .uNumPDCM       = 12u,  //doesn't change with chirp?
    .SnrType        = ZERO, //not used - for different sensor ASICs
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t)ME_FALSE,
        .Update                 = (uint8_t)US_E_UPDATE, //yes - for new profile change
        .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_FILTERPATH_FIL2, //chirp up
        .CompGain               = (sint8_t)ZERO,
        .MeasurementTime        = 30u,
        .PreburstNoiseChkTime   = TWO,      // 2 * 300 us = 0.60 ms
        .G_digBoost = THREE
    }
};

const US_S_BurstConfig_t US_BrstCfg_Chirp_Both =
{
    .uNumPDCM       = 12u,  //doesn't change with chirp?
    .SnrType        = ZERO, //not used - for different sensor ASICs
    .sSnrCfg        =
    {
        .IsCalibration          = (uint8_t)ME_FALSE,
        .IsNFDMode              = (uint8_t)ME_FALSE,
        .Update                 = (uint8_t)US_E_UPDATE, //yes - for new profile change
        .EnvOutput              = (uint8_t)US_E_ENVOUTDIS,
        .EchoInfo               = (uint8_t)US_E_FILTERPATH, //read both chirps
        .CompGain               = (sint8_t)ZERO,
        .MeasurementTime        = 30u,
        .PreburstNoiseChkTime   = TWO,      // 2 * 300 us = 0.60 ms
        .G_digBoost = THREE
    }
};

