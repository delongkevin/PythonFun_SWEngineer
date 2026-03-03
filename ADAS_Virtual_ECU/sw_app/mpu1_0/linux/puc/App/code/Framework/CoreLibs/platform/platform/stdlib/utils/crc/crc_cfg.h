#ifndef CRC_CFG_H
#define CRC_CFG_H

#include "platform/PlatformSpecs.h"
/* PRQA S 1025 EOF */ /* Macro may be used as a literal. */

/** Hardware based CRC8 calculation */
#define CRC_8_HARDWARE  1U /* not supported on MPC5602B */
/** Table based CRC8 calculation */
#define CRC_8_TABLE     2U
/** Runtime based CRC8 calculation */
#define CRC_8_RUNTIME   3U

/** Hardware based CRC16 calculation */
#define CRC_16_HARDWARE  1U /* not supported on MPC5602B */
/** Table based CRC16 calculation */
#define CRC_16_TABLE     2U
/** Runtime based CRC16 calculation */
#define CRC_16_RUNTIME   3U

/** Hardware based CRC32 calculation */
#define CRC_32_HARDWARE  1U /* not supported on MPC5602B */
/** Table based CRC16 calculation */
#define CRC_32_TABLE     2U
/** Runtime based CRC16 calculation */
#define CRC_32_RUNTIME   3U

/* Switch to select one of the available calculation method */
#define CRC_8_MODE      CRC_8_RUNTIME
#define CRC_16_MODE     CRC_16_RUNTIME
#define CRC_32_MODE     CRC_32_RUNTIME

/** Initial value for the 8-bit CRC calculation */
#define CRC_INITIAL_VALUE8     0x00U

/** Initial value for the 16-bit CRC calculation */
#define CRC_INITIAL_VALUE16    0xFFFFU

/** Initial value for the 32-bit CRC calculation */
#define CRC_INITIAL_VALUE32    0xFFFFFFFFU

#endif /* ==== End of file CRC_CFG_H =================================== */
