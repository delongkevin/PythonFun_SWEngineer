/**
 * @file ipc_lookup_table.c
 * @brief Maintains look up table
 *
 * @details This file maintains look up table using which Destination Core or
 *          Destination software module can be identified in association with
 *          Message ID
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2021. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
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
 * @author ---- (---- @magna.com)
 */

/* ===========================================================================
 *
 *   Fisker_L2H5010_IPC_SignalDef.xlsm Version
 *
 * ======================================================================== */
/*
 * Excel file Version:  11.0
 * Excel file Mod Date: 2022-05-06 00:00:00
 * Generated on:        2025-09-23 16:58:37
 */

/* ===========================================================================
 *
 *   Include Files
 *
 * ======================================================================== */
#include "ipc_lookup_table_include.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#if defined(BUILD_MCU2_0)
#define  TRUE   1
#define  FALSE  0
#endif

/* ===========================================================================
 *
 *   Function Prototypes
 *
 * ========================================================================= */
/* Callback functions prototype for signal handler */
#if defined(BUILD_MPU1_0)
static void callback_MsgId_0001(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0001   (&callback_MsgId_0001)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0002(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0002   (&callback_MsgId_0002)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0003(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0003   (&callback_MsgId_0003)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0004(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0004   (&callback_MsgId_0004)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0005(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0005   (&callback_MsgId_0005)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0006(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0006   (&callback_MsgId_0006)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0007(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0007   (&callback_MsgId_0007)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0008(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0008   (&callback_MsgId_0008)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0009(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0009   (&callback_MsgId_0009)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_000A   (&callback_MsgId_000A)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_000B   (&callback_MsgId_000B)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_000C   (&callback_MsgId_000C)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_000D   (&callback_MsgId_000D)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_000E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_000E   (&callback_MsgId_000E)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_000F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_000F   (&callback_MsgId_000F)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0010(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0010   (&callback_MsgId_0010)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0011(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0011   (&callback_MsgId_0011)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0012(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0012   (&callback_MsgId_0012)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0013(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0013   (&callback_MsgId_0013)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0014(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0014   (&callback_MsgId_0014)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0015(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0015   (&callback_MsgId_0015)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0016(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0016   (&callback_MsgId_0016)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0017(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0017   (&callback_MsgId_0017)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0018(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0018   (&callback_MsgId_0018)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0019(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0019   (&callback_MsgId_0019)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_001A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_001A   (&callback_MsgId_001A)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_001D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_001D   (&callback_MsgId_001D)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_001E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_001E   (&callback_MsgId_001E)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_001F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_001F   (&callback_MsgId_001F)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0020(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0020   (&callback_MsgId_0020)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0021(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0021   (&callback_MsgId_0021)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0022(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0022   (&callback_MsgId_0022)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0023(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0023   (&callback_MsgId_0023)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0024(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0024   (&callback_MsgId_0024)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0025(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0025   (&callback_MsgId_0025)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0026(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0026   (&callback_MsgId_0026)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0027(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0027   (&callback_MsgId_0027)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0028(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0028   (&callback_MsgId_0028)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_002A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_002A   (&callback_MsgId_002A)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_002B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_002B   (&callback_MsgId_002B)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_002C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_002C   (&callback_MsgId_002C)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_002F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_002F   (&callback_MsgId_002F)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0030(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0030   (&callback_MsgId_0030)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0031(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0031   (&callback_MsgId_0031)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0032(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0032   (&callback_MsgId_0032)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0034(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0034   (&callback_MsgId_0034)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0035(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0035   (&callback_MsgId_0035)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0036(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0036   (&callback_MsgId_0036)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0037(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0037   (&callback_MsgId_0037)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0038(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0038   (&callback_MsgId_0038)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0039(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0039   (&callback_MsgId_0039)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_003A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_003A   (&callback_MsgId_003A)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_003B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_003B   (&callback_MsgId_003B)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_003C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_003C   (&callback_MsgId_003C)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_003D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_003D   (&callback_MsgId_003D)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_003F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_003F   (&callback_MsgId_003F)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0040(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0040   (&callback_MsgId_0040)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0041(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0041   (&callback_MsgId_0041)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0042(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0042   (&callback_MsgId_0042)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0043(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0043   (&callback_MsgId_0043)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0044(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0044   (&callback_MsgId_0044)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0045(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0045   (&callback_MsgId_0045)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0046(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0046   (&callback_MsgId_0046)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0047(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0047   (&callback_MsgId_0047)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0048(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0048   (&callback_MsgId_0048)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0049(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0049   (&callback_MsgId_0049)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_004A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_004A   (&callback_MsgId_004A)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_004B   (&callback_MsgId_004B)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_004C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_004C   (&callback_MsgId_004C)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_004D   (&callback_MsgId_004D)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_004E   (&callback_MsgId_004E)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_004F   (&callback_MsgId_004F)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0050(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0050   (&callback_MsgId_0050)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0051(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0051   (&callback_MsgId_0051)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0052(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0052   (&callback_MsgId_0052)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0053(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0053   (&callback_MsgId_0053)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0054(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0054   (&callback_MsgId_0054)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0055(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0055   (&callback_MsgId_0055)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0057(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0057   (&callback_MsgId_0057)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0058(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0058   (&callback_MsgId_0058)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0059(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0059   (&callback_MsgId_0059)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_005A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_005A   (&callback_MsgId_005A)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_005B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_005B   (&callback_MsgId_005B)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_005C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_005C   (&callback_MsgId_005C)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_005D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_005D   (&callback_MsgId_005D)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_005E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_005E   (&callback_MsgId_005E)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_005F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_005F   (&callback_MsgId_005F)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0060(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0060   (&callback_MsgId_0060)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0061(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0061   (&callback_MsgId_0061)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0062(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0062   (&callback_MsgId_0062)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0063(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0063   (&callback_MsgId_0063)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0064(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0064   (&callback_MsgId_0064)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0065(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0065   (&callback_MsgId_0065)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0066(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0066   (&callback_MsgId_0066)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0067(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0067   (&callback_MsgId_0067)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0068(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0068   (&callback_MsgId_0068)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0069(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0069   (&callback_MsgId_0069)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_006A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_006A   (&callback_MsgId_006A)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_006B   (&callback_MsgId_006B)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_006C   (&callback_MsgId_006C)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_006D   (&callback_MsgId_006D)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_006E   (&callback_MsgId_006E)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0070(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0070   (&callback_MsgId_0070)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0071(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0071   (&callback_MsgId_0071)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0072(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0072   (&callback_MsgId_0072)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0073(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0073   (&callback_MsgId_0073)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0074(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0074   (&callback_MsgId_0074)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0075(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0075   (&callback_MsgId_0075)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0076(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0076   (&callback_MsgId_0076)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0077(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0077   (&callback_MsgId_0077)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0078(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0078   (&callback_MsgId_0078)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0079(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0079   (&callback_MsgId_0079)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_007A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_007A   (&callback_MsgId_007A)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_007B   (&callback_MsgId_007B)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_007C   (&callback_MsgId_007C)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_007E   (&callback_MsgId_007E)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_007F   (&callback_MsgId_007F)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0080(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0080   (&callback_MsgId_0080)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0081(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0081   (&callback_MsgId_0081)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0082(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0082   (&callback_MsgId_0082)
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0083(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0083   (&callback_MsgId_0083)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0084(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0084   (&callback_MsgId_0084)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0085(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0085   (&callback_MsgId_0085)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0086(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0086   (&callback_MsgId_0086)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0087(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0087   (&callback_MsgId_0087)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0088(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0088   (&callback_MsgId_0088)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0089(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0089   (&callback_MsgId_0089)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008A(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_008A   (&callback_MsgId_008A)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008B(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_008B   (&callback_MsgId_008B)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008C(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_008C   (&callback_MsgId_008C)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008D(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_008D   (&callback_MsgId_008D)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008E(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_008E   (&callback_MsgId_008E)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_008F(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_008F   (&callback_MsgId_008F)
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0090(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0090   (&callback_MsgId_0090)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0091(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0091   (&callback_MsgId_0091)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0092(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0092   (&callback_MsgId_0092)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0093(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0093   (&callback_MsgId_0093)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0094(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0094   (&callback_MsgId_0094)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0095(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0095   (&callback_MsgId_0095)
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0096(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0096   (&callback_MsgId_0096)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0097(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0097   (&callback_MsgId_0097)
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0098(const void* i_msgData_ps);
#define D_IPC_CALLBACK_FUNC_0098   (&callback_MsgId_0098)
#endif

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */
/* Structure to occupy space in shared memory for signal handler data */
#if (D_NUMBER_OF_TX_MESSAGES > 0)

#if defined(BUILD_MPU1_0)
/* Structure definition for signal handler data with CRC32 */
typedef struct {
    uint8_t                                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0000_t;

typedef struct {
    ScreenResponse_t                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0006_t;

typedef struct {
    ErrorMgr_ErrorCommPack_QNX_QM                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct000C_t;

typedef struct {
    ErrorMgr_ErrorCommPack_QNX_B                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct000D_t;

typedef struct {
    TRSC_Inputs_from_TrailerDetection_t          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct000E_t;

typedef struct {
    MeDLD_e_RrCamSts_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct000F_t;

typedef struct {
    SSM_QNX_CoreStatus                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0016_t;

typedef struct {
    TbSVS_e_SVSCalibSMToAlgoCamCalib_t           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct001B_t;

typedef struct {
    TbSVS_e_SVSCalibAlgoToSMCamCalib_t           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct001C_t;

typedef struct {
    TbSVS_S_SVSCamCurrentCalibDataToNVM_t        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct001D_t;

typedef struct {
    TbSVS_S_SVSCamOCCalibDataToNVM_t             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct001E_t;

typedef struct {
    TbSVS_S_SVSCamSCCalibDataToNVM_t             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct001F_t;

typedef struct {
    TbSVS_S_SVSCamEOLCalibDataToNVM_t            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0020_t;

typedef struct {
    TbSVS_e_SVSOutputToDiagMgrCamCalib_t         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0021_t;

typedef struct {
    JobTHADetOutput_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0025_t;

typedef struct {
    IJobPLDOutput_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct002C_t;

typedef struct {
    IParkingSlotInformation_t                    msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0031_t;

typedef struct {
    MOT_Output                                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0036_t;

typedef struct {
    Svs_CamEepromDataArray_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct004B_t;

typedef struct {
    LMD_Outputs_CVPAMFDData2_t                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct004F_t;

typedef struct {
    TrailerDetection_Output_DID_t                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0055_t;

typedef struct {
    TrscDebug_ScrRes_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct005E_t;

typedef struct {
    WdgCheckpointStatus_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct006E_t;

typedef struct {
    LMD_Lane_Outputs_s                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0070_t;

typedef struct {
    ME_Proxi_MPU1_0_to_MCU1_0_t                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct007F_t;

typedef struct {
    TbSVS_e_SVSCalibSMToHmi_t                    msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0080_t;

typedef struct {
    TrailerDetection_Output_HMI_t                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0083_t;

typedef struct {
    JobDLDOutput_t                               msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0084_t;

typedef struct {
    KeepAliveResponse_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0089_t;

typedef struct {
    Error_Fault_MPU1_0_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct008E_t;

typedef struct {
    RunTimeStats_MPU1_0_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0095_t;

/* Declare shared memory buffers for above structures */
static msgIdDataStruct0000_t                msgIdStruct0000_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0006_t                msgIdStruct0006_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct000C_t                msgIdStruct000C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct000D_t                msgIdStruct000D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct000E_t                msgIdStruct000E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct000F_t                msgIdStruct000F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0016_t                msgIdStruct0016_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct001B_t                msgIdStruct001B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct001C_t                msgIdStruct001C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct001D_t                msgIdStruct001D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct001E_t                msgIdStruct001E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct001F_t                msgIdStruct001F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0020_t                msgIdStruct0020_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0021_t                msgIdStruct0021_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0025_t                msgIdStruct0025_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct002C_t                msgIdStruct002C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0031_t                msgIdStruct0031_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0036_t                msgIdStruct0036_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct004B_t                msgIdStruct004B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct004F_t                msgIdStruct004F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0055_t                msgIdStruct0055_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct005E_t                msgIdStruct005E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct006E_t                msgIdStruct006E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0070_t                msgIdStruct0070_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct007F_t                msgIdStruct007F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0080_t                msgIdStruct0080_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0083_t                msgIdStruct0083_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0084_t                msgIdStruct0084_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0089_t                msgIdStruct0089_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct008E_t                msgIdStruct008E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0095_t                msgIdStruct0095_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));

/* Shared memory buffer states */
static IpcSmBuffState_t                            msgIdSmBuffState0000_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0006_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState000C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState000D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState000E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState000F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0016_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState001B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState001C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState001D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState001E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState001F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0020_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0021_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0025_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState002C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0031_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0036_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState004B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState004F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0055_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState005E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState006E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0070_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState007F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0080_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0083_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0084_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0089_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState008E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0095_as[3];

/* Shared memory buffer base addresss and size of corresponding message id */
#define D_SMBUFF_BASE_ADDR_0000             ((sizeof(uint8_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0000_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0000           (sizeof(msgIdDataStruct0000_t))

#define D_SMBUFF_BASE_ADDR_0006             ((sizeof(ScreenResponse_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0006_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0006           (sizeof(msgIdDataStruct0006_t))

#define D_SMBUFF_BASE_ADDR_000C             ((sizeof(ErrorMgr_ErrorCommPack_QNX_QM)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct000C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_000C           (sizeof(msgIdDataStruct000C_t))

#define D_SMBUFF_BASE_ADDR_000D             ((sizeof(ErrorMgr_ErrorCommPack_QNX_B)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct000D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_000D           (sizeof(msgIdDataStruct000D_t))

#define D_SMBUFF_BASE_ADDR_000E             ((sizeof(TRSC_Inputs_from_TrailerDetection_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct000E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_000E           (sizeof(msgIdDataStruct000E_t))

#define D_SMBUFF_BASE_ADDR_000F             ((sizeof(MeDLD_e_RrCamSts_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct000F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_000F           (sizeof(msgIdDataStruct000F_t))

#define D_SMBUFF_BASE_ADDR_0016             ((sizeof(SSM_QNX_CoreStatus)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0016_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0016           (sizeof(msgIdDataStruct0016_t))

#define D_SMBUFF_BASE_ADDR_001B             ((sizeof(TbSVS_e_SVSCalibSMToAlgoCamCalib_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct001B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_001B           (sizeof(msgIdDataStruct001B_t))

#define D_SMBUFF_BASE_ADDR_001C             ((sizeof(TbSVS_e_SVSCalibAlgoToSMCamCalib_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct001C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_001C           (sizeof(msgIdDataStruct001C_t))

#define D_SMBUFF_BASE_ADDR_001D             ((sizeof(TbSVS_S_SVSCamCurrentCalibDataToNVM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct001D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_001D           (sizeof(msgIdDataStruct001D_t))

#define D_SMBUFF_BASE_ADDR_001E             ((sizeof(TbSVS_S_SVSCamOCCalibDataToNVM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct001E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_001E           (sizeof(msgIdDataStruct001E_t))

#define D_SMBUFF_BASE_ADDR_001F             ((sizeof(TbSVS_S_SVSCamSCCalibDataToNVM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct001F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_001F           (sizeof(msgIdDataStruct001F_t))

#define D_SMBUFF_BASE_ADDR_0020             ((sizeof(TbSVS_S_SVSCamEOLCalibDataToNVM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0020_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0020           (sizeof(msgIdDataStruct0020_t))

#define D_SMBUFF_BASE_ADDR_0021             ((sizeof(TbSVS_e_SVSOutputToDiagMgrCamCalib_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0021_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0021           (sizeof(msgIdDataStruct0021_t))

#define D_SMBUFF_BASE_ADDR_0025             ((sizeof(JobTHADetOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0025_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0025           (sizeof(msgIdDataStruct0025_t))

#define D_SMBUFF_BASE_ADDR_002C             ((sizeof(IJobPLDOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct002C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_002C           (sizeof(msgIdDataStruct002C_t))

#define D_SMBUFF_BASE_ADDR_0031             ((sizeof(IParkingSlotInformation_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0031_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0031           (sizeof(msgIdDataStruct0031_t))

#define D_SMBUFF_BASE_ADDR_0036             ((sizeof(MOT_Output)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0036_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0036           (sizeof(msgIdDataStruct0036_t))

#define D_SMBUFF_BASE_ADDR_004B             ((sizeof(Svs_CamEepromDataArray_t )>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct004B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_004B           (sizeof(msgIdDataStruct004B_t))

#define D_SMBUFF_BASE_ADDR_004F             ((sizeof(LMD_Outputs_CVPAMFDData2_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct004F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_004F           (sizeof(msgIdDataStruct004F_t))

#define D_SMBUFF_BASE_ADDR_0055             ((sizeof(TrailerDetection_Output_DID_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0055_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0055           (sizeof(msgIdDataStruct0055_t))

#define D_SMBUFF_BASE_ADDR_005E             ((sizeof(TrscDebug_ScrRes_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct005E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_005E           (sizeof(msgIdDataStruct005E_t))

#define D_SMBUFF_BASE_ADDR_006E             ((sizeof(WdgCheckpointStatus_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct006E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_006E           (sizeof(msgIdDataStruct006E_t))

#define D_SMBUFF_BASE_ADDR_0070             ((sizeof(LMD_Lane_Outputs_s)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0070_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0070           (sizeof(msgIdDataStruct0070_t))

#define D_SMBUFF_BASE_ADDR_007F             ((sizeof(ME_Proxi_MPU1_0_to_MCU1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct007F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_007F           (sizeof(msgIdDataStruct007F_t))

#define D_SMBUFF_BASE_ADDR_0080             ((sizeof(TbSVS_e_SVSCalibSMToHmi_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0080_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0080           (sizeof(msgIdDataStruct0080_t))

#define D_SMBUFF_BASE_ADDR_0083             ((sizeof(TrailerDetection_Output_HMI_t )>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0083_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0083           (sizeof(msgIdDataStruct0083_t))

#define D_SMBUFF_BASE_ADDR_0084             ((sizeof(JobDLDOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0084_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0084           (sizeof(msgIdDataStruct0084_t))

#define D_SMBUFF_BASE_ADDR_0089             ((sizeof(KeepAliveResponse_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0089_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0089           (sizeof(msgIdDataStruct0089_t))

#define D_SMBUFF_BASE_ADDR_008E             ((sizeof(Error_Fault_MPU1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct008E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_008E           (sizeof(msgIdDataStruct008E_t))

#define D_SMBUFF_BASE_ADDR_0095             ((sizeof(RunTimeStats_MPU1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0095_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0095           (sizeof(msgIdDataStruct0095_t))

#endif

#if defined(BUILD_MCU1_0)
/* Structure definition for signal handler data with CRC32 */
typedef struct {
    ME_VehInp_to_IpcSignals_t                    msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0007_t;

typedef struct {
    SSM_SystemState                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0017_t;

typedef struct {
    CalDataProvider_MPU_1_0_Def                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0018_t;

typedef struct {
    CalDataProvider_MCU_2_0_Def                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0019_t;

typedef struct {
    CalDataProvider_MCU_2_1_Def                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct001A_t;

typedef struct {
    TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0022_t;

typedef struct {
    TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0023_t;

typedef struct {
    ME_Proxi_to_IpcSignals_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0024_t;

typedef struct {
    IKinematicData_t                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct002F_t;

typedef struct {
    ExtY_Kinematic_T                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0030_t;

typedef struct {
    FID_STRUCT_QM                                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0040_t;

typedef struct {
    FID_STRUCT_B                                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0041_t;

typedef struct {
    USS_Curr_Volt_Monitor_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0049_t;

typedef struct {
    DiagToSVS_t                                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct004C_t;

typedef struct {
    CAM_Curr_Volt_Monitor_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0050_t;

typedef struct {
    US_S_MarriageSensorIDs_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0053_t;

typedef struct {
    DiagToParkAssist_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0058_t;

typedef struct {
    ME_ProxiToMPU1_0_Def_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct005B_t;

typedef struct {
    ME_ProxiToMCU2_0_Def_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct005C_t;

typedef struct {
    ME_ProxiToMCU2_1_Def_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct005D_t;

typedef struct {
    TbNVM_ReadParam                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0064_t;

typedef struct {
    ME_CanDebugRIDStatus_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0065_t;

typedef struct {
    SVS_NVMData_t                                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0066_t;

typedef struct {
    USS_Calibration_Data_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct006A_t;

typedef struct {
    THA_Calibration_data_MCU2_1_t                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0072_t;

typedef struct {
    THA_Calibration_data_MPU1_0_t                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0073_t;

typedef struct {
    TRSC_Calibration_data_MCU2_1_t               msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0074_t;

typedef struct {
    APA_Calibration_data_MPU1_0_t                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0075_t;

typedef struct {
    APA_Calibration_data_MCU2_1_t                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0076_t;

typedef struct {
    SVS_Calibration_data_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0077_t;

typedef struct {
    FOD_Calibration_data_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0078_t;

typedef struct {
    LMD_Calibration_data_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0079_t;

typedef struct {
    TRSC_Calibration_data_MPU1_0_t               msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct007A_t;

typedef struct {
    USS_Calibration_data_2_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0081_t;

typedef struct {
    INVMSignalManager_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0085_t;

typedef struct {
    TimeManagerProxy_TimeStamp_t                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0087_t;

typedef struct {
    TRSC_CalibrationClear_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct008F_t;

typedef struct {
    UssTunningData_mcu1_0_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0090_t;

typedef struct {
    PerformanceStatsEnable_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0094_t;

/* Declare shared memory buffers for above structures */
static msgIdDataStruct0007_t                msgIdStruct0007_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0017_t                msgIdStruct0017_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0018_t                msgIdStruct0018_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0019_t                msgIdStruct0019_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct001A_t                msgIdStruct001A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0022_t                msgIdStruct0022_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0023_t                msgIdStruct0023_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0024_t                msgIdStruct0024_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct002F_t                msgIdStruct002F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0030_t                msgIdStruct0030_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0040_t                msgIdStruct0040_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0041_t                msgIdStruct0041_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0049_t                msgIdStruct0049_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct004C_t                msgIdStruct004C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0050_t                msgIdStruct0050_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0053_t                msgIdStruct0053_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0058_t                msgIdStruct0058_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct005B_t                msgIdStruct005B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct005C_t                msgIdStruct005C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct005D_t                msgIdStruct005D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0064_t                msgIdStruct0064_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0065_t                msgIdStruct0065_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0066_t                msgIdStruct0066_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct006A_t                msgIdStruct006A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0072_t                msgIdStruct0072_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0073_t                msgIdStruct0073_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0074_t                msgIdStruct0074_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0075_t                msgIdStruct0075_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0076_t                msgIdStruct0076_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0077_t                msgIdStruct0077_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0078_t                msgIdStruct0078_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0079_t                msgIdStruct0079_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct007A_t                msgIdStruct007A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0081_t                msgIdStruct0081_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0085_t                msgIdStruct0085_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0087_t                msgIdStruct0087_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct008F_t                msgIdStruct008F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0090_t                msgIdStruct0090_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0094_t                msgIdStruct0094_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));

/* Shared memory buffer states */
static IpcSmBuffState_t                            msgIdSmBuffState0007_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0017_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0018_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0019_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState001A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0022_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0023_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0024_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState002F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0030_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0040_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0041_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0049_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState004C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0050_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0053_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0058_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState005B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState005C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState005D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0064_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0065_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0066_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState006A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0072_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0073_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0074_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0075_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0076_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0077_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0078_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0079_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState007A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0081_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0085_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0087_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState008F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0090_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0094_as[3];

/* Shared memory buffer base addresss and size of corresponding message id */
#define D_SMBUFF_BASE_ADDR_0007             ((sizeof(ME_VehInp_to_IpcSignals_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0007_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0007           (sizeof(msgIdDataStruct0007_t))

#define D_SMBUFF_BASE_ADDR_0017             ((sizeof(SSM_SystemState)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0017_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0017           (sizeof(msgIdDataStruct0017_t))

#define D_SMBUFF_BASE_ADDR_0018             ((sizeof(CalDataProvider_MPU_1_0_Def)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0018_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0018           (sizeof(msgIdDataStruct0018_t))

#define D_SMBUFF_BASE_ADDR_0019             ((sizeof(CalDataProvider_MCU_2_0_Def)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0019_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0019           (sizeof(msgIdDataStruct0019_t))

#define D_SMBUFF_BASE_ADDR_001A             ((sizeof(CalDataProvider_MCU_2_1_Def)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct001A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_001A           (sizeof(msgIdDataStruct001A_t))

#define D_SMBUFF_BASE_ADDR_0022             ((sizeof(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0022_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0022           (sizeof(msgIdDataStruct0022_t))

#define D_SMBUFF_BASE_ADDR_0023             ((sizeof(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0023_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0023           (sizeof(msgIdDataStruct0023_t))

#define D_SMBUFF_BASE_ADDR_0024             ((sizeof(ME_Proxi_to_IpcSignals_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0024_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0024           (sizeof(msgIdDataStruct0024_t))

#define D_SMBUFF_BASE_ADDR_002F             ((sizeof(IKinematicData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct002F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_002F           (sizeof(msgIdDataStruct002F_t))

#define D_SMBUFF_BASE_ADDR_0030             ((sizeof(ExtY_Kinematic_T)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0030_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0030           (sizeof(msgIdDataStruct0030_t))

#define D_SMBUFF_BASE_ADDR_0040             ((sizeof(FID_STRUCT_QM)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0040_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0040           (sizeof(msgIdDataStruct0040_t))

#define D_SMBUFF_BASE_ADDR_0041             ((sizeof(FID_STRUCT_B)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0041_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0041           (sizeof(msgIdDataStruct0041_t))

#define D_SMBUFF_BASE_ADDR_0049             ((sizeof(USS_Curr_Volt_Monitor_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0049_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0049           (sizeof(msgIdDataStruct0049_t))

#define D_SMBUFF_BASE_ADDR_004C             ((sizeof(DiagToSVS_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct004C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_004C           (sizeof(msgIdDataStruct004C_t))

#define D_SMBUFF_BASE_ADDR_0050             ((sizeof(CAM_Curr_Volt_Monitor_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0050_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0050           (sizeof(msgIdDataStruct0050_t))

#define D_SMBUFF_BASE_ADDR_0053             ((sizeof(US_S_MarriageSensorIDs_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0053_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0053           (sizeof(msgIdDataStruct0053_t))

#define D_SMBUFF_BASE_ADDR_0058             ((sizeof(DiagToParkAssist_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0058_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0058           (sizeof(msgIdDataStruct0058_t))

#define D_SMBUFF_BASE_ADDR_005B             ((sizeof(ME_ProxiToMPU1_0_Def_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct005B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_005B           (sizeof(msgIdDataStruct005B_t))

#define D_SMBUFF_BASE_ADDR_005C             ((sizeof(ME_ProxiToMCU2_0_Def_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct005C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_005C           (sizeof(msgIdDataStruct005C_t))

#define D_SMBUFF_BASE_ADDR_005D             ((sizeof(ME_ProxiToMCU2_1_Def_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct005D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_005D           (sizeof(msgIdDataStruct005D_t))

#define D_SMBUFF_BASE_ADDR_0064             ((sizeof(TbNVM_ReadParam)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0064_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0064           (sizeof(msgIdDataStruct0064_t))

#define D_SMBUFF_BASE_ADDR_0065             ((sizeof(ME_CanDebugRIDStatus_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0065_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0065           (sizeof(msgIdDataStruct0065_t))

#define D_SMBUFF_BASE_ADDR_0066             ((sizeof(SVS_NVMData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0066_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0066           (sizeof(msgIdDataStruct0066_t))

#define D_SMBUFF_BASE_ADDR_006A             ((sizeof(USS_Calibration_Data_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct006A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_006A           (sizeof(msgIdDataStruct006A_t))

#define D_SMBUFF_BASE_ADDR_0072             ((sizeof(THA_Calibration_data_MCU2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0072_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0072           (sizeof(msgIdDataStruct0072_t))

#define D_SMBUFF_BASE_ADDR_0073             ((sizeof(THA_Calibration_data_MPU1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0073_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0073           (sizeof(msgIdDataStruct0073_t))

#define D_SMBUFF_BASE_ADDR_0074             ((sizeof(TRSC_Calibration_data_MCU2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0074_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0074           (sizeof(msgIdDataStruct0074_t))

#define D_SMBUFF_BASE_ADDR_0075             ((sizeof(APA_Calibration_data_MPU1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0075_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0075           (sizeof(msgIdDataStruct0075_t))

#define D_SMBUFF_BASE_ADDR_0076             ((sizeof(APA_Calibration_data_MCU2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0076_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0076           (sizeof(msgIdDataStruct0076_t))

#define D_SMBUFF_BASE_ADDR_0077             ((sizeof(SVS_Calibration_data_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0077_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0077           (sizeof(msgIdDataStruct0077_t))

#define D_SMBUFF_BASE_ADDR_0078             ((sizeof(FOD_Calibration_data_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0078_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0078           (sizeof(msgIdDataStruct0078_t))

#define D_SMBUFF_BASE_ADDR_0079             ((sizeof(LMD_Calibration_data_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0079_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0079           (sizeof(msgIdDataStruct0079_t))

#define D_SMBUFF_BASE_ADDR_007A             ((sizeof(TRSC_Calibration_data_MPU1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct007A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_007A           (sizeof(msgIdDataStruct007A_t))

#define D_SMBUFF_BASE_ADDR_0081             ((sizeof(USS_Calibration_data_2_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0081_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0081           (sizeof(msgIdDataStruct0081_t))

#define D_SMBUFF_BASE_ADDR_0085             ((sizeof(INVMSignalManager_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0085_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0085           (sizeof(msgIdDataStruct0085_t))

#define D_SMBUFF_BASE_ADDR_0087             ((sizeof(TimeManagerProxy_TimeStamp_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0087_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0087           (sizeof(msgIdDataStruct0087_t))

#define D_SMBUFF_BASE_ADDR_008F             ((sizeof(TRSC_CalibrationClear_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct008F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_008F           (sizeof(msgIdDataStruct008F_t))

#define D_SMBUFF_BASE_ADDR_0090             ((sizeof(UssTunningData_mcu1_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0090_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0090           (sizeof(msgIdDataStruct0090_t))

#define D_SMBUFF_BASE_ADDR_0094             ((sizeof(PerformanceStatsEnable_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0094_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0094           (sizeof(msgIdDataStruct0094_t))

#endif

#if defined(BUILD_MCU2_0)
/* Structure definition for signal handler data with CRC32 */
typedef struct {
    SvsToTHADet_t                                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0001_t;

typedef struct {
    SvsToVCAN_t                                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0002_t;

typedef struct {
    SVStoTRSC_t                                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0003_t;

typedef struct {
    ScreenRequest_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0004_t;

typedef struct {
    SvsToTHA_t                                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0005_t;

typedef struct {
    ErrorMgr_ErrorCommPack_2_0_QM                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0008_t;

typedef struct {
    ErrorMgr_ErrorCommPack_2_0_B                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0009_t;

typedef struct {
    SVStoTRSCSMVC_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0011_t;

typedef struct {
    SSM_2_0_CoreStatus                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0014_t;

typedef struct {
    IHMIInfoToFPA_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct002B_t;

typedef struct {
    IParkingSlotID_t                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0034_t;

typedef struct {
    THARelated_ScreenReq_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct004A_t;

typedef struct {
    SVSToDiag_t                                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct004D_t;

typedef struct {
    CAM_CS_Curr_Monitor_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0051_t;

typedef struct {
    HMIInfoToAP_t                                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0057_t;

typedef struct {
    USS_PowerSelect_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct005A_t;

typedef struct {
    TRSCDebug_ScrReq_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct005F_t;

typedef struct {
    CpuLoadMcu2_0_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0063_t;

typedef struct {
    SVS_NVMData_t                                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0069_t;

typedef struct {
    WdgCheckpointStatus_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct006D_t;

typedef struct {
    Cam_and_Ser_EN_Status_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0082_t;

typedef struct {
    CAM_select_info_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct008B_t;

typedef struct {
    Error_Fault_MCU2_0_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct008C_t;

typedef struct {
    RunTimeStats_MCU2_0_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0093_t;

typedef struct {
    CamHotplugStatus_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0096_t;

typedef struct {
    StackUsage_MCU2_0_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0098_t;

/* Declare shared memory buffers for above structures */
static msgIdDataStruct0001_t                msgIdStruct0001_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0002_t                msgIdStruct0002_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0003_t                msgIdStruct0003_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0004_t                msgIdStruct0004_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0005_t                msgIdStruct0005_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0008_t                msgIdStruct0008_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0009_t                msgIdStruct0009_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0011_t                msgIdStruct0011_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0014_t                msgIdStruct0014_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct002B_t                msgIdStruct002B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0034_t                msgIdStruct0034_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct004A_t                msgIdStruct004A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct004D_t                msgIdStruct004D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0051_t                msgIdStruct0051_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0057_t                msgIdStruct0057_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct005A_t                msgIdStruct005A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct005F_t                msgIdStruct005F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0063_t                msgIdStruct0063_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0069_t                msgIdStruct0069_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct006D_t                msgIdStruct006D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0082_t                msgIdStruct0082_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct008B_t                msgIdStruct008B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct008C_t                msgIdStruct008C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0093_t                msgIdStruct0093_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0096_t                msgIdStruct0096_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0098_t                msgIdStruct0098_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));

/* Shared memory buffer states */
static IpcSmBuffState_t                            msgIdSmBuffState0001_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0002_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0003_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0004_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0005_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0008_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0009_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0011_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0014_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState002B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0034_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState004A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState004D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0051_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0057_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState005A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState005F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0063_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0069_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState006D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0082_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState008B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState008C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0093_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0096_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0098_as[3];

/* Shared memory buffer base addresss and size of corresponding message id */
#define D_SMBUFF_BASE_ADDR_0001             ((sizeof(SvsToTHADet_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0001_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0001           (sizeof(msgIdDataStruct0001_t))

#define D_SMBUFF_BASE_ADDR_0002             ((sizeof(SvsToVCAN_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0002_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0002           (sizeof(msgIdDataStruct0002_t))

#define D_SMBUFF_BASE_ADDR_0003             ((sizeof(SVStoTRSC_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0003_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0003           (sizeof(msgIdDataStruct0003_t))

#define D_SMBUFF_BASE_ADDR_0004             ((sizeof(ScreenRequest_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0004_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0004           (sizeof(msgIdDataStruct0004_t))

#define D_SMBUFF_BASE_ADDR_0005             ((sizeof(SvsToTHA_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0005_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0005           (sizeof(msgIdDataStruct0005_t))

#define D_SMBUFF_BASE_ADDR_0008             ((sizeof(ErrorMgr_ErrorCommPack_2_0_QM)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0008_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0008           (sizeof(msgIdDataStruct0008_t))

#define D_SMBUFF_BASE_ADDR_0009             ((sizeof(ErrorMgr_ErrorCommPack_2_0_B)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0009_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0009           (sizeof(msgIdDataStruct0009_t))

#define D_SMBUFF_BASE_ADDR_0011             ((sizeof(SVStoTRSCSMVC_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0011_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0011           (sizeof(msgIdDataStruct0011_t))

#define D_SMBUFF_BASE_ADDR_0014             ((sizeof(SSM_2_0_CoreStatus)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0014_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0014           (sizeof(msgIdDataStruct0014_t))

#define D_SMBUFF_BASE_ADDR_002B             ((sizeof(IHMIInfoToFPA_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct002B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_002B           (sizeof(msgIdDataStruct002B_t))

#define D_SMBUFF_BASE_ADDR_0034             ((sizeof(IParkingSlotID_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0034_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0034           (sizeof(msgIdDataStruct0034_t))

#define D_SMBUFF_BASE_ADDR_004A             ((sizeof(THARelated_ScreenReq_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct004A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_004A           (sizeof(msgIdDataStruct004A_t))

#define D_SMBUFF_BASE_ADDR_004D             ((sizeof(SVSToDiag_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct004D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_004D           (sizeof(msgIdDataStruct004D_t))

#define D_SMBUFF_BASE_ADDR_0051             ((sizeof(CAM_CS_Curr_Monitor_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0051_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0051           (sizeof(msgIdDataStruct0051_t))

#define D_SMBUFF_BASE_ADDR_0057             ((sizeof(HMIInfoToAP_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0057_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0057           (sizeof(msgIdDataStruct0057_t))

#define D_SMBUFF_BASE_ADDR_005A             ((sizeof(USS_PowerSelect_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct005A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_005A           (sizeof(msgIdDataStruct005A_t))

#define D_SMBUFF_BASE_ADDR_005F             ((sizeof(TRSCDebug_ScrReq_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct005F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_005F           (sizeof(msgIdDataStruct005F_t))

#define D_SMBUFF_BASE_ADDR_0063             ((sizeof(CpuLoadMcu2_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0063_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0063           (sizeof(msgIdDataStruct0063_t))

#define D_SMBUFF_BASE_ADDR_0069             ((sizeof(SVS_NVMData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0069_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0069           (sizeof(msgIdDataStruct0069_t))

#define D_SMBUFF_BASE_ADDR_006D             ((sizeof(WdgCheckpointStatus_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct006D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_006D           (sizeof(msgIdDataStruct006D_t))

#define D_SMBUFF_BASE_ADDR_0082             ((sizeof(Cam_and_Ser_EN_Status_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0082_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0082           (sizeof(msgIdDataStruct0082_t))

#define D_SMBUFF_BASE_ADDR_008B             ((sizeof(CAM_select_info_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct008B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_008B           (sizeof(msgIdDataStruct008B_t))

#define D_SMBUFF_BASE_ADDR_008C             ((sizeof(Error_Fault_MCU2_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct008C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_008C           (sizeof(msgIdDataStruct008C_t))

#define D_SMBUFF_BASE_ADDR_0093             ((sizeof(RunTimeStats_MCU2_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0093_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0093           (sizeof(msgIdDataStruct0093_t))

#define D_SMBUFF_BASE_ADDR_0096             ((sizeof(CamHotplugStatus_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0096_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0096           (sizeof(msgIdDataStruct0096_t))

#define D_SMBUFF_BASE_ADDR_0098             ((sizeof(StackUsage_MCU2_0_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0098_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0098           (sizeof(msgIdDataStruct0098_t))

#endif

#if defined(BUILD_MCU2_1)
/* Structure definition for signal handler data with CRC32 */
typedef struct {
    ErrorMgr_ErrorCommPack_2_1_QM                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct000A_t;

typedef struct {
    ErrorMgr_ErrorCommPack_2_1_B                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct000B_t;

typedef struct {
    ME_VehOut_TRSC_t                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0010_t;

typedef struct {
    TRSCSMVCtoSVS_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0012_t;

typedef struct {
    Detection_Inputs_from_TRSC_t                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0013_t;

typedef struct {
    SSM_2_1_CoreStatus                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0015_t;

typedef struct {
    TbAP_APSMPAOut_t                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0026_t;

typedef struct {
    TbTHASmVc_FeatureOutputs_t                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0027_t;

typedef struct {
    IFPAInfoToHMI_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0028_t;

typedef struct {
    IFPAInfoToVC_t                               msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0029_t;

typedef struct {
    IFPAInfoToPLD_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct002A_t;

typedef struct {
    IUPASensorDataV2_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct002D_t;

typedef struct {
    IPathPlannerState_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct002E_t;

typedef struct {
    IJobFPAOutput_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0032_t;

typedef struct {
    IAutoParkingState_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0033_t;

typedef struct {
    NFCD_Output                                  msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0035_t;

typedef struct {
    TbAP_DriveAssistStatOut_t                    msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0037_t;

typedef struct {
    TbAP_SMDAInternalOut_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0038_t;

typedef struct {
    TbAP_SMPAInternalOut_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0039_t;

typedef struct {
    TbAP_FPAWarnOut_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct003A_t;

typedef struct {
    TbAP_RPAWarnOut_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct003B_t;

typedef struct {
    TbAP_PAStateOut_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct003C_t;

typedef struct {
    TbAP_VCActuatorOut_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct003D_t;

typedef struct {
    TbAP_VCTrajOut_t                             msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct003E_t;

typedef struct {
    TbAP_VCStateOut_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct003F_t;

typedef struct {
    US_S_PointMapGroup_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0042_t;

typedef struct {
    US_S_SnrDirEcho_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0043_t;

typedef struct {
    US_S_ZoneInfo_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0044_t;

typedef struct {
    US_S_BlockageBit_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0045_t;

typedef struct {
    US_S_USSConstantData_t                       msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0046_t;

typedef struct {
    US_S_USSPeriodDiagData_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0047_t;

typedef struct {
    US_S_USSErrorDiagData_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0048_t;

typedef struct {
    IFOD_Outputs_CVPAMFDData_t                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct004E_t;

typedef struct {
    US_S_MarriageSensorIDs_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0052_t;

typedef struct {
    TRSCtoDiagMgr_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0054_t;

typedef struct {
    TbAP_USSStateOut_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0056_t;

typedef struct {
    USS_PowerSelect_t                            msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0059_t;

typedef struct {
    US_S_USSDataCollectionData_t                 msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0060_t;

typedef struct {
    US_S_PointDistOutputBuff_t                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0061_t;

typedef struct {
    CpuLoadMcu2_1_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0062_t;

typedef struct {
    IJobUSSObjectMapOutput_t                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0067_t;

typedef struct {
    TbFA_ArbiterOutput_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0068_t;

typedef struct {
    TbAP_DebugOut                                msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct006B_t;

typedef struct {
    WdgCheckpointStatus_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct006C_t;

typedef struct {
    uint32_t                                     msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct006F_t;

typedef struct {
    TbTHASmVc_DiagMgr_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0071_t;

typedef struct {
    IFOD_Outputs_Arbitration_t                   msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct007B_t;

typedef struct {
    IDebug_FODObject_t                           msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct007C_t;

typedef struct {
    TbFA_USSStateOutput_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct007D_t;

typedef struct {
    TbFA_ResetKM_t                               msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct007E_t;

typedef struct {
    TRSCSMVCtoDebugCAN_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0086_t;

typedef struct {
    US_S_CsmStateChangeReason_Type               msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0088_t;

typedef struct {
    US_S_DebugMsg_t                              msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct008A_t;

typedef struct {
    Error_Fault_MCU2_1_t                         msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct008D_t;

typedef struct {
    UssTunningData_mcu2_1_t                      msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0091_t;

typedef struct {
    RunTimeStats_MCU2_1_t                        msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0092_t;

typedef struct {
    StackUsage_MCU2_1_t                          msgIdData_s;
    uint32_t                                msgIdCrc32_u32;
}msgIdDataStruct0097_t;

/* Declare shared memory buffers for above structures */
static msgIdDataStruct000A_t                msgIdStruct000A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct000B_t                msgIdStruct000B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0010_t                msgIdStruct0010_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0012_t                msgIdStruct0012_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0013_t                msgIdStruct0013_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0015_t                msgIdStruct0015_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0026_t                msgIdStruct0026_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0027_t                msgIdStruct0027_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0028_t                msgIdStruct0028_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0029_t                msgIdStruct0029_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct002A_t                msgIdStruct002A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct002D_t                msgIdStruct002D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct002E_t                msgIdStruct002E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0032_t                msgIdStruct0032_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0033_t                msgIdStruct0033_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0035_t                msgIdStruct0035_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0037_t                msgIdStruct0037_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0038_t                msgIdStruct0038_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0039_t                msgIdStruct0039_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct003A_t                msgIdStruct003A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct003B_t                msgIdStruct003B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct003C_t                msgIdStruct003C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct003D_t                msgIdStruct003D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct003E_t                msgIdStruct003E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct003F_t                msgIdStruct003F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0042_t                msgIdStruct0042_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0043_t                msgIdStruct0043_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0044_t                msgIdStruct0044_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0045_t                msgIdStruct0045_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0046_t                msgIdStruct0046_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0047_t                msgIdStruct0047_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0048_t                msgIdStruct0048_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct004E_t                msgIdStruct004E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0052_t                msgIdStruct0052_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0054_t                msgIdStruct0054_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0056_t                msgIdStruct0056_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0059_t                msgIdStruct0059_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0060_t                msgIdStruct0060_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0061_t                msgIdStruct0061_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0062_t                msgIdStruct0062_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0067_t                msgIdStruct0067_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0068_t                msgIdStruct0068_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct006B_t                msgIdStruct006B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct006C_t                msgIdStruct006C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct006F_t                msgIdStruct006F_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0071_t                msgIdStruct0071_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct007B_t                msgIdStruct007B_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct007C_t                msgIdStruct007C_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct007D_t                msgIdStruct007D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct007E_t                msgIdStruct007E_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0086_t                msgIdStruct0086_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0088_t                msgIdStruct0088_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct008A_t                msgIdStruct008A_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct008D_t                msgIdStruct008D_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0091_t                msgIdStruct0091_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0092_t                msgIdStruct0092_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));
static msgIdDataStruct0097_t                msgIdStruct0097_as[3] __attribute__ ((section("ipc_shared_Mem_buff"), aligned(4)));

/* Shared memory buffer states */
static IpcSmBuffState_t                            msgIdSmBuffState000A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState000B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0010_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0012_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0013_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0015_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0026_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0027_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0028_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0029_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState002A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState002D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState002E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0032_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0033_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0035_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0037_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0038_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0039_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState003A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState003B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState003C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState003D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState003E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState003F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0042_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0043_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0044_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0045_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0046_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0047_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0048_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState004E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0052_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0054_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0056_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0059_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0060_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0061_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0062_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0067_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0068_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState006B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState006C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState006F_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0071_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState007B_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState007C_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState007D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState007E_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0086_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0088_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState008A_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState008D_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0091_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0092_as[3];
static IpcSmBuffState_t                            msgIdSmBuffState0097_as[3];

/* Shared memory buffer base addresss and size of corresponding message id */
#define D_SMBUFF_BASE_ADDR_000A             ((sizeof(ErrorMgr_ErrorCommPack_2_1_QM)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct000A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_000A           (sizeof(msgIdDataStruct000A_t))

#define D_SMBUFF_BASE_ADDR_000B             ((sizeof(ErrorMgr_ErrorCommPack_2_1_B)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct000B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_000B           (sizeof(msgIdDataStruct000B_t))

#define D_SMBUFF_BASE_ADDR_0010             ((sizeof(ME_VehOut_TRSC_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0010_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0010           (sizeof(msgIdDataStruct0010_t))

#define D_SMBUFF_BASE_ADDR_0012             ((sizeof(TRSCSMVCtoSVS_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0012_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0012           (sizeof(msgIdDataStruct0012_t))

#define D_SMBUFF_BASE_ADDR_0013             ((sizeof(Detection_Inputs_from_TRSC_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0013_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0013           (sizeof(msgIdDataStruct0013_t))

#define D_SMBUFF_BASE_ADDR_0015             ((sizeof(SSM_2_1_CoreStatus)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0015_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0015           (sizeof(msgIdDataStruct0015_t))

#define D_SMBUFF_BASE_ADDR_0026             ((sizeof(TbAP_APSMPAOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0026_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0026           (sizeof(msgIdDataStruct0026_t))

#define D_SMBUFF_BASE_ADDR_0027             ((sizeof(TbTHASmVc_FeatureOutputs_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0027_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0027           (sizeof(msgIdDataStruct0027_t))

#define D_SMBUFF_BASE_ADDR_0028             ((sizeof(IFPAInfoToHMI_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0028_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0028           (sizeof(msgIdDataStruct0028_t))

#define D_SMBUFF_BASE_ADDR_0029             ((sizeof(IFPAInfoToVC_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0029_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0029           (sizeof(msgIdDataStruct0029_t))

#define D_SMBUFF_BASE_ADDR_002A             ((sizeof(IFPAInfoToPLD_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct002A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_002A           (sizeof(msgIdDataStruct002A_t))

#define D_SMBUFF_BASE_ADDR_002D             ((sizeof(IUPASensorDataV2_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct002D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_002D           (sizeof(msgIdDataStruct002D_t))

#define D_SMBUFF_BASE_ADDR_002E             ((sizeof(IPathPlannerState_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct002E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_002E           (sizeof(msgIdDataStruct002E_t))

#define D_SMBUFF_BASE_ADDR_0032             ((sizeof(IJobFPAOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0032_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0032           (sizeof(msgIdDataStruct0032_t))

#define D_SMBUFF_BASE_ADDR_0033             ((sizeof(IAutoParkingState_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0033_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0033           (sizeof(msgIdDataStruct0033_t))

#define D_SMBUFF_BASE_ADDR_0035             ((sizeof(NFCD_Output)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0035_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0035           (sizeof(msgIdDataStruct0035_t))

#define D_SMBUFF_BASE_ADDR_0037             ((sizeof(TbAP_DriveAssistStatOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0037_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0037           (sizeof(msgIdDataStruct0037_t))

#define D_SMBUFF_BASE_ADDR_0038             ((sizeof(TbAP_SMDAInternalOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0038_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0038           (sizeof(msgIdDataStruct0038_t))

#define D_SMBUFF_BASE_ADDR_0039             ((sizeof(TbAP_SMPAInternalOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0039_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0039           (sizeof(msgIdDataStruct0039_t))

#define D_SMBUFF_BASE_ADDR_003A             ((sizeof(TbAP_FPAWarnOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct003A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_003A           (sizeof(msgIdDataStruct003A_t))

#define D_SMBUFF_BASE_ADDR_003B             ((sizeof(TbAP_RPAWarnOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct003B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_003B           (sizeof(msgIdDataStruct003B_t))

#define D_SMBUFF_BASE_ADDR_003C             ((sizeof(TbAP_PAStateOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct003C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_003C           (sizeof(msgIdDataStruct003C_t))

#define D_SMBUFF_BASE_ADDR_003D             ((sizeof(TbAP_VCActuatorOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct003D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_003D           (sizeof(msgIdDataStruct003D_t))

#define D_SMBUFF_BASE_ADDR_003E             ((sizeof(TbAP_VCTrajOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct003E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_003E           (sizeof(msgIdDataStruct003E_t))

#define D_SMBUFF_BASE_ADDR_003F             ((sizeof(TbAP_VCStateOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct003F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_003F           (sizeof(msgIdDataStruct003F_t))

#define D_SMBUFF_BASE_ADDR_0042             ((sizeof(US_S_PointMapGroup_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0042_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0042           (sizeof(msgIdDataStruct0042_t))

#define D_SMBUFF_BASE_ADDR_0043             ((sizeof(US_S_SnrDirEcho_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0043_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0043           (sizeof(msgIdDataStruct0043_t))

#define D_SMBUFF_BASE_ADDR_0044             ((sizeof(US_S_ZoneInfo_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0044_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0044           (sizeof(msgIdDataStruct0044_t))

#define D_SMBUFF_BASE_ADDR_0045             ((sizeof(US_S_BlockageBit_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0045_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0045           (sizeof(msgIdDataStruct0045_t))

#define D_SMBUFF_BASE_ADDR_0046             ((sizeof(US_S_USSConstantData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0046_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0046           (sizeof(msgIdDataStruct0046_t))

#define D_SMBUFF_BASE_ADDR_0047             ((sizeof(US_S_USSPeriodDiagData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0047_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0047           (sizeof(msgIdDataStruct0047_t))

#define D_SMBUFF_BASE_ADDR_0048             ((sizeof(US_S_USSErrorDiagData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0048_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0048           (sizeof(msgIdDataStruct0048_t))

#define D_SMBUFF_BASE_ADDR_004E             ((sizeof(IFOD_Outputs_CVPAMFDData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct004E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_004E           (sizeof(msgIdDataStruct004E_t))

#define D_SMBUFF_BASE_ADDR_0052             ((sizeof(US_S_MarriageSensorIDs_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0052_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0052           (sizeof(msgIdDataStruct0052_t))

#define D_SMBUFF_BASE_ADDR_0054             ((sizeof(TRSCtoDiagMgr_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0054_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0054           (sizeof(msgIdDataStruct0054_t))

#define D_SMBUFF_BASE_ADDR_0056             ((sizeof(TbAP_USSStateOut_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0056_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0056           (sizeof(msgIdDataStruct0056_t))

#define D_SMBUFF_BASE_ADDR_0059             ((sizeof(USS_PowerSelect_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0059_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0059           (sizeof(msgIdDataStruct0059_t))

#define D_SMBUFF_BASE_ADDR_0060             ((sizeof(US_S_USSDataCollectionData_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0060_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0060           (sizeof(msgIdDataStruct0060_t))

#define D_SMBUFF_BASE_ADDR_0061             ((sizeof(US_S_PointDistOutputBuff_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0061_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0061           (sizeof(msgIdDataStruct0061_t))

#define D_SMBUFF_BASE_ADDR_0062             ((sizeof(CpuLoadMcu2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0062_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0062           (sizeof(msgIdDataStruct0062_t))

#define D_SMBUFF_BASE_ADDR_0067             ((sizeof(IJobUSSObjectMapOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0067_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0067           (sizeof(msgIdDataStruct0067_t))

#define D_SMBUFF_BASE_ADDR_0068             ((sizeof(TbFA_ArbiterOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0068_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0068           (sizeof(msgIdDataStruct0068_t))

#define D_SMBUFF_BASE_ADDR_006B             ((sizeof(TbAP_DebugOut)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct006B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_006B           (sizeof(msgIdDataStruct006B_t))

#define D_SMBUFF_BASE_ADDR_006C             ((sizeof(WdgCheckpointStatus_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct006C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_006C           (sizeof(msgIdDataStruct006C_t))

#define D_SMBUFF_BASE_ADDR_006F             ((sizeof(uint32_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct006F_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_006F           (sizeof(msgIdDataStruct006F_t))

#define D_SMBUFF_BASE_ADDR_0071             ((sizeof(TbTHASmVc_DiagMgr_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0071_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0071           (sizeof(msgIdDataStruct0071_t))

#define D_SMBUFF_BASE_ADDR_007B             ((sizeof(IFOD_Outputs_Arbitration_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct007B_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_007B           (sizeof(msgIdDataStruct007B_t))

#define D_SMBUFF_BASE_ADDR_007C             ((sizeof(IDebug_FODObject_t )>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct007C_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_007C           (sizeof(msgIdDataStruct007C_t))

#define D_SMBUFF_BASE_ADDR_007D             ((sizeof(TbFA_USSStateOutput_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct007D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_007D           (sizeof(msgIdDataStruct007D_t))

#define D_SMBUFF_BASE_ADDR_007E             ((sizeof(TbFA_ResetKM_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct007E_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_007E           (sizeof(msgIdDataStruct007E_t))

#define D_SMBUFF_BASE_ADDR_0086             ((sizeof(TRSCSMVCtoDebugCAN_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0086_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0086           (sizeof(msgIdDataStruct0086_t))

#define D_SMBUFF_BASE_ADDR_0088             ((sizeof(US_S_CsmStateChangeReason_Type)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0088_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0088           (sizeof(msgIdDataStruct0088_t))

#define D_SMBUFF_BASE_ADDR_008A             ((sizeof(US_S_DebugMsg_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct008A_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_008A           (sizeof(msgIdDataStruct008A_t))

#define D_SMBUFF_BASE_ADDR_008D             ((sizeof(Error_Fault_MCU2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct008D_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_008D           (sizeof(msgIdDataStruct008D_t))

#define D_SMBUFF_BASE_ADDR_0091             ((sizeof(UssTunningData_mcu2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0091_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0091           (sizeof(msgIdDataStruct0091_t))

#define D_SMBUFF_BASE_ADDR_0092             ((sizeof(RunTimeStats_MCU2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0092_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0092           (sizeof(msgIdDataStruct0092_t))

#define D_SMBUFF_BASE_ADDR_0097             ((sizeof(StackUsage_MCU2_1_t)>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct0097_as[0].msgIdData_s : NULL)
#define D_SMBUFF_STRUCT_SIZE_0097           (sizeof(msgIdDataStruct0097_t))

#endif

#if defined(BUILD_MCU3_0)
/* Structure definition for signal handler data with CRC32 */
/* Declare shared memory buffers for above structures */

/* Shared memory buffer states */

/* Shared memory buffer base addresss and size of corresponding message id */
#endif

#if defined(BUILD_MCU3_1)
/* Structure definition for signal handler data with CRC32 */
/* Declare shared memory buffers for above structures */

/* Shared memory buffer states */

/* Shared memory buffer base addresss and size of corresponding message id */
#endif

#if defined(BUILD_C66x_1)
/* Structure definition for signal handler data with CRC32 */
/* Declare shared memory buffers for above structures */

/* Shared memory buffer states */

/* Shared memory buffer base addresss and size of corresponding message id */
#endif

#if defined(BUILD_C66x_2)
/* Structure definition for signal handler data with CRC32 */
/* Declare shared memory buffers for above structures */

/* Shared memory buffer states */

/* Shared memory buffer base addresss and size of corresponding message id */
#endif
#endif

/* Shared memory buffer data size (Size occuiped by data, no CRC32) */
#define D_SMBUFF_DATA_SIZE_0000             (sizeof(uint8_t))
#define D_SMBUFF_DATA_SIZE_0001             (sizeof(SvsToTHADet_t))
#define D_SMBUFF_DATA_SIZE_0002             (sizeof(SvsToVCAN_t))
#define D_SMBUFF_DATA_SIZE_0003             (sizeof(SVStoTRSC_t))
#define D_SMBUFF_DATA_SIZE_0004             (sizeof(ScreenRequest_t))
#define D_SMBUFF_DATA_SIZE_0005             (sizeof(SvsToTHA_t))
#define D_SMBUFF_DATA_SIZE_0006             (sizeof(ScreenResponse_t))
#define D_SMBUFF_DATA_SIZE_0007             (sizeof(ME_VehInp_to_IpcSignals_t))
#define D_SMBUFF_DATA_SIZE_0008             (sizeof(ErrorMgr_ErrorCommPack_2_0_QM))
#define D_SMBUFF_DATA_SIZE_0009             (sizeof(ErrorMgr_ErrorCommPack_2_0_B))
#define D_SMBUFF_DATA_SIZE_000A             (sizeof(ErrorMgr_ErrorCommPack_2_1_QM))
#define D_SMBUFF_DATA_SIZE_000B             (sizeof(ErrorMgr_ErrorCommPack_2_1_B))
#define D_SMBUFF_DATA_SIZE_000C             (sizeof(ErrorMgr_ErrorCommPack_QNX_QM))
#define D_SMBUFF_DATA_SIZE_000D             (sizeof(ErrorMgr_ErrorCommPack_QNX_B))
#define D_SMBUFF_DATA_SIZE_000E             (sizeof(TRSC_Inputs_from_TrailerDetection_t))
#define D_SMBUFF_DATA_SIZE_000F             (sizeof(MeDLD_e_RrCamSts_t))
#define D_SMBUFF_DATA_SIZE_0010             (sizeof(ME_VehOut_TRSC_t))
#define D_SMBUFF_DATA_SIZE_0011             (sizeof(SVStoTRSCSMVC_t))
#define D_SMBUFF_DATA_SIZE_0012             (sizeof(TRSCSMVCtoSVS_t))
#define D_SMBUFF_DATA_SIZE_0013             (sizeof(Detection_Inputs_from_TRSC_t))
#define D_SMBUFF_DATA_SIZE_0014             (sizeof(SSM_2_0_CoreStatus))
#define D_SMBUFF_DATA_SIZE_0015             (sizeof(SSM_2_1_CoreStatus))
#define D_SMBUFF_DATA_SIZE_0016             (sizeof(SSM_QNX_CoreStatus))
#define D_SMBUFF_DATA_SIZE_0017             (sizeof(SSM_SystemState))
#define D_SMBUFF_DATA_SIZE_0018             (sizeof(CalDataProvider_MPU_1_0_Def))
#define D_SMBUFF_DATA_SIZE_0019             (sizeof(CalDataProvider_MCU_2_0_Def))
#define D_SMBUFF_DATA_SIZE_001A             (sizeof(CalDataProvider_MCU_2_1_Def))
#define D_SMBUFF_DATA_SIZE_001B             (sizeof(TbSVS_e_SVSCalibSMToAlgoCamCalib_t))
#define D_SMBUFF_DATA_SIZE_001C             (sizeof(TbSVS_e_SVSCalibAlgoToSMCamCalib_t))
#define D_SMBUFF_DATA_SIZE_001D             (sizeof(TbSVS_S_SVSCamCurrentCalibDataToNVM_t))
#define D_SMBUFF_DATA_SIZE_001E             (sizeof(TbSVS_S_SVSCamOCCalibDataToNVM_t))
#define D_SMBUFF_DATA_SIZE_001F             (sizeof(TbSVS_S_SVSCamSCCalibDataToNVM_t))
#define D_SMBUFF_DATA_SIZE_0020             (sizeof(TbSVS_S_SVSCamEOLCalibDataToNVM_t))
#define D_SMBUFF_DATA_SIZE_0021             (sizeof(TbSVS_e_SVSOutputToDiagMgrCamCalib_t))
#define D_SMBUFF_DATA_SIZE_0022             (sizeof(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t))
#define D_SMBUFF_DATA_SIZE_0023             (sizeof(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t))
#define D_SMBUFF_DATA_SIZE_0024             (sizeof(ME_Proxi_to_IpcSignals_t))
#define D_SMBUFF_DATA_SIZE_0025             (sizeof(JobTHADetOutput_t))
#define D_SMBUFF_DATA_SIZE_0026             (sizeof(TbAP_APSMPAOut_t))
#define D_SMBUFF_DATA_SIZE_0027             (sizeof(TbTHASmVc_FeatureOutputs_t))
#define D_SMBUFF_DATA_SIZE_0028             (sizeof(IFPAInfoToHMI_t))
#define D_SMBUFF_DATA_SIZE_0029             (sizeof(IFPAInfoToVC_t))
#define D_SMBUFF_DATA_SIZE_002A             (sizeof(IFPAInfoToPLD_t))
#define D_SMBUFF_DATA_SIZE_002B             (sizeof(IHMIInfoToFPA_t))
#define D_SMBUFF_DATA_SIZE_002C             (sizeof(IJobPLDOutput_t))
#define D_SMBUFF_DATA_SIZE_002D             (sizeof(IUPASensorDataV2_t))
#define D_SMBUFF_DATA_SIZE_002E             (sizeof(IPathPlannerState_t))
#define D_SMBUFF_DATA_SIZE_002F             (sizeof(IKinematicData_t))
#define D_SMBUFF_DATA_SIZE_0030             (sizeof(ExtY_Kinematic_T))
#define D_SMBUFF_DATA_SIZE_0031             (sizeof(IParkingSlotInformation_t))
#define D_SMBUFF_DATA_SIZE_0032             (sizeof(IJobFPAOutput_t))
#define D_SMBUFF_DATA_SIZE_0033             (sizeof(IAutoParkingState_t))
#define D_SMBUFF_DATA_SIZE_0034             (sizeof(IParkingSlotID_t))
#define D_SMBUFF_DATA_SIZE_0035             (sizeof(NFCD_Output))
#define D_SMBUFF_DATA_SIZE_0036             (sizeof(MOT_Output))
#define D_SMBUFF_DATA_SIZE_0037             (sizeof(TbAP_DriveAssistStatOut_t))
#define D_SMBUFF_DATA_SIZE_0038             (sizeof(TbAP_SMDAInternalOut_t))
#define D_SMBUFF_DATA_SIZE_0039             (sizeof(TbAP_SMPAInternalOut_t))
#define D_SMBUFF_DATA_SIZE_003A             (sizeof(TbAP_FPAWarnOut_t))
#define D_SMBUFF_DATA_SIZE_003B             (sizeof(TbAP_RPAWarnOut_t))
#define D_SMBUFF_DATA_SIZE_003C             (sizeof(TbAP_PAStateOut_t))
#define D_SMBUFF_DATA_SIZE_003D             (sizeof(TbAP_VCActuatorOut_t))
#define D_SMBUFF_DATA_SIZE_003E             (sizeof(TbAP_VCTrajOut_t))
#define D_SMBUFF_DATA_SIZE_003F             (sizeof(TbAP_VCStateOut_t))
#define D_SMBUFF_DATA_SIZE_0040             (sizeof(FID_STRUCT_QM))
#define D_SMBUFF_DATA_SIZE_0041             (sizeof(FID_STRUCT_B))
#define D_SMBUFF_DATA_SIZE_0042             (sizeof(US_S_PointMapGroup_t))
#define D_SMBUFF_DATA_SIZE_0043             (sizeof(US_S_SnrDirEcho_t))
#define D_SMBUFF_DATA_SIZE_0044             (sizeof(US_S_ZoneInfo_t))
#define D_SMBUFF_DATA_SIZE_0045             (sizeof(US_S_BlockageBit_t))
#define D_SMBUFF_DATA_SIZE_0046             (sizeof(US_S_USSConstantData_t))
#define D_SMBUFF_DATA_SIZE_0047             (sizeof(US_S_USSPeriodDiagData_t))
#define D_SMBUFF_DATA_SIZE_0048             (sizeof(US_S_USSErrorDiagData_t))
#define D_SMBUFF_DATA_SIZE_0049             (sizeof(USS_Curr_Volt_Monitor_t))
#define D_SMBUFF_DATA_SIZE_004A             (sizeof(THARelated_ScreenReq_t))
#define D_SMBUFF_DATA_SIZE_004B             (sizeof(Svs_CamEepromDataArray_t ))
#define D_SMBUFF_DATA_SIZE_004C             (sizeof(DiagToSVS_t))
#define D_SMBUFF_DATA_SIZE_004D             (sizeof(SVSToDiag_t))
#define D_SMBUFF_DATA_SIZE_004E             (sizeof(IFOD_Outputs_CVPAMFDData_t))
#define D_SMBUFF_DATA_SIZE_004F             (sizeof(LMD_Outputs_CVPAMFDData2_t))
#define D_SMBUFF_DATA_SIZE_0050             (sizeof(CAM_Curr_Volt_Monitor_t))
#define D_SMBUFF_DATA_SIZE_0051             (sizeof(CAM_CS_Curr_Monitor_t))
#define D_SMBUFF_DATA_SIZE_0052             (sizeof(US_S_MarriageSensorIDs_t))
#define D_SMBUFF_DATA_SIZE_0053             (sizeof(US_S_MarriageSensorIDs_t))
#define D_SMBUFF_DATA_SIZE_0054             (sizeof(TRSCtoDiagMgr_t))
#define D_SMBUFF_DATA_SIZE_0055             (sizeof(TrailerDetection_Output_DID_t))
#define D_SMBUFF_DATA_SIZE_0056             (sizeof(TbAP_USSStateOut_t))
#define D_SMBUFF_DATA_SIZE_0057             (sizeof(HMIInfoToAP_t))
#define D_SMBUFF_DATA_SIZE_0058             (sizeof(DiagToParkAssist_t))
#define D_SMBUFF_DATA_SIZE_0059             (sizeof(USS_PowerSelect_t))
#define D_SMBUFF_DATA_SIZE_005A             (sizeof(USS_PowerSelect_t))
#define D_SMBUFF_DATA_SIZE_005B             (sizeof(ME_ProxiToMPU1_0_Def_t))
#define D_SMBUFF_DATA_SIZE_005C             (sizeof(ME_ProxiToMCU2_0_Def_t))
#define D_SMBUFF_DATA_SIZE_005D             (sizeof(ME_ProxiToMCU2_1_Def_t))
#define D_SMBUFF_DATA_SIZE_005E             (sizeof(TrscDebug_ScrRes_t))
#define D_SMBUFF_DATA_SIZE_005F             (sizeof(TRSCDebug_ScrReq_t))
#define D_SMBUFF_DATA_SIZE_0060             (sizeof(US_S_USSDataCollectionData_t))
#define D_SMBUFF_DATA_SIZE_0061             (sizeof(US_S_PointDistOutputBuff_t))
#define D_SMBUFF_DATA_SIZE_0062             (sizeof(CpuLoadMcu2_1_t))
#define D_SMBUFF_DATA_SIZE_0063             (sizeof(CpuLoadMcu2_0_t))
#define D_SMBUFF_DATA_SIZE_0064             (sizeof(TbNVM_ReadParam))
#define D_SMBUFF_DATA_SIZE_0065             (sizeof(ME_CanDebugRIDStatus_t))
#define D_SMBUFF_DATA_SIZE_0066             (sizeof(SVS_NVMData_t))
#define D_SMBUFF_DATA_SIZE_0067             (sizeof(IJobUSSObjectMapOutput_t))
#define D_SMBUFF_DATA_SIZE_0068             (sizeof(TbFA_ArbiterOutput_t))
#define D_SMBUFF_DATA_SIZE_0069             (sizeof(SVS_NVMData_t))
#define D_SMBUFF_DATA_SIZE_006A             (sizeof(USS_Calibration_Data_t))
#define D_SMBUFF_DATA_SIZE_006B             (sizeof(TbAP_DebugOut))
#define D_SMBUFF_DATA_SIZE_006C             (sizeof(WdgCheckpointStatus_t))
#define D_SMBUFF_DATA_SIZE_006D             (sizeof(WdgCheckpointStatus_t))
#define D_SMBUFF_DATA_SIZE_006E             (sizeof(WdgCheckpointStatus_t))
#define D_SMBUFF_DATA_SIZE_006F             (sizeof(uint32_t))
#define D_SMBUFF_DATA_SIZE_0070             (sizeof(LMD_Lane_Outputs_s))
#define D_SMBUFF_DATA_SIZE_0071             (sizeof(TbTHASmVc_DiagMgr_t))
#define D_SMBUFF_DATA_SIZE_0072             (sizeof(THA_Calibration_data_MCU2_1_t))
#define D_SMBUFF_DATA_SIZE_0073             (sizeof(THA_Calibration_data_MPU1_0_t))
#define D_SMBUFF_DATA_SIZE_0074             (sizeof(TRSC_Calibration_data_MCU2_1_t))
#define D_SMBUFF_DATA_SIZE_0075             (sizeof(APA_Calibration_data_MPU1_0_t))
#define D_SMBUFF_DATA_SIZE_0076             (sizeof(APA_Calibration_data_MCU2_1_t))
#define D_SMBUFF_DATA_SIZE_0077             (sizeof(SVS_Calibration_data_t))
#define D_SMBUFF_DATA_SIZE_0078             (sizeof(FOD_Calibration_data_t))
#define D_SMBUFF_DATA_SIZE_0079             (sizeof(LMD_Calibration_data_t))
#define D_SMBUFF_DATA_SIZE_007A             (sizeof(TRSC_Calibration_data_MPU1_0_t))
#define D_SMBUFF_DATA_SIZE_007B             (sizeof(IFOD_Outputs_Arbitration_t))
#define D_SMBUFF_DATA_SIZE_007C             (sizeof(IDebug_FODObject_t ))
#define D_SMBUFF_DATA_SIZE_007D             (sizeof(TbFA_USSStateOutput_t))
#define D_SMBUFF_DATA_SIZE_007E             (sizeof(TbFA_ResetKM_t))
#define D_SMBUFF_DATA_SIZE_007F             (sizeof(ME_Proxi_MPU1_0_to_MCU1_0_t))
#define D_SMBUFF_DATA_SIZE_0080             (sizeof(TbSVS_e_SVSCalibSMToHmi_t))
#define D_SMBUFF_DATA_SIZE_0081             (sizeof(USS_Calibration_data_2_t))
#define D_SMBUFF_DATA_SIZE_0082             (sizeof(Cam_and_Ser_EN_Status_t))
#define D_SMBUFF_DATA_SIZE_0083             (sizeof(TrailerDetection_Output_HMI_t ))
#define D_SMBUFF_DATA_SIZE_0084             (sizeof(JobDLDOutput_t))
#define D_SMBUFF_DATA_SIZE_0085             (sizeof(INVMSignalManager_t))
#define D_SMBUFF_DATA_SIZE_0086             (sizeof(TRSCSMVCtoDebugCAN_t))
#define D_SMBUFF_DATA_SIZE_0087             (sizeof(TimeManagerProxy_TimeStamp_t))
#define D_SMBUFF_DATA_SIZE_0088             (sizeof(US_S_CsmStateChangeReason_Type))
#define D_SMBUFF_DATA_SIZE_0089             (sizeof(KeepAliveResponse_t))
#define D_SMBUFF_DATA_SIZE_008A             (sizeof(US_S_DebugMsg_t))
#define D_SMBUFF_DATA_SIZE_008B             (sizeof(CAM_select_info_t))
#define D_SMBUFF_DATA_SIZE_008C             (sizeof(Error_Fault_MCU2_0_t))
#define D_SMBUFF_DATA_SIZE_008D             (sizeof(Error_Fault_MCU2_1_t))
#define D_SMBUFF_DATA_SIZE_008E             (sizeof(Error_Fault_MPU1_0_t))
#define D_SMBUFF_DATA_SIZE_008F             (sizeof(TRSC_CalibrationClear_t))
#define D_SMBUFF_DATA_SIZE_0090             (sizeof(UssTunningData_mcu1_0_t))
#define D_SMBUFF_DATA_SIZE_0091             (sizeof(UssTunningData_mcu2_1_t))
#define D_SMBUFF_DATA_SIZE_0092             (sizeof(RunTimeStats_MCU2_1_t))
#define D_SMBUFF_DATA_SIZE_0093             (sizeof(RunTimeStats_MCU2_0_t))
#define D_SMBUFF_DATA_SIZE_0094             (sizeof(PerformanceStatsEnable_t))
#define D_SMBUFF_DATA_SIZE_0095             (sizeof(RunTimeStats_MPU1_0_t))
#define D_SMBUFF_DATA_SIZE_0096             (sizeof(CamHotplugStatus_t))
#define D_SMBUFF_DATA_SIZE_0097             (sizeof(StackUsage_MCU2_1_t))
#define D_SMBUFF_DATA_SIZE_0098             (sizeof(StackUsage_MCU2_0_t))

/* ===========================================================================
*
* Private variables
*
* ========================================================================= */
/* Counter variable for each Message ID */

#if defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0000_u32;
#define D_IPC_MSG_ID_CNT_0000   (&v_ipcMsgIdCnt_0000_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0001_u32;
#define D_IPC_MSG_ID_CNT_0001   (&v_ipcMsgIdCnt_0001_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0002_u32;
#define D_IPC_MSG_ID_CNT_0002   (&v_ipcMsgIdCnt_0002_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0003_u32;
#define D_IPC_MSG_ID_CNT_0003   (&v_ipcMsgIdCnt_0003_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0004_u32;
#define D_IPC_MSG_ID_CNT_0004   (&v_ipcMsgIdCnt_0004_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0005_u32;
#define D_IPC_MSG_ID_CNT_0005   (&v_ipcMsgIdCnt_0005_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0006_u32;
#define D_IPC_MSG_ID_CNT_0006   (&v_ipcMsgIdCnt_0006_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0007_u32;
#define D_IPC_MSG_ID_CNT_0007   (&v_ipcMsgIdCnt_0007_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0008_u32;
#define D_IPC_MSG_ID_CNT_0008   (&v_ipcMsgIdCnt_0008_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0009_u32;
#define D_IPC_MSG_ID_CNT_0009   (&v_ipcMsgIdCnt_0009_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_000A_u32;
#define D_IPC_MSG_ID_CNT_000A   (&v_ipcMsgIdCnt_000A_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_000B_u32;
#define D_IPC_MSG_ID_CNT_000B   (&v_ipcMsgIdCnt_000B_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_000C_u32;
#define D_IPC_MSG_ID_CNT_000C   (&v_ipcMsgIdCnt_000C_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_000D_u32;
#define D_IPC_MSG_ID_CNT_000D   (&v_ipcMsgIdCnt_000D_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_000E_u32;
#define D_IPC_MSG_ID_CNT_000E   (&v_ipcMsgIdCnt_000E_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_000F_u32;
#define D_IPC_MSG_ID_CNT_000F   (&v_ipcMsgIdCnt_000F_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0010_u32;
#define D_IPC_MSG_ID_CNT_0010   (&v_ipcMsgIdCnt_0010_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0011_u32;
#define D_IPC_MSG_ID_CNT_0011   (&v_ipcMsgIdCnt_0011_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0012_u32;
#define D_IPC_MSG_ID_CNT_0012   (&v_ipcMsgIdCnt_0012_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0013_u32;
#define D_IPC_MSG_ID_CNT_0013   (&v_ipcMsgIdCnt_0013_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0014_u32;
#define D_IPC_MSG_ID_CNT_0014   (&v_ipcMsgIdCnt_0014_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0015_u32;
#define D_IPC_MSG_ID_CNT_0015   (&v_ipcMsgIdCnt_0015_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0016_u32;
#define D_IPC_MSG_ID_CNT_0016   (&v_ipcMsgIdCnt_0016_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0017_u32;
#define D_IPC_MSG_ID_CNT_0017   (&v_ipcMsgIdCnt_0017_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0018_u32;
#define D_IPC_MSG_ID_CNT_0018   (&v_ipcMsgIdCnt_0018_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0019_u32;
#define D_IPC_MSG_ID_CNT_0019   (&v_ipcMsgIdCnt_0019_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_001A_u32;
#define D_IPC_MSG_ID_CNT_001A   (&v_ipcMsgIdCnt_001A_u32)
#endif

#if defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_001B_u32;
#define D_IPC_MSG_ID_CNT_001B   (&v_ipcMsgIdCnt_001B_u32)
#endif

#if defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_001C_u32;
#define D_IPC_MSG_ID_CNT_001C   (&v_ipcMsgIdCnt_001C_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_001D_u32;
#define D_IPC_MSG_ID_CNT_001D   (&v_ipcMsgIdCnt_001D_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_001E_u32;
#define D_IPC_MSG_ID_CNT_001E   (&v_ipcMsgIdCnt_001E_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_001F_u32;
#define D_IPC_MSG_ID_CNT_001F   (&v_ipcMsgIdCnt_001F_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0020_u32;
#define D_IPC_MSG_ID_CNT_0020   (&v_ipcMsgIdCnt_0020_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0021_u32;
#define D_IPC_MSG_ID_CNT_0021   (&v_ipcMsgIdCnt_0021_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0022_u32;
#define D_IPC_MSG_ID_CNT_0022   (&v_ipcMsgIdCnt_0022_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0023_u32;
#define D_IPC_MSG_ID_CNT_0023   (&v_ipcMsgIdCnt_0023_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0024_u32;
#define D_IPC_MSG_ID_CNT_0024   (&v_ipcMsgIdCnt_0024_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0025_u32;
#define D_IPC_MSG_ID_CNT_0025   (&v_ipcMsgIdCnt_0025_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0026_u32;
#define D_IPC_MSG_ID_CNT_0026   (&v_ipcMsgIdCnt_0026_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0027_u32;
#define D_IPC_MSG_ID_CNT_0027   (&v_ipcMsgIdCnt_0027_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0028_u32;
#define D_IPC_MSG_ID_CNT_0028   (&v_ipcMsgIdCnt_0028_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0029_u32;
#define D_IPC_MSG_ID_CNT_0029   (&v_ipcMsgIdCnt_0029_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_002A_u32;
#define D_IPC_MSG_ID_CNT_002A   (&v_ipcMsgIdCnt_002A_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_002B_u32;
#define D_IPC_MSG_ID_CNT_002B   (&v_ipcMsgIdCnt_002B_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_002C_u32;
#define D_IPC_MSG_ID_CNT_002C   (&v_ipcMsgIdCnt_002C_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_002D_u32;
#define D_IPC_MSG_ID_CNT_002D   (&v_ipcMsgIdCnt_002D_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_002E_u32;
#define D_IPC_MSG_ID_CNT_002E   (&v_ipcMsgIdCnt_002E_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_002F_u32;
#define D_IPC_MSG_ID_CNT_002F   (&v_ipcMsgIdCnt_002F_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0030_u32;
#define D_IPC_MSG_ID_CNT_0030   (&v_ipcMsgIdCnt_0030_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0031_u32;
#define D_IPC_MSG_ID_CNT_0031   (&v_ipcMsgIdCnt_0031_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0032_u32;
#define D_IPC_MSG_ID_CNT_0032   (&v_ipcMsgIdCnt_0032_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0033_u32;
#define D_IPC_MSG_ID_CNT_0033   (&v_ipcMsgIdCnt_0033_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0034_u32;
#define D_IPC_MSG_ID_CNT_0034   (&v_ipcMsgIdCnt_0034_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0035_u32;
#define D_IPC_MSG_ID_CNT_0035   (&v_ipcMsgIdCnt_0035_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0036_u32;
#define D_IPC_MSG_ID_CNT_0036   (&v_ipcMsgIdCnt_0036_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0037_u32;
#define D_IPC_MSG_ID_CNT_0037   (&v_ipcMsgIdCnt_0037_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0038_u32;
#define D_IPC_MSG_ID_CNT_0038   (&v_ipcMsgIdCnt_0038_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0039_u32;
#define D_IPC_MSG_ID_CNT_0039   (&v_ipcMsgIdCnt_0039_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_003A_u32;
#define D_IPC_MSG_ID_CNT_003A   (&v_ipcMsgIdCnt_003A_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_003B_u32;
#define D_IPC_MSG_ID_CNT_003B   (&v_ipcMsgIdCnt_003B_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_003C_u32;
#define D_IPC_MSG_ID_CNT_003C   (&v_ipcMsgIdCnt_003C_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_003D_u32;
#define D_IPC_MSG_ID_CNT_003D   (&v_ipcMsgIdCnt_003D_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_003E_u32;
#define D_IPC_MSG_ID_CNT_003E   (&v_ipcMsgIdCnt_003E_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_003F_u32;
#define D_IPC_MSG_ID_CNT_003F   (&v_ipcMsgIdCnt_003F_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0040_u32;
#define D_IPC_MSG_ID_CNT_0040   (&v_ipcMsgIdCnt_0040_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0041_u32;
#define D_IPC_MSG_ID_CNT_0041   (&v_ipcMsgIdCnt_0041_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0042_u32;
#define D_IPC_MSG_ID_CNT_0042   (&v_ipcMsgIdCnt_0042_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0043_u32;
#define D_IPC_MSG_ID_CNT_0043   (&v_ipcMsgIdCnt_0043_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0044_u32;
#define D_IPC_MSG_ID_CNT_0044   (&v_ipcMsgIdCnt_0044_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0045_u32;
#define D_IPC_MSG_ID_CNT_0045   (&v_ipcMsgIdCnt_0045_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0046_u32;
#define D_IPC_MSG_ID_CNT_0046   (&v_ipcMsgIdCnt_0046_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0047_u32;
#define D_IPC_MSG_ID_CNT_0047   (&v_ipcMsgIdCnt_0047_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0048_u32;
#define D_IPC_MSG_ID_CNT_0048   (&v_ipcMsgIdCnt_0048_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0049_u32;
#define D_IPC_MSG_ID_CNT_0049   (&v_ipcMsgIdCnt_0049_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_004A_u32;
#define D_IPC_MSG_ID_CNT_004A   (&v_ipcMsgIdCnt_004A_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_004B_u32;
#define D_IPC_MSG_ID_CNT_004B   (&v_ipcMsgIdCnt_004B_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_004C_u32;
#define D_IPC_MSG_ID_CNT_004C   (&v_ipcMsgIdCnt_004C_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_004D_u32;
#define D_IPC_MSG_ID_CNT_004D   (&v_ipcMsgIdCnt_004D_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_004E_u32;
#define D_IPC_MSG_ID_CNT_004E   (&v_ipcMsgIdCnt_004E_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_004F_u32;
#define D_IPC_MSG_ID_CNT_004F   (&v_ipcMsgIdCnt_004F_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0050_u32;
#define D_IPC_MSG_ID_CNT_0050   (&v_ipcMsgIdCnt_0050_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0051_u32;
#define D_IPC_MSG_ID_CNT_0051   (&v_ipcMsgIdCnt_0051_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0052_u32;
#define D_IPC_MSG_ID_CNT_0052   (&v_ipcMsgIdCnt_0052_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0053_u32;
#define D_IPC_MSG_ID_CNT_0053   (&v_ipcMsgIdCnt_0053_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0054_u32;
#define D_IPC_MSG_ID_CNT_0054   (&v_ipcMsgIdCnt_0054_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0055_u32;
#define D_IPC_MSG_ID_CNT_0055   (&v_ipcMsgIdCnt_0055_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0056_u32;
#define D_IPC_MSG_ID_CNT_0056   (&v_ipcMsgIdCnt_0056_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0057_u32;
#define D_IPC_MSG_ID_CNT_0057   (&v_ipcMsgIdCnt_0057_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0058_u32;
#define D_IPC_MSG_ID_CNT_0058   (&v_ipcMsgIdCnt_0058_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0059_u32;
#define D_IPC_MSG_ID_CNT_0059   (&v_ipcMsgIdCnt_0059_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_005A_u32;
#define D_IPC_MSG_ID_CNT_005A   (&v_ipcMsgIdCnt_005A_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_005B_u32;
#define D_IPC_MSG_ID_CNT_005B   (&v_ipcMsgIdCnt_005B_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_005C_u32;
#define D_IPC_MSG_ID_CNT_005C   (&v_ipcMsgIdCnt_005C_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_005D_u32;
#define D_IPC_MSG_ID_CNT_005D   (&v_ipcMsgIdCnt_005D_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_005E_u32;
#define D_IPC_MSG_ID_CNT_005E   (&v_ipcMsgIdCnt_005E_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_005F_u32;
#define D_IPC_MSG_ID_CNT_005F   (&v_ipcMsgIdCnt_005F_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0060_u32;
#define D_IPC_MSG_ID_CNT_0060   (&v_ipcMsgIdCnt_0060_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0061_u32;
#define D_IPC_MSG_ID_CNT_0061   (&v_ipcMsgIdCnt_0061_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0062_u32;
#define D_IPC_MSG_ID_CNT_0062   (&v_ipcMsgIdCnt_0062_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0063_u32;
#define D_IPC_MSG_ID_CNT_0063   (&v_ipcMsgIdCnt_0063_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0064_u32;
#define D_IPC_MSG_ID_CNT_0064   (&v_ipcMsgIdCnt_0064_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0065_u32;
#define D_IPC_MSG_ID_CNT_0065   (&v_ipcMsgIdCnt_0065_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0066_u32;
#define D_IPC_MSG_ID_CNT_0066   (&v_ipcMsgIdCnt_0066_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0067_u32;
#define D_IPC_MSG_ID_CNT_0067   (&v_ipcMsgIdCnt_0067_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0068_u32;
#define D_IPC_MSG_ID_CNT_0068   (&v_ipcMsgIdCnt_0068_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0069_u32;
#define D_IPC_MSG_ID_CNT_0069   (&v_ipcMsgIdCnt_0069_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_006A_u32;
#define D_IPC_MSG_ID_CNT_006A   (&v_ipcMsgIdCnt_006A_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_006B_u32;
#define D_IPC_MSG_ID_CNT_006B   (&v_ipcMsgIdCnt_006B_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_006C_u32;
#define D_IPC_MSG_ID_CNT_006C   (&v_ipcMsgIdCnt_006C_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_006D_u32;
#define D_IPC_MSG_ID_CNT_006D   (&v_ipcMsgIdCnt_006D_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_006E_u32;
#define D_IPC_MSG_ID_CNT_006E   (&v_ipcMsgIdCnt_006E_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_006F_u32;
#define D_IPC_MSG_ID_CNT_006F   (&v_ipcMsgIdCnt_006F_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0070_u32;
#define D_IPC_MSG_ID_CNT_0070   (&v_ipcMsgIdCnt_0070_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0071_u32;
#define D_IPC_MSG_ID_CNT_0071   (&v_ipcMsgIdCnt_0071_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0072_u32;
#define D_IPC_MSG_ID_CNT_0072   (&v_ipcMsgIdCnt_0072_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0073_u32;
#define D_IPC_MSG_ID_CNT_0073   (&v_ipcMsgIdCnt_0073_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0074_u32;
#define D_IPC_MSG_ID_CNT_0074   (&v_ipcMsgIdCnt_0074_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0075_u32;
#define D_IPC_MSG_ID_CNT_0075   (&v_ipcMsgIdCnt_0075_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0076_u32;
#define D_IPC_MSG_ID_CNT_0076   (&v_ipcMsgIdCnt_0076_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0077_u32;
#define D_IPC_MSG_ID_CNT_0077   (&v_ipcMsgIdCnt_0077_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0078_u32;
#define D_IPC_MSG_ID_CNT_0078   (&v_ipcMsgIdCnt_0078_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0079_u32;
#define D_IPC_MSG_ID_CNT_0079   (&v_ipcMsgIdCnt_0079_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_007A_u32;
#define D_IPC_MSG_ID_CNT_007A   (&v_ipcMsgIdCnt_007A_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_007B_u32;
#define D_IPC_MSG_ID_CNT_007B   (&v_ipcMsgIdCnt_007B_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_007C_u32;
#define D_IPC_MSG_ID_CNT_007C   (&v_ipcMsgIdCnt_007C_u32)
#endif

#if defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_007D_u32;
#define D_IPC_MSG_ID_CNT_007D   (&v_ipcMsgIdCnt_007D_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_007E_u32;
#define D_IPC_MSG_ID_CNT_007E   (&v_ipcMsgIdCnt_007E_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_007F_u32;
#define D_IPC_MSG_ID_CNT_007F   (&v_ipcMsgIdCnt_007F_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0080_u32;
#define D_IPC_MSG_ID_CNT_0080   (&v_ipcMsgIdCnt_0080_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0081_u32;
#define D_IPC_MSG_ID_CNT_0081   (&v_ipcMsgIdCnt_0081_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0082_u32;
#define D_IPC_MSG_ID_CNT_0082   (&v_ipcMsgIdCnt_0082_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0083_u32;
#define D_IPC_MSG_ID_CNT_0083   (&v_ipcMsgIdCnt_0083_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0084_u32;
#define D_IPC_MSG_ID_CNT_0084   (&v_ipcMsgIdCnt_0084_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0085_u32;
#define D_IPC_MSG_ID_CNT_0085   (&v_ipcMsgIdCnt_0085_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0086_u32;
#define D_IPC_MSG_ID_CNT_0086   (&v_ipcMsgIdCnt_0086_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0087_u32;
#define D_IPC_MSG_ID_CNT_0087   (&v_ipcMsgIdCnt_0087_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0088_u32;
#define D_IPC_MSG_ID_CNT_0088   (&v_ipcMsgIdCnt_0088_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static uint32_t v_ipcMsgIdCnt_0089_u32;
#define D_IPC_MSG_ID_CNT_0089   (&v_ipcMsgIdCnt_0089_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_008A_u32;
#define D_IPC_MSG_ID_CNT_008A   (&v_ipcMsgIdCnt_008A_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_008B_u32;
#define D_IPC_MSG_ID_CNT_008B   (&v_ipcMsgIdCnt_008B_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_008C_u32;
#define D_IPC_MSG_ID_CNT_008C   (&v_ipcMsgIdCnt_008C_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_008D_u32;
#define D_IPC_MSG_ID_CNT_008D   (&v_ipcMsgIdCnt_008D_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_008E_u32;
#define D_IPC_MSG_ID_CNT_008E   (&v_ipcMsgIdCnt_008E_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_008F_u32;
#define D_IPC_MSG_ID_CNT_008F   (&v_ipcMsgIdCnt_008F_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0090_u32;
#define D_IPC_MSG_ID_CNT_0090   (&v_ipcMsgIdCnt_0090_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0091_u32;
#define D_IPC_MSG_ID_CNT_0091   (&v_ipcMsgIdCnt_0091_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0092_u32;
#define D_IPC_MSG_ID_CNT_0092   (&v_ipcMsgIdCnt_0092_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0093_u32;
#define D_IPC_MSG_ID_CNT_0093   (&v_ipcMsgIdCnt_0093_u32)
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static uint32_t v_ipcMsgIdCnt_0094_u32;
#define D_IPC_MSG_ID_CNT_0094   (&v_ipcMsgIdCnt_0094_u32)
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0095_u32;
#define D_IPC_MSG_ID_CNT_0095   (&v_ipcMsgIdCnt_0095_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0)
static uint32_t v_ipcMsgIdCnt_0096_u32;
#define D_IPC_MSG_ID_CNT_0096   (&v_ipcMsgIdCnt_0096_u32)
#endif

#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0097_u32;
#define D_IPC_MSG_ID_CNT_0097   (&v_ipcMsgIdCnt_0097_u32)
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU1_0)
static uint32_t v_ipcMsgIdCnt_0098_u32;
#define D_IPC_MSG_ID_CNT_0098   (&v_ipcMsgIdCnt_0098_u32)
#endif

/* ===========================================================================
 *
 *   Global Data Types
 *
 * ======================================================================== */
/* Configuration for Tx messages */
#if (D_NUMBER_OF_TX_MESSAGES > 0)

const ipcLutAttrTx_t V_ipcLutAttrTx_as[D_NUMBER_OF_TX_MESSAGES] = {
    /*          MSG_ID                                                               (                       MPU1_0            MCU1_0            MCU2_0            MCU2_1            MCU3_0            MCU3_1            C66X_1            C66X_2            Resv              Resv        )       Base address,             smBuffSize,                 DataSize,       buffCnt,  MessageIdCntr,         smBuffStateAddr,       */
#if defined(BUILD_MPU1_0)
    {  (uint16_t)e_IpcMsgId_data_UnknownMsg_t                                               ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_0000, D_SMBUFF_STRUCT_SIZE_0000, D_SMBUFF_DATA_SIZE_0000, 3, D_IPC_MSG_ID_CNT_0000, &msgIdSmBuffState0000_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpScreenResponse_ScreenResponse_t                               ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0006, D_SMBUFF_STRUCT_SIZE_0006, D_SMBUFF_DATA_SIZE_0006, 3, D_IPC_MSG_ID_CNT_0006, &msgIdSmBuffState0006_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_000C, D_SMBUFF_STRUCT_SIZE_000C, D_SMBUFF_DATA_SIZE_000C, 3, D_IPC_MSG_ID_CNT_000C, &msgIdSmBuffState000C_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_000D, D_SMBUFF_STRUCT_SIZE_000D, D_SMBUFF_DATA_SIZE_000D, 3, D_IPC_MSG_ID_CNT_000D, &msgIdSmBuffState000D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t               ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_000E, D_SMBUFF_STRUCT_SIZE_000E, D_SMBUFF_DATA_SIZE_000E, 3, D_IPC_MSG_ID_CNT_000E, &msgIdSmBuffState000E_as[0]  },
    {  (uint16_t)e_IpcMsgId_data_MeDLD_e_RrCamSts_t                                         ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_000F, D_SMBUFF_STRUCT_SIZE_000F, D_SMBUFF_DATA_SIZE_000F, 3, D_IPC_MSG_ID_CNT_000F, &msgIdSmBuffState000F_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_QNX_State_QNX                                        ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0016, D_SMBUFF_STRUCT_SIZE_0016, D_SMBUFF_DATA_SIZE_0016, 3, D_IPC_MSG_ID_CNT_0016, &msgIdSmBuffState0016_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t                         ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_001B, D_SMBUFF_STRUCT_SIZE_001B, D_SMBUFF_DATA_SIZE_001B, 3, D_IPC_MSG_ID_CNT_001B, &msgIdSmBuffState001B_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t                         ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_001C, D_SMBUFF_STRUCT_SIZE_001C, D_SMBUFF_DATA_SIZE_001C, 3, D_IPC_MSG_ID_CNT_001C, &msgIdSmBuffState001C_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t      ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_001D, D_SMBUFF_STRUCT_SIZE_001D, D_SMBUFF_DATA_SIZE_001D, 3, D_IPC_MSG_ID_CNT_001D, &msgIdSmBuffState001D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_001E, D_SMBUFF_STRUCT_SIZE_001E, D_SMBUFF_DATA_SIZE_001E, 3, D_IPC_MSG_ID_CNT_001E, &msgIdSmBuffState001E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_001F, D_SMBUFF_STRUCT_SIZE_001F, D_SMBUFF_DATA_SIZE_001F, 3, D_IPC_MSG_ID_CNT_001F, &msgIdSmBuffState001F_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t              ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0020, D_SMBUFF_STRUCT_SIZE_0020, D_SMBUFF_DATA_SIZE_0020, 3, D_IPC_MSG_ID_CNT_0020, &msgIdSmBuffState0020_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t       ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0021, D_SMBUFF_STRUCT_SIZE_0021, D_SMBUFF_DATA_SIZE_0021, 3, D_IPC_MSG_ID_CNT_0021, &msgIdSmBuffState0021_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t                             ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0025, D_SMBUFF_STRUCT_SIZE_0025, D_SMBUFF_DATA_SIZE_0025, 3, D_IPC_MSG_ID_CNT_0025, &msgIdSmBuffState0025_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t                                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                   | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_002C, D_SMBUFF_STRUCT_SIZE_002C, D_SMBUFF_DATA_SIZE_002C, 3, D_IPC_MSG_ID_CNT_002C, &msgIdSmBuffState002C_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IParkingSlotInformation_t                                  ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0031, D_SMBUFF_STRUCT_SIZE_0031, D_SMBUFF_DATA_SIZE_0031, 3, D_IPC_MSG_ID_CNT_0031, &msgIdSmBuffState0031_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_MOT_Output                                                 ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0036, D_SMBUFF_STRUCT_SIZE_0036, D_SMBUFF_DATA_SIZE_0036, 3, D_IPC_MSG_ID_CNT_0036, &msgIdSmBuffState0036_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t                        ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_004B, D_SMBUFF_STRUCT_SIZE_004B, D_SMBUFF_DATA_SIZE_004B, 3, D_IPC_MSG_ID_CNT_004B, &msgIdSmBuffState004B_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t                       ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_004F, D_SMBUFF_STRUCT_SIZE_004F, D_SMBUFF_DATA_SIZE_004F, 3, D_IPC_MSG_ID_CNT_004F, &msgIdSmBuffState004F_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t                 ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0055, D_SMBUFF_STRUCT_SIZE_0055, D_SMBUFF_DATA_SIZE_0055, 3, D_IPC_MSG_ID_CNT_0055, &msgIdSmBuffState0055_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TrscDebug_ScrRes_t                                         ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_005E, D_SMBUFF_STRUCT_SIZE_005E, D_SMBUFF_DATA_SIZE_005E, 3, D_IPC_MSG_ID_CNT_005E, &msgIdSmBuffState005E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t               ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_006E, D_SMBUFF_STRUCT_SIZE_006E, D_SMBUFF_DATA_SIZE_006E, 3, D_IPC_MSG_ID_CNT_006E, &msgIdSmBuffState006E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s                                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0070, D_SMBUFF_STRUCT_SIZE_0070, D_SMBUFF_DATA_SIZE_0070, 3, D_IPC_MSG_ID_CNT_0070, &msgIdSmBuffState0070_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t                           ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_007F, D_SMBUFF_STRUCT_SIZE_007F, D_SMBUFF_DATA_SIZE_007F, 3, D_IPC_MSG_ID_CNT_007F, &msgIdSmBuffState007F_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToHmi_t                                  ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0080, D_SMBUFF_STRUCT_SIZE_0080, D_SMBUFF_DATA_SIZE_0080, 3, D_IPC_MSG_ID_CNT_0080, &msgIdSmBuffState0080_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TrailerDetection_Output_HMI_t                              ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0083, D_SMBUFF_STRUCT_SIZE_0083, D_SMBUFF_DATA_SIZE_0083, 3, D_IPC_MSG_ID_CNT_0083, &msgIdSmBuffState0083_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpDLDOutput_JobDLDOutput_t                                      ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0084, D_SMBUFF_STRUCT_SIZE_0084, D_SMBUFF_DATA_SIZE_0084, 3, D_IPC_MSG_ID_CNT_0084, &msgIdSmBuffState0084_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0089, D_SMBUFF_STRUCT_SIZE_0089, D_SMBUFF_DATA_SIZE_0089, 3, D_IPC_MSG_ID_CNT_0089, &msgIdSmBuffState0089_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpErrFltMpu1_0_Error_Fault_MPU1_0_t                             ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_008E, D_SMBUFF_STRUCT_SIZE_008E, D_SMBUFF_DATA_SIZE_008E, 3, D_IPC_MSG_ID_CNT_008E, &msgIdSmBuffState008E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t                     ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0095, D_SMBUFF_STRUCT_SIZE_0095, D_SMBUFF_DATA_SIZE_0095, 3, D_IPC_MSG_ID_CNT_0095, &msgIdSmBuffState0095_as[0]  },

#endif

#if defined(BUILD_MCU1_0)
    {  (uint16_t)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f                                  ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0007, D_SMBUFF_STRUCT_SIZE_0007, D_SMBUFF_DATA_SIZE_0007, 3, D_IPC_MSG_ID_CNT_0007, &msgIdSmBuffState0007_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_SSM_SystemState                                            ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0017, D_SMBUFF_STRUCT_SIZE_0017, D_SMBUFF_DATA_SIZE_0017, 3, D_IPC_MSG_ID_CNT_0017, &msgIdSmBuffState0017_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def                                ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0018, D_SMBUFF_STRUCT_SIZE_0018, D_SMBUFF_DATA_SIZE_0018, 3, D_IPC_MSG_ID_CNT_0018, &msgIdSmBuffState0018_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_CalDataProvider_MCU_2_0_Def                                ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0019, D_SMBUFF_STRUCT_SIZE_0019, D_SMBUFF_DATA_SIZE_0019, 3, D_IPC_MSG_ID_CNT_0019, &msgIdSmBuffState0019_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_CalDataProvider_MCU_2_1_Def                                ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_001A, D_SMBUFF_STRUCT_SIZE_001A, D_SMBUFF_DATA_SIZE_001A, 3, D_IPC_MSG_ID_CNT_001A, &msgIdSmBuffState001A_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t                ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0022, D_SMBUFF_STRUCT_SIZE_0022, D_SMBUFF_DATA_SIZE_0022, 3, D_IPC_MSG_ID_CNT_0022, &msgIdSmBuffState0022_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t                     ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0023, D_SMBUFF_STRUCT_SIZE_0023, D_SMBUFF_DATA_SIZE_0023, 3, D_IPC_MSG_ID_CNT_0023, &msgIdSmBuffState0023_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ME_Proxi_to_IpcSignals_t                                   ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0024, D_SMBUFF_STRUCT_SIZE_0024, D_SMBUFF_DATA_SIZE_0024, 3, D_IPC_MSG_ID_CNT_0024, &msgIdSmBuffState0024_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IKinematicData_t                                           ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_002F, D_SMBUFF_STRUCT_SIZE_002F, D_SMBUFF_DATA_SIZE_002F, 3, D_IPC_MSG_ID_CNT_002F, &msgIdSmBuffState002F_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ExtY_Kinematic_T                                           ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0030, D_SMBUFF_STRUCT_SIZE_0030, D_SMBUFF_DATA_SIZE_0030, 3, D_IPC_MSG_ID_CNT_0030, &msgIdSmBuffState0030_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_QM                                              ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0040, D_SMBUFF_STRUCT_SIZE_0040, D_SMBUFF_DATA_SIZE_0040, 3, D_IPC_MSG_ID_CNT_0040, &msgIdSmBuffState0040_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_B                                               ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0041, D_SMBUFF_STRUCT_SIZE_0041, D_SMBUFF_DATA_SIZE_0041, 3, D_IPC_MSG_ID_CNT_0041, &msgIdSmBuffState0041_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_USS_Curr_Volt_Monitor_t                                    ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0049, D_SMBUFF_STRUCT_SIZE_0049, D_SMBUFF_DATA_SIZE_0049, 3, D_IPC_MSG_ID_CNT_0049, &msgIdSmBuffState0049_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_DiagToSVS_t                                                ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_004C, D_SMBUFF_STRUCT_SIZE_004C, D_SMBUFF_DATA_SIZE_004C, 3, D_IPC_MSG_ID_CNT_004C, &msgIdSmBuffState004C_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_CAM_Curr_Volt_Monitor_t                                    ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0050, D_SMBUFF_STRUCT_SIZE_0050, D_SMBUFF_DATA_SIZE_0050, 3, D_IPC_MSG_ID_CNT_0050, &msgIdSmBuffState0050_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_US_S_MarriageSensorIDs_t                                   ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0053, D_SMBUFF_STRUCT_SIZE_0053, D_SMBUFF_DATA_SIZE_0053, 3, D_IPC_MSG_ID_CNT_0053, &msgIdSmBuffState0053_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_DiagToParkAssist_t                                         ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0058, D_SMBUFF_STRUCT_SIZE_0058, D_SMBUFF_DATA_SIZE_0058, 3, D_IPC_MSG_ID_CNT_0058, &msgIdSmBuffState0058_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t                                     ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_005B, D_SMBUFF_STRUCT_SIZE_005B, D_SMBUFF_DATA_SIZE_005B, 3, D_IPC_MSG_ID_CNT_005B, &msgIdSmBuffState005B_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ME_ProxiToMCU2_0_Def_t                                     ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_005C, D_SMBUFF_STRUCT_SIZE_005C, D_SMBUFF_DATA_SIZE_005C, 3, D_IPC_MSG_ID_CNT_005C, &msgIdSmBuffState005C_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ME_ProxiToMCU2_1_Def_t                                     ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_005D, D_SMBUFF_STRUCT_SIZE_005D, D_SMBUFF_DATA_SIZE_005D, 3, D_IPC_MSG_ID_CNT_005D, &msgIdSmBuffState005D_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbNVM_ReadParam                                            ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0064, D_SMBUFF_STRUCT_SIZE_0064, D_SMBUFF_DATA_SIZE_0064, 3, D_IPC_MSG_ID_CNT_0064, &msgIdSmBuffState0064_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ME_CanDebugRIDStatus_t                                     ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0065, D_SMBUFF_STRUCT_SIZE_0065, D_SMBUFF_DATA_SIZE_0065, 3, D_IPC_MSG_ID_CNT_0065, &msgIdSmBuffState0065_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_SVS_NVMData_t                                              ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0066, D_SMBUFF_STRUCT_SIZE_0066, D_SMBUFF_DATA_SIZE_0066, 3, D_IPC_MSG_ID_CNT_0066, &msgIdSmBuffState0066_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_USS_Calibration_Data_t                                     ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_006A, D_SMBUFF_STRUCT_SIZE_006A, D_SMBUFF_DATA_SIZE_006A, 3, D_IPC_MSG_ID_CNT_006A, &msgIdSmBuffState006A_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_THA_Calibration_data_MCU2_1_t                              ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0072, D_SMBUFF_STRUCT_SIZE_0072, D_SMBUFF_DATA_SIZE_0072, 3, D_IPC_MSG_ID_CNT_0072, &msgIdSmBuffState0072_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t                              ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0073, D_SMBUFF_STRUCT_SIZE_0073, D_SMBUFF_DATA_SIZE_0073, 3, D_IPC_MSG_ID_CNT_0073, &msgIdSmBuffState0073_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TRSC_Calibration_data_MCU2_1_t                             ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0074, D_SMBUFF_STRUCT_SIZE_0074, D_SMBUFF_DATA_SIZE_0074, 3, D_IPC_MSG_ID_CNT_0074, &msgIdSmBuffState0074_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t                              ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0075, D_SMBUFF_STRUCT_SIZE_0075, D_SMBUFF_DATA_SIZE_0075, 3, D_IPC_MSG_ID_CNT_0075, &msgIdSmBuffState0075_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_APA_Calibration_data_MCU2_1_t                              ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0076, D_SMBUFF_STRUCT_SIZE_0076, D_SMBUFF_DATA_SIZE_0076, 3, D_IPC_MSG_ID_CNT_0076, &msgIdSmBuffState0076_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_SVS_Calibration_data_t                                     ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0077, D_SMBUFF_STRUCT_SIZE_0077, D_SMBUFF_DATA_SIZE_0077, 3, D_IPC_MSG_ID_CNT_0077, &msgIdSmBuffState0077_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_FOD_Calibration_data_t                                     ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0078, D_SMBUFF_STRUCT_SIZE_0078, D_SMBUFF_DATA_SIZE_0078, 3, D_IPC_MSG_ID_CNT_0078, &msgIdSmBuffState0078_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_LMD_Calibration_data_t                                     ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                     | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0079, D_SMBUFF_STRUCT_SIZE_0079, D_SMBUFF_DATA_SIZE_0079, 3, D_IPC_MSG_ID_CNT_0079, &msgIdSmBuffState0079_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t                             ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_007A, D_SMBUFF_STRUCT_SIZE_007A, D_SMBUFF_DATA_SIZE_007A, 3, D_IPC_MSG_ID_CNT_007A, &msgIdSmBuffState007A_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_USS_Calibration_data_2_t                                   ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0081, D_SMBUFF_STRUCT_SIZE_0081, D_SMBUFF_DATA_SIZE_0081, 3, D_IPC_MSG_ID_CNT_0081, &msgIdSmBuffState0081_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_INVMSignalManager_t                                        ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0085, D_SMBUFF_STRUCT_SIZE_0085, D_SMBUFF_DATA_SIZE_0085, 3, D_IPC_MSG_ID_CNT_0085, &msgIdSmBuffState0085_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TimeManagerProxy_TimeStamp_t                               ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0087, D_SMBUFF_STRUCT_SIZE_0087, D_SMBUFF_DATA_SIZE_0087, 3, D_IPC_MSG_ID_CNT_0087, &msgIdSmBuffState0087_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TRSC_CalibrationClear_t                                    ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_008F, D_SMBUFF_STRUCT_SIZE_008F, D_SMBUFF_DATA_SIZE_008F, 3, D_IPC_MSG_ID_CNT_008F, &msgIdSmBuffState008F_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_UssTunningData_mcu1_0_t                                    ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0090, D_SMBUFF_STRUCT_SIZE_0090, D_SMBUFF_DATA_SIZE_0090, 3, D_IPC_MSG_ID_CNT_0090, &msgIdSmBuffState0090_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_PerformanceStatsEnable_t                                   ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                   | MCU2_0_BITMSK_2 | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0094, D_SMBUFF_STRUCT_SIZE_0094, D_SMBUFF_DATA_SIZE_0094, 3, D_IPC_MSG_ID_CNT_0094, &msgIdSmBuffState0094_as[0]  },

#endif

#if defined(BUILD_MCU2_0)
    {  (uint16_t)e_IpcMsgId_data_SvsToTHADet_t                                              ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0001, D_SMBUFF_STRUCT_SIZE_0001, D_SMBUFF_DATA_SIZE_0001, 3, D_IPC_MSG_ID_CNT_0001, &msgIdSmBuffState0001_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSvsToVCAN_SvsToVCAN_t                                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                   | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0002, D_SMBUFF_STRUCT_SIZE_0002, D_SMBUFF_DATA_SIZE_0002, 3, D_IPC_MSG_ID_CNT_0002, &msgIdSmBuffState0002_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVStoTRSC_SVStoTRSC_t                                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0003, D_SMBUFF_STRUCT_SIZE_0003, D_SMBUFF_DATA_SIZE_0003, 3, D_IPC_MSG_ID_CNT_0003, &msgIdSmBuffState0003_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpScreenRequest_ScreenRequest_t                                 ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1                   | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0004, D_SMBUFF_STRUCT_SIZE_0004, D_SMBUFF_DATA_SIZE_0004, 3, D_IPC_MSG_ID_CNT_0004, &msgIdSmBuffState0004_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSvsToTHA_SvsToTHA_t                                           ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                   | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0005, D_SMBUFF_STRUCT_SIZE_0005, D_SMBUFF_DATA_SIZE_0005, 3, D_IPC_MSG_ID_CNT_0005, &msgIdSmBuffState0005_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0008, D_SMBUFF_STRUCT_SIZE_0008, D_SMBUFF_DATA_SIZE_0008, 3, D_IPC_MSG_ID_CNT_0008, &msgIdSmBuffState0008_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0009, D_SMBUFF_STRUCT_SIZE_0009, D_SMBUFF_DATA_SIZE_0009, 3, D_IPC_MSG_ID_CNT_0009, &msgIdSmBuffState0009_as[0]  },
    {  (uint16_t)e_IpcMsgId_data_SVStoTRSCSMVC_t                                            ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0011, D_SMBUFF_STRUCT_SIZE_0011, D_SMBUFF_DATA_SIZE_0011, 3, D_IPC_MSG_ID_CNT_0011, &msgIdSmBuffState0011_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_0                                       ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1                   | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0014, D_SMBUFF_STRUCT_SIZE_0014, D_SMBUFF_DATA_SIZE_0014, 3, D_IPC_MSG_ID_CNT_0014, &msgIdSmBuffState0014_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IHMIInfoToFPA_t                                            ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_002B, D_SMBUFF_STRUCT_SIZE_002B, D_SMBUFF_DATA_SIZE_002B, 3, D_IPC_MSG_ID_CNT_002B, &msgIdSmBuffState002B_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IParkingSlotID_t                                           ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0034, D_SMBUFF_STRUCT_SIZE_0034, D_SMBUFF_DATA_SIZE_0034, 3, D_IPC_MSG_ID_CNT_0034, &msgIdSmBuffState0034_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_THARelated_ScreenReq_t                                     ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_004A, D_SMBUFF_STRUCT_SIZE_004A, D_SMBUFF_DATA_SIZE_004A, 3, D_IPC_MSG_ID_CNT_004A, &msgIdSmBuffState004A_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSToDiag_SVSToDiag_t                                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_004D, D_SMBUFF_STRUCT_SIZE_004D, D_SMBUFF_DATA_SIZE_004D, 3, D_IPC_MSG_ID_CNT_004D, &msgIdSmBuffState004D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCamCsData_CAM_CS_Curr_Monitor_t                               ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0051, D_SMBUFF_STRUCT_SIZE_0051, D_SMBUFF_DATA_SIZE_0051, 3, D_IPC_MSG_ID_CNT_0051, &msgIdSmBuffState0051_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_HMIInfoToAP_t                                              ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_0057, D_SMBUFF_STRUCT_SIZE_0057, D_SMBUFF_DATA_SIZE_0057, 3, D_IPC_MSG_ID_CNT_0057, &msgIdSmBuffState0057_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data1_USS_PowerSelect_t                                         ,  ( CORE_BITMSK_CLR                                                       | MCU2_1_BITMSK_3                                                                                                             ),  D_SMBUFF_BASE_ADDR_005A, D_SMBUFF_STRUCT_SIZE_005A, D_SMBUFF_DATA_SIZE_005A, 3, D_IPC_MSG_ID_CNT_005A, &msgIdSmBuffState005A_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TRSCDebug_ScrReq_t                                         ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_005F, D_SMBUFF_STRUCT_SIZE_005F, D_SMBUFF_DATA_SIZE_005F, 3, D_IPC_MSG_ID_CNT_005F, &msgIdSmBuffState005F_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t                                 ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0063, D_SMBUFF_STRUCT_SIZE_0063, D_SMBUFF_DATA_SIZE_0063, 3, D_IPC_MSG_ID_CNT_0063, &msgIdSmBuffState0063_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSVSNVMData_SVS_NVMData_t                                      ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0069, D_SMBUFF_STRUCT_SIZE_0069, D_SMBUFF_DATA_SIZE_0069, 3, D_IPC_MSG_ID_CNT_0069, &msgIdSmBuffState0069_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t               ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_006D, D_SMBUFF_STRUCT_SIZE_006D, D_SMBUFF_DATA_SIZE_006D, 3, D_IPC_MSG_ID_CNT_006D, &msgIdSmBuffState006D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCamSerENStat_Cam_and_Ser_EN_Status_t                          ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0082, D_SMBUFF_STRUCT_SIZE_0082, D_SMBUFF_DATA_SIZE_0082, 3, D_IPC_MSG_ID_CNT_0082, &msgIdSmBuffState0082_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCAMSelInfo_CAM_select_info_t                                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_008B, D_SMBUFF_STRUCT_SIZE_008B, D_SMBUFF_DATA_SIZE_008B, 3, D_IPC_MSG_ID_CNT_008B, &msgIdSmBuffState008B_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpErrFltMcu2_0_Error_Fault_MCU2_0_t                             ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_008C, D_SMBUFF_STRUCT_SIZE_008C, D_SMBUFF_DATA_SIZE_008C, 3, D_IPC_MSG_ID_CNT_008C, &msgIdSmBuffState008C_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t                     ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0093, D_SMBUFF_STRUCT_SIZE_0093, D_SMBUFF_DATA_SIZE_0093, 3, D_IPC_MSG_ID_CNT_0093, &msgIdSmBuffState0093_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_CamHotplugStatus_t                                         ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_0096, D_SMBUFF_STRUCT_SIZE_0096, D_SMBUFF_DATA_SIZE_0096, 3, D_IPC_MSG_ID_CNT_0096, &msgIdSmBuffState0096_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0098, D_SMBUFF_STRUCT_SIZE_0098, D_SMBUFF_DATA_SIZE_0098, 3, D_IPC_MSG_ID_CNT_0098, &msgIdSmBuffState0098_as[0]  },

#endif

#if defined(BUILD_MCU2_1)
    {  (uint16_t)e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_000A, D_SMBUFF_STRUCT_SIZE_000A, D_SMBUFF_DATA_SIZE_000A, 3, D_IPC_MSG_ID_CNT_000A, &msgIdSmBuffState000A_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_000B, D_SMBUFF_STRUCT_SIZE_000B, D_SMBUFF_DATA_SIZE_000B, 3, D_IPC_MSG_ID_CNT_000B, &msgIdSmBuffState000B_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTRSC_ME_VehOut_TRSC_t                                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0010, D_SMBUFF_STRUCT_SIZE_0010, D_SMBUFF_DATA_SIZE_0010, 3, D_IPC_MSG_ID_CNT_0010, &msgIdSmBuffState0010_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t                                 ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0012, D_SMBUFF_STRUCT_SIZE_0012, D_SMBUFF_DATA_SIZE_0012, 3, D_IPC_MSG_ID_CNT_0012, &msgIdSmBuffState0012_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t                       ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0013, D_SMBUFF_STRUCT_SIZE_0013, D_SMBUFF_DATA_SIZE_0013, 3, D_IPC_MSG_ID_CNT_0013, &msgIdSmBuffState0013_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_1                                       ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0015, D_SMBUFF_STRUCT_SIZE_0015, D_SMBUFF_DATA_SIZE_0015, 3, D_IPC_MSG_ID_CNT_0015, &msgIdSmBuffState0015_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpAPSMPAOut_TbAP_APSMPAOut_t                                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0026, D_SMBUFF_STRUCT_SIZE_0026, D_SMBUFF_DATA_SIZE_0026, 3, D_IPC_MSG_ID_CNT_0026, &msgIdSmBuffState0026_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t                  ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0027, D_SMBUFF_STRUCT_SIZE_0027, D_SMBUFF_DATA_SIZE_0027, 3, D_IPC_MSG_ID_CNT_0027, &msgIdSmBuffState0027_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IFPAInfoToHMI_t                                            ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0028, D_SMBUFF_STRUCT_SIZE_0028, D_SMBUFF_DATA_SIZE_0028, 3, D_IPC_MSG_ID_CNT_0028, &msgIdSmBuffState0028_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IFPAInfoToVC_t                                             ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_0029, D_SMBUFF_STRUCT_SIZE_0029, D_SMBUFF_DATA_SIZE_0029, 3, D_IPC_MSG_ID_CNT_0029, &msgIdSmBuffState0029_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IFPAInfoToPLD_t                                            ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0                                                                                                                                                                   ),  D_SMBUFF_BASE_ADDR_002A, D_SMBUFF_STRUCT_SIZE_002A, D_SMBUFF_DATA_SIZE_002A, 3, D_IPC_MSG_ID_CNT_002A, &msgIdSmBuffState002A_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IUPASensorDataV2_t                                         ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_002D, D_SMBUFF_STRUCT_SIZE_002D, D_SMBUFF_DATA_SIZE_002D, 3, D_IPC_MSG_ID_CNT_002D, &msgIdSmBuffState002D_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IPathPlannerState_t                                        ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_002E, D_SMBUFF_STRUCT_SIZE_002E, D_SMBUFF_DATA_SIZE_002E, 3, D_IPC_MSG_ID_CNT_002E, &msgIdSmBuffState002E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpJobFPAData_IJobFPAOutput_t                                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0032, D_SMBUFF_STRUCT_SIZE_0032, D_SMBUFF_DATA_SIZE_0032, 3, D_IPC_MSG_ID_CNT_0032, &msgIdSmBuffState0032_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_IAutoParkingState_t                                        ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_0033, D_SMBUFF_STRUCT_SIZE_0033, D_SMBUFF_DATA_SIZE_0033, 3, D_IPC_MSG_ID_CNT_0033, &msgIdSmBuffState0033_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpNFCDOutput_NFCD_Output                                        ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0035, D_SMBUFF_STRUCT_SIZE_0035, D_SMBUFF_DATA_SIZE_0035, 3, D_IPC_MSG_ID_CNT_0035, &msgIdSmBuffState0035_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t                  ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0037, D_SMBUFF_STRUCT_SIZE_0037, D_SMBUFF_DATA_SIZE_0037, 3, D_IPC_MSG_ID_CNT_0037, &msgIdSmBuffState0037_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSMDAInternal_TbAP_SMDAInternalOut_t                           ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0038, D_SMBUFF_STRUCT_SIZE_0038, D_SMBUFF_DATA_SIZE_0038, 3, D_IPC_MSG_ID_CNT_0038, &msgIdSmBuffState0038_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t                            ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0039, D_SMBUFF_STRUCT_SIZE_0039, D_SMBUFF_DATA_SIZE_0039, 3, D_IPC_MSG_ID_CNT_0039, &msgIdSmBuffState0039_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpFPAWarnOut_TbAP_FPAWarnOut_t                                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_003A, D_SMBUFF_STRUCT_SIZE_003A, D_SMBUFF_DATA_SIZE_003A, 3, D_IPC_MSG_ID_CNT_003A, &msgIdSmBuffState003A_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpRPAWarnOut_TbAP_RPAWarnOut_t                                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1 | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_003B, D_SMBUFF_STRUCT_SIZE_003B, D_SMBUFF_DATA_SIZE_003B, 3, D_IPC_MSG_ID_CNT_003B, &msgIdSmBuffState003B_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpPAStateOut_TbAP_PAStateOut_t                                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_003C, D_SMBUFF_STRUCT_SIZE_003C, D_SMBUFF_DATA_SIZE_003C, 3, D_IPC_MSG_ID_CNT_003C, &msgIdSmBuffState003C_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpVCActuatorOut_TbAP_VCActuatorOut_t                            ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_003D, D_SMBUFF_STRUCT_SIZE_003D, D_SMBUFF_DATA_SIZE_003D, 3, D_IPC_MSG_ID_CNT_003D, &msgIdSmBuffState003D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpVCTrajOut_TbAP_VCTrajOut_t                                    ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_003E, D_SMBUFF_STRUCT_SIZE_003E, D_SMBUFF_DATA_SIZE_003E, 3, D_IPC_MSG_ID_CNT_003E, &msgIdSmBuffState003E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpVCState_TbAP_VCStateOut_t                                     ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_003F, D_SMBUFF_STRUCT_SIZE_003F, D_SMBUFF_DATA_SIZE_003F, 3, D_IPC_MSG_ID_CNT_003F, &msgIdSmBuffState003F_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUssPointMapGrp_US_S_PointMapGroup_t                           ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0042, D_SMBUFF_STRUCT_SIZE_0042, D_SMBUFF_DATA_SIZE_0042, 3, D_IPC_MSG_ID_CNT_0042, &msgIdSmBuffState0042_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpSnrDirEcho_US_S_SnrDirEcho_t                                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0043, D_SMBUFF_STRUCT_SIZE_0043, D_SMBUFF_DATA_SIZE_0043, 3, D_IPC_MSG_ID_CNT_0043, &msgIdSmBuffState0043_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUssZoneInfo_US_S_ZoneInfo_t                                   ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0044, D_SMBUFF_STRUCT_SIZE_0044, D_SMBUFF_DATA_SIZE_0044, 3, D_IPC_MSG_ID_CNT_0044, &msgIdSmBuffState0044_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t                             ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0045, D_SMBUFF_STRUCT_SIZE_0045, D_SMBUFF_DATA_SIZE_0045, 3, D_IPC_MSG_ID_CNT_0045, &msgIdSmBuffState0045_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUSSConstantData_US_S_USSConstantData_t                        ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0046, D_SMBUFF_STRUCT_SIZE_0046, D_SMBUFF_DATA_SIZE_0046, 3, D_IPC_MSG_ID_CNT_0046, &msgIdSmBuffState0046_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0047, D_SMBUFF_STRUCT_SIZE_0047, D_SMBUFF_DATA_SIZE_0047, 3, D_IPC_MSG_ID_CNT_0047, &msgIdSmBuffState0047_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t                      ,  ( CORE_BITMSK_CLR | MPU1_0_BITMSK_0 | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0048, D_SMBUFF_STRUCT_SIZE_0048, D_SMBUFF_DATA_SIZE_0048, 3, D_IPC_MSG_ID_CNT_0048, &msgIdSmBuffState0048_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t                        ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_004E, D_SMBUFF_STRUCT_SIZE_004E, D_SMBUFF_DATA_SIZE_004E, 3, D_IPC_MSG_ID_CNT_004E, &msgIdSmBuffState004E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUssMrrgData_US_S_MarriageSensorIDs_t                          ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0052, D_SMBUFF_STRUCT_SIZE_0052, D_SMBUFF_DATA_SIZE_0052, 3, D_IPC_MSG_ID_CNT_0052, &msgIdSmBuffState0052_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTrscToDiag_TRSCtoDiagMgr_t                                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0054, D_SMBUFF_STRUCT_SIZE_0054, D_SMBUFF_DATA_SIZE_0054, 3, D_IPC_MSG_ID_CNT_0054, &msgIdSmBuffState0054_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbAP_USSStateOut_t                                         ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_0056, D_SMBUFF_STRUCT_SIZE_0056, D_SMBUFF_DATA_SIZE_0056, 3, D_IPC_MSG_ID_CNT_0056, &msgIdSmBuffState0056_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_USS_PowerSelect_t                                          ,  ( CORE_BITMSK_CLR                                     | MCU2_0_BITMSK_2                                                                                                                               ),  D_SMBUFF_BASE_ADDR_0059, D_SMBUFF_STRUCT_SIZE_0059, D_SMBUFF_DATA_SIZE_0059, 3, D_IPC_MSG_ID_CNT_0059, &msgIdSmBuffState0059_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUssDataCollection_US_S_USSDataCollectionData_t                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0060, D_SMBUFF_STRUCT_SIZE_0060, D_SMBUFF_DATA_SIZE_0060, 3, D_IPC_MSG_ID_CNT_0060, &msgIdSmBuffState0060_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpPointDistOpBuff_US_S_PointDistOutputBuff_t                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0061, D_SMBUFF_STRUCT_SIZE_0061, D_SMBUFF_DATA_SIZE_0061, 3, D_IPC_MSG_ID_CNT_0061, &msgIdSmBuffState0061_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t                                 ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0062, D_SMBUFF_STRUCT_SIZE_0062, D_SMBUFF_DATA_SIZE_0062, 3, D_IPC_MSG_ID_CNT_0062, &msgIdSmBuffState0062_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0067, D_SMBUFF_STRUCT_SIZE_0067, D_SMBUFF_DATA_SIZE_0067, 3, D_IPC_MSG_ID_CNT_0067, &msgIdSmBuffState0067_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t                        ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0068, D_SMBUFF_STRUCT_SIZE_0068, D_SMBUFF_DATA_SIZE_0068, 3, D_IPC_MSG_ID_CNT_0068, &msgIdSmBuffState0068_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTbAPDebugOut_TbAP_DebugOut                                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_006B, D_SMBUFF_STRUCT_SIZE_006B, D_SMBUFF_DATA_SIZE_006B, 3, D_IPC_MSG_ID_CNT_006B, &msgIdSmBuffState006B_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t               ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_006C, D_SMBUFF_STRUCT_SIZE_006C, D_SMBUFF_DATA_SIZE_006C, 3, D_IPC_MSG_ID_CNT_006C, &msgIdSmBuffState006C_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_ParkingMode_t                                              ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_006F, D_SMBUFF_STRUCT_SIZE_006F, D_SMBUFF_DATA_SIZE_006F, 3, D_IPC_MSG_ID_CNT_006F, &msgIdSmBuffState006F_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t                             ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0071, D_SMBUFF_STRUCT_SIZE_0071, D_SMBUFF_DATA_SIZE_0071, 3, D_IPC_MSG_ID_CNT_0071, &msgIdSmBuffState0071_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t                  ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_007B, D_SMBUFF_STRUCT_SIZE_007B, D_SMBUFF_DATA_SIZE_007B, 3, D_IPC_MSG_ID_CNT_007B, &msgIdSmBuffState007B_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpIDebugFODObject_IDebug_FODObject_t                            ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_007C, D_SMBUFF_STRUCT_SIZE_007C, D_SMBUFF_DATA_SIZE_007C, 3, D_IPC_MSG_ID_CNT_007C, &msgIdSmBuffState007C_as[0]  },
    {  (uint16_t)e_IpcMsgId_Data_TbFA_USSStateOutput_t                                      ,  ( CORE_BITMSK_CLR                                                                                                                                                                                     ),  D_SMBUFF_BASE_ADDR_007D, D_SMBUFF_STRUCT_SIZE_007D, D_SMBUFF_DATA_SIZE_007D, 3, D_IPC_MSG_ID_CNT_007D, &msgIdSmBuffState007D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTbFAResetKM_TbFA_ResetKM_t                                    ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_007E, D_SMBUFF_STRUCT_SIZE_007E, D_SMBUFF_DATA_SIZE_007E, 3, D_IPC_MSG_ID_CNT_007E, &msgIdSmBuffState007E_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t                          ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0086, D_SMBUFF_STRUCT_SIZE_0086, D_SMBUFF_DATA_SIZE_0086, 3, D_IPC_MSG_ID_CNT_0086, &msgIdSmBuffState0086_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type                ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0088, D_SMBUFF_STRUCT_SIZE_0088, D_SMBUFF_DATA_SIZE_0088, 3, D_IPC_MSG_ID_CNT_0088, &msgIdSmBuffState0088_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUssDebugMsg_US_S_DebugMsg_t                                   ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_008A, D_SMBUFF_STRUCT_SIZE_008A, D_SMBUFF_DATA_SIZE_008A, 3, D_IPC_MSG_ID_CNT_008A, &msgIdSmBuffState008A_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpErrFltMcu2_1_Error_Fault_MCU2_1_t                             ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_008D, D_SMBUFF_STRUCT_SIZE_008D, D_SMBUFF_DATA_SIZE_008D, 3, D_IPC_MSG_ID_CNT_008D, &msgIdSmBuffState008D_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpUssTunData_UssTunningData_mcu2_1_t                            ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0091, D_SMBUFF_STRUCT_SIZE_0091, D_SMBUFF_DATA_SIZE_0091, 3, D_IPC_MSG_ID_CNT_0091, &msgIdSmBuffState0091_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t                     ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0092, D_SMBUFF_STRUCT_SIZE_0092, D_SMBUFF_DATA_SIZE_0092, 3, D_IPC_MSG_ID_CNT_0092, &msgIdSmBuffState0092_as[0]  },
    {  (uint16_t)e_IpcMsgId_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t                         ,  ( CORE_BITMSK_CLR                   | MCU1_0_BITMSK_1                                                                                                                                                 ),  D_SMBUFF_BASE_ADDR_0097, D_SMBUFF_STRUCT_SIZE_0097, D_SMBUFF_DATA_SIZE_0097, 3, D_IPC_MSG_ID_CNT_0097, &msgIdSmBuffState0097_as[0]  },

#endif

#if defined(BUILD_MCU3_0)

#endif

#if defined(BUILD_MCU3_1)

#endif

#if defined(BUILD_C66x_1)

#endif

#if defined(BUILD_C66x_2)

#endif

};

#endif

/* Configuration for Rx messages */
#if (D_NUMBER_OF_RX_MESSAGES > 0)
const ipcLutAttrRx_t V_ipcLutAttrRx_as[D_NUMBER_OF_RX_MESSAGES] = {
    /*          MSG_ID                                                                   DataSize,              MessageIdPrevCntr     Callback function      */
#if defined(BUILD_MPU1_0)
    {  (uint16_t)e_IpcMsgId_data_SvsToTHADet_t                                              , D_SMBUFF_DATA_SIZE_0001, D_IPC_MSG_ID_CNT_0001, D_IPC_CALLBACK_FUNC_0001  },
    {  (uint16_t)e_IpcMsgId_PpScreenRequest_ScreenRequest_t                                 , D_SMBUFF_DATA_SIZE_0004, D_IPC_MSG_ID_CNT_0004, D_IPC_CALLBACK_FUNC_0004  },
    {  (uint16_t)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f                                  , D_SMBUFF_DATA_SIZE_0007, D_IPC_MSG_ID_CNT_0007, D_IPC_CALLBACK_FUNC_0007  },
    {  (uint16_t)e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t                       , D_SMBUFF_DATA_SIZE_0013, D_IPC_MSG_ID_CNT_0013, D_IPC_CALLBACK_FUNC_0013  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_0                                       , D_SMBUFF_DATA_SIZE_0014, D_IPC_MSG_ID_CNT_0014, D_IPC_CALLBACK_FUNC_0014  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_1                                       , D_SMBUFF_DATA_SIZE_0015, D_IPC_MSG_ID_CNT_0015, D_IPC_CALLBACK_FUNC_0015  },
    {  (uint16_t)e_IpcMsgId_Data_SSM_SystemState                                            , D_SMBUFF_DATA_SIZE_0017, D_IPC_MSG_ID_CNT_0017, D_IPC_CALLBACK_FUNC_0017  },
    {  (uint16_t)e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def                                , D_SMBUFF_DATA_SIZE_0018, D_IPC_MSG_ID_CNT_0018, D_IPC_CALLBACK_FUNC_0018  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t                , D_SMBUFF_DATA_SIZE_0022, D_IPC_MSG_ID_CNT_0022, D_IPC_CALLBACK_FUNC_0022  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t                     , D_SMBUFF_DATA_SIZE_0023, D_IPC_MSG_ID_CNT_0023, D_IPC_CALLBACK_FUNC_0023  },
    {  (uint16_t)e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t                  , D_SMBUFF_DATA_SIZE_0027, D_IPC_MSG_ID_CNT_0027, D_IPC_CALLBACK_FUNC_0027  },
    {  (uint16_t)e_IpcMsgId_Data_IFPAInfoToPLD_t                                            , D_SMBUFF_DATA_SIZE_002A, D_IPC_MSG_ID_CNT_002A, D_IPC_CALLBACK_FUNC_002A  },
    {  (uint16_t)e_IpcMsgId_Data_IKinematicData_t                                           , D_SMBUFF_DATA_SIZE_002F, D_IPC_MSG_ID_CNT_002F, D_IPC_CALLBACK_FUNC_002F  },
    {  (uint16_t)e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t                  , D_SMBUFF_DATA_SIZE_0037, D_IPC_MSG_ID_CNT_0037, D_IPC_CALLBACK_FUNC_0037  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_QM                                              , D_SMBUFF_DATA_SIZE_0040, D_IPC_MSG_ID_CNT_0040, D_IPC_CALLBACK_FUNC_0040  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_B                                               , D_SMBUFF_DATA_SIZE_0041, D_IPC_MSG_ID_CNT_0041, D_IPC_CALLBACK_FUNC_0041  },
    {  (uint16_t)e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t                             , D_SMBUFF_DATA_SIZE_0045, D_IPC_MSG_ID_CNT_0045, D_IPC_CALLBACK_FUNC_0045  },
    {  (uint16_t)e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t                      , D_SMBUFF_DATA_SIZE_0048, D_IPC_MSG_ID_CNT_0048, D_IPC_CALLBACK_FUNC_0048  },
    {  (uint16_t)e_IpcMsgId_Data_THARelated_ScreenReq_t                                     , D_SMBUFF_DATA_SIZE_004A, D_IPC_MSG_ID_CNT_004A, D_IPC_CALLBACK_FUNC_004A  },
    {  (uint16_t)e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t                                     , D_SMBUFF_DATA_SIZE_005B, D_IPC_MSG_ID_CNT_005B, D_IPC_CALLBACK_FUNC_005B  },
    {  (uint16_t)e_IpcMsgId_Data_TRSCDebug_ScrReq_t                                         , D_SMBUFF_DATA_SIZE_005F, D_IPC_MSG_ID_CNT_005F, D_IPC_CALLBACK_FUNC_005F  },
    {  (uint16_t)e_IpcMsgId_Data_ME_CanDebugRIDStatus_t                                     , D_SMBUFF_DATA_SIZE_0065, D_IPC_MSG_ID_CNT_0065, D_IPC_CALLBACK_FUNC_0065  },
    {  (uint16_t)e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t                              , D_SMBUFF_DATA_SIZE_0073, D_IPC_MSG_ID_CNT_0073, D_IPC_CALLBACK_FUNC_0073  },
    {  (uint16_t)e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t                              , D_SMBUFF_DATA_SIZE_0075, D_IPC_MSG_ID_CNT_0075, D_IPC_CALLBACK_FUNC_0075  },
    {  (uint16_t)e_IpcMsgId_Data_LMD_Calibration_data_t                                     , D_SMBUFF_DATA_SIZE_0079, D_IPC_MSG_ID_CNT_0079, D_IPC_CALLBACK_FUNC_0079  },
    {  (uint16_t)e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t                             , D_SMBUFF_DATA_SIZE_007A, D_IPC_MSG_ID_CNT_007A, D_IPC_CALLBACK_FUNC_007A  },
    {  (uint16_t)e_IpcMsgId_Data_TRSC_CalibrationClear_t                                    , D_SMBUFF_DATA_SIZE_008F, D_IPC_MSG_ID_CNT_008F, D_IPC_CALLBACK_FUNC_008F  },
    {  (uint16_t)e_IpcMsgId_Data_PerformanceStatsEnable_t                                   , D_SMBUFF_DATA_SIZE_0094, D_IPC_MSG_ID_CNT_0094, D_IPC_CALLBACK_FUNC_0094  },
    {  (uint16_t)e_IpcMsgId_Data_CamHotplugStatus_t                                         , D_SMBUFF_DATA_SIZE_0096, D_IPC_MSG_ID_CNT_0096, D_IPC_CALLBACK_FUNC_0096  },
#endif

#if defined(BUILD_MCU1_0)
    {  (uint16_t)e_IpcMsgId_PpSvsToVCAN_SvsToVCAN_t                                         , D_SMBUFF_DATA_SIZE_0002, D_IPC_MSG_ID_CNT_0002, D_IPC_CALLBACK_FUNC_0002  },
    {  (uint16_t)e_IpcMsgId_PpSVStoTRSC_SVStoTRSC_t                                         , D_SMBUFF_DATA_SIZE_0003, D_IPC_MSG_ID_CNT_0003, D_IPC_CALLBACK_FUNC_0003  },
    {  (uint16_t)e_IpcMsgId_PpScreenRequest_ScreenRequest_t                                 , D_SMBUFF_DATA_SIZE_0004, D_IPC_MSG_ID_CNT_0004, D_IPC_CALLBACK_FUNC_0004  },
    {  (uint16_t)e_IpcMsgId_PpSvsToTHA_SvsToTHA_t                                           , D_SMBUFF_DATA_SIZE_0005, D_IPC_MSG_ID_CNT_0005, D_IPC_CALLBACK_FUNC_0005  },
    {  (uint16_t)e_IpcMsgId_PpScreenResponse_ScreenResponse_t                               , D_SMBUFF_DATA_SIZE_0006, D_IPC_MSG_ID_CNT_0006, D_IPC_CALLBACK_FUNC_0006  },
    {  (uint16_t)e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM                , D_SMBUFF_DATA_SIZE_0008, D_IPC_MSG_ID_CNT_0008, D_IPC_CALLBACK_FUNC_0008  },
    {  (uint16_t)e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B                  , D_SMBUFF_DATA_SIZE_0009, D_IPC_MSG_ID_CNT_0009, D_IPC_CALLBACK_FUNC_0009  },
    {  (uint16_t)e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM                , D_SMBUFF_DATA_SIZE_000A, D_IPC_MSG_ID_CNT_000A, D_IPC_CALLBACK_FUNC_000A  },
    {  (uint16_t)e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B                  , D_SMBUFF_DATA_SIZE_000B, D_IPC_MSG_ID_CNT_000B, D_IPC_CALLBACK_FUNC_000B  },
    {  (uint16_t)e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM                , D_SMBUFF_DATA_SIZE_000C, D_IPC_MSG_ID_CNT_000C, D_IPC_CALLBACK_FUNC_000C  },
    {  (uint16_t)e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B                  , D_SMBUFF_DATA_SIZE_000D, D_IPC_MSG_ID_CNT_000D, D_IPC_CALLBACK_FUNC_000D  },
    {  (uint16_t)e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t               , D_SMBUFF_DATA_SIZE_000E, D_IPC_MSG_ID_CNT_000E, D_IPC_CALLBACK_FUNC_000E  },
    {  (uint16_t)e_IpcMsgId_PpTRSC_ME_VehOut_TRSC_t                                         , D_SMBUFF_DATA_SIZE_0010, D_IPC_MSG_ID_CNT_0010, D_IPC_CALLBACK_FUNC_0010  },
    {  (uint16_t)e_IpcMsgId_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t                                 , D_SMBUFF_DATA_SIZE_0012, D_IPC_MSG_ID_CNT_0012, D_IPC_CALLBACK_FUNC_0012  },
    {  (uint16_t)e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t                       , D_SMBUFF_DATA_SIZE_0013, D_IPC_MSG_ID_CNT_0013, D_IPC_CALLBACK_FUNC_0013  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_0                                       , D_SMBUFF_DATA_SIZE_0014, D_IPC_MSG_ID_CNT_0014, D_IPC_CALLBACK_FUNC_0014  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_1                                       , D_SMBUFF_DATA_SIZE_0015, D_IPC_MSG_ID_CNT_0015, D_IPC_CALLBACK_FUNC_0015  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_QNX_State_QNX                                        , D_SMBUFF_DATA_SIZE_0016, D_IPC_MSG_ID_CNT_0016, D_IPC_CALLBACK_FUNC_0016  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t      , D_SMBUFF_DATA_SIZE_001D, D_IPC_MSG_ID_CNT_001D, D_IPC_CALLBACK_FUNC_001D  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t                , D_SMBUFF_DATA_SIZE_001E, D_IPC_MSG_ID_CNT_001E, D_IPC_CALLBACK_FUNC_001E  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t                , D_SMBUFF_DATA_SIZE_001F, D_IPC_MSG_ID_CNT_001F, D_IPC_CALLBACK_FUNC_001F  },
    {  (uint16_t)e_IpcMsgId_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t              , D_SMBUFF_DATA_SIZE_0020, D_IPC_MSG_ID_CNT_0020, D_IPC_CALLBACK_FUNC_0020  },
    {  (uint16_t)e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t       , D_SMBUFF_DATA_SIZE_0021, D_IPC_MSG_ID_CNT_0021, D_IPC_CALLBACK_FUNC_0021  },
    {  (uint16_t)e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t                             , D_SMBUFF_DATA_SIZE_0025, D_IPC_MSG_ID_CNT_0025, D_IPC_CALLBACK_FUNC_0025  },
    {  (uint16_t)e_IpcMsgId_PpAPSMPAOut_TbAP_APSMPAOut_t                                    , D_SMBUFF_DATA_SIZE_0026, D_IPC_MSG_ID_CNT_0026, D_IPC_CALLBACK_FUNC_0026  },
    {  (uint16_t)e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t                  , D_SMBUFF_DATA_SIZE_0027, D_IPC_MSG_ID_CNT_0027, D_IPC_CALLBACK_FUNC_0027  },
    {  (uint16_t)e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t                                    , D_SMBUFF_DATA_SIZE_002C, D_IPC_MSG_ID_CNT_002C, D_IPC_CALLBACK_FUNC_002C  },
    {  (uint16_t)e_IpcMsgId_PpJobFPAData_IJobFPAOutput_t                                    , D_SMBUFF_DATA_SIZE_0032, D_IPC_MSG_ID_CNT_0032, D_IPC_CALLBACK_FUNC_0032  },
    {  (uint16_t)e_IpcMsgId_PpNFCDOutput_NFCD_Output                                        , D_SMBUFF_DATA_SIZE_0035, D_IPC_MSG_ID_CNT_0035, D_IPC_CALLBACK_FUNC_0035  },
    {  (uint16_t)e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t                  , D_SMBUFF_DATA_SIZE_0037, D_IPC_MSG_ID_CNT_0037, D_IPC_CALLBACK_FUNC_0037  },
    {  (uint16_t)e_IpcMsgId_PpSMDAInternal_TbAP_SMDAInternalOut_t                           , D_SMBUFF_DATA_SIZE_0038, D_IPC_MSG_ID_CNT_0038, D_IPC_CALLBACK_FUNC_0038  },
    {  (uint16_t)e_IpcMsgId_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t                            , D_SMBUFF_DATA_SIZE_0039, D_IPC_MSG_ID_CNT_0039, D_IPC_CALLBACK_FUNC_0039  },
    {  (uint16_t)e_IpcMsgId_PpFPAWarnOut_TbAP_FPAWarnOut_t                                  , D_SMBUFF_DATA_SIZE_003A, D_IPC_MSG_ID_CNT_003A, D_IPC_CALLBACK_FUNC_003A  },
    {  (uint16_t)e_IpcMsgId_PpRPAWarnOut_TbAP_RPAWarnOut_t                                  , D_SMBUFF_DATA_SIZE_003B, D_IPC_MSG_ID_CNT_003B, D_IPC_CALLBACK_FUNC_003B  },
    {  (uint16_t)e_IpcMsgId_PpPAStateOut_TbAP_PAStateOut_t                                  , D_SMBUFF_DATA_SIZE_003C, D_IPC_MSG_ID_CNT_003C, D_IPC_CALLBACK_FUNC_003C  },
    {  (uint16_t)e_IpcMsgId_PpVCActuatorOut_TbAP_VCActuatorOut_t                            , D_SMBUFF_DATA_SIZE_003D, D_IPC_MSG_ID_CNT_003D, D_IPC_CALLBACK_FUNC_003D  },
    {  (uint16_t)e_IpcMsgId_PpVCState_TbAP_VCStateOut_t                                     , D_SMBUFF_DATA_SIZE_003F, D_IPC_MSG_ID_CNT_003F, D_IPC_CALLBACK_FUNC_003F  },
    {  (uint16_t)e_IpcMsgId_PpUssPointMapGrp_US_S_PointMapGroup_t                           , D_SMBUFF_DATA_SIZE_0042, D_IPC_MSG_ID_CNT_0042, D_IPC_CALLBACK_FUNC_0042  },
    {  (uint16_t)e_IpcMsgId_PpSnrDirEcho_US_S_SnrDirEcho_t                                  , D_SMBUFF_DATA_SIZE_0043, D_IPC_MSG_ID_CNT_0043, D_IPC_CALLBACK_FUNC_0043  },
    {  (uint16_t)e_IpcMsgId_PpUssZoneInfo_US_S_ZoneInfo_t                                   , D_SMBUFF_DATA_SIZE_0044, D_IPC_MSG_ID_CNT_0044, D_IPC_CALLBACK_FUNC_0044  },
    {  (uint16_t)e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t                             , D_SMBUFF_DATA_SIZE_0045, D_IPC_MSG_ID_CNT_0045, D_IPC_CALLBACK_FUNC_0045  },
    {  (uint16_t)e_IpcMsgId_PpUSSConstantData_US_S_USSConstantData_t                        , D_SMBUFF_DATA_SIZE_0046, D_IPC_MSG_ID_CNT_0046, D_IPC_CALLBACK_FUNC_0046  },
    {  (uint16_t)e_IpcMsgId_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t                    , D_SMBUFF_DATA_SIZE_0047, D_IPC_MSG_ID_CNT_0047, D_IPC_CALLBACK_FUNC_0047  },
    {  (uint16_t)e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t                      , D_SMBUFF_DATA_SIZE_0048, D_IPC_MSG_ID_CNT_0048, D_IPC_CALLBACK_FUNC_0048  },
    {  (uint16_t)e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t                        , D_SMBUFF_DATA_SIZE_004B, D_IPC_MSG_ID_CNT_004B, D_IPC_CALLBACK_FUNC_004B  },
    {  (uint16_t)e_IpcMsgId_PpSVSToDiag_SVSToDiag_t                                         , D_SMBUFF_DATA_SIZE_004D, D_IPC_MSG_ID_CNT_004D, D_IPC_CALLBACK_FUNC_004D  },
    {  (uint16_t)e_IpcMsgId_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t                        , D_SMBUFF_DATA_SIZE_004E, D_IPC_MSG_ID_CNT_004E, D_IPC_CALLBACK_FUNC_004E  },
    {  (uint16_t)e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t                       , D_SMBUFF_DATA_SIZE_004F, D_IPC_MSG_ID_CNT_004F, D_IPC_CALLBACK_FUNC_004F  },
    {  (uint16_t)e_IpcMsgId_PpCamCsData_CAM_CS_Curr_Monitor_t                               , D_SMBUFF_DATA_SIZE_0051, D_IPC_MSG_ID_CNT_0051, D_IPC_CALLBACK_FUNC_0051  },
    {  (uint16_t)e_IpcMsgId_PpUssMrrgData_US_S_MarriageSensorIDs_t                          , D_SMBUFF_DATA_SIZE_0052, D_IPC_MSG_ID_CNT_0052, D_IPC_CALLBACK_FUNC_0052  },
    {  (uint16_t)e_IpcMsgId_PpTrscToDiag_TRSCtoDiagMgr_t                                    , D_SMBUFF_DATA_SIZE_0054, D_IPC_MSG_ID_CNT_0054, D_IPC_CALLBACK_FUNC_0054  },
    {  (uint16_t)e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t                 , D_SMBUFF_DATA_SIZE_0055, D_IPC_MSG_ID_CNT_0055, D_IPC_CALLBACK_FUNC_0055  },
    {  (uint16_t)e_IpcMsgId_PpUssDataCollection_US_S_USSDataCollectionData_t                , D_SMBUFF_DATA_SIZE_0060, D_IPC_MSG_ID_CNT_0060, D_IPC_CALLBACK_FUNC_0060  },
    {  (uint16_t)e_IpcMsgId_PpPointDistOpBuff_US_S_PointDistOutputBuff_t                    , D_SMBUFF_DATA_SIZE_0061, D_IPC_MSG_ID_CNT_0061, D_IPC_CALLBACK_FUNC_0061  },
    {  (uint16_t)e_IpcMsgId_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t                                 , D_SMBUFF_DATA_SIZE_0062, D_IPC_MSG_ID_CNT_0062, D_IPC_CALLBACK_FUNC_0062  },
    {  (uint16_t)e_IpcMsgId_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t                                 , D_SMBUFF_DATA_SIZE_0063, D_IPC_MSG_ID_CNT_0063, D_IPC_CALLBACK_FUNC_0063  },
    {  (uint16_t)e_IpcMsgId_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t                         , D_SMBUFF_DATA_SIZE_0067, D_IPC_MSG_ID_CNT_0067, D_IPC_CALLBACK_FUNC_0067  },
    {  (uint16_t)e_IpcMsgId_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t                        , D_SMBUFF_DATA_SIZE_0068, D_IPC_MSG_ID_CNT_0068, D_IPC_CALLBACK_FUNC_0068  },
    {  (uint16_t)e_IpcMsgId_PpSVSNVMData_SVS_NVMData_t                                      , D_SMBUFF_DATA_SIZE_0069, D_IPC_MSG_ID_CNT_0069, D_IPC_CALLBACK_FUNC_0069  },
    {  (uint16_t)e_IpcMsgId_PpTbAPDebugOut_TbAP_DebugOut                                    , D_SMBUFF_DATA_SIZE_006B, D_IPC_MSG_ID_CNT_006B, D_IPC_CALLBACK_FUNC_006B  },
    {  (uint16_t)e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t               , D_SMBUFF_DATA_SIZE_006C, D_IPC_MSG_ID_CNT_006C, D_IPC_CALLBACK_FUNC_006C  },
    {  (uint16_t)e_IpcMsgId_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t               , D_SMBUFF_DATA_SIZE_006D, D_IPC_MSG_ID_CNT_006D, D_IPC_CALLBACK_FUNC_006D  },
    {  (uint16_t)e_IpcMsgId_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t               , D_SMBUFF_DATA_SIZE_006E, D_IPC_MSG_ID_CNT_006E, D_IPC_CALLBACK_FUNC_006E  },
    {  (uint16_t)e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s                                  , D_SMBUFF_DATA_SIZE_0070, D_IPC_MSG_ID_CNT_0070, D_IPC_CALLBACK_FUNC_0070  },
    {  (uint16_t)e_IpcMsgId_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t                             , D_SMBUFF_DATA_SIZE_0071, D_IPC_MSG_ID_CNT_0071, D_IPC_CALLBACK_FUNC_0071  },
    {  (uint16_t)e_IpcMsgId_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t                  , D_SMBUFF_DATA_SIZE_007B, D_IPC_MSG_ID_CNT_007B, D_IPC_CALLBACK_FUNC_007B  },
    {  (uint16_t)e_IpcMsgId_PpIDebugFODObject_IDebug_FODObject_t                            , D_SMBUFF_DATA_SIZE_007C, D_IPC_MSG_ID_CNT_007C, D_IPC_CALLBACK_FUNC_007C  },
    {  (uint16_t)e_IpcMsgId_PpTbFAResetKM_TbFA_ResetKM_t                                    , D_SMBUFF_DATA_SIZE_007E, D_IPC_MSG_ID_CNT_007E, D_IPC_CALLBACK_FUNC_007E  },
    {  (uint16_t)e_IpcMsgId_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t                           , D_SMBUFF_DATA_SIZE_007F, D_IPC_MSG_ID_CNT_007F, D_IPC_CALLBACK_FUNC_007F  },
    {  (uint16_t)e_IpcMsgId_PpCamSerENStat_Cam_and_Ser_EN_Status_t                          , D_SMBUFF_DATA_SIZE_0082, D_IPC_MSG_ID_CNT_0082, D_IPC_CALLBACK_FUNC_0082  },
    {  (uint16_t)e_IpcMsgId_PpDLDOutput_JobDLDOutput_t                                      , D_SMBUFF_DATA_SIZE_0084, D_IPC_MSG_ID_CNT_0084, D_IPC_CALLBACK_FUNC_0084  },
    {  (uint16_t)e_IpcMsgId_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t                          , D_SMBUFF_DATA_SIZE_0086, D_IPC_MSG_ID_CNT_0086, D_IPC_CALLBACK_FUNC_0086  },
    {  (uint16_t)e_IpcMsgId_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type                , D_SMBUFF_DATA_SIZE_0088, D_IPC_MSG_ID_CNT_0088, D_IPC_CALLBACK_FUNC_0088  },
    {  (uint16_t)e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t                         , D_SMBUFF_DATA_SIZE_0089, D_IPC_MSG_ID_CNT_0089, D_IPC_CALLBACK_FUNC_0089  },
    {  (uint16_t)e_IpcMsgId_PpUssDebugMsg_US_S_DebugMsg_t                                   , D_SMBUFF_DATA_SIZE_008A, D_IPC_MSG_ID_CNT_008A, D_IPC_CALLBACK_FUNC_008A  },
    {  (uint16_t)e_IpcMsgId_PpCAMSelInfo_CAM_select_info_t                                  , D_SMBUFF_DATA_SIZE_008B, D_IPC_MSG_ID_CNT_008B, D_IPC_CALLBACK_FUNC_008B  },
    {  (uint16_t)e_IpcMsgId_PpErrFltMcu2_0_Error_Fault_MCU2_0_t                             , D_SMBUFF_DATA_SIZE_008C, D_IPC_MSG_ID_CNT_008C, D_IPC_CALLBACK_FUNC_008C  },
    {  (uint16_t)e_IpcMsgId_PpErrFltMcu2_1_Error_Fault_MCU2_1_t                             , D_SMBUFF_DATA_SIZE_008D, D_IPC_MSG_ID_CNT_008D, D_IPC_CALLBACK_FUNC_008D  },
    {  (uint16_t)e_IpcMsgId_PpErrFltMpu1_0_Error_Fault_MPU1_0_t                             , D_SMBUFF_DATA_SIZE_008E, D_IPC_MSG_ID_CNT_008E, D_IPC_CALLBACK_FUNC_008E  },
    {  (uint16_t)e_IpcMsgId_PpUssTunData_UssTunningData_mcu2_1_t                            , D_SMBUFF_DATA_SIZE_0091, D_IPC_MSG_ID_CNT_0091, D_IPC_CALLBACK_FUNC_0091  },
    {  (uint16_t)e_IpcMsgId_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t                     , D_SMBUFF_DATA_SIZE_0092, D_IPC_MSG_ID_CNT_0092, D_IPC_CALLBACK_FUNC_0092  },
    {  (uint16_t)e_IpcMsgId_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t                     , D_SMBUFF_DATA_SIZE_0093, D_IPC_MSG_ID_CNT_0093, D_IPC_CALLBACK_FUNC_0093  },
    {  (uint16_t)e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t                     , D_SMBUFF_DATA_SIZE_0095, D_IPC_MSG_ID_CNT_0095, D_IPC_CALLBACK_FUNC_0095  },
    {  (uint16_t)e_IpcMsgId_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t                         , D_SMBUFF_DATA_SIZE_0097, D_IPC_MSG_ID_CNT_0097, D_IPC_CALLBACK_FUNC_0097  },
    {  (uint16_t)e_IpcMsgId_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t                         , D_SMBUFF_DATA_SIZE_0098, D_IPC_MSG_ID_CNT_0098, D_IPC_CALLBACK_FUNC_0098  },
#endif

#if defined(BUILD_MCU2_0)
    {  (uint16_t)e_IpcMsgId_PpScreenResponse_ScreenResponse_t                               , D_SMBUFF_DATA_SIZE_0006, D_IPC_MSG_ID_CNT_0006, D_IPC_CALLBACK_FUNC_0006  },
    {  (uint16_t)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f                                  , D_SMBUFF_DATA_SIZE_0007, D_IPC_MSG_ID_CNT_0007, D_IPC_CALLBACK_FUNC_0007  },
    {  (uint16_t)e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t               , D_SMBUFF_DATA_SIZE_000E, D_IPC_MSG_ID_CNT_000E, D_IPC_CALLBACK_FUNC_000E  },
    {  (uint16_t)e_IpcMsgId_data_MeDLD_e_RrCamSts_t                                         , D_SMBUFF_DATA_SIZE_000F, D_IPC_MSG_ID_CNT_000F, D_IPC_CALLBACK_FUNC_000F  },
    {  (uint16_t)e_IpcMsgId_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t                                 , D_SMBUFF_DATA_SIZE_0012, D_IPC_MSG_ID_CNT_0012, D_IPC_CALLBACK_FUNC_0012  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_1                                       , D_SMBUFF_DATA_SIZE_0015, D_IPC_MSG_ID_CNT_0015, D_IPC_CALLBACK_FUNC_0015  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_QNX_State_QNX                                        , D_SMBUFF_DATA_SIZE_0016, D_IPC_MSG_ID_CNT_0016, D_IPC_CALLBACK_FUNC_0016  },
    {  (uint16_t)e_IpcMsgId_Data_SSM_SystemState                                            , D_SMBUFF_DATA_SIZE_0017, D_IPC_MSG_ID_CNT_0017, D_IPC_CALLBACK_FUNC_0017  },
    {  (uint16_t)e_IpcMsgId_Data_CalDataProvider_MCU_2_0_Def                                , D_SMBUFF_DATA_SIZE_0019, D_IPC_MSG_ID_CNT_0019, D_IPC_CALLBACK_FUNC_0019  },
    {  (uint16_t)e_IpcMsgId_Data_ME_Proxi_to_IpcSignals_t                                   , D_SMBUFF_DATA_SIZE_0024, D_IPC_MSG_ID_CNT_0024, D_IPC_CALLBACK_FUNC_0024  },
    {  (uint16_t)e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t                             , D_SMBUFF_DATA_SIZE_0025, D_IPC_MSG_ID_CNT_0025, D_IPC_CALLBACK_FUNC_0025  },
    {  (uint16_t)e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t                  , D_SMBUFF_DATA_SIZE_0027, D_IPC_MSG_ID_CNT_0027, D_IPC_CALLBACK_FUNC_0027  },
    {  (uint16_t)e_IpcMsgId_Data_IFPAInfoToHMI_t                                            , D_SMBUFF_DATA_SIZE_0028, D_IPC_MSG_ID_CNT_0028, D_IPC_CALLBACK_FUNC_0028  },
    {  (uint16_t)e_IpcMsgId_Data_IKinematicData_t                                           , D_SMBUFF_DATA_SIZE_002F, D_IPC_MSG_ID_CNT_002F, D_IPC_CALLBACK_FUNC_002F  },
    {  (uint16_t)e_IpcMsgId_Data_ExtY_Kinematic_T                                           , D_SMBUFF_DATA_SIZE_0030, D_IPC_MSG_ID_CNT_0030, D_IPC_CALLBACK_FUNC_0030  },
    {  (uint16_t)e_IpcMsgId_PpJobFPAData_IJobFPAOutput_t                                    , D_SMBUFF_DATA_SIZE_0032, D_IPC_MSG_ID_CNT_0032, D_IPC_CALLBACK_FUNC_0032  },
    {  (uint16_t)e_IpcMsgId_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t                            , D_SMBUFF_DATA_SIZE_0039, D_IPC_MSG_ID_CNT_0039, D_IPC_CALLBACK_FUNC_0039  },
    {  (uint16_t)e_IpcMsgId_PpFPAWarnOut_TbAP_FPAWarnOut_t                                  , D_SMBUFF_DATA_SIZE_003A, D_IPC_MSG_ID_CNT_003A, D_IPC_CALLBACK_FUNC_003A  },
    {  (uint16_t)e_IpcMsgId_PpRPAWarnOut_TbAP_RPAWarnOut_t                                  , D_SMBUFF_DATA_SIZE_003B, D_IPC_MSG_ID_CNT_003B, D_IPC_CALLBACK_FUNC_003B  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_QM                                              , D_SMBUFF_DATA_SIZE_0040, D_IPC_MSG_ID_CNT_0040, D_IPC_CALLBACK_FUNC_0040  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_B                                               , D_SMBUFF_DATA_SIZE_0041, D_IPC_MSG_ID_CNT_0041, D_IPC_CALLBACK_FUNC_0041  },
    {  (uint16_t)e_IpcMsgId_Data_DiagToSVS_t                                                , D_SMBUFF_DATA_SIZE_004C, D_IPC_MSG_ID_CNT_004C, D_IPC_CALLBACK_FUNC_004C  },
    {  (uint16_t)e_IpcMsgId_Data_CAM_Curr_Volt_Monitor_t                                    , D_SMBUFF_DATA_SIZE_0050, D_IPC_MSG_ID_CNT_0050, D_IPC_CALLBACK_FUNC_0050  },
    {  (uint16_t)e_IpcMsgId_Data_USS_PowerSelect_t                                          , D_SMBUFF_DATA_SIZE_0059, D_IPC_MSG_ID_CNT_0059, D_IPC_CALLBACK_FUNC_0059  },
    {  (uint16_t)e_IpcMsgId_Data_ME_ProxiToMCU2_0_Def_t                                     , D_SMBUFF_DATA_SIZE_005C, D_IPC_MSG_ID_CNT_005C, D_IPC_CALLBACK_FUNC_005C  },
    {  (uint16_t)e_IpcMsgId_Data_TrscDebug_ScrRes_t                                         , D_SMBUFF_DATA_SIZE_005E, D_IPC_MSG_ID_CNT_005E, D_IPC_CALLBACK_FUNC_005E  },
    {  (uint16_t)e_IpcMsgId_Data_ME_CanDebugRIDStatus_t                                     , D_SMBUFF_DATA_SIZE_0065, D_IPC_MSG_ID_CNT_0065, D_IPC_CALLBACK_FUNC_0065  },
    {  (uint16_t)e_IpcMsgId_Data_SVS_NVMData_t                                              , D_SMBUFF_DATA_SIZE_0066, D_IPC_MSG_ID_CNT_0066, D_IPC_CALLBACK_FUNC_0066  },
    {  (uint16_t)e_IpcMsgId_Data_SVS_Calibration_data_t                                     , D_SMBUFF_DATA_SIZE_0077, D_IPC_MSG_ID_CNT_0077, D_IPC_CALLBACK_FUNC_0077  },
    {  (uint16_t)e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToHmi_t                                  , D_SMBUFF_DATA_SIZE_0080, D_IPC_MSG_ID_CNT_0080, D_IPC_CALLBACK_FUNC_0080  },
    {  (uint16_t)e_IpcMsgId_Data_TrailerDetection_Output_HMI_t                              , D_SMBUFF_DATA_SIZE_0083, D_IPC_MSG_ID_CNT_0083, D_IPC_CALLBACK_FUNC_0083  },
    {  (uint16_t)e_IpcMsgId_Data_TimeManagerProxy_TimeStamp_t                               , D_SMBUFF_DATA_SIZE_0087, D_IPC_MSG_ID_CNT_0087, D_IPC_CALLBACK_FUNC_0087  },
    {  (uint16_t)e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t                         , D_SMBUFF_DATA_SIZE_0089, D_IPC_MSG_ID_CNT_0089, D_IPC_CALLBACK_FUNC_0089  },
    {  (uint16_t)e_IpcMsgId_Data_PerformanceStatsEnable_t                                   , D_SMBUFF_DATA_SIZE_0094, D_IPC_MSG_ID_CNT_0094, D_IPC_CALLBACK_FUNC_0094  },
#endif

#if defined(BUILD_MCU2_1)
    {  (uint16_t)e_IpcMsgId_PpSvsToVCAN_SvsToVCAN_t                                         , D_SMBUFF_DATA_SIZE_0002, D_IPC_MSG_ID_CNT_0002, D_IPC_CALLBACK_FUNC_0002  },
    {  (uint16_t)e_IpcMsgId_PpScreenRequest_ScreenRequest_t                                 , D_SMBUFF_DATA_SIZE_0004, D_IPC_MSG_ID_CNT_0004, D_IPC_CALLBACK_FUNC_0004  },
    {  (uint16_t)e_IpcMsgId_PpSvsToTHA_SvsToTHA_t                                           , D_SMBUFF_DATA_SIZE_0005, D_IPC_MSG_ID_CNT_0005, D_IPC_CALLBACK_FUNC_0005  },
    {  (uint16_t)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f                                  , D_SMBUFF_DATA_SIZE_0007, D_IPC_MSG_ID_CNT_0007, D_IPC_CALLBACK_FUNC_0007  },
    {  (uint16_t)e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t               , D_SMBUFF_DATA_SIZE_000E, D_IPC_MSG_ID_CNT_000E, D_IPC_CALLBACK_FUNC_000E  },
    {  (uint16_t)e_IpcMsgId_data_SVStoTRSCSMVC_t                                            , D_SMBUFF_DATA_SIZE_0011, D_IPC_MSG_ID_CNT_0011, D_IPC_CALLBACK_FUNC_0011  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_MCU2_State_2_0                                       , D_SMBUFF_DATA_SIZE_0014, D_IPC_MSG_ID_CNT_0014, D_IPC_CALLBACK_FUNC_0014  },
    {  (uint16_t)e_IpcMsgId_PpSR_State_QNX_State_QNX                                        , D_SMBUFF_DATA_SIZE_0016, D_IPC_MSG_ID_CNT_0016, D_IPC_CALLBACK_FUNC_0016  },
    {  (uint16_t)e_IpcMsgId_Data_SSM_SystemState                                            , D_SMBUFF_DATA_SIZE_0017, D_IPC_MSG_ID_CNT_0017, D_IPC_CALLBACK_FUNC_0017  },
    {  (uint16_t)e_IpcMsgId_Data_CalDataProvider_MCU_2_1_Def                                , D_SMBUFF_DATA_SIZE_001A, D_IPC_MSG_ID_CNT_001A, D_IPC_CALLBACK_FUNC_001A  },
    {  (uint16_t)e_IpcMsgId_Data_ME_Proxi_to_IpcSignals_t                                   , D_SMBUFF_DATA_SIZE_0024, D_IPC_MSG_ID_CNT_0024, D_IPC_CALLBACK_FUNC_0024  },
    {  (uint16_t)e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t                             , D_SMBUFF_DATA_SIZE_0025, D_IPC_MSG_ID_CNT_0025, D_IPC_CALLBACK_FUNC_0025  },
    {  (uint16_t)e_IpcMsgId_Data_IHMIInfoToFPA_t                                            , D_SMBUFF_DATA_SIZE_002B, D_IPC_MSG_ID_CNT_002B, D_IPC_CALLBACK_FUNC_002B  },
    {  (uint16_t)e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t                                    , D_SMBUFF_DATA_SIZE_002C, D_IPC_MSG_ID_CNT_002C, D_IPC_CALLBACK_FUNC_002C  },
    {  (uint16_t)e_IpcMsgId_Data_IKinematicData_t                                           , D_SMBUFF_DATA_SIZE_002F, D_IPC_MSG_ID_CNT_002F, D_IPC_CALLBACK_FUNC_002F  },
    {  (uint16_t)e_IpcMsgId_Data_ExtY_Kinematic_T                                           , D_SMBUFF_DATA_SIZE_0030, D_IPC_MSG_ID_CNT_0030, D_IPC_CALLBACK_FUNC_0030  },
    {  (uint16_t)e_IpcMsgId_Data_IParkingSlotInformation_t                                  , D_SMBUFF_DATA_SIZE_0031, D_IPC_MSG_ID_CNT_0031, D_IPC_CALLBACK_FUNC_0031  },
    {  (uint16_t)e_IpcMsgId_Data_IParkingSlotID_t                                           , D_SMBUFF_DATA_SIZE_0034, D_IPC_MSG_ID_CNT_0034, D_IPC_CALLBACK_FUNC_0034  },
    {  (uint16_t)e_IpcMsgId_Data_MOT_Output                                                 , D_SMBUFF_DATA_SIZE_0036, D_IPC_MSG_ID_CNT_0036, D_IPC_CALLBACK_FUNC_0036  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_QM                                              , D_SMBUFF_DATA_SIZE_0040, D_IPC_MSG_ID_CNT_0040, D_IPC_CALLBACK_FUNC_0040  },
    {  (uint16_t)e_IpcMsgId_Data_FID_STRUCT_B                                               , D_SMBUFF_DATA_SIZE_0041, D_IPC_MSG_ID_CNT_0041, D_IPC_CALLBACK_FUNC_0041  },
    {  (uint16_t)e_IpcMsgId_Data_USS_Curr_Volt_Monitor_t                                    , D_SMBUFF_DATA_SIZE_0049, D_IPC_MSG_ID_CNT_0049, D_IPC_CALLBACK_FUNC_0049  },
    {  (uint16_t)e_IpcMsgId_Data_US_S_MarriageSensorIDs_t                                   , D_SMBUFF_DATA_SIZE_0053, D_IPC_MSG_ID_CNT_0053, D_IPC_CALLBACK_FUNC_0053  },
    {  (uint16_t)e_IpcMsgId_Data_HMIInfoToAP_t                                              , D_SMBUFF_DATA_SIZE_0057, D_IPC_MSG_ID_CNT_0057, D_IPC_CALLBACK_FUNC_0057  },
    {  (uint16_t)e_IpcMsgId_Data_DiagToParkAssist_t                                         , D_SMBUFF_DATA_SIZE_0058, D_IPC_MSG_ID_CNT_0058, D_IPC_CALLBACK_FUNC_0058  },
    {  (uint16_t)e_IpcMsgId_Data1_USS_PowerSelect_t                                         , D_SMBUFF_DATA_SIZE_005A, D_IPC_MSG_ID_CNT_005A, D_IPC_CALLBACK_FUNC_005A  },
    {  (uint16_t)e_IpcMsgId_Data_ME_ProxiToMCU2_1_Def_t                                     , D_SMBUFF_DATA_SIZE_005D, D_IPC_MSG_ID_CNT_005D, D_IPC_CALLBACK_FUNC_005D  },
    {  (uint16_t)e_IpcMsgId_Data_TbNVM_ReadParam                                            , D_SMBUFF_DATA_SIZE_0064, D_IPC_MSG_ID_CNT_0064, D_IPC_CALLBACK_FUNC_0064  },
    {  (uint16_t)e_IpcMsgId_Data_ME_CanDebugRIDStatus_t                                     , D_SMBUFF_DATA_SIZE_0065, D_IPC_MSG_ID_CNT_0065, D_IPC_CALLBACK_FUNC_0065  },
    {  (uint16_t)e_IpcMsgId_Data_USS_Calibration_Data_t                                     , D_SMBUFF_DATA_SIZE_006A, D_IPC_MSG_ID_CNT_006A, D_IPC_CALLBACK_FUNC_006A  },
    {  (uint16_t)e_IpcMsgId_Data_THA_Calibration_data_MCU2_1_t                              , D_SMBUFF_DATA_SIZE_0072, D_IPC_MSG_ID_CNT_0072, D_IPC_CALLBACK_FUNC_0072  },
    {  (uint16_t)e_IpcMsgId_Data_TRSC_Calibration_data_MCU2_1_t                             , D_SMBUFF_DATA_SIZE_0074, D_IPC_MSG_ID_CNT_0074, D_IPC_CALLBACK_FUNC_0074  },
    {  (uint16_t)e_IpcMsgId_Data_APA_Calibration_data_MCU2_1_t                              , D_SMBUFF_DATA_SIZE_0076, D_IPC_MSG_ID_CNT_0076, D_IPC_CALLBACK_FUNC_0076  },
    {  (uint16_t)e_IpcMsgId_Data_SVS_Calibration_data_t                                     , D_SMBUFF_DATA_SIZE_0077, D_IPC_MSG_ID_CNT_0077, D_IPC_CALLBACK_FUNC_0077  },
    {  (uint16_t)e_IpcMsgId_Data_FOD_Calibration_data_t                                     , D_SMBUFF_DATA_SIZE_0078, D_IPC_MSG_ID_CNT_0078, D_IPC_CALLBACK_FUNC_0078  },
    {  (uint16_t)e_IpcMsgId_Data_LMD_Calibration_data_t                                     , D_SMBUFF_DATA_SIZE_0079, D_IPC_MSG_ID_CNT_0079, D_IPC_CALLBACK_FUNC_0079  },
    {  (uint16_t)e_IpcMsgId_Data_USS_Calibration_data_2_t                                   , D_SMBUFF_DATA_SIZE_0081, D_IPC_MSG_ID_CNT_0081, D_IPC_CALLBACK_FUNC_0081  },
    {  (uint16_t)e_IpcMsgId_Data_INVMSignalManager_t                                        , D_SMBUFF_DATA_SIZE_0085, D_IPC_MSG_ID_CNT_0085, D_IPC_CALLBACK_FUNC_0085  },
    {  (uint16_t)e_IpcMsgId_Data_TimeManagerProxy_TimeStamp_t                               , D_SMBUFF_DATA_SIZE_0087, D_IPC_MSG_ID_CNT_0087, D_IPC_CALLBACK_FUNC_0087  },
    {  (uint16_t)e_IpcMsgId_Data_UssTunningData_mcu1_0_t                                    , D_SMBUFF_DATA_SIZE_0090, D_IPC_MSG_ID_CNT_0090, D_IPC_CALLBACK_FUNC_0090  },
    {  (uint16_t)e_IpcMsgId_Data_PerformanceStatsEnable_t                                   , D_SMBUFF_DATA_SIZE_0094, D_IPC_MSG_ID_CNT_0094, D_IPC_CALLBACK_FUNC_0094  },
#endif

#if defined(BUILD_MCU3_0)
#endif

#if defined(BUILD_MCU3_1)
#endif

#if defined(BUILD_C66x_1)
#endif

#if defined(BUILD_C66x_2)
#endif
};
#endif

/* ===========================================================================
*
*   Private functions definition
*
* ========================================================================= */
/* Callback function definition */

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0001(const void* i_msgData_ps)
{
    /* DD-ID :{579EA45E-7DAA-4303-8E1F-F099810EBBDE}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_data_SvsToTHADet_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_data_SvsToTHADet_t((const SvsToTHADet_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_data_SvsToTHADet_t_Put((SvsToTHADet_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0002(const void* i_msgData_ps)
{
    /* DD-ID :{01B7301C-E568-4794-89C3-05A146A5C98E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSvsToVCAN_SvsToVCAN_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSvsToVCAN_SvsToVCAN_t((const SvsToVCAN_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put((SvsToVCAN_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0003(const void* i_msgData_ps)
{
    /* DD-ID :{B21F24D3-AACD-4952-B962-0EE665A71AA0}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVStoTRSC_SVStoTRSC_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVStoTRSC_SVStoTRSC_t((const SVStoTRSC_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVStoTRSC_SVStoTRSC_t_Put((SVStoTRSC_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0004(const void* i_msgData_ps)
{
    /* DD-ID :{624A973C-400B-437f-A924-8B36E0FF24EF}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpScreenRequest_ScreenRequest_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpScreenRequest_ScreenRequest_t((const ScreenRequest_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpScreenRequest_ScreenRequest_t_Put((ScreenRequest_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0005(const void* i_msgData_ps)
{
    /* DD-ID :{DFC94886-4B33-44cc-A96A-40D5A9668B3E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSvsToTHA_SvsToTHA_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSvsToTHA_SvsToTHA_t((const SvsToTHA_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSvsToTHA_SvsToTHA_t_Put((SvsToTHA_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0006(const void* i_msgData_ps)
{
    /* DD-ID :{B1159E9B-9B23-4f27-8642-275E459525D0}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpScreenResponse_ScreenResponse_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpScreenResponse_ScreenResponse_t((const ScreenResponse_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpScreenResponse_ScreenResponse_t_Put((ScreenResponse_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0007(const void* i_msgData_ps)
{
    /* DD-ID :{9F69E912-4DD4-474a-AF9B-111401797B1E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_ME_VehInp_to_IpcSignals_data_f((const ME_VehInp_to_IpcSignals_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_ME_VehInp_to_IpcSignals_data_f_Put((ME_VehInp_to_IpcSignals_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0008(const void* i_msgData_ps)
{
    /* DD-ID :{31C2F669-6A91-426d-A52F-FD31750DEBDE}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM((const ErrorMgr_ErrorCommPack_2_0_QM*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Put((ErrorMgr_ErrorCommPack_2_0_QM*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0009(const void* i_msgData_ps)
{
    /* DD-ID :{74A38092-CB0F-45b9-A926-BD7E98BB94CB}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B((const ErrorMgr_ErrorCommPack_2_0_B*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Put((ErrorMgr_ErrorCommPack_2_0_B*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000A(const void* i_msgData_ps)
{
    /* DD-ID :{F34A0DAB-191E-4fe1-BA33-73A0BAC50C3C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM((const ErrorMgr_ErrorCommPack_2_1_QM*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Put((ErrorMgr_ErrorCommPack_2_1_QM*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000B(const void* i_msgData_ps)
{
    /* DD-ID :{EAB72C20-6CAD-4b53-A564-8EFCCEC25C0D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B((const ErrorMgr_ErrorCommPack_2_1_B*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Put((ErrorMgr_ErrorCommPack_2_1_B*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000C(const void* i_msgData_ps)
{
    /* DD-ID :{400A24E3-8AC9-4af1-9F5A-06A1D57731A6}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM((const ErrorMgr_ErrorCommPack_QNX_QM*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM_Put((ErrorMgr_ErrorCommPack_QNX_QM*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_000D(const void* i_msgData_ps)
{
    /* DD-ID :{F609CFBD-6BE9-4496-B4BB-99FB2F935682}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B((const ErrorMgr_ErrorCommPack_QNX_B*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B_Put((ErrorMgr_ErrorCommPack_QNX_B*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_000E(const void* i_msgData_ps)
{
    /* DD-ID :{E0D4CA33-2886-4e22-A3F9-E4C9ACBC512A}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t((const TRSC_Inputs_from_TrailerDetection_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Put((TRSC_Inputs_from_TrailerDetection_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_000F(const void* i_msgData_ps)
{
    /* DD-ID :{151616D4-0D5F-419a-8D57-64B86ADE9C1C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_data_MeDLD_e_RrCamSts_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_data_MeDLD_e_RrCamSts_t((const MeDLD_e_RrCamSts_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_data_MeDLD_e_RrCamSts_t_Put((MeDLD_e_RrCamSts_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0010(const void* i_msgData_ps)
{
    /* DD-ID :{9AD782DC-9C2A-466d-AD35-21EDBC99B92D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTRSC_ME_VehOut_TRSC_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTRSC_ME_VehOut_TRSC_t((const ME_VehOut_TRSC_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put((ME_VehOut_TRSC_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0011(const void* i_msgData_ps)
{
	 /* DD-ID :{FC44E27B-6223-4bdb-9076-4A4212B90DC0}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_data_SVStoTRSCSMVC_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_data_SVStoTRSCSMVC_t((const SVStoTRSCSMVC_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_data_SVStoTRSCSMVC_t_Put((SVStoTRSCSMVC_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0012(const void* i_msgData_ps)
{
   /* DD-ID :{F1D55D1C-337C-435a-A434-DAF73FB982F0}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t((const TRSCSMVCtoSVS_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put((TRSCSMVCtoSVS_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0013(const void* i_msgData_ps)
{
    /* DD-ID :{E0394E1D-8A28-4662-B98B-E159FE8A301A}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpDetInpTrsc_Detection_Inputs_from_TRSC_t((const Detection_Inputs_from_TRSC_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put((Detection_Inputs_from_TRSC_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0014(const void* i_msgData_ps)
{
    /* DD-ID :{763E5CEE-234D-4a7e-B069-3C118D4609EB}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSR_State_MCU2_State_2_0);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSR_State_MCU2_State_2_0((const SSM_2_0_CoreStatus*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSR_State_MCU2_State_2_0_Put((SSM_2_0_CoreStatus*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0015(const void* i_msgData_ps)
{
    /* DD-ID :{7FD09C53-EBB8-4133-A233-211527009B8B}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSR_State_MCU2_State_2_1);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSR_State_MCU2_State_2_1((const SSM_2_1_CoreStatus*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSR_State_MCU2_State_2_1_Put((SSM_2_1_CoreStatus*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0016(const void* i_msgData_ps)
{
    /* DD-ID :{EDBCE478-F3DB-46b7-8211-15D3BB7953D2}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSR_State_QNX_State_QNX);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSR_State_QNX_State_QNX((const SSM_QNX_CoreStatus*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSR_State_QNX_State_QNX_Put((SSM_QNX_CoreStatus*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0017(const void* i_msgData_ps)
{
    /* DD-ID :{FC341E12-41DB-464f-A9A1-25B53A702C2B}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_SSM_SystemState);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_SSM_SystemState((const SSM_SystemState*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_SSM_SystemState_Put((SSM_SystemState*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0018(const void* i_msgData_ps)
{
  /* DD-ID :{7625642C-2605-4ee4-9954-037D519276A8}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_CalDataProvider_MPU_1_0_Def((const CalDataProvider_MPU_1_0_Def*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_CalDataProvider_MPU_1_0_Def_Put((CalDataProvider_MPU_1_0_Def*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0019(const void* i_msgData_ps)
{
    /* DD-ID :{E5270EC8-1999-4d97-9392-806830D83A0B}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_CalDataProvider_MCU_2_0_Def);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_CalDataProvider_MCU_2_0_Def((const CalDataProvider_MCU_2_0_Def*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_CalDataProvider_MCU_2_0_Def_Put((CalDataProvider_MCU_2_0_Def*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_001A(const void* i_msgData_ps)
{
     /*DD-ID:{835C9AB5-9282-4262-B706-76FCCE8BFB6E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_CalDataProvider_MCU_2_1_Def);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_CalDataProvider_MCU_2_1_Def((const CalDataProvider_MCU_2_1_Def*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_CalDataProvider_MCU_2_1_Def_Put((CalDataProvider_MCU_2_1_Def*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_001D(const void* i_msgData_ps)
{
    /* DD-ID :{FBE75AB9-986D-47ad-AD4C-A7EA2E857B5D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t((const TbSVS_S_SVSCamCurrentCalibDataToNVM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_Put((TbSVS_S_SVSCamCurrentCalibDataToNVM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_001E(const void* i_msgData_ps)
{
    /* DD-ID :{658C2DD4-3B2C-42db-B4AE-581916EBF4C3}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t((const TbSVS_S_SVSCamOCCalibDataToNVM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t_Put((TbSVS_S_SVSCamOCCalibDataToNVM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_001F(const void* i_msgData_ps)
{
    /* DD-ID :{4A49BD7D-F9AE-4a00-8362-BAF5E1272EBB}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t((const TbSVS_S_SVSCamSCCalibDataToNVM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t_Put((TbSVS_S_SVSCamSCCalibDataToNVM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0020(const void* i_msgData_ps)
{
    /* DD-ID :{629887D9-24D0-496f-BBF3-3033C5569729}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t((const TbSVS_S_SVSCamEOLCalibDataToNVM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t_Put((TbSVS_S_SVSCamEOLCalibDataToNVM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0021(const void* i_msgData_ps)
{
    /* DD-ID :{DCF90B04-0D43-4f78-A050-2C10D2A2734D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t((const TbSVS_e_SVSOutputToDiagMgrCamCalib_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_Put((TbSVS_e_SVSOutputToDiagMgrCamCalib_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0022(const void* i_msgData_ps)
{
    /* DD-ID :{C4B699B6-D052-44b9-83D4-9A0C68CDB191}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t((const TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t_Put((TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0023(const void* i_msgData_ps)
{
    /* DD-ID :{071F742E-184C-4b0f-A8B0-41A185C6B530}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t((const TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t_Put((TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0024(const void* i_msgData_ps)
{
    /* DD-ID :{AC4C435E-8F1B-4c1d-BDBD-ADDE75D28ACC}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_ME_Proxi_to_IpcSignals_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_ME_Proxi_to_IpcSignals_t((const ME_Proxi_to_IpcSignals_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_ME_Proxi_to_IpcSignals_t_Put((ME_Proxi_to_IpcSignals_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0025(const void* i_msgData_ps)
{
    /* DD-ID :{0151A54D-CF12-4693-BAE5-37391C2DA3B2}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t((const JobTHADetOutput_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Put((JobTHADetOutput_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0026(const void* i_msgData_ps)
{
	/* DD-ID: {0C963707-83A4-45f0-8ACA-492A800D8838} */
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpAPSMPAOut_TbAP_APSMPAOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpAPSMPAOut_TbAP_APSMPAOut_t((const TbAP_APSMPAOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put((TbAP_APSMPAOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0027(const void* i_msgData_ps)
{
    /* DD-ID:{31DC40F6-A1FA-4055-9E9D-278C9926E056}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t((const TbTHASmVc_FeatureOutputs_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put((TbTHASmVc_FeatureOutputs_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0028(const void* i_msgData_ps)
{
    /* DD-ID :{5EC62728-6DE6-4c36-817E-96D632EE33A1}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_IFPAInfoToHMI_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_IFPAInfoToHMI_t((const IFPAInfoToHMI_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_IFPAInfoToHMI_t_Put((IFPAInfoToHMI_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_002A(const void* i_msgData_ps)
{
    /* DD-ID:{B29F3F66-7846-48c0-86D4-848491AB64C9}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_IFPAInfoToPLD_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_IFPAInfoToPLD_t((const IFPAInfoToPLD_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_IFPAInfoToPLD_t_Put((IFPAInfoToPLD_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_002B(const void* i_msgData_ps)
{
    /* DD-ID :{6084019A-495C-483f-9630-563A7E1B6E56}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_IHMIInfoToFPA_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_IHMIInfoToFPA_t((const IHMIInfoToFPA_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_IHMIInfoToFPA_t_Put((IHMIInfoToFPA_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_002C(const void* i_msgData_ps)
{
    /* DD-ID :{8AED876D-54E6-4cee-B3EB-F52F6803B6C9}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpJobPLDData_IJobPLDOutput_t((const IJobPLDOutput_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpJobPLDData_IJobPLDOutput_t_Put((IJobPLDOutput_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_002F(const void* i_msgData_ps)
{
    /* DD-ID :{BE91C69C-A588-4acb-ACED-782956B11C13}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_IKinematicData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_IKinematicData_t((const IKinematicData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_IKinematicData_t_Put((IKinematicData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0030(const void* i_msgData_ps)
{
    /* DD-ID :{185652F9-ACFF-480c-B56A-E3B51B185EBA}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_ExtY_Kinematic_T);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_ExtY_Kinematic_T((const ExtY_Kinematic_T*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_ExtY_Kinematic_T_Put((ExtY_Kinematic_T*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0031(const void* i_msgData_ps)
{
    /* DD-ID :{CE24DCC8-4601-417d-A902-19605E56262B}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_IParkingSlotInformation_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_IParkingSlotInformation_t((const IParkingSlotInformation_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_IParkingSlotInformation_t_Put((IParkingSlotInformation_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0032(const void* i_msgData_ps)
{
    /* DD-ID :{250E4930-AA57-41b5-AA1B-9161D5B5DF47}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpJobFPAData_IJobFPAOutput_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpJobFPAData_IJobFPAOutput_t((const IJobFPAOutput_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpJobFPAData_IJobFPAOutput_t_Put((IJobFPAOutput_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0034(const void* i_msgData_ps)
{
    /* DD-ID :{07292250-05B3-4fb3-8592-466D30A53E79}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_IParkingSlotID_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_IParkingSlotID_t((const IParkingSlotID_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_IParkingSlotID_t_Put((IParkingSlotID_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0035(const void* i_msgData_ps)
{
	/* DD-ID :{B1FEEC04-7A05-44e8-842E-7C852871A83D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpNFCDOutput_NFCD_Output);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpNFCDOutput_NFCD_Output((const NFCD_Output*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpNFCDOutput_NFCD_Output_Put((NFCD_Output*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0036(const void* i_msgData_ps)
{
    /* DD-ID :{F295963E-F1CD-4abf-9C0F-47F6E100FE83}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_MOT_Output);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_MOT_Output((const MOT_Output*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_MOT_Output_Put((MOT_Output*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0037(const void* i_msgData_ps)
{
    /* DD-ID :{1D090091-F88B-4e75-BFBC-F9E3BBE64E2B}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t((const TbAP_DriveAssistStatOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put((TbAP_DriveAssistStatOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0038(const void* i_msgData_ps)
{
    /* DD-ID :{80E0461D-B221-4a3f-8961-704BBD9B2CFD}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSMDAInternal_TbAP_SMDAInternalOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSMDAInternal_TbAP_SMDAInternalOut_t((const TbAP_SMDAInternalOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put((TbAP_SMDAInternalOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0039(const void* i_msgData_ps)
{
	 /* DD-ID :{84C90E48-B450-4945-810E-39710E94B2E7}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t((const TbAP_SMPAInternalOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put((TbAP_SMPAInternalOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_003A(const void* i_msgData_ps)
{
    /* DD-ID :{2503FC06-D0A6-4ea3-83F1-756F9C1CF415}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpFPAWarnOut_TbAP_FPAWarnOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpFPAWarnOut_TbAP_FPAWarnOut_t((const TbAP_FPAWarnOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put((TbAP_FPAWarnOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_003B(const void* i_msgData_ps)
{
    /* DD-ID :{A5F74453-BF50-48b4-AE94-DA8DDEC14E3D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpRPAWarnOut_TbAP_RPAWarnOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpRPAWarnOut_TbAP_RPAWarnOut_t((const TbAP_RPAWarnOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put((TbAP_RPAWarnOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_003C(const void* i_msgData_ps)
{
    /* DD-ID :{C0F72359-DEBF-4d01-8327-34BAFA773A4C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpPAStateOut_TbAP_PAStateOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpPAStateOut_TbAP_PAStateOut_t((const TbAP_PAStateOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put((TbAP_PAStateOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_003D(const void* i_msgData_ps)
{
    /* DD-ID :{37C200A8-DB32-4ec8-BBD2-26E847138ACD}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpVCActuatorOut_TbAP_VCActuatorOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpVCActuatorOut_TbAP_VCActuatorOut_t((const TbAP_VCActuatorOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put((TbAP_VCActuatorOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_003F(const void* i_msgData_ps)
{
    /* DD-ID :{85774E14-11C2-4092-B361-ACE8D54A1520}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpVCState_TbAP_VCStateOut_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpVCState_TbAP_VCStateOut_t((const TbAP_VCStateOut_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpVCState_TbAP_VCStateOut_t_Put((TbAP_VCStateOut_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0040(const void* i_msgData_ps)
{
    /* DD-ID :{6389E217-2292-4bc3-88AD-4DDBD8E85C19}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_FID_STRUCT_QM);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_FID_STRUCT_QM((const FID_STRUCT_QM*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_FID_STRUCT_QM_Put((FID_STRUCT_QM*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0041(const void* i_msgData_ps)
{
    /* DD-ID:{DC7A4E2F-EAAC-4750-8B87-93570009B3BD}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_FID_STRUCT_B);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_FID_STRUCT_B((const FID_STRUCT_B*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_FID_STRUCT_B_Put((FID_STRUCT_B*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0042(const void* i_msgData_ps)
{
    /* DD-ID :{48379519-C3AC-4fbb-9A2E-66121E5A5983}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUssPointMapGrp_US_S_PointMapGroup_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUssPointMapGrp_US_S_PointMapGroup_t((const US_S_PointMapGroup_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put((US_S_PointMapGroup_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0043(const void* i_msgData_ps)
{
	/* DD-ID :{905F4DAA-18EF-4208-9CC8-9442DF31165E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSnrDirEcho_US_S_SnrDirEcho_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSnrDirEcho_US_S_SnrDirEcho_t((const US_S_SnrDirEcho_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put((US_S_SnrDirEcho_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0044(const void* i_msgData_ps)
{
    /* DD-ID :{64E85771-12EF-4376-BA05-C54FB75BA422}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUssZoneInfo_US_S_ZoneInfo_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUssZoneInfo_US_S_ZoneInfo_t((const US_S_ZoneInfo_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put((US_S_ZoneInfo_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0045(const void* i_msgData_ps)
{
    /* DD-ID :{11F77577-E3CD-4e3a-8D89-1C6A59BB6829}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUSSBlockageBit_US_S_BlockageBit_t((const US_S_BlockageBit_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put((US_S_BlockageBit_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0046(const void* i_msgData_ps)
{
    /* DD-ID :{357920DB-803B-410e-A2E1-8BBA2E01C349}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUSSConstantData_US_S_USSConstantData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUSSConstantData_US_S_USSConstantData_t((const US_S_USSConstantData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put((US_S_USSConstantData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0047(const void* i_msgData_ps)
{
    /* DD-ID :{E1B16916-BA15-4208-998A-12605FFF5136}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t((const US_S_USSPeriodDiagData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put((US_S_USSPeriodDiagData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0)
static void callback_MsgId_0048(const void* i_msgData_ps)
{
    /* DD-ID :{2165A5D8-DABC-44c4-A979-152607BB46B7}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUSSErrorDiagData_US_S_USSErrorDiagData_t((const US_S_USSErrorDiagData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put((US_S_USSErrorDiagData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0049(const void* i_msgData_ps)
{
    /* DD-ID :{EB509001-3BC0-4da7-BC59-DE72DAC28776}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_USS_Curr_Volt_Monitor_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_USS_Curr_Volt_Monitor_t((const USS_Curr_Volt_Monitor_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_USS_Curr_Volt_Monitor_t_Put((USS_Curr_Volt_Monitor_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_004A(const void* i_msgData_ps)
{
    /* DD-ID :{F2B56C08-00E9-4968-ACCD-FB2FF2DF2D1C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_THARelated_ScreenReq_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_THARelated_ScreenReq_t((const THARelated_ScreenReq_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_THARelated_ScreenReq_t_Put((THARelated_ScreenReq_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004B(const void* i_msgData_ps)
{
    /* DD-ID :{9FA28499-8064-4d1a-BEAE-3ECB37BF140A}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCamEepromData_Svs_CamEepromDataArray_t((const Svs_CamEepromDataArray_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCamEepromData_Svs_CamEepromDataArray_t_Put((Svs_CamEepromDataArray_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_004C(const void* i_msgData_ps)
{
    /* DD-ID :{3577C899-6BEE-4e5f-B22A-DA78BF166BC5}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_DiagToSVS_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_DiagToSVS_t((const DiagToSVS_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_DiagToSVS_t_Put((DiagToSVS_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004D(const void* i_msgData_ps)
{
    /* DD-ID :{5B03606B-041B-4916-AF4B-2CCBF493E94E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSToDiag_SVSToDiag_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSToDiag_SVSToDiag_t((const SVSToDiag_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSToDiag_SVSToDiag_t_Put((SVSToDiag_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004E(const void* i_msgData_ps)
{
    /* DD-ID :{B6246998-65A3-417b-B23D-7F776172601F}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t((const IFOD_Outputs_CVPAMFDData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put((IFOD_Outputs_CVPAMFDData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_004F(const void* i_msgData_ps)
{
    /* DD-ID :{A4F5A924-B33B-4b2b-8771-D2AD8E916156}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t((const LMD_Outputs_CVPAMFDData2_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t_Put((LMD_Outputs_CVPAMFDData2_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0050(const void* i_msgData_ps)
{
    /* DD-ID :{2F6DE958-BBB3-4a64-9492-8F6028E6BE7E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_CAM_Curr_Volt_Monitor_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_CAM_Curr_Volt_Monitor_t((const CAM_Curr_Volt_Monitor_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_CAM_Curr_Volt_Monitor_t_Put((CAM_Curr_Volt_Monitor_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0051(const void* i_msgData_ps)
{
    /* DD-ID :{D493B9CB-FB1B-4037-A10F-2D6EDC9286C3}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCamCsData_CAM_CS_Curr_Monitor_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCamCsData_CAM_CS_Curr_Monitor_t((const CAM_CS_Curr_Monitor_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put((CAM_CS_Curr_Monitor_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0052(const void* i_msgData_ps)
{
    /* DD-ID :{ACBBB04B-B356-4c14-8EBF-4CABC010065B}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUssMrrgData_US_S_MarriageSensorIDs_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUssMrrgData_US_S_MarriageSensorIDs_t((const US_S_MarriageSensorIDs_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put((US_S_MarriageSensorIDs_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0053(const void* i_msgData_ps)
{
	/* DD-ID :{573F9A6D-00F1-46a7-973C-F407972B7EEA}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_US_S_MarriageSensorIDs_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_US_S_MarriageSensorIDs_t((const US_S_MarriageSensorIDs_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_US_S_MarriageSensorIDs_t_Put((US_S_MarriageSensorIDs_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0054(const void* i_msgData_ps)
{
 	/* DD-ID:{A2FA9289-3342-4384-A179-49FA02A89539}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTrscToDiag_TRSCtoDiagMgr_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTrscToDiag_TRSCtoDiagMgr_t((const TRSCtoDiagMgr_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put((TRSCtoDiagMgr_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0055(const void* i_msgData_ps)
{
	/* DD-ID:{4114AA58-F799-44b1-8CF5-A4469674AEFF}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTrailerDetectOP_TrailerDetection_Output_DID_t((const TrailerDetection_Output_DID_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTrailerDetectOP_TrailerDetection_Output_DID_t_Put((TrailerDetection_Output_DID_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0057(const void* i_msgData_ps)
{
    /* DD-ID:{3AAEC5FA-4C71-4aab-8BE6-9394D42CB5D3}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_HMIInfoToAP_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_HMIInfoToAP_t((const HMIInfoToAP_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_HMIInfoToAP_t_Put((HMIInfoToAP_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0058(const void* i_msgData_ps)
{
    /* DD-ID:{1492020B-D010-4848-A924-4B49F6404E30}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_DiagToParkAssist_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_DiagToParkAssist_t((const DiagToParkAssist_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_DiagToParkAssist_t_Put((DiagToParkAssist_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0059(const void* i_msgData_ps)
{
 	/* DD-ID:{0718019F-72B6-4720-A7FA-9875DFE3D341}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_USS_PowerSelect_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_USS_PowerSelect_t((const USS_PowerSelect_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_USS_PowerSelect_t_Put((USS_PowerSelect_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_005A(const void* i_msgData_ps)
{
    /* DD-ID:{5FDC35A4-84AF-4c3a-99D7-F9906030E91C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data1_USS_PowerSelect_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data1_USS_PowerSelect_t((const USS_PowerSelect_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data1_USS_PowerSelect_t_Put((USS_PowerSelect_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_005B(const void* i_msgData_ps)
{
    /* DD-ID:{89452189-E4B9-4c6f-9C17-DCD3E9789372}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_ME_ProxiToMPU1_0_Def_t((const ME_ProxiToMPU1_0_Def_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_ME_ProxiToMPU1_0_Def_t_Put((ME_ProxiToMPU1_0_Def_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_005C(const void* i_msgData_ps)
{
	/* DD-ID :{C9308B7D-A096-41bf-A91C-34F48626B391}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_ME_ProxiToMCU2_0_Def_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_ME_ProxiToMCU2_0_Def_t((const ME_ProxiToMCU2_0_Def_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Put((ME_ProxiToMCU2_0_Def_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_005D(const void* i_msgData_ps)
{
	/* DD-ID :{3858D823-397D-482f-A72C-D683B144515E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_ME_ProxiToMCU2_1_Def_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_ME_ProxiToMCU2_1_Def_t((const ME_ProxiToMCU2_1_Def_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Put((ME_ProxiToMCU2_1_Def_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_005E(const void* i_msgData_ps)
{
	/* DD-ID :{4DFC79AD-1526-4787-A091-F21838F0D7A6}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TrscDebug_ScrRes_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TrscDebug_ScrRes_t((const TrscDebug_ScrRes_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TrscDebug_ScrRes_t_Put((TrscDebug_ScrRes_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_005F(const void* i_msgData_ps)
{
	/* DD-ID :{D51530C3-FAA6-46e2-849B-BA14793E9FA4}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TRSCDebug_ScrReq_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TRSCDebug_ScrReq_t((const TRSCDebug_ScrReq_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TRSCDebug_ScrReq_t_Put((TRSCDebug_ScrReq_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0060(const void* i_msgData_ps)
{
	/* DD-ID :{6DDDF68E-383C-4b34-8C76-315F10804E53}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUssDataCollection_US_S_USSDataCollectionData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUssDataCollection_US_S_USSDataCollectionData_t((const US_S_USSDataCollectionData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put((US_S_USSDataCollectionData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0061(const void* i_msgData_ps)
{
	/* DD-ID :{2D091703-922C-4a9a-B8E2-D7C71D04EABB}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpPointDistOpBuff_US_S_PointDistOutputBuff_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpPointDistOpBuff_US_S_PointDistOutputBuff_t((const US_S_PointDistOutputBuff_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put((US_S_PointDistOutputBuff_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0062(const void* i_msgData_ps)
{
	/* DD-ID :{4F8530F1-2015-4f24-81B8-D330A811F6CE}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t((const CpuLoadMcu2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t_Put((CpuLoadMcu2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0063(const void* i_msgData_ps)
{
	/* DD-ID :{1B3E2AA6-E902-45e8-8C5C-D14E77A2434A}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t((const CpuLoadMcu2_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t_Put((CpuLoadMcu2_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0064(const void* i_msgData_ps)
{
	/* DD-ID :{CA073BE6-74EE-4ea1-8B75-7AF5286D2820}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TbNVM_ReadParam);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TbNVM_ReadParam((const TbNVM_ReadParam*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TbNVM_ReadParam_Put((TbNVM_ReadParam*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0065(const void* i_msgData_ps)
{
	/* DD-ID :{95BC1A02-7DFA-4183-AE8D-E4778915575C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_ME_CanDebugRIDStatus_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_ME_CanDebugRIDStatus_t((const ME_CanDebugRIDStatus_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_ME_CanDebugRIDStatus_t_Put((ME_CanDebugRIDStatus_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0066(const void* i_msgData_ps)
{
	/* DD-ID :{516925F9-06E8-4fb0-9B12-D607E382AEBC}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_SVS_NVMData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_SVS_NVMData_t((const SVS_NVMData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_SVS_NVMData_t_Put((SVS_NVMData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0067(const void* i_msgData_ps)
{
	/* DD-ID :{BA22E0E8-78A2-428a-9130-FE1D57E20D92}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t((const IJobUSSObjectMapOutput_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t_Put((IJobUSSObjectMapOutput_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0068(const void* i_msgData_ps)
{
	/* DD-ID :{FCEA16E4-E770-44df-8A5D-D6A26172C44F}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t((const TbFA_ArbiterOutput_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put((TbFA_ArbiterOutput_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0069(const void* i_msgData_ps)
{
	/* DD-ID :{0E00A7C1-CDDF-4ca8-A590-2884A834296F}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpSVSNVMData_SVS_NVMData_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpSVSNVMData_SVS_NVMData_t((const SVS_NVMData_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpSVSNVMData_SVS_NVMData_t_Put((SVS_NVMData_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_006A(const void* i_msgData_ps)
{
	/* DD-ID :{BD36D984-6DF1-43e7-91D2-64D5C5029A2D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_USS_Calibration_Data_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_USS_Calibration_Data_t((const USS_Calibration_Data_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_USS_Calibration_Data_t_Put((USS_Calibration_Data_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006B(const void* i_msgData_ps)
{
	/* DD-ID :{A8D4E4D3-CA13-4bbf-B076-1F627C1F0737}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTbAPDebugOut_TbAP_DebugOut);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTbAPDebugOut_TbAP_DebugOut((const TbAP_DebugOut*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put((TbAP_DebugOut*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006C(const void* i_msgData_ps)
{
	/* DD-ID :{EB5C814F-5D33-44a6-8EFE-1B54DACBA836}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t((const WdgCheckpointStatus_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put((WdgCheckpointStatus_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006D(const void* i_msgData_ps)
{
	/* DD-ID :{85755F7D-50CC-43c8-8F4F-CCCFB491438C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t((const WdgCheckpointStatus_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put((WdgCheckpointStatus_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_006E(const void* i_msgData_ps)
{
	/* DD-ID :{35D1D02D-D1C7-463e-A422-B0D0ED8D549D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t((const WdgCheckpointStatus_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t_Put((WdgCheckpointStatus_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0070(const void* i_msgData_ps)
{
	/* DD-ID :{6FB3C0E2-C33C-4921-91D9-D417CA71960A}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpLMDLaneOp_LMD_Lane_Outputs_s((const LMD_Lane_Outputs_s*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpLMDLaneOp_LMD_Lane_Outputs_s_Put((LMD_Lane_Outputs_s*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0071(const void* i_msgData_ps)
{
	/* DD-ID :{D40898EC-D50D-4c13-924B-7F53259FC30D}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t((const TbTHASmVc_DiagMgr_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put((TbTHASmVc_DiagMgr_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0072(const void* i_msgData_ps)
{
	/* DD-ID :{F14F87DB-8508-4874-A8CC-51D133CBBBA0}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_THA_Calibration_data_MCU2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_THA_Calibration_data_MCU2_1_t((const THA_Calibration_data_MCU2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_THA_Calibration_data_MCU2_1_t_Put((THA_Calibration_data_MCU2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0073(const void* i_msgData_ps)
{
	/* DD-ID :{63C0F010-EAAF-48e0-A64F-129488DEDE02}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_THA_Calibration_data_MPU1_0_t((const THA_Calibration_data_MPU1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_THA_Calibration_data_MPU1_0_t_Put((THA_Calibration_data_MPU1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0074(const void* i_msgData_ps)
{
	/* DD-ID :{A8CE1EA2-4A10-45c9-8BEB-9613A62CF93A}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TRSC_Calibration_data_MCU2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TRSC_Calibration_data_MCU2_1_t((const TRSC_Calibration_data_MCU2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Put((TRSC_Calibration_data_MCU2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0075(const void* i_msgData_ps)
{
	/* DD-ID :{CD8D7590-A24E-458e-8BAB-B8CC076EC51E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_APA_Calibration_data_MPU1_0_t((const APA_Calibration_data_MPU1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_APA_Calibration_data_MPU1_0_t_Put((APA_Calibration_data_MPU1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0076(const void* i_msgData_ps)
{
	/* DD-ID :{E74AA9CF-B680-4950-A4CC-11BC83F0A1D1}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_APA_Calibration_data_MCU2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_APA_Calibration_data_MCU2_1_t((const APA_Calibration_data_MCU2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_APA_Calibration_data_MCU2_1_t_Put((APA_Calibration_data_MCU2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0077(const void* i_msgData_ps)
{
	/* DD-ID :{913400DF-3786-4f79-B158-DDA45AE9EF92}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_SVS_Calibration_data_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_SVS_Calibration_data_t((const SVS_Calibration_data_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_SVS_Calibration_data_t_Put((SVS_Calibration_data_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0078(const void* i_msgData_ps)
{
	/* DD-ID :{8AEFBE46-ED6C-4b75-AA60-2D55DC2FF9D3}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_FOD_Calibration_data_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_FOD_Calibration_data_t((const FOD_Calibration_data_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_FOD_Calibration_data_t_Put((FOD_Calibration_data_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0079(const void* i_msgData_ps)
{
	/* DD-ID :{8773AEA2-09F5-44bb-8CDA-268921E5D18C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_LMD_Calibration_data_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_LMD_Calibration_data_t((const LMD_Calibration_data_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_LMD_Calibration_data_t_Put((LMD_Calibration_data_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_007A(const void* i_msgData_ps)
{
	/* DD-ID :{390C0551-4F22-4df6-B66F-B9C23CC33030}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TRSC_Calibration_data_MPU1_0_t((const TRSC_Calibration_data_MPU1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TRSC_Calibration_data_MPU1_0_t_Put((TRSC_Calibration_data_MPU1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007B(const void* i_msgData_ps)
{
	/* DD-ID :{6FB75F02-EC53-4317-94DC-FAD8E49AE347}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t((const IFOD_Outputs_Arbitration_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Put((IFOD_Outputs_Arbitration_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007C(const void* i_msgData_ps)
{
	/* DD-ID :{04C9B9B1-B2DF-4f2f-9F26-0F9EF7DE9E37}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpIDebugFODObject_IDebug_FODObject_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpIDebugFODObject_IDebug_FODObject_t((const IDebug_FODObject_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put((IDebug_FODObject_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007E(const void* i_msgData_ps)
{
	/* DD-ID :{CBA72940-2E6E-43ea-A634-EE476DA3FD10}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTbFAResetKM_TbFA_ResetKM_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTbFAResetKM_TbFA_ResetKM_t((const TbFA_ResetKM_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put((TbFA_ResetKM_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_007F(const void* i_msgData_ps)
{
	/* DD-ID :{E4BBA878-86F4-4983-8B8D-DC1996808F24}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t((const ME_Proxi_MPU1_0_to_MCU1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t_Put((ME_Proxi_MPU1_0_to_MCU1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0080(const void* i_msgData_ps)
{
	/* DD-ID :{3FF9C1F6-FF2E-4349-969D-3AC2402CB265}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToHmi_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TbSVS_e_SVSCalibSMToHmi_t((const TbSVS_e_SVSCalibSMToHmi_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Put((TbSVS_e_SVSCalibSMToHmi_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0081(const void* i_msgData_ps)
{
	/* DD-ID :{ED7050CD-A573-41e6-9EC1-66AADE8EECE7}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_USS_Calibration_data_2_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_USS_Calibration_data_2_t((const USS_Calibration_data_2_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_USS_Calibration_data_2_t_Put((USS_Calibration_data_2_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0082(const void* i_msgData_ps)
{
	/* DD-ID :{8773AEA2-09F5-44bb-8CDA-268921E5D18C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCamSerENStat_Cam_and_Ser_EN_Status_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCamSerENStat_Cam_and_Ser_EN_Status_t((const Cam_and_Ser_EN_Status_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCamSerENStat_Cam_and_Ser_EN_Status_t_Put((Cam_and_Ser_EN_Status_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0)
static void callback_MsgId_0083(const void* i_msgData_ps)
{
	/* DD-ID :{89DE3414-056B-46da-BEDE-03F6ADFEDCED}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TrailerDetection_Output_HMI_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TrailerDetection_Output_HMI_t((const TrailerDetection_Output_HMI_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TrailerDetection_Output_HMI_t_Put((TrailerDetection_Output_HMI_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0084(const void* i_msgData_ps)
{
	/* DD-ID :{E46416C1-F591-443c-9824-09FC4E8FF3AF}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpDLDOutput_JobDLDOutput_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpDLDOutput_JobDLDOutput_t((const JobDLDOutput_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpDLDOutput_JobDLDOutput_t_Put((JobDLDOutput_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0085(const void* i_msgData_ps)
{
	/* DD-ID :{8716772F-85A2-41a8-A82B-AD38AAC1DE92}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_INVMSignalManager_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_INVMSignalManager_t((const INVMSignalManager_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_INVMSignalManager_t_Put((INVMSignalManager_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0086(const void* i_msgData_ps)
{
	/* DD-ID :{A3109D4F-F943-40e7-8B25-0F843B8561EA}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t((const TRSCSMVCtoDebugCAN_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put((TRSCSMVCtoDebugCAN_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0087(const void* i_msgData_ps)
{
	/* DD-ID :{98421A2A-19FD-46f8-8206-9F59300B3023}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TimeManagerProxy_TimeStamp_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TimeManagerProxy_TimeStamp_t((const TimeManagerProxy_TimeStamp_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TimeManagerProxy_TimeStamp_t_Put((TimeManagerProxy_TimeStamp_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0088(const void* i_msgData_ps)
{
	/* DD-ID :{368BA9CF-5A32-4206-97F9-4A16561287FB}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type((const US_S_CsmStateChangeReason_Type*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put((US_S_CsmStateChangeReason_Type*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0)
static void callback_MsgId_0089(const void* i_msgData_ps)
{
	/* DD-ID :{AEEB0CAA-C094-4e38-859F-1D0CAC56407C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpKeepAliveResponse_KeepAliveResponse_t((const KeepAliveResponse_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpKeepAliveResponse_KeepAliveResponse_t_Put((KeepAliveResponse_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008A(const void* i_msgData_ps)
{
	/* DD-ID :{89DDA116-F258-4cb1-8CF0-B6ED992579FB}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUssDebugMsg_US_S_DebugMsg_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUssDebugMsg_US_S_DebugMsg_t((const US_S_DebugMsg_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put((US_S_DebugMsg_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008B(const void* i_msgData_ps)
{
	/* DD-ID :{5C378A30-0F13-463e-96A6-67403940AFFE}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpCAMSelInfo_CAM_select_info_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpCAMSelInfo_CAM_select_info_t((const CAM_select_info_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpCAMSelInfo_CAM_select_info_t_Put((CAM_select_info_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008C(const void* i_msgData_ps)
{
	/* DD-ID :{9A3D5A90-60C6-44ad-B07B-AE395B910007}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpErrFltMcu2_0_Error_Fault_MCU2_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpErrFltMcu2_0_Error_Fault_MCU2_0_t((const Error_Fault_MCU2_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpErrFltMcu2_0_Error_Fault_MCU2_0_t_Put((Error_Fault_MCU2_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008D(const void* i_msgData_ps)
{
	/* DD-ID :{D0D0B38D-A395-4c91-9DE0-A2F44E6E6612}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpErrFltMcu2_1_Error_Fault_MCU2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpErrFltMcu2_1_Error_Fault_MCU2_1_t((const Error_Fault_MCU2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpErrFltMcu2_1_Error_Fault_MCU2_1_t_Put((Error_Fault_MCU2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_008E(const void* i_msgData_ps)
{
	/* DD-ID :{1759C365-B99D-4365-AAC5-834FE4840B97}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpErrFltMpu1_0_Error_Fault_MPU1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpErrFltMpu1_0_Error_Fault_MPU1_0_t((const Error_Fault_MPU1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpErrFltMpu1_0_Error_Fault_MPU1_0_t_Put((Error_Fault_MPU1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_008F(const void* i_msgData_ps)
{
    /* DD-ID :{A00B625F-7CDE-45b8-AC07-9A068E52068E}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_TRSC_CalibrationClear_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_TRSC_CalibrationClear_t((const TRSC_CalibrationClear_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_TRSC_CalibrationClear_t_Put((TRSC_CalibrationClear_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU2_1)
static void callback_MsgId_0090(const void* i_msgData_ps)
{
    /*DD-ID:{56EFA39D-2807-4736-82D6-7E6837771346}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_UssTunningData_mcu1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_UssTunningData_mcu1_0_t((const UssTunningData_mcu1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_UssTunningData_mcu1_0_t_Put((UssTunningData_mcu1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0091(const void* i_msgData_ps)
{
    /*DD-ID:{A8391E10-D48A-4fbe-8767-C8D9E24F67A8}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpUssTunData_UssTunningData_mcu2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpUssTunData_UssTunningData_mcu2_1_t((const UssTunningData_mcu2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put((UssTunningData_mcu2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0092(const void* i_msgData_ps)
{
    /*DD-ID:{2300CC59-F6D4-4c1b-9F70-081C0055A7F6}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t((const RunTimeStats_MCU2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put((RunTimeStats_MCU2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0093(const void* i_msgData_ps)
{
    /*DD-ID:{6EC14685-E11C-4af1-9F39-B4D67FF20055}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t((const RunTimeStats_MCU2_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put((RunTimeStats_MCU2_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
static void callback_MsgId_0094(const void* i_msgData_ps)
{
    /*DD-ID:{B8941BBB-7CD1-430e-B484-8C9E0B8CB3C3}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_PerformanceStatsEnable_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_PerformanceStatsEnable_t((const PerformanceStatsEnable_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_PerformanceStatsEnable_t_Put((PerformanceStatsEnable_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0095(const void* i_msgData_ps)
{
    /*DD-ID:{A1F01354-B6C9-43ae-8112-8EC659DE949C}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t((const RunTimeStats_MPU1_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t_Put((RunTimeStats_MPU1_0_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MPU1_0)
static void callback_MsgId_0096(const void* i_msgData_ps)
{
    /*DD-ID:{1F44512D-4FC8-49d2-8EBE-620C54C10BFF}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_Data_CamHotplugStatus_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_Data_CamHotplugStatus_t((const CamHotplugStatus_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_Data_CamHotplugStatus_t_Put((CamHotplugStatus_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0097(const void* i_msgData_ps)
{
    /*DD-ID:{4CB5DBC1-F98A-43ee-A99C-3073AA04DF21}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t((const StackUsage_MCU2_1_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put((StackUsage_MCU2_1_t*)i_msgData_ps);
#endif
}
#endif

#if defined(BUILD_MCU1_0)
static void callback_MsgId_0098(const void* i_msgData_ps)
{
    /*DD-ID:{2E7FA972-B312-4dcb-A7CB-3528F1A10576}*/
#if defined(BUILD_MPU1_0)
    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t);
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    (void)Rte_Write_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t((const StackUsage_MCU2_0_t*)i_msgData_ps);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put((StackUsage_MCU2_0_t*)i_msgData_ps);
#endif
}
#endif

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize all global variables accessed by pointer in IPC lookup table.
 * Description: IPC manager will call this function to initiaize all global variable used
 *              by IPC lookup table
 * Return Type : void
*/
void IPC_F_lookupTblInit_v (void)
{
    /* DD-ID :{E7C28F01-2939-4656-9D17-709F792027F6}*/
#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
    uint16_t v_msgIdx_u16;
#endif

#if (D_NUMBER_OF_TX_MESSAGES > 0)
    uint8_t v_buffStateIdx_u8;

    for(v_msgIdx_u16 = 0; v_msgIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdx_u16++)
    {
        /* Initialize shared memory buffer state variable */
        if (V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps != NULL)
        {
            for(v_buffStateIdx_u8 = 0; v_buffStateIdx_u8 < V_ipcLutAttrTx_as[v_msgIdx_u16].buffCnt_u8 ; v_buffStateIdx_u8++)
            {
                V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps[v_buffStateIdx_u8].buffInUse_u16 = 0;
                V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps[v_buffStateIdx_u8].timer_u8 = 0;
                V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps[v_buffStateIdx_u8].currPktNum_u16 = 0;
            }
        }
    }
#endif

#if (D_NUMBER_OF_RX_MESSAGES > 0)
    for(v_msgIdx_u16 = 0; v_msgIdx_u16 < D_NUMBER_OF_RX_MESSAGES; v_msgIdx_u16++)
    {
        /* Initialize Message counter */
        if (V_ipcLutAttrRx_as[v_msgIdx_u16].msgIdCntrPrev_pu32 != NULL)
        {
            *(V_ipcLutAttrRx_as[v_msgIdx_u16].msgIdCntrPrev_pu32) = 0;
        }
    }
#endif
}

/* ===========================================================================
 *
 *   End of Code File
 *
 * ======================================================================== */
