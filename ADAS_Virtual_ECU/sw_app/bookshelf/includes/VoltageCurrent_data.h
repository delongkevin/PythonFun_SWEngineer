#ifndef VOLTAGECURRENT_DATA_H_
#define VOLTAGECURRENT_DATA_H_


#include "PlatformDataTypes.h"


#define USS_PWR_ENABLED 0xAAu
#define USS_PWR_DISABLED 0x55u

/* mcu1_0 to mcu2_1 */
typedef struct USS_Curr_Volt_Monitor_s
{
 uint16 Volt_A;
 uint16 Volt_B;
 uint16 Curr_A;
 uint16 Curr_B;
}USS_Curr_Volt_Monitor_t;

/* mcu1_0 to mcu2_0 */
typedef struct CAM_Curr_Volt_Monitor_s
{
 uint8  s_Cam_ChId;
 uint16 CAM_CS_A;
 uint16 CAM_PS_MON;
 uint16 FreshnessCounter;
}CAM_Curr_Volt_Monitor_t;

#if !defined(BUILD_MCU1_0)
/* mcu2_0 to mcu1_0 */
typedef struct CAM_CS_Curr_Monitor_s
{
 uint8 s_Front_CAM_CS_A;
 uint8 s_Right_CAM_CS_A;
 uint8 s_Left_CAM_CS_A;
 uint8 s_Rear_CAM_CS_A;
 uint8 s_FreshnessCounter;
}CAM_CS_Curr_Monitor_t;

#endif

/* mcu2_1 to mcu2_0 */
typedef struct USS_PowerSelect_s
{
    boolean USS_PWR_EN_A; /* Enable/Disable power-out for USS-A */
    boolean USS_PWR_EN_B; /* Enable/Disable power-out for USS-B */
    uint8 status_A;
    uint8 status_B;
}USS_PowerSelect_t;

#if defined(BUILD_MCU2_0)
/* MCU2_0 to MCU1_0 */
typedef struct Cam_and_Ser_EN_Status_s
{
    uint8_t Cam1_en_stat;
    uint8_t Cam2_en_stat;
    uint8_t Cam3_en_stat;
    uint8_t Cam4_en_stat;
    uint8_t SER_en_stat;
}Cam_and_Ser_EN_Status_t;

/* MCU2_0 to MCU1_0 */
typedef struct CAM_select_info_s
{
    uint8 s_Cam_ChId;
    uint8 s_Cam_PwrEn_Sts;
    uint8 rsvd1;
    uint8 rsvd2;   
}CAM_select_info_t;
#endif

#endif /* VOLTAGECURRENT_DATA_H_ */
