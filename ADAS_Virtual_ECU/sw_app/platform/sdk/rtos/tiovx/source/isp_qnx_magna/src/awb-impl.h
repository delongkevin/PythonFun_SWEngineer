/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           awb-impl.c
 *  @brief          Auto white balance algorithm implementation
 *
 *  @version        3.21_tda4_01
 *  @author         Sergey Salishev & Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           12.10.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef AWB_API_H
#define AWB_API_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "isp_aux.h"
#include "../public/cogent/cogent_api.h"

typedef struct
{
    // R/G channel ratio
    float32_t rg;

    // B/G channel ratio
    float32_t bg;

} awb_ratios_t;


typedef enum
{
    RED           = 0,
    GREEN         = 1,
    BLUE          = 2,
    MAX_CHANNELS  = 3
} awb_color_channel_t;

// Prelimenary prepared configuration for AWB algorithm
typedef struct
{

    // Default white balance gain for 6500K color temperature
    float32_t static_gains[MAX_CHANNELS];

    // Threshold to check frame on skipping
    float32_t min_valid_blocks_ratio;

    // Weight for gray patch soft classification
    float32_t qda_weight[5];

    // Prelimenary calibrated ratios at warm and cold points
    awb_ratios_t points[2];

    // Prelimenary calibrated color temperature at warm and cold points
    float32_t temperatures[2];

    // Amount of block in statistics
    uint32_t block_count;

    // Mask of block usage. Configured and allocated in user-space.
    const uint8_t* mask;

    // Min/max values of color temperature range (Kelvin)
    float32_t temp_range_min;
    float32_t temp_range_max;


    // Min/max values of color temperature range (tint)
    float32_t tint_range_min;
    float32_t tint_range_max;


    // Min/max result values of color temperature range (Kelvin)
    float32_t temp_result_range_min;
    float32_t temp_result_range_max;


    // Min/max result values of color temperature range (tint)
    float32_t tint_result_range_min;
    float32_t tint_result_range_max;

    // Threshold for ccm gain correction
    float32_t second_component_threshold;

    // Max to top block confidence threshold in percentage
    float32_t confidence_threshold;
    float32_t q6;
    float32_t dist_threshold;

    // Difference of the Gray World AWB results between current and previous frames
    float32_t gw_dtemp;
    float32_t gw_dtint;

    // Illuminant calculated on the previous frame
    float32_t prev_inv_temp;
    float32_t prev_tint;

} awb_config_t;

typedef struct
{
    const float32_t* planck_temp_table;
    const float32_t* planck_lrg_table;
    const float32_t* planck_lbg_table;
    const float32_t* gray_hull_temp;
    const float32_t* gray_hull_tint;
    uint32_t planck_len;
    uint32_t gray_hull_len;
}awb_tables_t;



 // AE and AWB statistics processed and converted into algorithm suitable format
typedef struct
{
    // RG/BG ratios in a block
    awb_ratios_t ratios;

    // Brightness of a block
    float32_t y;

    // Confidence of a block
    float32_t conf;

    // index of a block. Used for location understanding after block are sorted.
    uint32_t index;/* PRQA S 0781 */

} awb_statistics_block_t;

 // Collected and Processed ISP statistics
typedef struct
{
    // Gains for statistics correction
    float32_t gains_from_sensor[MAX_CHANNELS];
    float32_t gains_used_for_stat[MAX_CHANNELS];

    // Array of blocks with statistics
    const awb_statistics_block_t* blocks;

} awb_statistics_t;

 // Size of AWB context allocated in user space and flag of AWB stage (Init/Process)
typedef struct
{
    int dummy[172];
    uint32_t init;
} awb_context_t;

int32_t awb_process(awb_context_t *context,
                    const awb_config_t* config,
                    const awb_statistics_t *statistics,
                    const awb_tables_t* tables,
                    float32_t gains[MAX_CHANNELS],
                    float32_t fine_gains[MAX_CHANNELS],
                    uint32_t *awb_valid_blocks,
                    float32_t *temp_nonclamp,
                    float32_t *tint_nonclamp,
                    float32_t *out_inv_temp_clamp,
                    float32_t *out_tint_clamp);

#endif  /* AWB_API_H */
