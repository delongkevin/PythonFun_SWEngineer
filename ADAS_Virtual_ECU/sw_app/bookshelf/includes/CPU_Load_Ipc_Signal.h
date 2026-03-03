#ifndef CPU_LOAD_IPC_SIGNAL_H_INCGUARD
#define CPU_LOAD_IPC_SIGNAL_H_INCGUARD

#include "PlatformDataTypes.h" 

/* MCU2_0 to MCU1_0*/
typedef struct CpuLoadMcu2_0_s
{
 uint32_t CpluLoad_MCU2_0_f32;
}CpuLoadMcu2_0_t;


/* MCU2_1 to MCU1_0*/
typedef struct CpuLoadMCU2_1_s
{
 uint32_t CpluLoad_MCU2_1_f32;
}CpuLoadMcu2_1_t;

/* MCU2_0 to MCU1_0 */
typedef struct Error_Fault_MCU2_0
{
uint16 Err_FaultInfo_MCU2_0;
uint8 Err_FaultNum_MCU2_0;
uint8 Reserved;
}Error_Fault_MCU2_0_t;

/* MCU2_1 to MCU1_0 */
typedef struct Error_Fault_MCU2_1
{
uint16 Err_FaultInfo_MCU2_1;
uint8 Err_FaultNum_MCU2_1;
uint8 Reserved;
}Error_Fault_MCU2_1_t;

#endif
