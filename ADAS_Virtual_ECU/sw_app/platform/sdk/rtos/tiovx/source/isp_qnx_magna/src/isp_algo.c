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

/* PRQA S 1412 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 1317 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 0881 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0491 ++ */
/* PRQA S 0342 ++ */
/* PRQA S 0841 ++ */
/* PRQA S 1056 ++ */
/* PRQA S 1055 ++ */
/* PRQA S 0604 ++ */
/* PRQA S 1031 ++ */

#include "isp_algo.h"


typedef struct
{
    int32_t input;
    int32_t output;
    uint32_t freq_id;
    uint32_t phase_id;
}parameter_copy_table_t;

typedef struct
{
    AE_CONTROL_ITEM internal_status;
    AE_CONTROL_ITEM internal_disable;
    AE_CONTROL_ITEM external_enable;
}algorithms_enable_flags_t;

static bool is_float(int32_t id);

static parameter_copy_table_t ISP_FAST_LOCAL_VARIABLE parameter_copy_table[] =
{
    #define ALGO_IMPL(NAME) NAME##_OUT(NAME)
    #include "algo_reg.h"

    #define ALGO_IMPL(NAME) {ISP_INTERNAL_##NAME##_STATUS, ISP_INTERNAL_##NAME##_STATUS, NAME##_IN_FREQ, NAME##_IN_PHASE},
    #include "algo_reg.h"
};


static algorithms_enable_flags_t algorithms_enable_flags[] =
{
    #define ALGO_IMPL(NAME) {ISP_INTERNAL_##NAME##_STATUS, ISP_INTERNAL_##NAME##_DISABLE, NAME##_IN_ENABLED},
    #include "algo_reg.h"
};

static const uint32_t algorithms_enable_flags_sz = sizeof(algorithms_enable_flags) / sizeof(algorithms_enable_flags[0]);
static const uint32_t parameter_copy_table_sz = sizeof(parameter_copy_table) / sizeof(parameter_copy_table[0]);

#ifdef _UTESTS
static const float32_t ones[2] = {1,2};
#endif



void fill_one_item_copy(ae_auto_params_table_t* dst, int32_t inp, int32_t control, uint32_t freq, uint32_t phase)/* PRQA S 3408 */
{
#ifndef _UTESTS
    static const float32_t ones[2] = {1,2};
#endif

    if (dst != NULL)
    {
        dst->control = control;
        dst->interp_type = INTERP_LINEAR_EXTRAPOLATION;
        dst->input = inp;
        dst->table_size = 2;
        dst->in = ones;
        dst->out = ones;
        dst->freq = freq;
        dst->phase = phase;
        dst->enable = 1;
    }
}


static bool patch_has_value(ae_output_queue_t* tasks, int32_t item)
{
    bool bret = false;

    if ((tasks != NULL) && (tasks->tasks_num > 0))
    {
        uint32_t k;

        for (k = 0; k < tasks->tasks_num; k++)
        {
            ae_params_for_frame_t* params = &tasks->tasks[k];

            uint32_t i;

            for (i = 0; i < params->patches_num; i++)
            {
                if (params->patches[i].control == item)
                {
                    bret = true;
                    break;
                }
            }
        }
    }

    return bret;
}

static inline ae_auto_params_table_t get_table_c(const parameters_storage_t* s, const ae_auto_tables_t* tables, uint32_t num)
{ /* PRQA S 0654 */
    ae_auto_params_table_t param_table = {0};

    if ((s != NULL) && (tables != NULL))
    {
        if (((int32_t)num - (int32_t)tables->ae_auto_table_num) < (int32_t)parameter_copy_table_sz)
        {
            if (num < tables->ae_auto_table_num)
            {
                param_table = tables->ae_auto_table[num];
            }
            else
            {
                uint32_t n = num - tables->ae_auto_table_num;
                uint32_t freq = (uint32_t)get_param(s, parameter_copy_table[n].freq_id); /* PRQA S 1482*/ /* PRQA S 1441*/
                uint32_t phase = (uint32_t)get_param(s, parameter_copy_table[n].phase_id); /* PRQA S 1482*/ /* PRQA S 1441*/
                fill_one_item_copy(&param_table, parameter_copy_table[n].input, parameter_copy_table[n].output, freq, phase);
            }
        }
    }

    return param_table;
}




void ae_context_push_param(ae_context_impl_t* c, float32_t val, int32_t control, uint32_t dst_frame)
{
    if ((c != NULL) && (dst_frame < MAX_AE_FRAMES_QUEUE_SZ))
    {
        while (dst_frame >= c->tasks.tasks_num)
        {
            c->tasks.tasks_num++;
            c->tasks.tasks[c->tasks.tasks_num].patches_num = 0;
        }

        ae_params_for_frame_t* frame_settings = &c->tasks.tasks[dst_frame];

        if (frame_settings->patches_num < MAX_AE_PATCH_SZ)
        {
            frame_settings->patches[frame_settings->patches_num].control = control;
            frame_settings->patches[frame_settings->patches_num].data_f32 = val;
            frame_settings->patches_num++;
        }
    }
}

const ae_auto_params_table_t* find_table_by_id(const ae_auto_tables_t* tables, int32_t item)
{
    const ae_auto_params_table_t* ret = NULL;
    uint32_t i;

    if (tables != NULL)
    {
        for (i = 0; i < tables->ae_auto_table_num; i++)
        {
            if (tables->ae_auto_table[i].control == item)
            {
                ret = &tables->ae_auto_table[i];
                break;
            }
        }
    }

    return ret;
}

static inline void round_value(float32_t* val, int32_t control)
{
    if (is_float(control) == false)
    {
        *val = floorf(*val + 0.5f); /* PRQA S 2814 */
    }
}

static inline void interpolate_push_one(ae_context_impl_t* context,
    float32_t prev,
    float32_t cur,
    uint32_t steps_num,
    uint32_t cur_step,
    int32_t control,
    int32_t intype,
    int32_t interp_type,
    uint32_t dst_frame
    )
{

    float32_t ret = (interp_type == INTERP_NEAREST)
        ? interpolate_one(cur, cur, steps_num, cur_step)
        : interpolate_one(prev, cur, steps_num, cur_step);

    round_value(&ret, control);
    if (((cmp_f32(prev, ret) == false) || (intype == control)) && (check_invalid(cur) == false)) /* PRQA S 3415 */
    {
        ae_context_push_param(context, ret, control, dst_frame);
    }
}


float32_t get_table_value( const ae_auto_params_table_t* adjust_table, float32_t x)
{
    const ae_auto_params_table_t* t = adjust_table;
    float32_t ret = INVALID_VALUE;

    if ((check_invalid(x) == false) && (t != NULL))
    {
        int32_t interp_type = t->interp_type;
        uint32_t i = 0;

        while (i < (t->table_size - 2))
        {
            if (x < t->in[i + 1])
            {
                break;
            }

            i++;
        }

        float32_t x1 = t->in[i];
        float32_t x2 = t->in[i + 1];
        float32_t y1 = t->out[i];   /* PRQA S 3334 */
        float32_t y2 = t->out[i + 1];

        float32_t q = (x - x1) / (x2 - x1);

        if (interp_type == INTERP_LINEAR_CLAMP)
        {
            q = clampf32(q, 0.f, 1.f);
        }

        if (interp_type == INTERP_NEAREST)
        {
            q = floorf(q + 0.5f);
            q = clampf32(q, 0.f, 1.f);
        }

        ret = (y1 + ((y2 - y1) * q));
    }

    return ret;
}

static inline float32_t find_value_table( const ae_auto_tables_t* adjust_tables, const parameters_storage_t* storage,
    uint32_t num, int32_t item[])
{
    const ae_auto_params_table_t t = get_table_c(storage, adjust_tables, num);
    float32_t ret = INVALID_VALUE;

    if ((item != NULL) && (t.enable != 0))
    {
        item[0] = t.control;
        float32_t x = get_param(storage, t.input);
        ret = get_table_value(&t, x);
    }

    return ret;
}

static void estimate_isp_based_parameters(
    ae_context_impl_t* context,
    const parameters_storage_t* parameters_storage,
    const ae_auto_tables_t* tuning_tables
    )
{
    uint32_t i;

    uint32_t buf_num;

    if ((context != NULL) && (parameters_storage != NULL) && (tuning_tables != NULL))
    {
        buf_num = tuning_tables->ae_auto_table_num + parameter_copy_table_sz;

        for (i = 0; i < buf_num; i++)
        {
            float32_t new_value = INVALID_VALUE;

            int32_t item = 0;
            float32_t val = find_value_table(tuning_tables, parameters_storage, i, &item);

            if (patch_has_value(&context->tasks, item) == false)
            {
                new_value = val;
            }

            ae_auto_params_table_t tab = get_table_c(parameters_storage, tuning_tables, i);

            if (tab.phase == 0)
            {
                int32_t type = tab.control;
                int32_t intype = tab.input;
                int32_t interp_type = tab.interp_type;

                float32_t prev_val = get_param(parameters_storage, type);
                uint32_t steps_num = tab.freq;
                uint32_t k;

                for (k = 0; k < steps_num; k++)
                {
                    if (check_invalid(new_value) == false)
                    {
                        interpolate_push_one(context, prev_val, new_value, steps_num, k, type, intype,interp_type, k);
                    }
                }
            }
        }
    }
}

static void add_new_value_to_patch(ae_params_for_frame_t* out, int32_t type, float32_t new_value)
{
    if ( (out != NULL) && (out->patches_num < MAX_AE_PATCH_SZ))
    {
        out->patches[out->patches_num].control = type;
        out->patches[out->patches_num].data_f32 = new_value;
        out->patches_num++;
    }
}

static void estimate_isp_based_parameters_post(
    ae_context_impl_t* context,
    const parameters_storage_t* parameters_storage,
    const ae_auto_tables_t* tuning_tables,
    uint32_t phase,
    ae_params_for_frame_t* out
    )
{
    uint32_t i;

    uint32_t buf_num;

    if ((context != NULL) &&
        (parameters_storage != NULL) &&
        (tuning_tables != NULL) &&
        (out != NULL))
    {
        uint32_t auto_table_sz = tuning_tables->ae_auto_table_num;
        buf_num = auto_table_sz + parameter_copy_table_sz;

        for (i = 0; i < buf_num; i++)
        {
            if (i >= auto_table_sz)
            {
                uint32_t n = i - auto_table_sz;
                float32_t check_val = get_param(parameters_storage, parameter_copy_table[n].input); /* PRQA S 1482*/ /* PRQA S 1441*/
                if (INVALID_VALUE == check_val)
                {
                    continue;
                }
            }

            float32_t new_value = INVALID_VALUE;

            int32_t item = 0;
            float32_t val = find_value_table(tuning_tables, parameters_storage, i, &item);

            if (patch_has_value(&context->tasks, item) == false)
            {
                new_value = val;
            }

            ae_auto_params_table_t tab = get_table_c(parameters_storage, tuning_tables, i);

            if (tab.phase == phase)
            {
                int32_t type = tab.control;
                float32_t prev_val = get_param(parameters_storage, type);

                round_value(&new_value, type);

                if ((check_invalid(new_value) == false) && (cmp_f32(prev_val, new_value) == false))  /* PRQA S 3415 */
                {
                    add_new_value_to_patch(out, type, new_value);
                }
            }
        }
    }
}

static void fill_from_patches(ae_output_queue_t* tasks, parameters_storage_t* storage)
{
    if ((tasks != NULL) && (storage != NULL) && (tasks->tasks_num > 0))
    {
        uint32_t k;

        for (k = 0; k < tasks->tasks_num; k++)
        {
            ae_params_for_frame_t* params = &tasks->tasks[k];

            uint32_t i;

            for (i = 0; i < params->patches_num; i++)
            {
                int32_t item = params->patches[i].control;
                float32_t val = params->patches[i].data_f32;
                uint32_t j;
                for (j = 0; j < algorithms_enable_flags_sz; j++)
                {
                    if (item == algorithms_enable_flags[j].internal_status)
                    {
                        set_param_if_empty(storage, algorithms_enable_flags[j].internal_disable, 1.f);
                    }
                }

                if (item > ISP_INTERNAL_SECTION)
                {
                    set_param(storage, item, val);
                }
            }
        }
    }
}

#define ALGO_IMPL(NAME) \
{ \
    uint32_t NAME##cur_phase = (uint32_t) get_param(parameters_storage, NAME##_IN_PHASE); \
    max_phase = ISP_MAX(max_phase, NAME##cur_phase); \
} /* PRQA S 3458 */

uint32_t get_max_phase(parameters_storage_t* parameters_storage) /* PRQA S 3673 */
{
    uint32_t max_phase = 0U;
    #include "algo_reg.h"
    return max_phase;
}

#define ALGO_IMPL(NAME) if (get_param(parameters_storage, ISP_INTERNAL_##NAME##_DISABLE) != 1.f) \
    { \
        if (get_param(parameters_storage, NAME##_IN_PHASE) == phase) \
        { \
            float32_t __alg_status__ = NAME##_run(context, stats, parameters_storage, cam_num); \
            if (__alg_status__ >= 0) \
            { \
                set_param_if_empty(parameters_storage, ISP_INTERNAL_##NAME##_STATUS, __alg_status__); \
            } \
        } \
    }


void algorithm_pipeline(
    ae_context_impl_t* context,  /* PRQA S 1330 */
    uint32_t cam_num,
    parameters_storage_t* parameters_storage,
    const ae_input_stats_t* stats,
    const ae_auto_tables_t* adjust_tables,
    uint32_t phase,
    ae_params_for_frame_t* out)
{
    PROF_START(algorithm_pipeline);
    if ((context != NULL) &&
        (parameters_storage != NULL) &&
        (adjust_tables != NULL) &&
        (out != NULL))
    {
        context->adjust_tables = adjust_tables;

        if (phase == 0)
        {
            /// storage preparation

            fill_from_patches(&context->tasks, parameters_storage);
            context->tasks.tasks[context->tasks.tasks_num].patches_num = 0;
            out->patches_num = 0;

            uint32_t j;
            for (j = 0; j < algorithms_enable_flags_sz; j++)
            {
                if (get_param(parameters_storage, algorithms_enable_flags[j].external_enable) < 1.0f)
                {
                    set_param_if_empty(parameters_storage, algorithms_enable_flags[j].internal_disable, 1.f);
                }
            }
        }

        #include "algo_reg.h"

        if (phase == 0)
        {
            estimate_isp_based_parameters(context, parameters_storage, adjust_tables);

            /// send output settings
            if (context->tasks.tasks_num != 0)
            {
                *out = context->tasks.tasks[0];
                context->tasks.tasks_num--;
                if (context->tasks.tasks_num != 0)
                {
                    (void)memmove(&context->tasks.tasks[0], &context->tasks.tasks[1], sizeof(ae_params_for_frame_t)*(context->tasks.tasks_num));
                }
            }
        }
        else
        {
            out->patches_num = 0;
            estimate_isp_based_parameters_post(context, parameters_storage, adjust_tables, phase, out);
        }
    }

    PROF_END(algorithm_pipeline);
}

/* PRQA S 0862 ++ */

#ifdef ITEM_PROC_I
#undef ITEM_PROC_I
#endif
#ifdef ITEM_PROC_F
#undef ITEM_PROC_F
#endif
#define ITEM_PROC_I(X)
#define ITEM_PROC_F(X) case X:  /* PRQA S 3410 */

static bool is_float(int32_t id)
{
    bool ret;
    switch (id)
    {
        LIST_ISP_CFG()
        LIST_NON_ISP_CFG()
        LIST_INTERNAL_CFG()
        ret = true;
        break;

    default:
        ret = false;
        break;
    }

    return ret;
}

/* PRQA S 1412 -- */
/* PRQA S 3450 -- */
/* PRQA S 1317 -- */
/* PRQA S 0781 -- */
/* PRQA S 0881 -- */
/* PRQA S 3412 -- */
/* PRQA S 0491 -- */
/* PRQA S 0862 -- */
/* PRQA S 0342 -- */
/* PRQA S 0841 -- */
/* PRQA S 1056 -- */
/* PRQA S 1055 -- */
/* PRQA S 0604 -- */
/* PRQA S 1031 -- */
