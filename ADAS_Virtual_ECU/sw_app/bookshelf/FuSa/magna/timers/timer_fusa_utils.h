#ifndef MAIN_DOMAIN_SAFETY_UTILS_H_
#define MAIN_DOMAIN_SAFETY_UTILS_H_
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


#define UPPER_THRESHOLD_TASK_5MSEC  5250U //5msec task periodicity.
#define LOWER_THRESHOLD_TASK_5MSEC  4750U


#define UPPER_THRESHOLD_TASK_1MSEC  1250U//1msec task periodicity.
#define LOWER_THRESHOLD_TASK_1MSEC  750U

#define MAX_COUNTER_LIMIT 5U
#define MIN_COUNTER_LIMIT 5U
typedef struct _thresholdCounter
{
uint64_t max_thresholdCounter;
uint64_t min_thresholdCounter;
}thresholdCounterVal;

thresholdCounterVal getCurrentTaskThresholdVal_5msec(void);
void resetTaskThresholdCounterVal_5msec(void);
void updateTaskThresholdCounterVal_5msec(uint64_t val,uint64_t maxLimit,uint64_t minLimit);


thresholdCounterVal getCurrentTaskThresholdVal_1msec(void);
void resetTaskThresholdCounterVal_1msec(void);
void updateTaskThresholdCounterVal_1msec(uint64_t val,uint64_t maxLimit,uint64_t minLimit);

#ifdef __cplusplus
}
#endif

#endif