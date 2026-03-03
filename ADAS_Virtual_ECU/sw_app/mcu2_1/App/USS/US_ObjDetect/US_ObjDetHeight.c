/*
 * US_ObjDetHeight.c
 *
 *  Created on: Nov 28, 2023
 *      Author: jwr3 & Jason Zalev
 */

/*PRQA S 0816 ++ */
/*PRQA S 1011, 0857 ++ */
/* PRQA S 0292 ++ */ /*Special characters in comments have no functional impact */

/* Needed for #def settings */
#include "US_PlatformCfg_Global.h"
/* TODO consider clean up */

/* Skip this entire file if the height geom isn't defined */
#ifdef US_D_OD_HEIGHT_GEOM_STATS

/* It's own header, for functions being shared with other OD files */
#include "US_ObjDetHeight.h"
/* Needed for calculations */
#include <math.h>
#include "US_Platform_Global.h"
/* Needed for 2D points lists */
#include "US_ObjDetTriang.h"
/* Needed for sensor position info */
#include "US_SnrCfg_Global.h"
/* Needed for height result flag to user & debug outputs*/
#include "US_ObjDet_Global.h"
/* Needed for vehicle input signals */
#include "US_ComInputBuffer_Global.h"

#if (US_D_LAUTERBACH_DEBUG_VARS == ME_TRUE)
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
        static volatile uint8_t g_LAUD_UseWallFlag = ZERO; /* to use wall extractor in decision logic within UssOD_bIsLowObject() */
        #define US_DD_ODH_UseWallFlag   g_LAUD_UseWallFlag
    #endif
    static volatile uint8_t g_LAUD_UsePoleFlag = ZERO; /* to use pole extractor in decision logic within UssOD_bIsLowObject() */
    #define US_DD_ODH_UsePoleFlag   g_LAUD_UsePoleFlag
    static volatile uint8_t g_LAUD_UseDNNFlag = ONE;   /* to DNN in decision logic within UssOD_bIsLowObject() */
    #define US_DD_ODH_UseDNNFlag   g_LAUD_UseDNNFlag

    static volatile US_E_RAEB_Height_Decisions_t g_LAUD_UseGlobHeightForRAEB = 2u;  /* use global height result for RAEB (instead of old logic) */
    #define US_DD_ODH_UseGlobHeightForRAEB   g_LAUD_UseGlobHeightForRAEB
    static volatile uint8_t g_LAUD_EnablePoleExt = ME_TRUE;    /* enabled 2D point height flags written by pole extractor */
    #define US_DD_ODH_EnablePoleExt   g_LAUD_EnablePoleExt
#else
    #define US_DD_ODH_UseWallFlag   ZERO
    #define US_DD_ODH_UsePoleFlag   ZERO
    #define US_DD_ODH_UseDNNFlag    ONE
    #define US_DD_ODH_UseGlobHeightForRAEB  (2u)
    #define US_DD_ODH_EnablePoleExt         ME_TRUE
#endif /* US_D_LAUTERBACH_DEBUG_VARS being ME_TRUE */
/* parameters for height geometry stats estimation */
#define US_D_OD_HEIGHT_GEOM_N_BINS  (5u) //use 5 bins.
#define US_D_OD_HEIGHT_COLLECT_STATS 0 //don't collect stats for now.
#define US_D_OD_HEIGHT_GEOM_LATCH_USE_SPD_DIST ME_FALSE
#define US_D_OD_HEIGHT_GEOM_LATCH_USE__SPD___TIME ME_FALSE
/* threshold that average heightFlag must exceed to be marked high (percentage of points in window) */
//  for example, setting to 0.65f means if at least 35% of points are low it can be marked low.
#define US_D_OD_HEIGHT_GEOM_MEAN_THRESH 0.80f   /*Changed from 0.65 to 0.8 on 27th Dec 2024*/

#define US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS
#ifdef US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS
    #define US_D_OD_HEIGHT_GEOM_SPEED_COMP_FACTOR   (10.0f)
    #define US_D_OD_HEIGHT_GEOM_LATCH_TIME_MS   (2000u)
    #define US_D_OD_HEIGHT_GEOM_LATCH_BASE_DIST   (200.0f)
    #define US_D_OD_HEIGHT_GEOM_RESET_LATCH     (ME_TRUE)
    #if (US_D_OD_HEIGHT_GEOM_RESET_LATCH == ME_TRUE)
        #define US_D_OD_HEIGHT_GRL_COLLECT_DIST    (350.0f)
        #define US_D_OD_HEIGHT_GRL_DESI_DIST_MIN_ADD (45.0f) /* Slow speeds, don't wait until the last min to latch */
        #define US_D_OD_HEIGHT_GRL_RATIO    (2.2f)
        #define US_D_OD_HEIGHT_GRL_MAX_AGE   (80u)
        #define US_D_OD_HEIGHT_GRL_MIN_CR    (45u)
        #define US_D_OD_HEIGHT_GRL_AGECR_OFFSET (5u)
        #define US_D_OD_HEIGHT_GRL_SKIP_LONES
        #define US_D_OD_HEIGHT_GEOM_GRL_PERCENTAGE  (2.0f)
        #define US_D_OD_HEIGHT_GRL_HIGH_OBJ_MIN_CR  (11u)
        #define US_D_OD_HEIGHT_COMPENSATE_NOISE_TRIANG
    #endif
    #define US_D_OD_HEIGHT_GEOM_LATCH_SUSTAIN_FLOOR_DIST_ADD    (10.0f) /* avoid trying to brake when close to DTC */
#endif

#define US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
#define US_D_OD_HEIGHT_NOTNEAR_ML
#ifdef  US_D_OD_HEIGHT_NOTNEAR_ML
#define US_D_OD_HEIGHT_NOTNEAR_LOW   0u
#define US_D_OD_HEIGHT_NOTNEAR_HIGH  1u
#define US_D_OD_HEIGHT_NOTNEAR_UNDEF 2u
#define US_D_OD_HEIGHT_NOTNEAR_DIST  50.0f //distance to use old ML decision if exists. 

#endif

    #define US_E_HDECIDE_NONE 0
    #define US_E_HDECIDE_FUNC 1
    #define US_E_HDECIDE_ALL_SAFE 2
    #define US_E_HDECIDE_WALL_POLE 3
    #define US_E_HDECIDE_ALL 4
    #define US_E_HDECIDE_OG_ALL_SAFE 5
    #define US_E_HDECIDE_OG_ONLY 6


/* Final result flag */
static bool_t abIsHighObject[US_D_PHYS_GRP_MAX];
static uint8_t uRearCenterPoleDecision = ME_FALSE; /* Make it true when High height is written in 2D Point*/
#ifdef US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS

static bool_t bWideLatchActive = ME_FALSE;
#endif
#ifdef US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
static uint16_t auBinHist[US_D_OD_HEIGHT_GEOM_N_BINS]={0};
#endif
#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH
static uint16_t auBinCounter[US_D_OD_HEIGHT_GEOM_N_BINS] ={0}; //bin counter is a 2D array (for front and rear). 
static uint16_t auBinMaxAge[US_D_OD_HEIGHT_GEOM_N_BINS]={0};
static bool_t bResetLatch = ME_FALSE;
static float32_t g_fCruiseBinRatio = 0.0f;
static uint16_t g_uLastNewObservationCounter = 0u;
static uint16_t g_uNewObsCounter2 = 0u;
#endif

#if (US_D_ENABLE_OVRWR_CANDBG == ME_TRUE)
uint8_t g_uArcsFromFeature[SIX];
#endif /* US_D_ENABLE_OVRWR_CANDBG */
#ifdef US_D_OD_HGEOM_COMPUTE_GRPHEIGHT


#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE)
static float32_t g_DEBUG_fPointDistToBumper = 0.0f;
#if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
static bool_t g_abBinNotEmpty[US_D_OD_HEIGHT_GEOM_N_BINS]={0}; //initialize ALL elements to zero, 0=Empty, 1=full.
static bool_t g_bIsHighObject = ME_TRUE;
static bool_t g_bIsCurbWall = ME_FALSE;
static uint8_t g_uValidPoints = ZERO; //number of points in first pass.
static uint8_t g_uPointsInWindow = ZERO; //number of points in second pass.
static float32_t g_DEBUG_fLatchDist = 0.0f;
static float32_t g_DEBUG_fClosestX_fresh = -1e6f;
static uint8_t g_DEBUG_bmapBinAccu = 0x00u;
static uint8_t g_DEBUG_HighGuess = 0x00u;
static uint32_t g_DEBUG_AdjLatchMaxAge = 0x00;
static uint32_t g_DEBUG_uLatchDecisions = 0x00;
static uint32_t g_DEBUG_AdjLatchMinCr = 0x00;
static uint32_t g_DEBUG_LatchPassMap = 0x00;
static uint16_t g_DEBUG_LoneCrZero = 0x00;
static float32_t g_DEBUG_fUnlatchDist = 0.0f;
static float32_t g_DEBUG_fMinUnlatchDist = 0.0f;

static float32_t g_fMeanHeight = 0.0f;
static float32_t g_fClosestX = -1e6f; //set to far away in negative land.
US_D_DBG_QUAL uint8_t   g_fGeomStats_ConfThresh_DEBUG[US_D_PHYS_GRP_MAX];
#endif
#if 0
static uint8_t g_InPass1, g_InPass2, g_InPass3;
#endif
#endif /* under US_D_OD_HEIGHT_GEOM_DEBUG */

#if (US_D_LAUTERBACH_DEBUG_VARS == ME_TRUE)
static US_D_LAUD_QUAL float32_t g_fAdjustedMinCrFactor = 1.4f; 
static US_D_LAUD_QUAL float32_t US_D_OD_HGEOM_DST_BUMP_TH_OFST_NOISE = 30.0f;
static US_D_LAUD_QUAL float32_t g_PoleExtrct_DistBumpOfst = 30.0f;
static US_D_LAUD_QUAL float32_t US_D_OD_HGEOM_DST_BUMP_TH_REAR_NOISE = 150.0f;
static US_D_LAUD_QUAL float32_t US_D_OD_HGEOM_DST_BUMP_TH_FRNT_NOISE = 120.0f;
static US_D_LAUD_QUAL uint8_t US_D_OD_HGEOM_BINCNTTHRESH_FRNT_NOISE = 3u;
static US_D_LAUD_QUAL uint8_t US_D_OD_HGEOM_BINCNTTHRESH_REAR_NOISE = 3u;
static US_D_LAUD_QUAL uint8_t US_D_OD_HGEOM_BINCNTTHRESH_OFST_NOISE = 3u;
static US_D_LAUD_QUAL float32_t g_PoleExtrct_DistBumpFrnt = 130.0f;
static US_D_LAUD_QUAL float32_t g_PoleExtrct_DistBumpRear = 175.0f;
static US_D_LAUD_QUAL uint8_t g_PoleExtrct_BinCntFrnt = 4u;
static US_D_LAUD_QUAL uint8_t g_PoleExtrct_BinCntRear = 4u;
static US_D_LAUD_QUAL uint8_t g_PoleExtrct_BinCntOfst = 3u;
static US_D_LAUD_QUAL uint8_t g_PoleExtract_BinCntNoiHspd = 1u;
static US_D_LAUD_QUAL uint8_t g_PoleExtrctCrusingAgeThsd = 6u; /* Pole extractor threshold for Cruising Age*/
static US_D_LAUD_QUAL uint16_t g_uLatchTimeMs = US_D_OD_HEIGHT_GEOM_LATCH_TIME_MS;
static US_D_LAUD_QUAL float32_t g_fLatchBaseDist = US_D_OD_HEIGHT_GEOM_LATCH_BASE_DIST;
static US_D_LAUD_QUAL float32_t g_fResetLatchDist = US_D_OD_HEIGHT_GRL_COLLECT_DIST;
static US_D_LAUD_QUAL float32_t g_fResetLatchRatio = US_D_OD_HEIGHT_GRL_RATIO;
static US_D_LAUD_QUAL uint8_t g_uResetLatchMaxAge = US_D_OD_HEIGHT_GRL_MAX_AGE;
static US_D_LAUD_QUAL float32_t g_fLatchSustainAdd = US_D_OD_HEIGHT_GEOM_LATCH_SUSTAIN_FLOOR_DIST_ADD;
static US_D_LAUD_QUAL float32_t g_fMinLatchResetAdd = US_D_OD_HEIGHT_GRL_DESI_DIST_MIN_ADD;
static US_D_LAUD_QUAL uint16_t g_uMinCruisingCnt = US_D_OD_HEIGHT_GRL_MIN_CR;
static US_D_LAUD_QUAL uint16_t g_uResetLatchAgeAndCr_Offset = US_D_OD_HEIGHT_GRL_AGECR_OFFSET;
static US_D_LAUD_QUAL float32_t g_fUnlatchDistPercentage = US_D_OD_HEIGHT_GEOM_GRL_PERCENTAGE;
static US_D_LAUD_QUAL uint16_t g_uNewObsCounter2_thresh = 3u; //this counter must exceed 3u to unlatch. 
static US_D_LAUD_QUAL float32_t g_fNewObsCounter2_XMin = 100.0f; 
static US_D_LAUD_QUAL float32_t g_fNewObsCounter2_XMax = 200.0f; 
static US_D_LAUD_QUAL float32_t g_fLastObservationThresh = 100.0f;
static US_D_LAUD_QUAL uint8_t g_uConfThresh = 90u;
static US_D_LAUD_QUAL uint16_t g_uObsCountThresh = 5u;
static US_D_LAUD_QUAL float32_t g_fHighRatioThresh = 3.0f;
static US_D_LAUD_QUAL float32_t g_NoiseCompensationDist = 12.0f;

#else  
#define g_fAdjustedMinCrFactor  (1.4f)

#define g_PoleExtrctCrusingAgeThsd    (6u) /* Pole extractor threshold for Cruising Age*/
#define g_uLatchTimeMs                (US_D_OD_HEIGHT_GEOM_LATCH_TIME_MS)
#define g_fLatchBaseDist              (US_D_OD_HEIGHT_GEOM_LATCH_BASE_DIST)
#define g_fResetLatchDist             (US_D_OD_HEIGHT_GRL_COLLECT_DIST)
#define g_fResetLatchRatio            (US_D_OD_HEIGHT_GRL_RATIO)
#define g_uResetLatchMaxAge           (US_D_OD_HEIGHT_GRL_MAX_AGE)
#define g_fLatchSustainAdd            (US_D_OD_HEIGHT_GEOM_LATCH_SUSTAIN_FLOOR_DIST_ADD)
#define g_fMinLatchResetAdd           (US_D_OD_HEIGHT_GRL_DESI_DIST_MIN_ADD)
#define g_uMinCruisingCnt             (US_D_OD_HEIGHT_GRL_MIN_CR)
#define g_uResetLatchAgeAndCr_Offset  (US_D_OD_HEIGHT_GRL_AGECR_OFFSET)
#define g_fUnlatchDistPercentage      (US_D_OD_HEIGHT_GEOM_GRL_PERCENTAGE)
#define g_uNewObsCounter2_thresh      (3u) //this counter must exceed 3u to unlatch. 
#define g_fNewObsCounter2_XMin        (100.0f)
#define g_fNewObsCounter2_XMax        (200.0f)
#define g_fLastObservationThresh      (100.0f)
#define g_uConfThresh                 (90u)
#define g_uObsCountThresh             (5u)
#define g_fHighRatioThresh            (3.0f)
#define g_NoiseCompensationDist       (12.0f)

#if 0 /* old config, no longer used. Keep for a bit */
static US_D_LAUD_QUAL uint8_t g_uThreshold_2kph = 60;
static US_D_LAUD_QUAL uint8_t g_uThreshold_4kph = 30;
static US_D_LAUD_QUAL uint8_t g_uThreshold_6kph = 25;
static US_D_LAUD_QUAL uint8_t g_uThreshold_8kph = 20;
static US_D_LAUD_QUAL uint32_t g_AdjLatchMinCrOffset = 5u;
static US_D_LAUD_QUAL uint8_t g_uHeightGrlHighObjMinCr = US_D_OD_HEIGHT_GRL_HIGH_OBJ_MIN_CR;
#endif

#endif/*(US_D_LAUTERBACH_DEBUG_VARS )*/
#endif
#define US_D_OD_HGEOM_COMPUTE_SIGMA
#ifdef US_D_OD_HGEOM_COMPUTE_SIGMA

#define US_D_OD_HGEOM_MU_INVALID 1e6f 

#define US_D_OD_HGEOM_RHO_DEFAULT 0.10f
#define US_D_OD_HGEOM_RHO_NOISE 0.15f
#define US_D_OD_HGEOM_SIGMAYTHRESH_DEFAULT 27.0f


/*
g_fMinXDist:  = Rear = 240, Front = 200, Offset = 100 
g_fMaxXDist:  = Rear = 10, Front = 10, Offset = 10
DistToBumperThresh:       = Rear = 150, Front = 70, Offset = 30
BinCounterThresh:            = Rear = 4, Front = 4, Offset = 3
*/

/////// 1234567890123456789012345678901
#define US_D_OD_HGEOM_MINXDIST_DEF_FRNT    (200.0f)
#define US_D_OD_HGEOM_MINXDIST_DEF_REAR    (240.0f)
#define US_D_OD_HGEOM_MINXDIST_DEF_OFST    (100.0f) 

#define US_D_OD_HGEOM_MAXXDIST_DEF_FRNT    (10.0f)
#define US_D_OD_HGEOM_MAXXDIST_DEF_REAR    (10.0f)
#define US_D_OD_HGEOM_MAXXDIST_DEF_OFST    (10.0f)

#define US_D_OD_HGEOM_BINCNTTHRESH_FRNT       (5u)
#define US_D_OD_HGEOM_BINCNTTHRESH_REAR       (5u)
#define US_D_OD_HGEOM_BINCNTTHRESH_OFST       (3u)
//after testing make it MACRO
uint8_t g_PoleExtrct_BinCntFrnt = 4u;
uint8_t g_PoleExtrct_BinCntRear = 4u;
uint8_t g_PoleExtrct_BinCntOfst = 3u;
uint8_t g_PoleExtract_BinCntNoiHspd = 2u;
uint8_t US_D_OD_HGEOM_BINCNTTHRESH_FRNT_NOISE = 3u;
uint8_t US_D_OD_HGEOM_BINCNTTHRESH_REAR_NOISE = 4u;
uint8_t US_D_OD_HGEOM_BINCNTTHRESH_OFST_NOISE = 3u;

#define US_D_OD_HGEOM_DST_BUMP_TH_FRNT    (130.0f) 
#define US_D_OD_HGEOM_DST_BUMP_TH_REAR    (175.0f)
//after testing make it MACRO
float32_t g_PoleExtrct_DistBumpFrnt = 130.0f;
float32_t g_PoleExtrct_DistBumpRear = 175.0f;
float32_t US_D_OD_HGEOM_DST_BUMP_TH_FRNT_NOISE = 120.0f;
float32_t US_D_OD_HGEOM_DST_BUMP_TH_REAR_NOISE = 150.0f;
#define US_D_OD_HGEOM_DST_BUMP_TH_OFST     (30.0f)
//after testing make it MACRO
float32_t g_PoleExtrct_DistBumpOfst = 30.0f;
float32_t US_D_OD_HGEOM_DST_BUMP_TH_OFST_NOISE = 30.0f;

#define US_D_OD_HGEOM_FLT_LARGE (1e6f)
/* linearly interpolate confidence threshold */
#define US_D_OD_HGEOM_CONFTHR_DEF_SLOW (25u)
#define US_D_OD_HGEOM_CONFTHR_DEF_FAST (25u)
#define US_D_OD_HGEOM_CONFTHR_DEF_SLOW_NOISE (15u)
#define US_D_OD_HGEOM_CONFTHR_DEF_FAST_NOISE (15u)
#define US_D_OD_HGEOM_CONFTHR_KPH_SLOW (1.0f)
#define US_D_OD_HGEOM_CONFTHR_KPH_FAST (8.0f)

static US_D_LAUD_QUAL float32_t g_fGeomStats_BorderY = 40.0f; 
#define US_D_OD_HGEOM_BORDER_Y g_fGeomStats_BorderY
#define US_D_OD_HGEOM_HALFWIDTHY 100.0f; 

/* for bumper specific default parameters, regular and offset */
#define US_D_OD_HGEOM_N_PARAMS (2)
#define US_D_OD_HGEOM_PARAM_REGULAR (0u)
#define US_D_OD_HGEOM_PARAM_OFFSET (1u)

#define US_POLE_EXT_CORNER_THSD_Y (80.0f)
static float32_t g_fGeomStats_rho = US_D_OD_HGEOM_RHO_DEFAULT; 
static US_D_LAUD_QUAL float32_t g_fGeomStats_SigmaYThresh_sq = (US_D_OD_HGEOM_SIGMAYTHRESH_DEFAULT*US_D_OD_HGEOM_SIGMAYTHRESH_DEFAULT); 
static uint8_t g_PoleExtract_CornerLateDetection[US_D_PHYS_GRP_MAX] = {ME_FALSE, ME_FALSE};
static US_D_LAUD_QUAL float32_t g_fGeomStats_MinXDist[US_D_PHYS_GRP_MAX][US_D_OD_HGEOM_N_PARAMS] = 
{
    {US_D_OD_HGEOM_MINXDIST_DEF_FRNT, US_D_OD_HGEOM_MINXDIST_DEF_OFST}, /* front */  
    {US_D_OD_HGEOM_MINXDIST_DEF_REAR, US_D_OD_HGEOM_MINXDIST_DEF_OFST}  /* rear */ 
};  
static US_D_LAUD_QUAL float32_t g_fGeomStats_MaxXDist[US_D_PHYS_GRP_MAX][US_D_OD_HGEOM_N_PARAMS] = 
{
    {US_D_OD_HGEOM_MAXXDIST_DEF_FRNT, US_D_OD_HGEOM_MAXXDIST_DEF_OFST}, /* front */ 
    {US_D_OD_HGEOM_MAXXDIST_DEF_REAR, US_D_OD_HGEOM_MAXXDIST_DEF_OFST}  /* rear */
};  
static uint8_t g_uBinCounterThresh[US_D_PHYS_GRP_MAX][US_D_OD_HGEOM_N_PARAMS] = 
{
    {US_D_OD_HGEOM_BINCNTTHRESH_FRNT, US_D_OD_HGEOM_BINCNTTHRESH_OFST}, /* front */ 
    {US_D_OD_HGEOM_BINCNTTHRESH_REAR, US_D_OD_HGEOM_BINCNTTHRESH_OFST}  /* rear */
};  
static float32_t g_DistToBumperThresh[US_D_PHYS_GRP_MAX][US_D_OD_HGEOM_N_PARAMS] = 
{
    {US_D_OD_HGEOM_DST_BUMP_TH_FRNT, US_D_OD_HGEOM_DST_BUMP_TH_OFST}, /* front */ 
    {US_D_OD_HGEOM_DST_BUMP_TH_REAR, US_D_OD_HGEOM_DST_BUMP_TH_OFST}  /* rear */
};  

US_D_LAUD_QUAL float32_t g_fGeomStats_ConfThresh_kph_slow = US_D_OD_HGEOM_CONFTHR_KPH_SLOW; 
US_D_LAUD_QUAL float32_t g_fGeomStats_ConfThresh_kph_fast = US_D_OD_HGEOM_CONFTHR_KPH_FAST; 
#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE)
US_D_DBG_QUAL float32_t g_fSigmaY_rear = 0.0f;
US_D_DBG_QUAL float32_t g_fSigmaY_front = 0.0f;
US_D_DBG_QUAL float32_t g_DEBUG_fPointDistToBumper_sigma[US_D_PHYS_GRP_MAX] = {0.0f, 0.0f};
#endif


#define US_D_OD_HGEOM_SET_HEIGHT_FLG /* set the height flag of 2D points based on pole decisions */

#define US_D_OD_HEIGHT_N_SIDE_BINS (2u)
static uint16_t auBinCounter_sigma[US_D_OD_HEIGHT_N_SIDE_BINS+US_D_OD_HEIGHT_GEOM_N_BINS][US_D_PHYS_GRP_MAX] ={0};


/* these need to store state of the previous frames */
static float32_t g_f_mu_last[US_D_OD_HGEOM_N_SIGMA_DIV][US_D_PHYS_GRP_MAX] = {
        {US_D_OD_HGEOM_MU_INVALID, US_D_OD_HGEOM_MU_INVALID}, 
        {US_D_OD_HGEOM_MU_INVALID, US_D_OD_HGEOM_MU_INVALID}, 
        {US_D_OD_HGEOM_MU_INVALID, US_D_OD_HGEOM_MU_INVALID}};
static float32_t g_f_sigma_sq_last[US_D_OD_HGEOM_N_SIGMA_DIV][US_D_PHYS_GRP_MAX] = {
        {0.0f, 0.0f}, 
        {0.0f, 0.0f},
        {0.0f, 0.0f}};
float32_t g_PrevSigma[US_D_PHYS_GRP_MAX] = {1000.0f, 1000.0f}; //QAC

US_D_DBG_QUAL uint8_t   g_uGeomStats_PoleDecision[US_D_OD_HGEOM_N_SIGMA_DIV][US_D_PHYS_GRP_MAX]; /* pole decision for front and rear group*/
#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE)
US_D_DBG_QUAL uint8_t   g_uGeomStats_PoleDBGFlag[US_D_OD_HGEOM_N_SIGMA_DIV][US_D_PHYS_GRP_MAX]; //  
        

US_D_DBG_QUAL uint8_t   g_uSpdCtrld_BinCounterThresh[US_D_OD_HGEOM_N_SIGMA_DIV][US_D_PHYS_GRP_MAX]; /* computed as output. */
#endif

static uint8_t UssOD_GeomStats_GetPoleDecision(uint8_t uDivIdx,uint8_t uGrpIdx, float32_t fPointDistToBumper, float32_t fSnrSideY, uint8_t uCornerLateDetection); 
static void UssOD_GeomStats_ResetMuSigma(const uint8_t uDivIdx, const uint8_t uGrpIdx); 
static void UssOD_GeomStats_ComputeMuSigma(const uint8_t uDivIdx, const uint8_t uGrpIdx, const float32_t fY); 

static void UssOD_UpdateHeightGeomStats_Sigma(uint8_t uGrpIdx, uint8_t uNumCurPnts); 
#endif

#ifdef US_D_OD_HGEOM_COMPUTE_GRPHEIGHT
static void UssOD_UpdateHeightGeomStats_Rear(uint8_t uGrpIdx, uint8_t uNumCurPnts); 
#endif

/*
 * Height algo (front and rear).
 */
/* ===========================================================================
 * Name: UssOD_UpdateHeightGeomStats	
 * Remarks:  DD-ID: {54075B7F-0362-4b6e-8EC2-D1A6688889E4}
 * ===========================================================================*/
void UssOD_UpdateHeightGeomStats(uint8_t uGrpIdx, uint8_t uNumCurPnts)  /* PRQA S 2755 */
{

#ifdef US_D_OD_HGEOM_COMPUTE_SIGMA 
    /* compute mu and sigma */
    UssOD_UpdateHeightGeomStats_Sigma(uGrpIdx, uNumCurPnts); 

#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE) /* these are used to send output to debug */
    if (uGrpIdx == US_D_PHYS_GRP_REAR)
    {
        g_fSigmaY_rear  = (float32_t)sqrtf(g_f_sigma_sq_last[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR]); /* PRQx 4435 */ /* QAC Can't identify math.h functions */
    }
    else if (uGrpIdx == US_D_PHYS_GRP_FRNT)
    {
        g_fSigmaY_front = (float32_t)sqrtf(g_f_sigma_sq_last[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_FRNT]); /* PRQx 4435 */ /* QAC Can't identify math.h functions */
    }
    else
    {
        /*do nothing*/
    }
#endif
#endif /* US_D_OD_HGEOM_COMPUTE_SIGMA  */
#ifdef US_D_OD_HGEOM_COMPUTE_GRPHEIGHT
    /* compute geom stats for rear only */
    if (uGrpIdx == US_D_PHYS_GRP_REAR)
    {
        /* performs RAEB Height detection*/
        UssOD_UpdateHeightGeomStats_Rear(US_D_PHYS_GRP_REAR, uNumCurPnts); 
    } 
    else{/*do nothing*/}
#endif /* US_D_OD_HGEOM_COMPUTE_GRPHEIGHT */
}

#ifdef US_D_OD_HGEOM_COMPUTE_GRPHEIGHT
/*
 * Height algo for REAR REAB.
 */
/* ===========================================================================
 * Name: UssOD_UpdateHeightGeomStats_Rear	
 * Remarks:  DD-ID: {DAC007C9-FD72-49dc-973D-A89B6AEA1ACA} 
 * ===========================================================================*/
static void UssOD_UpdateHeightGeomStats_Rear(uint8_t uGrpIdx, uint8_t uNumCurPnts)  /* PRQA S 2755 */
{
    uint8_t uListIdx;
    uint8_t uPntIdx;
    float32_t fRSnrX;
    const float32_t fHalfWidthY = US_D_OD_HGEOM_HALFWIDTHY; //half width of vehicle.
    uint8_t uValidPoints = 0; //number of points in first pass.
    uint8_t uPointsInWindow = 0; //number of points in second pass.
    float32_t fClosestX = -1e6f; //set to far away in negative land.
    const float32_t fDeltaXWindow = 50.0f; //size of window in X [cm].
    uint8_t * puaGrpSnrPntSortIdx = UssOD_sGetSnrPntSortIdxList(uGrpIdx); 
    US_S_SnrPoint_t * psaSnrPntList;
    US_S_SnrPoint_t * psSnrPnt;
    const US_S_SensorsCfg_t * pSnrCfg = US_SnrCfg_F_Get_SnrCfg();   // Get calibration record.
    const US_S_Sensor_coordinate_t * pSnrCoord = NULL;
    bool_t abBinNotEmpty[US_D_OD_HEIGHT_GEOM_N_BINS]={0}; //initialize ALL elements to zero, 0=Empty, 1=full.    
    float32_t fTotalHeightSum = 0.0f;
    float32_t fMeanHeight = 0.0f;
    uint8_t uBinIdx;
    bool_t bIsHighObject;
    bool_t bIsCurbWall = ME_FALSE;
    float32_t fAdjustedMinCr;
    const US_E_App_Prndl_Status_e eCurVehGear = UssCom_F_GetVehPrndl();
    

#ifdef US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS
    static uint32_t uWideLatchTimeStart_ms = ZERO;
    uint32_t uWideLatchDiffTime_ms  = ZERO;
    float32_t   fPointDistToBumper  = 0.0f;
    float32_t   fSpeedFactor        = 1.0f;
    uint16_t    uSpeedCorrection    = 0u;
    float32_t   fLatchAllowDist     = 0.0f;
    float32_t   fLatchSustainCalcd  = 0.0f;    
    float32_t   fVehSpeed_kph = 0.0f;
    float32_t   fUnlatchDist = 0.0f;
    float32_t   fMinUnlatchDist = 0.0f;
#endif

#ifdef  US_D_OD_HEIGHT_NOTNEAR_ML
    static uint8_t uLastValueML = US_D_OD_HEIGHT_NOTNEAR_UNDEF; 
#endif

#ifdef US_D_OD_HEIGHT_GEOM_DEBUG
#if 0
    g_InPass1 = ME_FALSE; 
    g_InPass2 = ME_FALSE; 
    g_InPass3 = ME_FALSE; 
#endif
    
#endif


    /* this function will only run for rear group */
    if (uGrpIdx != US_D_PHYS_GRP_REAR) 
    {
        return;
    }
    else{/*do nothing*/}

    /* Get the address of Sensor Coordinate from Calibration data */
    if (pSnrCfg != NULL)
    {
        pSnrCoord = pSnrCfg->pSnrCoordinate;
    }
    else{/*do nothing*/}

    if(pSnrCoord == NULL) 
    { 
        return;   // Check if data exists.  Early return for functional safety.
    }
    else{/*do nothing*/}
    /* get x coordinate of rear sensor to deliniate ROI x-coord */
    fRSnrX = pSnrCoord[US_D_SENSOR_RIR].fX;

#ifdef US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
    /* IF not in reverse, then reset auBinHist */
    if (US_PRNDL_REVERSE != eCurVehGear)
    {
        for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
        {
                auBinHist[uBinIdx] = 0u;
        }
    }
    else{/*do nothing*/}
#endif
#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH
    /* IF not in reverse, then reset auBinHist */
    if (US_PRNDL_REVERSE != eCurVehGear)
    {
        //uBinIdx REUSED!!
        for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
        {
                auBinCounter[uBinIdx] = 0u;
                auBinMaxAge[uBinIdx] = 0u;
        }
        //reset it here
        bResetLatch = ME_FALSE;
        g_fCruiseBinRatio = 0.0f;
        #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
        g_DEBUG_AdjLatchMaxAge = 0x00;
        g_DEBUG_AdjLatchMinCr = 0x00;
        g_DEBUG_LatchPassMap = 0x00;
        g_DEBUG_LoneCrZero = 0x00;
        g_DEBUG_fPointDistToBumper = 0.0f;
        #endif
        g_uLastNewObservationCounter = 0u;
        g_uNewObsCounter2 = 0u; 

    #ifdef  US_D_OD_HEIGHT_NOTNEAR_ML
        uLastValueML = US_D_OD_HEIGHT_NOTNEAR_UNDEF; /* set as undefined */ 
    #endif
    }
    else{/*do nothing*/}
#endif

#if 0  /* Was commented out, disabled this way to avoid nested comments */
#ifdef US_D_OD_HGEOM_COMPUTE_SIGMA
    /* IF not in reverse, then reset sigma y calculation */
    if (US_PRNDL_REVERSE != UssCom_F_GetVehPrndl())
    {
        UssOD_GeomStats_ResetMuSigma(uGrpIdx); 
        g_uGeomStats_PoleDecision[uGrpIdx] = ME_FALSE; 
    }
#endif
#endif

#if 1 //if we are not in reverse, nothing else to do (note: adding this is recent change) 
    if (US_PRNDL_REVERSE != eCurVehGear) {return;} 
#endif


#ifdef US_D_OD_HEIGHT_GEOM_BG_NOISE_TRACK
    UssOD_ComputeBackgroundNoiseLevel(uGrpIdx);     
#endif
    

    /* First pass. determine closest valid confident point to rear bumper */    
    {
        psaSnrPntList = UssOD_sGetSnrPntBuff(uGrpIdx);
        // Loop through all points in group
        for (uListIdx = 0; uListIdx < uNumCurPnts; uListIdx++)
        {
            uPntIdx = puaGrpSnrPntSortIdx[uListIdx]; // Get the sorted point index
            psSnrPnt =  &psaSnrPntList[uPntIdx];  // Get the record for this sorted point

            // If confidence of point is above threshold, proceed
            if (psSnrPnt->uConf >= 45u)
            {
                /* skip points outside region of interest: */
                if ((psSnrPnt->fX > fRSnrX) ||  //note, for rear bumper, we are pointing negative (watch sign)
                    (psSnrPnt->fY < -fHalfWidthY) ||
                    (psSnrPnt->fY > +fHalfWidthY))
                {
                    continue;
                }
                else{/*do nothing*/}

                uValidPoints++; //keep track of number of valid points found in ROI.             

                /* if closest point then update it: */
                if (psSnrPnt->fX > fClosestX)  //note, for rear bumper, we are pointing negative (watch sign)
                {
                    fClosestX = psSnrPnt->fX;
                }
                else{/*do nothing*/}

            }
            else if (psSnrPnt->uConf > 0u)
            {
                break; // Out of points in this group so quit.
            }
            else
            { /* do nothing (do not break if uConf == 0, which represents a deleted point)*/}

        } //end for
    } //end first pass
    fPointDistToBumper = fRSnrX - fClosestX;
    g_DEBUG_fPointDistToBumper = fPointDistToBumper;



    /////
    /* Second pass. determine geometry statistics of any points in window from (fClosestX-fDeltaXWindow) to fClosestX */
    /////    
    if (uValidPoints > 0u)
    {        
        /* Loop through all points in group */
        for (uListIdx = 0; uListIdx < uNumCurPnts; uListIdx++)
        {
            uPntIdx = puaGrpSnrPntSortIdx[uListIdx]; // Get the sorted point index
            psSnrPnt = &psaSnrPntList[uPntIdx];  // Get the record for this sorted point
            
#if 1 
            if (psSnrPnt->uConf == 0u)
            {
                continue; /* skip deleted points */ 
            }
            // If confidence of point is above threshold, proceed
            else if (psSnrPnt->uConf <= 20u) 
            {  
              break; //the list is sorted by confidence
            } 
            else {/* do nothing */}
#endif

            /* skip points outside of window within region of interest: */
            if ((psSnrPnt->fX > fClosestX) ||  //note, for rear bumper, we are pointing negative (watch sign)
                (psSnrPnt->fX < (fClosestX-fDeltaXWindow)) || //skip if more negative.
                (psSnrPnt->fY < -fHalfWidthY) ||
                (psSnrPnt->fY > +fHalfWidthY))
            {
                continue;
            }
            else{/*do nothing*/}

            /* update counter of points in window */
            uPointsInWindow++;



            /* determine which bin for the y coordinate: */                        
            uBinIdx = (uint8_t)floorf((float32_t)US_D_OD_HEIGHT_GEOM_N_BINS*((psSnrPnt->fY + fHalfWidthY)/(fHalfWidthY*2.0f)));
            if (uBinIdx >= US_D_OD_HEIGHT_GEOM_N_BINS)
            {
                //crop bin in case the last bin is exactly too high.
                uBinIdx = US_D_OD_HEIGHT_GEOM_N_BINS -1u;
            }
            else{/*do nothing*/}

            /* set that bin to non empty: */
            abBinNotEmpty[uBinIdx]=ME_TRUE; //we found a point, so it is not empty.

#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH
            if ( (fRSnrX - psSnrPnt->fX) <= g_fResetLatchDist )
            {
                /*accumulate points with cruising age 0*/                
                if (psSnrPnt->uCruisingAge == ZERO)
                {
    #ifdef US_D_OD_HEIGHT_GRL_SKIP_LONES
                    if ((psSnrPnt->uPntStat & US_D_PNTSTAT_DIRECT_ONLY) != ZERO)
                    {
                        #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                        g_DEBUG_LoneCrZero++;
                        #endif
                    }
                    else
    #endif
                    {
                        auBinCounter[uBinIdx]++;
                        if(((psSnrPnt->uConf > g_uConfThresh) && ((fRSnrX - psSnrPnt->fX) < g_fLastObservationThresh)) && (fVehSpeed_kph >= 0.5f))
                        {
                            g_uLastNewObservationCounter++;
                        }
                        else{/*do nothing*/}                                                
                    }
                }
                //only store the highest age
                if (auBinMaxAge[uBinIdx] < psSnrPnt->uAge)
                {
                    auBinMaxAge[uBinIdx] = psSnrPnt->uAge;
                }
                else{/*do nothing*/}
            }
            else{/*do nothing*/}
#endif


#ifdef US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
            if ( ((fRSnrX - psSnrPnt->fX) < g_fNewObsCounter2_XMax) && ((fRSnrX - psSnrPnt->fX) > g_fNewObsCounter2_XMin) && (psSnrPnt->uConf > g_uConfThresh) && (psSnrPnt->uCruisingAge == ZERO))
            {
                auBinHist[uBinIdx]++;
                g_uNewObsCounter2++;   
            }
            else{/*do nothing*/}
#endif



            /* increment the total height sum */
#ifndef US_D_OD_HEIGHT_FILTER_SMOOTING //smoothing filter should not be defined. ifndef
            if (psSnrPnt->uHeight != ONE) //ZERO = UNKNOWN, ONE=LOW, TWO = HIGH.
            {
                // if point is not low (i.e., high or unknown) then increment by 1.0f
                fTotalHeightSum += 1.0f;
            }
            else{/*do nothing*/}
#else
            // increment it by the probability (TBD)
            /* for now, just a check to make sure nobody enables this yet */
            #error "this is supposed to be disabled"
#endif


        }//end for.
    }//end of second pass.

    /* summarize results pass: */    
    {
        fMeanHeight = 0.0f;
        if (uPointsInWindow > 0u)
        {
            /* compute the average height score of the window */
            fMeanHeight = fTotalHeightSum/((float32_t)uPointsInWindow);


#if 0
            /* perform curbwall test */            
            bIsCurbWall = ME_TRUE;
            for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
            {
                /* if any bin is empty then set to false and break */
                if (abBinNotEmpty[uBinIdx]==ME_FALSE)
                {
                    bIsCurbWall = ME_FALSE;
                    break;
                }
            }
#else
            uint8_t uCountFullBins = 0;

            bIsCurbWall = (bool_t)ME_FALSE;
            for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
            {
                /* if any bin is empty then set to false and break */
                if (abBinNotEmpty[uBinIdx] == (bool_t)ME_TRUE)
                {
                    uCountFullBins++;
                }
                else{/*do nothing*/}
            }
			/*Default object to wide*/
            if(uCountFullBins >= 1u)
            {
                bIsCurbWall = (bool_t)ME_TRUE;
            }
            else if ( ( ( (bool_t)ME_TRUE == abBinNotEmpty[0] ) && 
                        ( (bool_t)ME_TRUE == abBinNotEmpty[4] )  
                      ) && 
                      ( ( (bool_t)ME_TRUE == abBinNotEmpty[1] ) ||
                        ( (bool_t)ME_TRUE == abBinNotEmpty[2] ) ||
                        ( (bool_t)ME_TRUE == abBinNotEmpty[3] ) )
                    )
                     
            {
                bIsCurbWall = (bool_t)ME_TRUE;
            }
            else
            {
                /* Do Nothing */
            }

#endif

            fVehSpeed_kph = UssCom_F_GetVehSpeed();            
#ifdef US_D_OD_HEIGHT_COMPENSATE_NOISE_TRIANG
            if (UssMgr_eGetGrpState(uGrpIdx) != SYSMGR_GRPSTATE_OK )
            {
                fPointDistToBumper -= g_NoiseCompensationDist;
                if(fPointDistToBumper < 0.0f)
                {
                    fPointDistToBumper = 0.0f;
                }
                else{/*do nothing*/}
            }
            else{/*do nothing*/}
#endif
            fLatchSustainCalcd = g_fLatchSustainAdd + (fVehSpeed_kph * US_D_OD_HEIGHT_GEOM_SPEED_COMP_FACTOR);
#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH
            /*Reset latch decision when distance is <= 200% of 10*speed */
            
            fUnlatchDist = (g_fUnlatchDistPercentage * US_D_OD_HEIGHT_GEOM_SPEED_COMP_FACTOR * fVehSpeed_kph);
            fMinUnlatchDist = (fLatchSustainCalcd + g_fMinLatchResetAdd);
            #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
            g_DEBUG_fUnlatchDist = fUnlatchDist;
            g_DEBUG_fMinUnlatchDist = fMinUnlatchDist;                        
            #endif
            if ( (fPointDistToBumper <= fUnlatchDist) || (fPointDistToBumper < fMinUnlatchDist) )
            {
                /*Get the highest count value*/
                uint8_t uMaxBinCruising = 0u;
                float32_t fCruiseBinAvg = 0.0f;
                bool_t  bCruiseRatioPass = ME_FALSE;
                bool_t  bAgeMaxPass      = ME_FALSE;
                bool_t  bMinCrAgePass    = ME_FALSE;
                bool_t  bObsCounter2     = ME_FALSE; 
                uint8_t uAdjustedMaxAge = 0u;
                uint8_t uAdjustedMinCr  = 0u;
                bool_t bLastObservationPass = ME_FALSE;
				bool_t bHighRatioCheck = ME_FALSE;
                uint8_t uPeakIdx = 0u;
                uint8_t uBinsWithCnt = 0u;
                float32_t fAdjResetLatchRatio = g_fResetLatchRatio;                


                uAdjustedMaxAge = (uint8_t)( ((float32_t)g_uResetLatchMaxAge) * (2.0f/fVehSpeed_kph) ) + (float32_t)g_uResetLatchAgeAndCr_Offset;
                #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                g_DEBUG_AdjLatchMaxAge = uAdjustedMaxAge;
                #endif
                for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
                {
                    if (auBinCounter[uBinIdx] > uMaxBinCruising)
                    {
                        uMaxBinCruising = (uint8_t)auBinCounter[uBinIdx];
                        uPeakIdx = uBinIdx;
                    }
                    else{/*do nothing*/}
                    if (auBinCounter[uBinIdx] > ZERO)
                    {
                        uBinsWithCnt++;
                    }
                    else{/*do nothing*/}
                    //sum the bin counters
                    fCruiseBinAvg += (float32_t)auBinCounter[uBinIdx];

                    //check for max age condition
                    if ( (auBinMaxAge[uBinIdx] >= uAdjustedMaxAge) || (auBinMaxAge[uBinIdx] == US_D_OD_PNT_MAX_AGE) )
                    {
                        bAgeMaxPass = ME_TRUE;
                    }
                    else{/*do nothing*/}
                }

                /* Adjust needed minimum cruising age counts based on number of bins populated */
                if ((uBinsWithCnt <= 2u) && (uBinsWithCnt > 0u))
                {
                    uAdjustedMinCr = US_D_OD_HEIGHT_GRL_HIGH_OBJ_MIN_CR; //not based on speed 
                    fAdjResetLatchRatio = US_D_OD_HEIGHT_GRL_RATIO - 0.3f; //adjust ratio for later checks
                }
                else{/*do nothing*/}
                if (uBinsWithCnt == 3u)
                {
                    uAdjustedMinCr = US_D_OD_HEIGHT_GRL_HIGH_OBJ_MIN_CR;
                }
                else{/*do nothing*/}
                if (uBinsWithCnt == 4u)
                {                    
                    fAdjustedMinCr = ( ((float32_t)g_uMinCruisingCnt) * (0.5f/fVehSpeed_kph) ) + ((float32_t)g_uResetLatchAgeAndCr_Offset);
                    if ((fAdjustedMinCr*g_fAdjustedMinCrFactor)<=255.0f) 
                    {
                        uAdjustedMinCr=(uint8_t) (fAdjustedMinCr* g_fAdjustedMinCrFactor);
                    }
                    else{/*do nothing*/}
                }
                else{/*do nothing*/}
                if (uBinsWithCnt > 4u )
                {                    
                    fAdjustedMinCr = ( ((float32_t)g_uMinCruisingCnt) * (1.0f/fVehSpeed_kph) ) + ((float32_t)g_uResetLatchAgeAndCr_Offset);
                    if ((fAdjustedMinCr*g_fAdjustedMinCrFactor) <=255.0f) 
                    {
                        uAdjustedMinCr=(uint8_t)(fAdjustedMinCr * g_fAdjustedMinCrFactor);
                    }
                    else{/*do nothing*/}
                }
                else{/*do nothing*/}

                //reduce needed min Cr for points on the edge bins
                if ((uPeakIdx == 0u) || (uPeakIdx == 4u))
                {
                    uAdjustedMinCr = US_D_OD_HEIGHT_GRL_HIGH_OBJ_MIN_CR;
                }
                else{/*do nothing*/}
                #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                g_DEBUG_AdjLatchMinCr = uAdjustedMinCr;
                #endif
                /* see if minimum cruising age reached */
                if ( (uAdjustedMinCr <= uMaxBinCruising) || (uMaxBinCruising == US_D_OD_PNT_MAX_CRUISING_AGE) )
                {
                    bMinCrAgePass = ME_TRUE;
                }
                else{/*do nothing*/}

                /* get the ratio */
                //calc the avg
                fCruiseBinAvg = (fCruiseBinAvg / (float32_t)US_D_OD_HEIGHT_GEOM_N_BINS);
                g_fCruiseBinRatio = (float32_t)uMaxBinCruising / fCruiseBinAvg;
                if( g_fCruiseBinRatio >= fAdjResetLatchRatio )
                {                    
                    bCruiseRatioPass = ME_TRUE;
                }
                else{/*do nothing*/}

                if (g_uLastNewObservationCounter >= g_uObsCountThresh)
                {
                    bLastObservationPass = ME_TRUE;
                }
                else{/*do nothing*/}
								
                if ((g_fCruiseBinRatio >= g_fHighRatioThresh) && (uPeakIdx != 0u) && (uPeakIdx != 4u) 
                    && (uMaxBinCruising >= US_D_OD_HEIGHT_GRL_HIGH_OBJ_MIN_CR))
				{
					bHighRatioCheck = ME_TRUE;
				}
                else{/*do nothing*/}


                if (g_uNewObsCounter2 >= g_uNewObsCounter2_thresh)
                {
                    bObsCounter2 = ME_TRUE; 
                }


                if ( (((bool_t)ME_TRUE == bCruiseRatioPass) && ((bool_t)ME_TRUE == bAgeMaxPass) && ((bool_t)ME_TRUE == bMinCrAgePass) && ((bool_t)ME_TRUE == bObsCounter2)) || ((bool_t)ME_TRUE == bLastObservationPass) || ((bool_t)ME_TRUE == bHighRatioCheck) )
                {
                    bResetLatch = ME_TRUE;
                }
                else{/*do nothing*/}
                #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                g_DEBUG_LatchPassMap = (uint32_t)((bCruiseRatioPass) | (bAgeMaxPass<<1) | (bMinCrAgePass<<2) | (bLastObservationPass<<3) | (bHighRatioCheck<<4) | (bObsCounter2 << 5));
                #endif
            }

#endif

#ifdef US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS
            //we have the "bIsCurbWall" data, latch it for a period of time to prevent loss with movement(?)            
            uSpeedCorrection = ZERO;
            fSpeedFactor = 1.0f;
    #if ( (US_D_OD_HEIGHT_GEOM_LATCH_USE_SPD_DIST == ME_TRUE) || (US_D_OD_HEIGHT_GEOM_LATCH_USE_SPD_TIME == ME_TRUE) )
            fVehSpeed_kph = UssCom_F_GetVehSpeed();  Kph to cm/s */
            if ( fVehSpeed_kph <= 6.5f )
            {
        #if (US_D_OD_HEIGHT_GEOM_LATCH_USE_SPD_DIST == ME_TRUE)
                fSpeedFactor = fVehSpeed_kph / 5.0f;
        #endif
        #if (US_D_OD_HEIGHT_GEOM_LATCH_USE__SPD___TIME == ME_TRUE)
                uSpeedCorrection = (uint16_t)fVehSpeed_kph * 50u;
                if( uSpeedCorrection > g_uLatchTimeMs )
                {
                    uSpeedCorrection = g_uLatchTimeMs;
                }
        #endif
            }
    #endif
            fLatchAllowDist = g_fLatchBaseDist * fSpeedFactor;
            #if 1
            {
                if((bool_t)ME_TRUE == bResetLatch)
                {
                    bWideLatchActive = ME_FALSE;
                    bIsCurbWall = ME_FALSE;
                    #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                    g_DEBUG_uLatchDecisions = 0x01;
                    #endif
                }
                else if ( (bIsCurbWall == (bool_t)ME_TRUE) && (fPointDistToBumper <= fLatchAllowDist) )
                {
                    bWideLatchActive = ME_TRUE;
                    #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                    g_DEBUG_fLatchDist = fPointDistToBumper;
                    #endif
                    //reset latch timer
                    uWideLatchTimeStart_ms = US_GetTimeStampTimeMs();
                    #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                    g_DEBUG_uLatchDecisions = 0x02;
                    #endif
                }
                else
                {
                    //curbwall came out false in the new calc - if latch is active, force it back to True
                    if( bWideLatchActive ==(bool_t) ME_TRUE )
                    {
                        /* TODO - TIME OVERFLOW is not handled. Rare occurance, not critical */
                        uWideLatchDiffTime_ms = US_GetTimeStampTimeMs() - uWideLatchTimeStart_ms;
                        if ( uWideLatchDiffTime_ms < ( g_uLatchTimeMs - uSpeedCorrection) )
                        {
                            bIsCurbWall = ME_TRUE;
                            #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                            g_DEBUG_uLatchDecisions = 0x03;
                            #endif
                        }
                        else
                        {
                            //latch is over
                            bWideLatchActive = ME_FALSE;
                            #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                            g_DEBUG_uLatchDecisions = 0x04;
                            #endif
                        }
                    }
                    else
                    {
                        #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                        g_DEBUG_uLatchDecisions = 0x05;
                        #endif
                    }
                    
                }
            }
            #endif
            #if 0
            else
            {
                if( bWideLatchActive == (bool_t)ME_TRUE )  /*PRQA S 2880 */ /* Expected*/
                { 
                    bIsCurbWall = ME_TRUE;
                    g_DEBUG_uLatchDecisions = 0x06;
                }
                else
                {
                    g_DEBUG_uLatchDecisions = 0x07;
                }
            }
            #endif
#endif /* US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS */


#ifdef US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
            //find fMaxBinHist            
            uint16_t uHighConfStarts = 0u;

            for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
            {
                if(auBinHist[uBinIdx] >= 1u)
                {
                    uHighConfStarts++;
                }
                else{/*do nothing*/}
            }
#if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)            
            if (uHighConfStarts >= 4u)
            {
                g_DEBUG_bmapBinAccu = ONE;
            }
            else 
            {
                g_DEBUG_bmapBinAccu = ZERO;
            }
#endif            
    #if 0  /* Was commented out, disabled this way to avoid nested comments */
            /* IF all bins are greater than 0.5*fMaxBinHist THEN set bIsCurbWall to TRUE, OTHERWISE keep it same */
            uint8_t uBinCounter = 0;
            uint8_t uDistFill[US_D_OD_HEIGHT_GEOM_N_BINS] = {0};
            for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
            {
                #if 0
                //check condition of each bin and set flag if found otherwise:
                if (auBinHist[uBinIdx] >= 0.35f*fMaxBinHist)
                {
                    uBinCounter++;
                    uDistFill[uBinIdx]=1;
                }
                #endif
                if ((auBinHist[uBinIdx] != 0.0f) && (auBinHist[uBinIdx] < 0.05f*fMaxBinHist))
                {
                    g_DEBUG_bmapBinAccu |= 0x02;
                }
                else if ((auBinHist[uBinIdx] != 0.0f) && (auBinHist[uBinIdx] < 0.1f*fMaxBinHist))
                {
                    g_DEBUG_bmapBinAccu |= 0x04;
                }
            }
            

            g_DEBUG_fMaxBinHist = fMaxBinHist;
            if (uBinCounter >= 4) //if at least 4 bins fulfill distribution threshold test
            {
                //bIsCurbWall = ME_TRUE; //set wide
                g_DEBUG_bmapBinAccu |= 0x02;
            }
            
            
            else if (uDistFill[0] && uDistFill[4] && (uDistFill[2] || uDistFill[3] || uDistFill[4]) )
            {                
                g_DEBUG_bmapBinAccu |= 0x04;
            }
    #endif /* #if 0 for comment block */


#endif

            /* determine if high object */            
            //start with false.
                        
            bIsHighObject = ME_FALSE;
            #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
            g_DEBUG_HighGuess = 0x01u;
            #endif
    #if 0 /* Was commented out, disabled this way to avoid nested comments */
            if(ME_TRUE == bResetLatch)  //always high for close objects
            {
                bIsHighObject = ME_TRUE;
                g_DEBUG_HighGuess = 0x05;
            }
            /* if neither a CURB or WALL then set it to HIGH */
            
    #endif
            if (bIsCurbWall == ME_FALSE)
            {
                bIsHighObject = ME_TRUE;
                #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                g_DEBUG_HighGuess = 0x02u;
                #endif
            }
            /*  */
            else if (UssMgr_eGetGrpState(uGrpIdx) != SYSMGR_GRPSTATE_OK)
            {
                bIsHighObject = ME_FALSE;
                #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                g_DEBUG_HighGuess = 0x09u;
                #endif
            }
#ifdef  US_D_OD_HEIGHT_NOTNEAR_ML
            /* if we are close to object and existing ML decision exists */
            else if((fPointDistToBumper <= US_D_OD_HEIGHT_NOTNEAR_DIST) && (uLastValueML != US_D_OD_HEIGHT_NOTNEAR_UNDEF))
            {
                /* if the last decision was high, set to high */ 
                if (uLastValueML == US_D_OD_HEIGHT_NOTNEAR_HIGH)
                {
                    bIsHighObject = ME_TRUE;                    
                } 
				else
				{
				/* Do Nothing */
				}
                /* otherwise it will be low by default. */                
            }
#endif
            /* otherwise fMeanHeight must exceed threshold for it to be HIGH */
            else if (fMeanHeight >= US_D_OD_HEIGHT_GEOM_MEAN_THRESH)
            {
                bIsHighObject = ME_TRUE;
                #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
                g_DEBUG_HighGuess = 0x03u;
                #endif

#ifdef  US_D_OD_HEIGHT_NOTNEAR_ML
                /* if far enough away, set last ML decision to HIGH*/
                if (fPointDistToBumper > US_D_OD_HEIGHT_NOTNEAR_DIST)
                {
                    uLastValueML = US_D_OD_HEIGHT_NOTNEAR_HIGH; //2u==undefined. 
                }
				else
				{
				  /* Do Nothing */
				}
#endif                
            }
            else
           {
#ifdef  US_D_OD_HEIGHT_NOTNEAR_ML
                /* if far enough away, set last ML decision to LOW*/
                if (fPointDistToBumper > US_D_OD_HEIGHT_NOTNEAR_DIST)
                {
                    uLastValueML = US_D_OD_HEIGHT_NOTNEAR_LOW; //2u==undefined. 
            }
            else
            {
                /* Do Nothing */
            }
#endif
                     //Do nothing
            }
        }
        else /* if there are no points in the window mark as HIGH  (so it works properly for other points outside ROI) */
        {
            bIsHighObject = ME_FALSE;
            #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
            g_DEBUG_HighGuess = 0x04u;
            #endif
        }
#if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
        /*Prevents very short brake in last ~30cm*/
        if (g_DEBUG_uLatchDecisions == 0x06u)
        {
            bIsHighObject = ME_FALSE;
        }
        else{/*do nothing*/}   
        #endif     

        /* set value for output */
        abIsHighObject[uGrpIdx] = bIsHighObject; //note, this is read asynchronous, so should be threadsafe.

    }//end summary pass.


#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE)
#if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
    for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
    {
        g_abBinNotEmpty[uBinIdx] = abBinNotEmpty[uBinIdx]; 
    }
    
    g_bIsHighObject = bIsHighObject;
    g_bIsCurbWall= bIsCurbWall; 
    g_uValidPoints = uValidPoints;
    g_uPointsInWindow = uPointsInWindow;
    g_fClosestX = fClosestX;
    g_fMeanHeight = fMeanHeight; 
    #endif

#endif


}

#endif /* US_D_OD_HGEOM_COMPUTE_GRPHEIGHT */


#ifdef US_D_OD_HGEOM_COMPUTE_SIGMA
/* ===========================================================================
 * Name: UssOD_UpdateHeightGeomStats_Sigma	
 * Remarks:  DD-ID: {D265E55D-5135-4e76-ADA3-CD81A90E6C3F}
 * ===========================================================================*/
static void UssOD_UpdateHeightGeomStats_Sigma(uint8_t uGrpIdx, uint8_t uNumCurPnts)  /* PRQA S 2755 */
{
    uint8_t uListIdx;
    uint8_t uPntIdx;
    float32_t fRSnrX;
    float32_t fSnrSideY;
    const float32_t fHalfWidthY = US_D_OD_HGEOM_HALFWIDTHY; //half width of vehicle.
    const float32_t fBorderY = US_D_OD_HGEOM_BORDER_Y; //extra border
    uint8_t uValidPoints = 0; //number of points in first pass.
    uint8_t uPointsInWindow = 0; //number of points in second pass.    
    float32_t fClosestX;  //(note sign is swapped) set to far away .
    const float32_t fDeltaXWindow = 50.0f; //size of window in X [cm].
    const uint8_t * puaGrpSnrPntSortIdx = UssOD_sGetSnrPntSortIdxList(uGrpIdx); 
    US_S_SnrPoint_t * psaSnrPntList;
    US_S_SnrPoint_t * psSnrPnt;
    const US_S_SensorsCfg_t * pSnrCfg = US_SnrCfg_F_Get_SnrCfg();   // Get calibration record.
    const US_S_Sensor_coordinate_t * pSnrCoord = NULL;
    US_E_App_Prndl_Status_e eCurVehGear = UssCom_F_GetVehPrndl();
    uint8_t uBinIdx;
    uint8_t uDivIdx;
    float32_t   fPointDistToBumper  = 0.0f;    
    float32_t fConfThresh = (float32_t)g_fGeomStats_ConfThresh_fast; 
    uint8_t uPoleDecision = ME_FALSE;     
    const float32_t fVehSpeed = UssCom_F_GetVehSpeed();
	uint8_t b_PoleExtract_PointsInMiddle = ME_FALSE;
	uint8_t b_PoleExtract_PointsInCorner = ME_FALSE;
    uint8_t   g_fGeomStats_ConfThresh_slow = US_D_OD_HGEOM_CONFTHR_DEF_SLOW; 
    uint8_t   g_fGeomStats_ConfThresh_fast = US_D_OD_HGEOM_CONFTHR_DEF_FAST; 
    

	if(US_PRNDL_REVERSE != eCurVehGear)
	{
		g_PrevSigma[US_D_PHYS_GRP_REAR] = 1000.0f;
	}
	if(US_PRNDL_DRIVE   != eCurVehGear)
	{
		g_PrevSigma[US_D_PHYS_GRP_FRNT] = 1000.0f;
	}

    /* Get the address of Sensor Coordinate from Calibration data */
    if (pSnrCfg != NULL)
    {
        pSnrCoord = pSnrCfg->pSnrCoordinate;
    }
    else{/*do nothing*/}

    if(pSnrCoord == NULL) 
    {return;}   // Check if data exists.  Early return for functional safety.
    else{/*do nothing*/}

    if (uGrpIdx == US_D_PHYS_GRP_FRNT)
    {
        /* get x coordinate of FRONT sensor to deliniate ROI x-coord */    
        fRSnrX = pSnrCoord[US_D_SENSOR_FIR].fX;
        fSnrSideY = pSnrCoord[US_D_SENSOR_FSL].fY;
        fClosestX = US_D_OD_HGEOM_FLT_LARGE; 
		
		/*RHO value in Noise*/
		if (UssMgr_eGetGrpState(US_D_PHYS_GRP_FRNT) == SYSMGR_GRPSTATE_NOISY)
		{
			g_fGeomStats_rho = US_D_OD_HGEOM_RHO_NOISE;
			g_fGeomStats_ConfThresh_slow = US_D_OD_HGEOM_CONFTHR_DEF_SLOW_NOISE; 
            g_fGeomStats_ConfThresh_fast = US_D_OD_HGEOM_CONFTHR_DEF_FAST_NOISE; 
		}
		else
		{
			g_fGeomStats_rho = US_D_OD_HGEOM_RHO_DEFAULT;
			g_fGeomStats_ConfThresh_slow = US_D_OD_HGEOM_CONFTHR_DEF_SLOW; 
            g_fGeomStats_ConfThresh_fast = US_D_OD_HGEOM_CONFTHR_DEF_FAST; 
		}
		/*RHO value in Noise done*/
    }
    else if (uGrpIdx == US_D_PHYS_GRP_REAR)
    {
        fRSnrX = pSnrCoord[US_D_SENSOR_RIR].fX;
        fSnrSideY = pSnrCoord[US_D_SENSOR_RSL].fY;
        fClosestX = -US_D_OD_HGEOM_FLT_LARGE; 
        g_fGeomStats_ConfThresh_slow = US_D_OD_HGEOM_CONFTHR_DEF_SLOW;
        g_fGeomStats_ConfThresh_fast = US_D_OD_HGEOM_CONFTHR_DEF_FAST;
		
		/*RHO value in Noise*/
		if (UssMgr_eGetGrpState(US_D_PHYS_GRP_REAR) == SYSMGR_GRPSTATE_NOISY)
		{
			g_fGeomStats_rho = US_D_OD_HGEOM_RHO_NOISE;
		}
		else
		{
			g_fGeomStats_rho = US_D_OD_HGEOM_RHO_DEFAULT;
		}
		/*RHO value in Noise done*/
    }
    else
    {        
        return; 
    }

    /* IF not in drive, then */
    if ( ((uGrpIdx == US_D_PHYS_GRP_FRNT) && (US_PRNDL_DRIVE   != eCurVehGear)) ||
         ((uGrpIdx == US_D_PHYS_GRP_REAR) && (US_PRNDL_REVERSE != eCurVehGear)) )
    {
        /* reset auBinHist */
        for (uBinIdx = 0; uBinIdx < (US_D_OD_HEIGHT_GEOM_N_BINS+US_D_OD_HEIGHT_N_SIDE_BINS); uBinIdx++)
        {
                auBinCounter_sigma[uBinIdx][uGrpIdx] = 0u;
        }
 

        for (uDivIdx=0; uDivIdx < US_D_OD_HGEOM_N_SIGMA_DIV; uDivIdx++)
        {
            /* reset sigma y calculation */
            UssOD_GeomStats_ResetMuSigma(uDivIdx, uGrpIdx); 
            

            g_uGeomStats_PoleDecision[uDivIdx][uGrpIdx] = ME_FALSE; 

        }

        /* return */
        return; 
    }   
    else{/*do nothing*/} 

    /* First pass. determine closest valid confident point to rear bumper */
    {
        psaSnrPntList = UssOD_sGetSnrPntBuff(uGrpIdx);
        // Loop through all points in group
        for (uListIdx = 0; uListIdx < uNumCurPnts; uListIdx++)
        {
            uPntIdx = puaGrpSnrPntSortIdx[uListIdx]; // Get the sorted point index
            psSnrPnt =  &psaSnrPntList[uPntIdx]; //&sSnrPnt[uGrpIdx][uPntIdx];  // Get the record for this sorted point
             /* make the confidence threshold a function of speed */
           

            if (psSnrPnt->uConf >= 45u)
            {

                /* skip points outside region of interest: */                
                if ( ((uGrpIdx == US_D_PHYS_GRP_FRNT) && (psSnrPnt->fX < fRSnrX)) ||  /* note, for front bumper, opposite sign than rear bumper */
                     ((uGrpIdx == US_D_PHYS_GRP_REAR) && (psSnrPnt->fX > fRSnrX)) ||  /* note, for rear bumper, we are pointing negative (watch sign) */
                     (psSnrPnt->fY < (-fHalfWidthY-fBorderY)) ||
                     (psSnrPnt->fY > (+fHalfWidthY+fBorderY)) )
                {
                    continue;
                }
                else{/*do nothing*/}

                uValidPoints++; //keep track of number of valid points found in ROI.

                /* if closest point then update it: */                  
                if (((uGrpIdx == US_D_PHYS_GRP_FRNT) && (psSnrPnt->fX < fClosestX)) || 
                    ((uGrpIdx == US_D_PHYS_GRP_REAR) && (psSnrPnt->fX > fClosestX)))  //note, for rear bumper, we are pointing negative (watch sign)                                  
                {
                    fClosestX = psSnrPnt->fX;
                }
                else{/*do nothing*/}

            }
            else if (psSnrPnt->uConf > 0u)
            {
                break; // Out of points in this group so quit.
            }
            else {/* do nothing (for deleted points with uConf == 0) */}

        } //end for
    } //end first pass

    fPointDistToBumper = (float32_t)fabsf(fClosestX - fRSnrX); /* note, swapped for front compared to rear */


    /////
    /* Second pass. determine geometry statistics of any points in window from (fClosestX-fDeltaXWindow) to fClosestX */
    /////
    if (uValidPoints > 0u)
    {

#if 1
        /* make the confidence threshold a function of speed */
        fConfThresh = (float32_t)g_fGeomStats_ConfThresh_fast; 
        fConfThresh += (float32_t)roundf((((float32_t)g_fGeomStats_ConfThresh_slow - (float32_t)g_fGeomStats_ConfThresh_fast)*(float32_t)fmaxf(0.0f, (float32_t)fminf(1.0f, 
                    (fVehSpeed - g_fGeomStats_ConfThresh_kph_fast) / 
                    (g_fGeomStats_ConfThresh_kph_slow - g_fGeomStats_ConfThresh_kph_fast))/*fminf end*/ )/* fmaxf end */)); 
#else 
        fConfThresh = (float32_t)g_fGeomStats_ConfThresh_fast; 
#endif        


        
        /* Loop through all points in group */
        for (uListIdx = 0; uListIdx < uNumCurPnts; uListIdx++)
        {
            uPntIdx = puaGrpSnrPntSortIdx[uListIdx]; // Get the sorted point index
            psSnrPnt = &psaSnrPntList[uPntIdx];  // Get the record for this sorted point
            
#if 1 
            if (psSnrPnt->uConf == 0u) 
            { 
                continue; /* skip deleted points */
            }
            // If confidence of point is above threshold, proceed            
            else if ((float32_t)psSnrPnt->uConf < fConfThresh) 
            {  
                 break; //the list is sorted by confidence, this will exit the loop.  
            } 
            else {/* do nothing */}
#endif


            /* skip points outside of window within region of interest: */
            if ( ((uGrpIdx == US_D_PHYS_GRP_REAR) && ((psSnrPnt->fX > fClosestX) || (psSnrPnt->fX < (fClosestX-fDeltaXWindow)))) || 
                 ((uGrpIdx == US_D_PHYS_GRP_FRNT) && ((psSnrPnt->fX < fClosestX) || (psSnrPnt->fX > (fClosestX+fDeltaXWindow)))) || 
                 (psSnrPnt->fY < (-fHalfWidthY-fBorderY)) ||
                 (psSnrPnt->fY > (+fHalfWidthY+fBorderY)) )
            {
                continue;
            }
            else{/*do nothing*/}

            /* update counter of points in window */
            uPointsInWindow++;


            /* center */
            if ((psSnrPnt->fY >= -fHalfWidthY) && (psSnrPnt->fY <= +fHalfWidthY))
            {
                /* compute sigma and mu with the point */
                UssOD_GeomStats_ComputeMuSigma(US_D_OD_HGEOM_SIGMA_C, uGrpIdx, psSnrPnt->fY);                             
            } else { /* do nothing */}

            /* left (positive Y) */
            if ((psSnrPnt->fY >= (fHalfWidthY - 10.0f)))
            {
                /* compute sigma and mu with the point */
                UssOD_GeomStats_ComputeMuSigma(US_D_OD_HGEOM_SIGMA_L, uGrpIdx, psSnrPnt->fY);                             
            } else { /* do nothing */}

            /* right (positive Y) */
            if ((psSnrPnt->fY <= (fHalfWidthY + 10.0f)))
            {
                /* compute sigma and mu with the point */
                UssOD_GeomStats_ComputeMuSigma(US_D_OD_HGEOM_SIGMA_R, uGrpIdx, psSnrPnt->fY);                             
            } else { /* do nothing */}



            /* determine which bin for the y coordinate: */
            uBinIdx = (uint8_t)floorf((float32_t)US_D_OD_HEIGHT_GEOM_N_BINS*((psSnrPnt->fY + fHalfWidthY)/(fHalfWidthY*2.0f)));
            if (uBinIdx >= US_D_OD_HEIGHT_GEOM_N_BINS)
            {
                //crop bin in case the last bin is exactly too high.
                uBinIdx = US_D_OD_HEIGHT_GEOM_N_BINS -1u;
            }
            else{/*do nothing*/}

            /* determine if point is side bins for offset isopole test */
            if (psSnrPnt->fY < -fHalfWidthY) 
            {
                uBinIdx = US_D_OD_HEIGHT_GEOM_N_BINS; /* right */
            }
            else if (psSnrPnt->fY > fHalfWidthY) 
            {
                uBinIdx = US_D_OD_HEIGHT_GEOM_N_BINS+1u; /* left */
            }
            else {/* do nothing*/}

#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH
            if (( (fRSnrX - psSnrPnt->fX) <= g_fResetLatchDist ) && 
			    ((g_PrevSigma[uGrpIdx] < g_fGeomStats_SigmaYThresh_sq) || (uBinIdx == US_D_OD_HEIGHT_GEOM_N_BINS) || (uBinIdx == (US_D_OD_HEIGHT_GEOM_N_BINS+1))))
            {
                /*accumulate points with cruising age 0*/
                if (psSnrPnt->uCruisingAge == ZERO)
                {
    #ifdef US_D_OD_HEIGHT_GRL_SKIP_LONES
                    if ((psSnrPnt->uPntStat & US_D_PNTSTAT_DIRECT_ONLY) != ZERO)
                    {                        
                        /* do nothing */
                    }
                    else
    #endif
                    {                       
                        /* bin counter for sigma */
                        auBinCounter_sigma[uBinIdx][uGrpIdx]++;    
                    }
                }
                    else{/*do nothing*/}   
            }
            else{/*do nothing*/}
#endif


            if ((psSnrPnt->fY > -US_POLE_EXT_CORNER_THSD_Y) && (psSnrPnt->fY < +US_POLE_EXT_CORNER_THSD_Y))
            {
                b_PoleExtract_PointsInMiddle = ME_TRUE;                             
            } else { /* do nothing */}
			if (((psSnrPnt->fY < -US_POLE_EXT_CORNER_THSD_Y) && (psSnrPnt->fY > -fHalfWidthY)) || ((psSnrPnt->fY > +US_POLE_EXT_CORNER_THSD_Y) && (psSnrPnt->fY < +fHalfWidthY)))
            {
                b_PoleExtract_PointsInCorner = ME_TRUE;                             
            } else { /* do nothing */}
        }//end for.
    }//end of second pass.
    else{/*do nothing*/}    


#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE) /* output debug info */
    g_DEBUG_fPointDistToBumper_sigma[uGrpIdx]= fPointDistToBumper; 
    /* set debug variable to see computed value */
    #if (US_D_OD_HGEOM_USE_DBG_FUNCS== ME_TRUE)
    g_fGeomStats_ConfThresh_DEBUG[uGrpIdx] = (uint8_t)fConfThresh; 
    #endif
#endif


    if ((b_PoleExtract_PointsInCorner == ME_TRUE) && (b_PoleExtract_PointsInMiddle == ME_FALSE))
	{
		g_PoleExtract_CornerLateDetection[uGrpIdx] = ME_TRUE;
	}
    for (uDivIdx=0; uDivIdx < US_D_OD_HGEOM_N_SIGMA_DIV; uDivIdx++)
    {
        /* get a decision for pole for sigma */ 
        g_uGeomStats_PoleDecision[uDivIdx][uGrpIdx] = UssOD_GeomStats_GetPoleDecision(uDivIdx, uGrpIdx, fPointDistToBumper, (float32_t)fabsf(fHalfWidthY), g_PoleExtract_CornerLateDetection[uGrpIdx] );  //currently uGrpIdx will always be rear. 


        if (g_uGeomStats_PoleDecision[uDivIdx][uGrpIdx] == ME_TRUE)
        {
            uPoleDecision = ME_TRUE; 
        }
        else{/*do nothing*/}
    }    



#ifdef  US_D_OD_HGEOM_SET_HEIGHT_FLG

    /////
    /* Third pass. set height flag of 2D points in window */
    /////
    if ((uPointsInWindow > 0u) && (uPoleDecision == ME_TRUE) &&( US_DD_ODH_EnablePoleExt == ME_TRUE ))
    {
		uRearCenterPoleDecision = ME_FALSE;
        /* Loop through all points in group */
        for (uListIdx = 0; uListIdx < uNumCurPnts; uListIdx++)
        {
            uPntIdx = puaGrpSnrPntSortIdx[uListIdx]; // Get the sorted point index
            psSnrPnt = &psaSnrPntList[uPntIdx];   // Get the record for this sorted point
              
            /* continue if we hit a deleted point */
            if (psSnrPnt->uConf == 0u) 
            {continue;}
            else{/*do nothing*/}

            /* skip points outside of window within region of interest: */
            if (((uGrpIdx == US_D_PHYS_GRP_REAR) && ((psSnrPnt->fX > fClosestX) || (psSnrPnt->fX < fClosestX-fDeltaXWindow))) || 
                ((uGrpIdx == US_D_PHYS_GRP_FRNT) && ((psSnrPnt->fX < fClosestX) || (psSnrPnt->fX > fClosestX+fDeltaXWindow))) || 
                (psSnrPnt->fY < -fHalfWidthY-fBorderY) ||
                (psSnrPnt->fY > +fHalfWidthY+fBorderY))
            {
                continue;
            }
            else{/*do nothing*/}

            if ((((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][uGrpIdx] == ME_TRUE) && ((psSnrPnt->fY >= -fHalfWidthY) && (psSnrPnt->fY <= +fHalfWidthY))) || /* center */
                ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_L][uGrpIdx] == ME_TRUE) && (psSnrPnt->fY >= fHalfWidthY)) || /* left (positive Y) */            
                ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_R][uGrpIdx] == ME_TRUE) && (psSnrPnt->fY <= -fHalfWidthY))) &&   /* right (positive Y) */        
				(psSnrPnt->uCruisingAge <= g_PoleExtrctCrusingAgeThsd)) /* Write high only when cruising age is low */
			{
                psSnrPnt->uHeight = TWO; /* set to high */
            } 
            else 
            { /* do nothing */}
		
			/* Overwrite Rear Center Pole decision if no point is written high*/
			if (((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR] == ME_TRUE) && ((psSnrPnt->fY >= -fHalfWidthY) && (psSnrPnt->fY <= +fHalfWidthY))) && /* center */
				(psSnrPnt->uCruisingAge <= g_PoleExtrctCrusingAgeThsd))
			{
				uRearCenterPoleDecision = ME_TRUE;
			}
			else
			{ /* do nothing */ 
			}

        }
		
		if (uRearCenterPoleDecision == ME_FALSE)
		{
			g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR] = ME_FALSE;
		}
    }
    else{/*do nothing*/}

#endif /* US_D_OD_HGEOM_SET_HEIGHT_FLG */

	/* Previous Sigma Value for center*/
	g_PrevSigma[uGrpIdx] = g_f_sigma_sq_last[US_D_OD_HGEOM_SIGMA_C][uGrpIdx];

}

#endif




#ifdef US_D_OD_HGEOM_COMPUTE_SIGMA 

/*===========================================================================
 * brief Compute mu and sigma from detected point fY:  
 *
 * param uint8_t uGrpIdx
 * param , float32_t fY - the point
 */
/* ===========================================================================
 * Name: UssOD_GeomStats_ComputeMuSigma	
 * Remarks:  DD-ID: {D04A45D6-9EB0-4f62-B79E-059DB8D5F958}
 * ===========================================================================*/
static void UssOD_GeomStats_ComputeMuSigma(uint8_t uDivIdx, uint8_t uGrpIdx, float32_t fY) 
{
    float32_t mu = 0.0f; 
    float32_t sigma_sq = 0.0f; 

    if (g_f_mu_last[uDivIdx][uGrpIdx]  >= US_D_OD_HGEOM_MU_INVALID)
    {
        mu = fY; 
        sigma_sq = 0.0f; 
    }
    else
    {
        mu = ((1.0f- g_fGeomStats_rho)*g_f_mu_last[uDivIdx][uGrpIdx]) + g_fGeomStats_rho*(fY); 
        sigma_sq = ((1.0f- g_fGeomStats_rho)*g_f_sigma_sq_last[uDivIdx][uGrpIdx]) + g_fGeomStats_rho*(fY-mu)*(fY-mu) ; 
    }

    g_f_mu_last[uDivIdx][uGrpIdx] = mu; 
    g_f_sigma_sq_last[uDivIdx][uGrpIdx] = sigma_sq; 
}


/*===========================================================================
 * brief Compute mu and sigma from detected point fY:  
 *
 * param uint8_t uGrpIdx
  */
 /* ===========================================================================
 * Name: UssOD_GeomStats_ResetMuSigma	
 * Remarks:  DD-ID: {1295D2A5-811E-481d-BC68-82A0C7D49E92}
 * ===========================================================================*/
 static void UssOD_GeomStats_ResetMuSigma(uint8_t uDivIdx, uint8_t uGrpIdx) 
 {
    g_f_mu_last[uDivIdx][uGrpIdx] = US_D_OD_HGEOM_MU_INVALID; 
    g_f_sigma_sq_last[uDivIdx][uGrpIdx] = 0.0f; 
 }


/*===========================================================================
 * brief Determine if a obstacle is a pole from distribution of detected points in window
 *
 * param float32_t sigma_sq -- sigma squared (i.e. sigma=sqrtf(sigmasq)))
 * param float32_t fPointDistToBumper -- distance to bumper of closest point. 
 * return uint8_t ME_TRUE if pole, otherwise ME_FALSE
 * remarks note, it is "sigma squared" here, not sigma 
 */
/* ===========================================================================
 * Name:UssOD_GeomStats_GetPoleDecision	
 * Remarks:  DD-ID:{6BB49633-C3FF-40b9-A5AB-5BA1B5BDB3F0}
 * ===========================================================================*/

static uint8_t UssOD_GeomStats_GetPoleDecision(uint8_t uDivIdx, uint8_t uGrpIdx, float32_t fPointDistToBumper, float32_t fSnrSideY, uint8_t uCornerLateDetection)
{

    /* 
    set the values of 0.1 for Rho and a sigma_Y threshold of 25
    a decision for pole 
        IF sigma_y less than 25 then is Pole 
            and   X from bumper is < 2.2m 
            and  at least one of the bins in teh geometric filter has > 5 points 
    */ 

        
    uint8_t uPoleDecision   = (bool_t)ME_FALSE; 
    bool_t bBinCountFlag    = (bool_t)ME_FALSE; 
    bool_t bBumperDistFlag  = (bool_t)ME_FALSE; 
    bool_t bDistThreshFlag  = (bool_t)ME_FALSE; 
    bool_t bSigmaThreshFlag = (bool_t)ME_FALSE; 
    bool_t bMuFlag          = (bool_t)ME_FALSE; 
    uint8_t uBinIdx;
    uint8_t uSpdCtrld_BinCounterThresh; 
	
	/* Pole Extractor Dist to bumper threshold Noise - No noise */
	/* distance thrshold flag and bin counter flag */

	if (UssMgr_eGetGrpState(US_D_PHYS_GRP_REAR) == SYSMGR_GRPSTATE_NOISY )
	{
		g_DistToBumperThresh[US_D_PHYS_GRP_REAR][ZERO] = US_D_OD_HGEOM_DST_BUMP_TH_REAR_NOISE;
		g_DistToBumperThresh[US_D_PHYS_GRP_REAR][ONE] = US_D_OD_HGEOM_DST_BUMP_TH_OFST_NOISE;
		g_uBinCounterThresh[US_D_PHYS_GRP_REAR][ZERO] = US_D_OD_HGEOM_BINCNTTHRESH_REAR_NOISE;
		g_uBinCounterThresh[US_D_PHYS_GRP_REAR][ONE] = US_D_OD_HGEOM_BINCNTTHRESH_OFST_NOISE;
	}
	else
	{
		g_DistToBumperThresh[US_D_PHYS_GRP_REAR][ZERO] = g_PoleExtrct_DistBumpRear;
		g_DistToBumperThresh[US_D_PHYS_GRP_REAR][ONE] = g_PoleExtrct_DistBumpOfst;
		g_uBinCounterThresh[US_D_PHYS_GRP_REAR][ZERO] = g_PoleExtrct_BinCntRear;
		g_uBinCounterThresh[US_D_PHYS_GRP_REAR][ONE] = g_PoleExtrct_BinCntOfst;
	}
		
	if (UssMgr_eGetGrpState(US_D_PHYS_GRP_FRNT) == SYSMGR_GRPSTATE_NOISY )
	{
		g_DistToBumperThresh[US_D_PHYS_GRP_FRNT][ZERO] = US_D_OD_HGEOM_DST_BUMP_TH_FRNT_NOISE;
		g_DistToBumperThresh[US_D_PHYS_GRP_FRNT][ONE] = US_D_OD_HGEOM_DST_BUMP_TH_OFST_NOISE;
		g_uBinCounterThresh[US_D_PHYS_GRP_FRNT][ZERO] = US_D_OD_HGEOM_BINCNTTHRESH_FRNT_NOISE;
		g_uBinCounterThresh[US_D_PHYS_GRP_FRNT][ONE] = US_D_OD_HGEOM_BINCNTTHRESH_OFST_NOISE;
	} 
	else
	{
		g_DistToBumperThresh[US_D_PHYS_GRP_FRNT][ZERO] = g_PoleExtrct_DistBumpFrnt;
		g_DistToBumperThresh[US_D_PHYS_GRP_FRNT][ONE] = g_PoleExtrct_DistBumpOfst;
		g_uBinCounterThresh[US_D_PHYS_GRP_FRNT][ZERO] = g_PoleExtrct_BinCntFrnt;
		g_uBinCounterThresh[US_D_PHYS_GRP_FRNT][ONE] = g_PoleExtrct_BinCntOfst;
	}
   

    uint8_t uBinType = (uDivIdx==US_D_OD_HGEOM_SIGMA_C)?US_D_OD_HGEOM_PARAM_REGULAR:US_D_OD_HGEOM_PARAM_OFFSET; 
    const uint8_t fVehSpeed = UssCom_F_GetVehSpeed();

    /* check if sigma is less than threshold */
    if (g_f_sigma_sq_last[uDivIdx][uGrpIdx] < g_fGeomStats_SigmaYThresh_sq)
    {
        bSigmaThreshFlag = (bool_t)ME_TRUE; 
    }        
    else{/*do nothing*/}           

    /* check that mean Y coordinate is in proper spot */
    if (((uDivIdx==US_D_OD_HGEOM_SIGMA_C) && ((g_f_mu_last[uDivIdx][uGrpIdx] >= -fSnrSideY) && (g_f_mu_last[uDivIdx][uGrpIdx] <= +fSnrSideY)))  ||
        ((uDivIdx==US_D_OD_HGEOM_SIGMA_L) && ((g_f_mu_last[uDivIdx][uGrpIdx] >= +fSnrSideY))) ||
        ((uDivIdx==US_D_OD_HGEOM_SIGMA_R) && ((g_f_mu_last[uDivIdx][uGrpIdx] <= -fSnrSideY))))
    {
        bMuFlag = (bool_t)ME_TRUE; 
    }    
    else{/*do nothing*/}      


    uSpdCtrld_BinCounterThresh = (g_uBinCounterThresh[uGrpIdx][uBinType] - (uint8_t)((float32_t)fmaxf(0.0f , fVehSpeed - 4.0f)/2.0f));
    /* ensure there is at least one detection in the bin: */
    if (uSpdCtrld_BinCounterThresh < 1u)
	{ 
		uSpdCtrld_BinCounterThresh = 1u;
	}
	else if ((UssCom_F_GetVehSpeed() > 5.5f) && (UssMgr_eGetGrpState(uGrpIdx) == SYSMGR_GRPSTATE_NOISY))
	{
		uSpdCtrld_BinCounterThresh = g_PoleExtract_BinCntNoiHspd;
	}
	else{/*do nothing*/}


    /* if center pole extractor */
    if (uDivIdx == US_D_OD_HGEOM_SIGMA_C)
    {
        for (uBinIdx=0;uBinIdx<US_D_OD_HEIGHT_GEOM_N_BINS;uBinIdx++)
        {    
            /* check if the bin counter exceeds bin counter threshold in any center bin */
            if (auBinCounter_sigma[uBinIdx][uGrpIdx] > uSpdCtrld_BinCounterThresh)
            {            
                bBinCountFlag = (bool_t)ME_TRUE;         
        
                break; 
            }
            else{/*do nothing*/}
        }    
    }
    else /* otherwise */
    {
        /* determine bin index based on division (check one bin only) */
        uBinIdx = (uDivIdx == US_D_OD_HGEOM_SIGMA_R)?US_D_OD_HEIGHT_GEOM_N_BINS:(US_D_OD_HEIGHT_GEOM_N_BINS+1u); 
        if (auBinCounter_sigma[uBinIdx][uGrpIdx] > uSpdCtrld_BinCounterThresh)
        {            
                bBinCountFlag = (bool_t)ME_TRUE; 
        }
        else{/*do nothing*/}
    }
    if(g_PoleExtract_CornerLateDetection[uGrpIdx] ==ME_TRUE )
    {
        bBinCountFlag = ME_TRUE;
    }

        
    /* check if bumper is less than 2.2m */
    if ((fPointDistToBumper <= g_fGeomStats_MinXDist[uGrpIdx][uBinType])&&(fPointDistToBumper >= g_fGeomStats_MaxXDist[uGrpIdx][uBinType]))
    {
        bBumperDistFlag = (bool_t)ME_TRUE; 
    }
    else{/*do nothing*/}

    /* distance thrshold flag */
    if (fPointDistToBumper < g_DistToBumperThresh[uGrpIdx][uBinType])
    {
        bDistThreshFlag = (bool_t)ME_TRUE; 
    }    
    else{/*do nothing*/}

    /* lock decision if distance is less than DistToBumperThresh */
    if ((g_uGeomStats_PoleDecision[uDivIdx][uGrpIdx] == ME_FALSE ) && ((bool_t)ME_TRUE == bDistThreshFlag) )
	{
		uPoleDecision = ME_FALSE;
	}
    /* if all four conditions are satisfied, then it is a pole for sure */
    else if (((bool_t)ME_TRUE == bSigmaThreshFlag) && ((bool_t)ME_TRUE == bBumperDistFlag ) && ((bool_t)ME_TRUE == bBinCountFlag) && ((bool_t)ME_TRUE == bMuFlag))
    {
        uPoleDecision = ME_TRUE; 
    }
    else{/*do nothing*/}

#if (US_D_OD_HEIGHT_GEOM_DEBUG == ME_TRUE)
    g_uGeomStats_PoleDBGFlag[uDivIdx][uGrpIdx] = bSigmaThreshFlag + (bBinCountFlag<<1u) + (bBumperDistFlag<<2u) + (uPoleDecision<<3u) + (bDistThreshFlag<<4u)+ (bMuFlag<<5u);     

    g_uSpdCtrld_BinCounterThresh[uDivIdx][uGrpIdx] = uSpdCtrld_BinCounterThresh; //set to global for debugging; 

#endif

    return uPoleDecision; 

}





#if (US_D_OD_HGEOM_USE_DBG_FUNCS == ME_TRUE)
/* Generic deubg output func */
float32_t UssOD_GetGeomDebugFloat(uint8_t uSelection)
{
    float32_t fRetOutput = 0.0f;

    switch( uSelection )
    {
        case 11u:
            fRetOutput = g_fMeanHeight;
        break;
        case 12u:
            fRetOutput = g_fClosestX;
        break;
        case 13u:
        {
#ifdef US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
            uint8_t uDebugBinIdx;
            for (uDebugBinIdx = 0; uDebugBinIdx < US_D_OD_HEIGHT_GEOM_N_BINS; uDebugBinIdx++)
            {
                fRetOutput += auBinHist[uDebugBinIdx];
            }
            fRetOutput = (fRetOutput / US_D_OD_HEIGHT_GEOM_N_BINS);
            break;
#endif
        }
        case 14u:
            fRetOutput = g_DEBUG_fLatchDist;
            break;
        case 15u:
            fRetOutput = g_DEBUG_fMaxBinHist;
            break;
        case 16u:
            fRetOutput = g_DEBUG_fClosestX_fresh;
            break;
        case 17u:
#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH
            fRetOutput = g_fCruiseBinRatio;
#endif
            break;
        case 18u:
            fRetOutput = g_DEBUG_fUnlatchDist;
            break;
        case 19u:
            fRetOutput = g_DEBUG_fMinUnlatchDist;
            break;
        case 20u:
            fRetOutput = g_DEBUG_fPointDistToBumper;
            break;
        default:
            fRetOutput = 12.34f;
#ifdef US_D_OD_HEIGHT_GEOM_BIN_PERSISTANCE
            if ( (uSelection > 0u) && (uSelection < 6u) )
            {
                fRetOutput = auBinHist[uSelection - 1u];
            }
#endif 
        break;
    }
    
    return fRetOutput;
}

/* Generic deubg output func */
uint32_t UssOD_GetGeomDebug(uint8_t uSelection)
{
    uint32_t uRetOutput = ZERO;
    
    switch( uSelection )
    {
        case 1u:
            uRetOutput = g_uPointsInWindow;
            break;
        case 2u:
        {
            uint8_t uDebugBinIdx;
            for (uDebugBinIdx = 0; uDebugBinIdx < US_D_OD_HEIGHT_GEOM_N_BINS; uDebugBinIdx++)
            {
                uRetOutput |= (g_abBinNotEmpty[uDebugBinIdx] & 0x0001u) << uDebugBinIdx; /* PRQA S 1821 */ 
            }            
            break;
        }
#ifdef US_D_OD_HEIGHT_GEOM_LATCH_WIDE_STATUS
        case 3u:
            uRetOutput = (uint32_t)bWideLatchActive;
            break;
#endif
        case 4u:
            uRetOutput = (uint32_t)g_bIsCurbWall;
            break;
        case 5u:
            uRetOutput = (uint32_t)g_DEBUG_bmapBinAccu;
            break;
        case 6u:
            uRetOutput = (uint32_t)g_DEBUG_HighGuess;
            break;
        /* 7 - 11 used in default */
        case 12u:
            uRetOutput = (uint32_t)bResetLatch;
            break;
        /* 13 - 17 used in default */
        case 18u:
            uRetOutput = (uint32_t)g_DEBUG_AdjLatchMaxAge;
            break;
        case 19u:
            uRetOutput = (uint32_t)g_DEBUG_uLatchDecisions;
            break;
        case 20u:
            uRetOutput = (uint32_t)g_DEBUG_AdjLatchMinCr;
            break;
        case 21u:
            uRetOutput = g_DEBUG_LatchPassMap;
            break;
        case 22u:
            uRetOutput = (uint32_t)g_DEBUG_LoneCrZero;
            break;
        case 23u:
            uRetOutput = (uint32_t)g_uLastNewObservationCounter;
            break;
        default:
            uRetOutput = 0xFFFFFFF0U;
#ifdef US_D_OD_HEIGHT_GEOM_RESET_LATCH  
            if ( (uSelection >= 7u) && (uSelection <= 11u) )
            {
                uRetOutput = auBinCounter[uSelection - 7u];
            }
            if ( (uSelection >= 13u) && (uSelection <= 17u) )
            {
                uRetOutput = auBinMaxAge[uSelection - 13u];
            }
#endif 
            break;
    }
    
    return uRetOutput;
}

#endif /* US_D_OD_HGEOM_USE_DBG_FUNCS */


#define US_D_GEOM_IS_LOW_VAL    ONE
#define US_D_GEOM_IS_HIGH_VAL   ZERO
/* returns true when a low object is detected in rear bumper */
/* ===========================================================================
 * Name: UssOD_bIsLowObjectRear	
 * Remarks:  DD-ID: {909DFA6A-D717-4355-A2DA-07169577D831} 
 * ===========================================================================*/
uint8_t UssOD_bIsLowObjectRear(void)
{
    uint8_t uRetIsLow = US_D_GEOM_IS_HIGH_VAL; /* default High */
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
    const bool_t bGetWallGuessbyBumper_Persist = UssMgr_bGetWallGuessbyBumper_Persist(US_D_PHYS_GRP_REAR);
    #else
    const bool_t bGetWallGuessbyBumper_Persist = FALSE;
    #endif
    const bool_t bFilteredHeightFlag = USSMgr_Height_GetFilteredHeightFlag(US_D_PHYS_GRP_REAR);
#if 0
    if (g_uLastNewObservationCounter >= g_uObsCountThresh)
    {
        bLastObservationPass = ME_TRUE;
    }
#endif
    #if (US_DD_ODH_UseGlobHeightForRAEB == US_E_HDECIDE_FUNC) /* #1 call function (by default will be only DNN) */
    {
        uRetIsLow = UssOD_bIsLowObject(US_D_PHYS_GRP_REAR);
    }
    #elif (US_DD_ODH_UseGlobHeightForRAEB == US_E_HDECIDE_ALL_SAFE) /* #2 or all three together + safety */
    {
        if ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR] == ME_TRUE) ||
            ( bGetWallGuessbyBumper_Persist == (bool_t)ME_TRUE) ||
            ( bFilteredHeightFlag == (bool_t)ME_TRUE) ||
            (g_uLastNewObservationCounter >= g_uObsCountThresh) /* 5 near points (safety) */           
           )
        {
            uRetIsLow = US_D_GEOM_IS_HIGH_VAL;
        }    
        else
        {
            uRetIsLow = US_D_GEOM_IS_LOW_VAL;
        }
    }
    #elif (US_DD_ODH_UseGlobHeightForRAEB == (uint8_t)US_E_HDECIDE_WALL_POLE) /* #3 only wall and pole (no safety) */
    {
        if ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR] == ME_TRUE) ||
            (bGetWallGuessbyBumper_Persist == (bool_t)ME_TRUE) 
           )
        {
            uRetIsLow = US_D_GEOM_IS_HIGH_VAL;
        }    
        else
        {
            uRetIsLow = US_D_GEOM_IS_LOW_VAL;
        }
    }
    #elif (US_DD_ODH_UseGlobHeightForRAEB == (uint8_t)US_E_HDECIDE_ALL) /* #4 or all three together (no safety) */
    {
        if ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR] == ME_TRUE) ||
            (bGetWallGuessbyBumper_Persist == (bool_t)ME_TRUE) ||
            (bFilteredHeightFlag == (bool_t)ME_TRUE)            
           )
        {
            uRetIsLow = US_D_GEOM_IS_HIGH_VAL;
        }    
        else
        {
            uRetIsLow = US_D_GEOM_IS_LOW_VAL;
        }
    }
    #elif (US_DD_ODH_UseGlobHeightForRAEB == (uint8_t)US_E_HDECIDE_OG_ALL_SAFE) /* #5 'the original way' AND 'any of three conditions' OR safety */
    {
        if (((ME_TRUE==abIsHighObject[US_D_PHYS_GRP_REAR]) && /* old way */
             ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][US_D_PHYS_GRP_REAR] == ME_TRUE) || /* three conditions */
              (bGetWallGuessbyBumper_Persist == (bool_t)ME_TRUE) ||
              (bFilteredHeightFlag == (bool_t)ME_TRUE))) ||
            (g_uLastNewObservationCounter >= g_uObsCountThresh) /* 5 near points (safety) */           
           )
        {
            uRetIsLow = US_D_GEOM_IS_HIGH_VAL;
        }    
        else
        {
            uRetIsLow = US_D_GEOM_IS_LOW_VAL;
        }
    }
    #elif (US_DD_ODH_UseGlobHeightForRAEB == (uint8_t)US_E_HDECIDE_OG_ONLY) /* #6 'the original way' */
    {
        #ifdef US_D_OD_HGEOM_COMPUTE_GRPHEIGHT
            if(ME_TRUE == abIsHighObject[US_D_PHYS_GRP_REAR])
            {
                uRetIsLow = US_D_GEOM_IS_HIGH_VAL;
            }
        #else
            uRetIsLow = US_D_GEOM_IS_HIGH_VAL;//sets to "high" so braking is enabled
        #endif
    }
    #else
    {
        uRetIsLow = US_D_GEOM_IS_HIGH_VAL;
    }
    #endif
    return uRetIsLow;
}


/* returns true when a low object is detected in rear bumper */
/* ===========================================================================
 * Name: UssOD_bIsLowObjectFront	
 * Remarks:  DD-ID: {D8F21191-F646-4260-A3A5-D95417E6D22C}
 * ===========================================================================*/
uint8_t UssOD_bIsLowObjectFront(void)
{
#ifdef US_D_OD_HGEOM_COMPUTE_GRPHEIGHT
    return (uint8_t)(ME_FALSE==abIsHighObject[US_D_PHYS_GRP_FRNT]);
#else
    return (uint8_t) !USSMgr_Height_GetFilteredHeightFlag(US_D_PHYS_GRP_FRNT);  //sets to "high" so braking is enabled
#endif
}
/* ===========================================================================
 * Name: UssOD_bIsLowObject	
 * Remarks:  DD-ID: {23827FAB-1E64-4ef9-B729-C759D4FDC8A8} 
 * ===========================================================================*/
uint8_t UssOD_bIsLowObject(uint8_t u_phys_grp)
{
    const bool_t bFilteredHeightFlag = USSMgr_Height_GetFilteredHeightFlag(u_phys_grp);
#ifdef US_D_OD_HGEOM_COMPUTE_SIGMA 
    /* if obstacle is a pole then object is never low */    
    /* for now, we can OR the decision together (later it can be split into CENTER, LEFT, RIGHT)*/
    if ( ((g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_C][u_phys_grp] == ME_TRUE) ||
          (g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_R][u_phys_grp] == ME_TRUE) ||
          (g_uGeomStats_PoleDecision[US_D_OD_HGEOM_SIGMA_L][u_phys_grp] == ME_TRUE)) && (US_DD_ODH_UsePoleFlag != ZERO) )
    {
        return (uint8_t) ME_FALSE; 
    }
#endif /*US_D_OD_HGEOM_COMPUTE_SIGMA */
#ifdef US_D_MGR_WALL_HIGH_FLAGS
    /* High confidence that object is a wall based on echoes */
    if( (UssMgr_bGetWallGuessbyBumper_Persist(u_phys_grp) == ME_TRUE) && (US_DD_ODH_UseWallFlag != ZERO) )
    {
        return (uint8_t) ME_FALSE;
    }
#endif /*US_D_MGR_WALL_HIGH_FLAGS*/
    /* Normal DNN decision */
    #if(US_DD_ODH_UseDNNFlag != ZERO)
    {
        return (uint8_t) ((bool_t)ME_FALSE == bFilteredHeightFlag); 
    }
    #endif
#ifdef US_D_MGR_WALL_HIGH_FLAGS
    /* If DNN is enabled, should never reach here - but check flag anyways in case logic changes later */
    #if( (US_DD_ODH_UsePoleFlag == ZERO) && (US_DD_ODH_UseWallFlag == ZERO) && (US_DD_ODH_UseDNNFlag == ZERO) )
    {
        /* ALL options off, default high*/
        return (uint8_t)ME_TRUE;
    }
    #else
    {
        /* something is enabled, but they all failed - return low*/
        return (uint8_t)ME_TRUE;
    }
    #endif
#endif /*US_D_MGR_WALL_HIGH_FLAGS*/
    return (uint8_t)ME_TRUE;
}

/*
  AlertCHR,0
  AlertLHR,1
  AlertRHR,2
  AlertCHF 3
  AlertLHF 4
  AlertCHF 5
  */
void UssOD_setArcSignal(uint32_t arcs_from_feature, uint8_t current_arc) /* PRQx 1503 */ /* Debug designed for export/extern */
{
#if (US_D_ENABLE_OVRWR_CANDBG == ME_TRUE)
    if(arcs_from_feature > 10u)
    {
        g_uArcsFromFeature[current_arc] = 10u;
    }
    else
    {
        g_uArcsFromFeature[current_arc] = (uint8_t) arcs_from_feature;
    }
#else
    (void)arcs_from_feature;
    (void)current_arc;
#endif
}


#endif /*  US_D_OD_HEIGHT_GEOM_STATS */

#endif /*US_D_OD_HEIGHT_GEOM_STATS*/
