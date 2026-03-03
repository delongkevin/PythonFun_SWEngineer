/*
 * US_ObjDetTriang.h
 *
 *  Created on: Sep 8, 2021
 *      Author: jonapais
 */
#ifndef US_OBJDETTRIANG_H_
#define US_OBJDETTRIANG_H_
#include "US_ME_Typedefs_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ObjDetMinDist.h"



#define US_D_OD_DEBUG_TRIANG    (ME_FALSE)
#define US_D_OD_USE_DIRECT_DIST_ODO (ME_TRUE)

/* Defining this here because US_S_SnrPoint_t needs to know */
#define US_D_OD_USE_CR_DIST_KILL  (ME_TRUE) /* should silently do nothing without odometry*/
#define US_D_OD_KEEP_DEAD_PTS     (ME_FALSE)

#if (US_D_OD_KEEP_DEAD_PTS == ME_TRUE)
    #define US_D_OD_KDP_USE_CR_DEBUG    (ME_TRUE)
#endif

#define US_D_OD_MATCH_DIST_X              (10.0f)
#define US_D_OD_MATCH_DIST_Y              (10.0f)
#define US_D_OD_MATCH_DIST_X_NOISY        (20.0f)
#define US_D_OD_MATCH_DIST_Y_NOISY        (20.0f)
#define US_D_OD_MATCH_DIST_X_D_ONLY       (20.0f)
#define US_D_OD_MATCH_DIST_Y_D_ONLY       (20.0f)
#define US_D_OD_MATCH_DIST_BIAS_Y_D_ONLY  (40.0f)
#define US_D_OD_MATCH_DIST_BIAS_X_D_ONLY  (15.0f)
#define US_D_OD_BIAS_MATCH_FLAG           (0x80u)
#define US_D_OD_BIAS_MATCH_MASK           (0x7Fu)

#define US_D_OD_MATCH_RANGE_MATCH_DIST (15.0f)
#define US_D_OD_MATCH_RANGE_MIN_CONF   (35u)
#define US_D_OD_NO_MATCH_FOUND (0xFFu)

#define US_D_OD_DEFAULT_DIST          (511u)
#define US_D_OD_DEFAULT_DIST_SQ       ((float32_t) US_D_OD_DEFAULT_DIST * (float32_t) US_D_OD_DEFAULT_DIST)
#define US_D_OD_DIST_MIN_CONF_THRESH  (50u)

#define US_D_OD_MAX_ECHOS_FOR_TRIANG  (2u)

#define US_D_MAX_NUM_SINGLE_SENSOR_MEAS (32u)

#if (US_D_OD_MAX_ECHOS_FOR_TRIANG > US_D_APP_MAX_ECHOES_BUFF)
   #error "US_D_OD_MAX_ECHOS_FOR_TRIANG must be <= US_D_APP_MAX_ECHOES_BUFF!!!"
#endif

/*
 * Size of point buffers for each physical group to be triangulated.
 */
#define US_D_POINT_BUFFER_SIZE (US_D_OD_MAX_ECHOS_FOR_TRIANG * TWO * US_D_OD_MAX_ECHOS_FOR_TRIANG * US_MAX_NUM_SENSORS_PER_GRP)
#define US_D_DEAD_PNT_BUFF_SIZE (US_D_POINT_BUFFER_SIZE)

/* Max values for point data values */
#define US_D_OD_PNT_MAX_AGE             (127u)
#define US_D_OD_PNT_MAX_CONF            (100u)
#define US_D_OD_PNT_MAX_CRUISING_AGE    (63u)


/* Bit fields for point measurement status */
/*#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE*/

#define US_D_PNTSTAT_NULL                    (ZERO)
#define US_D_PNTSTAT_MEASURED                (BIT0)
#define US_D_PNTSTAT_MEAS_MULT_SNRS          (BIT1)
#define US_D_PNTSTAT_MEAS_MULT_CYCLES        (BIT2)
#define US_D_PNTSTAT_DIRECT_ONLY             (BIT3)
#define US_D_PNTSTAT_DIR_IND_TRIANG          (BIT4)
#define US_D_PNTSTAT_DIR_DIR_TRING           (BIT5)
#define US_D_PNTSTAT_TDIR_DIR_TRIANG         (BIT6)
#define US_D_PNTSTAT_TRIANG_LATCHED_         (BIT7)  /* DEPRICATED */
#define US_D_PNTSTAT_DIRECT_ONLY_LTCH        (BIT8)
#define US_D_PNTSTAT_DIR_IND_TRIANG_LTCH     (BIT9)
#define US_D_PNTSTAT_DIR_DIR_TRING_LTCH      (BIT10)
#define US_D_PNTSTAT_TDIR_DIR_TRIANG_LTCH    (BIT11)
#define US_D_PNTSTAT_CONF_CAPPED_LTCH        (BIT12)
#define US_D_PNTSTAT_RESERVED_2              (BIT13)
#define US_D_PNTSTAT_RESERVED_3              (BIT14)
#define US_D_PNTSTAT_RESERVED_4              (BIT15)

#define US_D_PNTSTAT_PERSIST_MASK            (US_D_PNTSTAT_MEAS_MULT_CYCLES |    \
                                              US_D_PNTSTAT_DIRECT_ONLY_LTCH |    \
                                              US_D_PNTSTAT_DIR_IND_TRIANG_LTCH | \
                                              US_D_PNTSTAT_DIR_DIR_TRING_LTCH |  \
                                              US_D_PNTSTAT_TDIR_DIR_TRIANG_LTCH | \
                                              US_D_PNTSTAT_CONF_CAPPED_LTCH)

#define US_D_PNTSTAT_TRIANG_LATCHED_BITS (US_D_PNTSTAT_DIR_IND_TRIANG_LTCH | US_D_PNTSTAT_DIR_DIR_TRING_LTCH)
/*#endif*/

/* Bit fields for echo usage status */
#define US_D_ECHO_CACHE_STAT_IDLE             (ZERO)
#define US_D_ECHO_CACHE_L0_ACTIVE             (BIT0)  // Do not reorder these 3 flags (These bits are checked by shifting in loops.)
#define US_D_ECHO_CACHE_L1_ACTIVE             (BIT1)  // Do not reorder these 3 flags
#define US_D_ECHO_CACHE_L2_ACTIVE             (BIT2)  // Do not reorder these 3 flags
#define US_D_ECHO_CACHE_L1_LATCHED            (BIT3)  // L1 Min distance limit reached.  Measurement latched.

#define US_D_ECHO_USAGE_STAT_UNUSED           (ZERO)
#define US_D_ECHO_USAGE_STAT_USED_TD_TRIANG   (BIT0)  // Temporal Direct Triang
#define US_D_ECHO_USAGE_STAT_USED_DD_TRIANG   (BIT1)  // Direct-Direct Triang
#define US_D_ECHO_USAGE_STAT_USED_DI_TRIANG   (BIT2)  // Direct-Indirect Triang
#define US_D_ECHO_USAGE_STAT_USED_LONE        (BIT3)  // Considered for lone.


//#define US_D_ECHO_USAGE_STAT_HAS_PNT_IDX      (BIT10) // Point idx for update

//#define US_D_ECHO_USAGE_PERSISTANT_FLAGS (US_D_ECHO_CACHE_L0_ACTIVE | US_D_ECHO_CACHE_L1_ACTIVE | US_D_ECHO_CACHE_L2_ACTIVE | US_D_ECHO_CACHE_L1_LATCHED);
//#define UD_D_ECHO_USAGE_DD_CHECKED_BITS (US_D_ECHO_USAGE_STAT_DD_CHKED_AS_L | US_D_ECHO_USAGE_STAT_DD_CHKED_AS_R);

// Indices for US_S_DirEchoCache_t[idx].US_S_EchoCacheEntry_t
#define US_D_ECHO_CACHE_L0_PREV               (ZERO)
#define US_D_ECHO_CACHE_L1_MID                (ONE)
#define US_D_ECHO_CACHE_L2_FAR                (TWO)
#define US_D_NUM_ECHO_CACHE_ENTRIES           (THREE)

#define US_D_CACHE_MIN_SNR_BASE_DIST        (7.0f)
#define US_D_CACHE_MID_SNRDIST_LIM          (75u)  // 1x
#define US_D_CACHE_MID_SNRDIST_MAX          (US_D_CACHE_MID_SNRDIST_LIM * TWO ) // 2x
#define US_D_CACHE_SNRDIST_L2_L3_MAXLIM     (US_D_CACHE_MID_SNRDIST_LIM * THREE) // 3x
#define US_D_CACHE_SNRDIST_L0_MAXLIM        (250U)

#define US_D_CACHE_STANDSTILL_TIMEOUT       (5000u)

/* Bit fields for dead point status */
#if (US_D_OD_KEEP_DEAD_PTS == ME_TRUE)
    #define US_D_DPS_NULL       (ZERO)
    #define US_D_DPS_ACCEPTED   (BIT0)
    #define US_D_DPS_KEPT       (BIT1)
    #define US_D_DPS_REMEAS     (BIT2)
    #define US_D_DPS_DIST_DEL   (BIT3)
#endif

//#define US_D_OD_HEIGHT_GEOM_BG_NOISE_TRACK

typedef struct US_S_SnrPoint_s
{
#if (US_D_OD_DEBUG_TRIANG == ME_TRUE)
    float32_t fArea;
    float32_t fHeight;
    /* End debugging*/
#endif

    /* For point map */
    float32_t fX;
    float32_t fY;
    float32_t fAccuX; /* accumulated movement of the 2D point - reset to 0 when Cruising age => 0 */
    float32_t fAccuY;

    uint16_t  uLowDirDist;
    uint16_t  uIndirDist;
    uint16_t  uBaseDist;
    uint16_t  uPntStat;
#if (US_D_OD_KEEP_DEAD_PTS == ME_TRUE)
    uint8_t   uDeadPntStat;
    uint8_t   uMaxConf;
#endif
    uint8_t   uSectorIdx;
    uint8_t   uDirSnrIdx;
    uint8_t   uIndirSnrIdx;
    uint8_t   uAge;
    uint8_t   uCruisingAge;
    uint8_t   uConf;
    uint8_t   uHeight;
    uint8_t   uDecRate;
    uint8_t   uOutputId;
} US_S_SnrPoint_t;

typedef struct US_S_EchoCacheEntry_s
{
    float32_t fVirtualSnrPosX;      // X Sensor position adjusted by odometry, vehicle coord system
    float32_t fVirtualSnrPosY;      // Y Sensor position adjusted by odometry, vehicle coord system
    float32_t fLoneSnrAngle;        // Angle of vehicle adjusted by odometry

    float32_t fPairDist;            // Pair Dist on this meas cycle
    float32_t fDeltaX;              // Delta X this cycle/
    float32_t fDeltaY;              // Delta X this cycle/
    uint16_t  uDirDist;             // Storage for direct echo

    // Other measurement data.
    uint16_t uSignalStrength;
    bool_t   bLargeObj;

    // status flags
    uint8_t uMeasUseStat;
} US_S_EchoCacheEntry_t;

typedef struct US_S_DirEchoCache_s
{
    US_S_EchoCacheEntry_t sEchoCacheEntry[US_D_NUM_ECHO_CACHE_ENTRIES];  /* Direct echo cache */
    uint32_t uTimeoutOfEchoCache;  /* Failsafe to clear old/unused cache records */
    uint8_t  uEchoCacheUseStat;  /* Stat for echo cache entries*/
} US_S_DirEchoCache_t;

typedef struct US_S_ObjDetCalcRec_s
{
    bool_t   bNearFieldSeen;
    uint32_t uNFDTimestamp;      // Timestamp when measurement was taken
    US_S_DirEchoCache_t sDirEchoCache;  // Status of usage of a particular dir echo
} US_S_ObjDetCalcRec_t;

void UssOD_CreateSortIdxLists(void);
void UssOD_ClearFiltDistances(bool_t bDoInit);
uint16_t * UssOD_GetPntMinDist(void);
uint16_t * UssOD_GetPntMidDist(void);
US_S_SnrPoint_t * UssOD_sGetSnrPntBuff(uint8_t uGrpIdx);
uint8_t * UssOD_sGetSnrPntSortIdxList(uint8_t uGrpIdx);
float32_t UssOD_CalcTriangAreaSq(float32_t fHalfDistToSnr, uint16_t uDistDir, uint16_t uDistIndir);
void UssOD_PerformEchoLocation(void);
void UssOD_ResetOdCalcs(bool_t bInitTriangDirDirStat);
US_S_ObjDetCalcRec_t * UssOD_psGetObjDetCalcs(void);
void UssOD_InitDirectEchoCache(void);

/*#ifdef US_D_OD_HEIGHT_GEOM_STATS - always needed since PA externs this*/
void UssOD_ComputeBackgroundNoiseLevel(uint8_t uGrpIdx);
/*#endif*/

#endif /* US_OBJDETTRIANG_H_ */
