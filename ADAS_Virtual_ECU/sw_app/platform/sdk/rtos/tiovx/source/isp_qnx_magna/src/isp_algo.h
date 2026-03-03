/** @ingroup
 *  @file           isp_ae.h
 *  @brief          Auto-Exposure API
 *
 *  @version        3.31
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           28.02.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef ISP_AE_ALG_H
#define ISP_AE_ALG_H
/* PRQA S 0930 ++ */
/* PRQA S 0342 ++ */
/* PRQA S 3412 ++ */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "isp_aux.h"
#include "awb-impl.h"

#include "parameters_storage.h"

extern float32_t* g_isp_log_cam ;
extern uint32_t g_counters[];



#define AWB_STAT_SZ 225
#define MAX_AE_PATCH_SZ 128
#define MAX_AE_FRAMES_QUEUE_SZ 64
#define MAX_AE_TUNABLE_PARAMETERS_SZ 256


#define ANALOG_GAIN_DAY 5
#define ANALOG_GAIN_NIGHT 7


typedef enum
{
    INTERP_LINEAR_CLAMP = 1,
    INTERP_LINEAR_EXTRAPOLATION = 2,
    INTERP_NEAREST = 3,
}AE_INTERP_TYPE;

typedef enum
{
    ALGS_AE = 0,
    ALGS_AWB,
    ALGS_NEAREST,
}ALGS_ID;


#define ae_auto_params_table_name_sz 16
typedef struct
{
    int32_t control;
    int32_t    interp_type;
    int32_t     input;
    const float32_t*        out;
    const float32_t*        in;
    uint32_t          table_size;
    uint32_t          freq;
    uint32_t          phase;
    char name[ae_auto_params_table_name_sz];
    uint32_t enable;
} ae_auto_params_table_t;


typedef struct
{
    ae_auto_params_table_t ae_auto_table[MAX_AE_TUNABLE_PARAMETERS_SZ];
    uint32_t ae_auto_table_num;
} ae_auto_tables_t;

typedef enum
{
    AE_IN_PROCESS = 0,
    AE_FINISHED = 1,
    AE_IN_MODE_SWITCHING = 2,
    AE_FAILURE = 3,
}AE_STATUS;

typedef struct
{
    int32_t control;
    float32_t data_f32;
} ae_one_param_t;

typedef struct
{
    ae_one_param_t patches[MAX_AE_PATCH_SZ];
    uint32_t patches_num;
} ae_params_for_frame_t;

typedef struct
{
    ae_params_for_frame_t tasks[MAX_AE_FRAMES_QUEUE_SZ];
    uint32_t tasks_num;
} ae_output_queue_t;


typedef struct
{
    uint32_t data[128];
}   ae_dummy_t;

typedef struct
{
    const ae_auto_tables_t* adjust_tables;
    ae_output_queue_t tasks;
    float32_t sum_br_diff;
    ae_dummy_t ae_dummy;
    awb_context_t awb_context;
} ae_context_impl_t;




typedef struct
{
    float32_t histogram_5bins[5];
    uint32_t full_sensor_hist[512];
    uint32_t full_sensor_hist_pix_count;
    const float32_t* full_sensor_hist_weight;
    uint32_t hist_bins_num;
    awb_statistics_block_t awb_stat[ISP_AWB_NUM_ZONES];
    float32_t brightness;
    float32_t white_q;
    uint32_t global_night_mode;
} ae_input_stats_t;

void algorithm_pipeline(
    ae_context_impl_t* ae_context,
    uint32_t cam_num,
    parameters_storage_t* isp_context,
    const ae_input_stats_t* stats,
    const ae_auto_tables_t* adjust_tables,
    uint32_t phase,
    ae_params_for_frame_t* out);


void ae_context_push_param(ae_context_impl_t* c, float32_t val, int32_t control, uint32_t dst_frame);
uint32_t get_max_phase(parameters_storage_t* parameters_storage);
const ae_auto_params_table_t* find_table_by_id(const ae_auto_tables_t* tables, int32_t item);
float32_t get_table_value( const ae_auto_params_table_t* adjust_table, float32_t x);

#define ALGO_IMPL(NAME) float32_t NAME##_run( \
    ae_context_impl_t* context, \
    const ae_input_stats_t* stats, \
    parameters_storage_t* storage, \
    uint32_t cam_num \
    );
#include "algo_reg.h"

/* PRQA S 0930 -- */
/* PRQA S 0342 -- */
/* PRQA S 3412 -- */

#endif //ISP_AE_ALG_H
