/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           common_sensor_api.h
 *  @brief          sensor API declaration
 *
 *
 *  @version        3.31
 *  @author         Ronzhin Alexander
 *  @date           01.10.2021
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifndef TIVX_HWA_VPAC_CUC_COMMON_SENSOR_API_H_
#define TIVX_HWA_VPAC_CUC_COMMON_SENSOR_API_H_

#include <app_ipc.h>
#include <app_remote_service.h>
#include <iss_sensors.h>
#include <vx_vpac_cuc_common.h>

int32_t set_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t value);
int32_t get_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t *value);
int32_t cuc_set_fps_via_iss(uint32_t channel_id, camera_frame_rate_denominator_t fps);
int32_t set_register_byte_array_via_iss(uint32_t channel_id, uint32_t reg_address, const uint8_t* data, uint32_t sz_in_bytes);
int32_t get_ser_mipi_status_via_iss(uint32_t channel_id, IssSensor_MipiStatus *mipi_sts);
int32_t get_cam_pmic_status_via_iss(uint32_t channel_id, IssSensor_CameraPmicStatus *pmic_sts);

#endif /* TIVX_HWA_VPAC_CUC_COMMON_SENSOR_API_H_ */
