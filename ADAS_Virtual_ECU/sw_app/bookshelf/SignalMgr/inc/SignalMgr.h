#ifndef SIGNALMGR_H_INCGUARD
#define SIGNALMGR_H_INCGUARD

#include "SignalMgrTypes.h"


#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_WINDOWS
	#include  <stdio.h>
	#define SignalMgr_Printf   printf

#elif SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
	#include <ti/drv/uart/UART.h>
	#include <ti/drv/uart/UART_stdio.h>
	#define SignalMgr_Printf   UART_printf

#endif

#ifdef __cplusplus
extern "C" {
#endif
	bool_t SignalMgr_Init(void);

#ifdef __cplusplus
}
#endif

#endif
