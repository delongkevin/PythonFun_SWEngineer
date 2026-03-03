#ifndef RTE_OS_APP_H
#define RTE_OS_APP_H

#ifdef __cplusplus
extern "C" {
#endif

#define T10MS_TIMER_PERIOD_MS   ( 10 )
#define T13MS_TIMER_PERIOD_MS   ( 13 )
#define T20MS_TIMER_PERIOD_MS   ( 20 )
#define T40MS_TIMER_PERIOD_MS   ( 40 )
#define T60MS_TIMER_PERIOD_MS   ( 60 )
#define T80MS_TIMER_PERIOD_MS   ( 80 )

extern void ME_CommTask( void *pvParameters );


#ifdef __cplusplus
}
#endif

#endif                                 /* RTE_OS_APP_H */
