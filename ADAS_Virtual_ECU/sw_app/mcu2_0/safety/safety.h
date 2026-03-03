/** @file  safety.h
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
#ifndef SAFETY_MCU2_0_H
#define SAFETY_MCU2_0_H

#ifdef BUILD_MCU2_0
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
#endif

#include <ti/drv/csirx/csirx.h>

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
enum ErrorMapDictCSIrx
{
    ERRMGR_CSIRX_PROTOCOL,
    ERRMGR_CSIRX_DATA_OVERFLOW,
    ERRMGR_CSIRX_UDMA_COUNT,
    ERRMGR_CSIRX_MAX,
};

enum ErrorMapDictCamera
{
    ERRMGR_CAM_BIST,
    ERRMGR_CAM_PIXEL,
    ERRMGR_CAM_VOLTAGE_SELFTEST,
    ERRMGR_CAM_VOLTAGE_OOR,
    ERRMGR_CAM_ROM_LOADER,
    ERRMGR_CAM_PLL_CLOCK,
    ERRMGR_CAM_PLL_LOCK,
    ERRMGR_CAM_TEMP_OOR,
    ERRMGR_CAM_TEMP_INTEGRITY,
    ERRMGR_CAM_TEMP_SELFTEST,
    ERRMGR_CAM_I2C_READBACK,
    ERRMGR_CAM_UID,
    ERRMGR_CAM_ATPR,
    ERRMGR_CAM_DTPR,
    ERRMGR_CAM_BLC,
    ERRMGR_CAM_FIFO_CRC,
    ERRMGR_CAM_A2DSYNC,
    ERRMGR_CAM_SRAM_CRC,
    ERRMGR_CAM_EMB_CRC,
    ERRMGR_CAM_FRAME_COUNTER,
    ERRMGR_CAM_MIPI_2ECC,
    ERRMGR_CAM_MIPI_CRC,
    ERRMGR_CAM_PMIC_ID,
    ERRMGR_CAM_PMIC,
    ERRMGR_CAM_SCCB_CRC,
    ERRMGR_CAM_OTP_CRC,
    ERRMGR_CAM_LOCK_LOSS,
    ERRMGR_CAM_I2C_BCC_ERR,
    ERRMGR_CAM_I2C_NACK,
    ERRMGR_CAM_INTRINSIC_ZERO,
    ERRMGR_CAM_EEPROM_CRC_FAIL,
    ERRMGR_CAM_MAX,
};

enum ErrorMapDictDeser
{
    ERRMGR_DESER_I2C_NAK,
    ERRMGR_DESER_MAX,
};

#define CAM_RESET_NOT_SCHEDULED (0U)
#define CAM_RESET_SCHEDULED     (1U)
#define CAM_RESET_IN_PROGRESS   (2U)
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


	
	
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
extern void camera_report_sccb_fault(int cam_num, int err_status);
extern void camera_report_otp_fault(int cam_num, int err_status);
extern void camera_report_error_status(uint32_t cam, uint32_t err_num, int err_status);
extern void camera_report_lock_fault(uint32_t lock_status);
extern void camera_report_bcc_fault(uint32_t bcc_err_status);

extern void camera_set_for_reset(uint32_t cam_num);
extern void camera_set_for_shutdown(uint32_t cam_num);
extern bool camera_is_set_for_action(uint32_t cam_num);

extern void deser_report_error_status(uint32_t deser, uint32_t err_num, int err_status);

extern void Safety_Cam_stream_on(uint32_t cam_num);

extern void Safety_CSIrx_error(Csirx_EventStatus err_status);
extern void Safety_CSIrx_udma(uint32_t chId);

extern void Safety_CSIrx_Run_200ms();
extern void Safety_Recovery_Run_100ms();

extern void image_buffer_mark_err_report(bool error_status);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */



/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */


#endif
