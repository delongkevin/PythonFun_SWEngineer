#ifndef _CRC_H_
#define _CRC_H_ /* PRQA S 602 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

#include "crc32cfg.h"
/* PRQA S 1025 EOF */ /* Macro may be used as a literal. shared between c and cpp */
/* PRQA S 1020 EOF */ /* Macro may be used as a literal. shared between c and cpp */

#define CRC_TESTLENGTH                                 9
#define CRC_TESTSTRING                                 "123456789"

#define CRC_CRC32_PRESET_VALUE                         0xFFFFFFFFU

/* CRC_CRC32 -> CRC32, Initial Value 0xFFFFFFFF, reverse databytes, reverse result, Final XOR 0xFFFFFFFF */
#define CRC_CRC32_REVERSEDPOLYNOMIAL                   0x04C11DB7U /* = 0xEDB88320 = x^32 + x^26 + x^23 + x^22 + x^16 + x^12 +  x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + X^0 */
#define CRC_CRC32_CHECK_VALUE                          0xCBF43926U /* for "123456789" */


extern uint32_t crc_calculateCRC32(const uint8_t* crc_DataPtr, uint32_t crc_Length, uint32_t crc_StartValue32);

#ifdef __cplusplus
}
#endif

#endif /* _CRC_H_ */
