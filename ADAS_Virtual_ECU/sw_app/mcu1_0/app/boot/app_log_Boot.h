#ifndef APP_LOG_H
#define APP_LOG_H

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

#define APP_LOG_NONE    (0U)
#define APP_LOG_ERR     (1U)
#define APP_LOG_MIN     (2U)
#define APP_LOG_MAX     (3U)

/*extern uint8_t gbPMICMonEnable;*/

#define APP_log(dbg_level, ...)  if ((int32_t)(dbg_level) <= APP_LOG_LEVEL) { UART_printf(__VA_ARGS__); }
/*#define appLogPrintf(...)   if(gbPMICMonEnable == TRUE){ UART_printf(__VA_ARGS__); }*/
/*#define Enable_Printf*/

#endif
