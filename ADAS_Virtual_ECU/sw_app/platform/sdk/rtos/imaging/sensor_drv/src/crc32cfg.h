#ifndef CRC_CFG_H
#define CRC_CFG_H

/** Hardware based CRC32 calculation */
#define CRC_32_HARDWARE  1U /* not supported on MPC5602B */
/** Table based CRC32 calculation */
#define CRC_32_TABLE     2U
/** Runtime based CRC32 calculation */
#define CRC_32_RUNTIME   3U

/* Switch to select one of the available calculation method */
#define CRC_32_MODE     CRC_32_RUNTIME


/** Initial value for the 32-bit CRC calculation */
#define CRC_INITIAL_VALUE32    0xFFFFFFFFU

#endif /* ==== End of file CRC_CFG_H =================================== */
