/*
 * $QNXLicenseC:
 * Copyright 2018, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable
 * license fees to QNX Software Systems before you may reproduce,
 * modify or distribute this software, or any work that includes
 * all or part of this software. Free development licenses are
 * available for evaluation and non-commercial purposes. For more
 * information visit http://licensing.qnx.com or email
 * licensing@qnx.com.
 *
 * This file may contain contributions from others. Please review
 * this entire file for other proprietary rights or license notices,
 * as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

/**
 * @file camera_v3x_api.h
 *
 * @brief This file defines functions and data structures for communication
 *        with ISP in Renesas V3x.
 *
 *
 */

#ifndef _CAMERA_V3X_API_H_
#define _CAMERA_V3X_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <camera/camera_api.h>

/**
 * The maximum number of nodes supported by the V3x ISP.
 */
#define MAX_USED_NODES              225

/**
 * The maximum number of bins in an histogram.
 */
#define ISP_MAX_BINS                1024

/**
 * The maximum Output Formatter LUT number of entries.
 */
#define ISP_MAX_OUTF_LUT_SIZE       257

/**
 * CSI2 data type (DT) definitions.
 */
#define CSI2_DT_BLANKING_DATA                       0x11
#define CSI2_DT_EMBEDDED_DATA                       0x12
#define CSI2_DT_RAW14                               0x2d

/**
 * The V3x exposure statistics for a given node.
 */
typedef struct {
    /**
     * Bin 0 normalized pixel sum.
     */
    uint16_t Bin0;
    /**
     * Bin 1 normalized pixel sum.
     */
    uint16_t Bin1;
    /**
     * Bin 3 normalized pixel sum.
     */
    uint16_t Bin3;
    /**
     * Bin 4 normalized pixel sum.
     */
    uint16_t Bin4;
} v3xISP_ExpStatRecord_t;

/**
 * The V3x exposure statistics.  Structure used for the
 * @c METADATA_ID_EXPOSURE_STATS metadata.
 */
typedef struct {
    /**
     * Number of entries filled in @c nodes array.
     */
    uint32_t ctEntries;
    /**
     * Exposure statistics for each node.
     */
    v3xISP_ExpStatRecord_t nodes[MAX_USED_NODES];
    /**
     * Frame counter.
     */
    uint32_t FrameCount;
    /**
     * 16-bit CRC.
     */
    uint32_t CRC16;
    /**
     * Number of horizontal nodes used.
     */
    uint16_t Nodes_Used_Horiz;
    /**
     * Number of vertical nodes used.
     */
    uint16_t Nodes_Used_Vert;
    /**
     * Global average for Bin 0.
     */
    uint16_t Glob_Avg_Bin0;
    /**
     * Global average for Bin 1.
     */
    uint16_t Glob_Avg_Bin1;
    /**
     * Global average for Bin 3.
     */
    uint16_t Glob_Avg_Bin3;
    /**
     * Global average for Bin 4.
     */
    uint16_t Glob_Avg_Bin4;
} v3xISP_ExpStatsData_t;

/**
 * The V3x anti-fog histogram statistics.  Structure used for the
 * @c METADATA_ID_ANTI_FOG_STATS metadata.
 */
typedef struct {
    /**
     * Bins containing the histogram.
     */
    uint16_t bins[ISP_MAX_BINS];
    /**
     * Number of horizontal nodes used.
     */
    uint16_t Nodes_Used_Horiz;
    /**
     * Number of vertical nodes used.
     */
    uint16_t Nodes_Used_Vert;
    /**
     * Number of total pixels.
     */
    uint32_t Tot_PixelNumber;
    /**
     * Number of pixels processed.
     */
    uint32_t CountedPixels;
    /**
     * Number of pixels in plane 0.
     */
    uint32_t Plane0_Tot_PixelNumber;
    /**
     * Number of pixels in plane 1.
     */
    uint32_t Plane1_Tot_PixelNumber;
    /**
     * Number of pixels in plane 2.
     */
    uint32_t Plane2_Tot_PixelNumber;
    /**
     * Number of pixels in plane 3.
     */
    uint32_t Plane3_Tot_PixelNumber;
    /**
     * Number of pixels processed in plane 0.
     */
    uint32_t Plane0_CountedPixels;
    /**
     * Number of pixels processed in plane 1.
     */
    uint32_t Plane1_CountedPixels;
    /**
     * Number of pixels processed in plane 2.
     */
    uint32_t Plane2_CountedPixels;
    /**
     * Number of pixels processed in plane 3.
     */
    uint32_t Plane3_CountedPixels;
    /**
     * Frame counter.
     */
    uint32_t FrameCount;
    /**
     * 16-bit CRC.
     */
    uint32_t CRC16;
} v3xISP_HistStatsData_t;

/**
 * A bitmask describing the link status of the Max9286.
 */
typedef struct {
    /**
     * Set to 1 when a configuration link is detected.
     */
    uint8_t configDet           : 1;
    /**
     * Set to 1 when a video link is detected.
     */
    uint8_t videoDet            : 1;
    /**
     * Set to 1 when line tracking is not locked.
     */
    uint8_t hLocked             : 1;
    /**
     * Set to 1 when a line error is detected.
     */
    uint8_t lengthErr           : 1;
    /**
     * Set to 1 when a line buffer overflow is detected.
     */
    uint8_t linBuffOf           : 1;
    /**
     * Set to 1 when a rising edge vertical sync is detected.
     */
    uint8_t vSyncDet            : 1;
    /**
     * Set to 1 when frame synchronization is locked.
     */
    uint8_t fSyncLocked         : 1;
    /**
     * For internal use only. Do not use.
     */
    uint8_t reserved            : 1;
 } v3xMax9286_LinkStatus_t;

/**
 * The V3x Max9286 deserializer status information.  Structure used for the
 * @c METADATA_ID_MAX9286_LINK_STATUS metadata.
 */
typedef struct {
    /**
     * Link status information.
     */
    v3xMax9286_LinkStatus_t linkStatus;
    /**
     * Number of detected errors.
     */
    uint8_t                 detErr;
    /**
     * Number of corrected errors.
     */
    uint8_t                 corrErr;
} v3xMax9286_Status_t;

/**
 * The number of different Bayer components
 */
#define V3X_ISP_NUM_BAYER_COMPONENTS            4

/**
 * The V3x ISP White Balance configuration.  To be used when calling @c
 * camera_set_v3x_isp_config() with @c type set to @c V3XISP_CONFIG_WB.
 */
typedef struct {
    /**
     * Set to 1 to enable, 0 to disable.
     */
    uint8_t enable;
    /**
     * The 12-bit color gain in 4.8 format for each Bayer component:
     * 0 - 00
     * 1 - 01
     * 2 - 10
     * 3 - 11
     */
    uint16_t gain[V3X_ISP_NUM_BAYER_COMPONENTS];
    /**
     * The 24-bit black offset for each Bayer component:
     * 0 - 00
     * 1 - 01
     * 2 - 10
     * 3 - 11
     */
    uint32_t offset[V3X_ISP_NUM_BAYER_COMPONENTS];
} v3xISP_WbCfg_t;

/**
 * The V3x ISP vision mode type
 */
typedef enum {
    /* Configure ISP for human vision output video */
    ISP_MODE_HUMAN_VISION = 0,
    /* Configure ISP for machine vision output video */
    ISP_MODE_MACHINE_VISION = 1
} v3xISP_VisionModeType_t;

/**
 * The V3x ISP vision mode
 */
typedef struct {
    v3xISP_VisionModeType_t     visionModeType;
} v3xISP_VisionMode_t;

/**
 * The V3x ISP runtime AE mode
 */
typedef struct {
    uint8_t                     runtimeAeMode;
} v3xISP_RuntimeAeMode_t;

/**
 * The V3x ISP runtime AWB mode
 */
typedef struct {
    uint8_t                     runtimeAwbMode;
} v3xISP_RuntimeAwbMode_t;

/**
 * The V3x ISP WB Cfg mode
 */
typedef struct {
    uint8_t                     wbCfgMode;
} v3xISP_WbCfgMode_t;

/**
 * The V3x ISP Gamma Cfg mode
 */
typedef struct {
    uint8_t                     gammaCfgMode;
} v3xISP_GammaCfgMode_t;

/**
 * The V3x ISP Gamma Cfg LUT
 */
typedef struct {
    uint32_t                    gammaCfgLut[ISP_MAX_OUTF_LUT_SIZE];
    uint32_t                    size;
} v3xISP_GammaCfgLut_t;

/**
 * The V3x ISP Radial Shading Cfg mode
 */
typedef struct {
    uint8_t                     radialShadingCfgMode;
} v3xISP_RadialShadingCfgMode_t;

/**
 * The V3x ISP Sinter Cfg mode
 */
typedef struct {
    uint8_t                     sinterCfgMode;
} v3xISP_SinterCfgMode_t;

/**
 * The V3x ISP Sharpen strength for RGGB demosaic configuration
 */
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

/**
 * The V3x ISP Sharp Strength
 */
typedef struct {
    sharpStrength_t             sharpStrength;
} v3xISP_SharpStrength_t;

/**
 * The V3x ISP Tone Map Cfg mode
 */
typedef struct {
    uint32_t                    toneMapCfgMode;
} v3xISP_ToneMapCfgMode_t;

/**
 * The V3x Stats Roi
 */
typedef struct {
    uint32_t                    left;
    uint32_t                    top;
    uint32_t                    width;
    uint32_t                    height;
} v3xISP_StatsRoi_t;

typedef struct {
    float                       pre_roll_angle_z;
    float                       angle_x;
    float                       angle_y;
    float                       angle_z;
    float                       tr_vec[3];
} extrinsic_parameters_t;

typedef struct {
    float                       fx;
    float                       fy;
    float                       cx;
    float                       cy;
    float                       K0;
    float                       K1;
    float                       K2;
    float                       K3;
    float                       K4;
    float                       K5;
} intrinsic_parameters_t;

/**
 * The V3x Camera Params to calculate Stats Roi
 */
typedef struct {
    extrinsic_parameters_t      extrinsicParams;
    intrinsic_parameters_t       intrinsicParams;
} v3xISP_CameraParamsForStatsRoi_t;

/**
 * The V3x Camera Params to dump ISP's raw input frame
 */
typedef struct {
    char      rawDumpFilePath[CAMERA_ROLL_NAMELEN];
} v3xISP_CameraParamsDumpRawInput_t;

/**
 * The V3x ISP brightness and contrast step
 */
typedef struct {
    uint32_t                    brightnessStep;
    uint32_t                    contrastStep;
} v3xISP_BrightnessContrastStep_t;

/**
 * The V3x ISP manufacturing test type
 */
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

/**
 * The V3x ISP configuration
 */
typedef enum {
    /**
     * To configure the V3X ISP white balance.  It is associated with the
     * structure @c v3xISP_WbCfg_t.
     */
    V3XISP_CONFIG_WB,
    /**
     * To configure the V3X ISP vision mode.  It is associated with the
     * structure @c v3xISP_VisionMode_t.
     */
    V3XISP_CONFIG_VISION_MODE,
    /**
     * To configure the V3X ISP runtime AE mode.  It is associated with the
     * structure @c v3xISP_RuntimeAeMode_t.
     */
    V3XISP_CONFIG_RUNTIME_AE_MODE,
    /**
     * To configure the V3X ISP runtime AWB mode.  It is associated with the
     * structure @c v3xISP_RuntimeAwbMode_t.
     */
    V3XISP_CONFIG_RUNTIME_AWB_MODE,
    /**
     * To configure the V3X ISP WB Cfg mode.  It is associated with the
     * structure @c v3xISP_WbCfgMode_t.
     */
    V3XISP_CONFIG_WB_CFG_MODE,
    /**
     * To configure the V3X ISP Gamma Cfg mode.  It is associated with the
     * structure @c v3xISP_GammaCfgMode_t.
     */
    V3XISP_CONFIG_GAMMA_CFG_MODE,
    /**
     * To configure the V3X ISP Gamma Cfg Lut.  It is associated with the
     * structure @c v3xISP_GammaCfgLut_t.
     */
    V3XISP_CONFIG_GAMMA_CFG_LUT,
    /**
     * To configure the V3X ISP Radial Shading Cfg mode.  It is associated with the
     * structure @c v3xISP_RadialShadingCfgMode_t.
     */
    V3XISP_CONFIG_RADIAL_SHADING_CFG_MODE,
    /**
     * To configure the V3X ISP Sinter Cfg mode.  It is associated with the
     * structure @c v3xISP_SinterCfgMode_t.
     */
    V3XISP_CONFIG_SINTER_CFG_MODE,
    /**
     * To configure the V3X ISP Sharp Strength.  It is associated with the
     * structure @c v3xISP_SharpStrength_t.
     */
    V3XISP_CONFIG_SHARP_STRENGTH,
    /**
     * To configure the V3X ISP Tone Map Cfg mode.  It is associated with the
     * structure @c v3xISP_ToneMapCfgMode_t.
     */
    V3XISP_CONFIG_TONE_MAP_CFG_MODE,
    /**
     * To configure the V3X ISP Stats Roi.  It is associated with the
     * structure @c v3xISP_StatsRoi_t.
     */
    V3XISP_CONFIG_SET_STATS_ROI,
    /**
     * To configure the V3X ISP Stats Roi from camera parameters.  It is associated with the
     * structure @c v3xISP_CameraParamsForStatsRoi_t.
     */
    V3XISP_CONFIG_CAMERA_PARAMS_FOR_STATS_ROI,
    /**
     * To notify the V3X ISP to skip one context switch. This only applies for when the ISP
     * is using two contexts in a single output stream, e.g one frame proccessed with config A
     * and one frame proccessed with config B. This notification would make the ISP switch
     * from ABABA to BABAB
     * It is associated with the structure @c v3xISP_CameraParamsDumpRawInput_t.
     */
    V3XISP_CONFIG_ISP_SKIP_CONTEXT_SWITCH,
    /**
     * To notify the V3X ISP to dump the next possible raw input frame.
     * The frame would be dumped exactly as the ISP receives it, so it
     * might be padded to be aligned.
     */
    V3XISP_CONFIG_ISP_DUMP_RAW_INPUT_FRAME,
    /**
     * To configure the V3X ISP brightness and contrast step.  It is associated with the
     * structure @c v3xISP_BrightnessContrastStep_t.
     */
    V3XISP_CONFIG_BRIGHTNESS_CONTRAST_STEP,
    /**
     * To configure the V3X ISP for specific manufacturing test.  It is associated with the
     * structure @c v3xISP_ManufacturingTestType_t.
     */
    V3XISP_CONFIG_MANUFACTURING_TEST
} v3xISP_config_type_t;

/**
 * The V3x ISP stream context
 */
typedef enum {
    /**
     * To get information about the V3X ISP stream context.  It is associated with the
     * structure @c v3xISP_StreamInfo_t.
     */
    ISP_CONTEXT_A = 0,
    ISP_CONTEXT_B
} v3xISP_StreamContext_t;

/**
 * The V3x ISP additional stream information
 */
typedef struct {
    v3xISP_StreamContext_t    frame_context;
} v3xISP_StreamInfo_t;

/**
 * @brief Update dynamically the configuration of the V3x ISP.
 * @details Supports configuring different elements of the V3x ISP based on the
 *          value of @c type.
 *
 * @param handle The handle returned by a call to @c camera_open().
 * @param type The type of configuration that is desired to modify
 * @param config The updated configuration to apply.  Please see @c
 *               v3xISP_config_type_t for the appropriate structure to use based
 *               on the value of @c type.
 * @param size The size of the structure pointed to by @c config in bytes.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_v3x_isp_config(camera_handle_t handle,
                          v3xISP_config_type_t type,
                          void* config,
                          size_t size);

#ifdef __cplusplus
}
#endif
#endif /* _CAMERA_V3X_API_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
