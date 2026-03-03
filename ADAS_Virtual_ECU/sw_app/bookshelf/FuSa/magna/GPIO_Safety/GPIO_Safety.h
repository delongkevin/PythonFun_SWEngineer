/**
 * @file GPIO_Safety.h
 * @brief Header file for GPIO safety module
 *
 * @details This file contains GPIO safety module interface
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2023.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Fengyi Chen (fengyi.chen@magna.com)
 */
 
#ifndef __GPIO_SAFETY_H
#define __GPIO_SAFETY_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/arch/csl_arch.h>

#include <ti/board/board.h>
#include <ti/board/src/j721s2_hyd/include/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_control.h>
#include <ti/board/src/j721s2_hyd/include/board_pinmux.h>
#include <ti/board/src/j721s2_hyd/include/board_utils.h>

/* CSL Header files */
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/csl_gpio.h>

/* OSAL Header files */
#include <ti/osal/osal.h>

/* Board Header files */
#include <ti/board/board.h>
#include <ti/board/board_cfg.h>
#include <ti/board/src/devices/common/common.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define GPIO_SAFETY_PASS ((uint8_t)0)
#define GPIO_SAFETY_FAIL ((uint8_t)1)

typedef uint8_t GPIO_safetyConfig;

typedef enum {
    WKUP_GPIO0,
    WKUP_GPIO1,
    GPIO0,
    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4,
    GPIO5,
    GPIO6,
    GPIO7,
} GPIO_modules;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
extern void	TASK_gpio_safety_init(void);
extern void TASK_gpio_safety_MainFunction(void);

/* === End Of Header File ================================================= */
#endif  /* __GPIO_SAFETY_H*/
