/*******************************************************************************
 * common.h
 *
 * SV-PC application - common definitions
 *
 * Copyright (c) 2015-2020 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 * No part of the Software may be used, copied, reproduced, modified, published,
 * uploaded, posted, transmitted, distributed, or disclosed in any way without
 * prior express written permission from Cogent Embedded Inc.
 *
 * Cogent Embedded Inc. grants a nonexclusive, non-transferable, royalty-free
 * license to use the Software to Licensee without the right to sublicense.
 * Licensee agrees not to distribute the Software to any third-party without
 * the prior written permission of Cogent Embedded Inc.
 *
 * Unless otherwise agreed by Cogent Embedded Inc. in writing, you may not remove
 * or alter this notice or any other notice embedded in Software in any way.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#ifndef __SV_COMMON_H
#define __SV_COMMON_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>
#include <sched.h>

#include <sys/syspage.h>
#include <sys/neutrino.h>
#include <inttypes.h>

/*******************************************************************************
 * Primitive typedefs
 ******************************************************************************/

typedef uint8_t         u8;
typedef uint16_t        u16;
typedef uint32_t        u32;
typedef uint64_t        u64;

typedef int8_t          s8;
typedef int16_t         s16;
typedef int32_t         s32;
typedef int64_t         s64;

typedef float           float32_t;

/*******************************************************************************
 * Auxiliary macros
 ******************************************************************************/

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#ifndef offset_of
#define offset_of(type, member)         \
    ((int)(intptr_t)&(((const type *)(0))->member))
#endif

#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((void *)(ptr) - offset_of(type, member)))
#endif

/*******************************************************************************
 * Bug check for constant conditions (file scope)
 ******************************************************************************/

#define __C_BUG(n)      __C_BUG2(n)
#define __C_BUG2(n)     __c_bug_##n
#define C_BUG(expr)     typedef char __C_BUG(__LINE__)[(expr) ? -1 : 1]

/*******************************************************************************
 * Unused variable
 ******************************************************************************/

#define C_UNUSED(v)                     (void)(0 ? (v) = (v), 1 : 0)

/*******************************************************************************
 * Configuration options
 ******************************************************************************/

/* ...tracing facility is on */
#define INTERN_TRACE                    1

/* ...debugging facility is on */
#define INTERN_DEBUG                    1

/*******************************************************************************
 * Auxiliary macros
 ******************************************************************************/

/* ...define a stub for unused declarator */
#define __intern_stub(tag, line)        __intern_stub2(tag, line)
#define __intern_stub2(tag, line)       typedef int __intern_##tag##_##line

/* ...convert anything into string */
#define __intern_string(x)              __intern_string2(x)
#define __intern_string2(x)             #x

/*******************************************************************************
 * Tracing facility
 ******************************************************************************/

extern int LOG_LEVEL;

/* ...variable definition specifier */
#define __trace__(var)                  __attribute__ ((unused)) var

#if INTERN_TRACE

/* ...tracing to communication processor */
//extern int  intern_trace(const char *format, ...) __attribute__((format (printf, 1, 2)));
extern void ME_Debugger_F_Printf_v(const char* i_Format_pc, ...) __attribute__((format (printf, 1, 2)));
#define intern_trace(a,...)             ME_Debugger_F_Printf_v(a, ## __VA_ARGS__)
#define intern_trace_init(...)          intern_trace(__VA_ARGS__)

/* ...tracing facility initialization */
//extern void intern_trace_init(const char *banner);

/* ...initialize tracing facility */
#define TRACE_INIT(banner)              (intern_trace_init(banner))

/* ...trace tag definition */
#define TRACE_TAG(tag, on)              enum { __intern_trace_##tag = on }

/* ...check if the trace tag is enabled */
#define TRACE_CFG(tag)                  ((__intern_trace_##tag != 0)&& (__intern_trace_##tag <= LOG_LEVEL))

/* ...tagged tracing primitive */
#define TRACE(tag, fmt, ...)            (void)(TRACE_CFG(tag)  ? __intern_trace2(tag, __intern_format##fmt, ## __VA_ARGS__) : 0)

/* ...thread-safe tracing */
#define __intern_trace2(fmt, ...)                                   \
({                                                                  \
    int  __oldstate;                                                \
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &__oldstate);    \
    __intern_trace(fmt, ##__VA_ARGS__);                             \
    pthread_setcancelstate(__oldstate, NULL);                       \
})

/*******************************************************************************
 * Tagged tracing formats
 ******************************************************************************/

/* ...tracing primitive */
#define __intern_trace(tag, fmt, ...)   \
    ({ __attribute__((unused)) const char *__intern_tag = #tag; intern_trace(fmt, ## __VA_ARGS__); })

/* ...just a format string */
#define __intern_format_n(fmt)          fmt "\n"

/* ...module tag and trace tag shown */
#define __intern_format_b(fmt)          "[%s.%s] " fmt "\n", __intern_string(MODULE_TAG), __intern_tag

/* ...module tag, trace tag, file name and line shown */
#define __intern_format_x(fmt)          "[%s.%s] - %s@%d - " fmt "\n", __intern_string(MODULE_TAG), __intern_tag, __FILE__, __LINE__

/*******************************************************************************
 * Globally defined tags
 ******************************************************************************/

/* ...unconditionally OFF */
TRACE_TAG(0, 0);

/* ...unconditionally ON */
TRACE_TAG(1, 1);

/* ...error output - on by default */
TRACE_TAG(ERROR, 1);

/* ...warning output - on by default */
TRACE_TAG(WARNING, 1);

#else

#define TRACE_INIT(banner)              (void)0
#define TRACE_TAG(tag, on)              __intern_stub(trace_##tag, __LINE__)
#define TRACE(tag, fmt, ...)            (void)0
#define __intern_trace(tag, fmt, ...)   (void)0

#endif  /* INTERN_TRACE */

/*******************************************************************************
 * Bugchecks
 ******************************************************************************/

#if INTERN_DEBUG

/* ...run-time bugcheck */
#define BUG(cond, fmt, ...)                                         \
do                                                                  \
{                                                                   \
    if (cond)                                                       \
    {                                                               \
        /* ...output message */                                     \
        __intern_trace(BUG, __intern_format##fmt, ## __VA_ARGS__);  \
                                                                    \
        /* ...and die (tbd) */                                      \
        *(u32*)0 = 0;abort();/*exit(0);*/                           \
    }                                                               \
}                                                                   \
while (0)

#else
#define BUG(cond, fmt, ...)             (void)0
#endif  /* INTERN_DEBUG */

/*******************************************************************************
 * Performance counters
 ******************************************************************************/

#if defined(__ARM_ARCH_7A__)
/* ...retrieve CPU cycles count */
static inline u32 __get_cpu_cycles(void)
{
    u32     cycles = 0;

    asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (cycles));

    return cycles;
}
#elif defined(__aarch64__)
/* ...enable performance counter */
static inline void __pm_init(void)
{
    if (1)  return;

    u32     v = 0x1;
    asm volatile("msr pmcr_el0, %0" :: "r" (v));

    v = ~0U;
    asm volatile("msr pmcntenset_el0, %0" :: "r" (v));
}

static inline u32 __get_cpu_cycles(void)
{
    u64     cycles = 0;

    asm volatile("mrs %0, pmccntr_el0" : "=r" (cycles));

    return (u32)cycles;
}

#elif defined(__x86_64__)
static inline void __pm_init(void)
{
}

/* ...Intel architecture */
static inline u32 __get_cpu_cycles(void)
{
    u32     cycles_lo, cycles_hi;

	asm volatile("rdtsc" : "=a" (cycles_lo), "=d" (cycles_hi));

	return cycles_lo;
}
#else
#error "Unrecognized target architecture"
#endif

static inline u32 __get_time_usec(void)
{
#if 0
    struct timespec     ts;

    /* ...retrieve value of monotonic clock */
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* ...translate value into microseconds (ignore wrap-around) */
    return (u32)((u64)ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000);
#else
    return (uint32_t)((ClockCycles() * 1000000ULL) / SYSPAGE_ENTRY(qtime)->cycles_per_sec);
#endif
}

static inline u64 __get_time_ns(void)
{
#if 0
    struct timespec     ts;

    /* ...retrieve value of monotonic clock */
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* ...translate value into nanoseconds */
    return (u64)((u64)ts.tv_sec * 1000000000ULL + ts.tv_nsec);
#else
    return (uint32_t)((ClockCycles() * 1000000000ULL) / SYSPAGE_ENTRY(qtime)->cycles_per_sec);
#endif
}

/*******************************************************************************
 * Performance monitoring
 ******************************************************************************/

/* ...performance counter accumulator */
typedef struct pm_ctr
{
    /* ...duration accumulator */
    u32                 acc;

    /* ...last timestamp value */
    u32                 ts;

}   pm_ctr_t;

/* ...reset performance counter */
static inline void __pm_reset(pm_ctr_t *p, u32 ts)
{
    /* ...reset processing time accumulator */
    p->acc = 0, p->ts = ts;
}

/* ...update FPS calculator */
static inline u32 __pm_update(pm_ctr_t *p, u32 ts, const int e)
{
    u32     acc = p->acc;
    u32     t0 = p->ts;
    u32     delta = (u32)(ts - t0);

    /* ...check if accumulator is initialized */
    if (acc == 0)
    {
        /* ...initialize accumulator on first invocation */
        acc = (t0 ? delta << e : 0);
    }
    else
    {
        /* ...accumulator is setup already; do exponential averaging */
        acc += delta - ((acc + (1 << (e - 1))) >> e);
    }

    /* ...update timestamp and accumulator values */
    p->acc = acc;
    p->ts = ts;

    return (acc + (1 << (e - 1))) >> e;
}

/* ...get current average processing time */
static inline u32 __pm_get_avg(pm_ctr_t *p, const int e)
{
    return (p->acc + (1 << (e - 1))) >> e;
}

/*******************************************************************************
 * Miscellaneous utility functions
 ******************************************************************************/

/* ...pseudo-random number generation - xorshift algorithm */
extern u32 _xrandom(void);

/* ...pseudo-random number between 0..n-1 */
extern u32 _xrandom_n(u32 n);

/*******************************************************************************
 * Auxiliary helpers
 ******************************************************************************/

#define CHK_API(cond)                           \
({                                              \
    int  __r = (cond);                          \
    if (__r < 0)                                \
        return TRACE(ERROR, _x("%m")), __r;     \
    __r;                                        \
})

#define CHK_ERR(cond, err)                                          \
({                                                                  \
    if (!(cond))                                                    \
        return ({TRACE(ERROR, _x("condition failed")); (err);});    \
    1;                                                              \
})

#define CHK_GL(expr)                                                        \
({                                                                          \
    GLuint  _err;                                                           \
    (expr);                                                                 \
    _err = glGetError();                                                    \
    (_err != GL_NO_ERROR ? TRACE(ERROR, _x("GL error: %X"), _err), 0 : 1);  \
})

#define xmalloc(size)                                           \
({                                                              \
    size_t  __size = (size);                                    \
    void *__p = malloc(__size);                                 \
    if (!__p)                                                   \
        TRACE(ERROR, _x("alloc failed (%zu bytes)"), __size);   \
    __p;                                                        \
})

#define xcalloc(n, size)                                                \
({                                                                      \
    int     __n = (n);                                                  \
    size_t  __size = (size);                                            \
    void   *__p = calloc(__n, __size);                                  \
    if (!__p)                                                           \
        TRACE(ERROR, _x("calloc failed (%zu bytes)"), __n * __size);    \
    __p;                                                                \
})

#define xrealloc(p, size)                                       \
({                                                              \
    size_t  __size = (size);                                    \
    void   *__p = realloc((p), __size);                         \
    if (!__p)                                                   \
        TRACE(ERROR, _x("realloc failed (%zu bytes)"), __size); \
    __p;                                                        \
})

/*******************************************************************************
 * Formats processing helpers - think about this...
 ******************************************************************************/

#define __v4l2_fmt(f)     \
    ((f) >> 24) & 0xFF, ((f) >> 16) & 0xFF, ((f) >> 8) & 0xFF, ((f) >> 0) & 0xFF


/*******************************************************************************
 * Auxiliary debug stuff
 ******************************************************************************/

extern ssize_t getline(char **lineptr, size_t *n, FILE *stream);


static inline int store_uyvy(const char *fname, int width, int height, int format, void *data)
{
    FILE   *f;

    CHK_ERR(f = fopen(fname, "wb"), -errno);

    if (fwrite(data, width * height * 2, 1, f) != 1)
    {
        TRACE(ERROR, _x("failed to write image: %m"));
    }

    fclose(f);

    return 0;
}

static inline int store_argb(const char *name, int width, int height, int format, void *data)
{
    FILE   *f;
    char    fname[256];

    snprintf(fname, sizeof(fname), "%s.%u.%u.rgba", name, width, height);

    CHK_ERR(f = fopen(fname, "wb"), -errno);

    if (fwrite(data, width * height * 4, 1, f) != 1)
    {
        TRACE(ERROR, _x("failed to write image: %m"));
    }

    fclose(f);

    return 0;
}

static inline int store_gray(const char *fname, int width, int height, int format, void *data)
{
    FILE   *f;

    CHK_ERR(f = fopen(fname, "wb"), -errno);

    if (fwrite(data, width * height, 1, f) != 1)
    {
        TRACE(ERROR, _x("failed to write image: %m"));
    }

    fclose(f);

    return 0;
}

#endif  /* __SV_COMMON_H */
