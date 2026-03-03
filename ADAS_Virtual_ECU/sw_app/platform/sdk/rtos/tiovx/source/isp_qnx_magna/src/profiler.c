/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           profiler.c
 *  @brief          profiler implementation
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
#include "profiler.h"

// #define PROFILER 1

#ifdef PROFILER
#include <app_log.h>
#include <stdio.h>
#include <ti/osal/SemaphoreP.h>

#define MAX_BUFFER_LOG (512*1024)


profiler_t g_profiler = {0};
void* g_prof_mutex = 0;

static uint32_t timer_init = 0;


static int32_t MutexCreateLock(void **obj)
{
    // app_remote_service_back_init_prms_t remoteServicePrms;

    // appRemoteServiceBackInitSetDefault(&remoteServicePrms);
    // int status2 = appRemoteServiceBackInit(&remoteServicePrms);
    // printf("Init app remote back %d\n", status2);


    int32_t status = 0;
    // SemaphoreP_Params semParams;

    // SemaphoreP_Params_init(&semParams);
    // semParams.mode = SemaphoreP_Mode_BINARY;
    *obj = (void*)0x01;//SemaphoreP_create(1U, &semParams);
    if(*obj==NULL)
    {
        status = -1;
    }

    return status;
}

static void mutex_lock(void **obj)
{
    if(*obj == NULL)
    {
        MutexCreateLock(obj);
    }

    // if(*obj)
    // {
    //     SemaphoreP_pend(*obj, SemaphoreP_WAIT_FOREVER);
    // }
}

static void mutex_unlock(void **obj)
{
    // if(*obj)
    // {
    //     SemaphoreP_post(*obj);
    // }
}


uint64_t get_time_mcs(void)
{
    if (timer_init == 0)
    {
        timer_init = 1U;
        appLogGlobalTimeInit();
    }

    return appLogGetGlobalTimeInUsec();
}

void prof_start(PROFILER_TYPE t)
{
    static unsigned char buf[MAX_BUFFER_LOG] = {0};
    mutex_lock(&g_prof_mutex);
    if (g_profiler.dump == 0)
    {
        g_profiler.dump = buf;//pmem_malloc(MAX_BUFFER_LOG, 9);
    }

    profiler_t* p = &g_profiler;
    uint64_t cur_time = get_time_mcs();
    p->timings[p->tab] = cur_time;
    p->cur_method[p->tab] = t;

    uint16_t* p_dumpui16 = (uint16_t*)(p->dump + p->pos);
    uint32_t* p_dumpui32 = (uint32_t*)(p->dump + p->pos);
    p_dumpui16[0] = (uint16_t)p->tab;
    p_dumpui16[1] = (uint16_t)t;
    p_dumpui32[1] = 0;

    if (p->pos < (MAX_BUFFER_LOG - 128))
        p->pos+=8;

    p->tab++;
    mutex_unlock(&g_prof_mutex);
}

void prof_end(void)
{
    mutex_lock(&g_prof_mutex);
    profiler_t* p = &g_profiler;
    p->tab--;
    uint64_t cur_time = get_time_mcs() - p->timings[p->tab];
    cur_time = (cur_time == 0) ? 1 : cur_time;
    PROFILER_TYPE t = p->cur_method[p->tab];

    uint16_t* p_dumpui16 = (uint16_t*)(p->dump + p->pos);
    uint32_t* p_dumpui32 = (uint32_t*)(p->dump + p->pos);
    p_dumpui16[0] = (uint16_t)p->tab;
    p_dumpui16[1] = (uint16_t)t;
    p_dumpui32[1] = cur_time;

    if (p->pos < (MAX_BUFFER_LOG - 128))
        p->pos+=8;

    mutex_unlock(&g_prof_mutex);
}

#define STRINGIFY(x) #x  /* PRQA S 0341 */
#define STRING_LIST(x) STRINGIFY(x),  /* PRQA S 0341 */

#pragma pack(push, 1) /* set compiler alignment size to 1 byte and save previous setting to compiler stack */
typedef struct
{
    uint16_t tab;
    uint16_t method;
    uint32_t delta_t;
} prof_item_t;
#pragma pack(pop) /* restore compiler alignment size setting */

void print_prof(void)
{
    printf("----------------print_prof-0-----------------------\n");
    // appRemoteServiceBackRun(APP_IPC_CPU_MPU1_0, "my_test_func",
    //     1,
    //     (void*)g_profiler.dump, g_profiler.pos,
    //     0);
    printf("----------------print_prof-1-----------------------\n");

    static const char* arr[] =
    {
        "BEGIN ",
        PROFILER_ITEMS(STRING_LIST)
        "END",
    };

    mutex_lock(&g_prof_mutex);
    const prof_item_t* items = (const prof_item_t*)g_profiler.dump;
    uint32_t len = g_profiler.pos / 8;
    mutex_unlock(&g_prof_mutex);

    uint32_t c;
    for (c = 0; c < len; c++)
    {
        uint16_t tab = 0;
        uint16_t method = 0;
        uint32_t t = 0;

        tab = items->tab;
        method = items->method;
        t = items->delta_t;
        items++;

        int i;
        for (i = 0; i < tab; i++)
            printf("    ");

        printf("%s", arr[method]);

        if (t == 0)
            printf(" start\n");
        else
        {
            printf(" end time = %.2f\n", t / 1000.f);
        }
    }
}

#else
void print_prof(void)
{

}

void prof_dump(void)
{

}

void prof_start(PROFILER_TYPE t)
{

}

void prof_end(void)
{
}
#endif



#ifdef PC_PROFILER_PRINT

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define STRINGIFY(x) #x  /* PRQA S 0341 */
#define STRING_LIST(x) STRINGIFY(x),  /* PRQA S 0341 */


void print_log(const char* path)
{
    FILE* f = fopen(path, "rb");

    static const char* arr[] =
    {
        "BEGIN ",
        PROFILER_ITEMS(STRING_LIST)
        "END",
    };

    while(true)
    {
        uint16_t tab = 0;
        uint16_t method = 0;
        uint32_t t = 0;
        uint32_t r = 0;
        r = fread(&tab, 2, 1, f);
        r+= fread(&method, 2, 1, f);
        r+= fread(&t, 4, 1, f);

        if (r != 3)
            break;

        for (int i = 0; i < tab; i++)
            printf("    ");

        printf("%s", arr[method]);

        if (t == 0)
            printf(" start\n");
        else
        {
            printf(" end time = %.2f\n", t / 1000.f);
        }
    }

    fclose(f);
}

int main()
{
	print_log("/tmp/dump.bin");
	return 0;
}
#endif
