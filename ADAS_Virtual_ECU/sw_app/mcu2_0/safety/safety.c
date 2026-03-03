/** @file  safety.c
 *  @brief safety data
 *
 *  safety data
 *
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */
/*==================[inclusions]============================================*/


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "safety.h"
#include "cam_tools.h"
#include <utils/console_io/include/app_log.h>
#include <ti/csl/csl_gpio.h>

#include "cogent_api.h"
#include "cam_testpattern.h"
#include "app_iss.h"

#include "ProxiMgrIpcDataTypes.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define CSIRX_PREAMBULE "CSIrx Safety event: "
#define Csirx_Safety_log(...)  { appLogPrintf(CSIRX_PREAMBULE __VA_ARGS__); }

#define SAFETY_CAM_NUM_MAX  (5)
#define SAFETY_CAM_NUM      (4)

#define SAFETY_DESER_NUM_MAX (2)

#define CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW (CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW_FRONT | \
                                            CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW_STRM0 | \
                                            CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW_STRM1 | \
                                            CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW_STRM2 | \
                                            CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW_STRM3)

#define CSIRX_EVENT_TYPE_ERR_PROTOCOL (CSIRX_EVENT_TYPE_ERR_HEADER_ECC | \
                                       CSIRX_EVENT_TYPE_ERR_PAYLOAD_CRC)

#define EXPECTED_FRAME_NUM 6 // 200ms, 30fps 30fps * 200ms / 1000ms = 6

#define CAM_SHUTDOWN_NOT_SCHEDULED (0)
#define CAM_SHUTDOWN_SCHEDULED     (1)
#define CAM_SHUTDOWN_DONE          (2)

/*
 * Shutdown camera if CAM_RESET_MAX_NUM resets occurred
 * in last CAM_RESET_MAX_TIME_SEC seconds
 */
#define CAM_RESET_MAX_NUM      (10)
#define CAM_RESET_MAX_TIME_SEC (10*60)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */



/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
extern void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data);



/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static uint8_t CamResetSchedule[SAFETY_CAM_NUM_MAX] = {CAM_RESET_NOT_SCHEDULED};
static uint8_t CamShutdownSchedule[SAFETY_CAM_NUM_MAX] = {CAM_SHUTDOWN_NOT_SCHEDULED};

static uint32_t CamStreamStatus[SAFETY_CAM_NUM_MAX] = {0};
static uint32_t ErrorStatusCSIrx = 0;
static uint32_t ErrorStatusCam[SAFETY_CAM_NUM_MAX] = {0};
static uint32_t ErrorStatusDeser[SAFETY_DESER_NUM_MAX] = {0};

static uint64_t CamResetEvents[SAFETY_CAM_NUM_MAX][CAM_RESET_MAX_NUM] = {0};
static uint8_t  CamResetEventsIdx[SAFETY_CAM_NUM_MAX] = {0};

static uint32_t CSIrx_failure = 0;

//commented this faults ad it removed from degradation mgr
/* static ErrorMgr_enErrorNo_B ErrorMapCSIrx[ERRMGR_CSIRX_MAX] =  
{
    ldef_B_ErrorMgr_Error_SysIntFlt_Main_CSI_RX_IF_Protocol_Error,
    ldef_B_ErrorMgr_Error_SysIntFlt_Main_CSI_RX_IF_Data_overflow_errors,
    ldef_B_ErrorMgr_Error_SysIntFlt_Main_CSI_RX_IF_Frame_Expected_and_Received_mismatch,
}; 
*/

static ldef_ErrorMgr_enErrorNo ErrorMapCam[SAFETY_CAM_NUM_MAX][ERRMGR_CAM_MAX] =
{
    {
        /* Left */
        ldef_ErrorMgr_Error_SVC_Left_self_test_fail_SCCB_Register_error,
        ldef_ErrorMgr_Error_SVC_Left_online_pixel_test_error,
        ldef_ErrorMgr_Error_SVC_Left_VoltageMonitor_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Left_Cam_Pwr_Supply_OOR,
        ldef_ErrorMgr_Error_SVC_Left_ROM_CRC_Check_Fail,                    // ROM Loader includes ROM CRC
        ldef_ErrorMgr_Error_SVC_Left_PLL_Clock_Monitor_error,
        ldef_ErrorMgr_Error_SVC_Left_PLL_Lock_State_Monitoring_error,
        ldef_ErrorMgr_Error_SVC_Left_Temp_OOR,
        ldef_ErrorMgr_Error_SVC_Left_Temp_Snsr_Integrity_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Left_Temp_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Left_SI_Default_Register_Check_error,       // I2C readback is part of SI Default Register check
        ldef_ErrorMgr_Error_SVC_Left_row_column_id_checker_error,
        ldef_ErrorMgr_Error_SVC_Left_analog_test_pattern_error,
        ldef_ErrorMgr_Error_SVC_Left_digital_test_pattern_row_error,
        ldef_ErrorMgr_Error_SVC_Left_blc_check_error,
        ldef_ErrorMgr_Error_SVC_Left_FIFO_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Left_analog_digital_sync_error,
        ldef_ErrorMgr_Error_SVC_Left_SRAM_CRC_MISMATCH,
        ldef_ErrorMgr_Error_SVC_Left_SCCB_embedded_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Left_Frame_Cntr_Fault,
        ldef_ErrorMgr_Error_SVC_Left_MIPI_ECC_2_bit_mismatch,
        ldef_ErrorMgr_Error_SVC_Left_MIPI_CRC_mismatch,
        ldef_ErrorMgr_Error_Left_Cam_LOC_Incorrect_PMIC_DeviceID,
        ldef_ErrorMgr_Error_LOC_SVC_Left_Fault,
        ldef_ErrorMgr_Error_SVC_Left_SCCB_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Left_OTP_CRC_MISMATCH,
        ldef_ErrorMgr_Error_DS90UB962_RX1_LOCK_STS,
        ldef_ErrorMgr_Error_Left_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_SVC_Left_Cam_I2C_NACK_error,
        ldef_ErrorMgr_Error_Left_Cam_Intrinsic_Zero,
        ldef_ErrorMgr_Error_SVC_Left_Cam_EEPROM_CRCMismatch_Fault,
    },
    {
        /* Right */
        ldef_ErrorMgr_Error_SVC_Right_self_test_fail_SCCB_Register_error,
        ldef_ErrorMgr_Error_SVC_Right_online_pixel_test_error,
        ldef_ErrorMgr_Error_SVC_Right_VoltageMonitor_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Right_Cam_Pwr_Supply_OOR,
        ldef_ErrorMgr_Error_SVC_Right_ROM_CRC_Check_Fail,                    // ROM Loader includes ROM CRC
        ldef_ErrorMgr_Error_SVC_Right_PLL_Clock_Monitor_error,
        ldef_ErrorMgr_Error_SVC_Right_PLL_Lock_State_Monitoring_error,
        ldef_ErrorMgr_Error_SVC_Right_Temp_OOR,
        ldef_ErrorMgr_Error_SVC_Right_Temp_Snsr_Integrity_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Right_Temp_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Right_SI_Default_Register_Check_error,       // I2C readback is part of SI Default Register check
        ldef_ErrorMgr_Error_SVC_Right_row_column_id_checker_error,
        ldef_ErrorMgr_Error_SVC_Right_analog_test_pattern_error,
        ldef_ErrorMgr_Error_SVC_Right_digital_test_pattern_row_error,
        ldef_ErrorMgr_Error_SVC_Right_blc_check_error,
        ldef_ErrorMgr_Error_SVC_Right_FIFO_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Right_analog_digital_sync_error,
        ldef_ErrorMgr_Error_SVC_Right_SRAM_CRC_MISMATCH,
        ldef_ErrorMgr_Error_SVC_Right_SCCB_embedded_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Right_Frame_Cntr_Fault,
        ldef_ErrorMgr_Error_SVC_Right_MIPI_ECC_2_bit_mismatch,
        ldef_ErrorMgr_Error_SVC_Right_MIPI_CRC_mismatch,
        ldef_ErrorMgr_Error_Right_Cam_LOC_Incorrect_PMIC_DeviceID,
        ldef_ErrorMgr_Error_LOC_SVC_Right_Fault,
        ldef_ErrorMgr_Error_SVC_Right_SCCB_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Right_OTP_CRC_MISMATCH,
        ldef_ErrorMgr_Error_DS90UB962_RX0_LOCK_STS,
        ldef_ErrorMgr_Error_Right_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_SVC_Right_Cam_I2C_NACK_error,
        ldef_ErrorMgr_Error_Right_Cam_Intrinsic_Zero,
        ldef_ErrorMgr_Error_SVC_Right_Cam_EEPROM_CRCMismatch_Fault,
    },
    {
        /* Front */
        ldef_ErrorMgr_Error_SVC_Front_self_test_fail_SCCB_Register_error,
        ldef_ErrorMgr_Error_SVC_Front_online_pixel_test_error,
        ldef_ErrorMgr_Error_SVC_Front_VoltageMonitor_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Front_Cam_Pwr_Supply_OOR,
        ldef_ErrorMgr_Error_SVC_Front_ROM_CRC_Check_Fail,                    // ROM Loader includes ROM CRC
        ldef_ErrorMgr_Error_SVC_Front_PLL_Clock_Monitor_error,
        ldef_ErrorMgr_Error_SVC_Front_PLL_Lock_State_Monitoring_error,
        ldef_ErrorMgr_Error_SVC_Front_Temp_OOR,
        ldef_ErrorMgr_Error_SVC_Front_Temp_Snsr_Integrity_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Front_Temp_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Front_SI_Default_Register_Check_error,       // I2C readback is part of SI Default Register check
        ldef_ErrorMgr_Error_SVC_Front_row_column_id_checker_error,
        ldef_ErrorMgr_Error_SVC_Front_analog_test_pattern_error,
        ldef_ErrorMgr_Error_SVC_Front_digital_test_pattern_row_error,
        ldef_ErrorMgr_Error_SVC_Front_blc_check_error,
        ldef_ErrorMgr_Error_SVC_Front_FIFO_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Front_analog_digital_sync_error,
        ldef_ErrorMgr_Error_SVC_Front_SRAM_CRC_MISMATCH,
        ldef_ErrorMgr_Error_SVC_Front_SCCB_embedded_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Front_Frame_Cntr_Fault,
        ldef_ErrorMgr_Error_SVC_Front_MIPI_ECC_2_bit_mismatch,
        ldef_ErrorMgr_Error_SVC_Front_MIPI_CRC_mismatch,
        ldef_ErrorMgr_Error_Front_Cam_LOC_Incorrect_PMIC_DeviceID,
        ldef_ErrorMgr_Error_LOC_SVC_Front_Fault,
        ldef_ErrorMgr_Error_SVC_Front_SCCB_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Front_OTP_CRC_MISMATCH,
        ldef_ErrorMgr_Error_DS90UB962_RX3_LOCK_STS,
        ldef_ErrorMgr_Error_Front_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_SVC_Front_Cam_I2C_NACK_error,
        ldef_ErrorMgr_Error_Front_Cam_Intrinsic_Zero,
        ldef_ErrorMgr_Error_SVC_Front_Cam_EEPROM_CRCMismatch_Fault,
    },
    {
        /* Rear */
        ldef_ErrorMgr_Error_SVC_Rear_self_test_fail_SCCB_Register_error,
        ldef_ErrorMgr_Error_SVC_Rear_online_pixel_test_error,
        ldef_ErrorMgr_Error_SVC_Rear_VoltageMonitor_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Rear_Cam_Pwr_Supply_OOR,
        ldef_ErrorMgr_Error_SVC_Rear_ROM_CRC_Check_Fail,                    // ROM Loader includes ROM CRC
        ldef_ErrorMgr_Error_SVC_Rear_PLL_Clock_Monitor_error,
        ldef_ErrorMgr_Error_SVC_Rear_PLL_Lock_State_Monitoring_error,
        ldef_ErrorMgr_Error_SVC_Rear_Temp_OOR,
        ldef_ErrorMgr_Error_SVC_Rear_Temp_Snsr_Integrity_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Rear_Temp_Self_Test_Fault,
        ldef_ErrorMgr_Error_SVC_Rear_SI_Default_Register_Check_error,       // I2C readback is part of SI Default Register check
        ldef_ErrorMgr_Error_SVC_Rear_row_column_id_checker_error,
        ldef_ErrorMgr_Error_SVC_Rear_analog_test_pattern_error,
        ldef_ErrorMgr_Error_SVC_Rear_digital_test_pattern_row_error,
        ldef_ErrorMgr_Error_SVC_Rear_blc_check_error,
        ldef_ErrorMgr_Error_SVC_Rear_FIFO_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Rear_analog_digital_sync_error,
        ldef_ErrorMgr_Error_SVC_Rear_SRAM_CRC_MISMATCH,
        ldef_ErrorMgr_Error_SVC_Rear_SCCB_embedded_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Rear_Frame_Cntr_Fault,
        ldef_ErrorMgr_Error_SVC_Rear_MIPI_ECC_2_bit_mismatch,
        ldef_ErrorMgr_Error_SVC_Rear_MIPI_CRC_mismatch,
        ldef_ErrorMgr_Error_Rear_Cam_LOC_Incorrect_PMIC_DeviceID,
        ldef_ErrorMgr_Error_LOC_SVC_Rear_Fault,
        ldef_ErrorMgr_Error_SVC_Rear_SCCB_CRC_mismatch,
        ldef_ErrorMgr_Error_SVC_Rear_OTP_CRC_MISMATCH,
        ldef_ErrorMgr_Error_DS90UB962_RX2_LOCK_STS,
        ldef_ErrorMgr_Error_Rear_Cam_I2C_back_channel_error,
        ldef_ErrorMgr_Error_SVC_Rear_Cam_I2C_NACK_error,
        ldef_ErrorMgr_Error_Rear_Cam_Intrinsic_Zero,
        ldef_ErrorMgr_Error_SVC_Rear_Cam_EEPROM_CRCMismatch_Fault,
    }
};

static ldef_ErrorMgr_enErrorNo ErrorMapDeser[SAFETY_DESER_NUM_MAX][ERRMGR_DESER_MAX] =
{
    {
        ldef_ErrorMgr_Error_SysIntFlt_Main_Deserializer_NACK_Error,
    },
    {
        0,
    },
};

static uint8_t udmaIrqNum[SAFETY_CAM_NUM_MAX] = {0};

/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint64_t get_time_ucs(void)
{

	/* DD-ID: {61A1BD3D-97E3-4951-8D16-4543CF99465F}*/
	static int gtc_init = 0;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */

    if (gtc_init == 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        gtc_init = 1U;
        appLogGlobalTimeInit();
    }

    return appLogGetGlobalTimeInUsec();
}

static void camera_reset_max_helper(uint32_t cam_num)
{
  /* DD-ID: {D4E201C6-05BD-4f09-9F93-56B6FDCCA9CC}*/
    int cur_idx, last_idx;

    /* Do actual reset */
    camera_reset(cam_num);

    /* Check if we are not reseting too much */
    cur_idx = CamResetEventsIdx[cam_num];
    CamResetEvents[cam_num][cur_idx] = get_time_ucs();

    if (++CamResetEventsIdx[cam_num] == CAM_RESET_MAX_NUM)
    {
        CamResetEventsIdx[cam_num] = 0;
    }
    last_idx = CamResetEventsIdx[cam_num];
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (CamResetEvents[cam_num][last_idx] != 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        /* total CAM_RESET_MAX_NUM already occurred */
        uint64_t time_diff = CamResetEvents[cam_num][cur_idx] - CamResetEvents[cam_num][last_idx];
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (time_diff / 1000000 < CAM_RESET_MAX_TIME_SEC)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            Csirx_Safety_log("CAMERA[%d]: %d resets in %lld seconds. Shutdown.\n", cam_num, CAM_RESET_MAX_NUM, time_diff/1000000);
            camera_set_for_shutdown(cam_num);
        }
    }
    

}

static void Safety_CSIrx_reset(void)
{
  /* DD-ID: {93959322-7485-4359-9134-74697B04E714}*/
    // Only reset cameras at the moment
    // tbd: deser and CSIrx reset (appInitImageSensor?)
    Csirx_Safety_log("CSIrx reset (now just cameras reset)\n");
    for (int i = 0; i < SAFETY_CAM_NUM; i++) {
        camera_reset(i);
    }

#if 0 // Placeholder
    appLogWaitMsecs(150);
    //appInitImageSensor_early("ox03c10", 0, 0xf);
    appInitImageSensor("ox03c10", 0, 0xf);
#endif
}

static void report_error_status(uint32_t err_num, int err_status)
{
      /* DD-ID: {A37B9E58-97DF-4155-8D92-3050DA62C373}*/
    /* error reported first time */
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (err_status && !(ErrorStatusCSIrx & (1 << err_num)))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        ErrorStatusCSIrx |= 1 << err_num;
    }

    /* error deactivated and it used to be set before */
    if (!err_status && (ErrorStatusCSIrx & (1 << err_num)))
    {
        ErrorStatusCSIrx &= ~(1 << err_num);
        //ErrorMgrSatellite_ReportErrorStatus(ErrorMapCSIrx[err_num], ldef_ErrorMgr_ErrorInactive, NULL); //commented this faults ad it removed from degradation mgr
    }
}

void deser_report_error_status(uint32_t deser, uint32_t err_num, int err_status)

{
  /* DD-ID: {D38D323E-4C28-425f-8EC5-77310D40E48D}*/    
	/* error reported first time */
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */

    if (err_status && !(ErrorStatusDeser[deser] & (1 << err_num)))
	/* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        ErrorStatusDeser[deser] |= 1 << err_num;
        ErrorMgrSatellite_ReportErrorStatus(ErrorMapDeser[deser][err_num], ldef_ErrorMgr_ErrorActive, NULL);
    }

    /* error deactivated and it used to be set before */
    if (!err_status && (ErrorStatusDeser[deser] & (1 << err_num)))
    {
        ErrorStatusDeser[deser] &= ~(1 << err_num);
        ErrorMgrSatellite_ReportErrorStatus(ErrorMapDeser[deser][err_num], ldef_ErrorMgr_ErrorInactive, NULL);
    }
}

void camera_report_error_status(uint32_t cam, uint32_t err_num, int err_status)
{
  /* DD-ID: {EDF9C322-36D6-4bd4-8479-043C4A19FF8D}*/
    /* error reported first time */
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (err_status && !(ErrorStatusCam[cam] & (1 << err_num)))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        ErrorStatusCam[cam] |= 1 << err_num;
        ErrorMgrSatellite_ReportErrorStatus(ErrorMapCam[cam][err_num], ldef_ErrorMgr_ErrorActive, NULL);
    }

    /* error deactivated and it used to be set before */
    if (!err_status && (ErrorStatusCam[cam] & (1 << err_num)))
    {
        ErrorStatusCam[cam] &= ~(1 << err_num);
        ErrorMgrSatellite_ReportErrorStatus(ErrorMapCam[cam][err_num], ldef_ErrorMgr_ErrorInactive, NULL);
    }
}

void camera_report_sccb_fault(int cam_num, int err_status)
{
  /* DD-ID: {FCFBD3D4-5008-4937-8DFA-BC9BC277221F}*/
    camera_report_error_status(cam_num, ERRMGR_CAM_SCCB_CRC, err_status);
}

void camera_report_otp_fault(int cam_num, int err_status)
{
  /* DD-ID: {95D99E9D-8903-453e-88AA-32974091699C}*/
    camera_report_error_status(cam_num, ERRMGR_CAM_OTP_CRC, err_status);
}

/* Supports only 1 deser/4 channels - should be extended to 5 channels? */
void camera_report_lock_fault(uint32_t lock_status)
{
	/* DD-ID: {194B2B89-F9EF-4278-8E47-71B8C001769D}*/
    ME_ProxiToMCU2_0_Def_t CameraConfig = {0};
    uint32_t chId;
    int lock_sts;

    SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(&CameraConfig);
    if(TRUE == CameraConfig.PRX_SurroundViewCamera_b) /* Requirement ID:18768256 Four camera configuration */
    {
        chId = 0;
    }
    else /* Requirement ID:18642819 Single Camera configuration*/
    {
        chId = 3; /* Rear Camera*/
    }

    for (; chId < 4; chId++)
    {
        lock_sts = lock_status & (1 << chId);
        /* s_Fault_Rear_Camera_RX<chId>_LOCK_STS */
        if ((0 == lock_sts))
        {
            camera_report_error_status(chId, ERRMGR_CAM_LOCK_LOSS, 1);
        }
        else
        {
            camera_report_error_status(chId, ERRMGR_CAM_LOCK_LOSS, 0);
        }
    }
}

/* Supports only 1 deser/4 channels - should be extended to 5 channels? */
void camera_report_bcc_fault(uint32_t bcc_err_status)
{
  /* DD-ID: {76ACE9BA-6B19-40ce-8FE5-C384CFD17EDB}*/
    ME_ProxiToMCU2_0_Def_t CameraConfig = {0};
    uint32_t chId;
    int bcc_err_sts;

    SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(&CameraConfig);
    if(TRUE == CameraConfig.PRX_SurroundViewCamera_b) /* Requirement ID:18768256 Four camera configuration */
    {
        chId = 0;
    }
    else /* Requirement ID:18642819 Single Camera configuration*/
    {
        chId = 3; /* Rear Camera*/
    }

    for (; chId < 4; chId++)
    {
        bcc_err_sts = bcc_err_status & (1 << chId);
        /* s_Fault_Rear_Camera_RX<chId>_LOCK_STS */
        if (bcc_err_sts)
        {
            camera_report_error_status(chId, ERRMGR_CAM_I2C_BCC_ERR, 1);
        }
        else
        {
            camera_report_error_status(chId, ERRMGR_CAM_I2C_BCC_ERR, 0);
        }
    }
}

void camera_set_for_reset(uint32_t cam_num)
{
  /* DD-ID: {EC07A947-CC87-4753-A387-B116F3BF4447}*/
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ((cam_num < SAFETY_CAM_NUM_MAX) && (CamResetSchedule[cam_num] == CAM_RESET_NOT_SCHEDULED))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        CamResetSchedule[cam_num] = CAM_RESET_SCHEDULED;
    }
}

void camera_set_for_shutdown(uint32_t cam_num)
{
  /* DD-ID: {1AF8868D-07AD-4053-A6E1-1F0C15A732A8}*/
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ((cam_num < SAFETY_CAM_NUM_MAX) && (CamShutdownSchedule[cam_num] == CAM_SHUTDOWN_NOT_SCHEDULED))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        CamShutdownSchedule[cam_num] = CAM_SHUTDOWN_SCHEDULED;
    }
}
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
bool camera_is_set_for_action(uint32_t cam_num)
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
{
  /* DD-ID: {3BB5A288-5C8B-481e-A955-0BEE3FDC0DEA}*/
    return CamResetSchedule[cam_num] || CamShutdownSchedule[cam_num];
}

void Safety_CSIrx_error(Csirx_EventStatus err_status)
{
  /* DD-ID: {9DCD3AF8-DD21-4b6c-9F51-738FA1E64F66}*/
    /* FIXME: Disable CSIrx ECC and FIFO errors */
    //return;

    if (err_status.eventMasks & CSIRX_EVENT_TYPE_ERR_HEADER_CORRECTED_ECC)
    {
        Csirx_Safety_log("Corrected header ECC!\n");
        /* Nothing to do */
    }

    if (err_status.eventMasks & CSIRX_EVENT_TYPE_ERR_PROTOCOL)
    {
        Csirx_Safety_log("Header ECC or Payload CRC!\n");
        //report_error_status(ERRMGR_CSIRX_PROTOCOL, 1);
        //CSIrx_failure = true;
    }

    if (err_status.eventMasks & CSIRX_EVENT_TYPE_ERR_FIFO_OVERFLOW)
    {
        Csirx_Safety_log("Data overflow!\n");
        //report_error_status(ERRMGR_CSIRX_DATA_OVERFLOW, 1);
        //CSIrx_failure = true;
    }

    return;
}

void Safety_CSIrx_udma(uint32_t chId)
{
  /* DD-ID: {A03A0A27-5886-40c4-862A-0D2A90244196}*/
    /* FIXME: Disable CSIrx UDMA errors */
    return;

    //Csirx_Safety_log("UDMA channel %d event\n", chId);
    if (chId < SAFETY_CAM_NUM) {
        udmaIrqNum[chId]++;
    }
}

void Safety_Cam_stream_on(uint32_t cam_num)
{
  /* DD-ID: {71FB992E-4901-441e-9D73-BA4B67E95E6F}*/
    CamStreamStatus[cam_num] = 1;
    CamResetSchedule[cam_num] = CAM_RESET_NOT_SCHEDULED;
}

static bool Safety_CSIrx_timeout_test()
{
  /* DD-ID: {78A1BC34-C161-4f95-915E-2BB060EAF39B}*/
    static int udma_err_count = 0;
    bool       udma_fault = false;
    bool       ret = false;

    // If any camera frame counter is not valid report CSIrx udma fail
    // We do not care about individual cameras here
    for (int i = 0; i < SAFETY_CAM_NUM; i++) {
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (CamStreamStatus[i] && (udmaIrqNum[i] < (EXPECTED_FRAME_NUM - 1) || udmaIrqNum[i] > (EXPECTED_FRAME_NUM + 1))) {
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
            //Csirx_Safety_log("ch[%d]: fr num %d\n", i, udmaIrqNum[i]);
            udma_fault = true;
        }
        udmaIrqNum[i] = 0;
    }
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (udma_fault && (++udma_err_count == 10)) {
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
        // Recovery, message to MCU1_0 and reset counter
        report_error_status(ERRMGR_CSIRX_UDMA_COUNT, 1);
        //Csirx_Safety_log("CSIrx timeout: 3 errors in a row!\n");
        udma_err_count = 0;
        ret = true;
    } else if (!udma_fault) {
        // Report error cleared, Reset continuous error counter if there were no errors on all channels
        report_error_status(ERRMGR_CSIRX_UDMA_COUNT, 0);
        udma_err_count = 0;
    }

    return ret;
}

void Safety_CSIrx_Run_200ms()
{
  /* DD-ID: {5E087798-E571-4644-AFEA-36D4F990DA32}*/
/* FIXME: Disable CSIrx safety */
#if 0
    bool fail = false;
    //Csirx_Safety_log("Safety thread start\n");

    fail = CSIrx_failure;
    CSIrx_failure = false;

    if (fail) Csirx_Safety_log("CSI RX failure!!!\n");

    fail |= Safety_CSIrx_timeout_test();

    if (fail) Csirx_Safety_log("CSI RX UDMA failure!!!\n");

    if (fail) {
        Safety_CSIrx_reset();
    }
#endif
    return;
}

void Safety_Recovery_Run_100ms()
{
  /* DD-ID: {813471C5-D196-4cd2-BD46-4D4C281B75DD}*/
    for (int i = 0; i < SAFETY_CAM_NUM_MAX; i++)
    {
        if (CamShutdownSchedule[i] == CAM_SHUTDOWN_SCHEDULED)
        {
            camera_shutdown(i);
            CamShutdownSchedule[i] = CAM_SHUTDOWN_DONE;
            CamResetSchedule[i] = CAM_RESET_NOT_SCHEDULED;
        }
        else if (CamShutdownSchedule[i] == CAM_SHUTDOWN_DONE)
        {
            CamResetSchedule[i] = CAM_RESET_NOT_SCHEDULED;
        }
        else if (CamResetSchedule[i] == CAM_RESET_SCHEDULED)
        {
            camera_reset_max_helper(i);
            CamResetSchedule[i] = CAM_RESET_IN_PROGRESS;
        }
    }

    return;
}

void image_buffer_mark_err_report(bool error_status)
{
    /* DD-ID:{A867F395-5744-42d7-80B5-01FED8321548}*/
    if(true == error_status)
    {
        ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_BufferMarks_Comparison_Error, ldef_ErrorMgr_ErrorActive, NULL);
    }
    else
    {
        ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_BufferMarks_Comparison_Error, ldef_ErrorMgr_ErrorInactive, NULL);        
    }

}
