#ifndef _MECL_CRC_CFG_H_
#define _MECL_CRC_CFG_H_

#include "mecl/core/MeclTypes.h"

//PRQA S 1025 EOF
//PRQA S 2300 EOF
//PRQA S 2313 EOF
//PRQA S 2400 EOF
// QACPP warnings above are suppressed because it is a C-code (need to be checked by the corresponding tool)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;


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
/** Table based CRC32 calculation */
#define CRC_32_TABLE     2U
/** Runtime based CRC32 calculation */
#define CRC_32_RUNTIME   3U

/* Switch to select one of the available calculation method */
#define CRC_8_MODE      CRC_8_RUNTIME
#define CRC_16_MODE     CRC_16_RUNTIME
#define CRC_32_MODE     CRC_32_TABLE
#define CRC_FPGA_MODE   CRC_32_TABLE

#endif /* ==== End of file _CRC_CFG_H_ =================================== */


