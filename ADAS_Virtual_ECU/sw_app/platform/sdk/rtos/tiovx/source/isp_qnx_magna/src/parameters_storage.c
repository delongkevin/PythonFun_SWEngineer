/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           parameters_storage.h
 *  @brief          property storage implementation
 *
 *
 *  @version        3.31
 *  @author         Mikhail Vakhrushev
 *  @date           10.04.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* PRQA S 0491 ++ */
/* PRQA S 0310 ++ */
/* PRQA S 0311 ++ */
/* PRQA S 1055 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0841 ++ */
/* PRQA S 0342 ++ */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "isp_aux.h"
#include "../public/cogent/cogent_api.h"
#include "parameters_storage.h"

typedef struct
{
    float32_t data[circular_buffer_max_sz];
    uint32_t sz;
    int32_t cur;
    uint32_t init;
    /* data */
} circular_buffer_t; /* PRQA S 3448 */

/* PRQA S 2814 ++ */

static inline void circular_buffer_init(circular_buffer_t* p)
{
    uint32_t i;

    if (p->init == 0)
    {
        p->init = 1;
        p->sz = 0;
        p->cur = -1;

        for (i = 0; i < circular_buffer_max_sz; i++)
        {
            p->data[i] = INVALID_VALUE;
        }
    }
}

/* PRQA S 2814 --*/

static void circular_buffer_push(circular_buffer_t* p, float32_t val)
{
    if (p != NULL)
    {
        circular_buffer_init(p);
        p->cur++;
        p->sz = ISP_MIN(p->sz + 1, circular_buffer_max_sz);
        p->cur = p->cur % (int32_t)circular_buffer_max_sz;
        p->data[p->cur] = val;
    }
}

static float32_t circular_buffer_get(const circular_buffer_t* p, int32_t delay)
{
    float32_t ret = INVALID_VALUE;

    if (p != NULL)
    {
        if (delay < (int32_t)p->sz)
        {
            int32_t indx = ((int32_t)p->cur + (int32_t)circular_buffer_max_sz) - delay;
            indx = indx % (int32_t)circular_buffer_max_sz;
            ret = p->data[indx];
        }
    }

    return ret;
}

/* PRQA S 3410 ++ */

#ifdef ITEM_PROC
#undef ITEM_PROC
#endif
#define ITEM_PROC(X) circular_buffer_t buffer_##X;
struct parameters_storage_s
{
    uint32_t stored_parameters[PARAMS_NUM_ALL];
    LIST_OF_BUFFERS_REQUIRE_PARAMS() /* PRQA S 2814 */
};

#ifdef ITEM_PROC
#undef ITEM_PROC
#endif
#define ITEM_PROC(X) case X:\
    ret = circular_buffer_get(&isp_context->buffer_##X, (delay - 1));\
    break;

/* PRQA S 3410 -- */

float32_t get_buffer_parameter(const parameters_storage_t* isp_context, int32_t id, int32_t delay)
{
    float32_t ret = INVALID_VALUE;
    if (delay > 0)
    {
        switch ((int32_t)id)
        {
            LIST_OF_BUFFERS_REQUIRE_PARAMS() /* PRQA S 2814 */

        default:
            break;
        }
    }
    else
    {
        ret = get_param(isp_context, id);
    }


    return ret;
}

#ifdef ITEM_PROC
#undef ITEM_PROC
#endif
#define ITEM_PROC(X) \
    circular_buffer_push(&isp_context->buffer_##X, get_param(isp_context, (int32_t)X));

void push_buffer_parameters(parameters_storage_t* isp_context)
{
    LIST_OF_BUFFERS_REQUIRE_PARAMS() /* PRQA S 2814 */ /* PRQA S 1401 */  /* PRQA S 1461 */
}

static float32_t table_data_storage[2048] = {0};
static uint32_t table_data_storage_pointer = 0;
static uint32_t table_data_storage_sz = sizeof(table_data_storage) / sizeof(table_data_storage[0]); /* PRQA S 3218 */

static parameters_storage_t storages[MAX_CAMERAS_NUM*2] = {0};

float32_t get_param(const parameters_storage_t* isp_context, int32_t item)
{
    float32_t ret = 0.0f;

    if (isp_context != NULL)
    {
        float32_t* data = (float32_t*)isp_context->stored_parameters;
        ret = data[item];
    }

    return ret;
}

void* get_param_address(const parameters_storage_t* isp_context, int32_t item)
{
    float32_t* ret = NULL;

    if (isp_context != NULL)
    {
        float32_t* data = (float32_t*)isp_context->stored_parameters;
        ret = &data[item];
    }

    return ret;
}

void set_param(parameters_storage_t* isp_context, int32_t item, float32_t val)
{
    if (isp_context != NULL)
    {
        float32_t* data = (float32_t*)isp_context->stored_parameters;
        data[item] = val;
    }
}

uint32_t get_param_ui(parameters_storage_t* isp_context, int32_t item)
{
    uint32_t ret = 0.0f;

    if (isp_context != NULL)
    {
        uint32_t* data = (uint32_t*)isp_context->stored_parameters;
        ret = data[item];
    }

    return ret;
}

void set_param_ui(parameters_storage_t* isp_context, int32_t item, uint32_t val)
{
    if (isp_context != NULL)
    {
        uint32_t* data = (uint32_t*)isp_context->stored_parameters;
        data[item] = val;
    }
}

parameters_storage_t* get_parameters_storage(uint32_t cam_num)
{
    parameters_storage_t* ret = NULL;

    if (cam_num < MAX_CAMERAS_NUM)
    {
        ret = &storages[cam_num];
    }

    return ret;
}

parameters_storage_t* get_parameters_storage_copy(uint32_t cam_num)
{
    parameters_storage_t* ret = NULL;

    if (cam_num < MAX_CAMERAS_NUM)
    {
        ret = &storages[cam_num + MAX_CAMERAS_NUM];
        *ret = storages[cam_num];
    }

    return ret;
}

void reset_allocator(void)
{
    (void)memset(table_data_storage, 0, sizeof(table_data_storage));
    table_data_storage_pointer = 0;
}

float32_t* get_float_data(uint32_t sz)
{
    float32_t* ret = 0;

    if (sz <= (table_data_storage_sz + table_data_storage_pointer))
    {
        ret = &table_data_storage[table_data_storage_pointer];
        table_data_storage_pointer+= sz;
    }

    return ret;
}

/* PRQA S 0310 -- */
/* PRQA S 0311 -- */
/* PRQA S 0491 -- */
/* PRQA S 1055 -- */
/* PRQA S 3450 -- */
/* PRQA S 0781 -- */
/* PRQA S 3412 -- */
/* PRQA S 0841 -- */
/* PRQA S 0342 -- */
