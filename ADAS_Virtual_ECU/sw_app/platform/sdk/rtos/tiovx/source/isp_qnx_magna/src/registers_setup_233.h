/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           algo_defaults.h
 *  @brief
 *
 *  @version        3.31
 *  @author         Mikhail Vakhrushev
 *  @date           10.04.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* PRQA S 1055 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0842 ++ */
/* PRQA S 0342 ++ */

#ifndef REGISERS_SETUP_233_H
#define REGISERS_SETUP_233_H

#define EMB_DATA_REGISTER_LIST(IMPL)\
IMPL(0x2000,EMB_LINE_FRAME_COUNTER)\
IMPL(0x3012,EMB_LINE_EXPOSURE)\
IMPL(0x3308,EMB_LINE_DLO_GAIN)\
IMPL(0x3362,EMB_LINE_DC_GAIN)\
IMPL(0x336A,EMB_LINE_ANALOG_GAIN)\
IMPL(0x3366,EMB_LINE_ANALOG_GAIN_COARSE)\
IMPL(0x3056,EMB_LINE_GREEN_GAIN)\
IMPL(0x305A,EMB_LINE_RED_GAIN)\
IMPL(0x3058,EMB_LINE_BLUE_GAIN)\
IMPL(0x20B0,EMB_LINE_CURRENT_TEMPERATERE)\
IMPL(0x30C6,EMB_LINE_TEMPSENS0_CALIB1)\
IMPL(0x30C8,EMB_LINE_TEMPSENS0_CALIB2)\
IMPL(0x2040,EMB_LINE_RT1T2)\
IMPL(0x2042,EMB_LINE_RT2T3)\
IMPL(0x204E,EMB_LINE_RT1T4)\
IMPL(0x31D2,EMB_LINE_ISP_VERSION)\
IMPL(0x300E,EMB_LINE_SENSOR_VERSION)\
IMPL(0x3212,EMB_LINE_AE_EXPOSURE)\
IMPL(0x3F76,EMB_LINE_DCG_TRIM)\
IMPL(0x3216,EMB_LINE_SENSOR_VIRTUAL_GAIN_T0)\
IMPL(0x321A,EMB_LINE_SENSOR_VIRTUAL_GAIN_T1)\
IMPL(0x3370,EMB_LINE_DBLC_CONFIG)\
IMPL(0x3070,EMB_LINE_TPG_PART1)\
IMPL(0x3388,EMB_LINE_TPG_PART2) \
IMPL(0x3072,EMB_LINE_TEST_DATA_R) \
IMPL(0x3074,EMB_LINE_TEST_DATA_GR) \
IMPL(0x3076,EMB_LINE_TEST_DATA_B) \
IMPL(0x3078,EMB_LINE_TEST_DATA_GB) \
IMPL(0x302A, EMB_LINE_VT_PIX_CLK_DIV) \
IMPL(0x302E, EMB_LINE_PRE_PLL_CLK_DIV) \
IMPL(0x3030, EMB_LINE_PLL_MULTIPLIER) \
IMPL(0x300A, EMB_LINE_FLL) \
IMPL(0x300C, EMB_LINE_LLPCK) \
IMPL(0x33E4, EMB_LINE_DBLC_BTM_ROW) \
IMPL(0x3002, EMB_LINE_Y_ADDR_START) \
IMPL(0x3006, EMB_LINE_Y_ADDR_END) \
IMPL(0x3040, EMB_LINE_VERTICAL_FLIP) \
IMPL(0x33E2, EMB_LINE_SE_MODE) \
IMPL(0x3252, EMB_LINE_AB_PERIOD) \
IMPL(0x32EC, EMB_LINE_T3T4_SH_ADV) \
IMPL(0x3014, EMB_LINE_FIT) \
IMPL(0x3226, EMB_LINE_FIT4)

#define default_analog_gain 0xc0

#define AR233_DEFAULTS \
    {0x3012, 424}, /* T1 exposure  */  \
    {0x3212, 5},   /* T2 exposure  */  \
    {0x3056, 128},    \
    {0x3058, 288},    \
    {0x305a, 181},    \
    {0x305c, 128},    \
    {0x3308, 0x200},    \
    {0x3366, 0x31},    \
    {0x336a, default_analog_gain}, /* ANALOG GAIN  */  \
    {0x3370, 0x111},    \
    {0x3308, 512}, /* DLO  */  \
    {0x3140, 0},    \
    {0x3142, 0},    \
    {0x3144, 1920},    \
    {0x3146, 1080},    \
    {0x327C, 0x7070},    \
    {0x306e, 0x90d2},    \
    {0x3238, 0x8666},    \
    {0x33DA, 0},    \
    {0x33C0, 8192},    \
    {0x33C2, 16384},    \
    {0x33C4, 32768},    \
    {0x33C6, 33280},    \
    {0x33C8, 34304},    \
    {0x33CA, 36352},    \
    {0x33CC, 40448},    \
    {0x33CE, 48640},    \
    {0x33D0, 49664},    \
    {0x33D2, 51712},    \
    {0x33D4, 55808},    \
    {0x33D6, 64000},    \
    {0x33f4, 4087*16},    \
    {0x33f6, 4087*16},    \
    {0x33f8, 4087*16},    \
    {0x33fa, 4087*16},    \

#endif //REGISERS_SETUP_233_H
