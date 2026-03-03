#ifndef _MECL_CRC_H_
#define _MECL_CRC_H_

#include "Crc_cfg.h"

//PRQA S 1025 EOF

#define CRC_CRC32_PRESET_VALUE                         0xffffffffU
#define CRC_CRC16_PRESET_VALUE                         0xffffU
#define CRC_CRC16_ISO15693_PRESET_VALUE                0xffffU
#define CRC_CRC16_CCITT_PRESET_VALUE                   0xffffU

/* CRC_CRC32 -> CRC32, Initial Value 0xFFFFFFFF, reverse databytes, reverse result, Final XOR 0xFFFFFFFF */
#define CRC_CRC32_REVERSEDPOLYNOMIAL                   0x04c11db7U /* = 0xEDB88320 = x^32 + x^26 + x^23 + x^22 + x^16 + x^12 +  x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + X^0 */
#define CRC_CRC32_CHECK_VALUE                          0xcbf43926U /* for "123456789" */

/* CRC_CRC16_ISO15693 -> CRC-CCITT, Initial Value 0xFFFF, reverse databytes, reverse result, Final XOR 0xFFFF */
#define CRC_CRC16_ISO15693_REVERSEDPOLYNOMIAL          0x8408U /* = 0x1021 = x^16 + x^12 + x^5 + 1 */
#define CRC_CRC16_ISO15693_CHECK_VALUE                 0x906eU /* for "123456789" */

/* CRC_CRC16_CCITT -> CRC-CCITT, Initial Value 0xFFFF, Final XOR 0x0000 */
#define CRC_CRC16_CCITT_REVERSEDPOLYNOMIAL             0x8408U /* = 0x1021 = x^16 + x^12 + x^5 + 1 */
#define CRC_CRC16_CCITT_CHECK_VALUE                    0x29b1U /* for "123456789" */

/* CRC_CRC16-> CRC-CRCITT, Initial Value 0xFFFF, reverse databytes, reverse result, Final XOR 0x0000 */
#define CRC_CRC16_REVERSEDPOLYNOMIAL                   0x8408U /* = 0x1021 = x^16 + x^12 + x^5 + 1 */
#define CRC_CRC16_CHECK_VALUE                          0x6f91U /* for "123456789" */

namespace mecl
{

class crc
{
public:
  /** Initial values */
  static const uint8_t  c_CRC_INITIAL_VALUE_u8  = 0x00U;
  static const uint16_t c_CRC_INITIAL_VALUE_u16 = 0xffffU;
  static const uint32_t c_CRC_INITIAL_VALUE_u32 = 0xffffffffU;

  static uint8_t  calculateCRC8 (const uint8_t* crc_DataPtr, uint32_t crc_Length, uint8_t  crc_StartValue8 = c_CRC_INITIAL_VALUE_u8);
  static uint16_t calculateCRC16(const uint8_t* crc_DataPtr, uint32_t crc_Length, uint16_t crc_StartValue16 = c_CRC_INITIAL_VALUE_u16);
  static uint32_t calculateCRC32(const uint8_t* crc_DataPtr, uint32_t crc_Length, uint32_t crc_StartValue32 = c_CRC_INITIAL_VALUE_u32);
  static uint32_t calculateFpgaCRC32(uint32_t i_Data_u32, uint32_t i_CRC_u32);
  static uint32_t calculateFpgaCRC32(const uint32_t* i_Data_pu32, uint32_t i_Length_u32, uint32_t i_CRC_u32);
  static uint32_t calculateFpgaTableCRC32(uint32_t i_Data_u32, uint32_t i_CRC_u32);
  static uint32_t calculateFpgaTableCRC32(const uint32_t* i_Data_pu32, uint32_t i_Length_u32, uint32_t i_CRC_u32);
};

}
#endif /* _MECL_CRC_H_ */
