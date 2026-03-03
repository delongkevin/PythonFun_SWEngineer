/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           def_cfg.c
 *  @brief          default ISP configuration API declaration
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
#ifndef TIVX_HWA_VPAC_CUC_VISS_DEFAULT_CONFIG_H_
#define TIVX_HWA_VPAC_CUC_VISS_DEFAULT_CONFIG_H_
#include <vx_vpac_cuc_common.h>

void set_default_isp_config_ox3c(tivxVpacCucIspObj *t, uint32_t width, uint32_t height);
void set_default_isp_config_233(tivxVpacCucIspObj *t, uint32_t width, uint32_t height);
magna_camera_sensor_type_t get_sensor_type(void);

static inline void set_default_isp_config(tivxVpacCucIspObj *t, uint32_t width, uint32_t height)
{
    magna_camera_sensor_type_t type = get_sensor_type();

    switch (type)
    {
#ifdef ISP_SENSOR_AR233
    case MAGNA_CAMERA_SENSOR_AR0233:
        set_default_isp_config_233(t, width, height);
        break;
#endif
#ifdef ISP_SENSOR_OX3C
    case MAGNA_CAMERA_SENSOR_OX3C:
        set_default_isp_config_ox3c(t, width, height);
        break;
#endif
    default:
        VX_PRINT(VX_ZONE_ERROR, "ISP initialization error, unknown sensor type");
        break;
    }
}

#endif /* TIVX_HWA_VPAC_CUC_VISS_DEFAULT_CONFIG_H_ */
