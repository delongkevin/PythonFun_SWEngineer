#ifndef ProxiParameters_H_INCGUARD
#define ProxiParameters_H_INCGUARD

#include "PlatformDataTypes.h"

typedef enum  {
    QNX_IDLE_STATE,
    QNX_BOOTUP_STATE,
    QNX_RUNNING_STATE,
    QNX_RUNNING_PROXI_WRITTEN_PASS_STATE,
    QNX_RUNNING_PROXI_WRITTEN_FAILED_STATE,
    QNX_RUNNING_PROXI_WRITTEN_SKIPPED_STATE,
    QNX_RUNNING_PROXI_WAITING_TO_WRITE_STATE,
    QNX_RESTART_REQ_STATE,
    QNX_ETFS_NOT_READY_STATE,
    QNX_SHUTING_DOWN,
    QNX_current_status_MAX_Enforcer = 0xFFFFFFFF
} ME_QNX_current_status_t;

typedef struct ME_Proxi_MPU1_0_to_MCU1_0_s
{
    float32_t a72_cpu_load;
    ME_QNX_current_status_t state;
    uint8 PRX_RadioDispTyp_u8;
    uint8 PRX_variantID_u8;
} ME_Proxi_MPU1_0_to_MCU1_0_t;

typedef struct KeepAliveResponse_s
{
    uint32 FrameID_u32;
    uint8 ResponseCode_u8;
} KeepAliveResponse_t;

/* MPU1_0 to MCU1_0  */
typedef struct Error_Fault_MPU1_0
{
uint16 Err_FaultInfo_MPU1_0;
uint8 Err_FaultNum_MPU1_0;
uint8 Reserved;
}Error_Fault_MPU1_0_t;
#endif
