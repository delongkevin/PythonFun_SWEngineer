/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           processing.c
 *  @brief          API declaration for communication with ISP framework
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

#ifndef PROCESSING_H_
#define PROCESSING_H_

vx_status rc_init(tivxVpacCucIspObj* ispObj, uint32_t width, uint32_t height);
vx_status rc_process(tivxVpacCucIspObj* ispObj);

void rc_sensor_write(tivxVpacCucIspObj* ispObj);

#endif
