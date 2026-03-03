/*!
 *  @file       isp_cfg.h
 *  @brief      ISP configuration file for the user
 *  @date       2018/Oct/01 latest update
 *  @author     A. Lanari
 *  @version    2.0.0
 *  @par        history
 *  @note
 */
 
#ifndef ISP_CFG_H
#define ISP_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
* Includes <System Includes>, Project Includes             *
***********************************************************/
#include "drv.h"

/***********************************************************
* Macro definitions                                        *
***********************************************************/
#define ISP_CFG_DEVICE_RCAR_V3M                     0x01u
#define ISP_CFG_DEVICE_RCAR_V3H                     0x02u

/***********************************************************
* Configuration definitions                                *
***********************************************************/
#ifdef DRV_ARCH_RCAR_V3M
/* Target device configuration */
/* Possible values are listed ISP_CFG_DEVICE_RCAR_V3M, ISP_CFG_DEVICE_RCAR_V3H  */
#define ISP_CFG_TARGET_DEVICE           ISP_CFG_DEVICE_RCAR_V3M
#endif

#ifdef DRV_ARCH_RCAR_V3H
/* Target device configuration */
/* Possible values are listed ISP_CFG_DEVICE_RCAR_V3M, ISP_CFG_DEVICE_RCAR_V3H  */
#define ISP_CFG_TARGET_DEVICE           ISP_CFG_DEVICE_RCAR_V3H
#endif

#if !(defined(DRV_ARCH_RCAR_V3H) || defined(DRV_ARCH_RCAR_V3M))
#error " ISP: Unknown target device configuration!!!"
#endif

#ifdef __cplusplus
}
#endif

#endif      /* ISP_CFG_H */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/3rdparty/renesas/isp/public/renesas/isp_cfg.h $ $Rev: 873044 $")
#endif
