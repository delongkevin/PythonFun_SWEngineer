/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           isp_process.h
 *  @brief          Interface of AE and AWB functions
 *                  as well as basic data structures
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

#ifndef ISP_PROCESS_H
#define ISP_PROCESS_H

/* PRQA S 1055 ++ */


#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "isp_aux.h"
#include "isp_algo.h"
#include "awb-impl.h"
#include "config_reader.h"
#ifdef MAGNA_PSA
#include <pthread.h>
extern pthread_mutex_t process_mutex;
#endif


static const float32_t ccm_eye_mat[9] = {1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f}; /* PRQA S 3207 */ /* PRQA S 3480 */ /* PRQA S 3218 */

static inline void  mul33_33(float32_t dst[9], const float32_t a_33[9], const float32_t b_33[9])
{
    int32_t i, j;

    float32_t dst_temp[9];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            dst_temp[(i * 3) + j] = (a_33[(i * 3) + 0] * b_33[(0 * 3) + j]) +
                                    (a_33[(i * 3) + 1] * b_33[(1 * 3) + j]) +
                                    (a_33[(i * 3) + 2] * b_33[(2 * 3) + j]);
        }
    }

    (void)memcpy(dst, dst_temp, sizeof(dst_temp));
}

typedef struct
{
    float32_t ratio_r;
    float32_t ratio_b;
} wb_ratios_t;

typedef struct
{
    float32_t exposure;
    float32_t gain;
} exposure_gain_t;

#define RGB2RGB_SIZE 12



typedef struct
{
    uint32_t id;
    int64_t val;
    uint32_t y;
    uint32_t x;
} isp_cfg_patch_t;

#define MIN_AE_FREQ 32
#define MAX_PATCHES_NUM 255

typedef struct
{
    ae_context_impl_t ae_context;

} alg_history_data_t;

#ifdef MAGNA_PSA
extern void isp_algorithms(uint32_t camera_num,
    uint32_t phase,
    const struct ar014x_sensor_data* sensorData,
    const struct ISP_data* ispData,
    const struct ISP_config* ispConfig,
    alg_history_data_t* hist_data,
    parameters_storage_t* storage,
    const ae_auto_tables_t* tables,
    ae_params_for_frame_t* out
    );
#else
extern void isp_algorithms(uint32_t camera_num,
    uint32_t phase,
    const struct ar014x_sensor_data* sensorData,
    const struct ISP_data* ispData,
    alg_history_data_t* hist_data,
    parameters_storage_t* storage,
    const ae_auto_tables_t* tables,
    ae_params_for_frame_t* out
    );
#endif

extern void parse_regs_from_emb_line(parameters_storage_t* storage, const struct ar014x_sensor_data* sensorData, uint32_t cam_num);
extern void get_saturation_matrix(float32_t dst[9], float32_t sat);
extern void functions_init_ox3c(sensor_operations_t* ctx);
extern void functions_init_ar233(sensor_operations_t* ctx);
extern void apply_patch_to_settings(struct ISP_config* cfg, const isp_cfg_patch_t patches[MAX_PATCHES_NUM]);
#ifdef MAGNA_PSA
extern void set_default_isp(uint32_t cam_num, struct ISP_config *ispConfig);
extern void set_default_isp_147(uint32_t cam_num, struct ISP_config *ispConfig);
extern void set_default_isp_mv(struct ISP_config *ispConfig);
extern uint32_t read_isp_settings_from_file(const char* path, struct ISP_config* ispcfg, isp_cfg_patch_t patch_cfg[MAX_PATCHES_NUM], bool luts); /* PRQA S 1056 */
extern uint32_t read_isp_patch_from_file(const char* path, isp_cfg_patch_t cfg[MAX_PATCHES_NUM], bool luts); /* PRQA S 1056 */
extern void revert_patch_to_settings(const struct ISP_config* cfg_default, struct ISP_config* cfg, const isp_cfg_patch_t patches[MAX_PATCHES_NUM]);
extern void dump_debug_frame_init(void);
#endif
extern void set_default_isp_233(uint32_t cam_num, struct ISP_config *ispConfig);
extern void set_default_isp_ox3c(uint32_t cam_num, struct ISP_config *ispConfig);
extern void set_isp_val(struct ISP_config* isp_cfg, uint32_t item, float32_t val);
extern const char* get_string_from_id(uint32_t id);
extern void add_tuning_table(const ae_auto_params_table_t* table);
extern void reset_tuning_tables(void);
extern void get_ratio(uint32_t camera_num, uint32_t *r1, uint32_t *r2);
extern const ae_auto_tables_t* get_global_isp_tables(void);

/* PRQA S 1055 -- */

#endif //ISP_PROCESS_H
