/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Register definitions for TI Jacinto7
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.23.00   2020-08-14  visjdn  FBL-1947         Added Jacinto7 support
 *  01.23.01   2020-09-01  visjdn  ESCAN00107257    No changes
 *  01.24.00   2020-10-02  visrcn  FBL-2511         No changes
 *  01.25.00   2020-11-05  vistmo  FBL-2336         No changes
 *  01.26.00   2020-11-10  visjdn  FBL-2311         No changes
 *                                 FBL-2665         No changes
 *  01.26.01   2021-03-22  visjdn  ESCAN00108454    No changes
 *  01.27.00   2021-07-22  visrie  FBL-3688         No changes
 *  01.28.00   2021-09-21  visjdn  FBL-3844         No changes
 *  01.29.00   2022-03-04  vishor  FBL-4692         No changes
 *                                 ESCAN00110852    No changes
 *                                 ESCAN00111409    No changes
 *  01.30.00   2022-05-10  vishor  FBL-4246         No changes
 *  01.31.00   2022-05-17  visjdn  FBL-5159         No changes
 *  01.32.00   2022-05-31  visjdn  FBL-4938         No changes
 *  01.32.01   2022-08-04  visrie  ESCAN00112517    No changes
 *  01.32.02   2022-08-05  visjdn  ESCAN00112523    No changes
 *  01.33.00   2022-08-09  visjdn  FBL-4709         No changes
 **********************************************************************************************************************/

#ifndef FBL_SFR_H
#define FBL_SFR_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if defined( FBL_SFR_BASE_ADRESSES_PRECONFIGURED )
#else
# error "Error in fbl_sfr.h: Please add base addresses for your derivative to the .pcu file."
#endif /* FBL_SFR_BASE_ADRESSES_PRECONFIGURED */


/***********************************************************************************************************************
 *  ACCESS MACROS
 **********************************************************************************************************************/

/* PRQA S 3453 TAG_SfrDefinitionMacros */ /* MD_MSR_FctLikeMacro */

#ifndef FBL_IOS
# define FBL_IOS(type, base, offset) (*((volatile type *)((base) + (offset))))
#endif

#ifndef FBL_TIMER_BASE
# define FBL_TIMER_BASE   FBL_TIMER_MAIN_BASE
#endif

/*******************************************************************************************************************
 *  32-bit  TIMER
 *******************************************************************************************************************/
/* Timer counter registers */
#define FBL_TIMER_TIOCP_CFG(gr)              FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x10uL)   /* CBASS0 Configuration register */
#define FBL_TIMER_IRQSTATUS(gr)              FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x28uL)   /* Timer status register */
#define FBL_TIMER_IRQSTATUS_SET(gr)          FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x2CuL)   /* Interrupt enable register */
#define FBL_TIMER_TCLR(gr)                   FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x38uL)   /* Timer control register */
#define FBL_TIMER_TCRR(gr)                   FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x3CuL)   /* Timer counter register  */
#define FBL_TIMER_TLDR(gr)                   FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x40uL)   /* Timer load register */
#define FBL_TIMER_TOCR(gr)                   FBL_IOS(vuint32, FBL_TIMER_BASE, ((gr)*0x10000uL) + 0x68uL)   /* Timer overflow counter register */

/* Bit definitions */

/* TIMER_TCLR field offset */
#define FBL_TIMER_TCLR_AUTORELOAD        1uL

/* TIMER_IRQSTATUS_SET field offset */
#define FBL_TIMER_IRQSTATUS_OVERFLOW     1uL

/* Register macros */

/* TIMER_TCLR start macro */
#define FBL_TIMER_TCLR_START          0x01uL

/***********************************************************************************************************************
 * GPIO, Port configuration
 **********************************************************************************************************************/

/* GPIO port registers - valid only for GPIO pair 0 and 1 */
#define FBL_GPIO_PID(gr)                    FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x00uL)   /* GPIO Periperal ID Register */
#define FBL_GPIO_PCR(gr)                    FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x04uL)   /* Peripheral Control Register */
#define FBL_GPIO_BINTEN(gr)                 FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x08uL)   /* Bit Interrupt Enable Register */
#define FBL_GPIO_DIR01(gr)                  FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x10uL)   /* Direction Register */
#define FBL_GPIO_OUT_DATA01(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x14uL)   /* Output Drive State Register */
#define FBL_GPIO_SET_DATA01(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x18uL)   /* Set Output Drive State Register */
#define FBL_GPIO_CLR_DATA01(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x1CuL)   /* Clear Output Drive State Register */
#define FBL_GPIO_IN_DATA01(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x20uL)   /* Bank Status Register */
#define FBL_GPIO_SET_RIS_TRIG01(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x24uL)   /* Set Rising Edge Detection Register */
#define FBL_GPIO_CLR_RIS_TRIG01(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x28uL)   /* Clear Rising Edge Detection Register */
#define FBL_GPIO_SET_FAL_TRIG01(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x2CuL)   /* Set Falling Edge Detection Register */
#define FBL_GPIO_CLR_FAL_TRIG01(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x30uL)   /* Clear Falling Edge Detection Register */
#define FBL_GPIO_INTSTAT01(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x34uL)   /* Bank Interrupt Status Register */
#define FBL_GPIO_DIR23(gr)                  FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x38uL)   /* Direction Register */
#define FBL_GPIO_OUT_DATA23(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x3CuL)   /* Output Drive State Register */
#define FBL_GPIO_SET_DATA23(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x40uL)   /* Set Output Drive State Register */
#define FBL_GPIO_CLR_DATA23(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x44uL)   /* Clear Output Drive State Register */
#define FBL_GPIO_IN_DATA23(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x48uL)   /* Bank Status Register */
#define FBL_GPIO_SET_RIS_TRIG23(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x4CuL)   /* Set Rising Edge Detection Register */
#define FBL_GPIO_CLR_RIS_TRIG23(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x50uL)   /* Clear Rising Edge Detection Register */
#define FBL_GPIO_SET_FAL_TRIG23(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x54uL)   /* Set Falling Edge Detection Register */
#define FBL_GPIO_CLR_FAL_TRIG23(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x58uL)   /* Clear Falling Edge Detection Register */
#define FBL_GPIO_INTSTAT23(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x5CuL)   /* Bank Interrupt Status Register */
#define FBL_GPIO_DIR45(gr)                  FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x60uL)   /* Direction Register */
#define FBL_GPIO_OUT_DATA45(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x64uL)   /* Output Drive State Register */
#define FBL_GPIO_SET_DATA45(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x68uL)   /* Set Output Drive State Register */
#define FBL_GPIO_CLR_DATA45(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x6CuL)   /* Clear Output Drive State Register */
#define FBL_GPIO_IN_DATA45(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x70uL)   /* Bank Status Register */
#define FBL_GPIO_SET_RIS_TRIG45(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x74uL)   /* Set Rising Edge Detection Register */
#define FBL_GPIO_CLR_RIS_TRIG45(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x78uL)   /* Clear Rising Edge Detection Register */
#define FBL_GPIO_SET_FAL_TRIG45(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x7CuL)   /* Set Falling Edge Detection Register */
#define FBL_GPIO_CLR_FAL_TRIG45(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x80uL)   /* Clear Falling Edge Detection Register */
#define FBL_GPIO_INTSTAT45(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x84uL)   /* Bank Interrupt Status Register */
#define FBL_GPIO_DIR67(gr)                  FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x88uL)   /* Direction Register */
#define FBL_GPIO_OUT_DATA67(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x8CuL)   /* Output Drive State Register */
#define FBL_GPIO_SET_DATA67(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x90uL)   /* Set Output Drive State Register */
#define FBL_GPIO_CLR_DATA67(gr)             FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x94uL)   /* Clear Output Drive State Register */
#define FBL_GPIO_IN_DATA67(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x98uL)   /* Bank Status Register */
#define FBL_GPIO_SET_RIS_TRIG67(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0x9CuL)   /* Set Rising Edge Detection Register */
#define FBL_GPIO_CLR_RIS_TRIG67(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xA0uL)   /* Clear Rising Edge Detection Register */
#define FBL_GPIO_SET_FAL_TRIG67(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xA4uL)   /* Set Falling Edge Detection Register */
#define FBL_GPIO_CLR_FAL_TRIG67(gr)         FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xA8uL)   /* Clear Falling Edge Detection Register */
#define FBL_GPIO_INTSTAT67(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xACuL)   /* Bank Interrupt Status Register */
#define FBL_GPIO_DIR8(gr)                   FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xB0uL)   /* Direction Register */
#define FBL_GPIO_OUT_DATA8(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xB4uL)   /* Output Drive State Register */
#define FBL_GPIO_SET_DATA8(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xB8uL)   /* Set Output Drive State Register */
#define FBL_GPIO_CLR_DATA8(gr)              FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xBCuL)   /* Clear Output Drive State Register */
#define FBL_GPIO_IN_DATA8(gr)               FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xC0uL)   /* Bank Status Register */
#define FBL_GPIO_SET_RIS_TRIG8(gr)          FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xC4uL)   /* Set Rising Edge Detection Register */
#define FBL_GPIO_CLR_RIS_TRIG8(gr)          FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xC8uL)   /* Clear Rising Edge Detection Register */
#define FBL_GPIO_SET_FAL_TRIG8(gr)          FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xCCuL)   /* Set Falling Edge Detection Register */
#define FBL_GPIO_CLR_FAL_TRIG8(gr)          FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xD0uL)   /* Clear Falling Edge Detection Register */
#define FBL_GPIO_INTSTAT8(gr)               FBL_IOS(vuint32, FBL_GPIO_BASE, ((gr)*0x1000uL) + 0xD4uL)   /* Bank Interrupt Status Register */

/* PRQA L:TAG_SfrDefinitionMacros */

#endif /* FBL_SFR_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_SFR.H
 **********************************************************************************************************************/
