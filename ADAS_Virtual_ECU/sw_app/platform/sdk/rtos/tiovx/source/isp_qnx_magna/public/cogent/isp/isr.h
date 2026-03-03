#ifndef ISR_H
#define ISR_H

/*
This file is not a part of new ISP driver since Renesas removed from new ISP driver any dependency from other drivers.
QNX added this file since QNX v3x library requires below definitions.
*/

#include <sys/neutrino.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <atomic.h>
#include <pthread.h>
#include <unistd.h>
#include "drv.h"

/* SPI number */
#define drvISR_SPI025   (25U)   /* SPI 25  */
#define drvISR_SPI026   (26U)   /* SPI 26  */


/* CPU Target */
#define drvISR_CPU_0    (0U)    /* CPU 0 */

/* Priority */
#define drvISR_PRIORITY_10  (10U)   /* 10 */

#define RCAR_ISP_PULSE 		60
#define RCAR_TISP_PULSE 	61
#define RCAR_TRIGGER_PULSE 	62
#define RCAR_ISP_END   		63

#endif  /* ISR_H */


#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/3rdparty/renesas/isp/public/renesas/isr.h $ $Rev: 873044 $")
#endif
