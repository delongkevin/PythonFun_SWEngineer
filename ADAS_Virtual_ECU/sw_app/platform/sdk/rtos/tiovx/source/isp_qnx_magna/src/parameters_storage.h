/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           parameters_storage.h
 *  @brief          property storage API declaration
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
#ifndef PARAMETERS_STORAGE_H
#define PARAMETERS_STORAGE_H

/* PRQA S 1055 ++ */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "isp_aux.h"

#include "../public/cogent/cogent_api.h"
typedef ISP_ITEM_EXTENDED AE_CONTROL_ITEM;
#define circular_buffer_max_sz 8U

typedef struct parameters_storage_s parameters_storage_t; /* PRQA S 3313 */

float32_t get_param(const parameters_storage_t* isp_context, int32_t item);
float32_t get_buffer_parameter(const parameters_storage_t* isp_context, int32_t id, int32_t delay);
void push_buffer_parameters(parameters_storage_t* isp_context);
void* get_param_address(const parameters_storage_t* isp_context, int32_t item);
void set_param(parameters_storage_t* isp_context, int32_t item, float32_t val);
uint32_t get_param_ui(parameters_storage_t* isp_context, int32_t item);
void set_param_ui(parameters_storage_t* isp_context, int32_t item, uint32_t val);

#ifdef MAGNA_PSA
void init_params(const struct ISP_config* isp_config, parameters_storage_t* isp_context);
#endif
parameters_storage_t* get_parameters_storage(uint32_t cam_num);
parameters_storage_t* get_parameters_storage_copy(uint32_t cam_num);

static inline float32_t get_param_check(const parameters_storage_t* storage, int32_t item, bool* check) /* PRQA S 1056 */
{
    float32_t ret = get_param(storage, item);
    *check &= check_invalid(ret) == false; /* PRQA S 4104 */ /* PRQA S 4103 */
    return ret;
}

static inline float32_t get_buffer_param_check(const parameters_storage_t* storage, int32_t item, int32_t delay, bool* check) /* PRQA S 1056 */
{
    float32_t ret = get_buffer_parameter(storage, item, delay);
    *check &= check_invalid(ret) == false; /* PRQA S 4104 */ /* PRQA S 4103 */
    return ret;
}

static inline  void set_param_if_empty(parameters_storage_t* parameters_storage, int32_t item, float32_t val)
{
    float32_t ret = get_param(parameters_storage, item);

    if (check_invalid(ret))
    {
        set_param(parameters_storage, item, val);
    }
}

void reset_allocator(void);
float32_t* get_float_data(uint32_t sz);

/* PRQA S 1055 -- */

#endif  //PARAMETERS_STORAGE_H
