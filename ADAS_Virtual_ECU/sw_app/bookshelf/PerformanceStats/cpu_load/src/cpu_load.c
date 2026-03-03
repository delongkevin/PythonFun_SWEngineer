
// CPU utilization for Free-rtos
/*  CPU Load Headers    */
#include <ti/osal/LoadP.h>
#include "cpu_load.h"

#ifdef BUILD_MCU2_0
#include "CPU_Load_Ipc_Signal.h"
#include <utils/console_io/include/app_log.h>
extern bool_t SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(CpuLoadMcu2_0_t *data);
CpuLoadMcu2_0_t cpu_load_mcu2_0_s;
#endif

#ifdef BUILD_MCU2_1
#include <UART_stdio.h>
#include "SignalDef.h"
CpuLoadMcu2_1_t cpu_load_mcu2_1_s;
#endif


/*
cpu_load_MCU2_0 prints Percentage CPU load for MCU2_0
It Use TI's API "LoadP_getCPULoad" from SDK to get percentage CPU load
TI's API Used Idle and Non-Idle ticks to calculate CPU load for RTOS
*/
#ifdef BUILD_MCU2_0
void cpu_load_MCU2_0(void)
{    
    cpu_load_mcu2_0_s.CpluLoad_MCU2_0_f32 = LoadP_getCPULoad();
    LoadP_reset();
    (void)SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put(&cpu_load_mcu2_0_s);
    #ifdef LOG_CPU_LOAD_MCU2_0
    appLogPrintf("CPU_Load : %d \n", cpu_load_mcu2_0_s.CpluLoad_MCU2_0_f32);
    #endif
}
#endif
/*
cpu_load_MCU2_1 prints Percentage CPU load for MCU2_1
It Use TI's API "LoadP_getCPULoad" from SDK to get percentage CPU load
TI's API Used Idle and Non-Idle ticks to calculate CPU load for RTOS
*/
#ifdef BUILD_MCU2_1
void cpu_load_MCU2_1(void)
{               
    cpu_load_mcu2_1_s.CpluLoad_MCU2_1_f32 = LoadP_getCPULoad();
    SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put(&cpu_load_mcu2_1_s); 
    LoadP_reset();
    #ifdef LOG_CPU_LOAD_MCU2_1          // CPU utilization for Free-rtos  
    UART_printf("CPU_Load : %d \n", cpu_load_mcu2_1_s.CpluLoad_MCU2_1_f32);
    #endif
}
#endif
