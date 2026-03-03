/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           isp_aux.c
 *  @brief          Logging function
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

#include "isp_process.h"

extern float32_t* g_isp_log_level;  /* PRQA S 3447 */ /* PRQA S 3451 */
extern float32_t* g_isp_log_to_file; /* PRQA S 3447 */

#ifdef MAGNA_PSA
static pthread_mutex_t async_print_lock = PTHREAD_MUTEX_INITIALIZER; /* PRQA S 1053 */
static pthread_cond_t async_print_cnd = {0};

static char async_buf[32768] = {0};
static char async_buf_2[32768] = {0}; /* PRQA S 3218 */
static uint32_t async_buf_pointer = 0U;
static uint32_t async_buf_pointer_2 = 0U; /* PRQA S 3218 */ /* PRQA S 3229 */
#endif

#ifdef _UTESTS
static FILE* tmp_file = 0;
static uint32_t first_run = 1U;
static pthread_t async_print_thrd = 0;
static uint32_t warning_message = 0;
#endif

#ifdef MAGNA_PSA
static void print_to_file(const char* string) /* PRQA S 3450 */
{
#ifndef _UTESTS
    static FILE* tmp_file = 0;
    static uint32_t first_run = 1U;
#endif

    if (first_run == 1U)
    {
        if (magna_camera_sensor_type == MAGNA_CAMERA_SENSOR_AR0143)
        {
            tmp_file = fopen("/sd/isp_log_143.txt", "a+");
        }
        else
        {
            tmp_file = fopen("/sd/isp_log_147.txt", "a+");
        }

        first_run = 0U;
    }

    if (tmp_file != NULL)
    {
        (void)fprintf(tmp_file, "%s", string);
        (void)fflush(tmp_file);
    }
}

void* async_thread(void* not_used)/* PRQA S 3408 *//* PRQA S 3206 */
{
    while (ever())/* PRQA S 2870 *//* PRQA S 2740 */
    {
        (void)pthread_mutex_lock(&async_print_lock);
        while (async_buf_pointer == 0)
        {
            (void)pthread_cond_wait(&async_print_cnd, &async_print_lock);
        }

        {
            (void)memcpy(async_buf_2, async_buf, sizeof(async_buf_2));
            async_buf_pointer_2 = async_buf_pointer;
            async_buf_pointer = 0;
        }

        (void)pthread_mutex_unlock(&async_print_lock);

        if ((g_isp_log_to_file != NULL) && (*g_isp_log_to_file > FLT_EPSILON))
        {
            print_to_file(async_buf_2);
        }

        (void)printf("%s", async_buf_2);
        async_buf_pointer_2 = 0U;
    }

    return NULL;
}

void async_print(const char* str)
{
#ifndef _UTESTS
    static pthread_t async_print_thrd = 0;
    static uint32_t warning_message = 0;
#endif
    uint32_t l;

    if (str != NULL)
    {
        (void)pthread_mutex_lock(&async_print_lock);
        if (async_print_thrd == 0)
        {
            (void)pthread_create(&async_print_thrd, 0, async_thread, 0);/* PRQA S 3635 */
            (void)pthread_cond_init(&async_print_cnd, NULL);
        }

        l = (uint32_t)strlen(str);

        if ((async_buf_pointer + l + 1) > sizeof(async_buf))
        {
            if (warning_message == 0)
            {
                (void)fprintf(stderr, "\noverflow PRINTING BUFFER\n");
            }
            warning_message = 1;
        }
        else
        {
            (void)strcpy(&async_buf[async_buf_pointer], str);
            async_buf_pointer+= l;
            async_buf[async_buf_pointer] = 0;
            (void)pthread_cond_signal(&async_print_cnd);
        }

        (void)pthread_mutex_unlock(&async_print_lock);
    }
}
#endif



void get_saturation_matrix(float32_t dst[9], float32_t sat)
{
    float32_t to_hsv[9] = {
        0.299f, 0.587f, 0.114f,
        0.596f, -0.274f, -0.321f,
        0.211f, -0.523f, 0.311f
    };

    float32_t sat_mat[9] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
    };

    float32_t to_rgb[9] = {
        1.0f, 0.956f, 0.621f,
        1.0f, -0.272f, -0.647f,
        1.0f, -1.107f, 1.705f,
    };

    sat_mat[4] = sat;
    sat_mat[8] = sat;

    mul33_33(dst, sat_mat, to_hsv);
    mul33_33(dst, to_rgb, dst);
}
