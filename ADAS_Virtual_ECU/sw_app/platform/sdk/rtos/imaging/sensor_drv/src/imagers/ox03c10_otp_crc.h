/**
 * \file
 * Functions and types for CRC checks.
 *
 * Generated on Tue Aug  8 15:08:55 2023
 * by pycrc vunknown, https://pycrc.org
 * using the configuration:
 *  - Width         = 16
 *  - Poly          = 0x1021
 *  - XorIn         = 0xffff
 *  - ReflectIn     = False
 *  - XorOut        = 0x0000
 *  - ReflectOut    = False
 *  - Algorithm     = table-driven
 *
 * This file defines the functions ox03c10_otp_crc_init(), ox03c10_otp_crc_update() and ox03c10_otp_crc_finalize().
 *
 * The ox03c10_otp_crc_init() function returns the initial \c crc value and must be called
 * before the first call to ox03c10_otp_crc_update().
 * Similarly, the ox03c10_otp_crc_finalize() function must be called after the last call
 * to ox03c10_otp_crc_update(), before the \c crc is being used.
 * is being used.
 *
 * The ox03c10_otp_crc_update() function can be called any number of times (including zero
 * times) in between the ox03c10_otp_crc_init() and ox03c10_otp_crc_finalize() calls.
 *
 * This pseudo-code shows an example usage of the API:
 * \code{.c}
 * ox03c10_otp_crc_t crc;
 * unsigned char data[MAX_DATA_LEN];
 * size_t data_len;
 *
 * crc = ox03c10_otp_crc_init();
 * while ((data_len = read_data(data, MAX_DATA_LEN)) > 0) {
 *     crc = ox03c10_otp_crc_update(crc, data, data_len);
 * }
 * crc = ox03c10_otp_crc_finalize(crc);
 * \endcode
 */
#ifndef OX03C10_OTP_CRC_H
#define OX03C10_OTP_CRC_H

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * The definition of the used algorithm.
 *
 * This is not used anywhere in the generated code, but it may be used by the
 * application code to call algorithm-specific code, if desired.
 */
#define CRC_ALGO_TABLE_DRIVEN 1


/**
 * The type of the CRC values.
 *
 * This type must be big enough to contain at least 16 bits.
 */
typedef uint_fast16_t ox03c10_otp_crc_t;


/**
 * Calculate the initial crc value.
 *
 * \return     The initial crc value.
 */
static inline ox03c10_otp_crc_t ox03c10_otp_crc_init(void)
{
    return 0xffff;
}


/**
 * Update the crc value with new data.
 *
 * \param[in] crc      The current crc value.
 * \param[in] data     Pointer to a buffer of \a data_len bytes.
 * \param[in] data_len Number of bytes in the \a data buffer.
 * \return             The updated crc value.
 */
ox03c10_otp_crc_t ox03c10_otp_crc_update(ox03c10_otp_crc_t crc, const void *data, size_t data_len);


/**
 * Calculate the final crc value.
 *
 * \param[in] crc  The current crc value.
 * \return     The final crc value.
 */
static inline ox03c10_otp_crc_t ox03c10_otp_crc_finalize(ox03c10_otp_crc_t crc)
{
    return crc;
}


#ifdef __cplusplus
}           /* closing brace for extern "C" */
#endif

#endif      /* OX03C10_OTP_CRC_H */
