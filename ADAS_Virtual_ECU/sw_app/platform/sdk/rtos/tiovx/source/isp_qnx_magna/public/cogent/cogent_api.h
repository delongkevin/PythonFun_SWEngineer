/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           cogent_api.h
 *  @brief          External API
 *
 *  @version        3.31
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           12.10.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef COGENT_API_H
#define COGENT_API_H
/* PRQA S 0342 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0881 ++ */
/* PRQA S 0723 ++ */
/* PRQA S 0647 ++ */
/* PRQA S 0930 ++ */
/* PRQA S 0646 ++ */
/* PRQA S 1281 ++ */

#ifdef __cplusplus
extern "C" {
#endif

#define ISP_FAST_LOCAL_VARIABLE __attribute__((section(".isp_tcm")))

#include <stdint.h>
#include <float.h>
#include "../../src/profiler.h"

#ifdef MAGNA_PSA
#include "isp/isp_cfg.h"
#include "isp/cisp.h"
#else
#include <errno.h>
#include <ti/drv/vhwa/include/ee_cfg.h>
#include <ti/drv/vhwa/include/fcp_cfg.h>
#include <ti/drv/vhwa/include/glbce_cfg.h>
#include <ti/drv/vhwa/include/h3a_cfg.h>
#include <ti/drv/vhwa/include/nf_cfg.h>
#include <ti/drv/vhwa/include/nsf4_cfg.h>
#include <ti/drv/vhwa/include/rawfe_cfg.h>
#endif

#ifdef ITEM_PROC_I
#undef ITEM_PROC_I
#endif
#ifdef ITEM_PROC_F
#undef ITEM_PROC_F
#endif
#define ITEM_PROC_I(X) X, /* PRQA S 3410 */ /* PRQA S 3453 */
#define ITEM_PROC_F(X) X, /* PRQA S 3410 */ /* PRQA S 3453 */
#include "../../src/items.h"

typedef enum
{
    CFG_ISP_NONE = 0,
    LIST_ISP_CFG()
    CFG_ITEM_ID_NUM,
}CFG_ITEM_ID;


typedef enum
{
    ADDITIONAL_PARAMS_START = CFG_ITEM_ID_NUM,
    /// sensor settings
    LIST_NON_ISP_CFG()
    #define ALGO_IMPL(NAME) NAME##_IN_FREQ, NAME##_IN_PHASE, NAME##_IN_ENABLED,
    #include "../../src/algo_reg.h"

    /// intermediate values
    ISP_INTERNAL_SECTION,
    LIST_INTERNAL_CFG()
    #define ALGO_IMPL(NAME) ISP_INTERNAL_##NAME##_DISABLE, ISP_INTERNAL_##NAME##_STATUS,
    #include "../../src/algo_reg.h"
    TABLE,

    PARAMS_NUM_ALL,
}ISP_ITEM_EXTENDED;



#define INVALID_VALUE FLT_MAX


#ifndef PC_VER
#ifdef MAGNA_PSA
#include <camera/camera_v3x_api.h>
#include <camera/camera_magna_api.h>
#else
/**
 * Camera output frame rate denominator.
 */
typedef enum {
    CAMERA_FR_DENOMINATOR_30_FPS = 1,
    CAMERA_FR_DENOMINATOR_15_FPS = 2,
    CAMERA_FR_DENOMINATOR_10_FPS = 3,
    CAMERA_FR_DENOMINATOR_5_FPS  = 6
} camera_frame_rate_denominator_t;

typedef enum {
    /**
     * To configure the  ISP to disable any manufacturing test.
     */
    ISP_MANUFACTURING_TEST_NONE,
    /**
     * To configure the ISP for Solid White Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_WHITE,
    /**
     * To configure the ISP for Solid Black Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_BLACK,
    /**
     * To configure the ISP for Solid Red Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_RED,
    /**
     * To configure the ISP for Solid Green Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_GREEN,
    /**
     * To configure the ISP for Solid Blue Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_BLUE,
    /**
     * To configure the ISP for 100% Vertical Color Bars test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_COLOR_BAR,
    /**
     * To configure the ISP for Fade−to−Gray Vertical Color Bars test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_COLOR_BAR_GRADIENT,
    /**
     * To configure the ISP for Walking 1s test pattern (12−bit)
       specific manufacturing test.
     */
    ISP_MANUFACTURING_WALKING,
    /**
     * Number of supported manufacturing tests.
     */
    ISP_MANUFACTURING_TEST_NUM
} v3xISP_ManufacturingTestType_t;

#endif
#else

typedef enum {
    /**
     * To configure the V3X ISP to disable any manufacturing test.
     */
    V3XISP_MANUFACTURING_TEST_NONE,
    /**
     * To configure the V3X ISP for specific manufacturing test.
     */
    V3XISP_MANUFACTURING_TEST_1,
    /**
     * Number of supported manufacturing tests.
     */
    V3XISP_MANUFACTURING_TEST_NUM
} v3xISP_ManufacturingTestType_t;


typedef enum {
    /* Configure ISP for human vision output video */
    ISP_MODE_HUMAN_VISION = 0,
    /* Configure ISP for machine vision output video */
    ISP_MODE_MACHINE_VISION = 1
} v3xISP_VisionModeType_t;

typedef struct {
    /**
     * Sharpen strength for L_Ld.
     */
    uint8_t                     ld;
    /**
     * Sharpen strength for L_Ldu.
     */
    uint8_t                     ldu;
    /**
     * Sharpen strength for L_Lu.
     */
    uint8_t                     lu;
} sharpStrength_t;


typedef struct {
    float32_t pre_roll_angle_z;
    float32_t angle_x;
    float32_t angle_y;
    float32_t angle_z;
    float32_t tr_vec[3];
} extrinsic_parameters_t;

typedef struct {
    float32_t fx;
    float32_t fy;
    float32_t cx;
    float32_t cy;
    float32_t K0;
    float32_t K1;
    float32_t K2;
    float32_t K3;
    float32_t K4;
    float32_t K5;
} intrinsic_parameters_t;
/**
 * Camera output frame rate denominator.
 */
typedef enum {
    CAMERA_FR_DENOMINATOR_30_FPS = 1,
    CAMERA_FR_DENOMINATOR_15_FPS = 2,
    CAMERA_FR_DENOMINATOR_10_FPS = 3,
    CAMERA_FR_DENOMINATOR_5_FPS  = 6
} camera_frame_rate_denominator_t;
#endif

#define FRAME_RATE_SWITCH_DELAY 100

// Max number of sensor registers, which are required by Cogent lib
#define MAX_COGENT_SENSOR_REG_NUM                   50

#define AR014X_SENSOR_WIDTH                         1344
#define AR014X_SENSOR_HEIGHT                        968
#define AR014X_MAX_WIDTH                            1280
#define AR014X_MAX_HEIGHT                           960
#define AR014X_SENSOR_STRIDE_IN_BYTES               (AR014X_MAX_WIDTH * 12 / 8)

#define AR0233_SENSOR_WIDTH                         2072
#define AR0233_SENSOR_HEIGHT                        1296
#define AR0233_MAX_WIDTH                            2048
#define AR0233_MAX_HEIGHT                           1280
#define AR0233_SENSOR_STRIDE_IN_BYTES               (AR0233_MAX_WIDTH * 12 / 8)

#define AR014X_DELAY_CMD                            0xffff
// Escape code to indicate that a list should be used for the following I2c entries.
// List max size is 20 items.
#define AR014X_LIST_CMD                             0xfffe

// Max number of embedded data rows provided by AR014X sensor
#define MAX_SUPPORTED_EMBEDDED_DATA_ROWS            16
// Max number of embedded statistics rows provided by AR014X sensor
#define MAX_SUPPORTED_EMBEDDED_STATS_ROWS           4

// Structure to hold a register/value pair
struct ar014x_reg {
    uint16_t reg;
    uint16_t val;
};



#ifdef MAGNA_PSA
struct ar014x_sensor_data {
    uint8_t embeddedData[MAX_SUPPORTED_EMBEDDED_DATA_ROWS][AR014X_SENSOR_STRIDE_IN_BYTES];
    uint8_t embeddedStats[MAX_SUPPORTED_EMBEDDED_STATS_ROWS][AR014X_SENSOR_STRIDE_IN_BYTES];
};
#else
struct ar014x_sensor_data {
    uint16_t *embeddedData;
    const uint8_t *embeddedStats;
    uint8_t num_embedded_data_lines;
    uint32_t embedded_data_size;
    uint32_t embedded_data_width;
    uint8_t num_embedded_stats_lines;
    uint32_t embedded_stats_size;
    uint32_t embedded_stats_width;
};
#endif

/**
 * Supported Magna camera sensor type.
 */
typedef enum {
    MAGNA_CAMERA_SENSOR_UNKNOWN,
    MAGNA_CAMERA_SENSOR_AR0143,
    MAGNA_CAMERA_SENSOR_AR0147,
    MAGNA_CAMERA_SENSOR_AR0233,
    MAGNA_CAMERA_SENSOR_OX3C
} magna_camera_sensor_type_t;

extern magna_camera_sensor_type_t magna_camera_sensor_type;

#ifdef MAGNA_PSA
/**
 * The meaning of the @c usageFlag field in the @c ispConfig_t / @c ispData_t
 * It indicates which ISP settings require update / has valid value.
 */
typedef enum {
    /**
     * If bit is set, the ISP Digital Gain setting requires update / has valid value.
     */
    FLAG_ISP_DG_CFG = 0x1,
    /**
     * If bit is set, the ISP Liner Offset setting requires update / has valid value.
     */
    FLAG_ISP_LINOFF_CFG = 0x2,
    /**
     * If bit is set, the ISP Gamma DL setting requires update / has valid value.
     */
    FLAG_ISP_GAMMADL_CFG = 0x4,
    /**
     * If bit is set, the ISP Inverse Gamma DL setting requires update / has valid value.
     */
    FLAG_ISP_INVGAMMADL_CFG = 0x8,
    /**
     * If bit is set, the ISP Gamma FE LUT setting requires update / has valid value.
     */
    FLAG_ISP_GAMMA_CFG = 0x10,
    /**
     * If bit is set, the ISP Sinter setting requires update / has valid value.
     */
    FLAG_ISP_SINTER_CFG = 0x20,
    /**
     * If bit is set, the ISP Sinter Radial Shading setting requires update / has valid value.
     */
    FLAG_ISP_SINTERRS_CFG = 0x40,
    /**
     * If bit is set, the ISP Pipeline Noise Profile setting requires update / has valid value.
     */
    FLAG_ISP_PIPENP_CFG = 0x80,
    /**
     * If bit is set, the ISP Tone Mapping setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAP_CFG = 0x100,
    /**
     * If bit is set, the ISP Tone Mapping Pre Gamma LUT setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAPPREGAMMALUT_CFG = 0x200,
    /**
     * If bit is set, the ISP Tone Mapping Post Gamma LUT setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAPPOSTGAMMALUT_CFG = 0x400,
    /**
     * If bit is set, the ISP Local Tone Mapping (Iridix) Asymmetry LUT setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAPLOCALASYMLUT_CFG = 0x800,
    /**
     * If bit is set, the ISP Tone Mapping 2DLUT setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAP2DLUT_CFG = 0x1000,
    /**
     * If bit is set, the ISP Demosaic setting requires update / has valid value.
     */
    FLAG_ISP_DEM_CFG = 0x2000,
    /**
     * If bit is set, the ISP Video Test Generator setting requires update / has valid value.
     */
    FLAG_ISP_VTG_CFG = 0x4000,
    /**
     * If bit is set, the ISP Demosaic Noise Profile setting requires update / has valid value.
     */
    FLAG_ISP_DEMNP_CFG = 0x8000,
    /**
     * If bit is set, the ISP Histogram statistics setting requires update / has valid value.
     */
    FLAG_ISP_HISTSTATS_CFG = 0x10000,
    /**
     * If bit is set, the ISP White point statistics setting requires update / has valid value.
     */
    FLAG_ISP_WBSTATS_CFG = 0x20000,
    /**
     * If bit is set, the ISP Exposure statistics setting requires update / has valid value.
     */
    FLAG_ISP_EXPSTATS_CFG = 0x40000,
    /**
     * If bit is set, the ISP ROI statistics setting requires update / has valid value.
     */
    FLAG_ISP_ROISTATS_CFG = 0x80000,
    /**
     * If bit is set, the ISP Antifog statistics setting requires update / has valid value.
     */
    FLAG_ISP_AFSSTATS_CFG = 0x100000,
    /**
     * If bit is set, the ISP Micro ROI crop setting requires update / has valid value.
     */
    FLAG_ISP_UROICROP_CFG = 0x200000,
    /**
     * If bit is set, the ISP Static White Balance setting requires update / has valid value.
     */
    FLAG_ISP_WB_CFG = 0x400000,
    /**
     * If bit is set, the @c histStatsData field has valid data.
     */
    FLAG_ISP_HISTSTATS_DATA = 0x800000,
    /**
     * If bit is set, the @c roiStatsData field has valid data.
     */
    FLAG_ISP_ROISTATS_DATA = 0x1000000,
    /**
     * If bit is set, the @c afsStatsData field has valid data.
     */
    FLAG_ISP_AFSSTATS_DATA = 0x2000000,
    /**
     * If bit is set, the @c expStatsData field has valid data.
     */
    FLAG_ISP_EXPSTATS_DATA = 0x4000000,
    /**
     * If bit is set, the @c uRoiCropData field has valid data.
     */
    FLAG_ISP_UROICROP_DATA = 0x8000000,
    /**
     * If bit is set, the @c wbStatsData field has valid data.
     */
    FLAG_ISP_WBSTATS_DATA = 0x10000000,
    /**
     * If bit is set, the @c inputFormCfg field has valid data.
     */
    FLAG_ISP_INPUTFORM_CFG = 0x20000000,
    /**
     * If bit is set, the @c outFormCfg field has valid data.
     */
    FLAG_ISP_OUTFORM_CFG = 0x40000000,
    /**
     * If bit is set, the @c gammaBe0Cfg field has valid data.
     */
    FLAG_ISP_GAMMABE0_CFG = 0x80000000,
    /**
     * If bit is set, the @c gammaBe1Cfg field has valid data.
     */
    FLAG_ISP_GAMMABE1_CFG = 0x100000000,
    /**
     * If bit is set, the @c radialShadingCfg field has valid data.
     */
    FLAG_ISP_RADIALSHADING_CFG = 0x200000000,
    /**
     * If bit is set, the @c radialShadingLutCfg field has valid data.
     */
    FLAG_ISP_RADIALSHADINGLUT_CFG = 0x400000000,
    /**
     * If bit is set, the @c meshShadingCfg field has valid data.
     */
    FLAG_ISP_MESHSHADING_CFG = 0x800000000,
    /**
     * If bit is set, the @c meshShadingLutCfg field has valid data.
     */
    FLAG_ISP_MESHSHADINGLUT_CFG = 0x1000000000,
    /**
     * If bit is set, the @c rawFeCfg field has valid data.
     */
    FLAG_ISP_RAWFE_CFG = 0x2000000000,
    /**
     * If bit is set, the @c caCfg field has valid data.
     */
    FLAG_ISP_CA_CFG = 0x4000000000,
    /**
     * If bit is set, the @c caFiltLutCfg field has valid data.
     */
    FLAG_ISP_CAFILTLUT_CFG = 0x8000000000,
    /**
     * If bit is set, the @c caCorrLutCfg field has valid data.
     */
    FLAG_ISP_CACORRLUT_CFG = 0x10000000000,
    /**
     * If bit is set, the @c toneMapGainCfg field has valid data.
     */
    FLAG_ISP_TONEMAPGAIN_CFG = 0x20000000000
} flag_isp_cfg_t;

// ISP statistic data, which QNX passes to Cogent for processing
struct ISP_data {
    /**
     * usageFlag is a combination of FLAG_ISP_*_DATA from the @c flag_isp_cfg_t
     */
    uint64_t usageFlag;
    drvISP_HistStatsData_t histStatsData;
    drvISP_HistStatsData_t roiStatsData;
    drvISP_HistStatsData_t afsStatsData;
    drvISP_ExpStatsData_t expStatsData;
    drvISP_uRoiCropData_t uRoiCropData;
    drvISP_WbStatsData_t wbStatsData;
};

// ISP configuration update, which QNX retrieve from Cogent lib
// Or ISP current settings, which QNX provides to Cogent by request
struct ISP_config {
    /**
     * usageFlag is a combination of FLAG_ISP_*_CFG from the @c flag_isp_cfg_t
     */
    uint64_t usageFlag;
    drvISP_DgCfg_t dgCfg;
    drvISP_LinOffCfg_t linOffCfg;
    drvISP_GammaDlCfg_t gammaDlCfg;
    drvISP_GammaDlCfg_t invGammaDlCfg;
    drvISP_GammaCfg_t gammaCfg;
    drvISP_SinterCfg_t sinterCfg;
    drvISP_SinterRsCfg_t sinterRsCfg;
    drvISP_PipeNpCfg_t pipeNpCfg;
    drvISP_ToneMapCfg_t toneMapCfg;
    drvISP_ToneMapLutCfg_t toneMapPreGammaLutCfg;
    drvISP_ToneMapLutCfg_t toneMapPostGammaLutCfg;
    drvISP_ToneMapLutCfg_t toneMapLocalAsymLutCfg;
    drvISP_ToneMap_2DLUT_Cfg_t toneMap2DLutCfg;
    drvISP_DemCfg_t demCfg;
    drvISP_VtgCfg_t vtgCfg;
    drvISP_DemNpCfg_t demNpCfg;
    drvISP_HistStatsCfg_t histStatsCfg;
    drvISP_WbStatsCfg_t wbStatsCfg;
    drvISP_ExpStatsCfg_t expStatsCfg;
    drvISP_RoiStatsCfg_t roiStatsCfg;
    drvISP_AfStatsCfg_t afsStatsCfg;
    drvISP_uRoiCropCfg_t uRoiCropCfg;
    drvISP_WbCfg_t wbCfg;
    drvISP_InputFormCfg_t inputFormCfg;
    drvISP_OutFormCfg_t outFormCfg;
    drvISP_GammaCfg_t gammaBe0Cfg;
    drvISP_GammaCfg_t gammaBe1Cfg;
    drvISP_RadialShadingCfg_t radialShadingCfg;
    drvISP_RadialShadingLutCfg_t radialShadingLutCfg;
    drvISP_MeshShadingCfg_t meshShadingCfg;
    drvISP_MeshShadingLutCfg_t meshShadingLutCfg;
    drvISP_RawFeCfg_t rawFeCfg;
    drvISP_CaCfg_t caCfg;
    drvISP_CaFiltLutCfg_t caFiltLutCfg;
    drvISP_CaCorrLutCfg_t caCorrLutCfg;
    drvISP_DgCfg_t toneMapGainCfg;
};

#else
/**
 * The meaning of the @c usageFlag field in the @c ispConfig_t / @c ispData_t
 * It indicates which ISP settings require update / has valid value.
 */
typedef enum {
    /**
     * Initialization value.
     */
    FLAG_ZERO = 0x0,
    /**
     * If bit is set, the ISP CCM setting requires update / has valid value.
     */
    FLAG_ISP_CCM_CFG = 0x1,
    /**
     * If bit is set, the ISP Liner Offset setting requires update / has valid value.
     */
    FLAG_ISP_CFA_CFG = 0x2,
    /**
     * If bit is set, the ISP Gamma DL setting requires update / has valid value.
     */
    FLAG_ISP_CFALUT16TO12_CFG = 0x4,
    /**
     * If bit is set, the ISP Decompanding of very short exposure setting requires update / has valid value.
     */
    FLAG_ISP_DECOMP1_CFG = 0x8,
    /**
     * If bit is set, the ISP Decompanding of short exposure setting requires update / has valid value.
     */
    FLAG_ISP_DECOMP2_CFG = 0x10,
    /**
     * If bit is set, the ISP Decompanding of long exposure setting requires update / has valid value.
     */
    FLAG_ISP_DECOMP3_CFG = 0x20,
    /**
     * If bit is set, the ISP Defect pixel correction setting requires update / has valid value.
     */
    FLAG_ISP_DPCLUT_CFG = 0x40,
    /**
     * If bit is set, the ISP Dynamic defect pixel correction setting requires update / has valid value.
     */
    FLAG_ISP_DPCOTF_CFG = 0x80,
    /**
     * If bit is set, the ISP Tone Mapping setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAP_CFG = 0x100,
    /**
     * If bit is set, the ISP Tone Mapping Pre Gamma LUT setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAPPREGAMMALUT_CFG = 0x200,
    /**
     * If bit is set, the ISP Tone Mapping Post Gamma LUT setting requires update / has valid value.
     */
    FLAG_ISP_TONEMAPPOSTGAMMALUT_CFG = 0x400,
    /**
     * If bit is set, the ISP Edge Enhancement setting requires update / has valid value.
     */
    FLAG_ISP_EE_CFG = 0x2000,
    /**
     * If bit is set, the ISP Video Test Generator setting requires update / has valid value.
     */
    FLAG_ISP_GAMMA_CFG = 0x4000,
    /**
     * If bit is set, the ISP H3A statistic setting requires update / has valid value.
     */
    FLAG_ISP_H3A_CFG = 0x8000,
    /**
     * If bit is set, the ISP H3A statistic LUT setting requires update / has valid value.
     */
    FLAG_ISP_H3ALUT_CFG = 0x20000,
    /**
     * If bit is set, the ISP Histogram setting requires update / has valid value.
     */
    FLAG_ISP_HIST_CFG = 0x40000,
    /**
     * If bit is set, the ISP Mesh shading setting requires update / has valid value.
     */
    FLAG_ISP_LSC_CFG = 0x80000,
    /**
     * If bit is set, the ISP Stitching of very short and long (short+long) exposure setting requires update / has valid value.
     */
    FLAG_ISP_MERGE1_CFG = 0x100000,
    /**
     * If bit is set, the ISP Stitching of short and long exposure setting requires update / has valid value.
     */
    FLAG_ISP_MERGE2_CFG = 0x200000,
    /**
     * If bit is set, the ISP Sinter setting requires update / has valid value.
     */
    FLAG_ISP_NSF4_CFG = 0x800000,
    /**
     * If bit is set, the ISP Decompanding LUT for very short exposure setting requires update / has valid value.
     */
    FLAG_ISP_PWL1_CFG = 0x1000000,
    /**
     * If bit is set, the ISP Decompanding LUT for short exposure setting requires update / has valid value.
     */
    FLAG_ISP_PWL2_CFG = 0x2000000,
    /**
     * If bit is set, the ISP Decompanding LUT for long exposure setting requires update / has valid value.
     */
    FLAG_ISP_PWL3_CFG = 0x4000000,
    /**
     * If bit is set, the ISP Gamma LUT for compressing image from 20 into 16 bits setting requires update / has valid value.
     */
    FLAG_ISP_RFELUT20TO16_CFG = 0x8000000,
    /**
     * If bit is set, the ISP Color conversion (rgb into hsv) setting requires update / has valid value.
     */
    FLAG_ISP_RGB2HSV_CFG = 0x10000000,
    /**
     * If bit is set, the ISP Color conversion (rgb into yuv) setting requires update / has valid value.
     */
    FLAG_ISP_RGB2YUV_CFG = 0x20000000,
    /**
     * If bit is set, the ISP White balance gains setting requires update / has valid value.
     */
    FLAG_ISP_WB_CFG = 0x40000000,
    /**
     * If bit is set, the ISP Gamma for YUV image setting requires update / has valid value.
     */
    FLAG_ISP_YUVSATLUT_CFG = 0x80000000
} flag_isp_cfg_t;

#define ISP_AWB_NUM_ZONES (32*16)

// ISP statistic data, which cuc_rc kernel passes to Cogent for processing
struct ISP_data {
    /**
     * usageFlag is a combination of FLAG_ISP_*_DATA from the @c flag_isp_cfg_t
     */
    uint64_t usageFlag;
    H3a_StatsData_32x16_SumOnly *h3a_data;
    uint32_t n_row;
    uint32_t n_col;
    uint32_t n_pix;
};

// ISP configuration update, which cuc_rc kernel retrieve from Cogent lib
// Or ISP current settings, which cuc_rc kernel provides to Cogent by request
struct ISP_config
{
    /**
     * usageFlag is a combination of FLAG_ISP_*_CFG from the @c flag_isp_cfg_t
     */
    uint64_t usageFlag;
    Nsf4v_Config                        nsf4Cfg;
    H3a_Config                          h3aCfg;
    Fcp_CcmConfig                       ccmCfg;
    Rfe_PwlConfig                       pwlCfg1;
    Rfe_PwlConfig                       pwlCfg2;
    Rfe_PwlConfig                       pwlCfg3;
    Vhwa_LutConfig                      decomp1Cfg;
    Vhwa_LutConfig                      decomp2Cfg;
    Vhwa_LutConfig                      decomp3Cfg;
    Rfe_WdrConfig                       merge1Cfg;
    Rfe_WdrConfig                       merge2Cfg;
    Vhwa_LutConfig                      rfeLut20to16Cfg;
    Rfe_DpcOtfConfig                    dpcOtfCfg;
    Rfe_DpcLutConfig                    dpcLutCfg;
    Rfe_LscConfig                       lscCfg;
    Rfe_GainOfstConfig                  wbCfg;
    Rfe_H3aInConfig                     h3aInCfg;
    Vhwa_LutConfig                      h3aLutCfg;
    Fcp_CfaConfig                       cfaCfg;
    Vhwa_LutConfig                      cfaLut16to12Cfg;
    Fcp_Rgb2YuvConfig                   rgb2yuvCfg;
    Fcp_Rgb2HsvConfig                   rgb2hsvCfg;
    Fcp_GammaConfig                     gammaCfg;
    Fcp_YuvSatLutConfig                 yuvSatLutCfg;
    Fcp_HistConfig                      histCfg;
    Glbce_Config                        glbceCfg;
    Glbce_PerceptConfig                 fwdPrcpCfg;
    Glbce_PerceptConfig                 revPrcpCfg;
    Fcp_EeConfig                        eeCfg;
};

typedef struct parameters_storage_s parameters_storage_t; /* PRQA S 3313 */


typedef struct {
	void 	(*write_all_regs)(uint32_t cam_num, uint8_t* sensorConfig, uint32_t* len_bytes, bool* p_exp_gain_change);
	void 	(*fill_default_table)(uint8_t* sensorConfig, uint32_t* len_bytes);
	void 	(*parse_embedded_data)(parameters_storage_t* storage_ctx, const struct ar014x_sensor_data* sensorData, uint32_t cam_num);
    bool    (*parse_histogram)(const uint8_t* stat, uint32_t hist[512], uint32_t *pixel_count, uint32_t* bins_num, const float** weights);
    void    (*calc_snr)(const uint32_t hist[512], uint32_t pixel_count, uint32_t bins_num, float dg, float* snr);
    void    (*set_default_isp_settings)(uint32_t cam_num, struct ISP_config *ispConfig);
} sensor_operations_t;

extern sensor_operations_t sensor_custom_operations;

#define YUV_DATA_SIZE    128

typedef struct
{
    uint8_t data[YUV_DATA_SIZE];
    bool    valid;
} tivxYuvData;

#endif
/**
 * @brief Get initial sensor configuration
 * @details This function provides initial AR014X sensor configuration.
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param sensorType The type of Magna camera sensor
 * @param sensorConfig [in] table of initial sensor settings.
 *                     [out] table of sensor setting which requires modification.
 * @param numConfigItems [in] number of items in sensor settings table
 *                       [out] number of items in sensor settings table which requires modification
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int32_t getInitialSensorConfig(int32_t sensorIdx, magna_camera_sensor_type_t sensorType,
                           uint8_t* sensorConfig, uint32_t* numConfigItems);

/**
 * @brief Get initial ISP configuration
 * @details This function provides initial ISP configuration.
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param ispConfig [in] initial ISP hardware settings.
 *                  [out] required ISP settings for specified sensor.
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */

int getInitialIspConfig(int sensorIdx, struct ISP_config* ispConfig);

/**
 * @brief Process frame
 * @details This function is called on frame basis and provides updates
 *          for AR014X sensor configuration and ISP configuration.
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param sensorData [in] sensor embedded data and statistics extracted from incoming raw frame.
 * @param ispData [in] ISP statistics collected after frame processing by ISP module
 * @param sensorConfig [in] clear table of sensor settings.
 *                     [out] table of sensor setting which requires modification.
 * @param numConfigItems [in] number of items in sensor settings table.
 *                       [out] number of items in sensor settings table which requires modification.
 * @param ispConfig [in] current ISP settings for specified sensor.
 *                  [out] required ISP settings for specified sensor.
 * @param sensorType [in] The type of Magna camera sensor
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */

int processFrame(int sensorIdx, struct ar014x_sensor_data* sensorData, struct ISP_data* ispData,
                 uint8_t* sensorConfig, int* numConfigItems, struct ISP_config* ispConfig, tivxYuvData *yuvData);
/**
 * @brief Get required data list
 * @details This function returnes ISP data list required by Cogent tuning lib.
 *          It is called on the frame basis before call processFrame()
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param reqIspDataList [out] bit flag that specifies which ISP data is required (see @c usageFlag
 *                             from struct @c ISP_data and @c ISP_config for reference)
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int32_t getRequiredIspDataList(int32_t sensorIdx, uint64_t* reqIspDataList);

/**
 * @brief Get required sensor registers list
 * @details This function returns list of AR014X sensor register addresses required by Cogent tuning lib.
 *          Retrieved register list will be used to create @c sensorConfig for @c getInitialSensorConfig().
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param reqSensorRegsList [in] clear array of AR014X register addresses.
 *                          [out] array of AR014X register addresses for which Cogent tuning lib
 *                                requires initial sensor register values.
 * @param numSensorRegs [in] number of items in @c reqSensorRegsList
 *                      [out] number of items in @c reqSensorRegsList filled by Cogent tuning lib
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int32_t getRequiredSensorRegsList(int32_t sensorIdx, uint16_t* reqSensorRegsList, int32_t* numSensorRegs);

/**
 * @brief Set brightness value
 * @details This function sets brightness value to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param brightness The brightness value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setBrightness(int sensorIdx, int32_t brightness);

/**
 * @brief Set contrast value
 * @details This function sets contrast value to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param contrast The contrast value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setContrast(int sensorIdx, int32_t contrast);

/**
 * @brief Set brightness and contrast step value
 * @details This function sets brightness and contrast step value to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param brightnessStep The brightness step value
 * @param contrastStep The contrast step value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setBrightnessContrastStep(int sensorIdx, uint32_t brightnessStep, uint32_t contrastStep);

#ifdef MAGNA_PSA
/**
 * @brief Set ISP vision mode
 * @details This function sets ISP vision mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param mode The mode value (see @c isp_mode_t for details)
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setIspVisionMode(int sensorIdx, v3xISP_VisionModeType_t mode);
#endif
/**
 * @brief Set runtime AE mode
 * @details This function sets runtime AE mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param runtime_ae_mode The runtime AE mode value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setRuntimeAeMode(int sensorIdx, int8_t runtime_ae_mode);

/**
 * @brief Set runtime AWB mode
 * @details This function sets runtime AWB mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param runtime_awb_mode The runtime AWB mode value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setRuntimeAwbMode(int sensorIdx, int8_t runtime_awb_mode);

/**
 * @brief Set WB CFG mode
 * @details This function sets WB CFG mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param wb_cfg_mode The WB CFG mode value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setWbCfgMode(int sensorIdx, int8_t wb_cfg_mode);

/**
 * @brief Set 60 Hz On/Off mode
 * @details This function sets 60Hz On/Off mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param wb_cfg_mode The 60 Hz On/Off mode value (True - 60Hz On; False - 60Hz Off)
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int set60HzMode(int sensorIdx, bool mode);

/**
 * @brief Set Gamma CFG mode
 * @details This function sets Gamma CFG mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param gamma_cfg_mode The Gamma CFG mode value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setGammaCfgMode(int sensorIdx, int8_t gamma_cfg_mode);

/**
 * @brief Set Gamma CFG LUT value
 * @details This function sets Gamma CFG LUT value to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param gamma_cfg_lut Pointer to the Gamma CFG LUT table
 * @param size The size of the Gamma CFG LUT table
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setGammaCfgLut(int sensorIdx, const uint32_t* gamma_cfg_lut, uint32_t size);

/**
 * @brief Set Radial Shading Cfg mode
 * @details This function sets Radial Shading Cfg mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param radial_shading_cfg_mode The Radial Shading Cfg value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setRadialShadingCfgMode(int sensorIdx, int8_t radial_shading_cfg_mode);

/**
 * @brief Set Sinter CFG mode
 * @details This function sets Sinter CFG mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param sinter_cfg_mode The Sinter CFG mode value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setSinterCfgMode(int sensorIdx, int8_t sinter_cfg_mode);

#ifdef MAGNA_PSA
/**
 * @brief Set Sharp Strength for ISP RGGB demosaic
 * @details This function sets Sharp Strength for ISP RGGB demosaic to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param sharp_strength The Sharp Strength for ISP RGGB demosaic (see @c sharpStrength_t for detail)
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setSharpStrength(int sensorIdx, sharpStrength_t sharp_strength);
#endif
/**
 * @brief Tone Map CFG mode
 * @details This function sets Tone Map CFG mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param tone_map_cfg_mode The Tone Map CFG mode value
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setToneMapCfgMode(int sensorIdx, int32_t tone_map_cfg_mode);

/**
 * @brief Set Stats Roi
 * @details This function sets Stats Roi to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param left The x coordinate of the top-left corner of Roi
 * @param top The y coordinate of the top-left corner of Roi
 * @param width The width of Roi
 * @param height The height of Roi
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setStatsRoi(int sensorIdx, int32_t left, int32_t top, int32_t width, int32_t height);

/**
 * @brief Callback to notify subscribers about camera output frame rate changes.
 * @details The function that the Cogent library will call to notify subscribers
 *          of a change in the camera output frame rate.
 *
 * @param denominator Camera output frame rate denominator
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
typedef int (*outputFrameRate_callback)(uint32_t sensorIdx, camera_frame_rate_denominator_t denominator);

/**
 * @brief Set callback to notify subscribers about camera output frame rate changes.
 * @details Register a function that would be called when Cogent library
 *          needs to notify subscribers changes in camera output frame rate.
 *
 * @param func The function that would be called by the Cogent
 *             library to notify subscribers about camera output frame rate changes.
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int register_outputFrameRate_callback(outputFrameRate_callback func);

/**
 * @brief Set manufacturing test mode
 * @details This function sets specific manufacturing test mode to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param type The manufacturing test type
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setManufacturingTestMode(int sensorIdx, v3xISP_ManufacturingTestType_t type);

/**
 * @brief Turn on/off edge enhancement
 * @details This function turns on/off edge enhancement to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param enable The enable value (True - enable; False - disable)
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int setEE(int sensorIdx, uint32_t enable);

#ifdef MAGNA_PSA
/**
 * @brief Set Stats Roi calculated from provided camera parameters
 * @details This function sets Stats Roi calculated from provided camera parameters
 *          to Cogent tuning library
 *
 * @param sensorIdx The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param extrinsic_parameters The extrinsic parameters (see @c extrinsic_parameters_t for details)
 * @param intrinsic_parameters The intrinsic parameters (see @c intrinsic_parameters_t for details)
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int calcStatsRoiFromCameraParameters(int sensorIdx, extrinsic_parameters_t extrinsic_parameters,
                                     intrinsic_parameters_t intrinsic_parameters);


/**
 * @brief Callback to notify subscribers about raw sensor frame dump request.
 * @details The function that the Cogent library will call to request raw sensor frame dump.
 *          It is blocking function until collect raw video frame or deinit sensor.
 *          In case of sensor deinit the function returns size = 0 and buf = NULL.
 *
 * @param sensorIdx [in] The index of sensor (also reflects the ISP slot number). Valid range is 0-3
 * @param buf [out] pointer to raw video frame buffer.
 * @param size [out] size of raw frame buffer in bytes.
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
typedef int (*dumpFrame_callback)(int sensorIdx, uint8_t** buf, uint32_t* size);

/**
 * @brief Set callback to notify subscribers about raw sensor frame dump request.
 * @details Register a function that would be called when Cogent library
 *          needs to request raw sensor frame dump.
 *
 * @param func The function that would be called by the Cogent
 *             library to request raw sensor frame dump.
 *
 * @return @c #EOK when the function successfully completes, otherwise value
 * that provides the reason that the call failed.
 */
int register_dumpFrame_callback(dumpFrame_callback func);
#endif

#ifdef __cplusplus
}
#endif

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camera/cogent/public/cogent/cogent_api.h $ $Rev: 899700 $")
#endif

/* PRQA S 0646 -- */
/* PRQA S 1281 -- */
/* PRQA S 0647 -- */
/* PRQA S 0930 -- */
/* PRQA S 0723 -- */
/* PRQA S 0342 -- */
/* PRQA S 0881 -- */
/* PRQA S 3412 -- */

#endif   /* COGENT_API_H */
